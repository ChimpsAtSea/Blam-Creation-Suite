#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long FORMATION_TAG = 'form';
	extern s_tag_group formation_group; // formation_block
	extern s_tag_block_definition formation_block;
	extern s_tag_struct_definition formation; // formation_block


	extern s_tag_block_definition formation_primitive_definition_block;
	extern s_tag_struct_definition formation_primitive_definition_block_struct_definition; // formation_primitive_definition_block
	extern s_tag_block_definition formation_point_definition_block;
	extern s_tag_struct_definition formation_point_definition_block_struct_definition; // formation_point_definition_block


	extern c_versioned_string_list formation_primitive_flags_strings;
	extern s_string_list_definition formation_primitive_flags;

} // namespace macaque

} // namespace blofeld

