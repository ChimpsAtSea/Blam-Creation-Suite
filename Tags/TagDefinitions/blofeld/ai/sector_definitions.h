#pragma once

namespace blofeld
{



	constexpr unsigned long PATHFINDING_TAG = 'pfnd';
	extern s_tag_group pathfinding_group; // pathfinding_block
	extern s_tag_block_definition pathfinding_block;
	extern s_tag_struct_definition pathfinding_block_struct_definition; // pathfinding_block


	extern s_tag_block_definition pathfinding_data_block;
	extern s_tag_struct_definition pathfinding_data_block_struct_definition; // pathfinding_data_block
	extern s_tag_block_definition FaceUserDataBlock_block;
	extern s_tag_struct_definition FaceUserDataBlock_block_struct_definition; // FaceUserDataBlock_block
	extern s_tag_block_definition MobileNavMeshBlock_block;
	extern s_tag_struct_definition MobileNavMeshBlock_block_struct_definition; // MobileNavMeshBlock_block
	extern s_tag_block_definition NavVolumeBlock_block;
	extern s_tag_struct_definition NavVolumeBlock_block_struct_definition; // NavVolumeBlock_block
	extern s_tag_block_definition NavClimbBlock_block;
	extern s_tag_struct_definition NavClimbBlock_block_struct_definition; // NavClimbBlock_block
	extern s_tag_block_definition user_edge_block;
	extern s_tag_struct_definition user_edge_block_struct_definition; // user_edge_block


	extern s_string_list_definition MobileNavMeshFlagsDefinition;



} // namespace blofeld

