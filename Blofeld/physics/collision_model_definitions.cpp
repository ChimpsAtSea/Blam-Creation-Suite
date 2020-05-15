#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(collision_model_material, MAXIMUM_MATERIALS_PER_MODEL)
{
	{ _field_string_id, "name^*" },
	{ _field_terminator },
};

TAG_BLOCK(collision_model_region, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_string_id, "name^*" },
	{ _field_block, "permutations*", &collision_model_permutation_block },
	{ _field_terminator },
};

TAG_BLOCK(collision_model_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	{ _field_string_id, "name^*" },
	{ _field_short_integer, "resourceBspOffset*!" },
	{ _field_short_integer, "resourceBspCount*!" },
	{ _field_block, "bsps*", &collision_model_bsp_block },
	{ _field_block, "bsp_physics*", &collision_bsp_physics_block },
	{ _field_block, "mopp_codes*", &mopp_code_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(collision_model_bsp, MAXIMUM_BSPS_PER_COLLISION_REGION)
{
	{ _field_short_integer, "node index*" },
	{ _field_pad, "KXGCEIEI", 2 },
	{ _field_useless_pad },
	{ _field_struct, "bsp*" },
	{ _field_terminator },
};

TAG_BLOCK(collision_model_pathfinding_sphere, MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL)
{
	{ _field_short_block_index, "node*" },
	{ _field_word_flags, "flags" },
	{ _field_useless_pad },
	{ _field_real_point_3d, "center*" },
	{ _field_real, "radius*" },
	{ _field_terminator },
};

TAG_BLOCK(collision_model_node, MAXIMUM_NODES_PER_MODEL)
{
	{ _field_string_id, "name^*" },
	{ _field_pad, "PFPPD", 2 },
	{ _field_short_block_index, "parent node*" },
	{ _field_short_block_index, "next sibling node*" },
	{ _field_short_block_index, "first child node*" },
	{ _field_terminator },
};

TAG_GROUP(collision_model, COLLISION_MODEL_TAG)
{
	{ _field_long_integer, "import_info_checksum*!" },
	{ _field_block, "errors*", &global_error_report_categories_block },
	{ _field_long_flags, "flags*" },
	{ _field_block, "materials*", &collision_model_material_block },
	{ _field_block, "regions*", &collision_model_region_block },
	{ _field_block, "cookie cutters*", &collision_model_region_block },
	{ _field_block, "pathfinding spheres*", &collision_model_pathfinding_sphere_block },
	{ _field_block, "nodes*", &collision_model_node_block },
	{ _field_pageable, "regions resource" },
	{ _field_terminator },
};

} // namespace blofeld

