#pragma once

namespace blofeld
{

extern s_tag_struct custom_app_globals_struct_definition_struct_definition;

extern s_tag_struct custom_app_block_struct_definition;
extern s_tag_block_definition custom_app_block;
extern s_tag_struct custom_app_damage_modifier_block_struct_definition;
extern s_tag_block_definition custom_app_damage_modifier_block;

constexpr unsigned long CUSTOM_APP_GLOBALS_TAG = 'capg';

extern s_tag_block_definition custom_app_globals_block;
extern s_tag_group custom_app_globals_group;
} // namespace blofeld

