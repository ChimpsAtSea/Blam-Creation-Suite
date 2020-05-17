#pragma once

namespace blofeld
{

	constexpr unsigned long CLOTH_TAG = 'clwd';

	extern s_tag_group cloth_group;

	extern s_tag_struct_definition collision_sphere_block_block_struct;
	extern s_tag_block_definition collision_sphere_block_block;
	extern s_tag_struct_definition cloth_vertices_block_block_struct;
	extern s_tag_block_definition cloth_vertices_block_block;
	extern s_tag_struct_definition cloth_indices_block_block_struct;
	extern s_tag_block_definition cloth_indices_block_block;
	extern s_tag_struct_definition cloth_links_block_block_struct;
	extern s_tag_block_definition cloth_links_block_block;
	extern s_tag_block_definition cloth_block_block;


	extern s_tag_struct_definition cloth_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition cloth_properties_struct_definition;

	extern const char* cloth_flags_strings[];
	extern s_string_list_definition cloth_flags;
	extern const char* cloth_integration_enum_strings[];
	extern s_string_list_definition cloth_integration_enum;

} // namespace blofeld

