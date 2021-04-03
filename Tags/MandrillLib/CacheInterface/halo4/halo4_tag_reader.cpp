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
	interops(),
	_resource_type_index_to_halo4_resource_type(nullptr),
	_interop_type_index_to_halo4_interop_type(nullptr),
	interop_containers(nullptr),
	_shared_file_index_to_cache_file_reader(nullptr),
	_shared_file_count(0)
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
	for (unsigned long group_index = 0; group_index < tags_header.tag_groups.count; group_index++)
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
	for (unsigned long tag_index = 0; tag_index < tags_header.tag_instances.count; tag_index++)
	{
		s_halo4_tag_instance_info& tag_instance_info = instances[tag_index];
		halo4::xbox360::s_cache_file_tag_instance& tag_instance = tag_instance_info.instance = tag_instances_read_pointer[tag_index];
		byteswap(tag_instance);

		tag_instance_info.group_info = &groups[tag_instance.group_index];
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

	int32_t tag_global_instances_relative_offset;
	if (BCS_FAILED(rs = cache_reader.virtual_address_to_relative_offset(tags_header.global_tag_instances.address, tag_global_instances_relative_offset)))
	{
		throw(rs);
	}

	global_instance_count = tags_header.global_tag_instances.count;
	global_instances = new s_halo4_tag_global_instance_info[tags_header.global_tag_instances.count];
	const halo4::xbox360::s_cache_file_tag_global_instance* global_tag_instances_read_pointer = reinterpret_cast<const halo4::xbox360::s_cache_file_tag_global_instance*>(buffers_info.tag_section_buffer.begin + tag_global_instances_relative_offset);
	for (unsigned long global_tag_index = 0; global_tag_index < tags_header.global_tag_instances.count; global_tag_index++)
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
	for (unsigned long interop_index = 0; interop_index < tags_header.tag_interop_table.count; interop_index++)
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
	delete _resource_type_index_to_halo4_resource_type;
	delete _interop_type_index_to_halo4_interop_type;
	delete interop_containers;
	delete _shared_file_index_to_cache_file_reader;
}

BCS_RESULT c_halo4_tag_reader::get_global_instance_info(tag group_tag, const s_halo4_tag_global_instance_info*& out_global_instance_info)
{
	for (unsigned long global_tag_index = 0; global_tag_index < global_instance_count; global_tag_index++)
	{
		s_halo4_tag_global_instance_info& global_instance_info = global_instances[global_tag_index];
		if (global_instance_info.global_instance.group_tag == group_tag)
		{
			out_global_instance_info = &global_instance_info;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_halo4_tag_reader::get_instance_info(unsigned long tag_index, const s_halo4_tag_instance_info*& instance_info)
{
	if (tag_index > instance_count)
	{
		return BCS_E_FAIL;
	}

	instance_info = &instances[tag_index];

	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_reader::page_offset_to_pointer(long page_offset, const void*& data)
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

BCS_RESULT c_halo4_tag_reader::init_interop_table()
{
	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	using namespace blofeld::xbox360_gen3;

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	byteswap(resource_gestalt);

	const s_cache_file_resource_type_identifier_block_block_struct* resource_type_identifiers;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.resource_type_identifiers_block.address, *reinterpret_cast<const void**>(&resource_type_identifiers))))
	{
		return rs;
	}

	_resource_type_index_to_halo4_resource_type = new e_halo4_resource_type[resource_gestalt.resource_type_identifiers_block.count];
	for (unsigned long index = 0; index < resource_gestalt.resource_type_identifiers_block.count; index++)
	{
		s_cache_file_resource_type_identifier_block_block_struct resource_type_identifier = resource_type_identifiers[index];
		byteswap(resource_type_identifier);

		const char* name = nullptr;
		c_halo4_debug_reader* debug_reader;
		if (BCS_SUCCEEDED(cache_cluster.get_debug_reader(this->cache_reader, debug_reader)))
		{
			debug_reader->string_id_to_string(resource_type_identifier.name, name);
		}

		e_halo4_resource_type resource_type = k_num_halo4_resource_types;
		for (unsigned long resource_type_index = 0; resource_type_index < k_num_halo4_resource_types; resource_type_index++)
		{
			const s_halo4_tag_resource_info& resource_info = halo4_tag_resource_infos[resource_type_index];

			if (
				static_cast<unsigned long>(resource_type_identifier.identifier_part_0) == resource_info.definition.persistent_identifier.identifier_part_0 &&
				static_cast<unsigned long>(resource_type_identifier.identifier_part_1) == resource_info.definition.persistent_identifier.identifier_part_1 &&
				static_cast<unsigned long>(resource_type_identifier.identifier_part_2) == resource_info.definition.persistent_identifier.identifier_part_2 &&
				static_cast<unsigned long>(resource_type_identifier.identifier_part_3) == resource_info.definition.persistent_identifier.identifier_part_3
				)
			{
				resource_type = static_cast<e_halo4_resource_type>(resource_type_index);
				break;
			}
		}
		ASSERT(resource_type != k_num_halo4_resource_types);

		_resource_type_index_to_halo4_resource_type[index] = resource_type;

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo4_tag_reader::init_interops()
{
	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	using namespace blofeld::xbox360_gen3;

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	byteswap(resource_gestalt);

	interop_containers = new c_halo4_interop_container * [interop_count + 1];
	interop_containers[interop_count] = nullptr;
	for (unsigned long interop_index = 0; interop_index < interop_count; interop_index++)
	{
		halo4::xbox360::s_cache_file_tag_interop& cache_file_tag_interop_entry = interops[interop_index];

		e_halo4_interop_type interop_type;
		if (BCS_FAILED(rs = interop_type_index_to_halo4_interop_type(cache_file_tag_interop_entry.type_index, interop_type)))
		{
			return rs;
		}

		const s_tag_interop* tag_interop_pointer;
		if (BCS_FAILED(rs = page_offset_to_pointer(cache_file_tag_interop_entry.page_address, *(const void**)&tag_interop_pointer)))
		{
			return rs;
		}
		s_tag_interop tag_interop = *tag_interop_pointer;
		byteswap(tag_interop);

		const void* interop_data;
		if (BCS_FAILED(rs = page_offset_to_pointer(tag_interop.descriptor, interop_data)))
		{
			return rs;
		}


		//{
		//	const s_cache_file_interop_type_identifier_block_block_struct* interop_type_identifiers;
		//	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.interop_type_identifiers_block.address, *reinterpret_cast<const void**>(&interop_type_identifiers))))
		//	{
		//		throw(rs);
		//	}

		//	s_cache_file_interop_type_identifier_block_block_struct interop_type_identifier = interop_type_identifiers[tag_interop.type_index];
		//	byteswap(interop_type_identifier);

		//	const char* name = "<error>";
		//	c_halo4_debug_reader* debug_reader;
		//	if (BCS_SUCCEEDED(cache_cluster.get_debug_reader(this->cache_reader, debug_reader)))
		//	{
		//		debug_reader->string_id_to_string(interop_type_identifier.name, name);
		//	}
		//	c_console::write_line(name);
		//}

		switch (interop_type)
		{
		case _halo4_vectorart_vertex_buffer_interop:
			interop_containers[interop_index] = new c_halo4_vectorart_vertex_buffer_interop(*this, tag_interop.descriptor, interop_data);
			break;
		case _halo4_polyart_index_buffer_interop:
			interop_containers[interop_index] = new c_halo4_polyart_index_buffer_interop(*this, tag_interop.descriptor, interop_data);
			break;
		case _halo4_polyart_vertex_buffer_interop:
			interop_containers[interop_index] = new c_halo4_polyart_vertex_buffer_interop(*this, tag_interop.descriptor, interop_data);
			break;
		case _halo4_d3d_vertex_buffer_interop:
		case _halo4_d3d_index_buffer_interop:
		case _halo4_d3d_texture_interop:
		case _halo4_d3d_texture_interleaved_interop:
		case _halo4_d3d_vertex_shader_interop:
		case _halo4_d3d_pixel_shader_interop:
		default:
			interop_containers[interop_index] = nullptr;
			FATAL_ERROR(L"Unsupported interop type");
			break;
		}

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo4_tag_reader::interop_type_index_to_halo4_interop_type(long type_index, e_halo4_interop_type& interop_type)
{
	BCS_VALIDATE_ARGUMENT(type_index >= 0);

	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	using namespace blofeld::xbox360_gen3;

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	byteswap(resource_gestalt);

	if (static_cast<unsigned long>(type_index) >= resource_gestalt.interop_type_identifiers_block.count)
	{
		return BCS_E_FAIL;
	}

	interop_type = _interop_type_index_to_halo4_interop_type[type_index];

	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_reader::init_resource_table()
{
	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	using namespace blofeld::xbox360_gen3;

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	byteswap(resource_gestalt);

	const s_cache_file_interop_type_identifier_block_block_struct* interop_type_identifiers;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.interop_type_identifiers_block.address, *reinterpret_cast<const void**>(&interop_type_identifiers))))
	{
		throw(rs);
	}

	_interop_type_index_to_halo4_interop_type = new e_halo4_interop_type[resource_gestalt.interop_type_identifiers_block.count];
	for (unsigned long index = 0; index < resource_gestalt.interop_type_identifiers_block.count; index++)
	{
		s_cache_file_interop_type_identifier_block_block_struct interop_type_identifier = interop_type_identifiers[index];
		byteswap(interop_type_identifier);

		const char* name = nullptr;
		c_halo4_debug_reader* debug_reader;
		if (BCS_SUCCEEDED(cache_cluster.get_debug_reader(this->cache_reader, debug_reader)))
		{
			debug_reader->string_id_to_string(interop_type_identifier.name, name);
		}

		e_halo4_interop_type interop_type = k_num_halo4_interop_types;
		for (unsigned long interop_type_index = 0; interop_type_index < k_num_halo4_interop_types; interop_type_index++)
		{
			const s_halo4_tag_interop_info& interop_info = halo4_tag_interop_infos[interop_type_index];

			if (
				static_cast<unsigned long>(interop_type_identifier.identifier_part_0) == interop_info.persistent_identifier.identifier_part_0 &&
				static_cast<unsigned long>(interop_type_identifier.identifier_part_1) == interop_info.persistent_identifier.identifier_part_1 &&
				static_cast<unsigned long>(interop_type_identifier.identifier_part_2) == interop_info.persistent_identifier.identifier_part_2 &&
				static_cast<unsigned long>(interop_type_identifier.identifier_part_3) == interop_info.persistent_identifier.identifier_part_3
				)
			{
				interop_type = static_cast<e_halo4_interop_type>(interop_type_index);
				break;
			}
		}
		ASSERT(interop_type != k_num_halo4_interop_types);

		_interop_type_index_to_halo4_interop_type[index] = interop_type;

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo4_tag_reader::init_resources()
{
	using namespace blofeld::xbox360_gen3;

	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* resource_gestalt_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, resource_gestalt_global_instance_info)))
	{
		return rs;
	}
	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(resource_gestalt_global_instance_info->instance_info->instance_data);
	byteswap(resource_gestalt);

	const s_halo4_tag_global_instance_info* resource_layout_table_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG, resource_layout_table_global_instance_info)))
	{
		return rs;
	}

	const s_cache_file_resource_data_block_block_struct* resources;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.resources_block.address, *reinterpret_cast<const void**>(&resources))))
	{
		return rs;
	}

	c_typed_tag_block<s_cache_file_resource_page_struct> file_pages_block;
	c_typed_tag_block<s_cache_file_resource_section_block_block_struct> sections_block;
	if (resource_layout_table_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_layout_table_block_struct resource_layout_table = *static_cast<const s_cache_file_resource_layout_table_block_struct*>(resource_layout_table_global_instance_info->instance_info->instance_data);
		byteswap(resource_layout_table);

		file_pages_block = resource_layout_table.file_pages_block;
		sections_block = resource_layout_table.sections_block;
	}
	else
	{
		file_pages_block = resource_gestalt.file_pages_block;
		sections_block = resource_gestalt.sections_block;
	}

	const s_cache_file_resource_page_struct* file_pages;
	if (BCS_FAILED(rs = page_offset_to_pointer(file_pages_block.address, *reinterpret_cast<const void**>(&file_pages))))
	{
		return rs;
	}

	const s_cache_file_resource_section_block_block_struct* sections;
	if (BCS_FAILED(rs = page_offset_to_pointer(sections_block.address, *reinterpret_cast<const void**>(&sections))))
	{
		return rs;
	}

	const char* naive_resource_control_data;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.naive_resource_control_data.address, *reinterpret_cast<const void**>(&naive_resource_control_data))))
	{
		return rs;
	}

	//const char* current_naive_resource_control_data_position = naive_resource_control_data;

	for (unsigned long resource_index = 0; resource_index < resource_gestalt.resources_block.count; resource_index++)
	{
		s_cache_file_resource_data_block_block_struct resource = resources[resource_index];
		byteswap(resource);

		unsigned long tag_index = DATUM_INDEX_TO_ABSOLUTE_INDEX(resource.owner_tag.datum_index);

		if (tag_index < UINT16_MAX)
		{
			const s_halo4_tag_instance_info* instance_info;
			if (BCS_FAILED(rs = get_instance_info(tag_index, instance_info)))
			{
				return rs;
			}

			e_halo4_resource_type resource_type;
			if (BCS_FAILED(rs = resource_type_index_to_halo4_resource_type(resource.resource_type_index, resource_type)))
			{
				return rs;
			}

			ASSERT(resource.page >= 0);

			s_cache_file_resource_section_block_block_struct section = sections[resource.page];
			byteswap(section);

			const s_cache_file_resource_priority_data_block_block_struct(*priority_level_datas)[3];
			if (BCS_FAILED(rs = page_offset_to_pointer(resource.priority_level_data_block.address, *reinterpret_cast<const void**>(&priority_level_datas))))
			{
				return rs;
			}

			s_cache_file_resource_priority_data_block_block_struct priority_level_data = (*priority_level_datas)[0];
			byteswap(priority_level_data);
			debug_point;

			s_resource_priority_datas resource_priority_datas = {};
			resource_priority_datas.naive_resource_control_data = naive_resource_control_data + priority_level_data.naive_data_offset;
			resource_priority_datas.instance_info = instance_info;
			resource_priority_datas.flags = resource.flags;
			for (unsigned long priority_level_index = 0; priority_level_index < 3; priority_level_index++)
			{

				s_resource_priority_data& resource_priority_data = resource_priority_datas.data[priority_level_index];
				short page_index = section.file_page_indexes[priority_level_index].page_index;
				resource_priority_data.page_index = page_index;
				if (page_index == -1) continue;

				long page_offset = section.page_offsets[priority_level_index].offset;
				resource_priority_data.resource_page_offset = page_offset;

				s_cache_file_resource_page_struct file_page = file_pages[section.file_page_indexes[priority_level_index].page_index];
				byteswap(file_page);

				e_compression_codec compression_codec = _compression_uncompressed;
				if (BCS_FAILED(rs = get_compression_codec_by_index(file_page.codec, compression_codec)))
				{
					return rs;
				}

				c_halo4_cache_file_reader* resource_cache_file;
				if (BCS_FAILED(rs = shared_file_index_to_cache_file_reader(file_page.shared_file, resource_cache_file)))
				{
					return rs;
				}

				s_cache_file_buffer_info buffer_info;
				resource_cache_file->get_section_buffer(gen3::_cache_file_section_index_resource, buffer_info);

				const char* page_data_pointer = buffer_info.begin + file_page.file_offset;
				size_t raw_page_data_size = file_page.file_size;

				resource_priority_data.resource_cache_file = resource_cache_file;
				resource_priority_data.page_file_offset = file_page.file_offset;
				resource_priority_data.page_file_size = file_page.file_size;
				resource_priority_data.page_size = file_page.size;
				resource_priority_data.page_data_pointer = page_data_pointer;
				resource_priority_data.compression_codec = compression_codec;

				/*
				#NOTE
				Resource priority data is pooled inside of the cache cluster removing duplicate resources
				and decompressing pages to extract multiple resource entries at once.
				See c_halo4_cache_cluster for initialization of c_halo4_resource_entry_reader
				*/
			}
			resource_priority_datas.make_id();

			c_halo4_resource_container* resource_container = nullptr;
			if (BCS_FAILED(rs = cache_cluster.get_resource_container(resource_priority_datas, resource_container)) && rs != BCS_E_NOT_FOUND)
			{
				return rs;
			}
			if (resource_container == nullptr)
			{
				switch (resource_type)
				{
				case _halo4_bitmap_texture_interop_resource:
					resource_container = new c_halo4_bitmap_texture_interop_resource(*instance_info, resource_priority_datas);
					break;
				case _halo4_sound_resource_definition:
					resource_container = new c_halo4_sound_resource_definition(*instance_info, resource_priority_datas);
					break;
				case _halo4_facial_animation_resource_definition:
					resource_container = new c_halo4_facial_animation_resource_definition(*instance_info, resource_priority_datas);
					break;
				case _halo4_model_animation_tag_resource:
					resource_container = new c_halo4_model_animation_tag_resource(*instance_info, resource_priority_datas);
					break;
				case _halo4_render_geometry_api_resource_definition:
					resource_container = new c_halo4_render_geometry_api_resource_definition(*instance_info, resource_priority_datas);
					break;
				case _halo4_bitmap_texture_interleaved_interop_resource:
					resource_container = new c_halo4_bitmap_texture_interleaved_interop_resource(*instance_info, resource_priority_datas);
					break;
				case _halo4_structure_bsp_tag_resources:
					resource_container = new c_halo4_structure_bsp_tag_resources(*instance_info, resource_priority_datas);
					break;
				case _halo4_structure_bsp_cache_file_tag_resources:
					resource_container = new c_halo4_structure_bsp_cache_file_tag_resources(*instance_info, resource_priority_datas);
					break;
				case _halo4_bink_resource:
					resource_container = new c_halo4_bink_resource(*instance_info, resource_priority_datas);
					break;
				case _halo4_pca_coefficients_resource_definition:
					resource_container = new c_halo4_pca_coefficients_resource_definition(*instance_info, resource_priority_datas);
					break;
				case _halo4_stitchable_bitmap_texture_interop_resource:
					resource_container = new c_halo4_stitchable_bitmap_texture_interop_resource(*instance_info, resource_priority_datas);
					break;
				case _halo4_collision_model_resource:
					resource_container = new c_halo4_collision_model_resource(*instance_info, resource_priority_datas);
					break;
				default:
					return BCS_E_UNSUPPORTED;
				}
				ASSERT(resource_container != nullptr);
				if (BCS_FAILED(rs = cache_cluster.add_resource_container(*resource_container, true))) // #NOTE: can succeed and return null
				{
					return rs;
				}
			}
			ASSERT(resource_container != nullptr);
		}
		else
		{
			ASSERT(resource.owner_tag.datum_index == 0xFFFFFFFF);
			ASSERT(resource.resource_salt = -1);
			ASSERT(resource.resource_type_index == -1);
			ASSERT(resource.control_alignment_bits == 0);
			ASSERT(resource.control_size == 0);
			ASSERT(resource.flags.is_clear());
			ASSERT(resource.page == -1);
			ASSERT(resource.root_fixup.get_type() == 0);
			ASSERT(resource.root_fixup.get_fixup_value() == 0);
			ASSERT(resource.control_fixups_block.count == 0);
			ASSERT(resource.interop_locations_block.count == 0);
			ASSERT(resource.priority_level_data_block.count == 0);
			debug_point;
		}
	}

	//// s_cache_file_resource_priority_data_block_block_struct priority_level_data = (*priority_level_datas)[0];
	//// byteswap(priority_level_data);
	//// const char* current_naive_resource_control_data_position = naive_resource_control_data + priority_level_data.naive_data_offset;

	//const s_render_texture_interop_definition_struct* render_texture_interop_definition_ptr = reinterpret_cast<const s_render_texture_interop_definition_struct*>(current_naive_resource_control_data_position);
	//const s_bitmap_texture_interop_resource_struct* bitmap_texture_interop_resource_ptr = reinterpret_cast<const s_bitmap_texture_interop_resource_struct*>(render_texture_interop_definition_ptr + 1);

	//s_render_texture_interop_definition_struct render_texture_interop_definition = *render_texture_interop_definition_ptr;
	//byteswap(render_texture_interop_definition);

	//s_bitmap_texture_interop_resource_struct bitmap_texture_interop_resource = *bitmap_texture_interop_resource_ptr;
	//byteswap(bitmap_texture_interop_resource);


	////FILE* f = fopen("compressed.bin", "wb");
	////fwrite(raw_resource_data, 1, raw_resource_data_size, f);
	////fflush(f);
	////fclose(f);

	//
	////FATAL_ERROR(L"not implemented");

	//debug_point;

	//e_tag_resource_fixup_type root_fixup_type = resource.root_fixup.get_type();
	//dword root_fixup_value = resource.root_fixup.get_fixup_value();

	debug_point;

	return rs;
}

BCS_RESULT c_halo4_tag_reader::export_resources()
{
	using namespace blofeld::xbox360_gen3;

	BCS_RESULT rs = BCS_S_OK;

	c_halo4_cache_cluster::t_resource_container_cache_reader_map::iterator resource_container_search = cache_cluster.resource_containers_by_cache_reader.find(&cache_reader);
	if (resource_container_search == cache_cluster.resource_containers_by_cache_reader.end())
	{
		return rs; // no work to do here		
	}

	std::vector<c_halo4_resource_container*> const& resource_containers = resource_container_search->second;

	c_typed_tag_block<s_cache_file_resource_page_struct> file_pages_block;
	const s_cache_file_resource_page_struct* file_pages;
	{
		const s_halo4_tag_global_instance_info* resource_gestalt_global_instance_info;
		if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, resource_gestalt_global_instance_info)))
		{
			return rs;
		}
		s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(resource_gestalt_global_instance_info->instance_info->instance_data);
		byteswap(resource_gestalt);

		const s_halo4_tag_global_instance_info* resource_layout_table_global_instance_info;
		if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG, resource_layout_table_global_instance_info)))
		{
			return rs;
		}

		if (resource_layout_table_global_instance_info->instance_info->instance_data)
		{
			s_cache_file_resource_layout_table_block_struct resource_layout_table = *static_cast<const s_cache_file_resource_layout_table_block_struct*>(resource_layout_table_global_instance_info->instance_info->instance_data);
			byteswap(resource_layout_table);

			file_pages_block = resource_layout_table.file_pages_block;
		}
		else
		{
			file_pages_block = resource_gestalt.file_pages_block;
		}

		if (BCS_FAILED(rs = page_offset_to_pointer(file_pages_block.address, *reinterpret_cast<const void**>(&file_pages))))
		{
			return rs;
		}
	}

	s_cache_file_buffer_info buffer_info;
	if (BCS_FAILED(rs = cache_reader.get_section_buffer(gen3::_cache_file_section_index_resource, buffer_info)))
	{
		return rs;
	}
	
	const s_cache_file_resource_page_struct* const file_pages_end = file_pages + file_pages_block.count;
	for (const s_cache_file_resource_page_struct* _current_file_page = file_pages; _current_file_page < file_pages_end; _current_file_page++)
	{
		s_cache_file_resource_page_struct file_page = *_current_file_page;
		byteswap(file_page);

		if (file_page.shared_file != -1) continue; // #TODO: traverse external files

		char* page_data = new char[__max(0x8000, file_page.size)];
		const char* page_file_data = buffer_info.begin + file_page.file_offset;

		e_compression_codec compression_codec = _compression_uncompressed;
		if (BCS_FAILED(rs = get_compression_codec_by_index(file_page.codec, compression_codec)))
		{
			return rs;
		}

		switch (compression_codec)
		{
		case _compression_uncompressed:
			ASSERT(file_page.size == file_page.file_size);
			memcpy(page_data, page_file_data, file_page.size);
			break;
		case _compression_xdkcompress:
			codec_inflate_lzx_xbox360(page_file_data, file_page.file_size, page_data, file_page.size);
			break;
		default:
			return BCS_E_NOT_IMPLEMENTED; // unknown compression codec
		}

		for (c_halo4_resource_container* resource_container : resource_containers)
		{
			unsigned long page_index = static_cast<unsigned long>(_current_file_page - file_pages);

			resource_container->digest_page(cache_reader, page_index, page_data);
		}

		delete page_data;
	}

	return rs;
}

BCS_RESULT c_halo4_tag_reader::resource_type_index_to_halo4_resource_type(long type_index, e_halo4_resource_type& resource_type)
{
	BCS_VALIDATE_ARGUMENT(type_index >= 0);

	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	using namespace blofeld::xbox360_gen3;

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	byteswap(resource_gestalt);

	if (static_cast<unsigned long>(type_index) >= resource_gestalt.resource_type_identifiers_block.count)
	{
		return BCS_E_FAIL;
	}

	resource_type = _resource_type_index_to_halo4_resource_type[type_index];

	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_reader::init_shared_files_table()
{
	using namespace blofeld::xbox360_gen3;
	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* resource_gestalt_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, resource_gestalt_global_instance_info)))
	{
		return rs;
	}

	const s_halo4_tag_global_instance_info* resource_layout_table_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG, resource_layout_table_global_instance_info)))
	{
		return rs;
	}

	c_typed_tag_block<s_cache_file_shared_file_block_block_struct> shared_files_block;
	if (resource_layout_table_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_layout_table_block_struct resource_layout_table = *static_cast<const s_cache_file_resource_layout_table_block_struct*>(resource_layout_table_global_instance_info->instance_info->instance_data);
		byteswap(resource_layout_table);

		shared_files_block = resource_layout_table.shared_files_block;
	}
	else if (resource_gestalt_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(resource_gestalt_global_instance_info->instance_info->instance_data);
		byteswap(resource_gestalt);

		shared_files_block = resource_gestalt.shared_files_block;
	}

	const s_cache_file_shared_file_block_block_struct* shared_files;
	if (BCS_FAILED(rs = page_offset_to_pointer(shared_files_block.address, *reinterpret_cast<const void**>(&shared_files))))
	{
		return rs;
	}

	_shared_file_index_to_cache_file_reader = new c_halo4_cache_file_reader * [shared_files_block.count];
	_shared_file_count = shared_files_block.count;

	for (unsigned long shared_file_index = 0; shared_file_index < shared_files_block.count; shared_file_index++)
	{
		s_cache_file_shared_file_block_block_struct shared_file = shared_files[shared_file_index];
		byteswap(shared_file);

		const char* dvd_relative_path = shared_file.dvd_relative_path.get_string();

		c_halo4_cache_file_reader* cache_file_reader = nullptr;
		cache_cluster.get_cache_reader_by_relative_path(dvd_relative_path, cache_file_reader);
		//if (BCS_FAILED(rs = cache_cluster.get_cache_reader_by_relative_path(dvd_relative_path, cache_file_reader)))
		//{
		//	return rs;
		//}

		_shared_file_index_to_cache_file_reader[shared_file_index] = cache_file_reader;

		debug_point;
	}

	return rs;
}

BCS_RESULT c_halo4_tag_reader::shared_file_index_to_cache_file_reader(long shared_file_index, c_halo4_cache_file_reader*& cache_file_reader)
{
	BCS_VALIDATE_ARGUMENT(shared_file_index >= -1);

	if (shared_file_index == -1)
	{
		cache_file_reader = &cache_reader;
	}
	else
	{
		if (static_cast<unsigned long>(shared_file_index) > _shared_file_count)
		{
			return BCS_E_OUT_OF_RANGE;
		}

		cache_file_reader = _shared_file_index_to_cache_file_reader[shared_file_index];
	}

	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_reader::get_interop_container_by_type_and_descriptor(e_halo4_interop_type interop_type, unsigned long descriptor, c_halo4_interop_container*& interop_container)
{

	for (c_halo4_interop_container** interop_container_iter = interop_containers; *interop_container_iter; interop_container_iter++)
	{
		if ((*interop_container_iter)->type == interop_type && (*interop_container_iter)->descriptor == descriptor)
		{
			interop_container = *interop_container_iter;
			return BCS_S_OK;
		}
	}
	return BCS_E_FAIL;
}

BCS_RESULT c_halo4_tag_reader::get_compression_codec_by_index(long codec_index, e_compression_codec& compression_codec)
{
	BCS_RESULT rs = BCS_S_OK;

	using namespace blofeld::xbox360_gen3;
	const s_halo4_tag_global_instance_info* resource_layout_table_global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG, resource_layout_table_global_instance_info)))
	{
		return rs;
	}

	c_typed_tag_block<s_cache_file_codec_identifier_block_block_struct> codec_identifiers_block;
	if (resource_layout_table_global_instance_info->instance_info->instance_data)
	{
		s_cache_file_resource_layout_table_block_struct resource_layout_table = *static_cast<const s_cache_file_resource_layout_table_block_struct*>(resource_layout_table_global_instance_info->instance_info->instance_data);
		byteswap(resource_layout_table);

		codec_identifiers_block = resource_layout_table.codec_identifiers_block;
	}
	else
	{
		const s_halo4_tag_global_instance_info* resource_gestalt_global_instance_info;
		if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, resource_gestalt_global_instance_info)))
		{
			return rs;
		}
		s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(resource_gestalt_global_instance_info->instance_info->instance_data);
		byteswap(resource_gestalt);

		codec_identifiers_block = resource_gestalt.codec_identifiers_block;
	}

	const s_cache_file_codec_identifier_block_block_struct* codec_identifiers;
	if (BCS_FAILED(rs = page_offset_to_pointer(codec_identifiers_block.address, *reinterpret_cast<const void**>(&codec_identifiers))))
	{
		return rs;
	}

	if (codec_index >= 0)
	{
		s_cache_file_codec_identifier_block_block_struct codec_identifier = codec_identifiers[codec_index];
		byteswap(codec_identifier);

		blofeld::s_tag_persistent_identifier identifier =
		{
			static_cast<unsigned long>(codec_identifier.identifier_part_0),
			static_cast<unsigned long>(codec_identifier.identifier_part_1),
			static_cast<unsigned long>(codec_identifier.identifier_part_2),
			static_cast<unsigned long>(codec_identifier.identifier_part_3)
		};

		if (memcmp(&identifier, &k_xdkcompress_codec_identifier, sizeof(identifier)) == 0)
		{
			compression_codec = _compression_xdkcompress;
		}
		else
		{
			return BCS_E_UNSUPPORTED; // unsupported codec
		}
	}

	return rs;
}
