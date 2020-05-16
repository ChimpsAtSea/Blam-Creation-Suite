#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_map_leaf_block, ((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))))
{
	FIELD( _field_block, "faces*", &map_leaf_face_block ),
	FIELD( _field_block, "connection indices*", &map_leaf_connection_index_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(map_leaf_face_block, MAXIMUM_FACES_PER_MAP_LEAF)
{
	FIELD( _field_long_integer, "node index*" ),
	FIELD( _field_block, "vertices*", &map_leaf_face_vertex_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(map_leaf_face_vertex_block, MAXIMUM_VERTICES_PER_LEAF_CONNECTION)
{
	FIELD( _field_real_point_3d, "vertex*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(map_leaf_connection_index_block, MAXIMUM_CONNECTIONS_PER_MAP_LEAF)
{
	FIELD( _field_long_integer, "connection index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_leaf_connection_block, MAXIMUM_CONNECTIONS_PER_LEAF_MAP)
{
	FIELD( _field_long_integer, "plane index*" ),
	FIELD( _field_long_integer, "back leaf index*" ),
	FIELD( _field_long_integer, "front leaf index*" ),
	FIELD( _field_block, "vertices*", &leaf_connection_vertex_block ),
	FIELD( _field_real, "area*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(leaf_connection_vertex_block, MAXIMUM_VERTICES_PER_LEAF_CONNECTION)
{
	FIELD( _field_real_point_3d, "vertex*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

