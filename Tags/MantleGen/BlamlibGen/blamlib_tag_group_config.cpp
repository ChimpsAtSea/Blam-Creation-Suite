#include "mantlegen-private-pch.h"

const s_reflection_structure* reflection(uint32_t tag_group)
{
#define tag_group_definition(_definition, _group_tag) if (tag_group == _group_tag) return &reflection<_definition>();

	tag_group_definition(s_game_achievements, k_game_achievements_group_tag);
	tag_group_definition(s_ai_dialogue_globals, k_ai_dialogue_globals_group_tag);
	tag_group_definition(s_ai_globals_definition, k_ai_globals_group_tag);
	tag_group_definition(s_airstrike_definition, k_airstrike_group_tag);
	tag_group_definition(s_antenna_definition, k_antenna_group_tag);
	tag_group_definition(s_atmosphere_globals, k_atmosphere_globals_group_tag);
	tag_group_definition(s_game_avatar_awards, k_game_avatar_awards_group_tag);
	tag_group_definition(s_big_battle_creature_definition, k_big_battle_creature_group_tag);
	tag_group_definition(s_biped_death_program_selector, k_biped_death_program_selector_group_tag);
	tag_group_definition(s_bink_definition, k_bink_group_tag);
	tag_group_definition(s_biped_definition, k_biped_group_tag);
	tag_group_definition(s_bitmap_definition, k_bitmap_group_tag);
	tag_group_definition(s_crate_definition, k_crate_group_tag);
	tag_group_definition(s_breakable_surface_definition, k_breakable_source_group_tag);
	tag_group_definition(s_collision_damage_definition, k_collision_damage_group_tag);
	//tag_group_definition(c_camera_fx_settings, k_camera_fx_settings_group_tag); /*CLASS*/
	tag_group_definition(s_chud_animation_definition, k_chud_animation_group_tag);
	tag_group_definition(s_character_definition, k_character_group_tag);
	tag_group_definition(s_challenge_globals_definition, k_challenge_globals_group_tag);
	tag_group_definition(s_chud_definition, k_chud_group_tag);
	tag_group_definition(s_chud_globals_definition, k_chud_globals_group_tag);
	tag_group_definition(s_chocolate_mountain_new_definition, k_chocolate_mountain_new_group_tag);
	tag_group_definition(s_cinematic_definition, k_cinematic_group_tag);
	//tag_group_definition(s_cinematic_scene_definition, k_cinematic_scene_group_tag);
	tag_group_definition(s_cinematic_transition_definition, k_cinematic_transition_group_tag);
	tag_group_definition(s_cloth_definition, k_cloth_group_tag);
	tag_group_definition(s_camo_effect_definition, k_camo_effect_group_tag);
	tag_group_definition(s_cheap_particle_emitter, k_cheap_particle_emitter_group_tag);
	tag_group_definition(s_cheap_particle_type_library, k_cheap_particle_type_library_group_tag);
	tag_group_definition(s_control_definition, k_control_group_tag);
	tag_group_definition(s_device_definition, k_device_group_tag);
	tag_group_definition(s_effect_definition, k_effect_group_tag);
	tag_group_definition(s_effect_scenery_definition, k_effect_scenery_group_tag);
	tag_group_definition(s_equipment_definition, k_equipment_group_tag);
	tag_group_definition(s_material_effects_definition, k_material_effects_group_tag);
	tag_group_definition(s_giant_definition, k_giant_group_tag);
	tag_group_definition(s_grounded_friction_definition, k_grounded_friction_group_tag);
	tag_group_definition(s_model_definition, k_model_group_tag);
	tag_group_definition(s_item_definition, k_item_group_tag);
	//tag_group_definition(c_model_animation_graph, k_model_animation_graph_group_tag); /*CLASS*/
	tag_group_definition(s_scenario_lightmap_bsp_data, k_scenario_lightmap_bsp_data_group_tag);
	tag_group_definition(s_looping_sound_definition, k_sound_looping_group_tag);
	tag_group_definition(s_machine_definition, k_machine_group_tag);
	tag_group_definition(s_game_globals, k_globals_group_tag);
	tag_group_definition(s_render_model_definition, k_render_model_group_tag);
	tag_group_definition(s_object_definition, k_object_group_tag);
	//tag_group_definition(s_cache_file_resource_layout_table, k_cache_file_resource_layout_table_group_tag);
	tag_group_definition(s_projectile_definition, k_projectile_group_tag);
	//tag_group_definition(c_render_method, k_render_method_group_tag); /*CLASS*/
	//tag_group_definition(c_render_method_shader, k_render_method_shader_group_tag); /*CLASS*/
	tag_group_definition(s_scenario_lightmap, k_scenario_lightmap_group_tag);
	tag_group_definition(s_spring_acceleration_definition, k_spring_acceleration_group_tag);
	tag_group_definition(s_structure_bsp_definition, k_structure_bsp_group_tag);
	tag_group_definition(s_scenery_definition, k_scenery_group_tag);
	tag_group_definition(s_scenario, k_scenario_group_tag);
	tag_group_definition(s_structure_design_definition, k_structure_design_group_tag);
	tag_group_definition(s_area_screen_effect_definition, k_area_screen_effect_group_tag);
	tag_group_definition(s_sound_classes_definition, k_sound_classes_group_tag);
	tag_group_definition(s_sound_definition, k_sound_group_tag);
	tag_group_definition(s_sound_environment_definition, k_sound_environment_group_tag);
	tag_group_definition(s_sound_scenery_definition, k_sound_scenery_group_tag);
	tag_group_definition(s_unit_dialogue_definition, k_unit_dialogue_group_tag);
	tag_group_definition(s_sound_cache_file_gestalt_definition, k_sound_cache_file_gestalt_group_tag);
	tag_group_definition(s_unit_definition, k_unit_group_tag);
	tag_group_definition(s_vehicle_definition, k_vehicle_group_tag);
	tag_group_definition(s_weapon_definition, k_weapon_group_tag);
	tag_group_definition(s_scenario_wetness_bsp_data, k_scenario_wetness_bsp_data_group_tag);
	//tag_group_definition(s_cache_file_resource_gestalt, k_cache_file_resource_gestalt_group_tag);

#undef tag_group_definition
	return nullptr;
}
