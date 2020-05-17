#pragma once

namespace blofeld
{

	constexpr unsigned long FORMATION_TAG = 'form';

	extern s_tag_struct_definition formation_block_struct;
	extern s_tag_block_definition formation_block;
	extern s_tag_group formation_group;

	extern s_tag_struct_definition formation_point_definition_block_struct;
	extern s_tag_block_definition formation_point_definition_block;
	extern s_tag_struct_definition formation_primitive_definition_block_struct;
	extern s_tag_block_definition formation_primitive_definition_block;



	extern const char* formation_primitive_flags_strings[];
	extern s_string_list_definition formation_primitive_flags;

} // namespace blofeld

