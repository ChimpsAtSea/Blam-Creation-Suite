#pragma once

namespace blofeld
{



	constexpr unsigned long ITEM_TAG = 'item';
	extern s_tag_group item_group; // item_block


	extern s_tag_block_definition item_block;
	extern s_tag_block_definition predicted_bitmaps_block;
	extern s_tag_struct_definition predicted_bitmaps_block_struct_definition; // predicted_bitmaps_block

	extern s_tag_struct_definition item_struct_definition; // tag group

	extern s_string_list_definition item_definition_flags;

	extern s_tag_reference_definition object_reference$3;
	extern s_tag_reference_definition global_item_reference;



} // namespace blofeld

