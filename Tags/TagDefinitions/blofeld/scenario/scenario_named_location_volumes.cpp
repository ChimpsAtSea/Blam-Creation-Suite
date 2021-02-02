#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(named_location_volume_point_block, k_maximum_points_per_sector)
	{
		{ _field_legacy, _field_real_point_3d, "position" },
		{ _field_legacy, _field_real_euler_angles_2d, "normal" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_named_location_volume_block, s_scenario_named_location_volume::k_maximum_scenario_named_location_volumes)
	{
		{ _field_legacy, _field_block, "points", &named_location_volume_point_block_block },
		{ _field_legacy, _field_real, "height" },
		{ _field_legacy, _field_real, "sink" },
		{ _field_legacy, _field_string_id, "location name^" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

