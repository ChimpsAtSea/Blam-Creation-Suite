#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

struct s_bsp3d_node
{
	long long node_data_designator;
};
static_assert(sizeof(s_bsp3d_node) == 0x8);

struct s_bsp3d_kd_supernode
{
	real plane[15];
	long plane_dimensions;
	long child_indices[16];
};
static_assert(sizeof(s_bsp3d_kd_supernode) == 0x80);

enum e_collision_bsp_leaf_flags
{
	_collision_bsp_leaf_contains_double_sided_surfaces_bit,
	k_number_of_collision_bsp_leaf_flags
};

struct s_collision_bsp_leaf
{
	c_flags<e_collision_bsp_leaf_flags, byte> flags;
	char : 8;
	word bsp2d_reference_count;
	dword first_bsp2d_reference;
};
static_assert(sizeof(s_collision_bsp_leaf) == 0x8);

struct s_bsp2d_node
{
	real_plane2d plane;
	c_tag_block_index<s_bsp2d_node, short> left_child;
	c_tag_block_index<s_bsp2d_node, short> right_child;
};
static_assert(sizeof(s_bsp2d_node) == 0x10);

struct s_bsp2d_reference
{
	c_tag_block_index<real_plane3d, short> plane;
	c_tag_block_index<s_bsp2d_node, short> bsp2d_node;
};
static_assert(sizeof(s_bsp2d_reference) == 0x4);

struct s_collision_bsp_surface;
struct s_collision_bsp_edge;

struct s_collision_bsp_vertex
{
	real_point3d point;
	c_tag_block_index<s_collision_bsp_edge, word> first_edge;
	short sink;
};
static_assert(sizeof(s_collision_bsp_vertex) == 0x10);

struct s_collision_bsp_edge
{
	c_tag_block_index<s_collision_bsp_vertex, word> start_vertex;
	c_tag_block_index<s_collision_bsp_vertex, word> end_vertex;
	c_tag_block_index<s_collision_bsp_edge, word> forward_edge;
	c_tag_block_index<s_collision_bsp_edge, word> reverse_edge;
	c_tag_block_index<s_collision_bsp_surface, word> left_surface;
	c_tag_block_index<s_collision_bsp_surface, word> right_surface;
};
static_assert(sizeof(s_collision_bsp_edge) == 0xC);

enum e_collision_bsp_surface_flags
{
	_collision_bsp_surface_two_sided_bit,
	_collision_bsp_surface_invisible_bit,
	_collision_bsp_surface_climbable_bit,
	_collision_bsp_surface_invalid_bit,
	_collision_bsp_surface_conveyor_bit,
	_collision_bsp_surface_slip_bit,
	_collision_bsp_surface_plane_negated_bit,
	k_number_of_collision_bsp_surface_flags
};

struct s_collision_bsp_surface
{
	c_tag_block_index<real_plane3d, word> plane;
	c_tag_block_index<s_collision_bsp_edge, word> first_edge;
	short material_index; // TODO: block index
	c_enum<e_collision_bsp_surface_flags, byte> flags;
	byte best_plane_calculation_vertex_index;
};
static_assert(sizeof(s_collision_bsp_surface) == 0x8);

struct s_collision_bsp
{
	c_typed_tag_block<s_bsp3d_node> bsp3d_nodes;
	c_typed_tag_block<s_bsp3d_kd_supernode> bsp3d_supernodes;
	c_typed_tag_block<real_plane3d> planes;
	c_typed_tag_block<s_collision_bsp_leaf> leaves;
	c_typed_tag_block<s_bsp2d_reference> bsp2d_references;
	c_typed_tag_block<s_bsp2d_node> bsp2d_nodes;
	c_typed_tag_block<s_collision_bsp_surface> surfaces;
	c_typed_tag_block<s_collision_bsp_edge> edges;
	c_typed_tag_block<s_collision_bsp_vertex> vertices;
};
static_assert(sizeof(s_collision_bsp) == 0x6C);
