#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_atmosphere_dumpling, s_scenario_atmosphere_dumpling::k_maximum_scenario_atmosphere_dumplings)
{
	{ _field_struct, "dumpling" },
	{ _field_short_block_index, "atmosphere" },
	{ _field_pad, "pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_weather_dumpling, s_scenario_weather_dumpling::k_maximum_scenario_weather_dumplings)
{
	{ _field_struct, "dumpling" },
	{ _field_short_block_index, "weather" },
	{ _field_pad, "pad", 2 },
	{ _field_terminator },
};

} // namespace blofeld

