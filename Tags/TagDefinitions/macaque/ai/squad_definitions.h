#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SQUAD_TEMPLATE_TAG = 'sqtm';
	extern s_tag_group squad_template_group; // squad_template_block
	extern s_tag_block_definition squad_template_block;
	extern s_tag_struct_definition squad_template; // squad_template_block


	extern s_tag_block_definition squad_groups_block;
	extern s_tag_struct_definition squad_groups_block_struct_definition; // squad_groups_block
	extern s_tag_block_definition squads_block;
	extern s_tag_struct_definition squads_block_struct_definition; // squads_block
	extern s_tag_block_definition spawn_formation_block;
	extern s_tag_struct_definition spawn_formation_block_struct_definition; // spawn_formation_block
	extern s_tag_block_definition patrol_point_block;
	extern s_tag_struct_definition patrol_point_block_struct_definition; // patrol_point_block
	extern s_tag_block_definition spawn_points_block;
	extern s_tag_struct_definition spawn_points_block_struct_definition; // spawn_points_block
	extern s_tag_block_definition cell_block;
	extern s_tag_struct_definition cell_block_struct_definition; // cell_block
	extern s_tag_block_definition character_palette_choice_block;
	extern s_tag_struct_definition character_palette_choice_block_struct_definition; // character_palette_choice_block
	extern s_tag_block_definition weapon_palette_choice_block;
	extern s_tag_struct_definition weapon_palette_choice_block_struct_definition; // weapon_palette_choice_block
	extern s_tag_block_definition equipment_palette_choice_block;
	extern s_tag_struct_definition equipment_palette_choice_block_struct_definition; // equipment_palette_choice_block
	extern s_tag_block_definition cell_template_block;
	extern s_tag_struct_definition cell_template_block_struct_definition; // cell_template_block
	extern s_tag_block_definition character_ref_choice_block;
	extern s_tag_struct_definition character_ref_choice_block_struct_definition; // character_ref_choice_block
	extern s_tag_block_definition weapon_ref_choice_block;
	extern s_tag_struct_definition weapon_ref_choice_block_struct_definition; // weapon_ref_choice_block
	extern s_tag_block_definition equipment_ref_choice_block;
	extern s_tag_struct_definition equipment_ref_choice_block_struct_definition; // equipment_ref_choice_block

	extern s_tag_struct_definition squad_definition_internal_struct;

	extern c_versioned_string_list patrol_point_flags_strings;
	extern s_string_list_definition patrol_point_flags;
	extern c_versioned_string_list patrol_mode_enum_strings;
	extern s_string_list_definition patrol_mode_enum;
	extern c_versioned_string_list starting_location_flags_strings;
	extern s_string_list_definition starting_location_flags;
	extern c_versioned_string_list ai_placement_seat_preference_enum_strings;
	extern s_string_list_definition ai_placement_seat_preference_enum;
	extern c_versioned_string_list actor_movement_modes_strings;
	extern s_string_list_definition actor_movement_modes;
	extern c_versioned_string_list major_upgrade_enum_strings;
	extern s_string_list_definition major_upgrade_enum;
	extern c_versioned_string_list squad_flags_strings;
	extern s_string_list_definition squad_flags;
	extern c_versioned_string_list spawn_formation_flags_strings;
	extern s_string_list_definition spawn_formation_flags;
	extern c_versioned_string_list g_activity_enum_strings;
	extern s_string_list_definition g_activity_enum;
	extern c_versioned_string_list ai_team_enum_strings;
	extern s_string_list_definition ai_team_enum;

} // namespace macaque

} // namespace blofeld

