#pragma once

class c_gen3_cache_file;
class c_gen3_tag_group_interface;

class c_gen3_tag_interface :
	public c_tag_interface
{
public:
	c_gen3_tag_interface(c_gen3_cache_file& cache_file, uint32_t tag_index);
	~c_gen3_tag_interface();

	virtual unsigned long get_group_tag() const final;
	virtual c_tag_group_interface* get_tag_group_interface() const final;

	inline gen3::s_cache_file_tag_instance* get_cache_file_instance() const { return &cache_file_tag_instance; };
	inline gen3::s_cache_file_tag_group* get_cache_file_group() const { return cache_file_tag_group; };
	inline c_gen3_cache_file& get_cache_file() const { return *reinterpret_cast<c_gen3_cache_file*>(&cache_file); };
	inline bool get_is_tag_valid() const { return is_tag_valid; };
	inline bool get_is_struct_valid() const { return is_struct_valid; };

	virtual const char* get_filepath() const final;
	virtual const char* get_path_with_group_id_cstr() const final;
	virtual const char* get_path_with_group_name_cstr() const final;
	virtual const char* get_name_cstr() const final;
	virtual const char* get_name_with_group_id_cstr() const final;
	virtual const char* get_name_with_group_name_cstr() const final;

	virtual char* get_data() final;

	void validate();
protected:
	gen3::s_cache_file_tag_instance& cache_file_tag_instance;
	gen3::s_cache_file_tag_group* cache_file_tag_group;
	c_gen3_tag_group_interface* tag_group_interface;

	c_fixed_string_512 filepath;
	c_fixed_string_512 filepath_with_group_id;
	c_fixed_string_512 filepath_with_group_name;
	const char* filename;
	const char* filename_with_group_id;
	const char* filename_with_group_name;

	char* tag_data;

	bool is_tag_valid;
	bool is_struct_valid;
};

