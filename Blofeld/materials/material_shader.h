#pragma once

namespace blofeld
{

	extern const char* material_shader_flags_strings[];
	extern s_string_list_definition material_shader_flags;

	constexpr unsigned long MATERIAL_SHADER_TAG = 'mats';

	extern s_tag_struct material_shader_block_struct;
	extern s_tag_block_definition material_shader_block;
	extern s_tag_group material_shader_group;

	extern s_tag_struct material_shader_source_file_block_block_struct;
	extern s_tag_block_definition material_shader_source_file_block_block;
	extern s_tag_struct compiled_effects_block_block_struct;
	extern s_tag_block_definition compiled_effects_block_block;
	extern s_tag_struct material_vertex_shader_entry_point_block_block_struct;
	extern s_tag_block_definition material_vertex_shader_entry_point_block_block;
	extern s_tag_struct compiled_vertex_shader_refererence_block_block_struct;
	extern s_tag_block_definition compiled_vertex_shader_refererence_block_block;
	extern s_tag_struct compiled_pixel_shader_refererence_block_block_struct;
	extern s_tag_block_definition compiled_pixel_shader_refererence_block_block;


} // namespace blofeld

