#pragma once

namespace blofeld
{

extern s_tag_struct weather_globals_struct_definition_struct_definition;
extern s_tag_struct rain_ripple_setting_block_struct_definition;

extern s_tag_struct global_textures_refs_block_struct_definition;
extern s_tag_block_definition global_textures_refs_block;

constexpr unsigned long WEATHER_GLOBALS_TAG = 'wxcg';

extern s_tag_block_definition weather_globals_block;
extern s_tag_group weather_globals_group;
} // namespace blofeld

