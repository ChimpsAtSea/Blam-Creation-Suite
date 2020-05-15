#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(camera_track_control_point, k_maximum_number_of_camera_track_control_points)
{
	{ _field_real_vector_3d, "position" },
	{ _field_real_quaternion, "orientation" },
	{ _field_useless_pad },
	{ _field_terminator },
};

TAG_GROUP(camera_track, CAMERA_TRACK_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_block, "control points", &camera_track_control_point_block },
	{ _field_useless_pad },
	{ _field_terminator },
};

} // namespace blofeld

