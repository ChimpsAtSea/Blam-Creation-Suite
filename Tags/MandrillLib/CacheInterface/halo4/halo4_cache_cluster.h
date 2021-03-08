#pragma once

class c_halo4_debug_reader;
class c_halo4_tag_reader;
class c_halo4_resource_reader;
class c_halo4_localization_reader;
class c_halo4_tag_group;
class c_halo4_tag_instance;

struct s_halo4_cache_cluster_entry
{
	c_halo4_cache_file_reader* cache_reader;
	c_halo4_debug_reader* debug_reader;
	c_halo4_tag_reader* tag_reader;
	c_halo4_resource_reader* resource_reader;
	c_halo4_localization_reader* localization_reader;
};

class c_halo4_cache_cluster : public c_cache_cluster
{
public:
	c_halo4_cache_cluster(c_halo4_cache_file_reader** cache_readers, uint32_t cache_reader_count, s_engine_platform_build engine_platform_build);
	virtual ~c_halo4_cache_cluster();

	BCS_RESULT get_debug_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_debug_reader*& debug_reader);
	BCS_RESULT get_tag_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_tag_reader*& tag_reader);
	BCS_RESULT get_resource_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_resource_reader*& resource_reader);
	BCS_RESULT get_localization_reader(c_halo4_cache_file_reader& cache_reader, c_halo4_localization_reader*& localization_reader);

protected:
	virtual BCS_RESULT get_debug_reader(c_cache_file_reader& cache_reader, c_debug_reader*& debug_reader);
	virtual BCS_RESULT get_tag_reader(c_cache_file_reader& cache_reader, c_tag_reader*& tag_reader);
	virtual BCS_RESULT get_resource_reader(c_cache_file_reader& cache_reader, c_resource_reader*& resource_reader);
	virtual BCS_RESULT get_localization_reader(c_cache_file_reader& cache_reader, c_localization_reader*& localization_reader);

public:
	s_engine_platform_build engine_platform_build;

	BCS_RESULT get_cache_file_entry(c_halo4_cache_file_reader& cache_reader, const s_halo4_cache_cluster_entry*& cache_file_entry);


	std::vector<s_halo4_cache_cluster_entry> entries;

};
