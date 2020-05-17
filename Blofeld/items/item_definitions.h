#pragma once

namespace blofeld
{

	extern const char* item_definition_flags_strings[];
	extern s_string_list_definition item_definition_flags;

	constexpr unsigned long ITEM_TAG = 'item';

	extern s_tag_group item_group;

	extern s_tag_block_definition item_block_block;
	extern s_tag_struct predicted_bitmaps_block_block_struct;
	extern s_tag_block_definition predicted_bitmaps_block_block;

	extern s_tag_struct item_struct_definition_struct_definition; // tag group

} // namespace blofeld

