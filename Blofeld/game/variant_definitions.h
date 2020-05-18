#pragma once

namespace blofeld
{

	constexpr unsigned long VARIANT_GLOBALS_TAG = 'vtgl';

	extern s_tag_group variant_globals_group;

	extern s_tag_struct_definition single_variant_block_block_struct;
	extern s_tag_block_definition single_variant_block_block;
	extern s_tag_struct_definition FallbackHopperFileBlock_block_struct;
	extern s_tag_block_definition FallbackHopperFileBlock_block;
	extern s_tag_block_definition variant_globals_block_block;

	extern s_tag_struct_definition variant_globals_struct_definition_struct_definition; // tag group

} // namespace blofeld

