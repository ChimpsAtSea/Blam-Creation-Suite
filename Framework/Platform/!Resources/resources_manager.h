#pragma once

enum e_resource_type
{
	_resource_type_icon,
	_resource_type_font_cousine_regular,
	_resource_type_font_font_awesome,
	_resource_type_box_pixel_shader,
	_resource_type_box_vertex_shader,
	_resource_type_symbols_blob,
};

class c_resources_manager
{
public:
	static void* get_resource_int_resource_impl(e_resource_type type);
	template<typename T>
	static T get_resource_int_resource(e_resource_type type)
	{
		return static_cast<T>(get_resource_int_resource_impl(type));
	}
	static bool get_resource(e_resource_type type, char** out_data, size_t* out_data_size, bool null_terminate = false);
private:
	static HRSRC get_resource_handle(e_resource_type type);
};


