#pragma once

namespace blofeld
{

extern s_tag_block loadout_definition_block;
extern s_tag_block loadout_palette_definition_block;
extern s_tag_block loadout_index_block;
extern s_tag_block loadout_name_block;
extern s_tag_block custom_loadout_defaults_block;
extern s_tag_block game_engine_loadout_options_block;
extern s_tag_block game_engine_loadout_palette_entry_block;

constexpr unsigned long LOADOUT_GLOBALS_DEFINITION_TAG = 'lgtd';

extern s_tag_block loadout_globals_definition_block;
extern s_tag_group loadout_globals_definition_group;
} // namespace blofeld

