#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_named_location_volume, s_scenario_named_location_volume::k_maximum_scenario_named_location_volumes)
{
	FIELD( _field_block, "points", &named_location_volume_point_block ),
	FIELD( _field_real, "height" ),
	FIELD( _field_real, "sink" ),
	FIELD( _field_string_id, "location name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(named_location_volume_point, k_maximum_points_per_sector)
{
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_real_euler_angles_2d, "normal" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

