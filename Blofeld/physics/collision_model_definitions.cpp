#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(collision_model_material, MAXIMUM_MATERIALS_PER_MODEL)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_model_region, MAXIMUM_REGIONS_PER_MODEL)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_block, "permutations*", &collision_model_permutation_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_model_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_short_integer, "resourceBspOffset*!" ),
	FIELD( _field_short_integer, "resourceBspCount*!" ),
	FIELD( _field_block, "bsps*", &collision_model_bsp_block ),
	FIELD( _field_block, "bsp_physics*", &collision_bsp_physics_block ),
	FIELD( _field_block, "mopp_codes*", &mopp_code_definition_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_model_bsp, MAXIMUM_BSPS_PER_COLLISION_REGION)
{
	FIELD( _field_short_integer, "node index*" ),
	FIELD( _field_pad, "KXGCEIEI", 2 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_struct, "bsp*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_model_pathfinding_sphere, MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL)
{
	FIELD( _field_short_block_index, "node*" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_real_point_3d, "center*" ),
	FIELD( _field_real, "radius*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(collision_model_node, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_pad, "PFPPD", 2 ),
	FIELD( _field_short_block_index, "parent node*" ),
	FIELD( _field_short_block_index, "next sibling node*" ),
	FIELD( _field_short_block_index, "first child node*" ),
	FIELD( _field_terminator )
};

TAG_GROUP(collision_model, COLLISION_MODEL_TAG)
{
	FIELD( _field_long_integer, "import_info_checksum*!" ),
	FIELD( _field_block, "errors*", &global_error_report_categories_block ),
	FIELD( _field_long_flags, "flags*" ),
	FIELD( _field_block, "materials*", &collision_model_material_block ),
	FIELD( _field_block, "regions*", &collision_model_region_block ),
	FIELD( _field_block, "cookie cutters*", &collision_model_region_block ),
	FIELD( _field_block, "pathfinding spheres*", &collision_model_pathfinding_sphere_block ),
	FIELD( _field_block, "nodes*", &collision_model_node_block ),
	FIELD( _field_pageable, "regions resource" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

