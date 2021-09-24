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
	_bcs_resource_type_viewport_p_vertex_shader,
	_bcs_resource_type_viewport_pc_vertex_shader,
	_bcs_resource_type_viewport_ptcn_vertex_shader,
	_bcs_resource_type_viewport_debug_pixel_shader,
	_bcs_resource_type_viewport_default_pixel_shader,
	_bcs_resource_type_symbols_blob,
	k_number_of_bcs_resource_types
};

#ifdef _WINDOWS_
BCS_DEBUG_API BCS_RESULT resources_get_resource_type(e_bcs_resource_type type, LPCWSTR& resource_type);
BCS_DEBUG_API BCS_RESULT resources_get_resource_int(e_bcs_resource_type type, LPCWSTR& resource_int);
BCS_DEBUG_API BCS_RESULT resources_get_resource_handle(e_bcs_resource_type type, HRSRC& resource_handle);
BCS_DEBUG_API BCS_RESULT resources_get_resource_icon_handle(e_bcs_resource_type type, HICON& resource_icon_handle);
#endif

BCS_DEBUG_API BCS_RESULT resources_get_resource_filename(e_bcs_resource_type type, const char*& resource_filename);
BCS_DEBUG_API BCS_RESULT resources_get_resource_size(e_bcs_resource_type type, unsigned long& resource_size);
BCS_DEBUG_API BCS_RESULT resources_copy_resource_to_buffer(e_bcs_resource_type type, void* buffer, unsigned long& buffer_size);
BCS_DEBUG_API BCS_RESULT resources_read_resource_to_memory(e_bcs_resource_type type, void*& buffer, unsigned long& buffer_size);

BCS_DEBUG_API BCS_RESULT resources_set_resource_data(e_bcs_resource_type type, const void* buffer, unsigned long buffer_size);
BCS_DEBUG_API BCS_RESULT resources_set_external_resource_data(e_bcs_resource_type type, const char* target_filepath, const void* buffer, unsigned long buffer_size);
BCS_DEBUG_API BCS_RESULT resources_set_external_resource_data(e_bcs_resource_type type, const char* target_filepath, const char* resource_filepath);
