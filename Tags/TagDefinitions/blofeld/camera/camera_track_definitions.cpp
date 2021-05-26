#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		camera_track_group,
		CAMERA_TRACK_TAG,
		nullptr,
		INVALID_TAG,
		camera_track_block );

	TAG_BLOCK_FROM_STRUCT(
		camera_track_block,
		"camera_track_block",
		1,
		camera_track_struct_definition);

	#define CAMERA_TRACK_CONTROL_POINT_BLOCK_ID { 0x549FEEF0, 0xCAD54130, 0x9685AB6F, 0x75D07A1F }
	TAG_BLOCK(
		camera_track_control_point_block,
		"camera_track_control_point_block",
		k_maximum_number_of_camera_track_control_points,
		"s_camera_track_control_point",
		SET_UNKNOWN4 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_TRACK_CONTROL_POINT_BLOCK_ID)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_real_quaternion, "orientation" },
		{ _field_useless_pad, "" },
		{ _field_terminator }
	};

	#define CAMERA_TRACK_STRUCT_DEFINITION_ID { 0x3215F817, 0x264E4A98, 0x8165BFA1, 0xAACA3E6F }
	TAG_STRUCT(
		camera_track_struct_definition,
		"camera_track_struct_definition",
		"s_camera_track_definition",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CAMERA_TRACK_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &camera_track_flags },
		{ _field_block, "control points", &camera_track_control_point_block },
		{ _field_useless_pad, "" },
		{ _field_terminator }
	};

	STRING_LIST(camera_track_flags, empty_string_list, 0);

	TAG_REFERENCE(global_camera_track_reference, CAMERA_TRACK_TAG);



} // namespace blofeld

