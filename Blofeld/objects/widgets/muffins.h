#pragma once

namespace blofeld
{

	constexpr unsigned long MUFFIN_TAG = 'mffn';

	extern s_tag_struct_definition muffin_block_struct;
	extern s_tag_block_definition muffin_block;
	extern s_tag_group muffin_group;

	extern s_tag_struct_definition muffin_permutation_name_block_block_struct;
	extern s_tag_block_definition muffin_permutation_name_block_block;
	extern s_tag_struct_definition muffin_marker_block_block_struct;
	extern s_tag_block_definition muffin_marker_block_block;
	extern s_tag_block_definition global_muffin_type_block_block;


	extern s_tag_struct_definition global_muffin_type_struct_struct_definition;
	extern s_tag_struct_definition muffin_scalar_function_struct_struct_definition;

	extern const char* muffin_type_flags_definition_strings[];
	extern s_string_list_definition muffin_type_flags_definition;

} // namespace blofeld

