#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define CAMERA_OBSTRUCTION_STRUCT_ID { 0x3A9D370F, 0x57744B3B, 0x863CAE2F, 0x93F2A8CC }
	TAG_STRUCT(
		camera_obstruction_struct,
		"camera_obstruction_struct",
		"s_camera_obstruction_parameters",
		CAMERA_OBSTRUCTION_STRUCT_ID)
	{
		{ _field_real_fraction, "cylinder fraction", "controls how far from the focus point the outer raycasts start.  0 == cone, 1 == cylinder" },
		{ _field_angle, "obstruction test angle", "how wide of a cone to test", "degrees" },
		{ _field_real, "obstruction max inward accel", "how quickly the camera moves inward when it anticipates a collision", "1.0/s/s" },
		{ _field_real, "obstruction max outward accel", "how quickly the camera returns to a normal position when its anticipated distance is further than its current", "1.0/s/s" },
		{ _field_real, "obstruction max velocity", "maximum speed the camera can move", "1.0/s" },
		{ _field_real, "obstruction return delay", "when the camera wants to start moving back out, wait this long before doing so", "s" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

