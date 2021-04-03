#include "mandrilllib-private-pch.h"

c_halo4_cache_cluster::c_halo4_cache_cluster(c_halo4_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build) :
	engine_platform_build(engine_platform_build),
	entries()
{
	BCS_RESULT rs;
	BCS_VALIDATE_ARGUMENT_THROW(cache_readers);
	BCS_VALIDATE_ARGUMENT_THROW(cache_reader_count > 0);

	s_cache_file_buffer_info temp_info;

	for (uint32_t cache_reader_index = 0; cache_reader_index < cache_reader_count; cache_reader_index++)
	{
		c_halo4_cache_file_reader* cache_reader = cache_readers[cache_reader_index];
		BCS_VALIDATE_ARGUMENT_THROW(cache_reader);

		s_halo4_cache_cluster_entry& entry = entries.emplace_back();

		entry.cache_reader = cache_reader;
		entry.debug_reader = nullptr;
		entry.tag_reader = nullptr;
		entry.resource_reader = nullptr;
		entry.localization_reader = nullptr;

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_debug_section_buffer, temp_info)))
		{
			entry.debug_reader = new c_halo4_debug_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_resources_section_buffer, temp_info)))
		{
			entry.resource_reader = new c_halo4_resource_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_localization_section_buffer, temp_info)))
		{
			entry.localization_reader = new c_halo4_localization_reader(*this, *cache_reader);
		}

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_tag_section_buffer, temp_info)))
		{
			entry.tag_reader = new c_halo4_tag_reader(*this, *cache_reader);
		}

		debug_point;
	}

	for (s_halo4_cache_cluster_entry& entry : entries) // populate resource definitions
	{
		c_halo4_cache_file_reader* cache_reader = entry.cache_reader;

		if (entry.tag_reader == nullptr)
		{
			continue;
		}

		if (BCS_FAILED(rs = entry.tag_reader->init_shared_files_table()))
		{
			throw(rs);
		}

		if (BCS_FAILED(rs = entry.tag_reader->init_interop_table()))
		{
			throw(rs);
		}
		if (BCS_FAILED(rs = entry.tag_reader->init_resource_table()))
		{
			throw(rs);
		}

		debug_point;
	}

	for (s_halo4_cache_cluster_entry& entry : entries) // populate resource definitions
	{
		c_halo4_cache_file_reader* cache_reader = entry.cache_reader;

		if (entry.tag_reader == nullptr)
		{
			continue;
		}

		if (BCS_FAILED(rs = entry.tag_reader->init_interops()))
		{
			throw(rs);
		}
		if (BCS_FAILED(rs = entry.tag_reader->init_resources()))
		{
			throw(rs);
		}
		if (BCS_FAILED(rs = entry.tag_reader->export_resources()))
		{
			throw(rs);
		}

		debug_point;
	}
}

c_halo4_cache_cluster::~c_halo4_cache_cluster()
{
	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		delete entry.debug_reader;
		delete entry.localization_reader;
		delete entry.resource_reader;
		delete entry.tag_reader;
	}
}

BCS_RESULT c_halo4_cache_cluster::get_debug_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_debug_reader*& debug_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		debug_reader = cache_cluster_entry->debug_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_tag_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_tag_reader*& tag_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		tag_reader = cache_cluster_entry->tag_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_resource_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_resource_reader*& resource_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		resource_reader = cache_cluster_entry->resource_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_localization_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_localization_reader*& localization_reader)
{
	BCS_RESULT result = BCS_S_OK;
	const s_halo4_cache_cluster_entry* cache_cluster_entry;
	if (BCS_SUCCEEDED(result = get_cache_file_entry(cache_reader, cache_cluster_entry)))
	{
		localization_reader = cache_cluster_entry->localization_reader;
	}
	return result;
}

BCS_RESULT c_halo4_cache_cluster::get_resource_container(s_resource_priority_datas const& resource_priority_datas, c_halo4_resource_container*& resource_container)
{
	t_resource_container_by_id_map::iterator it = resource_containers_by_id.find(resource_priority_datas.id);
	if (it == resource_containers_by_id.end())
	{
		return BCS_E_NOT_FOUND;
	}
	else
	{
		resource_container = it->second;
		return BCS_S_OK;
	}

//	// #TODO: check if the resource container already exists
//
//	const s_resource_priority_data(&a)[3] = resource_priority_datas.data;
//
//	const std::vector<c_halo4_resource_container*>& cache_file_resource_containers = resource_containers_by_cache_file[a[0].resource_cache_file][a[1].resource_cache_file][a[2].resource_cache_file];
//	for (c_halo4_resource_container* current_resource_container : cache_file_resource_containers)
//	{
//		const s_resource_priority_data(&b)[3] = current_resource_container->resource_priority_datas.data;
//
//		//#NOTE: this is all done because its absolutely
//		// fucking!!!
//		// terrible performance in debug
//
//#define compare_part1(index)																		\
//		if (a[index].resource_cache_file != b[index].resource_cache_file) continue;					\
//		if (a[index].resource_page_offset != b[index].resource_page_offset) continue;			
//
//#define compare_part2(index)																		\
//		if (a[index].page_index != b[index].page_index) continue;									\
//		if (a[index].page_file_offset != b[index].page_file_offset) continue;						\
//		if (a[index].page_file_size != b[index].page_file_size) continue;							\
//		if (a[index].page_size != b[index].page_size) continue;										
//
//		compare_part1(0);
//		compare_part1(1);
//		compare_part1(2);
//
//		compare_part2(0);
//		compare_part2(1);
//		compare_part2(2);
//
//		resource_container = current_resource_container;
//		return BCS_S_OK;
//	}
//
//	return BCS_E_NOT_FOUND;
}

BCS_RESULT c_halo4_cache_cluster::add_resource_container(c_halo4_resource_container& resource_container, bool force)
{
	if (!force)
	{
		t_resource_container_by_id_map::iterator it = resource_containers_by_id.find(resource_container.resource_priority_datas.id);
		if(it != resource_containers_by_id.end())
		{
			ASSERT(it->second == &resource_container); // make sure that we don't have a hash collision!!!

			return BCS_E_FAIL; // duplicate entry
		}
	}

	resource_containers_by_id[resource_container.resource_priority_datas.id] = &resource_container;
	resource_containers_by_cache_reader[resource_container.resource_priority_datas.data[0].resource_cache_file].push_back(&resource_container);
	resource_containers_by_cache_reader[resource_container.resource_priority_datas.data[1].resource_cache_file].push_back(&resource_container);
	resource_containers_by_cache_reader[resource_container.resource_priority_datas.data[2].resource_cache_file].push_back(&resource_container);
	resource_containers.push_back(&resource_container);

	return BCS_S_OK;


//	std::vector<c_halo4_resource_container*>& cache_file_resource_containers = resource_containers_by_cache_file[a[0].resource_cache_file][a[1].resource_cache_file][a[2].resource_cache_file];
//#ifdef _DEBUG
//
//	for (c_halo4_resource_container* current_resource_container : cache_file_resource_containers)
//	{
//		if (current_resource_container == &resource_container)
//		{
//			return BCS_E_FAIL; // duplicate entry
//		}
//	}
//
//	c_halo4_resource_container* existing_resource_container;
//	if (BCS_SUCCEEDED(get_resource_container(resource_container.resource_priority_datas, existing_resource_container)))
//	{
//		return BCS_E_FAIL; // duplicate entry, exists via search from priority data
//	}
//#endif
//
//	cache_file_resource_containers.push_back(&resource_container);
//	resource_containers.push_back(&resource_container);
//
//	return BCS_S_OK;
}

BCS_RESULT c_halo4_cache_cluster::get_cache_file_entry(c_halo4_cache_file_reader& cache_reader, const s_halo4_cache_cluster_entry*& cache_cluster_entry)
{
	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		if (entry.cache_reader == &cache_reader)
		{
			cache_cluster_entry = &entry;
			return BCS_S_OK;
		}
	}

	return BCS_E_FAIL;
}

BCS_RESULT c_halo4_cache_cluster::get_cache_reader_by_relative_path(const char* relative_path, c_halo4_cache_file_reader*& cache_reader)
{
	BCS_RESULT rs = BCS_S_OK;
	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		s_cache_file_build_info build_info;
		if (FAILED(rs = entry.cache_reader->get_build_info(build_info)))
		{
			return rs;
		}

		c_fixed_path cache_relative_path;
		cache_relative_path.format("maps\\%s.map", build_info.name.c_str());

		if (strcmp(cache_relative_path.c_str(), relative_path) == 0)
		{
			cache_reader = entry.cache_reader;
			return rs;
		}

		//if (strcmp(build_info.relative_path.get_string(), relative_path) == 0)
		//{
		//	cache_reader = entry.cache_reader;
		//	return rs;
		//}
	}
	rs = BCS_E_NOT_FOUND; // failed to find a cache file

	return rs;
}

BCS_RESULT c_halo4_cache_cluster::get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader)
{
	return get_debug_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_debug_reader**>(&debug_reader));
}

BCS_RESULT c_halo4_cache_cluster::get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader)
{
	return get_tag_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_tag_reader**>(&tag_reader));
}

BCS_RESULT c_halo4_cache_cluster::get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader)
{
	return get_resource_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_resource_reader**>(&resource_reader));
}

BCS_RESULT c_halo4_cache_cluster::get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader)
{
	return get_localization_reader(*static_cast<c_halo4_cache_file_reader*>(&cache_reader), *reinterpret_cast<c_halo4_localization_reader**>(&localization_reader));
}
