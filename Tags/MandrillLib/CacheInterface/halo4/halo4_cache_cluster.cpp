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

		debug_point;
	}

	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		c_halo4_cache_file_reader* cache_reader = entry.cache_reader;

		s_cache_file_buffer_info tag_section_buffer;
		if (BCS_SUCCEEDED(cache_reader->get_buffer(_tag_section_buffer, tag_section_buffer)))
		{
			entry.tag_reader = new c_halo4_tag_reader(*this, *cache_reader);
		}
	}

	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		c_halo4_cache_file_reader* cache_reader = entry.cache_reader;

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_resources_section_buffer, temp_info)))
		{
			entry.resource_reader = new c_halo4_resource_reader(*this, *cache_reader);
		}
	}

	for (s_halo4_cache_cluster_entry& entry : entries)
	{
		c_halo4_cache_file_reader* cache_reader = entry.cache_reader;

		if (BCS_SUCCEEDED(cache_reader->get_buffer(_localization_section_buffer, temp_info)))
		{
			entry.localization_reader = new c_halo4_localization_reader(*this, *cache_reader);
		}
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
