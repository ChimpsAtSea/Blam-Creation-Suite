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

	extern s_string_list_definition behavior_set1;
	extern s_string_list_definition behavior_set2;
	extern s_string_list_definition behavior_set3;
	extern s_string_list_definition behavior_set4;
	extern s_string_list_definition behavior_set5;
	extern s_string_list_definition behavior_set6;
	extern s_string_list_definition behavior_set7;
	extern s_string_list_definition behavior_set8;
	extern s_string_list_definition style_control_flags;
	extern s_string_list_definition combat_status_enum$2;



} // namespace blofeld

