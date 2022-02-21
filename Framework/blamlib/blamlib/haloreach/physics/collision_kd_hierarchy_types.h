#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/memory/static_arrays.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- types */

enum e_collision_kd_hierarchy_cull_flags
{
	_collision_kd_hierarchy_render_only_bit,
	_collision_kd_hierarchy_does_not_block_aoe_bit,
	_collision_kd_hierarchy_non_pathfindable_bit,
	k_number_of_collision_kd_hierarchy_cull_flags
};

struct s_collision_kd_hierarchy_static_hash_table_data
{
	long node_index;
	long key_a;
	long key_b;
	long key_c;
};
static_assert(sizeof(s_collision_kd_hierarchy_static_hash_table_data) == 0x10);

struct s_collision_kd_hierarchy_static_hash_table_header
{
	c_flags<e_collision_kd_hierarchy_cull_flags, word> cull_flags;
	short instance_index;
	dword instance_mask;
	short bsp_index;
	short : 16;
	dword bsp_mask;
};
static_assert(sizeof(s_collision_kd_hierarchy_static_hash_table_header) == 0x10);

struct s_collision_kd_hierarchy_static_node
{
	c_typed_tag_block<s_collision_kd_hierarchy_static_hash_table_header> render_only_headers;
	c_typed_tag_block<s_collision_kd_hierarchy_static_hash_table_header> collidable_headers;
	c_tag_block_index<s_collision_kd_hierarchy_static_node, short> child_below;
	c_tag_block_index<s_collision_kd_hierarchy_static_node, short> child_above;
	c_tag_block_index<s_collision_kd_hierarchy_static_node, short> parent;
	short cluster_index;
};
static_assert(sizeof(s_collision_kd_hierarchy_static_node) == 0x20);

struct s_collision_kd_hierarchy_super_node_mapping
{
	c_tag_block_index<s_collision_kd_hierarchy_static_node, short> nodes[32];
};
static_assert(sizeof(s_collision_kd_hierarchy_super_node_mapping) == 0x40);

struct s_collision_kd_hierarchy_cluster_mapping
{
	c_typed_tag_block<s_collision_kd_hierarchy_super_node_mapping> super_node_mappings;
};
static_assert(sizeof(s_collision_kd_hierarchy_cluster_mapping) == 0xC);

struct s_collision_kd_hierarchy_static
{
	long hash_total_count;
	c_typed_tag_block<s_collision_kd_hierarchy_static_hash_table_data> hash_data;
	c_typed_tag_block<short> hash_entry_count;
	c_typed_tag_block<short> original_hash_entry_count;
	c_typed_tag_block<s_collision_kd_hierarchy_static_node> nodes;
	c_typed_tag_block<dword> in_use_masks;
	c_typed_tag_block<s_collision_kd_hierarchy_cluster_mapping> cluster_table;
};
static_assert(sizeof(s_collision_kd_hierarchy_static) == 0x4C);
