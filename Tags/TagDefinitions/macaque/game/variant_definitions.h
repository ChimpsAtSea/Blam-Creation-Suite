#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long VARIANT_GLOBALS_TAG = 'vtgl';
	extern s_tag_group variant_globals_group; // variant_globals_block


	extern s_tag_block_definition variant_globals_block;
	extern s_tag_block_definition single_variant_block;
	extern s_tag_struct_definition single_variant_block_struct_definition; // single_variant_block
	extern s_tag_block_definition FallbackHopperFileBlock_block;
	extern s_tag_struct_definition FallbackHopperFileBlock_block_struct_definition; // FallbackHopperFileBlock_block

	extern s_tag_struct_definition variant_globals_struct_definition; // tag group

} // namespace macaque

} // namespace blofeld

