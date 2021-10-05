#pragma once

namespace blofeld
{



	constexpr unsigned long CLOTH_TAG = 'clwd';
	extern s_tag_group cloth_group; // cloth_block


	extern s_tag_block_definition cloth_block;
	extern s_tag_block_definition collision_sphere_block;
	extern s_tag_struct_definition collision_sphere_block_struct_definition; // collision_sphere_block
	extern s_tag_block_definition cloth_vertices_block;
	extern s_tag_struct_definition cloth_vertices_block_struct_definition; // cloth_vertices_block
	extern s_tag_block_definition cloth_indices_block;
	extern s_tag_struct_definition cloth_indices_block_struct_definition; // cloth_indices_block
	extern s_tag_block_definition cloth_links_block;
	extern s_tag_struct_definition cloth_links_block_struct_definition; // cloth_links_block

	extern s_tag_struct_definition cloth_struct_definition; // tag group
	extern s_tag_struct_definition cloth_properties;

	extern s_string_list_definition cloth_flags;
	extern s_string_list_definition cloth_integration_enum;

	extern s_tag_reference_definition global_shader_reference;



} // namespace blofeld

