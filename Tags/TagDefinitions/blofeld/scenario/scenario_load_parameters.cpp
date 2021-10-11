#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define GLOBAL_SCENARIO_LOAD_PARAMETERS_BLOCK_ID { 0x4B6AED51, 0xF0454236, 0x871E52C4, 0xA013780C }
	TAG_BLOCK(
		global_scenario_load_parameters_block,
		"scenario load parameters",
		k_scenario_load_maximum_parameter_blocks,
		"s_scenario_load_parameters",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_SCENARIO_LOAD_PARAMETERS_BLOCK_ID)
	{
		FIELD_EXPLANATION_EX("SCENARIO LOAD PARAMETERS", nullptr, FIELD_FLAG_NONE, "strip-variant <variant-name>\nstrips a given variant out of the model tag\nstrip-dialogue\nstrips all the dialogue for this model i.e. cinematic only"),
		{ _field_tag_reference, "scenario", FIELD_FLAG_INDEX, &scenario_reference$2 },
		{ _field_data, "parameters" },
		FIELD_PAD_EX("BDZDSK", nullptr, FIELD_FLAG_NONE, 32),
		{ _field_terminator }
	};



} // namespace blofeld

