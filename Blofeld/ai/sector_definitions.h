#pragma once

namespace blofeld
{

extern s_tag_block pathfinding_data_block;
extern s_tag_block FaceUserDataBlock_block;
extern s_tag_block MobileNavMeshBlock_block;
extern s_tag_block NavVolumeBlock_block;
extern s_tag_block NavClimbBlock_block;
extern s_tag_block user_edge_block;

constexpr unsigned long PATHFINDING_TAG = 'pfnd';

extern s_tag_block pathfinding_block;
extern s_tag_group pathfinding_group;
} // namespace blofeld

