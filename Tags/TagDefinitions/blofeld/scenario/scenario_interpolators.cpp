#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(scenario_interpolator, SCENARIO_INTERPOLATOR_TAG, scenario_interpolator_block_block );

	TAG_BLOCK(scenario_interpolator_data_block, k_maximum_interpolators_per_scenario)
	{
		{ _field_word_flags, "flags", &scenario_interpolator_flags },
		{ _field_pad, "SCBP1", 2 },
		{ _field_string_id, "name^" },
		{ _field_struct, "function", &scalar_function_named_struct_struct_definition },
		{ _field_real, "duration:seconds" },
		{ _field_long_enum, "map reset type", &scenario_interpolator_reset_value_enum },
		{ _field_real_fraction, "custom map reset value" },
		{ _field_long_enum, "start type", &scenario_interpolator_start_value_enum },
		{ _field_long_enum, "stop type", &scenario_interpolator_stop_value_enum },
		{ _field_real_fraction, "custom stop value" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(scenario_interpolator_block, 1, scenario_interpolator_struct_definition_struct_definition );

	TAG_STRUCT(scenario_interpolator_struct_definition)
	{
		{ _field_block, "interpolators", &scenario_interpolator_data_block_block },
		{ _field_terminator }
	};

	STRINGS(scenario_interpolator_reset_value_enum)
	{
		"initial",
		"ending",
		"custom"
	};
	STRING_LIST(scenario_interpolator_reset_value_enum, scenario_interpolator_reset_value_enum_strings, _countof(scenario_interpolator_reset_value_enum_strings));

	STRINGS(scenario_interpolator_start_value_enum)
	{
		"initial",
		"unchanged"
	};
	STRING_LIST(scenario_interpolator_start_value_enum, scenario_interpolator_start_value_enum_strings, _countof(scenario_interpolator_start_value_enum_strings));

	STRINGS(scenario_interpolator_stop_value_enum)
	{
		"initial",
		"hold",
		"ending",
		"custom"
	};
	STRING_LIST(scenario_interpolator_stop_value_enum, scenario_interpolator_stop_value_enum_strings, _countof(scenario_interpolator_stop_value_enum_strings));

	STRINGS(scenario_interpolator_flags)
	{
		"loops#will continue to play until stopped.  if checked, no wrap should also be checked",
		"always active#will be started when the map loads.  good for looping interpolators"
	};
	STRING_LIST(scenario_interpolator_flags, scenario_interpolator_flags_strings, _countof(scenario_interpolator_flags_strings));

	TAG_REFERENCE(global_scenario_interpolator_reference, SCENARIO_INTERPOLATOR_TAG);

} // namespace blofeld

