#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_camera_impulse, 1)
{
	{ _field_custom },
	{ _field_struct, "mapping" },
	{ _field_terminator },
};

TAG_GROUP(camera_shake, CAMERA_SHAKE_TAG)
{
	{ _field_explanation, "camera impulse" },
	{ _field_struct, "camera impulse" },
	{ _field_explanation, "camera shake" },
	{ _field_struct, "camera shake" },
	{ _field_terminator },
};

} // namespace blofeld

