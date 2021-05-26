#pragma once

namespace blofeld
{



	constexpr unsigned long GIANT_TAG = 'gint';
	extern s_tag_group giant_group; // giant_block


	extern s_tag_block_definition giant_block;
	extern s_tag_block_definition giant_buckle_parameters_block;
	extern s_tag_struct_definition giant_buckle_parameters_block_struct_definition; // giant_buckle_parameters_block

	extern s_tag_struct_definition giant_struct_definition; // tag group

	extern c_versioned_string_list giant_definition_flags_strings;
	extern s_string_list_definition giant_definition_flags;
	extern c_versioned_string_list slider_movement_patterns_strings;
	extern s_string_list_definition slider_movement_patterns;



} // namespace blofeld

