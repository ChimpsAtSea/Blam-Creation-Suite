#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(bsp3d_nodes_block, ((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_child_index_bits-1)))))
{
	FIELD( _field_int64_integer, "node data designator!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(bsp3d_kd_supdernodes_block, (k_bsp3d_maximum_super_node_count))
{
	FIELD( _field_real, "plane 0*!" ),
	FIELD( _field_real, "plane 1*!" ),
	FIELD( _field_real, "plane 2*!" ),
	FIELD( _field_real, "plane 3*!" ),
	FIELD( _field_real, "plane 4*!" ),
	FIELD( _field_real, "plane 5*!" ),
	FIELD( _field_real, "plane 6*!" ),
	FIELD( _field_real, "plane 7*!" ),
	FIELD( _field_real, "plane 8*!" ),
	FIELD( _field_real, "plane 9*!" ),
	FIELD( _field_real, "plane10*!" ),
	FIELD( _field_real, "plane11*!" ),
	FIELD( _field_real, "plane12*!" ),
	FIELD( _field_real, "plane13*!" ),
	FIELD( _field_real, "plane14*!" ),
	FIELD( _field_long_integer, "plane dimensions*!" ),
	FIELD( _field_long_integer, "child index 0*!" ),
	FIELD( _field_long_integer, "child index 1*!" ),
	FIELD( _field_long_integer, "child index 2*!" ),
	FIELD( _field_long_integer, "child index 3*!" ),
	FIELD( _field_long_integer, "child index 4*!" ),
	FIELD( _field_long_integer, "child index 5*!" ),
	FIELD( _field_long_integer, "child index 6*!" ),
	FIELD( _field_long_integer, "child index 7*!" ),
	FIELD( _field_long_integer, "child index 8*!" ),
	FIELD( _field_long_integer, "child index 9*!" ),
	FIELD( _field_long_integer, "child index10*!" ),
	FIELD( _field_long_integer, "child index11*!" ),
	FIELD( _field_long_integer, "child index12*!" ),
	FIELD( _field_long_integer, "child index13*!" ),
	FIELD( _field_long_integer, "child index14*!" ),
	FIELD( _field_long_integer, "child index15*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(planes_block, ((((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))>(((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))?(((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits))))):(((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))))
{
	FIELD( _field_real_plane_3d, "plane*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(leaves_block, ((false) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))), collision_leaf_struct_struct_definition );

TAG_BLOCK(bsp2d_references_block, ((false) ? 2147483647L>>2 : 196608))
{
	FIELD( _field_short_integer, "plane*" ),
	FIELD( _field_short_integer, "bsp2d node*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(bsp2d_nodes_block, ((false) ? 2147483647L>>2 : SHORT_MAX))
{
	FIELD( _field_real_plane_2d, "plane*" ),
	FIELD( _field_short_integer, "left child*" ),
	FIELD( _field_short_integer, "right child*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(surfaces_block, ((false) ? SHORT_MAX<<3 : SHORT_MAX))
{
	FIELD( _field_word_integer, "plane index*" ),
	FIELD( _field_word_integer, "first edge*" ),
	FIELD( _field_short_integer, "material*" ),
	FIELD( _field_short_integer, "breakable surface set*" ),
	FIELD( _field_short_integer, "breakable surface*" ),
	FIELD( _field_byte_flags, "flags*" ),
	FIELD( _field_byte_integer, "best plane calculation vertex index *!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(edges_block, ((false) ? 2621440 : UNSIGNED_SHORT_MAX))
{
	FIELD( _field_word_integer, "start vertex*" ),
	FIELD( _field_word_integer, "end vertex*" ),
	FIELD( _field_word_integer, "forward edge*" ),
	FIELD( _field_word_integer, "reverse edge*" ),
	FIELD( _field_word_integer, "left surface*" ),
	FIELD( _field_word_integer, "right surface*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vertices_block, ((false) ? 1310720 : 131072))
{
	FIELD( _field_real_point_3d, "point*" ),
	FIELD( _field_word_integer, "first edge*" ),
	FIELD( _field_short_integer, "sink*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_collision_bsp_block, 1)
{
	FIELD( _field_block, "bsp3d nodes*", &bsp3d_nodes_block_block ),
	FIELD( _field_block, "bsp3d supernodes*", &bsp3d_kd_supdernodes_block_block ),
	FIELD( _field_block, "planes*", &planes_block_block ),
	FIELD( _field_block, "leaves*", &leaves_block_block ),
	FIELD( _field_block, "bsp2d references*", &bsp2d_references_block_block ),
	FIELD( _field_block, "bsp2d nodes*", &bsp2d_nodes_block_block ),
	FIELD( _field_block, "surfaces*", &surfaces_block_block ),
	FIELD( _field_block, "edges*", &edges_block_block ),
	FIELD( _field_block, "vertices*", &vertices_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_large_collision_bsp_block, 1)
{
	FIELD( _field_block, "bsp3d nodes*", &large_bsp3d_nodes_block_block ),
	FIELD( _field_block, "bsp3d supernodes*", &bsp3d_kd_supdernodes_block_block ),
	FIELD( _field_block, "planes*", &planes_block_block ),
	FIELD( _field_block, "leaves*", &large_leaves_block_block ),
	FIELD( _field_block, "bsp2d references*", &large_bsp2d_references_block_block ),
	FIELD( _field_block, "bsp2d nodes*", &large_bsp2d_nodes_block_block ),
	FIELD( _field_block, "surfaces*", &large_surfaces_block_block ),
	FIELD( _field_block, "edges*", &large_edges_block_block ),
	FIELD( _field_block, "vertices*", &large_vertices_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(large_bsp3d_nodes_block, ((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_child_index_bits-1)))))
{
	FIELD( _field_long_integer, "plane*" ),
	FIELD( _field_long_integer, "back child*" ),
	FIELD( _field_long_integer, "front child*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(large_leaves_block, ((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))))
{
	FIELD( _field_word_flags, "flags*" ),
	FIELD( _field_short_integer, "bsp2d reference count*" ),
	FIELD( _field_long_integer, "first bsp2d reference*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(large_bsp2d_references_block, ((true) ? 2147483647L>>2 : 196608))
{
	FIELD( _field_long_integer, "plane*" ),
	FIELD( _field_long_integer, "bsp2d node*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(large_bsp2d_nodes_block, ((true) ? 2147483647L>>2 : SHORT_MAX))
{
	FIELD( _field_real_plane_2d, "plane*" ),
	FIELD( _field_long_integer, "left child*" ),
	FIELD( _field_long_integer, "right child*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(large_surfaces_block, ((true) ? SHORT_MAX<<3 : SHORT_MAX))
{
	FIELD( _field_long_integer, "plane index*" ),
	FIELD( _field_long_integer, "first edge*" ),
	FIELD( _field_short_integer, "material*" ),
	FIELD( _field_short_integer, "breakable surface set*" ),
	FIELD( _field_short_integer, "breakable surface*" ),
	FIELD( _field_byte_flags, "flags*" ),
	FIELD( _field_byte_integer, "best plane calculation vertex index *!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(large_edges_block, ((true) ? 2621440 : UNSIGNED_SHORT_MAX))
{
	FIELD( _field_long_integer, "start vertex*" ),
	FIELD( _field_long_integer, "end vertex*" ),
	FIELD( _field_long_integer, "forward edge*" ),
	FIELD( _field_long_integer, "reverse edge*" ),
	FIELD( _field_long_integer, "left surface*" ),
	FIELD( _field_long_integer, "right surface*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(large_vertices_block, ((true) ? 1310720 : 131072))
{
	FIELD( _field_real_point_3d, "point*" ),
	FIELD( _field_long_integer, "first edge*" ),
	FIELD( _field_long_integer, "sink*!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(collision_leaf_struct)
{
	FIELD( _field_byte_flags, "flags*" ),
	FIELD( _field_pad, "pad", 1 ),
	FIELD( _field_word_integer, "bsp2d reference count*" ),
	FIELD( _field_dword_integer, "first bsp2d reference*" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_collision_bsp_struct)
{
	FIELD( _field_block, "bsp3d nodes*", &bsp3d_nodes_block_block ),
	FIELD( _field_block, "bsp3d supernodes*", &bsp3d_kd_supdernodes_block_block ),
	FIELD( _field_block, "planes*", &planes_block_block ),
	FIELD( _field_block, "leaves*", &leaves_block_block ),
	FIELD( _field_block, "bsp2d references*", &bsp2d_references_block_block ),
	FIELD( _field_block, "bsp2d nodes*", &bsp2d_nodes_block_block ),
	FIELD( _field_block, "surfaces*", &surfaces_block_block ),
	FIELD( _field_block, "edges*", &edges_block_block ),
	FIELD( _field_block, "vertices*", &vertices_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

