#include "haloreachtagdefinitions-private-pch.h"

namespace blofeld::haloreach::pc64
{

	s_tag_group const* const tag_groups[] =
	{
		&achievements_group,
		&ai_dialogue_globals_group,
		&ai_globals_group,
		&ai_mission_dialogue_group,
		&airstrike_group,
		&antenna_group,
		&area_screen_effect_group,
		&atmosphere_fog_group,
		&atmosphere_globals_group,
		&avatar_awards_group,
		&beam_system_group,
		&big_battle_creature_group,
		&bink_group,
		&biped_group,
		&bitmap_group,
		&breakable_surface_group,
		&cache_file_resource_gestalt_group,
		&cache_file_resource_layout_table_group,
		&cache_file_sound_group,
		&camera_fx_settings_group,
		&camera_shake_group,
		&camera_track_group,
		&camo_group,
		&cellular_automata2d_group,
		&cellular_automata_group,
		&challenge_globals_definition_group,
		&character_group,
		&cheap_light_group,
		&cheap_particle_emitter_group,
		&cheap_particle_type_library_group,
		&chocolate_mountain_new_group,
		&chud_animation_definition_group,
		&chud_definition_group,
		&chud_globals_definition_group,
		&chud_widget_animation_data_template_group,
		&chud_widget_datasource_template_group,
		&chud_widget_placement_data_template_group,
		&chud_widget_render_data_template_group,
		&chud_widget_state_data_template_group,
		&cinematic_group,
		&cinematic_scene_group,
		&cinematic_transition_group,
		&cloth_group,
		&collision_damage_group,
		&collision_model_group,
		&color_table_group,
		&commendation_globals_definition_group,
		&communication_sounds_group,
		&compute_shader_group,
		&contrail_system_group,
		&cookie_globals_definition_group,
		&cookie_purchase_globals_group,
		&coop_spawning_globals_definition_group,
		&crate_group,
		&creature_group,
		&cui_screen_group,
		&cui_static_data_group,
		&damage_effect_group,
		&damage_response_definition_group,
		&death_program_selector_group,
		&decal_system_group,
		&decorator_set_group,
		&detail_object_collection_group,
		&device_control_group,
		&device_group,
		&device_machine_group,
		&device_terminal_group,
		&dialogue_group,
		&effect_globals_group,
		&effect_group,
		&effect_scenery_group,
		&emblem_library_group,
		&equipment_group,
		&flock_group,
		&fluid_dynamics_group,
		&formation_group,
		&frame_event_list_group,
		&fx_test_group,
		&game_completion_rewards_globals_group,
		&game_engine_globals_group,
		&game_engine_settings_definition_group,
		&game_medal_globals_group,
		&game_performance_throttle_group,
		&giant_group,
		&global_cache_file_pixel_shaders_group,
		&global_pixel_shader_group,
		&global_vertex_shader_group,
		&globals_group,
		&grounded_friction_group,
		&havok_collision_filter_group,
		&hlsl_include_group,
		&imposter_model_group,
		&incident_global_properties_definition_group,
		&incident_globals_definition_group,
		&instance_imposter_definition_group,
		&item_group,
		&leaf_system_group,
		&lens_flare_group,
		&light_group,
		&light_volume_system_group,
		&lightmapper_globals_group,
		&lightning_system_group,
		&load_screen_globals_group,
		&loadout_globals_definition_group,
		&location_name_globals_definition_group,
		&material_effects_group,
		&megalo_string_id_table_group,
		&megalogamengine_sounds_group,
		&meter_group,
		&model_animation_graph_group,
		&model_group,
		&mouse_cursor_definition_group,
		&muffin_group,
		&multilingual_unicode_string_list_group,
		&multiplayer_globals_group,
		&multiplayer_object_type_list_group,
		&multiplayer_scenario_description_group,
		&multiplayer_variant_settings_interface_definition_group,
		&mux_generator_group,
		&new_cinematic_lighting_group,
		&object_group,
		&particle_emitter_boat_hull_shape_group,
		&particle_emitter_custom_points_group,
		&particle_group,
		&particle_model_group,
		&particle_physics_group,
		&performance_template_group,
		&performance_throttles_group,
		&pgcr_enemy_to_category_mapping_definition_group,
		&physics_model_group,
		&pixel_shader_group,
		&planar_fog_parameters_group,
		&player_grade_globals_definition_group,
		&player_model_customization_globals_group,
		&point_physics_group,
		&projectile_group,
		&rain_definition_group,
		&rasterizer_cache_file_globals_group,
		&rasterizer_globals_group,
		&render_method_definition_group,
		&render_method_group,
		&render_method_option_group,
		&render_method_template_group,
		&render_model_group,
		&render_water_ripple_group,
		&rumble_group,
		&sandbox_text_value_pair_definition_group,
		&scenario_ai_resource_group,
		&scenario_bipeds_resource_group,
		&scenario_cinematics_resource_group,
		&scenario_cluster_data_resource_group,
		&scenario_comments_resource_group,
		&scenario_creature_resource_group,
		&scenario_cubemap_resource_group,
		&scenario_decals_resource_group,
		&scenario_decorators_resource_group,
		&scenario_devices_resource_group,
		&scenario_dumplings_resource_group,
		&scenario_effect_scenery_resource_group,
		&scenario_equipment_resource_group,
		&scenario_faux_data_group,
		&scenario_group,
		&scenario_hs_source_file_group,
		&scenario_interpolator_group,
		&scenario_lightmap_bsp_data_group,
		&scenario_lightmap_group,
		&scenario_lights_resource_group,
		&scenario_performances_resource_group,
		&scenario_required_resource_group,
		&scenario_scenery_resource_group,
		&scenario_sky_references_resource_group,
		&scenario_sound_scenery_resource_group,
		&scenario_structure_bsp_group,
		&scenario_structure_lighting_info_group,
		&scenario_structure_lighting_resource_group,
		&scenario_trigger_volumes_resource_group,
		&scenario_vehicles_resource_group,
		&scenario_weapons_resource_group,
		&scenario_wetness_bsp_data_group,
		&scenery_group,
		&shader_beam_group,
		&shader_contrail_group,
		&shader_cortana_group,
		&shader_custom_group,
		&shader_decal_group,
		&shader_foliage_group,
		&shader_fur_group,
		&shader_fur_stencil_group,
		&shader_glass_group,
		&shader_group,
		&shader_halogram_group,
		&shader_light_volume_group,
		&shader_mux_group,
		&shader_mux_material_group,
		&shader_particle_group,
		&shader_screen_group,
		&shader_skin_group,
		&shader_terrain_group,
		&shader_water_group,
		&shared_cache_file_layout_group,
		&shield_impact_group,
		&simulated_input_group,
		&simulation_interpolation_group,
		&sky_atm_parameters_group,
		&sound_cache_file_gestalt_group,
		&sound_classes_group,
		&sound_combiner_group,
		&sound_dialogue_constants_group,
		&sound_effect_collection_group,
		&sound_effect_template_group,
		&sound_environment_group,
		&sound_global_propagation_group,
		&sound_group,
		&sound_looping_group,
		&sound_mix_group,
		&sound_mix_mastering_group,
		&sound_radio_settings_group,
		&sound_scenery_group,
		&spring_acceleration_group,
		&squad_template_group,
		&ssao_definition_group,
		&stereo_system_group,
		&structure_design_group,
		&structure_seams_group,
		&style_group,
		&survival_mode_globals_group,
		&tag_package_manifest_group,
		&tag_template_unit_test_group,
		&test_tag_group,
		&text_value_pair_definition_group,
		&unit_group,
		&user_interface_globals_definition_group,
		&user_interface_shared_globals_definition_group,
		&user_interface_sounds_definition_group,
		&variant_globals_group,
		&vehicle_group,
		&vertex_shader_group,
		&vision_mode_group,
		&water_physics_drag_properties_group,
		&wave_template_group,
		&weapon_group,
		&weather_globals_group,
		&wind_group,
		nullptr
	};

} // namespace blofeld::haloreach::pc64
