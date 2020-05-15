#pragma once

namespace blofeld
{

extern s_tag_block default_textures_refs_block;
extern s_tag_block material_textures_refs_block;
extern s_tag_block explicit_shader_refs_block;

constexpr unsigned long RASTERIZER_GLOBALS_TAG = 'rasg';

extern s_tag_block rasterizer_globals_block;
extern s_tag_group rasterizer_globals_group;
} // namespace blofeld

