#pragma once

namespace blofeld
{



	constexpr unsigned long USER_INTERFACE_HUD_GLOBALS_DEFINITION_TAG = 'uihg';
	extern s_tag_group user_interface_hud_globals_definition_group; // user_interface_hud_globals_definition_block


	extern s_tag_block_definition user_interface_hud_globals_definition_block;

	extern s_tag_struct_definition screen_transform_basis_array_definition_array_struct_definition;
	extern s_tag_array_definition screen_transform_basis_array_definition_array;
	extern s_tag_struct_definition user_interface_hud_globals_definition_struct_definition; // tag group

	extern s_string_list_definition HUDMotionSensorGlobalsFlags;
	extern s_string_list_definition high_contrast_flags;



} // namespace blofeld

