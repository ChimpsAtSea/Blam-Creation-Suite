#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define SCENARIO_ATMOSPHERE_DUMPLING_BLOCK_ID { 0xD490A4DF, 0x4B7F4238, 0x8EC0F957, 0x0E68E2D6 }
	TAG_BLOCK(
		scenario_atmosphere_dumpling_block,
		"scenario_atmosphere_dumpling_block",
		s_scenario_atmosphere_dumpling::k_maximum_scenario_atmosphere_dumplings,
		"s_scenario_atmosphere_dumpling",
		SCENARIO_ATMOSPHERE_DUMPLING_BLOCK_ID)
	{
		{ _field_struct, "dumpling", &scenario_dumpling_struct },
		{ _field_short_block_index, "atmosphere", &scenario_atmosphere_palette_block },
		FIELD_PAD("pad", nullptr, 2),
		{ _field_terminator }
	};

	#define DUMPLING_POINT_BLOCK_ID { 0x5B797CB1, 0x9AAD4931, 0xA4D67F82, 0x3AE0B8EF }
	TAG_BLOCK(
		dumpling_point_block,
		"dumpling_point_block",
		k_maximum_points_per_sector,
		"s_dumpling_sector_point",
		DUMPLING_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_2d, "normal" },
		{ _field_terminator }
	};

	#define SCENARIO_WEATHER_DUMPLING_BLOCK_ID { 0x349A4BED, 0x672F4C73, 0xBF2F2635, 0x93364AFB }
	TAG_BLOCK(
		scenario_weather_dumpling_block,
		"scenario_weather_dumpling_block",
		s_scenario_weather_dumpling::k_maximum_scenario_weather_dumplings,
		"s_scenario_weather_dumpling",
		SCENARIO_WEATHER_DUMPLING_BLOCK_ID)
	{
		{ _field_struct, "dumpling", &scenario_dumpling_struct },
		{ _field_short_block_index, "weather", &scenario_weather_palette_block },
		FIELD_PAD("pad", nullptr, 2),
		{ _field_terminator }
	};

	#define SCENARIO_DUMPLING_STRUCT_ID { 0x2FF9A01B, 0xB3764EDA, 0xB70B64FE, 0x1E7F95AD }
	TAG_STRUCT(
		scenario_dumpling_struct,
		"scenario_dumpling_struct",
		"s_scenario_dumpling",
		SCENARIO_DUMPLING_STRUCT_ID)
	{
		{ _field_block, "inner points", &dumpling_point_block },
		{ _field_block, "outer points", &dumpling_point_block },
		{ _field_real, "height" },
		{ _field_real, "sink" },
		{ _field_real, "inner value" },
		{ _field_real, "outer value" },
		{ _field_real_point_3d, "center point" },
		{ _field_real, "trivial cull radius squared" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

