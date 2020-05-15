#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_interpolator_data, k_maximum_interpolators_per_scenario)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "SCBP1", 2 },
	{ _field_string_id, "name^" },
	{ _field_struct, "function" },
	{ _field_real, "duration:seconds" },
	{ _field_long_enum, "map reset type" },
	{ _field_real_fraction, "custom map reset value" },
	{ _field_long_enum, "start type" },
	{ _field_long_enum, "stop type" },
	{ _field_real_fraction, "custom stop value" },
	{ _field_terminator },
};

TAG_GROUP(scenario_interpolator, SCENARIO_INTERPOLATOR_TAG)
{
	{ _field_block, "interpolators", &scenario_interpolator_data_block },
	{ _field_terminator },
};

} // namespace blofeld

