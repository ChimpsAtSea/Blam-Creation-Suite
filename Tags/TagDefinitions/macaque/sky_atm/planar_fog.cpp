#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
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
		PLANAR_FOG_ZONE_SET_VISIBILITY_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "structure visiblity*", &planar_fog_structure_visibility_definition_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_STRUCTURE_VISIBILITY_DEFINITION_BLOCK_ID { 0x3593A341, 0x6239A94D, 0xB035CD9A, 0xAB6EA346 }
	TAG_BLOCK(
		planar_fog_structure_visibility_definition_block,
		"planar_fog_structure_visibility_definition_block",
		MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO,
		"s_planar_fog_structure_visibility",
		PLANAR_FOG_STRUCTURE_VISIBILITY_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "cluster visiblity*", &planar_fog_cluster_visibility_definition_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_CLUSTER_VISIBILITY_DEFINITION_BLOCK_ID { 0x359AA341, 0x6A39AC4D, 0xB036CD9A, 0xAB6EA046 }
	TAG_BLOCK(
		planar_fog_cluster_visibility_definition_block,
		"planar_fog_cluster_visibility_definition_block",
		MAXIMUM_CLUSTERS_PER_STRUCTURE,
		"s_planar_fog_cluster_visibility",
		PLANAR_FOG_CLUSTER_VISIBILITY_DEFINITION_BLOCK_ID)
	{
		{ _field_block, "attached fogs*", &planar_fog_reference_definition_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_REFERENCE_DEFINITION_BLOCK_ID { 0x354AA341, 0x6A39AC4D, 0xB036CD9A, 0xAB6EA046 }
	TAG_BLOCK(
		planar_fog_reference_definition_block,
		"planar_fog_reference_definition_block",
		k_short_max,
		"s_planar_fog_reference",
		PLANAR_FOG_REFERENCE_DEFINITION_BLOCK_ID)
	{
		{ _field_short_integer, "structure design index*" },
		{ _field_short_integer, "fog index*" },
		{ _field_terminator }
	};

	#define PLANAR_FOG_DEFINITION_BLOCK_ID { 0x35629341, 0x62394A4D, 0xBC854D9A, 0x946EE346 }
	TAG_BLOCK(
		planar_fog_definition_block,
		"planar_fog_definition_block",
		s_planer_fog_set_definition::k_maximum_planar_fog_count,
		"s_planar_fog_definition",
		PLANAR_FOG_DEFINITION_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_tag_reference, "appearance settings", &global_planar_fog_reference },
		{ _field_block, "vertices*", &planar_fog_vertex_block },
		{ _field_block, "triangles*", &planar_fog_triangle_block },
		{ _field_real, "depth*" },
		{ _field_real_vector_3d, "normal*" },
		{ _field_terminator }
	};

	#define PLANAR_FOG_VERTEX_BLOCK_ID { 0xE3CCF250, 0x83D64DB6, 0x852C0EE8, 0xD14E650D }
	TAG_BLOCK(
		planar_fog_vertex_block,
		"planar_fog_vertex_block",
		s_planar_fog_definition::k_maximum_triangle_count*k_vertices_per_triangle_count,
		"s_planar_fog_vertex",
		PLANAR_FOG_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "position*" },
		{ _field_terminator }
	};

	#define PLANAR_FOG_TRIANGLE_BLOCK_ID { 0x3AB29341, 0x62666A4D, 0x99854D9A, 0xAB3EE346 }
	TAG_BLOCK(
		planar_fog_triangle_block,
		"planar_fog_triangle_block",
		k_short_max,
		"s_planar_fog_triangle",
		PLANAR_FOG_TRIANGLE_BLOCK_ID)
	{
		{ _field_block, "planes*", &planar_fog_triangle_planes_block },
		{ _field_terminator }
	};

	#define PLANAR_FOG_TRIANGLE_PLANES_BLOCK_ID { 0x03AB29AB, 0x62666A4D, 0x03854D9A, 0xAB3AB346 }
	TAG_BLOCK(
		planar_fog_triangle_planes_block,
		"planar_fog_triangle_planes_block",
		s_planar_fog_definition::k_maximum_triangle_count,
		"real_plane3d",
		PLANAR_FOG_TRIANGLE_PLANES_BLOCK_ID)
	{
		{ _field_real_plane_3d, "plane*!" },
		{ _field_terminator }
	};

	#define PLANAR_FOG_PARAMETERS_STRUCT_DEFINITION_ID { 0x9E9FE02A, 0x81DC4FFC, 0x9D107ADB, 0x0FF0BCF4 }
	TAG_STRUCT(
		planar_fog_parameters_struct_definition,
		"planar_fog_parameters_struct_definition",
		"s_planar_fog_parameters",
		PLANAR_FOG_PARAMETERS_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "flags", &planar_fog_flags },
		{ _field_pad, "ABCDadf", 2 },
		{ _field_real, "fog thickness [0.0 to 1.0]" },
		{ _field_real, "per-vertex fog thickness modulation:(only for transparents)" },
		{ _field_real, "full fog depth:world units" },
		{ _field_real_rgb_color, "fog color" },
		{ _field_real, "fog color intensity" },
		{ _field_tag_reference, "palette texture", &global_bitmap_reference },
		FIELD_CUSTOM("patchy effect", _custom_field_function_group_begin),
		{ _field_tag_reference, "patchy texture", &global_bitmap_reference },
		{ _field_real_rgb_color, "patchy color" },
		{ _field_real, "patchy color intensity" },
		{ _field_real, "patchy texture tile size:world units" },
		{ _field_real, "patchy distance between sheets:world units" },
		{ _field_real, "patchy z-buffer fade factor" },
		{ _field_real, "patchy distance falloff start:world units" },
		{ _field_real, "patchy distance falloff power:world units" },
		{ _field_real, "patchy density" },
		{ _field_real, "patchy surface depth:world units" },
		{ _field_real, "patchy fade range:world units" },
		{ _field_real_vector_3d, "patchy wind direction:world units" },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("LoD settings (N/A yet)", _custom_field_function_group_begin),
		{ _field_real, "max fog draw distance:world units" },
		{ _field_real, "patchy fade start distance:world units" },
		{ _field_real, "patchy fade end distance:world units" },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	#define PLANAR_FOG_SET_DEFINITION_STRUCT_ID { 0xADF66371, 0xDA8642BF, 0xCD987004, 0xBABC69EC }
	TAG_STRUCT(
		planar_fog_set_definition_struct,
		"planar_fog_set_definition_struct",
		"s_planer_fog_set_definition",
		PLANAR_FOG_SET_DEFINITION_STRUCT_ID)
	{
		{ _field_block, "planar fogs", &planar_fog_definition_block },
		{ _field_block, "mopp code*!", &mopp_code_definition_block },
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

} // namespace macaque

} // namespace blofeld

