#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
namespace halo1 {

	TAG_GROUP(
		model_group,
		MODEL_TAG,
		nullptr,
		INVALID_TAG,
		model);

	TAG_BLOCK(
		model,
		"model_group_block",
		1,
		"s_model",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum },
		{ _field_long_integer, "node list checksum", FIELD_FLAG_READ_ONLY },
		{ _field_real, "super-high detail cutoff", nullptr, "pixels" },
		{ _field_real, "high detail cutoff", nullptr, "pixels" },
		{ _field_real, "medium detail cutoff", nullptr, "pixels" },
		{ _field_real, "low detail cutoff", nullptr, "pixels" },
		{ _field_real, "super-low cutoff", nullptr, "pixels" },
		{ _field_short_integer, "super-high detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "high detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "medium detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "low detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "super-low detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "base map u-scale", "0 defaults to 1", FIELD_FLAG_READ_ONLY },
		{ _field_real, "base map v-scale", "0 defaults to 1", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 116),
		{ _field_block, "markers", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_markers_block },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_node_block },
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_region_block },
		{ _field_block, "geometries", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_geometry_block },
		{ _field_block, "shaders", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_shader_reference_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum)
	{
		"blend shared normals",
		"parts have local nodes",
		"ignore skinning"
	};
	STRING_LIST(unnamed_enum, unnamed_enum_strings, _countof(unnamed_enum_strings));

	TAG_BLOCK(
		model_shader_reference_block,
		"model_shader_reference_block",
		32,
		"s_model_shader_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "shader", FIELD_FLAG_INDEX, &blofeld::halo1::shader_reference },
		{ _field_short_integer, "permutation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	TAG_REFERENCE(shader_reference, SHADER_TAG);

	TAG_BLOCK(
		model_geometry_block,
		"model_geometry_block",
		256,
		"s_model_geometry_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "parts", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_geometry_part_block },
		{ _field_terminator }
	};

	STRING_LIST(unnamed_enum$3, empty_string_list, 0);

	TAG_BLOCK(
		model_geometry_part_block,
		"model_geometry_part_block",
		32,
		"s_model_geometry_part_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$4 },
		{ _field_short_block_index, "shader index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_shader_reference_block },
		{ _field_char_integer, "prev filthy part index" },
		{ _field_char_integer, "next filthy part index" },
		{ _field_short_integer, "centroid primary node", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "centroid secondary node", FIELD_FLAG_READ_ONLY },
		{ _field_real_fraction, "centroid primary weight", FIELD_FLAG_READ_ONLY },
		{ _field_real_fraction, "centroid secondary weight", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "centroid", FIELD_FLAG_READ_ONLY },
		{ _field_block, "uncompressed vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_vertex_uncompressed_block },
		{ _field_block, "compressed vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_vertex_compressed_block },
		{ _field_block, "triangles", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_triangle_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$4)
	{
		"stripped (INTERNAL)",
		"ZONER: _model_part_local_nodes"
	};
	STRING_LIST(unnamed_enum$4, unnamed_enum$4_strings, _countof(unnamed_enum$4_strings));

	TAG_BLOCK(
		model_triangle_block,
		"model_triangle_block",
		65535,
		"s_model_triangle_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "vertex0 index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "vertex1 index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "vertex2 index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		model_vertex_compressed_block,
		"model_vertex_compressed_block",
		65535,
		"s_model_vertex_compressed_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "normal[11.11.10-bit]", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "binormal[11.11.10-bit]", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "tangent[11.11.10-bit]", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "texture coordinate u[16-bit]", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "texture coordinate v[16-bit]", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "node0 index(x3)", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "node1 index(x3)", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "node0 weight[16-bit]", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		model_vertex_uncompressed_block,
		"model_vertex_uncompressed_block",
		65535,
		"s_model_vertex_uncompressed_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "normal", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "binormal", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "tangent", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_2d, "texture coords", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "node0 index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "node1 index", FIELD_FLAG_READ_ONLY },
		{ _field_real, "node0 weight", FIELD_FLAG_READ_ONLY },
		{ _field_real, "node1 weight", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		model_region_block,
		"model_region_block",
		32,
		"s_model_region_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "permutations", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_region_permutation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		model_region_permutation_block,
		"model_region_permutation_block",
		32,
		"s_model_region_permutation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_short_block_index, "super low", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_geometry_block },
		{ _field_short_block_index, "low", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_geometry_block },
		{ _field_short_block_index, "medium", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_geometry_block },
		{ _field_short_block_index, "high", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_geometry_block },
		{ _field_short_block_index, "super high", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_geometry_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "markers", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_region_permutation_marker_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$2)
	{
		"cannot be chosen randomly"
	};
	STRING_LIST(unnamed_enum$2, unnamed_enum$2_strings, _countof(unnamed_enum$2_strings));

	TAG_BLOCK(
		model_region_permutation_marker_block,
		"model_region_permutation_marker_block",
		64,
		"s_model_region_permutation_marker_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_block_index, "node index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_node_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_quaternion, "rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "translation", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	TAG_BLOCK(
		model_node_block,
		"model_node_block",
		64,
		"s_model_node_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_block_index, "next sibling node index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_node_block },
		{ _field_short_block_index, "first child node index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_node_block },
		{ _field_short_block_index, "parent node index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_node_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "default translation", FIELD_FLAG_READ_ONLY },
		{ _field_real_quaternion, "default rotation", FIELD_FLAG_READ_ONLY },
		{ _field_real, "node distance from parent", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		{ _field_terminator }
	};

	TAG_BLOCK(
		model_markers_block,
		"model_markers_block",
		256,
		"s_model_markers_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_integer, "magic identifier", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_block, "instances", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_marker_instance_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		model_marker_instance_block,
		"model_marker_instance_block",
		32,
		"s_model_marker_instance_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_char_integer, "region index", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "permutation index", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "node index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_real_point_3d, "translation", FIELD_FLAG_READ_ONLY },
		{ _field_real_quaternion, "rotation", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};


	TAG_GROUP(
		gbxmodel_group,
		GBXMODEL_TAG,
		nullptr,
		INVALID_TAG,
		gbxmodel);

	TAG_BLOCK(
		gbxmodel,
		"gbxmodel_group_block",
		1,
		"s_gbxmodel",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum },
		{ _field_long_integer, "node list checksum", FIELD_FLAG_READ_ONLY },
		{ _field_real, "super-high detail cutoff", nullptr, "pixels" },
		{ _field_real, "high detail cutoff", nullptr, "pixels" },
		{ _field_real, "medium detail cutoff", nullptr, "pixels" },
		{ _field_real, "low detail cutoff", nullptr, "pixels" },
		{ _field_real, "super-low cutoff", nullptr, "pixels" },
		{ _field_short_integer, "super-high detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "high detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "medium detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "low detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "super-low detail node count", nullptr, "nodes", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "base map u-scale", "0 defaults to 1", FIELD_FLAG_READ_ONLY },
		{ _field_real, "base map v-scale", "0 defaults to 1", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 116),
		{ _field_block, "markers", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_markers_block },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_node_block },
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_region_block },
		{ _field_block, "geometries", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_geometry_block },
		{ _field_block, "shaders", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_shader_reference_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		gbxmodel_geometry_block,
		"gbxmodel_geometry_block",
		256,
		"s_gbxmodel_geometry_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "parts", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_geometry_part_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		gbxmodel_geometry_part_block,
		"gbxmodel_geometry_part_block",
		32,
		"s_gbxmodel_geometry_part_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$4 },
		{ _field_short_block_index, "shader index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_shader_reference_block },
		{ _field_char_integer, "prev filthy part index" },
		{ _field_char_integer, "next filthy part index" },
		{ _field_short_integer, "centroid primary node", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "centroid secondary node", FIELD_FLAG_READ_ONLY },
		{ _field_real_fraction, "centroid primary weight", FIELD_FLAG_READ_ONLY },
		{ _field_real_fraction, "centroid secondary weight", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "centroid", FIELD_FLAG_READ_ONLY },
		{ _field_block, "uncompressed vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_vertex_uncompressed_block },
		{ _field_block, "compressed vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_vertex_compressed_block },
		{ _field_block, "triangles", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_triangle_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	TAG_BLOCK(
		gbxmodel_region_block,
		"gbxmodel_region_block",
		32,
		"s_gbxmodel_region_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "permutations", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_region_permutation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		gbxmodel_region_permutation_block,
		"gbxmodel_region_permutation_block",
		32,
		"s_gbxmodel_region_permutation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_short_block_index, "super low", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_geometry_block },
		{ _field_short_block_index, "low", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_geometry_block },
		{ _field_short_block_index, "medium", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_geometry_block },
		{ _field_short_block_index, "high", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_geometry_block },
		{ _field_short_block_index, "super high", FIELD_FLAG_READ_ONLY, &blofeld::halo1::gbxmodel_geometry_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "markers", FIELD_FLAG_READ_ONLY, &blofeld::halo1::model_region_permutation_marker_block },
		{ _field_terminator }
	};


	TAG_GROUP(
		model_animations_group,
		MODEL_ANIMATIONS_TAG,
		nullptr,
		INVALID_TAG,
		model_animations);

	TAG_BLOCK(
		model_animations,
		"model_animations_group_block",
		1,
		"s_model_animations",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "OBJECTS", &blofeld::halo1::animation_graph_object_overlay },
		{ _field_block, "UNITS", &blofeld::halo1::animation_graph_unit_seat_block },
		{ _field_block, "WEAPONS", &blofeld::halo1::animation_graph_weapon_animations_block },
		{ _field_block, "VEHICLES", &blofeld::halo1::animation_graph_vehicle_animations_block },
		{ _field_block, "DEVICES", &blofeld::halo1::device_animations },
		{ _field_block, "UNIT DAMAGE", &blofeld::halo1::unit_damage_animations },
		{ _field_block, "FIRST PERSON WEAPONS", &blofeld::halo1::animation_graph_first_person_weapon_animations_block },
		{ _field_block, "sound references", &blofeld::halo1::animation_graph_sound_reference_block },
		{ _field_real, "limp body node radius", "0 uses 0.04 default" },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$10 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_graph_node_block },
		{ _field_block, "animations", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$10)
	{
		"compress all animations",
		"force idle compression"
	};
	STRING_LIST(unnamed_enum$10, unnamed_enum$10_strings, _countof(unnamed_enum$10_strings));

	TAG_BLOCK(
		animation_block,
		"animation_block",
		256,
		"s_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_enum, "type", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$5 },
		{ _field_short_integer, "frame count", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "frame size", FIELD_FLAG_READ_ONLY },
		{ _field_short_enum, "frame info type", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$6 },
		{ _field_long_integer, "node list checksum", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "node count", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "loop frame index" },
		{ _field_real_fraction, "weight" },
		{ _field_short_integer, "key frame index" },
		{ _field_short_integer, "second key frame index" },
		{ _field_short_block_index, "next animation", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_block },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$7 },
		{ _field_short_block_index, "sound", &blofeld::halo1::animation_graph_sound_reference_block },
		{ _field_short_integer, "sound frame index" },
		{ _field_char_integer, "left foot frame index" },
		{ _field_char_integer, "right foot frame index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_data, "frame info", FIELD_FLAG_READ_ONLY },
		{ _field_array, "node trans. flag data", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_block__node_trans_flag_data_array },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_array, "node rotation flag data", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_block__node_rotation_flag_data_array },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_array, "node scale flag data", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_block__node_scale_flag_data_array },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_long_integer, "offset to compressed data", nullptr, "bytes", FIELD_FLAG_READ_ONLY },
		{ _field_data, "default data", FIELD_FLAG_READ_ONLY },
		{ _field_data, "frame data", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$5)
	{
		"base",
		"overlay",
		"replacement"
	};
	STRING_LIST(unnamed_enum$5, unnamed_enum$5_strings, _countof(unnamed_enum$5_strings));

	STRINGS(unnamed_enum$6)
	{
		"none",
		"dx,dy",
		"dx,dy,dyaw",
		"dx,dy,dz,dyaw"
	};
	STRING_LIST(unnamed_enum$6, unnamed_enum$6_strings, _countof(unnamed_enum$6_strings));

	STRINGS(unnamed_enum$7)
	{
		"compressed data",
		"world relative",
		"25Hz (PAL)"
	};
	STRING_LIST(unnamed_enum$7, unnamed_enum$7_strings, _countof(unnamed_enum$7_strings));

	TAG_ARRAY(
		animation_block__node_scale_flag_data_array,
		"animation_block | node scale flag data* array",
		2,
		"s_animation_block__node_scale_flag_data_array",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "value" },
		{ _field_terminator }
	};

	TAG_ARRAY(
		animation_block__node_rotation_flag_data_array,
		"animation_block | node rotation flag data* array",
		2,
		"s_animation_block__node_rotation_flag_data_array",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "value" },
		{ _field_terminator }
	};

	TAG_ARRAY(
		animation_block__node_trans_flag_data_array,
		"animation_block | node trans. flag data* array",
		2,
		"s_animation_block__node_trans_flag_data_array",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "value" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_node_block,
		"animation_graph_node_block",
		64,
		"s_animation_graph_node_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "next sibling node index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_graph_node_block },
		{ _field_short_block_index, "first child node index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_graph_node_block },
		{ _field_short_block_index, "parent node index", FIELD_FLAG_READ_ONLY, &blofeld::halo1::animation_graph_node_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_flags, "Node joint flags", &blofeld::halo1::unnamed_enum$11 },
		{ _field_real_vector_3d, "base vector", FIELD_FLAG_READ_ONLY },
		{ _field_real, "vector range", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$11)
	{
		"ball-socket",
		"hinge",
		"no movement"
	};
	STRING_LIST(unnamed_enum$11, unnamed_enum$11_strings, _countof(unnamed_enum$11_strings));

	TAG_BLOCK(
		animation_graph_sound_reference_block,
		"animation_graph_sound_reference_block",
		257,
		"s_animation_graph_sound_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	TAG_REFERENCE(sound_reference, SOUND_TAG);

	TAG_BLOCK(
		animation_graph_first_person_weapon_animations_block,
		"animation_graph_first_person_weapon_animations_block",
		1,
		"s_animation_graph_first_person_weapon_animations_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_block, "animations", &blofeld::halo1::first_person_weapon_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		first_person_weapon_block,
		"first_person_weapon_block",
		28,
		"s_first_person_weapon_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		unit_damage_animations,
		"unit_damage_animations",
		176,
		"s_unit_damage_animations",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", FIELD_FLAG_INDEX, &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		device_animations,
		"device_animations",
		1,
		"s_device_animations",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_block, "animations", &blofeld::halo1::device_animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		device_animation_block,
		"device_animation_block",
		2,
		"s_device_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_vehicle_animations_block,
		"animation_graph_vehicle_animations_block",
		1,
		"s_animation_graph_vehicle_animations_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("steering screen", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "right yaw per frame" },
		{ _field_angle, "left yaw per frame" },
		{ _field_short_integer, "right frame count" },
		{ _field_short_integer, "left frame count" },
		{ _field_angle, "down pitch per frame" },
		{ _field_angle, "up pitch per frame" },
		{ _field_short_integer, "down pitch frame count" },
		{ _field_short_integer, "up pitch frame count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 68),
		{ _field_block, "animations", &blofeld::halo1::vehicle_animation_block },
		{ _field_block, "suspension animations", &blofeld::halo1::suspension_animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		suspension_animation_block,
		"suspension_animation_block",
		8,
		"s_suspension_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "mass point index" },
		{ _field_short_block_index, "animation", FIELD_FLAG_INDEX, &blofeld::halo1::animation_block },
		{ _field_real, "full extension ground_depth" },
		{ _field_real, "full compression ground_depth" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	TAG_BLOCK(
		vehicle_animation_block,
		"vehicle_animation_block",
		8,
		"s_vehicle_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_weapon_animations_block,
		"animation_graph_weapon_animations_block",
		1,
		"s_animation_graph_weapon_animations_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_block, "animations", &blofeld::halo1::weapon_animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		weapon_animation_block,
		"weapon_animation_block",
		11,
		"s_weapon_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_unit_seat_block,
		"animation_graph_unit_seat_block",
		32,
		"s_animation_graph_unit_seat_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "label", FIELD_FLAG_INDEX },
		FIELD_EXPLANATION_EX("looking screen bounds", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "right yaw per frame" },
		{ _field_angle, "left yaw per frame" },
		{ _field_short_integer, "right frame count" },
		{ _field_short_integer, "left frame count" },
		{ _field_angle, "down pitch per frame" },
		{ _field_angle, "up pitch per frame" },
		{ _field_short_integer, "down pitch frame count" },
		{ _field_short_integer, "up pitch frame count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_block, "animations", &blofeld::halo1::unit_seat_animation_block },
		{ _field_block, "ik points", &blofeld::halo1::animation_graph_unit_seat_ik_point },
		{ _field_block, "weapons", &blofeld::halo1::animation_graph_weapon_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_weapon_block,
		"animation_graph_weapon_block",
		16,
		"s_animation_graph_weapon_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_string, "grip marker", "the marker name on the weapon to which the hand is attached (leave blank to use origin)" },
		{ _field_string, "hand marker", "the marker name on the unit to which the weapon is attached" },
		FIELD_EXPLANATION_EX("aiming screen bounds", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "right yaw per frame" },
		{ _field_angle, "left yaw per frame" },
		{ _field_short_integer, "right frame count" },
		{ _field_short_integer, "left frame count" },
		{ _field_angle, "down pitch per frame" },
		{ _field_angle, "up pitch per frame" },
		{ _field_short_integer, "down pitch frame count" },
		{ _field_short_integer, "up pitch frame count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "animations", &blofeld::halo1::weapon_class_animation_block },
		{ _field_block, "ik points", &blofeld::halo1::animation_graph_unit_seat_ik_point },
		{ _field_block, "weapon types", &blofeld::halo1::animation_graph_weapon_type_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_weapon_type_block,
		"animation_graph_weapon_type_block",
		16,
		"s_animation_graph_weapon_type_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "label", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_block, "animations", &blofeld::halo1::weapon_type_animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		weapon_type_animation_block,
		"weapon_type_animation_block",
		10,
		"s_weapon_type_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_unit_seat_ik_point,
		"animation_graph_unit_seat_ik_point",
		4,
		"s_animation_graph_unit_seat_ik_point",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "marker", "the marker name on the object being attached" },
		{ _field_string, "attach to marker", "the marker name object (weapon, vehicle, etc.) the above marker is being attached to" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		weapon_class_animation_block,
		"weapon_class_animation_block",
		55,
		"s_weapon_class_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		unit_seat_animation_block,
		"unit_seat_animation_block",
		30,
		"s_unit_seat_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		animation_graph_object_overlay,
		"animation_graph_object_overlay",
		4,
		"s_animation_graph_object_overlay",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "animation", &blofeld::halo1::animation_block },
		{ _field_short_enum, "function", &blofeld::halo1::unnamed_enum$8 },
		{ _field_short_enum, "function controls", &blofeld::halo1::unnamed_enum$9 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$8)
	{
		"A out",
		"B out",
		"C out",
		"D out"
	};
	STRING_LIST(unnamed_enum$8, unnamed_enum$8_strings, _countof(unnamed_enum$8_strings));

	STRINGS(unnamed_enum$9)
	{
		"frame",
		"scale"
	};
	STRING_LIST(unnamed_enum$9, unnamed_enum$9_strings, _countof(unnamed_enum$9_strings));


	TAG_GROUP(
		bitmap_group,
		BITMAP_TAG,
		nullptr,
		INVALID_TAG,
		bitmap);

	TAG_BLOCK(
		bitmap,
		"bitmap_group_block",
		1,
		"s_bitmap",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_custom, "value" },
		FIELD_EXPLANATION_EX("type", nullptr, FIELD_FLAG_NONE, "Type controls bitmap \'geometry\'. All dimensions must be a power of two except for SPRITES and INTERFACE BITMAPS:\n\n* 2D TEXTURES: Ordinary, 2D textures will be generated.\n* 3D TEXTURES: Volume textures will be generated from each sequence of 2D texture \'slices\'.\n* CUBE MAPS: Cube maps will be generated from each consecutive set of six 2D textures in each sequence, all faces of a cube map must be square and the same size.\n* SPRITES: Sprite texture pages will be generated.\n* INTERFACE BITMAPS: Similar to 2D TEXTURES, but without mipmaps and without the power of two restriction."),
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$12 },
		FIELD_EXPLANATION_EX("format", nullptr, FIELD_FLAG_NONE, "Format controls how pixels will be stored internally:\n\n* COMPRESSED WITH COLOR-KEY TRANSPARENCY: DXT1 compression, uses 4 bits per pixel. 4x4 blocks of pixels are reduced to 2 colors and interpolated, alpha channel uses color-key transparency instead of alpha from the plate (all zero-alpha pixels also have zero-color).\n* COMPRESSED WITH EXPLICIT ALPHA: DXT2/3 compression, uses 8 bits per pixel. Same as DXT1 without the color key transparency, alpha channel uses alpha from plate quantized down to 4 bits per pixel.\n* COMPRESSED WITH INTERPOLATED ALPHA: DXT4/5 compression, uses 8 bits per pixel. Same as DXT2/3, except alpha is smoother. Better for smooth alpha gradients, worse for noisy alpha.\n* 16-BIT COLOR: Uses 16 bits per pixel. Depending on the alpha channel, bitmaps are quantized to either r5g6b5 (no alpha), a1r5g5b5 (1-bit alpha), or a4r4g4b4 (>1-bit alpha).\n* 32-BIT COLOR: Uses 32 bits per pixel. Very high quality, can have alpha at no added cost. This format takes up the most memory, however. Bitmap formats are x8r8g8b8 and a8r8g8b.\n* MONOCHROME: Uses either 8 or 16 bits per pixel. Bitmap formats are a8 (alpha), y8 (intensity), ay8 (combined alpha-intensity) and a8y8 (separate alpha-intensity).\n\nNote: Height maps (a.k.a. bump maps) should use 32-bit color; this is internally converted to a palettized format which takes less memory."),
		{ _field_short_enum, "format", &blofeld::halo1::unnamed_enum$13 },
		FIELD_EXPLANATION_EX("usage", nullptr, FIELD_FLAG_NONE, "Usage controls how mipmaps are generated:\n\n* ALPHA BLEND: Pixels with zero alpha are ignored in mipmaps, to prevent bleeding the transparent color.\n* DEFAULT: Downsampling works normally, as in Photoshop.\n* HEIGHT MAP: The bitmap (normally grayscale) is a height map which gets converted to a bump map. Uses <bump height> below. Alpha is passed through unmodified.\n* DETAIL MAP: Mipmap color fades to gray, controlled by <detail fade factor> below. Alpha fades to white.\n* LIGHT MAP: Generates no mipmaps. Do not use!\n* VECTOR MAP: Used mostly for special effects; pixels are treated as XYZ vectors and normalized after downsampling. Alpha is passed through unmodified."),
		{ _field_short_enum, "usage", &blofeld::halo1::unnamed_enum$14 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$15 },
		FIELD_EXPLANATION_EX("post-processing", nullptr, FIELD_FLAG_NONE, "These properties control how mipmaps are post-processed."),
		{ _field_real_fraction, "detail fade factor", "0 means fade to gray by last mipmap, 1 means fade to gray by first mipmap", nullptr, "[0,1]" },
		{ _field_real_fraction, "sharpen amount", "sharpens mipmap after downsampling", nullptr, "[0,1]" },
		{ _field_real_fraction, "bump height", "the apparent height of the bump map above the triangle it is textured onto, in texture repeats (i.e., 1.0 would be as high as the texture is wide)", "repeats" },
		FIELD_EXPLANATION_EX("sprite processing", nullptr, FIELD_FLAG_NONE, "When creating a sprite group, specify the number and size of textures that the group is allowed to occupy. During importing, you\'ll receive feedback about how well the alloted space was used."),
		{ _field_short_enum, "sprite budget size", &blofeld::halo1::unnamed_enum$16 },
		{ _field_short_integer, "sprite budget count" },
		FIELD_EXPLANATION_EX("color plate", nullptr, FIELD_FLAG_NONE, "The original TIFF file used to import the bitmap group."),
		{ _field_short_integer, "color plate width", nullptr, "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "color plate height", nullptr, "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_data, "compressed color plate data", FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION_EX("processed pixel data", nullptr, FIELD_FLAG_NONE, "Pixel data after being processed by the tool."),
		{ _field_data, "processed pixel data", FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION_EX("miscellaneous", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "blur filter size", "blurs the bitmap before generating mipmaps", nullptr, "[0,10] pixels" },
		{ _field_real, "alpha bias", "affects alpha mipmap generation", nullptr, "[-1,1]" },
		{ _field_short_integer, "mipmap count", "0 defaults to all levels", "levels" },
		FIELD_EXPLANATION_EX("...more sprite processing", nullptr, FIELD_FLAG_NONE, "Sprite usage controls the background color of sprite plates."),
		{ _field_short_enum, "sprite usage", &blofeld::halo1::unnamed_enum$17 },
		{ _field_short_integer, "sprite spacing", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "sequences", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bitmap_group_sequence_block },
		{ _field_block, "bitmaps", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bitmap_data_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$12)
	{
		"2D textures",
		"3D textures",
		"cube maps",
		"sprites",
		"interface bitmaps"
	};
	STRING_LIST(unnamed_enum$12, unnamed_enum$12_strings, _countof(unnamed_enum$12_strings));

	STRINGS(unnamed_enum$13)
	{
		"compressed with color-key transparency",
		"compressed with explicit alpha",
		"compressed with interpolated alpha",
		"16-bit color",
		"32-bit color",
		"monochrome"
	};
	STRING_LIST(unnamed_enum$13, unnamed_enum$13_strings, _countof(unnamed_enum$13_strings));

	STRINGS(unnamed_enum$14)
	{
		"alpha-blend",
		"default",
		"height map",
		"detail map",
		"light map",
		"vector map"
	};
	STRING_LIST(unnamed_enum$14, unnamed_enum$14_strings, _countof(unnamed_enum$14_strings));

	STRINGS(unnamed_enum$15)
	{
		"enable diffusion dithering",
		"disable height map compression",
		"uniform sprite sequences",
		"filthy sprite bug fix"
	};
	STRING_LIST(unnamed_enum$15, unnamed_enum$15_strings, _countof(unnamed_enum$15_strings));

	STRINGS(unnamed_enum$16)
	{
		"32x32",
		"64x64",
		"128x128",
		"256x256",
		"512x512"
	};
	STRING_LIST(unnamed_enum$16, unnamed_enum$16_strings, _countof(unnamed_enum$16_strings));

	STRINGS(unnamed_enum$17)
	{
		"blend/add/subtract/max",
		"multiply/min",
		"double multiply"
	};
	STRING_LIST(unnamed_enum$17, unnamed_enum$17_strings, _countof(unnamed_enum$17_strings));

	TAG_BLOCK(
		bitmap_data_block,
		"bitmap_data_block",
		2048,
		"s_bitmap_data_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag, "signature", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "width", nullptr, "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "height", nullptr, "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "depth", "depth is 1 for 2D textures and cube maps", "pixels", FIELD_FLAG_READ_ONLY },
		{ _field_short_enum, "type", "determines bitmap 'geometry'", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$18 },
		{ _field_short_enum, "format", "determines how pixels are represented internally", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$19 },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$20 },
		{ _field_point_2d, "registration point", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "mipmap count", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "pixels offset", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$18)
	{
		"2D texture",
		"3D texture",
		"cube map",
		"white"
	};
	STRING_LIST(unnamed_enum$18, unnamed_enum$18_strings, _countof(unnamed_enum$18_strings));

	STRINGS(unnamed_enum$19)
	{
		"a8",
		"y8",
		"ay8",
		"a8y8",
		"unused1",
		"unused2",
		"r5g6b5",
		"unused3",
		"a1r5g5b5",
		"a4r4g4b4",
		"x8r8g8b8",
		"a8r8g8b8",
		"unused4",
		"unused5",
		"dxt1",
		"dxt3",
		"dxt5",
		"p8-bump"
	};
	STRING_LIST(unnamed_enum$19, unnamed_enum$19_strings, _countof(unnamed_enum$19_strings));

	STRINGS(unnamed_enum$20)
	{
		"power of two dimensions",
		"compressed",
		"palettized",
		"swizzled",
		"linear",
		"v16u16"
	};
	STRING_LIST(unnamed_enum$20, unnamed_enum$20_strings, _countof(unnamed_enum$20_strings));

	TAG_BLOCK(
		bitmap_group_sequence_block,
		"bitmap_group_sequence_block",
		256,
		"s_bitmap_group_sequence_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_short_integer, "first bitmap index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "bitmap count", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_block, "sprites", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bitmap_group_sprite_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		bitmap_group_sprite_block,
		"bitmap_group_sprite_block",
		64,
		"s_bitmap_group_sprite_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "bitmap index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "left", FIELD_FLAG_READ_ONLY },
		{ _field_real, "right", FIELD_FLAG_READ_ONLY },
		{ _field_real, "top", FIELD_FLAG_READ_ONLY },
		{ _field_real, "bottom", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_2d, "registration point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};


	TAG_GROUP(
		color_table_group,
		COLOR_TABLE_TAG,
		nullptr,
		INVALID_TAG,
		color_table);

	TAG_BLOCK(
		color_table,
		"color_table_group_block",
		1,
		"s_color_table",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "colors", &blofeld::halo1::color_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		color_block,
		"color_block",
		512,
		"s_color_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_argb_color, "color" },
		{ _field_terminator }
	};


	TAG_GROUP(
		string_list_group,
		STRING_LIST_TAG,
		nullptr,
		INVALID_TAG,
		string_list);

	TAG_BLOCK(
		string_list,
		"string_list_group_block",
		1,
		"s_string_list",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "string references", &blofeld::halo1::string_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(
		string_reference,
		"string reference",
		800,
		"s_string_reference",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_data, "string" },
		{ _field_terminator }
	};


	TAG_GROUP(
		unicode_string_list_group,
		UNICODE_STRING_LIST_TAG,
		nullptr,
		INVALID_TAG,
		unicode_string_list);

	TAG_BLOCK(
		unicode_string_list,
		"unicode_string_list_group_block",
		1,
		"s_unicode_string_list",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "string references", &blofeld::halo1::string_reference$2 },
		{ _field_terminator }
	};

	TAG_BLOCK(
		string_reference$2,
		"string reference",
		800,
		"s_string_reference$2",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_data, "string" },
		{ _field_terminator }
	};


	TAG_GROUP(
		font_group,
		FONT_TAG,
		nullptr,
		INVALID_TAG,
		font);

	TAG_BLOCK(
		font,
		"font_group_block",
		1,
		"s_font",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "flags" },
		{ _field_short_integer, "ascending height" },
		{ _field_short_integer, "decending height" },
		{ _field_short_integer, "leading height" },
		{ _field_short_integer, "leadin width" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_block, "character tables", &blofeld::halo1::font_character_tables },
		{ _field_tag_reference, "bold", &blofeld::halo1::font_reference },
		{ _field_tag_reference, "italic", &blofeld::halo1::font_reference },
		{ _field_tag_reference, "condense", &blofeld::halo1::font_reference },
		{ _field_tag_reference, "underline", &blofeld::halo1::font_reference },
		{ _field_block, "characters", &blofeld::halo1::character },
		{ _field_data, "pixels" },
		{ _field_terminator }
	};

	TAG_REFERENCE(font_reference, FONT_TAG);

	TAG_BLOCK(
		character,
		"character",
		32000,
		"s_character",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "character", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "character width" },
		{ _field_short_integer, "bitmap width", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "bitmap height", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "bitmap origin x" },
		{ _field_short_integer, "bitmap origin y" },
		{ _field_short_integer, "hardware character index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "pixels offset", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		font_character_tables,
		"font_character_tables",
		256,
		"s_font_character_tables",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "character table", &blofeld::halo1::font_character_table },
		{ _field_terminator }
	};

	TAG_BLOCK(
		font_character_table,
		"font_character_table",
		256,
		"s_font_character_table",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "character index", &blofeld::halo1::character },
		{ _field_terminator }
	};


	TAG_GROUP(
		physics_group,
		PHYSICS_TAG,
		nullptr,
		INVALID_TAG,
		physics);

	TAG_BLOCK(
		physics,
		"physics_group_block",
		1,
		"s_physics",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real, "radius", "positive uses old inferior physics, negative uses new improved physics" },
		{ _field_real_fraction, "moment scale" },
		{ _field_real, "mass" },
		{ _field_real_point_3d, "center of mass", FIELD_FLAG_READ_ONLY },
		{ _field_real, "density" },
		{ _field_real, "gravity scale" },
		{ _field_real, "ground friction" },
		{ _field_real, "ground depth" },
		{ _field_real_fraction, "ground damp fraction" },
		{ _field_real, "ground normal k1" },
		{ _field_real, "ground normal k0" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "water friction" },
		{ _field_real, "water depth" },
		{ _field_real, "water density" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_fraction, "air friction" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "xx moment" },
		{ _field_real, "yy moment" },
		{ _field_real, "zz moment" },
		{ _field_block, "inertial matrix and inverse", FIELD_FLAG_READ_ONLY, &blofeld::halo1::inertial_matrix_block },
		{ _field_block, "powered mass points", &blofeld::halo1::powered_mass_point_block },
		{ _field_block, "mass points", &blofeld::halo1::mass_point_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		mass_point_block,
		"mass_point_block",
		32,
		"s_mass_point_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_block_index, "powered mass point", &blofeld::halo1::powered_mass_point_block },
		{ _field_short_integer, "model node", FIELD_FLAG_READ_ONLY },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$34 },
		{ _field_real, "relative mass" },
		{ _field_real, "mass", FIELD_FLAG_READ_ONLY },
		{ _field_real, "relative density" },
		{ _field_real, "density", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "position" },
		{ _field_real_vector_3d, "forward" },
		{ _field_real_vector_3d, "up" },
		{ _field_short_enum, "friction type", &blofeld::halo1::unnamed_enum$35 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "friction parallel scale" },
		{ _field_real, "friction perpendicular scale" },
		{ _field_real, "radius" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$34)
	{
		"metallic"
	};
	STRING_LIST(unnamed_enum$34, unnamed_enum$34_strings, _countof(unnamed_enum$34_strings));

	STRINGS(unnamed_enum$35)
	{
		"point",
		"forward",
		"left",
		"up"
	};
	STRING_LIST(unnamed_enum$35, unnamed_enum$35_strings, _countof(unnamed_enum$35_strings));

	TAG_BLOCK(
		powered_mass_point_block,
		"powered_mass_point_block",
		32,
		"s_powered_mass_point_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$33 },
		{ _field_real, "antigrav strength" },
		{ _field_real, "antigrav offset" },
		{ _field_real, "antigrav height" },
		{ _field_real, "antigrav damp fraction" },
		{ _field_real, "antigrav normal k1" },
		{ _field_real, "antigrav normal k0" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 68),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$33)
	{
		"ground friction",
		"water friction",
		"air friction",
		"water lift",
		"air lift",
		"thrust",
		"antigrav"
	};
	STRING_LIST(unnamed_enum$33, unnamed_enum$33_strings, _countof(unnamed_enum$33_strings));

	TAG_BLOCK(
		inertial_matrix_block,
		"inertial_matrix_block",
		2,
		"s_inertial_matrix_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_vector_3d, "yy+zz    -xy     -zx" },
		{ _field_real_vector_3d, "-xy    zz+xx    -yz" },
		{ _field_real_vector_3d, "-zx     -yz    xx+yy" },
		{ _field_terminator }
	};


	TAG_GROUP(
		object_group,
		OBJECT_TAG,
		nullptr,
		INVALID_TAG,
		object);

	TAG_BLOCK(
		object,
		"object_group_block",
		1,
		"s_object",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$36 },
		{ _field_real, "bounding radius", nullptr, "world units" },
		{ _field_real_point_3d, "bounding offset" },
		{ _field_real_point_3d, "origin offset" },
		{ _field_real, "acceleration scale", "marine 1.0, grunt 1.4, elite 0.9, hunter 0.5, etc.", nullptr, "[0,+inf]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_tag_reference, "model", &blofeld::halo1::gbxmodel_reference },
		{ _field_tag_reference, "animation graph", &blofeld::halo1::model_animations_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_tag_reference, "collision model", &blofeld::halo1::model_collision_geometry_reference },
		{ _field_tag_reference, "physics", &blofeld::halo1::physics_reference },
		{ _field_tag_reference, "modifier shader", &blofeld::halo1::shader_reference },
		{ _field_tag_reference, "creation effect", &blofeld::halo1::effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_real, "render bounding radius", "if set, this radius is used to determine if the object is visible. set it for the pelican.", "world units" },
		FIELD_EXPLANATION_EX("export to functions", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$37 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$37 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$37 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$37 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_short_integer, "hud text message index" },
		{ _field_short_integer, "forced shader permuation index" },
		{ _field_block, "attachments", &blofeld::halo1::object_attachment_block },
		{ _field_block, "widgets", &blofeld::halo1::object_widget_block },
		{ _field_block, "functions", &blofeld::halo1::object_function_block },
		{ _field_block, "change colors", &blofeld::halo1::object_change_colors },
		{ _field_block, "predicted resources", FIELD_FLAG_READ_ONLY, &blofeld::halo1::predicted_resource_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$36)
	{
		"does not cast shadow",
		"transparent self-occlusion",
		"brighter than it should be",
		"not a pathfinding obstacle"
	};
	STRING_LIST(unnamed_enum$36, unnamed_enum$36_strings, _countof(unnamed_enum$36_strings));

	TAG_REFERENCE(gbxmodel_reference, GBXMODEL_TAG);

	TAG_REFERENCE(model_animations_reference, MODEL_ANIMATIONS_TAG);

	TAG_REFERENCE(model_collision_geometry_reference, MODEL_COLLISION_GEOMETRY_TAG);

	TAG_REFERENCE(physics_reference, PHYSICS_TAG);

	TAG_REFERENCE(effect_reference, EFFECT_TAG);

	STRINGS(unnamed_enum$37)
	{
		"none",
		"body vitality",
		"shield vitality",
		"recent body damage",
		"recent shield damage",
		"random constant",
		"umbrella shield vitality",
		"shield stun",
		"recent umbrella shield vitality",
		"umbrella shield stun",
		"region #00 damage",
		"region #01 damage",
		"region #02 damage",
		"region #03 damage",
		"region #04 damage",
		"region #05 damage",
		"region #06 damage",
		"region #07 damage",
		"alive",
		"compass"
	};
	STRING_LIST(unnamed_enum$37, unnamed_enum$37_strings, _countof(unnamed_enum$37_strings));

	TAG_BLOCK(
		predicted_resource_block,
		"predicted_resource_block",
		1024,
		"s_predicted_resource_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$46 },
		{ _field_short_integer, "resource index" },
		{ _field_long_integer, "tag index" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$46)
	{
		"bitmap",
		"sound"
	};
	STRING_LIST(unnamed_enum$46, unnamed_enum$46_strings, _countof(unnamed_enum$46_strings));

	TAG_BLOCK(
		object_change_colors,
		"object_change_colors",
		4,
		"s_object_change_colors",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "darken by", &blofeld::halo1::unnamed_enum$41 },
		{ _field_short_enum, "scale by", &blofeld::halo1::unnamed_enum$41 },
		{ _field_long_flags, "scale flags", &blofeld::halo1::unnamed_enum$45 },
		{ _field_real_rgb_color, "color lower bound" },
		{ _field_real_rgb_color, "color upper bound" },
		{ _field_block, "permutations", &blofeld::halo1::object_change_color_permutations },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$41)
	{
		"none",
		"A in",
		"B in",
		"C in",
		"D in",
		"A out",
		"B out",
		"C out",
		"D out"
	};
	STRING_LIST(unnamed_enum$41, unnamed_enum$41_strings, _countof(unnamed_enum$41_strings));

	STRINGS(unnamed_enum$45)
	{
		"blend in hsv#blends colors in hsv rather than rgb space",
		"...more colors#blends colors through more hues (goes the long way around the color wheel)"
	};
	STRING_LIST(unnamed_enum$45, unnamed_enum$45_strings, _countof(unnamed_enum$45_strings));

	TAG_BLOCK(
		object_change_color_permutations,
		"object_change_color_permutations",
		8,
		"s_object_change_color_permutations",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real, "weight" },
		{ _field_real_rgb_color, "color lower bound" },
		{ _field_real_rgb_color, "color upper bound" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		object_function_block,
		"object_function_block",
		4,
		"s_object_function_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$40 },
		{ _field_real, "period", "this is the period for the above function (lower values make the function oscillate quickly, higher values make it oscillate slowly)", "seconds" },
		{ _field_short_enum, "scale period by", "multiply this function by the above period", &blofeld::halo1::unnamed_enum$41 },
		{ _field_short_enum, "function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_short_enum, "scale function by", "multiply this function by the result of the above function", &blofeld::halo1::unnamed_enum$41 },
		{ _field_short_enum, "wobble function", "the curve used for the wobble", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "wobble period", "the length of time it takes for the magnitude of this function to complete a wobble", "seconds" },
		{ _field_real, "wobble magnitude", "the amount of random wobble in the magnitude", "percent" },
		{ _field_real_fraction, "square wave threshold", "if non-zero, all values above the square wave threshold are snapped to 1.0, and all values below it are snapped to 0.0 to create a square wave." },
		{ _field_short_integer, "step count", "the number of discrete values to snap to (e.g., a step count of 5 would snap the function to 0.00,0.25,0.50,0.75 or 1.00)" },
		{ _field_short_enum, "map to", &blofeld::halo1::unnamed_enum$43 },
		{ _field_short_integer, "sawtooth count", "the number of times this function should repeat (e.g., a sawtooth count of 5 would give the function a value of 1.0 at each of 0.25,0.50,0.75 as well as at 1.0" },
		{ _field_short_enum, "add", "add this function to the final result of all of the above math", &blofeld::halo1::unnamed_enum$41 },
		{ _field_short_enum, "scale result by", "multiply this function (from a weapon, vehicle, etc.) final result of all of the above math", &blofeld::halo1::unnamed_enum$41 },
		{ _field_short_enum, "bounds mode", "controls how the bounds, below, are used", &blofeld::halo1::unnamed_enum$44 },
		{ _field_fraction_bounds, "bounds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "turn off with", "if the specified function is off, so is this function", &blofeld::halo1::object_function_block },
		{ _field_real, "scale by", "applied before clip, ignored if zero" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 252),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_string, "usage" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$40)
	{
		"invert#result of function is one minus actual result",
		"additive",
		"always active#function does not deactivate when at or below lower bound"
	};
	STRING_LIST(unnamed_enum$40, unnamed_enum$40_strings, _countof(unnamed_enum$40_strings));

	STRINGS(unnamed_enum$42)
	{
		"one",
		"zero",
		"cosine",
		"cosine (variable period)",
		"diagonal wave",
		"diagonal wave (variable period)",
		"slide",
		"slide (variable period)",
		"noise",
		"jitter",
		"wander",
		"spark"
	};
	STRING_LIST(unnamed_enum$42, unnamed_enum$42_strings, _countof(unnamed_enum$42_strings));

	STRINGS(unnamed_enum$43)
	{
		"linear",
		"early",
		"very early",
		"late",
		"very late",
		"cosine"
	};
	STRING_LIST(unnamed_enum$43, unnamed_enum$43_strings, _countof(unnamed_enum$43_strings));

	STRINGS(unnamed_enum$44)
	{
		"clip",
		"clip and normalize",
		"scale to fit"
	};
	STRING_LIST(unnamed_enum$44, unnamed_enum$44_strings, _countof(unnamed_enum$44_strings));

	TAG_BLOCK(
		object_widget_block,
		"object_widget_block",
		4,
		"s_object_widget_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &blofeld::halo1::flag_antenna_glow_light_volume_lightning_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	TAG_REFERENCE_GROUP(flag_antenna_glow_light_volume_lightning_reference)
	{
		FLAG_TAG,
		ANTENNA_TAG,
		GLOW_TAG,
		LIGHT_VOLUME_TAG,
		LIGHTNING_TAG,
		INVALID_TAG
	};

	TAG_BLOCK(
		object_attachment_block,
		"object_attachment_block",
		8,
		"s_object_attachment_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "type", FIELD_FLAG_INDEX, &blofeld::halo1::light_light_volume_contrail_particle_system_effect_sound_looping_reference },
		{ _field_string, "marker" },
		{ _field_short_enum, "primary scale", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "secondary scale", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "change color", &blofeld::halo1::unnamed_enum$39 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	TAG_REFERENCE_GROUP(light_light_volume_contrail_particle_system_effect_sound_looping_reference)
	{
		LIGHT_TAG,
		LIGHT_VOLUME_TAG,
		CONTRAIL_TAG,
		PARTICLE_SYSTEM_TAG,
		EFFECT_TAG,
		SOUND_LOOPING_TAG,
		INVALID_TAG
	};

	STRINGS(unnamed_enum$38)
	{
		"none",
		"A out",
		"B out",
		"C out",
		"D out"
	};
	STRING_LIST(unnamed_enum$38, unnamed_enum$38_strings, _countof(unnamed_enum$38_strings));

	STRINGS(unnamed_enum$39)
	{
		"none",
		"A",
		"B",
		"C",
		"D"
	};
	STRING_LIST(unnamed_enum$39, unnamed_enum$39_strings, _countof(unnamed_enum$39_strings));


	TAG_GROUP(
		contrail_group,
		CONTRAIL_TAG,
		nullptr,
		INVALID_TAG,
		contrail);

	TAG_BLOCK(
		contrail,
		"contrail_group_block",
		1,
		"s_contrail",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$47 },
		{ _field_word_flags, "scale flags", "these flags determine which fields are scaled by the contrail density", &blofeld::halo1::unnamed_enum$48 },
		FIELD_EXPLANATION_EX("point creation", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "point generation rate", "this many points are generated per second", "points per second" },
		{ _field_real_bounds, "point velocity", "velocity added to each point's initial velocity", "world units per second" },
		{ _field_angle, "point velocity cone angle", "initial velocity is inside the cone defined by the marker's forward vector and this angle", "degrees" },
		{ _field_real_fraction, "inherited velocity fraction", "fraction of parent object's velocity that is inherited by contrail points." },
		FIELD_EXPLANATION_EX("rendering", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "render type", "this specifies how the contrail is oriented in space", &blofeld::halo1::unnamed_enum$49 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "texture repeats u", "texture repeats per contrail segment" },
		{ _field_real, "texture repeats v", "texture repeats across contrail width" },
		{ _field_real, "texture animation u", "the texture along the contrail is animated by this value", "repeats per second" },
		{ _field_real, "texture animation v", "the texture across the contrail is animated by this value", "repeats per second" },
		{ _field_real, "animation rate", nullptr, "frames per second" },
		{ _field_tag_reference, "bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "first sequence index" },
		{ _field_short_integer, "sequence count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_word_flags, "shader flags", &blofeld::halo1::unnamed_enum$50 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_word_flags, "map flags", &blofeld::halo1::unnamed_enum$53 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("Secondary Map", nullptr, FIELD_FLAG_NONE, "Optional multitextured second map"),
		{ _field_tag_reference, "bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$54 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$53 },
		{ _field_short_enum, "u-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "u-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "u-animation phase" },
		{ _field_real, "u-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "v-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "v-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "v-animation phase" },
		{ _field_real, "v-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "rotation-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "rotation-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "rotation-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "rotation-animation phase" },
		{ _field_real, "rotation-animation scale", "0 defaults to 360", "degrees" },
		{ _field_real_point_2d, "rotation-animation center" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "zsprite radius scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_block, "point states", &blofeld::halo1::contrail_point_states_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$47)
	{
		"first point unfaded",
		"last point unfaded",
		"points start pinned to media",
		"points start pinned to ground",
		"points always pinned to media",
		"points always pinned to ground",
		"edge effect fades slowly"
	};
	STRING_LIST(unnamed_enum$47, unnamed_enum$47_strings, _countof(unnamed_enum$47_strings));

	STRINGS(unnamed_enum$48)
	{
		"point generation rate",
		"point velocity",
		"point velocity delta",
		"point velocity cone angle",
		"inherited velocity fraction",
		"sequence animation rate",
		"texture scale u",
		"texture scale v",
		"texture animation u",
		"texture animation v"
	};
	STRING_LIST(unnamed_enum$48, unnamed_enum$48_strings, _countof(unnamed_enum$48_strings));

	STRINGS(unnamed_enum$49)
	{
		"vertical orientation",
		"horizontal orientation",
		"media mapped",
		"ground mapped",
		"viewer facing",
		"double-marker linked"
	};
	STRING_LIST(unnamed_enum$49, unnamed_enum$49_strings, _countof(unnamed_enum$49_strings));

	TAG_REFERENCE(bitmap_reference, BITMAP_TAG);

	STRINGS(unnamed_enum$50)
	{
		"sort bias",
		"nonlinear tint",
		"don\'t overdraw fp weapon"
	};
	STRING_LIST(unnamed_enum$50, unnamed_enum$50_strings, _countof(unnamed_enum$50_strings));

	STRINGS(unnamed_enum$51)
	{
		"alpha blend",
		"multiply",
		"double multiply",
		"add",
		"subtract",
		"component min",
		"component max",
		"alpha-multiply add"
	};
	STRING_LIST(unnamed_enum$51, unnamed_enum$51_strings, _countof(unnamed_enum$51_strings));

	STRINGS(unnamed_enum$52)
	{
		"none",
		"fade when perpendicular",
		"fade when parallel"
	};
	STRING_LIST(unnamed_enum$52, unnamed_enum$52_strings, _countof(unnamed_enum$52_strings));

	STRINGS(unnamed_enum$53)
	{
		"unfiltered"
	};
	STRING_LIST(unnamed_enum$53, unnamed_enum$53_strings, _countof(unnamed_enum$53_strings));

	STRINGS(unnamed_enum$54)
	{
		"with primary",
		"with screen space",
		"zsprite"
	};
	STRING_LIST(unnamed_enum$54, unnamed_enum$54_strings, _countof(unnamed_enum$54_strings));

	TAG_BLOCK(
		contrail_point_states_block,
		"contrail_point_states_block",
		16,
		"s_contrail_point_states_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("state timing", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "duration", "the time a point spends in this state", "seconds:seconds" },
		{ _field_real_bounds, "transition duration", "the time a point takes to transition to the next state", "seconds" },
		FIELD_EXPLANATION_EX("point variables", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "physics", &blofeld::halo1::point_physics_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_real, "width", "contrail width at this point", "world units" },
		{ _field_real_argb_color, "color lower bound", "contrail color at this point" },
		{ _field_real_argb_color, "color upper bound", "contrail color at this point" },
		{ _field_long_flags, "scale flags", "these flags determine which fields are scaled by the contrail density", &blofeld::halo1::unnamed_enum$55 },
		{ _field_terminator }
	};

	TAG_REFERENCE(point_physics_reference, POINT_PHYSICS_TAG);

	STRINGS(unnamed_enum$55)
	{
		"duration",
		"duration delta",
		"transition duration",
		"transition duration delta",
		"width",
		"color"
	};
	STRING_LIST(unnamed_enum$55, unnamed_enum$55_strings, _countof(unnamed_enum$55_strings));


	TAG_GROUP(
		light_group,
		LIGHT_TAG,
		nullptr,
		INVALID_TAG,
		light);

	TAG_BLOCK(
		light,
		"light_group_block",
		1,
		"s_light",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$65 },
		FIELD_EXPLANATION_EX("SHAPE", nullptr, FIELD_FLAG_NONE, "the size and shape of the light"),
		{ _field_real, "radius", "the radius where illumination is zero. (lens flare only if this is 0)" },
		{ _field_real_bounds, "radius modifer", "how the radius changes with external scale" },
		{ _field_angle, "falloff angle", "the angle at which the light begins to fade." },
		{ _field_angle, "cutoff angle", "the angle at which the illumination is zero." },
		{ _field_real, "lens flare only radius" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("COLOR", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "interpolation flags", &blofeld::halo1::unnamed_enum$45 },
		{ _field_real_argb_color, "color lower bound" },
		{ _field_real_argb_color, "color upper bound" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("GEL", nullptr, FIELD_FLAG_NONE, "the gel map tints the light per-pixel of cube map"),
		{ _field_tag_reference, "primary cube map", "used for diffuse and specular light", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "texture animation function", "a function to control texture animation", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "texture animation period", "time between repeats", "seconds" },
		{ _field_tag_reference, "secondary cube map", "used for specular light", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "yaw function", "a function to control rotation of the gel in yaw", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "yaw period", "time between repeats", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "roll function", "a function to control rotation of the gel in roll", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "roll period", "time between repeats", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "pitch function", "a function to control rotation of the gel in pitch", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "pitch period", "time between repeats", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("LENS FLARE", nullptr, FIELD_FLAG_NONE, "optional lens flare associated with this light"),
		{ _field_tag_reference, "lens flare", &blofeld::halo1::lens_flare_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("RADIOSITY", nullptr, FIELD_FLAG_NONE, "how the light affects the lightmaps (ignored for dynamic lights)"),
		{ _field_real, "intensity" },
		{ _field_real_rgb_color, "color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("EFFECT PARAMETERS", nullptr, FIELD_FLAG_NONE, "if the light is created by an effect, it will animate itself as follows"),
		{ _field_real, "duration", "the light will last this long when created by an effect", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "falloff function", "the scale of the light will diminish over time according to this function", &blofeld::halo1::unnamed_enum$43 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 92),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$65)
	{
		"dynamic#dynamically illuminate interiors",
		"no specular#for dynamic lights, cast only diffuse light.",
		"don\'t light own object#for dynamic lights, don\'t light the object that the light is attached to.",
		"supersize in first person#for dynamic lights, light every environment surface if this light is on the gun of the current window.",
		"first person flashlight",
		"don\'t fade active camouflage"
	};
	STRING_LIST(unnamed_enum$65, unnamed_enum$65_strings, _countof(unnamed_enum$65_strings));

	TAG_REFERENCE(lens_flare_reference, LENS_FLARE_TAG);


	TAG_GROUP(
		effect_group,
		EFFECT_TAG,
		nullptr,
		INVALID_TAG,
		effect);

	TAG_BLOCK(
		effect,
		"effect_group_block",
		1,
		"s_effect",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$66 },
		{ _field_short_block_index, "loop start event", &blofeld::halo1::effect_event_block },
		{ _field_short_block_index, "loop stop event", &blofeld::halo1::effect_event_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "locations", &blofeld::halo1::effect_locations_block },
		{ _field_block, "events", &blofeld::halo1::effect_event_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$66)
	{
		"deleted when attachment deactivates",
		"required for gameplay (cannot optimize out)"
	};
	STRING_LIST(unnamed_enum$66, unnamed_enum$66_strings, _countof(unnamed_enum$66_strings));

	TAG_BLOCK(
		effect_event_block,
		"effect_event_block",
		32,
		"s_effect_event_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_fraction, "skip fraction", "chance that this event will be skipped entirely" },
		{ _field_real_bounds, "delay bounds", "delay before this event takes place", "seconds" },
		{ _field_real_bounds, "duration bounds", "duration of this event", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_block, "parts", &blofeld::halo1::effect_part_block },
		{ _field_block, "particles", &blofeld::halo1::effect_particles_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		effect_particles_block,
		"effect_particles_block",
		32,
		"s_effect_particles_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "create in", &blofeld::halo1::unnamed_enum$67 },
		{ _field_short_enum, "create in", &blofeld::halo1::unnamed_enum$68 },
		{ _field_short_enum, "create", &blofeld::halo1::unnamed_enum$71 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "location", &blofeld::halo1::effect_locations_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_euler_angles_2d, "relative direction", "particle initial velocity direction relative to the location's forward" },
		{ _field_real_vector_3d, "relative offset", "particle initial position offset relative to the locatin's forward" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_tag_reference, "particle type", FIELD_FLAG_INDEX, &blofeld::halo1::particle_reference },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$72 },
		{ _field_short_enum, "distribution function", "describes how the part creations are distributed over the event duration", &blofeld::halo1::unnamed_enum$73 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer_bounds, "count", "number of particles created" },
		{ _field_real_bounds, "distribution radius", "initial distance from the location's origin", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_bounds, "velocity", "initial velocity along the specified direction", "world units per second" },
		{ _field_angle, "velocity cone angle", "particle initial velocities will be inside the cone defined by this angle and the specified direction", "degrees" },
		{ _field_angle_bounds, "angular velocity", nullptr, "degrees per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_bounds, "radius", "particle radius", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_argb_color, "tint lower bound" },
		{ _field_real_argb_color, "tint upper bound" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("SCALE MODIFIERS", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "A scales values", &blofeld::halo1::unnamed_enum$74 },
		{ _field_long_flags, "B scales values", &blofeld::halo1::unnamed_enum$74 },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$67)
	{
		"any environment",
		"air only",
		"water only",
		"space only"
	};
	STRING_LIST(unnamed_enum$67, unnamed_enum$67_strings, _countof(unnamed_enum$67_strings));

	STRINGS(unnamed_enum$68)
	{
		"either mode",
		"violent mode only",
		"nonviolent mode only"
	};
	STRING_LIST(unnamed_enum$68, unnamed_enum$68_strings, _countof(unnamed_enum$68_strings));

	STRINGS(unnamed_enum$71)
	{
		"independent of camera mode",
		"only in first person",
		"only in third person",
		"in first person if possible"
	};
	STRING_LIST(unnamed_enum$71, unnamed_enum$71_strings, _countof(unnamed_enum$71_strings));

	TAG_REFERENCE(particle_reference, PARTICLE_TAG);

	STRINGS(unnamed_enum$72)
	{
		"stay attached to marker",
		"random initial angle",
		"tint from object color",
		"interpolate tint as HSV",
		"... across the long hue path"
	};
	STRING_LIST(unnamed_enum$72, unnamed_enum$72_strings, _countof(unnamed_enum$72_strings));

	STRINGS(unnamed_enum$73)
	{
		"start",
		"end",
		"constant",
		"buildup",
		"falloff",
		"buildup and falloff"
	};
	STRING_LIST(unnamed_enum$73, unnamed_enum$73_strings, _countof(unnamed_enum$73_strings));

	STRINGS(unnamed_enum$74)
	{
		"velocity",
		"velocity delta",
		"velocity cone angle",
		"angular velocity",
		"angular velocity delta",
		"count",
		"count delta",
		"distribution radius",
		"distribution radius delta",
		"particle radius",
		"particle radius delta",
		"tint"
	};
	STRING_LIST(unnamed_enum$74, unnamed_enum$74_strings, _countof(unnamed_enum$74_strings));

	TAG_BLOCK(
		effect_part_block,
		"effect_part_block",
		32,
		"s_effect_part_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "create in", &blofeld::halo1::unnamed_enum$67 },
		{ _field_short_enum, "create in", &blofeld::halo1::unnamed_enum$68 },
		{ _field_short_block_index, "location", &blofeld::halo1::effect_locations_block },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$69 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "type", FIELD_FLAG_INDEX, &blofeld::halo1::damage_effect_object_particle_system_sound_decal_light_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real_bounds, "velocity bounds", "initial velocity along the location's forward", "world units per second" },
		{ _field_angle, "velocity cone angle", "initial velocity will be inside the cone defined by this angle.", "degrees" },
		{ _field_angle_bounds, "angular velocity bounds", nullptr, "degrees per second" },
		{ _field_real_bounds, "radius modifier bounds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("SCALE MODIFIERS", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "A scales values", &blofeld::halo1::unnamed_enum$70 },
		{ _field_long_flags, "B scales values", &blofeld::halo1::unnamed_enum$70 },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$69)
	{
		"face down regardless of location (decals)"
	};
	STRING_LIST(unnamed_enum$69, unnamed_enum$69_strings, _countof(unnamed_enum$69_strings));

	TAG_REFERENCE_GROUP(damage_effect_object_particle_system_sound_decal_light_reference)
	{
		DAMAGE_EFFECT_TAG,
		OBJECT_TAG,
		PARTICLE_SYSTEM_TAG,
		SOUND_TAG,
		DECAL_TAG,
		LIGHT_TAG,
		INVALID_TAG
	};

	STRINGS(unnamed_enum$70)
	{
		"velocity",
		"velocity delta",
		"velocity cone angle",
		"angular velocity",
		"angular velocity delta",
		"type-specific scale"
	};
	STRING_LIST(unnamed_enum$70, unnamed_enum$70_strings, _countof(unnamed_enum$70_strings));

	TAG_BLOCK(
		effect_locations_block,
		"effect_locations_block",
		32,
		"s_effect_locations_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "marker name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};


	TAG_GROUP(
		particle_group,
		PARTICLE_TAG,
		nullptr,
		INVALID_TAG,
		particle);

	TAG_BLOCK(
		particle,
		"particle_group_block",
		1,
		"s_particle",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$75 },
		{ _field_tag_reference, "bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "physics", &blofeld::halo1::point_physics_reference },
		{ _field_tag_reference, "marty traded his kids for this", &blofeld::halo1::material_effects_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_bounds, "lifespan", nullptr, "seconds" },
		{ _field_real, "fade in time" },
		{ _field_real, "fade out time" },
		{ _field_tag_reference, "collision effect", &blofeld::halo1::sound_effect_reference$2 },
		{ _field_tag_reference, "death effect", &blofeld::halo1::sound_effect_reference$2 },
		{ _field_real, "minimum size", "in the distance, don't get any smaller than this size on the screen", "pixels" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_bounds, "radius animation", "when created, the radius is multiplied by the first number. at the end of the lifetime, the radius is multiplied by the second number." },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_bounds, "animation rate", "rate at which the particle animates", "frames per second" },
		{ _field_real, "contact deterioration", "the decrease in the frame rate caused by a collision" },
		{ _field_real, "fade start size", "begin fading the particle out when it's smaller than this size on the screen", "pixels" },
		{ _field_real, "fade end size", "kill the particle when it's smaller than this size on the screen", "pixels" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "first sequence index", "the index of the first sequence in the bitmap group used by this particle" },
		{ _field_short_integer, "initial sequence count" },
		{ _field_short_integer, "looping sequence count" },
		{ _field_short_integer, "final sequence count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_short_enum, "orientation", &blofeld::halo1::unnamed_enum$76 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_word_flags, "shader flags", &blofeld::halo1::unnamed_enum$50 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_word_flags, "map flags", &blofeld::halo1::unnamed_enum$53 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("Secondary Map", nullptr, FIELD_FLAG_NONE, "Optional multitextured second map"),
		{ _field_tag_reference, "bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$54 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$53 },
		{ _field_short_enum, "u-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "u-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "u-animation phase" },
		{ _field_real, "u-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "v-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "v-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "v-animation phase" },
		{ _field_real, "v-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "rotation-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "rotation-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "rotation-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "rotation-animation phase" },
		{ _field_real, "rotation-animation scale", "0 defaults to 360", "degrees" },
		{ _field_real_point_2d, "rotation-animation center" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "zsprite radius scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$75)
	{
		"can animate backwards",
		"animation stops at rest",
		"animation starts on random frame",
		"animate once per frame",
		"dies at rest",
		"dies on contact with structure",
		"tint from diffuse texture",
		"dies on contact with water",
		"dies on contact with air",
		"self-illuminated#don\'t cast world-lights onto this particle",
		"random horizontal mirroring",
		"random vertical mirroring"
	};
	STRING_LIST(unnamed_enum$75, unnamed_enum$75_strings, _countof(unnamed_enum$75_strings));

	TAG_REFERENCE(material_effects_reference, MATERIAL_EFFECTS_TAG);

	TAG_REFERENCE_GROUP(sound_effect_reference$2)
	{
		SOUND_TAG,
		EFFECT_TAG,
		INVALID_TAG
	};

	STRINGS(unnamed_enum$76)
	{
		"screen facing",
		"parallel to direction",
		"perpendicular to direction"
	};
	STRING_LIST(unnamed_enum$76, unnamed_enum$76_strings, _countof(unnamed_enum$76_strings));


	TAG_GROUP(
		globals_group,
		GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		globals);

	TAG_BLOCK(
		globals,
		"globals_group_block",
		1,
		"s_globals",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 248),
		{ _field_block, "sounds", &blofeld::halo1::sound_block },
		{ _field_block, "camera", &blofeld::halo1::camera_block },
		{ _field_block, "player control", &blofeld::halo1::player_control_block },
		{ _field_block, "difficulty", &blofeld::halo1::difficulty_block },
		{ _field_block, "grenades", &blofeld::halo1::grenades_block },
		{ _field_block, "rasterizer data", &blofeld::halo1::rasterizer_data_block },
		{ _field_block, "interface bitmaps", &blofeld::halo1::interface_tag_references },
		{ _field_block, "weapon list (update _weapon_list enum in game_globals.h)", &blofeld::halo1::cheat_weapons_block },
		{ _field_block, "cheat powerups", &blofeld::halo1::cheat_powerups_block },
		{ _field_block, "multiplayer information", &blofeld::halo1::multiplayer_information_block },
		{ _field_block, "player information", &blofeld::halo1::player_information_block },
		{ _field_block, "first person interface", &blofeld::halo1::first_person_interface_block },
		{ _field_block, "falling damage", &blofeld::halo1::falling_damage_block },
		{ _field_block, "materials", &blofeld::halo1::materials_block },
		{ _field_block, "playlist members", &blofeld::halo1::playlist_autogenerate_choice_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		playlist_autogenerate_choice_block,
		"playlist_autogenerate_choice_block",
		20,
		"s_playlist_autogenerate_choice_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "map name" },
		{ _field_string, "game variant" },
		{ _field_long_integer, "minimum experience" },
		{ _field_long_integer, "maximum experience" },
		{ _field_long_integer, "minimum player count" },
		{ _field_long_integer, "maximum player count" },
		{ _field_long_integer, "rating" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		{ _field_terminator }
	};

	TAG_BLOCK(
		materials_block,
		"materials_block",
		33,
		"s_materials_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 100),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		FIELD_EXPLANATION_EX("vehicle terrain parameters", nullptr, FIELD_FLAG_NONE, "the following fields modify the way a vehicle drives over terrain of this material type."),
		{ _field_real, "ground friction scale", "fraction of original velocity parallel to the ground after one tick" },
		{ _field_real, "ground friction normal k1 scale", "cosine of angle at which friction falls off" },
		{ _field_real, "ground friction normal k0 scale", "cosine of angle at which friction is zero" },
		{ _field_real, "ground depth scale", "depth a point mass rests in the ground" },
		{ _field_real, "ground damp fraction scale", "fraction of original velocity perpendicular to the ground after one tick" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 480),
		FIELD_EXPLANATION_EX("breakable surface parameters", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "maximum vitality" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_tag_reference, "effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "sound", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "particle effects", &blofeld::halo1::breakable_surface_particle_effect_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 60),
		{ _field_tag_reference, "melee hit sound", &blofeld::halo1::sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(
		breakable_surface_particle_effect_block,
		"breakable_surface_particle_effect_block",
		8,
		"s_breakable_surface_particle_effect_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "particle type", FIELD_FLAG_INDEX, &blofeld::halo1::particle_reference$2 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$78 },
		{ _field_real, "density", nullptr, "world units" },
		{ _field_real_bounds, "velocity scale", "scales initial velocity" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_angle_bounds, "angular velocity", nullptr, "degrees per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_bounds, "radius", "particle radius", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_argb_color, "tint lower bound" },
		{ _field_real_argb_color, "tint upper bound" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	TAG_REFERENCE(particle_reference$2, PARTICLE_TAG);

	STRINGS(unnamed_enum$78)
	{
		"interpolate color in hsv",
		"...more colors"
	};
	STRING_LIST(unnamed_enum$78, unnamed_enum$78_strings, _countof(unnamed_enum$78_strings));

	TAG_BLOCK(
		falling_damage_block,
		"falling_damage_block",
		1,
		"s_falling_damage_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_bounds, "harmful falling distance", nullptr, "world units" },
		{ _field_tag_reference, "falling damage", &blofeld::halo1::damage_effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "maximum falling distance", nullptr, "world units" },
		{ _field_tag_reference, "distance damage", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "vehicle environemtn collision damage effect", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "vehicle killed unit damage effect", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "vehicle collision damage", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "flaming death damage", &blofeld::halo1::damage_effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	TAG_REFERENCE(damage_effect_reference, DAMAGE_EFFECT_TAG);

	TAG_BLOCK(
		first_person_interface_block,
		"first_person_interface_block",
		1,
		"s_first_person_interface_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "first person hands", &blofeld::halo1::gbxmodel_reference$3 },
		{ _field_tag_reference, "base bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "shield meter", &blofeld::halo1::meter_reference },
		{ _field_point_2d, "shield meter origin" },
		{ _field_tag_reference, "body meter", &blofeld::halo1::meter_reference },
		{ _field_point_2d, "body meter origin" },
		{ _field_tag_reference, "night-vision OFF->ON effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "night-vision ON->OFF effect", &blofeld::halo1::effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 88),
		{ _field_terminator }
	};

	TAG_REFERENCE(gbxmodel_reference$3, GBXMODEL_TAG);

	TAG_REFERENCE(meter_reference, METER_TAG);

	TAG_BLOCK(
		player_information_block,
		"player_information_block",
		1,
		"s_player_information_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "unit", &blofeld::halo1::unit_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_real, "walking speed", nullptr, "world units per second" },
		{ _field_real, "\"double speed\" multiplier", nullptr, nullptr, "[1.0,+inf]" },
		{ _field_real, "run forward", nullptr, "world units per second" },
		{ _field_real, "run backward", nullptr, "world units per second" },
		{ _field_real, "run sideways", nullptr, "world units per second" },
		{ _field_real, "run acceleration", nullptr, "world units per second squared" },
		{ _field_real, "sneak forward", nullptr, "world units per second" },
		{ _field_real, "sneak backward", nullptr, "world units per second" },
		{ _field_real, "sneak sideways", nullptr, "world units per second" },
		{ _field_real, "sneak acceleration", nullptr, "world units per second squared" },
		{ _field_real, "airborne acceleration", nullptr, "world units per second squared" },
		{ _field_real, "speed multiplier", nullptr, "multiplayer only" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_point_3d, "grenade origin" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "stun movement penalty", "1.0 prevents moving while stunned", nullptr, "[0,1]" },
		{ _field_real, "stun turning penalty", "1.0 prevents turning while stunned", nullptr, "[0,1]" },
		{ _field_real, "stun jumping penalty", "1.0 prevents jumping while stunned", nullptr, "[0,1]" },
		{ _field_real, "minimum stun time", "all stunning damage will last for at least this long", "seconds" },
		{ _field_real, "maximum stun time", "no stunning damage will last for longer than this", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_bounds, "first person idle time", nullptr, "seconds" },
		{ _field_real_fraction, "first person skip fraction", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "coop respawn effect", &blofeld::halo1::effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_terminator }
	};

	TAG_REFERENCE(unit_reference, UNIT_TAG);

	TAG_BLOCK(
		multiplayer_information_block,
		"multiplayer_information_block",
		1,
		"s_multiplayer_information_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "flag", &blofeld::halo1::item_reference },
		{ _field_tag_reference, "unit", &blofeld::halo1::unit_reference },
		{ _field_block, "vehicles", &blofeld::halo1::vehicles_block },
		{ _field_tag_reference, "hill shader", &blofeld::halo1::shader_reference },
		{ _field_tag_reference, "flag shader", &blofeld::halo1::shader_reference },
		{ _field_tag_reference, "ball", &blofeld::halo1::item_reference },
		{ _field_block, "sounds", &blofeld::halo1::sounds_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 56),
		{ _field_terminator }
	};

	TAG_REFERENCE(item_reference, ITEM_TAG);

	TAG_BLOCK(
		sounds_block,
		"sounds_block",
		60,
		"s_sounds_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &blofeld::halo1::sound_reference$2 },
		{ _field_terminator }
	};

	TAG_REFERENCE(sound_reference$2, SOUND_TAG);

	TAG_BLOCK(
		vehicles_block,
		"vehicles_block",
		20,
		"s_vehicles_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "vehicle", FIELD_FLAG_INDEX, &blofeld::halo1::vehicle_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(vehicle_reference, VEHICLE_TAG);

	TAG_BLOCK(
		cheat_powerups_block,
		"cheat_powerups_block",
		20,
		"s_cheat_powerups_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "powerup", FIELD_FLAG_INDEX, &blofeld::halo1::equipment_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(equipment_reference, EQUIPMENT_TAG);

	TAG_BLOCK(
		cheat_weapons_block,
		"cheat_weapons_block",
		20,
		"s_cheat_weapons_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "weapon", FIELD_FLAG_INDEX, &blofeld::halo1::item_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(
		interface_tag_references,
		"interface_tag_references",
		1,
		"s_interface_tag_references",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "font system", &blofeld::halo1::font_reference },
		{ _field_tag_reference, "font terminal", &blofeld::halo1::font_reference },
		{ _field_tag_reference, "screen color table", &blofeld::halo1::color_table_reference },
		{ _field_tag_reference, "hud color table", &blofeld::halo1::color_table_reference },
		{ _field_tag_reference, "editor color table", &blofeld::halo1::color_table_reference },
		{ _field_tag_reference, "dialog color table", &blofeld::halo1::color_table_reference },
		{ _field_tag_reference, "hud globals", &blofeld::halo1::hud_globals_reference },
		{ _field_tag_reference, "motion sensor sweep bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "motion sensor sweep bitmap mask", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "multiplayer hud bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "localization", &blofeld::halo1::string_list_reference },
		{ _field_tag_reference, "hud digits definition", &blofeld::halo1::hud_number_reference },
		{ _field_tag_reference, "motion sensor blip bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "interface goo map1", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "interface goo map2", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "interface goo map3", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	TAG_REFERENCE(color_table_reference, COLOR_TABLE_TAG);

	TAG_REFERENCE(hud_globals_reference, HUD_GLOBALS_TAG);

	TAG_REFERENCE(string_list_reference, STRING_LIST_TAG);

	TAG_REFERENCE(hud_number_reference, HUD_NUMBER_TAG);

	TAG_BLOCK(
		rasterizer_data_block,
		"rasterizer_data_block",
		1,
		"s_rasterizer_data_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("function textures", nullptr, FIELD_FLAG_NONE, "Used internally by the rasterizer. (Do not change unless you know what you\'re doing!)"),
		{ _field_tag_reference, "distance attenuation", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "vector normalization", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "atmospheric fog density", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "planar fog density", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "linear corner fade", "used for shadows", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "active camouflage distortion", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "glow", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 60),
		FIELD_EXPLANATION_EX("default textures", nullptr, FIELD_FLAG_NONE, "Used internally by the rasterizer - additive, multiplicative, detail, vector. (Do not change ever, period.)"),
		{ _field_tag_reference, "default 2D", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "default 3D", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "default cube map", &blofeld::halo1::bitmap_reference },
		FIELD_EXPLANATION_EX("experimental textures", nullptr, FIELD_FLAG_NONE, "Used internally by the rasterizer. (Used by Bernie\'s experimental shaders.)"),
		{ _field_tag_reference, "test 0", &blofeld::halo1::bitmap_reference$2 },
		{ _field_tag_reference, "test 1", &blofeld::halo1::bitmap_reference$2 },
		{ _field_tag_reference, "test 2", &blofeld::halo1::bitmap_reference$2 },
		{ _field_tag_reference, "test 3", &blofeld::halo1::bitmap_reference$2 },
		FIELD_EXPLANATION_EX("video effect textures", nullptr, FIELD_FLAG_NONE, "Used in cinematics."),
		{ _field_tag_reference, "video scanline map", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "video noise map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		FIELD_EXPLANATION_EX("active camouflage", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$77 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "refraction amount", nullptr, "pixels" },
		{ _field_real, "distance falloff" },
		{ _field_real_rgb_color, "tint color" },
		{ _field_real, "hyper-stealth refraction", nullptr, "pixels" },
		{ _field_real, "hyper-stealth distance falloff" },
		{ _field_real_rgb_color, "hyper-stealth tint color" },
		FIELD_EXPLANATION_EX("PC textures", nullptr, FIELD_FLAG_NONE, "The PC can\'t use 3D textures, so we use this instead."),
		{ _field_tag_reference, "distance attenuation 2D", "the pc can't use 3d textures, so we use this instead", &blofeld::halo1::bitmap_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(bitmap_reference$2, BITMAP_TAG);

	STRINGS(unnamed_enum$77)
	{
		"tint edge density"
	};
	STRING_LIST(unnamed_enum$77, unnamed_enum$77_strings, _countof(unnamed_enum$77_strings));

	TAG_BLOCK(
		grenades_block,
		"grenades_block",
		2,
		"s_grenades_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "maximum count" },
		{ _field_short_integer, "mp spawn default" },
		{ _field_tag_reference, "throwing effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "hud interface", &blofeld::halo1::grenade_hud_interface_reference },
		{ _field_tag_reference, "equipment", &blofeld::halo1::equipment_reference },
		{ _field_tag_reference, "projectile", &blofeld::halo1::projectile_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(grenade_hud_interface_reference, GRENADE_HUD_INTERFACE_TAG);

	TAG_REFERENCE(projectile_reference, PROJECTILE_TAG);

	TAG_BLOCK(
		difficulty_block,
		"difficulty_block",
		1,
		"s_difficulty_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("health", nullptr, FIELD_FLAG_NONE, "scale values for enemy health and damage settings"),
		{ _field_real, "easy enemy damage", "enemy damage multiplier on easy difficulty" },
		{ _field_real, "normal enemy damage", "enemy damage multiplier on normal difficulty" },
		{ _field_real, "hard enemy damage", "enemy damage multiplier on hard difficulty" },
		{ _field_real, "imposs. enemy damage", "enemy damage multiplier on impossible difficulty" },
		{ _field_real, "easy enemy vitality", "enemy maximum body vitality scale on easy difficulty" },
		{ _field_real, "normal enemy vitality", "enemy maximum body vitality scale on normal difficulty" },
		{ _field_real, "hard enemy vitality", "enemy maximum body vitality scale on hard difficulty" },
		{ _field_real, "imposs. enemy vitality", "enemy maximum body vitality scale on impossible difficulty" },
		{ _field_real, "easy enemy shield", "enemy maximum shield vitality scale on easy difficulty" },
		{ _field_real, "normal enemy shield", "enemy maximum shield vitality scale on normal difficulty" },
		{ _field_real, "hard enemy shield", "enemy maximum shield vitality scale on hard difficulty" },
		{ _field_real, "imposs. enemy shield", "enemy maximum shield vitality scale on impossible difficulty" },
		{ _field_real, "easy enemy recharge", "enemy shield recharge scale on easy difficulty" },
		{ _field_real, "normal enemy recharge", "enemy shield recharge scale on normal difficulty" },
		{ _field_real, "hard enemy recharge", "enemy shield recharge scale on hard difficulty" },
		{ _field_real, "imposs. enemy recharge", "enemy shield recharge scale on impossible difficulty" },
		{ _field_real, "easy friend damage", "friend damage multiplier on easy difficulty" },
		{ _field_real, "normal friend damage", "friend damage multiplier on normal difficulty" },
		{ _field_real, "hard friend damage", "friend damage multiplier on hard difficulty" },
		{ _field_real, "imposs. friend damage", "friend damage multiplier on impossible difficulty" },
		{ _field_real, "easy friend vitality", "friend maximum body vitality scale on easy difficulty" },
		{ _field_real, "normal friend vitality", "friend maximum body vitality scale on normal difficulty" },
		{ _field_real, "hard friend vitality", "friend maximum body vitality scale on hard difficulty" },
		{ _field_real, "imposs. friend vitality", "friend maximum body vitality scale on impossible difficulty" },
		{ _field_real, "easy friend shield", "friend maximum shield vitality scale on easy difficulty" },
		{ _field_real, "normal friend shield", "friend maximum shield vitality scale on normal difficulty" },
		{ _field_real, "hard friend shield", "friend maximum shield vitality scale on hard difficulty" },
		{ _field_real, "imposs. friend shield", "friend maximum shield vitality scale on impossible difficulty" },
		{ _field_real, "easy friend recharge", "friend shield recharge scale on easy difficulty" },
		{ _field_real, "normal friend recharge", "friend shield recharge scale on normal difficulty" },
		{ _field_real, "hard friend recharge", "friend shield recharge scale on hard difficulty" },
		{ _field_real, "imposs. friend recharge", "friend shield recharge scale on impossible difficulty" },
		{ _field_real, "easy infection forms", "toughness of infection forms (may be negative) on easy difficulty" },
		{ _field_real, "normal infection forms", "toughness of infection forms (may be negative) on normal difficulty" },
		{ _field_real, "hard infection forms", "toughness of infection forms (may be negative) on hard difficulty" },
		{ _field_real, "imposs. infection forms", "toughness of infection forms (may be negative) on impossible difficulty" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("ranged fire", nullptr, FIELD_FLAG_NONE, "difficulty-affecting values for enemy ranged combat settings"),
		{ _field_real, "easy rate of fire", "enemy rate of fire scale on easy difficulty" },
		{ _field_real, "normal rate of fire", "enemy rate of fire scale on normal difficulty" },
		{ _field_real, "hard rate of fire", "enemy rate of fire scale on hard difficulty" },
		{ _field_real, "imposs. rate of fire", "enemy rate of fire scale on impossible difficulty" },
		{ _field_real, "easy projectile error", "enemy projectile error scale, as a fraction of their base firing error. on easy difficulty" },
		{ _field_real, "normal projectile error", "enemy projectile error scale, as a fraction of their base firing error. on normal difficulty" },
		{ _field_real, "hard projectile error", "enemy projectile error scale, as a fraction of their base firing error. on hard difficulty" },
		{ _field_real, "imposs. projectile error", "enemy projectile error scale, as a fraction of their base firing error. on impossible difficulty" },
		{ _field_real, "easy burst error", "enemy burst error scale; reduces intra-burst shot distance. on easy difficulty" },
		{ _field_real, "normal burst error", "enemy burst error scale; reduces intra-burst shot distance. on normal difficulty" },
		{ _field_real, "hard burst error", "enemy burst error scale; reduces intra-burst shot distance. on hard difficulty" },
		{ _field_real, "imposs. burst error", "enemy burst error scale; reduces intra-burst shot distance. on impossible difficulty" },
		{ _field_real, "easy new target delay", "enemy new-target delay scale factor. on easy difficulty" },
		{ _field_real, "normal new target delay", "enemy new-target delay scale factor. on normal difficulty" },
		{ _field_real, "hard new target delay", "enemy new-target delay scale factor. on hard difficulty" },
		{ _field_real, "imposs. new target delay", "enemy new-target delay scale factor. on impossible difficulty" },
		{ _field_real, "easy burst separation", "delay time between bursts scale factor for enemies. on easy difficulty" },
		{ _field_real, "normal burst separation", "delay time between bursts scale factor for enemies. on normal difficulty" },
		{ _field_real, "hard burst separation", "delay time between bursts scale factor for enemies. on hard difficulty" },
		{ _field_real, "imposs. burst separation", "delay time between bursts scale factor for enemies. on impossible difficulty" },
		{ _field_real, "easy target tracking", "additional target tracking fraction for enemies. on easy difficulty" },
		{ _field_real, "normal target tracking", "additional target tracking fraction for enemies. on normal difficulty" },
		{ _field_real, "hard target tracking", "additional target tracking fraction for enemies. on hard difficulty" },
		{ _field_real, "imposs. target tracking", "additional target tracking fraction for enemies. on impossible difficulty" },
		{ _field_real, "easy target leading", "additional target leading fraction for enemies. on easy difficulty" },
		{ _field_real, "normal target leading", "additional target leading fraction for enemies. on normal difficulty" },
		{ _field_real, "hard target leading", "additional target leading fraction for enemies. on hard difficulty" },
		{ _field_real, "imposs. target leading", "additional target leading fraction for enemies. on impossible difficulty" },
		{ _field_real, "easy overcharge chance", "overcharge chance scale factor for enemies. on easy difficulty" },
		{ _field_real, "normal overcharge chance", "overcharge chance scale factor for enemies. on normal difficulty" },
		{ _field_real, "hard overcharge chance", "overcharge chance scale factor for enemies. on hard difficulty" },
		{ _field_real, "imposs. overcharge chance", "overcharge chance scale factor for enemies. on impossible difficulty" },
		{ _field_real, "easy special fire delay", "delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on easy difficulty" },
		{ _field_real, "normal special fire delay", "delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on normal difficulty" },
		{ _field_real, "hard special fire delay", "delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on hard difficulty" },
		{ _field_real, "imposs. special fire delay", "delay between special-fire shots (overcharge, banshee bombs) scale factor for enemies. on impossible difficulty" },
		{ _field_real, "easy guidance vs player", "guidance velocity scale factor for all projectiles targeted on a player. on easy difficulty" },
		{ _field_real, "normal guidance vs player", "guidance velocity scale factor for all projectiles targeted on a player. on normal difficulty" },
		{ _field_real, "hard guidance vs player", "guidance velocity scale factor for all projectiles targeted on a player. on hard difficulty" },
		{ _field_real, "imposs. guidance vs player", "guidance velocity scale factor for all projectiles targeted on a player. on impossible difficulty" },
		{ _field_real, "easy melee delay base", "delay period added to all melee attacks, even when berserk. on easy difficulty" },
		{ _field_real, "normal melee delay base", "delay period added to all melee attacks, even when berserk. on normal difficulty" },
		{ _field_real, "hard melee delay base", "delay period added to all melee attacks, even when berserk. on hard difficulty" },
		{ _field_real, "imposs. melee delay base", "delay period added to all melee attacks, even when berserk. on impossible difficulty" },
		{ _field_real, "easy melee delay scale", "multiplier for all existing non-berserk melee delay times. on easy difficulty" },
		{ _field_real, "normal melee delay scale", "multiplier for all existing non-berserk melee delay times. on normal difficulty" },
		{ _field_real, "hard melee delay scale", "multiplier for all existing non-berserk melee delay times. on hard difficulty" },
		{ _field_real, "imposs. melee delay scale", "multiplier for all existing non-berserk melee delay times. on impossible difficulty" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("grenades", nullptr, FIELD_FLAG_NONE, "difficulty-affecting values for enemy grenade behavior"),
		{ _field_real, "easy grenade chance scale", "scale factor affecting the desicions to throw a grenade. on easy difficulty" },
		{ _field_real, "normal grenade chance scale", "scale factor affecting the desicions to throw a grenade. on normal difficulty" },
		{ _field_real, "hard grenade chance scale", "scale factor affecting the desicions to throw a grenade. on hard difficulty" },
		{ _field_real, "imposs. grenade chance scale", "scale factor affecting the desicions to throw a grenade. on impossible difficulty" },
		{ _field_real, "easy grenade timer scale", "scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on easy difficulty" },
		{ _field_real, "normal grenade timer scale", "scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on normal difficulty" },
		{ _field_real, "hard grenade timer scale", "scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on hard difficulty" },
		{ _field_real, "imposs. grenade timer scale", "scale factor affecting the delay period between grenades thrown from the same encounter (lower is more often). on impossible difficulty" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("placement", nullptr, FIELD_FLAG_NONE, "difficulty-affecting values for enemy placement"),
		{ _field_real, "easy major upgrade (normal)", "fraction of actors upgraded to their major variant. on easy difficulty" },
		{ _field_real, "normal major upgrade (normal)", "fraction of actors upgraded to their major variant. on normal difficulty" },
		{ _field_real, "hard major upgrade (normal)", "fraction of actors upgraded to their major variant. on hard difficulty" },
		{ _field_real, "imposs. major upgrade (normal)", "fraction of actors upgraded to their major variant. on impossible difficulty" },
		{ _field_real, "easy major upgrade (few)", "fraction of actors upgraded to their major variant when mix = normal. on easy difficulty" },
		{ _field_real, "normal major upgrade (few)", "fraction of actors upgraded to their major variant when mix = normal. on normal difficulty" },
		{ _field_real, "hard major upgrade (few)", "fraction of actors upgraded to their major variant when mix = normal. on hard difficulty" },
		{ _field_real, "imposs. major upgrade (few)", "fraction of actors upgraded to their major variant when mix = normal. on impossible difficulty" },
		{ _field_real, "easy major upgrade (many)", "fraction of actors upgraded to their major variant when mix = many. on easy difficulty" },
		{ _field_real, "normal major upgrade (many)", "fraction of actors upgraded to their major variant when mix = many. on normal difficulty" },
		{ _field_real, "hard major upgrade (many)", "fraction of actors upgraded to their major variant when mix = many. on hard difficulty" },
		{ _field_real, "imposs. major upgrade (many)", "fraction of actors upgraded to their major variant when mix = many. on impossible difficulty" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_terminator }
	};

	TAG_BLOCK(
		player_control_block,
		"player_control_block",
		1,
		"s_player_control_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_fraction, "magnetism friction", "how much the crosshair slows over enemies" },
		{ _field_real_fraction, "magnetism adhesion", "how much the crosshair sticks to enemies" },
		{ _field_real_fraction, "inconsequential target scale", "scales magnetism level for inconsequential targets like infection forms" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		{ _field_real, "look acceleration time", "time for a pegged look to reach maximum effect", "seconds" },
		{ _field_real, "look acceleration scale", "maximum effect of a pegged look (scales last value in the look function below)" },
		{ _field_real_fraction, "look peg threshold", "magnitude of yaw for pegged acceleration to kick in" },
		{ _field_real, "look default pitch rate", nullptr, "degrees" },
		{ _field_real, "look default yaw rate", nullptr, "degrees" },
		{ _field_real, "look autolevelling scale", "1 is fast, 0 is none, >1 will probably be really fast" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_short_integer, "minimum weapon swap ticks", "amount of time player needs to hold down ACTION to pick up a new weapon" },
		{ _field_short_integer, "minimum autolevelling ticks", "amount of time player needs to move and not look up or down for autolevelling to kick in" },
		{ _field_angle, "minimum angle for vehicle flipping", "0 means the vehicle's up vector is along the ground, 90 means the up vector is pointing straight up:degrees" },
		{ _field_block, "look function", &blofeld::halo1::look_function_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		look_function_block,
		"look_function_block",
		16,
		"s_look_function_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real, "scale" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		camera_block,
		"camera_block",
		1,
		"s_camera_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "default unit camera track", &blofeld::halo1::camera_track_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(camera_track_reference, CAMERA_TRACK_TAG);

	TAG_BLOCK(
		sound_block,
		"sound_block",
		2,
		"s_sound_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "sound", &blofeld::halo1::sound_reference },
		{ _field_terminator }
	};


	TAG_GROUP(
		sound_group,
		SOUND_TAG,
		nullptr,
		INVALID_TAG,
		sound);

	TAG_BLOCK(
		sound,
		"sound_group_block",
		1,
		"s_sound",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$79 },
		{ _field_short_enum, "class", &blofeld::halo1::unnamed_enum$80 },
		{ _field_short_enum, "sample rate", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$81 },
		{ _field_real, "minimum distance", "the distance below which this sound no longer gets louder", "world units" },
		{ _field_real, "maximum distance", "the distance beyond which this sound is no longer audible", "world units" },
		{ _field_real_fraction, "skip fraction", "fraction of requests to play this sound that will be ignored (0 means always play.)" },
		FIELD_EXPLANATION_EX("randomization", nullptr, FIELD_FLAG_NONE, "these settings control random variation of volume and pitch."),
		{ _field_real_bounds, "random pitch bounds", "the sound's pitch will be randomly selected and will be in this range. (1.0 is the recorded pitch.)" },
		{ _field_angle, "inner cone angle", "within the cone defined by this angle and the sound's direction, the sound plays with a gain of 1.0.", "degrees" },
		{ _field_angle, "outer cone angle", "outside the cone defined by this angle and the sound's direction, the sound plays with a gain of OUTER CONE GAIN. (0 means the sound does not attenuate with direction.)", "degrees" },
		{ _field_real_fraction, "outer cone gain", "the gain to use when the sound is directed away from the listener" },
		{ _field_real, "gain modifier" },
		{ _field_real, "maximum bend per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("when scale is ZERO", nullptr, FIELD_FLAG_NONE, "as the sound\'s input scale changes from zero to one, these modifiers move between the two values specified here. the sound will play using the current scale modifier multiplied by the value specified above. (0 values are ignored.)"),
		{ _field_real, "skip fraction modifier" },
		{ _field_real, "gain modifier" },
		{ _field_real, "pitch modifier" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("when scale is ONE", nullptr, FIELD_FLAG_NONE, "as the sound\'s input scale changes from zero to one, these modifiers move between the two values specified here. the sound will play using the current scale modifier multiplied by the value specified above. (0 values are ignored.)"),
		{ _field_real, "skip fraction modifier" },
		{ _field_real, "gain modifier" },
		{ _field_real, "pitch modifier" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("import properties", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "encoding", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$82 },
		{ _field_short_enum, "compression", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$83 },
		{ _field_tag_reference, "promotion sound", &blofeld::halo1::sound_reference },
		{ _field_short_integer, "promotion count", "when there are this many instances of the sound, promote to the new sound." },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_block, "pitch ranges", "pitch ranges allow multiple samples to represent the same sound at different pitches", &blofeld::halo1::sound_pitch_range_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$79)
	{
		"fit to adpcm blocksize",
		"split long sound into permutations"
	};
	STRING_LIST(unnamed_enum$79, unnamed_enum$79_strings, _countof(unnamed_enum$79_strings));

	STRINGS(unnamed_enum$80)
	{
		"projectile_impact",
		"projectile_detonation",
		"unused",
		"unused",
		"weapon_fire",
		"weapon_ready",
		"weapon_reload",
		"weapon_empty",
		"weapon_charge",
		"weapon_overheat",
		"weapon_idle",
		"unused",
		"unused",
		"object_impacts",
		"particle_impacts",
		"slow_particle_impacts",
		"unused",
		"unused",
		"unit_footsteps",
		"unit_dialog",
		"unused",
		"unused",
		"vehicle_collision",
		"vehicle_engine",
		"unused",
		"unused",
		"device_door",
		"device_force_field",
		"device_machinery",
		"device_nature",
		"device_computers",
		"unused",
		"music",
		"ambient_nature",
		"ambient_machinery",
		"ambient_computers",
		"unused",
		"unused",
		"unused",
		"first_person_damage",
		"unused",
		"unused",
		"unused",
		"unused",
		"scripted_dialog_player",
		"scripted_effect",
		"scripted_dialog_other",
		"scripted_dialog_force_unspatialized",
		"unused",
		"unused",
		"game_event"
	};
	STRING_LIST(unnamed_enum$80, unnamed_enum$80_strings, _countof(unnamed_enum$80_strings));

	STRINGS(unnamed_enum$81)
	{
		"22kHz",
		"44kHz"
	};
	STRING_LIST(unnamed_enum$81, unnamed_enum$81_strings, _countof(unnamed_enum$81_strings));

	STRINGS(unnamed_enum$82)
	{
		"mono",
		"stereo"
	};
	STRING_LIST(unnamed_enum$82, unnamed_enum$82_strings, _countof(unnamed_enum$82_strings));

	STRINGS(unnamed_enum$83)
	{
		"none",
		"xbox adpcm",
		"ima adpcm",
		"ogg"
	};
	STRING_LIST(unnamed_enum$83, unnamed_enum$83_strings, _countof(unnamed_enum$83_strings));

	TAG_BLOCK(
		sound_pitch_range_block,
		"sound_pitch_range_block",
		8,
		"s_sound_pitch_range_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", "the name of the imported pitch range directory", FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION_EX("pitch control", nullptr, FIELD_FLAG_NONE, "these settings control what pitches this set of samples represents. if there is only one pitch range, all three values are ignored."),
		{ _field_real, "natural pitch", "the apparent pitch when these samples are played at their recorded pitch." },
		{ _field_real_bounds, "bend bounds", "the range of pitches that will be represented using this sample. this should always contain the natural pitch." },
		{ _field_short_integer, "actual permutation count", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "permutations", "permutations represent equivalent variations of this sound.", &blofeld::halo1::sound_permutations_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		sound_permutations_block,
		"sound_permutations_block",
		256,
		"s_sound_permutations_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", "name of the file from which this sample was imported", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_real_fraction, "skip fraction", "fraction of requests to play this permutation that are ignored (a different permutation is selected.)" },
		{ _field_real_fraction, "gain", "fraction of recorded volume to play at." },
		{ _field_short_enum, "compression", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$83 },
		{ _field_short_integer, "next permutation index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_data, "samples", "sampled sound data" },
		{ _field_data, "mouth data" },
		{ _field_data, "subtitle data" },
		{ _field_terminator }
	};


	TAG_GROUP(
		sound_looping_group,
		SOUND_LOOPING_TAG,
		nullptr,
		INVALID_TAG,
		sound_looping);

	TAG_BLOCK(
		sound_looping,
		"sound_looping_group_block",
		1,
		"s_sound_looping",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$84 },
		FIELD_EXPLANATION_EX("when scale is ZERO", nullptr, FIELD_FLAG_NONE, "as the sound\'s input scale changes from zero to one, these modifiers move between the two values specified here. the sound will play using the current scale modifier multiplied by the value specified below. (0 values are ignored.)"),
		{ _field_real, "detail sound period" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("when scale is ONE", nullptr, FIELD_FLAG_NONE, "as the sound\'s input scale changes from zero to one, these modifiers move between the two values specified here. the sound will play using the current scale modifier multiplied by the value specified below. (0 values are ignored.)"),
		{ _field_real, "detail sound period" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "continuous damage effect", &blofeld::halo1::continuous_damage_effect_reference },
		{ _field_block, "tracks", "tracks play in parallel and loop continuously for the duration of the looping sound.", &blofeld::halo1::looping_sound_track_block },
		{ _field_block, "detail sounds", "detail sounds play at random throughout the duration of the looping sound.", &blofeld::halo1::looping_sound_detail_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$84)
	{
		"deafening to AIs#when used as a background stereo track, causes nearby AIs to be unable to hear",
		"not a loop#this is a collection of permutations strung together that should play once then stop.",
		"stops music#all other music loops will stop when this one starts."
	};
	STRING_LIST(unnamed_enum$84, unnamed_enum$84_strings, _countof(unnamed_enum$84_strings));

	TAG_REFERENCE(continuous_damage_effect_reference, CONTINUOUS_DAMAGE_EFFECT_TAG);

	TAG_BLOCK(
		looping_sound_detail_block,
		"looping_sound_detail_block",
		32,
		"s_looping_sound_detail_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &blofeld::halo1::sound_reference },
		FIELD_EXPLANATION_EX("frequency of play", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "random period bounds", "the time between successive playings of this sound will be randomly selected from this range.", "seconds" },
		{ _field_real_fraction, "gain" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$86 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		FIELD_EXPLANATION_EX("random spatialization", nullptr, FIELD_FLAG_NONE, "if the sound specified above is not stereo it will be randomly spatialized according to the following constraints. if both lower and upper bounds are zero for any of the following fields, the sound\'s position will be randomly selected from all possible directions or distances."),
		{ _field_angle_bounds, "yaw bounds", "the sound's position along the horizon will be randomly selected from this range.", "degrees" },
		{ _field_angle_bounds, "pitch bounds", "the sound's position above (positive values) or below (negative values) the horizon will be randomly selected from this range.", "degrees" },
		{ _field_real_bounds, "distance bounds", "the sound's distance (from its spatialized looping sound or from the listener if the looping sound is stereo) will be randomly selected from this range.", "world units" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$86)
	{
		"don\'t play with alternate",
		"don\'t play without alternate"
	};
	STRING_LIST(unnamed_enum$86, unnamed_enum$86_strings, _countof(unnamed_enum$86_strings));

	TAG_BLOCK(
		looping_sound_track_block,
		"looping_sound_track_block",
		4,
		"s_looping_sound_track_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$85 },
		{ _field_real_fraction, "gain" },
		{ _field_real, "fade in duration", nullptr, "seconds" },
		{ _field_real, "fade out duration", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "start", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "loop", FIELD_FLAG_INDEX, &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "end", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "alternate loop", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "alternate end", &blofeld::halo1::sound_reference },
		{ _field_custom, "value" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$85)
	{
		"fade in at start#the loop sound should fade in while the start sound is playing.",
		"fade out at stop#the loop sound should fade out while the stop sound is playing.",
		"fade in alternate#when the sound changes to the alternate version,  ."
	};
	STRING_LIST(unnamed_enum$85, unnamed_enum$85_strings, _countof(unnamed_enum$85_strings));


	TAG_GROUP(
		item_group,
		ITEM_TAG,
		&object_group,
		OBJECT_TAG,
		item);

	TAG_BLOCK(
		item,
		"item_group_block",
		1,
		"s_item",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "object", &blofeld::halo1::object_struct_definition },
		FIELD_EXPLANATION_EX("$$$ ITEM $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$87 },
		FIELD_EXPLANATION_EX("message-index", nullptr, FIELD_FLAG_NONE, "This sets which string from tags\\ui\\hud\\hud_item_messages.unicode_string_list to display."),
		{ _field_short_integer, "message index" },
		{ _field_short_integer, "sort order" },
		{ _field_real, "scale" },
		{ _field_short_integer, "hud message value scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$88 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$88 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$88 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$88 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 164),
		{ _field_tag_reference, "material effects", &blofeld::halo1::material_effects_reference },
		{ _field_tag_reference, "collision sound", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 120),
		{ _field_real_bounds, "detonation delay", nullptr, "seconds" },
		{ _field_tag_reference, "detonating effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "detonation effect", &blofeld::halo1::effect_reference },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$87)
	{
		"always maintains z up",
		"destroyed by explosions",
		"unaffected by gravity"
	};
	STRING_LIST(unnamed_enum$87, unnamed_enum$87_strings, _countof(unnamed_enum$87_strings));

	STRINGS(unnamed_enum$88)
	{
		"none"
	};
	STRING_LIST(unnamed_enum$88, unnamed_enum$88_strings, _countof(unnamed_enum$88_strings));


	TAG_GROUP(
		equipment_group,
		EQUIPMENT_TAG,
		&item_group,
		ITEM_TAG,
		equipment);

	TAG_BLOCK(
		equipment,
		"equipment_group_block",
		1,
		"s_equipment",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "item", &blofeld::halo1::item_struct_definition },
		{ _field_short_enum, "powerup type", &blofeld::halo1::unnamed_enum$89 },
		{ _field_short_enum, "grenade type", &blofeld::halo1::unnamed_enum$26 },
		{ _field_real, "powerup time", nullptr, "seconds" },
		{ _field_tag_reference, "pickup sound", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 144),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$89)
	{
		"none",
		"double speed",
		"over shield",
		"active camouflage",
		"full-spectrum vision",
		"health",
		"grenade"
	};
	STRING_LIST(unnamed_enum$89, unnamed_enum$89_strings, _countof(unnamed_enum$89_strings));

	STRINGS(unnamed_enum$26)
	{
		"human fragmentation",
		"covenant plasma"
	};
	STRING_LIST(unnamed_enum$26, unnamed_enum$26_strings, _countof(unnamed_enum$26_strings));


	TAG_GROUP(
		flag_group,
		FLAG_TAG,
		nullptr,
		INVALID_TAG,
		flag);

	TAG_BLOCK(
		flag,
		"flag_group_block",
		1,
		"s_flag",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$90 },
		{ _field_short_enum, "trailing edge shape", &blofeld::halo1::unnamed_enum$91 },
		{ _field_short_integer, "trailing edge shape offset", "zero places the shape exactly on the trailing edge, positive numbers push it off the edge", "vertices" },
		{ _field_short_enum, "attached edge shape", &blofeld::halo1::unnamed_enum$92 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "width", "flag size from attached to trailing edge", "vertices" },
		{ _field_short_integer, "height", "flag size along the direction of attachment (should be odd)", "vertices" },
		{ _field_real, "cell width", "width of the cell between each pair of vertices", "world units" },
		{ _field_real, "cell height", "height of the cell between each pair of vertices", "world units" },
		{ _field_tag_reference, "red flag shader", FIELD_FLAG_INDEX, &blofeld::halo1::shader_reference },
		{ _field_tag_reference, "physics", &blofeld::halo1::point_physics_reference },
		{ _field_real, "wind noise", nullptr, "world units per second^2" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_tag_reference, "blue flag shader", FIELD_FLAG_INDEX, &blofeld::halo1::shader_reference },
		{ _field_block, "attachment points", "attachment points determine where the flag is attached", &blofeld::halo1::flag_attachment_point_block },
		{ _field_terminator }
	};

	STRING_LIST(unnamed_enum$90, empty_string_list, 0);

	STRINGS(unnamed_enum$91)
	{
		"flat",
		"concave triangular",
		"convex triangular",
		"trapezoid, short top",
		"trapezoid, short bottom"
	};
	STRING_LIST(unnamed_enum$91, unnamed_enum$91_strings, _countof(unnamed_enum$91_strings));

	STRINGS(unnamed_enum$92)
	{
		"flat",
		"concave triangular"
	};
	STRING_LIST(unnamed_enum$92, unnamed_enum$92_strings, _countof(unnamed_enum$92_strings));

	TAG_BLOCK(
		flag_attachment_point_block,
		"flag_attachment_point_block",
		5,
		"s_flag_attachment_point_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "height_to_next_attachment", "flag vertices between this attachment point and the next", "vertices" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_string, "marker name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};


	TAG_GROUP(
		antenna_group,
		ANTENNA_TAG,
		nullptr,
		INVALID_TAG,
		antenna);

	TAG_BLOCK(
		antenna,
		"antenna_group_block",
		1,
		"s_antenna",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "attachment marker name", "the marker name where the antenna should be attached" },
		{ _field_tag_reference, "bitmaps", &blofeld::halo1::bitmap_reference$3 },
		{ _field_tag_reference, "physics", &blofeld::halo1::point_physics_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 80),
		{ _field_real_fraction, "spring strength coefficient", "strength of the spring (larger values make the spring stronger)" },
		{ _field_real, "falloff pixels" },
		{ _field_real, "cutoff pixels" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_block, "vertices", &blofeld::halo1::antenna_vertex_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(bitmap_reference$3, BITMAP_TAG);

	TAG_BLOCK(
		antenna_vertex_block,
		"antenna_vertex_block",
		20,
		"s_antenna_vertex_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_fraction, "spring strength coefficient", "strength of the spring (larger values make the spring stronger)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real_euler_angles_2d, "angles", "direction toward next vertex" },
		{ _field_real, "length", "distance between this vertex and the next", "world units" },
		{ _field_short_integer, "sequence index", "bitmap group sequence index for this vertex's texture" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_argb_color, "color", "color at this vertex" },
		{ _field_real_argb_color, "LOD color", "color at this vertex for the low-LOD line primitives" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};


	TAG_GROUP(
		spheroid_group,
		SPHEROID_TAG,
		nullptr,
		INVALID_TAG,
		spheroid);

	TAG_BLOCK(
		spheroid,
		"spheroid_group_block",
		1,
		"s_spheroid",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};


	TAG_GROUP(
		weather_particle_system_group,
		WEATHER_PARTICLE_SYSTEM_TAG,
		nullptr,
		INVALID_TAG,
		weather_particle_system);

	TAG_BLOCK(
		weather_particle_system,
		"weather_particle_system_group_block",
		1,
		"s_weather_particle_system",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$93 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "particle types", &blofeld::halo1::weather_particle_type_block },
		{ _field_terminator }
	};

	STRING_LIST(unnamed_enum$93, empty_string_list, 0);

	TAG_BLOCK(
		weather_particle_type_block,
		"weather_particle_type_block",
		8,
		"s_weather_particle_type_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$94 },
		{ _field_real, "fade-in start distance", "Particles begin to fade into visibility beyond this distance", "world units" },
		{ _field_real, "fade-in end distance", "Particles become fully visible beyond this distance", "world units" },
		{ _field_real, "fade-out start distance", "Particles begin to fade out of visibility beyond this distance", "world units" },
		{ _field_real, "fade-out end distance", "Particles become fully invisible beyond this distance", "world units" },
		{ _field_real, "fade-in start height", "Particles begin to fade into visibility above this height", "world units" },
		{ _field_real, "fade-in end height", "Particles become fully visible above this height", "world units" },
		{ _field_real, "fade-out start height", "Particles begin to fade out of visibility above this height", "world units" },
		{ _field_real, "fade-out end height", "Particles become fully invisible above this height", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 96),
		{ _field_real_bounds, "particle count", nullptr, "particles per cubic world unit" },
		{ _field_tag_reference, "physics", &blofeld::halo1::point_physics_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real_bounds, "acceleration magnitude" },
		{ _field_real_fraction, "acceleration turning rate" },
		{ _field_real, "acceleration change rate" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_real_bounds, "particle radius", nullptr, "world units" },
		{ _field_real_bounds, "animation rate", nullptr, "frames per second" },
		{ _field_angle_bounds, "rotation rate", nullptr, "degrees per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_real_argb_color, "color lower bound" },
		{ _field_real_argb_color, "color upper bound" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		FIELD_EXPLANATION_EX("SHADER", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "sprite bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_short_enum, "render mode", &blofeld::halo1::unnamed_enum$76 },
		{ _field_short_enum, "render direction source", "Render modes that depend on an direction will use this vector.", &blofeld::halo1::unnamed_enum$95 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_word_flags, "shader flags", &blofeld::halo1::unnamed_enum$50 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_word_flags, "map flags", &blofeld::halo1::unnamed_enum$53 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("Secondary Map", nullptr, FIELD_FLAG_NONE, "Optional multitextured second map"),
		{ _field_tag_reference, "bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$54 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$53 },
		{ _field_short_enum, "u-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "u-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "u-animation phase" },
		{ _field_real, "u-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "v-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "v-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "v-animation phase" },
		{ _field_real, "v-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "rotation-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "rotation-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "rotation-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "rotation-animation phase" },
		{ _field_real, "rotation-animation scale", "0 defaults to 360", "degrees" },
		{ _field_real_point_2d, "rotation-animation center" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "zsprite radius scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$94)
	{
		"interpolate colors in hsv",
		"... along long hue path",
		"random rotation"
	};
	STRING_LIST(unnamed_enum$94, unnamed_enum$94_strings, _countof(unnamed_enum$94_strings));

	STRINGS(unnamed_enum$95)
	{
		"from velocity",
		"from acceleration"
	};
	STRING_LIST(unnamed_enum$95, unnamed_enum$95_strings, _countof(unnamed_enum$95_strings));


	TAG_GROUP(
		glow_group,
		GLOW_TAG,
		nullptr,
		INVALID_TAG,
		glow);

	TAG_BLOCK(
		glow,
		"glow_group_block",
		1,
		"s_glow",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "attachment marker", "the marker name that the glow should be attached to" },
		{ _field_short_integer, "number of particles", "the number of particles that comprise the glow system" },
		{ _field_short_enum, "boundary effect", "particles behavior on reaching the end of an object", &blofeld::halo1::unnamed_enum$96 },
		{ _field_short_enum, "normal particle distribution", "distribution of the normal particles about the object", &blofeld::halo1::unnamed_enum$97 },
		{ _field_short_enum, "trailing particle distribution", "distribution of the trailing particles about the object", &blofeld::halo1::unnamed_enum$98 },
		{ _field_long_flags, "glow flags", &blofeld::halo1::unnamed_enum$99 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_enum, "attachment", &blofeld::halo1::unnamed_enum$100 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "particle rotational velocity", "radians per second" },
		{ _field_real, "particle rot vel mul low", "multiplied by overall velocity; only used if controlled by attachment" },
		{ _field_real, "particle rot vel mul high", "multiplied by overall velocity; only used if controlled by attachment" },
		{ _field_short_enum, "attachment", &blofeld::halo1::unnamed_enum$100 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "effect rotational velocity", "in radians per second" },
		{ _field_real, "effect rot vel mul low", "multiplied by overall velocity; only used if controlled by attachment" },
		{ _field_real, "effect rot vel mul high", "multiplied by overall velocity; only used if controlled by attachment" },
		{ _field_short_enum, "attachment", &blofeld::halo1::unnamed_enum$100 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "effect translational velocity", "in world units per second" },
		{ _field_real, "effect trans vel mul low", "multiplied by overall velocity; only used if controlled by attachment" },
		{ _field_real, "effect trans vel mul high", "multiplied by overall velocity; only used if controlled by attachment" },
		{ _field_short_enum, "attachment", &blofeld::halo1::unnamed_enum$100 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "min distance particle to object", "in world units" },
		{ _field_real, "max distance particle to object", "in world units" },
		{ _field_real, "distance to object mul low", "multiplied by particle distance; only used if controlled by attachment" },
		{ _field_real, "distance to object mul high", "multiplied by particle distance; only used if controlled by attachment" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_enum, "attachment", &blofeld::halo1::unnamed_enum$100 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_bounds, "particle size bounds", "size of particles", "world units" },
		{ _field_real_bounds, "size attachment multiplier", "multiplied by particle size; only used if controlled by attachment" },
		{ _field_short_enum, "attachment", &blofeld::halo1::unnamed_enum$100 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_argb_color, "color_bound_0", "the color of all particles will vary between color bound 0 and color bound 1" },
		{ _field_real_argb_color, "color_bound_1", "the color of all particles will vary between color bound 0 and color bound 1" },
		{ _field_real_argb_color, "scale color 0", "used to scale the particle color; only used if controlled by attachment" },
		{ _field_real_argb_color, "scale color 1", "used to scale the particle color; only used if controlled by attachment" },
		{ _field_real, "color rate of change", "for glow effects that dynamically control particle color; sets rate of change" },
		{ _field_real, "fading percentage of glow", "percentage of the glow that is fading at any given time" },
		{ _field_real, "particle generation freq", "frequency in Hz that trailing particles are generated:Hz" },
		{ _field_real, "lifetime of trailing particles", "seconds that a trailing particle remains in existence:s" },
		{ _field_real, "velocity of trailing particles", nullptr, "wu/s" },
		{ _field_real, "trailing particle minimum t" },
		{ _field_real, "trailing particle maximum t" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		{ _field_tag_reference, "texture", &blofeld::halo1::bitmap_reference },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$96)
	{
		"bounce",
		"wrap"
	};
	STRING_LIST(unnamed_enum$96, unnamed_enum$96_strings, _countof(unnamed_enum$96_strings));

	STRINGS(unnamed_enum$97)
	{
		"distributed randomly",
		"distributed uniformly"
	};
	STRING_LIST(unnamed_enum$97, unnamed_enum$97_strings, _countof(unnamed_enum$97_strings));

	STRINGS(unnamed_enum$98)
	{
		"emit vertically",
		"emit normal (up)",
		"emit randomly"
	};
	STRING_LIST(unnamed_enum$98, unnamed_enum$98_strings, _countof(unnamed_enum$98_strings));

	STRINGS(unnamed_enum$99)
	{
		"modify particle color in range",
		"particles move backwards",
		"partices move in both directions",
		"trailing particles fade over time",
		"trailing particles shrink over time",
		"trailing particles slow over time"
	};
	STRING_LIST(unnamed_enum$99, unnamed_enum$99_strings, _countof(unnamed_enum$99_strings));

	STRINGS(unnamed_enum$100)
	{
		"NONE",
		"A out",
		"B out",
		"C out",
		"D out"
	};
	STRING_LIST(unnamed_enum$100, unnamed_enum$100_strings, _countof(unnamed_enum$100_strings));


	TAG_GROUP(
		light_volume_group,
		LIGHT_VOLUME_TAG,
		nullptr,
		INVALID_TAG,
		light_volume);

	TAG_BLOCK(
		light_volume,
		"light_volume_group_block",
		1,
		"s_light_volume",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("light volume", nullptr, FIELD_FLAG_NONE, "Draws a sequence of glow bitmaps along a line. Can be used for contrail-type effects as well as volumetric lights."),
		{ _field_string, "attachment marker", "the marker name that the light volume should be attached to" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$101 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("brightness scale", nullptr, FIELD_FLAG_NONE, "Fades the effect in and out with distance, viewer angle, and external source."),
		{ _field_real, "near fade distance", "distance at which light volume is full brightness", "world units" },
		{ _field_real, "far fade distance", "distance at which light volume is zero brightness", "world units" },
		{ _field_real_fraction, "perpendicular brightness scale", "brightness scale when viewed at a 90-degree angle", nullptr, "[0,1]" },
		{ _field_real_fraction, "parallel brightness scale", "brightness scale when viewed directly", nullptr, "[0,1]" },
		{ _field_short_enum, "brightness scale source", "scales brightness based on external value", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("bitmaps", nullptr, FIELD_FLAG_NONE, "Bitmap tag used to draw the light volume, repeated <count> times. Default is \'tags\\rasterizer_textures\\glow\'. Note that sprite plates are not valid for light volumes."),
		{ _field_tag_reference, "map", "NOT A SPRITE PLATE", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "sequence index" },
		{ _field_short_integer, "count", "number of bitmaps to draw (0 causes light volume not to render)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 72),
		FIELD_EXPLANATION_EX("frame animation", nullptr, FIELD_FLAG_NONE, "Frames are descriptions of the light volume at a particular point in time, interpolated by an external source. For example, a bolt of energy can be made to stretch out and grow thinner as it is fired from a weapon."),
		{ _field_short_enum, "frame animation source", "interpolates between frames based on external value", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		{ _field_block, "frames", &blofeld::halo1::light_volume_frame_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$101)
	{
		"interpolate color in hsv",
		"...more colors"
	};
	STRING_LIST(unnamed_enum$101, unnamed_enum$101_strings, _countof(unnamed_enum$101_strings));

	TAG_BLOCK(
		light_volume_frame_block,
		"light_volume_frame_block",
		2,
		"s_light_volume_frame_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real, "offset from marker", nullptr, "world units" },
		{ _field_real, "offset exponent", "0 defaults to 1; >1 compresses light near marker, <1 compresses light near far end" },
		{ _field_real, "length", "0 causes light volume not to render", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_real, "radius hither", "radius near the marker", "world units" },
		{ _field_real, "radius yon", "radius at far end of light volume", "world units" },
		{ _field_real, "radius exponent", "0 defaults to 1; >1 values are more teardrop-shaped, <1 values are more pill-shaped" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_real_argb_color, "tint color hither", "tint color near the marker (alpha is brightness)" },
		{ _field_real_argb_color, "tint color yon", "tint color at far end of light volume (alpha is brightness)" },
		{ _field_real, "tint color exponent", "0 defaults to 1; affects tint color only, not brightness" },
		{ _field_real, "brightness exponent", "0 defaults to 1" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};


	TAG_GROUP(
		lightning_group,
		LIGHTNING_TAG,
		nullptr,
		INVALID_TAG,
		lightning);

	TAG_BLOCK(
		lightning,
		"lightning_group_block",
		1,
		"s_lightning",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("lightning", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "count", "number of overlapping lightning effects to render; 0 defaults to 1" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real, "near fade distance", "distance at which lightning is at full brightness", "world units" },
		{ _field_real, "far fade distance", "distance at which lightning is at zero brightness", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_short_enum, "jitter scale source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "thickness scale source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "tint modulation source", &blofeld::halo1::unnamed_enum$39 },
		{ _field_short_enum, "brightness scale source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_tag_reference, "bitmap", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_block, "markers", &blofeld::halo1::lightning_marker_block },
		{ _field_block, "shader", &blofeld::halo1::lightning_shader_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 88),
		{ _field_terminator }
	};

	TAG_BLOCK(
		lightning_shader_block,
		"lightning_shader_block",
		1,
		"s_lightning_shader_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_word_flags, "shader flags", &blofeld::halo1::unnamed_enum$50 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_word_flags, "map flags", &blofeld::halo1::unnamed_enum$53 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 56),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	TAG_BLOCK(
		lightning_marker_block,
		"lightning_marker_block",
		16,
		"s_lightning_marker_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "attachment marker" },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$102 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "octaves to next marker" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		{ _field_real_vector_3d, "random position bounds", nullptr, "world units" },
		{ _field_real, "random jitter", nullptr, "world units" },
		{ _field_real, "thickness", nullptr, "world units" },
		{ _field_real_argb_color, "tint", "alpha is brightness" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$102)
	{
		"not connected to next marker"
	};
	STRING_LIST(unnamed_enum$102, unnamed_enum$102_strings, _countof(unnamed_enum$102_strings));


	TAG_GROUP(
		camera_track_group,
		CAMERA_TRACK_TAG,
		nullptr,
		INVALID_TAG,
		camera_track);

	TAG_BLOCK(
		camera_track,
		"camera_track_group_block",
		1,
		"s_camera_track",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$103 },
		{ _field_block, "control points", &blofeld::halo1::camera_track_control_point_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRING_LIST(unnamed_enum$103, empty_string_list, 0);

	TAG_BLOCK(
		camera_track_control_point_block,
		"camera_track_control_point_block",
		16,
		"s_camera_track_control_point_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_real_quaternion, "orientation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};


	TAG_GROUP(
		particle_system_group,
		PARTICLE_SYSTEM_TAG,
		nullptr,
		INVALID_TAG,
		particle_system);

	TAG_BLOCK(
		particle_system,
		"particle_system_group_block",
		1,
		"s_particle_system",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		FIELD_EXPLANATION_EX("system behavior", nullptr, FIELD_FLAG_NONE, "These settings affect the behavior of the system\'s origin."),
		{ _field_tag_reference, "point physics", &blofeld::halo1::point_physics_reference },
		{ _field_short_enum, "system update physics", &blofeld::halo1::unnamed_enum$104 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_flags, "physics flags", &blofeld::halo1::unnamed_enum$105 },
		{ _field_block, "physics constants", &blofeld::halo1::particle_system_physics_constants_block },
		{ _field_block, "particle types", &blofeld::halo1::particle_system_types_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$104)
	{
		"default",
		"explosion"
	};
	STRING_LIST(unnamed_enum$104, unnamed_enum$104_strings, _countof(unnamed_enum$104_strings));

	STRING_LIST(unnamed_enum$105, empty_string_list, 0);

	TAG_BLOCK(
		particle_system_types_block,
		"particle_system_types_block",
		4,
		"s_particle_system_types_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$106 },
		{ _field_short_integer, "initial particle count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "complex sprite render modes", &blofeld::halo1::unnamed_enum$107 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "radius", nullptr, "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_short_enum, "particle creation physics", "This controls the initial placement of particles.", &blofeld::halo1::unnamed_enum$108 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_flags, "physics flags", &blofeld::halo1::unnamed_enum$105 },
		{ _field_block, "physics constants", &blofeld::halo1::particle_system_physics_constants_block },
		{ _field_block, "states", &blofeld::halo1::particle_system_type_states_block },
		{ _field_block, "particle states", &blofeld::halo1::particle_system_type_particle_states_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$106)
	{
		"type states loop",
		"... forward/backward",
		"particle states loop",
		"... forward/backward",
		"particles die in water",
		"particles die in air",
		"particles die on ground",
		"rotational sprites animate sideways#if the complex sprite mode is rotational and this flag is set, the sideways sequence is contains an animation rather than a set of permutations.",
		"disabled",
		"tint by effect color",
		"initial count scales with effect",
		"minimum count scales with effect",
		"creation rate scales with effect",
		"scale scales with effect",
		"animation rate scales with effect",
		"rotation rate scales with effect",
		"don\'t draw in first person",
		"don\'t draw in third person"
	};
	STRING_LIST(unnamed_enum$106, unnamed_enum$106_strings, _countof(unnamed_enum$106_strings));

	STRINGS(unnamed_enum$107)
	{
		"simple",
		"rotational"
	};
	STRING_LIST(unnamed_enum$107, unnamed_enum$107_strings, _countof(unnamed_enum$107_strings));

	STRINGS(unnamed_enum$108)
	{
		"default",
		"explosion",
		"jet"
	};
	STRING_LIST(unnamed_enum$108, unnamed_enum$108_strings, _countof(unnamed_enum$108_strings));

	TAG_BLOCK(
		particle_system_type_particle_states_block,
		"particle_system_type_particle_states_block",
		8,
		"s_particle_system_type_particle_states_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_bounds, "duration bounds", "Time in this state.", "seconds" },
		{ _field_real_bounds, "transition time bounds", "Time spent in transition to next state.", "seconds" },
		{ _field_tag_reference, "bitmaps", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_bounds, "scale", "Apparent size of the particles.", "world units per pixel" },
		{ _field_real_bounds, "animation rate", "Rate of sprite animation.", "frames per second" },
		{ _field_angle_bounds, "rotation rate", "Rate of texture rotation.", "degrees per second" },
		{ _field_real_argb_color, "color 1", "Particle will have a random color in the range determined by these two colors." },
		{ _field_real_argb_color, "color 2", "Particle will have a random color in the range determined by these two colors." },
		{ _field_real, "radius multiplier", "This value will be multiplied into the radius computed by the type." },
		{ _field_tag_reference, "point physics", &blofeld::halo1::point_physics_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_word_flags, "shader flags", &blofeld::halo1::unnamed_enum$50 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_word_flags, "map flags", &blofeld::halo1::unnamed_enum$53 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("Secondary Map", nullptr, FIELD_FLAG_NONE, "Optional multitextured second map"),
		{ _field_tag_reference, "bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$54 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$53 },
		{ _field_short_enum, "u-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "u-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "u-animation phase" },
		{ _field_real, "u-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "v-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "v-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "v-animation phase" },
		{ _field_real, "v-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "rotation-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "rotation-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "rotation-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "rotation-animation phase" },
		{ _field_real, "rotation-animation scale", "0 defaults to 360", "degrees" },
		{ _field_real_point_2d, "rotation-animation center" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "zsprite radius scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_block, "physics constants", &blofeld::halo1::particle_system_physics_constants_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		particle_system_physics_constants_block,
		"particle_system_physics_constants_block",
		16,
		"s_particle_system_physics_constants_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real, "k", "The meaning of this constant depends on the selected physics creation/update function." },
		{ _field_terminator }
	};

	TAG_BLOCK(
		particle_system_type_states_block,
		"particle_system_type_states_block",
		8,
		"s_particle_system_type_states_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_bounds, "duration bounds", "Time in this state.", "seconds" },
		{ _field_real_bounds, "transition time bounds", "Time spent in transition to next state.", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "scale multiplier", "This value will be multiplied into the scale computed by the particles' state." },
		{ _field_real, "animation_rate_multiplier", "This value will be multiplied into the animation rate computed by the particles' state." },
		{ _field_real, "rotation rate multiplier", "This value will be multiplied into the rotation rate computed by the particles' state." },
		{ _field_real_argb_color, "color multiplier", "This value will be multiplied into the color computed by the particles' state." },
		{ _field_real, "radius multiplier", "This value will be multiplied into the radius computed by the type." },
		{ _field_real, "minimum particle count" },
		{ _field_real, "particle creation rate", nullptr, "particles per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_short_enum, "particle creation physics", "This controls the placement of particles created during this state.", &blofeld::halo1::unnamed_enum$108 },
		{ _field_short_enum, "particle update physics", "This controls the motion of particles during this state.", &blofeld::halo1::unnamed_enum$109 },
		{ _field_block, "physics constants", &blofeld::halo1::particle_system_physics_constants_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$109)
	{
		"default"
	};
	STRING_LIST(unnamed_enum$109, unnamed_enum$109_strings, _countof(unnamed_enum$109_strings));


	TAG_GROUP(
		preferences_network_game_group,
		PREFERENCES_NETWORK_GAME_TAG,
		nullptr,
		INVALID_TAG,
		preferences_network_game);

	TAG_BLOCK(
		preferences_network_game,
		"preferences_network_game_group_block",
		1,
		"s_preferences_network_game",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name" },
		{ _field_real_rgb_color, "primary color" },
		{ _field_real_rgb_color, "secondary color" },
		{ _field_tag_reference, "pattern", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "bitmap index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "decal", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "bitmap index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 800),
		{ _field_terminator }
	};


	TAG_GROUP(
		projectile_group,
		PROJECTILE_TAG,
		&object_group,
		OBJECT_TAG,
		projectile);

	TAG_BLOCK(
		projectile,
		"projectile_group_block",
		1,
		"s_projectile",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "object", &blofeld::halo1::object_struct_definition },
		FIELD_EXPLANATION_EX("$$$ PROJECTILE $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$110 },
		{ _field_short_enum, "detonation timer starts", &blofeld::halo1::unnamed_enum$111 },
		{ _field_short_enum, "impact noise", &blofeld::halo1::unnamed_enum$23 },
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$112 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$112 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$112 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$112 },
		{ _field_tag_reference, "super detonation", &blofeld::halo1::effect_reference },
		{ _field_real, "AI perception radius", nullptr, "world units" },
		{ _field_real, "collision radius", nullptr, "world units" },
		FIELD_EXPLANATION_EX("detonation", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "arming time", "won't detonate before this time elapses", "seconds" },
		{ _field_real, "danger radius", nullptr, "world units" },
		{ _field_tag_reference, "effect", &blofeld::halo1::effect_reference },
		{ _field_real_bounds, "timer", "detonation countdown (zero is untimed)", "seconds" },
		{ _field_real, "minimum velocity", "detonates when slowed below this velocity", "world units per second" },
		{ _field_real, "maximum range", "detonates after travelling this distance", "world units" },
		FIELD_EXPLANATION_EX("physics", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "air gravity scale", "the proportion of normal gravity applied to the projectile when in air." },
		{ _field_real_bounds, "air damage range", "the range over which damage is scaled when the projectile is in air.", "world units" },
		{ _field_real, "water gravity scale", "the proportion of normal gravity applied to the projectile when in water." },
		{ _field_real_bounds, "water damage range", "the range over which damage is scaled when the projectile is in water.", "world units" },
		{ _field_real, "initial velocity", "bullet's velocity when inflicting maximum damage", "world units per second" },
		{ _field_real, "final velocity", "bullet's velocity when inflicting minimum damage", "world units per second" },
		{ _field_angle, "guided angular velocity", nullptr, "degrees per second" },
		{ _field_short_enum, "detonation noise", &blofeld::halo1::unnamed_enum$23 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "detonation started", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "flyby sound", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "attached detonation damage", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "impact damage", &blofeld::halo1::damage_effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "material responses", &blofeld::halo1::projectile_material_response_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$110)
	{
		"oriented along velocity",
		"AI must use ballistic aiming",
		"detonation max time if attached",
		"has super combining explosion",
		"combine initial velocity with parent velocity",
		"random attached detonation time",
		"minimum unattached detonation time"
	};
	STRING_LIST(unnamed_enum$110, unnamed_enum$110_strings, _countof(unnamed_enum$110_strings));

	STRINGS(unnamed_enum$111)
	{
		"immediately",
		"after first bounce",
		"when at rest"
	};
	STRING_LIST(unnamed_enum$111, unnamed_enum$111_strings, _countof(unnamed_enum$111_strings));

	STRINGS(unnamed_enum$23)
	{
		"silent",
		"medium",
		"loud",
		"shout",
		"quiet"
	};
	STRING_LIST(unnamed_enum$23, unnamed_enum$23_strings, _countof(unnamed_enum$23_strings));

	STRINGS(unnamed_enum$112)
	{
		"none",
		"range remaining",
		"time remaining",
		"tracer"
	};
	STRING_LIST(unnamed_enum$112, unnamed_enum$112_strings, _countof(unnamed_enum$112_strings));

	TAG_BLOCK(
		projectile_material_response_block,
		"projectile_material_response_block",
		33,
		"s_projectile_material_response_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$113 },
		FIELD_EXPLANATION_EX("default result", nullptr, FIELD_FLAG_NONE, "(if the potential result, below, fails to happen)"),
		{ _field_short_enum, "response", &blofeld::halo1::unnamed_enum$114 },
		{ _field_tag_reference, "effect", &blofeld::halo1::effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("potential result", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "response", &blofeld::halo1::unnamed_enum$114 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$115 },
		{ _field_real_fraction, "skip fraction", nullptr, nullptr, "[0,1]" },
		{ _field_angle_bounds, "between", nullptr, "degrees" },
		{ _field_real_bounds, "and", nullptr, "world units per second" },
		{ _field_tag_reference, "effect", &blofeld::halo1::effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("misc", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "scale effects by", &blofeld::halo1::unnamed_enum$116 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_angle, "angular noise", "the angle of incidence is randomly perturbed by at most this amount to simulate irregularity.", "degrees" },
		{ _field_real, "velocity noise", "the velocity is randomly perturbed by at most this amount to simulate irregularity.", "world units per second" },
		{ _field_tag_reference, "detonation effect", &blofeld::halo1::effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("penetration", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "initial friction", "the fraction of the projectile's velocity lost on penetration" },
		{ _field_real, "maximum distance", "the maximum distance the projectile can travel through on object of this material" },
		FIELD_EXPLANATION_EX("reflection", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "parallel friction", "the fraction of the projectile's velocity parallel to the surface lost on impact" },
		{ _field_real, "perpendicular friction", "the fraction of the projectile's velocity perpendicular to the surface lost on impact" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$113)
	{
		"cannot be overpenetrated"
	};
	STRING_LIST(unnamed_enum$113, unnamed_enum$113_strings, _countof(unnamed_enum$113_strings));

	STRINGS(unnamed_enum$114)
	{
		"disappear",
		"detonate",
		"reflect",
		"overpenetrate",
		"attach"
	};
	STRING_LIST(unnamed_enum$114, unnamed_enum$114_strings, _countof(unnamed_enum$114_strings));

	STRINGS(unnamed_enum$115)
	{
		"only against units"
	};
	STRING_LIST(unnamed_enum$115, unnamed_enum$115_strings, _countof(unnamed_enum$115_strings));

	STRINGS(unnamed_enum$116)
	{
		"damage",
		"angle"
	};
	STRING_LIST(unnamed_enum$116, unnamed_enum$116_strings, _countof(unnamed_enum$116_strings));


	TAG_GROUP(
		model_collision_geometry_group,
		MODEL_COLLISION_GEOMETRY_TAG,
		nullptr,
		INVALID_TAG,
		model_collision_geometry);

	TAG_BLOCK(
		model_collision_geometry,
		"model_collision_geometry_group_block",
		1,
		"s_model_collision_geometry",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$117 },
		{ _field_short_block_index, "indirect damage material", "the material we use when shielding child objects or getting hit by area of effect damage", &blofeld::halo1::damage_materials_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("body", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "maximum body vitality", "the default initial and maximum body vitality of this object" },
		{ _field_real, "body system shock", "anything that kills us (body depleted) doing more than this amount of damage also destroys us" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_real_fraction, "friendly damage resistance", "the fraction of damage caused by friendly units ignored by this object (zero means full damage)", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "localized damage effect", &blofeld::halo1::effect_reference },
		{ _field_real, "area damage effect threshold", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "area damage effect", &blofeld::halo1::effect_reference },
		{ _field_real, "body damaged threshold", "when passing this vitality the 'body damaged' effect, below, is created" },
		{ _field_tag_reference, "body damaged effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "body depleted effect", &blofeld::halo1::effect_reference },
		{ _field_real, "body destroyed threshold", "when passing this vitality (usually negative) the object is deleted" },
		{ _field_tag_reference, "body destroyed effect", &blofeld::halo1::effect_reference },
		FIELD_EXPLANATION_EX("shield", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "maximum shield vitality", "the default initial and maximum shield vitality of this object" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "shield material type", "the material type used when projectiles impact the shield (instead of the body)", &blofeld::halo1::unnamed_enum$119 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_short_enum, "shield failure function", "how fast the shield begins to leak", &blofeld::halo1::unnamed_enum$43 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "shield failure threshold", "when the shield begins to leak (0.5 would cause the shield to begin to fail after taking half damage)" },
		{ _field_real_fraction, "failing shield leak fraction", "the maximum percent [0,1] damage a failing shield will leak to the body" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real, "minimum stun damage", "the minimum damage required to stun this object's shields" },
		{ _field_real, "stun time", "the length of time the shields stay stunned (do not recharge) after taking damage", "seconds" },
		{ _field_real, "recharge time", "the length of time it would take for the shields to fully recharge after being completely depleted", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 96),
		{ _field_real, "shield damaged threshold" },
		{ _field_tag_reference, "shield damaged effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "shield depleted effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "shield recharging effect", &blofeld::halo1::effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 112),
		{ _field_block, "materials", FIELD_FLAG_READ_ONLY, &blofeld::halo1::damage_materials_block },
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &blofeld::halo1::damage_regions_block },
		{ _field_block, "modifiers", &blofeld::halo1::damage_modifiers_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("pathfinding box", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "x" },
		{ _field_real_bounds, "y" },
		{ _field_real_bounds, "z" },
		{ _field_block, "pathfinding spheres", &blofeld::halo1::sphere },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::node },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$117)
	{
		"takes shield damage for children",
		"takes body damage for children",
		"always shields friendly damage",
		"passes area damage to children",
		"parent never takes body damage for us",
		"only damaged by explosives",
		"only damaged while occupied"
	};
	STRING_LIST(unnamed_enum$117, unnamed_enum$117_strings, _countof(unnamed_enum$117_strings));

	STRINGS(unnamed_enum$119)
	{
		"dirt",
		"sand",
		"stone",
		"snow",
		"wood",
		"metal (hollow)",
		"metal (thin)",
		"metal (thick)",
		"rubber",
		"glass",
		"force field",
		"grunt",
		"hunter armor",
		"hunter skin",
		"elite",
		"jackal",
		"jackal energy shield",
		"engineer skin",
		"engineer force field",
		"flood combat form",
		"flood carrier form",
		"cyborg armor",
		"cyborg energy shield",
		"human armor",
		"human skin",
		"sentinel",
		"monitor",
		"plastic",
		"water",
		"leaves",
		"elite energy shield",
		"ice",
		"hunter shield"
	};
	STRING_LIST(unnamed_enum$119, unnamed_enum$119_strings, _countof(unnamed_enum$119_strings));

	TAG_BLOCK(
		node,
		"node",
		64,
		"s_node",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_block_index, "region", FIELD_FLAG_READ_ONLY, &blofeld::halo1::damage_regions_block },
		{ _field_short_block_index, "parent node", FIELD_FLAG_READ_ONLY, &blofeld::halo1::node },
		{ _field_short_block_index, "next sibling node", FIELD_FLAG_READ_ONLY, &blofeld::halo1::node },
		{ _field_short_block_index, "first child node", FIELD_FLAG_READ_ONLY, &blofeld::halo1::node },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "bsps", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp },
		{ _field_terminator }
	};

	TAG_BLOCK(
		bsp,
		"bsp",
		32,
		"s_bsp",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "bsp3d nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp3d_node },
		{ _field_block, "planes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::plane },
		{ _field_block, "leaves", FIELD_FLAG_READ_ONLY, &blofeld::halo1::leaf },
		{ _field_block, "bsp2d references", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp2d_reference },
		{ _field_block, "bsp2d nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp2d_node },
		{ _field_block, "surfaces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::surface },
		{ _field_block, "edges", FIELD_FLAG_READ_ONLY, &blofeld::halo1::edge },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::vertex },
		{ _field_terminator }
	};

	TAG_BLOCK(
		vertex,
		"vertex",
		131072,
		"s_vertex",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "point", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "first edge", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		edge,
		"edge",
		262144,
		"s_edge",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "start vertex", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "end vertex", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "forward edge", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "reverse edge", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "left surface", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "right surface", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		surface,
		"surface",
		131072,
		"s_surface",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "first edge", FIELD_FLAG_READ_ONLY },
		{ _field_byte_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$122 },
		{ _field_char_integer, "breakable surface", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "material", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$122)
	{
		"two sided",
		"invisible",
		"climbable",
		"breakable"
	};
	STRING_LIST(unnamed_enum$122, unnamed_enum$122_strings, _countof(unnamed_enum$122_strings));

	TAG_BLOCK(
		bsp2d_node,
		"bsp2d node",
		65535,
		"s_bsp2d_node",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_plane_2d, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "left child", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "right child", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		bsp2d_reference,
		"bsp2d reference",
		131072,
		"s_bsp2d_reference",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_block_index, "plane", FIELD_FLAG_READ_ONLY, &blofeld::halo1::plane },
		{ _field_long_block_index, "bsp2d node", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp2d_node },
		{ _field_terminator }
	};

	TAG_BLOCK(
		leaf,
		"leaf",
		65536,
		"s_leaf",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$121 },
		{ _field_short_integer, "bsp2d reference count", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "first bsp2d reference", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$121)
	{
		"contains double-sided surfaces"
	};
	STRING_LIST(unnamed_enum$121, unnamed_enum$121_strings, _countof(unnamed_enum$121_strings));

	TAG_BLOCK(
		plane,
		"plane",
		65536,
		"s_plane",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_plane_3d, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		bsp3d_node,
		"bsp3d node",
		131072,
		"s_bsp3d_node",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "back child", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "front child", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		sphere,
		"sphere",
		32,
		"s_sphere",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "node", &blofeld::halo1::node },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_point_3d, "center" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		damage_modifiers_block,
		"damage_modifiers_block",
		0,
		"s_damage_modifiers_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		{ _field_terminator }
	};

	TAG_BLOCK(
		damage_regions_block,
		"damage_regions_block",
		8,
		"s_damage_regions_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$120 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "damage threshold", "if this region takes this amount of damage, it will be destroyed" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_tag_reference, "destroyed effect", &blofeld::halo1::effect_reference },
		{ _field_block, "permutations", &blofeld::halo1::damage_permutations_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$120)
	{
		"lives until object dies",
		"forces object to die",
		"dies when object dies",
		"dies when object is damaged",
		"disappears when shield is off",
		"inhibits melee attack",
		"inhibits weapon attack",
		"inhibits walking",
		"forces drop weapon",
		"causes head-maimed scream"
	};
	STRING_LIST(unnamed_enum$120, unnamed_enum$120_strings, _countof(unnamed_enum$120_strings));

	TAG_BLOCK(
		damage_permutations_block,
		"damage_permutations_block",
		32,
		"s_damage_permutations_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	TAG_BLOCK(
		damage_materials_block,
		"damage_materials_block",
		32,
		"s_damage_materials_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$118 },
		{ _field_short_enum, "material type", &blofeld::halo1::unnamed_enum$119 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "shield leak percentage", "the percent [0,1] damage the shield always leaks through to the body" },
		{ _field_real, "shield damage multiplier" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "body damage multiplier", "multiplier to body damage against this material (1.0 is normal)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$118)
	{
		"head"
	};
	STRING_LIST(unnamed_enum$118, unnamed_enum$118_strings, _countof(unnamed_enum$118_strings));


	TAG_GROUP(
		device_group,
		DEVICE_TAG,
		&object_group,
		OBJECT_TAG,
		device);

	TAG_BLOCK(
		device,
		"device_group_block",
		1,
		"s_device",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "object", &blofeld::halo1::object_struct_definition },
		FIELD_EXPLANATION_EX("$$$ DEVICE $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$123 },
		{ _field_real, "power transition time", nullptr, "seconds" },
		{ _field_real, "power acceleration time", nullptr, "seconds" },
		{ _field_real, "position transition time", nullptr, "seconds" },
		{ _field_real, "position acceleration time", nullptr, "seconds" },
		{ _field_real, "depowered position transition time", nullptr, "seconds" },
		{ _field_real, "depowered position acceleration time", nullptr, "seconds" },
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$124 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$124 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$124 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$124 },
		{ _field_tag_reference, "open (up)", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_tag_reference, "close (down)", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_tag_reference, "opened", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_tag_reference, "closed", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_tag_reference, "depowered", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_tag_reference, "repowered", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_real, "delay time", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_tag_reference, "delay effect", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_real, "automatic activation radius", nullptr, "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$123)
	{
		"position loops",
		"position not interpolated"
	};
	STRING_LIST(unnamed_enum$123, unnamed_enum$123_strings, _countof(unnamed_enum$123_strings));

	STRINGS(unnamed_enum$124)
	{
		"none",
		"power",
		"change in power",
		"position",
		"change in position",
		"locked",
		"delay"
	};
	STRING_LIST(unnamed_enum$124, unnamed_enum$124_strings, _countof(unnamed_enum$124_strings));

	TAG_REFERENCE_GROUP(sound_effect_reference$3)
	{
		SOUND_TAG,
		EFFECT_TAG,
		INVALID_TAG
	};


	TAG_GROUP(
		device_machine_group,
		DEVICE_MACHINE_TAG,
		&device_group,
		DEVICE_TAG,
		device_machine);

	TAG_BLOCK(
		device_machine,
		"device_machine_group_block",
		1,
		"s_device_machine",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "device", &blofeld::halo1::device_struct_definition },
		FIELD_EXPLANATION_EX("$$$ MACHINE $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$125 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$126 },
		{ _field_real, "door open time", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 80),
		{ _field_short_enum, "collision response", &blofeld::halo1::unnamed_enum$127 },
		{ _field_short_integer, "elevator node" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$125)
	{
		"door",
		"platform",
		"gear"
	};
	STRING_LIST(unnamed_enum$125, unnamed_enum$125_strings, _countof(unnamed_enum$125_strings));

	STRINGS(unnamed_enum$126)
	{
		"pathfinding obstacle",
		"...but not when open",
		"elevator#lighting based on what\'s around, rather than what\'s below"
	};
	STRING_LIST(unnamed_enum$126, unnamed_enum$126_strings, _countof(unnamed_enum$126_strings));

	STRINGS(unnamed_enum$127)
	{
		"pause until crushed",
		"reverse directions"
	};
	STRING_LIST(unnamed_enum$127, unnamed_enum$127_strings, _countof(unnamed_enum$127_strings));


	TAG_GROUP(
		device_control_group,
		DEVICE_CONTROL_TAG,
		&device_group,
		DEVICE_TAG,
		device_control);

	TAG_BLOCK(
		device_control,
		"device_control_group_block",
		1,
		"s_device_control",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "device", &blofeld::halo1::device_struct_definition },
		FIELD_EXPLANATION_EX("$$$ CONTROL $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$128 },
		{ _field_short_enum, "triggers when", &blofeld::halo1::unnamed_enum$129 },
		{ _field_real, "call value", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 80),
		{ _field_tag_reference, "on", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_tag_reference, "off", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_tag_reference, "deny", &blofeld::halo1::sound_effect_reference$3 },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$128)
	{
		"toggle switch",
		"on button",
		"off button",
		"call button"
	};
	STRING_LIST(unnamed_enum$128, unnamed_enum$128_strings, _countof(unnamed_enum$128_strings));

	STRINGS(unnamed_enum$129)
	{
		"touched by player",
		"destroyed"
	};
	STRING_LIST(unnamed_enum$129, unnamed_enum$129_strings, _countof(unnamed_enum$129_strings));


	TAG_GROUP(
		device_light_fixture_group,
		DEVICE_LIGHT_FIXTURE_TAG,
		&device_group,
		DEVICE_TAG,
		device_light_fixture);

	TAG_BLOCK(
		device_light_fixture,
		"device_light_fixture_group_block",
		1,
		"s_device_light_fixture",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "device", &blofeld::halo1::device_struct_definition },
		FIELD_EXPLANATION_EX("$$$ LIGHT FIXTURE $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		{ _field_terminator }
	};


	TAG_GROUP(
		point_physics_group,
		POINT_PHYSICS_TAG,
		nullptr,
		INVALID_TAG,
		point_physics);

	TAG_BLOCK(
		point_physics,
		"point_physics_group_block",
		1,
		"s_point_physics",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$130 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_real, "density", nullptr, "g/mL" },
		{ _field_real, "air friction" },
		{ _field_real, "water friction" },
		{ _field_real, "surface friction", "when hitting the ground or interior, percentage of velocity lost in one collision" },
		{ _field_real, "elasticity", "0.0 is inelastic collisions (no bounce) 1.0 is perfectly elastic (reflected velocity equals incoming velocity)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("Densities (g/mL)", nullptr, FIELD_FLAG_NONE, "air        0.0011 (g/mL)\nsnow       0.128\ncork       0.24\ncedar      0.43\noak        0.866\nice        0.897\nwater      1.0\nsoil       1.1\ncotton     1.491\ndry earth  1.52\nsand       1.7\ngranite    2.4\nglass      2.5\niron       7.65\nsteel      7.77\nlead       11.37\nuranium    18.74\ngold       19.3\n"),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$130)
	{
		"flamethrower particle collision",
		"collides with structures",
		"collides with water surface",
		"uses simple wind#the wind on this point won\'t have high-frequency variations",
		"uses damped wind#the wind on this point will be artificially slow",
		"no gravity#the point is not affected by gravity"
	};
	STRING_LIST(unnamed_enum$130, unnamed_enum$130_strings, _countof(unnamed_enum$130_strings));


	TAG_GROUP(
		scenario_structure_bsp_group,
		SCENARIO_STRUCTURE_BSP_TAG,
		nullptr,
		INVALID_TAG,
		scenario_structure_bsp);

	TAG_BLOCK(
		scenario_structure_bsp,
		"scenario_structure_bsp_group_block",
		1,
		"s_scenario_structure_bsp",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "lightmaps", &blofeld::halo1::bitmap_reference },
		{ _field_real, "vehicle floor", "height below which vehicles get pushed up by an unstoppable force", "world units" },
		{ _field_real, "vehicle ceiling", "height above which vehicles get pushed down by an unstoppable force", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_real_rgb_color, "default ambient color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_rgb_color, "default distant light 0 color" },
		{ _field_real_vector_3d, "default distant light 0 direction" },
		{ _field_real_rgb_color, "default distant light 1 color" },
		{ _field_real_vector_3d, "default distant light 1 direction" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_argb_color, "default reflection tint" },
		{ _field_real_vector_3d, "default shadow vector" },
		{ _field_real_rgb_color, "default shadow color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_block, "collision materials", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_collision_materials_block },
		{ _field_block, "collision bsp", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp$2 },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_node_block },
		{ _field_real_bounds, "world bounds x", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "world bounds y", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "world bounds z", FIELD_FLAG_READ_ONLY },
		{ _field_block, "leaves", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_leaf_block },
		{ _field_block, "leaf surfaces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_surface_reference_block },
		{ _field_block, "surfaces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_surface_block },
		{ _field_block, "lightmaps", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_lightmap_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "lens flares", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_lens_flare_block },
		{ _field_block, "lens flare markers", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_lens_flare_marker_block },
		{ _field_block, "clusters", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_block },
		{ _field_data, "cluster data", FIELD_FLAG_READ_ONLY },
		{ _field_block, "cluster portals", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_portal_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "breakable surfaces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_breakable_surface_block },
		{ _field_block, "fog planes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_fog_plane_block },
		{ _field_block, "fog regions", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_fog_region_block },
		{ _field_block, "fog palette", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_fog_palette_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "weather palette", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_weather_palette_block },
		{ _field_block, "weather polyhedra", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_weather_polyhedron_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "pathfinding surfaces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_pathfinding_surfaces_block },
		{ _field_block, "pathfinding edges", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_pathfinding_edges_block },
		{ _field_block, "background sound palette", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_background_sound_palette_block },
		{ _field_block, "sound environment palette", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_sound_environment_palette_block },
		{ _field_data, "sound PAS data", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "markers", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_marker_block },
		{ _field_block, "detail objects", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_detail_object_data_block },
		{ _field_block, "runtime decals", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_runtime_decal_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_block, "leaf map leaves", &blofeld::halo1::global_map_leaf_block },
		{ _field_block, "leaf map portals", &blofeld::halo1::global_leaf_portal_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		global_leaf_portal_block,
		"global_leaf_portal_block",
		524288,
		"s_global_leaf_portal_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "plane index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "back leaf index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "front leaf index", FIELD_FLAG_READ_ONLY },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::leaf_portal_vertex_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		leaf_portal_vertex_block,
		"leaf_portal_vertex_block",
		64,
		"s_leaf_portal_vertex_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		global_map_leaf_block,
		"global_map_leaf_block",
		65536,
		"s_global_map_leaf_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "faces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::map_leaf_face_block },
		{ _field_block, "portal indices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::map_leaf_portal_index_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		map_leaf_portal_index_block,
		"map_leaf_portal_index_block",
		256,
		"s_map_leaf_portal_index_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "portal index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		map_leaf_face_block,
		"map_leaf_face_block",
		256,
		"s_map_leaf_face_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "node index", FIELD_FLAG_READ_ONLY },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::map_leaf_face_vertex_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		map_leaf_face_vertex_block,
		"map_leaf_face_vertex_block",
		64,
		"s_map_leaf_face_vertex_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_2d, "vertex", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_runtime_decal_block,
		"structure_bsp_runtime_decal_block",
		6144,
		"s_structure_bsp_runtime_decal_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_SKIP_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_detail_object_data_block,
		"structure_bsp_detail_object_data_block",
		1,
		"s_structure_bsp_detail_object_data_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "cells", &blofeld::halo1::global_detail_object_cells_block },
		{ _field_block, "instances", &blofeld::halo1::global_detail_object_block },
		{ _field_block, "counts", &blofeld::halo1::global_detail_object_counts_block },
		{ _field_block, "z reference vectors", &blofeld::halo1::global_z_reference_vector_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	TAG_BLOCK(
		global_z_reference_vector_block,
		"global_z_reference_vector_block",
		262144,
		"s_global_z_reference_vector_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real, "value", FIELD_FLAG_READ_ONLY },
		{ _field_real, "value", FIELD_FLAG_READ_ONLY },
		{ _field_real, "value", FIELD_FLAG_READ_ONLY },
		{ _field_real, "value", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		global_detail_object_counts_block,
		"global_detail_object_counts_block",
		8388608,
		"s_global_detail_object_counts_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		global_detail_object_block,
		"global_detail_object_block",
		2097152,
		"s_global_detail_object_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_char_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		global_detail_object_cells_block,
		"global_detail_object_cells_block",
		262144,
		"s_global_detail_object_cells_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "value", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "value", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_marker_block,
		"structure_bsp_marker_block",
		1024,
		"s_structure_bsp_marker_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY },
		{ _field_real_quaternion, "rotation" },
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_sound_environment_palette_block,
		"structure_bsp_sound_environment_palette_block",
		64,
		"s_structure_bsp_sound_environment_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "sound environment", &blofeld::halo1::sound_environment_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(sound_environment_reference, SOUND_ENVIRONMENT_TAG);

	TAG_BLOCK(
		structure_bsp_background_sound_palette_block,
		"structure_bsp_background_sound_palette_block",
		64,
		"s_structure_bsp_background_sound_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "background sound", &blofeld::halo1::sound_looping_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "scale function" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(sound_looping_reference, SOUND_LOOPING_TAG);

	TAG_BLOCK(
		structure_bsp_pathfinding_edges_block,
		"structure_bsp_pathfinding_edges_block",
		262144,
		"s_structure_bsp_pathfinding_edges_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_char_integer, "midpoint", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_pathfinding_surfaces_block,
		"structure_bsp_pathfinding_surfaces_block",
		131072,
		"s_structure_bsp_pathfinding_surfaces_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_char_integer, "data", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_weather_polyhedron_block,
		"structure_bsp_weather_polyhedron_block",
		32,
		"s_structure_bsp_weather_polyhedron_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "bounding sphere center", FIELD_FLAG_READ_ONLY },
		{ _field_real, "bounding sphere radius", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_block, "planes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_weather_polyhedron_plane_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_weather_polyhedron_plane_block,
		"structure_bsp_weather_polyhedron_plane_block",
		16,
		"s_structure_bsp_weather_polyhedron_plane_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_plane_3d, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_weather_palette_block,
		"structure_bsp_weather_palette_block",
		32,
		"s_structure_bsp_weather_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "particle system", &blofeld::halo1::weather_particle_system_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "particle system scale function" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_tag_reference, "wind", &blofeld::halo1::wind_reference },
		{ _field_real_vector_3d, "wind direction" },
		{ _field_real, "wind magnitude" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "wind scale function" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_terminator }
	};

	TAG_REFERENCE(weather_particle_system_reference, WEATHER_PARTICLE_SYSTEM_TAG);

	TAG_REFERENCE(wind_reference, WIND_TAG);

	TAG_BLOCK(
		structure_bsp_fog_palette_block,
		"structure_bsp_fog_palette_block",
		32,
		"s_structure_bsp_fog_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "fog", &blofeld::halo1::fog_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "fog scale function" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		{ _field_terminator }
	};

	TAG_REFERENCE(fog_reference, FOG_TAG);

	TAG_BLOCK(
		structure_bsp_fog_region_block,
		"structure_bsp_fog_region_block",
		32,
		"s_structure_bsp_fog_region_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_short_block_index, "fog palette", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_fog_palette_block },
		{ _field_short_block_index, "weather palette", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_weather_palette_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_fog_plane_block,
		"structure_bsp_fog_plane_block",
		32,
		"s_structure_bsp_fog_plane_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "front region", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_fog_region_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_plane_3d, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_fog_plane_vertex_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_fog_plane_vertex_block,
		"structure_bsp_fog_plane_vertex_block",
		4096,
		"s_structure_bsp_fog_plane_vertex_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_breakable_surface_block,
		"structure_bsp_breakable_surface_block",
		256,
		"s_structure_bsp_breakable_surface_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "centroid", FIELD_FLAG_READ_ONLY },
		{ _field_real, "radius", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "collision surface index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_cluster_portal_block,
		"structure_bsp_cluster_portal_block",
		512,
		"s_structure_bsp_cluster_portal_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "front cluster", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_block },
		{ _field_short_block_index, "back cluster", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_block },
		{ _field_long_integer, "plane index", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "centroid", FIELD_FLAG_READ_ONLY },
		{ _field_real, "bounding radius", FIELD_FLAG_READ_ONLY },
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$132 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_portal_vertex_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$132)
	{
		"ai can\'t hear through this shit"
	};
	STRING_LIST(unnamed_enum$132, unnamed_enum$132_strings, _countof(unnamed_enum$132_strings));

	TAG_BLOCK(
		structure_bsp_cluster_portal_vertex_block,
		"structure_bsp_cluster_portal_vertex_block",
		128,
		"s_structure_bsp_cluster_portal_vertex_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_cluster_block,
		"structure_bsp_cluster_block",
		8192,
		"s_structure_bsp_cluster_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "sky", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "fog", FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "background sound", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_background_sound_palette_block },
		{ _field_short_block_index, "sound environment", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_sound_environment_palette_block },
		{ _field_short_block_index, "weather", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_weather_palette_block },
		{ _field_short_integer, "transition structure bsp" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "predicted resources", FIELD_FLAG_READ_ONLY, &blofeld::halo1::predicted_resource_block },
		{ _field_block, "subclusters", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_subcluster_block },
		{ _field_short_integer, "first lens flare marker index", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "lens flare marker count", FIELD_FLAG_READ_ONLY },
		{ _field_block, "surface indices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_surface_index_block },
		{ _field_block, "mirrors", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_mirror_block },
		{ _field_block, "portals", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_portal_index_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_cluster_portal_index_block,
		"structure_bsp_cluster_portal_index_block",
		128,
		"s_structure_bsp_cluster_portal_index_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "portal", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_cluster_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_mirror_block,
		"structure_bsp_mirror_block",
		16,
		"s_structure_bsp_mirror_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_plane_3d, "plane", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "shader", FIELD_FLAG_READ_ONLY, &blofeld::halo1::shader_reference },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_mirror_vertex_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_mirror_vertex_block,
		"structure_bsp_mirror_vertex_block",
		512,
		"s_structure_bsp_mirror_vertex_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "point", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_cluster_surface_index_block,
		"structure_bsp_cluster_surface_index_block",
		32768,
		"s_structure_bsp_cluster_surface_index_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_subcluster_block,
		"structure_bsp_subcluster_block",
		4096,
		"s_structure_bsp_subcluster_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_bounds, "world bounds x", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "world bounds y", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "world bounds z", FIELD_FLAG_READ_ONLY },
		{ _field_block, "surface indices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_subcluster_surface_index_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_subcluster_surface_index_block,
		"structure_bsp_subcluster_surface_index_block",
		128,
		"s_structure_bsp_subcluster_surface_index_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_integer, "index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_lens_flare_marker_block,
		"structure_bsp_lens_flare_marker_block",
		65536,
		"s_structure_bsp_lens_flare_marker_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "direction i-component", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "direction j-component", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "direction k-component", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "lens flare index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_lens_flare_block,
		"structure_bsp_lens_flare_block",
		256,
		"s_structure_bsp_lens_flare_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "lens flare", &blofeld::halo1::lens_flare_reference$2 },
		{ _field_terminator }
	};

	TAG_REFERENCE(lens_flare_reference$2, LENS_FLARE_TAG);

	TAG_BLOCK(
		structure_bsp_lightmap_block,
		"structure_bsp_lightmap_block",
		128,
		"s_structure_bsp_lightmap_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "bitmap", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_block, "materials", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_material_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_material_block,
		"structure_bsp_material_block",
		2048,
		"s_structure_bsp_material_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "shader", FIELD_FLAG_READ_ONLY, &blofeld::halo1::shader_reference },
		{ _field_short_integer, "shader permutation", FIELD_FLAG_READ_ONLY },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$131 },
		{ _field_long_block_index, "surfaces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_surface_block },
		{ _field_long_integer, "surface count", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "centroid", FIELD_FLAG_READ_ONLY },
		{ _field_real_rgb_color, "ambient color", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "distant light count", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_rgb_color, "distant light 0 color", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "distant light 0 direction", FIELD_FLAG_READ_ONLY },
		{ _field_real_rgb_color, "distant light 1 color", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "distant light 1 direction", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_argb_color, "reflection tint", FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "shadow vector", FIELD_FLAG_READ_ONLY },
		{ _field_real_rgb_color, "shadow color", FIELD_FLAG_READ_ONLY },
		{ _field_real_plane_3d, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "breakable surface", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_array, "vertex buffers", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_material_block__vertex_buffers_array },
		{ _field_data, "uncompressed vertices" },
		{ _field_data, "compressed vertices" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$131)
	{
		"coplanar*",
		"fog plane*"
	};
	STRING_LIST(unnamed_enum$131, unnamed_enum$131_strings, _countof(unnamed_enum$131_strings));

	TAG_ARRAY(
		structure_bsp_material_block__vertex_buffers_array,
		"structure_bsp_material_block | vertex buffers* array",
		2,
		"s_structure_bsp_material_block__vertex_buffers_array",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_long_integer, "count", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "offset", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_surface_block,
		"structure_bsp_surface_block",
		131072,
		"s_structure_bsp_surface_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_array, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_surface_block__vertices_array },
		{ _field_terminator }
	};

	TAG_ARRAY(
		structure_bsp_surface_block__vertices_array,
		"structure_bsp_surface_block | vertices* array",
		3,
		"s_structure_bsp_surface_block__vertices_array",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "a" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_surface_reference_block,
		"structure_bsp_surface_reference_block",
		262144,
		"s_structure_bsp_surface_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_block_index, "surface", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_surface_block },
		{ _field_long_block_index, "node", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_node_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_leaf_block,
		"structure_bsp_leaf_block",
		65536,
		"s_structure_bsp_leaf_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_SKIP_EX("value", nullptr, FIELD_FLAG_NONE, 6),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "cluster", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "surface reference count", FIELD_FLAG_READ_ONLY },
		{ _field_long_block_index, "surface references", FIELD_FLAG_READ_ONLY, &blofeld::halo1::structure_bsp_surface_reference_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_bsp_node_block,
		"structure_bsp_node_block",
		131072,
		"s_structure_bsp_node_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_SKIP_EX("value", nullptr, FIELD_FLAG_NONE, 6),
		{ _field_terminator }
	};

	TAG_BLOCK(
		bsp$2,
		"bsp",
		1,
		"s_bsp$2",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "bsp3d nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp3d_node },
		{ _field_block, "planes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::plane },
		{ _field_block, "leaves", FIELD_FLAG_READ_ONLY, &blofeld::halo1::leaf },
		{ _field_block, "bsp2d references", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp2d_reference },
		{ _field_block, "bsp2d nodes", FIELD_FLAG_READ_ONLY, &blofeld::halo1::bsp2d_node },
		{ _field_block, "surfaces", FIELD_FLAG_READ_ONLY, &blofeld::halo1::surface },
		{ _field_block, "edges", FIELD_FLAG_READ_ONLY, &blofeld::halo1::edge },
		{ _field_block, "vertices", FIELD_FLAG_READ_ONLY, &blofeld::halo1::vertex },
		{ _field_terminator }
	};

	TAG_BLOCK(
		structure_collision_materials_block,
		"structure_collision_materials_block",
		512,
		"s_structure_collision_materials_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "shader", FIELD_FLAG_READ_ONLY, &blofeld::halo1::shader_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};


	TAG_GROUP(
		scenario_group,
		SCENARIO_TAG,
		nullptr,
		INVALID_TAG,
		scenario);

	TAG_BLOCK(
		scenario,
		"scenario_group_block",
		1,
		"s_scenario",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "DON'T USE", &blofeld::halo1::scenario_structure_bsp_reference },
		{ _field_tag_reference, "WON'T USE", &blofeld::halo1::scenario_structure_bsp_reference },
		{ _field_tag_reference, "CAN'T USE", "set me!! me!!!  i do something cool!!!  you'll be happy forever if there this tag reference is filled in!  don't believe the lies!!! LIESSSS!!!!!!!!  YESS, MY PRECIOUSSSSS, LIESSSS...", &blofeld::halo1::sky_reference },
		{ _field_block, "skies", &blofeld::halo1::scenario_sky_reference_block },
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$133 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$134 },
		{ _field_block, "child scenarios", &blofeld::halo1::scenario_child_scenario_block },
		{ _field_angle, "local north" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 136),
		{ _field_block, "predicted resources", FIELD_FLAG_READ_ONLY, &blofeld::halo1::predicted_resource_block },
		{ _field_block, "functions", &blofeld::halo1::scenario_function_block },
		{ _field_data, "editor scenario data" },
		{ _field_block, "comments", &blofeld::halo1::editor_comment_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 224),
		{ _field_block, "object names", FIELD_FLAG_READ_ONLY, &blofeld::halo1::scenario_object_names_block },
		{ _field_block, "scenery", &blofeld::halo1::scenario_scenery_block },
		{ _field_block, "scenery palette", &blofeld::halo1::scenario_scenery_palette_block },
		{ _field_block, "bipeds", &blofeld::halo1::scenario_biped_block },
		{ _field_block, "biped palette", &blofeld::halo1::scenario_biped_palette_block },
		{ _field_block, "vehicles", &blofeld::halo1::scenario_vehicle_block },
		{ _field_block, "vehicle palette", &blofeld::halo1::scenario_vehicle_palette_block },
		{ _field_block, "equipment", &blofeld::halo1::scenario_equipment_block },
		{ _field_block, "equipment palette", &blofeld::halo1::scenario_equipment_palette_block },
		{ _field_block, "weapons", &blofeld::halo1::scenario_weapon_block },
		{ _field_block, "weapon palette", &blofeld::halo1::scenario_weapon_palette_block },
		{ _field_block, "device groups", &blofeld::halo1::device_group_block$2 },
		{ _field_block, "machines", &blofeld::halo1::scenario_machine_block },
		{ _field_block, "machine palette", &blofeld::halo1::scenario_machine_palette_block },
		{ _field_block, "controls", &blofeld::halo1::scenario_control_block },
		{ _field_block, "control palette", &blofeld::halo1::scenario_control_palette_block },
		{ _field_block, "light fixtures", &blofeld::halo1::scenario_light_fixture_block },
		{ _field_block, "light fixtures palette", &blofeld::halo1::scenario_light_fixture_palette_block },
		{ _field_block, "sound scenery", &blofeld::halo1::scenario_sound_scenery_block },
		{ _field_block, "sound scenery palette", &blofeld::halo1::scenario_sound_scenery_palette_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_block, "player starting profile", &blofeld::halo1::scenario_profiles_block },
		{ _field_block, "player starting locations", &blofeld::halo1::scenario_players_block },
		{ _field_block, "trigger volumes", &blofeld::halo1::scenario_trigger_volume_block },
		{ _field_block, "recorded animations", &blofeld::halo1::recorded_animation_block },
		{ _field_block, "netgame flags", &blofeld::halo1::scenario_netgame_flags_block },
		{ _field_block, "netgame equipment", &blofeld::halo1::scenario_netgame_equipment_block },
		{ _field_block, "starting equipment", &blofeld::halo1::scenario_starting_equipment_block },
		{ _field_block, "bsp switch trigger volumes", &blofeld::halo1::scenario_bsp_switch_trigger_volume_block },
		{ _field_block, "decals", &blofeld::halo1::scenario_decals_block },
		{ _field_block, "decal palette", &blofeld::halo1::scenario_decal_palette_block },
		{ _field_block, "detail object collection palette", &blofeld::halo1::scenario_detail_object_collection_palette_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_block, "actor palette", &blofeld::halo1::actor_palette_block },
		{ _field_block, "encounters", &blofeld::halo1::encounter_block },
		{ _field_block, "command lists", &blofeld::halo1::ai_command_list_block },
		{ _field_block, "ai animation references", &blofeld::halo1::ai_animation_reference_block },
		{ _field_block, "ai script references", &blofeld::halo1::ai_script_reference_block },
		{ _field_block, "ai recording references", &blofeld::halo1::ai_recording_reference_block },
		{ _field_block, "ai conversations", &blofeld::halo1::ai_conversation_block },
		{ _field_data, "script syntax data" },
		{ _field_data, "script string data" },
		{ _field_block, "scripts", FIELD_FLAG_READ_ONLY, &blofeld::halo1::hs_scripts_block },
		{ _field_block, "globals", FIELD_FLAG_READ_ONLY, &blofeld::halo1::hs_globals_block },
		{ _field_block, "references", FIELD_FLAG_READ_ONLY, &blofeld::halo1::hs_references_block },
		{ _field_block, "source files", FIELD_FLAG_READ_ONLY, &blofeld::halo1::hs_source_files_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "cutscene flags", &blofeld::halo1::scenario_cutscene_flag_block },
		{ _field_block, "cutscene camera points", &blofeld::halo1::scenario_cutscene_camera_point_block },
		{ _field_block, "cutscene titles", &blofeld::halo1::scenario_cutscene_title_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 108),
		{ _field_tag_reference, "custom object names", &blofeld::halo1::unicode_string_list_reference },
		{ _field_tag_reference, "ingame help text", &blofeld::halo1::unicode_string_list_reference },
		{ _field_tag_reference, "hud messages", &blofeld::halo1::hud_message_text_reference },
		{ _field_block, "structure bsps", &blofeld::halo1::scenario_structure_bsps_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(scenario_structure_bsp_reference, SCENARIO_STRUCTURE_BSP_TAG, _tag_reference_flag_dont_resolve_in_editor);

	TAG_REFERENCE(sky_reference, SKY_TAG);

	STRINGS(unnamed_enum$133)
	{
		"solo",
		"multiplayer",
		"main menu"
	};
	STRING_LIST(unnamed_enum$133, unnamed_enum$133_strings, _countof(unnamed_enum$133_strings));

	STRINGS(unnamed_enum$134)
	{
		"cortana hack#sort cortana in front of other transparent geometry",
		"use demo UI#uses alternate UI collection for demo"
	};
	STRING_LIST(unnamed_enum$134, unnamed_enum$134_strings, _countof(unnamed_enum$134_strings));

	TAG_REFERENCE(unicode_string_list_reference, UNICODE_STRING_LIST_TAG);

	TAG_REFERENCE(hud_message_text_reference, HUD_MESSAGE_TEXT_TAG);

	TAG_BLOCK(
		scenario_structure_bsps_block,
		"scenario_structure_bsps_block",
		16,
		"s_scenario_structure_bsps_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "structure bsp", FIELD_FLAG_INDEX, &blofeld::halo1::scenario_structure_bsp_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_cutscene_title_block,
		"scenario_cutscene_title_block",
		64,
		"s_scenario_cutscene_title_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "name", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_rectangle_2d, "text bounds (on screen)" },
		{ _field_short_integer, "string index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "justification", &blofeld::halo1::unnamed_enum$172 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_argb_color, "text color" },
		{ _field_argb_color, "shadow color" },
		{ _field_real, "fade in time [seconds]" },
		{ _field_real, "up time [seconds]" },
		{ _field_real, "fade out time [seconds]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$172)
	{
		"left",
		"right",
		"center"
	};
	STRING_LIST(unnamed_enum$172, unnamed_enum$172_strings, _countof(unnamed_enum$172_strings));

	TAG_BLOCK(
		scenario_cutscene_camera_point_block,
		"scenario_cutscene_camera_point_block",
		512,
		"s_scenario_cutscene_camera_point_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "name", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "orientation" },
		{ _field_angle, "field of view" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_cutscene_flag_block,
		"scenario_cutscene_flag_block",
		512,
		"s_scenario_cutscene_flag_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_2d, "facing" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_terminator }
	};

	TAG_BLOCK(
		hs_source_files_block,
		"hs_source_files_block",
		8,
		"s_hs_source_files_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY },
		{ _field_data, "source" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		hs_references_block,
		"hs_references_block",
		256,
		"s_hs_references_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_tag_reference, "reference", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &blofeld::halo1::_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(_reference);

	TAG_BLOCK(
		hs_globals_block,
		"hs_globals_block",
		128,
		"s_hs_globals_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY },
		{ _field_short_enum, "type", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$171 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_long_integer, "initialization expression index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$171)
	{
		"unparsed",
		"special form",
		"function name",
		"passthrough",
		"void",
		"boolean",
		"real",
		"short",
		"long",
		"string",
		"script",
		"trigger_volume",
		"cutscene_flag",
		"cutscene_camera_point",
		"cutscene_title",
		"cutscene_recording",
		"device_group",
		"ai",
		"ai_command_list",
		"starting_profile",
		"conversation",
		"navpoint",
		"hud_message",
		"object_list",
		"sound",
		"effect",
		"damage",
		"looping_sound",
		"animation_graph",
		"actor_variant",
		"damage_effect",
		"object_definition",
		"game_difficulty",
		"team",
		"ai_default_state",
		"actor_type",
		"hud_corner",
		"object",
		"unit",
		"vehicle",
		"weapon",
		"device",
		"scenery",
		"object_name",
		"unit_name",
		"vehicle_name",
		"weapon_name",
		"device_name",
		"scenery_name"
	};
	STRING_LIST(unnamed_enum$171, unnamed_enum$171_strings, _countof(unnamed_enum$171_strings));

	TAG_BLOCK(
		hs_scripts_block,
		"hs_scripts_block",
		512,
		"s_hs_scripts_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY },
		{ _field_short_enum, "script type", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$170 },
		{ _field_short_enum, "return type", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$171 },
		{ _field_long_integer, "root expression index", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 52),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$170)
	{
		"startup",
		"dormant",
		"continuous",
		"static",
		"stub"
	};
	STRING_LIST(unnamed_enum$170, unnamed_enum$170_strings, _countof(unnamed_enum$170_strings));

	TAG_BLOCK(
		ai_conversation_block,
		"ai_conversation_block",
		128,
		"s_ai_conversation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$164 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "trigger distance", "distance the player must enter before the conversation can trigger", "world units" },
		{ _field_real, "run-to-player dist", "if the 'involves player' flag is set, when triggered the conversation's participant(s) will run to within this distance of the player", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_block, "participants", &blofeld::halo1::ai_conversation_participant_block },
		{ _field_block, "lines", &blofeld::halo1::ai_conversation_line_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$164)
	{
		"stop if death#this conversation will be aborted if any participant dies",
		"stop if damaged#an actor will abort this conversation if they are damaged",
		"stop if visible enemy#an actor will abort this conversation if they see an enemy",
		"stop if alerted to enemy#an actor will abort this conversation if they suspect an enemy",
		"player must be visible#this conversation cannot take place unless the participants can _see_ a nearby player",
		"stop other actions#participants stop doing whatever they were doing in order to perform this conversation",
		"keep trying to play#if this conversation fails initially, it will keep testing to see when it can play",
		"player must be looking#this conversation will not start until the player is looking at one of the participants"
	};
	STRING_LIST(unnamed_enum$164, unnamed_enum$164_strings, _countof(unnamed_enum$164_strings));

	TAG_BLOCK(
		ai_conversation_line_block,
		"ai_conversation_line_block",
		32,
		"s_ai_conversation_line_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$168 },
		{ _field_short_block_index, "participant", &blofeld::halo1::ai_conversation_participant_block },
		{ _field_short_enum, "addressee", &blofeld::halo1::unnamed_enum$169 },
		{ _field_short_block_index, "addressee participant", "this field is only used if the addressee type is 'participant'", &blofeld::halo1::ai_conversation_participant_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "line delay time" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_tag_reference, "variant 1", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "variant 2", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "variant 3", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "variant 4", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "variant 5", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "variant 6", &blofeld::halo1::sound_reference },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$168)
	{
		"addressee look at speaker",
		"everyone look at speaker",
		"everyone look at addressee",
		"wait after until told to advance",
		"wait until speaker nearby",
		"wait until everyone nearby"
	};
	STRING_LIST(unnamed_enum$168, unnamed_enum$168_strings, _countof(unnamed_enum$168_strings));

	STRINGS(unnamed_enum$169)
	{
		"none",
		"player",
		"participant"
	};
	STRING_LIST(unnamed_enum$169, unnamed_enum$169_strings, _countof(unnamed_enum$169_strings));

	TAG_BLOCK(
		ai_conversation_participant_block,
		"ai_conversation_participant_block",
		8,
		"s_ai_conversation_participant_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$165 },
		{ _field_short_enum, "selection type", &blofeld::halo1::unnamed_enum$166 },
		{ _field_short_enum, "actor type", &blofeld::halo1::unnamed_enum$167 },
		{ _field_short_block_index, "use this object", "if a unit with this name exists, we try to pick them to start the conversation", &blofeld::halo1::scenario_object_names_block },
		{ _field_short_block_index, "set new name", "once we pick a unit, we name it this", &blofeld::halo1::scenario_object_names_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_string, "encounter name" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$165)
	{
		"optional#the conversation can continue even if nobody for this participant was found",
		"has alternate#if nobody for this participant can be found, we use a participant marked as \'is alternate\' instead, e.g. someone from over the radio",
		"is alternate#this participant is only used if some participant in this conversation was marked as \'has alternate\' could not be found"
	};
	STRING_LIST(unnamed_enum$165, unnamed_enum$165_strings, _countof(unnamed_enum$165_strings));

	STRINGS(unnamed_enum$166)
	{
		"friendly actor",
		"disembodied",
		"in player\'s vehicle",
		"not in a vehicle",
		"prefer sergeant",
		"any actor",
		"radio unit",
		"radio sergeant"
	};
	STRING_LIST(unnamed_enum$166, unnamed_enum$166_strings, _countof(unnamed_enum$166_strings));

	STRINGS(unnamed_enum$167)
	{
		"elite",
		"jackal",
		"grunt",
		"hunter",
		"engineer",
		"assassin",
		"player",
		"marine",
		"crew",
		"combat form",
		"infection form",
		"carrier form",
		"monitor",
		"sentinel",
		"none",
		"mounted weapon"
	};
	STRING_LIST(unnamed_enum$167, unnamed_enum$167_strings, _countof(unnamed_enum$167_strings));

	TAG_BLOCK(
		ai_recording_reference_block,
		"ai_recording_reference_block",
		128,
		"s_ai_recording_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "recording name", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	TAG_BLOCK(
		ai_script_reference_block,
		"ai_script_reference_block",
		128,
		"s_ai_script_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "script name", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	TAG_BLOCK(
		ai_animation_reference_block,
		"ai_animation_reference_block",
		128,
		"s_ai_animation_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "animation name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "animation graph", "leave this blank to use the unit's normal animation graph", &blofeld::halo1::model_animations_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	TAG_REFERENCE(model_animations_reference$3, MODEL_ANIMATIONS_TAG);

	TAG_BLOCK(
		ai_command_list_block,
		"ai_command_list_block",
		256,
		"s_ai_command_list_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$161 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_integer, "manual bsp index", "structure bsp index that this encounter belongs to... ignored unless 'manual bsp index' flag is checked. if this flag is not checked, the structure bsp is found automatically (may fail in areas of overlapping geometry)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "commands", &blofeld::halo1::ai_command_block },
		{ _field_block, "points", &blofeld::halo1::ai_command_point_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$161)
	{
		"allow initiative#lets an actor decide to stop following its commands and attack an enemy",
		"allow targeting#lets an actor shoot at enemies while following its commands",
		"disable looking#stops an actor from turning, stopping or looking around in response to stimuli received while following its commands",
		"disable communication#stops an actor from communicating while following its commands",
		"disable falling damage#makes an actor not take any damage from falling while following its commands",
		"manual bsp index#set if the command list is manually attached to a specific bsp"
	};
	STRING_LIST(unnamed_enum$161, unnamed_enum$161_strings, _countof(unnamed_enum$161_strings));

	TAG_BLOCK(
		ai_command_point_block,
		"ai_command_point_block",
		64,
		"s_ai_command_point_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	TAG_BLOCK(
		ai_command_block,
		"ai_command_block",
		64,
		"s_ai_command_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "atom type", &blofeld::halo1::unnamed_enum$162 },
		{ _field_short_integer, "atom modifier" },
		{ _field_real, "parameter1" },
		{ _field_real, "parameter2" },
		{ _field_short_block_index, "point 1", &blofeld::halo1::ai_command_point_block },
		{ _field_short_block_index, "point 2", &blofeld::halo1::ai_command_point_block },
		{ _field_short_block_index, "animation", &blofeld::halo1::ai_animation_reference_block },
		{ _field_short_block_index, "script", &blofeld::halo1::ai_script_reference_block },
		{ _field_short_block_index, "recording", &blofeld::halo1::ai_recording_reference_block },
		{ _field_short_block_index, "command", &blofeld::halo1::ai_command_block },
		{ _field_short_block_index, "object name", &blofeld::halo1::scenario_object_names_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 6),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$162)
	{
		"pause",
		"go to",
		"go to and face",
		"move in direction",
		"look",
		"animation mode",
		"crouch",
		"shoot",
		"grenade",
		"vehicle",
		"running jump",
		"targeted jump",
		"script",
		"animate",
		"recording",
		"action",
		"vocalize",
		"targeting",
		"initiative",
		"wait",
		"loop",
		"die",
		"move immediate",
		"look random",
		"look player",
		"look object",
		"set radius",
		"teleport"
	};
	STRING_LIST(unnamed_enum$162, unnamed_enum$162_strings, _countof(unnamed_enum$162_strings));

	TAG_BLOCK(
		encounter_block,
		"encounter_block",
		128,
		"s_encounter_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$150 },
		{ _field_short_enum, "team index", &blofeld::halo1::unnamed_enum$151 },
		FIELD_SKIP_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "search behavior", &blofeld::halo1::unnamed_enum$152 },
		{ _field_short_integer, "manual bsp index", "structure bsp index that this encounter belongs to... ignored unless 'manual bsp index' flag is checked. if this flag is not checked, the structure bsp is found automatically (may fail in areas of overlapping geometry)" },
		{ _field_real_bounds, "respawn delay", "delay between respawning actors in this encounter", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		{ _field_block, "squads", &blofeld::halo1::squads_block },
		{ _field_block, "platoons", &blofeld::halo1::platoons_block },
		{ _field_block, "firing positions", &blofeld::halo1::firing_positions_block },
		{ _field_block, "player starting locations", &blofeld::halo1::scenario_players_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$150)
	{
		"not initially created",
		"respawn enabled",
		"initially blind",
		"initially deaf",
		"initially braindead",
		"3d firing positions",
		"manual bsp index specified"
	};
	STRING_LIST(unnamed_enum$150, unnamed_enum$150_strings, _countof(unnamed_enum$150_strings));

	STRINGS(unnamed_enum$151)
	{
		"0 / default by unit",
		"1 / player",
		"2 / human",
		"3 / covenant",
		"4 / flood",
		"5 / sentinel",
		"6 / unused6",
		"7 / unused7",
		"8 / unused8",
		"9 / unused9"
	};
	STRING_LIST(unnamed_enum$151, unnamed_enum$151_strings, _countof(unnamed_enum$151_strings));

	STRINGS(unnamed_enum$152)
	{
		"normal",
		"never",
		"tenacious"
	};
	STRING_LIST(unnamed_enum$152, unnamed_enum$152_strings, _countof(unnamed_enum$152_strings));

	TAG_BLOCK(
		scenario_players_block,
		"scenario_players_block",
		256,
		"s_scenario_players_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position" },
		{ _field_angle, "facing", nullptr, "degrees" },
		{ _field_short_integer, "team index" },
		{ _field_short_integer, "bsp index" },
		{ _field_short_enum, "type 0", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 1", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 2", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 3", &blofeld::halo1::unnamed_enum$146 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$146)
	{
		"none",
		"ctf",
		"slayer",
		"oddball",
		"king of the hill",
		"race",
		"terminator",
		"stub",
		"ignored1",
		"ignored2",
		"ignored3",
		"ignored4",
		"all games",
		"all except ctf",
		"all except race & ctf"
	};
	STRING_LIST(unnamed_enum$146, unnamed_enum$146_strings, _countof(unnamed_enum$146_strings));

	TAG_BLOCK(
		firing_positions_block,
		"firing_positions_block",
		512,
		"s_firing_positions_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position" },
		{ _field_short_enum, "group index", &blofeld::halo1::unnamed_enum$163 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 10),
		{ _field_custom, "value" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$163)
	{
		"A",
		"B",
		"C",
		"D",
		"E",
		"F",
		"G",
		"H",
		"I",
		"J",
		"K",
		"L",
		"M",
		"N",
		"O",
		"P",
		"Q",
		"R",
		"S",
		"T",
		"U",
		"V",
		"W",
		"X",
		"Y",
		"Z"
	};
	STRING_LIST(unnamed_enum$163, unnamed_enum$163_strings, _countof(unnamed_enum$163_strings));

	TAG_BLOCK(
		platoons_block,
		"platoons_block",
		32,
		"s_platoons_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$153 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_short_enum, "change attacking/defending state when", &blofeld::halo1::unnamed_enum$154 },
		{ _field_short_block_index, "happens to", &blofeld::halo1::platoons_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_enum, "maneuver when", &blofeld::halo1::unnamed_enum$154 },
		{ _field_short_block_index, "happens to", &blofeld::halo1::platoons_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$153)
	{
		"flee when maneuvering",
		"say \'advancing\' when maneuver",
		"start in defending state"
	};
	STRING_LIST(unnamed_enum$153, unnamed_enum$153_strings, _countof(unnamed_enum$153_strings));

	STRINGS(unnamed_enum$154)
	{
		"(never)",
		"< 75% strength",
		"< 50% strength",
		"< 25% strength",
		"anybody dead",
		"25% dead",
		"50% dead",
		"75% dead",
		"all but one dead",
		"all dead"
	};
	STRING_LIST(unnamed_enum$154, unnamed_enum$154_strings, _countof(unnamed_enum$154_strings));

	TAG_BLOCK(
		squads_block,
		"squads_block",
		64,
		"s_squads_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name" },
		{ _field_short_block_index, "actor type", &blofeld::halo1::actor_palette_block },
		{ _field_short_block_index, "platoon", &blofeld::halo1::platoons_block },
		{ _field_short_enum, "initial state", "state that this actor starts in", &blofeld::halo1::unnamed_enum$155 },
		{ _field_short_enum, "return state", "state that this actor will return to when it has nothing to do", &blofeld::halo1::unnamed_enum$155 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$156 },
		{ _field_short_enum, "unique leader type", "what kind of leader this squad has (e.g. a sarge for marines) - 'normal' is based on the size of the squad, 'random' always creates a leader, or you can specify an individual type", &blofeld::halo1::unnamed_enum$157 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "maneuver to squad", &blofeld::halo1::squads_block },
		{ _field_real, "squad delay time", nullptr, "seconds" },
		{ _field_long_flags, "attacking", &blofeld::halo1::unnamed_enum$158 },
		{ _field_long_flags, "attacking search", &blofeld::halo1::unnamed_enum$158 },
		{ _field_long_flags, "attacking guard", &blofeld::halo1::unnamed_enum$158 },
		{ _field_long_flags, "defending", &blofeld::halo1::unnamed_enum$158 },
		{ _field_long_flags, "defending search", &blofeld::halo1::unnamed_enum$158 },
		{ _field_long_flags, "defending guard", &blofeld::halo1::unnamed_enum$158 },
		{ _field_long_flags, "pursuing", &blofeld::halo1::unnamed_enum$158 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_integer, "normal diff count", "initial number of actors on normal difficulty" },
		{ _field_short_integer, "insane diff count", "initial number of actors on insane difficulty (hard difficulty is midway between normal and insane)" },
		{ _field_short_enum, "major upgrade", &blofeld::halo1::unnamed_enum$159 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "respawn min actors", "minimum number of actors alive at once (will spawn instantly if less than this number)" },
		{ _field_short_integer, "respawn max actors", "maximum number of actors alive at once (never spawns above this number)" },
		{ _field_short_integer, "respawn total", "total number to respawn (zero = infinite)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_bounds, "respawn delay", "delay between respawning actors in this squad", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_block, "move positions", &blofeld::halo1::move_positions_block },
		{ _field_block, "starting locations", &blofeld::halo1::actor_starting_locations_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$155)
	{
		"none",
		"sleeping",
		"alert",
		"moving - repeat same position",
		"moving - loop",
		"moving - loop back and forth",
		"moving - loop randomly",
		"moving - randomly",
		"guarding",
		"guarding at guard position",
		"searching",
		"fleeing"
	};
	STRING_LIST(unnamed_enum$155, unnamed_enum$155_strings, _countof(unnamed_enum$155_strings));

	STRINGS(unnamed_enum$156)
	{
		"unused",
		"never search",
		"start timer immediately",
		"no timer, delay forever",
		"magic sight after timer",
		"automatic migration"
	};
	STRING_LIST(unnamed_enum$156, unnamed_enum$156_strings, _countof(unnamed_enum$156_strings));

	STRINGS(unnamed_enum$157)
	{
		"normal",
		"none",
		"random",
		"sgt johnson",
		"sgt lehto"
	};
	STRING_LIST(unnamed_enum$157, unnamed_enum$157_strings, _countof(unnamed_enum$157_strings));

	STRINGS(unnamed_enum$158)
	{
		"A",
		"B",
		"C",
		"D",
		"E",
		"F",
		"G",
		"H",
		"I",
		"J",
		"K",
		"L",
		"M",
		"N",
		"O",
		"P",
		"Q",
		"R",
		"S",
		"T",
		"U",
		"V",
		"W",
		"X",
		"Y",
		"Z"
	};
	STRING_LIST(unnamed_enum$158, unnamed_enum$158_strings, _countof(unnamed_enum$158_strings));

	STRINGS(unnamed_enum$159)
	{
		"normal",
		"few",
		"many",
		"none",
		"all"
	};
	STRING_LIST(unnamed_enum$159, unnamed_enum$159_strings, _countof(unnamed_enum$159_strings));

	TAG_BLOCK(
		actor_starting_locations_block,
		"actor_starting_locations_block",
		32,
		"s_actor_starting_locations_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position" },
		{ _field_angle, "facing", nullptr, "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_char_integer, "sequence ID", "which move position sequence we can use (zero = no specific sequences)" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$160 },
		{ _field_short_enum, "return state", "state that this actor will return to when it has nothing to do", &blofeld::halo1::unnamed_enum$155 },
		{ _field_short_enum, "initial state", "state that this actor starts in", &blofeld::halo1::unnamed_enum$155 },
		{ _field_short_block_index, "actor type", &blofeld::halo1::actor_palette_block },
		{ _field_short_block_index, "command list", &blofeld::halo1::ai_command_list_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$160)
	{
		"required"
	};
	STRING_LIST(unnamed_enum$160, unnamed_enum$160_strings, _countof(unnamed_enum$160_strings));

	TAG_BLOCK(
		move_positions_block,
		"move_positions_block",
		32,
		"s_move_positions_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position" },
		{ _field_angle, "facing", nullptr, "degrees" },
		{ _field_real, "weight" },
		{ _field_real_bounds, "time", nullptr, "seconds" },
		{ _field_short_block_index, "animation", &blofeld::halo1::ai_animation_reference_block },
		{ _field_char_integer, "sequence ID", "identifies this move position as belonging to a sequence, only actors whose starting locations match this sequence ID can use it (zero = no sequence)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_long_integer, "surface index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		actor_palette_block,
		"actor_palette_block",
		64,
		"s_actor_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &blofeld::halo1::actor_variant_reference$3 },
		{ _field_terminator }
	};

	TAG_REFERENCE(actor_variant_reference$3, ACTOR_VARIANT_TAG);

	TAG_BLOCK(
		scenario_detail_object_collection_palette_block,
		"scenario_detail_object_collection_palette_block",
		32,
		"s_scenario_detail_object_collection_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::detail_object_collection_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(detail_object_collection_reference, DETAIL_OBJECT_COLLECTION_TAG);

	TAG_BLOCK(
		scenario_decal_palette_block,
		"scenario_decal_palette_block",
		128,
		"s_scenario_decal_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &blofeld::halo1::decal_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(decal_reference, DECAL_TAG);

	TAG_BLOCK(
		scenario_decals_block,
		"scenario_decals_block",
		65536,
		"s_scenario_decals_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "decal type", FIELD_FLAG_INDEX, &blofeld::halo1::scenario_decal_palette_block },
		{ _field_char_integer, "yaw", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "pitch", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "position", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_bsp_switch_trigger_volume_block,
		"scenario_bsp_switch_trigger_volume_block",
		256,
		"s_scenario_bsp_switch_trigger_volume_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "trigger volume", &blofeld::halo1::scenario_trigger_volume_block },
		{ _field_short_integer, "source" },
		{ _field_short_integer, "destination" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_starting_equipment_block,
		"scenario_starting_equipment_block",
		200,
		"s_scenario_starting_equipment_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$149 },
		{ _field_short_enum, "type 0", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 1", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 2", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 3", &blofeld::halo1::unnamed_enum$146 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_tag_reference, "item collection 1", &blofeld::halo1::item_collection_reference },
		{ _field_tag_reference, "item collection 2", &blofeld::halo1::item_collection_reference },
		{ _field_tag_reference, "item collection 3", &blofeld::halo1::item_collection_reference },
		{ _field_tag_reference, "item collection 4", &blofeld::halo1::item_collection_reference },
		{ _field_tag_reference, "item collection 5", &blofeld::halo1::item_collection_reference },
		{ _field_tag_reference, "item collection 6", &blofeld::halo1::item_collection_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$149)
	{
		"no grenades",
		"plasma grenades"
	};
	STRING_LIST(unnamed_enum$149, unnamed_enum$149_strings, _countof(unnamed_enum$149_strings));

	TAG_REFERENCE(item_collection_reference, ITEM_COLLECTION_TAG);

	TAG_BLOCK(
		scenario_netgame_equipment_block,
		"scenario_netgame_equipment_block",
		200,
		"s_scenario_netgame_equipment_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$148 },
		{ _field_short_enum, "type 0", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 1", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 2", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_enum, "type 3", &blofeld::halo1::unnamed_enum$146 },
		{ _field_short_integer, "team index" },
		{ _field_short_integer, "spawn time (in seconds, 0 = default)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_real_point_3d, "position" },
		{ _field_angle, "facing", nullptr, "degress" },
		{ _field_tag_reference, "item collection", &blofeld::halo1::item_collection_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$148)
	{
		"levitate"
	};
	STRING_LIST(unnamed_enum$148, unnamed_enum$148_strings, _countof(unnamed_enum$148_strings));

	TAG_BLOCK(
		scenario_netgame_flags_block,
		"scenario_netgame_flags_block",
		200,
		"s_scenario_netgame_flags_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position" },
		{ _field_angle, "facing", nullptr, "degress" },
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$147 },
		{ _field_short_integer, "team index" },
		{ _field_tag_reference, "weapon group", &blofeld::halo1::item_collection_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 112),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$147)
	{
		"ctf - flag",
		"ctf - vehicle",
		"oddball - ball spawn",
		"race - track",
		"race - vehicle",
		"vegas - bank",
		"teleport from",
		"teleport to",
		"hill - flag"
	};
	STRING_LIST(unnamed_enum$147, unnamed_enum$147_strings, _countof(unnamed_enum$147_strings));

	TAG_BLOCK(
		recorded_animation_block,
		"recorded_animation_block",
		1024,
		"s_recorded_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_char_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "raw animation data", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "unit control data version", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "length of animation", nullptr, "ticks", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_data, "recorded animation event stream", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_trigger_volume_block,
		"scenario_trigger_volume_block",
		256,
		"s_scenario_trigger_volume_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_SKIP_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_array, "value", &blofeld::halo1::scenario_trigger_volume_block___array },
		{ _field_terminator }
	};

	TAG_ARRAY(
		scenario_trigger_volume_block___array,
		"scenario_trigger_volume_block |  array",
		15,
		"s_scenario_trigger_volume_block___array",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real, "value" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_profiles_block,
		"scenario_profiles_block",
		256,
		"s_scenario_profiles_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real_fraction, "starting health modifier", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "starting shield modifier", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "primary weapon", &blofeld::halo1::weapon_reference$3 },
		{ _field_short_integer, "rounds loaded" },
		{ _field_short_integer, "rounds total" },
		{ _field_tag_reference, "secondary weapon", &blofeld::halo1::weapon_reference$3 },
		{ _field_short_integer, "rounds loaded" },
		{ _field_short_integer, "rounds total" },
		{ _field_char_integer, "starting fragmentation grenade count" },
		{ _field_char_integer, "starting plasma grenade count" },
		{ _field_char_integer, "starting <unknown> grenade count" },
		{ _field_char_integer, "starting <unknown> grenade count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_terminator }
	};

	TAG_REFERENCE(weapon_reference$3, WEAPON_TAG);

	TAG_BLOCK(
		scenario_sound_scenery_palette_block,
		"scenario_sound_scenery_palette_block",
		100,
		"s_scenario_sound_scenery_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::sound_scenery_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(sound_scenery_reference, SOUND_SCENERY_TAG);

	TAG_BLOCK(
		scenario_sound_scenery_block,
		"scenario_sound_scenery_block",
		256,
		"s_scenario_sound_scenery_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_sound_scenery_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$137)
	{
		"automatically",
		"on easy",
		"on normal",
		"on hard"
	};
	STRING_LIST(unnamed_enum$137, unnamed_enum$137_strings, _countof(unnamed_enum$137_strings));

	TAG_BLOCK(
		scenario_light_fixture_palette_block,
		"scenario_light_fixture_palette_block",
		100,
		"s_scenario_light_fixture_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::device_light_fixture_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(device_light_fixture_reference, DEVICE_LIGHT_FIXTURE_TAG);

	TAG_BLOCK(
		scenario_light_fixture_block,
		"scenario_light_fixture_block",
		500,
		"s_scenario_light_fixture_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_light_fixture_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_block_index, "power group", &blofeld::halo1::device_group_block$2 },
		{ _field_short_block_index, "position group", &blofeld::halo1::device_group_block$2 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$143 },
		{ _field_real_rgb_color, "color" },
		{ _field_real, "intensity" },
		{ _field_angle, "falloff angle", nullptr, "degrees" },
		{ _field_angle, "cutoff angle", nullptr, "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$143)
	{
		"initially open (1.0)",
		"initially off (0.0)",
		"can change only once",
		"position reversed",
		"not usable from any side"
	};
	STRING_LIST(unnamed_enum$143, unnamed_enum$143_strings, _countof(unnamed_enum$143_strings));

	TAG_BLOCK(
		scenario_control_palette_block,
		"scenario_control_palette_block",
		100,
		"s_scenario_control_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::device_control_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(device_control_reference, DEVICE_CONTROL_TAG);

	TAG_BLOCK(
		scenario_control_block,
		"scenario_control_block",
		100,
		"s_scenario_control_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_control_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_block_index, "power group", &blofeld::halo1::device_group_block$2 },
		{ _field_short_block_index, "position group", &blofeld::halo1::device_group_block$2 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$143 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$145 },
		{ _field_short_integer, "*DON'T TOUCH THIS" },
		{ _field_custom, "value" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$145)
	{
		"usable from both sides"
	};
	STRING_LIST(unnamed_enum$145, unnamed_enum$145_strings, _countof(unnamed_enum$145_strings));

	TAG_BLOCK(
		scenario_machine_palette_block,
		"scenario_machine_palette_block",
		100,
		"s_scenario_machine_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::device_machine_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(device_machine_reference, DEVICE_MACHINE_TAG);

	TAG_BLOCK(
		scenario_machine_block,
		"scenario_machine_block",
		400,
		"s_scenario_machine_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_machine_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_block_index, "power group", &blofeld::halo1::device_group_block$2 },
		{ _field_short_block_index, "position group", &blofeld::halo1::device_group_block$2 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$143 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$144 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$144)
	{
		"does not operate automatically",
		"one-sided",
		"never appears locked",
		"opened by melee attack"
	};
	STRING_LIST(unnamed_enum$144, unnamed_enum$144_strings, _countof(unnamed_enum$144_strings));

	TAG_BLOCK(
		device_group_block$2,
		"device_group_block",
		128,
		"s_device_group_block$2",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real, "initial value", nullptr, nullptr, "[0,1]" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$142 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$142)
	{
		"can change only once"
	};
	STRING_LIST(unnamed_enum$142, unnamed_enum$142_strings, _countof(unnamed_enum$142_strings));

	TAG_BLOCK(
		scenario_weapon_palette_block,
		"scenario_weapon_palette_block",
		100,
		"s_scenario_weapon_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::weapon_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(weapon_reference$2, WEAPON_TAG);

	TAG_BLOCK(
		scenario_weapon_block,
		"scenario_weapon_block",
		128,
		"s_scenario_weapon_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_weapon_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_integer, "rounds left" },
		{ _field_short_integer, "rounds loaded" },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$141 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$141)
	{
		"initially at rest (doesn\'t fall)",
		"obsolete",
		"does accelerate (moves due to explosions)"
	};
	STRING_LIST(unnamed_enum$141, unnamed_enum$141_strings, _countof(unnamed_enum$141_strings));

	TAG_BLOCK(
		scenario_equipment_palette_block,
		"scenario_equipment_palette_block",
		100,
		"s_scenario_equipment_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::equipment_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(equipment_reference$2, EQUIPMENT_TAG);

	TAG_BLOCK(
		scenario_equipment_block,
		"scenario_equipment_block",
		256,
		"s_scenario_equipment_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_equipment_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_word_flags, "misc flags", &blofeld::halo1::unnamed_enum$140 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$140)
	{
		"initially at rest (doesn\'t fall)",
		"obsolete",
		"does accelerate (moves due to explosions)"
	};
	STRING_LIST(unnamed_enum$140, unnamed_enum$140_strings, _countof(unnamed_enum$140_strings));

	TAG_BLOCK(
		scenario_vehicle_palette_block,
		"scenario_vehicle_palette_block",
		100,
		"s_scenario_vehicle_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::vehicle_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(vehicle_reference$2, VEHICLE_TAG);

	TAG_BLOCK(
		scenario_vehicle_block,
		"scenario_vehicle_block",
		80,
		"s_scenario_vehicle_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_vehicle_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "body vitality", nullptr, nullptr, "[0,1]" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$138 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_char_integer, "multiplayer team index", "on a multiplayer map, this determines which team the vehicle belongs to for custom vehicle sets." },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_word_flags, "multiplayer spawn flags", &blofeld::halo1::unnamed_enum$139 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$138)
	{
		"dead"
	};
	STRING_LIST(unnamed_enum$138, unnamed_enum$138_strings, _countof(unnamed_enum$138_strings));

	STRINGS(unnamed_enum$139)
	{
		"slayer default#vehicle will spawn when default vehicle set is used in a slayer game",
		"ctf default#vehicle will spawn when default vehicle set is used in a ctf game",
		"king default#vehicle will spawn when default vehicle set is used in a king game",
		"oddball default#vehicle will spawn when default vehicle set is used in a oddball game",
		"unused#unused",
		"unused#unused",
		"unused#unused",
		"unused#unused",
		"slayer allowed#vehicle can spawn in a slayer game",
		"ctf allowed#vehicle can spawn in a ctf game",
		"king allowed#vehicle can spawn in a king game",
		"oddball allowed#vehicle can spawn in a oddball game",
		"unused#unused",
		"unused#unused",
		"unused#unused",
		"unused#unused"
	};
	STRING_LIST(unnamed_enum$139, unnamed_enum$139_strings, _countof(unnamed_enum$139_strings));

	TAG_BLOCK(
		scenario_biped_palette_block,
		"scenario_biped_palette_block",
		100,
		"s_scenario_biped_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::biped_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(biped_reference, BIPED_TAG);

	TAG_BLOCK(
		scenario_biped_block,
		"scenario_biped_block",
		128,
		"s_scenario_biped_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_biped_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "body vitality", nullptr, nullptr, "[0,1]" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$138 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_scenery_palette_block,
		"scenario_scenery_palette_block",
		100,
		"s_scenario_scenery_palette_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "name", FIELD_FLAG_INDEX, &blofeld::halo1::scenery_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(scenery_reference, SCENERY_TAG);

	TAG_BLOCK(
		scenario_scenery_block,
		"scenario_scenery_block",
		2000,
		"s_scenario_scenery_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_block_index, "type", &blofeld::halo1::scenario_scenery_palette_block },
		{ _field_short_block_index, "name", &blofeld::halo1::scenario_object_names_block },
		{ _field_word_flags, "not placed", &blofeld::halo1::unnamed_enum$137 },
		{ _field_short_integer, "desired permutation", "if non-zero, will try to use model permutations with names that end in that number, e.g. 7 would pick \"body-7\" and \"head-7\"" },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_object_names_block,
		"scenario_object_names_block",
		512,
		"s_scenario_object_names_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	TAG_BLOCK(
		editor_comment_block,
		"editor_comment_block",
		1024,
		"s_editor_comment_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_point_3d, "position" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_data, "comment" },
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_function_block,
		"scenario_function_block",
		32,
		"s_scenario_function_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$135 },
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_real, "period", "this is the period for the above function (lower values make the function oscillate quickly, higher values make it oscillate slowly)", "seconds" },
		{ _field_short_block_index, "scale period by", "multiply this function by the above period", &blofeld::halo1::scenario_function_block },
		{ _field_short_enum, "function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_short_block_index, "scale function by", "multiply this function by the result of the above function", &blofeld::halo1::scenario_function_block },
		{ _field_short_enum, "wobble function", "the curve used for the wobble", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "wobble period", "the length of time it takes for the magnitude of this function to complete a wobble", "seconds" },
		{ _field_real, "wobble magnitude", "the amount of random wobble in the magnitude", "percent" },
		{ _field_real_fraction, "square wave threshold", "if non-zero, all values above the square wave threshold are snapped to 1.0, and all values below it are snapped to 0.0 to create a square wave." },
		{ _field_short_integer, "step count", "the number of discrete values to snap to (e.g., a step count of 5 would snap the function to 0.00,0.25,0.50,0.75 or 1.00)" },
		{ _field_short_enum, "map to", &blofeld::halo1::unnamed_enum$43 },
		{ _field_short_integer, "sawtooth count", "the number of times this function should repeat (e.g., a sawtooth count of 5 would give the function a value of 1.0 at each of 0.25,0.50,0.75 as well as at 1.0" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "scale result by", "multiply this function (from a weapon, vehicle, etc.) final result of all of the above math", &blofeld::halo1::scenario_function_block },
		{ _field_short_enum, "bounds mode", "controls how the bounds, below, are used", &blofeld::halo1::unnamed_enum$136 },
		{ _field_fraction_bounds, "bounds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_block_index, "turn off with", "if the specified function is off, so is this function", &blofeld::halo1::scenario_function_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$135)
	{
		"scripted#the level script will set this value; the other settings here will be ignored.",
		"invert#result of function is one minus actual result",
		"additive",
		"always active#function does not deactivate when at or below lower bound"
	};
	STRING_LIST(unnamed_enum$135, unnamed_enum$135_strings, _countof(unnamed_enum$135_strings));

	STRINGS(unnamed_enum$136)
	{
		"clip",
		"clip and normalize",
		"scale to fit"
	};
	STRING_LIST(unnamed_enum$136, unnamed_enum$136_strings, _countof(unnamed_enum$136_strings));

	TAG_BLOCK(
		scenario_child_scenario_block,
		"scenario_child_scenario_block",
		16,
		"s_scenario_child_scenario_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "child scenario", &blofeld::halo1::scenario_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	TAG_REFERENCE(scenario_reference, SCENARIO_TAG);

	TAG_BLOCK(
		scenario_sky_reference_block,
		"scenario_sky_reference_block",
		8,
		"s_scenario_sky_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "sky", &blofeld::halo1::sky_reference },
		{ _field_terminator }
	};


	TAG_GROUP(
		shader_group,
		SHADER_TAG,
		nullptr,
		INVALID_TAG,
		shader);

	TAG_BLOCK(
		shader,
		"shader_group_block",
		1,
		"s_shader",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("radiosity properties", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$173 },
		{ _field_short_enum, "detail level", "affects the density of tesselation (high means slow).", &blofeld::halo1::unnamed_enum$174 },
		{ _field_real, "power", "power of emitted light from 0 to infinity" },
		{ _field_real_rgb_color, "color of emitted light" },
		{ _field_real_rgb_color, "tint color", "light passing through this surface (if it's transparent) will be tinted this color." },
		FIELD_EXPLANATION_EX("physics properties", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$175 },
		{ _field_short_enum, "material type", &blofeld::halo1::unnamed_enum$119 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$173)
	{
		"simple parameterization#lightmap texture parametrization should correspond to diffuse texture parametrization",
		"ignore normals#light independent of normals (trees)",
		"transparent lit"
	};
	STRING_LIST(unnamed_enum$173, unnamed_enum$173_strings, _countof(unnamed_enum$173_strings));

	STRINGS(unnamed_enum$174)
	{
		"high",
		"medium",
		"low",
		"turd"
	};
	STRING_LIST(unnamed_enum$174, unnamed_enum$174_strings, _countof(unnamed_enum$174_strings));

	STRING_LIST(unnamed_enum$175, empty_string_list, 0);


	TAG_GROUP(
		shader_environment_group,
		SHADER_ENVIRONMENT_TAG,
		&shader_group,
		SHADER_TAG,
		shader_environment);

	TAG_BLOCK(
		shader_environment,
		"shader_environment_group_block",
		1,
		"s_shader_environment",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("environment shader", nullptr, FIELD_FLAG_NONE, "Setting <true atmospheric fog> enables per-pixel atmospheric fog (for models) but disables point/spot lights, planar fog, and the ability to control the atmospheric fog density for this shader."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$176 },
		FIELD_EXPLANATION_EX("environment shader type", nullptr, FIELD_FLAG_NONE, "Controls how diffuse maps are combined:\n\nNORMAL:\nSecondary detail map alpha controls blend between primary and secondary detail map. Specular mask is alpha of blended primary and secondary detail map alpha multiplied by alpha of micro detail map.\n\nBLENDED:\nBase map alpha controls blend between primary and secondary detail map. Specular mask is alpha of blended primary and secondary detail map alpha multiplied by alpha of micro detail map.\n\nBLENDED BASE SPECULAR:\nSame as BLENDED, except specular mask is alpha is base map times alpha of micro detail map."),
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$177 },
		FIELD_EXPLANATION_EX("lens flares", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "lens flare spacing", "0 places a single lens flare", "world units" },
		{ _field_tag_reference, "lens flare", &blofeld::halo1::lens_flare_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		FIELD_EXPLANATION_EX("diffuse properties", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$178 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_tag_reference, "base map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_short_enum, "detail map function", "affects primary and secondary detail maps", &blofeld::halo1::unnamed_enum$179 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "primary detail map scale", "0 defaults to 1" },
		{ _field_tag_reference, "primary detail map", &blofeld::halo1::bitmap_reference },
		{ _field_real, "secondary detail map scale", "0 defaults to 1" },
		{ _field_tag_reference, "secondary detail map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_short_enum, "micro detail map function", &blofeld::halo1::unnamed_enum$179 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "micro detail map scale", "0 defaults to 1" },
		{ _field_tag_reference, "micro detail map", &blofeld::halo1::bitmap_reference },
		{ _field_real_rgb_color, "material color", "modulates incoming diffuse light, including lightmaps, but excluding self-illumination and specular effects" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("bump properties", nullptr, FIELD_FLAG_NONE, "Perforated (alpha-tested) shaders use alpha in bump map."),
		{ _field_real, "bump map scale" },
		{ _field_tag_reference, "bump map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("texture scrolling animation", nullptr, FIELD_FLAG_NONE, "Scrolls all 2D maps simultaneously."),
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "u-animation period", nullptr, "seconds" },
		{ _field_real, "u-animation scale", nullptr, "base map repeats" },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "v-animation period", nullptr, "seconds" },
		{ _field_real, "v-animation scale", nullptr, "base map repeats" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("self-illumination properties", nullptr, FIELD_FLAG_NONE, "There are three self-illumination effects which are added together. Each effect has an <on color>, used when the shader is active, and an <off color>, used when the shader is not active. The self-illumination map is used as follows:\n* RED: primary mask\n* GREEN: secondary mask\n* BLUE: plasma mask\n* ALPHA: plasma animation reference\n\nEach effect also has an animation <function>, <period> and <phase>, used when the shader is active. The primary and secondary effects simply modulate the <on color> by the animation value to produce an animation color, and then blend between the animation color and the <off color> based on the shader\'s activation level, and finally modulate by the mask.\n\nThe plasma shader compares the animation value with the alpha channel of the map (the plasma animation reference) and produces a high value when they are similar and a dark value when they are different. This value modulates the <plasma on color> to produce a plasma animation color, and the rest proceeds just like the primary and secondary effects."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$180 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real_rgb_color, "primary on color" },
		{ _field_real_rgb_color, "primary off color" },
		{ _field_short_enum, "primary animation function", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "primary animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "primary animation phase", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real_rgb_color, "secondary on color" },
		{ _field_real_rgb_color, "secondary off color" },
		{ _field_short_enum, "secondary animation function", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "secondary animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "secondary animation phase", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real_rgb_color, "plasma on color" },
		{ _field_real_rgb_color, "plasma off color" },
		{ _field_short_enum, "plasma animation function", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "plasma animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "plasma animation phase", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real, "map scale", "0 defaults to 1" },
		{ _field_tag_reference, "map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("specular properties", nullptr, FIELD_FLAG_NONE, "Controls dynamic specular highlights. The highlight is modulated by <brightness> as well as a blend between <perpendicular color> and <parallel color>.\n\nSet <brightness> to zero to disable."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$181 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real_fraction, "brightness", "0 is no specular hilights", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_real_rgb_color, "perpendicular color", "hilight color when viewed perpendicularly" },
		{ _field_real_rgb_color, "parallel color", "hilight color when viewed at a glancing angle" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("reflection properties", nullptr, FIELD_FLAG_NONE, "Controls environment cube map reflections. The color of the cube map is \"tinted\" by a blend between <perpendicular color> and <parallel color> from the SPECULAR PROPERTIES above, and then modulated by a blend between <perpendicular brightness> and <parallel brightness>.\n\nBUMPED CUBE MAP:\nThis type of reflection uses the shader\'s bump map (if it exists) to affect the reflection, as well as the perpendicular and parallel brightness (i.e. the \"fresnel\" effect).\n\nFLAT CUBE MAP:\nThis is the fastest type of reflection. The bump map is used to attenuate the fresnel effect, but the reflection image itself is not bumped.\n\nClear <reflection cube map> or set both <perpendicular brightness> and <parallel brightness> to zero to disable."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$182 },
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$183 },
		{ _field_real_fraction, "lightmap brightness scale", "reflection brightness when lightmap brightness is 1", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_real_fraction, "perpendicular brightness", "brightness when viewed perpendicularly", nullptr, "[0,1]" },
		{ _field_real_fraction, "parallel brightness", "brightness when viewed at a glancing angle", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "reflection cube map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$176)
	{
		"alpha-tested",
		"bump map is specular mask",
		"true atmospheric fog"
	};
	STRING_LIST(unnamed_enum$176, unnamed_enum$176_strings, _countof(unnamed_enum$176_strings));

	STRINGS(unnamed_enum$177)
	{
		"normal",
		"blended",
		"blended base specular"
	};
	STRING_LIST(unnamed_enum$177, unnamed_enum$177_strings, _countof(unnamed_enum$177_strings));

	STRINGS(unnamed_enum$178)
	{
		"rescale detail maps",
		"rescale bump map"
	};
	STRING_LIST(unnamed_enum$178, unnamed_enum$178_strings, _countof(unnamed_enum$178_strings));

	STRINGS(unnamed_enum$179)
	{
		"double/biased multiply",
		"multiply",
		"double/biased add"
	};
	STRING_LIST(unnamed_enum$179, unnamed_enum$179_strings, _countof(unnamed_enum$179_strings));

	STRINGS(unnamed_enum$180)
	{
		"unfiltered"
	};
	STRING_LIST(unnamed_enum$180, unnamed_enum$180_strings, _countof(unnamed_enum$180_strings));

	STRINGS(unnamed_enum$181)
	{
		"overbright",
		"extra-shiny",
		"lightmap is specular"
	};
	STRING_LIST(unnamed_enum$181, unnamed_enum$181_strings, _countof(unnamed_enum$181_strings));

	STRINGS(unnamed_enum$182)
	{
		"dynamic mirror"
	};
	STRING_LIST(unnamed_enum$182, unnamed_enum$182_strings, _countof(unnamed_enum$182_strings));

	STRINGS(unnamed_enum$183)
	{
		"bumped cube-map",
		"flat cube-map",
		"bumped radiosity"
	};
	STRING_LIST(unnamed_enum$183, unnamed_enum$183_strings, _countof(unnamed_enum$183_strings));


	TAG_GROUP(
		shader_model_group,
		SHADER_MODEL_TAG,
		&shader_group,
		SHADER_TAG,
		shader_model);

	TAG_BLOCK(
		shader_model,
		"shader_model_group_block",
		1,
		"s_shader_model",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("model shader", nullptr, FIELD_FLAG_NONE, "Setting <true atmospheric fog> enables per-pixel atmospheric fog but disables point/spot lights, planar fog, and the ability to control the atmospheric fog density for this shader."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$184 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_fraction, "translucency", "amount of light that can illuminate the shader from behind" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("change color", nullptr, FIELD_FLAG_NONE, "Change color is used to recolor the diffuse map, it affects pixels based on the BLUE channel of the multipurpose map."),
		{ _field_short_enum, "change color source", &blofeld::halo1::unnamed_enum$39 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("self-illumination", nullptr, FIELD_FLAG_NONE, "Self-illumination adds diffuse light to pixels based on the GREEN channel of the multipurpose map. The external self-illumination color referenced by <color source> is modulated by the self-illumination animation."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$185 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "color source", &blofeld::halo1::unnamed_enum$39 },
		{ _field_short_enum, "animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "animation period", nullptr, "seconds" },
		{ _field_real_rgb_color, "animation color lower bound" },
		{ _field_real_rgb_color, "animation color upper bound" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("maps", nullptr, FIELD_FLAG_NONE, "Base map alpha is used for alpha-testing.\n\nMultipurpose map is used for the following:\n* RED: specular reflection mask (modulates reflections)\n* GREEN: self-illumination mask (adds to diffuse light)\n* BLUE: primary change color mask (recolors diffuse map)\n* ALPHA: auxiliary mask\n\nNote that when DXT1 compressed color-key textures are used for the multipurpose map (as they should be normally), the alpha channel is 1-bit and any non-zero alpha pixels must have zero-color, therefore the secondary change color mask cannot affect pixels already affected by any of the other channels.\n\nDetail map affects diffuse map, and optionally affects reflection if <detail after reflection> flag is set."),
		{ _field_real, "map u-scale", "0 defaults to 1; scales all 2D maps simultaneously" },
		{ _field_real, "map v-scale", "0 defaults to 1; scales all 2D maps simultaneously" },
		{ _field_tag_reference, "base map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_tag_reference, "multipurpose map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_enum, "detail function", "controls how detail map is applied to diffuse map", &blofeld::halo1::unnamed_enum$186 },
		{ _field_short_enum, "detail mask", "controls how detail map is masked", &blofeld::halo1::unnamed_enum$187 },
		{ _field_real, "detail map scale", "0 defaults to 1" },
		{ _field_tag_reference, "detail map", &blofeld::halo1::bitmap_reference },
		{ _field_real, "detail map v-scale", "0 defaults to 1 (applied on top of detail map scale above)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("texture scrolling animation", nullptr, FIELD_FLAG_NONE, "Scrolls all 2D maps simultaneously."),
		{ _field_short_enum, "u-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "u-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "u-animation phase" },
		{ _field_real, "u-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "v-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "v-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "v-animation phase" },
		{ _field_real, "v-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "rotation-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "rotation-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "rotation-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "rotation-animation phase" },
		{ _field_real, "rotation-animation scale", "0 defaults to 360", "degrees" },
		{ _field_real_point_2d, "rotation-animation center" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("reflection properties", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "reflection falloff distance", "distance at which the reflection begins to fade out", "world units" },
		{ _field_real, "reflection cutoff distance", "distance at which the reflection fades out entirely (0 means no cutoff)", "world units" },
		{ _field_real_fraction, "perpendicular brightness", "reflection brightness when viewed perpendicularly", nullptr, "[0,1]" },
		{ _field_real_rgb_color, "perpendicular tint color", "reflection tint color when viewed perpendicularly" },
		{ _field_real_fraction, "parallel brightness", "reflection brightness when viewed at a glancing angle", nullptr, "[0,1]" },
		{ _field_real_rgb_color, "parallel tint color", "reflection tint color when viewed at a glancing angle" },
		{ _field_tag_reference, "reflection cube map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$184)
	{
		"detail after reflection",
		"two-sided",
		"not alpha-tested",
		"alpha-blended decal",
		"true atmospheric fog",
		"disable two-sided culling"
	};
	STRING_LIST(unnamed_enum$184, unnamed_enum$184_strings, _countof(unnamed_enum$184_strings));

	STRINGS(unnamed_enum$185)
	{
		"no random phase"
	};
	STRING_LIST(unnamed_enum$185, unnamed_enum$185_strings, _countof(unnamed_enum$185_strings));

	STRINGS(unnamed_enum$186)
	{
		"double/biased multiply",
		"multiply",
		"double/biased add"
	};
	STRING_LIST(unnamed_enum$186, unnamed_enum$186_strings, _countof(unnamed_enum$186_strings));

	STRINGS(unnamed_enum$187)
	{
		"none",
		"reflection mask inverse",
		"reflection mask",
		"self-illumination mask inverse",
		"self-illumination mask",
		"change-color mask inverse",
		"change-color mask",
		"multipurpose map alpha inverse",
		"multipurpose map alpha"
	};
	STRING_LIST(unnamed_enum$187, unnamed_enum$187_strings, _countof(unnamed_enum$187_strings));


	TAG_GROUP(
		shader_transparent_generic_group,
		SHADER_TRANSPARENT_GENERIC_TAG,
		&shader_group,
		SHADER_TAG,
		shader_transparent_generic);

	TAG_BLOCK(
		shader_transparent_generic,
		"shader_transparent_generic_group_block",
		1,
		"s_shader_transparent_generic",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("generic transparent shader", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_char_integer, "numeric counter limit", nullptr, nullptr, "[0,255]" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$188 },
		{ _field_short_enum, "first map type", &blofeld::halo1::unnamed_enum$189 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_short_enum, "framebuffer fade source", "fade is multiplied by this external value", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("lens flares", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "lens flare spacing", "0 places a single lens flare", "world units" },
		{ _field_tag_reference, "lens flare", &blofeld::halo1::lens_flare_reference$2 },
		{ _field_block, "extra layers", &blofeld::halo1::shader_transparent_layer_block },
		{ _field_block, "maps", &blofeld::halo1::shader_transparent_generic_map_block },
		{ _field_block, "stages", &blofeld::halo1::shader_transparent_generic_stage_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$188)
	{
		"alpha-tested",
		"decal",
		"two-sided",
		"first map is in screenspace",
		"draw before water",
		"ignore effect",
		"scale first map with distance",
		"numeric"
	};
	STRING_LIST(unnamed_enum$188, unnamed_enum$188_strings, _countof(unnamed_enum$188_strings));

	STRINGS(unnamed_enum$189)
	{
		"2D map",
		"reflection cube map",
		"object-centered cube map",
		"viewer-centered cube map"
	};
	STRING_LIST(unnamed_enum$189, unnamed_enum$189_strings, _countof(unnamed_enum$189_strings));

	TAG_BLOCK(
		shader_transparent_generic_stage_block,
		"shader_transparent_generic_stage_block",
		7,
		"s_shader_transparent_generic_stage_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$191 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("constants and animation", nullptr, FIELD_FLAG_NONE, "Constant color 0 is animated in exactly the same way as the self-illumination color of the model shader, except that it has an alpha component in addition to the RGB components. Constant color 1 is just a constant."),
		{ _field_short_enum, "color0 source", &blofeld::halo1::unnamed_enum$39 },
		{ _field_short_enum, "color0 animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "color0 animation period", "0 defaults to 1", "seconds" },
		{ _field_real_argb_color, "color0 animation lower bound" },
		{ _field_real_argb_color, "color0 animation upper bound" },
		{ _field_real_argb_color, "color1" },
		FIELD_EXPLANATION_EX("color inputs", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "input A", &blofeld::halo1::unnamed_enum$192 },
		{ _field_short_enum, "input A mapping", &blofeld::halo1::unnamed_enum$193 },
		{ _field_short_enum, "input B", &blofeld::halo1::unnamed_enum$192 },
		{ _field_short_enum, "input B mapping", &blofeld::halo1::unnamed_enum$193 },
		{ _field_short_enum, "input C", &blofeld::halo1::unnamed_enum$192 },
		{ _field_short_enum, "input C mapping", &blofeld::halo1::unnamed_enum$193 },
		{ _field_short_enum, "input D", &blofeld::halo1::unnamed_enum$192 },
		{ _field_short_enum, "input D mapping", &blofeld::halo1::unnamed_enum$193 },
		FIELD_EXPLANATION_EX("color outputs", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "output AB", &blofeld::halo1::unnamed_enum$194 },
		{ _field_short_enum, "output AB function", &blofeld::halo1::unnamed_enum$195 },
		{ _field_short_enum, "output CD", &blofeld::halo1::unnamed_enum$194 },
		{ _field_short_enum, "output CD function", &blofeld::halo1::unnamed_enum$195 },
		{ _field_short_enum, "output AB CD mux/sum", &blofeld::halo1::unnamed_enum$194 },
		{ _field_short_enum, "output mapping", &blofeld::halo1::unnamed_enum$196 },
		FIELD_EXPLANATION_EX("alpha inputs", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "input A", &blofeld::halo1::unnamed_enum$197 },
		{ _field_short_enum, "input A mapping", &blofeld::halo1::unnamed_enum$193 },
		{ _field_short_enum, "input B", &blofeld::halo1::unnamed_enum$197 },
		{ _field_short_enum, "input B mapping", &blofeld::halo1::unnamed_enum$193 },
		{ _field_short_enum, "input C", &blofeld::halo1::unnamed_enum$197 },
		{ _field_short_enum, "input C mapping", &blofeld::halo1::unnamed_enum$193 },
		{ _field_short_enum, "input D", &blofeld::halo1::unnamed_enum$197 },
		{ _field_short_enum, "input D mapping", &blofeld::halo1::unnamed_enum$193 },
		FIELD_EXPLANATION_EX("alpha outputs", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "output AB", &blofeld::halo1::unnamed_enum$198 },
		{ _field_short_enum, "output CD", &blofeld::halo1::unnamed_enum$198 },
		{ _field_short_enum, "output AB CD mux/sum", &blofeld::halo1::unnamed_enum$198 },
		{ _field_short_enum, "output mapping", &blofeld::halo1::unnamed_enum$196 },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$191)
	{
		"color mux",
		"alpha mux",
		"A-out controls color0 animation"
	};
	STRING_LIST(unnamed_enum$191, unnamed_enum$191_strings, _countof(unnamed_enum$191_strings));

	STRINGS(unnamed_enum$192)
	{
		"zero",
		"one",
		"one half",
		"negative one",
		"negative one half",
		"map color 0",
		"map color 1",
		"map color 2",
		"map color 3",
		"vertex color 0 / diffuse light",
		"vertex color 1 / fade(perpendicular)",
		"scratch color 0",
		"scratch color 1",
		"constant color 0",
		"constant color 1",
		"map alpha 0",
		"map alpha 1",
		"map alpha 2",
		"map alpha 3",
		"vertex alpha 0 / fade(none)",
		"vertex alpha 1 / fade(perpendicular)",
		"scratch alpha 0",
		"scratch alpha 1",
		"constant alpha 0",
		"constant alpha 1"
	};
	STRING_LIST(unnamed_enum$192, unnamed_enum$192_strings, _countof(unnamed_enum$192_strings));

	STRINGS(unnamed_enum$193)
	{
		"clamp(x)",
		"1 - clamp(x)",
		"2*clamp(x) - 1",
		"1 - 2*clamp(x)",
		"clamp(x) - 1/2",
		"1/2 - clamp(x)",
		"x",
		"-x"
	};
	STRING_LIST(unnamed_enum$193, unnamed_enum$193_strings, _countof(unnamed_enum$193_strings));

	STRINGS(unnamed_enum$194)
	{
		"discard",
		"scratch color 0 / final color",
		"scratch color 1",
		"vertex color 0",
		"vertex color 1",
		"map color 0",
		"map color 1",
		"map color 2",
		"map color 3"
	};
	STRING_LIST(unnamed_enum$194, unnamed_enum$194_strings, _countof(unnamed_enum$194_strings));

	STRINGS(unnamed_enum$195)
	{
		"multiply",
		"dot product"
	};
	STRING_LIST(unnamed_enum$195, unnamed_enum$195_strings, _countof(unnamed_enum$195_strings));

	STRINGS(unnamed_enum$196)
	{
		"identity",
		"scale by 1/2",
		"scale by 2",
		"scale by 4",
		"bias by -1/2",
		"expand normal"
	};
	STRING_LIST(unnamed_enum$196, unnamed_enum$196_strings, _countof(unnamed_enum$196_strings));

	STRINGS(unnamed_enum$197)
	{
		"zero",
		"one",
		"one half",
		"negative one",
		"negative one half",
		"map alpha 0",
		"map alpha 1",
		"map alpha 2",
		"map alpha 3",
		"vertex alpha 0 / fade(none)",
		"vertex alpha 1 / fade(perpendicular)",
		"scratch alpha 0",
		"scratch alpha 1",
		"constant alpha 0",
		"constant alpha 1",
		"map blue 0",
		"map blue 1",
		"map blue 2",
		"map blue 3",
		"vertex blue 0 / blue light",
		"vertex blue 1 / fade(parallel)",
		"scratch blue 0",
		"scratch blue 1",
		"constant blue 0",
		"constant blue 1"
	};
	STRING_LIST(unnamed_enum$197, unnamed_enum$197_strings, _countof(unnamed_enum$197_strings));

	STRINGS(unnamed_enum$198)
	{
		"discard",
		"scratch alpha 0 / final alpha",
		"scratch alpha 1",
		"vertex alpha 0 / fog",
		"vertex alpha 1",
		"map alpha 0",
		"map alpha 1",
		"map alpha 2",
		"map alpha 3"
	};
	STRING_LIST(unnamed_enum$198, unnamed_enum$198_strings, _countof(unnamed_enum$198_strings));

	TAG_BLOCK(
		shader_transparent_generic_map_block,
		"shader_transparent_generic_map_block",
		4,
		"s_shader_transparent_generic_map_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$190 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "map u-scale", "0 defaults to 1" },
		{ _field_real, "map v-scale", "0 defaults to 1" },
		{ _field_real, "map u-offset" },
		{ _field_real, "map v-offset" },
		{ _field_real, "map rotation", nullptr, "degrees" },
		{ _field_real_fraction, "mipmap bias", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "map", &blofeld::halo1::bitmap_reference },
		FIELD_EXPLANATION_EX("2D texture animation", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "u-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "u-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "u-animation phase" },
		{ _field_real, "u-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "v-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "v-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "v-animation phase" },
		{ _field_real, "v-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "rotation-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "rotation-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "rotation-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "rotation-animation phase" },
		{ _field_real, "rotation-animation scale", "0 defaults to 360", "degrees" },
		{ _field_real_point_2d, "rotation-animation center" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$190)
	{
		"unfiltered",
		"u-clamped",
		"v-clamped"
	};
	STRING_LIST(unnamed_enum$190, unnamed_enum$190_strings, _countof(unnamed_enum$190_strings));

	TAG_BLOCK(
		shader_transparent_layer_block,
		"shader_transparent_layer_block",
		4,
		"s_shader_transparent_layer_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "shader", &blofeld::halo1::shader_reference },
		{ _field_terminator }
	};


	TAG_GROUP(
		shader_transparent_chicago_group,
		SHADER_TRANSPARENT_CHICAGO_TAG,
		&shader_group,
		SHADER_TAG,
		shader_transparent_chicago);

	TAG_BLOCK(
		shader_transparent_chicago,
		"shader_transparent_chicago_group_block",
		1,
		"s_shader_transparent_chicago",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("chicago shader", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_char_integer, "numeric counter limit", nullptr, nullptr, "[0,255]" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$188 },
		{ _field_short_enum, "first map type", &blofeld::halo1::unnamed_enum$199 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_short_enum, "framebuffer fade source", "fade is multiplied by this external value", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("lens flares", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "lens flare spacing", "0 places a single lens flare", "world units" },
		{ _field_tag_reference, "lens flare", &blofeld::halo1::lens_flare_reference$2 },
		{ _field_block, "extra layers", &blofeld::halo1::shader_transparent_layer_block },
		{ _field_block, "maps", &blofeld::halo1::shader_transparent_chicago_map_block },
		{ _field_long_flags, "extra flags", &blofeld::halo1::unnamed_enum$202 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$199)
	{
		"2D map",
		"first map is reflection cube map",
		"first map is object-centered cube map",
		"first map is viewer-centered cube map"
	};
	STRING_LIST(unnamed_enum$199, unnamed_enum$199_strings, _countof(unnamed_enum$199_strings));

	STRINGS(unnamed_enum$202)
	{
		"don\'t fade active-camouflage",
		"numeric countdown timer"
	};
	STRING_LIST(unnamed_enum$202, unnamed_enum$202_strings, _countof(unnamed_enum$202_strings));

	TAG_BLOCK(
		shader_transparent_chicago_map_block,
		"shader_transparent_chicago_map_block",
		4,
		"s_shader_transparent_chicago_map_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$200 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_short_enum, "color function", "ignored for last map", &blofeld::halo1::unnamed_enum$201 },
		{ _field_short_enum, "alpha function", "ignored for last map", &blofeld::halo1::unnamed_enum$201 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_real, "map u-scale", "0 defaults to 1" },
		{ _field_real, "map v-scale", "0 defaults to 1" },
		{ _field_real, "map u-offset" },
		{ _field_real, "map v-offset" },
		{ _field_real, "map rotation", nullptr, "degrees" },
		{ _field_real_fraction, "mipmap bias", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "map", FIELD_FLAG_INDEX, &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		FIELD_EXPLANATION_EX("2D texture animation", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "u-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "u-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "u-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "u-animation phase" },
		{ _field_real, "u-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "v-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "v-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "v-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "v-animation phase" },
		{ _field_real, "v-animation scale", "0 defaults to 1", "repeats" },
		{ _field_short_enum, "rotation-animation source", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "rotation-animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "rotation-animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "rotation-animation phase" },
		{ _field_real, "rotation-animation scale", "0 defaults to 360", "degrees" },
		{ _field_real_point_2d, "rotation-animation center" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$200)
	{
		"unfiltered",
		"alpha replicate",
		"u-clamped",
		"v-clamped"
	};
	STRING_LIST(unnamed_enum$200, unnamed_enum$200_strings, _countof(unnamed_enum$200_strings));

	STRINGS(unnamed_enum$201)
	{
		"current",
		"next map",
		"multiply",
		"double-multiply",
		"add",
		"add-signed current",
		"add-signed next map",
		"subtract current",
		"subtract next map",
		"blend current alpha",
		"blend current alpha-inverse",
		"blend next map alpha",
		"blend next map alpha-inverse"
	};
	STRING_LIST(unnamed_enum$201, unnamed_enum$201_strings, _countof(unnamed_enum$201_strings));


	TAG_GROUP(
		shader_transparent_chicago_extended_group,
		SHADER_TRANSPARENT_CHICAGO_EXTENDED_TAG,
		&shader_group,
		SHADER_TAG,
		shader_transparent_chicago_extended);

	TAG_BLOCK(
		shader_transparent_chicago_extended,
		"shader_transparent_chicago_extended_group_block",
		1,
		"s_shader_transparent_chicago_extended",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("chicago shader extended", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_char_integer, "numeric counter limit", nullptr, nullptr, "[0,255]" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$188 },
		{ _field_short_enum, "first map type", &blofeld::halo1::unnamed_enum$199 },
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		{ _field_short_enum, "framebuffer fade mode", &blofeld::halo1::unnamed_enum$52 },
		{ _field_short_enum, "framebuffer fade source", "fade is multiplied by this external value", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("lens flares", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "lens flare spacing", "0 places a single lens flare", "world units" },
		{ _field_tag_reference, "lens flare", &blofeld::halo1::lens_flare_reference$2 },
		{ _field_block, "extra layers", &blofeld::halo1::shader_transparent_layer_block },
		{ _field_block, "4 stage maps", &blofeld::halo1::shader_transparent_chicago_map_block },
		{ _field_block, "2 stage maps", &blofeld::halo1::shader_transparent_chicago_map_block },
		{ _field_long_flags, "extra flags", &blofeld::halo1::unnamed_enum$202 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};


	TAG_GROUP(
		shader_transparent_water_group,
		SHADER_TRANSPARENT_WATER_TAG,
		&shader_group,
		SHADER_TAG,
		shader_transparent_water);

	TAG_BLOCK(
		shader_transparent_water,
		"shader_transparent_water_group_block",
		1,
		"s_shader_transparent_water",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("water shader", nullptr, FIELD_FLAG_NONE, "Base map color modulates the background, while base map alpha modulates reflection brightness. Both of these effects can be independently enables and disabled. Note that if the <base map alpha modulates reflection> flag is not set, then the perpendicular/parallel brightness has no effect (but the perpendicular/parallel tint color DOES has an effect)."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$203 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "base map", "controls reflection brightness and background tint", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real_fraction, "view perpendicular brightness", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "view perpendicular tint color" },
		{ _field_real_fraction, "view parallel brightness", "0 defaults to 1", nullptr, "[0,1]" },
		{ _field_real_rgb_color, "view parallel tint color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "reflection map", nullptr, nullptr, "[0,1]", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_angle, "ripple animation angle", nullptr, nullptr, "[0,360]" },
		{ _field_real, "ripple animation velocity" },
		{ _field_real, "ripple scale", "0 defaults to 1" },
		{ _field_tag_reference, "ripple maps", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "ripple mipmap levels", "0 defaults to 1" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "ripple mipmap fade factor", "flatness of last mipmap", nullptr, "[0,1]" },
		{ _field_real, "ripple mipmap detail bias" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		{ _field_block, "ripples", &blofeld::halo1::shader_transparent_water_ripple_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$203)
	{
		"base map alpha modulates reflection",
		"base map color modulates background",
		"atmospheric fog",
		"draw before fog"
	};
	STRING_LIST(unnamed_enum$203, unnamed_enum$203_strings, _countof(unnamed_enum$203_strings));

	TAG_BLOCK(
		shader_transparent_water_ripple_block,
		"shader_transparent_water_ripple_block",
		4,
		"s_shader_transparent_water_ripple_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "contribution factor", "0 defaults to 1", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_angle, "animation angle", nullptr, nullptr, "[0,360]" },
		{ _field_real, "animation velocity" },
		{ _field_real_vector_2d, "map offset" },
		{ _field_short_integer, "map repeats", "0 defaults to 1" },
		{ _field_short_integer, "map index", "index into ripple maps" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};


	TAG_GROUP(
		shader_transparent_glass_group,
		SHADER_TRANSPARENT_GLASS_TAG,
		&shader_group,
		SHADER_TAG,
		shader_transparent_glass);

	TAG_BLOCK(
		shader_transparent_glass,
		"shader_transparent_glass_group_block",
		1,
		"s_shader_transparent_glass",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("glass shader", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$204 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("background tint properties", nullptr, FIELD_FLAG_NONE, "Background pixels are multiplied by the tint map and constant tint color."),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_real_rgb_color, "background tint color" },
		{ _field_real, "background tint map scale", "0 defaults to 1" },
		{ _field_tag_reference, "background tint map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("reflection properties", nullptr, FIELD_FLAG_NONE, "Reflection maps are multiplied by fresnel terms (glancing angles cause reflections to disappear) and then added to the background. The primary reflection map is textured normally, while the secondary reflection map is magnified."),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "reflection type", &blofeld::halo1::unnamed_enum$205 },
		{ _field_real_fraction, "perpendicular brightness", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "perpendicular tint color" },
		{ _field_real_fraction, "parallel brightness", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "parallel tint color" },
		{ _field_tag_reference, "reflection map", &blofeld::halo1::bitmap_reference },
		{ _field_real, "bump map scale" },
		{ _field_tag_reference, "bump map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		FIELD_EXPLANATION_EX("diffuse properties", nullptr, FIELD_FLAG_NONE, "Diffuse lights are accumulated in monochrome and then alpha-blended with diffuse map and diffuse detail map. The color is determined by double-multiplying both maps and multiplying with the accumulated light, the result being alpha-blended into the framebuffer. The opacity is determined by multiplying both map\'s alpha channels. Since this effect is alpha-blended, it covers up tinting and reflection on pixels with high opacity."),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "diffuse map scale", "0 defaults to 1" },
		{ _field_tag_reference, "diffuse map", &blofeld::halo1::bitmap_reference },
		{ _field_real, "diffuse detail map scale", "0 defaults to 1" },
		{ _field_tag_reference, "diffuse detail map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("specular properties", nullptr, FIELD_FLAG_NONE, "Specular lights are accumulated in monochrome and then alpha-blended with diffuse map and diffuse detail map. The color is determined by double-multiplying both maps and multiplying with the accumulated light, the result being alpha-blended into the framebuffer. The opacity is determined by multiplying both map\'s alpha channels. Since this effect is alpha-blended, it covers up tinting, reflection and diffuse texture on pixels with high opacity."),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "specular map scale", "0 defaults to 1" },
		{ _field_tag_reference, "specular map", &blofeld::halo1::bitmap_reference },
		{ _field_real, "specular detail map scale", "0 defaults to 1" },
		{ _field_tag_reference, "specular detail map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$204)
	{
		"alpha-tested",
		"decal",
		"two-sided",
		"bump map is specular mask"
	};
	STRING_LIST(unnamed_enum$204, unnamed_enum$204_strings, _countof(unnamed_enum$204_strings));

	STRINGS(unnamed_enum$205)
	{
		"bumped cube-map",
		"flat cube-map",
		"dynamic mirror"
	};
	STRING_LIST(unnamed_enum$205, unnamed_enum$205_strings, _countof(unnamed_enum$205_strings));


	TAG_GROUP(
		shader_transparent_meter_group,
		SHADER_TRANSPARENT_METER_TAG,
		&shader_group,
		SHADER_TAG,
		shader_transparent_meter);

	TAG_BLOCK(
		shader_transparent_meter,
		"shader_transparent_meter_group_block",
		1,
		"s_shader_transparent_meter",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("meter shader", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$206 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("colors", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_rgb_color, "gradient min color" },
		{ _field_real_rgb_color, "gradient max color" },
		{ _field_real_rgb_color, "background color" },
		{ _field_real_rgb_color, "flash color" },
		{ _field_real_rgb_color, "tint color", "modulates framebuffer color unless map alpha is zero" },
		{ _field_real_fraction, "meter transparency", "used only when 'tint mode-2' is set", nullptr, "[0,1]" },
		{ _field_real_fraction, "background transparency", "used only when 'tint mode-2' is set", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("external function sources", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "meter brightness source", "overall meter brightness (default is 1)", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "flash brightness source", "brightness of flash (default is 1)", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "value source", "position of flash leading edge (default is 1)", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "gradient source", "high color leading edge (default is 1)", &blofeld::halo1::unnamed_enum$38 },
		{ _field_short_enum, "flash-extension source", "position of flash extension leading edge (default is 1)", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$206)
	{
		"decal",
		"two-sided",
		"flash color is negative",
		"tint mode-2",
		"unfiltered"
	};
	STRING_LIST(unnamed_enum$206, unnamed_enum$206_strings, _countof(unnamed_enum$206_strings));


	TAG_GROUP(
		shader_transparent_plasma_group,
		SHADER_TRANSPARENT_PLASMA_TAG,
		&shader_group,
		SHADER_TAG,
		shader_transparent_plasma);

	TAG_BLOCK(
		shader_transparent_plasma,
		"shader_transparent_plasma_group_block",
		1,
		"s_shader_transparent_plasma",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "shader", &blofeld::halo1::shader_struct_definition },
		FIELD_EXPLANATION_EX("plasma shader", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("intensity", nullptr, FIELD_FLAG_NONE, "Controls how bright the plasma is."),
		{ _field_short_enum, "intensity source", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "intensity exponent", "0 defaults to 1" },
		FIELD_EXPLANATION_EX("offset", nullptr, FIELD_FLAG_NONE, "Controls how far the plasma energy extends from the model geometry."),
		{ _field_short_enum, "offset source", &blofeld::halo1::unnamed_enum$38 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "offset amount", nullptr, "world units" },
		{ _field_real, "offset exponent", "0 defaults to 1" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("color", nullptr, FIELD_FLAG_NONE, "Controls the tint color and Fresnel brightness effects."),
		{ _field_real_fraction, "perpendicular brightness", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "perpendicular tint color" },
		{ _field_real_fraction, "parallel brightness", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "parallel tint color" },
		{ _field_short_enum, "tint color source", "modulates perpendicular and parallel colors above", &blofeld::halo1::unnamed_enum$39 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("primary noise map", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "primary animation period", nullptr, "seconds" },
		{ _field_real_vector_3d, "primary animation direction" },
		{ _field_real, "primary noise map scale" },
		{ _field_tag_reference, "primary noise map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("secondary noise map", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "secondary animation period", nullptr, "seconds" },
		{ _field_real_vector_3d, "secondary animation direction" },
		{ _field_real, "secondary noise map scale" },
		{ _field_tag_reference, "secondary noise map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};


	TAG_GROUP(
		actor_group,
		ACTOR_TAG,
		nullptr,
		INVALID_TAG,
		actor);

	TAG_BLOCK(
		actor,
		"actor_group_block",
		1,
		"s_actor",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$207 },
		{ _field_long_flags, "more flags", &blofeld::halo1::unnamed_enum$208 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$167 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("perception", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "max vision distance", "maximum range of sight", "world units" },
		{ _field_angle, "central vision angle", "horizontal angle within which we see targets out to our maximum range", "degrees" },
		{ _field_angle, "max vision angle", "maximum horizontal angle within which we see targets at range", "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_angle, "peripheral vision angle", "maximum horizontal angle within which we can see targets out of the corner of our eye", "degrees" },
		{ _field_real, "peripheral distance", "maximum range at which we can see targets our of the corner of our eye", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_vector_3d, "standing gun offset", "offset of gun from feet when standing (x=forward, y=left, z=up)" },
		{ _field_real_vector_3d, "crouching gun offset", "offset of gun from feet when crouch (x=forward, y=left, z=up)" },
		{ _field_real, "hearing distance", "maximum range at which sounds can be heard", "world units" },
		{ _field_real, "notice projectile chance", "random chance of noticing a dangerous enemy projectile (e.g. grenade)", nullptr, "[0,1]" },
		{ _field_real, "notice vehicle chance", "random chance of noticing a dangerous vehicle", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "combat perception time", "time required to acknowledge a visible enemy when we are already in combat or searching for them", "seconds" },
		{ _field_real, "guard perception time", "time required to acknowledge a visible enemy when we have been alerted", "seconds" },
		{ _field_real, "non-combat perception time", "time required to acknowledge a visible enemy when we are not alerted", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("movement", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "dive into cover chance", "chance of running a dive animation when moving into cover", nullptr, "[0,1]" },
		{ _field_real, "emerge from cover chance", "chance of running an emerge animation when uncovering a target", nullptr, "[0,1]" },
		{ _field_real, "dive from grenade chance", "chance of running a dive animation when moving away from a grenade", nullptr, "[0,1]" },
		{ _field_real, "pathfinding radius", nullptr, "world units" },
		{ _field_real, "glass ignorance chance", "chance of not noticing that breakable surfaces have been destroyed", nullptr, "[0,1]" },
		{ _field_real, "stationary movement dist", "movement distance which is considered 'stationary' for considering whether we crouch", "world units" },
		{ _field_real, "free-flying sidestep", "distance which we allow sidestepping for flying units", "world units" },
		{ _field_angle, "begin moving angle", "we must be facing this close to our target before we start applying the throttle (default: 180 degrees)", "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("looking", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_euler_angles_2d, "maximum aiming deviation", "how far we can turn our weapon", "degrees" },
		{ _field_real_euler_angles_2d, "maximum looking deviation", "how far we can turn our head", "degrees" },
		{ _field_angle, "noncombat look delta L", "how far we can turn our head left away from our aiming vector when not in combat", "degrees" },
		{ _field_angle, "noncombat look delta R", "how far we can turn our head right away from our aiming vector when not in combat", "degrees" },
		{ _field_angle, "combat look delta L", "how far we can turn our head left away from our aiming vector when in combat", "degrees" },
		{ _field_angle, "combat look delta R", "how far we can turn our head right away from our aiming vector when in combat", "degrees" },
		{ _field_real_euler_angles_2d, "idle aiming range", "range in which we select random directions to aim in", "degrees" },
		{ _field_real_euler_angles_2d, "idle looking range", "range in which we select random directions to look at", "degrees" },
		{ _field_real_bounds, "event look time modifier", "multiplier for how long we look at interesting events (zero = unchanged)" },
		{ _field_real_bounds, "noncombat idle facing", "rate at which we change facing when looking around randomly when not in combat", "seconds" },
		{ _field_real_bounds, "noncombat idle aiming", "rate at which we change aiming directions when looking around randomly when not in combat", "seconds" },
		{ _field_real_bounds, "noncombat idle looking", "rate at which we change look around randomly when not in combat", "seconds" },
		{ _field_real_bounds, "guard idle facing", "rate at which we change facing when looking around randomly when guarding", "seconds" },
		{ _field_real_bounds, "guard idle aiming", "rate at which we change aiming directions when looking around randomly when guarding", "seconds" },
		{ _field_real_bounds, "guard idle looking", "rate at which we change look around randomly when guarding", "seconds" },
		{ _field_real_bounds, "combat idle facing", "rate at which we change facing when looking around randomly when searching or in combat", "seconds" },
		{ _field_real_bounds, "combat idle aiming", "rate at which we change aiming directions when looking around randomly when searching or in combat", "seconds" },
		{ _field_real_bounds, "combat idle looking", "rate at which we change look around randomly when searching or in combat", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "DO NOT USE", nullptr, "weapon", &blofeld::halo1::weapon_reference$4 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 268),
		{ _field_tag_reference, "DO NOT USE", nullptr, "projectile", &blofeld::halo1::projectile_reference },
		FIELD_EXPLANATION_EX("unopposable", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "unreachable danger trigger", "danger level of an unreachable enemy which will trigger a retreat if it continues over time", &blofeld::halo1::unnamed_enum$209 },
		{ _field_short_enum, "vehicle danger trigger", "danger level of a vehicle-based enemy which will trigger a retreat if it continues over time", &blofeld::halo1::unnamed_enum$209 },
		{ _field_short_enum, "player danger trigger", "danger level of an enemy player which will trigger a retreat if it continues over time", &blofeld::halo1::unnamed_enum$209 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_bounds, "danger trigger time", "how long it takes for an unopposable enemy that has the above danger level to trigger a retreat", "seconds" },
		{ _field_short_integer, "friends killed trigger", "if this many of our friends are killed by an unopposable enemy, we trigger a retreat (zero = never use this as a retreat condition)" },
		{ _field_short_integer, "friends retreating trigger", "if this many of our friends are retreating from an unopposable enemy, we retreat as well (zero = never use this as a retreat condition)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_bounds, "retreat time", "how long we retreat from an unopposable enemy for", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("panic", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "cowering time", "how long we hide in cover after being panicked", "seconds" },
		{ _field_real, "friend killed panic chance", "chance of panicking when we see a friend killed near us and the enemy is looking at us too", nullptr, "[0,1]" },
		{ _field_short_enum, "leader type", "if we see a friend of this type killed we have a chance of panicking", &blofeld::halo1::unnamed_enum$167 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "leader killed panic chance", "chance of panicking when we see a leader killed", nullptr, "[0,1]" },
		{ _field_real, "panic damage threshold", "panic if we take this much body damage in a short period of time", nullptr, "[0,1]" },
		{ _field_real, "surprise distance", "the distance at which newly acknowledged props or weapon impacts are considered 'close' for surprise purposes", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("defensive", nullptr, FIELD_FLAG_NONE, "danger values: being aimed at: 0.7\nan enemy shooting in our general direction: 1.2\nan enemy shooting directly at us: 1.6\nan enemy damaging us: 2.0"),
		{ _field_real_bounds, "hide behind cover time", "how long we stay behind cover after seeking cover", "seconds" },
		{ _field_real, "hide target-not-visible time", "if this is non-zero then we will only seek cover if our target has not been visible recently", "seconds" },
		{ _field_real, "hide shield fraction", "elites and jackals only seek cover if their shield falls below this value", nullptr, "[0,1]" },
		{ _field_real, "attack shield fraction", "elites and jackals only come out from cover to attack if they have this much shields", nullptr, "[0,1]" },
		{ _field_real, "pursue shield fraction", "elites and jackals only come out from cover to pursue if they have this much shields", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_short_enum, "defensive crouch type", &blofeld::halo1::unnamed_enum$210 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "attacking crouch threshold", "when in attacking mode, if our crouch type is based on shields, we crouch when our shields are below this number; if our crouch type is based on danger, we crouch when our danger is above this number" },
		{ _field_real, "defending crouch threshold", "when in defending mode, if our crouch type is based on shields, we crouch when our shields are below this number; if our crouch type is based on danger, we crouch when our danger is above this number" },
		{ _field_real, "min stand time", "minimum time to remain standing (zero = default)", "seconds" },
		{ _field_real, "min crouch time", "minimum time to remain crouching (zero = default)", "seconds" },
		{ _field_real, "defending hide time modifier", "how much longer we hide behind cover for when in the defending state (zero = unchanged)" },
		{ _field_real, "attacking evasion threshold", "when in attacking mode, we consider seeking cover or evading when our danger gets this high" },
		{ _field_real, "defending evasion threshold", "when in defending mode, we consider seeking cover or evading when our danger gets this high" },
		{ _field_real, "evasion seek-cover chance", "chance of seeking cover (otherwise we just evade)", nullptr, "[0,1]" },
		{ _field_real, "evasion delay time", "minimum time period between evasion moves", "seconds" },
		{ _field_real, "max seek-cover distance", "maximum distance we will consider going to find cover (zero = default)", "world units" },
		{ _field_real, "cover damage threshold", "how much damage we must take before we are allowed to seek cover (zero = always allowed to)", nullptr, "[0,1]" },
		{ _field_real, "stalking discovery time", "if our target sees us for this long while we are stalking them, our cover is blown and we do something else (zero = never stop stalking)", "seconds" },
		{ _field_real, "stalking max distance", "distance outside of which we don't bother stalking", "world units" },
		{ _field_angle, "stationary facing angle", "angle outside of which we must abandon a stationary facing direction and suffer any penalties", "angle" },
		{ _field_real, "change-facing stand time", "how long we must stand up for after changing our fixed stationary facing", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("pursuit", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "uncover delay time", "time to look at target's position after it becomes visible", "seconds" },
		{ _field_real_bounds, "target search time", "time we search at target's position", "seconds" },
		{ _field_real_bounds, "pursuit-position time", "time we search at a pursuit position", "seconds" },
		{ _field_short_integer, "num positions (coord)", "number of pursuit positions to check when in coordinated group search mode", nullptr, "[0,n]" },
		{ _field_short_integer, "num positions (normal)", "number of pursuit positions to check when in normal search mode", nullptr, "[0,n]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("berserk", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "melee attack delay", "how long we must wait between attempting melee attacks", "seconds" },
		{ _field_real, "melee fudge factor", "fudge factor that offsets how far in front of the target we start our attack (negative = we try to time our attack so that we go _through_ the target). this should be close to zero, but might be bigger for suiciding units", "world units" },
		{ _field_real, "melee charge time", "how long we can stay in the charging state trying to reach our target before we give up", "seconds" },
		{ _field_real_bounds, "melee leap range", "we can launch leaping melee attacks at targets within these ranges (zero = can't leap)", "world units" },
		{ _field_real, "melee leap velocity", "how fast we spring at targets when launching a leaping melee attack", "world units per tick" },
		{ _field_real, "melee leap chance", "chance of launching a leaping melee attack at a ground-based target (we always leap at flying targets)", nullptr, "[0,1]" },
		{ _field_real, "melee leap ballistic", "fraction that controls how ballistic our leaping melee trajectory is", nullptr, "[0,1]" },
		{ _field_real, "berserk damage amount", "amount of body damage in a short time that makes us berserk", nullptr, "[0,1]" },
		{ _field_real, "berserk damage threshold", "how low our body health must get before we will consider berserking", nullptr, "[0,1]" },
		{ _field_real, "berserk proximity", "if we ever get this close to a target, we berserk", "world units" },
		{ _field_real, "suicide sensing dist", "when we are this close to a target, we check to see if they're getting away and if so blow up", "world units" },
		{ _field_real, "berserk grenade chance", "chance of berserking when we have a dangerous projectile stuck to us", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("firing positions", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "guard position time", "time after which we decide to change guard positions (zero = never)", "seconds" },
		{ _field_real_bounds, "combat position time", "time after which we change combat firing positions", "seconds" },
		{ _field_real, "old position avoid dist", "distance we try and stay from our last discarded firing position", "world units" },
		{ _field_real, "friend avoid dist", "distance we try and stay from any friends", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		FIELD_EXPLANATION_EX("communication", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "noncombat idle speech time", "time between idle vocalizations when we are not in combat", "seconds" },
		{ _field_real_bounds, "combat idle speech time", "time between idle vocalizations when we are in combat or searching", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		{ _field_tag_reference, "DO NOT USE", nullptr, "major upgrade", &blofeld::halo1::actor_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$207)
	{
		"can see in darkness",
		"sneak uncovering target",
		"sneak uncovering pursuit position",
		"unused",
		"shoot at target\'s last location",
		"try to stay still when crouched",
		"crouch when not in combat",
		"crouch when guarding",
		"unused",
		"must crouch to shoot",
		"panic when surprised",
		"always charge at enemies",
		"gets in vehicles with player",
		"start firing before aligned",
		"standing must move forward",
		"crouching must move forward",
		"defensive crouch while charging",
		"use stalking behavior",
		"stalking freeze if exposed",
		"always berserk in attacking mode",
		"berserking uses panicked movement",
		"flying",
		"panicked by unopposable enemy",
		"crouch when hiding from unopposable",
		"always charge in \'attacking\' mode",
		"dive off ledges",
		"swarm",
		"suicidal melee attack",
		"cannot move while crouching",
		"fixed crouch facing",
		"crouch when in line of fire",
		"avoid friends\' line of fire"
	};
	STRING_LIST(unnamed_enum$207, unnamed_enum$207_strings, _countof(unnamed_enum$207_strings));

	STRINGS(unnamed_enum$208)
	{
		"avoid all enemy attack vectors",
		"must stand to fire",
		"must stop to fire",
		"disallow vehicle combat",
		"pathfinding ignores danger",
		"panic in groups",
		"no corpse shooting"
	};
	STRING_LIST(unnamed_enum$208, unnamed_enum$208_strings, _countof(unnamed_enum$208_strings));

	TAG_REFERENCE(weapon_reference$4, WEAPON_TAG);

	STRINGS(unnamed_enum$209)
	{
		"never",
		"visible",
		"shooting",
		"shooting near us",
		"damaging us",
		"unused",
		"unused",
		"unused",
		"unused",
		"unused"
	};
	STRING_LIST(unnamed_enum$209, unnamed_enum$209_strings, _countof(unnamed_enum$209_strings));

	STRINGS(unnamed_enum$210)
	{
		"never",
		"danger",
		"low shields",
		"hide behind shield",
		"any target",
		"flood shamble"
	};
	STRING_LIST(unnamed_enum$210, unnamed_enum$210_strings, _countof(unnamed_enum$210_strings));

	TAG_REFERENCE(actor_reference, ACTOR_TAG);


	TAG_GROUP(
		actor_variant_group,
		ACTOR_VARIANT_TAG,
		nullptr,
		INVALID_TAG,
		actor_variant);

	TAG_BLOCK(
		actor_variant,
		"actor_variant_group_block",
		1,
		"s_actor_variant",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$211 },
		{ _field_tag_reference, "actor definition", &blofeld::halo1::actor_reference },
		{ _field_tag_reference, "unit", &blofeld::halo1::unit_reference$2 },
		{ _field_tag_reference, "major variant", &blofeld::halo1::actor_variant_reference$4 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("movement switching", nullptr, FIELD_FLAG_NONE, "note: only the flood combat forms will ever try to switch movement types voluntarily during combat"),
		{ _field_short_enum, "movement type", "when we have a choice of movement types, which type we will use", &blofeld::halo1::unnamed_enum$212 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "initial crouch chance", "actors that start their movement try to maintain this fraction of crouched actors", nullptr, "[0,1]" },
		{ _field_real_bounds, "crouch time", "when switching movement types, how long we will stay crouched for before running", "seconds" },
		{ _field_real_bounds, "run time", "when switching movement types, how long we will run for before slowing to a crouch", "seconds" },
		FIELD_EXPLANATION_EX("ranged combat", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "weapon", &blofeld::halo1::weapon_reference$4 },
		{ _field_real, "maximum firing distance", "we can only fire our weapon at targets within this distance", "world units" },
		{ _field_real, "rate of fire", "how many times per second we pull the trigger (zero = continuously held down)" },
		{ _field_angle, "projectile error", "error added to every projectile we fire", "degrees" },
		{ _field_real_bounds, "first burst delay time", nullptr, "seconds" },
		{ _field_real, "new-target firing pattern time", nullptr, "seconds" },
		{ _field_real, "surprise delay time", nullptr, "seconds" },
		{ _field_real, "surprise fire-wildly time", nullptr, "seconds" },
		{ _field_real, "death fire-wildly chance", nullptr, nullptr, "[0,1]" },
		{ _field_real, "death fire-wildly time", nullptr, "seconds" },
		{ _field_real_bounds, "desired combat range", nullptr, "world units" },
		{ _field_real_vector_3d, "custom stand gun offset", "custom standing gun offset for overriding the default in the base actor" },
		{ _field_real_vector_3d, "custom crouch gun offset", "custom crouching gun offset for overriding the default in the base actor" },
		{ _field_real, "target tracking", "how well our bursts track moving targets. 0.0= fire at the position they were standing when we started the burst. 1.0= fire at current position", nullptr, "[0,1]" },
		{ _field_real, "target leading", "how much we lead moving targets. 0.0= no prediction. 1.0= predict completely.", nullptr, "[0,1]" },
		{ _field_real, "weapon damage modifier", "what fraction of its normal damage our weapon inflicts (zero = no modifier)" },
		{ _field_real, "damage per second", "only used if weapon damage modifier is zero... how much damage we should deliver to the target per second while firing a burst at them (zero = use weapon default)" },
		FIELD_EXPLANATION_EX("burst geometry", nullptr, FIELD_FLAG_NONE, "at the start of every burst we pick a random point near the target to fire at, on either the left or the right side.\nthe burst origin angle controls whether this error is exactly horizontal or might have some vertical component.\n\nover the course of the burst we move our projectiles back in the opposite direction towards the target. this return motion is also controlled by an angle that specifies how close to the horizontal it is.\n\nfor example if the burst origin angle and the burst return angle were both zero, and the return length was the same as the burst length, every burst would start the same amount away from the target (on either the left or right) and move back to exactly over the target at the end of the burst."),
		{ _field_real, "burst origin radius", "how far away from the target the starting point is", "world units" },
		{ _field_angle, "burst origin angle", "the range from the horizontal that our starting error can be", "degrees" },
		{ _field_real_bounds, "burst return length", "how far the burst point moves back towards the target (could be negative)", "world units" },
		{ _field_angle, "burst return angle", "the range from the horizontal that the return direction can be", "degrees" },
		{ _field_real_bounds, "burst duration", "how long each burst we fire is", "seconds" },
		{ _field_real_bounds, "burst separation", "how long we wait between bursts", "seconds" },
		{ _field_angle, "burst angular velocity", "the maximum rate at which we can sweep our fire (zero = unlimited)", "degrees per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "special damage modifier", "damage modifier for special weapon fire (applied in addition to the normal damage modifier. zero = no change)", nullptr, "[0,1]" },
		{ _field_angle, "special projectile error", "projectile error angle for special weapon fire (applied in addition to the normal error)", "degrees" },
		FIELD_EXPLANATION_EX("firing patterns", nullptr, FIELD_FLAG_NONE, "a firing pattern lets you modify the properties of an actor\'s burst geometry. actors choose which firing pattern to use based on their current state:\n     \'new-target\' when the target just appeared\n     \'moving\' when the actor is moving\n     \'berserk\' if the actor is berserk\nif none of these apply, no firing pattern is used.\n\nthe default values in the burst geometry are multiplied by any non-zero modifiers in the firing pattern."),
		{ _field_real, "new-target burst duration", "burst duration multiplier for newly appeared targets (zero = unchanged)" },
		{ _field_real, "new-target burst separation", "burst separation multiplier for newly appeared targets (zero = unchanged)" },
		{ _field_real, "new-target rate of fire", "rate-of-fire multiplier for newly appeared targets (zero = unchanged)" },
		{ _field_real, "new-target projectile error", "error multiplier for newly appeared targets (zero = unchanged)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "moving burst duration", "burst duration multiplier when the actor is moving (zero = unchanged)" },
		{ _field_real, "moving burst separation", "burst separation multiplier when the actor is moving (zero = unchanged)" },
		{ _field_real, "moving rate of fire", "rate-of-fire multiplier when the actor is moving (zero = unchanged)" },
		{ _field_real, "moving projectile error", "error multiplier when the actor is moving (zero = unchanged)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "berserk burst duration", "burst duration multiplier when the actor is berserk (zero = unchanged)" },
		{ _field_real, "berserk burst separation", "burst separation multiplier when the actor is berserk (zero = unchanged)" },
		{ _field_real, "berserk rate of fire", "rate-of-fire multiplier when the actor is berserk (zero = unchanged)" },
		{ _field_real, "berserk projectile error", "error multiplier when the actor is berserk (zero = unchanged)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("special-case firing properties", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "super-ballistic range", "we try to aim our shots super-ballistically if target is outside this range (zero = never)" },
		{ _field_real, "bombardment range", "we offset our burst targets randomly by this range when firing at non-visible enemies (zero = never)" },
		{ _field_real, "modified vision range", "any custom vision range that this actor variant has (zero = normal)" },
		{ _field_short_enum, "special-fire mode", "the type of special weapon fire that we can use", &blofeld::halo1::unnamed_enum$213 },
		{ _field_short_enum, "special-fire situation", "when we will decide to use our special weapon fire mode", &blofeld::halo1::unnamed_enum$214 },
		{ _field_real, "special-fire chance", "how likely we are to use our special weapon fire mode", nullptr, "[0,1]" },
		{ _field_real, "special-fire delay", "how long we must wait between uses of our special weapon fire mode", "seconds" },
		FIELD_EXPLANATION_EX("berserking and melee", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "melee range", "how close an enemy target must get before triggering a melee charge", "world units" },
		{ _field_real, "melee abort range", "if our target gets this far away from us, we stop trying to melee them", "world units" },
		{ _field_real_bounds, "berserk firing ranges", "if we are outside maximum range, we advance towards target, stopping when we reach minimum range", "world units" },
		{ _field_real, "berserk melee range", "while berserking, how close an enemy target must get before triggering a melee charge", "world units" },
		{ _field_real, "berserk melee abort range", "while berserking, if our target gets this far away from us, we stop trying to melee them", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("grenades", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "grenade type", "type of grenades that we throw", &blofeld::halo1::unnamed_enum$26 },
		{ _field_short_enum, "trajectory type", "how we throw our grenades", &blofeld::halo1::unnamed_enum$215 },
		{ _field_short_enum, "grenade stimulus", "what causes us to consider throwing a grenade", &blofeld::halo1::unnamed_enum$216 },
		{ _field_short_integer, "minimum enemy count", "how many enemies must be within the radius of the grenade before we will consider throwing there" },
		{ _field_real, "enemy radius", "we consider enemies within this radius when determining where to throw", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "grenade velocity", "how fast we can throw our grenades", "world units per second" },
		{ _field_real_bounds, "grenade ranges", "ranges within which we will consider throwing a grenade", "world units" },
		{ _field_real, "collateral damage radius", "we won't throw if there are friendlies around our target within this range", "world units" },
		{ _field_real_fraction, "grenade chance", "how likely we are to throw a grenade", nullptr, "[0,1]" },
		{ _field_real, "grenade check time", "for continuous stimuli (e.g. visible target), how often we check to see if we want to throw a grenade", "seconds" },
		{ _field_real, "encounter grenade timeout", "we cannot throw grenades if someone else in our encounter threw one this recently", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("items", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "equipment", "equipment item to drop when we die", &blofeld::halo1::equipment_reference },
		{ _field_short_integer_bounds, "grenade count", "number of grenades that we start with" },
		{ _field_real, "dont drop grenades chance", "how likely we are not to drop any grenades when we die, even if we still have some", nullptr, "[0,1]" },
		{ _field_real_bounds, "drop weapon loaded", "amount of ammo loaded into the weapon that we drop (in fractions of a clip, e.g. 0.3 to 0.5)" },
		{ _field_short_integer_bounds, "drop weapon ammo", "total number of rounds in the weapon that we drop (ignored for energy weapons)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("unit", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "body vitality", "maximum body vitality of our unit" },
		{ _field_real, "shield vitality", "maximum shield vitality of our unit" },
		{ _field_real, "shield sapping radius", "how far away we can drain the player's shields", "world units" },
		{ _field_short_integer, "forced shader permutation", "if nonzero, overrides the unit's shader permutation" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "change colors", &blofeld::halo1::actor_variant_change_colors_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$211)
	{
		"can shoot while flying",
		"interpolate color in HSV",
		"has unlimited grenades",
		"moveswitch stay w/ friends",
		"active camouflage",
		"super active camouflage",
		"cannot use ranged weapons",
		"prefer passenger seat"
	};
	STRING_LIST(unnamed_enum$211, unnamed_enum$211_strings, _countof(unnamed_enum$211_strings));

	TAG_REFERENCE(unit_reference$2, UNIT_TAG);

	TAG_REFERENCE(actor_variant_reference$4, ACTOR_VARIANT_TAG);

	STRINGS(unnamed_enum$212)
	{
		"always run",
		"always crouch",
		"switch types"
	};
	STRING_LIST(unnamed_enum$212, unnamed_enum$212_strings, _countof(unnamed_enum$212_strings));

	STRINGS(unnamed_enum$213)
	{
		"none",
		"overcharge",
		"secondary trigger"
	};
	STRING_LIST(unnamed_enum$213, unnamed_enum$213_strings, _countof(unnamed_enum$213_strings));

	STRINGS(unnamed_enum$214)
	{
		"never",
		"enemy visible",
		"enemy out of sight",
		"strafing"
	};
	STRING_LIST(unnamed_enum$214, unnamed_enum$214_strings, _countof(unnamed_enum$214_strings));

	STRINGS(unnamed_enum$215)
	{
		"toss",
		"lob",
		"bounce"
	};
	STRING_LIST(unnamed_enum$215, unnamed_enum$215_strings, _countof(unnamed_enum$215_strings));

	STRINGS(unnamed_enum$216)
	{
		"never",
		"visible target",
		"seek cover"
	};
	STRING_LIST(unnamed_enum$216, unnamed_enum$216_strings, _countof(unnamed_enum$216_strings));

	TAG_BLOCK(
		actor_variant_change_colors_block,
		"actor_variant_change_colors_block",
		4,
		"s_actor_variant_change_colors_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_rgb_color, "color lower bound" },
		{ _field_real_rgb_color, "color upper bound" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};


	TAG_GROUP(
		sky_group,
		SKY_TAG,
		nullptr,
		INVALID_TAG,
		sky);

	TAG_BLOCK(
		sky,
		"sky_group_block",
		1,
		"s_sky",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "model", &blofeld::halo1::gbxmodel_reference$4 },
		{ _field_tag_reference, "animation_graph", &blofeld::halo1::model_animations_reference$4 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real_rgb_color, "indoor ambient radiosity color", "the indoor ambient light color" },
		{ _field_real, "indoor ambient radiosity power", "the indoor ambient light power from 0 to infinity" },
		{ _field_real_rgb_color, "outdoor ambient radiosity color", "the outdoor ambient light color" },
		{ _field_real, "outdoor ambient radiosity power", "the outdoor ambient light power from 0 to infinity" },
		{ _field_real_rgb_color, "outdoor fog color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_fraction, "outdoor fog maximum density", "density at opaque distance - 0 defaults to 1", nullptr, "[0,1]" },
		{ _field_real, "outdoor fog start distance", "below this distance there is no fog", "world units" },
		{ _field_real, "outdoor fog opaque distance", "beyond this distance surfaces are completely fogged", "world units" },
		{ _field_real_rgb_color, "indoor fog color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_fraction, "indoor fog maximum density", "density at opaque distance - 0 defaults to 1", nullptr, "[0,1]" },
		{ _field_real, "indoor fog start distance", "below this distance there is no fog", "world units" },
		{ _field_real, "indoor fog opaque distance", "beyond this distance surfaces are completely fogged", "world units" },
		{ _field_tag_reference, "indoor fog screen", "used for FOG SCREEN only; not used for planar fog", &blofeld::halo1::fog_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_block, "shader functions", &blofeld::halo1::sky_shader_function_block },
		{ _field_block, "animations", &blofeld::halo1::sky_animation_block },
		{ _field_block, "lights", &blofeld::halo1::sky_light_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(gbxmodel_reference$4, GBXMODEL_TAG);

	TAG_REFERENCE(model_animations_reference$4, MODEL_ANIMATIONS_TAG);

	TAG_REFERENCE(fog_reference$2, FOG_TAG);

	TAG_BLOCK(
		sky_light_block,
		"sky_light_block",
		8,
		"s_sky_light_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("LENS FLARE", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "lens flare", &blofeld::halo1::lens_flare_reference$3 },
		{ _field_string, "lens flare marker name", "the lens flare for this light will be attached to the specified marker in the model" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		FIELD_EXPLANATION_EX("RADIOSITY", nullptr, FIELD_FLAG_NONE, "these parameters control how the light illuminates the world."),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$217 },
		{ _field_real_rgb_color, "color", "light color" },
		{ _field_real, "power", "light power from 0 to infinity" },
		{ _field_real, "test distance", "the length of the ray for shadow testing." },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_euler_angles_2d, "direction", "direction toward the light source in the sky." },
		{ _field_angle, "diameter", "angular diameter of the light source in the sky." },
		{ _field_terminator }
	};

	TAG_REFERENCE(lens_flare_reference$3, LENS_FLARE_TAG);

	STRINGS(unnamed_enum$217)
	{
		"affects exteriors",
		"affects interiors"
	};
	STRING_LIST(unnamed_enum$217, unnamed_enum$217_strings, _countof(unnamed_enum$217_strings));

	TAG_BLOCK(
		sky_animation_block,
		"sky_animation_block",
		8,
		"s_sky_animation_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "animation index", "the index of the animation in the animation graph" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "period", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	TAG_BLOCK(
		sky_shader_function_block,
		"sky_shader_function_block",
		8,
		"s_sky_shader_function_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_string, "global function name", "the global function that controls this shader value", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};


	TAG_GROUP(
		wind_group,
		WIND_TAG,
		nullptr,
		INVALID_TAG,
		wind);

	TAG_BLOCK(
		wind,
		"wind_group_block",
		1,
		"s_wind",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_bounds, "velocity", "the wind magnitude in the weather region scales the wind between these bounds", "world units" },
		{ _field_real_euler_angles_2d, "variation area", "the wind direction varies inside a box defined by these angles on either side of the direction from the weather region." },
		{ _field_real, "local variation weight" },
		{ _field_real, "local variation rate" },
		{ _field_real, "damping" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_terminator }
	};


	TAG_GROUP(
		sound_environment_group,
		SOUND_ENVIRONMENT_TAG,
		nullptr,
		INVALID_TAG,
		sound_environment);

	TAG_BLOCK(
		sound_environment,
		"sound_environment_group_block",
		1,
		"s_sound_environment",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "priority", "when multiple listeners are in different sound environments in split screen, the combined environment will be the one with the highest priority." },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "room intensity", "intensity of the room effect" },
		{ _field_real_fraction, "room intensity hf", "intensity of the room effect above the reference high frequency" },
		{ _field_real, "room rolloff (0 to 10)", "how quickly the room effect rolls off, from 0.0 to 10.0" },
		{ _field_real, "decay time (.1 to 20)", nullptr, "seconds" },
		{ _field_real, "decay hf ratio (.1 to 2)" },
		{ _field_real_fraction, "reflections intensity" },
		{ _field_real, "reflections delay (0 to .3)", nullptr, "seconds" },
		{ _field_real_fraction, "reverb intensity" },
		{ _field_real, "reverb delay (0 to .1)", nullptr, "seconds" },
		{ _field_real, "diffusion" },
		{ _field_real, "density" },
		{ _field_real, "hf reference(20 to 20,000)", "for hf values, what frequency defines hf, from 20 to 20,000", "Hz" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};


	TAG_GROUP(
		lens_flare_group,
		LENS_FLARE_TAG,
		nullptr,
		INVALID_TAG,
		lens_flare);

	TAG_BLOCK(
		lens_flare,
		"lens_flare_group_block",
		1,
		"s_lens_flare",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("lens flare", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "falloff angle", nullptr, "degrees" },
		{ _field_angle, "cutoff angle", nullptr, "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("occlusion", nullptr, FIELD_FLAG_NONE, "Occlusion factor affects overall lens flare brightness and can also affect scale. Occlusion never affects rotation."),
		{ _field_real, "occlusion radius", "radius of the square used to test occlusion", "world units" },
		{ _field_short_enum, "occlusion offset direction", &blofeld::halo1::unnamed_enum$218 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "near fade distance", "distance at which the lens flare brightness is maximum", "world units" },
		{ _field_real, "far fade distance", "distance at which the lens flare brightness is minimum; set to zero to disable distance fading", "world units" },
		FIELD_EXPLANATION_EX("bitmaps", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "bitmap", "used by reflections", &blofeld::halo1::bitmap_reference },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$219 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		FIELD_EXPLANATION_EX("corona rotation", nullptr, FIELD_FLAG_NONE, "Controls how corona rotation is affected by viewer and light angles."),
		{ _field_short_enum, "rotation function", &blofeld::halo1::unnamed_enum$220 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_angle, "rotation function scale", nullptr, "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("corona radius scale", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "horizontal scale", "amount to stretch the corona along the horizontal axis; 0 defaults to 1" },
		{ _field_real, "vertical scale", "amount to stretch the corona along the vertical axis; 0 defaults to 1" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_block, "reflections", &blofeld::halo1::lens_flare_reflection_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$218)
	{
		"toward viewer",
		"marker forward",
		"none"
	};
	STRING_LIST(unnamed_enum$218, unnamed_enum$218_strings, _countof(unnamed_enum$218_strings));

	STRINGS(unnamed_enum$219)
	{
		"sun"
	};
	STRING_LIST(unnamed_enum$219, unnamed_enum$219_strings, _countof(unnamed_enum$219_strings));

	STRINGS(unnamed_enum$220)
	{
		"none",
		"rotation A",
		"rotation B",
		"rotation-translation",
		"translation"
	};
	STRING_LIST(unnamed_enum$220, unnamed_enum$220_strings, _countof(unnamed_enum$220_strings));

	TAG_BLOCK(
		lens_flare_reflection_block,
		"lens_flare_reflection_block",
		32,
		"s_lens_flare_reflection_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$221 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "bitmap index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_real, "position", "0 is on top of light, 1 is opposite light, 0.5 is the center of the screen, etc.", "along flare axis" },
		{ _field_real, "rotation offset", nullptr, "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_bounds, "radius", "interpolated by light scale", "world units" },
		{ _field_short_enum, "radius scaled by", &blofeld::halo1::unnamed_enum$222 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_fraction_bounds, "brightness", "interpolated by light scale", nullptr, "[0,1]" },
		{ _field_short_enum, "brightness scaled by", &blofeld::halo1::unnamed_enum$222 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("tint color", nullptr, FIELD_FLAG_NONE, "Tinting and modulating are not the same; \'tinting\' a reflection will color the darker regions but leave the white highlights, while \'modulating\' will color everything uniformly (as in most games). The tint alpha controls how much the reflection is tinted as opposed to modulated (0 is modulated, 1 is tinted). If all components are zero, the reflection is fully tinted by the light color."),
		{ _field_real_argb_color, "tint color", "if a=r=g=b=0 use light color instead; alpha blends between modulation and tinting" },
		FIELD_EXPLANATION_EX("animation", nullptr, FIELD_FLAG_NONE, "Causes lens flare reflection to flicker, pulse, or whatever. Animated color modulates tint color, above, while animated alpha modulates brightness. Animation is ignored if tint color is BLACK or the animation function is ONE or ZERO."),
		{ _field_real_argb_color, "color lower bound", "if a=r=g=b=0, default to a=r=g=b=1" },
		{ _field_real_argb_color, "color upper bound", "if a=r=g=b=0, default to a=r=g=b=1" },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$223 },
		{ _field_short_enum, "animation function", &blofeld::halo1::unnamed_enum$42 },
		{ _field_real, "animation period", "0 defaults to 1", "seconds" },
		{ _field_real, "animation phase", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$221)
	{
		"align rotation with screen center",
		"radius NOT scaled by distance",
		"radius scaled by occlusion factor",
		"occluded by solid objects"
	};
	STRING_LIST(unnamed_enum$221, unnamed_enum$221_strings, _countof(unnamed_enum$221_strings));

	STRINGS(unnamed_enum$222)
	{
		"none",
		"rotation",
		"rotation and strafing",
		"distance from center"
	};
	STRING_LIST(unnamed_enum$222, unnamed_enum$222_strings, _countof(unnamed_enum$222_strings));

	STRINGS(unnamed_enum$223)
	{
		"interpolate color in hsv",
		"...more colors"
	};
	STRING_LIST(unnamed_enum$223, unnamed_enum$223_strings, _countof(unnamed_enum$223_strings));


	TAG_GROUP(
		fog_group,
		FOG_TAG,
		nullptr,
		INVALID_TAG,
		fog);

	TAG_BLOCK(
		fog,
		"fog_group_block",
		1,
		"s_fog",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("FLAGS", nullptr, FIELD_FLAG_NONE, "Setting <atmosphere dominant> prevents polygon popping when the atmospheric fog maximum density (in the sky tag) is 1 and the atmospheric fog opaque distance is less than the diameter of the map. However, this flag will cause artifacts when the camera goes below the fog plane - so it should only be used when the fog plane is close to the ground."),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$224 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		FIELD_EXPLANATION_EX("DENSITY", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_fraction, "maximum density", "planar fog density is clamped to this value", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "opaque distance", "the fog becomes opaque at this distance from the viewer", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "opaque depth", "the fog becomes opaque at this distance from its surface", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "distance to water plane", "the fog becomes water at this distance from its surface", "world units" },
		FIELD_EXPLANATION_EX("COLOR", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_rgb_color, "color" },
		FIELD_EXPLANATION_EX("SCREEN LAYERS", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$225 },
		{ _field_short_integer, "layer count", "0 layers disables the effect", nullptr, "[0,4]" },
		{ _field_real_bounds, "distance gradient", nullptr, "world units" },
		{ _field_fraction_bounds, "density gradient", nullptr, nullptr, "[0,1]" },
		{ _field_real, "start distance from fog plane", "do NOT set this to the same value as maximum_depth", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_rgb_color, "color", "0 defaults to planar fog color" },
		{ _field_real_fraction, "rotation multiplier", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "strafing multiplier", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "zoom multiplier", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "map scale", "0 defaults to 1" },
		{ _field_tag_reference, "map", &blofeld::halo1::bitmap_reference },
		FIELD_EXPLANATION_EX("SCREEN LAYER ANIMATION", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "animation period", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_bounds, "wind velocity", nullptr, "world units per second" },
		{ _field_real_bounds, "wind period", "0 defaults to 1", "seconds" },
		{ _field_real_fraction, "wind acceleration weight", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "wind perpendicular weight", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("SOUND", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "background sound", &blofeld::halo1::sound_looping_reference },
		{ _field_tag_reference, "sound environment", &blofeld::halo1::sound_environment_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 120),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$224)
	{
		"is water",
		"atmosphere dominant",
		"fog screen only"
	};
	STRING_LIST(unnamed_enum$224, unnamed_enum$224_strings, _countof(unnamed_enum$224_strings));

	STRINGS(unnamed_enum$225)
	{
		"no environment multipass",
		"no model multipass",
		"no texture-based falloff"
	};
	STRING_LIST(unnamed_enum$225, unnamed_enum$225_strings, _countof(unnamed_enum$225_strings));

	TAG_REFERENCE(sound_environment_reference$2, SOUND_ENVIRONMENT_TAG);


	TAG_GROUP(
		placeholder_group,
		PLACEHOLDER_TAG,
		&object_group,
		OBJECT_TAG,
		placeholder);

	TAG_BLOCK(
		placeholder,
		"placeholder_group_block",
		1,
		"s_placeholder",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "object", &blofeld::halo1::object_struct_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		{ _field_terminator }
	};


	TAG_GROUP(
		meter_group,
		METER_TAG,
		nullptr,
		INVALID_TAG,
		meter);

	TAG_BLOCK(
		meter,
		"meter_group_block",
		1,
		"s_meter",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$226 },
		{ _field_tag_reference, "stencil bitmaps", "two bitmaps specifying the mask and the meter levels", &blofeld::halo1::bitmap_reference$4 },
		{ _field_tag_reference, "source bitmap", "optional bitmap to draw into the unmasked regions of the meter (modulated by the colors below)", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "stencil sequence index" },
		{ _field_short_integer, "source sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_enum, "interpolate colors...", &blofeld::halo1::unnamed_enum$227 },
		{ _field_short_enum, "anchor colors...", &blofeld::halo1::unnamed_enum$228 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_argb_color, "empty color" },
		{ _field_real_argb_color, "full color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_real, "unmask distance", "fade from fully masked to fully unmasked this distance beyond full (and below empty)", "meter units" },
		{ _field_real, "mask distance", "fade from fully unmasked to fully masked this distance below full (and beyond empty)", "meter units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_data, "encoded stencil" },
		{ _field_terminator }
	};

	STRING_LIST(unnamed_enum$226, empty_string_list, 0);

	TAG_REFERENCE(bitmap_reference$4, BITMAP_TAG, _tag_reference_flag_dont_resolve_in_editor);

	STRINGS(unnamed_enum$227)
	{
		"linearly",
		"faster near empty",
		"faster near full",
		"through random noise"
	};
	STRING_LIST(unnamed_enum$227, unnamed_enum$227_strings, _countof(unnamed_enum$227_strings));

	STRINGS(unnamed_enum$228)
	{
		"at both ends",
		"at empty",
		"at full"
	};
	STRING_LIST(unnamed_enum$228, unnamed_enum$228_strings, _countof(unnamed_enum$228_strings));


	TAG_GROUP(
		decal_group,
		DECAL_TAG,
		nullptr,
		INVALID_TAG,
		decal);

	TAG_BLOCK(
		decal,
		"decal_group_block",
		1,
		"s_decal",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("decal", nullptr, FIELD_FLAG_NONE, "A \'compound decal\' is a chain of decals which are instantiated simultaneously. Compound decals are created by choosing a <next_decal_in_chain> below. NOTE: Do not attempt to create a circularly linked decal chain, i.e. A->B->C->A! Also, do not reference a decal from an effect if it is not the \'head\' of the chain; for example an effect should not instantiate decal B if the chain was A->B->C. Compound decals can have seperate bitmaps, seperate framebuffer blend functions, and can be drawn in seperate layers. In addition, each decal in the chain can either inherit its parent\'s <radius>, rotation, <color>, <fade>, and <sequence> - or it can randomly choose its own. This behavior is controlled by the \'geometry_inherited_by_next_decal_in_chain\' flag, below. \n\nThe decal <type> (or layer) determines the drawing order of the decal with respect to the rest of the environment. Decals in the primary layer are drawn after the environment diffuse texture, hence they affect the already-lit texture of the surface. Decals in the secondary layer are drawn immediately after decals in the primary layer, so they \'cover up\' the primary decals. Decals in the \'light\' layer are drawn before the environment diffuse texture, hence they affect the accumulated diffuse light and only indirectly affect the lit texture."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$229 },
		{ _field_short_enum, "type", "controls how the decal wraps onto surface geometry", &blofeld::halo1::unnamed_enum$230 },
		{ _field_short_enum, "layer", &blofeld::halo1::unnamed_enum$231 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "next decal in chain", &blofeld::halo1::decal_reference$2 },
		FIELD_EXPLANATION_EX("radius and color", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "radius", "0 defaults to 0.125", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_fraction_bounds, "intensity", "1 is fully visible, 0 is invisible", nullptr, "[0,1]" },
		{ _field_real_rgb_color, "color lower bounds" },
		{ _field_real_rgb_color, "color upper bounds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("animation", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_integer, "animation loop frame" },
		{ _field_short_integer, "animation speed", nullptr, nullptr, "[1,120] ticks per frame" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_real_bounds, "lifetime", nullptr, "seconds" },
		{ _field_real_bounds, "decay time", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("shader", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "framebuffer blend function", &blofeld::halo1::unnamed_enum$51 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "map", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("sprite info", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "maximum sprite extent", nullptr, "pixels", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$229)
	{
		"geometry inherited by next decal in chain",
		"interpolate color in hsv",
		"...more colors",
		"no random rotation",
		"water effect",
		"SAPIEN- snap to axis",
		"SAPIEN- incremental counter",
		"animation loop",
		"preserve aspect"
	};
	STRING_LIST(unnamed_enum$229, unnamed_enum$229_strings, _countof(unnamed_enum$229_strings));

	STRINGS(unnamed_enum$230)
	{
		"scratch",
		"splatter",
		"burn",
		"painted sign"
	};
	STRING_LIST(unnamed_enum$230, unnamed_enum$230_strings, _countof(unnamed_enum$230_strings));

	STRINGS(unnamed_enum$231)
	{
		"primary",
		"secondary",
		"light",
		"alpha-tested",
		"water"
	};
	STRING_LIST(unnamed_enum$231, unnamed_enum$231_strings, _countof(unnamed_enum$231_strings));

	TAG_REFERENCE(decal_reference$2, DECAL_TAG);


	TAG_GROUP(
		damage_effect_group,
		DAMAGE_EFFECT_TAG,
		nullptr,
		INVALID_TAG,
		damage_effect);

	TAG_BLOCK(
		damage_effect,
		"damage_effect_group_block",
		1,
		"s_damage_effect",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_bounds, "radius", nullptr, "world units" },
		{ _field_real_fraction, "cutoff scale", nullptr, nullptr, "[0,1]" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$232 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("screen flash", nullptr, FIELD_FLAG_NONE, "There are seven screen flash types:\n\nNONE: DST\'= DST\nLIGHTEN: DST\'= DST(1 - A) + C\nDARKEN: DST\'= DST(1 - A) - C\nMAX: DST\'= MAX[DST(1 - C), (C - A)(1-DST)]\nMIN: DST\'= MIN[DST(1 - C), (C + A)(1-DST)]\nTINT: DST\'= DST(1 - C) + (A*PIN[2C - 1, 0, 1] + A)(1-DST)\nINVERT: DST\'= DST(1 - C) + A)\n\nIn the above equations C and A represent the color and alpha of the screen flash, DST represents the color in the framebuffer before the screen flash is applied, and DST\' represents the color after the screen flash is applied."),
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$233 },
		{ _field_short_enum, "priority", &blofeld::halo1::unnamed_enum$234 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "duration", nullptr, "seconds" },
		{ _field_short_enum, "fade function", &blofeld::halo1::unnamed_enum$43 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_fraction, "maximum intensity", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_argb_color, "color" },
		FIELD_EXPLANATION_EX("low frequency vibrate", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_fraction, "frequency", nullptr, nullptr, "[0,1]" },
		{ _field_real, "duration", nullptr, "seconds" },
		{ _field_short_enum, "fade function", &blofeld::halo1::unnamed_enum$43 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("high frequency vibrate", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_fraction, "frequency", nullptr, nullptr, "[0,1]" },
		{ _field_real, "duration", nullptr, "seconds" },
		{ _field_short_enum, "fade function", &blofeld::halo1::unnamed_enum$43 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("temporary camera impulse", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "duration", nullptr, "seconds" },
		{ _field_short_enum, "fade function", &blofeld::halo1::unnamed_enum$43 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_angle, "rotation", nullptr, "degrees" },
		{ _field_real, "pushback", nullptr, "world units" },
		{ _field_real_bounds, "jitter", nullptr, "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("permanent camera impulse", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "angle", nullptr, "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("camera shaking", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "duration", "the effect will last for this duration.", "seconds" },
		{ _field_short_enum, "falloff function", "a function to envelope the effect's magnitude over time", &blofeld::halo1::unnamed_enum$43 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "random translation", "random translation in all directions", "world units" },
		{ _field_angle, "random rotation", "random rotation in all directions", "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_short_enum, "wobble function", "a function to perturb the effect's behavior over time", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "wobble function period", nullptr, "seconds" },
		{ _field_real_fraction, "wobble weight", "a value of 0.0 signifies that the wobble function has no effect; a value of 1.0 signifies that the effect will not be felt when the wobble function's value is zero." },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("sound", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "sound", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 112),
		FIELD_EXPLANATION_EX("breaking effect", nullptr, FIELD_FLAG_NONE, "Controls particle velocities when a damage effect shatters a materal."),
		{ _field_real, "forward velocity", nullptr, "world units per second" },
		{ _field_real, "forward radius", nullptr, "world units" },
		{ _field_real, "forward exponent" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "outward velocity", nullptr, "world units per second" },
		{ _field_real, "outward radius", nullptr, "world units" },
		{ _field_real, "outward exponent" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("damage", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "side effect", &blofeld::halo1::unnamed_enum$235 },
		{ _field_short_enum, "category", &blofeld::halo1::unnamed_enum$236 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$237 },
		{ _field_real, "AOE core radius", "if this is area of effect damage", "world units" },
		{ _field_real, "damage lower bound" },
		{ _field_real_bounds, "damage upper bound" },
		{ _field_real, "vehicle passthrough penalty", "zero damages passengers in vehicles, one does not", nullptr, "[0,1]" },
		{ _field_real, "active camouflage damage", "how much more visible this damage makes a player who is active camouflaged", nullptr, "[0,1]" },
		{ _field_real, "stun", "amount of stun added to damaged unit", nullptr, "[0,1]" },
		{ _field_real, "maximum stun", "damaged unit's stun will never exceed this amount", nullptr, "[0,1]" },
		{ _field_real, "stun time", "duration of stun due to this damage", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "instantaneous acceleration", nullptr, nullptr, "[0,+inf]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("damage modifiers", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "dirt", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "sand", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "stone", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "snow", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "wood", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "metal (hollow)", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "metal (thin)", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "metal (thick)", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "rubber", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "glass", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "force field", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "grunt", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "hunter armor", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "hunter skin", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "elite", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "jackal", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "jackal energy shield", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "engineer", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "engineer force field", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "flood combat form", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "flood carrier form", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "cyborg", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "cyborg energy shield", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "armored human", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "human", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "sentinel", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "monitor", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "plastic", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "water", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "leaves", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "elite energy shield", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "ice", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "hunter shield", nullptr, nullptr, "[0,+inf]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$232)
	{
		"don\'t scale damage by distance"
	};
	STRING_LIST(unnamed_enum$232, unnamed_enum$232_strings, _countof(unnamed_enum$232_strings));

	STRINGS(unnamed_enum$233)
	{
		"none",
		"lighten",
		"darken",
		"max",
		"min",
		"invert",
		"tint"
	};
	STRING_LIST(unnamed_enum$233, unnamed_enum$233_strings, _countof(unnamed_enum$233_strings));

	STRINGS(unnamed_enum$234)
	{
		"low",
		"medium",
		"high"
	};
	STRING_LIST(unnamed_enum$234, unnamed_enum$234_strings, _countof(unnamed_enum$234_strings));

	STRINGS(unnamed_enum$235)
	{
		"none",
		"harmless",
		"lethal to the unsuspecting",
		"emp"
	};
	STRING_LIST(unnamed_enum$235, unnamed_enum$235_strings, _countof(unnamed_enum$235_strings));

	STRINGS(unnamed_enum$236)
	{
		"none",
		"falling",
		"bullet",
		"grenade",
		"high explosive",
		"sniper",
		"melee",
		"flame",
		"mounted weapon",
		"vehicle",
		"plasma",
		"needle",
		"shotgun"
	};
	STRING_LIST(unnamed_enum$236, unnamed_enum$236_strings, _countof(unnamed_enum$236_strings));

	STRINGS(unnamed_enum$237)
	{
		"does not hurt owner",
		"can cause headshots",
		"pings resistant units",
		"does not hurt friends",
		"does not ping units",
		"detonates explosives",
		"only hurts shields",
		"causes flaming death",
		"damage indicators always point down",
		"skips shields",
		"only hurts one infection form",
		"can cause multiplayer headshots",
		"infection form pop"
	};
	STRING_LIST(unnamed_enum$237, unnamed_enum$237_strings, _countof(unnamed_enum$237_strings));


	TAG_GROUP(
		dialogue_group,
		DIALOGUE_TAG,
		nullptr,
		INVALID_TAG,
		dialogue);

	TAG_BLOCK(
		dialogue,
		"dialogue_group_block",
		1,
		"s_dialogue",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_SKIP_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("idle", nullptr, FIELD_FLAG_NONE, "vocalizations generated at intervals when nothing else is happening."),
		{ _field_tag_reference, "idle noncombat", "played randomly and intermittently whenever we aren't in combat", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "idle combat", "played randomly and intermittently whenever we're in combat", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "idle flee", "played continuously while we are fleeing", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("involuntary", nullptr, FIELD_FLAG_NONE, "vocalizations generated automatically when damaged; interrupt everything except scripted dialogue."),
		{ _field_tag_reference, "pain body minor", "took body damage", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "pain body major", "took a significant amount of body damage", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "pain shield", "took shield damage", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "pain falling", "took damage from falling", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "scream fear", "screaming in fear (falling to your death, explosive stuck to you)", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "scream pain", "screaming in pain (being flamed)", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "maimed limb", "limb body part (arm or leg) was destroyed", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "maimed head", "head body part was destroyed", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "death quiet", "died from minor damage, or was unprepared", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "death violent", "died from violent trauma", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "death falling", "died from falling", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "death agonizing", "died in a horribly painful fashion (burnt to death)", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "death instant", "died instantly", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "death flying", "died and was blown up into the air", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("hurting people", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "damaged friend", "hurt a friendly AI", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "damaged friend player", "hurt a friendly player", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "damaged enemy", "hurt an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "damaged enemy cm", "hurt an enemy: comment to friend", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("being hurt", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "hurt friend", "hurt by a friendly AI", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt friend re", "hurt by a friendly AI: response from that friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt friend player", "hurt by a friendly player", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy", "hurt by an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy re", "hurt by an enemy: response from the enemy that hurt us ('you like that?')", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy cm", "hurt by an enemy: comment from a friend of ours", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy bullet", "hurt by an enemy with bullets", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy needler", "hurt by an enemy with needles", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy plasma", "hurt by an enemy with a plasma bolt", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy sniper", "hurt by an enemy with a sniper weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy grenade", "a grenade is stuck to us", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy explosion", "hurt by an enemy with an explosive weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy melee", "hurt by an enemy with a melee weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy flame", "hurt by an enemy with flamethrower", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy shotgun", "hurt by an enemy with a shotgun", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy vehicle", "hurt by an enemy with a vehicle", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hurt enemy mountedweapon", "hurt by an enemy with a fixed weapon", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("killing people", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "killed friend", "killed a friendly AI", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed friend cm", "killed a friendly AI: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed friend player", "killed a friendly player", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed friend player cm", "killed a friendly player: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy", "killed an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy cm", "killed an enemy: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy player", "killed an enemy player", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy player cm", "killed an enemy player: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy covenant", "killed an enemy covenant", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy covenant cm", "killed an enemy covenant: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy floodcombat", "killed an enemy flood combat form", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy floodcombat cm", "killed an enemy flood combat form: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy floodcarrier", "killed an enemy flood carrier form", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy floodcarrier cm", "killed an enemy flood carrier form: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy sentinel", "killed an enemy sentinel", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy sentinel cm", "killed an enemy sentinel: comment from a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy bullet", "killed an enemy with bullets", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy needler", "killed an enemy with needles", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy plasma", "killed an enemy with a plasma bolt", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy sniper", "killed an enemy with a sniper weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy grenade", "killed an enemy with a grenade", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy explosion", "killed an enemy with an explosive weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy melee", "killed an enemy with a melee weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy flame", "killed an enemy with flamethrower", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy shotgun", "killed an enemy with a shotgun", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy vehicle", "killed an enemy by hitting them with a vehicle", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killed enemy mountedweapon", "killed an enemy with a fixed weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "killing spree", "we are on a killing spree", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("player kill responses", nullptr, FIELD_FLAG_NONE, "responses to a friendly player killing an enemy nearby"),
		{ _field_tag_reference, "player kill cm", "response to the player killing an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill bullet cm", "response to the player killing an enemy with bullets", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill needler cm", "response to the player killing an enemy with needles", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill plasma cm", "response to the player killing an enemy with a plasma bolt", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill sniper cm", "response to the player killing an enemy with a sniper weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "anyone kill grenade cm", "response to _anyone_ killing an enemy with a grenade", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill explosion cm", "response to the player killing an enemy with an explosive weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill melee cm", "response to the player killing an enemy with a melee weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill flame cm", "response to the player killing an enemy with flamethrower", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill shotgun cm", "response to the player killing an enemy with a shotgun", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill vehicle cm", "response to the player killing an enemy by hitting them with a vehicle", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player kill mountedweapon cm", "response to the player killing an enemy with a fixed weapon", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "player killling spree cm", "response to the player going on a killing spree", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("friends dying", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "friend died", "a friendly AI died", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend player died", "a friendly player died", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend killed by friend", "a friend died from friendly fire", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend killed by friendly player", "friend died from player's friendly fire", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend killed by enemy", "a friend died from enemy fire", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend killed by enemy player", "friend died from an enemy player", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend killed by covenant", "a friend died from covenant fire", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend killed by flood", "a friend died from the flood", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend killed by sentinel", "a friend died from sentinel fire", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "friend betrayed", "a friend was deliberately killed by an ally that we don't trust (e.g. player killed a marine)", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("shouting", nullptr, FIELD_FLAG_NONE, "vocalizations that can be played even if a friend is talking"),
		{ _field_tag_reference, "new combat alone", "see an enemy and we have not previously been in combat", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "new enemy recent combat", "see a new enemy and we have recently been in combat", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "old enemy sighted", "see an enemy that we are currently looking for", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "unexpected enemy", "unexpectedly encounters enemy (behind or to the side)", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "dead friend found", "unexpectedly finds a dead body of a friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "alliance broken", "we decide that a former ally is now a traitor", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "alliance reformed", "we forgive a traitor and make him our friend again", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "grenade throwing", "throwing a grenade", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "grenade sighted", "see an enemy grenade", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "grenade startle", "alerted by a grenade bouncing near us", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "grenade danger enemy", "in danger from an enemy grenade", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "grenade danger self", "in danger from your own grenade", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "grenade danger friend", "in danger from a friendly grenade (not our own)", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("group communication", nullptr, FIELD_FLAG_NONE, "vocalizations that require friends"),
		{ _field_tag_reference, "new combat group re", "reply to a nearby friend who alerted us to an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "new combat nearby re", "reply to a distant friend who alerted us to an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "alert friend", "alert a friend who is in a noncombat state", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "alert friend re", "alerted by a friend when in a noncombat state", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "alert lost contact", "alert friends that target was not at expected location", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "alert lost contact re", "alert friends that target was not at expected location: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "blocked", "friend is blocking us from moving or firing", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "blocked re", "friend is blocking us from moving or firing: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "search start", "starting to search", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "search query", "asking searchers whether they have found anything", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "search query re", "asking searchers whether they have found anything: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "search report", "searcher reporting that an area is clear", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "search abandon", "searcher giving up on search", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "search group abandon", "search coordinator giving up on search", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "group uncover", "starting to uncover target with friend", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "group uncover re", "starting to uncover target: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "advance", "our platoon starts to attack or advance", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "advance re", "our platoon starts to attack or advance: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "retreat", "our platoon starts to defend or retreat", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "retreat re", "our platoon starts to defend or retreat: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "cover", "telling friends to seek cover", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("actions", nullptr, FIELD_FLAG_NONE, "vocalizations that don\'t require friends"),
		{ _field_tag_reference, "sighted friend player", "sighted a new friendly player", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "shooting", "shooting at an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "shooting vehicle", "shooting from a vehicle at an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "shooting berserk", "shooting at an enemy while berserk", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "shooting group", "shooting at a group of enemies", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "shooting traitor", "shooting at a traitorous player", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "taunt", "taunting the enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "taunt re", "taunted by an enemy: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "flee", "fleeing in panic", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "flee re", "fleeing in panic: response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "flee leader died", "fleeing in panic because our leaders are all dead", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "attempted flee", "unable to flee because a leader is nearby", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "attempted flee re", "unable to flee because a leader is nearby - response", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "lost contact", "target was not at expected location", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "hiding finished", "stops hiding and pursues target", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "vehicle entry", "enters vehicle", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "vehicle exit", "exits vehicle", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "vehicle woohoo", "excited while in vehicle (big air, etc)", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "vehicle scared", "scared while in vehicle (imminent crash)", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "vehicle collision", "riding in a vehicle and the driver collides with something", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "partially sighted", "saw something suspicious but not sure it was an enemy", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "nothing there", "decided that a suspicious sighting was nothing after all", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "pleading", "pleading for the player to spare our pitiable lives", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("exclamations", nullptr, FIELD_FLAG_NONE, "vocalizations that interrupt our talking"),
		{ _field_tag_reference, "surprise", "surprised by an enemy, noise, body or weapon impact", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "berserk", "went berserk", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "melee attack", "attacked an enemy in melee", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "dive", "dove away from danger or into cover", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "uncover exclamation", "leapt out of corner to uncover a suspected target", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "leap attack", "begin a leap attack", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "resurrection", "arise and return to life", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("post-combat actions", nullptr, FIELD_FLAG_NONE, "vocalizations that immediately follow combat"),
		{ _field_tag_reference, "celebration", "all enemies defeated", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "check body enemy", "post-combat checking an enemy's dead body", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "check body friend", "post-combat checking a friend's dead body", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "shooting dead enemy", "post-combat shooting an enemy's dead body", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "shooting dead enemy player", "post-combat shooting an enemy player's dead body", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("post-combat chatter", nullptr, FIELD_FLAG_NONE, "vocalizations that immediately follow combat"),
		{ _field_tag_reference, "alone", "post-combat all friends killed", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "unscathed", "post-combat we were not hurt", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "seriously wounded", "post-combat we were badly hurt", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "seriously wounded re", "post-combat replying to a friend who was badly hurt", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "massacre", "post-combat our friends took heavy casualties", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "massacre re", "post-combat reply: our friends took heavy casualties", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "rout", "post-combat our friends kicked alien ass", &blofeld::halo1::sound_reference$3 },
		{ _field_tag_reference, "rout re", "post-combat reply: our friends kicked alien ass", &blofeld::halo1::sound_reference$3 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 752),
		{ _field_terminator }
	};

	TAG_REFERENCE(sound_reference$3, SOUND_TAG);


	TAG_GROUP(
		item_collection_group,
		ITEM_COLLECTION_TAG,
		nullptr,
		INVALID_TAG,
		item_collection);

	TAG_BLOCK(
		item_collection,
		"item_collection_group_block",
		1,
		"s_item_collection",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "item permutations", &blofeld::halo1::item_permutation },
		{ _field_short_integer, "spawn time (in seconds, 0 = default)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		{ _field_terminator }
	};

	TAG_BLOCK(
		item_permutation,
		"item_permutation",
		32,
		"s_item_permutation",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_real, "weight", "relatively how likely this item will be chosen" },
		{ _field_tag_reference, "item", "which item to ", FIELD_FLAG_INDEX, &blofeld::halo1::item_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};


	TAG_GROUP(
		weapon_hud_interface_group,
		WEAPON_HUD_INTERFACE_TAG,
		nullptr,
		INVALID_TAG,
		weapon_hud_interface);

	TAG_BLOCK(
		weapon_hud_interface,
		"weapon_hud_interface_group_block",
		1,
		"s_weapon_hud_interface",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "child hud", &blofeld::halo1::weapon_hud_interface_reference },
		FIELD_EXPLANATION_EX("Flash cutoffs", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$238 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "total ammo cutoff" },
		{ _field_short_integer, "loaded ammo cutoff" },
		{ _field_short_integer, "heat cutoff" },
		{ _field_short_integer, "age cutoff" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("Weapon hud screen alignment", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$239 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "static elements", &blofeld::halo1::weapon_hud_static_block },
		{ _field_block, "meter elements", &blofeld::halo1::weapon_hud_meter_block },
		{ _field_block, "number elements", &blofeld::halo1::weapon_hud_number_block },
		FIELD_EXPLANATION_EX("Crosshairs", nullptr, FIELD_FLAG_NONE, "Crosshairs always go in the center of the screen.\nCrosshairs can be attached to one of four different states:\n\n* Aim: Default crosshair. Frame 0 is the default state, frame 1 is the auto-aim state (frame rate ignored)\n* Zoom: Zoom overlay. Each zoom level has a corresponding frame (frame rate ignored)\n* Charge: Charging overlay. If you wish to display an animation for charging, put it here.\n* Flash: Similar to charging, but for low ammo/batter/heat states\n* Reload/Overheat: Similar to charging, but for reloading/overheating\n"),
		{ _field_block, "crosshairs", &blofeld::halo1::weapon_hud_crosshair_block },
		{ _field_block, "overlay elements", &blofeld::halo1::weapon_hud_overlays_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "screen effect", &blofeld::halo1::global_hud_screen_effect_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 132),
		FIELD_EXPLANATION_EX("Messaging information", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_integer, "sequence index", "sequence index into the global hud icon bitmap" },
		{ _field_short_integer, "width offset", "extra spacing beyond bitmap width for text alignment" },
		{ _field_point_2d, "offset from reference corner" },
		{ _field_argb_color, "override icon color" },
		{ _field_char_integer, "frame rate" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$261 },
		{ _field_short_integer, "text index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	TAG_REFERENCE(weapon_hud_interface_reference, WEAPON_HUD_INTERFACE_TAG);

	STRINGS(unnamed_enum$238)
	{
		"use parent hud flashing parameters"
	};
	STRING_LIST(unnamed_enum$238, unnamed_enum$238_strings, _countof(unnamed_enum$238_strings));

	STRINGS(unnamed_enum$239)
	{
		"top left",
		"top right",
		"bottom left",
		"bottom right",
		"center"
	};
	STRING_LIST(unnamed_enum$239, unnamed_enum$239_strings, _countof(unnamed_enum$239_strings));

	STRINGS(unnamed_enum$261)
	{
		"use text from string_list instead",
		"override default color",
		"width offset is absolute icon width"
	};
	STRING_LIST(unnamed_enum$261, unnamed_enum$261_strings, _countof(unnamed_enum$261_strings));

	TAG_BLOCK(
		global_hud_screen_effect_definition,
		"global_hud_screen_effect_definition",
		1,
		"s_global_hud_screen_effect_definition",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("mask", nullptr, FIELD_FLAG_NONE, "Mask bitmap overlay. Use either a 2D bitmap or an interface bitmap."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$257 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "mask (fullscreen)", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "mask (splitscreen)", &blofeld::halo1::bitmap_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("convolution", nullptr, FIELD_FLAG_NONE, "Warp effect like in \'Pitch-Black\', sort of."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$258 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_angle_bounds, "FOV in bounds", nullptr, "degrees" },
		{ _field_real_bounds, "radius out bounds", nullptr, "pixels" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("night-vision", nullptr, FIELD_FLAG_NONE, "Real-time gamma correction to make dark objects appear brighter."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$259 },
		{ _field_short_integer, "script source", nullptr, nullptr, "[0,3]" },
		{ _field_real_fraction, "intensity", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("desaturation", nullptr, FIELD_FLAG_NONE, "Real-time monochromatic color filter."),
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$260 },
		{ _field_short_integer, "script source", nullptr, nullptr, "[0,3]" },
		{ _field_real_fraction, "intensity", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "tint" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$257)
	{
		"only when zoomed"
	};
	STRING_LIST(unnamed_enum$257, unnamed_enum$257_strings, _countof(unnamed_enum$257_strings));

	STRINGS(unnamed_enum$258)
	{
		"only when zoomed"
	};
	STRING_LIST(unnamed_enum$258, unnamed_enum$258_strings, _countof(unnamed_enum$258_strings));

	STRINGS(unnamed_enum$259)
	{
		"only when zoomed",
		"connect to flashlight",
		"masked"
	};
	STRING_LIST(unnamed_enum$259, unnamed_enum$259_strings, _countof(unnamed_enum$259_strings));

	STRINGS(unnamed_enum$260)
	{
		"only when zoomed",
		"connect to flashlight",
		"additive",
		"masked"
	};
	STRING_LIST(unnamed_enum$260, unnamed_enum$260_strings, _countof(unnamed_enum$260_strings));

	TAG_BLOCK(
		weapon_hud_overlays_block,
		"weapon_hud_overlays_block",
		16,
		"s_weapon_hud_overlays_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "state attached to", &blofeld::halo1::unnamed_enum$240 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "can use on map type", &blofeld::halo1::unnamed_enum$241 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_tag_reference, "Overlay bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_block, "Overlays", &blofeld::halo1::weapon_hud_overlay_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$240)
	{
		"total ammo",
		"loaded ammo",
		"heat",
		"age",
		"secondary weapon total ammo",
		"secondary weapon loaded ammo",
		"distance to target",
		"elevation to target"
	};
	STRING_LIST(unnamed_enum$240, unnamed_enum$240_strings, _countof(unnamed_enum$240_strings));

	STRINGS(unnamed_enum$241)
	{
		"any",
		"solo",
		"multiplayer"
	};
	STRING_LIST(unnamed_enum$241, unnamed_enum$241_strings, _countof(unnamed_enum$241_strings));

	TAG_BLOCK(
		weapon_hud_overlay_block,
		"weapon_hud_overlay_block",
		16,
		"s_weapon_hud_overlay_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "frame rate" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "sequence index" },
		{ _field_word_flags, "type", &blofeld::halo1::unnamed_enum$255 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$256 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$242)
	{
		"don\'t scale offset",
		"don\'t scale size",
		"use high res scale"
	};
	STRING_LIST(unnamed_enum$242, unnamed_enum$242_strings, _countof(unnamed_enum$242_strings));

	STRINGS(unnamed_enum$243)
	{
		"reverse default/flashing colors"
	};
	STRING_LIST(unnamed_enum$243, unnamed_enum$243_strings, _countof(unnamed_enum$243_strings));

	STRINGS(unnamed_enum$255)
	{
		"show on flashing",
		"show on empty",
		"show on reload/overheating",
		"show on default",
		"show always"
	};
	STRING_LIST(unnamed_enum$255, unnamed_enum$255_strings, _countof(unnamed_enum$255_strings));

	STRINGS(unnamed_enum$256)
	{
		"flashes when active"
	};
	STRING_LIST(unnamed_enum$256, unnamed_enum$256_strings, _countof(unnamed_enum$256_strings));

	TAG_BLOCK(
		weapon_hud_crosshair_block,
		"weapon_hud_crosshair_block",
		19,
		"s_weapon_hud_crosshair_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "crosshair type", &blofeld::halo1::unnamed_enum$253 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "can use on map type", &blofeld::halo1::unnamed_enum$241 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_tag_reference, "Crosshair bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_block, "Crosshair overlays", &blofeld::halo1::weapon_hud_crosshair_item_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$253)
	{
		"aim",
		"zoom",
		"charge",
		"should reload",
		"flash heat",
		"flash total ammo",
		"flash battery",
		"reload/overheat",
		"flash when firing and no ammo",
		"flash when throwing and no grenade",
		"low ammo and none left to reload",
		"should reload secondary trigger",
		"flash secondary total ammo",
		"flash secondary reload",
		"flash when firing secondary trigger with no ammo",
		"low secondary ammo and none left to reload",
		"primary trigger ready",
		"secondary trigger ready",
		"flash when firing with depleted battery"
	};
	STRING_LIST(unnamed_enum$253, unnamed_enum$253_strings, _countof(unnamed_enum$253_strings));

	TAG_BLOCK(
		weapon_hud_crosshair_item_block,
		"weapon_hud_crosshair_item_block",
		16,
		"s_weapon_hud_crosshair_item_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "frame rate" },
		{ _field_short_integer, "sequence index" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$254 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$254)
	{
		"flashes when active",
		"not a sprite",
		"show only when zoomed",
		"show sniper data",
		"hide area outside reticle",
		"one zoom level",
		"don\'t show when zoomed"
	};
	STRING_LIST(unnamed_enum$254, unnamed_enum$254_strings, _countof(unnamed_enum$254_strings));

	TAG_BLOCK(
		weapon_hud_number_block,
		"weapon_hud_number_block",
		16,
		"s_weapon_hud_number_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "state attached to", &blofeld::halo1::unnamed_enum$240 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "can use on map type", &blofeld::halo1::unnamed_enum$241 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_char_integer, "maximum number of digits" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$251 },
		{ _field_char_integer, "number of fractional digits" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_word_flags, "weapon specific flags", &blofeld::halo1::unnamed_enum$252 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 36),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$251)
	{
		"show leading zeros",
		"only show when zoomed",
		"draw a trailing m"
	};
	STRING_LIST(unnamed_enum$251, unnamed_enum$251_strings, _countof(unnamed_enum$251_strings));

	STRINGS(unnamed_enum$252)
	{
		"divide number by clip size"
	};
	STRING_LIST(unnamed_enum$252, unnamed_enum$252_strings, _countof(unnamed_enum$252_strings));

	TAG_BLOCK(
		weapon_hud_meter_block,
		"weapon_hud_meter_block",
		16,
		"s_weapon_hud_meter_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "state attached to", &blofeld::halo1::unnamed_enum$240 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "can use on map type", &blofeld::halo1::unnamed_enum$241 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "meter bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_rgb_color, "color at meter minimum" },
		{ _field_rgb_color, "color at meter maximum" },
		{ _field_rgb_color, "flash color" },
		{ _field_argb_color, "empty color" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$250 },
		{ _field_char_integer, "minumum meter value" },
		{ _field_short_integer, "sequence index" },
		{ _field_char_integer, "alpha multiplier" },
		{ _field_char_integer, "alpha bias" },
		{ _field_short_integer, "value scale", "used for non-integral values, i.e. health and shields" },
		{ _field_real, "opacity" },
		{ _field_real, "translucency" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$250)
	{
		"use min/max for state changes",
		"interpolate between min/max flash colors as state changes",
		"interpolate color along hsv space",
		"...more colors for hsv interpolation",
		"invert interpolation"
	};
	STRING_LIST(unnamed_enum$250, unnamed_enum$250_strings, _countof(unnamed_enum$250_strings));

	TAG_BLOCK(
		weapon_hud_static_block,
		"weapon_hud_static_block",
		16,
		"s_weapon_hud_static_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "state attached to", &blofeld::halo1::unnamed_enum$240 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_enum, "can use on map type", &blofeld::halo1::unnamed_enum$241 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_terminator }
	};

	TAG_BLOCK(
		global_hud_multitexture_overlay_definition,
		"global_hud_multitexture_overlay_definition",
		30,
		"s_global_hud_multitexture_overlay_definition",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "type" },
		{ _field_short_enum, "framebuffer blend func", &blofeld::halo1::unnamed_enum$51 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("anchors", nullptr, FIELD_FLAG_NONE, "where you want the origin of the texture.\n*\"texture\" uses the texture coordinates supplied\n*\"screen\" uses the origin of the screen as the origin of the texture"),
		{ _field_short_enum, "primary anchor", &blofeld::halo1::unnamed_enum$244 },
		{ _field_short_enum, "secondary anchor", &blofeld::halo1::unnamed_enum$244 },
		{ _field_short_enum, "tertiary anchor", &blofeld::halo1::unnamed_enum$244 },
		FIELD_EXPLANATION_EX("blending function", nullptr, FIELD_FLAG_NONE, "how to blend the textures together"),
		{ _field_short_enum, "0 to 1 blend func", &blofeld::halo1::unnamed_enum$245 },
		{ _field_short_enum, "1 to 2 blend func", &blofeld::halo1::unnamed_enum$245 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("map scales", nullptr, FIELD_FLAG_NONE, "how much to scale the textures"),
		{ _field_real_point_2d, "primary scale" },
		{ _field_real_point_2d, "secondary scale" },
		{ _field_real_point_2d, "tertiary scale" },
		FIELD_EXPLANATION_EX("map offsets", nullptr, FIELD_FLAG_NONE, "how much to offset the origin of the texture"),
		{ _field_real_point_2d, "primary offset" },
		{ _field_real_point_2d, "secondary offset" },
		{ _field_real_point_2d, "tertiary offset" },
		FIELD_EXPLANATION_EX("map", nullptr, FIELD_FLAG_NONE, "which maps to use"),
		{ _field_tag_reference, "primary", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "secondary", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "tertiary", &blofeld::halo1::bitmap_reference },
		{ _field_short_enum, "primary wrap mode", &blofeld::halo1::unnamed_enum$246 },
		{ _field_short_enum, "secondary wrap mode", &blofeld::halo1::unnamed_enum$246 },
		{ _field_short_enum, "tertiary wrap mode", &blofeld::halo1::unnamed_enum$246 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 184),
		{ _field_block, "effectors", &blofeld::halo1::global_hud_multitexture_overlay_effector_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$244)
	{
		"texture",
		"screen"
	};
	STRING_LIST(unnamed_enum$244, unnamed_enum$244_strings, _countof(unnamed_enum$244_strings));

	STRINGS(unnamed_enum$245)
	{
		"add",
		"subtract",
		"multiply",
		"multiply2x",
		"dot"
	};
	STRING_LIST(unnamed_enum$245, unnamed_enum$245_strings, _countof(unnamed_enum$245_strings));

	STRINGS(unnamed_enum$246)
	{
		"clamp",
		"wrap"
	};
	STRING_LIST(unnamed_enum$246, unnamed_enum$246_strings, _countof(unnamed_enum$246_strings));

	TAG_BLOCK(
		global_hud_multitexture_overlay_effector_definition,
		"global_hud_multitexture_overlay_effector_definition",
		30,
		"s_global_hud_multitexture_overlay_effector_definition",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		FIELD_EXPLANATION_EX("source/destination", nullptr, FIELD_FLAG_NONE, "These describe the relationship that causes the effect.\n* destination type is the type of variable you want to be effected\n* destination tells which texture map (or geometry offset) to apply it to\n* source says which value to look at when computing the effect"),
		{ _field_short_enum, "destination type", &blofeld::halo1::unnamed_enum$247 },
		{ _field_short_enum, "destination", &blofeld::halo1::unnamed_enum$248 },
		{ _field_short_enum, "source", &blofeld::halo1::unnamed_enum$249 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("in/out bounds", nullptr, FIELD_FLAG_NONE, "When the source is at the lower inbound, the destination ends up the lower outbound and vice-versa applies for the upper values."),
		{ _field_real_bounds, "in bounds", nullptr, "source units" },
		{ _field_real_bounds, "out bounds", nullptr, "pixels" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		FIELD_EXPLANATION_EX("tint color bounds", nullptr, FIELD_FLAG_NONE, "If destination is tint, these values are used instead of the out bounds."),
		{ _field_real_rgb_color, "tint color lower bound" },
		{ _field_real_rgb_color, "tint color upper bound" },
		FIELD_EXPLANATION_EX("periodic functions", nullptr, FIELD_FLAG_NONE, "If you use a periodic function as the source, this lets you tweak it."),
		{ _field_short_enum, "periodic function", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "function period", nullptr, "seconds" },
		{ _field_real, "function phase", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$247)
	{
		"tint [0,1]",
		"horizontal offset",
		"vertical offset",
		"fade [0,1]"
	};
	STRING_LIST(unnamed_enum$247, unnamed_enum$247_strings, _countof(unnamed_enum$247_strings));

	STRINGS(unnamed_enum$248)
	{
		"geometry offset",
		"primary map",
		"secondary map",
		"tertiary map"
	};
	STRING_LIST(unnamed_enum$248, unnamed_enum$248_strings, _countof(unnamed_enum$248_strings));

	STRINGS(unnamed_enum$249)
	{
		"player pitch",
		"player pitch tangent",
		"player yaw",
		"weapon ammo (total)",
		"weapon ammo (loaded)",
		"weapon heat",
		"explicit (uses low bound)",
		"weapon zoom level"
	};
	STRING_LIST(unnamed_enum$249, unnamed_enum$249_strings, _countof(unnamed_enum$249_strings));


	TAG_GROUP(
		grenade_hud_interface_group,
		GRENADE_HUD_INTERFACE_TAG,
		nullptr,
		INVALID_TAG,
		grenade_hud_interface);

	TAG_BLOCK(
		grenade_hud_interface,
		"grenade_hud_interface_group_block",
		1,
		"s_grenade_hud_interface",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_custom, "value" },
		FIELD_EXPLANATION_EX("Grenade hud screen alignment", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$239 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("Grenade hud background", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Total grenades background", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Total grenades numbers", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_char_integer, "maximum number of digits" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$251 },
		{ _field_char_integer, "number of fractional digits" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_short_integer, "flash cutoff" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("Total grenades overlays", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "Overlay bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_block, "Overlays", &blofeld::halo1::grenade_hud_overlay_block },
		{ _field_block, "Warning sounds", &blofeld::halo1::grenade_hud_sound_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 68),
		FIELD_EXPLANATION_EX("Messaging information", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_integer, "sequence index", "sequence index into the global hud icon bitmap" },
		{ _field_short_integer, "width offset", "extra spacing beyond bitmap width for text alignment" },
		{ _field_point_2d, "offset from reference corner" },
		{ _field_argb_color, "override icon color" },
		{ _field_char_integer, "frame rate" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$261 },
		{ _field_short_integer, "text index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	TAG_BLOCK(
		grenade_hud_sound_block,
		"grenade_hud_sound_block",
		12,
		"s_grenade_hud_sound_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &blofeld::halo1::sound_sound_looping_reference },
		{ _field_long_flags, "latched to", &blofeld::halo1::unnamed_enum$263 },
		{ _field_real, "scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE_GROUP(sound_sound_looping_reference)
	{
		SOUND_TAG,
		SOUND_LOOPING_TAG,
		INVALID_TAG
	};

	STRINGS(unnamed_enum$263)
	{
		"low grenade count",
		"no grenades left",
		"throw on no grenades"
	};
	STRING_LIST(unnamed_enum$263, unnamed_enum$263_strings, _countof(unnamed_enum$263_strings));

	TAG_BLOCK(
		grenade_hud_overlay_block,
		"grenade_hud_overlay_block",
		16,
		"s_grenade_hud_overlay_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "frame rate" },
		{ _field_short_integer, "sequence index" },
		{ _field_word_flags, "type", &blofeld::halo1::unnamed_enum$262 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$256 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$262)
	{
		"show on flashing",
		"show on empty",
		"show on default",
		"show always"
	};
	STRING_LIST(unnamed_enum$262, unnamed_enum$262_strings, _countof(unnamed_enum$262_strings));


	TAG_GROUP(
		unit_hud_interface_group,
		UNIT_HUD_INTERFACE_TAG,
		nullptr,
		INVALID_TAG,
		unit_hud_interface);

	TAG_BLOCK(
		unit_hud_interface,
		"unit_hud_interface_group_block",
		1,
		"s_unit_hud_interface",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_custom, "value" },
		FIELD_EXPLANATION_EX("Weapon hud screen alignment", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$239 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("Unit hud background", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Shield panel background", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Shield panel meter", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "meter bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_rgb_color, "color at meter minimum" },
		{ _field_rgb_color, "color at meter maximum" },
		{ _field_rgb_color, "flash color" },
		{ _field_argb_color, "empty color" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$250 },
		{ _field_char_integer, "minumum meter value" },
		{ _field_short_integer, "sequence index" },
		{ _field_char_integer, "alpha multiplier" },
		{ _field_char_integer, "alpha bias" },
		{ _field_short_integer, "value scale", "used for non-integral values, i.e. health and shields" },
		{ _field_real, "opacity" },
		{ _field_real, "translucency" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_rgb_color, "overcharge minimum color" },
		{ _field_rgb_color, "overcharge maximum color" },
		{ _field_rgb_color, "overcharge flash color" },
		{ _field_rgb_color, "overcharge empty color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("Health panel background", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Health panel meter", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "meter bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_rgb_color, "color at meter minimum" },
		{ _field_rgb_color, "color at meter maximum" },
		{ _field_rgb_color, "flash color" },
		{ _field_argb_color, "empty color" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$250 },
		{ _field_char_integer, "minumum meter value" },
		{ _field_short_integer, "sequence index" },
		{ _field_char_integer, "alpha multiplier" },
		{ _field_char_integer, "alpha bias" },
		{ _field_short_integer, "value scale", "used for non-integral values, i.e. health and shields" },
		{ _field_real, "opacity" },
		{ _field_real, "translucency" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_rgb_color, "medium health left color" },
		{ _field_real, "max color health fraction cutoff" },
		{ _field_real, "min color health fraction cutoff" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("Motion sensor background", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Motion sensor foreground", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("Motion sensor center", nullptr, FIELD_FLAG_NONE, "The blips use this as a reference point"),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("Auxilary overlays", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$239 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_block, "overlays", &blofeld::halo1::unit_hud_auxilary_overlay_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("Hud warning sounds", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_block, "sounds", &blofeld::halo1::unit_hud_sound_block },
		FIELD_EXPLANATION_EX("Auxilary hud meters", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_block, "meters", &blofeld::halo1::unit_hud_auxilary_panel_block },
		FIELD_EXPLANATION_EX("Vehicle hud", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 356),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	TAG_BLOCK(
		unit_hud_auxilary_panel_block,
		"unit_hud_auxilary_panel_block",
		16,
		"s_unit_hud_auxilary_panel_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$267 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("BACKGROUND", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("METER", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "meter bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_rgb_color, "color at meter minimum" },
		{ _field_rgb_color, "color at meter maximum" },
		{ _field_rgb_color, "flash color" },
		{ _field_argb_color, "empty color" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$250 },
		{ _field_char_integer, "minumum meter value" },
		{ _field_short_integer, "sequence index" },
		{ _field_char_integer, "alpha multiplier" },
		{ _field_char_integer, "alpha bias" },
		{ _field_short_integer, "value scale", "used for non-integral values, i.e. health and shields" },
		{ _field_real, "opacity" },
		{ _field_real, "translucency" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_real, "minimum fraction cutoff" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$268 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 64),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$267)
	{
		"integrated light"
	};
	STRING_LIST(unnamed_enum$267, unnamed_enum$267_strings, _countof(unnamed_enum$267_strings));

	STRINGS(unnamed_enum$268)
	{
		"show only when active",
		"flash once if activated while disabled"
	};
	STRING_LIST(unnamed_enum$268, unnamed_enum$268_strings, _countof(unnamed_enum$268_strings));

	TAG_BLOCK(
		unit_hud_sound_block,
		"unit_hud_sound_block",
		12,
		"s_unit_hud_sound_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "sound", FIELD_FLAG_INDEX, &blofeld::halo1::sound_sound_looping_reference },
		{ _field_long_flags, "latched to", &blofeld::halo1::unnamed_enum$266 },
		{ _field_real, "scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$266)
	{
		"shield recharging",
		"shield damaged",
		"shield low",
		"shield empty",
		"health low",
		"health empty",
		"health minor damage",
		"health major damage"
	};
	STRING_LIST(unnamed_enum$266, unnamed_enum$266_strings, _countof(unnamed_enum$266_strings));

	TAG_BLOCK(
		unit_hud_auxilary_overlay_block,
		"unit_hud_auxilary_overlay_block",
		16,
		"s_unit_hud_auxilary_overlay_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "interface bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "multitex overlay", &blofeld::halo1::global_hud_multitexture_overlay_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$264 },
		{ _field_word_flags, "flags", &blofeld::halo1::unnamed_enum$265 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$264)
	{
		"team icon"
	};
	STRING_LIST(unnamed_enum$264, unnamed_enum$264_strings, _countof(unnamed_enum$264_strings));

	STRINGS(unnamed_enum$265)
	{
		"use team color"
	};
	STRING_LIST(unnamed_enum$265, unnamed_enum$265_strings, _countof(unnamed_enum$265_strings));


	TAG_GROUP(
		hud_number_group,
		HUD_NUMBER_TAG,
		nullptr,
		INVALID_TAG,
		hud_number);

	TAG_BLOCK(
		hud_number,
		"hud_number_group_block",
		1,
		"s_hud_number",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "digits bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_char_integer, "bitmap digit width" },
		{ _field_char_integer, "screen digit width" },
		{ _field_char_integer, "x offset" },
		{ _field_char_integer, "y offset" },
		{ _field_char_integer, "decimal point width" },
		{ _field_char_integer, "colon width" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 76),
		{ _field_terminator }
	};


	TAG_GROUP(
		hud_globals_group,
		HUD_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		hud_globals);

	TAG_BLOCK(
		hud_globals,
		"hud_globals_group_block",
		1,
		"s_hud_globals",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("Messaging parameters", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "anchor", &blofeld::halo1::unnamed_enum$239 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_point_2d, "anchor offset" },
		{ _field_real, "width scale" },
		{ _field_real, "height scale" },
		{ _field_word_flags, "scaling flags", &blofeld::halo1::unnamed_enum$242 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_tag_reference, "single player font", &blofeld::halo1::font_reference },
		{ _field_tag_reference, "multi player font", &blofeld::halo1::font_reference },
		{ _field_real, "up time" },
		{ _field_real, "fade time" },
		{ _field_real_argb_color, "icon color" },
		{ _field_real_argb_color, "text color" },
		{ _field_real, "text spacing" },
		{ _field_tag_reference, "item message text", &blofeld::halo1::unicode_string_list_reference$2 },
		{ _field_tag_reference, "icon bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "alternate icon text", &blofeld::halo1::unicode_string_list_reference$2 },
		{ _field_block, "button icons", &blofeld::halo1::hud_button_icon_block },
		FIELD_EXPLANATION_EX("HUD HELP TEXT COLOR", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Other hud messaging data", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "hud messages", &blofeld::halo1::hud_message_text_reference$2 },
		FIELD_EXPLANATION_EX("Objective colors", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		{ _field_short_integer, "uptime ticks" },
		{ _field_short_integer, "fade ticks" },
		FIELD_EXPLANATION_EX("Waypoint parameters", nullptr, FIELD_FLAG_NONE, "The offset values are how much the waypoint rectangle border is offset from the safe camera bounds"),
		{ _field_real, "top offset" },
		{ _field_real, "bottom offset" },
		{ _field_real, "left offset" },
		{ _field_real, "right offset" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "arrow bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_block, "waypoint arrows", &blofeld::halo1::hud_waypoint_arrow_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 80),
		FIELD_EXPLANATION_EX("Multiplayer parameters", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "hud scale in multiplayer" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 256),
		FIELD_EXPLANATION_EX("Hud globals", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "default weapon hud", &blofeld::halo1::weapon_hud_interface_reference },
		{ _field_real, "motion sensor range" },
		{ _field_real, "motion sensor velocity sensitivity", "how fast something moves to show up on the motion sensor" },
		{ _field_real, "motion sensor scale [DON'T TOUCH EVER]", FIELD_FLAG_READ_ONLY },
		{ _field_rectangle_2d, "default chapter title bounds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		FIELD_EXPLANATION_EX("Hud damage indicators", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_integer, "top offset" },
		{ _field_short_integer, "bottom offset" },
		{ _field_short_integer, "left offset" },
		{ _field_short_integer, "right offset" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "indicator bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_short_integer, "sequence index" },
		{ _field_short_integer, "multiplayer sequence index" },
		{ _field_argb_color, "color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_EXPLANATION_EX("Hud timer definitions", nullptr, FIELD_FLAG_NONE, nullptr),
		FIELD_EXPLANATION_EX("Not much time left flash color", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("Time out flash color", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_argb_color, "default color" },
		{ _field_argb_color, "flashing color" },
		{ _field_real, "flash period" },
		{ _field_real, "flash delay", "time between flashes" },
		{ _field_short_integer, "number of flashes" },
		{ _field_word_flags, "flash flags", &blofeld::halo1::unnamed_enum$243 },
		{ _field_real, "flash length", "time of each flash" },
		{ _field_argb_color, "disabled color" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_tag_reference, "carnage report bitmap", &blofeld::halo1::bitmap_reference },
		FIELD_EXPLANATION_EX("Hud crap that wouldn't fit anywhere else", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_integer, "loading begin text" },
		{ _field_short_integer, "loading end text" },
		{ _field_short_integer, "checkpoint begin text" },
		{ _field_short_integer, "checkpoint end text" },
		{ _field_tag_reference, "checkpoint sound", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 96),
		{ _field_terminator }
	};

	TAG_REFERENCE(unicode_string_list_reference$2, UNICODE_STRING_LIST_TAG);

	TAG_REFERENCE(hud_message_text_reference$2, HUD_MESSAGE_TEXT_TAG);

	TAG_BLOCK(
		hud_waypoint_arrow_block,
		"hud_waypoint_arrow_block",
		16,
		"s_hud_waypoint_arrow_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_rgb_color, "color" },
		{ _field_real, "opacity" },
		{ _field_real, "translucency" },
		{ _field_short_integer, "on screen sequence index" },
		{ _field_short_integer, "off screen sequence index" },
		{ _field_short_integer, "occluded sequence index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$269 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$269)
	{
		"don\'t rotate when pointing offscreen"
	};
	STRING_LIST(unnamed_enum$269, unnamed_enum$269_strings, _countof(unnamed_enum$269_strings));

	TAG_BLOCK(
		hud_button_icon_block,
		"hud_button_icon_block",
		18,
		"s_hud_button_icon_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "sequence index", "sequence index into the global hud icon bitmap" },
		{ _field_short_integer, "width offset", "extra spacing beyond bitmap width for text alignment" },
		{ _field_point_2d, "offset from reference corner" },
		{ _field_argb_color, "override icon color" },
		{ _field_char_integer, "frame rate" },
		{ _field_byte_flags, "flags", &blofeld::halo1::unnamed_enum$261 },
		{ _field_short_integer, "text index" },
		{ _field_terminator }
	};


	TAG_GROUP(
		virtual_keyboard_group,
		VIRTUAL_KEYBOARD_TAG,
		nullptr,
		INVALID_TAG,
		virtual_keyboard);

	TAG_BLOCK(
		virtual_keyboard,
		"virtual_keyboard_group_block",
		1,
		"s_virtual_keyboard",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "display font", &blofeld::halo1::font_reference },
		{ _field_tag_reference, "background bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "special key labels string list", &blofeld::halo1::unicode_string_list_reference$2 },
		{ _field_block, "virtual keys", &blofeld::halo1::virtual_key_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		virtual_key_block,
		"virtual_key_block",
		44,
		"s_virtual_key_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "keyboard key", &blofeld::halo1::unnamed_enum$270 },
		FIELD_EXPLANATION_EX("key codes", nullptr, FIELD_FLAG_NONE, "enter unicode character values as integer numbers"),
		{ _field_short_integer, "lowercase character" },
		{ _field_short_integer, "shift character" },
		{ _field_short_integer, "caps character" },
		{ _field_short_integer, "symbols character" },
		{ _field_short_integer, "shift+caps character" },
		{ _field_short_integer, "shift+symbols character" },
		{ _field_short_integer, "caps+symbols character" },
		{ _field_tag_reference, "unselected background bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "selected background bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "active background bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "sticky background bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$270)
	{
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"0",
		"A",
		"B",
		"C",
		"D",
		"E",
		"F",
		"G",
		"H",
		"I",
		"J",
		"K",
		"L",
		"M",
		"N",
		"O",
		"P",
		"Q",
		"R",
		"S",
		"T",
		"U",
		"V",
		"W",
		"X",
		"Y",
		"Z",
		"DONE",
		"SHIFT",
		"CAPS LOCK",
		"SYMBOLS",
		"BACKSPACE",
		"LEFT",
		"RIGHT",
		"SPACE"
	};
	STRING_LIST(unnamed_enum$270, unnamed_enum$270_strings, _countof(unnamed_enum$270_strings));


	TAG_GROUP(
		multiplayer_scenario_description_group,
		MULTIPLAYER_SCENARIO_DESCRIPTION_TAG,
		nullptr,
		INVALID_TAG,
		multiplayer_scenario_description);

	TAG_BLOCK(
		multiplayer_scenario_description,
		"multiplayer_scenario_description_group_block",
		1,
		"s_multiplayer_scenario_description",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "multiplayer scenarios", &blofeld::halo1::scenario_description_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		scenario_description_block,
		"scenario_description_block",
		32,
		"s_scenario_description_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_EXPLANATION_EX("net map info", nullptr, FIELD_FLAG_NONE, "these provide the info required by the UI to load a net map"),
		{ _field_tag_reference, "descriptive bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "displayed map name", &blofeld::halo1::unicode_string_list_reference$2 },
		{ _field_string, "scenario tag directory path", "this is the path to the directory containing the scenario tag file of the same name" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};


	TAG_GROUP(
		detail_object_collection_group,
		DETAIL_OBJECT_COLLECTION_TAG,
		nullptr,
		INVALID_TAG,
		detail_object_collection);

	TAG_BLOCK(
		detail_object_collection,
		"detail_object_collection_group_block",
		1,
		"s_detail_object_collection",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "collection type", &blofeld::halo1::unnamed_enum$271 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "global z offset", nullptr, "applied to all detail objects of in this collection so they don't float above the ground" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 44),
		{ _field_tag_reference, "sprite plate", &blofeld::halo1::bitmap_reference },
		{ _field_block, "types", &blofeld::halo1::detail_object_type_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 48),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$271)
	{
		"screen-facing",
		"viewer-facing"
	};
	STRING_LIST(unnamed_enum$271, unnamed_enum$271_strings, _countof(unnamed_enum$271_strings));

	TAG_BLOCK(
		detail_object_type_block,
		"detail_object_type_block",
		16,
		"s_detail_object_type_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_INDEX },
		{ _field_char_integer, "sequence index", nullptr, nullptr, "[0,15]" },
		{ _field_byte_flags, "type flags", &blofeld::halo1::unnamed_enum$272 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "color override factor", "fraction of detail object color to use instead of the base map color in the environment:[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "near fade distance", nullptr, "world units" },
		{ _field_real, "far fade distance", nullptr, "world units" },
		{ _field_real, "size", nullptr, "world units per pixel" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real_rgb_color, "minimum color", nullptr, nullptr, "[0,1]" },
		{ _field_real_rgb_color, "maximum color", nullptr, nullptr, "[0,1]" },
		{ _field_argb_color, "ambient color", nullptr, nullptr, "[0,255]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$272)
	{
		"unused",
		"unused",
		"interpolate color in hsv",
		"...more colors"
	};
	STRING_LIST(unnamed_enum$272, unnamed_enum$272_strings, _countof(unnamed_enum$272_strings));


	TAG_GROUP(
		sound_scenery_group,
		SOUND_SCENERY_TAG,
		&object_group,
		OBJECT_TAG,
		sound_scenery);

	TAG_BLOCK(
		sound_scenery,
		"sound_scenery_group_block",
		1,
		"s_sound_scenery",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "object", &blofeld::halo1::object_struct_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		{ _field_terminator }
	};


	TAG_GROUP(
		hud_message_text_group,
		HUD_MESSAGE_TEXT_TAG,
		nullptr,
		INVALID_TAG,
		hud_message_text);

	TAG_BLOCK(
		hud_message_text,
		"hud_message_text_group_block",
		1,
		"s_hud_message_text",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_data, "text data", FIELD_FLAG_READ_ONLY },
		{ _field_block, "message elements", FIELD_FLAG_READ_ONLY, &blofeld::halo1::hud_message_elements_block },
		{ _field_block, "messages", FIELD_FLAG_READ_ONLY, &blofeld::halo1::hud_messages_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 84),
		{ _field_terminator }
	};

	TAG_BLOCK(
		hud_messages_block,
		"hud_messages_block",
		1024,
		"s_hud_messages_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "name", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "start index into text blob", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "start index of message block", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "panel count", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_terminator }
	};

	TAG_BLOCK(
		hud_message_elements_block,
		"hud_message_elements_block",
		8192,
		"s_hud_message_elements_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_char_integer, "type", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "data", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};


	TAG_GROUP(
		ui_widget_definition_group,
		UI_WIDGET_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		ui_widget_definition);

	TAG_BLOCK(
		ui_widget_definition,
		"ui_widget_definition_group_block",
		1,
		"s_ui_widget_definition",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "widget type", &blofeld::halo1::unnamed_enum$273 },
		{ _field_short_enum, "controller index", &blofeld::halo1::unnamed_enum$274 },
		{ _field_string, "name" },
		{ _field_rectangle_2d, "bounds" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$275 },
		{ _field_long_integer, "milliseconds to auto close", "<=0 to never auto-close" },
		{ _field_long_integer, "milliseconds auto close fade time", "<= 0 for immediate close" },
		{ _field_tag_reference, "background bitmap", &blofeld::halo1::bitmap_reference },
		FIELD_EXPLANATION_EX("game data input fxns", nullptr, FIELD_FLAG_NONE, "These functions use current game data to modify the appearance of\nthe widget. These functions are called every time the widget is\nrendered."),
		{ _field_block, "game data inputs", &blofeld::halo1::game_data_input_references_block },
		FIELD_EXPLANATION_EX("event handlers", nullptr, FIELD_FLAG_NONE, "These allow actions to be tied to certain ui events.\nThe event handler is run every time the widget receives the specified event.\nBy default, the \'back\' and \'B\' buttons will take you to the previous screen."),
		{ _field_block, "event handlers", &blofeld::halo1::event_handler_references_block },
		FIELD_EXPLANATION_EX("search-and-replace", nullptr, FIELD_FLAG_NONE, "These are used to run a search-and-replace on the specified\nword in the text-box text, replacing all occurrences of the word\nwith the output of the replace-function. These are invoked each\ntime the text box is rendered (after any game data input functions\nhave been run). The searching is case-sensitive."),
		{ _field_block, "search and replace functions", &blofeld::halo1::search_and_replace_reference_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		FIELD_EXPLANATION_EX("text box", nullptr, FIELD_FLAG_NONE, "parameters specific to text box widgets\nNOTE: the string list tag can also be used for lists whose items come from a string list tag"),
		{ _field_tag_reference, "text label unicode strings list", &blofeld::halo1::unicode_string_list_reference$2 },
		{ _field_tag_reference, "text font", &blofeld::halo1::font_reference },
		{ _field_real_argb_color, "text color" },
		{ _field_short_enum, "justification", &blofeld::halo1::unnamed_enum$281 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$282 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("more text box parameters", nullptr, FIELD_FLAG_NONE, "blah blah blah"),
		{ _field_short_integer, "string list index", "default is 0" },
		{ _field_short_integer, "horiz offset", "offsets text position in its bounding area" },
		{ _field_short_integer, "vert offset", "offsets the text position in its bounding area" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 26),
		FIELD_EXPLANATION_EX("list items", nullptr, FIELD_FLAG_NONE, "These options affect list items for both spinner and column lists\n* child widgets are used to define the visible list items\n* for lists with code-generated list items, the child widgets are used\n  as templated for visible list item placement\nIMPORTANT: for list widgets, the ONLY thing you can have as child widgets are the list item widgets!"),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$283 },
		FIELD_EXPLANATION_EX("spinner list", nullptr, FIELD_FLAG_NONE, "parameters specific to spinner list widgets\nchild widgets are the list items"),
		{ _field_tag_reference, "list header bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_tag_reference, "list footer bitmap", &blofeld::halo1::bitmap_reference },
		{ _field_rectangle_2d, "header bounds" },
		{ _field_rectangle_2d, "footer bounds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_EXPLANATION_EX("column list", nullptr, FIELD_FLAG_NONE, "parameters specific to column list widgets\nchild widgets are the list items"),
		{ _field_tag_reference, "extended description widget", &blofeld::halo1::ui_widget_definition_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 256),
		FIELD_EXPLANATION_EX("conditional widgets", nullptr, FIELD_FLAG_NONE, "use this to attach widgets that are loaded only\nif some internal criteria is met while processing a widget event"),
		{ _field_block, "conditional widgets", &blofeld::halo1::conditional_widget_reference_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		FIELD_EXPLANATION_EX("child widgets", nullptr, FIELD_FLAG_NONE, "use this to attach widgets that are loaded as \'children\'\nof this widget (children are always loaded as part of the parent widget)"),
		{ _field_block, "child widgets", &blofeld::halo1::child_widget_reference_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$273)
	{
		"container",
		"text box",
		"spinner list",
		"column list",
		"game model (not implemented)",
		"movie (not implemented)",
		"custom (not implemented)"
	};
	STRING_LIST(unnamed_enum$273, unnamed_enum$273_strings, _countof(unnamed_enum$273_strings));

	STRINGS(unnamed_enum$274)
	{
		"player 1",
		"player 2",
		"player 3",
		"player 4",
		"any player"
	};
	STRING_LIST(unnamed_enum$274, unnamed_enum$274_strings, _countof(unnamed_enum$274_strings));

	STRINGS(unnamed_enum$275)
	{
		"pass unhandled events to focused child",
		"pause game time",
		"flash background bitmap",
		"dpad up/down tabs thru children",
		"dpad left/right tabs thru children",
		"dpad up/down tabs thru list items",
		"dpad left/right tabs thru list items",
		"dont focus a specific child widget",
		"pass unhandled events to all children",
		"render regardless of controller index",
		"pass handled events to all children",
		"return to main menu if no history",
		"always use tag controller index",
		"always use nifty render fx",
		"don\'t push history",
		"force handle mouse"
	};
	STRING_LIST(unnamed_enum$275, unnamed_enum$275_strings, _countof(unnamed_enum$275_strings));

	STRINGS(unnamed_enum$281)
	{
		"left justify",
		"right justify",
		"center justify"
	};
	STRING_LIST(unnamed_enum$281, unnamed_enum$281_strings, _countof(unnamed_enum$281_strings));

	STRINGS(unnamed_enum$282)
	{
		"editable",
		"password",
		"flashing",
		"don\'t do that weird focus test"
	};
	STRING_LIST(unnamed_enum$282, unnamed_enum$282_strings, _countof(unnamed_enum$282_strings));

	STRINGS(unnamed_enum$283)
	{
		"list items generated in code",
		"list items from string list tag",
		"list items only one tooltip",
		"list single preview no scroll"
	};
	STRING_LIST(unnamed_enum$283, unnamed_enum$283_strings, _countof(unnamed_enum$283_strings));

	TAG_REFERENCE(ui_widget_definition_reference, UI_WIDGET_DEFINITION_TAG);

	TAG_BLOCK(
		child_widget_reference_block,
		"child_widget_reference_block",
		32,
		"s_child_widget_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "widget tag", &blofeld::halo1::ui_widget_definition_reference },
		{ _field_string, "name (unused)" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$285 },
		{ _field_short_integer, "custom controller index" },
		{ _field_short_integer, "vertical offset" },
		{ _field_short_integer, "horizontal offset" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 22),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$285)
	{
		"use custom controller index"
	};
	STRING_LIST(unnamed_enum$285, unnamed_enum$285_strings, _countof(unnamed_enum$285_strings));

	TAG_BLOCK(
		conditional_widget_reference_block,
		"conditional_widget_reference_block",
		32,
		"s_conditional_widget_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "widget tag", &blofeld::halo1::ui_widget_definition_reference },
		{ _field_string, "name (unused)" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$284 },
		{ _field_short_integer, "custom controller index (unused)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 26),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$284)
	{
		"load if event handler function fails"
	};
	STRING_LIST(unnamed_enum$284, unnamed_enum$284_strings, _countof(unnamed_enum$284_strings));

	TAG_BLOCK(
		search_and_replace_reference_block,
		"search_and_replace_reference_block",
		32,
		"s_search_and_replace_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_string, "search string" },
		{ _field_short_enum, "replace function", &blofeld::halo1::unnamed_enum$280 },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$280)
	{
		"NULL",
		"widget\'s controller",
		"build number",
		"pid"
	};
	STRING_LIST(unnamed_enum$280, unnamed_enum$280_strings, _countof(unnamed_enum$280_strings));

	TAG_BLOCK(
		event_handler_references_block,
		"event_handler_references_block",
		32,
		"s_event_handler_references_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$277 },
		{ _field_short_enum, "event type", &blofeld::halo1::unnamed_enum$278 },
		{ _field_short_enum, "function", &blofeld::halo1::unnamed_enum$279 },
		{ _field_tag_reference, "widget tag", &blofeld::halo1::ui_widget_definition_reference },
		{ _field_tag_reference, "sound effect", &blofeld::halo1::sound_reference },
		{ _field_string, "script" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$277)
	{
		"close current widget",
		"close other widget",
		"close all widgets",
		"open widget",
		"reload self",
		"reload other widget",
		"give focus to widget",
		"run function",
		"replace self w/ widget",
		"go back to previous widget",
		"run scenario script",
		"try to branch on failure"
	};
	STRING_LIST(unnamed_enum$277, unnamed_enum$277_strings, _countof(unnamed_enum$277_strings));

	STRINGS(unnamed_enum$278)
	{
		"A button",
		"B button",
		"X button",
		"Y button",
		"black button",
		"white button",
		"left trigger",
		"right trigger",
		"dpad up",
		"dpad down",
		"dpad left",
		"dpad right",
		"start button",
		"back button",
		"left thumb",
		"right thumb",
		"left analog stick up",
		"left analog stick down",
		"left analog stick left",
		"left analog stick right",
		"left analog stick up",
		"right analog stick down",
		"right analog stick left",
		"right analog stick right",
		"created",
		"deleted",
		"get focus",
		"lose focus",
		"left mouse",
		"middle mouse",
		"right mouse",
		"double click",
		"custom activation",
		"post-render"
	};
	STRING_LIST(unnamed_enum$278, unnamed_enum$278_strings, _countof(unnamed_enum$278_strings));

	STRINGS(unnamed_enum$279)
	{
		"NULL",
		"list goto next item",
		"list goto previous item",
		"unused",
		"unused",
		"initialize sp level list solo",
		"initialize sp level list coop",
		"dispose sp level list",
		"solo level set map",
		"set difficulty",
		"start new game",
		"pause game restart at checkpoint",
		"pause game restart level",
		"pause game return to main menu",
		"clear multiplayer player joins",
		"join controller to mp game",
		"initialize net game server list",
		"start network game server",
		"dispose net game server list",
		"shutdown network game",
		"net game join from server list",
		"split screen game initialize",
		"coop game initialize",
		"main menu intialize",
		"mp type menu initialize",
		"pick play stage for quick start",
		"mp level list initialize",
		"mp level list dispose",
		"mp level select",
		"mp profiles list initialize",
		"mp profiles list dispose",
		"mp profile set for game",
		"swap player team",
		"net game join player",
		"player profile list initialize",
		"player profile list dispose",
		"3wide plyr prof set for game",
		"1wide plyr prof set for game",
		"mp profile begin editing",
		"mp profile end editing",
		"mp profile set game engine",
		"mp profile change name",
		"mp profile set ctf rules",
		"mp profile set koth rules",
		"mp profile set slayer rules",
		"mp profile set oddball rules",
		"mp profile set racing rules",
		"mp profile set player options",
		"mp profile set item options",
		"mp profile set indicator opts",
		"mp profile init game engine",
		"mp profile init name",
		"mp profile init ctf rules",
		"mp profile init koth rules",
		"mp profile init slayer rules",
		"mp profile init oddball rules",
		"mp profile init racing rules",
		"mp profile init player opts",
		"mp profile init item options",
		"mp profile init indicator opts",
		"mp profile save changes",
		"color picker menu initialize",
		"color picker menu dispose",
		"color picker select color",
		"player profile begin editing",
		"player profile end editing",
		"player profile change name",
		"player profile save changes",
		"plyr prf init cntl settings",
		"plyr prf init adv cntl set",
		"plyr prf save cntl settings",
		"plyr prf save adv cntl set",
		"mp game player quit",
		"main menu switch to solo game",
		"request del player profile",
		"request del playlist profile",
		"final del player profile",
		"final del playlist profile",
		"cancel profile delete",
		"create&edit playlist profile",
		"create&edit player profile",
		"net game speed start",
		"net game delay start",
		"net server accept conx",
		"net server defer start",
		"net server allow start",
		"disable if no xdemos",
		"run xdemos",
		"sp reset controller choices",
		"sp set p1 controller choice",
		"sp set p2 controller choice",
		"error if no network connection",
		"start server if none advertised",
		"net game unjoin player",
		"close if not editing profile",
		"exit to xbox dashboard",
		"new campaign chosen",
		"new campaign decision",
		"pop history stack once",
		"difficulty menu init",
		"begin music fade out",
		"new game if no plyr profiles",
		"exit gracefully to xbox dashboard",
		"pause game invert pitch",
		"start new coop game",
		"pause game invert spinner get",
		"pause game invert spinner set",
		"main menu quit game",
		"mouse - emit ACCEPT event",
		"mouse - emit BACK event",
		"mouse - emit DPAD LEFT event",
		"mouse - emit DPAD RIGHT event",
		"mouse spinner 3wide click",
		"controls screen init",
		"video screen init",
		"controls begin binding",
		"gamespy screen init",
		"gamespy screen dispose",
		"gamespy select header",
		"gamespy select item",
		"gamespy select button",
		"plr prof init mouse set",
		"plr prof change mouse set",
		"plr prof init audio set",
		"plr prof change audio set",
		"plr prof change video set",
		"controls screen dispose",
		"controls screen change set",
		"mouse - emit X event",
		"gamepad screen init",
		"gamepad screen dispose",
		"gamepad screen change gamepads",
		"gamepad screen select item",
		"mouse screen defaults",
		"audio screen defaults",
		"video screen defaults",
		"controls screen defaults",
		"profile set edit begin",
		"profile manager delete",
		"profile manager select",
		"gamespy dismiss error",
		"server settings init",
		"ss edit server name",
		"ss edit server password",
		"ss start game",
		"video test dialog init",
		"video test dialog dispose",
		"video test dialog accept",
		"gamespy dismiss filters",
		"gamespy update filter settings",
		"gamespy back handler",
		"mouse spinner 1wide click",
		"controls back handler",
		"controls advanced launch",
		"controls advanced ok",
		"mp pause menu open",
		"mp game options open",
		"mp choose team",
		"mp prof init vehicle options",
		"mp prof save vehicle options",
		"single prev cl item activated",
		"mp prof init teamplay options",
		"mp prof save teamplay options",
		"mp game options choose",
		"emit custom activation event",
		"plr prof cancel audio set",
		"plr prof init network options",
		"plr prof save network options",
		"credits post render",
		"difficulty item select",
		"credits initialize",
		"credits dispose",
		"gamespy get patch",
		"video screen dispose",
		"campaign menu init",
		"campaign menu continue",
		"load game menu init",
		"load game menu dispose",
		"load game menu activated",
		"solo menu save checkpoint",
		"mp type set mode",
		"checking for updates ok",
		"checking for updates dismiss",
		"direct ip connect init",
		"direct ip connect go",
		"direct ip edit field",
		"network settings edit a port",
		"network settings defaults",
		"load game menu delete request",
		"load game menu delete finish"
	};
	STRING_LIST(unnamed_enum$279, unnamed_enum$279_strings, _countof(unnamed_enum$279_strings));

	TAG_BLOCK(
		game_data_input_references_block,
		"game_data_input_references_block",
		64,
		"s_game_data_input_references_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "function", &blofeld::halo1::unnamed_enum$276 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$276)
	{
		"NULL",
		"player settings menu update desc",
		"unused",
		"playlist settings menu update desc",
		"gametype select menu update desc",
		"multiplayer type menu update desc",
		"solo level select update",
		"difficulty menu update desc",
		"build number (textbox only)",
		"server list update",
		"network pregame status update",
		"splitscreen pregame status update",
		"net/splitscreen prejoin players",
		"mp profile list update",
		"3wide player profile list update",
		"plyr prof edit-select menu upd8",
		"player profile small menu update",
		"game settings lists text update",
		"solo game objective text",
		"color picker update",
		"game settings lists pic update",
		"main menu fake animate",
		"mp level select update",
		"get active plyr profile name",
		"get edit plyr profile name",
		"get edit game settings name",
		"get active plyr profile color",
		"mp set textbox map name",
		"mp set textbox game ruleset",
		"mp set textbox teams noteams",
		"mp set textbox score limit",
		"mp set textbox score limit type",
		"mp set bitmap for map",
		"mp set bitmap for ruleset",
		"mp set textbox # of players",
		"mp edit profile set rule text",
		"system link status check",
		"mp game directions",
		"teams/no teams bitmap update",
		"warn if diff. will nuke saved game",
		"dim if no net cable",
		"pause game set textbox inverted",
		"dim unless two controllers",
		"controls update menu",
		"video menu update",
		"gamespy screen update",
		"common button bar update",
		"gamepad update menu",
		"server settings update",
		"audio_menu_update",
		"mp prof vehicles update",
		"solo map list update",
		"mp map list update",
		"gt select list update",
		"gt edit list update",
		"load game list update",
		"checking for updates",
		"direct ip connect update",
		"network settings update"
	};
	STRING_LIST(unnamed_enum$276, unnamed_enum$276_strings, _countof(unnamed_enum$276_strings));


	TAG_GROUP(
		ui_widget_collection_group,
		UI_WIDGET_COLLECTION_TAG,
		nullptr,
		INVALID_TAG,
		ui_widget_collection);

	TAG_BLOCK(
		ui_widget_collection,
		"ui_widget_collection_group_block",
		1,
		"s_ui_widget_collection",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "ui widget definitions", &blofeld::halo1::ui_widget_references_block },
		{ _field_terminator }
	};

	TAG_BLOCK(
		ui_widget_references_block,
		"ui_widget_references_block",
		32,
		"s_ui_widget_references_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "ui_widget_definition", &blofeld::halo1::ui_widget_definition_reference },
		{ _field_terminator }
	};


	TAG_GROUP(
		continuous_damage_effect_group,
		CONTINUOUS_DAMAGE_EFFECT_TAG,
		nullptr,
		INVALID_TAG,
		continuous_damage_effect);

	TAG_BLOCK(
		continuous_damage_effect,
		"continuous_damage_effect_group_block",
		1,
		"s_continuous_damage_effect",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_real_bounds, "radius", nullptr, "world units" },
		{ _field_real_fraction, "cutoff scale", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("vibrate parameters", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_fraction, "low frequency", nullptr, nullptr, "[0,1]" },
		{ _field_real_fraction, "high frequency", nullptr, nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("camera shaking", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "random translation", "random translation in all directions", "world units" },
		{ _field_angle, "random rotation", "random rotation in all directions", "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_short_enum, "wobble function", "a function to perturb the effect's behavior over time", &blofeld::halo1::unnamed_enum$42 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "wobble function period", nullptr, "seconds" },
		{ _field_real_fraction, "wobble weight", "a value of 0.0 signifies that the wobble function has no effect; a value of 1.0 signifies that the effect will not be felt when the wobble function's value is zero." },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 160),
		FIELD_EXPLANATION_EX("damage", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "side effect", &blofeld::halo1::unnamed_enum$235 },
		{ _field_short_enum, "category", &blofeld::halo1::unnamed_enum$236 },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$237 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "damage lower bound" },
		{ _field_real_bounds, "damage upper bound" },
		{ _field_real, "vehicle passthrough penalty", "zero damages passengers in vehicles, one does not", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "stun", "amount of stun added to damaged unit", nullptr, "[0,1]" },
		{ _field_real, "maximum stun", "damaged unit's stun will never exceed this amount", nullptr, "[0,1]" },
		{ _field_real, "stun time", "duration of stun due to this damage", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "instantaneous acceleration", nullptr, nullptr, "[0,+inf]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("damage modifiers", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "dirt", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "sand", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "stone", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "snow", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "wood", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "metal (hollow)", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "metal (thin)", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "metal (thick)", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "rubber", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "glass", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "force field", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "grunt", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "hunter armor", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "hunter skin", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "elite", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "jackal", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "jackal energy shield", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "engineer", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "engineer force field", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "flood combat form", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "flood carrier form", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "cyborg", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "cyborg energy shield", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "armored human", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "human", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "sentinel", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "monitor", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "plastic", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "water", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "leaves", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "elite energy shield", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "ice", nullptr, nullptr, "[0,+inf]" },
		{ _field_real, "hunter shield", nullptr, nullptr, "[0,+inf]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_terminator }
	};


	TAG_GROUP(
		material_effects_group,
		MATERIAL_EFFECTS_TAG,
		nullptr,
		INVALID_TAG,
		material_effects);

	TAG_BLOCK(
		material_effects,
		"material_effects_group_block",
		1,
		"s_material_effects",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "effects", &blofeld::halo1::material_effect_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		{ _field_terminator }
	};

	TAG_BLOCK(
		material_effect_block,
		"material_effect_block",
		13,
		"s_material_effect_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "materials", &blofeld::halo1::material_effect_material_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};

	TAG_BLOCK(
		material_effect_material_block,
		"material_effect_material_block",
		33,
		"s_material_effect_material_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "effect", &blofeld::halo1::effect_reference },
		{ _field_tag_reference, "sound", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_terminator }
	};


	TAG_GROUP(
		garbage_group,
		GARBAGE_TAG,
		&item_group,
		ITEM_TAG,
		garbage);

	TAG_BLOCK(
		garbage,
		"garbage_group_block",
		1,
		"s_garbage",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "item", &blofeld::halo1::item_struct_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 168),
		{ _field_terminator }
	};


	TAG_GROUP(
		tag_collection_group,
		TAG_COLLECTION_TAG,
		nullptr,
		INVALID_TAG,
		tag_collection);

	TAG_BLOCK(
		tag_collection,
		"tag_collection_group_block",
		1,
		"s_tag_collection",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_block, "tag references", &blofeld::halo1::tag_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(
		tag_reference,
		"tag reference",
		200,
		"s_tag_reference",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "tag", &blofeld::halo1::_reference$2 },
		{ _field_terminator }
	};

	TAG_REFERENCE(_reference$2);


	TAG_GROUP(
		input_device_defaults_group,
		INPUT_DEVICE_DEFAULTS_TAG,
		nullptr,
		INVALID_TAG,
		input_device_defaults);

	TAG_BLOCK(
		input_device_defaults,
		"input_device_defaults_group_block",
		1,
		"s_input_device_defaults",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_enum, "device type", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$286 },
		{ _field_word_flags, "flags", FIELD_FLAG_READ_ONLY, &blofeld::halo1::unnamed_enum$287 },
		{ _field_data, "device id", FIELD_FLAG_READ_ONLY },
		{ _field_data, "profile", FIELD_FLAG_READ_ONLY },
		{ _field_custom, "value" },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$286)
	{
		"mouse and keyboard",
		"joysticks/gamepads/etc...",
		"full profile definition"
	};
	STRING_LIST(unnamed_enum$286, unnamed_enum$286_strings, _countof(unnamed_enum$286_strings));

	STRINGS(unnamed_enum$287)
	{
		"unused"
	};
	STRING_LIST(unnamed_enum$287, unnamed_enum$287_strings, _countof(unnamed_enum$287_strings));


	TAG_GROUP(
		unit_group,
		UNIT_TAG,
		&object_group,
		OBJECT_TAG,
		unit);

	TAG_BLOCK(
		unit,
		"unit_group_block",
		1,
		"s_unit",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "object", &blofeld::halo1::object_struct_definition },
		FIELD_EXPLANATION_EX("$$$ UNIT $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$21 },
		{ _field_short_enum, "default team", &blofeld::halo1::unnamed_enum$22 },
		{ _field_short_enum, "constant sound volume", &blofeld::halo1::unnamed_enum$23 },
		{ _field_real, "rider damage fraction", "what percent damage applied to us gets applied to our children (i.e., riders)", nullptr, "[0,+inf]" },
		{ _field_tag_reference, "integrated light toggle", &blofeld::halo1::effect_reference },
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$24 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$24 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$24 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$24 },
		{ _field_angle, "camera field of view", nullptr, "degrees" },
		{ _field_real, "camera stiffness" },
		{ _field_string, "camera marker name" },
		{ _field_string, "camera submerged marker name" },
		{ _field_angle, "pitch auto-level" },
		{ _field_angle_bounds, "pitch range" },
		{ _field_block, "camera tracks", &blofeld::halo1::unit_camera_track_block },
		{ _field_real_vector_3d, "seat acceleration scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "soft ping threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "soft ping interrupt time", nullptr, "seconds" },
		{ _field_real, "hard ping threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "hard ping interrupt time", nullptr, "seconds" },
		{ _field_real, "hard death threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "feign death threshold", nullptr, nullptr, "[0,1]" },
		{ _field_real, "feign death time", nullptr, "seconds" },
		{ _field_real, "distance of evade anim", "this must be set to tell the AI how far it should expect our evade animation to move us", "world units" },
		{ _field_real, "distance of dive anim", "this must be set to tell the AI how far it should expect our dive animation to move us", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "stunned movement threshold", "if we take this much damage in a short space of time we will play our 'stunned movement' animations", nullptr, "[0,1]" },
		{ _field_real, "feign death chance", nullptr, nullptr, "[0,1]" },
		{ _field_real, "feign repeat chance", nullptr, nullptr, "[0,1]" },
		{ _field_tag_reference, "spawned actor", "actor variant which we spawn when we are destroyed or self-destruct", &blofeld::halo1::actor_variant_reference },
		{ _field_short_integer_bounds, "spawned actor count", "number of actors which we spawn" },
		{ _field_real, "spawned velocity", "velocity at which we throw spawned actors" },
		{ _field_angle, "aiming velocity maximum", nullptr, "degrees per second" },
		{ _field_angle, "aiming acceleration maximum", nullptr, "degrees per second squared" },
		{ _field_real_fraction, "casual aiming modifier", nullptr, nullptr, "[0,1]" },
		{ _field_angle, "looking velocity maximum", nullptr, "degrees per second" },
		{ _field_angle, "looking acceleration maximum", nullptr, "degrees per second squared" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "AI vehicle radius", "radius around this unit that the AI tries to avoid when entering it as a vehicle (zero = use bounding sphere radius)" },
		{ _field_real, "AI danger radius", "danger radius around this unit that the AI tries to avoid" },
		{ _field_tag_reference, "melee damage", &blofeld::halo1::damage_effect_reference },
		{ _field_short_enum, "motion sensor blip size", &blofeld::halo1::unnamed_enum$25 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "NEW HUD INTERFACES", &blofeld::halo1::unit_hud_reference_block },
		{ _field_block, "dialogue variants", &blofeld::halo1::dialogue_variant_block },
		{ _field_real, "grenade velocity", nullptr, "world units per second" },
		{ _field_short_enum, "grenade type", &blofeld::halo1::unnamed_enum$26 },
		{ _field_short_integer, "grenade count" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_block, "powered seats", &blofeld::halo1::powered_seat_block },
		{ _field_block, "weapons", &blofeld::halo1::unit_weapon_block },
		{ _field_block, "seats", &blofeld::halo1::unit_seat_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$21)
	{
		"circular aiming",
		"destroyed after dying",
		"half-speed interpolation",
		"fires from camera",
		"entrance inside bounding sphere",
		"unused",
		"causes passenger dialogue",
		"resists pings",
		"melee attack is fatal",
		"don\'t reface during pings",
		"has no aiming",
		"simple creature",
		"impact melee attaches to unit",
		"impact melee dies on shields",
		"cannot open doors automatically",
		"melee attackers cannot attach",
		"not instantly killed by melee",
		"shield sapping",
		"runs around flaming",
		"inconsequential",
		"special cinematic unit",
		"ignored by autoaiming",
		"shields fry infection forms",
		"integrated light cntrls weapon",
		"integrated light lasts forever"
	};
	STRING_LIST(unnamed_enum$21, unnamed_enum$21_strings, _countof(unnamed_enum$21_strings));

	STRINGS(unnamed_enum$22)
	{
		"none",
		"player",
		"human",
		"covenant",
		"flood",
		"sentinel",
		"unused (6)",
		"unused (7)",
		"unused (8)",
		"unused (9)"
	};
	STRING_LIST(unnamed_enum$22, unnamed_enum$22_strings, _countof(unnamed_enum$22_strings));

	STRINGS(unnamed_enum$24)
	{
		"none",
		"driver seat power",
		"gunner seat power",
		"aiming change",
		"mouth aperture",
		"integrated light power",
		"can blink",
		"shield sapping"
	};
	STRING_LIST(unnamed_enum$24, unnamed_enum$24_strings, _countof(unnamed_enum$24_strings));

	TAG_REFERENCE(actor_variant_reference, ACTOR_VARIANT_TAG);

	STRINGS(unnamed_enum$25)
	{
		"medium",
		"small",
		"large"
	};
	STRING_LIST(unnamed_enum$25, unnamed_enum$25_strings, _countof(unnamed_enum$25_strings));

	TAG_BLOCK(
		unit_seat_block,
		"unit_seat_block",
		16,
		"s_unit_seat_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$27 },
		{ _field_string, "label" },
		{ _field_string, "marker name", FIELD_FLAG_INDEX },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_real_vector_3d, "acceleration scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "yaw rate", nullptr, "degrees per second" },
		{ _field_real, "pitch rate", nullptr, "degrees per second" },
		{ _field_string, "camera marker name" },
		{ _field_string, "camera submerged marker name" },
		{ _field_angle, "pitch auto-level" },
		{ _field_angle_bounds, "pitch range" },
		{ _field_block, "camera tracks", &blofeld::halo1::unit_camera_track_block },
		{ _field_block, "unit hud interface", &blofeld::halo1::unit_hud_reference_block },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_short_integer, "hud text message index" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_angle, "yaw minimum" },
		{ _field_angle, "yaw maximum" },
		{ _field_tag_reference, "built-in gunner", &blofeld::halo1::actor_variant_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$27)
	{
		"invisible",
		"locked",
		"driver",
		"gunner",
		"third person camera",
		"allows weapons",
		"third person on enter",
		"first person camera slaved to gun.",
		"allow vehicle communication animations",
		"not valid without driver",
		"allow AI noncombatants"
	};
	STRING_LIST(unnamed_enum$27, unnamed_enum$27_strings, _countof(unnamed_enum$27_strings));

	TAG_REFERENCE(actor_variant_reference$2, ACTOR_VARIANT_TAG);

	TAG_BLOCK(
		unit_hud_reference_block,
		"unit_hud_reference_block",
		2,
		"s_unit_hud_reference_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "unit hud interface", &blofeld::halo1::unit_hud_interface_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};

	TAG_REFERENCE(unit_hud_interface_reference, UNIT_HUD_INTERFACE_TAG);

	TAG_BLOCK(
		unit_camera_track_block,
		"unit_camera_track_block",
		2,
		"s_unit_camera_track_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "track", &blofeld::halo1::camera_track_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_terminator }
	};

	TAG_BLOCK(
		unit_weapon_block,
		"unit_weapon_block",
		4,
		"s_unit_weapon_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_tag_reference, "weapon", FIELD_FLAG_INDEX, &blofeld::halo1::weapon_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_terminator }
	};

	TAG_REFERENCE(weapon_reference, WEAPON_TAG);

	TAG_BLOCK(
		powered_seat_block,
		"powered_seat_block",
		2,
		"s_powered_seat_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "driver powerup time", nullptr, "seconds" },
		{ _field_real, "driver powerdown time", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 56),
		{ _field_terminator }
	};

	TAG_BLOCK(
		dialogue_variant_block,
		"dialogue_variant_block",
		16,
		"s_dialogue_variant_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "variant number", "variant number to use this dialogue with (must match the suffix in the permutations on the unit's model)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_tag_reference, "dialogue", &blofeld::halo1::dialogue_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(dialogue_reference, DIALOGUE_TAG);


	TAG_GROUP(
		biped_group,
		BIPED_TAG,
		&unit_group,
		UNIT_TAG,
		biped);

	TAG_BLOCK(
		biped,
		"biped_group_block",
		1,
		"s_biped",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "unit", &blofeld::halo1::unit_struct_definition },
		FIELD_EXPLANATION_EX("$$$ BIPED $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "moving turning speed", nullptr, "degrees per second" },
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$28 },
		{ _field_angle, "stationary turning threshold" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$29 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$29 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$29 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$29 },
		{ _field_tag_reference, "DON'T USE", &blofeld::halo1::damage_effect_reference },
		FIELD_EXPLANATION_EX("flying", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "bank angle", "angle at which we bank left/right when sidestepping or turning while moving forwards", "degrees" },
		{ _field_real, "bank apply time", "time it takes us to apply a bank", "seconds" },
		{ _field_real, "bank decay time", "time it takes us to recover from a bank", "seconds" },
		{ _field_real, "pitch ratio", "amount that we pitch up/down when moving up or down" },
		{ _field_real, "max velocity", "max velocity when not crouching", "world units per second" },
		{ _field_real, "max sidestep velocity", "max sideways or up/down velocity when not crouching", "world units per second" },
		{ _field_real, "acceleration", nullptr, "world units per second squared" },
		{ _field_real, "deceleration", nullptr, "world units per second squared" },
		{ _field_angle, "angular velocity maximum", "turn rate", "degrees per second" },
		{ _field_angle, "angular acceleration maximum", "turn acceleration rate", "degrees per second squared" },
		{ _field_real, "crouch velocity modifier", "how much slower we fly if crouching (zero = same speed)", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("movement", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "maximum slope angle", nullptr, "degrees" },
		{ _field_angle, "downhill falloff angle", nullptr, "degrees" },
		{ _field_angle, "downhill cutoff angle", nullptr, "degrees" },
		{ _field_real, "downhill velocity scale" },
		{ _field_angle, "uphill falloff angle", nullptr, "degrees" },
		{ _field_angle, "uphill cutoff angle", nullptr, "degrees" },
		{ _field_real, "uphill velocity scale" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_tag_reference, "footsteps", &blofeld::halo1::material_effects_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		FIELD_EXPLANATION_EX("jumping and landing", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "jump velocity", nullptr, "world units per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 28),
		{ _field_real, "maximum soft landing time", "the longest amount of time the biped can take to recover from a soft landing", "seconds" },
		{ _field_real, "maximum hard landing time", "the longest amount of time the biped can take to recover from a hard landing", "seconds" },
		{ _field_real, "minimum soft landing velocity", "below this velocity the biped does not react when landing", "world units per second" },
		{ _field_real, "minimum hard landing velocity", "below this velocity the biped will not do a soft landing when returning to the ground", "world units per second" },
		{ _field_real, "maximum hard landing velocity", "the velocity corresponding to the maximum landing time", "world units per second" },
		{ _field_real, "death hard landing velocity", "the maximum velocity with which a character can strike the ground and live", "world units per second" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 20),
		FIELD_EXPLANATION_EX("camera, collision, and autoaim", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "standing camera height", nullptr, "world units" },
		{ _field_real, "crouching camera height", nullptr, "world units" },
		{ _field_real, "crouch transition time", nullptr, "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real, "standing collision height", nullptr, "world units" },
		{ _field_real, "crouching collision height", nullptr, "world units" },
		{ _field_real, "collision radius", nullptr, "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 40),
		{ _field_real, "autoaim width", nullptr, "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 140),
		{ _field_block, "contact points", "these are the points where the biped touches the ground", &blofeld::halo1::contact_point_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$28)
	{
		"turns without animating",
		"uses player physics",
		"flying",
		"physics pill centered at origin",
		"spherical",
		"passes through other bipeds",
		"can climb any surface",
		"immune to falling damage",
		"rotate while airborne",
		"uses limp body physics",
		"has no dying airborne",
		"random speed increase",
		"unit uses old (NTSC) player physics"
	};
	STRING_LIST(unnamed_enum$28, unnamed_enum$28_strings, _countof(unnamed_enum$28_strings));

	STRINGS(unnamed_enum$29)
	{
		"none",
		"flying velocity"
	};
	STRING_LIST(unnamed_enum$29, unnamed_enum$29_strings, _countof(unnamed_enum$29_strings));

	TAG_BLOCK(
		contact_point_block,
		"contact_point_block",
		2,
		"s_contact_point_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_string, "marker name", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};


	TAG_GROUP(
		vehicle_group,
		VEHICLE_TAG,
		&unit_group,
		UNIT_TAG,
		vehicle);

	TAG_BLOCK(
		vehicle,
		"vehicle_group_block",
		1,
		"s_vehicle",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "unit", &blofeld::halo1::unit_struct_definition },
		FIELD_EXPLANATION_EX("$$$ VEHICLE $$$", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$30 },
		{ _field_short_enum, "type", &blofeld::halo1::unnamed_enum$31 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "maximum forward speed" },
		{ _field_real, "maximum reverse speed" },
		{ _field_real, "speed acceleration" },
		{ _field_real, "speed deceleration" },
		{ _field_real, "maximum left turn" },
		{ _field_real, "maximum right turn (negative)" },
		{ _field_real, "wheel circumference" },
		{ _field_real, "turn rate" },
		{ _field_real, "blur speed" },
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$32 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$32 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$32 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$32 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "maximum left slide" },
		{ _field_real, "maximum right slide" },
		{ _field_real, "slide acceleration" },
		{ _field_real, "slide deceleration" },
		{ _field_real, "minimum flipping angular velocity" },
		{ _field_real, "maximum flipping angular velocity" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real, "fixed gun yaw" },
		{ _field_real, "fixed gun pitch" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_real, "ai sideslip distance" },
		{ _field_real, "ai destination radius" },
		{ _field_real, "ai avoidance distance" },
		{ _field_real, "ai pathfinding radius" },
		{ _field_real, "ai charge repeat timeout" },
		{ _field_real, "ai strafing abort range" },
		{ _field_angle_bounds, "ai oversteering bounds" },
		{ _field_angle, "ai steering maximum" },
		{ _field_real, "ai throttle maximum" },
		{ _field_real, "ai move-position time" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_tag_reference, "suspension sound", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "crash sound", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "material effects", &blofeld::halo1::material_effects_reference },
		{ _field_tag_reference, "effect", &blofeld::halo1::effect_reference },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$30)
	{
		"speed wakes physics",
		"turn wakes physics",
		"driver power wakes physics",
		"gunner power wakes physics",
		"control opposite speed sets brake",
		"slide wakes physics",
		"kills riders at terminal velocity",
		"causes collision damage",
		"ai weapon cannot rotate",
		"ai does not require driver",
		"ai unused",
		"ai driver enable",
		"ai driver flying",
		"ai driver can-sidestep",
		"ai driver hovering"
	};
	STRING_LIST(unnamed_enum$30, unnamed_enum$30_strings, _countof(unnamed_enum$30_strings));

	STRINGS(unnamed_enum$31)
	{
		"human tank",
		"human jeep",
		"human boat",
		"human plane",
		"alien scout",
		"alien fighter",
		"turret"
	};
	STRING_LIST(unnamed_enum$31, unnamed_enum$31_strings, _countof(unnamed_enum$31_strings));

	STRINGS(unnamed_enum$32)
	{
		"none",
		"speed absolute",
		"speed forward",
		"speed backward",
		"slide absolute",
		"slide left",
		"slide right",
		"speed slide maximum",
		"turn absolute",
		"turn left",
		"turn right",
		"crouch",
		"jump",
		"walk",
		"velocity air",
		"velocity water",
		"velocity ground",
		"velocity forward",
		"velocity left",
		"velocity up",
		"left tread position",
		"right tread position",
		"left tread velocity",
		"right tread velocity",
		"front left tire position",
		"front right tire position",
		"back left tire position",
		"back right tire position",
		"front left tire velocity",
		"front right tire velocity",
		"back left tire velocity",
		"back right tire velocity",
		"wingtip contrail",
		"hover",
		"thrust",
		"engine hack",
		"wingtip contrail new"
	};
	STRING_LIST(unnamed_enum$32, unnamed_enum$32_strings, _countof(unnamed_enum$32_strings));


	TAG_GROUP(
		scenery_group,
		SCENERY_TAG,
		&object_group,
		OBJECT_TAG,
		scenery);

	TAG_BLOCK(
		scenery,
		"scenery_group_block",
		1,
		"s_scenery",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "object", &blofeld::halo1::object_struct_definition },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 128),
		{ _field_terminator }
	};


	TAG_GROUP(
		weapon_group,
		WEAPON_TAG,
		&item_group,
		ITEM_TAG,
		weapon);

	TAG_BLOCK(
		weapon,
		"weapon_group_block",
		1,
		"s_weapon",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_struct, "item", &blofeld::halo1::item_struct_definition },
		FIELD_EXPLANATION_EX("$$$ WEAPON $$$", nullptr, FIELD_FLAG_NONE, "All weapons should have \'primary trigger\' and \'secondary trigger\' markers as appropriate.\nBlurred permutations are called \'$primary-blur\' and \'$secondary-blur\'."),
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$56 },
		{ _field_string, "label", "the string used to match this weapon to an animation mode in the unit carrying it" },
		{ _field_short_enum, "secondary trigger mode", &blofeld::halo1::unnamed_enum$57 },
		{ _field_short_integer, "maximum alternate shots loaded", "if the second trigger loads alternate ammunition, this is the maximum number of shots that can be loaded at a time" },
		FIELD_EXPLANATION_EX("export to functions", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "A in", &blofeld::halo1::unnamed_enum$58 },
		{ _field_short_enum, "B in", &blofeld::halo1::unnamed_enum$58 },
		{ _field_short_enum, "C in", &blofeld::halo1::unnamed_enum$58 },
		{ _field_short_enum, "D in", &blofeld::halo1::unnamed_enum$58 },
		{ _field_real, "ready time", nullptr, "seconds" },
		{ _field_tag_reference, "ready effect", &blofeld::halo1::sound_effect_reference },
		FIELD_EXPLANATION_EX("heat", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_fraction, "heat recovery threshold", "the heat value a weapon must return to before leaving the overheated state, once it has become overheated in the first place", nullptr, "[0,1]" },
		{ _field_real_fraction, "overheated threshold", "the heat value over which a weapon first becomes overheated (should be greater than the heat recovery threshold)", nullptr, "[0,1]" },
		{ _field_real_fraction, "heat detonation threshold", "the heat value above which the weapon has a chance of exploding each time it is fired", nullptr, "[0,1]" },
		{ _field_real_fraction, "heat detonation fraction", "the percent chance (between 0.0 and 1.0) the weapon will explode when fired over the heat detonation threshold", nullptr, "[0,1]" },
		{ _field_real_fraction, "heat loss per second", "the amount of heat lost each second when the weapon is not being fired", nullptr, "[0,1]" },
		{ _field_real_fraction, "heat illumination", "the amount of illumination given off when the weapon is overheated", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "overheated", &blofeld::halo1::sound_effect_reference },
		{ _field_tag_reference, "detonation", &blofeld::halo1::sound_effect_reference },
		{ _field_tag_reference, "player melee damage", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "player melee response", &blofeld::halo1::damage_effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("actor firing parameters", nullptr, FIELD_FLAG_NONE, "an optional actor variant that specifies the burst geometry and firing patterns to be used with this weapon"),
		{ _field_tag_reference, "actor firing parameters", &blofeld::halo1::actor_variant_reference$2 },
		FIELD_EXPLANATION_EX("reticle", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "near reticle range", "the range at which the closer of the two static target reticles will be drawn", "world units" },
		{ _field_real, "far reticle range", "the range at which the farther of the two static target reticles will be drawn", "world units" },
		{ _field_real, "intersection reticle range", "the maximum range at which the dynamic target reticle will be drawn" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("zoom", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_integer, "magnification levels", "the number of magnification levels this weapon allows" },
		{ _field_real_bounds, "magnification range" },
		FIELD_EXPLANATION_EX("aim assist", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_angle, "autoaim angle", "the maximum angle that autoaim works at full strength", "degrees" },
		{ _field_real, "autoaim range", "the maximum distance that autoaim works at full strength", "world units" },
		{ _field_angle, "magnetism angle", "the maximum angle that magnetism works at full strength", "degrees" },
		{ _field_real, "magnetism range", "the maximum distance that magnetism works at full strength", "world units" },
		{ _field_angle, "deviation angle", "the maximum angle that a projectile is allowed to deviate from the gun barrel", "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("movement", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "movement penalized", &blofeld::halo1::unnamed_enum$59 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_fraction, "forward movement penalty", "percent slowdown to forward movement for units carrying this weapon" },
		{ _field_real_fraction, "sideways movement penalty", "percent slowdown to sideways and backward movement for units carrying this weapon" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("AI targeting parameters", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "minimum target range", "minimum range that actors using this weapon will try and target stuff at" },
		{ _field_real, "looking time modifier", "how much faster actors look around idly using this weapon (zero is unchanged)" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		FIELD_EXPLANATION_EX("miscellaneous", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "light power-on time", nullptr, "seconds" },
		{ _field_real, "light power-off time", nullptr, "seconds" },
		{ _field_tag_reference, "light power-on effect", &blofeld::halo1::sound_effect_reference },
		{ _field_tag_reference, "light power-off effect", &blofeld::halo1::sound_effect_reference },
		{ _field_real, "age heat recovery penalty", "how much the weapon's heat recovery is penalized as it ages" },
		{ _field_real, "age rate of fire penalty", "how much the weapon's rate of fire is penalized as it ages" },
		{ _field_real_fraction, "age misfire start", "the age threshold when the weapon begins to misfire", nullptr, "[0,1]" },
		{ _field_real_fraction, "age misfire chance", "at age 1.0, the misfire chance per shot", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_EXPLANATION_EX("interface", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_tag_reference, "first person model", &blofeld::halo1::gbxmodel_reference$2 },
		{ _field_tag_reference, "first person animations", &blofeld::halo1::model_animations_reference$2 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_tag_reference, "hud interface", &blofeld::halo1::weapon_hud_interface_reference },
		{ _field_tag_reference, "pickup sound", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "zoom-in sound", &blofeld::halo1::sound_reference },
		{ _field_tag_reference, "zoom-out sound", &blofeld::halo1::sound_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real, "active camo ding", "how much to decrease active camo when a round is fired" },
		{ _field_real, "active camo regrowth rate", "how fast to increase active camo (per tick) when a round is fired" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION_EX("more miscellaneous", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "weapon type", &blofeld::halo1::unnamed_enum$60 },
		{ _field_block, "predicted resources", &blofeld::halo1::predicted_resource_block },
		{ _field_block, "magazines", &blofeld::halo1::magazines },
		{ _field_block, "triggers", &blofeld::halo1::triggers },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$56)
	{
		"vertical heat display",
		"mutually exclusive triggers",
		"attacks automatically on bump",
		"must be readied",
		"doesn\'t count toward maximum",
		"aim assists only when zoomed",
		"prevents grenade throwing",
		"must be picked up",
		"holds triggers when dropped",
		"prevents melee attack",
		"detonates when dropped",
		"cannot fire at maximum age",
		"secondary trigger overrides grenades",
		"(OBSOLETE)does not depower active camo in multilplayer",
		"enables integrated night vision",
		"AIs use weapon melee damage"
	};
	STRING_LIST(unnamed_enum$56, unnamed_enum$56_strings, _countof(unnamed_enum$56_strings));

	STRINGS(unnamed_enum$57)
	{
		"normal",
		"slaved to primary",
		"inhibits primary",
		"loads alterate ammunition",
		"loads multiple primary ammunition"
	};
	STRING_LIST(unnamed_enum$57, unnamed_enum$57_strings, _countof(unnamed_enum$57_strings));

	STRINGS(unnamed_enum$58)
	{
		"none",
		"heat",
		"primary ammunition",
		"secondary ammunition",
		"primary rate of fire",
		"secondary rate of fire",
		"ready",
		"primary ejection port",
		"secondary ejection port",
		"overheated",
		"primary charged",
		"secondary charged",
		"illumination",
		"age",
		"integrated light",
		"primary firing",
		"secondary firing",
		"primary firing on",
		"secondary firing on"
	};
	STRING_LIST(unnamed_enum$58, unnamed_enum$58_strings, _countof(unnamed_enum$58_strings));

	TAG_REFERENCE_GROUP(sound_effect_reference)
	{
		SOUND_TAG,
		EFFECT_TAG,
		INVALID_TAG
	};

	STRINGS(unnamed_enum$59)
	{
		"always",
		"when zoomed",
		"when zoomed or reloading"
	};
	STRING_LIST(unnamed_enum$59, unnamed_enum$59_strings, _countof(unnamed_enum$59_strings));

	TAG_REFERENCE(gbxmodel_reference$2, GBXMODEL_TAG);

	TAG_REFERENCE(model_animations_reference$2, MODEL_ANIMATIONS_TAG);

	STRINGS(unnamed_enum$60)
	{
		"undefined",
		"shotgun",
		"needler",
		"plasma pistol",
		"plasma rifle"
	};
	STRING_LIST(unnamed_enum$60, unnamed_enum$60_strings, _countof(unnamed_enum$60_strings));

	TAG_BLOCK(
		triggers,
		"triggers",
		2,
		"s_triggers",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$62 },
		FIELD_EXPLANATION_EX("firing", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "rounds per second", "the number of firing effects created per second" },
		{ _field_real, "acceleration time", "the continuous firing time it takes for the weapon to achieve its final rounds per second", "seconds" },
		{ _field_real, "deceleration time", "the continuous idle time it takes for the weapon to return from its final rounds per second to its initial", "seconds" },
		{ _field_real_fraction, "blurred rate of fire", "a percentage between 0 and 1 which controls how soon in its firing animation the weapon blurs" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_short_block_index, "magazine", "the magazine from which this trigger draws its ammunition", &blofeld::halo1::magazines },
		{ _field_short_integer, "rounds per shot", "the number of rounds expended to create a single firing effect" },
		{ _field_short_integer, "minimum rounds loaded", "the minimum number of rounds necessary to fire the weapon" },
		{ _field_short_integer, "rounds between tracers", "the number of non-tracer rounds fired between tracers" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 6),
		{ _field_short_enum, "firing noise", "how loud this weapon appears to the AI", &blofeld::halo1::unnamed_enum$23 },
		FIELD_EXPLANATION_EX("error", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real_bounds, "error", "the accuracy (between 0.0 and 1.0) of the weapon during firing" },
		{ _field_real, "acceleration time", "the continuous firing time it takes for the weapon to achieve its final error", "seconds" },
		{ _field_real, "deceleration time", "the continuous idle time it takes for the weapon to return to its initial error", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_EXPLANATION_EX("charging", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "charging time", "the amount of time it takes for this trigger to become fully charged", "seconds" },
		{ _field_real, "charged time", "the amount of time this trigger can be charged before becoming overcharged", "seconds" },
		{ _field_short_enum, "overcharged action", &blofeld::halo1::unnamed_enum$63 },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "charged illumination", "the amount of illumination given off when the weapon is fully charged", nullptr, "[0,1]" },
		{ _field_real, "spew time", "length of time the weapon will spew (fire continuously) while discharging", "seconds" },
		{ _field_tag_reference, "charging effect", "the charging effect is created once when the trigger begins to charge", &blofeld::halo1::sound_effect_reference },
		FIELD_EXPLANATION_EX("projectile", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_short_enum, "distribution function", &blofeld::halo1::unnamed_enum$64 },
		{ _field_short_integer, "projectiles per shot" },
		{ _field_real, "distribution angle", nullptr, "degrees" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_angle, "minimum error", nullptr, "degrees" },
		{ _field_angle_bounds, "error angle", nullptr, "degrees" },
		{ _field_real_point_3d, "first person offset", "+x is forward, +z is up, +y is left", "world units" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_tag_reference, "projectile", &blofeld::halo1::projectile_reference },
		FIELD_EXPLANATION_EX("misc", nullptr, FIELD_FLAG_NONE, nullptr),
		{ _field_real, "ejection port recovery time", "the amount of time (in seconds) it takes for the ejection port to transition from 1.0 (open) to 0.0 (closed) after a shot has been fired" },
		{ _field_real, "illumination recovery time", "the amount of time (in seconds) it takes the illumination function to transition from 1.0 (bright) to 0.0 (dark) after a shot has been fired" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_real_fraction, "heat generated per round", "the amount of heat generated each time the trigger is fired", nullptr, "[0,1]" },
		{ _field_real_fraction, "age generated per round", "the amount the weapon ages each time the trigger is fired", nullptr, "[0,1]" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "overload time", "the next trigger fires this often while holding down this trigger", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 24),
		{ _field_block, "firing effects", "firing effects determine what happens when this trigger is fired", &blofeld::halo1::trigger_firing_effect_block },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$62)
	{
		"tracks fired projectile#poo poo ca ca pee pee",
		"random firing effects#rather than being chosen sequentially, firing effects are picked randomly",
		"can fire with partial ammo#allows a weapon to be fired as long as there is a non-zero amount of ammunition loaded",
		"does not repeat automatically#once fired, this trigger must be released and pressed to fire again",
		"locks in on/off state#once depressed, this trigger must be released and pressed again to turn it off (and likewise to turn it back on)",
		"projectiles use weapon origin#instead of coming out of the magic first person camera origin, the projectiles for this weapon actually come out of the gun",
		"sticks when dropped#if this trigger is pressed when its owner drops the weapon (for whatever reason) this trigger stays down",
		"ejects during chamber#this trigger\'s ejection port is started during the key frame of its chamber animation",
		"discharging spews",
		"analog rate of fire",
		"use error when unzoomed",
		"projectile vector cannot be adjusted#projectiles fired by this weapon cannot have their direction adjusted by the AI to hit the target",
		"projectiles have identical error",
		"projectile is client-side only"
	};
	STRING_LIST(unnamed_enum$62, unnamed_enum$62_strings, _countof(unnamed_enum$62_strings));

	STRINGS(unnamed_enum$63)
	{
		"none",
		"explode",
		"discharge"
	};
	STRING_LIST(unnamed_enum$63, unnamed_enum$63_strings, _countof(unnamed_enum$63_strings));

	STRINGS(unnamed_enum$64)
	{
		"point",
		"horizontal fan"
	};
	STRING_LIST(unnamed_enum$64, unnamed_enum$64_strings, _countof(unnamed_enum$64_strings));

	TAG_BLOCK(
		trigger_firing_effect_block,
		"trigger_firing_effect_block",
		8,
		"s_trigger_firing_effect_block",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "shot count lower bound", "the minimum number of times this firing effect will be used, once it has been chosen" },
		{ _field_short_integer, "shot count upper bound", "the maximum number of times this firing effect will be used, once it has been chosen" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_tag_reference, "firing effect", "this effect is used when the weapon is loaded and fired normally", FIELD_FLAG_INDEX, &blofeld::halo1::sound_effect_reference },
		{ _field_tag_reference, "misfire effect", "this effect is used when the weapon is loaded but fired while overheated", &blofeld::halo1::sound_effect_reference },
		{ _field_tag_reference, "empty effect", "this effect is used when the weapon is not loaded", &blofeld::halo1::sound_effect_reference },
		{ _field_tag_reference, "firing damage", "this effect is used when the weapon is loaded and fired normally", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "misfire damage", "this effect is used when the weapon is loaded but fired while overheated", &blofeld::halo1::damage_effect_reference },
		{ _field_tag_reference, "empty damage", "this effect is used when the weapon is not loaded", &blofeld::halo1::damage_effect_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(
		magazines,
		"magazines",
		2,
		"s_magazines",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_long_flags, "flags", &blofeld::halo1::unnamed_enum$61 },
		{ _field_short_integer, "rounds recharged", nullptr, "per second" },
		{ _field_short_integer, "rounds total initial" },
		{ _field_short_integer, "rounds total maximum" },
		{ _field_short_integer, "rounds loaded maximum" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "reload time", "the length of time it takes to load a single magazine into the weapon", "seconds" },
		{ _field_short_integer, "rounds reloaded" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "chamber time", "the length of time it takes to chamber the next round", "seconds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 8),
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 16),
		{ _field_tag_reference, "reloading effect", &blofeld::halo1::sound_effect_reference },
		{ _field_tag_reference, "chambering effect", &blofeld::halo1::sound_effect_reference },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_block, "magazines", &blofeld::halo1::magazine_objects },
		{ _field_terminator }
	};

	STRINGS(unnamed_enum$61)
	{
		"wastes rounds when reloaded",
		"every round must be chambered"
	};
	STRING_LIST(unnamed_enum$61, unnamed_enum$61_strings, _countof(unnamed_enum$61_strings));

	TAG_BLOCK(
		magazine_objects,
		"magazine_objects",
		8,
		"s_magazine_objects",
		SET_DEFAULT,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PERSISTENT_ID_UNKNOWN)
	{
		{ _field_short_integer, "rounds" },
		FIELD_PAD_EX("value", nullptr, FIELD_FLAG_NONE, 10),
		{ _field_tag_reference, "equipment", &blofeld::halo1::equipment_reference },
		{ _field_terminator }
	};



} // namespace blofeld

} // namespace halo1

