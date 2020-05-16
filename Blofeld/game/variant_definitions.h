#pragma once

namespace blofeld
{

extern s_tag_struct variant_globals_struct_definition_struct_definition;

extern s_tag_struct single_variant_block_struct_definition;
extern s_tag_block_definition single_variant_block;
extern s_tag_struct FallbackHopperFileBlock_struct_definition;
extern s_tag_block_definition FallbackHopperFileBlock;

constexpr unsigned long VARIANT_GLOBALS_TAG = 'vtgl';

extern s_tag_block_definition variant_globals_block;
extern s_tag_group variant_globals_group;
} // namespace blofeld

