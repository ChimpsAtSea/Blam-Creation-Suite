#pragma once

namespace blofeld
{



	constexpr unsigned long GLOBAL_PIXEL_SHADER_TAG = 'glps';
	extern s_tag_group global_pixel_shader_group; // global_pixel_shader_block
	extern s_tag_block_definition global_pixel_shader_block;
	extern s_tag_struct_definition global_pixel_shader_block_struct_definition; // global_pixel_shader_block

	constexpr unsigned long GLOBAL_VERTEX_SHADER_TAG = 'glvs';
	extern s_tag_group global_vertex_shader_group; // global_vertex_shader_block
	extern s_tag_block_definition global_vertex_shader_block;
	extern s_tag_struct_definition global_vertex_shader_block_struct_definition; // global_vertex_shader_block

	constexpr unsigned long GLOBAL_CACHE_FILE_PIXEL_SHADERS_TAG = 'gpix';
	extern s_tag_group global_cache_file_pixel_shaders_group; // global_cache_file_pixel_shaders_block

	constexpr unsigned long HLSL_INCLUDE_TAG = 'hlsl';
	extern s_tag_group hlsl_include_group; // hlsl_include_block

	constexpr unsigned long PIXEL_SHADER_TAG = 'pixl';
	extern s_tag_group pixel_shader_group; // pixel_shader_block
	extern s_tag_block_definition pixel_shader_block;
	extern s_tag_struct_definition pixel_shader_block_struct_definition; // pixel_shader_block

	constexpr unsigned long VERTEX_SHADER_TAG = 'vtsh';
	extern s_tag_group vertex_shader_group; // vertex_shader_block
	extern s_tag_block_definition vertex_shader_block;
	extern s_tag_struct_definition vertex_shader_block_struct_definition; // vertex_shader_block

	constexpr unsigned long COMPUTE_SHADER_TAG = 'cmpu';
	constexpr unsigned long COMPUTE_SHADER2_TAG = 'cmps';
	extern s_tag_group compute_shader_group; // compute_shader_block
	extern s_tag_group compute_shader2_group; // compute_shader_block
	extern s_tag_block_definition compute_shader_block;
	extern s_tag_struct_definition compute_shader_block_struct_definition; // compute_shader_block

	extern s_tag_block_definition global_cache_file_pixel_shaders_block;
	extern s_tag_block_definition hlsl_include_block;
	extern s_tag_block_definition global_shader_entry_point_block;
	extern s_tag_struct_definition global_shader_entry_point_block_struct_definition; // global_shader_entry_point_block
	extern s_tag_block_definition global_shader_category_dependency_block;
	extern s_tag_struct_definition global_shader_category_dependency_block_struct_definition; // global_shader_category_dependency_block
	extern s_tag_block_definition global_shader_option_dependency_block;
	extern s_tag_struct_definition global_shader_option_dependency_block_struct_definition; // global_shader_option_dependency_block
	extern s_tag_block_definition compiled_pixel_shader_block;
	extern s_tag_struct_definition compiled_pixel_shader_block_struct_definition; // compiled_pixel_shader_block
	extern s_tag_block_definition global_vertex_shader_vertex_types_block;
	extern s_tag_struct_definition global_vertex_shader_vertex_types_block_struct_definition; // global_vertex_shader_vertex_types_block
	extern s_tag_block_definition compiled_vertex_shader_block;
	extern s_tag_struct_definition compiled_vertex_shader_block_struct_definition; // compiled_vertex_shader_block
	extern s_tag_block_definition compiled_compute_shader_block;
	extern s_tag_struct_definition compiled_compute_shader_block_struct_definition; // compiled_compute_shader_block
	extern s_tag_block_definition pixel_entry_point_block;
	extern s_tag_struct_definition pixel_entry_point_block_struct_definition; // pixel_entry_point_block
	extern s_tag_block_definition vertex_entry_point_block;
	extern s_tag_struct_definition vertex_entry_point_block_struct_definition; // vertex_entry_point_block
	extern s_tag_block_definition vertex_types_block$3_block;
	extern s_tag_struct_definition vertex_types_block$3_block_struct_definition; // vertex_types_block$3_block
	extern s_tag_block_definition compute_entry_point_block;
	extern s_tag_struct_definition compute_entry_point_block_struct_definition; // compute_entry_point_block

	extern s_tag_struct_definition global_cache_file_pixel_shaders_struct_definition; // tag group
	extern s_tag_struct_definition hlsl_include_struct_definition; // tag group
	extern s_tag_struct_definition rasterizer_compiled_shader_struct;

	extern c_versioned_string_list shader_flags_strings;
	extern s_string_list_definition shader_flags;



} // namespace blofeld

