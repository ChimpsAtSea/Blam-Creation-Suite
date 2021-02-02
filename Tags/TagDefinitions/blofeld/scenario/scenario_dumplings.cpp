#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(dumpling_point_block, k_maximum_points_per_sector)
	{
		{ _field_legacy, _field_real_point_3d, "position" },
		{ _field_legacy, _field_real_euler_angles_2d, "normal" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_atmosphere_dumpling_block, s_scenario_atmosphere_dumpling::k_maximum_scenario_atmosphere_dumplings)
	{
		{ _field_legacy, _field_struct, "dumpling", &scenario_dumpling_struct_struct_definition },
		{ _field_legacy, _field_short_block_index, "atmosphere" },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_weather_dumpling_block, s_scenario_weather_dumpling::k_maximum_scenario_weather_dumplings)
	{
		{ _field_legacy, _field_struct, "dumpling", &scenario_dumpling_struct_struct_definition },
		{ _field_legacy, _field_short_block_index, "weather" },
		{ _field_legacy, _field_pad, "pad", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(scenario_dumpling_struct)
	{
		{ _field_legacy, _field_block, "inner points", &dumpling_point_block_block },
		{ _field_legacy, _field_block, "outer points", &dumpling_point_block_block },
		{ _field_legacy, _field_real, "height" },
		{ _field_legacy, _field_real, "sink" },
		{ _field_legacy, _field_real, "inner value" },
		{ _field_legacy, _field_real, "outer value" },
		{ _field_legacy, _field_real_point_3d, "center point!" },
		{ _field_legacy, _field_real, "trivial cull radius squared!" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

