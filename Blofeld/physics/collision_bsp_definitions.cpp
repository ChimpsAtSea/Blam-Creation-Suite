#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(bsp3d_nodes_block, ((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_child_index_bits-1)))))
	{
		{ _field_int64_integer, "node data designator!" },
		{ _field_terminator }
	};

	TAG_BLOCK(bsp3d_kd_supdernodes_block, (k_bsp3d_maximum_super_node_count))
	{
		{ _field_real, "plane 0*!" },
		{ _field_real, "plane 1*!" },
		{ _field_real, "plane 2*!" },
		{ _field_real, "plane 3*!" },
		{ _field_real, "plane 4*!" },
		{ _field_real, "plane 5*!" },
		{ _field_real, "plane 6*!" },
		{ _field_real, "plane 7*!" },
		{ _field_real, "plane 8*!" },
		{ _field_real, "plane 9*!" },
		{ _field_real, "plane10*!" },
		{ _field_real, "plane11*!" },
		{ _field_real, "plane12*!" },
		{ _field_real, "plane13*!" },
		{ _field_real, "plane14*!" },
		{ _field_long_integer, "plane dimensions*!" },
		{ _field_long_integer, "child index 0*!" },
		{ _field_long_integer, "child index 1*!" },
		{ _field_long_integer, "child index 2*!" },
		{ _field_long_integer, "child index 3*!" },
		{ _field_long_integer, "child index 4*!" },
		{ _field_long_integer, "child index 5*!" },
		{ _field_long_integer, "child index 6*!" },
		{ _field_long_integer, "child index 7*!" },
		{ _field_long_integer, "child index 8*!" },
		{ _field_long_integer, "child index 9*!" },
		{ _field_long_integer, "child index10*!" },
		{ _field_long_integer, "child index11*!" },
		{ _field_long_integer, "child index12*!" },
		{ _field_long_integer, "child index13*!" },
		{ _field_long_integer, "child index14*!" },
		{ _field_long_integer, "child index15*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(planes_block, ((((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))>(((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))?(((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits))))):(((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))))
	{
		{ _field_real_plane_3d, "plane*" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(leaves_block, ((false) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))), collision_leaf_struct_struct_definition );

	TAG_BLOCK(bsp2d_references_block, ((false) ? 2147483647L>>2 : 196608))
	{
		{ _field_short_integer, "plane*" },
		{ _field_short_integer, "bsp2d node*" },
		{ _field_terminator }
	};

	TAG_BLOCK(bsp2d_nodes_block, ((false) ? 2147483647L>>2 : SHORT_MAX))
	{
		{ _field_real_plane_2d, "plane*" },
		{ _field_short_integer, "left child*" },
		{ _field_short_integer, "right child*" },
		{ _field_terminator }
	};

	TAG_BLOCK(surfaces_block, ((false) ? SHORT_MAX<<3 : SHORT_MAX))
	{
		{ _field_word_integer, "plane index*" },
		{ _field_word_integer, "first edge*" },
		{ _field_short_integer, "material*" },
		{ _field_short_integer, "breakable surface set*" },
		{ _field_short_integer, "breakable surface*" },
		{ _field_byte_flags, "flags*", &surface_flags },
		{ _field_byte_integer, "best plane calculation vertex index *!" },
		{ _field_terminator }
	};

	TAG_BLOCK(edges_block, ((false) ? 2621440 : UNSIGNED_SHORT_MAX))
	{
		{ _field_word_integer, "start vertex*" },
		{ _field_word_integer, "end vertex*" },
		{ _field_word_integer, "forward edge*" },
		{ _field_word_integer, "reverse edge*" },
		{ _field_word_integer, "left surface*" },
		{ _field_word_integer, "right surface*" },
		{ _field_terminator }
	};

	TAG_BLOCK(vertices_block, ((false) ? 1310720 : 131072))
	{
		{ _field_real_point_3d, "point*" },
		{ _field_word_integer, "first edge*" },
		{ _field_short_integer, "sink*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_collision_bsp_block, 1)
	{
		{ _field_block, "bsp3d nodes*", &bsp3d_nodes_block_block },
		{ _field_block, "bsp3d supernodes*", &bsp3d_kd_supdernodes_block_block },
		{ _field_block, "planes*", &planes_block_block },
		{ _field_block, "leaves*", &leaves_block_block },
		{ _field_block, "bsp2d references*", &bsp2d_references_block_block },
		{ _field_block, "bsp2d nodes*", &bsp2d_nodes_block_block },
		{ _field_block, "surfaces*", &surfaces_block_block },
		{ _field_block, "edges*", &edges_block_block },
		{ _field_block, "vertices*", &vertices_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(large_bsp3d_nodes_block, ((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_child_index_bits-1)))))
	{
		{ _field_long_integer, "plane*" },
		{ _field_long_integer, "back child*" },
		{ _field_long_integer, "front child*" },
		{ _field_terminator }
	};

	TAG_BLOCK(large_leaves_block, ((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))))
	{
		{ _field_word_flags, "flags*", &leaf_flags },
		{ _field_short_integer, "bsp2d reference count*" },
		{ _field_long_integer, "first bsp2d reference*" },
		{ _field_terminator }
	};

	TAG_BLOCK(large_bsp2d_references_block, ((true) ? 2147483647L>>2 : 196608))
	{
		{ _field_long_integer, "plane*" },
		{ _field_long_integer, "bsp2d node*" },
		{ _field_terminator }
	};

	TAG_BLOCK(large_bsp2d_nodes_block, ((true) ? 2147483647L>>2 : SHORT_MAX))
	{
		{ _field_real_plane_2d, "plane*" },
		{ _field_long_integer, "left child*" },
		{ _field_long_integer, "right child*" },
		{ _field_terminator }
	};

	TAG_BLOCK(large_surfaces_block, ((true) ? SHORT_MAX<<3 : SHORT_MAX))
	{
		{ _field_long_integer, "plane index*" },
		{ _field_long_integer, "first edge*" },
		{ _field_short_integer, "material*" },
		{ _field_short_integer, "breakable surface set*" },
		{ _field_short_integer, "breakable surface*" },
		{ _field_byte_flags, "flags*", &surface_flags },
		{ _field_byte_integer, "best plane calculation vertex index *!" },
		{ _field_terminator }
	};

	TAG_BLOCK(large_edges_block, ((true) ? 2621440 : UNSIGNED_SHORT_MAX))
	{
		{ _field_long_integer, "start vertex*" },
		{ _field_long_integer, "end vertex*" },
		{ _field_long_integer, "forward edge*" },
		{ _field_long_integer, "reverse edge*" },
		{ _field_long_integer, "left surface*" },
		{ _field_long_integer, "right surface*" },
		{ _field_terminator }
	};

	TAG_BLOCK(large_vertices_block, ((true) ? 1310720 : 131072))
	{
		{ _field_real_point_3d, "point*" },
		{ _field_long_integer, "first edge*" },
		{ _field_long_integer, "sink*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_large_collision_bsp_block, 1)
	{
		{ _field_block, "bsp3d nodes*", &large_bsp3d_nodes_block_block },
		{ _field_block, "bsp3d supernodes*", &bsp3d_kd_supdernodes_block_block },
		{ _field_block, "planes*", &planes_block_block },
		{ _field_block, "leaves*", &large_leaves_block_block },
		{ _field_block, "bsp2d references*", &large_bsp2d_references_block_block },
		{ _field_block, "bsp2d nodes*", &large_bsp2d_nodes_block_block },
		{ _field_block, "surfaces*", &large_surfaces_block_block },
		{ _field_block, "edges*", &large_edges_block_block },
		{ _field_block, "vertices*", &large_vertices_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(global_collision_bsp_struct)
	{
		{ _field_block, "bsp3d nodes*", &bsp3d_nodes_block_block },
		{ _field_block, "bsp3d supernodes*", &bsp3d_kd_supdernodes_block_block },
		{ _field_block, "planes*", &planes_block_block },
		{ _field_block, "leaves*", &leaves_block_block },
		{ _field_block, "bsp2d references*", &bsp2d_references_block_block },
		{ _field_block, "bsp2d nodes*", &bsp2d_nodes_block_block },
		{ _field_block, "surfaces*", &surfaces_block_block },
		{ _field_block, "edges*", &edges_block_block },
		{ _field_block, "vertices*", &vertices_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(collision_leaf_struct)
	{
		{ _field_byte_flags, "flags*", &leaf_flags },
		{ _field_pad, "pad", 1 },
		{ _field_word_integer, "bsp2d reference count*" },
		{ _field_dword_integer, "first bsp2d reference*" },
		{ _field_terminator }
	};

	STRINGS(leaf_flags)
	{
		"contains double-sided surfaces"
	};
	STRING_LIST(leaf_flags, leaf_flags_strings, _countof(leaf_flags_strings));

	STRINGS(surface_flags)
	{
		"two sided",
		"invisible",
		"climbable",
		"breakable",
		"invalid",
		"conveyor",
		"slip",
		"plane negated"
	};
	STRING_LIST(surface_flags, surface_flags_strings, _countof(surface_flags_strings));

} // namespace blofeld

