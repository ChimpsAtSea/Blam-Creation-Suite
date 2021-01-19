#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long BINK_TAG = 'bink';
	extern s_tag_group bink_group; // bink_block


	extern s_tag_block_definition bink_block;
	extern s_tag_block_definition binkPaletteBlock_block;
	extern s_tag_struct_definition binkPaletteBlock_block_struct_definition; // binkPaletteBlock_block

	extern s_tag_struct_definition bink_struct_definition; // tag group
	extern s_tag_struct_definition bink_resource_struct;

} // namespace macaque

} // namespace blofeld

