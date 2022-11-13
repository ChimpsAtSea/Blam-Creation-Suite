#pragma once

class c_halo1_cache_cluster;
class c_halo1_cache_file_reader;

class c_halo1_resource_reader : public c_resource_reader
{
public:
	c_halo1_resource_reader(c_halo1_cache_cluster& cache_cluster, c_halo1_cache_file_reader& cache_reader);
	~c_halo1_resource_reader();

private:
	c_halo1_cache_cluster& cache_cluster;
	c_halo1_cache_file_reader& cache_reader;
};
