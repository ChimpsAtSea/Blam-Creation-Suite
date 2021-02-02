#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_MAP_LEAF_BLOCK_ID { 0x7963BAF0, 0x35ED4A23, 0x91FEC7CC, 0xC9477083 }
	TAG_BLOCK(
		global_map_leaf_block,
		"global_map_leaf_block",
		((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))),
		"map_leaf",
		GLOBAL_MAP_LEAF_BLOCK_ID)
	{
		{ _field_block, "faces", &map_leaf_face_block },
		{ _field_block, "connection indices", &map_leaf_connection_index_block },
		{ _field_terminator }
	};

	#define MAP_LEAF_FACE_BLOCK_ID { 0x76C78229, 0x504B49E6, 0xAE70E1D0, 0x63A16B1E }
	TAG_BLOCK(
		map_leaf_face_block,
		"map_leaf_face_block",
		MAXIMUM_FACES_PER_MAP_LEAF,
		"map_leaf_face",
		MAP_LEAF_FACE_BLOCK_ID)
	{
		{ _field_long_integer, "node index" },
		{ _field_block, "vertices", &map_leaf_face_vertex_block },
		{ _field_terminator }
	};

	#define MAP_LEAF_FACE_VERTEX_BLOCK_ID { 0xF918DB0A, 0x67E04ADB, 0x9440FD77, 0x21A4734D }
	TAG_BLOCK(
		map_leaf_face_vertex_block,
		"map_leaf_face_vertex_block",
		MAXIMUM_VERTICES_PER_LEAF_CONNECTION,
		"real_point3d",
		MAP_LEAF_FACE_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "vertex" },
		{ _field_terminator }
	};

	#define MAP_LEAF_CONNECTION_INDEX_BLOCK_ID { 0xDE3F27ED, 0x242A469D, 0xAF139C96, 0xFB3C81EA }
	TAG_BLOCK(
		map_leaf_connection_index_block,
		"map_leaf_connection_index_block",
		MAXIMUM_CONNECTIONS_PER_MAP_LEAF,
		"long",
		MAP_LEAF_CONNECTION_INDEX_BLOCK_ID)
	{
		{ _field_long_integer, "connection index" },
		{ _field_terminator }
	};

	#define GLOBAL_LEAF_CONNECTION_BLOCK_ID { 0x7FE10580, 0x88974F2E, 0x810AB1B9, 0xD47E3481 }
	TAG_BLOCK(
		global_leaf_connection_block,
		"global_leaf_connection_block",
		MAXIMUM_CONNECTIONS_PER_LEAF_MAP,
		"leaf_connection",
		GLOBAL_LEAF_CONNECTION_BLOCK_ID)
	{
		{ _field_long_integer, "plane index" },
		{ _field_long_integer, "back leaf index" },
		{ _field_long_integer, "front leaf index" },
		{ _field_block, "vertices", &leaf_connection_vertex_block },
		{ _field_real, "area" },
		{ _field_terminator }
	};

	#define LEAF_CONNECTION_VERTEX_BLOCK_ID { 0x421E487D, 0x11484CA1, 0x853701FC, 0x69284A5C }
	TAG_BLOCK(
		leaf_connection_vertex_block,
		"leaf_connection_vertex_block",
		MAXIMUM_VERTICES_PER_LEAF_CONNECTION,
		"real_point3d",
		LEAF_CONNECTION_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "vertex" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

