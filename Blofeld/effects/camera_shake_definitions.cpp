#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_camera_impulse, 1)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "mapping" ),
	FIELD( _field_terminator )
};

TAG_GROUP(camera_shake, CAMERA_SHAKE_TAG)
{
	FIELD( _field_explanation, "camera impulse" ),
	FIELD( _field_struct, "camera impulse" ),
	FIELD( _field_explanation, "camera shake" ),
	FIELD( _field_struct, "camera shake" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

