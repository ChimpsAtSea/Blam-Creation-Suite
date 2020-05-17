#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(global_pixel_shader, GLOBAL_PIXEL_SHADER_TAG)
	{
		FIELD( _field_block, "entry points", &global_shader_entry_point_block_block ),
		FIELD( _field_dword_integer, "version*" ),
		FIELD( _field_block, "compiled shaders", &compiled_pixel_shader_block_block ),
		FIELD( _field_terminator )
	};

	TAG_GROUP(global_vertex_shader, GLOBAL_VERTEX_SHADER_TAG)
	{
		FIELD( _field_block, "vertex types", &global_vertex_shader_vertex_types_block_block ),
		FIELD( _field_dword_integer, "version*" ),
		FIELD( _field_block, "compiled shaders", &compiled_vertex_shader_block_block ),
		FIELD( _field_terminator )
	};

	TAG_GROUP_FROM_BLOCK(global_cache_file_pixel_shaders, GLOBAL_CACHE_FILE_PIXEL_SHADERS_TAG, global_cache_file_pixel_shaders_block_block );

	TAG_GROUP_FROM_BLOCK(hlsl_include, HLSL_INCLUDE_TAG, hlsl_include_block_block );

	TAG_GROUP(pixel_shader, PIXEL_SHADER_TAG)
	{
		FIELD( _field_block, "entry points", &pixel_entry_point_block_block ),
		FIELD( _field_dword_integer, "version*" ),
		FIELD( _field_block, "compiled shaders", &compiled_pixel_shader_block_block ),
		FIELD( _field_terminator )
	};

	TAG_GROUP(vertex_shader, VERTEX_SHADER_TAG)
	{
		FIELD( _field_block, "entry points", &vertex_entry_point_block_block ),
		FIELD( _field_dword_integer, "version*" ),
		FIELD( _field_block, "compiled shaders", &compiled_vertex_shader_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(global_shader_option_dependency, c_render_method_definition::k_maximum_category_options)
	{
		FIELD( _field_long_integer, "compiled shader index" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(global_shader_category_dependency, c_render_method_definition::k_maximum_categories)
	{
		FIELD( _field_long_integer, "definition category index" ),
		FIELD( _field_block, "option dependency", &global_shader_option_dependency_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(global_shader_entry_point_block, k_number_of_entry_points*2)
	{
		FIELD( _field_block, "category dependency", &global_shader_category_dependency_block ),
		FIELD( _field_long_integer, "default compiled shader index" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(compiled_pixel_shader_block, 10*k_kilo)
	{
		FIELD( _field_struct, "compiled shader splut", &rasterizer_compiled_shader_struct_struct_definition ),
		FIELD( _field_long_integer, "runtime shader ~*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(global_vertex_shader_vertex_types_block, k_number_of_vertex_types*2)
	{
		FIELD( _field_block, "entry point dependency", &global_shader_entry_point_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(compiled_vertex_shader_block, 10*k_kilo)
	{
		FIELD( _field_struct, "compiled shader splut", &rasterizer_compiled_shader_struct_struct_definition ),
		FIELD( _field_long_integer, "runtime shader ~*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(global_cache_file_pixel_shaders_block, 1, global_cache_file_pixel_shaders_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(hlsl_include_block, 1, hlsl_include_struct_definition_struct_definition );

	TAG_BLOCK(pixel_entry_point_block, k_kilo)
	{
		FIELD( _field_byte_integer, "start index" ),
		FIELD( _field_byte_integer, "count" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vertex_types_block$3, k_kilo)
	{
		FIELD( _field_byte_integer, "start index" ),
		FIELD( _field_byte_integer, "count" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vertex_entry_point_block, k_number_of_vertex_types*2)
	{
		FIELD( _field_block, "vertex types", &vertex_types_block$3_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(rasterizer_compiled_shader_struct)
	{
		FIELD( _field_long_flags, "shader flags", &shader_flags ),
		FIELD( _field_data, "xenon compiled shader{..:xenon compiled shader}" ),
		FIELD( _field_data, "dx9 compiled shader{..:dx9 compiled shader}" ),
		FIELD( _field_explanation, "Xenon constant table" ),
		FIELD( _field_struct, "xenon rasterizer constant table*!", &global_rasterizer_constant_table_struct_struct_definition ),
		FIELD( _field_explanation, "DX9 constant table" ),
		FIELD( _field_struct, "dx9 rasterizer constant table*!", &global_rasterizer_constant_table_struct_struct_definition ),
		FIELD( _field_dword_integer, "gprs{..:gprs}" ),
		FIELD( _field_long_integer, "cache file reference*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(global_cache_file_pixel_shaders_struct_definition)
	{
		FIELD( _field_long_integer, "shader count" ),
		FIELD( _field_long_integer, "cached shader count" ),
		FIELD( _field_long_integer, "total memory size" ),
		FIELD( _field_long_integer, "cached memory size" ),
		FIELD( _field_block, "compiled shaders", &compiled_pixel_shader_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(hlsl_include_struct_definition)
	{
		FIELD( _field_data, "include file" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(shader_flags, 1)
	{
		OPTION("requires constant table"),
	};

} // namespace blofeld

