#pragma once

class c_gen3_cache_file;

class c_gen3_resource_page
{
public:
	c_gen3_resource_page(c_gen3_cache_file& cache_file, const void* raw_data, uint32_t raw_size, uint32_t memory_size, bool is_compressed);
	~c_gen3_resource_page();

	c_gen3_cache_file& cache_file;
	char* data;
	uint32_t data_size;
};