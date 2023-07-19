#include "highlevelcachefileserialization-private-pch.h"

#ifdef BCS_BUILD_HIGH_LEVEL_ELDORADO

c_eldorado_cache_cluster::c_eldorado_cache_cluster(c_eldorado_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build) :
	engine_platform_build(engine_platform_build),
	cache_readers(cache_readers, cache_readers + cache_reader_count),
	debug_readers(),
	tag_readers(),
	resource_readers(),
	localization_readers()
{
	BCS_RESULT rs;
	BCS_VALIDATE_ARGUMENT_THROW(cache_readers);
	BCS_VALIDATE_ARGUMENT_THROW(cache_reader_count > 0);

	s_cache_file_buffer_info temp_info;

	

	for (uint32_t cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_eldorado_cache_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		cache_reader->associate_cache_cluster(*this);
	}

	for (uint32_t cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_eldorado_cache_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		t_memory_mapped_file* resources_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_resources];
		t_memory_mapped_file* textures_resources_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_textures_resources];
		t_memory_mapped_file* textures_b_resources_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_textures_b_resources];
		t_memory_mapped_file* audio_resources_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_audio_resources];
		t_memory_mapped_file* video_resources_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_video_resources];
		t_memory_mapped_file* string_ids_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_string_ids];
		t_memory_mapped_file* tags_list_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_tags_list];
		t_memory_mapped_file* tags_cache_memory_mapped_file = cache_reader->memory_mapped_files[_eldorado_file_type_tags_cache];

		if (resources_memory_mapped_file || 
			textures_resources_memory_mapped_file || 
			textures_b_resources_memory_mapped_file || 
			audio_resources_memory_mapped_file || 
			video_resources_memory_mapped_file)
		{
			resource_readers[cache_reader] = new() c_eldorado_resource_reader(*this, *cache_reader);
		}

		if (string_ids_memory_mapped_file || tags_list_memory_mapped_file)
		{
			debug_readers[cache_reader] = new() c_eldorado_debug_reader(*this, *cache_reader);
		}

		if (tags_cache_memory_mapped_file)
		{
			tag_readers[cache_reader] = new() c_eldorado_tag_reader(*this, *cache_reader);
		}
	}

	for (c_eldorado_cache_file_reader* cache_reader : this->cache_readers)
	{
		c_eldorado_tag_reader* tag_reader;
		if (BCS_SUCCEEDED(get_tag_reader(*cache_reader, tag_reader)))
		{
			if (BCS_FAILED(rs = tag_reader->read_header()))
			{
				throw(rs);
			}
			if (BCS_FAILED(rs = tag_reader->read_groups()))
			{
				throw(rs);
			}
			if (BCS_FAILED(rs = tag_reader->read_instances()))
			{
				throw(rs);
			}
		}
	}
}

c_eldorado_cache_cluster::~c_eldorado_cache_cluster()
{
	for (auto& keyval : debug_readers)
	{
		delete keyval.second;
	}
	for (auto& keyval : resource_readers)
	{
		delete keyval.second;
	}
	for (auto& keyval : localization_readers)
	{
		delete keyval.second;
	}
	for (auto& keyval : tag_readers)
	{
		delete keyval.second;
	}
}

BCS_RESULT c_eldorado_cache_cluster::get_debug_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_debug_reader*& debug_reader)
{
	t_debug_readers::const_iterator search_result = debug_readers.find(&cache_reader);
	if (search_result == debug_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	debug_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_tag_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_tag_reader*& tag_reader)
{
	t_tag_readers::const_iterator search_result = tag_readers.find(&cache_reader);
	if (search_result == tag_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	tag_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_resource_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_resource_reader*& resource_reader)
{
	t_resource_readers::const_iterator search_result = resource_readers.find(&cache_reader);
	if (search_result == resource_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	resource_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_localization_reader(c_eldorado_cache_file_reader& cache_reader, c_eldorado_localization_reader*& localization_reader)
{
	t_localization_readers::const_iterator search_result = localization_readers.find(&cache_reader);
	if (search_result == localization_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	localization_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT c_eldorado_cache_cluster::get_engine_platform_build(s_engine_platform_build& engine_platform_build) const
{
	engine_platform_build = this->engine_platform_build;
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_cache_readers(c_cache_file_reader* const*& cache_readers, uint32_t& cache_reader_count) const
{
	cache_readers = reinterpret_cast<c_cache_file_reader* const*>(this->cache_readers.data());
	cache_reader_count = static_cast<unsigned long>(this->cache_readers.size());
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_cache_readers(c_eldorado_cache_file_reader* const*& cache_readers, uint32_t& cache_reader_count) const
{
	cache_readers = this->cache_readers.data();
	cache_reader_count = static_cast<unsigned long>(this->cache_readers.size());
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_postprocessing_fixups(c_postprocessing_fixup const* const*& out_fixups, uint32_t& fixup_count) const
{
	if (engine_platform_build == s_engine_platform_build{ _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 })
	{
		out_fixups = eldorado_1_106708_cert_ms23::postprocessing_fixups;
		fixup_count = eldorado_1_106708_cert_ms23::num_postprocessing_fixups;
	}
	else
	{
		out_fixups = nullptr;
		fixup_count = 0;
	}
	return BCS_S_OK;
}

BCS_RESULT c_eldorado_cache_cluster::get_cache_reader_by_relative_path(const char* relative_path, c_eldorado_cache_file_reader*& out_cache_reader)
{
	for (c_eldorado_cache_file_reader* cache_reader : cache_readers)
	{
		s_cache_file_build_info build_info;
		BCS_FAIL_RETURN(cache_reader->get_build_info(build_info));

		c_fixed_path cache_relative_path;
		cache_relative_path.format("maps\\%s.map", build_info.name.get_buffer());

		if (strcmp(cache_relative_path.c_str(), relative_path) == 0)
		{
			out_cache_reader = cache_reader;
			return BCS_S_OK;
		}

		//if (strcmp(build_info.relative_path.get_string(), relative_path) == 0)
		//{
		//	cache_reader = entry.cache_reader;
		//	return rs;
		//}
	}

	return BCS_E_NOT_FOUND; // failed to find a cache file
}

BCS_RESULT c_eldorado_cache_cluster::get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader)
{
	return get_debug_reader(*static_cast<c_eldorado_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_eldorado_debug_reader**>(&debug_reader));
}

BCS_RESULT c_eldorado_cache_cluster::get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader)
{
	return get_tag_reader(*static_cast<c_eldorado_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_eldorado_tag_reader**>(&tag_reader));
}

BCS_RESULT c_eldorado_cache_cluster::get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader)
{
	return get_resource_reader(*static_cast<c_eldorado_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_eldorado_resource_reader**>(&resource_reader));
}

BCS_RESULT c_eldorado_cache_cluster::get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader)
{
	return get_localization_reader(*static_cast<c_eldorado_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_eldorado_localization_reader**>(&localization_reader));
}

#endif // BCS_BUILD_HIGH_LEVEL_ELDORADO
