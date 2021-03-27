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
	interop_containers(nullptr)
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

		const char* tag_name;
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

	if (type_index >= resource_gestalt.interop_type_identifiers_block.count)
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
	BCS_RESULT rs = BCS_S_OK;

	const s_halo4_tag_global_instance_info* global_instance_info;
	if (BCS_FAILED(rs = get_global_instance_info(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG, global_instance_info)))
	{
		return rs;
	}

	using namespace blofeld::xbox360_gen3;

	s_cache_file_resource_gestalt_block_struct resource_gestalt = *static_cast<const s_cache_file_resource_gestalt_block_struct*>(global_instance_info->instance_info->instance_data);
	byteswap(resource_gestalt);

	const s_cache_file_resource_data_block_block_struct* resources;
	if (BCS_FAILED(rs = page_offset_to_pointer(resource_gestalt.resources_block.address, *reinterpret_cast<const void**>(&resources))))
	{
		throw(rs);
	}

	for (unsigned long resource_index = 0; resource_index < resource_gestalt.resources_block.count; resource_index++)
	{
		s_cache_file_resource_data_block_block_struct resource = resources[resource_index];
		byteswap(resource);
		
		e_tag_resource_fixup_type type = resource.root_fixup.get_type();
		dword fixup_value = resource.root_fixup.get_fixup_value();

		debug_point;
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

	if (type_index >= resource_gestalt.resource_type_identifiers_block.count)
	{
		return BCS_E_FAIL;
	}

	resource_type = _resource_type_index_to_halo4_resource_type[type_index];
	
	return BCS_S_OK;
}

BCS_RESULT c_halo4_tag_reader::get_interop_container_by_type_and_descriptor(e_halo4_interop_type interop_type, unsigned long descriptor, c_halo4_interop_container*& interop_container)
{

	for (c_halo4_interop_container** interop_container_iter = interop_containers; *interop_container_iter; interop_container_iter++)
	{
		if ((*interop_container_iter)->type == interop_type&& (*interop_container_iter)->descriptor == descriptor)
		{
			interop_container = *interop_container_iter;
			return BCS_S_OK;
		}
	}
	return BCS_E_FAIL;
}

c_halo4_interop_container::c_halo4_interop_container(e_halo4_interop_type type, unsigned long descriptor, const void* data) :
	h_interop(),
	type(type),
	descriptor(descriptor),
	data(data)
{

}

c_halo4_interop_container::~c_halo4_interop_container()
{

}

c_halo4_vectorart_vertex_buffer_interop::c_halo4_vectorart_vertex_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data) :
	c_halo4_interop_container(_halo4_vectorart_vertex_buffer_interop, descriptor, data),
	vertex_data(),
	vertex_data_size()
{
	using namespace blofeld::xbox360_gen3;
	s_vectorartVertexBufferDescriptorStruct interop_data = *static_cast<const s_vectorartVertexBufferDescriptorStruct*>(data);
	byteswap(interop_data);

	const void* source_vertex_data;
	tag_reader.page_offset_to_pointer(interop_data.vertices.address, source_vertex_data);

	vertex_data_size = interop_data.vertices.size;
	vertex_data = new char[vertex_data_size];
	memcpy(vertex_data, source_vertex_data, vertex_data_size);

	debug_point;
}

c_halo4_vectorart_vertex_buffer_interop::~c_halo4_vectorart_vertex_buffer_interop()
{

}

c_halo4_polyart_vertex_buffer_interop::c_halo4_polyart_vertex_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data) :
	c_halo4_interop_container(_halo4_polyart_vertex_buffer_interop, descriptor, data),
	vertex_data(),
	vertex_data_size(),
	vertex_type()
{
	using namespace blofeld::xbox360_gen3;
	s_polyartVertexBufferDescriptorStruct interop_data = *static_cast<const s_polyartVertexBufferDescriptorStruct*>(data);
	byteswap(interop_data);

	const void* source_vertex_data;
	tag_reader.page_offset_to_pointer(interop_data.vertices.address, source_vertex_data);

	vertex_data_size = interop_data.vertices.size;
	vertex_data = new char[vertex_data_size];
	memcpy(vertex_data, source_vertex_data, vertex_data_size);
	vertex_type = interop_data.vertex_type;

	debug_point;
}

c_halo4_polyart_vertex_buffer_interop::~c_halo4_polyart_vertex_buffer_interop()
{
	delete vertex_data;
}

c_halo4_polyart_index_buffer_interop::c_halo4_polyart_index_buffer_interop(c_halo4_tag_reader& tag_reader, unsigned long descriptor, const void* data) :
	c_halo4_interop_container(_halo4_polyart_index_buffer_interop, descriptor, data),
	index_data(),
	index_data_size()
{
	using namespace blofeld::xbox360_gen3;
	s_polyartIndexBufferDescriptorStruct interop_data = *static_cast<const s_polyartIndexBufferDescriptorStruct*>(data);
	byteswap(interop_data);

	const void* source_index_data;
	tag_reader.page_offset_to_pointer(interop_data.index_data.address, source_index_data);

	index_data_size = interop_data.index_data.size;
	index_data = new char[index_data_size];
	memcpy(index_data, source_index_data, index_data_size);

	debug_point;
}

c_halo4_polyart_index_buffer_interop::~c_halo4_polyart_index_buffer_interop()
{
	delete index_data;
}
