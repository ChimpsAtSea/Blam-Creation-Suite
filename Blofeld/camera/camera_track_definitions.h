#pragma once

namespace blofeld
{

	constexpr unsigned long CAMERA_TRACK_TAG = 'trak';

	extern s_tag_group camera_track_group;

	extern s_tag_struct_definition camera_track_control_point_block_block_struct;
	extern s_tag_block_definition camera_track_control_point_block_block;
	extern s_tag_block_definition camera_track_block_block;

	extern s_tag_struct_definition camera_track_struct_definition_struct_definition; // tag group

	extern const char* camera_track_flags_strings[];
	extern s_string_list_definition camera_track_flags;

	extern s_tag_reference_definition global_camera_track_reference;

} // namespace blofeld

