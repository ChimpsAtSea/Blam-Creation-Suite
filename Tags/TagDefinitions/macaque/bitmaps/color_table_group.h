#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long COLOR_TABLE_TAG = 'colo';
	extern s_tag_group color_table_group; // color_table_block


	extern s_tag_block_definition color_table_block;
	extern s_tag_block_definition color_block;
	extern s_tag_struct_definition color_block_struct_definition; // color_block

	extern s_tag_struct_definition color_table_struct_definition; // tag group

	extern s_tag_reference_definition global_color_table_reference;

} // namespace macaque

} // namespace blofeld

