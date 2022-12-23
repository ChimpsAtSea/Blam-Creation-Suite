#pragma once

class c_cache_file_reader;
class c_debug_reader;
class c_tag_reader;
class c_resource_reader;
class c_localization_reader;

class c_cache_cluster
{
public:
	c_cache_cluster();
	virtual ~c_cache_cluster();

	virtual BCS_RESULT get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader) = 0;
	virtual BCS_RESULT get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader) = 0;
	virtual BCS_RESULT get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader) = 0;
	virtual BCS_RESULT get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader) = 0;
	virtual BCS_RESULT get_blofeld_tag_groups(blofeld::t_tag_group_collection& tag_groups) const = 0;
	virtual BCS_RESULT get_engine_platform_build(s_engine_platform_build& engine_platform_build) const = 0;
	virtual BCS_RESULT get_cache_readers(c_cache_file_reader* const*& cache_readers, uint32_t& cache_reader_count) const = 0;
};

