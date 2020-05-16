#pragma once

namespace blofeld
{


extern s_tag_struct pathfinding_data_block_struct_definition;
extern s_tag_block_definition pathfinding_data_block;
extern s_tag_struct FaceUserDataBlock_struct_definition;
extern s_tag_block_definition FaceUserDataBlock;
extern s_tag_struct MobileNavMeshBlock_struct_definition;
extern s_tag_block_definition MobileNavMeshBlock;
extern s_tag_struct NavVolumeBlock_struct_definition;
extern s_tag_block_definition NavVolumeBlock;
extern s_tag_struct NavClimbBlock_struct_definition;
extern s_tag_block_definition NavClimbBlock;
extern s_tag_struct user_edge_block_struct_definition;
extern s_tag_block_definition user_edge_block;

constexpr unsigned long PATHFINDING_TAG = 'pfnd';

extern s_tag_block_definition pathfinding_block;
extern s_tag_group pathfinding_group;
} // namespace blofeld

