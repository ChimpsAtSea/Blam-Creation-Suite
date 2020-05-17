#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(camera_track, CAMERA_TRACK_TAG, camera_track_block_block );

	TAG_BLOCK(camera_track_control_point_block, k_maximum_number_of_camera_track_control_points)
	{
		FIELD( _field_real_vector_3d, "position" ),
		FIELD( _field_real_quaternion, "orientation" ),
		FIELD( _field_useless_pad ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(camera_track_block, 1, camera_track_struct_definition_struct_definition );

	TAG_STRUCT(camera_track_struct_definition)
	{
		FIELD( _field_long_flags, "flags", &camera_track_flags ),
		FIELD( _field_block, "control points", &camera_track_control_point_block_block ),
		FIELD( _field_useless_pad ),
		FIELD( _field_terminator )
	};

	TAG_ENUM_EMPTY(camera_track_flags, 0);

} // namespace blofeld

