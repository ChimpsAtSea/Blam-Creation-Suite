#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_seam_mapping, k_structure_seam_maximum_seam_count)
{
	{ _field_struct, "seams identifier*!" },
	{ _field_block, "edge mapping*", &structure_seam_edge_mapping_block },
	{ _field_block, "cluster mapping*", &structure_seam_cluster_mapping_block },
	{ _field_terminator },
};

TAG_BLOCK(structure_seam_edge_mapping, k_structure_seam_maximum_edges_count)
{
	{ _field_long_integer, "structure edge index*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_seam_cluster_mapping, k_structure_seam_maximum_clusters_on_seam_count)
{
	{ _field_long_integer, "cluster_index*" },
	{ _field_real_point_3d, "cluster center*" },
	{ _field_terminator },
};

TAG_BLOCK(structure_seam, k_structure_seam_maximum_seam_count)
{
	{ _field_struct, "identifier*!" },
	{ _field_struct, "original*!" },
	{ _field_struct, "final*!" },
	{ _field_terminator },
};

TAG_GROUP(structure_seams, STRUCTURE_SEAMS_TAG)
{
	{ _field_struct, "structure manifest*" },
	{ _field_explanation, "This tag defines the geometry between seam connected structures bsp." },
	{ _field_long_integer, "version*!" },
	{ _field_block, "errors*!", &global_error_report_categories_block },
	{ _field_block, "seams*!", &structure_seam_block },
	{ _field_block, "seam triangle mopp code block!*", &mopp_code_definition_block },
	{ _field_terminator },
};

} // namespace blofeld

