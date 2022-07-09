#include "mandrilllib-private-pch.h"

c_halo3_cache_cluster::c_halo3_cache_cluster(c_halo3_cache_file_reader** cache_readers, unsigned long cache_reader_count, s_engine_platform_build engine_platform_build) :
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

	

	for (unsigned long cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_halo3_cache_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		cache_reader->associate_cache_cluster(*this);
	}

	for (unsigned long cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_halo3_cache_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_debug_section_buffer, temp_info)))
		{
			debug_readers[cache_reader] = new() c_halo3_debug_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_resources_section_buffer, temp_info)))
		{
			resource_readers[cache_reader] = new() c_halo3_resource_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_localization_section_buffer, temp_info)))
		{
			localization_readers[cache_reader] = new() c_halo3_localization_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_tag_section_buffer, temp_info)))
		{
			tag_readers[cache_reader] = new() c_halo3_tag_reader(*this, *cache_reader);
		}

		
	}

	for (c_halo3_cache_file_reader* cache_reader : this->cache_readers)
	{
		c_halo3_tag_reader* tag_reader;
		if (BCS_SUCCEEDED(get_tag_reader(*cache_reader, tag_reader)))
		{
			if (BCS_FAILED(rs = tag_reader->init_shared_files_table()))
			{
				throw(rs);
			}

			if (BCS_FAILED(rs = tag_reader->init_interop_table()))
			{
				throw(rs);
			}
			if (BCS_FAILED(rs = tag_reader->init_resource_table()))
			{
				throw(rs);
			}
		}
	}	
	
	for (c_halo3_cache_file_reader* cache_reader : this->cache_readers)
	{
		c_halo3_tag_reader* tag_reader;
		if (BCS_SUCCEEDED(get_tag_reader(*cache_reader, tag_reader)))
		{
			if (BCS_FAILED(rs = tag_reader->init_interops()))
			{
				throw(rs);
			}
			if (BCS_FAILED(rs = tag_reader->init_resources()))
			{
				throw(rs);
			}
		}
	}
}

c_halo3_cache_cluster::~c_halo3_cache_cluster()
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

BCS_RESULT c_halo3_cache_cluster::get_debug_reader(c_halo3_cache_file_reader& cache_reader, c_halo3_debug_reader*& debug_reader)
{
	t_debug_readers::const_iterator search_result = debug_readers.find(&cache_reader);
	if (search_result == debug_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	debug_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_tag_reader(c_halo3_cache_file_reader& cache_reader, c_halo3_tag_reader*& tag_reader)
{
	t_tag_readers::const_iterator search_result = tag_readers.find(&cache_reader);
	if (search_result == tag_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	tag_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_resource_reader(c_halo3_cache_file_reader& cache_reader, c_halo3_resource_reader*& resource_reader)
{
	t_resource_readers::const_iterator search_result = resource_readers.find(&cache_reader);
	if (search_result == resource_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	resource_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_localization_reader(c_halo3_cache_file_reader& cache_reader, c_halo3_localization_reader*& localization_reader)
{
	t_localization_readers::const_iterator search_result = localization_readers.find(&cache_reader);
	if (search_result == localization_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	localization_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const
{
	tag_groups = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build);

	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_engine_platform_build(s_engine_platform_build& engine_platform_build) const
{
	engine_platform_build = this->engine_platform_build;
	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_cache_readers(c_cache_file_reader* const*& cache_readers, unsigned long& cache_reader_count) const
{
	cache_readers = reinterpret_cast<c_cache_file_reader* const*>(this->cache_readers.data());
	cache_reader_count = static_cast<unsigned long>(this->cache_readers.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_cache_readers(c_halo3_cache_file_reader* const*& cache_readers, unsigned long& cache_reader_count) const
{
	cache_readers = this->cache_readers.data();
	cache_reader_count = static_cast<unsigned long>(this->cache_readers.size());
	return BCS_S_OK;
}

BCS_RESULT c_halo3_cache_cluster::get_cache_reader_by_relative_path(const char* relative_path, c_halo3_cache_file_reader*& out_cache_reader)
{
	for (c_halo3_cache_file_reader* cache_reader : cache_readers)
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

BCS_RESULT c_halo3_cache_cluster::get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader)
{
	return get_debug_reader(*static_cast<c_halo3_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo3_debug_reader**>(&debug_reader));
}

BCS_RESULT c_halo3_cache_cluster::get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader)
{
	return get_tag_reader(*static_cast<c_halo3_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo3_tag_reader**>(&tag_reader));
}

BCS_RESULT c_halo3_cache_cluster::get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader)
{
	return get_resource_reader(*static_cast<c_halo3_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo3_resource_reader**>(&resource_reader));
}

BCS_RESULT c_halo3_cache_cluster::get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader)
{
	return get_localization_reader(*static_cast<c_halo3_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo3_localization_reader**>(&localization_reader));
}
