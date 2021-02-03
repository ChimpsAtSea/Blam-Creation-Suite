#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_RENDER_MODEL_INSTANCE_PLACEMENT_BLOCK_ID { 0xC01E3AA5, 0x8CC5444B, 0xAA65DA03, 0xDF961696 }
	TAG_BLOCK(
		global_render_model_instance_placement_block,
		"global_render_model_instance_placement_block",
		k_maximum_instance_placements_per_render_model,
		"s_render_model_instance_placement",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_RENDER_MODEL_INSTANCE_PLACEMENT_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_long_block_index, "node_index", &render_model_node_block },
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "left" },
		{ _field_real_vector_3d, "up" },
		{ _field_real_point_3d, "position" },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_INSTANCED_GEOMETRY_INSTANCES_BLOCK_ID { 0x1AED06E6, 0xF1AC46B4, 0x8A2AF2D2, 0xDA51B54A }
	TAG_BLOCK(
		structure_bsp_instanced_geometry_instances_block,
		"structure_bsp_instanced_geometry_instances_block",
		k_maximum_instance_geometry_instances_per_structure_bsp,
		"structure_bsp_instanced_geometry_instances_block",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_INSTANCED_GEOMETRY_INSTANCES_BLOCK_ID)
	{
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "left" },
		{ _field_real_vector_3d, "up" },
		{ _field_real_point_3d, "position" },
		{ _field_short_block_index, "instance definition", &structure_bsp_instanced_geometry_definition_block },
		{ _field_word_flags, "flags", &instanced_geometry_flags },
		{ _field_long_flags, "Light Channels", &channelDefinitionFlags },
		{ _field_short_integer, "mesh_index" },
		{ _field_short_integer, "compression_index" },
		{ _field_long_integer, "seam bit vector 0" },
		{ _field_long_integer, "seam bit vector 1" },
		{ _field_long_integer, "seam bit vector 2" },
		{ _field_long_integer, "seam bit vector 3" },
		{ _field_real, "bounds x0" },
		{ _field_real, "bounds x1" },
		{ _field_real, "bounds y0" },
		{ _field_real, "bounds y1" },
		{ _field_real, "bounds z0" },
		{ _field_real, "bounds z1" },
		{ _field_real_point_3d, "world bounding sphere center" },
		{ _field_real, "world bounding sphere radius" },
		{ _field_real, "imposter transition complete distance" },
		{ _field_real, "imposter brightness" },
		{ _field_long_integer, "checksum" },
		{ _field_char_enum, "pathfinding policy", &instanced_geometry_pathfinding_policy_enum },
		{ _field_char_enum, "lightmapping policy", &instanced_geometry_lightmapping_policy_enum },
		{ _field_char_enum, "imposter policy", &instanced_geometry_imposter_policy_enum },
		FIELD_PAD("SDFSDFE", nullptr, 1),
		{ _field_char_enum, "streaming priority", &instanced_geometry_streamingpriority_enum },
		FIELD_PAD("strpad", nullptr, 1),
		{ _field_short_integer, "cubemap 0 bitmap index" },
		{ _field_real, "lightmap resolution scale" },
		{ _field_short_integer, "group_index" },
		{ _field_short_integer, "group_list_index" },
		{ _field_string_id, "name" },
		{ _field_long_string, "source file name" },
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_INSTANCED_GEOMETRY_DEFINITION_BLOCK_ID { 0xF51D0B5F, 0x91954EB1, 0x8B0C7E1F, 0x85168F82 }
	TAG_BLOCK(
		structure_bsp_instanced_geometry_definition_block,
		"structure_bsp_instanced_geometry_definition_block",
		k_maximum_instance_geometry_definitions_per_structure_bsp,
		"structure_instanced_geometry_definition",
		SET_DELETE_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_INSTANCED_GEOMETRY_DEFINITION_BLOCK_ID)
	{
		{ _field_long_integer, "checksum" },
		{ _field_long_flags, "flags", &instanced_geometry_definition_flags },
		{ _field_short_integer, "mesh index" },
		{ _field_short_integer, "compression index" },
		{ _field_real, "global lightmap resolution scale" },
		{ _field_short_integer, "external_index" },
		FIELD_PAD("useme", nullptr, 2),
		{ _field_terminator }
	};

	#define STRUCTURE_BSP_INSTANCED_GEOMETRY_INSTANCES_NAMES_BLOCK_ID { 0xA3DF7A2E, 0xC2DC41E9, 0xDBA27244, 0x1AD617D1 }
	TAG_BLOCK(
		structure_bsp_instanced_geometry_instances_names_block,
		"structure_bsp_instanced_geometry_instances_names_block",
		k_maximum_instance_geometry_instances_per_structure_bsp,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_INSTANCED_GEOMETRY_INSTANCES_NAMES_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		structureIOHavokDataBlock_block,
		"structureIOHavokDataBlock",
		1,
		structureIOHavokDataBlock_struct);

	TAG_BLOCK_FROM_STRUCT(
		SerializedHavokGeometryDataBlock_block,
		"SerializedHavokGeometryDataBlock",
		5,
		SerializedHavokGeometryDataBlock_struct);

	#define STRUCTURE_BSP_INSTANCED_GEOMETRY_INSTANCES_WITHOUT_NAMES_BLOCK_ID { 0xA3DF7F2E, 0x72DC41E9, 0xDFA27244, 0x1AD627D1 }
	TAG_BLOCK(
		structure_bsp_instanced_geometry_instances_without_names_block,
		"structure_bsp_instanced_geometry_instances_without_names_block",
		k_maximum_instance_geometry_instances_per_structure_bsp,
		"structure_instanced_geometry_instance",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_BSP_INSTANCED_GEOMETRY_INSTANCES_WITHOUT_NAMES_BLOCK_ID)
	{
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "left" },
		{ _field_real_vector_3d, "up" },
		{ _field_real_point_3d, "position" },
		{ _field_short_block_index, "instance definition", &structure_bsp_instanced_geometry_definition_block },
		{ _field_word_flags, "flags", &instanced_geometry_flags },
		{ _field_long_flags, "Light Channels", &channelDefinitionFlags },
		{ _field_short_integer, "mesh_index" },
		{ _field_short_integer, "compression_index" },
		{ _field_long_integer, "seam bit vector 0" },
		{ _field_long_integer, "seam bit vector 1" },
		{ _field_long_integer, "seam bit vector 2" },
		{ _field_long_integer, "seam bit vector 3" },
		{ _field_real, "bounds x0" },
		{ _field_real, "bounds x1" },
		{ _field_real, "bounds y0" },
		{ _field_real, "bounds y1" },
		{ _field_real, "bounds z0" },
		{ _field_real, "bounds z1" },
		{ _field_real_point_3d, "world bounding sphere center" },
		{ _field_real, "world bounding sphere radius" },
		{ _field_real, "imposter transition complete distance" },
		{ _field_real, "imposter brightness" },
		{ _field_long_integer, "checksum" },
		{ _field_char_enum, "pathfinding policy", &instanced_geometry_pathfinding_policy_enum },
		{ _field_char_enum, "lightmapping policy", &instanced_geometry_lightmapping_policy_enum },
		{ _field_char_enum, "imposter policy", &instanced_geometry_imposter_policy_enum },
		FIELD_PAD("SDFSDFE", nullptr, 1),
		{ _field_char_enum, "streaming priority", &instanced_geometry_streamingpriority_enum },
		FIELD_PAD("strpad", nullptr, 1),
		{ _field_short_integer, "cubemap 0 bitmap index" },
		{ _field_real, "lightmap resolution scale" },
		{ _field_short_integer, "group_index" },
		{ _field_short_integer, "group_list_index" },
		{ _field_terminator }
	};

	#define STRUCTUREIOHAVOKDATABLOCK_STRUCT_ID { 0x07320729, 0x546A468D, 0xBDB63F21, 0xF4C58C41 }
	TAG_STRUCT(
		structureIOHavokDataBlock_struct,
		"structureIOHavokDataBlock_struct",
		"StructureIOSerializedHavokData",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTUREIOHAVOKDATABLOCK_STRUCT_ID)
	{
		{ _field_long_integer, "version" },
		{ _field_long_integer, "RuntimeDeserializedBody Pointer" },
		{ _field_long_integer, "RuntimeDeserializedData Pointer" },
		{ _field_long_integer, "Prefab Index" },
		{ _field_data, "Serialized Havok Data" },
		{ _field_block, "Serialized Per Collision Type Havok Geometry", &SerializedHavokGeometryDataBlock_block },
		{ _field_real_point_3d, "Shapes bounds min" },
		{ _field_real_point_3d, "Shapes bounds max" },
		{ _field_terminator }
	};

	#define SERIALIZEDHAVOKGEOMETRYDATABLOCK_STRUCT_ID { 0xB831D0B0, 0x123446F2, 0x832BB0CF, 0x6CDDB759 }
	TAG_STRUCT(
		SerializedHavokGeometryDataBlock_struct,
		"SerializedHavokGeometryDataBlock_struct",
		"SerializedHavokGeometry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SERIALIZEDHAVOKGEOMETRYDATABLOCK_STRUCT_ID)
	{
		{ _field_data, "Serialized Havok Data" },
		{ _field_data, "Serialized Static Havok Data" },
		{ _field_long_integer, "collision type" },
		{ _field_long_integer, "RuntimeDeserializedBody Pointer" },
		{ _field_long_integer, "RuntimeDeserializedData Pointer" },
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

} // namespace macaque

} // namespace blofeld

