#include "highlevelcachefileserialization-private-pch.h"

c_eldorado_cache_file_reader::c_eldorado_cache_file_reader(const wchar_t* _directory, s_engine_platform_build _engine_platform_build) :
	directory(wcsdup(_directory)),
	engine_platform_build(_engine_platform_build),
	memory_mapped_files(),
	memory_mapped_file_infos(),
	cache_cluster(nullptr),
	tag_groups(nullptr)
{
	BCS_RESULT rs;

	if (BCS_FAILED(rs = blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups)))
	{
		throw(rs);
	}

	for (unsigned int eldorado_file_index = 0; eldorado_file_index < k_eldorado_num_files; eldorado_file_index++)
	{
		const char* eldorado_relative_file_path = eldorado_relative_file_paths[eldorado_file_index];
		c_fixed_wide_path eldorado_file_path;
		eldorado_file_path.format(L"%s\\%S", directory, eldorado_relative_file_path);

		t_memory_mapped_file*& memory_mapped_file = memory_mapped_files[eldorado_file_index];
		if (BCS_FAILED(rs = create_memory_mapped_file(eldorado_file_path, true, memory_mapped_file)))
		{
			memory_mapped_file = nullptr;
			switch (eldorado_file_index)
			{
			case _eldorado_file_type_resources:
			case _eldorado_file_type_textures_resources:
			case _eldorado_file_type_textures_b_resources:
			case _eldorado_file_type_audio_resources:
			case _eldorado_file_type_video_resources:
			case _eldorado_file_type_string_ids:
			case _eldorado_file_type_tags_cache:
				throw(rs);
			}
		}
		else
		{
			s_memory_mapped_file_info& memory_mapped_file_info = memory_mapped_file_infos[eldorado_file_index];
			if (BCS_FAILED(rs = get_memory_mapped_file_info(memory_mapped_file, memory_mapped_file_info)))
			{
				throw(rs);
			}

			switch (eldorado_file_index)
			{
			case _eldorado_file_type_resources:
			case _eldorado_file_type_textures_resources:
			case _eldorado_file_type_textures_b_resources:
			case _eldorado_file_type_audio_resources:
			case _eldorado_file_type_video_resources:
			case _eldorado_file_type_string_ids:
			case _eldorado_file_type_tags_list:
			case _eldorado_file_type_tags_cache:
				break;
			}
		}

		debug_point;
	}
}

c_eldorado_cache_file_reader::~c_eldorado_cache_file_reader()
{
	untracked_free(directory);

	for (unsigned int eldorado_file_index = 0; eldorado_file_index < k_eldorado_num_files; eldorado_file_index++)
	{
		if (t_memory_mapped_file*& memory_mapped_file = memory_mapped_files[eldorado_file_index])
		{
			BCS_RESULT rs = destroy_memory_mapped_file(memory_mapped_file);
			ASSERT_NO_THROW(BCS_SUCCEEDED(rs));
		}
	}
}

BCS_RESULT c_eldorado_cache_file_reader::get_section_buffer(gen3::e_cache_file_section section_index, s_cache_file_buffer_info& buffer_info) const
{
	switch (section_index)
	{
	case gen3::_cache_file_section_index_tags:
		if (t_memory_mapped_file* tags_cache_file = memory_mapped_files[_eldorado_file_type_tags_cache])
		{
			s_memory_mapped_file_info const& memory_mapped_file_info = memory_mapped_file_infos[_eldorado_file_type_tags_cache];
			buffer_info = {};
			buffer_info.begin = memory_mapped_file_info.file_view_begin;
			buffer_info.end = memory_mapped_file_info.file_view_end;
			buffer_info.size = memory_mapped_file_info.file_size;
			return BCS_S_OK;
		}
		break;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_eldorado_cache_file_reader::associate_cache_cluster(c_cache_cluster& target_cache_cluster)
{
	if (c_eldorado_cache_cluster* eldorado_cache_cluster = dynamic_cast<c_eldorado_cache_cluster*>(&target_cache_cluster))
	{
		return associate_cache_cluster(*eldorado_cache_cluster);
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_eldorado_cache_file_reader::associate_cache_cluster(c_eldorado_cache_cluster& target_cache_cluster)
{
	if (cache_cluster == nullptr)
	{
		cache_cluster = &target_cache_cluster;
		return BCS_S_OK;
	}
	return BCS_E_FAIL;
}

BCS_RESULT c_eldorado_cache_file_reader::virtual_address_to_relative_offset(int64_t virtual_address, int32_t& relative_offset) const
{
	switch (engine_platform_build.platform_type)
	{
	case _platform_type_pc_32bit:
		relative_offset = virtual_address;
		return BCS_S_OK;
	}

	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_eldorado_cache_file_reader::page_offset_to_virtual_address(uint32_t page_offset, int64_t& virtual_address) const
{
	virtual_address = page_offset;

	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_file_reader::get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const
{
	return blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups);
}
