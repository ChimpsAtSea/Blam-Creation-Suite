#pragma once

namespace blofeld
{

extern s_tag_struct achievements_struct_definition_struct_definition;

extern s_tag_struct single_achievement_definition_block_struct_definition;
extern s_tag_block_definition single_achievement_definition_block;
extern s_tag_struct single_achievement_restricted_level_block_struct_definition;
extern s_tag_block_definition single_achievement_restricted_level_block;

constexpr unsigned long ACHIEVEMENTS_TAG = 'achi';

extern s_tag_block_definition achievements_block;
extern s_tag_group achievements_group;
} // namespace blofeld

