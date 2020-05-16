#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(collision_kd_hierarchy_static_struct)
{
	FIELD( _field_long_integer, "hash total_count!" ),
	FIELD( _field_block, "hash data", &collision_kd_hierarchy_static_hash_table_data_block ),
	FIELD( _field_block, "hash entry count", &collision_kd_hierarchy_static_hash_table_short_block ),
	FIELD( _field_block, "original hash entry count", &collision_kd_hierarchy_static_hash_table_short_block ),
	FIELD( _field_block, "nodes", &collision_kd_hierarchy_static_nodes_block ),
	FIELD( _field_block, "in use masks", &collision_kd_hierarchy_static_in_use_masks_block ),
	FIELD( _field_block, "cluster table", &cluster_table_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_kd_hierarchy_static_hash_table_data_block, k_short_max)
{
	FIELD( _field_long_integer, "node index!" ),
	FIELD( _field_long_integer, "key a!" ),
	FIELD( _field_long_integer, "key b!" ),
	FIELD( _field_long_integer, "key c!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_kd_hierarchy_static_hash_table_short_block, k_short_max)
{
	FIELD( _field_short_integer, "index!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_kd_hierarchy_static_nodes_block, k_short_max)
{
	FIELD( _field_block, "render only headers!", &collision_kd_hierarchy_static_hash_table_headers_block ),
	FIELD( _field_block, "collidable headers!", &collision_kd_hierarchy_static_hash_table_headers_block ),
	FIELD( _field_short_block_index, "child below!" ),
	FIELD( _field_short_block_index, "child above!" ),
	FIELD( _field_short_block_index, "parent!" ),
	FIELD( _field_short_integer, "cluster index!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_kd_hierarchy_static_hash_table_headers_block, k_short_max)
{
	FIELD( _field_word_flags, "cull flags!" ),
	FIELD( _field_short_integer, "instance index!" ),
	FIELD( _field_long_integer, "instance index dword mask!" ),
	FIELD( _field_short_integer, "bsp index!" ),
	FIELD( _field_pad, "bsp-index-pad", 2 ),
	FIELD( _field_long_integer, "bsp mask!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_kd_hierarchy_static_in_use_masks_block, (k_bsp3d_maximum_super_node_count))
{
	FIELD( _field_long_integer, "mask!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cluster_table_block, k_short_max)
{
	FIELD( _field_block, "super node mappings", &super_node_mappings_block$3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(super_node_mappings_block$3, k_short_max)
{
	FIELD( _field_array, "indices!" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

