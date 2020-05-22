#pragma once

typedef signed __int8		int8_t;
typedef signed __int16		int16_t;
typedef signed __int32		int32_t;
typedef signed __int64		int64_t;
typedef unsigned __int8		uint8_t;
typedef unsigned __int16	uint16_t;
typedef unsigned __int32	uint32_t;
typedef unsigned __int64	uint64_t;
typedef unsigned __int8		bool8_t;
typedef unsigned __int16	bool16_t;
typedef unsigned __int32	bool32_t;
typedef unsigned __int64	bool64_t;
typedef	uint8_t				enum8_t;
typedef	uint16_t			enum16_t;
typedef	uint32_t			enum32_t;
typedef	uint64_t			enum64_t;
typedef	uint8_t				bitfield8_t;
typedef	uint16_t			bitfield16_t;
typedef	uint32_t			bitfield32_t;
typedef	uint64_t			bitfield64_t;
typedef	uint8_t				bitflag8_t;
typedef	uint16_t			bitflag16_t;
typedef	uint32_t			bitflag32_t;
typedef	uint64_t			bitflag64_t;
typedef	uint8_t				undefined8_t;
typedef	uint16_t			undefined16_t;
typedef	uint32_t			undefined32_t;
typedef	uint64_t			undefined64_t;
typedef char				char8_t;

#pragma pack(push, 1)

#ifndef STRINGIFY
#define STRINGIFY(s) __STRINGIFY(s)
#define __STRINGIFY(s) #s
#endif

#ifdef __INTELLISENSE__
#define noreflection /* noreflection */
#define nicename(...) /* nicename */
#define tag_group(...) /* group */
#else
#ifdef __clang__
#define noreflection __attribute__((annotate("no_reflection")))
#define nicename(name) __attribute__((annotate("nice_name:" name)))
#define tag_group(groupName) __attribute__((annotate("tag_group:" STRINGIFY(groupName))))
#else
#define noreflection 
#define nicename(name) 
#define tag_group(groupName) 
#endif
#endif

#ifndef BUILD_REFLECTION_DATA
#include <MantleGen/LegacyGen/tag_groups_legacy.h>
#define _legacy_tag_group_render_method static_cast<e_tag_group>('rm  ')
//#define _legacy_tag_group_render_method_template static_cast<e_tag_group>('rmt2')
//#define _legacy_tag_group_render_method_definition static_cast<e_tag_group>('rmsh')
#define _legacy_tag_group_bink static_cast<e_tag_group>('bink')
#define _legacy_tag_group_any static_cast<e_tag_group>(-2)
#define _legacy_tag_group_object static_cast<e_tag_group>('obje')
#else
enum noreflection e_tag_group : int32_t {};
#endif

#include <MantleGen/LegacyGen/TagTypes/string_id_legacy.h>
#include <MantleGen/LegacyGen/TagTypes/data_reference_legacy.h>
#include <MantleGen/LegacyGen/TagTypes/tag_reference_legacy.h>
#include <MantleGen/LegacyGen/TagTypes/tag_block_legacy.h>
#include <MantleGen/LegacyGen/TagTypes/undefined_legacy.h>
#include <MantleGen/LegacyGen/TagTypes/color_legacy.h>
#include <MantleGen/LegacyGen/TagTypes/degree_legacy.h>
#include <MantleGen/LegacyGen/TagTypes/uniclist_legacy.h>

// Tag Definitions

#include <MantleGen/LegacyGen/TagDefinitions/light_volume_system.h>
#include <MantleGen/LegacyGen/TagDefinitions/loadout_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/location_name_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/material_effects.h>
#include <MantleGen/LegacyGen/TagDefinitions/megalo_string_id_table.h>
#include <MantleGen/LegacyGen/TagDefinitions/megalogamengine_sounds.h>
#include <MantleGen/LegacyGen/TagDefinitions/model.h>
#include <MantleGen/LegacyGen/TagDefinitions/model_animation_graph.h>
#include <MantleGen/LegacyGen/TagDefinitions/multilingual_unicode_string_list.h>
#include <MantleGen/LegacyGen/TagDefinitions/multiplayer_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/multiplayer_object_type_list.h>
#include <MantleGen/LegacyGen/TagDefinitions/multiplayer_variant_settings_interface_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/new_cinematic_lighting.h>
#include <MantleGen/LegacyGen/TagDefinitions/particle.h>
#include <MantleGen/LegacyGen/TagDefinitions/particle_emitter_custom_points.h>
#include <MantleGen/LegacyGen/TagDefinitions/particle_model.h>
#include <MantleGen/LegacyGen/TagDefinitions/particle_physics.h>
#include <MantleGen/LegacyGen/TagDefinitions/performance_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/performance_throttles.h>
#include <MantleGen/LegacyGen/TagDefinitions/pgcr_enemy_to_category_mapping_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/physics_model.h>
#include <MantleGen/LegacyGen/TagDefinitions/pixel_shader.h>
#include <MantleGen/LegacyGen/TagDefinitions/planar_fog_parameters.h>
#include <MantleGen/LegacyGen/TagDefinitions/player_grade_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/player_model_customization_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/point_physics.h>
#include <MantleGen/LegacyGen/TagDefinitions/projectile.h>
#include <MantleGen/LegacyGen/TagDefinitions/rain_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/rasterizer_cache_file_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/rasterizer_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/render_method_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/render_method_option.h>
#include <MantleGen/LegacyGen/TagDefinitions/render_method_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/render_model.h>
#include <MantleGen/LegacyGen/TagDefinitions/render_water_ripple.h>
#include <MantleGen/LegacyGen/TagDefinitions/rumble.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario_interpolator.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario_lightmap.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario_lightmap_bsp_data.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario_required_resource.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario_structure_bsp.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario_structure_lighting_info.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenario_wetness_bsp_data.h>
#include <MantleGen/LegacyGen/TagDefinitions/scenery.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_custom.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_decal.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_foliage.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_fur.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_fur_stencil.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_glass.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_halogram.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_mux.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_screen.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_terrain.h>
#include <MantleGen/LegacyGen/TagDefinitions/shader_water.h>
#include <MantleGen/LegacyGen/TagDefinitions/shield_impact.h>
#include <MantleGen/LegacyGen/TagDefinitions/simulated_input.h>
#include <MantleGen/LegacyGen/TagDefinitions/simulation_interpolation.h>
#include <MantleGen/LegacyGen/TagDefinitions/sky_atm_parameters.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_cache_file_gestalt.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_classes.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_combiner.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_dialogue_constants.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_effect_collection.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_environment.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_global_propagation.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_looping.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_mix.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_mix_mastering.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_radio_settings.h>
#include <MantleGen/LegacyGen/TagDefinitions/sound_scenery.h>
#include <MantleGen/LegacyGen/TagDefinitions/spring_acceleration.h>
#include <MantleGen/LegacyGen/TagDefinitions/squad_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/ssao_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/structure_design.h>
#include <MantleGen/LegacyGen/TagDefinitions/style.h>
#include <MantleGen/LegacyGen/TagDefinitions/survival_mode_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/text_value_pair_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/user_interface_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/user_interface_shared_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/user_interface_sounds_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/variant_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/vehicle.h>
#include <MantleGen/LegacyGen/TagDefinitions/vertex_shader.h>
#include <MantleGen/LegacyGen/TagDefinitions/water_physics_drag_properties.h>
#include <MantleGen/LegacyGen/TagDefinitions/wave_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/weapon.h>
#include <MantleGen/LegacyGen/TagDefinitions/weather_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/wind.h>
#include <MantleGen/LegacyGen/TagDefinitions/achievements.h>
#include <MantleGen/LegacyGen/TagDefinitions/ai_dialogue_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/ai_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/ai_mission_dialogue.h>
#include <MantleGen/LegacyGen/TagDefinitions/airstrike.h>
#include <MantleGen/LegacyGen/TagDefinitions/antenna.h>
#include <MantleGen/LegacyGen/TagDefinitions/area_screen_effect.h>
#include <MantleGen/LegacyGen/TagDefinitions/atmosphere_fog.h>
#include <MantleGen/LegacyGen/TagDefinitions/atmosphere_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/avatar_awards.h>
#include <MantleGen/LegacyGen/TagDefinitions/beam_system.h>
#include <MantleGen/LegacyGen/TagDefinitions/big_battle_creature.h>
#include <MantleGen/LegacyGen/TagDefinitions/biped.h>
#include <MantleGen/LegacyGen/TagDefinitions/bitmap.h>
#include <MantleGen/LegacyGen/TagDefinitions/breakable_surface.h>
#include <MantleGen/LegacyGen/TagDefinitions/cache_file_resource_gestalt.h>
#include <MantleGen/LegacyGen/TagDefinitions/cache_file_resource_layout_table.h>
#include <MantleGen/LegacyGen/TagDefinitions/camera_fx_settings.h>
#include <MantleGen/LegacyGen/TagDefinitions/camera_shake.h>
#include <MantleGen/LegacyGen/TagDefinitions/camera_track.h>
#include <MantleGen/LegacyGen/TagDefinitions/camo.h>
#include <MantleGen/LegacyGen/TagDefinitions/challenge_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/character.h>
#include <MantleGen/LegacyGen/TagDefinitions/cheap_light.h>
#include <MantleGen/LegacyGen/TagDefinitions/cheap_particle_emitter.h>
#include <MantleGen/LegacyGen/TagDefinitions/cheap_particle_type_library.h>
#include <MantleGen/LegacyGen/TagDefinitions/chocolate_mountain_new.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_animation_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_widget_animation_data_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_widget_datasource_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_widget_placement_data_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_widget_render_data_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/chud_widget_state_data_template.h>
#include <MantleGen/LegacyGen/TagDefinitions/cinematic.h>
#include <MantleGen/LegacyGen/TagDefinitions/cinematic_scene.h>
#include <MantleGen/LegacyGen/TagDefinitions/cinematic_transition.h>
#include <MantleGen/LegacyGen/TagDefinitions/cloth.h>
#include <MantleGen/LegacyGen/TagDefinitions/collision_damage.h>
#include <MantleGen/LegacyGen/TagDefinitions/collision_model.h>
#include <MantleGen/LegacyGen/TagDefinitions/color_table.h>
#include <MantleGen/LegacyGen/TagDefinitions/commendation_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/communication_sounds.h>
#include <MantleGen/LegacyGen/TagDefinitions/compute_shader.h>
#include <MantleGen/LegacyGen/TagDefinitions/contrail_system.h>
#include <MantleGen/LegacyGen/TagDefinitions/cookie_purchase_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/coop_spawning_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/crate.h>
#include <MantleGen/LegacyGen/TagDefinitions/creature.h>
#include <MantleGen/LegacyGen/TagDefinitions/cui_screen.h>
#include <MantleGen/LegacyGen/TagDefinitions/cui_static_data.h>
#include <MantleGen/LegacyGen/TagDefinitions/damage_effect.h>
#include <MantleGen/LegacyGen/TagDefinitions/damage_response_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/death_program_selector.h>
#include <MantleGen/LegacyGen/TagDefinitions/decal_system.h>
#include <MantleGen/LegacyGen/TagDefinitions/decorator_set.h>
#include <MantleGen/LegacyGen/TagDefinitions/device_control.h>
#include <MantleGen/LegacyGen/TagDefinitions/device_machine.h>
#include <MantleGen/LegacyGen/TagDefinitions/device_terminal.h>
#include <MantleGen/LegacyGen/TagDefinitions/dialogue.h>
#include <MantleGen/LegacyGen/TagDefinitions/effect.h>
#include <MantleGen/LegacyGen/TagDefinitions/effect_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/effect_scenery.h>
#include <MantleGen/LegacyGen/TagDefinitions/emblem_library.h>
#include <MantleGen/LegacyGen/TagDefinitions/equipment.h>
#include <MantleGen/LegacyGen/TagDefinitions/flock.h>
#include <MantleGen/LegacyGen/TagDefinitions/formation.h>
#include <MantleGen/LegacyGen/TagDefinitions/frame_event_list.h>
#include <MantleGen/LegacyGen/TagDefinitions/game_completion_rewards_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/game_engine_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/game_engine_settings_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/game_medal_globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/game_performance_throttle.h>
#include <MantleGen/LegacyGen/TagDefinitions/giant.h>
#include <MantleGen/LegacyGen/TagDefinitions/global_cache_file_pixel_shaders.h>
#include <MantleGen/LegacyGen/TagDefinitions/global_pixel_shader.h>
#include <MantleGen/LegacyGen/TagDefinitions/global_vertex_shader.h>
#include <MantleGen/LegacyGen/TagDefinitions/globals.h>
#include <MantleGen/LegacyGen/TagDefinitions/grounded_friction.h>
#include <MantleGen/LegacyGen/TagDefinitions/havok_collision_filter.h>
#include <MantleGen/LegacyGen/TagDefinitions/imposter_model.h>
#include <MantleGen/LegacyGen/TagDefinitions/incident_global_properties_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/incident_globals_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/instance_imposter_definition.h>
#include <MantleGen/LegacyGen/TagDefinitions/lens_flare.h>
#include <MantleGen/LegacyGen/TagDefinitions/light.h>

#ifndef BUILD_REFLECTION_DATA
#include <MantleGen/LegacyGen/generated_gui_legacy.h>
#include <MantleGen/LegacyGen/reflection_data_legacy.h>
#include <MantleGen/LegacyGen/generated_conversion_legacy.h>
//#include <MantleGen/LegacyGen/virtual_tag_interfaces_legacy.h>
#endif

#pragma pack(pop)

#undef noreflection
#undef nicename
#undef tag_group
