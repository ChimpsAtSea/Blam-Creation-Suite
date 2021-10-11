#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		structure_seams_group,
		STRUCTURE_SEAMS_TAG,
		nullptr,
		INVALID_TAG,
		structure_seams_block );

	TAG_BLOCK_FROM_STRUCT(
		structure_seams_block,
		"structure_seams_block",
		1,
		structure_seams_struct_definition);

	#define STRUCTURE_SEAM_MAPPING_BLOCK_ID { 0xB9EF902E, 0xE89545BC, 0xABE91A74, 0x40C7C1A5 }
	TAG_BLOCK(
		structure_seam_mapping_block,
		"structure_seam_mapping_block",
		k_structure_seam_maximum_seam_count,
		"s_structure_seam_mapping",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_MAPPING_BLOCK_ID)
	{
		{ _field_struct, "seams identifier", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_identifier_struct },
		{ _field_block, "edge mapping", FIELD_FLAG_READ_ONLY, &structure_seam_edge_mapping_block },
		{ _field_block, "cluster mapping", FIELD_FLAG_READ_ONLY, &structure_seam_cluster_mapping_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_EDGE_MAPPING_BLOCK_ID { 0x758F902F, 0x67CC4351, 0x9A174FC4, 0x0590C91F }
	TAG_BLOCK(
		structure_seam_edge_mapping_block,
		"structure_seam_edge_mapping_block",
		k_structure_seam_maximum_edges_count,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_EDGE_MAPPING_BLOCK_ID)
	{
		{ _field_long_integer, "structure edge index", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_CLUSTER_MAPPING_BLOCK_ID { 0xE1A86C0A, 0x487745EF, 0x922F5821, 0x3E39C08A }
	TAG_BLOCK(
		structure_seam_cluster_mapping_block,
		"structure_seam_cluster_mapping_block",
		k_structure_seam_maximum_clusters_on_seam_count,
		"s_structure_seam_cluster_mapping",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_CLUSTER_MAPPING_BLOCK_ID)
	{
		{ _field_long_integer, "cluster_index", FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "cluster center", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_BLOCK_ID { 0x71952903, 0x695E49A5, 0x85CD305E, 0x57868F0C }
	TAG_BLOCK(
		structure_seam_block,
		"structure_seam_block",
		k_structure_seam_maximum_seam_count,
		"s_structure_seam",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_BLOCK_ID)
	{
		{ _field_struct, "identifier", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_identifier_struct },
		{ _field_struct, "original", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_original_geometry_struct },
		{ _field_struct, "final", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_geometry_struct },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_ORIGINAL_VERTEX_BLOCK_ID { 0x1C23A365, 0x182E4449, 0x9EB71083, 0x6091788A }
	TAG_BLOCK(
		structure_seam_original_vertex_block,
		"structure_seam_original_vertex_block",
		k_structure_seam_maximum_points_count,
		"s_structure_seam_original_vertex",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_ORIGINAL_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "original vertex", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "final point index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_block, "plane normals", FIELD_FLAG_READ_ONLY, &structure_seam_original_vertex_plane_normals_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_ORIGINAL_VERTEX_PLANE_NORMALS_BLOCK_ID { 0x1C23AABC, 0x11234449, 0x9EAB1083, 0x09170D8A }
	TAG_BLOCK(
		structure_seam_original_vertex_plane_normals_block,
		"structure_seam_original_vertex_plane_normals_block",
		1024,
		"real_vector3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_ORIGINAL_VERTEX_PLANE_NORMALS_BLOCK_ID)
	{
		{ _field_real_vector_3d, "triangle normal", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_FINAL_PLANES_BLOCK_ID { 0x9D8D76FA, 0xC55D4D57, 0xBE1E8C92, 0x39DC68A8 }
	TAG_BLOCK(
		structure_seam_final_planes_block,
		"structure_seam_final_planes_block",
		k_structure_seam_maximum_planes_count,
		"real_plane3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_FINAL_PLANES_BLOCK_ID)
	{
		{ _field_real_plane_3d, "plane", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_FINAL_POINTS_BLOCK_ID { 0xD88A3DB6, 0x83704955, 0xB4012152, 0x3E69CCA7 }
	TAG_BLOCK(
		structure_seam_final_points_block,
		"structure_seam_final_points_block",
		k_structure_seam_maximum_points_count,
		"real_point3d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_FINAL_POINTS_BLOCK_ID)
	{
		{ _field_real_point_3d, "final point", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_FINAL_TRIANGLES_BLOCK_ID { 0xFA685DE8, 0xA9BF4914, 0xB6C3D98E, 0x0C4B0CED }
	TAG_BLOCK(
		structure_seam_final_triangles_block,
		"structure_seam_final_triangles_block",
		k_structure_seam_maximum_triangles_count,
		"s_structure_seam_final_triangle",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_FINAL_TRIANGLES_BLOCK_ID)
	{
		{ _field_long_integer, "final plane", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "final point0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_points_block },
		{ _field_short_block_index, "final point1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_points_block },
		{ _field_short_block_index, "final point2", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_points_block },
		FIELD_PAD_EX("pad0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_FINAL_EDGES_BLOCK_ID { 0x5CE6FC51, 0x55D54CD5, 0x8B04C24C, 0x116945CA }
	TAG_BLOCK(
		structure_seam_final_edges_block,
		"structure_seam_final_edges_block",
		k_structure_seam_maximum_edges_count,
		"s_structure_seam_final_edge",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_FINAL_EDGES_BLOCK_ID)
	{
		{ _field_short_block_index, "final point0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_points_block },
		{ _field_short_block_index, "final point1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_points_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAMS_STRUCT_DEFINITION_ID { 0x1073D9E0, 0x3D9447BB, 0x89E0B4FF, 0x30BD63B1 }
	TAG_STRUCT(
		structure_seams_struct_definition,
		"structure_seams_struct_definition",
		"s_structure_seams",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAMS_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "structure manifest", FIELD_FLAG_READ_ONLY, &structure_manifest_struct },
		FIELD_EXPLANATION_EX("This tag defines the geometry between seam connected structures bsp.", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_integer, "version", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_block, "errors", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_error_report_categories_block },
		{ _field_block, "seams", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_block },
		{ _field_block, "seam triangle mopp code block", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &mopp_code_definition_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_IDENTIFIER_STRUCT_ID { 0xDDF67371, 0xDF8642BF, 0xAC893004, 0xBC6869EC }
	TAG_STRUCT(
		structure_seam_identifier_struct,
		"structure_seam_identifier_struct",
		"s_structure_seam_identifier",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_IDENTIFIER_STRUCT_ID)
	{
		{ _field_long_integer, "seam_id0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "seam_id1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "seam_id2", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "seam_id3", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_ORIGINAL_GEOMETRY_STRUCT_ID { 0x94C5DB45, 0x5F934BF3, 0xA02C2890, 0x4C76F360 }
	TAG_STRUCT(
		structure_seam_original_geometry_struct,
		"structure_seam_original_geometry_struct",
		"s_structure_seam_original_geometry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_ORIGINAL_GEOMETRY_STRUCT_ID)
	{
		{ _field_block, "original vertices", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_original_vertex_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SEAM_FINAL_GEOMETRY_STRUCT_ID { 0x89A4CF05, 0x884A4959, 0xB0830D92, 0x161B070E }
	TAG_STRUCT(
		structure_seam_final_geometry_struct,
		"structure_seam_final_geometry_struct",
		"s_structure_seam_final_geometry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_SEAM_FINAL_GEOMETRY_STRUCT_ID)
	{
		{ _field_block, "planes", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_planes_block },
		{ _field_block, "points", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_points_block },
		{ _field_block, "triangles", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_triangles_block },
		{ _field_block, "edges", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &structure_seam_final_edges_block },
		{ _field_terminator }
	};



} // namespace blofeld

