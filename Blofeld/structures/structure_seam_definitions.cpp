#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_seam_mapping, k_structure_seam_maximum_seam_count)
{
	FIELD( _field_struct, "seams identifier*!" ),
	FIELD( _field_block, "edge mapping*", &structure_seam_edge_mapping_block ),
	FIELD( _field_block, "cluster mapping*", &structure_seam_cluster_mapping_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_seam_edge_mapping, k_structure_seam_maximum_edges_count)
{
	FIELD( _field_long_integer, "structure edge index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_seam_cluster_mapping, k_structure_seam_maximum_clusters_on_seam_count)
{
	FIELD( _field_long_integer, "cluster_index*" ),
	FIELD( _field_real_point_3d, "cluster center*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_seam, k_structure_seam_maximum_seam_count)
{
	FIELD( _field_struct, "identifier*!" ),
	FIELD( _field_struct, "original*!" ),
	FIELD( _field_struct, "final*!" ),
	FIELD( _field_terminator )
};

TAG_GROUP(structure_seams, STRUCTURE_SEAMS_TAG)
{
	FIELD( _field_struct, "structure manifest*" ),
	FIELD( _field_explanation, "This tag defines the geometry between seam connected structures bsp." ),
	FIELD( _field_long_integer, "version*!" ),
	FIELD( _field_block, "errors*!", &global_error_report_categories_block ),
	FIELD( _field_block, "seams*!", &structure_seam_block ),
	FIELD( _field_block, "seam triangle mopp code block!*", &mopp_code_definition_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

