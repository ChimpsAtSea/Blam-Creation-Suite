#pragma once

class c_halo1_cache_file;

enum e_tag_interface_path_type
{
	_tag_interface_path_type_default,
	_tag_interface_path_type_group_id,
	_tag_interface_path_type_group_name,
};

class c_halo1_tag_interface :
	public c_tag_interface
{
public:
	c_halo1_tag_interface(c_halo1_cache_file& cache_file, uint32_t tag_index);

	virtual unsigned long get_group_tag() const final; 
	virtual c_tag_group_interface* get_tag_group_interface() const final;

	virtual const char* get_filepath() const final;
	virtual const char* get_path_with_group_id_cstr() const final;
	virtual const char* get_path_with_group_name_cstr() const final;
	virtual const char* get_name_cstr() const final;
	virtual const char* get_name_with_group_id_cstr() const final;
	virtual const char* get_name_with_group_name_cstr() const final;

	virtual char* get_data();

protected:
	halo1::s_cache_file_tag_instance& cache_file_tag_instance;
	c_halo1_tag_group_interface* tag_group_interface;

	c_fixed_string_512 filepath;
	c_fixed_string_512 filepath_with_group_id;
	c_fixed_string_512 filepath_with_group_name;
	const char* filename;
	const char* filename_with_group_id;
	const char* filename_with_group_name;
};

