#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(collision_kd_hierarchy_static_hash_table_data_block, k_short_max)
	{
		{ _field_long_integer, "node index!" },
		{ _field_long_integer, "key a!" },
		{ _field_long_integer, "key b!" },
		{ _field_long_integer, "key c!" },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_kd_hierarchy_static_hash_table_short_block, k_short_max)
	{
		{ _field_short_integer, "index!" },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_kd_hierarchy_static_hash_table_headers_block, k_short_max)
	{
		{ _field_word_flags, "cull flags!", &collision_kd_hierarchy_static_hash_table_cull_flags },
		{ _field_short_integer, "instance index!" },
		{ _field_long_integer, "instance index dword mask!" },
		{ _field_short_integer, "bsp index!" },
		{ _field_pad, "bsp-index-pad", 2 },
		{ _field_long_integer, "bsp mask!" },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_kd_hierarchy_static_nodes_block, k_short_max)
	{
		{ _field_block, "render only headers!", &collision_kd_hierarchy_static_hash_table_headers_block_block },
		{ _field_block, "collidable headers!", &collision_kd_hierarchy_static_hash_table_headers_block_block },
		{ _field_short_block_index, "child below!" },
		{ _field_short_block_index, "child above!" },
		{ _field_short_block_index, "parent!" },
		{ _field_short_integer, "cluster index!" },
		{ _field_terminator }
	};

	TAG_BLOCK(collision_kd_hierarchy_static_in_use_masks_block, (k_bsp3d_maximum_super_node_count))
	{
		{ _field_long_integer, "mask!" },
		{ _field_terminator }
	};

	TAG_BLOCK(super_node_mappings_block$3, k_short_max)
	{
		{ _field_array, "indices!", &super_node_mapping_index_array_array },
		{ _field_pad, "pad", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(cluster_table_block, k_short_max)
	{
		{ _field_block, "super node mappings", &super_node_mappings_block$3_block },
		{ _field_terminator }
	};

	TAG_ARRAY(super_node_mapping_index_array, k_super_node_node_count+k_super_node_child_indices_count)
	{
		{ _field_short_block_index, "index!" },
		{ _field_terminator }
	};

	TAG_STRUCT(collision_kd_hierarchy_static_struct)
	{
		{ _field_long_integer, "hash total_count!" },
		{ _field_block, "hash data", &collision_kd_hierarchy_static_hash_table_data_block_block },
		{ _field_block, "hash entry count", &collision_kd_hierarchy_static_hash_table_short_block_block },
		{ _field_block, "original hash entry count", &collision_kd_hierarchy_static_hash_table_short_block_block },
		{ _field_block, "nodes", &collision_kd_hierarchy_static_nodes_block_block },
		{ _field_block, "in use masks", &collision_kd_hierarchy_static_in_use_masks_block_block },
		{ _field_block, "cluster table", &cluster_table_block_block },
		{ _field_terminator }
	};

	STRINGS(collision_kd_hierarchy_static_hash_table_cull_flags)
	{
		"render only",
		"does not block aoe",
		"non pathfindable"
	};
	STRING_LIST(collision_kd_hierarchy_static_hash_table_cull_flags, collision_kd_hierarchy_static_hash_table_cull_flags_strings, _countof(collision_kd_hierarchy_static_hash_table_cull_flags_strings));

} // namespace blofeld

