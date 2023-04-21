#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO

using namespace blofeld;
using namespace blofeld::eldorado::pc32;

c_eldorado_tag_reader::c_eldorado_tag_reader(c_eldorado_cache_cluster& _cache_cluster, c_eldorado_cache_file_reader& _cache_reader) :
	c_tag_reader(_cache_cluster, _cache_reader),
	cache_cluster(_cache_cluster),
	cache_reader(_cache_reader),
	cache_file_section_header(),
	tag_groups(),
	tag_instances(),
	tag_instances_by_index()
{

}

c_eldorado_tag_reader::~c_eldorado_tag_reader()
{

}

BCS_RESULT c_eldorado_tag_reader::read_header()
{
	s_memory_mapped_file_info& tags_cache_file = cache_reader.memory_mapped_file_infos[_eldorado_file_type_tags_cache];

	if (tags_cache_file.file_size < sizeof(eldorado::s_cache_file_section_header))
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	eldorado::s_cache_file_section_header* _cache_file_section_header = reinterpret_cast<eldorado::s_cache_file_section_header*>(tags_cache_file.file_view_begin);
	// byteswap_inplace(_cache_file_tags_header);
	cache_file_section_header = *_cache_file_section_header;

	tag_cache_offsets = reinterpret_cast<unsigned int*>(tags_cache_file.file_view_begin + cache_file_section_header.file_offsets);
	if (tags_cache_file.file_view_end < static_cast<void*>(tag_cache_offsets + cache_file_section_header.file_count))
	{
		throw BCS_E_OUT_OF_RANGE;
	}

	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_reader::create_group(blofeld::s_tag_group const& tag_group, c_eldorado_tag_group*& eldorado_tag_group)
{
	if (BCS_SUCCEEDED(get_tag_group_by_blofeld_tag_group(tag_group, eldorado_tag_group)))
	{
		return BCS_S_NO_CHANGES_MADE;
	}

	c_eldorado_tag_group* parent_tag_group = nullptr;
	if (tag_group.parent_tag_group)
	{
		BCS_RESULT rs = BCS_S_OK;
		if (BCS_FAILED(rs = create_group(*tag_group.parent_tag_group, parent_tag_group)))
		{
			return rs;
		}
	}

	eldorado_tag_group = new() c_eldorado_tag_group(cache_cluster, tag_group, parent_tag_group);
	tag_groups.push_back(eldorado_tag_group);

	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_reader::read_groups()
{
	BCS_RESULT rs = BCS_S_OK;

	for (t_tag_group_collection tag_group_collection = cache_reader.tag_groups; *tag_group_collection; tag_group_collection++)
	{
		blofeld::s_tag_group const& tag_group = **tag_group_collection;

		c_eldorado_tag_group* eldorado_tag_group;
		if (BCS_FAILED(rs = create_group(tag_group, eldorado_tag_group)))
		{
			return rs;
		}
	}

	return rs;
}

BCS_RESULT c_eldorado_tag_reader::read_instances()
{
	s_memory_mapped_file_info& tags_cache_file = cache_reader.memory_mapped_file_infos[_eldorado_file_type_tags_cache];

	uint32_t specific_index;
	BCS_RESULT specific_index_result = command_line_get_argument_ulong("specificindex", specific_index);

	const char* specific_group;
	BCS_RESULT specific_group_result = command_line_get_argument("specificgroup", specific_group);

	for (unsigned int cache_file_tag_index = 0; cache_file_tag_index < cache_file_section_header.file_count; cache_file_tag_index++)
	{
		unsigned int tag_offset = tag_cache_offsets[cache_file_tag_index];

		if (BCS_SUCCEEDED(specific_index_result) && cache_file_tag_index != specific_index)
		{
			continue;
		}

		if (tag_offset != 0)
		{
			const char* tag_data_start = tags_cache_file.file_view_begin + tag_offset;
			if (tag_data_start + sizeof(blofeld::eldorado::s_cache_file_tag_instance) >= tags_cache_file.file_view_end)
			{
				return BCS_E_OUT_OF_RANGE;
			}
			const blofeld::eldorado::s_cache_file_tag_instance* tag_header = reinterpret_cast<const blofeld::eldorado::s_cache_file_tag_instance*>(tag_data_start);
			const char* tag_data_end = tag_data_start + tag_header->total_size;
			if (tag_data_end >= tags_cache_file.file_view_end)
			{
				return BCS_E_OUT_OF_RANGE;
			}

			c_eldorado_tag_group* eldorado_tag_group;
			tag group_tag = tag_header->group_tags[0];
			if (group_tag == blofeld::taggroups::SOUND_TAG)
			{
				group_tag = blofeld::taggroups::CACHE_FILE_SOUND_TAG;
			}
			BCS_RESULT get_tag_group_result = get_tag_group_by_group_tag(group_tag, eldorado_tag_group);
			if (BCS_FAILED(get_tag_group_result))
			{
				return get_tag_group_result;
			}

			char tag_instance_name_buffer[256];
			sprintf(tag_instance_name_buffer, "tag%04X", cache_file_tag_index);

			if (BCS_SUCCEEDED(specific_group_result))
			{
				const char* group_name;
				if (BCS_SUCCEEDED(eldorado_tag_group->get_group_name(group_name)))
				{
					if (_stricmp(specific_group, group_name) != 0)
					{
						continue;
					}
				}
			}

			c_eldorado_tag_instance* tag_instance = new() c_eldorado_tag_instance(
				cache_cluster,
				*this,
				*eldorado_tag_group,
				cache_file_tag_index,
				tag_instance_name_buffer,
				*tag_header,
				tag_data_start,
				tag_data_end);
			tag_instances.push_back(tag_instance);
		}
	}

	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_reader::page_offset_to_pointer(int32_t page_offset, const void*& data)
{
	BCS_RESULT rs = BCS_S_OK;

	if (page_offset == 0)
	{
		data = nullptr;
		return rs;
	}

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	int64_t virtual_address;
	if (BCS_FAILED(rs = cache_reader.page_offset_to_virtual_address(page_offset, virtual_address)))
	{
		return rs;
	}

	int32_t relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(virtual_address, relative_offset)))
	{
		return rs;
	}

	const char* data_pointer = tag_section_buffer.begin + relative_offset;
	data = data_pointer;

	return rs;
}

BCS_RESULT c_eldorado_tag_reader::get_tag_group_by_group_tag(tag in_group_tag, c_eldorado_tag_group*& out_tag_group) const
{
	for (c_eldorado_tag_group* tag_group : tag_groups)
	{
		tag group_tag;
		ASSERT(BCS_SUCCEEDED(tag_group->get_group_tag(group_tag)));
		if (group_tag == in_group_tag)
		{
			out_tag_group = tag_group;
			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_eldorado_tag_reader::get_tag_group_by_blofeld_tag_group(const s_tag_group& in_blofeld_tag_group, c_eldorado_tag_group*& out_tag_group) const
{
	for (c_eldorado_tag_group* tag_group : tag_groups)
	{
		s_tag_group const* blofeld_tag_group;
		ASSERT(BCS_SUCCEEDED(tag_group->get_blofeld_tag_group(blofeld_tag_group)));

		if (blofeld_tag_group == &in_blofeld_tag_group)
		{
			out_tag_group = tag_group;
			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_eldorado_tag_reader::get_tag_groups(c_eldorado_tag_group**& out_tag_groups, uint32_t& out_tag_group_count)
{
	out_tag_groups = tag_groups.data();
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_reader::get_tag_groups(c_tag_group**& out_tag_groups, uint32_t& out_tag_group_count)
{
	out_tag_groups = reinterpret_cast<c_tag_group**>(tag_groups.data());
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_reader::get_tag_instances(c_eldorado_tag_instance**& out_tag_instances, uint32_t& out_tag_instance_count)
{
	out_tag_instances = tag_instances.data();
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_reader::get_tag_instances(c_tag_instance**& out_tag_instances, uint32_t& out_tag_instance_count)
{
	out_tag_instances = reinterpret_cast<c_tag_instance**>(tag_instances.data());
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_tag_reader::get_tag_instance_by_cache_file_tag_index(uint32_t cache_file_tag_index, c_tag_instance*& out_tag_instance)
{
	BCS_RESULT rs = BCS_S_OK;

	c_eldorado_tag_instance** tag_instances;
	uint32_t tag_instances_count;
	if (BCS_FAILED(rs = get_tag_instances(tag_instances, tag_instances_count)))
	{
		return rs;
	}

	for (uint32_t tag_instance_index = 0; tag_instance_index < tag_instances_count; tag_instance_index++)
	{
		c_eldorado_tag_instance& tag_instance = *tag_instances[tag_instance_index];
		if (tag_instance.cache_file_tag_index == cache_file_tag_index)
		{
			out_tag_instance = &tag_instance;

			return BCS_S_OK;
		}
	}

	return BCS_E_FAIL;
}

#endif // BCS_BUILD_HIGH_LEVEL_ELDORADO
