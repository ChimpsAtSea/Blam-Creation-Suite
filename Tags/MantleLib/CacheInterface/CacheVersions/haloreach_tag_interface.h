#pragma once

class c_haloreach_tag_interface :
	public c_tag_interface
{
public:
	c_haloreach_tag_interface(c_haloreach_cache_file& cache_file, uint16_t tag_index);
	~c_haloreach_tag_interface();

	inline s_cache_file_tag_instance*& get_cache_file_instance() { return *reinterpret_cast<s_cache_file_tag_instance**>(&cache_file_tag_instance); };
	inline s_cache_file_tag_group*& get_cache_file_group() { return *reinterpret_cast<s_cache_file_tag_group**>(&cache_file_tag_group); };
	inline s_cache_file_tag_instance* const& get_cache_file_instance() const { return *reinterpret_cast<s_cache_file_tag_instance* const*>(&cache_file_tag_instance); };
	inline s_cache_file_tag_group* const& get_cache_file_group() const { return *reinterpret_cast<s_cache_file_tag_group* const*>(&cache_file_tag_group); };

};

