#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_scenario_load_parameters, k_scenario_load_maximum_parameter_blocks)
{
	{ _field_explanation, "SCENARIO LOAD PARAMETERS" },
	{ _field_tag_reference, "scenario^" },
	{ _field_data, "parameters" },
	{ _field_pad, "BDZDSK", 32 },
	{ _field_terminator },
};

} // namespace blofeld

