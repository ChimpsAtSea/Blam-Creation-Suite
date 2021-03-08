#include "mandrilllib-private-pch.h"

c_halo4_tag_reader::c_halo4_tag_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader) :
	cache_cluster(cache_cluster),
	cache_reader(cache_reader),
	group_count(),
	groups(),
	instance_count(),
	instances(),
	global_instance_count(),
	global_instances(),
	interop_count(),
	interops()
{
	BCS_RESULT rs;
	c_halo4_debug_reader* debug_reader;
	if (BCS_FAILED(rs = cache_cluster.get_debug_reader(cache_reader, debug_reader)))
	{
		throw(rs);
	}

	s_cache_file_buffers_info buffers_info;
	if (BCS_FAILED(rs = cache_reader.get_buffers(buffers_info)))
	{
		throw(rs);
	}

	halo4::xbox360::s_cache_file_header& cache_file_header = cache_reader.cache_file_header;
	
	int32_t tags_header_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(cache_file_header.tags_header_address, tags_header_relative_offset)))
	{
		throw(rs);
	}

	halo4::xbox360::s_cache_file_tags_header tags_header = *reinterpret_cast<const halo4::xbox360::s_cache_file_tags_header*>(buffers_info.tag_section_buffer.begin + tags_header_relative_offset);
	byteswap(tags_header);

	if (tags_header.tags_signature != 'tags')
	{
		throw(BCS_E_FAIL);
	}

	int32_t tag_groups_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.tag_groups.address, tag_groups_relative_offset)))
	{
		throw(rs);
	}

	group_count = tags_header.tag_groups.count;
	groups = new s_halo4_tag_group_info[tags_header.tag_groups.count];
	const halo4::xbox360::s_cache_file_tag_group* tag_groups_read_pointer = reinterpret_cast<const halo4::xbox360::s_cache_file_tag_group*>(buffers_info.tag_section_buffer.begin + tag_groups_relative_offset);
	for (long group_index = 0; group_index < tags_header.tag_groups.count; group_index++)
	{
		s_halo4_tag_group_info& tag_group_info = groups[group_index];
		halo4::xbox360::s_cache_file_tag_group& tag_group = tag_group_info.group = tag_groups_read_pointer[group_index];
		byteswap(tag_group);

		if (BCS_FAILED(rs = debug_reader->string_id_to_string(tag_group.name, tag_group_info.group_name)))
		{
			throw(rs);
		}

		debug_point;
	}

	int32_t tag_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.tag_instances.address, tag_instances_relative_offset)))
	{
		throw(rs);
	}

	instance_count = tags_header.tag_instances.count;
	instances = new s_halo4_tag_instance_info[tags_header.tag_instances.count];
	const halo4::xbox360::s_cache_file_tag_instance* tag_instances_read_pointer = reinterpret_cast<const halo4::xbox360::s_cache_file_tag_instance*>(buffers_info.tag_section_buffer.begin + tag_instances_relative_offset);
	for (long tag_index = 0; tag_index < tags_header.tag_instances.count; tag_index++)
	{
		s_halo4_tag_instance_info& tag_instance_info = instances[tag_index];
		halo4::xbox360::s_cache_file_tag_instance& tag_instance = tag_instance_info.instance = tag_instances_read_pointer[tag_index];
		byteswap(tag_instance);

		tag_instance_info.group_info = &groups[tag_instance.group_index];
		tag_instance_info.index = tag_index;

		const char* tag_name;
		if (BCS_FAILED(rs = debug_reader->get_tag_filepath(tag_index, tag_instance_info.instance_name)))
		{
			throw(rs);
		}

		debug_point;
	}

	int32_t tag_global_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.global_tag_instances.address, tag_global_instances_relative_offset)))
	{
		throw(rs);
	}

	global_instance_count = tags_header.global_tag_instances.count;
	global_instances = new s_halo4_tag_global_instance_info[tags_header.global_tag_instances.count];
	const halo4::xbox360::s_cache_file_tag_global_instance* global_tag_instances_read_pointer = reinterpret_cast<const halo4::xbox360::s_cache_file_tag_global_instance*>(buffers_info.tag_section_buffer.begin + tag_global_instances_relative_offset);
	for (long global_tag_index = 0; global_tag_index < tags_header.global_tag_instances.count; global_tag_index++)
	{
		s_halo4_tag_global_instance_info& global_instance_info = global_instances[global_tag_index];
		halo4::xbox360::s_cache_file_tag_global_instance& global_tag_instance = global_instance_info.global_instance = global_tag_instances_read_pointer[global_tag_index];
		byteswap(global_tag_instance);

		unsigned long tag_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(global_tag_instance.datum_index);

		global_instance_info.instance_info = &instances[tag_index];

		debug_point;
	}

	int32_t tag_interops_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.tag_interop_table.address, tag_interops_relative_offset)))
	{
		throw(rs);
	}

	interop_count = tags_header.tag_interop_table.count;
	interops = new halo4::xbox360::s_cache_file_tag_interop[tags_header.tag_interop_table.count];
	const halo4::xbox360::s_cache_file_tag_interop* tag_interops_read_pointer = reinterpret_cast<const halo4::xbox360::s_cache_file_tag_interop*>(buffers_info.tag_section_buffer.begin + tag_interops_relative_offset);
	for (long interop_index = 0; interop_index < tags_header.tag_interop_table.count; interop_index++)
	{
		halo4::xbox360::s_cache_file_tag_interop& tag_interop = interops[interop_index] = tag_interops_read_pointer[interop_index];
		byteswap(tag_interop);

		debug_point;
	}
}

c_halo4_tag_reader::~c_halo4_tag_reader()
{
	delete groups;
	delete instances;
	delete global_instances;
	delete interops;
}
