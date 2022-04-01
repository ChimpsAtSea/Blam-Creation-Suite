#include "mandrilllib-private-pch.h"

c_halo1_cache_file_reader::c_halo1_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build) :
	is_resource_file(false),
	filepath(filepath),
	engine_platform_build(engine_platform_build),
	file(nullptr),
	file_info(),
	cache_cluster(nullptr),
	cache_file_header(nullptr),
	cache_file_resource_header(nullptr)
{
	BCS_RESULT rs;
	if (BCS_FAILED(rs = create_memory_mapped_file(filepath, true, file)))
	{
		throw(rs);
	}
	if (BCS_FAILED(rs = get_memory_mapped_file_info(file, file_info)))
	{
		throw(rs);
	}

	if (engine_platform_build.build == _build_halo1_demo)
	{
		halo1::demo::s_cache_file_header& demo_cache_file_header = *reinterpret_cast<halo1::demo::s_cache_file_header*>(file_info.file_view_begin);
		cache_file_header = new() c_halo1_header_wrapper(demo_cache_file_header);
	}
	else
	{
		halo1::pc::s_cache_file_header& pc_cache_file_header = *reinterpret_cast<halo1::pc::s_cache_file_header*>(file_info.file_view_begin);

		if (pc_cache_file_header.header_signature == k_cache_header_signature)
		{
			cache_file_header = new() c_halo1_header_wrapper(pc_cache_file_header);
		}
		else
		{
			cache_file_resource_header = reinterpret_cast<halo1::s_cache_file_resource_header*>(file_info.file_view_begin);
			is_resource_file = true;
		}
	}
}

c_halo1_cache_file_reader::~c_halo1_cache_file_reader()
{
	ASSERT_NO_THROW(BCS_SUCCEEDED(destroy_memory_mapped_file(file)));
	delete cache_file_header;
}

BCS_RESULT c_halo1_cache_file_reader::get_build_info(s_cache_file_build_info& build_info) const
{
	build_info = {};
	if(cache_file_header)
	{
		build_info.file_version = cache_file_header->file_version;
		build_info.file_length = cache_file_header->file_length;
		//build_info.file_compressed_length = cache_file_header->file_compressed_length;
		//build_info.source_file = cache_file_header->source_file;
		build_info.build_version = cache_file_header->build_version;
		//build_info.scenario_type = cache_file_header->scenario_type;
		//build_info.scenario_load_type = cache_file_header->scenario_load_type;
		//build_info.tracked_build = cache_file_header->tracked_build;
		//build_info.header_flags = cache_file_header->header_flags;
		//build_info.shared_file_type_flags = cache_file_header->shared_file_type_flags;
		//build_info.timestamp = cache_file_header->timestamp;
		build_info.name = cache_file_header->scenario_name;
		//build_info.relative_path = cache_file_header->relative_path;
		//build_info.expected_base_address = cache_file_header->expected_base_address;
		//build_info.xdk_version = cache_file_header->xdk_version;
		//build_info.hash = cache_file_header->hash;
		//build_info.rsa = cache_file_header->rsa;
	}
	else
	{
		switch (cache_file_resource_header->type)
		{
		case 0:
			build_info.name = "unknown";
			break;
		case 1:
			build_info.name = "bitmaps";
			break;
		case 2:
			build_info.name = "sounds";
			break;
		case 3:
			build_info.name = "loc";
			break;
		}
	}

	

	return BCS_S_OK;
}

BCS_RESULT c_halo1_cache_file_reader::get_debug_info(s_cache_file_debug_info& debug_info) const
{

	return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_halo1_cache_file_reader::get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const
{
	if (is_resource_file)
	{
		if (section_index == gen3::_cache_file_section_index_debug)
		{
			buffer_info.begin = file_info.file_view_begin + cache_file_resource_header->tag_names_offset;
			buffer_info.end = nullptr;
			buffer_info.size = 0xFFFFFFFFul;
			buffer_info.offset = 0;
			buffer_info.offset_mask = 0;

			return BCS_S_OK;
		}
		if (section_index == gen3::_cache_file_section_index_tags)
		{
			buffer_info.begin = file_info.file_view_begin + cache_file_resource_header->tag_data_offset;
			buffer_info.end = nullptr;
			buffer_info.size = 0xFFFFFFFFul;
			buffer_info.offset = 0;
			buffer_info.offset_mask = 0;

			return BCS_S_OK;
		}
	}
	else
	{
		if (section_index == gen3::_cache_file_section_index_tags || section_index == gen3::_cache_file_section_index_debug)
		{
			buffer_info.begin = file_info.file_view_begin + cache_file_header->tag_data_offset;
			buffer_info.end = buffer_info.begin + cache_file_header->tag_data_size;
			buffer_info.size = cache_file_header->tag_data_size;
			buffer_info.offset = 0;
			buffer_info.offset_mask = 0;

			return BCS_S_OK;
		}
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo1_cache_file_reader::get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const
{
	switch (buffer_index)
	{
	case _cache_file_buffer:
		buffer_info.begin = file_info.file_view_begin;
		buffer_info.end = file_info.file_view_end;
		buffer_info.size = static_cast<unsigned long>(file_info.file_size);
		return BCS_S_OK;
	case _debug_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_debug, buffer_info);
	case _tag_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_tags, buffer_info);
	case _resources_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_resource, buffer_info);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo1_cache_file_reader::get_buffers(s_cache_file_buffers_info& buffers_info) const
{
	for (int cache_file_buffer_index = 0; cache_file_buffer_index < k_num_cache_file_buffers; cache_file_buffer_index++)
	{
		get_buffer(static_cast<e_cache_file_buffer_index>(cache_file_buffer_index), buffers_info.buffer_infos[cache_file_buffer_index]);
	}

	return BCS_S_OK;
}

BCS_RESULT c_halo1_cache_file_reader::associate_cache_cluster(c_cache_cluster& target_cache_cluster)
{
	if (c_halo1_cache_cluster* halo1_cache_cluster = dynamic_cast<c_halo1_cache_cluster*>(&target_cache_cluster))
	{
		return associate_cache_cluster(*halo1_cache_cluster);
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_halo1_cache_file_reader::associate_cache_cluster(c_halo1_cache_cluster& target_cache_cluster)
{
	if (cache_cluster == nullptr)
	{
		cache_cluster = &target_cache_cluster;
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT c_halo1_cache_file_reader::virtual_address_to_relative_offset(long long virtual_address, long& relative_offset) const
{
	BCS_RESULT rs = BCS_S_OK;

	s_cache_file_buffer_info buffer_info;
	if (BCS_FAILED(rs = get_buffer(_tag_section_buffer, buffer_info)))
	{
		return rs;
	}

	halo1::s_cache_file_tags_header tags_header = *reinterpret_cast<const halo1::s_cache_file_tags_header*>(buffer_info.begin);

	relative_offset = static_cast<long>(virtual_address - tags_header.tag_instances_address + sizeof(halo1::s_cache_file_tags_header));

	return rs;
}

BCS_RESULT c_halo1_cache_file_reader::page_offset_to_virtual_address(unsigned long page_offset, long long& virtual_address) const
{
	virtual_address = page_offset; // -cache_file_header->expected_base_address;

	return BCS_S_OK;
	//return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_halo1_cache_file_reader::get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const
{
	tag_groups = blofeld::tag_groups[engine_platform_build.engine_type];

	return BCS_S_OK;
}

BCS_RESULT c_halo1_cache_file_reader::get_cache_file_resource_instance(unsigned long index, const halo1::s_cache_file_resource_instance*& cache_file_resource_instance)
{
	if (!is_resource_file)
	{
		return BCS_E_UNSUPPORTED;
	}
	if (index > cache_file_resource_header->tag_instance_count)
	{
		return BCS_E_FAIL;
	}
	
	BCS_RESULT rs = BCS_S_OK;

	s_cache_file_buffer_info tag_section_buffer_info;
	if (BCS_FAILED(rs = get_buffer(_tag_section_buffer, tag_section_buffer_info)))
	{
		return rs;
	}

	const halo1::s_cache_file_resource_instance* tag_instances = reinterpret_cast<const halo1::s_cache_file_resource_instance*>(tag_section_buffer_info.begin);
	cache_file_resource_instance = tag_instances + index;

	return rs;
}

BCS_RESULT c_halo1_cache_file_reader::get_cache_file_resource_instance_data(unsigned long index, const void*& tag_instance_data)
{
	BCS_RESULT rs = BCS_S_OK;

	const halo1::s_cache_file_resource_instance* cache_file_resource_instance;
	if (BCS_FAILED(rs = get_cache_file_resource_instance(index, cache_file_resource_instance)))
	{
		return rs;
	}

	s_cache_file_buffer_info cache_file_buffer_info;
	if (BCS_FAILED(rs = get_buffer(_cache_file_buffer, cache_file_buffer_info)))
	{
		return rs;
	}

	tag_instance_data = cache_file_buffer_info.begin + cache_file_resource_instance->address;

	return rs;
}

BCS_RESULT c_halo1_cache_file_reader::get_cache_file_resource_instance_name(unsigned long index, const char*& tag_instance_name)
{
	BCS_RESULT rs = BCS_S_OK;

	const halo1::s_cache_file_resource_instance* cache_file_resource_instance;
	if (BCS_FAILED(rs = get_cache_file_resource_instance(index, cache_file_resource_instance)))
	{
		return rs;
	}

	s_cache_file_buffer_info debug_section_buffer_info;
	if (BCS_FAILED(rs = get_buffer(_debug_section_buffer, debug_section_buffer_info)))
	{
		return rs;
	}

	tag_instance_name = debug_section_buffer_info.begin + cache_file_resource_instance->name_address;

	return rs;
}
