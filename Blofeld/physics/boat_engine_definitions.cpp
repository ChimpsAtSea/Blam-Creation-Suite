#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(boat_engine_definition_block, 1)
	{
		{ _field_byte_flags, "flags", &boat_flags },
		{ _field_pad, "blah", 3 },
		{ _field_custom },
		{ _field_string_id, "propeller marker name" },
		{ _field_real_fraction, "out of water thrust scale" },
		{ _field_real_fraction, "out of water torque scale" },
		{ _field_real, "propeller radius:wu#used to interpolate out-of-water thrust" },
		{ _field_real, "propeller torque scale#(fake physics mode only)\nScale value for pitch when thrusting" },
		{ _field_real, "reverse linear acceleration" },
		{ _field_real, "linear acceleration" },
		{ _field_real, "angular acceleration" },
		{ _field_explanation, "Stabilization" },
		{ _field_angle, "stabilization angular acceleration:deg/s/s#how quickly the boat can accelerate to the desired orientation" },
		{ _field_angle, "stabilization desired inclination:deg#how far pitched back the boat tries to achieve (0 is perfectly flat)" },
		{ _field_explanation, "drag" },
		{ _field_real, "drag input range velocity:wu/s" },
		{ _field_struct, "normal drag", &scalar_function_named_struct_struct_definition },
		{ _field_struct, "boost drag", &scalar_function_named_struct_struct_definition },
		{ _field_struct, "air drag", &scalar_function_named_struct_struct_definition },
		{ _field_terminator }
	};

	STRINGS(boat_flags$2)
	{
		"uses fake physics"
	};
	STRING_LIST(boat_flags$2, boat_flags$2_strings, _countof(boat_flags$2_strings));

} // namespace blofeld

