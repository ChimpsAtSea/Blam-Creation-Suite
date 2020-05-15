#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_named_location_volume, s_scenario_named_location_volume::k_maximum_scenario_named_location_volumes)
{
	{ _field_block, "points", &named_location_volume_point_block },
	{ _field_real, "height" },
	{ _field_real, "sink" },
	{ _field_string_id, "location name^" },
	{ _field_terminator },
};

TAG_BLOCK(named_location_volume_point, k_maximum_points_per_sector)
{
	{ _field_real_point_3d, "position" },
	{ _field_real_euler_angles_2d, "normal" },
	{ _field_terminator },
};

} // namespace blofeld

