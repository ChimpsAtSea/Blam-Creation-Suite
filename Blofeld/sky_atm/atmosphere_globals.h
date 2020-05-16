#pragma once

namespace blofeld
{

extern s_tag_struct atmosphere_globals_struct_definition_struct_definition;

extern s_tag_struct underwater_setting_block_struct_definition;
extern s_tag_block_definition underwater_setting_block;

constexpr unsigned long ATMOSPHERE_GLOBALS_TAG = 'atgf';

extern s_tag_block_definition atmosphere_globals_block;
extern s_tag_group atmosphere_globals_group;
} // namespace blofeld

