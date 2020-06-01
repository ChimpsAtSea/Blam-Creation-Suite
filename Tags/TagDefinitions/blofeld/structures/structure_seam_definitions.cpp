#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(structure_seams, STRUCTURE_SEAMS_TAG, structure_seams_block_block );

	TAG_BLOCK(structure_seam_edge_mapping_block, k_structure_seam_maximum_edges_count)
	{
		{ _field_long_integer, "structure edge index*" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_cluster_mapping_block, k_structure_seam_maximum_clusters_on_seam_count)
	{
		{ _field_long_integer, "cluster_index*" },
		{ _field_real_point_3d, "cluster center*" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_mapping_block, k_structure_seam_maximum_seam_count)
	{
		{ _field_struct, "seams identifier*!", &structure_seam_identifier_struct_struct_definition },
		{ _field_block, "edge mapping*", &structure_seam_edge_mapping_block_block },
		{ _field_block, "cluster mapping*", &structure_seam_cluster_mapping_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_original_vertex_plane_normals_block, 1024)
	{
		{ _field_real_vector_3d, "triangle normal*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_original_vertex_block, k_structure_seam_maximum_points_count)
	{
		{ _field_real_point_3d, "original vertex*!" },
		{ _field_long_integer, "final point index*!" },
		{ _field_block, "plane normals*", &structure_seam_original_vertex_plane_normals_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_final_planes_block, k_structure_seam_maximum_planes_count)
	{
		{ _field_real_plane_3d, "plane*" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_final_points_block, k_structure_seam_maximum_points_count)
	{
		{ _field_real_point_3d, "final point*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_final_triangles_block, k_structure_seam_maximum_triangles_count)
	{
		{ _field_long_integer, "final plane*!" },
		{ _field_short_block_index, "final point0*!" },
		{ _field_short_block_index, "final point1*!" },
		{ _field_short_block_index, "final point2*!" },
		{ _field_pad, "pad0", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_final_edges_block, k_structure_seam_maximum_edges_count)
	{
		{ _field_short_block_index, "final point0*!" },
		{ _field_short_block_index, "final point1*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(structure_seam_block, k_structure_seam_maximum_seam_count)
	{
		{ _field_struct, "identifier*!", &structure_seam_identifier_struct_struct_definition },
		{ _field_struct, "original*!", &structure_seam_original_geometry_struct_struct_definition },
		{ _field_struct, "final*!", &structure_seam_final_geometry_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(structure_seams_block, 1, structure_seams_struct_definition_struct_definition );

	TAG_STRUCT(structure_seam_identifier_struct)
	{
		{ _field_long_integer, "seam_id0*!" },
		{ _field_long_integer, "seam_id1*!" },
		{ _field_long_integer, "seam_id2*!" },
		{ _field_long_integer, "seam_id3*!" },
		{ _field_terminator }
	};

	TAG_STRUCT(structure_seams_struct_definition)
	{
		{ _field_struct, "structure manifest*", &structure_manifest_struct_struct_definition },
		{ _field_explanation, "This tag defines the geometry between seam connected structures bsp.", "" },
		{ _field_long_integer, "version*!" },
		{ _field_block, "errors*!", &global_error_report_categories_block_block },
		{ _field_block, "seams*!", &structure_seam_block_block },
		{ _field_block, "seam triangle mopp code block!*", &mopp_code_definition_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(structure_seam_original_geometry_struct)
	{
		{ _field_block, "original vertices*!", &structure_seam_original_vertex_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(structure_seam_final_geometry_struct)
	{
		{ _field_block, "planes*!", &structure_seam_final_planes_block_block },
		{ _field_block, "points*!", &structure_seam_final_points_block_block },
		{ _field_block, "triangles*!", &structure_seam_final_triangles_block_block },
		{ _field_block, "edges*!", &structure_seam_final_edges_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

