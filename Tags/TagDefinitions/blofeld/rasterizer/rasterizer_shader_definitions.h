#pragma once

namespace blofeld
{

	constexpr unsigned long GLOBAL_PIXEL_SHADER_TAG = 'glps';
	constexpr unsigned long GLOBAL_VERTEX_SHADER_TAG = 'glvs';
	constexpr unsigned long GLOBAL_CACHE_FILE_PIXEL_SHADERS_TAG = 'gpix';
	constexpr unsigned long HLSL_INCLUDE_TAG = 'hlsl';
	constexpr unsigned long PIXEL_SHADER_TAG = 'pixl';
	constexpr unsigned long VERTEX_SHADER_TAG = 'vtsh';
	constexpr unsigned long COMPUTE_SHADER_TAG = 'cmpu';
	constexpr unsigned long COMPUTE_SHADER2_TAG = 'cmps';

	extern const char* shader_flags_strings[];
	extern s_string_list_definition shader_flags;

	extern s_tag_group hlsl_include_group;
	extern s_tag_block_definition hlsl_include_block_block;
	extern s_tag_struct_definition hlsl_include_struct_definition_struct_definition; // tag group

	extern s_tag_group global_pixel_shader_group;
	extern s_tag_block_definition global_pixel_shader_block;
	extern s_tag_struct_definition global_pixel_shader_block_struct;

	extern s_tag_group global_vertex_shader_group;
	extern s_tag_block_definition global_vertex_shader_block;
	extern s_tag_struct_definition global_vertex_shader_block_struct;
	extern s_tag_block_definition global_vertex_shader_vertex_types_block_block;
	extern s_tag_struct_definition global_vertex_shader_vertex_types_block_block_struct;

	extern s_tag_group pixel_shader_group;
	extern s_tag_block_definition pixel_shader_block;
	extern s_tag_struct_definition pixel_shader_block_struct;
	extern s_tag_block_definition pixel_entry_point_block_block;
	extern s_tag_struct_definition pixel_entry_point_block_block_struct;
	extern s_tag_block_definition compiled_pixel_shader_block_block;
	extern s_tag_struct_definition compiled_pixel_shader_block_block_struct;

	extern s_tag_group vertex_shader_group;
	extern s_tag_block_definition vertex_shader_block;
	extern s_tag_struct_definition vertex_shader_block_struct;
	extern s_tag_block_definition vertex_types_block$3_block;
	extern s_tag_struct_definition vertex_types_block$3_block_struct;
	extern s_tag_block_definition vertex_entry_point_block_block;
	extern s_tag_struct_definition vertex_entry_point_block_block_struct;
	extern s_tag_block_definition compiled_vertex_shader_block_block;
	extern s_tag_struct_definition compiled_vertex_shader_block_block_struct;

	extern s_tag_group compute_shader_group;
	extern s_tag_group compute_shader2_group;
	extern s_tag_block_definition compute_shader_block;
	extern s_tag_block_definition compute_shader2_block;
	extern s_tag_struct_definition compute_shader_block_struct;
	extern s_tag_struct_definition compute_shader2_block_struct;
	extern s_tag_block_definition compute_entry_point_block_block;
	extern s_tag_struct_definition compute_entry_point_block_block_struct;
	extern s_tag_block_definition compiled_compute_shader_block_block;
	extern s_tag_struct_definition compiled_compute_shader_block_block_struct;

	extern s_tag_struct_definition rasterizer_compiled_shader_struct_struct_definition;






	extern s_tag_group global_cache_file_pixel_shaders_group;
	extern s_tag_block_definition global_cache_file_pixel_shaders_block_block;
	extern s_tag_struct_definition global_cache_file_pixel_shaders_struct_definition_struct_definition; // tag group

	extern s_tag_block_definition global_shader_option_dependency_block;
	extern s_tag_struct_definition global_shader_option_dependency_block_struct;
	extern s_tag_block_definition global_shader_category_dependency_block;
	extern s_tag_struct_definition global_shader_category_dependency_block_struct;
	extern s_tag_block_definition global_shader_entry_point_block_block;
	extern s_tag_struct_definition global_shader_entry_point_block_block_struct;


} // namespace blofeld

