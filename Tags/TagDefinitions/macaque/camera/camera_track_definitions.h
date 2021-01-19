#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long CAMERA_TRACK_TAG = 'trak';
	extern s_tag_group camera_track_group; // camera_track_block


	extern s_tag_block_definition camera_track_block;
	extern s_tag_block_definition camera_track_control_point_block;
	extern s_tag_struct_definition camera_track_control_point_block_struct_definition; // camera_track_control_point_block

	extern s_tag_struct_definition camera_track_struct_definition; // tag group

	extern c_versioned_string_list camera_track_flags_strings;
	extern s_string_list_definition camera_track_flags;

	extern s_tag_reference_definition global_camera_track_reference;

} // namespace macaque

} // namespace blofeld

