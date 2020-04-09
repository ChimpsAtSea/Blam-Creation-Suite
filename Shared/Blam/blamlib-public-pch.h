#pragma once

#ifdef auto
#undef auto
#endif

#ifdef ASSERT
#define blamlib_assert ASSERT
#endif

#include <blamlib/source/cseries/cseries.h>
#include <blamlib/source/math/real_math.h>
#include <blamlib/source/tag_files/tag_groups.h>

#include <blamlib/source/haloreach/math/function_definitions.h>

/* achi achievements s_game_achievements*/ #include <blamlib/source/haloreach/game/player_achievements.h>
/* adlg ai_dialogue_globals s_ai_dialogue_globals*/ #include <blamlib/source/haloreach/ai/ai_dialogue.h>
/* aigl ai_globals s_ai_globals_definition*/ #include <blamlib/source/haloreach/ai/ai_globals.h>
/* airs airstrike s_airstrike_definition*/ #include <blamlib/source/haloreach/items/airstrike.h>
/* ant! antenna s_antenna_definition*/ #include <blamlib/source/haloreach/objects/widgets/antenna.h>
/* atgf atmosphere_globals s_atmosphere_globals*/ #include <blamlib/source/haloreach/sky_atm/atmosphere_globals.h>
/* avat avatar_awards s_game_avatar_awards*/ #include <blamlib/source/haloreach/game/player_avatar_awards.h>
/* bbcr big_battle_creature s_big_battle_creature_definition*/ #include <blamlib/source/haloreach/big_battle_squad/big_battle_squad.h>
/* bdpd death_program_selector s_biped_death_program_selector*/ #include <blamlib/source/haloreach/motor/death_program_selection_definitions.h>
/* beam beam_system */
/* bink bink s_bink_definition*/ #include <blamlib/source/haloreach/bink/bink_definitions.h>
/* bipd biped s_biped_definition*/ #include <blamlib/source/haloreach/units/biped_definitions.h>
/* bitm bitmap s_bitmap_definition*/ #include <blamlib/source/haloreach/bitmaps/bitmap_definitions.h>
/* bloc crate s_crate_definition*/ #include <blamlib/source/haloreach/objects/crates.h>
/* bsdt breakable_surface s_breakable_surface_definition*/ #include <blamlib/source/haloreach/physics/breakable_surfaces.h>
/* cddf collision_damage s_collision_damage_definition*/ #include <blamlib/source/haloreach/physics/havok_collision_damage.h>
/* cfxs camera_fx_settings c_camera_fx_settings*/ #include <blamlib/source/haloreach/render/camera_fx_settings.h>
/* chad chud_animation_definition s_chud_animation_definition*/ #include <blamlib/source/haloreach/interface/chud/chud_definitions.h>
/* char character s_character_definition*/ #include <blamlib/source/haloreach/ai/character_definitions.h>
/* chdg challenge_globals_definition s_challenge_globals_definition*/ #include <blamlib/source/haloreach/game/challenges/challenge_definitions.h>
/* chdt chud_definition s_chud_definition*/ #include <blamlib/source/haloreach/interface/chud/chud_definitions.h>
/* chgd chud_globals_definition s_chud_globals_definition*/ #include <blamlib/source/haloreach/interface/chud/chud_definitions.h>
/* chmt chocolate_mountain_new s_chocolate_mountain_new_definition*/ #include <blamlib/source/haloreach/scenario/scenario_lightmap_definitions.h>
/* cine cinematic s_cinematic_definition*/ #include <blamlib/source/haloreach/cutscene/cinematics_definitions.h>
/* cisc cinematic_scene s_cinematic_scene_definition*/ #include <blamlib/source/haloreach/cutscene/cinematics_definitions.h>
/* citr cinematic_transition s_cinematic_transition_definition*/ #include <blamlib/source/haloreach/cutscene/cinematics_definitions.h>
/* clwd cloth s_cloth_definition*/ #include <blamlib/source/haloreach/objects/widgets/cloth.h>
/* cmoe camo s_camo_effect_definition*/ #include <blamlib/source/haloreach/effects/camo_effect_definition.h>
/* cmps compute_shader */
/* cntl contrail_system */
/* coll collision_model */
/* colo color_table */
/* comg commendation_globals_definition */
/* coms communication_sounds */
/* cook cookie_globals_definition */
/* coop coop_spawning_globals_definition */
/* cpem cheap_particle_emitter s_cheap_particle_emitter*/ #include <blamlib/source/haloreach/effects/cheap_particle_system.h>
/* cpgd cookie_purchase_globals */
/* cptl cheap_particle_type_library s_cheap_particle_type_library*/ #include <blamlib/source/haloreach/effects/cheap_particle_system.h>
/* crea creature */
/* csdt camera_shake */
/* ctrl device_control s_control_definition*/ #include <blamlib/source/haloreach/devices/device_controls.h>
/* cusc cui_screen */
/* cust cui_static_data */
/* dctr decorator_set */
/* decs decal_system */
/* devi device s_device_definition*/ #include <blamlib/source/haloreach/devices/devices.h>
/* devo cellular_automata */
/* dobc detail_object_collection */
/* draw rasterizer_cache_file_globals */
/* drdf damage_response_definition */
/* ebhd particle_emitter_boat_hull_shape */
/* effe effect s_effect_definition*/ #include <blamlib/source/haloreach/effects/effects.h>
/* effg effect_globals */
/* efsc effect_scenery s_effect_scenery_definition*/ #include <blamlib/source/haloreach/effects/effect_scenery.h>
/* eqip equipment s_equipment_definition*/ #include <blamlib/source/haloreach/items/equipment_definitions.h>
/* flck flock */
/* fldy fluid_dynamics */
/* fogg atmosphere_fog */
/* foot material_effects s_material_effects_definition*/ #include <blamlib/source/haloreach/effects/material_effect_definitions.h>
/* form formation */
/* frms frame_event_list */
/* fxtt fx_test */
/* gcrg game_completion_rewards_globals */
/* gegl game_engine_globals */
/* gint giant s_giant_definition*/ #include <blamlib/source/haloreach/units/giant_definitions.h>
/* gldf cheap_light */
/* glps global_pixel_shader */
/* glvs global_vertex_shader */
/* gmeg game_medal_globals */
/* goof multiplayer_variant_settings_interface_d */
/* gpix global_cache_file_pixel_shaders */
/* gptd game_performance_throttle */
/* grfr grounded_friction s_grounded_friction_definition*/ #include <blamlib/source/haloreach/physics/grounded_friction.h>
/* hcfd havok_collision_filter */
/* hlmt model s_model_definition*/ #include <blamlib/source/haloreach/models/model_definitions.h>
/* hlsl hlsl_include */
/* hsc* scenario_hs_source_file */
/* igpd incident_global_properties_definition */
/* iimz instance_imposter_definition */
/* impo imposter_model */
/* ingd incident_globals_definition */
/* item item s_item_definition*/ #include <blamlib/source/haloreach/items/item_definitions.h>
/* jmad model_animation_graph c_model_animation_graph*/ #include <blamlib/source/haloreach/animations/animation_definitions.h>
/* jmrq sandbox_text_value_pair_definition */
/* jpt! damage_effect */
/* Lbsp scenario_lightmap_bsp_data s_scenario_lightmap_bsp_data*/ #include <blamlib/source/haloreach/scenario/scenario_lightmap_definitions.h>
/* ldsc load_screen_globals */
/* lens lens_flare */
/* lgtd loadout_globals_definition */
/* ligh light */
/* locs location_name_globals_definition */
/* lsnd sound_looping s_looping_sound_definition*/ #include <blamlib/source/haloreach/sound/sound_definitions.h>
/* lswd leaf_system */
/* ltvl light_volume_system */
/* mach device_machine s_machine_definition*/ #include <blamlib/source/haloreach/devices/device_machines.h>
/* matg globals s_game_globals*/ #include <blamlib/source/haloreach/game/game_globals.h>
/* mcsr mouse_cursor_definition */
/* mdlg ai_mission_dialogue */
/* metr meter */
/* mffn muffin */
/* mgls megalogamengine_sounds */
/* mlib emblem_library */
/* mode render_model s_render_model_definition*/ #include <blamlib/source/haloreach/models/render_model_definitions.h>
/* motl multiplayer_object_type_list */
/* mply multiplayer_scenario_description */
/* msit megalo_string_id_table */
/* mulg multiplayer_globals */
/* muxg mux_generator */
/* nclt new_cinematic_lighting */
/* obje object s_object_definition*/ #include <blamlib/source/haloreach/objects/object_definitions.h>
/* pach tag_package_manifest */
/* pcec pgcr_enemy_to_category_mapping_definition */
/* pecp particle_emitter_custom_points */
/* perf performance_throttles */
/* pfmc performance_template */
/* pfpt planar_fog_parameters */
/* pggd player_grade_globals_definition */
/* phmo physics_model */
/* pixl pixel_shader */
/* play cache_file_resource_layout_table s_cache_file_resource_layout_table*/ //#include <blamlib/source/haloreach/cache/cache_file_resource_definitions.h>
/* pmcg player_model_customization_globals */
/* pmdf particle_model */
/* pmov particle_physics */
/* pphy point_physics */
/* proj projectile s_projectile_definition*/ #include <blamlib/source/haloreach/items/projectile_definitions.h>
/* prt3 particle */
/* rain rain_definition */
/* rasg rasterizer_globals */
/* rm render_method c_render_method*/ #include <blamlib/source/haloreach/render_methods/render_method_definitions.h>
/* rmb shader_beam */
/* rmbl rumble */
/* rmcs shader_custom */
/* rmct shader_cortana */
/* rmd shader_decal */
/* rmdf render_method_definition */
/* rmfl shader_foliage */
/* rmfs shader_fur_stencil */
/* rmfu shader_fur */
/* rmgl shader_glass */
/* rmhg shader_halogram */
/* rmlv shader_light_volume */
/* rmmm shader_mux_material */
/* rmmx shader_mux */
/* rmop render_method_option */
/* rmsh shader c_render_method_shader*/ #include <blamlib/source/haloreach/render_methods/render_method_definitions.h>
/* rmsk shader_skin */
/* rmss shader_screen */
/* rmt2 render_method_template */
/* rmtr shader_terrain */
/* rmw shader_water */
/* rwrd render_water_ripple */
/* sFdT scenario_faux_data */
/* sLdT scenario_lightmap s_scenario_lightmap*/ #include <blamlib/source/haloreach/scenario/scenario_lightmap_definitions.h>
/* sadt spring_acceleration s_spring_acceleration_definition*/ #include <blamlib/source/haloreach/physics/spring_acceleration.h>
/* sbsp scenario_structure_bsp s_structure_bsp_definition*/ #include <blamlib/source/haloreach/structures/structure_bsp_definitions.h>
/* scen scenery s_scenery_definition*/ #include <blamlib/source/haloreach/objects/scenery.h>
/* scmb sound_combiner */
/* scnr scenario s_scenario*/ #include <blamlib/source/haloreach/scenario/scenario_definitions.h>
/* sddt structure_design s_structure_design_definition*/ #include <blamlib/source/haloreach/structures/structure_bsp_definitions.h>
/* sefc area_screen_effect s_area_screen_effect_definition*/ #include <blamlib/source/haloreach/effects/screen_effect.h>
/* sfx+ sound_effect_collection */
/* sgp! sound_global_propagation */
/* shit shield_impact */
/* sidt simulated_input */
/* siin simulation_interpolation */
/* sily text_value_pair_definition */
/* sirp scenario_interpolator */
/* skya sky_atm_parameters */
/* smap shared_cache_file_layout */
/* smdt survival_mode_globals */
/* sncl sound_classes s_sound_classes_definition*/ #include <blamlib/source/haloreach/sound/sound_classes.h>
/* snd! sound s_sound_definition*/ #include <blamlib/source/haloreach/sound/sound_definitions.h>
/* snde sound_environment s_sound_environment_definition*/ #include <blamlib/source/haloreach/sound/sound_definitions.h>
/* snmm sound_mix_mastering */
/* snmx sound_mix */
/* spk! sound_dialogue_constants */
/* sqtm squad_template */
/* srad sound_radio_settings */
/* ssao ssao_definition */
/* ssce sound_scenery s_sound_scenery_definition*/ #include <blamlib/source/haloreach/sound/sound_scenery.h>
/* stli scenario_structure_lighting_info */
/* stse structure_seams */
/* styl style */
/* term device_terminal */
/* trak camera_track */
/* ttag test_tag */
/* udlg dialogue s_unit_dialogue_definition*/ #include <blamlib/source/haloreach/units/unit_dialogue.h>
/* ugh! sound_cache_file_gestalt s_sound_cache_file_gestalt_definition*/ #include <blamlib/source/haloreach/sound/sound_definitions.h>
/* uise user_interface_sounds_definition */
/* unic multilingual_unicode_string_list */
/* unit unit s_unit_definition*/ #include <blamlib/source/haloreach/units/unit_definitions.h>
/* uttt tag_template_unit_test */
/* vehi vehicle s_vehicle_definition*/ #include <blamlib/source/haloreach/units/vehicle_definitions.h>
/* vmdx vision_mode */
/* vtgl variant_globals */
/* vtsh vertex_shader */
/* wadt chud_widget_animation_data_template */
/* wave wave_template */
/* wdst chud_widget_datasource_template */
/* weap weapon s_weapon_definition*/ #include <blamlib/source/haloreach/items/weapon_definitions.h>
/* wetn scenario_wetness_bsp_data s_scenario_wetness_bsp_data*/ #include <blamlib/source/haloreach/scenario/scenario_lightmap_definitions.h>
/* wezr game_engine_settings_definition */
/* wgtz user_interface_globals_definition */
/* whip cellular_automata2d */
/* wigl user_interface_shared_globals_definition */
/* wind wind */
/* wpdp water_physics_drag_properties */
/* wpdt chud_widget_placement_data_template */
/* wrdt chud_widget_render_data_template */
/* wsdt chud_widget_state_data_template */
/* wxcg weather_globals */
/* zone cache_file_resource_gestalt s_cache_file_resource_gestalt*/ //#include <blamlib/source/haloreach/cache/cache_file_resource_definitions.h>

#ifndef auto
#define auto auto_is_banned
#endif
