#pragma once

namespace blofeld
{

extern s_tag_struct cloth_struct_definition_struct_definition;
extern s_tag_struct cloth_properties_struct_definition;

extern s_tag_struct collision_sphere_block_struct_definition;
extern s_tag_block_definition collision_sphere_block;
extern s_tag_struct cloth_vertices_block_struct_definition;
extern s_tag_block_definition cloth_vertices_block;
extern s_tag_struct cloth_indices_block_struct_definition;
extern s_tag_block_definition cloth_indices_block;
extern s_tag_struct cloth_links_block_struct_definition;
extern s_tag_block_definition cloth_links_block;

constexpr unsigned long CLOTH_TAG = 'clwd';

extern s_tag_block_definition cloth_block;
extern s_tag_group cloth_group;
} // namespace blofeld

