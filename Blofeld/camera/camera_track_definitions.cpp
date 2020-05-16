#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(camera_track_struct_definition)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_block, "control points", &camera_track_control_point_block ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

TAG_BLOCK(camera_track_control_point_block, k_maximum_number_of_camera_track_control_points)
{
	FIELD( _field_real_vector_3d, "position" ),
	FIELD( _field_real_quaternion, "orientation" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

TAG_GROUP(camera_track_block, CAMERA_TRACK_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_block, "control points", &camera_track_control_point_block ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

} // namespace blofeld

