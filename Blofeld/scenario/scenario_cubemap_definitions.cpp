#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_cluster_cubemap, k_max_cubemaps_per_cluster)
{
	{ _field_short_integer, "scenario cubemap index" },
	{ _field_short_integer, "cubemap bitmap index" },
	{ _field_block, "reference points", &cubemap_reference_points_block },
	{ _field_terminator },
};

TAG_BLOCK(cubemap_reference_points, k_max_cubemap_reference_point_count)
{
	{ _field_real_point_3d, "reference point" },
	{ _field_long_integer, "point index!" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cubemap, k_max_cubemaps_per_scenario)
{
	{ _field_custom },
	{ _field_string_id, "name" },
	{ _field_real_point_3d, "cubemap position" },
	{ _field_enum, "cubemap resolution" },
	{ _field_pad, "post-cubemap-resolution-pad", 2 },
	{ _field_explanation, "bsps it could belong to" },
	{ _field_struct, "manual bsp flags" },
	{ _field_block, "reference points", &cubemap_reference_points_block },
	{ _field_terminator },
};

} // namespace blofeld

