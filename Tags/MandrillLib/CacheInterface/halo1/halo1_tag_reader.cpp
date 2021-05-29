#include "mandrilllib-private-pch.h"

c_halo1_tag_reader::c_halo1_tag_reader(c_halo1_cache_cluster& cache_cluster, c_halo1_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	group_count(),
	groups(),
	instance_count(),
	instances()
{
	BCS_RESULT rs;
	c_halo1_debug_reader* debug_reader;
	if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
	{
		throw(rs);
	}

	s_cache_file_buffers_info buffers_info;
	if (BCS_FAILED(rs = cache_reader.get_buffers(buffers_info)))
	{
		throw(rs);
	}

	c_halo1_header_wrapper& cache_file_header = *cache_reader.cache_file_header;

	halo1::s_cache_file_tags_header tags_header = *reinterpret_cast<const halo1::s_cache_file_tags_header*>(buffers_info.tag_section_buffer.begin);

	if (tags_header.tags_signature != 'tags')
	{
		throw(BCS_E_FAIL);
	}

	int32_t tag_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.tag_instances_address, tag_instances_relative_offset)))
	{
		throw(rs);
	}

	// emulate tag groups
	{
		using namespace blofeld;

		groups = blofeld::tag_groups[cache_reader.engine_platform_build.engine_type];
		for (const s_tag_group** tag_group = groups; *tag_group; tag_group++)
		{
			group_count++;
		}
	}

	instance_count = tags_header.tag_instance_count;
	instances = new s_halo1_tag_instance_info[tags_header.tag_instance_count];
	const halo1::s_cache_file_tag_instance* tag_instances_read_pointer = reinterpret_cast<const halo1::s_cache_file_tag_instance*>(buffers_info.tag_section_buffer.begin + tag_instances_relative_offset);
	for (unsigned long tag_index = 0; tag_index < tags_header.tag_instance_count; tag_index++)
	{
		s_halo1_tag_instance_info& tag_instance_info = instances[tag_index];
		halo1::s_cache_file_tag_instance& tag_instance = tag_instance_info.instance = tag_instances_read_pointer[tag_index];

		tag group_tag = tag_instance.group_tags[0];
		{
			using namespace blofeld;
			for (const s_tag_group** tag_group = groups; *tag_group; tag_group++)
			{
				if ((*tag_group)->group_tag == group_tag)
				{
					tag_instance_info.tag_group = *tag_group;
					goto tag_group_search_finished;
				}
			}
			FATAL_ERROR(L"Failed to find tag group");
		tag_group_search_finished:;
		}

		tag_instance_info.index = tag_index;

		if (BCS_FAILED(rs = debug_reader->get_tag_filepath(tag_index, tag_instance_info.instance_name)))
		{
			throw(rs);
		}

		const void* instance_data;
		if (BCS_FAILED(rs = page_offset_to_pointer(tag_instance_info.instance.address, instance_data)))
		{
			throw(rs);
		}

		tag_instance_info.instance_data = instance_data;

		debug_point;
	}
}

c_halo1_tag_reader::~c_halo1_tag_reader()
{
	//delete groups; // #NOTE: memory owned by blofeld
	delete instances;
}

BCS_RESULT c_halo1_tag_reader::get_instance_info(unsigned long tag_index, const s_halo1_tag_instance_info*& instance_info)
{
	if (tag_index > instance_count)
	{
		return BCS_E_FAIL;
	}

	instance_info = &instances[tag_index];

	return BCS_S_OK;
}

BCS_RESULT c_halo1_tag_reader::page_offset_to_pointer(long page_offset, const void*& data)
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
