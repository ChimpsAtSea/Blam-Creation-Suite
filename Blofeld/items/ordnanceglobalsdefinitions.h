#pragma once

namespace blofeld
{

extern s_tag_block GameGlobalsOrdnanceBlock_block;
extern s_tag_block OrdnanceRemappingVariantBlock_block;
extern s_tag_block OrdnanceRemappingBlock_block;
extern s_tag_block RandomOrdnanceItemBlock_block;
extern s_tag_block PlayerOrdnanceGroupBlock_block;
extern s_tag_block PlayerOrdnanceItemBlock_block;

constexpr unsigned long GAME_GLOBALS_ORDNANCE_LIST_TAG = 'ggol';

extern s_tag_block game_globals_ordnance_list_block;
extern s_tag_group game_globals_ordnance_list_group;
constexpr unsigned long SCENARIO_ORDNANCE_LIST_TAG = 'scol';

extern s_tag_block scenario_ordnance_list_block;
extern s_tag_group scenario_ordnance_list_group;
} // namespace blofeld

