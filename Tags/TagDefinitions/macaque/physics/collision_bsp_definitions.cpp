#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define BSP3D_NODES_BLOCK_STRUCT_ID { 0xB5D8FC21, 0xFF8E48E7, 0x92611F52, 0x3E7371A3 }
	TAG_BLOCK(
		bsp3d_nodes_block,
		"bsp3d_nodes_block",
		((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_child_index_bits-1)))),
		"bsp3d_node",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP3D_NODES_BLOCK_STRUCT_ID,
		3)
	{
		{ _field_int64_integer, "node data designator" },
		{ _field_terminator }
	};

	#define BSP3D_KD_SUPDERNODES_BLOCK_ID { 0xABCDC201, 0x10124FA9, 0xA7400AB4, 0xE01AB4BC }
	TAG_BLOCK(
		bsp3d_kd_supdernodes_block,
		"bsp3d_kd_supdernodes_block",
		(k_bsp3d_maximum_super_node_count),
		"s_bsp3d_kd_super_node",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP3D_KD_SUPDERNODES_BLOCK_ID,
		7)
	{
		{ _field_real, "plane 0" },
		{ _field_real, "plane 1" },
		{ _field_real, "plane 2" },
		{ _field_real, "plane 3" },
		{ _field_real, "plane 4" },
		{ _field_real, "plane 5" },
		{ _field_real, "plane 6" },
		{ _field_real, "plane 7" },
		{ _field_real, "plane 8" },
		{ _field_real, "plane 9" },
		{ _field_real, "plane10" },
		{ _field_real, "plane11" },
		{ _field_real, "plane12" },
		{ _field_real, "plane13" },
		{ _field_real, "plane14" },
		{ _field_long_integer, "plane dimensions" },
		{ _field_long_integer, "child index 0" },
		{ _field_long_integer, "child index 1" },
		{ _field_long_integer, "child index 2" },
		{ _field_long_integer, "child index 3" },
		{ _field_long_integer, "child index 4" },
		{ _field_long_integer, "child index 5" },
		{ _field_long_integer, "child index 6" },
		{ _field_long_integer, "child index 7" },
		{ _field_long_integer, "child index 8" },
		{ _field_long_integer, "child index 9" },
		{ _field_long_integer, "child index10" },
		{ _field_long_integer, "child index11" },
		{ _field_long_integer, "child index12" },
		{ _field_long_integer, "child index13" },
		{ _field_long_integer, "child index14" },
		{ _field_long_integer, "child index15" },
		{ _field_terminator }
	};

	#define PLANES_BLOCK_ID { 0x5D188A8D, 0x719C4E0D, 0x8015A6DA, 0x22E342EB }
	TAG_BLOCK(
		planes_block,
		"planes_block",
		((((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))>(((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))?(((false) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits))))):(((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_plane_index_bits)))))),
		"real_plane3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLANES_BLOCK_ID,
		4)
	{
		{ _field_real_plane_3d, "plane" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		leaves_block,
		"leaves_block",
		((false) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))),
		collision_leaf_struct);

	#define BSP2D_REFERENCES_BLOCK_ID { 0x591E809E, 0x8C38445F, 0xB889DE6F, 0x3B5474FF }
	TAG_BLOCK(
		bsp2d_references_block,
		"bsp2d_references_block",
		((false) ? 2147483647L>>2 : 196608),
		"bsp2d_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP2D_REFERENCES_BLOCK_ID,
		2)
	{
		{ _field_short_integer, "plane" },
		{ _field_short_integer, "bsp2d node" },
		{ _field_terminator }
	};

	#define BSP2D_NODES_BLOCK_ID { 0x6CD60C8C, 0xC73B4124, 0xB339408C, 0x966AD3BE }
	TAG_BLOCK(
		bsp2d_nodes_block,
		"bsp2d_nodes_block",
		((false) ? 2147483647L>>2 : SHORT_MAX),
		"bsp2d_node",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BSP2D_NODES_BLOCK_ID,
		4)
	{
		{ _field_real_plane_2d, "plane" },
		{ _field_short_integer, "left child" },
		{ _field_short_integer, "right child" },
		{ _field_terminator }
	};

	#define SURFACES_BLOCK_STRUCT_ID { 0x7AB81935, 0x010A4B88, 0xAB12DE80, 0x85CD9139 }
	TAG_BLOCK(
		surfaces_block,
		"surfaces_block",
		((false) ? SHORT_MAX<<3 : SHORT_MAX),
		"collision_surface",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SURFACES_BLOCK_STRUCT_ID)
	{
		{ _field_word_integer, "plane index" },
		{ _field_word_integer, "first edge" },
		{ _field_short_integer, "material" },
		{ _field_short_integer, "breakable surface set" },
		{ _field_short_integer, "breakable surface" },
		{ _field_byte_flags, "flags", &surface_flags },
		{ _field_byte_integer, "best plane calculation vertex index " },
		{ _field_terminator }
	};

	#define EDGES_BLOCK_ID { 0xB51DA635, 0xEC534400, 0x81B58C33, 0xD1DCCAFD }
	TAG_BLOCK(
		edges_block,
		"edges_block",
		((false) ? 2621440 : UNSIGNED_SHORT_MAX),
		"collision_edge",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EDGES_BLOCK_ID)
	{
		{ _field_word_integer, "start vertex" },
		{ _field_word_integer, "end vertex" },
		{ _field_word_integer, "forward edge" },
		{ _field_word_integer, "reverse edge" },
		{ _field_word_integer, "left surface" },
		{ _field_word_integer, "right surface" },
		{ _field_terminator }
	};

	#define VERTICES_BLOCK_ID { 0x6C3F6A60, 0x1FCE4C6A, 0x8F89E265, 0xE56D2F60 }
	TAG_BLOCK(
		vertices_block,
		"vertices_block",
		((false) ? 1310720 : 131072),
		"collision_vertex",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VERTICES_BLOCK_ID,
		4)
	{
		{ _field_real_point_3d, "point" },
		{ _field_word_integer, "first edge" },
		{ _field_short_integer, "sink" },
		{ _field_terminator }
	};

	#define GLOBAL_COLLISION_BSP_BLOCK_ID { 0xE15E4F1B, 0x1F17442D, 0x8730F6BB, 0xC0E02045 }
	TAG_BLOCK(
		global_collision_bsp_block,
		"global_collision_bsp_block",
		1,
		"collision_bsp",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_COLLISION_BSP_BLOCK_ID)
	{
		{ _field_block, "bsp3d nodes", &bsp3d_nodes_block },
		{ _field_block, "bsp3d supernodes", &bsp3d_kd_supdernodes_block },
		{ _field_block, "planes", &planes_block },
		{ _field_block, "leaves", &leaves_block },
		{ _field_block, "bsp2d references", &bsp2d_references_block },
		{ _field_block, "bsp2d nodes", &bsp2d_nodes_block },
		{ _field_block, "surfaces", &surfaces_block },
		{ _field_block, "edges", &edges_block },
		{ _field_block, "vertices", &vertices_block },
		{ _field_terminator }
	};

	#define GLOBAL_LARGE_COLLISION_BSP_BLOCK_ID { 0xE15AAF1B, 0xBF17422D, 0xB730F6DB, 0xCDE02043 }
	TAG_BLOCK(
		global_large_collision_bsp_block,
		"global_large_collision_bsp_block",
		1,
		"large_collision_bsp",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_LARGE_COLLISION_BSP_BLOCK_ID)
	{
		{ _field_block, "bsp3d nodes", &large_bsp3d_nodes_block },
		{ _field_block, "bsp3d supernodes", &bsp3d_kd_supdernodes_block },
		{ _field_block, "planes", &planes_block },
		{ _field_block, "leaves", &large_leaves_block },
		{ _field_block, "bsp2d references", &large_bsp2d_references_block },
		{ _field_block, "bsp2d nodes", &large_bsp2d_nodes_block },
		{ _field_block, "surfaces", &large_surfaces_block },
		{ _field_block, "edges", &large_edges_block },
		{ _field_block, "vertices", &large_vertices_block },
		{ _field_terminator }
	};

	#define LARGE_BSP3D_NODES_BLOCK_ID { 0xB16070E2, 0x373C48DD, 0xBC536E38, 0xA979E2E0 }
	TAG_BLOCK(
		large_bsp3d_nodes_block,
		"bsp3d node",
		((true) ? 2147483647L>>2 : ((1<<(k_bsp3d_node_child_index_bits-1)))),
		"large_bsp3d_node",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LARGE_BSP3D_NODES_BLOCK_ID)
	{
		{ _field_long_integer, "plane" },
		{ _field_long_integer, "back child" },
		{ _field_long_integer, "front child" },
		{ _field_terminator }
	};

	#define LARGE_LEAVES_BLOCK_ID { 0x6FACAFAA, 0x8B1C4C58, 0x913373AA, 0x7C8A9E94 }
	TAG_BLOCK(
		large_leaves_block,
		"leaf",
		((true) ? 16*((1<<(k_bsp3d_node_child_index_bits-1))) : ((1<<(k_bsp3d_node_child_index_bits-1)))),
		"large_collision_leaf",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LARGE_LEAVES_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &leaf_flags },
		{ _field_short_integer, "bsp2d reference count" },
		{ _field_long_integer, "first bsp2d reference" },
		{ _field_terminator }
	};

	#define LARGE_BSP2D_REFERENCES_BLOCK_ID { 0x7E600865, 0x481349EE, 0xAA595566, 0x4FD9C2BB }
	TAG_BLOCK(
		large_bsp2d_references_block,
		"bsp2d reference",
		((true) ? 2147483647L>>2 : 196608),
		"large_bsp2d_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LARGE_BSP2D_REFERENCES_BLOCK_ID)
	{
		{ _field_long_integer, "plane" },
		{ _field_long_integer, "bsp2d node" },
		{ _field_terminator }
	};

	#define LARGE_BSP2D_NODES_BLOCK_ID { 0xC17973C7, 0x16C14EE5, 0xA40FA277, 0x212D8050 }
	TAG_BLOCK(
		large_bsp2d_nodes_block,
		"bsp2d node",
		((true) ? 2147483647L>>2 : SHORT_MAX),
		"large_bsp2d_node",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LARGE_BSP2D_NODES_BLOCK_ID)
	{
		{ _field_real_plane_2d, "plane" },
		{ _field_long_integer, "left child" },
		{ _field_long_integer, "right child" },
		{ _field_terminator }
	};

	#define LARGE_SURFACES_BLOCK_STRUCT_ID { 0xABF80B98, 0x00164C5B, 0xBACE563D, 0x04A14589 }
	TAG_BLOCK(
		large_surfaces_block,
		"large_surfaces_block",
		((true) ? SHORT_MAX<<3 : SHORT_MAX),
		"large_collision_surface",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LARGE_SURFACES_BLOCK_STRUCT_ID)
	{
		{ _field_long_integer, "plane index" },
		{ _field_long_integer, "first edge" },
		{ _field_short_integer, "material" },
		{ _field_short_integer, "breakable surface set" },
		{ _field_short_integer, "breakable surface" },
		{ _field_byte_flags, "flags", &surface_flags },
		{ _field_byte_integer, "best plane calculation vertex index " },
		{ _field_terminator }
	};

	#define LARGE_EDGES_BLOCK_ID { 0x76B24BE8, 0xE1574464, 0xB7C09C61, 0x948F3471 }
	TAG_BLOCK(
		large_edges_block,
		"edge",
		((true) ? 2621440 : UNSIGNED_SHORT_MAX),
		"large_collision_edge",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LARGE_EDGES_BLOCK_ID)
	{
		{ _field_long_integer, "start vertex" },
		{ _field_long_integer, "end vertex" },
		{ _field_long_integer, "forward edge" },
		{ _field_long_integer, "reverse edge" },
		{ _field_long_integer, "left surface" },
		{ _field_long_integer, "right surface" },
		{ _field_terminator }
	};

	#define LARGE_VERTICES_BLOCK_ID { 0x0459797B, 0xF03B4186, 0xAA638C78, 0xD41B79DD }
	TAG_BLOCK(
		large_vertices_block,
		"vertex",
		((true) ? 1310720 : 131072),
		"large_collision_vertex",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LARGE_VERTICES_BLOCK_ID)
	{
		{ _field_real_point_3d, "point" },
		{ _field_long_integer, "first edge" },
		{ _field_long_integer, "sink" },
		{ _field_terminator }
	};

	#define GLOBAL_COLLISION_BSP_STRUCT_ID { 0x130D16E9, 0xA4684A1E, 0xA91958AD, 0x3BDAA7EC }
	TAG_STRUCT(
		global_collision_bsp_struct,
		"global_collision_bsp_struct",
		"collision_bsp",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_COLLISION_BSP_STRUCT_ID)
	{
		{ _field_block, "bsp3d nodes", &bsp3d_nodes_block },
		{ _field_block, "bsp3d supernodes", &bsp3d_kd_supdernodes_block },
		{ _field_block, "planes", &planes_block },
		{ _field_block, "leaves", &leaves_block },
		{ _field_block, "bsp2d references", &bsp2d_references_block },
		{ _field_block, "bsp2d nodes", &bsp2d_nodes_block },
		{ _field_block, "surfaces", &surfaces_block },
		{ _field_block, "edges", &edges_block },
		{ _field_block, "vertices", &vertices_block },
		{ _field_terminator }
	};

	#define COLLISION_LEAF_STRUCT_ID { 0xA5FD8EE3, 0x9A644ECC, 0x9CEBF2FB, 0x45030CA1 }
	TAG_STRUCT(
		collision_leaf_struct,
		"collision_leaf_struct",
		"collision_leaf",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_LEAF_STRUCT_ID,
		2)
	{
		{ _field_byte_flags, "flags", &leaf_flags },
		FIELD_PAD("pad", nullptr, 1),
		{ _field_word_integer, "bsp2d reference count" },
		{ _field_dword_integer, "first bsp2d reference" },
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

} // namespace macaque

} // namespace blofeld

