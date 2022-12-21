#pragma once

class c_tag_group;
class c_tag_instance;
class c_cache_cluster;
class c_cache_file_reader;

class c_tag_reader
{
public:
	c_tag_reader(c_cache_cluster& cache_cluster, c_cache_file_reader& cache_file_reader);
	virtual ~c_tag_reader();

	virtual BCS_RESULT get_tag_groups(c_tag_group**& tag_groups, uint32_t& tag_group_count) = 0;
	virtual BCS_RESULT get_tag_instances(c_tag_instance**& tag_instances, uint32_t& tag_instance_count) = 0;
	virtual BCS_RESULT get_tag_instance_by_cache_file_tag_index(uint32_t cache_file_tag_index, c_tag_instance*& tag_instance) = 0;
	virtual BCS_RESULT get_cache_cluster(c_cache_cluster*& cache_cluster) const;
	virtual BCS_RESULT get_cache_file_reader(c_cache_file_reader*& cache_file_reader) const;

	c_cache_cluster& cache_cluster;
	c_cache_file_reader& cache_file_reader;
};
