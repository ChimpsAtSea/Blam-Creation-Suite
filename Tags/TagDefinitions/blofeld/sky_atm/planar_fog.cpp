#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		planar_fog_parameters_group,
		PLANAR_FOG_PARAMETERS_TAG,
		nullptr,
		INVALID_TAG,
		planar_fog_parameters_block );

	TAG_BLOCK_FROM_STRUCT(
		planar_fog_parameters_block,
		"planar_fog_parameters_block",
		1,
		planar_fog_parameters_struct_definition);

	#define PLANAR_FOG_ZONE_SET_VISIBILITY_DEFINITION_BLOCK_ID { 0x35939341, 0x6239A44D, 0xB0354D9A, 0xAB6EE346 }
	TAG_BLOCK(
		planar_fog_zone_set_visibility_definition_block,
		"planar_fog_zone_set_visibility_definition_block",
		1,
		"s_planar_fog_zone_set_visibility",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_ZONE_SET_VISIBILITY_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "structure visiblity", FIELD_FLAG_READ_ONLY, &planar_fog_structure_visibility_definition_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_STRUCTURE_VISIBILITY_DEFINITION_BLOCK_ID { 0x3593A341, 0x6239A94D, 0xB035CD9A, 0xAB6EA346 }
	TAG_BLOCK(
		planar_fog_structure_visibility_definition_block,
		"planar_fog_structure_visibility_definition_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_planar_fog_structure_visibility",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_STRUCTURE_VISIBILITY_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "cluster visiblity", FIELD_FLAG_READ_ONLY, &planar_fog_cluster_visibility_definition_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_CLUSTER_VISIBILITY_DEFINITION_BLOCK_ID { 0x359AA341, 0x6A39AC4D, 0xB036CD9A, 0xAB6EA046 }
	TAG_BLOCK(
		planar_fog_cluster_visibility_definition_block,
		"planar_fog_cluster_visibility_definition_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_planar_fog_cluster_visibility",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_CLUSTER_VISIBILITY_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "attached fogs", FIELD_FLAG_READ_ONLY, &planar_fog_reference_definition_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_REFERENCE_DEFINITION_BLOCK_ID { 0x354AA341, 0x6A39AC4D, 0xB036CD9A, 0xAB6EA046 }
	TAG_BLOCK(
		planar_fog_reference_definition_block,
		"planar_fog_reference_definition_block",
		k_short_max,
		"s_planar_fog_reference",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_REFERENCE_DEFINITION_BLOCK_ID)
	{
		{ _field_short_integer, "structure design index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "fog index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PLANAR_FOG_DEFINITION_BLOCK_ID { 0x35629341, 0x62394A4D, 0xBC854D9A, 0x946EE346 }
	TAG_BLOCK(
		planar_fog_definition_block,
		"planar_fog_definition_block",
		s_planer_fog_set_definition::k_maximum_planar_fog_count,
		"s_planar_fog_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_tag_reference, "appearance settings", &global_planar_fog_reference },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &planar_fog_vertex_block },
		{ _field_block, "triangles", FIELD_FLAG_READ_ONLY, &planar_fog_triangle_block },
		{ _field_real, "depth", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "normal", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PLANAR_FOG_VERTEX_BLOCK_ID { 0xE3CCF250, 0x83D64DB6, 0x852C0EE8, 0xD14E650D }
	TAG_BLOCK(
		planar_fog_vertex_block,
		"planar_fog_vertex_block",
		s_planar_fog_definition::k_maximum_triangle_count*k_vertices_per_triangle_count,
		"s_planar_fog_vertex",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PLANAR_FOG_TRIANGLE_BLOCK_ID { 0x3AB29341, 0x62666A4D, 0x99854D9A, 0xAB3EE346 }
	TAG_BLOCK(
		planar_fog_triangle_block,
		"planar_fog_triangle_block",
		k_short_max,
		"s_planar_fog_triangle",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_TRIANGLE_BLOCK_ID)
	{
		{ _field_block, "planes", FIELD_FLAG_READ_ONLY, &planar_fog_triangle_planes_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_TRIANGLE_PLANES_BLOCK_ID { 0x03AB29AB, 0x62666A4D, 0x03854D9A, 0xAB3AB346 }
	TAG_BLOCK(
		planar_fog_triangle_planes_block,
		"planar_fog_triangle_planes_block",
		s_planar_fog_definition::k_maximum_triangle_count,
		"real_plane3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_TRIANGLE_PLANES_BLOCK_ID)
	{
		{ _field_real_plane_3d, "plane", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PLANAR_FOG_PARAMETERS_STRUCT_DEFINITION_ID { 0x9E9FE02A, 0x81DC4FFC, 0x9D107ADB, 0x0FF0BCF4 }
	TAG_STRUCT(
		planar_fog_parameters_struct_definition,
		"planar_fog_parameters_struct_definition",
		"s_planar_fog_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_PARAMETERS_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "flags", &planar_fog_flags },
		FIELD_PAD_EX("ABCDadf", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "fog thickness" },
		{ _field_real, "per-vertex fog thickness modulation", nullptr, "(only for transparents)" },
		{ _field_real, "full fog depth", nullptr, "world units" },
		{ _field_real_rgb_color, "fog color" },
		{ _field_real, "fog color intensity" },
		{ _field_tag_reference, "palette texture", &global_bitmap_reference },
		FIELD_CUSTOM_EX("patchy effect", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_tag_reference, "patchy texture", &global_bitmap_reference },
		{ _field_real_rgb_color, "patchy color" },
		{ _field_real, "patchy color intensity" },
		{ _field_real, "patchy texture tile size", nullptr, "world units" },
		{ _field_real, "patchy distance between sheets", nullptr, "world units" },
		{ _field_real, "patchy z-buffer fade factor" },
		{ _field_real, "patchy distance falloff start", nullptr, "world units" },
		{ _field_real, "patchy distance falloff power", nullptr, "world units" },
		{ _field_real, "patchy density" },
		{ _field_real, "patchy surface depth", nullptr, "world units" },
		{ _field_real, "patchy fade range", nullptr, "world units" },
		{ _field_real_vector_3d, "patchy wind direction", nullptr, "world units" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("LoD settings (N/A yet)", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "max fog draw distance", nullptr, "world units" },
		{ _field_real, "patchy fade start distance", nullptr, "world units" },
		{ _field_real, "patchy fade end distance", nullptr, "world units" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define PLANAR_FOG_SET_DEFINITION_STRUCT_ID { 0xADF66371, 0xDA8642BF, 0xCD987004, 0xBABC69EC }
	TAG_STRUCT(
		planar_fog_set_definition_struct,
		"planar_fog_set_definition_struct",
		"s_planer_fog_set_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PLANAR_FOG_SET_DEFINITION_STRUCT_ID)
	{
		{ _field_block, "planar fogs", &planar_fog_definition_block },
		{ _field_block, "mopp code", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &mopp_code_definition_block },
		{ _field_terminator }
	};

	STRINGS(planar_fog_flags)
	{
		"enable patchy effect",
		"enable color palette",
		"enable alpha palette",
		"render only"
	};
	STRING_LIST(planar_fog_flags, planar_fog_flags_strings, _countof(planar_fog_flags_strings));

	TAG_REFERENCE(global_planar_fog_reference, PLANAR_FOG_PARAMETERS_TAG);



} // namespace blofeld

