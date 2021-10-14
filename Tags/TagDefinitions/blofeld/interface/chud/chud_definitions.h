#pragma once

namespace blofeld
{
	constexpr unsigned long CHUD_ANIMATION_DEFINITION_TAG = 'chad';
	constexpr unsigned long CHUD_DEFINITION_TAG = 'chdt';
	constexpr unsigned long CHUD_GLOBALS_DEFINITION_TAG = 'chgd';

	extern s_tag_reference_definition unknown_reference;

	extern s_tag_group chud_animation_group;
	extern s_tag_struct_definition chad_struct_definition_struct_definition;
	extern s_tag_block_definition chad_block;
	extern s_tag_reference_definition chud_animation_reference;
	extern s_tag_block_definition chad_size_block;
	extern s_tag_block_definition chad_texture_coords_animation_block;
	extern s_tag_block_definition chad_color_block;
	extern s_tag_block_definition chad_position_animation_block;
	extern s_tag_block_definition chad_alpha_animation_block;
	extern s_tag_block_definition chad_rotation_animation_block;
	extern s_tag_block_definition chad_ammo_counter_block;
	extern s_tag_block_definition chad_color_animation_block;
	extern s_tag_block_definition chad_ammo_counter_boot_block;
	extern s_tag_block_definition chad_size_animation_block;
	extern s_tag_block_definition chad_position_block;
	extern s_tag_block_definition chad_rotation_block;
	extern s_tag_block_definition chad_alpha_block;
	extern s_tag_block_definition chad_texture_coords_block;

	extern s_tag_struct_definition chad_block_struct_definition;
	extern s_tag_struct_definition chad_size_block_struct_definition;
	extern s_tag_struct_definition chad_texture_coords_animation_block_struct_definition;
	extern s_tag_struct_definition chad_color_block_struct_definition;
	extern s_tag_struct_definition chad_position_animation_block_struct_definition;
	extern s_tag_struct_definition chad_alpha_animation_block_struct_definition;
	extern s_tag_struct_definition chad_rotation_animation_block_struct_definition;
	extern s_tag_struct_definition chad_ammo_counter_block_struct_definition;
	extern s_tag_struct_definition chad_color_animation_block_struct_definition;
	extern s_tag_struct_definition chad_ammo_counter_boot_block_struct_definition;
	extern s_tag_struct_definition chad_size_animation_block_struct_definition;
	extern s_tag_struct_definition chad_position_block_struct_definition;
	extern s_tag_struct_definition chad_rotation_block_struct_definition;
	extern s_tag_struct_definition chad_alpha_block_struct_definition;
	extern s_tag_struct_definition chad_texture_coords_block_struct_definition;

	extern s_tag_group chud_group;
	extern s_tag_struct_definition chud_struct_definition_struct_definition;
	extern s_tag_block_definition chud_block;
	extern s_tag_reference_definition chud_reference;
	extern s_tag_block_definition chdt_compiled_widget_data_block;
	extern s_tag_block_definition chdt_triggers_block;
	extern s_tag_block_definition chdt_yesno_states_block;
	extern s_tag_block_definition chdt_placement_data_block;
	extern s_tag_block_definition chdt_state_data_block;
	extern s_tag_block_definition chdt_animation_data_block;
	extern s_tag_block_definition chdt_render_data_block;
	extern s_tag_block_definition chdt_unknown_block;
	extern s_tag_block_definition chdt_datasource_block;
	extern s_tag_block_definition chdt_bitmap_widgets_block;
	extern s_tag_block_definition chdt_text_widgets_block;
	extern s_tag_block_definition chdt_hud_widgets_block;

	extern s_tag_struct_definition chud_block_struct_definition;
	extern s_tag_struct_definition chdt_compiled_widget_data_block_struct_definition;
	extern s_tag_struct_definition chdt_triggers_block_struct_definition;
	extern s_tag_struct_definition chdt_yesno_states_block_struct_definition;
	extern s_tag_struct_definition chdt_placement_data_block_struct_definition;
	extern s_tag_struct_definition chdt_state_data_block_struct_definition;
	extern s_tag_struct_definition chdt_animation_data_block_struct_definition;
	extern s_tag_struct_definition chdt_render_data_block_struct_definition;
	extern s_tag_struct_definition chdt_unknown_block_struct_definition;
	extern s_tag_struct_definition chdt_datasource_block_struct_definition;
	extern s_tag_struct_definition chdt_bitmap_widgets_block_struct_definition;
	extern s_tag_struct_definition chdt_text_widgets_block_struct_definition;
	extern s_tag_struct_definition chdt_hud_widgets_block_struct_definition;

	extern s_tag_group chud_globals_group;
	extern s_tag_struct_definition chgd_struct_definition_struct_definition;
	extern s_tag_block_definition chgd_block;
	extern s_tag_reference_definition chud_globals_reference;
	extern s_tag_block_definition chgd_hud_sounds_block;
	extern s_tag_block_definition chgd_hud_attributes_block;
	extern s_tag_block_definition chgd_hud_globals_block;
	extern s_tag_block_definition chgd_waypoint_blips_block;
	extern s_tag_block_definition chgd_shaders_block;
	extern s_tag_block_definition chgd_unknown_block;
	extern s_tag_block_definition chgd_player_training_data_block;
	extern s_tag_block_definition chgd_state_triggers_block;

	extern s_tag_struct_definition chgd_block_struct_definition;
	extern s_tag_struct_definition chgd_hud_sounds_block_struct_definition;
	extern s_tag_struct_definition chgd_hud_attributes_block_struct_definition;
	extern s_tag_struct_definition chgd_hud_globals_block_struct_definition;
	extern s_tag_struct_definition chgd_waypoint_blips_block_struct_definition;
	extern s_tag_struct_definition chgd_shaders_block_struct_definition;
	extern s_tag_struct_definition chgd_unknown_block_struct_definition;
	extern s_tag_struct_definition chgd_player_training_data_block_struct_definition;
	extern s_tag_struct_definition chgd_state_triggers_block_struct_definition;

	extern s_string_list_definition biped_enum_definition;
	extern s_string_list_definition resolution_flags_definition;
	extern s_string_list_definition latched_to_flags_definition;
	extern s_string_list_definition icon_enum_definition;
	extern s_string_list_definition player_training_flags_definition;

	extern s_string_list_definition chdt_special_hud_type_definition;
	extern s_string_list_definition chdt_input_definition;
	extern s_string_list_definition chdt_flag_definition;
	extern s_string_list_definition chdt_unknown_definition;
	extern s_string_list_definition chdt_anchor_definition;
	extern s_string_list_definition chdt_animation_function_definition;
	extern s_string_list_definition chdt_animation_flags_definition;
	extern s_string_list_definition chdt_shader_index_definition;
	extern s_string_list_definition chdt_output_color_definition;
	extern s_string_list_definition chdt_output_scalar_definition;
	extern s_string_list_definition chdt_flags_definition;
	extern s_string_list_definition chdt_render_data_flags_definition;
	extern s_string_list_definition chdt_font_definition;
	extern s_string_list_definition chdt_second_state_block_start_value_definition;
	extern s_string_list_definition chdt_input_variable_triggers_definition;
	extern s_string_list_definition chdt_input_variable_triggers2_definition;

	extern s_string_list_definition chad_flags_definition;

}

