#include "mandrilllib-private-pch.h"
#include "infinite_cache_cluster.h"

c_infinite_cache_cluster::c_infinite_cache_cluster(c_infinite_module_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build) :
	engine_platform_build(engine_platform_build),
	cache_readers(cache_readers, cache_readers + cache_reader_count),
	debug_readers(),
	tag_readers(),
	resource_readers(),
	localization_readers()
{
	BCS_VALIDATE_ARGUMENT_THROW(cache_readers);
	BCS_VALIDATE_ARGUMENT_THROW(cache_reader_count > 0);



	for (uint32_t cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_infinite_module_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		cache_reader->associate_cache_cluster(*this);
	}

	// #TODO: multithread this
	for (uint32_t cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		s_cache_file_buffer_info temp_info;

		c_infinite_module_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_debug_section_buffer, temp_info)))
		{
			debug_readers[cache_reader] = new() c_infinite_debug_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_resources_section_buffer, temp_info)))
		{
			resource_readers[cache_reader] = new() c_infinite_resource_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_localization_section_buffer, temp_info)))
		{
			localization_readers[cache_reader] = new() c_infinite_localization_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_tag_section_buffer, temp_info)))
		{
			tag_readers[cache_reader] = new() c_infinite_tag_reader(*this, *cache_reader);
		}

		
	}

	for (c_infinite_module_file_reader* cache_reader : this->cache_readers)
	{
		c_infinite_tag_reader* tag_reader;
		if (BCS_SUCCEEDED(get_tag_reader(*cache_reader, tag_reader)))
		{
			//if (BCS_FAILED(rs = tag_reader->init_shared_files_table()))
			//{
			//	throw(rs);
			//}

			//if (BCS_FAILED(rs = tag_reader->init_interop_table()))
			//{
			//	throw(rs);
			//}
			//if (BCS_FAILED(rs = tag_reader->init_resource_table()))
			//{
			//	throw(rs);
			//}
		}
	}

	for (c_infinite_module_file_reader* cache_reader : this->cache_readers)
	{
		c_infinite_tag_reader* tag_reader;
		if (BCS_SUCCEEDED(get_tag_reader(*cache_reader, tag_reader)))
		{
			//if (BCS_FAILED(rs = tag_reader->init_interops()))
			//{
			//	throw(rs);
			//}
			//if (BCS_FAILED(rs = tag_reader->init_resources()))
			//{
			//	throw(rs);
			//}
			//if (BCS_FAILED(rs = tag_reader->export_resources()))
			//{
			//	throw(rs);
			//}
		}
	}

	uint32_t duplicate_id_count = 0;
	for (c_infinite_module_file_reader* module_file_reader : this->cache_readers)
	{
		c_infinite_tag_reader* tag_reader;
		BCS_RESULT rs = BCS_S_OK;
		if (BCS_SUCCEEDED(rs = get_tag_reader(*module_file_reader, tag_reader)))
		{
			c_infinite_tag_instance** tag_instances;
			uint32_t num_tag_instances;
			if (BCS_FAILED(rs = tag_reader->get_tag_instances(tag_instances, num_tag_instances)))
			{
				throw rs;
			}

			for (uint32_t tag_instance_index = 0; tag_instance_index < num_tag_instances; tag_instance_index++)
			{
				c_infinite_tag_instance& tag_instance = *tag_instances[tag_instance_index];
				int32_t global_tag_id;
				if (BCS_FAILED(rs = tag_instance.get_global_tag_id(global_tag_id)))
				{
					throw rs;
				}
				//DEBUG_ASSERT(tag_instances_by_global_id.find(global_tag_id) == tag_instances_by_global_id.end());
				if (tag_instances_by_global_id.find(global_tag_id) != tag_instances_by_global_id.end())
				{
					duplicate_id_count++;
				}
				tag_instances_by_global_id[global_tag_id] = &tag_instance;
			}
		}
	}
	if (duplicate_id_count > 0)
	{
		console_write_line("Duplicate tags %u", duplicate_id_count);
	}
}

c_infinite_cache_cluster::~c_infinite_cache_cluster()
{
	for (auto& keyval : debug_readers)
	{
		delete keyval.second;
	}
	for (auto& keyval : tag_readers)
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
}

BCS_RESULT c_infinite_cache_cluster::get_debug_reader(c_infinite_module_file_reader& cache_reader, c_infinite_debug_reader*& debug_reader)
{
	t_debug_readers::const_iterator search_result = debug_readers.find(&cache_reader);
	if (search_result == debug_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	debug_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_tag_reader(c_infinite_module_file_reader& cache_reader, c_infinite_tag_reader*& tag_reader)
{
	t_tag_readers::const_iterator search_result = tag_readers.find(&cache_reader);
	if (search_result == tag_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	tag_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_resource_reader(c_infinite_module_file_reader& cache_reader, c_infinite_resource_reader*& resource_reader)
{
	t_resource_readers::const_iterator search_result = resource_readers.find(&cache_reader);
	if (search_result == resource_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	resource_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_localization_reader(c_infinite_module_file_reader& cache_reader, c_infinite_localization_reader*& localization_reader)
{
	t_localization_readers::const_iterator search_result = localization_readers.find(&cache_reader);
	if (search_result == localization_readers.end())
	{
		return BCS_E_NOT_FOUND;
	}
	localization_reader = search_result->second;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_blofeld_tag_groups(const blofeld::s_tag_group**& tag_groups) const
{
	tag_groups = blofeld::get_tag_groups_by_engine_platform_build(engine_platform_build);

	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_engine_platform_build(s_engine_platform_build& engine_platform_build) const
{
	engine_platform_build = this->engine_platform_build;
	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_cache_readers(c_cache_file_reader* const*& cache_readers, uint32_t& cache_reader_count) const
{
	cache_readers = reinterpret_cast<c_cache_file_reader* const*>(this->cache_readers.data());
	cache_reader_count = static_cast<unsigned long>(this->cache_readers.size());
	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_cache_readers(c_infinite_module_file_reader* const*& cache_readers, uint32_t& cache_reader_count) const
{
	cache_readers = this->cache_readers.data();
	cache_reader_count = static_cast<unsigned long>(this->cache_readers.size());
	return BCS_S_OK;
}

BCS_RESULT c_infinite_cache_cluster::get_tag_instance_by_global_tag_id64(int64_t global_tag_id, c_tag_instance*& tag_instance)
{
	t_tag_instances_by_global_id64::const_iterator search = tag_instances_by_global_id64.find(global_tag_id);
	if (search != tag_instances_by_global_id64.end())
	{
		tag_instance = search->second;
		return BCS_S_OK;
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_cache_cluster::get_tag_instance_by_global_tag_id64_and_group_tag(int64_t global_tag_id, tag group_tag, c_tag_instance*& tag_instance)
{
	t_tag_instances_by_global_id64::const_iterator search = tag_instances_by_global_id64.find(global_tag_id);
	if (search != tag_instances_by_global_id64.end())
	{
		tag_instance = search->second;
		return BCS_S_OK;
	}
	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_cache_cluster::get_tag_instance_by_global_tag_id(int32_t global_tag_id, c_tag_instance*& tag_instance)
{
	t_tag_instances_by_global_id::const_iterator search = tag_instances_by_global_id.find(global_tag_id);
	if (search != tag_instances_by_global_id.end())
	{
		tag_instance = search->second;
		return BCS_S_OK;
	}
	return BCS_E_NOT_FOUND;
	//BCS_RESULT rs = BCS_S_OK;

	//for (c_infinite_module_file_reader* module_file_reader : cache_readers)
	//{
	//	c_infinite_tag_reader* tag_reader;
	//	if (BCS_SUCCEEDED(rs = get_tag_reader(*module_file_reader, tag_reader)))
	//	{
	//		if (BCS_SUCCEEDED(rs = tag_reader->get_tag_instance_by_global_tag_id(global_tag_id, tag_instance)))
	//		{
	//			return rs;
	//		}
	//	}
	//}
	//return rs;
}

BCS_RESULT c_infinite_cache_cluster::get_tag_instance_by_global_tag_id_and_group_tag(int32_t global_tag_id, tag group_tag, c_tag_instance*& tag_instance)
{
	t_tag_instances_by_global_id::const_iterator search = tag_instances_by_global_id.find(global_tag_id);
	if (search != tag_instances_by_global_id.end())
	{
		tag_instance = search->second;

		return BCS_S_OK;
	}
	return BCS_E_NOT_FOUND;
	//BCS_RESULT rs = BCS_S_OK;

	//for (c_infinite_module_file_reader* module_file_reader : cache_readers)
	//{
	//	c_infinite_tag_reader* tag_reader;
	//	if (BCS_SUCCEEDED(rs = get_tag_reader(*module_file_reader, tag_reader)))
	//	{
	//		if (BCS_SUCCEEDED(rs = tag_reader->get_tag_instance_by_global_tag_id_and_group_tag(global_tag_id, group_tag, tag_instance)))
	//		{
	//			return rs;
	//		}
	//	}
	//}
	//return rs;
}

BCS_RESULT c_infinite_cache_cluster::get_cache_reader_by_relative_path(const char* relative_path, c_infinite_module_file_reader*& out_cache_reader)
{
	for (c_infinite_module_file_reader* cache_reader : cache_readers)
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

	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_infinite_cache_cluster::get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader)
{
	return get_debug_reader(*static_cast<c_infinite_module_file_reader*>(&cache_reader), *reinterpret_cast<c_infinite_debug_reader**>(&debug_reader));
}

BCS_RESULT c_infinite_cache_cluster::get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader)
{
	return get_tag_reader(*static_cast<c_infinite_module_file_reader*>(&cache_reader), *reinterpret_cast<c_infinite_tag_reader**>(&tag_reader));
}

BCS_RESULT c_infinite_cache_cluster::get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader)
{
	return get_resource_reader(*static_cast<c_infinite_module_file_reader*>(&cache_reader), *reinterpret_cast<c_infinite_resource_reader**>(&resource_reader));
}

BCS_RESULT c_infinite_cache_cluster::get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader)
{
	return get_localization_reader(*static_cast<c_infinite_module_file_reader*>(&cache_reader), *reinterpret_cast<c_infinite_localization_reader**>(&localization_reader));
}
