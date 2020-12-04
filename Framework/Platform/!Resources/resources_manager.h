#pragma once

enum e_bcs_resource_type
{
	_bcs_resource_type_icon_application,
	_bcs_resource_type_icon_blam_creation_suite,
	_bcs_resource_type_icon_mandrill,
	_bcs_resource_type_font_cousine_regular,
	_bcs_resource_type_font_font_awesome,
	_bcs_resource_type_box_pixel_shader,
	_bcs_resource_type_box_vertex_shader,
	_bcs_resource_type_symbols_blob,
	k_num_bcs_resource_types
};

class c_bcs_cached_resource_info
{
public:
	c_bcs_cached_resource_info(e_bcs_resource_type resource_type);
	~c_bcs_cached_resource_info();

	HRSRC resource_handle;
	HGLOBAL resource_memory_handle;
	DWORD resource_size;
	LPVOID resource_pointer;

	static c_bcs_cached_resource_info& get_info(e_bcs_resource_type resource_type);

private:
	static c_bcs_cached_resource_info* cached_resource_infos[k_num_bcs_resource_types];
};

class c_bcs_resources_manager
{
public:
	friend class c_bcs_cached_resource_info;

	static LPCWSTR get_resource_type(e_bcs_resource_type type);
	static LPCWSTR get_resource_int_resource(e_bcs_resource_type type);
	static const void* get_resource(e_bcs_resource_type type, size_t* resource_size);
	static bool copy_resource_to_buffer(e_bcs_resource_type type, void*& out_data, size_t* out_data_size = nullptr, bool null_terminate = false);
private:
	static HRSRC get_resource_handle(e_bcs_resource_type type);
};



