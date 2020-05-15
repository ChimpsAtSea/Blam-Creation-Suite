#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(simulated_input, SIMULATED_INPUT_TAG)
{
	FIELD( _field_explanation, "Simulated Input (SI)" ),
	FIELD( _field_explanation, "Impulse" ),
	FIELD( _field_explanation, "Scalers" ),
	FIELD( _field_explanation, "Screen Space angles" ),
	FIELD( _field_explanation, "Move" ),
	FIELD( _field_struct, "move" ),
	FIELD( _field_explanation, "Look" ),
	FIELD( _field_struct, "look" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

