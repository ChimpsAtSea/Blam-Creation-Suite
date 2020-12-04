#pragma once

class c_cache_file;
struct s_init_cache_file_payload;

class c_cache_cluster
{
public:
	c_cache_cluster(const wchar_t* files[], uint32_t num_files);
	c_cache_cluster(const wchar_t* directory);
	~c_cache_cluster();

	std::vector<c_cache_file*> cache_files;
};

