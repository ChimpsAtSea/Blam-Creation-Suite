#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_shader_entry_point, k_number_of_entry_points*2)
{
	{ _field_block, "category dependency", &global_shader_category_dependency_block },
	{ _field_long_integer, "default compiled shader index" },
	{ _field_terminator },
};

TAG_BLOCK(global_shader_category_dependency, c_render_method_definition::k_maximum_categories)
{
	{ _field_long_integer, "definition category index" },
	{ _field_block, "option dependency", &global_shader_option_dependency_block },
	{ _field_terminator },
};

TAG_BLOCK(global_shader_option_dependency, c_render_method_definition::k_maximum_category_options)
{
	{ _field_long_integer, "compiled shader index" },
	{ _field_terminator },
};

TAG_BLOCK(compiled_pixel_shader, 10*k_kilo)
{
	{ _field_struct, "compiled shader splut" },
	{ _field_long_integer, "runtime shader ~*!" },
	{ _field_terminator },
};

TAG_BLOCK(global_vertex_shader_vertex_types, k_number_of_vertex_types*2)
{
	{ _field_block, "entry point dependency", &global_shader_entry_point_block },
	{ _field_terminator },
};

TAG_BLOCK(compiled_vertex_shader, 10*k_kilo)
{
	{ _field_struct, "compiled shader splut" },
	{ _field_long_integer, "runtime shader ~*!" },
	{ _field_terminator },
};

TAG_BLOCK(pixel_entry_point, k_kilo)
{
	{ _field_byte_integer, "start index" },
	{ _field_byte_integer, "count" },
	{ _field_terminator },
};

TAG_BLOCK(vertex_entry_point, k_number_of_vertex_types*2)
{
	{ _field_block, "vertex types", &vertex_types$2_block },
	{ _field_terminator },
};

TAG_BLOCK(vertex_types$2, k_kilo)
{
	{ _field_byte_integer, "start index" },
	{ _field_byte_integer, "count" },
	{ _field_terminator },
};

TAG_GROUP(global_pixel_shader, GLOBAL_PIXEL_SHADER_TAG)
{
	{ _field_block, "entry points", &global_shader_entry_point_block },
	{ _field_dword_integer, "version*" },
	{ _field_block, "compiled shaders", &compiled_pixel_shader_block },
	{ _field_terminator },
};

TAG_GROUP(global_vertex_shader, GLOBAL_VERTEX_SHADER_TAG)
{
	{ _field_block, "vertex types", &global_vertex_shader_vertex_types_block },
	{ _field_dword_integer, "version*" },
	{ _field_block, "compiled shaders", &compiled_vertex_shader_block },
	{ _field_terminator },
};

TAG_GROUP(global_cache_file_pixel_shaders, GLOBAL_CACHE_FILE_PIXEL_SHADERS_TAG)
{
	{ _field_long_integer, "shader count" },
	{ _field_long_integer, "cached shader count" },
	{ _field_long_integer, "total memory size" },
	{ _field_long_integer, "cached memory size" },
	{ _field_block, "compiled shaders", &compiled_pixel_shader_block },
	{ _field_terminator },
};

TAG_GROUP(hlsl_include, HLSL_INCLUDE_TAG)
{
	{ _field_data, "include file" },
	{ _field_terminator },
};

TAG_GROUP(pixel_shader, PIXEL_SHADER_TAG)
{
	{ _field_block, "entry points", &pixel_entry_point_block },
	{ _field_dword_integer, "version*" },
	{ _field_block, "compiled shaders", &compiled_pixel_shader_block },
	{ _field_terminator },
};

TAG_GROUP(vertex_shader, VERTEX_SHADER_TAG)
{
	{ _field_block, "entry points", &vertex_entry_point_block },
	{ _field_dword_integer, "version*" },
	{ _field_block, "compiled shaders", &compiled_vertex_shader_block },
	{ _field_terminator },
};

} // namespace blofeld

