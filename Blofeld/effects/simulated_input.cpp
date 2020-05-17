#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(simulated_input_flags, 5)
	{
		OPTION("ignore base scaler#Always start with 1.0 instead of any value from damage multiplier value"),
		OPTION("ignore area control falloff#Skip this scaler"),
		OPTION("ignore elapsed time function scaler#Skip this scaler"),
		OPTION("ignore zoom scaler#Skip this scaler"),
		OPTION("ignore tick_delta_secs scaler#Skip this scaler"),
	};

	TAG_ENUM(direction_type_enum_definition, 5)
	{
		OPTION("aim vector"),
		OPTION("hit vector"),
		OPTION("inverse hit vector"),
		OPTION("attacker origin to victim origin"),
		OPTION("victim origin to attacker origin"),
	};

	TAG_ENUM(mapping_type_enum_definition, 2)
	{
		OPTION("top down"),
		OPTION("screen space"),
	};

	TAG_GROUP_FROM_BLOCK(simulated_input, SIMULATED_INPUT_TAG, simulated_input_block_block );

	TAG_BLOCK_FROM_STRUCT(simulated_input_block, 1, simulated_input_struct_definition_struct_definition );

TAG_STRUCT(simulated_input_struct_definition)
{
		FIELD( _field_explanation, "Simulated Input (SI)" ),
		FIELD( _field_explanation, "Impulse" ),
		FIELD( _field_explanation, "Scalers" ),
		FIELD( _field_explanation, "Screen Space angles" ),
		FIELD( _field_explanation, "Move" ),
		FIELD( _field_struct, "move", &simulated_input_stick_struct_struct_definition ),
		FIELD( _field_explanation, "Look" ),
		FIELD( _field_struct, "look", &simulated_input_stick_struct_struct_definition ),
		FIELD( _field_terminator )
};

TAG_STRUCT(simulated_input_stick_struct)
{
		FIELD( _field_long_flags, "flags", &simulated_input_flags ),
		FIELD( _field_enum, "response type", &direction_type_enum_definition ),
		FIELD( _field_enum, "mapping type", &mapping_type_enum_definition ),
		FIELD( _field_real_bounds, "angle:degrees" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "duration:seconds" ),
		FIELD( _field_real, "inverse duration:seconds#if >0.f, accumulated inpulse will be \'undone\' over the give time span" ),
		FIELD( _field_real, "inverse random length:percent#15.0 would randomly adjust length of accumulated impulse +/-15%" ),
		FIELD( _field_real_bounds, "inverse random angle:degrees#apply random adjustment to direction of accumulated impulse" ),
		FIELD( _field_real, "linear zoom penalty#linear multiplier of zoom that increases effect; computed for no change at zoom 1" ),
		FIELD( _field_real, "square root zoom penalty#multiplier to increase effect proportional to square root of zoom; computed for no change at zoom 1" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

