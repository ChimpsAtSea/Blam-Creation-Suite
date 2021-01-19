#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long CAMERA_SHAKE_TAG = 'csdt';
	extern s_tag_group camera_shake_group; // camera_shake_block


	extern s_tag_block_definition camera_shake_block;
	extern s_tag_block_definition global_camera_impulse_block;
	extern s_tag_struct_definition global_camera_impulse_block_struct_definition; // global_camera_impulse_block

	extern s_tag_struct_definition camera_shake_struct_definition; // tag group
	extern s_tag_struct_definition camera_impulse_struct;
	extern s_tag_struct_definition camera_shake_struct;

	extern c_versioned_string_list animated_camera_shake_playback_type_enum_strings;
	extern s_string_list_definition animated_camera_shake_playback_type_enum;
	extern c_versioned_string_list animated_camera_shake_weight_type_enum_strings;
	extern s_string_list_definition animated_camera_shake_weight_type_enum;

	extern s_tag_reference_definition global_camera_shake_reference;

} // namespace macaque

} // namespace blofeld

