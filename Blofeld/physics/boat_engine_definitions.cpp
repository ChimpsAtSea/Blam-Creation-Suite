#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(boat_flags$2, 1)
	{
		OPTION("uses fake physics"),
	};

	TAG_BLOCK(boat_engine_definition_block, 1)
	{
		FIELD( _field_byte_flags, "flags", &boat_flags ),
		FIELD( _field_pad, "blah", 3 ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "propeller marker name" ),
		FIELD( _field_real_fraction, "out of water thrust scale" ),
		FIELD( _field_real_fraction, "out of water torque scale" ),
		FIELD( _field_real, "propeller radius:wu#used to interpolate out-of-water thrust" ),
		FIELD( _field_real, "propeller torque scale#(fake physics mode only)\nScale value for pitch when thrusting" ),
		FIELD( _field_real, "reverse linear acceleration" ),
		FIELD( _field_real, "linear acceleration" ),
		FIELD( _field_real, "angular acceleration" ),
		FIELD( _field_explanation, "Stabilization" ),
		FIELD( _field_angle, "stabilization angular acceleration:deg/s/s#how quickly the boat can accelerate to the desired orientation" ),
		FIELD( _field_angle, "stabilization desired inclination:deg#how far pitched back the boat tries to achieve (0 is perfectly flat)" ),
		FIELD( _field_explanation, "drag" ),
		FIELD( _field_real, "drag input range velocity:wu/s" ),
		FIELD( _field_struct, "normal drag", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_struct, "boost drag", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_struct, "air drag", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

