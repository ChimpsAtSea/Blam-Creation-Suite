#pragma once

namespace blofeld
{

extern s_tag_struct creature_struct_definition_struct_definition;

extern s_tag_struct creature_scalar_timing_block_struct_definition;
extern s_tag_block_definition creature_scalar_timing_block;

constexpr unsigned long BIG_BATTLE_CREATURE_TAG = 'bbcr';

extern s_tag_block_definition big_battle_creature_block;
extern s_tag_group big_battle_creature_group;
constexpr unsigned long CREATURE_TAG = 'crea';

extern s_tag_block_definition creature_block;
extern s_tag_group creature_group;
} // namespace blofeld

