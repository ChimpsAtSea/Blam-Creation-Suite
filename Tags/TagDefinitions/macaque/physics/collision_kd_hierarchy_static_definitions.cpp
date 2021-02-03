#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define COLLISION_KD_HIERARCHY_STATIC_HASH_TABLE_DATA_BLOCK_ID { 0x1C33AABC, 0x1A234449, 0x3EAB1083, 0xA9170D8A }
	TAG_BLOCK(
		collision_kd_hierarchy_static_hash_table_data_block,
		"collision_kd_hierarchy_static_hash_table_data_block",
		k_short_max,
		"int32",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_KD_HIERARCHY_STATIC_HASH_TABLE_DATA_BLOCK_ID)
	{
		{ _field_long_integer, "node index" },
		{ _field_long_integer, "key a" },
		{ _field_long_integer, "key b" },
		{ _field_long_integer, "key c" },
		{ _field_terminator }
	};

	#define COLLISION_KD_HIERARCHY_STATIC_HASH_TABLE_SHORT_BLOCK_ID { 0x1C33AABC, 0xCA234449, 0x3EAB10C3, 0xA917098A }
	TAG_BLOCK(
		collision_kd_hierarchy_static_hash_table_short_block,
		"collision_kd_hierarchy_static_hash_table_short_block",
		k_short_max,
		"int16",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_KD_HIERARCHY_STATIC_HASH_TABLE_SHORT_BLOCK_ID)
	{
		{ _field_short_integer, "index" },
		{ _field_terminator }
	};

	#define COLLISION_KD_HIERARCHY_STATIC_NODES_BLOCK_ID { 0x1C33AABC, 0x9A234449, 0x0EAB1083, 0xA9173D8A }
	TAG_BLOCK(
		collision_kd_hierarchy_static_nodes_block,
		"collision_kd_hierarchy_static_nodes_block",
		k_short_max,
		"s_collision_kd_hierarchy_static_node",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_KD_HIERARCHY_STATIC_NODES_BLOCK_ID)
	{
		{ _field_block, "render only headers", &collision_kd_hierarchy_static_hash_table_headers_block },
		{ _field_block, "collidable headers", &collision_kd_hierarchy_static_hash_table_headers_block },
		{ _field_short_block_index, "child below", &collision_kd_hierarchy_static_nodes_block },
		{ _field_short_block_index, "child above", &collision_kd_hierarchy_static_nodes_block },
		{ _field_short_block_index, "parent", &collision_kd_hierarchy_static_nodes_block },
		{ _field_short_integer, "cluster index" },
		{ _field_terminator }
	};

	#define COLLISION_KD_HIERARCHY_STATIC_HASH_TABLE_HEADERS_BLOCK_ID { 0x1C33AABC, 0x7A234449, 0x0EABD083, 0xD9173D8A }
	TAG_BLOCK(
		collision_kd_hierarchy_static_hash_table_headers_block,
		"collision_kd_hierarchy_static_hash_table_headers_block",
		k_short_max,
		"s_collision_kd_hierarchy_static_header",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_KD_HIERARCHY_STATIC_HASH_TABLE_HEADERS_BLOCK_ID)
	{
		{ _field_word_flags, "cull flags", &collision_kd_hierarchy_static_hash_table_cull_flags },
		{ _field_short_integer, "instance index" },
		{ _field_long_integer, "instance index dword mask" },
		{ _field_short_integer, "bsp index" },
		FIELD_PAD("bsp-index-pad", nullptr, 2),
		{ _field_long_integer, "bsp mask" },
		{ _field_terminator }
	};

	#define COLLISION_KD_HIERARCHY_STATIC_IN_USE_MASKS_BLOCK_ID { 0x0C33AABC, 0x3A234449, 0x1EAB1083, 0xA9870D8A }
	TAG_BLOCK(
		collision_kd_hierarchy_static_in_use_masks_block,
		"collision_kd_hierarchy_static_in_use_masks_block",
		(k_bsp3d_maximum_super_node_count),
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_KD_HIERARCHY_STATIC_IN_USE_MASKS_BLOCK_ID)
	{
		{ _field_long_integer, "mask" },
		{ _field_terminator }
	};

	#define CLUSTER_TABLE_BLOCK_ID { 0x1CABDABC, 0x1A23C449, 0xAEABD083, 0x19A70D8A }
	TAG_BLOCK(
		cluster_table_block,
		"cluster_table_block",
		k_short_max,
		"s_cluster_table",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CLUSTER_TABLE_BLOCK_ID)
	{
		{ _field_block, "super node mappings", &super_node_mappings_block$3_block },
		{ _field_terminator }
	};

	#define SUPER_NODE_MAPPINGS_BLOCK_ID { 0xACC3DABC, 0xBA2F4449, 0xCEAB10B3, 0x49A70C8A }
	TAG_BLOCK(
		super_node_mappings_block$3_block,
		"super_node_mappings_block",
		k_short_max,
		"s_super_node_mapping",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUPER_NODE_MAPPINGS_BLOCK_ID)
	{
		{ _field_array, "indices", &super_node_mapping_index_array },
		FIELD_PAD("pad", nullptr, 2),
		{ _field_terminator }
	};

	#define SUPER_NODE_MAPPING_INDEX_ARRAY_ID { 0xD98D671C, 0xB7E64985, 0x3D63EF05, 0xFAEAE84E }
	TAG_ARRAY(
		super_node_mapping_index_array,
		"super_node_mapping_index_array",
		k_super_node_node_count+k_super_node_child_indices_count,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SUPER_NODE_MAPPING_INDEX_ARRAY_ID)
	{
		{ _field_short_block_index, "index", &collision_kd_hierarchy_static_nodes_block },
		{ _field_terminator }
	};

	#define COLLISION_KD_HIERARCHY_STATIC_STRUCT_ID { 0x9AC5DB45, 0x1F934BF3, 0x902C2890, 0x4C76F360 }
	TAG_STRUCT(
		collision_kd_hierarchy_static_struct,
		"collision_kd_hierarchy_static_struct",
		"s_collision_kd_hierarchy_static",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLLISION_KD_HIERARCHY_STATIC_STRUCT_ID)
	{
		{ _field_long_integer, "hash total_count" },
		{ _field_block, "hash data", &collision_kd_hierarchy_static_hash_table_data_block },
		{ _field_block, "hash entry count", &collision_kd_hierarchy_static_hash_table_short_block },
		{ _field_block, "original hash entry count", &collision_kd_hierarchy_static_hash_table_short_block },
		{ _field_block, "nodes", &collision_kd_hierarchy_static_nodes_block },
		{ _field_block, "in use masks", &collision_kd_hierarchy_static_in_use_masks_block },
		{ _field_block, "cluster table", &cluster_table_block },
		{ _field_terminator }
	};

	STRINGS(collision_kd_hierarchy_static_hash_table_cull_flags)
	{
		"render only",
		"does not block aoe",
		"non pathfindable"
	};
	STRING_LIST(collision_kd_hierarchy_static_hash_table_cull_flags, collision_kd_hierarchy_static_hash_table_cull_flags_strings, _countof(collision_kd_hierarchy_static_hash_table_cull_flags_strings));

} // namespace macaque

} // namespace blofeld

