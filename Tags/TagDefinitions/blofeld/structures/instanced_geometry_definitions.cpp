#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(global_render_model_instance_placement_block, k_maximum_instance_placements_per_render_model)
	{
		{ _field_string_id, "name^*" },
		{ _field_long_block_index, "node_index*" },
		{ _field_real, "scale*" },
		{ _field_real_vector_3d, "forward*" },
		{ _field_real_vector_3d, "left*" },
		{ _field_real_vector_3d, "up*" },
		{ _field_real_point_3d, "position*" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_bsp_instanced_geometry_collision_definition_block, 65536) // assembly
	{
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_short_integer, "size" },
		{ _field_short_integer, "count" },
		{ _field_real, "unknown@" },
		{ _field_long_integer, "offset" },
		{ _field_real, "unknown@" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real_vector_3d, "unknown" },
		{ _field_real, "unknown@" },
		{ _field_real_vector_3d, "unknown" },
		{ _field_real, "unknown@" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_char_integer, "bsp index" },
		{ _field_char_integer, "unknown" },
		{ _field_short_integer, "instance geometry index" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_short_integer, "size" },
		{ _field_short_integer, "count" },
		{ _field_real, "unknown@" },
		{ _field_long_integer, "offset" },
		{ _field_real, "unknown@" },
		{ _field_long_integer, "unknown" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_bsp_instanced_geometry_instances_block, k_maximum_instance_geometry_instances_per_structure_bsp)
	{
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "left" },
		{ _field_real_vector_3d, "up" },
		{ _field_real_point_3d, "position" },
		{ _field_short_block_index, "instance definition*" },
		{ _field_word_flags, "flags", &instanced_geometry_flags },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_long_flags, "Light Channels:", &channelDefinitionFlags },

		{ _field_short_integer, "mesh_index" },
		{ _field_short_integer, "compression_index" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_long_integer, "unknown@" },

		{ _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_long_integer, "seam bit vector 0" },
		{ _field_long_integer, "seam bit vector 1" },
		{ _field_long_integer, "seam bit vector 2" },
		{ _field_long_integer, "seam bit vector 3" },

		{ _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_real, "bounds x0!" },
		{ _field_real, "bounds x1!" },
		{ _field_real, "bounds y0!" },
		{ _field_real, "bounds y1!" },
		{ _field_real, "bounds z0!" },
		{ _field_real, "bounds z1!" },

		{ _field_real_point_3d, "world bounding sphere center!" },
		{ _field_real, "world bounding sphere radius!" },
		{ _field_real, "imposter transition complete distance!" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_string_id, "name" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "imposter brightness!" },
		{ _field_long_integer, "checksum*" },

		{ _field_char_enum, "pathfinding policy*", &instanced_geometry_pathfinding_policy_enum },
		{ _field_char_enum, "lightmapping policy*", &instanced_geometry_lightmapping_policy_enum },
		{ _field_char_enum, "imposter policy*", &instanced_geometry_imposter_policy_enum },
		{ _field_pad, "SDFSDFE", 1 },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },


		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_char_enum, "streaming priority*", &instanced_geometry_streamingpriority_enum },
		{ _field_pad, "strpad", 1 },
		{ _field_short_integer, "cubemap 0 bitmap index" },

		{ _field_real, "lightmap resolution scale" },

		{ _field_block, "collision definition?", &structure_bsp_instanced_geometry_collision_definition_block_block },

		{ _field_short_integer, "group_index!" },
		{ _field_short_integer, "group_list_index!" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_string_id, "name*^" },
		{ _field_long_string, "source file name*" },

		{ _field_terminator }
	};

	TAG_BLOCK(structure_bsp_instanced_geometry_instances_names_block, k_maximum_instance_geometry_instances_per_structure_bsp)
	{
		{ _field_string_id, "name*^" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_bsp_instanced_geometry_definition_block, k_maximum_instance_geometry_definitions_per_structure_bsp)
	{
		{ _field_long_integer, "checksum*" },
		{ _field_long_flags, "flags*", &instanced_geometry_definition_flags },
		{ _field_short_integer, "mesh index" },
		{ _field_short_integer, "compression index" },
		{ _field_real, "global lightmap resolution scale" },
		{ _field_short_integer, "external_index" },
		{ _field_pad, "useme", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(SerializedHavokGeometryDataBlock, 5, SerializedHavokGeometryDataBlock_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(structureIOHavokDataBlock, 1, structureIOHavokDataBlock_struct_struct_definition );

	TAG_STRUCT(structureIOHavokDataBlock_struct)
	{
		{ _field_long_integer, "version*" },
		{ _field_long_integer, "RuntimeDeserializedBody Pointer*!" },
		{ _field_long_integer, "RuntimeDeserializedData Pointer*!" },
		{ _field_long_integer, "Prefab Index*!" },
		{ _field_data, "Serialized Havok Data*" },
		{ _field_block, "Serialized Per Collision Type Havok Geometry", &SerializedHavokGeometryDataBlock_block },
		{ _field_real_point_3d, "Shapes bounds min!*" },
		{ _field_real_point_3d, "Shapes bounds max!*" },
		{ _field_terminator }
	};

	TAG_STRUCT(SerializedHavokGeometryDataBlock_struct)
	{
		{ _field_data, "Serialized Havok Data*" },
		{ _field_data, "Serialized Static Havok Data*" },
		{ _field_long_integer, "collision type" },
		{ _field_long_integer, "RuntimeDeserializedBody Pointer*!" },
		{ _field_long_integer, "RuntimeDeserializedData Pointer*!" },
		{ _field_terminator }
	};

	STRINGS(instanced_geometry_flags)
	{
		"not in lightprobes",
		"render only",
		"does not block aoe damage",
		"collidable",
		"decal spacing",
		"rain blocker",
		"vertical rain sheet",
		"outside map",
		"seam colliding",
		"(mostly) planar",
		"remove from shadow geometry",
		"cinema only",
		"exclude from cinema",
		"disallow object lighting samples"
	};
	STRING_LIST(instanced_geometry_flags, instanced_geometry_flags_strings, _countof(instanced_geometry_flags_strings));

	STRINGS(instanced_geometry_imposter_policy_enum)
	{
		"polygon default",
		"polygon high",
		"cards medium",
		"cards high",
		"none",
		"rainbow box (runtime only)"
	};
	STRING_LIST(instanced_geometry_imposter_policy_enum, instanced_geometry_imposter_policy_enum_strings, _countof(instanced_geometry_imposter_policy_enum_strings));

	STRINGS(instanced_geometry_pathfinding_policy_enum)
	{
		"cut-out",
		"static",
		"none"
	};
	STRING_LIST(instanced_geometry_pathfinding_policy_enum, instanced_geometry_pathfinding_policy_enum_strings, _countof(instanced_geometry_pathfinding_policy_enum_strings));

	STRINGS(instanced_geometry_lightmapping_policy_enum)
	{
		"per-pixel shared",
		"per-vertex",
		"single-probe",
		"exclude",
		"per-pixel ao",
		"per-vertex ao"
	};
	STRING_LIST(instanced_geometry_lightmapping_policy_enum, instanced_geometry_lightmapping_policy_enum_strings, _countof(instanced_geometry_lightmapping_policy_enum_strings));

	STRINGS(instanced_geometry_streamingpriority_enum)
	{
		"default",
		"higher",
		"highest"
	};
	STRING_LIST(instanced_geometry_streamingpriority_enum, instanced_geometry_streamingpriority_enum_strings, _countof(instanced_geometry_streamingpriority_enum_strings));

	STRINGS(instanced_geometry_definition_flags)
	{
		"miscolored bsp",
		"error free",
		"surface to triangle remapped",
		"external reference mesh",
		"no physics",
		"stitched physics"
	};
	STRING_LIST(instanced_geometry_definition_flags, instanced_geometry_definition_flags_strings, _countof(instanced_geometry_definition_flags_strings));

} // namespace blofeld

