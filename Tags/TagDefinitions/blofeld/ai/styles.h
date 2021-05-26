#pragma once

namespace blofeld
{



	constexpr unsigned long STYLE_TAG = 'styl';
	extern s_tag_group style_group; // style_block


	extern s_tag_block_definition style_block;
	extern s_tag_block_definition style_palette_block;
	extern s_tag_struct_definition style_palette_block_struct_definition; // style_palette_block
	extern s_tag_block_definition behavior_names_block;
	extern s_tag_struct_definition behavior_names_block_struct_definition; // behavior_names_block

	extern s_tag_struct_definition style_struct_definition; // tag group

	extern c_versioned_string_list behavior_set1_strings;
	extern s_string_list_definition behavior_set1;
	extern c_versioned_string_list behavior_set2_strings;
	extern s_string_list_definition behavior_set2;
	extern c_versioned_string_list behavior_set3_strings;
	extern s_string_list_definition behavior_set3;
	extern c_versioned_string_list behavior_set4_strings;
	extern s_string_list_definition behavior_set4;
	extern c_versioned_string_list behavior_set5_strings;
	extern s_string_list_definition behavior_set5;
	extern c_versioned_string_list behavior_set6_strings;
	extern s_string_list_definition behavior_set6;
	extern c_versioned_string_list behavior_set7_strings;
	extern s_string_list_definition behavior_set7;
	extern c_versioned_string_list behavior_set8_strings;
	extern s_string_list_definition behavior_set8;
	extern c_versioned_string_list style_control_flags_strings;
	extern s_string_list_definition style_control_flags;
	extern c_versioned_string_list combat_status_enum$2_strings;
	extern s_string_list_definition combat_status_enum$2;



} // namespace blofeld

