#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_cluster_cubemap, k_max_cubemaps_per_cluster)
{
	FIELD( _field_short_integer, "scenario cubemap index" ),
	FIELD( _field_short_integer, "cubemap bitmap index" ),
	FIELD( _field_block, "reference points", &cubemap_reference_points_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cubemap_reference_points, k_max_cubemap_reference_point_count)
{
	FIELD( _field_real_point_3d, "reference point" ),
	FIELD( _field_long_integer, "point index!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_cubemap, k_max_cubemaps_per_scenario)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "name" ),
	FIELD( _field_real_point_3d, "cubemap position" ),
	FIELD( _field_enum, "cubemap resolution" ),
	FIELD( _field_pad, "post-cubemap-resolution-pad", 2 ),
	FIELD( _field_explanation, "bsps it could belong to" ),
	FIELD( _field_struct, "manual bsp flags" ),
	FIELD( _field_block, "reference points", &cubemap_reference_points_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

