#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		scenario_interpolator_group,
		SCENARIO_INTERPOLATOR_TAG,
		nullptr,
		INVALID_TAG,
		scenario_interpolator_block );

	TAG_BLOCK_FROM_STRUCT(
		scenario_interpolator_block,
		"scenario_interpolator_block",
		1,
		scenario_interpolator_struct_definition);

	#define SCENARIO_INTERPOLATOR_DATA_BLOCK_ID { 0x2FA4AF3D, 0x658E4C1D, 0x8B561159, 0xEE9A1051 }
	TAG_BLOCK(
		scenario_interpolator_data_block,
		"scenario_interpolator_data_block",
		k_maximum_interpolators_per_scenario,
		"s_scenario_interpolator_entry_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_INTERPOLATOR_DATA_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &scenario_interpolator_flags },
		FIELD_PAD("SCBP1", nullptr, 2),
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_struct, "function", &scalar_function_named_struct },
		{ _field_real, "duration", nullptr, "seconds" },
		{ _field_long_enum, "map reset type", &scenario_interpolator_reset_value_enum },
		{ _field_real_fraction, "custom map reset value" },
		{ _field_long_enum, "start type", &scenario_interpolator_start_value_enum },
		{ _field_long_enum, "stop type", &scenario_interpolator_stop_value_enum },
		{ _field_real_fraction, "custom stop value" },
		{ _field_terminator }
	};

	#define SCENARIO_INTERPOLATOR_STRUCT_DEFINITION_ID { 0x8A877FF6, 0xEA794454, 0x853A9148, 0x53A71CCF }
	TAG_STRUCT(
		scenario_interpolator_struct_definition,
		"scenario_interpolator_struct_definition",
		"s_scenario_interpolator_tag_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_INTERPOLATOR_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "interpolators", &scenario_interpolator_data_block },
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

} // namespace macaque

} // namespace blofeld

