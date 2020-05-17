#pragma once

namespace blofeld
{

	extern const char* HUDMotionSensorGlobalsFlags_strings[];
	extern s_string_list_definition HUDMotionSensorGlobalsFlags;
	extern const char* high_contrast_flags_strings[];
	extern s_string_list_definition high_contrast_flags;

	constexpr unsigned long USER_INTERFACE_HUD_GLOBALS_DEFINITION_TAG = 'uihg';

	extern s_tag_group user_interface_hud_globals_definition_group;

	extern s_tag_block_definition user_interface_hud_globals_definition_block_block;

	extern s_tag_struct user_interface_hud_globals_definition_struct_definition_struct_definition; // tag group

} // namespace blofeld

