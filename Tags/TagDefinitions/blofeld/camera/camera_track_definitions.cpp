#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(camera_track, CAMERA_TRACK_TAG, camera_track_block_block );

	TAG_BLOCK(camera_track_control_point_block, k_maximum_number_of_camera_track_control_points)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_real_quaternion, "orientation" },
		{ _field_useless_pad },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(camera_track_block, 1, camera_track_struct_definition_struct_definition );

	TAG_STRUCT(camera_track_struct_definition)
	{
		{ _field_long_flags, "flags", &camera_track_flags },
		{ _field_block, "control points", &camera_track_control_point_block_block },
		{ _field_useless_pad },
		{ _field_terminator }
	};

	STRING_LIST(camera_track_flags, empty_string_list, 0);

	TAG_REFERENCE(global_camera_track_reference, CAMERA_TRACK_TAG);

} // namespace blofeld

