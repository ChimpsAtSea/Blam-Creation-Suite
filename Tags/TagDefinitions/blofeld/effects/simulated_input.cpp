#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(simulated_input, SIMULATED_INPUT_TAG, simulated_input_block_block );

	TAG_BLOCK_FROM_STRUCT(simulated_input_block, 1, simulated_input_struct_definition_struct_definition );

	TAG_STRUCT(simulated_input_struct_definition)
	{
		{ _field_explanation, "Simulated Input (SI)" },
		{ _field_explanation, "Impulse" },
		{ _field_explanation, "Scalers" },
		{ _field_explanation, "Screen Space angles" },
		{ _field_explanation, "Move" },
		{ _field_struct, "move", &simulated_input_stick_struct_struct_definition },
		{ _field_explanation, "Look" },
		{ _field_struct, "look", &simulated_input_stick_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(simulated_input_stick_struct)
	{
		{ _field_long_flags, "flags", &simulated_input_flags },
		{ _field_enum, "response type", &direction_type_enum_definition },
		{ _field_enum, "mapping type", &mapping_type_enum_definition },
		{ _field_real_bounds, "angle:degrees" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_real, "duration:seconds" },
		{ _field_real, "inverse duration:seconds#if >0.f, accumulated inpulse will be \'undone\' over the give time span" },
		{ _field_real, "inverse random length:percent#15.0 would randomly adjust length of accumulated impulse +/-15%" },
		{ _field_real_bounds, "inverse random angle:degrees#apply random adjustment to direction of accumulated impulse" },
		{ _field_real, "linear zoom penalty#linear multiplier of zoom that increases effect; computed for no change at zoom 1" },
		{ _field_real, "square root zoom penalty#multiplier to increase effect proportional to square root of zoom; computed for no change at zoom 1" },
		{ _field_terminator }
	};

	STRINGS(simulated_input_flags)
	{
		"ignore base scaler#Always start with 1.0 instead of any value from damage multiplier value",
		"ignore area control falloff#Skip this scaler",
		"ignore elapsed time function scaler#Skip this scaler",
		"ignore zoom scaler#Skip this scaler",
		"ignore tick_delta_secs scaler#Skip this scaler"
	};
	STRING_LIST(simulated_input_flags, simulated_input_flags_strings, _countof(simulated_input_flags_strings));

	STRINGS(direction_type_enum_definition)
	{
		"aim vector",
		"hit vector",
		"inverse hit vector",
		"attacker origin to victim origin",
		"victim origin to attacker origin"
	};
	STRING_LIST(direction_type_enum_definition, direction_type_enum_definition_strings, _countof(direction_type_enum_definition_strings));

	STRINGS(mapping_type_enum_definition)
	{
		"top down",
		"screen space"
	};
	STRING_LIST(mapping_type_enum_definition, mapping_type_enum_definition_strings, _countof(mapping_type_enum_definition_strings));

	TAG_REFERENCE(global_simulated_input_reference, SIMULATED_INPUT_TAG);

} // namespace blofeld

