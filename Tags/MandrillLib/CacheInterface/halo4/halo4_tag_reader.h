#pragma once

class c_halo4_cache_cluster;
class c_halo4_cache_file_reader;

struct s_halo4_tag_group_info
{
	halo4::xbox360::s_cache_file_tag_group group;
	const char* group_name;
};

struct s_halo4_tag_instance_info
{
	halo4::xbox360::s_cache_file_tag_instance instance;
	long index;
	const char* instance_name;
	s_halo4_tag_group_info* group_info;
};

struct s_halo4_tag_global_instance_info
{
	halo4::xbox360::s_cache_file_tag_global_instance global_instance;
	s_halo4_tag_instance_info* instance_info;
};

class c_halo4_tag_reader : public c_tag_reader
{
public:
	c_halo4_tag_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader);
	~c_halo4_tag_reader();

	c_halo4_cache_cluster& cache_cluster;
	c_halo4_cache_file_reader& cache_reader;

	unsigned long group_count;
	s_halo4_tag_group_info* groups;
	unsigned long instance_count;
	s_halo4_tag_instance_info* instances;
	unsigned long global_instance_count;
	s_halo4_tag_global_instance_info* global_instances;
	unsigned long interop_count;
	halo4::xbox360::s_cache_file_tag_interop* interops;
};
