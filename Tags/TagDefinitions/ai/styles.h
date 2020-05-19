#pragma once

namespace blofeld
{

	constexpr unsigned long STYLE_TAG = 'styl';

	extern s_tag_group style_group;

	extern s_tag_struct_definition style_palette_block_block_struct;
	extern s_tag_block_definition style_palette_block_block;
	extern s_tag_struct_definition behavior_names_block_block_struct;
	extern s_tag_block_definition behavior_names_block_block;
	extern s_tag_block_definition style_block_block;

	extern s_tag_struct_definition style_struct_definition_struct_definition; // tag group

	extern const char* behavior_set1_strings[];
	extern s_string_list_definition behavior_set1;
	extern const char* behavior_set2_strings[];
	extern s_string_list_definition behavior_set2;
	extern const char* behavior_set3_strings[];
	extern s_string_list_definition behavior_set3;
	extern const char* behavior_set4_strings[];
	extern s_string_list_definition behavior_set4;
	extern const char* behavior_set5_strings[];
	extern s_string_list_definition behavior_set5;
	extern const char* behavior_set6_strings[];
	extern s_string_list_definition behavior_set6;
	extern const char* behavior_set7_strings[];
	extern s_string_list_definition behavior_set7;
	extern const char* behavior_set8_strings[];
	extern s_string_list_definition behavior_set8;
	extern const char* style_control_flags_strings[];
	extern s_string_list_definition style_control_flags;
	extern const char* combat_status_enum$2_strings[];
	extern s_string_list_definition combat_status_enum$2;

} // namespace blofeld

