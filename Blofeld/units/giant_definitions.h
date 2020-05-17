#pragma once

namespace blofeld
{

	extern const char* giant_definition_flags_strings[];
	extern s_string_list_definition giant_definition_flags;
	extern const char* slider_movement_patterns_strings[];
	extern s_string_list_definition slider_movement_patterns;

	constexpr unsigned long GIANT_TAG = 'gint';

	extern s_tag_group giant_group;

	extern s_tag_block_definition giant_block_block;
	extern s_tag_struct giant_buckle_parameters_block_block_struct;
	extern s_tag_block_definition giant_buckle_parameters_block_block;

	extern s_tag_struct giant_struct_definition_struct_definition; // tag group

} // namespace blofeld

