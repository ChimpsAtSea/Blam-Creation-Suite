#pragma once

namespace blofeld
{

	constexpr unsigned long BINK_TAG = 'bink';

	extern s_tag_group bink_group;

	extern s_tag_block_definition bink_block_block;
	extern s_tag_struct_definition binkPaletteBlock_block_struct;
	extern s_tag_block_definition binkPaletteBlock_block;

	extern s_tag_struct_definition bink_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition bink_resource_struct_struct_definition;

} // namespace blofeld

