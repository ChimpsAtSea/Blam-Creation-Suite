#pragma once

namespace blofeld
{



	constexpr unsigned long SQUAD_TEMPLATE_TAG = 'sqtm';
	extern s_tag_group squad_template_group; // squad_template_block
	extern s_tag_block_definition squad_template_block;
	extern s_tag_struct_definition squad_template_block_struct_definition; // squad_template_block


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

	extern s_string_list_definition patrol_point_flags;
	extern s_string_list_definition patrol_mode_enum;
	extern s_string_list_definition starting_location_flags;
	extern s_string_list_definition ai_placement_seat_preference_enum;
	extern s_string_list_definition actor_movement_modes;
	extern s_string_list_definition major_upgrade_enum;
	extern s_string_list_definition squad_flags;
	extern s_string_list_definition spawn_formation_flags;
	extern s_string_list_definition g_activity_enum;
	extern s_string_list_definition ai_team_enum;



} // namespace blofeld

