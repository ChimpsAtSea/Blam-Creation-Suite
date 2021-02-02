#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SCENARIO_NAMED_LOCATION_VOLUME_BLOCK_STRUCT_ID { 0x788095DE, 0x7C514271, 0xBB149679, 0x682095DA }
	TAG_BLOCK(
		scenario_named_location_volume_block,
		"scenario_named_location_volume_block",
		s_scenario_named_location_volume::k_maximum_scenario_named_location_volumes,
		"s_scenario_named_location_volume",
		SCENARIO_NAMED_LOCATION_VOLUME_BLOCK_STRUCT_ID)
	{
		{ _field_block, "points", &named_location_volume_point_block },
		{ _field_real, "height" },
		{ _field_real, "sink" },
		{ _field_string_id, "location name" },
		{ _field_terminator }
	};

	#define NAMED_LOCATION_VOLUME_POINT_BLOCK_ID { 0x93E2B78A, 0x31554713, 0x814F05D1, 0xE48C66BB }
	TAG_BLOCK(
		named_location_volume_point_block,
		"named_location_volume_point_block",
		k_maximum_points_per_sector,
		"s_real_sector_point",
		NAMED_LOCATION_VOLUME_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

