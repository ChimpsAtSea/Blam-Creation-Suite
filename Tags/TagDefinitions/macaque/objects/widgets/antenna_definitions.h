#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long ANTENNA_TAG = 'ant!';
	extern s_tag_group antenna_group; // antenna_block


	extern s_tag_block_definition antenna_block;
	extern s_tag_block_definition antenna_vertex_block;
	extern s_tag_struct_definition antenna_vertex_block_struct_definition; // antenna_vertex_block

	extern s_tag_struct_definition antenna_struct_definition; // tag group

} // namespace macaque

} // namespace blofeld

