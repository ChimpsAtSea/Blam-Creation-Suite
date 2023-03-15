#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_HALO3

c_halo3_cache_file_reader::c_halo3_cache_file_reader(const wchar_t* filepath, s_engine_platform_build engine_platform_build) :
	filepath(filepath),
	engine_platform_build(engine_platform_build),
	file(nullptr),
	file_info(),
	cache_cluster(nullptr),
	cache_file_header()
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

	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
	{
		xbox360_cache_file_header = *reinterpret_cast<halo3::xbox360::s_cache_file_header*>(file_info.file_view_begin);
		byteswap_inplace(xbox360_cache_file_header);
	}
	break;
	case _platform_type_pc_64bit:
	{
		pc_cache_file_header = *reinterpret_cast<halo3::pc::s_cache_file_header*>(file_info.file_view_begin);
	}
	break;
	default: throw BCS_E_UNSUPPORTED;
	}
}

c_halo3_cache_file_reader::~c_halo3_cache_file_reader()
{
	ASSERT_NO_THROW(BCS_SUCCEEDED(destroy_memory_mapped_file(file)));
}

BCS_RESULT c_halo3_cache_file_reader::get_build_info(s_cache_file_build_info& build_info) const
{
	build_info.file_version = cache_file_header.file_version;
	build_info.file_length = cache_file_header.file_length;
	build_info.file_compressed_length = cache_file_header.file_compressed_length;

	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
	{
		build_info.source_file = xbox360_cache_file_header.source_file;
		build_info.build_version = xbox360_cache_file_header.build;
		build_info.scenario_type = xbox360_cache_file_header.scenario_type;
		build_info.scenario_load_type = xbox360_cache_file_header.scenario_load_type;
		build_info.tracked_build = xbox360_cache_file_header.tracked_build;
		build_info.header_flags = xbox360_cache_file_header.header_flags;
		build_info.shared_file_type_flags = xbox360_cache_file_header.shared_file_type_flags;
		build_info.timestamp = xbox360_cache_file_header.timestamp;
		build_info.name = xbox360_cache_file_header.name;
		build_info.relative_path = xbox360_cache_file_header.relative_path;
		build_info.expected_base_address = xbox360_cache_file_header.expected_base_address;
		build_info.xdk_version = xbox360_cache_file_header.xdk_version;
		build_info.hash = xbox360_cache_file_header.hash;
		build_info.rsa = xbox360_cache_file_header.rsa;
	}
	break;
	default: throw BCS_E_UNSUPPORTED;
	}

	

	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_file_reader::get_debug_info(s_cache_file_debug_info& debug_info) const
{

	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_file_reader::get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const
{
	int32_t section_size = 0;
	int32_t section_offset_mask = 0;
	int32_t section_offset = 0;

	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
	{
		section_size = xbox360_cache_file_header.section_file_bounds[section_index].size;
		section_offset_mask = xbox360_cache_file_header.offset_masks[section_index];
		section_offset = xbox360_cache_file_header.section_file_bounds[section_index].offset;
	}
	break;
	default: throw BCS_E_UNSUPPORTED;
	}

	if (section_size == 0)
	{
		return BCS_E_UNSUPPORTED;
	}

	const char* section_begin = file_info.file_view_begin + section_offset + section_offset_mask;
	const char* section_end = section_begin + section_size;

	buffer_info.begin = section_begin;
	buffer_info.end = section_end;
	buffer_info.size = section_size;
	buffer_info.offset = section_offset;
	buffer_info.offset_mask = section_offset_mask;

	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_file_reader::get_buffer(e_cache_file_buffer_index buffer_index, s_cache_file_buffer_info& buffer_info) const
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
	case _resources_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_resource, buffer_info);
	case _tag_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_tags, buffer_info);
	case _localization_section_buffer:
		return get_section_buffer(gen3::_cache_file_section_index_localization, buffer_info);
	case _tag_post_link_buffer:
		buffer_info = {};
		break;
	case _tag_language_dependent_read_only_buffer:
		buffer_info = {};
		break;
	case _tag_language_dependent_read_write_buffer:
		buffer_info = {};
		break;
	case _tag_language_neutral_read_write_buffer:
		buffer_info = {};
		break;
	case _tag_language_neutral_write_combined_buffer:
		buffer_info = {};
		break;
	case _tag_language_neutral_read_only_buffer:
		buffer_info = {};
		break;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_buffers(s_cache_file_buffers_info& buffers_info) const
{
	for (int cache_file_buffer_index = 0; cache_file_buffer_index < k_num_cache_file_buffers; cache_file_buffer_index++)
	{
		get_buffer(static_cast<e_cache_file_buffer_index>(cache_file_buffer_index), buffers_info.buffer_infos[cache_file_buffer_index]);
	}

	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_file_reader::associate_cache_cluster(c_cache_cluster& target_cache_cluster)
{
	if (c_halo3_cache_cluster* halo3_cache_cluster = dynamic_cast<c_halo3_cache_cluster*>(&target_cache_cluster))
	{
		return associate_cache_cluster(*halo3_cache_cluster);
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_halo3_cache_file_reader::associate_cache_cluster(c_halo3_cache_cluster& target_cache_cluster)
{
	if (cache_cluster == nullptr)
	{
		cache_cluster = &target_cache_cluster;
		return BCS_S_OK;
	}
	return BCS_E_FAIL;
}

BCS_RESULT c_halo3_cache_file_reader::virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
	{
		relative_offset = static_cast<long>(virtual_address - xbox360_cache_file_header.expected_base_address);
	}
	return BCS_S_OK;
	}

	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const
{
	virtual_address = page_offset; // -cache_file_header.expected_base_address;

	return BCS_S_OK;
	//return BCS_E_NOT_IMPLEMENTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const
{
	return blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups);
}

BCS_RESULT c_halo3_cache_file_reader::get_tags_header_relative_offset(int32_t& tags_header_relative_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		BCS_FAIL_RETURN(virtual_address_to_relative_offset(xbox360_cache_file_header.tags_header_address, tags_header_relative_offset));
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_file_count(int32_t& file_count) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		file_count = xbox360_cache_file_header.file_count;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_string_id_index_buffer_count(int32_t& string_id_index_buffer_count) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		string_id_index_buffer_count = xbox360_cache_file_header.string_id_index_buffer_count;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_string_id_index_buffer_offset(int32_t& string_id_index_buffer_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		string_id_index_buffer_offset = xbox360_cache_file_header.string_id_index_buffer_offset;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_string_id_string_storage_offset(int32_t& string_id_string_storage_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		string_id_string_storage_offset = xbox360_cache_file_header.string_id_string_storage_offset;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_string_id_string_storage_size(int32_t& string_id_string_storage_size) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		string_id_string_storage_size = xbox360_cache_file_header.string_id_string_storage_size;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_file_table_indices_offset(int32_t& file_table_indices_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		file_table_indices_offset = xbox360_cache_file_header.file_table_indices_offset;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_file_table_offset(int32_t& file_table_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		file_table_offset = xbox360_cache_file_header.file_table_offset;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_halo3_cache_file_reader::get_file_table_length(int32_t& file_table_length) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_xbox_360:
		file_table_length = xbox360_cache_file_header.file_table_length;
		return BCS_S_OK;
	}
	return BCS_E_UNSUPPORTED;
}

#endif // BCS_BUILD_HIGH_LEVEL_HALO3
