#pragma once

class c_halo4_cache_cluster;
class c_halo4_cache_file_reader;

class c_halo4_tag_reader : public c_tag_reader
{
public:
	c_halo4_tag_reader(c_halo4_cache_cluster& cache_cluster, c_halo4_cache_file_reader& cache_reader);
	~c_halo4_tag_reader();

private:
	c_halo4_cache_cluster& cache_cluster;
	c_halo4_cache_file_reader& cache_reader;

	halo4::xbox360::s_cache_file_tag_group* groups;
	halo4::xbox360::s_cache_file_tag_instance* instances;
	halo4::xbox360::s_cache_file_tag_global_instance* global_instances;
	halo4::xbox360::s_cache_file_tag_interop* interops;
};
