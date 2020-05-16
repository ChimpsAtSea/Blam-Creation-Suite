#pragma once

namespace blofeld
{

extern s_tag_struct airstrike_struct_definition_struct_definition;

extern s_tag_struct airstrike_battery_block_struct_definition;
extern s_tag_block_definition airstrike_battery_block;
extern s_tag_struct airstrike_fire_location_block_struct_definition;
extern s_tag_block_definition airstrike_fire_location_block;

constexpr unsigned long AIRSTRIKE_TAG = 'airs';

extern s_tag_block_definition airstrike_block;
extern s_tag_group airstrike_group;
} // namespace blofeld

