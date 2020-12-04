#pragma once

class c_cache_file;
struct s_init_cache_file_payload;

class c_cache_cluster
{
public:
	c_cache_cluster(const wchar_t* files[], uint32_t num_files);
	c_cache_cluster(const wchar_t* directory);
	~c_cache_cluster();

	uint32_t encode_page_address(uint32_t file_index, uint64_t offset);
	bool decode_page_address(uint32_t page_address, uint32_t& file_index, uint64_t& offset);
	bool is_valid_data_address(void* data) const;

	std::vector<c_cache_file*> cache_files;
};

