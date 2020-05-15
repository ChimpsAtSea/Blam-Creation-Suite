#pragma once

namespace blofeld
{

extern s_tag_block lightmap_model_reference_block;

constexpr unsigned long LIGHTMAP_MODEL_GLOBALS_TAG = 'LMMg';

extern s_tag_block lightmap_model_globals_block;
extern s_tag_group lightmap_model_globals_group;
constexpr unsigned long LIGHTMAPPER_GLOBALS_TAG = 'LMgS';

extern s_tag_block lightmapper_globals_block;
extern s_tag_group lightmapper_globals_group;
} // namespace blofeld

