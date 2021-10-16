#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define SCENARIO_ATMOSPHERE_DUMPLING_BLOCK_ID { 0xD490A4DF, 0x4B7F4238, 0x8EC0F957, 0x0E68E2D6 }
	TAG_BLOCK(
		scenario_atmosphere_dumpling_block,
		"scenario_atmosphere_dumpling_block",
		s_scenario_atmosphere_dumpling::k_maximum_scenario_atmosphere_dumplings,
		"s_scenario_atmosphere_dumpling",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_ATMOSPHERE_DUMPLING_BLOCK_ID)
	{
		{ _field_struct, "dumpling", &scenario_dumpling_struct },
		{ _field_short_block_index, "atmosphere", &scenario_atmosphere_palette_block },
		FIELD_PAD_EX("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define DUMPLING_POINT_BLOCK_ID { 0x5B797CB1, 0x9AAD4931, 0xA4D67F82, 0x3AE0B8EF }
	TAG_BLOCK(
		dumpling_point_block,
		"dumpling_point_block",
		k_maximum_points_per_sector,
		"s_dumpling_sector_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
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
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_WEATHER_DUMPLING_BLOCK_ID)
	{
		{ _field_struct, "dumpling", &scenario_dumpling_struct },
		{ _field_short_block_index, "weather", &scenario_weather_palette_block },
		FIELD_PAD_EX("pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define SCENARIO_DUMPLING_STRUCT_ID { 0x2FF9A01B, 0xB3764EDA, 0xB70B64FE, 0x1E7F95AD }
	TAG_STRUCT_V6(
		scenario_dumpling_struct,
		"scenario_dumpling_struct",
		"s_scenario_dumpling",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_DUMPLING_STRUCT_ID)
	{
		{ _field_block, "inner points", &dumpling_point_block },
		{ _field_block, "outer points", &dumpling_point_block },
		{ _field_real, "height" },
		{ _field_real, "sink" },
		{ _field_real, "inner value" },
		{ _field_real, "outer value" },
		{ _field_real_point_3d, "center point", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "trivial cull radius squared", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};



} // namespace blofeld

