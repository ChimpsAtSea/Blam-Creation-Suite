#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(global_scenario_load_parameters_block, k_scenario_load_maximum_parameter_blocks)
	{
		{ _field_explanation, "SCENARIO LOAD PARAMETERS", "strip-variant <variant-name>\nstrips a given variant out of the model tag\nstrip-dialogue\nstrips all the dialogue for this model i.e. cinematic only" },
		{ _field_tag_reference, "scenario^", &scenario_reference$2 },
		{ _field_data, "parameters" },
		{ _field_pad, "BDZDSK", 32 },
		{ _field_terminator }
	};

} // namespace blofeld

