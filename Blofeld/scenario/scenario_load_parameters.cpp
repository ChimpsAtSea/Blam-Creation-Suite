#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_scenario_load_parameters_block, k_scenario_load_maximum_parameter_blocks)
{
	FIELD( _field_explanation, "SCENARIO LOAD PARAMETERS" ),
	FIELD( _field_tag_reference, "scenario^" ),
	FIELD( _field_data, "parameters" ),
	FIELD( _field_pad, "BDZDSK", 32 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

