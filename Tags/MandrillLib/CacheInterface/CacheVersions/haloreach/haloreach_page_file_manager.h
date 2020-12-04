#pragma once

class c_gen3_resource_page;
class c_haloreach_cache_file;

class c_haloreach_page_file_manager
{
public:

	struct s_resource_page_entry
	{
		c_gen3_resource_page* resource_page;
		uint32_t page_address_start;
		uint32_t page_address_end;
	};

	std::vector<s_resource_page_entry> resource_pages;

	c_haloreach_page_file_manager(c_haloreach_cache_file& cache_file);
	~c_haloreach_page_file_manager();

	uint32_t encode_page_address(uint32_t file_page_index, uint32_t file_page_offset);
	bool decode_page_address(uint32_t page_address, uint32_t& file_page_index, uint32_t& file_page_offset);
	bool is_valid_data_address(void* data) const;


protected:
	c_haloreach_cache_file& cache_file;
};