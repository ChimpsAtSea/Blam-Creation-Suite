#pragma once

namespace blofeld
{

	constexpr unsigned long SQUAD_TEMPLATE_TAG = 'sqtm';

	extern s_tag_struct_definition squad_template_block_struct;
	extern s_tag_block_definition squad_template_block;
	extern s_tag_group squad_template_group;

	extern s_tag_struct_definition squad_groups_block_block_struct;
	extern s_tag_block_definition squad_groups_block_block;
	extern s_tag_struct_definition patrol_point_block_block_struct;
	extern s_tag_block_definition patrol_point_block_block;
	extern s_tag_struct_definition spawn_formation_block_block_struct;
	extern s_tag_block_definition spawn_formation_block_block;
	extern s_tag_struct_definition spawn_points_block_block_struct;
	extern s_tag_block_definition spawn_points_block_block;
	extern s_tag_struct_definition character_palette_choice_block_block_struct;
	extern s_tag_block_definition character_palette_choice_block_block;
	extern s_tag_struct_definition weapon_palette_choice_block_block_struct;
	extern s_tag_block_definition weapon_palette_choice_block_block;
	extern s_tag_struct_definition equipment_palette_choice_block_block_struct;
	extern s_tag_block_definition equipment_palette_choice_block_block;
	extern s_tag_struct_definition cell_block_block_struct;
	extern s_tag_block_definition cell_block_block;
	extern s_tag_struct_definition squads_block_block_struct;
	extern s_tag_block_definition squads_block_block;
	extern s_tag_struct_definition character_ref_choice_block_block_struct;
	extern s_tag_block_definition character_ref_choice_block_block;
	extern s_tag_struct_definition weapon_ref_choice_block_block_struct;
	extern s_tag_block_definition weapon_ref_choice_block_block;
	extern s_tag_struct_definition equipment_ref_choice_block_block_struct;
	extern s_tag_block_definition equipment_ref_choice_block_block;
	extern s_tag_struct_definition cell_template_block_block_struct;
	extern s_tag_block_definition cell_template_block_block;

	extern s_tag_struct_definition squad_definition_internal_struct_struct_definition;

	extern const char* patrol_point_flags_strings[];
	extern s_string_list_definition patrol_point_flags;
	extern const char* patrol_mode_enum_strings[];
	extern s_string_list_definition patrol_mode_enum;
	extern const char* starting_location_flags_strings[];
	extern s_string_list_definition starting_location_flags;
	extern const char* ai_placement_seat_preference_enum_strings[];
	extern s_string_list_definition ai_placement_seat_preference_enum;
	extern const char* actor_movement_modes_strings[];
	extern s_string_list_definition actor_movement_modes;
	extern const char* major_upgrade_enum_strings[];
	extern s_string_list_definition major_upgrade_enum;
	extern const char* squad_flags_strings[];
	extern s_string_list_definition squad_flags;
	extern const char* spawn_formation_flags_strings[];
	extern s_string_list_definition spawn_formation_flags;
	extern const char* g_activity_enum_strings[];
	extern s_string_list_definition g_activity_enum;
	extern const char* ai_team_enum_strings[];
	extern s_string_list_definition ai_team_enum;

} // namespace blofeld

