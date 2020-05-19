#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(map_leaf_face_vertex_block, MAXIMUM_VERTICES_PER_LEAF_CONNECTION)
	{
		{ _field_real_point_3d, "vertex*" },
		{ _field_terminator }
	};

	TAG_BLOCK(map_leaf_face_block, MAXIMUM_FACES_PER_MAP_LEAF)
	{
		{ _field_long_integer, "node index*" },
		{ _field_block, "vertices*", &map_leaf_face_vertex_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(map_leaf_connection_index_block, MAXIMUM_CONNECTIONS_PER_MAP_LEAF)
	{
		{ _field_long_integer, "connection index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_map_leaf_block, ((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))))
	{
		{ _field_block, "faces*", &map_leaf_face_block_block },
		{ _field_block, "connection indices*", &map_leaf_connection_index_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(leaf_connection_vertex_block, MAXIMUM_VERTICES_PER_LEAF_CONNECTION)
	{
		{ _field_real_point_3d, "vertex*" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_leaf_connection_block, MAXIMUM_CONNECTIONS_PER_LEAF_MAP)
	{
		{ _field_long_integer, "plane index*" },
		{ _field_long_integer, "back leaf index*" },
		{ _field_long_integer, "front leaf index*" },
		{ _field_block, "vertices*", &leaf_connection_vertex_block_block },
		{ _field_real, "area*" },
		{ _field_terminator }
	};

} // namespace blofeld

