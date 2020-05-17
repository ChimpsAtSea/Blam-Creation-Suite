#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_STRUCT(boat_physics_definition_struct)
	{
		FIELD( _field_explanation, "water hull physics" ),
		FIELD( _field_real, "ground vertical extrusion#for hull surfaces that drive on ground this is how far we pretend the water is above everything physical" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

