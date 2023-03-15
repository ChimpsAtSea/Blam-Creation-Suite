#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO1

using namespace blofeld;
using namespace blofeld::taggroups;

c_halo1_tag_reader::c_halo1_tag_reader(c_halo1_cache_cluster& _cache_cluster, c_halo1_cache_file_reader& _cache_reader) :
	c_tag_reader(_cache_cluster, _cache_reader),
	cache_cluster(_cache_cluster),
	cache_reader(_cache_reader),
	tag_groups(),
	tag_instances(),
	tag_instances_by_index(),
	tag_instance_infos()
{
	BCS_RESULT rs;

	if (!cache_reader.is_resource_file)
	{
		if (BCS_FAILED(rs = read_tag_instances()))
		{
			throw(rs);
		}

		if (BCS_FAILED(rs = init_tag_groups()))
		{
			throw(rs);
		}
		if (BCS_FAILED(rs = init_tag_instances()))
		{
			throw(rs);
		}
	}
}

c_halo1_tag_reader::~c_halo1_tag_reader()
{
}

BCS_RESULT c_halo1_tag_reader::read_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	c_halo1_debug_reader* debug_reader;
	if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
	{
		return rs;
	}

	s_cache_file_buffer_info tag_section_buffer;
	if (BCS_FAILED(rs = cache_reader.get_buffer(_tag_section_buffer, tag_section_buffer)))
	{
		return rs;
	}

	c_halo1_header_wrapper& cache_file_header = *cache_reader.cache_file_header;

	halo1::s_cache_file_tags_header tags_header = *reinterpret_cast<const halo1::s_cache_file_tags_header*>(tag_section_buffer.begin);

	if (tags_header.tags_signature != 'tags')
	{
		return BCS_E_FAIL;
	}

	int32_t tag_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.tag_instances_address, tag_instances_relative_offset)))
	{
		return rs;
	}

	tag_instance_infos.resize(tags_header.tag_instance_count);
	const halo1::s_cache_file_tag_instance* tag_instances_read_pointer = reinterpret_cast<const halo1::s_cache_file_tag_instance*>(tag_section_buffer.begin + tag_instances_relative_offset);
	for (uint32_t tag_index = 0; tag_index < tags_header.tag_instance_count; tag_index++)
	{
		s_halo1_tag_instance_info& tag_instance_info = tag_instance_infos[tag_index];
		halo1::s_cache_file_tag_instance& tag_instance = tag_instance_info.instance = tag_instances_read_pointer[tag_index];

		tag group_tag = tag_instance.group_tags[0];
		s_tag_group const* tag_group;
		if (BCS_FAILED(rs = tag_definition_registry_get_tag_group_by_engine_platform_build(cache_reader.engine_platform_build, group_tag, tag_group)))
		{
			return rs;
		}

		tag_instance_info.blofeld_tag_group = tag_group;
		tag_instance_info.tag_group = nullptr; // deferred : init_tag_groups

		tag_instance_info.index = tag_index;

		if (BCS_FAILED(rs = debug_reader->get_tag_filepath(tag_index, tag_instance_info.instance_name)))
		{
			return rs;
		}

		const void* instance_data;
		if (!tag_instance.in_data_file || tag_instance.group_tags[0] == SOUND_TAG)
		{
			if (BCS_FAILED(rs = page_offset_to_pointer(tag_instance_info.instance.address, instance_data)))
			{
				return rs;
			}
		}
		else
		{
			const char* relative_cache_file_path = nullptr;
			switch (tag_instance.group_tags[0])
			{
			case BITMAP_TAG:
				relative_cache_file_path = "maps\\bitmaps.map";
				break;
			case SOUND_TAG:
				relative_cache_file_path = "maps\\sounds.map";
				break;
			case FONT_TAG:
			case HUD_MESSAGE_TEXT_TAG:
			case UNICODE_STRING_LIST_TAG:
				relative_cache_file_path = "maps\\loc.map";
				break;
			default:
				FATAL_ERROR("Unsupported data file");
			}

			c_halo1_cache_file_reader* cache_file_reader;
			if (BCS_FAILED(rs = cache_cluster.get_cache_reader_by_relative_path(relative_cache_file_path, cache_file_reader)))
			{
				return rs;
			}
			if (BCS_FAILED(rs = cache_file_reader->get_cache_file_resource_instance_data(tag_instance_info.instance.address, instance_data)))
			{
				return rs;
			}
			const char* resource_tag_instance_name;
			if (BCS_FAILED(rs = cache_file_reader->get_cache_file_resource_instance_name(tag_instance_info.instance.address, resource_tag_instance_name)))
			{
				return rs;
			}

			ASSERT(strcmp(tag_instance_info.instance_name, resource_tag_instance_name) == 0);

			
		}

		//ASSERT(instance_data != nullptr);
		tag_instance_info.instance_data = instance_data;

		
	}

	return rs;
}

BCS_RESULT c_halo1_tag_reader::init_tag_groups()
{
	BCS_RESULT rs = BCS_S_OK;

	t_tag_group_collection blofeld_tag_groups;
	if (BCS_FAILED(rs = cache_cluster.get_blofeld_tag_groups(blofeld_tag_groups)))
	{
		return rs;
	}

	uint32_t tag_group_count = 0; // #TODO: create a function for this
	for (t_tag_group_iterator tag_group_iterator = blofeld_tag_groups; *tag_group_iterator; tag_group_iterator++)
	{
		tag_group_count++;
	}

	bool added_tag_group = false;
	do
	{
		added_tag_group = false;
		for (t_tag_group_iterator tag_group_iterator = blofeld_tag_groups; *tag_group_iterator; tag_group_iterator++)
		{
			const s_tag_group& blofeld_tag_group = **tag_group_iterator;

			c_halo1_tag_group* tag_group = nullptr;
			if (BCS_SUCCEEDED(get_tag_group_by_group_tag(blofeld_tag_group.group_tag, tag_group)))
			{
				continue; // skip groups already added
			}

			c_halo1_tag_group* parent_tag_group = nullptr;
			if (blofeld_tag_group.parent_tag_group)
			{
				if (BCS_FAILED(get_tag_group_by_group_tag(blofeld_tag_group.parent_tag_group->group_tag, parent_tag_group)))
				{
					continue;
				}
			}

			tag_group = new() c_halo1_tag_group(cache_cluster, blofeld_tag_group, parent_tag_group);
			tag_groups.push_back(tag_group);
			added_tag_group = true;
		}
	} while (added_tag_group);
	ASSERT(tag_groups.size() >= tag_group_count);

	return rs;
}

BCS_RESULT c_halo1_tag_reader::init_tag_instances()
{
	BCS_RESULT rs = BCS_S_OK;

	for (s_halo1_tag_instance_info& tag_instance_info : tag_instance_infos)
	{
		// skip null tags
		if (tag_instance_info.instance_data == nullptr) // #NOTE: is this the best way to do this?
		{
			continue;
		}

		c_halo1_tag_group* tag_group;
		if (BCS_FAILED(rs = get_tag_group_by_blofeld_tag_group(*tag_instance_info.blofeld_tag_group, tag_group)))
		{
			return rs;
		}

		c_halo1_tag_instance* tag_instance = new() c_halo1_tag_instance(
			cache_cluster,
			*this,
			*tag_group,
			tag_instance_info.index,
			tag_instance_info.instance_name,
			tag_instance_info.instance_data
		);

		tag_instances.push_back(tag_instance);
		tag_instances_by_index[tag_instance_info.index] = tag_instance;
	}

	return rs;
}

BCS_RESULT c_halo1_tag_reader::get_tag_group_by_group_tag(tag in_group_tag, c_halo1_tag_group*& out_tag_group) const
{
	for (c_halo1_tag_group* tag_group : tag_groups)
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

BCS_RESULT c_halo1_tag_reader::get_tag_group_by_blofeld_tag_group(const s_tag_group& in_blofeld_tag_group, c_halo1_tag_group*& out_tag_group) const
{
	for (c_halo1_tag_group* tag_group : tag_groups)
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

BCS_RESULT c_halo1_tag_reader::get_instance_info_by_tag_index(uint32_t tag_index, const s_halo1_tag_instance_info*& instance_info)
{
	if (tag_index > tag_instance_infos.size())
	{
		return BCS_E_FAIL;
	}

	instance_info = &tag_instance_infos[tag_index];

	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_reader::page_offset_to_pointer(int32_t page_offset, const void*& data)
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

BCS_RESULT c_halo1_tag_reader::get_tag_groups(c_halo1_tag_group**& out_tag_groups, uint32_t& out_tag_group_count)
{
	out_tag_groups = tag_groups.data();
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_reader::get_tag_groups(c_tag_group**& out_tag_groups, uint32_t& out_tag_group_count)
{
	out_tag_groups = reinterpret_cast<c_tag_group**>(tag_groups.data());
	out_tag_group_count = static_cast<unsigned long>(tag_groups.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_reader::get_tag_instances(c_halo1_tag_instance**& out_tag_instances, uint32_t& out_tag_instance_count)
{
	out_tag_instances = tag_instances.data();
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_reader::get_tag_instances(c_tag_instance**& out_tag_instances, uint32_t& out_tag_instance_count)
{
	out_tag_instances = reinterpret_cast<c_tag_instance**>(tag_instances.data());
	out_tag_instance_count = static_cast<unsigned long>(tag_instances.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_reader::get_tag_instance_by_cache_file_tag_index(uint32_t cache_file_tag_index, c_tag_instance*& out_tag_instance)
{
	BCS_RESULT rs = BCS_S_OK;

	c_halo1_tag_instance** tag_instances;
	uint32_t tag_instances_count;
	if (BCS_FAILED(rs = get_tag_instances(tag_instances, tag_instances_count)))
	{
		return rs;
	}

	for (uint32_t tag_instance_index = 0; tag_instance_index < tag_instances_count; tag_instance_index++)
	{
		c_halo1_tag_instance& tag_instance = *tag_instances[tag_instance_index];
		if (tag_instance.cache_file_tag_index == cache_file_tag_index)
		{
			out_tag_instance = &tag_instance;

			return BCS_S_OK;
		}
	}

	return BCS_E_FAIL;
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO1
