#pragma once

class c_haloreach_cache_file;

class c_haloreach_tag_interface :
	public c_tag_interface
{
public:
	c_haloreach_tag_interface(c_haloreach_cache_file& cache_file, uint16_t tag_index);
	~c_haloreach_tag_interface();

	virtual unsigned long get_group_tag() const final;
	virtual c_tag_group_interface* get_tag_group_interface() const final;

	inline gen3::s_cache_file_tag_instance* get_cache_file_instance() const { return cache_file_tag_instance; };
	inline gen3::s_cache_file_tag_group* get_cache_file_group() const { return cache_file_tag_group; };

	virtual const char* get_filepath() const final;
	virtual const char* get_path_with_group_id_cstr() const final;
	virtual const char* get_path_with_group_name_cstr() const final;
	virtual const char* get_name_cstr() const final;
	virtual const char* get_name_with_group_id_cstr() const final;
	virtual const char* get_name_with_group_name_cstr() const final;
	virtual const char* get_group_short_name_cstr() const;
	virtual const char* get_group_full_name_cstr() const;

protected:
	gen3::s_cache_file_tag_instance* cache_file_tag_instance;
	gen3::s_cache_file_tag_group* cache_file_tag_group;
	c_haloreach_tag_group_interface* tag_group_interface;

	std::string tag_group_short_name;
	std::string tag_group_full_name;
	std::string tag_path;
	std::string tag_path_with_group_id;
	std::string tag_path_with_group_name;
	std::string tag_name;
	std::string tag_name_with_group_id;
	std::string tag_name_with_group_name;
};

