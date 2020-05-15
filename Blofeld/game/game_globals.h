#pragma once

namespace blofeld
{

extern s_tag_block havok_cleanup_resources_block;
extern s_tag_block sound$2_block;
extern s_tag_block soft_ceiling_globals_block;
extern s_tag_block cheat_weapons_block;
extern s_tag_block cheat_powerups_block;
extern s_tag_block multiplayer_color_block;
extern s_tag_block visor_color_block;

constexpr unsigned long GLOBALS_TAG = 'matg';

extern s_tag_block globals_block;
extern s_tag_group globals_group;
constexpr unsigned long PATCH_GLOBALS_TAG = 'patg';

extern s_tag_block patch_globals_block;
extern s_tag_group patch_globals_group;
} // namespace blofeld

