#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_STRUCT(camera_obstruction_struct)
	{
		FIELD( _field_real_fraction, "cylinder fraction#controls how far from the focus point the outer raycasts start.  0 == cone, 1 == cylinder" ),
		FIELD( _field_angle, "obstruction test angle:degrees#how wide of a cone to test" ),
		FIELD( _field_real, "obstruction max inward accel:1.0/s/s#how quickly the camera moves inward when it anticipates a collision" ),
		FIELD( _field_real, "obstruction max outward accel:1.0/s/s#how quickly the camera returns to a normal position when its anticipated distance is further than its current" ),
		FIELD( _field_real, "obstruction max velocity:1.0/s#maximum speed the camera can move" ),
		FIELD( _field_real, "obstruction return delay:s#when the camera wants to start moving back out, wait this long before doing so" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

