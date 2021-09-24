#pragma once

namespace blofeld
{



	constexpr unsigned long GAME_GLOBALS_ORDNANCE_LIST_TAG = 'ggol';
	extern s_tag_group game_globals_ordnance_list_group; // game_globals_ordnance_list_block

	constexpr unsigned long SCENARIO_ORDNANCE_LIST_TAG = 'scol';
	extern s_tag_group scenario_ordnance_list_group; // scenario_ordnance_list_block


	extern s_tag_block_definition game_globals_ordnance_list_block;
	extern s_tag_block_definition scenario_ordnance_list_block;
	extern s_tag_block_definition GameGlobalsOrdnanceBlock_block;
	extern s_tag_struct_definition GameGlobalsOrdnanceBlock_block_struct_definition; // GameGlobalsOrdnanceBlock_block
	extern s_tag_block_definition OrdnanceRemappingVariantBlock_block;
	extern s_tag_struct_definition OrdnanceRemappingVariantBlock_block_struct_definition; // OrdnanceRemappingVariantBlock_block
	extern s_tag_block_definition OrdnanceRemappingBlock_block;
	extern s_tag_struct_definition OrdnanceRemappingBlock_block_struct_definition; // OrdnanceRemappingBlock_block
	extern s_tag_block_definition RandomOrdnanceItemBlock_block;
	extern s_tag_struct_definition RandomOrdnanceItemBlock_block_struct_definition; // RandomOrdnanceItemBlock_block
	extern s_tag_block_definition PlayerOrdnanceGroupBlock_block;
	extern s_tag_struct_definition PlayerOrdnanceGroupBlock_block_struct_definition; // PlayerOrdnanceGroupBlock_block
	extern s_tag_block_definition PlayerOrdnanceItemBlock_block;
	extern s_tag_struct_definition PlayerOrdnanceItemBlock_block_struct_definition; // PlayerOrdnanceItemBlock_block

	extern s_tag_struct_definition game_globals_ordnance_list_struct_definition; // tag group
	extern s_tag_struct_definition scenario_ordnance_list_struct_definition; // tag group

	extern s_string_list_definition GuiOrdnancePrimiumFlag;



} // namespace blofeld

