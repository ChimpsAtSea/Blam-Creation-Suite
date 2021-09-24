#pragma once

namespace blofeld
{



	constexpr unsigned long UNIT_TAG = 'unit';
	extern s_tag_group unit_group; // unit_block

	extern s_tag_block_definition hud_screen_reference_block;
	extern s_tag_struct_definition hud_screen_reference_block_struct_definition;

	extern s_tag_block_definition unit_block;
	extern s_tag_block_definition unit_screen_effect_block;
	extern s_tag_struct_definition unit_screen_effect_block_struct_definition; // unit_screen_effect_block
	extern s_tag_block_definition unit_camera_track_block;
	extern s_tag_struct_definition unit_camera_track_block_struct_definition; // unit_camera_track_block
	extern s_tag_block_definition unit_camera_acceleration_displacement_block;
	extern s_tag_struct_definition unit_camera_acceleration_displacement_block_struct_definition; // unit_camera_acceleration_displacement_block
	extern s_tag_block_definition WeaponSpecificMarkersBlock_block;
	extern s_tag_struct_definition WeaponSpecificMarkersBlock_block_struct_definition; // WeaponSpecificMarkersBlock_block
	extern s_tag_block_definition unit_postures_block;
	extern s_tag_struct_definition unit_postures_block_struct_definition; // unit_postures_block
	extern s_tag_block_definition dialogue_variant_block;
	extern s_tag_struct_definition dialogue_variant_block_struct_definition; // dialogue_variant_block
	extern s_tag_block_definition powered_seat_block;
	extern s_tag_struct_definition powered_seat_block_struct_definition; // powered_seat_block
	extern s_tag_block_definition unit_weapon_block;
	extern s_tag_struct_definition unit_weapon_block_struct_definition; // unit_weapon_block
	extern s_tag_block_definition SentryPropertiesBlock_block;
	extern s_tag_struct_definition SentryPropertiesBlock_block_struct_definition; // SentryPropertiesBlock_block
	extern s_tag_block_definition unit_seat_block;
	extern s_tag_struct_definition unit_seat_block_struct_definition; // unit_seat_block
	extern s_tag_block_definition boarding_seat_block;
	extern s_tag_struct_definition boarding_seat_block_struct_definition; // boarding_seat_block

	extern s_tag_struct_definition unit_struct_definition; // tag group
	extern s_tag_struct_definition unit_camera_struct;

	extern s_tag_block_definition halo3_unit_camera_struct_unknown_block; // unkknown
	extern s_tag_struct_definition halo3_unit_camera_struct_unknown_block_struct_definition; // unknown

	extern s_tag_struct_definition unit_camera_acceleration_displacement_function_struct;
	extern s_tag_struct_definition unit_additional_node_names_struct;
	extern s_tag_struct_definition unit_boarding_melee_struct;
	extern s_tag_struct_definition unit_boost_struct;
	extern s_tag_struct_definition unit_lipsync_scales_struct;
	extern s_tag_struct_definition unit_birth_struct;

	extern s_string_list_definition unit_camera_acceleration_displacement_input;
	extern s_string_list_definition unit_camera_flags_definition;
	extern s_string_list_definition unit_seat_flags;
	extern s_string_list_definition unit_seat_secondary_flags;
	extern s_string_list_definition global_ai_seat_type_enum;
	extern s_string_list_definition initial_weapon_position;
	extern s_string_list_definition sentryTurretBehaviorFlagDefinition;
	extern s_string_list_definition unit_flags_part1;
	extern s_string_list_definition unit_flags_part2;
	extern s_string_list_definition unit_default_teams$2;
	extern s_string_list_definition boost_flags;
	extern s_string_list_definition unit_item_owner_size_enum;

	extern s_tag_reference_definition integrated_light_toggle_reference; // #CUSTOM
	extern s_tag_reference_definition unit_hud_interface_reference; // #CUSTOM
	extern s_tag_block_definition unit_hud_interfaces_block; // #CUSTOM
	extern s_tag_struct_definition unit_hud_interfaces_block_struct_definition; // #CUSTOM

} // namespace blofeld

