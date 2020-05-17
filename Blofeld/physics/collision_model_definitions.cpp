#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(pathfinding_sphere_flags, 3)
	{
		OPTION("remains when open"),
		OPTION("vehicle only"),
		OPTION("with sectors"),
	};

	TAG_ENUM(collision_model_flags, 5)
	{
		OPTION("contains open edges"),
		OPTION("physics built*!"),
		OPTION("physics in use*!"),
		OPTION("processed*!"),
		OPTION("has two sided surfaces"),
	};

	TAG_GROUP(collision_model, COLLISION_MODEL_TAG)
	{
		FIELD( _field_long_integer, "import_info_checksum*!" ),
		FIELD( _field_block, "errors*", &global_error_report_categories_block_block ),
		FIELD( _field_long_flags, "flags*", &collision_model_flags ),
		FIELD( _field_block, "materials*", &collision_model_material_block_block ),
		FIELD( _field_block, "regions*", &collision_model_region_block_block ),
		FIELD( _field_block, "cookie cutters*", &collision_model_region_block_block ),
		FIELD( _field_block, "pathfinding spheres*", &collision_model_pathfinding_sphere_block_block ),
		FIELD( _field_block, "nodes*", &collision_model_node_block_block ),
		FIELD( _field_pageable, "regions resource" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(collision_model_material_block, MAXIMUM_MATERIALS_PER_MODEL)
	{
		FIELD( _field_string_id, "name^*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(collision_model_region_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "name^*" ),
		FIELD( _field_block, "permutations*", &collision_model_permutation_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(collision_model_permutation_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		FIELD( _field_string_id, "name^*" ),
		FIELD( _field_short_integer, "resourceBspOffset*!" ),
		FIELD( _field_short_integer, "resourceBspCount*!" ),
		FIELD( _field_block, "bsps*", &collision_model_bsp_block_block ),
		FIELD( _field_block, "bsp_physics*", &collision_bsp_physics_block_block ),
		FIELD( _field_block, "mopp_codes*", &mopp_code_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(collision_model_bsp_block, MAXIMUM_BSPS_PER_COLLISION_REGION, collision_model_bsp_struct_struct_definition );

	TAG_BLOCK(collision_model_pathfinding_sphere_block, MAXIMUM_PATHFINDING_SPHERES_PER_COLLISION_MODEL)
	{
		FIELD( _field_short_block_index, "node*" ),
		FIELD( _field_word_flags, "flags", &pathfinding_sphere_flags ),
		FIELD( _field_useless_pad ),
		FIELD( _field_real_point_3d, "center*" ),
		FIELD( _field_real, "radius*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(collision_model_node_block, MAXIMUM_NODES_PER_MODEL)
	{
		FIELD( _field_string_id, "name^*" ),
		FIELD( _field_pad, "PFPPD", 2 ),
		FIELD( _field_short_block_index, "parent node*" ),
		FIELD( _field_short_block_index, "next sibling node*" ),
		FIELD( _field_short_block_index, "first child node*" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(collision_model_bsp_struct)
{
		FIELD( _field_short_integer, "node index*" ),
		FIELD( _field_pad, "KXGCEIEI", 2 ),
		FIELD( _field_useless_pad ),
		FIELD( _field_struct, "bsp*", &global_collision_bsp_struct_struct_definition ),
		FIELD( _field_terminator )
};

} // namespace blofeld

