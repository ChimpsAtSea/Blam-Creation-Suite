#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_STRUCT(boat_physics_definition_struct)
	{
		{ _field_legacy, _field_explanation, "water hull physics", "" },
		{ _field_legacy, _field_real, "ground vertical extrusion#for hull surfaces that drive on ground this is how far we pretend the water is above everything physical" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

