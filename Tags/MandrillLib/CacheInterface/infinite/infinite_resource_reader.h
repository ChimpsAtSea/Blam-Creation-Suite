#pragma once

class c_infinite_cache_cluster;
class c_infinite_module_file_reader;

class c_infinite_resource_reader : public c_resource_reader
{
public:
	c_infinite_resource_reader(c_infinite_cache_cluster& cache_cluster, c_infinite_module_file_reader& cache_reader);
	~c_infinite_resource_reader();

private:
	c_infinite_cache_cluster& cache_cluster;
	c_infinite_module_file_reader& cache_reader;
};
