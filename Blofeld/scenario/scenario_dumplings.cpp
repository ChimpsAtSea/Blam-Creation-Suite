#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(scenario_atmosphere_dumpling_block, s_scenario_atmosphere_dumpling::k_maximum_scenario_atmosphere_dumplings)
	{
		FIELD( _field_struct, "dumpling", &scenario_dumpling_struct_struct_definition ),
		FIELD( _field_short_block_index, "atmosphere" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(dumpling_point_block, k_maximum_points_per_sector)
	{
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_real_euler_angles_2d, "normal" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_weather_dumpling_block, s_scenario_weather_dumpling::k_maximum_scenario_weather_dumplings)
	{
		FIELD( _field_struct, "dumpling", &scenario_dumpling_struct_struct_definition ),
		FIELD( _field_short_block_index, "weather" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(scenario_dumpling_struct)
{
		FIELD( _field_block, "inner points", &dumpling_point_block_block ),
		FIELD( _field_block, "outer points", &dumpling_point_block_block ),
		FIELD( _field_real, "height" ),
		FIELD( _field_real, "sink" ),
		FIELD( _field_real, "inner value" ),
		FIELD( _field_real, "outer value" ),
		FIELD( _field_real_point_3d, "center point!" ),
		FIELD( _field_real, "trivial cull radius squared!" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

