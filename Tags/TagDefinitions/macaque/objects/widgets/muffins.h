#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long MUFFIN_TAG = 'mffn';
	extern s_tag_group muffin_group; // muffin_block
	extern s_tag_block_definition muffin_block;
	extern s_tag_struct_definition muffin; // muffin_block


	extern s_tag_block_definition muffin_permutation_name_block;
	extern s_tag_struct_definition muffin_permutation_name_block_struct_definition; // muffin_permutation_name_block
	extern s_tag_block_definition muffin_marker_block;
	extern s_tag_struct_definition muffin_marker_block_struct_definition; // muffin_marker_block
	extern s_tag_block_definition global_muffin_type_block;

	extern s_tag_struct_definition global_muffin_type_struct;
	extern s_tag_struct_definition muffin_scalar_function_struct;

	extern c_versioned_string_list muffin_type_flags_definition_strings;
	extern s_string_list_definition muffin_type_flags_definition;

} // namespace macaque

} // namespace blofeld

