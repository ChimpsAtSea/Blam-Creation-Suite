#pragma once

namespace blofeld
{
namespace haloreach {

	static constexpr unsigned long CACHE_FILE_SOUND_TAG = '$#!+';
	extern s_tag_group cache_file_sound_group;

	static constexpr unsigned long SCENARIO_SCENERY_RESOURCE_TAG = '*cen';
	extern s_tag_group scenario_scenery_resource_group;

	static constexpr unsigned long SCENARIO_WEAPONS_RESOURCE_TAG = '*eap';
	extern s_tag_group scenario_weapons_resource_group;

	static constexpr unsigned long SCENARIO_VEHICLES_RESOURCE_TAG = '*ehi';
	extern s_tag_group scenario_vehicles_resource_group;

	static constexpr unsigned long SCENARIO_EFFECT_SCENERY_RESOURCE_TAG = '*fsc';
	extern s_tag_group scenario_effect_scenery_resource_group;

	static constexpr unsigned long SCENARIO_LIGHTS_RESOURCE_TAG = '*igh';
	extern s_tag_group scenario_lights_resource_group;

	static constexpr unsigned long SCENARIO_BIPEDS_RESOURCE_TAG = '*ipd';
	extern s_tag_group scenario_bipeds_resource_group;

	static constexpr unsigned long SCENARIO_EQUIPMENT_RESOURCE_TAG = '*qip';
	extern s_tag_group scenario_equipment_resource_group;

	static constexpr unsigned long SCENARIO_CREATURE_RESOURCE_TAG = '*rea';
	extern s_tag_group scenario_creature_resource_group;

	static constexpr unsigned long SCENARIO_SOUND_SCENERY_RESOURCE_TAG = '*sce';
	extern s_tag_group scenario_sound_scenery_resource_group;

	static constexpr unsigned long SCENARIO_COMMENTS_RESOURCE_TAG = '/**/';
	extern s_tag_group scenario_comments_resource_group;

	static constexpr unsigned long SOUND_EFFECT_TEMPLATE_TAG = '<fx>';
	extern s_tag_group sound_effect_template_group;

	static constexpr unsigned long STEREO_SYSTEM_TAG = 'BooM';
	extern s_tag_group stereo_system_group;

	static constexpr unsigned long LIGHTMAPPER_GLOBALS_TAG = 'LMgS';
	extern s_tag_group lightmapper_globals_group;

	static constexpr unsigned long SCENARIO_LIGHTMAP_BSP_DATA_TAG = 'Lbsp';
	extern s_tag_group scenario_lightmap_bsp_data_group;

	static constexpr unsigned long LIGHTNING_SYSTEM_TAG = 'ZZAP';
	extern s_tag_group lightning_system_group;

	static constexpr unsigned long ACHIEVEMENTS_TAG = 'achi';
	extern s_tag_group achievements_group;

	static constexpr unsigned long AI_DIALOGUE_GLOBALS_TAG = 'adlg';
	extern s_tag_group ai_dialogue_globals_group;

	static constexpr unsigned long SCENARIO_AI_RESOURCE_TAG = 'ai**';
	extern s_tag_group scenario_ai_resource_group;

	static constexpr unsigned long AI_GLOBALS_TAG = 'aigl';
	extern s_tag_group ai_globals_group;

	static constexpr unsigned long AIRSTRIKE_TAG = 'airs';
	extern s_tag_group airstrike_group;

	static constexpr unsigned long ANTENNA_TAG = 'ant!';
	extern s_tag_group antenna_group;

	static constexpr unsigned long ATMOSPHERE_GLOBALS_TAG = 'atgf';
	extern s_tag_group atmosphere_globals_group;

	static constexpr unsigned long AVATAR_AWARDS_TAG = 'avat';
	extern s_tag_group avatar_awards_group;

	static constexpr unsigned long BIG_BATTLE_CREATURE_TAG = 'bbcr';
	extern s_tag_group big_battle_creature_group;

	static constexpr unsigned long DEATH_PROGRAM_SELECTOR_TAG = 'bdpd';
	extern s_tag_group death_program_selector_group;

	static constexpr unsigned long BEAM_SYSTEM_TAG = 'beam';
	extern s_tag_group beam_system_group;

	static constexpr unsigned long BINK_TAG = 'bink';
	extern s_tag_group bink_group;

	static constexpr unsigned long BITMAP_TAG = 'bitm';
	extern s_tag_group bitmap_group;

	static constexpr unsigned long BREAKABLE_SURFACE_TAG = 'bsdt';
	extern s_tag_group breakable_surface_group;

	static constexpr unsigned long COLLISION_DAMAGE_TAG = 'cddf';
	extern s_tag_group collision_damage_group;

	static constexpr unsigned long CAMERA_FX_SETTINGS_TAG = 'cfxs';
	extern s_tag_group camera_fx_settings_group;

	static constexpr unsigned long CHUD_ANIMATION_DEFINITION_TAG = 'chad';
	extern s_tag_group chud_animation_definition_group;

	static constexpr unsigned long CHARACTER_TAG = 'char';
	extern s_tag_group character_group;

	static constexpr unsigned long CHALLENGE_GLOBALS_DEFINITION_TAG = 'chdg';
	extern s_tag_group challenge_globals_definition_group;

	static constexpr unsigned long CHUD_DEFINITION_TAG = 'chdt';
	extern s_tag_group chud_definition_group;

	static constexpr unsigned long CHUD_GLOBALS_DEFINITION_TAG = 'chgd';
	extern s_tag_group chud_globals_definition_group;

	static constexpr unsigned long CHOCOLATE_MOUNTAIN_NEW_TAG = 'chmt';
	extern s_tag_group chocolate_mountain_new_group;

	static constexpr unsigned long SCENARIO_CINEMATICS_RESOURCE_TAG = 'cin*';
	extern s_tag_group scenario_cinematics_resource_group;

	static constexpr unsigned long CINEMATIC_TAG = 'cine';
	extern s_tag_group cinematic_group;

	static constexpr unsigned long CINEMATIC_SCENE_TAG = 'cisc';
	extern s_tag_group cinematic_scene_group;

	static constexpr unsigned long CINEMATIC_TRANSITION_TAG = 'citr';
	extern s_tag_group cinematic_transition_group;

	static constexpr unsigned long SCENARIO_CLUSTER_DATA_RESOURCE_TAG = 'clu*';
	extern s_tag_group scenario_cluster_data_resource_group;

	static constexpr unsigned long CLOTH_TAG = 'clwd';
	extern s_tag_group cloth_group;

	static constexpr unsigned long CAMO_TAG = 'cmoe';
	extern s_tag_group camo_group;

	static constexpr unsigned long CONTRAIL_SYSTEM_TAG = 'cntl';
	extern s_tag_group contrail_system_group;

	static constexpr unsigned long COLLISION_MODEL_TAG = 'coll';
	extern s_tag_group collision_model_group;

	static constexpr unsigned long COLOR_TABLE_TAG = 'colo';
	extern s_tag_group color_table_group;

	static constexpr unsigned long COMMENDATION_GLOBALS_DEFINITION_TAG = 'comg';
	extern s_tag_group commendation_globals_definition_group;

	static constexpr unsigned long COMMUNICATION_SOUNDS_TAG = 'coms';
	extern s_tag_group communication_sounds_group;

	static constexpr unsigned long COOKIE_GLOBALS_DEFINITION_TAG = 'cook';
	extern s_tag_group cookie_globals_definition_group;

	static constexpr unsigned long COOP_SPAWNING_GLOBALS_DEFINITION_TAG = 'coop';
	extern s_tag_group coop_spawning_globals_definition_group;

	static constexpr unsigned long CHEAP_PARTICLE_EMITTER_TAG = 'cpem';
	extern s_tag_group cheap_particle_emitter_group;

	static constexpr unsigned long COOKIE_PURCHASE_GLOBALS_TAG = 'cpgd';
	extern s_tag_group cookie_purchase_globals_group;

	static constexpr unsigned long CHEAP_PARTICLE_TYPE_LIBRARY_TAG = 'cptl';
	extern s_tag_group cheap_particle_type_library_group;

	static constexpr unsigned long CAMERA_SHAKE_TAG = 'csdt';
	extern s_tag_group camera_shake_group;

	static constexpr unsigned long SCENARIO_CUBEMAP_RESOURCE_TAG = 'cub*';
	extern s_tag_group scenario_cubemap_resource_group;

	static constexpr unsigned long CUI_SCREEN_TAG = 'cusc';
	extern s_tag_group cui_screen_group;

	static constexpr unsigned long CUI_STATIC_DATA_TAG = 'cust';
	extern s_tag_group cui_static_data_group;

	static constexpr unsigned long SCENARIO_DECORATORS_RESOURCE_TAG = 'dc*s';
	extern s_tag_group scenario_decorators_resource_group;

	static constexpr unsigned long DECORATOR_SET_TAG = 'dctr';
	extern s_tag_group decorator_set_group;

	static constexpr unsigned long SCENARIO_DECALS_RESOURCE_TAG = 'dec*';
	extern s_tag_group scenario_decals_resource_group;

	static constexpr unsigned long DECAL_SYSTEM_TAG = 'decs';
	extern s_tag_group decal_system_group;

	static constexpr unsigned long CELLULAR_AUTOMATA_TAG = 'devo';
	extern s_tag_group cellular_automata_group;

	static constexpr unsigned long SCENARIO_DEVICES_RESOURCE_TAG = 'dgr*';
	extern s_tag_group scenario_devices_resource_group;

	static constexpr unsigned long SCENARIO_DUMPLINGS_RESOURCE_TAG = 'dmp*';
	extern s_tag_group scenario_dumplings_resource_group;

	static constexpr unsigned long DETAIL_OBJECT_COLLECTION_TAG = 'dobc';
	extern s_tag_group detail_object_collection_group;

	static constexpr unsigned long RASTERIZER_CACHE_FILE_GLOBALS_TAG = 'draw';
	extern s_tag_group rasterizer_cache_file_globals_group;

	static constexpr unsigned long DAMAGE_RESPONSE_DEFINITION_TAG = 'drdf';
	extern s_tag_group damage_response_definition_group;

	static constexpr unsigned long PARTICLE_EMITTER_BOAT_HULL_SHAPE_TAG = 'ebhd';
	extern s_tag_group particle_emitter_boat_hull_shape_group;

	static constexpr unsigned long EFFECT_TAG = 'effe';
	extern s_tag_group effect_group;

	static constexpr unsigned long EFFECT_GLOBALS_TAG = 'effg';
	extern s_tag_group effect_globals_group;

	static constexpr unsigned long FLOCK_TAG = 'flck';
	extern s_tag_group flock_group;

	static constexpr unsigned long FLUID_DYNAMICS_TAG = 'fldy';
	extern s_tag_group fluid_dynamics_group;

	static constexpr unsigned long ATMOSPHERE_FOG_TAG = 'fogg';
	extern s_tag_group atmosphere_fog_group;

	static constexpr unsigned long MATERIAL_EFFECTS_TAG = 'foot';
	extern s_tag_group material_effects_group;

	static constexpr unsigned long FORMATION_TAG = 'form';
	extern s_tag_group formation_group;

	static constexpr unsigned long FRAME_EVENT_LIST_TAG = 'frms';
	extern s_tag_group frame_event_list_group;

	static constexpr unsigned long FX_TEST_TAG = 'fxtt';
	extern s_tag_group fx_test_group;

	static constexpr unsigned long GAME_COMPLETION_REWARDS_GLOBALS_TAG = 'gcrg';
	extern s_tag_group game_completion_rewards_globals_group;

	static constexpr unsigned long GAME_ENGINE_GLOBALS_TAG = 'gegl';
	extern s_tag_group game_engine_globals_group;

	static constexpr unsigned long CHEAP_LIGHT_TAG = 'gldf';
	extern s_tag_group cheap_light_group;

	static constexpr unsigned long GLOBAL_PIXEL_SHADER_TAG = 'glps';
	extern s_tag_group global_pixel_shader_group;

	static constexpr unsigned long GLOBAL_VERTEX_SHADER_TAG = 'glvs';
	extern s_tag_group global_vertex_shader_group;

	static constexpr unsigned long GAME_MEDAL_GLOBALS_TAG = 'gmeg';
	extern s_tag_group game_medal_globals_group;

	static constexpr unsigned long MULTIPLAYER_VARIANT_SETTINGS_INTERFACE_DEFINITION_TAG = 'goof';
	extern s_tag_group multiplayer_variant_settings_interface_definition_group;

	static constexpr unsigned long GLOBAL_CACHE_FILE_PIXEL_SHADERS_TAG = 'gpix';
	extern s_tag_group global_cache_file_pixel_shaders_group;

	static constexpr unsigned long GAME_PERFORMANCE_THROTTLE_TAG = 'gptd';
	extern s_tag_group game_performance_throttle_group;

	static constexpr unsigned long GROUNDED_FRICTION_TAG = 'grfr';
	extern s_tag_group grounded_friction_group;

	static constexpr unsigned long HAVOK_COLLISION_FILTER_TAG = 'hcfd';
	extern s_tag_group havok_collision_filter_group;

	static constexpr unsigned long MODEL_TAG = 'hlmt';
	extern s_tag_group model_group;

	static constexpr unsigned long HLSL_INCLUDE_TAG = 'hlsl';
	extern s_tag_group hlsl_include_group;

	static constexpr unsigned long SCENARIO_HS_SOURCE_FILE_TAG = 'hsc*';
	extern s_tag_group scenario_hs_source_file_group;

	static constexpr unsigned long INCIDENT_GLOBAL_PROPERTIES_DEFINITION_TAG = 'igpd';
	extern s_tag_group incident_global_properties_definition_group;

	static constexpr unsigned long INSTANCE_IMPOSTER_DEFINITION_TAG = 'iimz';
	extern s_tag_group instance_imposter_definition_group;

	static constexpr unsigned long IMPOSTER_MODEL_TAG = 'impo';
	extern s_tag_group imposter_model_group;

	static constexpr unsigned long INCIDENT_GLOBALS_DEFINITION_TAG = 'ingd';
	extern s_tag_group incident_globals_definition_group;

	static constexpr unsigned long MODEL_ANIMATION_GRAPH_TAG = 'jmad';
	extern s_tag_group model_animation_graph_group;

	static constexpr unsigned long SANDBOX_TEXT_VALUE_PAIR_DEFINITION_TAG = 'jmrq';
	extern s_tag_group sandbox_text_value_pair_definition_group;

	static constexpr unsigned long DAMAGE_EFFECT_TAG = 'jpt!';
	extern s_tag_group damage_effect_group;

	static constexpr unsigned long LOAD_SCREEN_GLOBALS_TAG = 'ldsc';
	extern s_tag_group load_screen_globals_group;

	static constexpr unsigned long LENS_FLARE_TAG = 'lens';
	extern s_tag_group lens_flare_group;

	static constexpr unsigned long LOADOUT_GLOBALS_DEFINITION_TAG = 'lgtd';
	extern s_tag_group loadout_globals_definition_group;

	static constexpr unsigned long LIGHT_TAG = 'ligh';
	extern s_tag_group light_group;

	static constexpr unsigned long LOCATION_NAME_GLOBALS_DEFINITION_TAG = 'locs';
	extern s_tag_group location_name_globals_definition_group;

	static constexpr unsigned long SOUND_LOOPING_TAG = 'lsnd';
	extern s_tag_group sound_looping_group;

	static constexpr unsigned long LEAF_SYSTEM_TAG = 'lswd';
	extern s_tag_group leaf_system_group;

	static constexpr unsigned long LIGHT_VOLUME_SYSTEM_TAG = 'ltvl';
	extern s_tag_group light_volume_system_group;

	static constexpr unsigned long GLOBALS_TAG = 'matg';
	extern s_tag_group globals_group;

	static constexpr unsigned long AI_MISSION_DIALOGUE_TAG = 'mdlg';
	extern s_tag_group ai_mission_dialogue_group;

	static constexpr unsigned long METER_TAG = 'metr';
	extern s_tag_group meter_group;

	static constexpr unsigned long MUFFIN_TAG = 'mffn';
	extern s_tag_group muffin_group;

	static constexpr unsigned long MEGALOGAMENGINE_SOUNDS_TAG = 'mgls';
	extern s_tag_group megalogamengine_sounds_group;

	static constexpr unsigned long EMBLEM_LIBRARY_TAG = 'mlib';
	extern s_tag_group emblem_library_group;

	static constexpr unsigned long RENDER_MODEL_TAG = 'mode';
	extern s_tag_group render_model_group;

	static constexpr unsigned long MULTIPLAYER_OBJECT_TYPE_LIST_TAG = 'motl';
	extern s_tag_group multiplayer_object_type_list_group;

	static constexpr unsigned long MULTIPLAYER_SCENARIO_DESCRIPTION_TAG = 'mply';
	extern s_tag_group multiplayer_scenario_description_group;

	static constexpr unsigned long MEGALO_STRING_ID_TABLE_TAG = 'msit';
	extern s_tag_group megalo_string_id_table_group;

	static constexpr unsigned long MULTIPLAYER_GLOBALS_TAG = 'mulg';
	extern s_tag_group multiplayer_globals_group;

	static constexpr unsigned long MUX_GENERATOR_TAG = 'muxg';
	extern s_tag_group mux_generator_group;

	static constexpr unsigned long NEW_CINEMATIC_LIGHTING_TAG = 'nclt';
	extern s_tag_group new_cinematic_lighting_group;

	static constexpr unsigned long OBJECT_TAG = 'obje';
	extern s_tag_group object_group;

	static constexpr unsigned long TAG_PACKAGE_MANIFEST_TAG = 'pach';
	extern s_tag_group tag_package_manifest_group;

	static constexpr unsigned long PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_TAG = 'pcec';
	extern s_tag_group pgcr_enemy_to_category_mapping_definition_group;

	static constexpr unsigned long PARTICLE_EMITTER_CUSTOM_POINTS_TAG = 'pecp';
	extern s_tag_group particle_emitter_custom_points_group;

	static constexpr unsigned long PERFORMANCE_THROTTLES_TAG = 'perf';
	extern s_tag_group performance_throttles_group;

	static constexpr unsigned long PERFORMANCE_TEMPLATE_TAG = 'pfmc';
	extern s_tag_group performance_template_group;

	static constexpr unsigned long PLANAR_FOG_PARAMETERS_TAG = 'pfpt';
	extern s_tag_group planar_fog_parameters_group;

	static constexpr unsigned long PLAYER_GRADE_GLOBALS_DEFINITION_TAG = 'pggd';
	extern s_tag_group player_grade_globals_definition_group;

	static constexpr unsigned long PHYSICS_MODEL_TAG = 'phmo';
	extern s_tag_group physics_model_group;

	static constexpr unsigned long PIXEL_SHADER_TAG = 'pixl';
	extern s_tag_group pixel_shader_group;

	static constexpr unsigned long CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG = 'play';
	extern s_tag_group cache_file_resource_layout_table_group;

	static constexpr unsigned long PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG = 'pmcg';
	extern s_tag_group player_model_customization_globals_group;

	static constexpr unsigned long PARTICLE_MODEL_TAG = 'pmdf';
	extern s_tag_group particle_model_group;

	static constexpr unsigned long PARTICLE_PHYSICS_TAG = 'pmov';
	extern s_tag_group particle_physics_group;

	static constexpr unsigned long POINT_PHYSICS_TAG = 'pphy';
	extern s_tag_group point_physics_group;

	static constexpr unsigned long SCENARIO_PERFORMANCES_RESOURCE_TAG = 'prf*';
	extern s_tag_group scenario_performances_resource_group;

	static constexpr unsigned long PROJECTILE_TAG = 'proj';
	extern s_tag_group projectile_group;

	static constexpr unsigned long PARTICLE_TAG = 'prt3';
	extern s_tag_group particle_group;

	static constexpr unsigned long RAIN_DEFINITION_TAG = 'rain';
	extern s_tag_group rain_definition_group;

	static constexpr unsigned long RASTERIZER_GLOBALS_TAG = 'rasg';
	extern s_tag_group rasterizer_globals_group;

	static constexpr unsigned long RENDER_METHOD_TAG = 'rm  ';
	extern s_tag_group render_method_group;

	static constexpr unsigned long SHADER_BEAM_TAG = 'rmb ';
	extern s_tag_group shader_beam_group;

	static constexpr unsigned long RUMBLE_TAG = 'rmbl';
	extern s_tag_group rumble_group;

	static constexpr unsigned long SHADER_CUSTOM_TAG = 'rmcs';
	extern s_tag_group shader_custom_group;

	static constexpr unsigned long SHADER_CORTANA_TAG = 'rmct';
	extern s_tag_group shader_cortana_group;

	static constexpr unsigned long SHADER_DECAL_TAG = 'rmd ';
	extern s_tag_group shader_decal_group;

	static constexpr unsigned long RENDER_METHOD_DEFINITION_TAG = 'rmdf';
	extern s_tag_group render_method_definition_group;

	static constexpr unsigned long SHADER_FOLIAGE_TAG = 'rmfl';
	extern s_tag_group shader_foliage_group;

	static constexpr unsigned long SHADER_FUR_STENCIL_TAG = 'rmfs';
	extern s_tag_group shader_fur_stencil_group;

	static constexpr unsigned long SHADER_FUR_TAG = 'rmfu';
	extern s_tag_group shader_fur_group;

	static constexpr unsigned long SHADER_GLASS_TAG = 'rmgl';
	extern s_tag_group shader_glass_group;

	static constexpr unsigned long SHADER_HALOGRAM_TAG = 'rmhg';
	extern s_tag_group shader_halogram_group;

	static constexpr unsigned long SHADER_LIGHT_VOLUME_TAG = 'rmlv';
	extern s_tag_group shader_light_volume_group;

	static constexpr unsigned long SHADER_MUX_MATERIAL_TAG = 'rmmm';
	extern s_tag_group shader_mux_material_group;

	static constexpr unsigned long SHADER_MUX_TAG = 'rmmx';
	extern s_tag_group shader_mux_group;

	static constexpr unsigned long RENDER_METHOD_OPTION_TAG = 'rmop';
	extern s_tag_group render_method_option_group;

	static constexpr unsigned long SHADER_TAG = 'rmsh';
	extern s_tag_group shader_group;

	static constexpr unsigned long SHADER_SKIN_TAG = 'rmsk';
	extern s_tag_group shader_skin_group;

	static constexpr unsigned long SHADER_SCREEN_TAG = 'rmss';
	extern s_tag_group shader_screen_group;

	static constexpr unsigned long RENDER_METHOD_TEMPLATE_TAG = 'rmt2';
	extern s_tag_group render_method_template_group;

	static constexpr unsigned long SHADER_TERRAIN_TAG = 'rmtr';
	extern s_tag_group shader_terrain_group;

	static constexpr unsigned long SHADER_WATER_TAG = 'rmw ';
	extern s_tag_group shader_water_group;

	static constexpr unsigned long RENDER_WATER_RIPPLE_TAG = 'rwrd';
	extern s_tag_group render_water_ripple_group;

	static constexpr unsigned long SCENARIO_FAUX_DATA_TAG = 'sFdT';
	extern s_tag_group scenario_faux_data_group;

	static constexpr unsigned long SCENARIO_LIGHTMAP_TAG = 'sLdT';
	extern s_tag_group scenario_lightmap_group;

	static constexpr unsigned long SPRING_ACCELERATION_TAG = 'sadt';
	extern s_tag_group spring_acceleration_group;

	static constexpr unsigned long SCENARIO_STRUCTURE_BSP_TAG = 'sbsp';
	extern s_tag_group scenario_structure_bsp_group;

	static constexpr unsigned long SCENERY_TAG = 'scen';
	extern s_tag_group scenery_group;

	static constexpr unsigned long SOUND_COMBINER_TAG = 'scmb';
	extern s_tag_group sound_combiner_group;

	static constexpr unsigned long SCENARIO_TAG = 'scnr';
	extern s_tag_group scenario_group;

	static constexpr unsigned long STRUCTURE_DESIGN_TAG = 'sddt';
	extern s_tag_group structure_design_group;

	static constexpr unsigned long SCENARIO_REQUIRED_RESOURCE_TAG = 'sdzg';
	extern s_tag_group scenario_required_resource_group;

	static constexpr unsigned long AREA_SCREEN_EFFECT_TAG = 'sefc';
	extern s_tag_group area_screen_effect_group;

	static constexpr unsigned long SOUND_EFFECT_COLLECTION_TAG = 'sfx+';
	extern s_tag_group sound_effect_collection_group;

	static constexpr unsigned long SOUND_GLOBAL_PROPAGATION_TAG = 'sgp!';
	extern s_tag_group sound_global_propagation_group;

	static constexpr unsigned long SHIELD_IMPACT_TAG = 'shit';
	extern s_tag_group shield_impact_group;

	static constexpr unsigned long SIMULATED_INPUT_TAG = 'sidt';
	extern s_tag_group simulated_input_group;

	static constexpr unsigned long SIMULATION_INTERPOLATION_TAG = 'siin';
	extern s_tag_group simulation_interpolation_group;

	static constexpr unsigned long TEXT_VALUE_PAIR_DEFINITION_TAG = 'sily';
	extern s_tag_group text_value_pair_definition_group;

	static constexpr unsigned long SCENARIO_INTERPOLATOR_TAG = 'sirp';
	extern s_tag_group scenario_interpolator_group;

	static constexpr unsigned long SCENARIO_SKY_REFERENCES_RESOURCE_TAG = 'sky*';
	extern s_tag_group scenario_sky_references_resource_group;

	static constexpr unsigned long SKY_ATM_PARAMETERS_TAG = 'skya';
	extern s_tag_group sky_atm_parameters_group;

	static constexpr unsigned long SURVIVAL_MODE_GLOBALS_TAG = 'smdt';
	extern s_tag_group survival_mode_globals_group;

	static constexpr unsigned long SOUND_CLASSES_TAG = 'sncl';
	extern s_tag_group sound_classes_group;

	static constexpr unsigned long SOUND_TAG = 'snd!';
	extern s_tag_group sound_group;

	static constexpr unsigned long SOUND_ENVIRONMENT_TAG = 'snde';
	extern s_tag_group sound_environment_group;

	static constexpr unsigned long SOUND_MIX_TAG = 'snmx';
	extern s_tag_group sound_mix_group;

	static constexpr unsigned long SOUND_DIALOGUE_CONSTANTS_TAG = 'spk!';
	extern s_tag_group sound_dialogue_constants_group;

	static constexpr unsigned long SQUAD_TEMPLATE_TAG = 'sqtm';
	extern s_tag_group squad_template_group;

	static constexpr unsigned long SOUND_RADIO_SETTINGS_TAG = 'srad';
	extern s_tag_group sound_radio_settings_group;

	static constexpr unsigned long SSAO_DEFINITION_TAG = 'ssao';
	extern s_tag_group ssao_definition_group;

	static constexpr unsigned long SOUND_SCENERY_TAG = 'ssce';
	extern s_tag_group sound_scenery_group;

	static constexpr unsigned long SCENARIO_STRUCTURE_LIGHTING_RESOURCE_TAG = 'sslt';
	extern s_tag_group scenario_structure_lighting_resource_group;

	static constexpr unsigned long SCENARIO_STRUCTURE_LIGHTING_INFO_TAG = 'stli';
	extern s_tag_group scenario_structure_lighting_info_group;

	static constexpr unsigned long STRUCTURE_SEAMS_TAG = 'stse';
	extern s_tag_group structure_seams_group;

	static constexpr unsigned long STYLE_TAG = 'styl';
	extern s_tag_group style_group;

	static constexpr unsigned long CAMERA_TRACK_TAG = 'trak';
	extern s_tag_group camera_track_group;

	static constexpr unsigned long SCENARIO_TRIGGER_VOLUMES_RESOURCE_TAG = 'trg*';
	extern s_tag_group scenario_trigger_volumes_resource_group;

	static constexpr unsigned long DIALOGUE_TAG = 'udlg';
	extern s_tag_group dialogue_group;

	static constexpr unsigned long SOUND_CACHE_FILE_GESTALT_TAG = 'ugh!';
	extern s_tag_group sound_cache_file_gestalt_group;

	static constexpr unsigned long USER_INTERFACE_SOUNDS_DEFINITION_TAG = 'uise';
	extern s_tag_group user_interface_sounds_definition_group;

	static constexpr unsigned long MULTILINGUAL_UNICODE_STRING_LIST_TAG = 'unic';
	extern s_tag_group multilingual_unicode_string_list_group;

	static constexpr unsigned long UNIT_TAG = 'unit';
	extern s_tag_group unit_group;

	static constexpr unsigned long VEHICLE_TAG = 'vehi';
	extern s_tag_group vehicle_group;

	static constexpr unsigned long VISION_MODE_TAG = 'vmdx';
	extern s_tag_group vision_mode_group;

	static constexpr unsigned long VARIANT_GLOBALS_TAG = 'vtgl';
	extern s_tag_group variant_globals_group;

	static constexpr unsigned long VERTEX_SHADER_TAG = 'vtsh';
	extern s_tag_group vertex_shader_group;

	static constexpr unsigned long CHUD_WIDGET_ANIMATION_DATA_TEMPLATE_TAG = 'wadt';
	extern s_tag_group chud_widget_animation_data_template_group;

	static constexpr unsigned long WAVE_TEMPLATE_TAG = 'wave';
	extern s_tag_group wave_template_group;

	static constexpr unsigned long CHUD_WIDGET_DATASOURCE_TEMPLATE_TAG = 'wdst';
	extern s_tag_group chud_widget_datasource_template_group;

	static constexpr unsigned long SCENARIO_WETNESS_BSP_DATA_TAG = 'wetn';
	extern s_tag_group scenario_wetness_bsp_data_group;

	static constexpr unsigned long GAME_ENGINE_SETTINGS_DEFINITION_TAG = 'wezr';
	extern s_tag_group game_engine_settings_definition_group;

	static constexpr unsigned long USER_INTERFACE_GLOBALS_DEFINITION_TAG = 'wgtz';
	extern s_tag_group user_interface_globals_definition_group;

	static constexpr unsigned long CELLULAR_AUTOMATA2D_TAG = 'whip';
	extern s_tag_group cellular_automata2d_group;

	static constexpr unsigned long USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG = 'wigl';
	extern s_tag_group user_interface_shared_globals_definition_group;

	static constexpr unsigned long WIND_TAG = 'wind';
	extern s_tag_group wind_group;

	static constexpr unsigned long WATER_PHYSICS_DRAG_PROPERTIES_TAG = 'wpdp';
	extern s_tag_group water_physics_drag_properties_group;

	static constexpr unsigned long CHUD_WIDGET_PLACEMENT_DATA_TEMPLATE_TAG = 'wpdt';
	extern s_tag_group chud_widget_placement_data_template_group;

	static constexpr unsigned long CHUD_WIDGET_RENDER_DATA_TEMPLATE_TAG = 'wrdt';
	extern s_tag_group chud_widget_render_data_template_group;

	static constexpr unsigned long CHUD_WIDGET_STATE_DATA_TEMPLATE_TAG = 'wsdt';
	extern s_tag_group chud_widget_state_data_template_group;

	static constexpr unsigned long WEATHER_GLOBALS_TAG = 'wxcg';
	extern s_tag_group weather_globals_group;

	static constexpr unsigned long CACHE_FILE_RESOURCE_GESTALT_TAG = 'zone';
	extern s_tag_group cache_file_resource_gestalt_group;

	static constexpr unsigned long SHADER_CONTRAIL_TAG = 'rmc';
	extern s_tag_group shader_contrail_group;

	static constexpr unsigned long SHADER_PARTICLE_TAG = 'rmp';
	extern s_tag_group shader_particle_group;

	static constexpr unsigned long BIPED_TAG = 'bipd';
	extern s_tag_group biped_group;

	static constexpr unsigned long CRATE_TAG = 'bloc';
	extern s_tag_group crate_group;

	static constexpr unsigned long CREATURE_TAG = 'crea';
	extern s_tag_group creature_group;

	static constexpr unsigned long DEVICE_TAG = 'devi';
	extern s_tag_group device_group;

	static constexpr unsigned long EFFECT_SCENERY_TAG = 'efsc';
	extern s_tag_group effect_scenery_group;

	static constexpr unsigned long GIANT_TAG = 'gint';
	extern s_tag_group giant_group;

	static constexpr unsigned long ITEM_TAG = 'item';
	extern s_tag_group item_group;

	static constexpr unsigned long DEVICE_MACHINE_TAG = 'mach';
	extern s_tag_group device_machine_group;

	static constexpr unsigned long DEVICE_TERMINAL_TAG = 'term';
	extern s_tag_group device_terminal_group;

	static constexpr unsigned long WEAPON_TAG = 'weap';
	extern s_tag_group weapon_group;

	static constexpr unsigned long DEVICE_CONTROL_TAG = 'ctrl';
	extern s_tag_group device_control_group;

	static constexpr unsigned long EQUIPMENT_TAG = 'eqip';
	extern s_tag_group equipment_group;

	extern s_tag_block_definition camera_fx_settings_block_group_block;

	extern s_tag_block_definition performane_throttle_block_block;

	extern s_tag_block_definition performance_throttles_block_group_block;

	extern s_tag_block_definition default_textures_refs_block_block;

	extern s_tag_block_definition material_textures_refs_block_block;

	extern s_tag_block_definition atmosphere_textures_refs_block_block;

	extern s_tag_block_definition explicit_shader_refs_block_block;

	extern s_tag_block_definition rasterizer_globals_block_group_block;

	extern s_tag_block_definition rasterizer_constant_block_block;

	extern s_tag_block_definition vertex_types_block_block$2;

	extern s_tag_block_definition compiled_vertex_shader_block_block;

	extern s_tag_block_definition vertex_entry_point_block_block;

	extern s_tag_block_definition pixel_entry_point_block_block;

	extern s_tag_block_definition compiled_pixel_shader_block_block;

	extern s_tag_block_definition vertex_shader_block_group_block;

	extern s_tag_block_definition pixel_shader_block_group_block;

	extern s_tag_block_definition global_cache_file_pixel_shaders_block_group_block;

	extern s_tag_block_definition hlsl_include_block_group_block;

	extern s_tag_block_definition global_shader_option_dependency_block;

	extern s_tag_block_definition global_shader_category_dependency_block;

	extern s_tag_block_definition global_shader_entry_point_block_block;

	extern s_tag_block_definition global_vertex_shader_vertex_types_block_block;

	extern s_tag_block_definition global_vertex_shader_block_group_block;

	extern s_tag_block_definition global_pixel_shader_block_group_block;

	extern s_tag_block_definition shader_block_group_block;

	extern s_tag_block_definition shader_custom_block_group_block;

	extern s_tag_block_definition shader_halogram_block_group_block;

	extern s_tag_block_definition shader_fur_block_group_block;

	extern s_tag_block_definition shader_fur_stencil_block_group_block;

	extern s_tag_block_definition shader_foliage_block_group_block;

	extern s_tag_block_definition shader_glass_block_group_block;

	extern s_tag_block_definition shader_skin_block_group_block;

	extern s_tag_block_definition shader_cortana_block_group_block;

	extern s_tag_block_definition shader_terrain_block_group_block;

	extern s_tag_block_definition shader_mux_material_block_group_block;

	extern s_tag_block_definition shader_mux_block_group_block;

	extern s_tag_block_definition shader_particle_block_group_block;

	extern s_tag_block_definition shader_contrail_block_group_block;

	extern s_tag_block_definition shader_light_volume_block_group_block;

	extern s_tag_block_definition shader_beam_block_group_block;

	extern s_tag_block_definition shader_decal_block_group_block;

	extern s_tag_block_definition shader_water_block_group_block;

	extern s_tag_block_definition shader_screen_block_group_block;

	extern s_tag_block_definition tag_block_index_block_block;

	extern s_tag_block_definition short_block_block;

	extern s_tag_block_definition real_vector4d_block_block;

	extern s_tag_block_definition int_block_block;

	extern s_tag_block_definition render_method_options_block_block;

	extern s_tag_block_definition render_method_category_block_block;

	extern s_tag_block_definition render_method_pass_category_dependencies_block;

	extern s_tag_block_definition render_method_pass_block_block;

	extern s_tag_block_definition render_method_entry_points_block_block;

	extern s_tag_block_definition vertex_types_block_block;

	extern s_tag_block_definition render_method_definition_block_group_block;

	extern s_tag_block_definition render_method_option_parameter_block_block;

	extern s_tag_block_definition render_method_option_block_group_block;

	extern s_tag_block_definition render_method_locked_parameter_block_block;

	extern s_tag_block_definition render_method_animated_parameter_block_block;

	extern s_tag_block_definition render_method_parameter_block_block;

	extern s_tag_block_definition render_method_postprocess_texture_block_block;

	extern s_tag_block_definition render_method_postprocess_pass_block_block;

	extern s_tag_block_definition render_method_routing_info_block_block;

	extern s_tag_block_definition render_method_postprocess_block_block;

	extern s_tag_block_definition render_method_block_group_block;

	extern s_tag_block_definition render_method_template_constant_table_block_block;

	extern s_tag_block_definition render_method_template_pass_block_block;

	extern s_tag_block_definition render_method_template_platform_block_block;

	extern s_tag_block_definition render_method_template_block_group_block;

	extern s_tag_block_definition planar_fog_parameters_block_group_block;

	extern s_tag_block_definition planar_fog_vertex_block_block;

	extern s_tag_block_definition planar_fog_triangle_planes_block_block;

	extern s_tag_block_definition planar_fog_triangle_block_block;

	extern s_tag_block_definition planar_fog_definition_block_block;

	extern s_tag_block_definition planar_fog_reference_definition_block_block;

	extern s_tag_block_definition planar_fog_cluster_visibility_definition_block_block;

	extern s_tag_block_definition planar_fog_structure_visibility_definition_block_block;

	extern s_tag_block_definition planar_fog_zone_set_visibility_definition_block_block;

	extern s_tag_block_definition ssao_definition_block_group_block;

	extern s_tag_block_definition underwater_setting_block_block;

	extern s_tag_block_definition atmosphere_globals_block_group_block;

	extern s_tag_block_definition per_object_type_relative_min_luminance_block_block;

	extern s_tag_block_definition chocolate_mountain_new_block_group_block;

	extern s_tag_block_definition global_textures_refs_block_block;

	extern s_tag_block_definition weather_globals_block_group_block;

	extern s_tag_block_definition decorator_set_instance_name_block_block;

	extern s_tag_block_definition global_decorator_type_block_block;

	extern s_tag_block_definition decorator_set_block_group_block;

	extern s_tag_block_definition decorator_runtime_cluster_block_block;

	extern s_tag_block_definition atmosphere_definition_block_group_block;

	extern s_tag_block_definition rain_definition_block_group_block;

	extern s_tag_block_definition light_block_group_block;

	extern s_tag_block_definition equipment_type_multiplayer_powerup_block_block;

	extern s_tag_block_definition equipment_type_spawner_block_block;

	extern s_tag_block_definition equipment_type_proximity_mine_block_block;

	extern s_tag_block_definition equipment_type_motion_tracker_noise_block_block;

	extern s_tag_block_definition equipment_type_showme_block_block;

	extern s_tag_block_definition equipment_effect_with_threshold_block_block;

	extern s_tag_block_definition equipment_type_invincibility_block_block;

	extern s_tag_block_definition equipment_type_treeoflife_block_block;

	extern s_tag_block_definition equipment_type_shapeshifter_block_block;

	extern s_tag_block_definition equipment_type_player_trait_field_block_block;

	extern s_tag_block_definition ai_equipment_trait_appearance_block_block;

	extern s_tag_block_definition ai_equipment_traits_block_block;

	extern s_tag_block_definition equipment_type_ai_trait_field_block_block;

	extern s_tag_block_definition equipment_type_repulsor_field_block_block;

	extern s_tag_block_definition equipment_type_daddy_block_block;

	extern s_tag_block_definition equipment_type_laser_designation_block_block;

	extern s_tag_block_definition equipment_type_super_jump_block_block;

	extern s_tag_block_definition equipment_type_ammo_pack_block_block;

	extern s_tag_block_definition equipment_type_power_fist_block_block;

	extern s_tag_block_definition equipment_type_health_pack_block_block;

	extern s_tag_block_definition equipment_type_jet_pack_block_block;

	extern s_tag_block_definition equipment_type_hologram_block_block;

	extern s_tag_block_definition equipment_type_special_weapon_block_block;

	extern s_tag_block_definition equipment_type_special_move_block_block;

	extern s_tag_block_definition equipment_type_engineer_shields_block_block;

	extern s_tag_block_definition equipment_type_sprint_block_block;

	extern s_tag_block_definition optional_unit_camera_block_block;

	extern s_tag_block_definition equipment_block_group_block;

	extern s_tag_block_definition airstrike_fire_location_block_block;

	extern s_tag_block_definition airstrike_battery_block_block;

	extern s_tag_block_definition airstrike_block_group_block;

	extern s_tag_block_definition brute_grenade_block_block;

	extern s_tag_block_definition fire_bomb_grenade_block_block;

	extern s_tag_block_definition conical_projection_block_block;

	extern s_tag_block_definition old_projectile_material_response_block_block;

	extern s_tag_block_definition projectile_material_response_block_block;

	extern s_tag_block_definition projectile_block_group_block;

	extern s_tag_block_definition tracking_type_block_block;

	extern s_tag_block_definition global_target_tracking_parameters_block_block;

	extern s_tag_block_definition magazine_objects_block;

	extern s_tag_block_definition magazines_block;

	extern s_tag_block_definition weapon_barrel_first_person_offset_block_block;

	extern s_tag_block_definition barrel_firing_effect_block_block;

	extern s_tag_block_definition weapon_barrel_function_block_block;

	extern s_tag_block_definition weapon_barrels_block;

	extern s_tag_block_definition weapon_trigger_charging_fire_fraction_block;

	extern s_tag_block_definition weapon_triggers_block;

	extern s_tag_block_definition melee_damage_parameters_block_block;

	extern s_tag_block_definition weapon_first_person_interface_block_block;

	extern s_tag_block_definition weapon_screen_effect_block_block;

	extern s_tag_block_definition weapon_block_group_block;

	extern s_tag_block_definition garbage_collection_block_block;

	extern s_tag_block_definition unit_hud_reference_block_block;

	extern s_tag_block_definition unit_camera_track_block_block;

	extern s_tag_block_definition unit_camera_acceleration_displacement_block_block;

	extern s_tag_block_definition unit_postures_block_block;

	extern s_tag_block_definition unit_seat_block_block;

	extern s_tag_block_definition boarding_seat_block_block;

	extern s_tag_block_definition unit_weapon_block_block;

	extern s_tag_block_definition powered_seat_block_block;

	extern s_tag_block_definition dialogue_variant_block_block;

	extern s_tag_block_definition unit_screen_effect_block_block;

	extern s_tag_block_definition unit_block_group_block;

	extern s_tag_block_definition area_control_block_block;

	extern s_tag_block_definition damage_response_global_sound_effect_block_block;

	extern s_tag_block_definition damage_response_class_block_block;

	extern s_tag_block_definition damage_response_definition_block_group_block;

	extern s_tag_block_definition custom_damage_response_label_block_block;

	extern s_tag_block_definition damage_effect_sound_block_block;

	extern s_tag_block_definition damage_effect_block_group_block;

	extern s_tag_block_definition muffin_permutation_name_block_block;

	extern s_tag_block_definition global_muffin_type_block_block;

	extern s_tag_block_definition muffin_marker_block_block;

	extern s_tag_block_definition muffin_block_group_block;

	extern s_tag_block_definition leaf_type_block_block;

	extern s_tag_block_definition leaf_system_block_group_block;

	extern s_tag_block_definition cloth_vertices_block_block;

	extern s_tag_block_definition cloth_indices_block_block;

	extern s_tag_block_definition cloth_links_block_block;

	extern s_tag_block_definition collision_sphere_block_block;

	extern s_tag_block_definition cloth_block_group_block;

	extern s_tag_block_definition creature_scalar_timing_block_block;

	extern s_tag_block_definition creature_block_group_block;

	extern s_tag_block_definition big_battle_creature_block_group_block;

	extern s_tag_block_definition device_block_group_block;

	extern s_tag_block_definition device_machine_block_group_block;

	extern s_tag_block_definition terminal_page_block_definition_block;

	extern s_tag_block_definition device_terminal_block_group_block;

	extern s_tag_block_definition device_control_block_group_block;

	extern s_tag_block_definition human_tank_block_block;

	extern s_tag_block_definition human_jeep_block_block;

	extern s_tag_block_definition wolverine_block_block;

	extern s_tag_block_definition human_plane_block_block;

	extern s_tag_block_definition alien_scout_block_block;

	extern s_tag_block_definition jackal_glider_block_block;

	extern s_tag_block_definition alien_fighter_block_block;

	extern s_tag_block_definition turret_block_block;

	extern s_tag_block_definition mantis_block_block;

	extern s_tag_block_definition guardian_block_block;

	extern s_tag_block_definition vtol_speed_interpolated_block_block;

	extern s_tag_block_definition vtol_block_block;

	extern s_tag_block_definition chopper_block_block;

	extern s_tag_block_definition boat_block_block;

	extern s_tag_block_definition space_fighter_block_block;

	extern s_tag_block_definition revenant_block_block;

	extern s_tag_block_definition vehicle_block_group_block;

	extern s_tag_block_definition contact_point_block_block;

	extern s_tag_block_definition biped_movement_gate_block_block;

	extern s_tag_block_definition biped_camera_height_block_block;

	extern s_tag_block_definition biped_wall_proximity_block_block;

	extern s_tag_block_definition biped_block_group_block;

	extern s_tag_block_definition object_function_interpolation_block_block;

	extern s_tag_block_definition object_runtime_interpolator_functions_block_block;

	extern s_tag_block_definition object_function_block_block;

	extern s_tag_block_definition global_object_attachment_block_block;

	extern s_tag_block_definition object_widget_block_block;

	extern s_tag_block_definition object_change_color_initial_permutation_block;

	extern s_tag_block_definition object_change_color_function_block;

	extern s_tag_block_definition object_change_colors_block;

	extern s_tag_block_definition multiplayer_object_block_block;

	extern s_tag_block_definition object_ai_properties_block_block;

	extern s_tag_block_definition object_spawn_effects_block_block;

	extern s_tag_block_definition object_early_mover_obb_block_block;

	extern s_tag_block_definition object_block_group_block;

	extern s_tag_block_definition unit_trick_definition_block_block;

	extern s_tag_block_definition gear_block_block;

	extern s_tag_block_definition load_and_cruise_block_block;

	extern s_tag_block_definition death_program_velocity_gate_block_block;

	extern s_tag_block_definition death_program_damage_reporting_block_block;

	extern s_tag_block_definition death_program_special_block_block;

	extern s_tag_block_definition death_program_selector_block_group_block;

	extern s_tag_block_definition structure_lighting_generic_light_definition_block_block$2;

	extern s_tag_block_definition structure_lighting_generic_light_instance_block_block;

	extern s_tag_block_definition screen_space_light_shader_override_block_block;

	extern s_tag_block_definition structure_lighting_region_triangle_block_block;

	extern s_tag_block_definition structure_lighting_region_block_block;

	extern s_tag_block_definition structure_material_lighting_info_block_block;

	extern s_tag_block_definition structure_instance_imposter_info_block_block;

	extern s_tag_block_definition scenario_structure_lighting_info_block_group_block;

	extern s_tag_block_definition effect_component_holdback_block_block;

	extern s_tag_block_definition effect_component_holdbacks_block_block;

	extern s_tag_block_definition effect_global_spawn_effects_block_block;

	extern s_tag_block_definition effect_globals_block_group_block;

	extern s_tag_block_definition light_volume_precompiled_vert_block_block;

	extern s_tag_block_definition light_volume_definition_block_block;

	extern s_tag_block_definition light_volume_system_block_group_block;

	extern s_tag_block_definition attachment_block_block;

	extern s_tag_block_definition gpu_sprite_block_block;

	extern s_tag_block_definition gpu_variants_block_block;

	extern s_tag_block_definition particle_block_group_block;

	extern s_tag_block_definition particle_controller_parameters_block;

	extern s_tag_block_definition particle_controller_block;

	extern s_tag_block_definition particle_physics_block_group_block;

	extern s_tag_block_definition gpu_function_block_block;

	extern s_tag_block_definition gpu_color_block_block;

	extern s_tag_block_definition gpu_property_block_block;

	extern s_tag_block_definition particle_system_emitter_definition_block_block;

	extern s_tag_block_definition particle_system_definition_block_new_block;

	extern s_tag_block_definition particle_model_block_group_block;

	extern s_tag_block_definition sorting_position_block_block;

	extern s_tag_block_definition part_block_block;

	extern s_tag_block_definition subpart_block_block;

	extern s_tag_block_definition indices_word_block_block;

	extern s_tag_block_definition indices_dword_block_block;

	extern s_tag_block_definition raw_vertex_block_block;

	extern s_tag_block_definition raw_water_append_block_block;

	extern s_tag_block_definition raw_water_block_block;

	extern s_tag_block_definition raw_imposter_brdf_block_block;

	extern s_tag_block_definition raw_instance_imposter_block_block;

	extern s_tag_block_definition compression_info_block_block;

	extern s_tag_block_definition node_map_byte_block_block;

	extern s_tag_block_definition instance_index_word_block_block;

	extern s_tag_block_definition global_instance_bucket_block_block;

	extern s_tag_block_definition global_mesh_block_block;

	extern s_tag_block_definition per_mesh_raw_data_block_block;

	extern s_tag_block_definition per_mesh_node_map_block_block;

	extern s_tag_block_definition per_mesh_subpart_visibility_block_block;

	extern s_tag_block_definition per_instance_prt_data_block_block;

	extern s_tag_block_definition per_mesh_prt_data_block_block;

	extern s_tag_block_definition per_instance_lightmap_texcoords_block_block;

	extern s_tag_block_definition per_instance_lightmap_texcoords_vertex_buffer_block_block;

	extern s_tag_block_definition water_bounding_box_block_block;

	extern s_tag_block_definition user_data_block_block;

	extern s_tag_block_definition vertex_buffers_block_block;

	extern s_tag_block_definition index_buffers_block_block;

	extern s_tag_block_definition render_vertex_buffer_block_block;

	extern s_tag_block_definition render_index_buffer_block_block;

	extern s_tag_block_definition player_training_entry_data_block_block;

	extern s_tag_block_definition vision_mode_block_group_block;

	extern s_tag_block_definition single_screen_effect_block;

	extern s_tag_block_definition area_screen_effect_block_group_block;

	extern s_tag_block_definition g_null_block_block;

	extern s_tag_block_definition scenario_interpolator_data_block_block;

	extern s_tag_block_definition scenario_interpolator_block_group_block;

	extern s_tag_block_definition full_lightprobe_block;

	extern s_tag_block_definition converted_lightprobe_block;

	extern s_tag_block_definition scenario_lightmap_lightprobe_value_block;

	extern s_tag_block_definition scenario_lightmap_airprobe_value_block;

	extern s_tag_block_definition scenario_lightmap_scenery_probe_value_block;

	extern s_tag_block_definition scenario_lightmap_device_machine_probe_value_block;

	extern s_tag_block_definition scenario_lightmap_device_machine_probe_data_value_block;

	extern s_tag_block_definition scenario_lightmap_pervertex_data_block;

	extern s_tag_block_definition scenario_lightmap_pervertex_data_run_time_block;

	extern s_tag_block_definition scenario_lightmap_cluster_data_block;

	extern s_tag_block_definition scenario_lightmap_instance_data_block;

	extern s_tag_block_definition wentness_bit_vector_block;

	extern s_tag_block_definition wentness_byte_vector_block;

	extern s_tag_block_definition cluster_wetness_offset_block_block;

	extern s_tag_block_definition instance_wetness_instance_block_block;

	extern s_tag_block_definition triangle_mapping_block_block;

	extern s_tag_block_definition triangle_mapping_per_mesh_block_block;

	extern s_tag_block_definition scenario_lightmap_bsp_data_block_group_block;

	extern s_tag_block_definition scenario_wetness_bsp_data_block_group_block;

	extern s_tag_block_definition obsolete_scenario_lightmap_bsp_data_block;

	extern s_tag_block_definition uber_light_index_mapping_data_block;

	extern s_tag_block_definition scenario_lightmap_bsp_data_reference_block_block;

	extern s_tag_block_definition scenario_lightmap_block_group_block;

	extern s_tag_block_definition polyhedron_with_material_block_block;

	extern s_tag_block_definition structure_bsp_instanced_geometry_definition_block_block;

	extern s_tag_block_definition collision_geometry_shape_block_block;

	extern s_tag_block_definition decomposed_poop_physics_block_block;

	extern s_tag_block_definition instanced_geometry_physics_block_block;

	extern s_tag_block_definition structure_bsp_instanced_geometry_instances_block_block;

	extern s_tag_block_definition structure_bsp_instanced_geometry_instances_without_names_block_block;

	extern s_tag_block_definition structure_bsp_instanced_geometry_instances_names_block_block;

	extern s_tag_block_definition global_render_model_instance_placement_block_block;

	extern s_tag_block_definition breakable_surface_block_group_block;

	extern s_tag_block_definition dumpling_point_block_block;

	extern s_tag_block_definition scenario_atmosphere_dumpling_block_block;

	extern s_tag_block_definition scenario_weather_dumpling_block_block;

	extern s_tag_block_definition scenario_function_block_block;

	extern s_tag_block_definition scenario_object_names_block_block;

	extern s_tag_block_definition scenario_soft_ceilings_block_block;

	extern s_tag_block_definition scenario_profiles_block_block;

	extern s_tag_block_definition scenario_players_block_block;

	extern s_tag_block_definition scenario_trigger_volume_block_block;

	extern s_tag_block_definition scenario_kill_trigger_volumes_block_block;

	extern s_tag_block_definition scenario_safe_zone_trigger_volumes_block_block;

	extern s_tag_block_definition scenario_requisition_trigger_volumes_block_block;

	extern s_tag_block_definition scenario_location_name_trigger_volumes_block_block;

	extern s_tag_block_definition trigger_volume_point_block_block;

	extern s_tag_block_definition trigger_volume_runtime_triangles_block_block;

	extern s_tag_block_definition scenario_zone_set_bsp_checksum_block_block;

	extern s_tag_block_definition scenario_zone_set_cluster_pvs_bit_vector_block_block;

	extern s_tag_block_definition scenario_zone_set_bsp_bits_block_block;

	extern s_tag_block_definition scenario_zone_set_cluster_pvs_block_block;

	extern s_tag_block_definition scenario_structure_bsp_reference_block_block;

	extern s_tag_block_definition scenario_sky_reference_block_block;

	extern s_tag_block_definition scenario_zone_set_cluster_sky_indices_block_block;

	extern s_tag_block_definition scenario_zone_set_multiple_skies_visible_bit_vector_block_block;

	extern s_tag_block_definition scenario_zone_set_cluster_reference_block_block;

	extern s_tag_block_definition scenario_zone_set_bsp_seam_cluster_mappings_block_block;

	extern s_tag_block_definition scenario_zone_set_bsp_pvs_block_block;

	extern s_tag_block_definition scenario_zone_set_pvs_block_block;

	extern s_tag_block_definition scenario_design_reference_block_block;

	extern s_tag_block_definition scenario_zone_set_block_block;

	extern s_tag_block_definition scenario_zone_set_switch_trigger_volume_block_block;

	extern s_tag_block_definition player_spawn_influencer_block_block;

	extern s_tag_block_definition scenario_performance_actor_block_block;

	extern s_tag_block_definition scenario_performance_line_animation_block_block;

	extern s_tag_block_definition scenario_performance_line_sync_action_actor_block_block;

	extern s_tag_block_definition scenario_performance_line_sync_action_block_block;

	extern s_tag_block_definition scenario_performance_line_scenery_sync_action_block_block;

	extern s_tag_block_definition scenario_performance_line_dialog_block_block;

	extern s_tag_block_definition scenario_performance_line_sound_block_block;

	extern s_tag_block_definition scenario_performance_line_script_fragment_block_block;

	extern s_tag_block_definition scenario_performance_line_point_interaction_block_block;

	extern s_tag_block_definition scenario_performance_line_block_block;

	extern s_tag_block_definition scenario_performance_task_block_block;

	extern s_tag_block_definition scenario_performances_block_block;

	extern s_tag_block_definition performance_template_point_block_block;

	extern s_tag_block_definition performance_template_actor_block_block;

	extern s_tag_block_definition performance_template_block_group_block;

	extern s_tag_block_definition scenario_decal_palette_block_block;

	extern s_tag_block_definition scenario_decals_block_block;

	extern s_tag_block_definition scenario_detail_object_collection_palette_block_block;

	extern s_tag_block_definition scenario_cheap_particle_system_palette_block_block;

	extern s_tag_block_definition scenario_cheap_particle_systems_block_block;

	extern s_tag_block_definition scenario_cutscene_flag_block_block;

	extern s_tag_block_definition scenario_cutscene_camera_point_block_block;

	extern s_tag_block_definition editor_comment_block_block;

	extern s_tag_block_definition dont_use_me_scenario_environment_object_block_block;

	extern s_tag_block_definition scenario_cluster_acoustics_block_block;

	extern s_tag_block_definition scenario_atmosphere_palette_block_block;

	extern s_tag_block_definition scenario_cluster_atmosphere_properties_block_block;

	extern s_tag_block_definition scenario_weather_palette_block_block;

	extern s_tag_block_definition scenario_cluster_weather_properties_block_block;

	extern s_tag_block_definition scenario_camera_fx_palette_block_block;

	extern s_tag_block_definition scenario_cluster_camera_fx_properties_block_block;

	extern s_tag_block_definition scenario_cluster_points_block_block;

	extern s_tag_block_definition scenario_cluster_data_block_block;

	extern s_tag_block_definition scenario_spawn_data_block_block;

	extern s_tag_block_definition scenario_lighting_zone_set_block_block;

	extern s_tag_block_definition scenario_cinematic_lighting_palette_block_block;

	extern s_tag_block_definition model_references_block_block;

	extern s_tag_block_definition trigger_volume_mopp_code_block_block;

	extern s_tag_block_definition scenario_airprobes_block_block;

	extern s_tag_block_definition scenario_budget_references_block_block;

	extern s_tag_block_definition scenario_required_resource_block_group_block;

	extern s_tag_block_definition scenario_block_group_block;

	extern s_tag_block_definition map_leaf_face_vertex_block_block;

	extern s_tag_block_definition map_leaf_face_block_block;

	extern s_tag_block_definition map_leaf_connection_index_block_block;

	extern s_tag_block_definition global_map_leaf_block_block;

	extern s_tag_block_definition leaf_connection_vertex_block_block;

	extern s_tag_block_definition global_leaf_connection_block_block;

	extern s_tag_block_definition mopp_code_data_definition_block_block;

	extern s_tag_block_definition mopp_code_definition_block_block;

	extern s_tag_block_definition transparent_planes_block_block;

	extern s_tag_block_definition structure_bsp_cluster_portal_vertex_block_block;

	extern s_tag_block_definition structure_bsp_cluster_portal_index_block_block;

	extern s_tag_block_definition seam_indices_block_definition_block;

	extern s_tag_block_definition cheap_light_reference_block_block;

	extern s_tag_block_definition cheap_light_marker_ref_block_block;

	extern s_tag_block_definition pvs_bound_object_identifiers_block_block;

	extern s_tag_block_definition pvs_bound_object_references_block_block;

	extern s_tag_block_definition structure_bsp_cluster_block_block;

	extern s_tag_block_definition structure_bsp_cluster_portal_block_block;

	extern s_tag_block_definition structure_bsp_pathfinding_edges_block_block;

	extern s_tag_block_definition structure_bsp_conveyor_surface_block_block;

	extern s_tag_block_definition structure_collision_materials_block_block;

	extern s_tag_block_definition structure_bsp_marker_block_block;

	extern s_tag_block_definition structure_bsp_marker_light_palette_block;

	extern s_tag_block_definition structure_bsp_marker_light_index_block;

	extern s_tag_block_definition structure_bsp_environment_object_palette_block_block;

	extern s_tag_block_definition structure_bsp_environment_object_block_block;

	extern s_tag_block_definition structure_bsp_detail_object_data_block_block;

	extern s_tag_block_definition structure_bsp_runtime_decal_block_block;

	extern s_tag_block_definition bsp_preplaced_decal_set_reference_block_block;

	extern s_tag_block_definition bsp_preplaced_decal_reference_block_block;

	extern s_tag_block_definition structure_bsp_leaf_block_block;

	extern s_tag_block_definition super_node_recursable_masks_block_block;

	extern s_tag_block_definition structure_super_node_traversal_geometry_indices_block_block;

	extern s_tag_block_definition structure_super_node_aabbs_block_block;

	extern s_tag_block_definition super_node_mappings_block_block;

	extern s_tag_block_definition structure_super_node_traversal_geometry_block_block;

	extern s_tag_block_definition structure_surface_block_block;

	extern s_tag_block_definition structure_surface_to_triangle_mapping_block_block;

	extern s_tag_block_definition structure_bsp_debug_info_render_line_block_block;

	extern s_tag_block_definition structure_bsp_debug_info_indices_block_block;

	extern s_tag_block_definition structure_bsp_cluster_debug_info_block_block;

	extern s_tag_block_definition structure_bsp_fog_plane_debug_info_block_block;

	extern s_tag_block_definition structure_bsp_fog_zone_debug_info_block_block;

	extern s_tag_block_definition structure_bsp_debug_info_block_block;

	extern s_tag_block_definition structure_bsp_sky_owner_cluster_block_block;

	extern s_tag_block_definition structure_bsp_fake_lightprobes_block_block;

	extern s_tag_block_definition structure_edge_to_seam_edge_mapping_block_block;

	extern s_tag_block_definition widget_reference_block_block;

	extern s_tag_block_definition runtime_decorator_set_block_block;

	extern s_tag_block_definition structure_bsp_raw_resources_block;

	extern s_tag_block_definition index_list_block_block;

	extern s_tag_block_definition structure_instance_cluster_definition_block;

	extern s_tag_block_definition structure_instance_group_definition_block;

	extern s_tag_block_definition structure_cookie_cutter_definition_block;

	extern s_tag_block_definition scenario_structure_bsp_block_group_block;

	extern s_tag_block_definition structure_seam_cluster_mapping_block_block;

	extern s_tag_block_definition structure_seam_edge_mapping_block_block;

	extern s_tag_block_definition structure_seam_mapping_block_block;

	extern s_tag_block_definition structure_seam_original_vertex_plane_normals_block_block;

	extern s_tag_block_definition structure_seam_original_vertex_block_block;

	extern s_tag_block_definition structure_seam_final_points_block_block;

	extern s_tag_block_definition structure_seam_final_planes_block_block;

	extern s_tag_block_definition structure_seam_final_triangles_block_block;

	extern s_tag_block_definition structure_seam_final_edges_block_block;

	extern s_tag_block_definition structure_seam_block_block;

	extern s_tag_block_definition structure_seams_block_group_block;

	extern s_tag_block_definition water_physics_material_override_block;

	extern s_tag_block_definition water_physics_hull_surface_definition_block_block;

	extern s_tag_block_definition water_physics_drag_properties_block_group_block;

	extern s_tag_block_definition scenario_acoustics_palette_block_definition_block;

	extern s_tag_block_definition acoustic_sector_point_block_block;

	extern s_tag_block_definition scenario_acoustic_sector_block_block;

	extern s_tag_block_definition scenario_acoustic_transition_block_block;

	extern s_tag_block_definition wind_block_group_block;

	extern s_tag_block_definition cubemap_reference_points_block_block;

	extern s_tag_block_definition scenario_cubemap_block_block;

	extern s_tag_block_definition structure_cluster_cubemap_block;

	extern s_tag_block_definition effect_locations_block_block;

	extern s_tag_block_definition effect_accelerations_block_block;

	extern s_tag_block_definition effect_part_block_block;

	extern s_tag_block_definition effect_event_block_block;

	extern s_tag_block_definition effect_conical_distribution_block_block;

	extern s_tag_block_definition effect_looping_sound_block_block;

	extern s_tag_block_definition effect_block_group_block;

	extern s_tag_block_definition multilingual_unicode_string_reference_block_block;

	extern s_tag_block_definition string_substitution_pair_block_block;

	extern s_tag_block_definition multilingual_unicode_string_list_block_group_block;

	extern s_tag_block_definition havok_cleanup_resources_block_block;

	extern s_tag_block_definition cheat_weapons_block_block;

	extern s_tag_block_definition cheat_powerups_block_block;

	extern s_tag_block_definition grenades_block_block;

	extern s_tag_block_definition soft_ceiling_globals_block_block;

	extern s_tag_block_definition sound_block_block;

	extern s_tag_block_definition multiplayer_color_block_block;

	extern s_tag_block_definition visor_color_block_block;

	extern s_tag_block_definition named_rgb_color_block_block;

	extern s_tag_block_definition globals_block_group_block;

	extern s_tag_block_definition customized_model_player_bits_block_block;

	extern s_tag_block_definition customized_model_selection_block_block;

	extern s_tag_block_definition player_model_customization_globals_block_group_block;

	extern s_tag_block_definition spawn_influence_weight_falloff_function_block_block;

	extern s_tag_block_definition multiplayer_color_block_block$2;

	extern s_tag_block_definition multiplayer_universal_block_block;

	extern s_tag_block_definition weapon_spawn_influence_block_block;

	extern s_tag_block_definition vehicle_spawn_influence_block_block;

	extern s_tag_block_definition projectile_spawn_influence_block_block;

	extern s_tag_block_definition equipment_spawn_influence_block_block;

	extern s_tag_block_definition requisition_constants_block_block;

	extern s_tag_block_definition multiplayer_constants_block_block;

	extern s_tag_block_definition game_engine_status_response_block_block;

	extern s_tag_block_definition sounds_block_block;

	extern s_tag_block_definition looping_sounds_block_block;

	extern s_tag_block_definition multiplayer_runtime_block_block;

	extern s_tag_block_definition multiplayer_globals_block_group_block;

	extern s_tag_block_definition single_achievement_restricted_level_block_block;

	extern s_tag_block_definition single_achievement_definition_block_block;

	extern s_tag_block_definition achievements_block_group_block;

	extern s_tag_block_definition lens_flare_reflection_block_block;

	extern s_tag_block_definition lens_flare_scalar_animation_block_block;

	extern s_tag_block_definition lens_flare_color_animation_block_block;

	extern s_tag_block_definition lens_flare_block_group_block;

	extern s_tag_block_definition region_name_block_block;

	extern s_tag_block_definition model_variant_state_block_block;

	extern s_tag_block_definition model_variant_permutation_block_block;

	extern s_tag_block_definition model_variant_region_block_block;

	extern s_tag_block_definition model_variant_object_block_block;

	extern s_tag_block_definition model_instance_group_member_block_block;

	extern s_tag_block_definition global_model_instance_group_block_block;

	extern s_tag_block_definition model_variant_block_block;

	extern s_tag_block_definition model_material_block_old_block;

	extern s_tag_block_definition model_material_block_new_block;

	extern s_tag_block_definition model_target_block_old_block;

	extern s_tag_block_definition model_target_block_new_block;

	extern s_tag_block_definition model_permutation_block_block;

	extern s_tag_block_definition model_region_block_block;

	extern s_tag_block_definition model_node_block_block;

	extern s_tag_block_definition model_self_shadow_region_cast_override_block_block;

	extern s_tag_block_definition model_self_shadow_region_receive_override_block_block;

	extern s_tag_block_definition model_occlusion_sphere_block_block;

	extern s_tag_block_definition model_block_group_block;

	extern s_tag_block_definition sky_lights_block_block;

	extern s_tag_block_definition instance_node_map_mapping_block_block;

	extern s_tag_block_definition volume_samples_block_block;

	extern s_tag_block_definition default_node_orientations_block_block;

	extern s_tag_block_definition render_model_permutation_block_block;

	extern s_tag_block_definition render_model_region_block_block;

	extern s_tag_block_definition render_model_node_block_block;

	extern s_tag_block_definition render_model_marker_block_block;

	extern s_tag_block_definition render_model_marker_group_block_block;

	extern s_tag_block_definition render_model_block_group_block;

	extern s_tag_block_definition imposter_mode_node_block_block;

	extern s_tag_block_definition imposter_model_block_group_block;

	extern s_tag_block_definition multiplayer_object_type_block_block;

	extern s_tag_block_definition multiplayer_object_collection_block_block;

	extern s_tag_block_definition multiplayer_weapon_remap_table_entry_block_block;

	extern s_tag_block_definition multiplayer_vehicle_remap_table_entry_block_block;

	extern s_tag_block_definition multiplayer_weapon_remap_table_block_block;

	extern s_tag_block_definition multiplayer_vehicle_remap_table_block_block;

	extern s_tag_block_definition multiplayer_object_type_list_block_group_block;

	extern s_tag_block_definition campaign_metagame_bucket_block_block;

	extern s_tag_block_definition campaign_metagame_scenario_bonuses_block_block;

	extern s_tag_block_definition campaign_metagame_scenario_block_block;

	extern s_tag_block_definition campaign_metagame_style_type_block_block;

	extern s_tag_block_definition campaign_metagame_difficulty_scale_block_block;

	extern s_tag_block_definition campaign_metagame_skull_block_block;

	extern s_tag_block_definition campaign_metagame_globals_block_block;

	extern s_tag_block_definition loadout_definition_block_block;

	extern s_tag_block_definition loadout_index_block_block;

	extern s_tag_block_definition loadout_name_block_block;

	extern s_tag_block_definition loadout_palette_definition_block_block;

	extern s_tag_block_definition loadout_globals_definition_block_group_block;

	extern s_tag_block_definition game_engine_loadout_palette_entry_block_block;

	extern s_tag_block_definition game_engine_loadout_options_block_block;

	extern s_tag_block_definition sound_platform_sound_playback_block_block;

	extern s_tag_block_definition sound_dialogue_constants_block_group_block;

	extern s_tag_block_definition sound_global_propagation_block_group_block;

	extern s_tag_block_definition campaign_unspatialized_sounds_block_block;

	extern s_tag_block_definition sound_globals_block_block;

	extern s_tag_block_definition sound_mix_block_group_block;

	extern s_tag_block_definition sound_permutation_chunk_block_block;

	extern s_tag_block_definition sound_permutation_marker_block_block;

	extern s_tag_block_definition sound_xma2_seek_table_block_block;

	extern s_tag_block_definition facial_animation_curve_block_block;

	extern s_tag_block_definition facial_animation_permutation_block_block;

	extern s_tag_block_definition facial_animation_language_block_block;

	extern s_tag_block_definition sound_permutation_raw_info_block_block;

	extern s_tag_block_definition sound_definition_language_permutation_info_block_block;

	extern s_tag_block_definition sound_permutation_languages_block_block;

	extern s_tag_block_definition sound_permutations_block_block;

	extern s_tag_block_definition sound_pitch_range_block_block;

	extern s_tag_block_definition sound_promotion_rule_block_block;

	extern s_tag_block_definition sound_promotion_runtime_timer_block_block;

	extern s_tag_block_definition sound_extra_info_block_block;

	extern s_tag_block_definition sound_block_group_block;

	extern s_tag_block_definition looping_sound_detail_block_block;

	extern s_tag_block_definition looping_sound_track_block_block;

	extern s_tag_block_definition sound_looping_block_group_block;

	extern s_tag_block_definition havok_collision_filter_group_block_block;

	extern s_tag_block_definition havok_collision_filter_block_group_block;

	extern s_tag_block_definition player_trait_shield_vitality_block_block;

	extern s_tag_block_definition player_trait_weapons_block_block;

	extern s_tag_block_definition player_trait_movement_block_block;

	extern s_tag_block_definition player_trait_sensors_block_block;

	extern s_tag_block_definition player_trait_appearance_block_block;

	extern s_tag_block_definition game_engine_player_traits_block_block;

	extern s_tag_block_definition game_engine_player_traits_list_block_block;

	extern s_tag_block_definition pathfinding_object_index_list_block_block;

	extern s_tag_block_definition scenario_object_node_orientations_bit_vector_block_block;

	extern s_tag_block_definition scenario_object_node_orientations_orientations_block_block;

	extern s_tag_block_definition scenario_object_node_orientations_block_block;

	extern s_tag_block_definition scenario_scenery_palette_block_block;

	extern s_tag_block_definition scenario_scenery_block_block;

	extern s_tag_block_definition scenario_crate_palette_block_block;

	extern s_tag_block_definition scenario_crate_block_block;

	extern s_tag_block_definition scenario_creature_palette_block_block;

	extern s_tag_block_definition scenario_creature_block_block;

	extern s_tag_block_definition scenario_equipment_palette_block_block;

	extern s_tag_block_definition scenario_equipment_block_block;

	extern s_tag_block_definition scenario_weapon_palette_block_block;

	extern s_tag_block_definition scenario_weapon_block_block;

	extern s_tag_block_definition scenario_biped_palette_block_block;

	extern s_tag_block_definition scenario_biped_block_block;

	extern s_tag_block_definition scenario_giant_palette_block_block;

	extern s_tag_block_definition scenario_giant_block_block;

	extern s_tag_block_definition scenario_requisition_palette_block_block;

	extern s_tag_block_definition scenario_vehicle_palette_block_block;

	extern s_tag_block_definition scenario_vehicle_block_block;

	extern s_tag_block_definition device_group_block_block;

	extern s_tag_block_definition scenario_machine_palette_block_block;

	extern s_tag_block_definition scenario_machine_block_block;

	extern s_tag_block_definition scenario_terminal_palette_block_block;

	extern s_tag_block_definition scenario_terminal_block_block;

	extern s_tag_block_definition scenario_control_palette_block_block;

	extern s_tag_block_definition scenario_control_block_block;

	extern s_tag_block_definition scenario_sound_scenery_palette_block_block;

	extern s_tag_block_definition scenario_sound_scenery_block_block;

	extern s_tag_block_definition scenario_effect_scenery_palette_block_block;

	extern s_tag_block_definition scenario_effect_scenery_block_block;

	extern s_tag_block_definition scenario_light_palette_block_block;

	extern s_tag_block_definition scenario_light_block_block;

	extern s_tag_block_definition instantaneous_damage_repsonse_block_block;

	extern s_tag_block_definition global_damage_section_block_block;

	extern s_tag_block_definition global_damage_nodes_block_block;

	extern s_tag_block_definition damage_seat_region_setting_block_block;

	extern s_tag_block_definition damage_seat_info_block_block;

	extern s_tag_block_definition damage_constraint_info_block_block;

	extern s_tag_block_definition global_damage_info_block_block;

	extern s_tag_block_definition damage_section_recharge_speed_curve_block_block;

	extern s_tag_block_definition damage_section_segmented_recharge_fraction_block;

	extern s_tag_block_definition damage_response_region_transition_block_block;

	extern s_tag_block_definition damage_transfer_block_block;

	extern s_tag_block_definition seat_ejection_block_block;

	extern s_tag_block_definition new_instantaneous_damage_response_block_block;

	extern s_tag_block_definition damage_section_rendering_paramters_block;

	extern s_tag_block_definition new_global_damage_section_block_block;

	extern s_tag_block_definition phantom_types_block_block;

	extern s_tag_block_definition materials_block_block;

	extern s_tag_block_definition phantoms_block_block;

	extern s_tag_block_definition physics_model_damped_spring_motor_block_block;

	extern s_tag_block_definition physics_model_position_motor_block_block;

	extern s_tag_block_definition physics_model_ragdoll_motors_block_block;

	extern s_tag_block_definition physics_model_limited_hinge_motors_block_block;

	extern s_tag_block_definition physics_model_constraint_edge_constraint_block_block;

	extern s_tag_block_definition nodes_block_block;

	extern s_tag_block_definition physics_model_powered_chain_nodes_block_block;

	extern s_tag_block_definition physics_model_powered_chain_constraints_block_block;

	extern s_tag_block_definition physics_model_powered_chains_block_block;

	extern s_tag_block_definition physics_model_node_constraint_edge_block_block;

	extern s_tag_block_definition rigid_bodies_block_block;

	extern s_tag_block_definition rigid_body_indices_block_block;

	extern s_tag_block_definition permutations_block_block;

	extern s_tag_block_definition regions_block_block;

	extern s_tag_block_definition spheres_block_block;

	extern s_tag_block_definition multi_spheres_block_block;

	extern s_tag_block_definition pills_block_block;

	extern s_tag_block_definition boxes_block_block;

	extern s_tag_block_definition triangles_block_block;

	extern s_tag_block_definition polyhedra_block_block;

	extern s_tag_block_definition polyhedron_four_vectors_block_block;

	extern s_tag_block_definition polyhedron_plane_equations_block_block;

	extern s_tag_block_definition mass_distributions_block_block;

	extern s_tag_block_definition lists_block_block;

	extern s_tag_block_definition list_shapes_block_block;

	extern s_tag_block_definition mopps_block_block;

	extern s_tag_block_definition hinge_constraints_block_block;

	extern s_tag_block_definition limited_hinge_constraints_block_block;

	extern s_tag_block_definition ragdoll_constraints_block_block;

	extern s_tag_block_definition ball_and_socket_constraints_block_block;

	extern s_tag_block_definition stiff_spring_constraints_block_block;

	extern s_tag_block_definition prismatic_constraints_block_block;

	extern s_tag_block_definition point_to_path_curve_point_block_block;

	extern s_tag_block_definition point_to_path_curve_block_block;

	extern s_tag_block_definition physics_model_block_group_block;

	extern s_tag_block_definition animation_graph_node_block_block;

	extern s_tag_block_definition animation_node_mask_entry_block_block;

	extern s_tag_block_definition animation_node_mask_block_block;

	extern s_tag_block_definition animation_function_block_block;

	extern s_tag_block_definition animation_graph_sound_reference_block_block;

	extern s_tag_block_definition animation_graph_effect_reference_block_block;

	extern s_tag_block_definition animation_frame_event_block_block;

	extern s_tag_block_definition animation_sound_event_block_block;

	extern s_tag_block_definition animation_effect_event_block_block;

	extern s_tag_block_definition animation_dialogue_event_block_block;

	extern s_tag_block_definition animation_blend_screen_block_block;

	extern s_tag_block_definition object_space_node_data_block_block;

	extern s_tag_block_definition foot_tracking_member_block_block;

	extern s_tag_block_definition foot_lock_cycle_block_block;

	extern s_tag_block_definition foot_tracking_block_block;

	extern s_tag_block_definition foot_tracking_defaults_block;

	extern s_tag_block_definition object_space_offset_node_block_block;

	extern s_tag_block_definition fik_anchor_node_block_block;

	extern s_tag_block_definition animation_ik_chain_events_block;

	extern s_tag_block_definition animation_facial_wrinkle_events_block;

	extern s_tag_block_definition animation_extended_events_block;

	extern s_tag_block_definition animation_object_functions_block;

	extern s_tag_block_definition animation_ik_chain_proxies_block;

	extern s_tag_block_definition shared_model_animation_block_block;

	extern s_tag_block_definition animation_pool_block_block;

	extern s_tag_block_definition import_frame_event_block_block;

	extern s_tag_block_definition animation_sound_event_block_extended_block;

	extern s_tag_block_definition animation_effects_event_block_extended_block;

	extern s_tag_block_definition animation_dialogue_event_block_extended_block;

	extern s_tag_block_definition import_animation_event_block_block;

	extern s_tag_block_definition animation_transition_destination_block_block;

	extern s_tag_block_definition animation_transition_source_block_block;

	extern s_tag_block_definition new_animation_blend_screen_block_block;

	extern s_tag_block_definition new_animation_function_overlay_block_block;

	extern s_tag_block_definition blend_screen_item_definition_block_block;

	extern s_tag_block_definition function_overlay_item_definition_block_block;

	extern s_tag_block_definition overlay_group_definition_block_block;

	extern s_tag_block_definition animation_gait_block_block;

	extern s_tag_block_definition animation_gait_item_block_block;

	extern s_tag_block_definition animation_gait_group_block_block;

	extern s_tag_block_definition animation_ik_block_v1_block;

	extern s_tag_block_definition animation_ik_block_block;

	extern s_tag_block_definition animation_ik_set_item_block;

	extern s_tag_block_definition animation_ik_set_block;

	extern s_tag_block_definition animation_sync_action_same_type_participant_block;

	extern s_tag_block_definition animation_sync_action_other_type_participant_block;

	extern s_tag_block_definition animation_sync_action_block_block;

	extern s_tag_block_definition animation_sync_action_group_block_block;

	extern s_tag_block_definition animation_entry_block_block;

	extern s_tag_block_definition ranged_animation_entry_block_block;

	extern s_tag_block_definition damage_region_block_block;

	extern s_tag_block_definition damage_direction_block_block;

	extern s_tag_block_definition damage_animation_block_block;

	extern s_tag_block_definition vehicle_suspension_block_block;

	extern s_tag_block_definition animation_velocity_boundaries_block_block;

	extern s_tag_block_definition animation_set_block_block;

	extern s_tag_block_definition weapon_type_block_block;

	extern s_tag_block_definition triangulation_point_block_block;

	extern s_tag_block_definition triangulation_triangle_block_block;

	extern s_tag_block_definition triangulation_entry_block_block;

	extern s_tag_block_definition animation_ranged_action_block_block;

	extern s_tag_block_definition weapon_class_block_block;

	extern s_tag_block_definition animation_mode_block_block;

	extern s_tag_block_definition function_overlay_animation_block_block;

	extern s_tag_block_definition animation_usage_block_block;

	extern s_tag_block_definition mode_or_stance_alias_block_block;

	extern s_tag_block_definition model_animation_variant_block_block;

	extern s_tag_block_definition animation_ik_chain_block_block;

	extern s_tag_block_definition inherited_animation_node_map_block_block;

	extern s_tag_block_definition inherited_animation_node_map_flag_block_block;

	extern s_tag_block_definition inherited_animation_block_block;

	extern s_tag_block_definition weapon_class_lookup_block_block;

	extern s_tag_block_definition additional_node_data_block_block;

	extern s_tag_block_definition model_animation_tag_resource_member_block;

	extern s_tag_block_definition model_animation_tag_resource_group_block;

	extern s_tag_block_definition frame_event_list_block_group_block;

	extern s_tag_block_definition model_animation_graph_block_group_block;

	extern s_tag_block_definition grounded_friction_block_group_block;

	extern s_tag_block_definition old_material_effect_material_block_block;

	extern s_tag_block_definition material_effect_material_block_block;

	extern s_tag_block_definition material_effect_block_v2_block;

	extern s_tag_block_definition material_effects_block_group_block;

	extern s_tag_block_definition player_information_block_block;

	extern s_tag_block_definition player_representation_block_block;

	extern s_tag_block_definition location_name_block_block;

	extern s_tag_block_definition location_name_globals_definition_block_group_block;

	extern s_tag_block_definition input_mapping_function_block_block;

	extern s_tag_block_definition gamepad_stick_info_block_block;

	extern s_tag_block_definition controller_input_block_block;

	extern s_tag_block_definition player_control_block_block;

	extern s_tag_block_definition camera_track_control_point_block_block;

	extern s_tag_block_definition camera_track_block_group_block;

	extern s_tag_block_definition simulated_input_block_group_block;

	extern s_tag_block_definition global_camera_impulse_block_block;

	extern s_tag_block_definition camera_shake_block_group_block;

	extern s_tag_block_definition rumble_block_group_block;

	extern s_tag_block_definition point_physics_block_group_block;

	extern s_tag_block_definition cheap_particle_emitter_block_group_block;

	extern s_tag_block_definition cheap_particle_bitmap_reference_block_block;

	extern s_tag_block_definition cheap_particle_type_block_block;

	extern s_tag_block_definition cheap_particle_type_library_block_group_block;

	extern s_tag_block_definition anti_gravity_point_definition_block_block;

	extern s_tag_block_definition friction_point_definition_block_block;

	extern s_tag_block_definition walker_physics_leg_block_block;

	extern s_tag_block_definition boat_engine_definition_block_block;

	extern s_tag_block_definition jetwash_definition_block_block;

	extern s_tag_block_definition collision_kd_hierarchy_static_hash_table_headers_block_block;

	extern s_tag_block_definition collision_kd_hierarchy_static_nodes_block_block;

	extern s_tag_block_definition super_node_mappings_block_block$2;

	extern s_tag_block_definition cluster_table_block_block;

	extern s_tag_block_definition collision_kd_hierarchy_static_hash_table_short_block_block;

	extern s_tag_block_definition collision_kd_hierarchy_static_hash_table_data_block_block;

	extern s_tag_block_definition collision_kd_hierarchy_static_in_use_masks_block_block;

	extern s_tag_block_definition scenario_scenery_resource_block_group_block;

	extern s_tag_block_definition scenario_bipeds_resource_block_group_block;

	extern s_tag_block_definition scenario_vehicles_resource_block_group_block;

	extern s_tag_block_definition scenario_equipment_resource_block_group_block;

	extern s_tag_block_definition scenario_weapons_resource_block_group_block;

	extern s_tag_block_definition scenario_sound_scenery_resource_block_group_block;

	extern s_tag_block_definition scenario_lights_resource_block_group_block;

	extern s_tag_block_definition scenario_devices_resource_block_group_block;

	extern s_tag_block_definition scenario_effect_scenery_resource_block_group_block;

	extern s_tag_block_definition scenario_decals_resource_block_group_block;

	extern s_tag_block_definition scenario_cinematics_resource_block_group_block;

	extern s_tag_block_definition scenario_trigger_volumes_resource_block_group_block;

	extern s_tag_block_definition scenario_performances_resource_block_group_block;

	extern s_tag_block_definition scenario_dumplings_resource_block_group_block;

	extern s_tag_block_definition scenario_cluster_data_resource_block_group_block;

	extern s_tag_block_definition scenario_sky_references_resource_block_group_block;

	extern s_tag_block_definition scenario_cubemap_resource_block_group_block;

	extern s_tag_block_definition scenario_ai_resource_block_group_block;

	extern s_tag_block_definition scenario_comments_resource_block_group_block;

	extern s_tag_block_definition scenario_creature_resource_block_group_block;

	extern s_tag_block_definition scenario_decorators_resource_block_group_block;

	extern s_tag_block_definition scenario_structure_lighting_resource_block_group_block;

	extern s_tag_block_definition scenario_hs_source_reference_block_block;

	extern s_tag_block_definition scenario_ai_resource_reference_block_block;

	extern s_tag_block_definition scenario_split_resources_block_block;

	extern s_tag_block_definition scenario_resources_block_block;

	extern s_tag_block_definition structure_manifest_bsp_block_block;

	extern s_tag_block_definition global_scenario_load_parameters_block_block;

	extern s_tag_block_definition sound_class_block_block;

	extern s_tag_block_definition sound_classes_block_group_block;

	extern s_tag_block_definition sound_equalizer_band_settings_block_block;

	extern s_tag_block_definition sound_radio_settings_block_group_block;

	extern s_tag_block_definition single_variant_block_block;

	extern s_tag_block_definition variant_globals_block_group_block;

	extern s_tag_block_definition single_avatar_award_definition_block_block;

	extern s_tag_block_definition avatar_awards_block_group_block;

	extern s_tag_block_definition tag_patch_block_block;

	extern s_tag_block_definition tag_package_manifest_block_group_block;

	extern s_tag_block_definition megalo_string_id_block_block;

	extern s_tag_block_definition megalo_string_id_table_block_group_block;

	extern s_tag_block_definition game_completion_rewards_falloff_point_block_block;

	extern s_tag_block_definition game_completion_rewards_definition_block_block;

	extern s_tag_block_definition game_completion_rewards_difficulty_block_block;

	extern s_tag_block_definition game_completion_rewards_multiplayer_block_block;

	extern s_tag_block_definition game_completion_rewards_never_online_block_block;

	extern s_tag_block_definition game_completion_rewards_globals_block_group_block;

	extern s_tag_block_definition challenge_block_block;

	extern s_tag_block_definition challenge_category_block_block;

	extern s_tag_block_definition challenge_globals_definition_block_group_block;

	extern s_tag_block_definition game_medal_block_block;

	extern s_tag_block_definition game_medal_globals_block_group_block;

	extern s_tag_block_definition coop_spawning_globals_definition_block_group_block;

	extern s_tag_block_definition purchase_player_appearance_effect_model_permutation_block_block;

	extern s_tag_block_definition purchase_player_appearance_effect_non_model_permutation_block_block;

	extern s_tag_block_definition purchase_player_appearance_effect_visor_tint_block_block;

	extern s_tag_block_definition purchase_player_appearance_effect_emblem_index_block_block;

	extern s_tag_block_definition purchase_player_appearance_effect_voice_block_block;

	extern s_tag_block_definition purchase_prerequisite_grade_definition_block_block;

	extern s_tag_block_definition purchase_prerequisite_purchased_item_definition_block_block;

	extern s_tag_block_definition purchase_prerequisites_unlockable_definition_block_block;

	extern s_tag_block_definition cookie_purchase_definition_block_block;

	extern s_tag_block_definition cookie_purchase_definition_reference_block_block;

	extern s_tag_block_definition cookie_purchase_family_definition_block_block;

	extern s_tag_block_definition cookie_purchase_external_unlockable_block_definition_block;

	extern s_tag_block_definition cookie_purchase_globals_block_group_block;

	extern s_tag_block_definition cookie_award_definition_block_block;

	extern s_tag_block_definition cookie_globals_definition_block_group_block;

	extern s_tag_block_definition commendation_block_block;

	extern s_tag_block_definition commendation_globals_definition_block_group_block;

	extern s_tag_block_definition game_engine_ai_traits_list_block_block;

	extern s_tag_block_definition game_engine_miscellaneous_options_block_block;

	extern s_tag_block_definition game_engine_respawn_options_block_block;

	extern s_tag_block_definition game_engine_social_options_block_block;

	extern s_tag_block_definition game_engine_map_override_options_block_block;

	extern s_tag_block_definition game_engine_team_options_block_block;

	extern s_tag_block_definition game_engine_sandbox_variant_block_block;

	extern s_tag_block_definition game_engine_survival_set_properties_block_block;

	extern s_tag_block_definition survival_wave_squad_block_block;

	extern s_tag_block_definition game_engine_survival_round_properties_block_block;

	extern s_tag_block_definition game_engine_survival_custom_skull_block_block;

	extern s_tag_block_definition game_engine_survival_variant_block_block;

	extern s_tag_block_definition game_engine_campaign_variant_block_block;

	extern s_tag_block_definition game_engine_settings_definition_block_group_block;

	extern s_tag_block_definition game_engine_globals_block_group_block;

	extern s_tag_block_definition player_sub_grade_definition_block_block;

	extern s_tag_block_definition player_grade_definition_block_block;

	extern s_tag_block_definition player_grade_globals_definition_block_group_block;

	extern s_tag_block_definition suppressed_incident_block_block;

	extern s_tag_block_definition specialized_incident_kill_implement_block_block;

	extern s_tag_block_definition specialized_incident_object_properties_block_block;

	extern s_tag_block_definition specialized_incident_special_kill_type_block_block;

	extern s_tag_block_definition specialized_incident_block_block;

	extern s_tag_block_definition incident_accumulator_child_incident_block_block;

	extern s_tag_block_definition incident_accumulator_block_block;

	extern s_tag_block_definition incident_definition_block_block;

	extern s_tag_block_definition incident_globals_definition_block_group_block;

	extern s_tag_block_definition incident_globals_block_block;

	extern s_tag_block_definition incident_global_properties_definition_block_group_block;

	extern s_tag_block_definition survival_mode_wave_templates_block;

	extern s_tag_block_definition survival_spartan_voice_block;

	extern s_tag_block_definition survival_mode_globals_block_group_block;

	extern s_tag_block_definition bink_block_group_block;

	extern s_tag_block_definition scenario_cutscene_title_block_block;

	extern s_tag_block_definition cinematic_characters_block_block;

	extern s_tag_block_definition cinematics_globals_block_block;

	extern s_tag_block_definition cinematic_shot_frame_block_block;

	extern s_tag_block_definition cinematic_shot_frame_dynamic_block_block;

	extern s_tag_block_definition cinematic_shot_frame_constant_block_block;

	extern s_tag_block_definition cinematic_shot_lighting_block_block;

	extern s_tag_block_definition cinematic_shot_clip_subject_block_block;

	extern s_tag_block_definition cinematic_shot_clip_block_block;

	extern s_tag_block_definition cinematic_shot_dialogue_block_block;

	extern s_tag_block_definition cinematic_shot_music_block_block;

	extern s_tag_block_definition cinematic_shot_effect_block_block;

	extern s_tag_block_definition cinematic_shot_object_function_keyframe_block_block;

	extern s_tag_block_definition cinematic_shot_object_function_block_block;

	extern s_tag_block_definition cinematic_shot_screen_effect_block_block;

	extern s_tag_block_definition cinematic_shot_custom_script_block_block;

	extern s_tag_block_definition cinematic_shot_user_input_constraints_block_block;

	extern s_tag_block_definition cinematic_shot_block_block;

	extern s_tag_block_definition scene_object_attachment_block_block;

	extern s_tag_block_definition cinematic_scene_object_block_block;

	extern s_tag_block_definition cinematic_extra_camera_frame_block_block;

	extern s_tag_block_definition cinematic_extra_camera_shot_block_block;

	extern s_tag_block_definition cinematic_shot_extra_camera_block_block;

	extern s_tag_block_definition cinematic_scene_block_group_block;

	extern s_tag_block_definition cinematic_scene_reference_block_block;

	extern s_tag_block_definition cinematic_shot_playback_data_block_block;

	extern s_tag_block_definition cinematic_transition_global_gain_block_block;

	extern s_tag_block_definition cinematic_transition_sound_class_gain_block_block;

	extern s_tag_block_definition cinematic_transition_sound_reference_block_block;

	extern s_tag_block_definition cinematic_transition_looping_sound_reference_block_block;

	extern s_tag_block_definition cinematic_transition_looping_sound_state_block_block;

	extern s_tag_block_definition cinematic_transition_block_group_block;

	extern s_tag_block_definition cinematic_block_group_block;

	extern s_tag_block_definition scenario_cinematics_block_block;

	extern s_tag_block_definition cache_file_resource_type_identifier_block_block;

	extern s_tag_block_definition cache_file_interop_type_identifier_block_block;

	extern s_tag_block_definition cache_file_codec_identifier_block_block;

	extern s_tag_block_definition cache_file_resource_fixup_location_block_block;

	extern s_tag_block_definition cache_file_resource_interop_location_block_block;

	extern s_tag_block_definition cache_file_shared_file_block_block;

	extern s_tag_block_definition cache_file_resource_streaming_sublocation_block_block;

	extern s_tag_block_definition cache_file_resource_streaming_sublocation_table_block_block;

	extern s_tag_block_definition cache_file_resource_file_location_block_block;

	extern s_tag_block_definition cache_file_resource_default_location_block_block;

	extern s_tag_block_definition cache_file_resource_data_block_block;

	extern s_tag_block_definition cache_file_tag_resources_bitvector_block_block;

	extern s_tag_block_definition cache_file_tag_resource_usage_block_block;

	extern s_tag_block_definition cache_file_bsp_reference_block_block;

	extern s_tag_block_definition cache_file_resource_owner_block_block;

	extern s_tag_block_definition cache_file_resource_owner_reference_block_block;

	extern s_tag_block_definition cache_file_zone_resource_visit_node_link_block_block;

	extern s_tag_block_definition cache_file_zone_resource_visit_node_block_block;

	extern s_tag_block_definition cache_file_model_variant_usage_block_block;

	extern s_tag_block_definition cache_file_model_variant_usage_reference_block_block;

	extern s_tag_block_definition cache_file_character_usage_block_block;

	extern s_tag_block_definition cache_file_tag_zone_block_block;

	extern s_tag_block_definition cache_file_global_zone_block_block;

	extern s_tag_block_definition cache_file_bsp_zone_block_block;

	extern s_tag_block_definition cache_file_designer_zone_block_block;

	extern s_tag_block_definition cache_file_cinematic_zone_block_block;

	extern s_tag_block_definition cache_file_full_zone_sets_block_block;

	extern s_tag_block_definition cache_file_zone_set_zone_usage_block_block;

	extern s_tag_block_definition resource_category_block_block;

	extern s_tag_block_definition cache_file_debug_resource_definition_block_block;

	extern s_tag_block_definition cache_file_resource_layout_block_block;

	extern s_tag_block_definition cache_file_tag_resource_named_value_block_block;

	extern s_tag_block_definition cache_file_tag_resource_properties_block_block;

	extern s_tag_block_definition debug_cache_file_tag_zone_block_block;

	extern s_tag_block_definition debug_cache_file_model_variant_zone_block_block;

	extern s_tag_block_definition debug_cache_file_combat_dialogue_zone_block_block;

	extern s_tag_block_definition cache_file_tag_parentage_reference_block_block;

	extern s_tag_block_definition cache_file_tag_parentage_block_block;

	extern s_tag_block_definition cache_file_tag_resource_prediction_quantum_block_block;

	extern s_tag_block_definition cache_file_tag_resource_prediction_atom_block_block;

	extern s_tag_block_definition cache_file_tag_resource_prediction_molecule_atom_reference_block_block;

	extern s_tag_block_definition cache_file_tag_resource_prediction_molecule_block_block;

	extern s_tag_block_definition cache_file_tag_resource_prediction_molecule_keys_block_block;

	extern s_tag_block_definition cache_file_bsp_attachment_block_block;

	extern s_tag_block_definition cache_file_bsp_game_attachments_block_block;

	extern s_tag_block_definition cache_file_resource_gestalt_block_group_block;

	extern s_tag_block_definition cache_file_resource_layout_table_block_group_block;

	extern s_tag_block_definition sound_gestalt_codec_block_block;

	extern s_tag_block_definition sound_gestalt_playback_block_block;

	extern s_tag_block_definition sound_gestalt_scale_block_block;

	extern s_tag_block_definition sound_gestalt_import_names_block_block;

	extern s_tag_block_definition sound_pitch_range_distances_block_block;

	extern s_tag_block_definition sound_gestalt_pitch_range_parameters_block_block;

	extern s_tag_block_definition sound_gestalt_permutations_block_block;

	extern s_tag_block_definition sound_gestalt_permutation_languages_block_block;

	extern s_tag_block_definition sound_gestalt_pitch_ranges_block_block;

	extern s_tag_block_definition sound_gestalt_custom_playback_block_block;

	extern s_tag_block_definition sound_gestalt_runtime_permutation_bit_vector_block_block;

	extern s_tag_block_definition sound_gestalt_promotions_block_block;

	extern s_tag_block_definition sound_gestalt_facial_animation_block_block;

	extern s_tag_block_definition sound_gestalt_layer_markers_block_block;

	extern s_tag_block_definition sound_cache_file_gestalt_block_group_block;

	extern s_tag_block_definition cache_file_sound_block_group_block;

	extern s_tag_block_definition platform_sound_playback_component_block_block;

	extern s_tag_block_definition platform_sound_playback_lowpass_block_block;

	extern s_tag_block_definition platform_sound_playback_block_block;

	extern s_tag_block_definition sound_effect_collection_block_group_block;

	extern s_tag_block_definition sound_effect_template_parameter_block_block;

	extern s_tag_block_definition sound_effect_templates_block_block;

	extern s_tag_block_definition sound_effect_template_additional_sound_input_block_block;

	extern s_tag_block_definition sound_effect_template_block_group_block;

	extern s_tag_block_definition communication_sounds_block_group_block;

	extern s_tag_block_definition megalogamengine_sounds_block_group_block;

	extern s_tag_block_definition sound_scenery_block_group_block;

	extern s_tag_block_definition detail_object_type_block_block;

	extern s_tag_block_definition detail_object_collection_block_group_block;

	extern s_tag_block_definition global_detail_object_cells_block_block;

	extern s_tag_block_definition global_detail_object_block_block;

	extern s_tag_block_definition global_detail_object_counts_block_block;

	extern s_tag_block_definition global_z_reference_vector_block_block;

	extern s_tag_block_definition scenario_description_block_block;

	extern s_tag_block_definition multiplayer_scenario_description_block_group_block;

	extern s_tag_block_definition decal_definition_block_block;

	extern s_tag_block_definition decal_system_block_group_block;

	extern s_tag_block_definition sound_environment_block_group_block;

	extern s_tag_block_definition camo_block_group_block;

	extern s_tag_block_definition shield_impact_block_group_block;

	extern s_tag_block_definition cinematic_dynamic_light_block_block;

	extern s_tag_block_definition new_cinematic_lighting_block_group_block;

	extern s_tag_block_definition faux_data_cluster_data_block;

	extern s_tag_block_definition faux_data_instance_data_block;

	extern s_tag_block_definition faux_data_global_cluster_instance_data_block;

	extern s_tag_block_definition faux_data_global_cluster_data_block;

	extern s_tag_block_definition faux_data_global_instance_definition_data_block;

	extern s_tag_block_definition faux_data_global_instance_data_block;

	extern s_tag_block_definition faux_data_global_material_data_block;

	extern s_tag_block_definition faux_data_bsp_global_data_block;

	extern s_tag_block_definition faux_data_object_data_block;

	extern s_tag_block_definition faux_data_airprobe_lightgroup_value_block;

	extern s_tag_block_definition faux_data_scenery_probe_lightgroup_value_block;

	extern s_tag_block_definition faux_data_device_probe_lightgroup_value_block;

	extern s_tag_block_definition faux_data_device_probes_lightgroup_value_block;

	extern s_tag_block_definition faux_data_lightmap_group_data_block;

	extern s_tag_block_definition faux_data_airprobe_value_block;

	extern s_tag_block_definition faux_data_scenery_probe_value_block;

	extern s_tag_block_definition faux_data_device_machine_probe_value_block;

	extern s_tag_block_definition faux_data_device_machine_probes_value_block;

	extern s_tag_block_definition scenario_faux_data_block_group_block;

	extern s_tag_block_definition sound_combiner_definition_entry_block_block;

	extern s_tag_block_definition sound_combiner_block_group_block;

	extern s_tag_block_definition particle_emitter_boat_hull_group_block_block;

	extern s_tag_block_definition particle_emitter_boat_hull_shape_block_group_block;

	extern s_tag_block_definition particle_emitter_custom_point_block_block;

	extern s_tag_block_definition particle_emitter_custom_points_block_group_block;

	extern s_tag_block_definition fx_property_default_block_block;

	extern s_tag_block_definition fx_property_block_block;

	extern s_tag_block_definition fx_test_block_group_block;

	extern s_tag_block_definition bolt_definition_block_block;

	extern s_tag_block_definition lightning_system_block_group_block;

	extern s_tag_block_definition beam_definition_block_block;

	extern s_tag_block_definition beam_system_block_group_block;

	extern s_tag_block_definition contrail_definition_block_block;

	extern s_tag_block_definition contrail_system_block_group_block;

	extern s_tag_block_definition effect_scenery_block_group_block;

	extern s_tag_block_definition color_block_block;

	extern s_tag_block_definition color_table_block_group_block;

	extern s_tag_block_definition bitmap_texture_interop_block_block;

	extern s_tag_block_definition bitmap_texture_interleaved_interop_block_block;

	extern s_tag_block_definition bitmap_block_group_block;

	extern s_tag_block_definition structure_design_block_group_block;

	extern s_tag_block_definition spring_linear_acceleration_block_block;

	extern s_tag_block_definition spring_acceleration_block_group_block;

	extern s_tag_block_definition game_performance_throttle_entries_block_block;

	extern s_tag_block_definition game_performance_throttle_block_group_block;

	extern s_tag_block_definition collision_model_material_block_block;

	extern s_tag_block_definition collision_model_permutation_block_block;

	extern s_tag_block_definition collision_model_region_block_block;

	extern s_tag_block_definition collision_model_node_block_block;

	extern s_tag_block_definition collision_model_pathfinding_sphere_block_block;

	extern s_tag_block_definition collision_model_block_group_block;

	extern s_tag_block_definition collision_model_bsp_block_block;

	extern s_tag_block_definition instance_imposter_block_block;

	extern s_tag_block_definition instance_imposter_checksum_block_block;

	extern s_tag_block_definition instance_imposter_definition_block_group_block;

	extern s_tag_block_definition bitmap_usage_block_block;

	extern s_tag_block_definition camera_block_block;

	extern s_tag_block_definition global_geometry_material_block_block;

	extern s_tag_block_definition global_self_track_block_block;

	extern s_tag_block_definition error_report_vertices_block_block;

	extern s_tag_block_definition error_report_vectors_block_block;

	extern s_tag_block_definition error_report_lines_block_block;

	extern s_tag_block_definition error_report_triangles_block_block;

	extern s_tag_block_definition error_report_quads_block_block;

	extern s_tag_block_definition error_report_comments_block_block;

	extern s_tag_block_definition error_reports_block_block;

	extern s_tag_block_definition global_error_report_categories_block_block;

	extern s_tag_block_definition collision_bsp_physics_block_block;

	extern s_tag_block_definition breakable_surface_set_block_block;

	extern s_tag_block_definition bsp3d_nodes_block_block;

	extern s_tag_block_definition bsp3d_kd_supdernodes_block_block;

	extern s_tag_block_definition planes_block_block;

	extern s_tag_block_definition leaves_block_block;

	extern s_tag_block_definition bsp2d_references_block_block;

	extern s_tag_block_definition bsp2d_nodes_block_block;

	extern s_tag_block_definition surfaces_block_block;

	extern s_tag_block_definition edges_block_block;

	extern s_tag_block_definition vertices_block_block;

	extern s_tag_block_definition global_collision_bsp_block_block;

	extern s_tag_block_definition large_bsp3d_nodes_block_block;

	extern s_tag_block_definition large_leaves_block_block;

	extern s_tag_block_definition large_bsp2d_references_block_block;

	extern s_tag_block_definition large_bsp2d_nodes_block_block;

	extern s_tag_block_definition large_surfaces_block_block;

	extern s_tag_block_definition large_edges_block_block;

	extern s_tag_block_definition large_vertices_block_block;

	extern s_tag_block_definition global_large_collision_bsp_block_block;

	extern s_tag_block_definition structure_soft_ceiling_triangle_block_block;

	extern s_tag_block_definition structure_soft_ceiling_block_block;

	extern s_tag_block_definition breakable_surface_key_table_block_block;

	extern s_tag_block_definition structure_water_groups_block_block;

	extern s_tag_block_definition structure_water_instance_planes_block_block;

	extern s_tag_block_definition structure_water_instance_debug_triangles_block_block;

	extern s_tag_block_definition structure_water_instances_block_block;

	extern s_tag_block_definition soft_surfaces_definition_block_block;

	extern s_tag_block_definition global_decorator_placement_block_block;

	extern s_tag_block_definition decorator_scenario_set_block_block;

	extern s_tag_block_definition decorator_palette_block;

	extern s_tag_block_definition scenario_decorator_block_block;

	extern s_tag_block_definition scenario_zone_debugger_block_definition_block;

	extern s_tag_block_definition hs_script_parameters_block_block;

	extern s_tag_block_definition hs_scripts_block_block;

	extern s_tag_block_definition hs_globals_block_block;

	extern s_tag_block_definition hs_references_block_block;

	extern s_tag_block_definition hs_source_files_block_group_block;

	extern s_tag_block_definition hs_syntax_datum_block_block;

	extern s_tag_block_definition hs_unit_seat_block_block;

	extern s_tag_block_definition named_location_volume_point_block_block;

	extern s_tag_block_definition scenario_named_location_volume_block_block;

	extern s_tag_block_definition recorded_animation_block_block;

	extern s_tag_block_definition map_variant_object_variant_block_block;

	extern s_tag_block_definition map_variant_palette_entry_block_block;

	extern s_tag_block_definition map_variant_palette_block_block;

	extern s_tag_block_definition door_encoded_pas_block_block;

	extern s_tag_block_definition room_door_portal_encoded_pas_block_block;

	extern s_tag_block_definition ai_deafening_encoded_pas_block_block;

	extern s_tag_block_definition encoded_room_distances_block_block;

	extern s_tag_block_definition game_portal_to_door_occluder_block_block;

	extern s_tag_block_definition bsp_cluster_to_room_bounds_block;

	extern s_tag_block_definition bsp_cluster_to_room_indices_block;

	extern s_tag_block_definition game_audibility_block_block;

	extern s_tag_block_definition biped_block_index_flags_block_block;

	extern s_tag_block_definition vehicle_block_index_flags_block_block;

	extern s_tag_block_definition weapon_block_index_flags_block_block;

	extern s_tag_block_definition equipment_block_index_flags_block_block;

	extern s_tag_block_definition scenery_block_index_flags_block_block;

	extern s_tag_block_definition machine_block_index_flags_block_block;

	extern s_tag_block_definition terminal_block_index_flags_block_block;

	extern s_tag_block_definition control_block_index_flags_block_block;

	extern s_tag_block_definition sound_scenery_block_index_flags_block_block;

	extern s_tag_block_definition crate_block_index_flags_block_block;

	extern s_tag_block_definition creature_block_index_flags_block_block;

	extern s_tag_block_definition giant_block_index_flags_block_block;

	extern s_tag_block_definition effect_scenery_block_index_flags_block_block;

	extern s_tag_block_definition character_block_index_flags_block_block;

	extern s_tag_block_definition budget_reference_block_index_flags_block_block;

	extern s_tag_block_definition scenario_designer_zone_block_block;

	extern s_tag_block_definition structure_device_portal_association_block_block;

	extern s_tag_block_definition game_portal_to_portal_mapping_block_block;

	extern s_tag_block_definition occluding_portal_to_portal_mapping_block_block;

	extern s_tag_block_definition structure_portal_device_mapping_block_block;

	extern s_tag_block_definition g_scenario_editor_folder_block_block;

	extern s_tag_block_definition structure_sound_cluster_portal_designators_block;

	extern s_tag_block_definition structure_sound_cluster_interior_cluster_indices_block;

	extern s_tag_block_definition structure_bsp_sound_cluster_block_block;

	extern s_tag_block_definition object_type_drag_properties_block_block;

	extern s_tag_block_definition underwater_proxies_block_block;

	extern s_tag_block_definition materials_block_block$2;

	extern s_tag_block_definition runtime_materials_block_block;

	extern s_tag_block_definition active_camo_level_definition_block_block;

	extern s_tag_block_definition active_camo_globals_block_block;

	extern s_tag_block_definition damage_globals_block_block;

	extern s_tag_block_definition shield_boost_block_block;

	extern s_tag_block_definition armor_modifier_block_block;

	extern s_tag_block_definition damage_group_block_block;

	extern s_tag_block_definition game_globals_damage_block_block;

	extern s_tag_block_definition interface_tag_references_block;

	extern s_tag_block_definition difficulty_block_block;

	extern s_tag_block_definition coop_difficulty_block_block;

	extern s_tag_block_definition sound_permutation_language_info_block;

	extern s_tag_block_definition sound_pitch_range_language_info_block;

	extern s_tag_block_definition sound_language_info_block_block;

	extern s_tag_block_definition sound_response_definition_block_block;

	extern s_tag_block_definition game_engine_event_block_block;

	extern s_tag_block_definition game_incident_daily_challenge_to_increment_block_block;

	extern s_tag_block_definition game_incident_response_block_block;

	extern s_tag_block_definition bitmap_data_block_def_block;

	extern s_tag_block_definition bitmap_tight_bounds_block_def_block;

	extern s_tag_block_definition bitmap_group_sprite_block_def_block;

	extern s_tag_block_definition bitmap_group_sequence_block_def_block;

	extern s_tag_block_definition character_voice_region_permutation_filter_block_block;

	extern s_tag_block_definition character_voice_region_filter_block_block;

	extern s_tag_block_definition character_voice_block_block;

	extern s_tag_block_definition character_variants_block_block;

	extern s_tag_block_definition character_voice_properties_block_block;

	extern s_tag_block_definition disallowed_weapons_for_trading_block_block;

	extern s_tag_block_definition character_general_block_block;

	extern s_tag_block_definition character_interact_block_block;

	extern s_tag_block_definition character_emotions_situational_danger_block_block;

	extern s_tag_block_definition character_emotions_block_block;

	extern s_tag_block_definition character_placement_block_block;

	extern s_tag_block_definition character_vitality_block_block;

	extern s_tag_block_definition character_perception_block_block;

	extern s_tag_block_definition character_target_block_block;

	extern s_tag_block_definition character_look_block_block;

	extern s_tag_block_definition movement_stationary_pause_block_block;

	extern s_tag_block_definition movement_throttle_block_block;

	extern s_tag_block_definition movement_throttle_control_block_block;

	extern s_tag_block_definition character_movement_block_block;

	extern s_tag_block_definition character_throttle_style_block_block;

	extern s_tag_block_definition movement_mapping_block_block;

	extern s_tag_block_definition character_movement_set_block_block;

	extern s_tag_block_definition character_flocking_block_block;

	extern s_tag_block_definition character_swarm_block_block;

	extern s_tag_block_definition evaluator_definition_block_block;

	extern s_tag_block_definition character_firing_point_evaluator_block_block;

	extern s_tag_block_definition character_engage_block_block;

	extern s_tag_block_definition character_evasion_block_block;

	extern s_tag_block_definition character_cover_block_block;

	extern s_tag_block_definition character_search_block_block;

	extern s_tag_block_definition character_presearch_block_block;

	extern s_tag_block_definition character_retreat_block_block;

	extern s_tag_block_definition character_charge_difficulty_limits_block_block;

	extern s_tag_block_definition character_charge_block_block;

	extern s_tag_block_definition character_ready_block_block;

	extern s_tag_block_definition character_weapons_block_block;

	extern s_tag_block_definition character_firing_pattern_block_block;

	extern s_tag_block_definition character_firing_pattern_properties_block_block;

	extern s_tag_block_definition character_grenades_block_block;

	extern s_tag_block_definition character_vehicle_block_block;

	extern s_tag_block_definition character_flying_movement_block_block;

	extern s_tag_block_definition character_idle_block_block;

	extern s_tag_block_definition character_vocalization_block_block;

	extern s_tag_block_definition character_vehicle_boarding_block_block;

	extern s_tag_block_definition character_boarding_block_block;

	extern s_tag_block_definition character_kungfu_block_block;

	extern s_tag_block_definition character_bunker_block_block;

	extern s_tag_block_definition character_guardian_block_block;

	extern s_tag_block_definition character_combatform_block_block;

	extern s_tag_block_definition character_engineer_block_block;

	extern s_tag_block_definition character_inspect_block_block;

	extern s_tag_block_definition character_scarab_block_block;

	extern s_tag_block_definition character_morph_block_block;

	extern s_tag_block_definition character_equipment_usage_block_block;

	extern s_tag_block_definition character_equipment_block_block;

	extern s_tag_block_definition character_stimuli_response_block_block;

	extern s_tag_block_definition character_activity_object_block_block;

	extern s_tag_block_definition character_pain_screen_block_block;

	extern s_tag_block_definition character_block_group_block;

	extern s_tag_block_definition ai_globals_gravemind_block_block;

	extern s_tag_block_definition ai_globals_formation_block_block;

	extern s_tag_block_definition ai_globals_squad_template_block_block;

	extern s_tag_block_definition ai_globals_squad_template_sub_folder_block_block;

	extern s_tag_block_definition ai_globals_squad_template_folder_block_block;

	extern s_tag_block_definition ai_globals_performance_template_block_block;

	extern s_tag_block_definition ai_globals_performance_template_sub_folder_block_block;

	extern s_tag_block_definition ai_globals_performance_template_folder_block_block;

	extern s_tag_block_definition ai_globals_custom_stimuli_block_block;

	extern s_tag_block_definition ai_trait_vision_block_block;

	extern s_tag_block_definition ai_trait_sound_block_block;

	extern s_tag_block_definition ai_trait_luck_block_block;

	extern s_tag_block_definition ai_trait_grenade_block_block;

	extern s_tag_block_definition ai_globals_data_block_block;

	extern s_tag_block_definition ai_globals_block_group_block;

	extern s_tag_block_definition character_palette_block_block;

	extern s_tag_block_definition big_battle_creature_palette_block_block;

	extern s_tag_block_definition ai_recording_reference_block_block;

	extern s_tag_block_definition user_hint_line_segment_block_block;

	extern s_tag_block_definition user_hint_parallelogram_block_block;

	extern s_tag_block_definition user_hint_jump_block_block;

	extern s_tag_block_definition user_hint_climb_block_block;

	extern s_tag_block_definition user_hint_well_point_block_block;

	extern s_tag_block_definition user_hint_well_block_block;

	extern s_tag_block_definition user_hint_flight_point_block_block;

	extern s_tag_block_definition user_hint_flight_block_block;

	extern s_tag_block_definition user_hint_volume_avoidance_block;

	extern s_tag_block_definition user_hint_spline_control_point_block_block;

	extern s_tag_block_definition user_hint_spline_intersect_point_block_block;

	extern s_tag_block_definition user_hint_spline_block_block;

	extern s_tag_block_definition user_hint_sector_point_block_block;

	extern s_tag_block_definition user_hint_cookie_cutter_block_block;

	extern s_tag_block_definition user_hint_flood_sector_block_block;

	extern s_tag_block_definition user_hint_giant_sector_block_block;

	extern s_tag_block_definition user_hint_giant_rail_block_block;

	extern s_tag_block_definition user_hint_flood_block_block;

	extern s_tag_block_definition user_hint_giant_block_block;

	extern s_tag_block_definition user_hint_block_block;

	extern s_tag_block_definition pathfinding_hints_block_block;

	extern s_tag_block_definition special_movement_block_block;

	extern s_tag_block_definition ai_reference_frame_block_block;

	extern s_tag_block_definition wave_squad_specification_struct_block;

	extern s_tag_block_definition wave_template_block_group_block;

	extern s_tag_block_definition patrol_point_block_block;

	extern s_tag_block_definition spawn_points_block_block;

	extern s_tag_block_definition spawn_formation_block_block;

	extern s_tag_block_definition character_palette_choice_block_block;

	extern s_tag_block_definition weapon_palette_choice_block_block;

	extern s_tag_block_definition equipment_palette_choice_block_block;

	extern s_tag_block_definition cell_block_block;

	extern s_tag_block_definition squad_groups_block_block;

	extern s_tag_block_definition squads_block_block;

	extern s_tag_block_definition character_ref_choice_block_block;

	extern s_tag_block_definition weapon_ref_choice_block_block;

	extern s_tag_block_definition equipment_ref_choice_block_block;

	extern s_tag_block_definition cell_template_block_block;

	extern s_tag_block_definition squad_template_block_group_block;

	extern s_tag_block_definition formation_point_definition_block;

	extern s_tag_block_definition formation_primitive_definition_block;

	extern s_tag_block_definition formation_block_group_block;

	extern s_tag_block_definition flock_palette_block_block;

	extern s_tag_block_definition flock_source_block_block;

	extern s_tag_block_definition flock_destination_block_block;

	extern s_tag_block_definition flock_instance_block_block;

	extern s_tag_block_definition flock_block_group_block;

	extern s_tag_block_definition mission_dialogue_variants_block_block;

	extern s_tag_block_definition mission_dialogue_lines_block_block;

	extern s_tag_block_definition ai_mission_dialogue_block_group_block;

	extern s_tag_block_definition ai_scene_role_variants_block_block;

	extern s_tag_block_definition ai_scene_role_block_block;

	extern s_tag_block_definition ai_scene_trigger_block_block;

	extern s_tag_block_definition ai_scene_block_block;

	extern s_tag_block_definition ai_scenario_mission_dialogue_block_block;

	extern s_tag_block_definition response_block_block;

	extern s_tag_block_definition vocalization_definitions_block_block;

	extern s_tag_block_definition vocalization_patterns_block_block;

	extern s_tag_block_definition dialogue_data_block_block;

	extern s_tag_block_definition involuntary_data_block_block;

	extern s_tag_block_definition predicted_data_block_block;

	extern s_tag_block_definition default_stimulus_suppressor_block_block;

	extern s_tag_block_definition ai_dialogue_globals_block_group_block;

	extern s_tag_block_definition behavior_names_block_block;

	extern s_tag_block_definition style_block_group_block;

	extern s_tag_block_definition style_palette_block_block;

	extern s_tag_block_definition order_completion_condition_block;

	extern s_tag_block_definition triggers_block_block;

	extern s_tag_block_definition trigger_references_block;

	extern s_tag_block_definition secondary_set_trigger_block_block;

	extern s_tag_block_definition order_ending_block_block;

	extern s_tag_block_definition orders_block_block;

	extern s_tag_block_definition cs_point_block_block;

	extern s_tag_block_definition cs_point_set_block_block;

	extern s_tag_block_definition cs_script_data_block_block;

	extern s_tag_block_definition sector_link_block_block;

	extern s_tag_block_definition sector_vertex_block_block;

	extern s_tag_block_definition sector_block_block;

	extern s_tag_block_definition ref_block_block;

	extern s_tag_block_definition sector_bsp2d_nodes_block_block;

	extern s_tag_block_definition environment_object_bsp_refs_block;

	extern s_tag_block_definition environment_object_refs_block;

	extern s_tag_block_definition instanced_geometry_reference_block_block;

	extern s_tag_block_definition giant_pathfinding_data_block_block;

	extern s_tag_block_definition pf_seam_link_block_block;

	extern s_tag_block_definition pf_seam_block_block;

	extern s_tag_block_definition pf_jump_index_block_block;

	extern s_tag_block_definition pf_jump_seam_block_block;

	extern s_tag_block_definition pf_door_block_block;

	extern s_tag_block_definition pathfinding_data_block_block;

	extern s_tag_block_definition firing_point_payload_block_block;

	extern s_tag_block_definition script_payload_block_block;

	extern s_tag_block_definition combat_sync_action_group_payload_block_block;

	extern s_tag_block_definition stimulus_payload_block_block;

	extern s_tag_block_definition combat_cue_payload_block_block;

	extern s_tag_block_definition task_distribution_block_block;

	extern s_tag_block_definition radial_distribution_block_block;

	extern s_tag_block_definition probability_distribution_block_block;

	extern s_tag_block_definition character_distribution_block_block;

	extern s_tag_block_definition weapon_distribution_block_block;

	extern s_tag_block_definition ai_cue_block_block;

	extern s_tag_block_definition ai_full_cue_block_block;

	extern s_tag_block_definition ai_quick_cue_block_block;

	extern s_tag_block_definition ai_cue_template_block_block;

	extern s_tag_block_definition squad_patrol_member_block_block;

	extern s_tag_block_definition squad_patrol_point_block_block;

	extern s_tag_block_definition squad_patrol_waypoint_block_block;

	extern s_tag_block_definition squad_patrol_transition_block_block;

	extern s_tag_block_definition squad_patrol_block_block;

	extern s_tag_block_definition flight_reference_block_block;

	extern s_tag_block_definition area_sector_point_block_block;

	extern s_tag_block_definition areas_block_block;

	extern s_tag_block_definition zone_block_block;

	extern s_tag_block_definition script_fragment_block_block;

	extern s_tag_block_definition task_direction_point_block_block;

	extern s_tag_block_definition task_direction_block_v2_block;

	extern s_tag_block_definition zone_set_block_block;

	extern s_tag_block_definition tasks_block_block;

	extern s_tag_block_definition opposing_objective_block_block;

	extern s_tag_block_definition objectives_block_block;

	extern s_tag_block_definition firing_positions_block_block;

	extern s_tag_block_definition emblem_bitmap_list_block;

	extern s_tag_block_definition emblem_shape_list_block;

	extern s_tag_block_definition emblem_front_list_block;

	extern s_tag_block_definition emblem_back_list_block;

	extern s_tag_block_definition emblem_runtime_back_list_block;

	extern s_tag_block_definition emblem_runtime_front_list_block;

	extern s_tag_block_definition emblem_library_block_group_block;

	extern s_tag_block_definition chud_widget_state_or_block_block;

	extern s_tag_block_definition chud_widget_state_and_block_block;

	extern s_tag_block_definition chud_widget_state_editor_block_block;

	extern s_tag_block_definition chud_widget_state_data_base_block_block;

	extern s_tag_block_definition chud_widget_state_data_template_block_group_block;

	extern s_tag_block_definition chud_widget_placement_data_base_block_block;

	extern s_tag_block_definition chud_widget_placement_data_template_block_group_block;

	extern s_tag_block_definition chud_datasource_position_block_block;

	extern s_tag_block_definition chud_datasource_resolution_block_block;

	extern s_tag_block_definition chud_widget_datasource_base_block_block;

	extern s_tag_block_definition chud_widget_datasource_template_block_group_block;

	extern s_tag_block_definition chud_widget_render_data_base_block_block;

	extern s_tag_block_definition chud_widget_render_data_template_block_group_block;

	extern s_tag_block_definition chud_widget_animation_data_base_block_block;

	extern s_tag_block_definition chud_widget_animation_data_template_block_group_block;

	extern s_tag_block_definition chud_widget_bitmap_block_block;

	extern s_tag_block_definition chud_widget_text_block_block;

	extern s_tag_block_definition chud_widget_object_highlight_block_block;

	extern s_tag_block_definition chud_widget_collection_block_block;

	extern s_tag_block_definition chud_widget_update_cache_block_block;

	extern s_tag_block_definition chud_definition_block_group_block;

	extern s_tag_block_definition chud_keyframe_position_block_block;

	extern s_tag_block_definition chud_keyframe_rotation_block_block;

	extern s_tag_block_definition chud_keyframe_scale_block_block;

	extern s_tag_block_definition chud_keyframe_color_block_block;

	extern s_tag_block_definition chud_keyframe_scalar_block_block;

	extern s_tag_block_definition chud_keyframe_texture_block_block;

	extern s_tag_block_definition chud_keyframe_external_input_block_block;

	extern s_tag_block_definition chud_animation_position_block_block;

	extern s_tag_block_definition chud_animation_rotation_block_block;

	extern s_tag_block_definition chud_animation_scale_block_block;

	extern s_tag_block_definition chud_animation_scalar_block_block;

	extern s_tag_block_definition chud_animation_texture_block_block;

	extern s_tag_block_definition chud_animation_external_input_a_block_block;

	extern s_tag_block_definition chud_animation_external_input_b_block_block;

	extern s_tag_block_definition chud_animation_color_block_block;

	extern s_tag_block_definition chud_animation_definition_block_group_block;

	extern s_tag_block_definition chud_curvature_info_block_block;

	extern s_tag_block_definition chud_sound_block_block;

	extern s_tag_block_definition chud_scripted_object_priority_definition_block;

	extern s_tag_block_definition chud_skin_info_block_block;

	extern s_tag_block_definition chud_shader_block_block;

	extern s_tag_block_definition chud_suck_profile_block_block;

	extern s_tag_block_definition chud_state_category_block_block;

	extern s_tag_block_definition chud_globals_definition_block_group_block;

	extern s_tag_block_definition property_long_value_block;

	extern s_tag_block_definition property_real_value_block;

	extern s_tag_block_definition property_string_id_value_block;

	extern s_tag_block_definition property_tag_reference_value_block;

	extern s_tag_block_definition property_text_value_block;

	extern s_tag_block_definition property_argb_color_value_block;

	extern s_tag_block_definition property_binding_block;

	extern s_tag_block_definition binding_conversion_long_comparison_block_definition_block;

	extern s_tag_block_definition animation_property_keyframe_real_value_block;

	extern s_tag_block_definition animation_property_keyframe_argb_color_value_block;

	extern s_tag_block_definition animation_component_real_property_block;

	extern s_tag_block_definition animation_component_argb_color_property_block;

	extern s_tag_block_definition animation_component_definition_block;

	extern s_tag_block_definition animation_definition_block;

	extern s_tag_block_definition static_data_column_block;

	extern s_tag_block_definition static_data_row_block;

	extern s_tag_block_definition cui_static_data_block_group_block;

	extern s_tag_block_definition static_data_table_block;

	extern s_tag_block_definition expression_step_block;

	extern s_tag_block_definition expression_block;

	extern s_tag_block_definition template_instantiation_block_definition_block;

	extern s_tag_block_definition component_definition_block;

	extern s_tag_block_definition component_index_block_definition_block;

	extern s_tag_block_definition component_properties_definition_block;

	extern s_tag_block_definition overlay_definition_block;

	extern s_tag_block_definition property_editor_only_definition_block;

	extern s_tag_block_definition component_editor_only_definition_block;

	extern s_tag_block_definition animation_editor_only_definition_block;

	extern s_tag_block_definition overlay_editor_only_definition_block;

	extern s_tag_block_definition cui_screen_block_group_block;

	extern s_tag_block_definition color_presets_block_block;

	extern s_tag_block_definition color_list_block_block;

	extern s_tag_block_definition tint_colors_block_block;

	extern s_tag_block_definition gui_alert_description_block_block;

	extern s_tag_block_definition gui_dialog_description_block_block;

	extern s_tag_block_definition user_interface_sounds_definition_block_group_block;

	extern s_tag_block_definition pgcr_incident_block_block;

	extern s_tag_block_definition pgcr_player_to_category_entry_block_block;

	extern s_tag_block_definition pgcr_enemy_to_category_entry_block_block;

	extern s_tag_block_definition pgcr_enemy_to_category_list_block_block;

	extern s_tag_block_definition pgcr_enemy_to_category_mapping_definition_block_group_block;

	extern s_tag_block_definition user_interface_shared_globals_definition_block_group_block;

	extern s_tag_block_definition cui_component_screen_reference_block_definition_block;

	extern s_tag_block_definition cui_overlay_camera_block_definition_block;

	extern s_tag_block_definition cui_player_model_camera_settings_definition_block;

	extern s_tag_block_definition cui_player_model_controller_settings_definition_block;

	extern s_tag_block_definition cui_player_model_transition_settings_definition_block;

	extern s_tag_block_definition cui_active_roster_settings_block_block;

	extern s_tag_block_definition campaign_state_screen_script_block_definition_block;

	extern s_tag_block_definition user_interface_globals_definition_block_group_block;

	extern s_tag_block_definition text_value_pair_reference_block_block;

	extern s_tag_block_definition text_value_pair_definition_block_group_block;

	extern s_tag_block_definition sandbox_property_allowed_values_reference_block_block;

	extern s_tag_block_definition sandbox_text_value_pair_definition_block_group_block;

	extern s_tag_block_definition variant_option_block_block;

	extern s_tag_block_definition variant_setting_edit_reference_block_block;

	extern s_tag_block_definition multiplayer_variant_settings_interface_definition_block_group_block;

	extern s_tag_block_definition meter_block_group_block;

	extern s_tag_block_definition load_screen_data_block_block;

	extern s_tag_block_definition load_screen_globals_block_group_block;

	extern s_tag_block_definition rasterizer_cache_file_globals_block_group_block;

	extern s_tag_block_definition structure_lighting_generic_light_definition_block_block;

	extern s_tag_block_definition lightmapper_globals_block_group_block;

	extern s_tag_block_definition atmosphere_setting_block_block;

	extern s_tag_block_definition underwater_setting_block_block$2;

	extern s_tag_block_definition sky_atm_parameters_block_group_block;

	extern s_tag_block_definition mux_generator_material_block_block;

	extern s_tag_block_definition mux_generator_block_group_block;

	extern s_tag_block_definition render_water_ripple_block_group_block;

	extern s_tag_block_definition simulation_interpolation_block_group_block;

	extern s_tag_block_definition fluid_dynamics_squirter_block_block;

	extern s_tag_block_definition fluid_dynamics_inflow_block_block;

	extern s_tag_block_definition fluid_dynamics_outflow_block_block;

	extern s_tag_block_definition fluid_dynamics_obstacle_block_block;

	extern s_tag_block_definition fluid_dynamics_block_group_block;

	extern s_tag_block_definition vocalization_stimuli_block_definition_block;

	extern s_tag_block_definition sound_references_block_block;

	extern s_tag_block_definition dialogue_block_group_block;

	extern s_tag_block_definition stereo_system_block_group_block;

	extern s_tag_block_definition states_block_block;

	extern s_tag_block_definition rules_block_block;

	extern s_tag_block_definition cellular_automata2d_block_group_block;

	extern s_tag_block_definition cellular_automata_block_group_block;

	extern s_tag_block_definition antenna_vertex_block_block;

	extern s_tag_block_definition antenna_block_group_block;

	extern s_tag_block_definition predicted_bitmaps_block_block;

	extern s_tag_block_definition item_block_group_block;

	extern s_tag_block_definition cheap_light_block_group_block;

	extern s_tag_block_definition giant_buckle_parameters_block_block;

	extern s_tag_block_definition giant_block_group_block;

	extern s_tag_block_definition crate_block_group_block;

	extern s_tag_block_definition scenery_block_group_block;

	extern s_tag_block_definition collision_damage_block_group_block;

	extern s_tag_array_definition runtime_queryable_properties;

	extern s_tag_array_definition gpu_single_constant_register_array;

	extern s_tag_array_definition gpu_function_sub_array;

	extern s_tag_array_definition gpu_color_sub_array;

	extern s_tag_array_definition gpu_property_sub_array;

	extern s_tag_array_definition node_indices_array;

	extern s_tag_array_definition node_weights_implicit_array;

	extern s_tag_array_definition node_weights_complete_array;

	extern s_tag_array_definition vertex_buffer_indices_word_array;

	extern s_tag_array_definition lightprobe_terms;

	extern s_tag_array_definition single_vmf_terms;

	extern s_tag_array_definition dual_vmf_terms;

	extern s_tag_array_definition uber_light_index_mapping_per_bsp_data;

	extern s_tag_array_definition object_salt_storage_array;

	extern s_tag_array_definition data_hash_definition;

	extern s_tag_array_definition multilingual_unicode_string_list_language_pack_offsets;

	extern s_tag_array_definition runtime_region_index_array;

	extern s_tag_array_definition model_state_permutation_index_array;

	extern s_tag_array_definition radiance_transfer_matrix;

	extern s_tag_array_definition default_lightprobe;

	extern s_tag_array_definition default_dual_vmf;

	extern s_tag_array_definition sun_direction_intensity;

	extern s_tag_array_definition multi_sphere_vector_storage;

	extern s_tag_array_definition g_node_flag_storage_array;

	extern s_tag_array_definition animation_velocity_boundaries;

	extern s_tag_array_definition super_node_mapping_index_array;

	extern s_tag_array_definition game_engine_team_options_team_block;

	extern s_tag_array_definition resource_hash_definition;

	extern s_tag_array_definition faux_data_dual_vmf_terms;

	extern s_tag_array_definition error_point_node_index_array;

	extern s_tag_array_definition error_point_node_weight_array;

	extern s_tag_array_definition error_report_line_point_array;

	extern s_tag_array_definition error_report_triangle_point_array;

	extern s_tag_array_definition error_report_quad_point_array;

	extern s_tag_array_definition supported_bitfield;

	extern s_tag_array_definition render_interleaved_texture_array_definition;

	extern s_tag_array_definition area_cluster_occupancy_bitvector_array;

	extern s_tag_array_definition screen_transform_basis_array_definition;

	extern s_tag_struct_definition shader_contrail_struct_definition;
	extern s_tag_reference_definition render_method_definition_group_reference_tagref;
	extern s_tag_reference_definition render_method_group_reference_tagref;
	extern s_string_list_definition global_render_method_lock_option_flags_defintion;
	extern s_string_list_definition global_render_method_flags_defintion;
	extern s_string_list_definition global_sort_layer_enum_defintion;

	extern s_tag_struct_definition shader_particle_struct_definition;
	extern s_tag_reference_definition bitmap_group_reference$2_tagref;

	extern s_tag_struct_definition biped_group_struct_definition;
	extern s_string_list_definition biped_definition_flags;
	extern s_tag_reference_definition death_program_selector_group_reference_tagref;
	extern s_tag_reference_definition effect_group_reference_tagref;
	extern s_tag_reference_definition character_group_reference$3_tagref;
	extern s_tag_reference_definition muffin_group_reference_tagref;

	extern s_tag_struct_definition crate_struct_definition;
	extern s_string_list_definition crate_flags;

	extern s_tag_struct_definition creature_struct_definition;
	extern s_string_list_definition creature_definition_flags;
	extern s_string_list_definition unit_default_teams;
	extern s_string_list_definition global_chud_blip_type_definition;
	extern s_tag_reference_definition damage_effect_group_reference_tagref;
	extern s_string_list_definition creature_big_battle_definition_flags;
	extern s_tag_reference_definition cheap_particle_emitter_group_reference$2_tagref;

	extern s_tag_struct_definition device_control_struct_definition;
	extern s_string_list_definition control_types;
	extern s_string_list_definition control_triggers;
	extern s_tag_reference_definition _reference$7_tagref;

	extern s_tag_struct_definition device_struct_definition;
	extern s_string_list_definition device_definition_flags;
	extern s_string_list_definition device_lightmap_flags;

	extern s_tag_struct_definition effect_scenery_struct_definition;

	extern s_tag_struct_definition equipment_group_struct_definition;
	extern s_string_list_definition equipment_flags;
	extern s_string_list_definition equipment_activation_mode;
	extern s_string_list_definition global_damage_reporting_enum_definition;
	extern s_tag_reference_definition chud_definition_group_reference_tagref;
	extern s_tag_reference_definition _reference_tagref;

	extern s_tag_struct_definition giant_struct_definition;
	extern s_string_list_definition giant_definition_flags;

	extern s_tag_struct_definition item_struct_definition;
	extern s_string_list_definition item_definition_flags;
	extern s_tag_reference_definition grounded_friction_group_reference_tagref;

	extern s_tag_struct_definition device_machine_struct_definition;
	extern s_string_list_definition machine_types;
	extern s_string_list_definition machine_flags;
	extern s_string_list_definition machine_collision_responses;
	extern s_string_list_definition machine_pathfinding_policy_enum;

	extern s_tag_struct_definition projectile_group_struct_definition;
	extern s_string_list_definition projectile_flags;
	extern s_string_list_definition projectile_detonation_timer_modes;
	extern s_string_list_definition ai_sound_volume_enum;
	extern s_string_list_definition object_type_enum_definition;
	extern s_tag_reference_definition damage_response_definition_group_reference$2_tagref;

	extern s_tag_struct_definition shader_beam_struct_definition;

	extern s_tag_struct_definition shader_custom_struct_definition;

	extern s_tag_struct_definition shader_cortana_struct_definition;

	extern s_tag_struct_definition shader_decal_struct_definition;

	extern s_tag_struct_definition shader_foliage_struct_definition;

	extern s_tag_struct_definition shader_fur_stencil_struct_definition;

	extern s_tag_struct_definition shader_fur_struct_definition;

	extern s_tag_struct_definition shader_glass_struct_definition;

	extern s_tag_struct_definition shader_halogram_struct_definition;

	extern s_tag_struct_definition shader_light_volume_struct_definition;

	extern s_tag_struct_definition shader_mux_material_struct_definition;

	extern s_tag_struct_definition shader_mux_struct_definition;

	extern s_tag_struct_definition shader_struct_definition;

	extern s_tag_struct_definition shader_skin_struct_definition;

	extern s_tag_struct_definition shader_screen_struct_definition;
	extern s_string_list_definition global_screen_shader_render_layer_enum;
	extern s_string_list_definition global_screen_shader_flags_definition;

	extern s_tag_struct_definition shader_terrain_struct_definition;

	extern s_tag_struct_definition shader_water_struct_definition;

	extern s_tag_struct_definition scenery_group_struct_definition;
	extern s_string_list_definition pathfinding_policy_enum$2;
	extern s_string_list_definition scenery_flags;
	extern s_string_list_definition lightmapping_policy_enum;

	extern s_tag_struct_definition sound_scenery_struct_definition;

	extern s_tag_struct_definition device_terminal_struct_definition;
	extern s_tag_reference_definition sound_group_reference$3_tagref;
	extern s_tag_reference_definition multilingual_unicode_string_list_group_reference_tagref;

	extern s_tag_struct_definition unit_struct_definition;
	extern s_string_list_definition unit_flags;
	extern s_string_list_definition unit_default_teams$2;
	extern s_tag_reference_definition _reference$4_tagref;
	extern s_tag_reference_definition damage_response_definition_group_reference_tagref;
	extern s_tag_reference_definition weapon_group_reference$3_tagref;
	extern s_tag_reference_definition spring_acceleration_group_reference_tagref;
	extern s_tag_reference_definition character_group_reference$2_tagref;
	extern s_string_list_definition global_melee_class_enum_definition;
	extern s_string_list_definition unit_item_owner_size_enum;
	extern s_string_list_definition global_grenade_type_enum;
	extern s_tag_reference_definition weapon_group_reference$2_tagref;

	extern s_tag_struct_definition vehicle_group_struct_definition;
	extern s_string_list_definition vehicle_flags$2;
	extern s_string_list_definition player_training_vehicle_type_enum;
	extern s_string_list_definition vehicle_size_enum;
	extern s_tag_reference_definition _reference$10_tagref;

	extern s_tag_struct_definition weapon_struct_definition;
	extern s_string_list_definition weapon_definition_flags;
	extern s_string_list_definition weapon_definition_secondary_flags;
	extern s_string_list_definition secondary_trigger_modes;
	extern s_tag_reference_definition _reference$22_tagref;
	extern s_string_list_definition movement_penalty_modes;
	extern s_string_list_definition weapon_types;
	extern s_tag_reference_definition vehicle_group_reference$5_tagref;
	extern s_tag_reference_definition material_effects_group_reference_tagref;

	extern s_tag_struct_definition camera_fx_exposure_struct;
	extern s_string_list_definition camera_fx_parameter_flags_auto_adjust;

	extern s_tag_struct_definition camera_fx_exposure_sensitivity_struct;
	extern s_string_list_definition camera_fx_parameter_flags_no_auto_adjust;

	extern s_tag_struct_definition camera_fx_bloom_highlight_struct;

	extern s_tag_struct_definition camera_fx_bloom_inherent_struct;

	extern s_tag_struct_definition camera_fx_bloom_intensity_struct;

	extern s_tag_struct_definition camera_fx_bloom_large_color_struct;

	extern s_tag_struct_definition camera_fx_bloom_medium_color_struct;

	extern s_tag_struct_definition camera_fx_bloom_small_color_struct;

	extern s_tag_struct_definition camera_fx_bling_intensity_struct;

	extern s_tag_struct_definition camera_fx_bling_size_struct;

	extern s_tag_struct_definition camera_fx_bling_angle_struct;

	extern s_tag_struct_definition camera_fx_bling_count_struct;
	extern s_string_list_definition camera_fx_parameter_flags_bling_spikes;

	extern s_tag_struct_definition camera_fx_self_illum_preferred_struct;

	extern s_tag_struct_definition camera_fx_self_illum_scale_struct;

	extern s_tag_struct_definition camera_fx_settings_block;

	extern s_tag_struct_definition performane_throttle_block;
	extern s_string_list_definition performance_throttle_flags;

	extern s_tag_struct_definition performance_throttles_struct_definition;

	extern s_tag_struct_definition default_textures_refs_block;
	extern s_string_list_definition global_bitmap_flags;
	extern s_tag_reference_definition bitmap_group_reference$11_tagref;

	extern s_tag_struct_definition material_textures_refs_block;

	extern s_tag_struct_definition atmosphere_textures_refs_block;

	extern s_tag_struct_definition explicit_shader_refs_block;
	extern s_tag_reference_definition vertex_shader_group_reference_tagref;
	extern s_tag_reference_definition pixel_shader_group_reference_tagref;

	extern s_tag_struct_definition rasterizer_globals_struct_definition;
	extern s_tag_reference_definition vertex_shader_group_reference$2_tagref;
	extern s_tag_reference_definition pixel_shader_group_reference$2_tagref;
	extern s_tag_reference_definition performance_throttles_group_reference_tagref;
	extern s_tag_reference_definition vision_mode_group_reference_tagref;
	extern s_tag_reference_definition cheap_particle_type_library_group_reference$2_tagref;
	extern s_tag_reference_definition emblem_library_group_reference_tagref;

	extern s_tag_struct_definition rasterizer_constant_block;
	extern s_string_list_definition register_set_enum;

	extern s_tag_struct_definition global_rasterizer_constant_table_struct;
	extern s_string_list_definition rasterizer_constant_table_type_enum;

	extern s_tag_struct_definition rasterizer_compiled_shader_struct;
	extern s_string_list_definition shader_flags;

	extern s_tag_struct_definition vertex_types_block$2;

	extern s_tag_struct_definition compiled_vertex_shader_block;

	extern s_tag_struct_definition vertex_entry_point_block;

	extern s_tag_struct_definition pixel_entry_point_block;

	extern s_tag_struct_definition compiled_pixel_shader_block;

	extern s_tag_struct_definition vertex_shader_block_struct;
	extern s_string_list_definition entry_points_flags;

	extern s_tag_struct_definition pixel_shader_block_struct;

	extern s_tag_struct_definition global_cache_file_pixel_shaders_struct_definition;

	extern s_tag_struct_definition hlsl_include_struct_definition;

	extern s_tag_struct_definition global_shader_option_dependency;

	extern s_tag_struct_definition global_shader_category_dependency;

	extern s_tag_struct_definition global_shader_entry_point_block;

	extern s_tag_struct_definition global_vertex_shader_vertex_types_block;

	extern s_tag_struct_definition global_vertex_shader_block_struct;

	extern s_tag_struct_definition global_pixel_shader_block_struct;

	extern s_tag_struct_definition material_type_struct;

	extern s_tag_struct_definition tag_block_index_struct;

	extern s_tag_struct_definition tag_block_index_block;

	extern s_tag_struct_definition short_block;

	extern s_tag_struct_definition real_vector4d_block;

	extern s_tag_struct_definition int_block;

	extern s_tag_struct_definition render_method_options_block;
	extern s_tag_reference_definition render_method_option_group_reference_tagref;

	extern s_tag_struct_definition render_method_category_block;

	extern s_tag_struct_definition render_method_pass_category_dependencies;

	extern s_tag_struct_definition render_method_pass_block;
	extern s_string_list_definition render_method_pass_flags;

	extern s_tag_struct_definition render_method_entry_points_block;
	extern s_string_list_definition entry_point_enum;

	extern s_tag_struct_definition vertex_types_block;
	extern s_string_list_definition vertex_types_names_enum;

	extern s_tag_struct_definition render_method_definition_struct_definition;
	extern s_tag_reference_definition global_pixel_shader_group_reference_tagref;
	extern s_tag_reference_definition global_vertex_shader_group_reference_tagref;
	extern s_string_list_definition render_method_definition_flags;

	extern s_tag_struct_definition render_method_option_parameter_block;
	extern s_string_list_definition render_method_parameter_type_enum;
	extern s_string_list_definition render_method_extern_enum;
	extern s_string_list_definition render_method_bitmap_filter_mode_enum;
	extern s_string_list_definition render_method_bitmap_address_mode_enum;
	extern s_string_list_definition ui_and_usage_flags;
	extern s_string_list_definition function_type_enum_definition;
	extern s_string_list_definition color_graph_type_enum_definition;

	extern s_tag_struct_definition render_method_option_struct_definition;

	extern s_tag_struct_definition render_method_locked_parameter_block;

	extern s_tag_struct_definition render_method_animated_parameter_block;
	extern s_string_list_definition render_method_animated_parameter_type_enum;

	extern s_tag_struct_definition render_method_parameter_block;
	extern s_tag_reference_definition bitmap_group_reference_tagref;

	extern s_tag_struct_definition render_method_postprocess_texture_block;

	extern s_tag_struct_definition render_method_postprocess_pass_block;

	extern s_tag_struct_definition render_method_routing_info_block;

	extern s_tag_struct_definition runtime_queryable_properties_struct_definition;

	extern s_tag_struct_definition render_method_postprocess_block;
	extern s_tag_reference_definition render_method_template_group_reference_tagref;

	extern s_tag_struct_definition render_method_struct_definition;

	extern s_tag_struct_definition render_method_template_constant_table_block;

	extern s_tag_struct_definition render_method_template_pass_block;

	extern s_tag_struct_definition render_method_template_platform_block;
	extern s_tag_reference_definition vertex_shader_group_reference$3_tagref;
	extern s_tag_reference_definition pixel_shader_group_reference$3_tagref;

	extern s_tag_struct_definition render_method_template_struct_definition;

	extern s_tag_struct_definition planar_fog_parameters_struct_definition;
	extern s_string_list_definition planar_fog_flags;

	extern s_tag_struct_definition planar_fog_vertex_block;

	extern s_tag_struct_definition planar_fog_triangle_planes_block;

	extern s_tag_struct_definition planar_fog_triangle_block;

	extern s_tag_struct_definition planar_fog_definition_block;
	extern s_tag_reference_definition planar_fog_parameters_group_reference_tagref;

	extern s_tag_struct_definition planar_fog_set_definition_struct;

	extern s_tag_struct_definition planar_fog_reference_definition_block;

	extern s_tag_struct_definition planar_fog_cluster_visibility_definition_block;

	extern s_tag_struct_definition planar_fog_structure_visibility_definition_block;

	extern s_tag_struct_definition planar_fog_zone_set_visibility_definition_block;

	extern s_tag_struct_definition ssao_definition_struct_definition;
	extern s_string_list_definition ssao_downsample_enum_definition;
	extern s_string_list_definition ssao_type_enum_definition;

	extern s_tag_struct_definition underwater_setting_block;

	extern s_tag_struct_definition atmosphere_globals_struct_definition;

	extern s_tag_struct_definition per_object_type_relative_min_luminance_block;

	extern s_tag_struct_definition chocolate_mountain_new_struct_definition;

	extern s_tag_struct_definition global_textures_refs_block;

	extern s_tag_struct_definition rain_ripple_setting_block;

	extern s_tag_struct_definition weather_globals_struct_definition;
	extern s_tag_reference_definition rain_definition_group_reference_tagref;

	extern s_tag_struct_definition decorator_set_instance_name_block;

	extern s_tag_struct_definition global_decorator_type_struct;
	extern s_string_list_definition decorator_type_flags_definition;

	extern s_tag_struct_definition decorator_set_block;
	extern s_tag_reference_definition render_model_group_reference_tagref;
	extern s_tag_reference_definition bitmap_group_reference$7_tagref;
	extern s_string_list_definition decorator_set_render_flags_definition;
	extern s_string_list_definition decorator_set_render_shader_enum_definition;
	extern s_string_list_definition decorator_set_lighting_sample_pattern_enum_definition;

	extern s_tag_struct_definition decorator_runtime_cluster_block;

	extern s_tag_struct_definition solo_fog_parameters_struct_definition;

	extern s_tag_struct_definition fog_light_struct_definition;

	extern s_tag_struct_definition atmosphere_definition_block;
	extern s_string_list_definition atmosphere_flags;

	extern s_tag_struct_definition rain_definition_struct_definition;
	extern s_tag_reference_definition area_screen_effect_group_reference_tagref;
	extern s_tag_reference_definition camera_fx_settings_group_reference_tagref;
	extern s_string_list_definition rain_particle_flags;

	extern s_tag_struct_definition light_scalar_function_struct;
	extern s_string_list_definition output_mod_enum$4;

	extern s_tag_struct_definition light_color_function_struct;

	extern s_tag_struct_definition light_struct_definition;
	extern s_string_list_definition light_type_enum;
	extern s_string_list_definition light_definition_flags;
	extern s_string_list_definition light_type_enum_definition;
	extern s_string_list_definition light_shadow_quality_enumeration;
	extern s_tag_reference_definition bitmap_group_reference$8_tagref;
	extern s_string_list_definition light_priority_enumeration;
	extern s_tag_reference_definition lens_flare_group_reference_tagref;
	extern s_string_list_definition light_clip_flags_definition;

	extern s_tag_struct_definition equipment_type_multiplayer_powerup_block;
	extern s_string_list_definition multiplayer_powerup_flavor;

	extern s_tag_struct_definition equipment_type_spawner_block;
	extern s_tag_reference_definition object_group_reference$2_tagref;
	extern s_string_list_definition equipment_spawner_spawn_type;

	extern s_tag_struct_definition equipment_type_proximity_mine_block;

	extern s_tag_struct_definition equipment_type_motion_tracker_noise_block;

	extern s_tag_struct_definition equipment_type_showme_block;

	extern s_tag_struct_definition equipment_effect_with_threshold_block;

	extern s_tag_struct_definition equipment_type_invincibility_block;
	extern s_tag_reference_definition collision_damage_group_reference$3_tagref;
	extern s_tag_reference_definition damage_effect_group_reference$3_tagref;

	extern s_tag_struct_definition equipment_type_treeoflife_block;
	extern s_string_list_definition equipment_type_treeoflife_flags;

	extern s_tag_struct_definition equipment_type_shapeshifter_block;

	extern s_tag_struct_definition equipment_type_player_trait_field_block;

	extern s_tag_struct_definition ai_equipment_trait_appearance_block;
	extern s_string_list_definition ai_equipement_trait_appearance_active_camo_settings;

	extern s_tag_struct_definition ai_equipment_traits_block;

	extern s_tag_struct_definition equipment_type_ai_trait_field_block;

	extern s_tag_struct_definition equipment_type_repulsor_field_block;
	extern s_string_list_definition repulsor_field_flags;

	extern s_tag_struct_definition equipment_type_daddy_block;
	extern s_string_list_definition equipment_type_daddy_visible_flags;

	extern s_tag_struct_definition equipment_type_laser_designation_block;

	extern s_tag_struct_definition equipment_type_super_jump_block;

	extern s_tag_struct_definition equipment_type_ammo_pack_block;

	extern s_tag_struct_definition equipment_type_power_fist_block;

	extern s_tag_struct_definition equipment_type_health_pack_block;

	extern s_tag_struct_definition equipment_type_jet_pack_block;

	extern s_tag_struct_definition equipment_type_hologram_block;
	extern s_string_list_definition collision_filter_enum;

	extern s_tag_struct_definition equipment_type_special_weapon_block;

	extern s_tag_struct_definition equipment_type_special_move_block;

	extern s_tag_struct_definition equipment_type_engineer_shields_block;
	extern s_string_list_definition equipment_engineer_shields_flags;

	extern s_tag_struct_definition equipment_type_sprint_block;

	extern s_tag_struct_definition optional_unit_camera_block;

	extern s_tag_struct_definition airstrike_fire_location_block;

	extern s_tag_struct_definition airstrike_battery_block;

	extern s_tag_struct_definition airstrike_struct_definition;

	extern s_tag_struct_definition brute_grenade_block;

	extern s_tag_struct_definition fire_bomb_grenade_block;

	extern s_tag_struct_definition conical_projection_block;

	extern s_tag_struct_definition old_projectile_material_response_block;
	extern s_string_list_definition material_response;
	extern s_string_list_definition material_possible_response_flags;
	extern s_string_list_definition effect_scale_enum;

	extern s_tag_struct_definition projectile_material_response_block;

	extern s_tag_struct_definition angular_velocity_lower_bound_struct;

	extern s_tag_struct_definition super_detonation_damage_struct;

	extern s_tag_struct_definition tracking_type_block;

	extern s_tag_struct_definition global_target_tracking_parameters_block;
	extern s_tag_reference_definition _reference$5_tagref;

	extern s_tag_struct_definition weapon_barrel_first_person_offset_block;

	extern s_tag_struct_definition weapon_barrel_firing_parameters_struct;

	extern s_tag_struct_definition weapon_barrel_firing_error_struct;

	extern s_tag_struct_definition weapon_barrel_function_block;

	extern s_tag_struct_definition weapon_barrel_projectile_accuracy_penalty_function_struct;

	extern s_tag_struct_definition weapon_barrel_projectile_accuracy_penalty_struct;

	extern s_tag_struct_definition weapon_trigger_autofire_struct;
	extern s_string_list_definition weapon_trigger_autofire_actions;

	extern s_tag_struct_definition weapon_trigger_charging_fire_fraction;

	extern s_tag_struct_definition weapon_trigger_charging_struct;
	extern s_string_list_definition weapon_trigger_overcharged_actions;
	extern s_string_list_definition weapon_trigger_charging_flags;

	extern s_tag_struct_definition weapon_triggers;
	extern s_string_list_definition weapon_trigger_definition_flags;
	extern s_string_list_definition weapon_trigger_inputs;
	extern s_string_list_definition weapon_trigger_behaviors;
	extern s_string_list_definition trigger_prediction_type_enum;

	extern s_tag_struct_definition aim_assist_struct;

	extern s_tag_struct_definition melee_damage_parameters_block;

	extern s_tag_struct_definition weapon_first_person_interface_block;
	extern s_tag_reference_definition render_model_group_reference$7_tagref;
	extern s_tag_reference_definition model_animation_graph_group_reference$3_tagref;

	extern s_tag_struct_definition weapon_shared_interface_struct;

	extern s_tag_struct_definition weapon_interface_struct;

	extern s_tag_struct_definition weapon_screen_effect_block;
	extern s_string_list_definition weapon_screen_effect_flags;

	extern s_tag_struct_definition magazine_objects;
	extern s_tag_reference_definition equipment_group_reference$3_tagref;

	extern s_tag_struct_definition magazines;
	extern s_string_list_definition magazine_flags;

	extern s_tag_struct_definition barrel_firing_effect_block;

	extern s_tag_struct_definition weapon_barrel_damage_effect_struct;

	extern s_tag_struct_definition weapon_barrels;
	extern s_string_list_definition weapon_barrel_flags;
	extern s_string_list_definition barrel_prediction_type_enum;
	extern s_string_list_definition weapon_barrel_distribution_functions;
	extern s_tag_reference_definition projectile_group_reference$2_tagref;
	extern s_tag_reference_definition crate_group_reference$4_tagref;

	extern s_tag_struct_definition garbage_collection_block;

	extern s_tag_struct_definition unit_hud_reference_block;

	extern s_tag_struct_definition unit_camera_track_block;
	extern s_tag_reference_definition camera_track_group_reference_tagref;

	extern s_tag_struct_definition unit_camera_acceleration_displacement_function_struct;
	extern s_string_list_definition unit_camera_acceleration_displacement_input;

	extern s_tag_struct_definition unit_camera_acceleration_displacement_block;

	extern s_tag_struct_definition unit_camera_struct;
	extern s_string_list_definition unit_camera_flags_definition;

	extern s_tag_struct_definition unit_postures_block;

	extern s_tag_struct_definition boarding_seat_block;

	extern s_tag_struct_definition unit_weapon_block;
	extern s_string_list_definition initial_weapon_position;

	extern s_tag_struct_definition powered_seat_block;

	extern s_tag_struct_definition dialogue_variant_block;
	extern s_tag_reference_definition dialogue_group_reference_tagref;

	extern s_tag_struct_definition unit_boost_struct;
	extern s_tag_reference_definition collision_damage_group_reference$2_tagref;
	extern s_string_list_definition boost_flags;

	extern s_tag_struct_definition unit_screen_effect_block;

	extern s_tag_struct_definition unit_seat_block;
	extern s_string_list_definition unit_seat_flags;
	extern s_string_list_definition global_ai_seat_type_enum;

	extern s_tag_struct_definition unit_boarding_melee_struct;

	extern s_tag_struct_definition unit_additional_node_names_struct;

	extern s_tag_struct_definition unit_lipsync_scales_struct;

	extern s_tag_struct_definition damage_response_directional_flash_struct;
	extern s_string_list_definition global_reverse_transition_functions_enum;

	extern s_tag_struct_definition damage_response_motion_sensor_ping;

	extern s_tag_struct_definition area_control_scalar_function_struct;

	extern s_tag_struct_definition area_control_scalar_object_function_struct;

	extern s_tag_struct_definition area_control_block_struct;
	extern s_string_list_definition area_control_flags;

	extern s_tag_struct_definition damage_response_global_sound_effect_block_struct;

	extern s_tag_struct_definition damage_response_class_block;
	extern s_string_list_definition damage_response_class_type_enum;
	extern s_string_list_definition damage_response_class_flags;
	extern s_tag_reference_definition rumble_group_reference_tagref;
	extern s_tag_reference_definition camera_shake_group_reference_tagref;
	extern s_tag_reference_definition simulated_input_group_reference_tagref;

	extern s_tag_struct_definition damage_response_definition_struct_definition;

	extern s_tag_struct_definition custom_damage_response_label_block;

	extern s_tag_struct_definition damage_effect_sound_block_struct;
	extern s_string_list_definition damage_effect_sound_type_flags;

	extern s_tag_struct_definition damage_outer_cone_angle_struct;

	extern s_tag_struct_definition damage_effect_group_struct_definition;
	extern s_string_list_definition damage_effect_flags;
	extern s_string_list_definition damage_side_effects;
	extern s_string_list_definition damage_categories;
	extern s_string_list_definition damage_death_vocalizations;
	extern s_string_list_definition damage_flags;

	extern s_tag_struct_definition muffin_permutation_name_block;

	extern s_tag_struct_definition muffin_scalar_function_struct;

	extern s_tag_struct_definition global_muffin_type_struct;
	extern s_string_list_definition muffin_type_flags_definition;

	extern s_tag_struct_definition muffin_marker_block;

	extern s_tag_struct_definition muffin_block;
	extern s_tag_reference_definition render_model_group_reference$4_tagref;

	extern s_tag_struct_definition leaf_type_block;

	extern s_tag_struct_definition leaf_system_struct_definition;
	extern s_string_list_definition leaf_flags$2;

	extern s_tag_struct_definition cloth_properties;
	extern s_string_list_definition cloth_integration_enum;

	extern s_tag_struct_definition cloth_vertices_block;

	extern s_tag_struct_definition cloth_indices_block;

	extern s_tag_struct_definition cloth_links_block;

	extern s_tag_struct_definition collision_sphere_block;

	extern s_tag_struct_definition cloth_struct_definition;
	extern s_string_list_definition cloth_flags;
	extern s_tag_reference_definition shader_group_reference_tagref;

	extern s_tag_struct_definition creature_scalar_timing_block;

	extern s_tag_struct_definition big_battle_creature_block_struct;
	extern s_tag_reference_definition imposter_model_group_reference_tagref;

	extern s_tag_struct_definition terminal_page_block_definition;

	extern s_tag_struct_definition steering_animation_struct;

	extern s_tag_struct_definition engine_function_struct;

	extern s_tag_struct_definition vehicle_steering_control_struct;

	extern s_tag_struct_definition vehicle_turning_control_struct;

	extern s_tag_struct_definition human_tank_struct;

	extern s_tag_struct_definition human_jeep_block;

	extern s_tag_struct_definition wolverine_block;

	extern s_tag_struct_definition human_plane_block;

	extern s_tag_struct_definition alien_scout_block;
	extern s_string_list_definition alien_scout_specific_type_enum;
	extern s_string_list_definition alien_scout_flags;

	extern s_tag_struct_definition flight_surface_struct;
	extern s_string_list_definition dimensions_enum;

	extern s_tag_struct_definition jackal_glider_drag_struct;

	extern s_tag_struct_definition jackal_glider_block;

	extern s_tag_struct_definition alien_fighter_block;

	extern s_tag_struct_definition turret_block;
	extern s_string_list_definition turret_flags;

	extern s_tag_struct_definition mantis_block;

	extern s_tag_struct_definition guardian_block;

	extern s_tag_struct_definition vtol_descent_function_struct;

	extern s_tag_struct_definition vtol_speed_interpolated_block;

	extern s_tag_struct_definition vtol_block;

	extern s_tag_struct_definition chopper_block;

	extern s_tag_struct_definition boat_block;
	extern s_string_list_definition boat_flags$2;

	extern s_tag_struct_definition space_fighter_block;
	extern s_string_list_definition space_fighter_turn_back_flags;

	extern s_tag_struct_definition revenant_block;

	extern s_tag_struct_definition vehicle_physics_types_struct;

	extern s_tag_struct_definition contact_point_block;

	extern s_tag_struct_definition biped_movement_gate_block;

	extern s_tag_struct_definition biped_leaping_data_struct;
	extern s_string_list_definition biped_leap_flags_definition;

	extern s_tag_struct_definition biped_camera_height_block;

	extern s_tag_struct_definition biped_wall_proximity_block;
	extern s_string_list_definition biped_wall_proximity_composition_mode;

	extern s_tag_struct_definition biped_ground_fitting_data_struct;
	extern s_string_list_definition biped_ground_fitting_flags_definition;

	extern s_tag_struct_definition object_function_interpolation_block;
	extern s_string_list_definition object_function_interpolation_mode_enum;

	extern s_tag_struct_definition object_runtime_interpolator_functions_block;

	extern s_tag_struct_definition object_function_block;
	extern s_string_list_definition object_function_flags;

	extern s_tag_struct_definition global_object_attachment_block;
	extern s_tag_reference_definition _reference$2_tagref;
	extern s_string_list_definition global_object_change_color_enum;
	extern s_string_list_definition object_attachment_flags;

	extern s_tag_struct_definition object_widget_block;
	extern s_tag_reference_definition _reference$3_tagref;

	extern s_tag_struct_definition object_change_color_initial_permutation;

	extern s_tag_struct_definition object_change_color_function;
	extern s_string_list_definition global_rgb_interpolation_flags;

	extern s_tag_struct_definition object_change_colors;

	extern s_tag_struct_definition multiplayer_object_block;
	extern s_string_list_definition global_game_engine_type_flags;
	extern s_string_list_definition multiplayer_object_type;
	extern s_string_list_definition teleporter_passability_flags;
	extern s_string_list_definition multiplayer_object_boundary_shape;
	extern s_string_list_definition multiplayer_object_spawn_timer_types;
	extern s_string_list_definition multiplayer_object_flags;
	extern s_tag_reference_definition object_group_reference_tagref;
	extern s_tag_reference_definition render_method_group_reference$3_tagref;

	extern s_tag_struct_definition object_ai_properties_block;
	extern s_string_list_definition ai_properties_flags;
	extern s_string_list_definition ai_size_enum;
	extern s_string_list_definition global_ai_jump_height_enum;

	extern s_tag_struct_definition object_spawn_effects_block;

	extern s_tag_struct_definition object_early_mover_obb_block;

	extern s_tag_struct_definition object_struct_definition;
	extern s_string_list_definition object_definition_flags;
	extern s_string_list_definition lightmap_shadow_mode_enum;
	extern s_string_list_definition sweetener_size_enum;
	extern s_string_list_definition water_density_type_enum;
	extern s_tag_reference_definition model_group_reference_tagref;
	extern s_tag_reference_definition crate_group_reference$2_tagref;
	extern s_tag_reference_definition collision_damage_group_reference_tagref;
	extern s_string_list_definition object_definition_secondary_flags;
	extern s_tag_reference_definition simulation_interpolation_group_reference_tagref;

	extern s_tag_struct_definition unit_trick_definition_block;
	extern s_string_list_definition unit_trick_activation_type_enum;
	extern s_string_list_definition unit_trick_velocity_preservation_mode_enum;
	extern s_string_list_definition unit_trick_flags;

	extern s_tag_struct_definition torque_curve_struct;

	extern s_tag_struct_definition gear_block;

	extern s_tag_struct_definition load_and_cruise_block;

	extern s_tag_struct_definition global_vehicle_engine_struct;

	extern s_tag_struct_definition death_program_velocity_gate_block;
	extern s_string_list_definition death_program_result_enum;

	extern s_tag_struct_definition death_program_damage_reporting_block;

	extern s_tag_struct_definition death_program_special_block;
	extern s_string_list_definition object_damage_aftermath_special_damage_type_enum;

	extern s_tag_struct_definition death_program_selector_struct_definition;

	extern s_tag_struct_definition scalar_function_named_struct;

	extern s_tag_struct_definition mapping_function;

	extern s_tag_struct_definition structure_lighting_generic_light_definition_block$2;
	extern s_string_list_definition structure_lighting_generic_light_type_enum;
	extern s_string_list_definition structure_lighting_generic_light_flags;
	extern s_string_list_definition structure_lighting_generic_light_shape_enum;

	extern s_tag_struct_definition structure_lighting_generic_light_instance_block;
	extern s_string_list_definition structure_lighting_bungie_light_type_enum;
	extern s_string_list_definition light_instance_flags;
	extern s_tag_reference_definition light_group_reference$4_tagref;
	extern s_tag_reference_definition render_method_definition_group_reference$2_tagref;
	extern s_tag_reference_definition bitmap_group_reference$12_tagref;
	extern s_tag_reference_definition lens_flare_group_reference$2_tagref;

	extern s_tag_struct_definition screen_space_light_shader_override_block;

	extern s_tag_struct_definition structure_lighting_region_triangle_block;

	extern s_tag_struct_definition structure_lighting_region_block;

	extern s_tag_struct_definition structure_material_lighting_info_block;
	extern s_string_list_definition structure_material_lighting_info_flags;

	extern s_tag_struct_definition structure_instance_imposter_info_block;

	extern s_tag_struct_definition scenario_structure_lighting_info_struct_definition;

	extern s_tag_struct_definition effect_component_holdback_block;
	extern s_string_list_definition global_effect_priority_enum;

	extern s_tag_struct_definition effect_component_holdbacks_block;
	extern s_string_list_definition effect_holdback_type_enum;

	extern s_tag_struct_definition effect_global_spawn_effects_block;

	extern s_tag_struct_definition effect_globals_struct_definition;

	extern s_tag_struct_definition light_volume_property_real;
	extern s_string_list_definition light_volume_state_input_enum;
	extern s_string_list_definition output_mod_enum$6;

	extern s_tag_struct_definition light_volume_property_real_rgb_color;

	extern s_tag_struct_definition light_volume_precompiled_vert_block;

	extern s_tag_struct_definition light_volume_definition_block;
	extern s_string_list_definition light_volume_appearance_flags;
	extern s_string_list_definition light_volume_flags;

	extern s_tag_struct_definition light_volume_system_struct_definition;

	extern s_tag_struct_definition attachment_block;
	extern s_tag_reference_definition _reference$18_tagref;
	extern s_string_list_definition attachment_type_enum;
	extern s_string_list_definition game_state_type_enum;

	extern s_tag_struct_definition gpu_single_constant_register_array_struct_definition;

	extern s_tag_struct_definition gpu_sprite_block;

	extern s_tag_struct_definition gpu_variants_block;

	extern s_tag_struct_definition gpu_data_struct$2;

	extern s_tag_struct_definition particle_struct_definition;
	extern s_string_list_definition particle_main_flags;
	extern s_string_list_definition particle_appearance_flags;
	extern s_string_list_definition particle_billboard_type_enum;
	extern s_string_list_definition particle_animation_flags;
	extern s_tag_reference_definition particle_model_group_reference$2_tagref;

	extern s_tag_struct_definition particle_controller_parameters;

	extern s_tag_struct_definition particle_controller;
	extern s_string_list_definition particle_movement_type;
	extern s_string_list_definition particle_controller_flags;

	extern s_tag_struct_definition particle_physics_struct;
	extern s_tag_reference_definition particle_physics_group_reference_tagref;
	extern s_string_list_definition particle_movement_flags;

	extern s_tag_struct_definition particle_physics_struct_definition;

	extern s_tag_struct_definition gpu_function_sub_array_struct_definition;

	extern s_tag_struct_definition gpu_function_block;

	extern s_tag_struct_definition gpu_color_sub_array_struct_definition;

	extern s_tag_struct_definition gpu_color_block;

	extern s_tag_struct_definition gpu_property_sub_array_struct_definition;

	extern s_tag_struct_definition gpu_property_block;

	extern s_tag_struct_definition gpu_property_function_color_struct;

	extern s_tag_struct_definition particle_system_emitter_definition_block;
	extern s_string_list_definition emission_shape_enum;
	extern s_string_list_definition emitter_flags;
	extern s_string_list_definition visible_emitter_flags;
	extern s_string_list_definition emission_axis_enum;
	extern s_string_list_definition emission_reference_axis_enum;
	extern s_tag_reference_definition particle_emitter_custom_points_group_reference_tagref;
	extern s_tag_reference_definition particle_emitter_boat_hull_shape_group_reference_tagref;

	extern s_tag_struct_definition particle_system_definition_block_new;
	extern s_tag_reference_definition particle_group_reference_tagref;
	extern s_string_list_definition coordinate_system_enum;
	extern s_string_list_definition effect_environments;
	extern s_string_list_definition effect_dispositions;
	extern s_string_list_definition effect_camera_modes;
	extern s_string_list_definition particle_system_flags;

	extern s_tag_struct_definition gpu_data_struct;

	extern s_tag_struct_definition particle_model_struct_definition;

	extern s_tag_struct_definition node_indices_array_struct_definition;

	extern s_tag_struct_definition node_weights_implicit_array_struct_definition;

	extern s_tag_struct_definition sorting_position_block;

	extern s_tag_struct_definition part_block;
	extern s_string_list_definition specialized_render_definition;
	extern s_string_list_definition part_flags;
	extern s_string_list_definition tessellation_mode_definition;

	extern s_tag_struct_definition subpart_block;

	extern s_tag_struct_definition indices_word_block;

	extern s_tag_struct_definition indices_dword_block;

	extern s_tag_struct_definition node_weights_complete_array_struct_definition;

	extern s_tag_struct_definition raw_vertex_block;

	extern s_tag_struct_definition raw_water_append_block;

	extern s_tag_struct_definition raw_water_block;

	extern s_tag_struct_definition raw_imposter_brdf_block;

	extern s_tag_struct_definition raw_instance_imposter_block;

	extern s_tag_struct_definition compression_info_block;
	extern s_string_list_definition compression_flags;

	extern s_tag_struct_definition node_map_byte_block;

	extern s_tag_struct_definition instance_index_word_block;

	extern s_tag_struct_definition global_instance_bucket_block;

	extern s_tag_struct_definition vertex_buffer_indices_word_array_struct_definition;

	extern s_tag_struct_definition global_mesh_block;
	extern s_string_list_definition mesh_flags;
	extern s_string_list_definition mesh_vertex_type_definition;
	extern s_string_list_definition mesh_transfer_vertex_type_definition;
	extern s_string_list_definition mesh_lighting_policy_type_definition;
	extern s_string_list_definition mesh_index_buffer_type_definition;

	extern s_tag_struct_definition per_mesh_raw_data_block;
	extern s_string_list_definition per_mesh_raw_data_flags;

	extern s_tag_struct_definition per_mesh_node_map_block;

	extern s_tag_struct_definition per_mesh_subpart_visibility_block;

	extern s_tag_struct_definition per_instance_prt_data_block;

	extern s_tag_struct_definition per_mesh_prt_data_block;

	extern s_tag_struct_definition per_instance_lightmap_texcoords_block;

	extern s_tag_struct_definition per_instance_lightmap_texcoords_vertex_buffer_block;

	extern s_tag_struct_definition water_bounding_box_block;

	extern s_tag_struct_definition global_render_geometry_user_data_header_struct;
	extern s_string_list_definition render_geometry_user_data_type_definition;

	extern s_tag_struct_definition user_data_block;

	extern s_tag_struct_definition vertex_buffers_block;

	extern s_tag_struct_definition index_buffers_block;

	extern s_tag_struct_definition render_vertex_buffer_block;

	extern s_tag_struct_definition render_index_buffer_block;

	extern s_tag_struct_definition render_geometry_api_resource_definition_struct;

	extern s_tag_struct_definition global_render_geometry_struct;
	extern s_string_list_definition render_geometry_flags;

	extern s_tag_struct_definition player_training_entry_data_block;
	extern s_string_list_definition player_training_flags;

	extern s_tag_struct_definition vision_mode_color_function_struct;

	extern s_tag_struct_definition vision_mode_struct_definition;
	extern s_string_list_definition vision_mode_global_flags_definition;

	extern s_tag_struct_definition screen_effect_scalar_function_struct;

	extern s_tag_struct_definition screen_effect_scalar_object_function_struct;

	extern s_tag_struct_definition single_screen_effect;
	extern s_string_list_definition area_screen_effect_flags_definition;
	extern s_string_list_definition area_screen_effect_hidden_flags_definition;
	extern s_tag_reference_definition shader_screen_group_reference_tagref;

	extern s_tag_struct_definition area_screen_effect_struct_definition;
	extern s_string_list_definition area_screen_effect_global_flags_definition;
	extern s_string_list_definition area_screen_effect_global_hidden_flags_definition;

	extern s_tag_struct_definition g_null_block;

	extern s_tag_struct_definition scenario_interpolator_data_block;
	extern s_string_list_definition scenario_interpolator_flags;
	extern s_string_list_definition scenario_interpolator_reset_value_enum;
	extern s_string_list_definition scenario_interpolator_start_value_enum;
	extern s_string_list_definition scenario_interpolator_stop_value_enum;

	extern s_tag_struct_definition scenario_interpolator_struct_definition;

	extern s_tag_struct_definition lightprobe_terms_struct_definition;

	extern s_tag_struct_definition single_vmf_terms_struct_definition;

	extern s_tag_struct_definition dual_vmf_terms_struct_definition;

	extern s_tag_struct_definition full_lightprobe;

	extern s_tag_struct_definition converted_lightprobe;

	extern s_tag_struct_definition scenario_lightmap_lightprobe_value;

	extern s_tag_struct_definition scenario_lightmap_airprobe_value;

	extern s_tag_struct_definition scenario_lightmap_scenery_probe_value;

	extern s_tag_struct_definition scenario_lightmap_device_machine_probe_value;

	extern s_tag_struct_definition scenario_lightmap_device_machine_probe_data_value;

	extern s_tag_struct_definition scenario_lightmap_pervertex_data;

	extern s_tag_struct_definition scenario_lightmap_pervertex_data_run_time;

	extern s_tag_struct_definition scenario_lightmap_cluster_data;

	extern s_tag_struct_definition scenario_lightmap_instance_data;

	extern s_tag_struct_definition wentness_bit_vector;

	extern s_tag_struct_definition wentness_byte_vector;

	extern s_tag_struct_definition cluster_wetness_offset_block;

	extern s_tag_struct_definition instance_wetness_instance_block;

	extern s_tag_struct_definition triangle_mapping_block;

	extern s_tag_struct_definition triangle_mapping_per_mesh_block;

	extern s_tag_struct_definition scenario_lightmap_bsp_data_block_struct;
	extern s_string_list_definition scenario_lightmap_bsp_flags;
	extern s_tag_reference_definition bitmap_group_reference$4_tagref;

	extern s_tag_struct_definition scenario_wetness_bsp_data_struct_definition;

	extern s_tag_struct_definition obsolete_scenario_lightmap_bsp_data;

	extern s_tag_struct_definition uber_light_index_mapping_per_bsp_data_struct_definition;

	extern s_tag_struct_definition uber_light_index_mapping_data;

	extern s_tag_struct_definition scenario_lightmap_bsp_data_reference_block;
	extern s_tag_reference_definition scenario_lightmap_bsp_data_group_reference_tagref;
	extern s_tag_reference_definition scenario_wetness_bsp_data_group_reference_tagref;

	extern s_tag_struct_definition scenario_lightmap_block_struct;

	extern s_tag_struct_definition polyhedron_with_material_block;

	extern s_tag_struct_definition structure_bsp_instanced_geometry_definition_block;
	extern s_string_list_definition instanced_geometry_definition_flags;

	extern s_tag_struct_definition decomposed_poop_physics_block;

	extern s_tag_struct_definition instanced_geometry_physics_block;

	extern s_tag_struct_definition cubemap_sample_struct;

	extern s_tag_struct_definition structure_bsp_instanced_geometry_instances_without_names_block;
	extern s_string_list_definition instanced_geometry_flags;
	extern s_string_list_definition instanced_geometry_pathfinding_policy_enum;
	extern s_string_list_definition instanced_geometry_lightmapping_policy_enum;
	extern s_string_list_definition instanced_geometry_imposter_policy_enum;

	extern s_tag_struct_definition structure_bsp_instanced_geometry_instances_names_block;

	extern s_tag_struct_definition global_render_model_instance_placement_block;

	extern s_tag_struct_definition structure_bsp_instanced_geometry_instances_block;

	extern s_tag_struct_definition breakable_surface_struct_definition;

	extern s_tag_struct_definition dumpling_point_block;

	extern s_tag_struct_definition scenario_dumpling_struct;

	extern s_tag_struct_definition scenario_atmosphere_dumpling_block;

	extern s_tag_struct_definition scenario_weather_dumpling_block;

	extern s_tag_struct_definition scenario_function_block;
	extern s_string_list_definition scenario_function_flags;
	extern s_string_list_definition global_periodic_functions_enum;
	extern s_string_list_definition global_transition_functions_enum;
	extern s_string_list_definition function_bounds_mode_enum;

	extern s_tag_struct_definition scenario_object_names_block;

	extern s_tag_struct_definition scenario_soft_ceilings_block;
	extern s_string_list_definition scenario_soft_ceiling_flags_definition;
	extern s_string_list_definition soft_ceiling_type_enum;

	extern s_tag_struct_definition scenario_profiles_block;
	extern s_tag_reference_definition weapon_group_reference$8_tagref;
	extern s_tag_reference_definition equipment_group_reference$5_tagref;

	extern s_tag_struct_definition scenario_players_block;
	extern s_string_list_definition scenario_player_flags;

	extern s_tag_struct_definition scenario_kill_trigger_volumes_block;
	extern s_string_list_definition kill_volume_flags;

	extern s_tag_struct_definition scenario_safe_zone_trigger_volumes_block;

	extern s_tag_struct_definition scenario_requisition_trigger_volumes_block;
	extern s_string_list_definition scenario_requisition_trigger_volume_flags_definition;

	extern s_tag_struct_definition scenario_location_name_trigger_volumes_block;

	extern s_tag_struct_definition trigger_volume_point_block;

	extern s_tag_struct_definition trigger_volume_runtime_triangles_block;

	extern s_tag_struct_definition scenario_zone_set_bsp_checksum_block;

	extern s_tag_struct_definition scenario_zone_set_cluster_pvs_bit_vector_block;

	extern s_tag_struct_definition scenario_zone_set_bsp_bits_block;

	extern s_tag_struct_definition scenario_zone_set_cluster_pvs_block;

	extern s_tag_struct_definition scenario_lightmap_setting_struct;
	extern s_string_list_definition scenario_lightmap_per_bsp_flags;

	extern s_tag_struct_definition scenario_structure_bsp_reference_block;
	extern s_tag_reference_definition scenario_structure_bsp_group_reference_tagref;
	extern s_tag_reference_definition scenario_structure_lighting_info_group_reference_tagref;
	extern s_string_list_definition scenario_structure_size_enum;
	extern s_string_list_definition scenario_structure_bsp_reference_flags_definition;
	extern s_tag_reference_definition bitmap_group_reference$3_tagref;
	extern s_tag_reference_definition wind_group_reference_tagref;

	extern s_tag_struct_definition scenario_sky_reference_block;
	extern s_tag_reference_definition scenery_group_reference_tagref;

	extern s_tag_struct_definition scenario_zone_set_cluster_sky_indices_block;

	extern s_tag_struct_definition scenario_zone_set_multiple_skies_visible_bit_vector_block;

	extern s_tag_struct_definition scenario_zone_set_cluster_reference_block;

	extern s_tag_struct_definition scenario_zone_set_bsp_seam_cluster_mappings_block;

	extern s_tag_struct_definition scenario_zone_set_bsp_pvs_block;

	extern s_tag_struct_definition scenario_zone_set_pvs_block;
	extern s_string_list_definition scenario_zone_set_pvs_flags;

	extern s_tag_struct_definition scenario_design_reference_block;
	extern s_tag_reference_definition structure_design_group_reference_tagref;

	extern s_tag_struct_definition scenario_zone_set_block;
	extern s_string_list_definition scenario_zone_set_flags_definition;

	extern s_tag_struct_definition scenario_zone_set_switch_trigger_volume_block;
	extern s_string_list_definition scenario_zone_set_switch_trigger_volume_flags_definition;

	extern s_tag_struct_definition player_spawn_influencer_block;

	extern s_tag_struct_definition scenario_performance_actor_block_struct;
	extern s_string_list_definition scenario_performance_actor_flags_definition;

	extern s_tag_struct_definition scenario_performance_line_animation_block_struct;
	extern s_string_list_definition scenario_performance_line_animation_flags_definition;

	extern s_tag_struct_definition scenario_performance_line_sync_action_actor_block;

	extern s_tag_struct_definition scenario_performance_line_sync_action_block_struct;
	extern s_string_list_definition scenario_performance_line_sync_action_flag_type_definition;

	extern s_tag_struct_definition scenario_performance_line_scenery_sync_action_block_struct;
	extern s_string_list_definition scenario_performance_line_scenery_sync_action_flag_type_definition;

	extern s_tag_struct_definition scenario_performance_line_dialog_block_struct;

	extern s_tag_struct_definition scenario_performance_line_sound_block_struct;

	extern s_tag_struct_definition scenario_performance_line_script_fragment_block;
	extern s_string_list_definition scenario_performance_fragment_placement_definition;
	extern s_string_list_definition scenario_performance_fragment_type_definition;

	extern s_tag_struct_definition scenario_performance_line_point_interaction_block_struct;
	extern s_string_list_definition scenario_performance_line_point_interaction_type_definition;

	extern s_tag_struct_definition scenario_performance_line_block_struct;
	extern s_string_list_definition scenario_performance_line_flags;
	extern s_string_list_definition scenario_performance_line_progress_definition;

	extern s_tag_struct_definition scenario_performance_task_block_struct;

	extern s_tag_struct_definition scenario_performances_block_struct;
	extern s_string_list_definition performance_flags;

	extern s_tag_struct_definition performance_template_point_block_struct;

	extern s_tag_struct_definition performance_template_actor_block_struct;
	extern s_tag_reference_definition character_group_reference$5_tagref;
	extern s_tag_reference_definition vehicle_group_reference$3_tagref;
	extern s_tag_reference_definition weapon_group_reference$7_tagref;

	extern s_tag_struct_definition performance_template_block_struct;

	extern s_tag_struct_definition scenario_decal_palette_block;
	extern s_tag_reference_definition decal_system_group_reference_tagref;

	extern s_tag_struct_definition scenario_decals_block;

	extern s_tag_struct_definition scenario_detail_object_collection_palette_block;
	extern s_tag_reference_definition detail_object_collection_group_reference_tagref;

	extern s_tag_struct_definition scenario_cheap_particle_system_palette_block;
	extern s_tag_reference_definition cheap_particle_emitter_group_reference_tagref;

	extern s_tag_struct_definition scenario_cheap_particle_systems_block;

	extern s_tag_struct_definition scenario_cutscene_flag_block;

	extern s_tag_struct_definition scenario_cutscene_camera_point_block;
	extern s_string_list_definition scenario_cutscene_camera_flags;
	extern s_string_list_definition scenario_cutscene_camera_types;

	extern s_tag_struct_definition editor_comment_block;
	extern s_string_list_definition editor_comment_type_enum_definition;

	extern s_tag_struct_definition dont_use_me_scenario_environment_object_block;

	extern s_tag_struct_definition scenario_cluster_acoustics_block_struct;

	extern s_tag_struct_definition scenario_atmosphere_palette_block;
	extern s_tag_reference_definition atmosphere_fog_group_reference_tagref;

	extern s_tag_struct_definition scenario_cluster_atmosphere_properties_block;

	extern s_tag_struct_definition scenario_weather_palette_block;

	extern s_tag_struct_definition scenario_cluster_weather_properties_block;

	extern s_tag_struct_definition scenario_camera_fx_palette_block;
	extern s_string_list_definition camera_fx_palette_flags;

	extern s_tag_struct_definition scenario_cluster_camera_fx_properties_block;

	extern s_tag_struct_definition scenario_cluster_points_block;

	extern s_tag_struct_definition scenario_cluster_data_block;

	extern s_tag_struct_definition scenario_spawn_data_block;

	extern s_tag_struct_definition object_salt_storage_array_struct_definition;

	extern s_tag_struct_definition scenario_lighting_zone_set_block;

	extern s_tag_struct_definition scenario_cinematic_lighting_palette_block;
	extern s_tag_reference_definition new_cinematic_lighting_group_reference_tagref;

	extern s_tag_struct_definition model_references_block;
	extern s_tag_reference_definition model_group_reference$2_tagref;

	extern s_tag_struct_definition trigger_volume_mopp_code_block;

	extern s_tag_struct_definition scenario_airprobes_block;

	extern s_tag_struct_definition scenario_budget_references_block;
	extern s_tag_reference_definition _reference$20_tagref;

	extern s_tag_struct_definition scenario_required_resource_struct_definition;

	extern s_tag_struct_definition scenario_struct_definition;
	extern s_string_list_definition scenario_type_enum;
	extern s_string_list_definition scenario_flags;
	extern s_string_list_definition scenario_runtime_trigger_volume_flags;
	extern s_tag_reference_definition game_performance_throttle_group_reference$2_tagref;
	extern s_tag_reference_definition structure_seams_group_reference_tagref;
	extern s_tag_reference_definition multiplayer_object_type_list_group_reference_tagref;
	extern s_tag_reference_definition airstrike_group_reference_tagref;
	extern s_tag_reference_definition sound_effect_collection_group_reference_tagref;
	extern s_tag_reference_definition scenario_interpolator_group_reference_tagref;
	extern s_tag_reference_definition ssao_definition_group_reference_tagref;
	extern s_tag_reference_definition sky_atm_parameters_group_reference_tagref;
	extern s_tag_reference_definition atmosphere_globals_group_reference_tagref;
	extern s_tag_reference_definition chocolate_mountain_new_group_reference_tagref;
	extern s_tag_reference_definition scenario_lightmap_group_reference_tagref;
	extern s_tag_reference_definition location_name_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition scenario_required_resource_group_reference_tagref;
	extern s_tag_reference_definition variant_globals_group_reference_tagref;

	extern s_tag_struct_definition scenario_trigger_volume_struct;
	extern s_string_list_definition trigger_volume_type_enum;

	extern s_tag_struct_definition map_leaf_face_vertex_block;

	extern s_tag_struct_definition map_leaf_face_block;

	extern s_tag_struct_definition map_leaf_connection_index_block;

	extern s_tag_struct_definition global_map_leaf_block;

	extern s_tag_struct_definition leaf_connection_vertex_block;

	extern s_tag_struct_definition global_leaf_connection_block;

	extern s_tag_struct_definition mopp_code_data_definition_block;

	extern s_tag_struct_definition mopp_code_definition_block;

	extern s_tag_struct_definition transparent_planes_block;

	extern s_tag_struct_definition structure_bsp_cluster_portal_vertex_block;

	extern s_tag_struct_definition structure_bsp_cluster_portal_oriented_bounds_block;

	extern s_tag_struct_definition structure_bsp_cluster_portal_index_block;

	extern s_tag_struct_definition seam_indices_block_definition;

	extern s_tag_struct_definition cheap_light_reference_block;
	extern s_tag_reference_definition cheap_light_group_reference_tagref;

	extern s_tag_struct_definition cheap_light_marker_ref_block;

	extern s_tag_struct_definition pvs_bound_object_identifiers_block;

	extern s_tag_struct_definition pvs_bound_object_references_block;

	extern s_tag_struct_definition structure_bsp_cluster_block_struct;
	extern s_string_list_definition structure_cluster_flags;

	extern s_tag_struct_definition structure_bsp_cluster_portal_block;
	extern s_string_list_definition structure_bsp_cluster_portal_flags_definition;

	extern s_tag_struct_definition structure_bsp_pathfinding_edges_block;

	extern s_tag_struct_definition structure_bsp_conveyor_surface_block;

	extern s_tag_struct_definition structure_collision_materials_block;
	extern s_tag_reference_definition render_method_group_reference$6_tagref;
	extern s_string_list_definition structure_collision_materialg_flags;

	extern s_tag_struct_definition structure_bsp_marker_block;
	extern s_string_list_definition structure_marker_type_enum;

	extern s_tag_struct_definition structure_bsp_marker_light_palette;
	extern s_tag_reference_definition light_group_reference$3_tagref;

	extern s_tag_struct_definition structure_bsp_marker_light_index;

	extern s_tag_struct_definition structure_bsp_environment_object_palette_block;
	extern s_tag_reference_definition object_group_reference$6_tagref;
	extern s_tag_reference_definition render_model_group_reference$6_tagref;

	extern s_tag_struct_definition structure_bsp_environment_object_block;

	extern s_tag_struct_definition structure_bsp_detail_object_data_block;

	extern s_tag_struct_definition structure_bsp_runtime_decal_block;

	extern s_tag_struct_definition bsp_preplaced_decal_set_reference_block;

	extern s_tag_struct_definition bsp_preplaced_decal_reference_block;

	extern s_tag_struct_definition super_node_recursable_masks_block;

	extern s_tag_struct_definition structure_super_node_traversal_geometry_indices_block;

	extern s_tag_struct_definition structure_super_node_aabbs_block;

	extern s_tag_struct_definition super_node_mappings_block;
	extern s_string_list_definition structure_super_node_mapping_flags;

	extern s_tag_struct_definition structure_super_node_traversal_geometry_block;

	extern s_tag_struct_definition structure_surface_to_triangle_mapping_block_struct;

	extern s_tag_struct_definition structure_bsp_debug_info_render_line_block;
	extern s_string_list_definition structure_bsp_debug_info_render_line_type_enum;

	extern s_tag_struct_definition structure_bsp_debug_info_indices_block;

	extern s_tag_struct_definition structure_bsp_cluster_debug_info_block;
	extern s_string_list_definition structure_bsp_debug_info_cluster_error_flags;
	extern s_string_list_definition structure_bsp_debug_info_cluster_warning_flags;

	extern s_tag_struct_definition structure_bsp_fog_plane_debug_info_block;

	extern s_tag_struct_definition structure_bsp_fog_zone_debug_info_block;

	extern s_tag_struct_definition structure_bsp_debug_info_block;

	extern s_tag_struct_definition structure_bsp_sky_owner_cluster_block;

	extern s_tag_struct_definition structure_bsp_fake_lightprobes_block;

	extern s_tag_struct_definition structure_edge_to_seam_edge_mapping_block;

	extern s_tag_struct_definition widget_reference_block;
	extern s_tag_reference_definition _reference$19_tagref;

	extern s_tag_struct_definition runtime_decorator_set_block;
	extern s_tag_reference_definition decorator_set_group_reference_tagref;

	extern s_tag_struct_definition structure_bsp_resource_struct;

	extern s_tag_struct_definition structure_bsp_tag_resources_struct;

	extern s_tag_struct_definition structure_bsp_raw_resources;

	extern s_tag_struct_definition structure_bsp_cache_file_tag_resources_struct;

	extern s_tag_struct_definition structure_bsp_resource_interface;

	extern s_tag_struct_definition index_list_block;

	extern s_tag_struct_definition structure_instance_cluster_definition;
	extern s_string_list_definition structure_instance_cluster_flags;

	extern s_tag_struct_definition structure_instance_group_definition;
	extern s_string_list_definition structure_instance_group_flags;

	extern s_tag_struct_definition structure_cookie_cutter_definition;

	extern s_tag_struct_definition scenario_structure_bsp_block_struct;
	extern s_string_list_definition structure_bsp_flags_definition;
	extern s_string_list_definition structure_bsp_content_policy_flag;
	extern s_tag_reference_definition instance_imposter_definition_group_reference_tagref;

	extern s_tag_struct_definition structure_bsp_leaf_block;

	extern s_tag_struct_definition structure_surface_block;

	extern s_tag_struct_definition structure_seam_identifier_struct;

	extern s_tag_struct_definition structure_seam_cluster_mapping_block;

	extern s_tag_struct_definition structure_seam_edge_mapping_block;

	extern s_tag_struct_definition structure_seam_mapping_block;

	extern s_tag_struct_definition structure_seam_original_vertex_plane_normals_block;

	extern s_tag_struct_definition structure_seam_original_vertex_block;

	extern s_tag_struct_definition structure_seam_original_geometry_struct;

	extern s_tag_struct_definition structure_seam_final_points_block;

	extern s_tag_struct_definition structure_seam_final_planes_block;

	extern s_tag_struct_definition structure_seam_final_triangles_block;

	extern s_tag_struct_definition structure_seam_final_edges_block;

	extern s_tag_struct_definition structure_seam_final_geometry_struct;

	extern s_tag_struct_definition structure_seam_block;

	extern s_tag_struct_definition structure_seams_struct_definition;

	extern s_tag_struct_definition physics_force_function_struct;

	extern s_tag_struct_definition water_physics_drag_properties_struct;

	extern s_tag_struct_definition water_physics_material_override;

	extern s_tag_struct_definition water_physics_hull_surface_definition_block;
	extern s_string_list_definition water_physics_hull_surface_definition_flags;

	extern s_tag_struct_definition water_physics_drag_properties_struct_definition;

	extern s_tag_struct_definition scenario_acoustics_environment_definition;
	extern s_tag_reference_definition sound_environment_group_reference_tagref;
	extern s_string_list_definition sound_class_acoustics_string_definition;

	extern s_tag_struct_definition scenario_acoustics_ambience_definition;
	extern s_tag_reference_definition sound_looping_group_reference_tagref;
	extern s_string_list_definition background_sound_scale_flags_definition;

	extern s_tag_struct_definition scenario_acoustics_palette_block_definition_struct;

	extern s_tag_struct_definition acoustic_sector_point_block;

	extern s_tag_struct_definition scenario_acoustic_sector_block_struct;

	extern s_tag_struct_definition scenario_acoustic_cluster_reference_definition;

	extern s_tag_struct_definition scenario_acoustic_location_definition;

	extern s_tag_struct_definition scenario_acoustic_transition_block_struct;

	extern s_tag_struct_definition render_vertex_buffer_descriptor_struct;

	extern s_tag_struct_definition render_index_buffer_descriptor_struct;

	extern s_tag_struct_definition wind_scalar_function_struct;

	extern s_tag_struct_definition wind_block;

	extern s_tag_struct_definition cubemap_reference_points_block;

	extern s_tag_struct_definition scenario_cubemap_block;
	extern s_string_list_definition cubemap_resolution_enum;

	extern s_tag_struct_definition structure_cluster_cubemap;

	extern s_tag_struct_definition effect_locations_block;
	extern s_string_list_definition effect_location_flags;

	extern s_tag_struct_definition effect_accelerations_block;

	extern s_tag_struct_definition effect_part_block;
	extern s_string_list_definition effect_part_flags;
	extern s_tag_reference_definition _reference$9_tagref;
	extern s_string_list_definition effect_part_scaleable_values;

	extern s_tag_struct_definition effect_event_block;
	extern s_string_list_definition event_flags;

	extern s_tag_struct_definition effect_conical_distribution_block;

	extern s_tag_struct_definition effect_looping_sound_block_struct;

	extern s_tag_struct_definition effect_block_struct;
	extern s_string_list_definition effect_flags;

	extern s_tag_struct_definition data_hash_definition_struct_definition;

	extern s_tag_struct_definition language_pack_definition;

	extern s_tag_struct_definition multilingual_unicode_string_reference_block;

	extern s_tag_struct_definition string_substitution_pair_block;

	extern s_tag_struct_definition multilingual_unicode_string_list_language_pack_offsets_struct_definition;

	extern s_tag_struct_definition multilingual_unicode_string_list_struct_definition;

	extern s_tag_struct_definition havok_cleanup_resources_block;

	extern s_tag_struct_definition cheat_weapons_block;
	extern s_tag_reference_definition item_group_reference_tagref;

	extern s_tag_struct_definition cheat_powerups_block;

	extern s_tag_struct_definition grenades_block;

	extern s_tag_struct_definition soft_ceiling_globals_block;

	extern s_tag_struct_definition sound_block;
	extern s_tag_reference_definition _reference$14_tagref;

	extern s_tag_struct_definition multiplayer_color_block;

	extern s_tag_struct_definition visor_color_block;

	extern s_tag_struct_definition named_rgb_color_block;

	extern s_tag_struct_definition elite_specular_color_struct;

	extern s_tag_struct_definition globals_struct_definition;
	extern s_string_list_definition language_enum;
	extern s_tag_reference_definition ai_globals_group_reference_tagref;
	extern s_tag_reference_definition load_screen_globals_group_reference_tagref;
	extern s_tag_reference_definition game_engine_globals_group_reference_tagref;
	extern s_tag_reference_definition multiplayer_globals_group_reference_tagref;
	extern s_tag_reference_definition survival_mode_globals_group_reference_tagref;
	extern s_tag_reference_definition game_medal_globals_group_reference_tagref;
	extern s_tag_reference_definition rasterizer_globals_group_reference_tagref;
	extern s_tag_reference_definition weather_globals_group_reference_tagref;
	extern s_tag_reference_definition collision_damage_group_reference$4_tagref;
	extern s_tag_reference_definition effect_globals_group_reference_tagref;
	extern s_tag_reference_definition havok_collision_filter_group_reference_tagref;
	extern s_tag_reference_definition incident_global_properties_definition_group_reference_tagref;
	extern s_tag_reference_definition player_grade_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition player_model_customization_globals_group_reference_tagref;
	extern s_tag_reference_definition loadout_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition challenge_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition game_completion_rewards_globals_group_reference_tagref;
	extern s_tag_reference_definition achievements_group_reference_tagref;
	extern s_tag_reference_definition avatar_awards_group_reference_tagref;
	extern s_tag_reference_definition game_performance_throttle_group_reference_tagref;

	extern s_tag_struct_definition customized_model_player_bits_block;
	extern s_string_list_definition model_customization_player_permutation_flags;

	extern s_tag_struct_definition customized_model_selection_block;

	extern s_tag_struct_definition player_model_customization_globals_struct_definition;
	extern s_tag_reference_definition render_model_group_reference$5_tagref;

	extern s_tag_struct_definition spawn_influence_weight_falloff_function_block;

	extern s_tag_struct_definition multiplayer_color_block$2;

	extern s_tag_struct_definition multiplayer_universal_block;
	extern s_tag_reference_definition sandbox_text_value_pair_definition_group_reference_tagref;

	extern s_tag_struct_definition weapon_spawn_influence_block;
	extern s_tag_reference_definition weapon_group_reference$6_tagref;

	extern s_tag_struct_definition vehicle_spawn_influence_block;
	extern s_tag_reference_definition vehicle_group_reference$2_tagref;

	extern s_tag_struct_definition projectile_spawn_influence_block;
	extern s_tag_reference_definition projectile_group_reference$3_tagref;

	extern s_tag_struct_definition equipment_spawn_influence_block;
	extern s_tag_reference_definition equipment_group_reference$4_tagref;

	extern s_tag_struct_definition requisition_constants_block;

	extern s_tag_struct_definition multiplayer_constants_block;

	extern s_tag_struct_definition game_engine_status_response_block;
	extern s_string_list_definition game_engine_status_flags_definition;
	extern s_string_list_definition game_engine_status_enum_definition;
	extern s_tag_reference_definition _reference$15_tagref;

	extern s_tag_struct_definition sounds_block;

	extern s_tag_struct_definition looping_sounds_block;

	extern s_tag_struct_definition multiplayer_globals_struct_definition;

	extern s_tag_struct_definition multiplayer_runtime_block;
	extern s_tag_reference_definition unit_group_reference$4_tagref;
	extern s_tag_reference_definition object_group_reference$5_tagref;
	extern s_tag_reference_definition megalogamengine_sounds_group_reference_tagref;
	extern s_tag_reference_definition communication_sounds_group_reference_tagref;
	extern s_tag_reference_definition render_method_group_reference$4_tagref;
	extern s_tag_reference_definition coop_spawning_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition megalo_string_id_table_group_reference_tagref;

	extern s_tag_struct_definition single_achievement_restricted_level_block;

	extern s_tag_struct_definition single_achievement_definition_block;
	extern s_string_list_definition global_achievement_enum;
	extern s_string_list_definition global_campaign_difficulty_flags;

	extern s_tag_struct_definition achievements_struct_definition;

	extern s_tag_struct_definition lens_flare_reflection_block;
	extern s_string_list_definition lens_flare_reflection_flags_definition;

	extern s_tag_struct_definition lens_flare_scalar_animation_block;

	extern s_tag_struct_definition lens_flare_color_function_struct;
	extern s_string_list_definition output_mod_enum$5;

	extern s_tag_struct_definition lens_flare_color_animation_block;

	extern s_tag_struct_definition lens_flare_struct_definition;
	extern s_string_list_definition lens_flare_occlusion_offset_enum_definition;
	extern s_string_list_definition lens_flare_flags_definition;
	extern s_string_list_definition lens_flare_corona_rotation_function_enum_definition;
	extern s_string_list_definition lens_flare_animation_flags_definition;

	extern s_tag_struct_definition region_name_block;

	extern s_tag_struct_definition runtime_region_index_array_struct_definition;

	extern s_tag_struct_definition model_variant_state_block;
	extern s_string_list_definition model_state_property_flags_definition;
	extern s_string_list_definition model_state_enum_definition;

	extern s_tag_struct_definition model_state_permutation_index_array_struct_definition;

	extern s_tag_struct_definition model_variant_permutation_block;
	extern s_string_list_definition model_variant_permutation_flags_definition;

	extern s_tag_struct_definition model_variant_region_block;
	extern s_string_list_definition region_sort_enum;

	extern s_tag_struct_definition model_variant_object_block;
	extern s_tag_reference_definition object_group_reference$3_tagref;

	extern s_tag_struct_definition model_instance_group_member_block;

	extern s_tag_struct_definition global_model_instance_group_block;
	extern s_string_list_definition model_instance_group_choice_enum;

	extern s_tag_struct_definition model_variant_block;

	extern s_tag_struct_definition model_material_block_old;

	extern s_tag_struct_definition model_material_block_new;

	extern s_tag_struct_definition model_target_lock_on_data_struct;
	extern s_string_list_definition model_target_lock_on_flags_definition;

	extern s_tag_struct_definition model_target_block_old;

	extern s_tag_struct_definition model_target_block_new;
	extern s_string_list_definition model_target_flags_definition;

	extern s_tag_struct_definition model_permutation_block;
	extern s_string_list_definition model_permutation_flags_definition;

	extern s_tag_struct_definition model_region_block;

	extern s_tag_struct_definition model_node_block;

	extern s_tag_struct_definition model_self_shadow_region_cast_override_block;

	extern s_tag_struct_definition model_self_shadow_region_receive_override_block;
	extern s_string_list_definition model_prt_shadow_receive_mode_definition;

	extern s_tag_struct_definition model_occlusion_sphere_block;

	extern s_tag_struct_definition model_block_struct;
	extern s_tag_reference_definition render_model_group_reference$2_tagref;
	extern s_tag_reference_definition collision_model_group_reference_tagref;
	extern s_tag_reference_definition model_animation_graph_group_reference_tagref;
	extern s_tag_reference_definition physics_model_group_reference_tagref;
	extern s_tag_reference_definition imposter_model_group_reference$2_tagref;
	extern s_string_list_definition imposter_quality_definition;
	extern s_string_list_definition imposter_policy_definition;
	extern s_tag_reference_definition dialogue_group_reference$3_tagref;
	extern s_string_list_definition model_flags_definition;
	extern s_string_list_definition model_private_flags_definition;
	extern s_string_list_definition model_self_shadow_detail_definition;
	extern s_string_list_definition model_self_shadow_bounces_definition;
	extern s_tag_reference_definition shield_impact_group_reference_tagref;

	extern s_tag_struct_definition sky_lights_block;

	extern s_tag_struct_definition instance_node_map_mapping_block;

	extern s_tag_struct_definition radiance_transfer_matrix_struct_definition;

	extern s_tag_struct_definition volume_samples_block;

	extern s_tag_struct_definition default_node_orientations_block;

	extern s_tag_struct_definition default_lightprobe_struct_definition;

	extern s_tag_struct_definition default_dual_vmf_struct_definition;

	extern s_tag_struct_definition sun_direction_intensity_struct_definition;

	extern s_tag_struct_definition render_model_permutation_block;
	extern s_string_list_definition render_model_instance_bitfield_flags_definition;

	extern s_tag_struct_definition render_model_region_block;

	extern s_tag_struct_definition render_model_node_block;

	extern s_tag_struct_definition render_model_marker_block;
	extern s_string_list_definition render_model_marker_flags_definition;

	extern s_tag_struct_definition render_model_marker_group_block;

	extern s_tag_struct_definition render_model_block_struct;
	extern s_string_list_definition render_model_flags_definition;

	extern s_tag_struct_definition imposter_mode_node_block;

	extern s_tag_struct_definition imposter_model_struct_definition;

	extern s_tag_struct_definition multiplayer_object_type_block;
	extern s_tag_reference_definition object_group_reference$4_tagref;

	extern s_tag_struct_definition multiplayer_object_collection_block;

	extern s_tag_struct_definition multiplayer_weapon_remap_table_entry_block;

	extern s_tag_struct_definition multiplayer_vehicle_remap_table_entry_block;

	extern s_tag_struct_definition multiplayer_weapon_remap_table_block;

	extern s_tag_struct_definition multiplayer_vehicle_remap_table_block;

	extern s_tag_struct_definition multiplayer_object_type_list_struct_definition;

	extern s_tag_struct_definition campaign_metagame_bucket_block;
	extern s_string_list_definition campaign_metagame_bucket_flags;
	extern s_string_list_definition campaign_metagame_bucket_type_enum;
	extern s_string_list_definition campaign_metagame_bucket_class_enum;

	extern s_tag_struct_definition campaign_metagame_scenario_bonuses_block;

	extern s_tag_struct_definition campaign_metagame_scenario_block;

	extern s_tag_struct_definition campaign_metagame_style_type_block;

	extern s_tag_struct_definition campaign_metagame_difficulty_scale_block;

	extern s_tag_struct_definition campaign_metagame_skull_block;

	extern s_tag_struct_definition campaign_metagame_globals_block;

	extern s_tag_struct_definition loadout_definition_block;
	extern s_string_list_definition player_trait_grenade_count_setting;

	extern s_tag_struct_definition loadout_index_block;

	extern s_tag_struct_definition loadout_name_block;

	extern s_tag_struct_definition loadout_palette_definition_block;

	extern s_tag_struct_definition loadout_globals_definition_struct_definition;

	extern s_tag_struct_definition game_engine_loadout_palette_entry_block;

	extern s_tag_struct_definition game_engine_loadout_options_block;
	extern s_string_list_definition loadout_flags_definition;

	extern s_tag_struct_definition sound_platform_sound_playback_block;

	extern s_tag_struct_definition sound_dialogue_constants_struct_definition;

	extern s_tag_struct_definition sound_propagation_definition_struct;

	extern s_tag_struct_definition sound_global_propagation_block_struct;

	extern s_tag_struct_definition sound_center_mix_struct;

	extern s_tag_struct_definition sound_global_mix_struct;
	extern s_tag_reference_definition sound_group_reference_tagref;

	extern s_tag_struct_definition campaign_unspatialized_sounds_block;

	extern s_tag_struct_definition sound_globals_block;
	extern s_tag_reference_definition sound_classes_group_reference_tagref;
	extern s_tag_reference_definition sound_mix_group_reference_tagref;
	extern s_tag_reference_definition sound_dialogue_constants_group_reference_tagref;
	extern s_tag_reference_definition sound_global_propagation_group_reference_tagref;

	extern s_tag_struct_definition sound_stereo_mix_struct;

	extern s_tag_struct_definition sound_surround_mix_struct;

	extern s_tag_struct_definition sound_transmission_definition_struct;

	extern s_tag_struct_definition sound_mix_block_struct;

	extern s_tag_struct_definition sound_resource_definition_struct;

	extern s_tag_struct_definition sound_permutation_marker_block;

	extern s_tag_struct_definition sound_xma2_seek_table_block;

	extern s_tag_struct_definition facial_animation_curve_block_struct;
	extern s_string_list_definition facial_animation_track_enum_definition;

	extern s_tag_struct_definition facial_animation_permutation_block_struct;

	extern s_tag_struct_definition facial_animation_resource_definition_struct;

	extern s_tag_struct_definition facial_animation_language_block_struct;
	extern s_string_list_definition sound_language_enum_definition;

	extern s_tag_struct_definition sound_permutation_raw_info_block;
	extern s_string_list_definition sound_compression_enum;

	extern s_tag_struct_definition sound_definition_language_permutation_info_block;

	extern s_tag_struct_definition sound_distance_parameters_struct;

	extern s_tag_struct_definition sound_permutation_languages_block_struct;

	extern s_tag_struct_definition sound_permutations_block;
	extern s_string_list_definition sound_permutation_external_flags;
	extern s_string_list_definition sound_permutation_flags;

	extern s_tag_struct_definition sound_pitch_range_block;
	extern s_string_list_definition sound_pitch_range_internal_xsync_flags;

	extern s_tag_struct_definition sound_playback_parameters_struct;
	extern s_string_list_definition sound_override_location_flags_definition;

	extern s_tag_struct_definition sound_scale_modifiers_struct;

	extern s_tag_struct_definition sound_promotion_rule_block;

	extern s_tag_struct_definition sound_promotion_runtime_timer_block;

	extern s_tag_struct_definition sound_extra_info_block_struct;

	extern s_tag_struct_definition sound_block_struct;
	extern s_string_list_definition sound_definition_flags;
	extern s_string_list_definition sound_import_flags;
	extern s_string_list_definition sound_xsync_flags;
	extern s_string_list_definition sound_class_enum;
	extern s_string_list_definition sound_sample_rate_enum;
	extern s_string_list_definition sound_import_type_enum;
	extern s_string_list_definition sound_encoding_enum;

	extern s_tag_struct_definition looping_sound_track_block;
	extern s_string_list_definition looping_sound_track_flags;
	extern s_string_list_definition sound_effects_enum;
	extern s_string_list_definition looping_sound_fade_modes;
	extern s_string_list_definition looping_sound_layers;
	extern s_string_list_definition looping_sound_track_layer_flags;

	extern s_tag_struct_definition sound_looping_struct_definition;
	extern s_string_list_definition looping_sound_flags;

	extern s_tag_struct_definition sound_permutation_chunk_block;

	extern s_tag_struct_definition sound_promotion_parameters_struct;

	extern s_tag_struct_definition looping_sound_detail_block;
	extern s_string_list_definition looping_sound_detail_period_type_enum;
	extern s_string_list_definition looping_sound_detail_flags;

	extern s_tag_struct_definition havok_collision_filter_group_block;

	extern s_tag_struct_definition havok_group_filter_filter_struct;

	extern s_tag_struct_definition havok_collision_filter_struct_definition;

	extern s_tag_struct_definition player_trait_shield_vitality_block;
	extern s_string_list_definition player_trait_damage_resistance;
	extern s_string_list_definition player_trait_shield_multiplier;
	extern s_string_list_definition player_trait_shield_recharge_rate;
	extern s_string_list_definition player_trait_boolean;
	extern s_string_list_definition player_trait_vampirism;

	extern s_tag_struct_definition player_trait_weapons_block;
	extern s_string_list_definition player_trait_damage_modifier;
	extern s_string_list_definition player_trait_infinite_ammo_setting;
	extern s_string_list_definition player_trait_equipment_usage_setting;

	extern s_tag_struct_definition player_trait_movement_block;
	extern s_string_list_definition player_trait_speed;
	extern s_string_list_definition player_trait_gravity;
	extern s_string_list_definition player_trait_movement_vehicle_usage;
	extern s_string_list_definition player_trait_movement_double_jump;

	extern s_tag_struct_definition player_trait_sensors_block;
	extern s_string_list_definition player_trait_sensors_motion_tracker_settings;
	extern s_string_list_definition player_trait_sensors_motion_tracker_range;

	extern s_tag_struct_definition player_trait_appearance_block;
	extern s_string_list_definition player_trait_appearance_active_camo_settings;
	extern s_string_list_definition player_trait_appearance_waypoint_settings;
	extern s_string_list_definition player_trait_appearance_aura_settings;
	extern s_string_list_definition player_trait_appearance_forced_change_color_settings;

	extern s_tag_struct_definition game_engine_player_traits_block;

	extern s_tag_struct_definition game_engine_player_traits_list_block;

	extern s_tag_struct_definition pathfinding_object_index_list_block;

	extern s_tag_struct_definition scenario_object_id_struct;
	extern s_string_list_definition object_source_enum_definition;

	extern s_tag_struct_definition scenario_object_reference_struct;

	extern s_tag_struct_definition scenario_object_parent_struct;

	extern s_tag_struct_definition scenario_object_node_orientations_bit_vector_block;

	extern s_tag_struct_definition scenario_object_node_orientations_orientations_block;

	extern s_tag_struct_definition scenario_object_node_orientations_block;

	extern s_tag_struct_definition scenario_object_permutation_struct;
	extern s_string_list_definition scenario_object_active_change_color_flags;

	extern s_tag_struct_definition scenario_multiplayer_object_struct;
	extern s_string_list_definition game_engine_symmetry_placement_flags;
	extern s_string_list_definition global_multiplayer_team_designator_enum_definition;
	extern s_string_list_definition multiplayer_object_placement_spawn_flags;
	extern s_string_list_definition multiplayer_goal_area_boundary_shape_enum;
	extern s_string_list_definition multiplayer_object_remapping_policy;
	extern s_string_list_definition multiplayer_teleporter_channel;

	extern s_tag_struct_definition scenario_scenery_palette_block;
	extern s_tag_reference_definition scenery_group_reference$2_tagref;

	extern s_tag_struct_definition scenario_scenery_datum_struct_v4;
	extern s_string_list_definition pathfinding_policy_enum;
	extern s_string_list_definition scenery_lightmap_policy_enum;

	extern s_tag_struct_definition scenario_crate_palette_block;
	extern s_tag_reference_definition crate_group_reference_tagref;

	extern s_tag_struct_definition scenario_crate_datum_struct;

	extern s_tag_struct_definition scenario_crate_block;

	extern s_tag_struct_definition scenario_creature_palette_block;
	extern s_tag_reference_definition creature_group_reference_tagref;

	extern s_tag_struct_definition scenario_creature_block;

	extern s_tag_struct_definition scenario_equipment_palette_block;
	extern s_tag_reference_definition equipment_group_reference_tagref;

	extern s_tag_struct_definition scenario_equipment_datum_struct;
	extern s_string_list_definition scenario_equipment_flags_definition;

	extern s_tag_struct_definition scenario_weapon_palette_block;
	extern s_tag_reference_definition weapon_group_reference_tagref;

	extern s_tag_struct_definition scenario_weapon_datum_struct;
	extern s_string_list_definition scenario_weapon_datum_flags;

	extern s_tag_struct_definition scenario_unit_struct;
	extern s_string_list_definition scenario_unit_datum_flags;

	extern s_tag_struct_definition scenario_biped_palette_block;
	extern s_tag_reference_definition biped_group_reference_tagref;

	extern s_tag_struct_definition scenario_giant_datum_struct;

	extern s_tag_struct_definition scenario_giant_palette_block;
	extern s_tag_reference_definition giant_group_reference_tagref;

	extern s_tag_struct_definition scenario_requisition_palette_block;
	extern s_tag_reference_definition _reference$21_tagref;
	extern s_string_list_definition requisition_submenu_global_enum;
	extern s_string_list_definition scenario_requisition_palette_presence;

	extern s_tag_struct_definition scenario_vehicle_palette_block;
	extern s_tag_reference_definition vehicle_group_reference_tagref;

	extern s_tag_struct_definition device_group_block;
	extern s_string_list_definition device_group_flags;

	extern s_tag_struct_definition scenario_device_struct;
	extern s_string_list_definition scenario_device_flags;

	extern s_tag_struct_definition scenario_machine_palette_block;
	extern s_tag_reference_definition device_machine_group_reference_tagref;

	extern s_tag_struct_definition scenario_machine_struct_v3;
	extern s_string_list_definition scenario_machine_flags;
	extern s_string_list_definition scenario_machine_pathfinding_policy_enum;

	extern s_tag_struct_definition scenario_terminal_palette_block;
	extern s_tag_reference_definition device_terminal_group_reference_tagref;

	extern s_tag_struct_definition scenario_terminal_struct;

	extern s_tag_struct_definition scenario_terminal_block;

	extern s_tag_struct_definition scenario_control_palette_block;
	extern s_tag_reference_definition device_control_group_reference_tagref;

	extern s_tag_struct_definition scenario_control_struct;
	extern s_string_list_definition scenario_control_flags;
	extern s_string_list_definition scenario_control_character_types;

	extern s_tag_struct_definition scenario_sound_scenery_palette_block;
	extern s_tag_reference_definition sound_scenery_group_reference_tagref;

	extern s_tag_struct_definition sound_scenery_datum_struct;
	extern s_string_list_definition sound_volume_type_enumeration;

	extern s_tag_struct_definition scenario_effect_scenery_datum_struct;

	extern s_tag_struct_definition scenario_effect_scenery_palette_block;
	extern s_tag_reference_definition effect_scenery_group_reference_tagref;

	extern s_tag_struct_definition scenario_light_palette_block;
	extern s_tag_reference_definition light_group_reference_tagref;

	extern s_tag_struct_definition scenario_light_struct;
	extern s_string_list_definition scenario_light_flags_definition;
	extern s_string_list_definition scenario_light_lightmap_type_enum_definition;
	extern s_string_list_definition scenario_light_lightmap_flags_definition;

	extern s_tag_struct_definition scenario_object_datum_struct;
	extern s_string_list_definition object_location_placement_flags;
	extern s_string_list_definition scenario_object_bsp_placement_policy_definition;
	extern s_string_list_definition object_transform_flags;

	extern s_tag_struct_definition scenario_scenery_block;

	extern s_tag_struct_definition scenario_equipment_block;

	extern s_tag_struct_definition scenario_weapon_block;

	extern s_tag_struct_definition scenario_biped_block;

	extern s_tag_struct_definition scenario_giant_block;

	extern s_tag_struct_definition scenario_vehicle_block;

	extern s_tag_struct_definition scenario_machine_block;

	extern s_tag_struct_definition scenario_control_block;

	extern s_tag_struct_definition scenario_sound_scenery_block;

	extern s_tag_struct_definition scenario_effect_scenery_block;

	extern s_tag_struct_definition scenario_light_block;

	extern s_tag_struct_definition instantaneous_damage_repsonse_block;
	extern s_string_list_definition damage_response_type_enum_definition;
	extern s_string_list_definition damage_response_constraint_damage_type_enum_definition;
	extern s_string_list_definition damage_response_flags_definition;
	extern s_string_list_definition damage_response_body_threshold_flags_definition;
	extern s_string_list_definition damage_response_custom_response_behavior_enum_definition;

	extern s_tag_struct_definition global_damage_section_block;
	extern s_string_list_definition damage_section_flags_definition;

	extern s_tag_struct_definition global_damage_nodes_block;

	extern s_tag_struct_definition damage_body_parameters_struct;

	extern s_tag_struct_definition damage_shield_parameters_struct;

	extern s_tag_struct_definition damage_seat_region_setting_block;

	extern s_tag_struct_definition damage_seat_info_block;

	extern s_tag_struct_definition damage_constraint_info_block;

	extern s_tag_struct_definition damage_section_recharge_speed_curve_block;

	extern s_tag_struct_definition damage_section_segmented_recharge_fraction;

	extern s_tag_struct_definition damage_response_region_transition_block;

	extern s_tag_struct_definition damage_transfer_block;
	extern s_string_list_definition damage_transfer_flags_definition;
	extern s_string_list_definition damage_transfer_function_enum_definition;

	extern s_tag_struct_definition seat_ejection_block;

	extern s_tag_struct_definition new_instantaneous_damage_response_block;
	extern s_string_list_definition new_damage_response_flags_definition;

	extern s_tag_struct_definition damage_section_rendering_paramters;

	extern s_tag_struct_definition new_global_damage_section_block;
	extern s_string_list_definition new_damage_section_flags_definition;

	extern s_tag_struct_definition model_damage_info_struct;
	extern s_string_list_definition new_model_damage_info_flags_definition;

	extern s_tag_struct_definition global_damage_info_block;
	extern s_string_list_definition model_damage_info_flags_definition;

	extern s_tag_struct_definition instantaneous_response_damage_effect_struct;

	extern s_tag_struct_definition instantaneous_response_damage_effect_marker_struct;

	extern s_tag_struct_definition materials_block;
	extern s_string_list_definition physics_material_flags;
	extern s_string_list_definition physics_material_proxy_collision_groups;

	extern s_tag_struct_definition havok_shape_struct;

	extern s_tag_struct_definition havok_shape_reference_struct;
	extern s_string_list_definition shape_enum;

	extern s_tag_struct_definition phantoms_block;

	extern s_tag_struct_definition havok_primitive_struct;

	extern s_tag_struct_definition havok_shape_collection_struct;

	extern s_tag_struct_definition havok_convex_shape_struct;

	extern s_tag_struct_definition havok_convex_transform_shape_struct;

	extern s_tag_struct_definition havok_convex_translate_shape_struct;

	extern s_tag_struct_definition physics_model_damped_spring_motor_block;

	extern s_tag_struct_definition physics_model_position_motor_block;

	extern s_tag_struct_definition physics_model_motor_reference_struct;
	extern s_string_list_definition physics_model_motor_types_enum;

	extern s_tag_struct_definition physics_model_ragdoll_motors_block;

	extern s_tag_struct_definition physics_model_limited_hinge_motors_block;

	extern s_tag_struct_definition physics_model_constraint_edge_constraint_block;
	extern s_string_list_definition rigid_constraint_types_enum;
	extern s_string_list_definition rigid_body_constraint_edge_constraint_flags_definition;

	extern s_tag_struct_definition nodes_block;
	extern s_string_list_definition nodes_flags;

	extern s_tag_struct_definition physics_model_powered_chain_nodes_block;

	extern s_tag_struct_definition physics_model_powered_chain_constraints_block;

	extern s_tag_struct_definition physics_model_powered_chains_block;

	extern s_tag_struct_definition physics_model_node_constraint_edge_block;

	extern s_tag_struct_definition rigid_body_indices_block;

	extern s_tag_struct_definition permutations_block;

	extern s_tag_struct_definition regions_block;

	extern s_tag_struct_definition spheres_block_struct;

	extern s_tag_struct_definition multi_sphere_vector_storage_struct_definition;

	extern s_tag_struct_definition multi_spheres_block;

	extern s_tag_struct_definition pills_block;

	extern s_tag_struct_definition boxes_block_struct;

	extern s_tag_struct_definition triangles_block;

	extern s_tag_struct_definition polyhedron_shape_struct;

	extern s_tag_struct_definition polyhedra_block;

	extern s_tag_struct_definition polyhedron_four_vectors_block;

	extern s_tag_struct_definition polyhedron_plane_equations_block;

	extern s_tag_struct_definition mass_distributions_block;

	extern s_tag_struct_definition lists_block;

	extern s_tag_struct_definition list_shapes_block;

	extern s_tag_struct_definition mopps_block;

	extern s_tag_struct_definition constraint_bodies_struct;

	extern s_tag_struct_definition hinge_constraints_block;

	extern s_tag_struct_definition limited_hinge_constraints_block;

	extern s_tag_struct_definition ragdoll_constraints_block;

	extern s_tag_struct_definition ball_and_socket_constraints_block;

	extern s_tag_struct_definition stiff_spring_constraints_block;

	extern s_tag_struct_definition prismatic_constraints_block;

	extern s_tag_struct_definition point_to_path_curve_point_block;

	extern s_tag_struct_definition point_to_path_curve_block;

	extern s_tag_struct_definition rigid_bodies_block;
	extern s_string_list_definition rigid_body_flags;
	extern s_string_list_definition rigid_body_motion_enum;
	extern s_string_list_definition rigid_body_size_enum;

	extern s_tag_struct_definition phantom_types_block;
	extern s_string_list_definition phantom_flags;

	extern s_tag_struct_definition physics_model_struct_definition;
	extern s_string_list_definition physics_model_flags;

	extern s_tag_struct_definition g_node_flag_storage_array_struct_definition;

	extern s_tag_struct_definition animation_node_mask_entry_block;

	extern s_tag_struct_definition animation_node_mask_block;

	extern s_tag_struct_definition animation_function_block;

	extern s_tag_struct_definition animation_aiming_screen_struct;

	extern s_tag_struct_definition animation_graph_sound_reference_block;
	extern s_string_list_definition key_event_flags_enum;

	extern s_tag_struct_definition animation_graph_effect_reference_block;

	extern s_tag_struct_definition animation_frame_event_block_struct;
	extern s_string_list_definition frame_event_type_new;

	extern s_tag_struct_definition animation_sound_event_block;

	extern s_tag_struct_definition animation_dialogue_event_block;
	extern s_string_list_definition animation_dialogue_event_enum;

	extern s_tag_struct_definition animation_blend_screen_block;

	extern s_tag_struct_definition packed_data_sizes_struct;

	extern s_tag_struct_definition quantized_orientation_struct;

	extern s_tag_struct_definition object_space_node_data_block;
	extern s_string_list_definition object_space_node_flags;

	extern s_tag_struct_definition foot_tracking_member_block;
	extern s_string_list_definition foot_tracking_default_values;

	extern s_tag_struct_definition foot_lock_cycle_block;

	extern s_tag_struct_definition foot_tracking_block;

	extern s_tag_struct_definition foot_tracking_defaults;

	extern s_tag_struct_definition object_space_offset_node_block;

	extern s_tag_struct_definition fik_anchor_node_block;

	extern s_tag_struct_definition animation_ik_chain_events_struct;
	extern s_string_list_definition animation_ik_chain_type_enumeration;
	extern s_string_list_definition animation_ik_chain_event_usage;
	extern s_string_list_definition animation_ik_chain_event_type;

	extern s_tag_struct_definition animation_facial_wrinkle_events_struct;
	extern s_string_list_definition animation_facial_wrinkle_region;

	extern s_tag_struct_definition animation_extended_events_struct;

	extern s_tag_struct_definition animation_object_functions_struct;
	extern s_string_list_definition animation_object_function_name;

	extern s_tag_struct_definition animation_ik_chain_proxies_struct;

	extern s_tag_struct_definition shared_model_animation_block;
	extern s_string_list_definition animation_type_enum;
	extern s_string_list_definition frame_info_type_enum;
	extern s_string_list_definition compression_settings;
	extern s_string_list_definition internal_animation_flags;

	extern s_tag_struct_definition shared_animation_reference_block;
	extern s_tag_reference_definition model_animation_graph_group_reference$2_tagref;

	extern s_tag_struct_definition animation_pool_block_struct;
	extern s_string_list_definition animation_index_flags;
	extern s_string_list_definition production_status_flags;

	extern s_tag_struct_definition animation_index_struct;

	extern s_tag_struct_definition import_frame_event_block;

	extern s_tag_struct_definition animation_sound_event_block_extended;

	extern s_tag_struct_definition animation_effects_event_block_extended;

	extern s_tag_struct_definition animation_dialogue_event_block_extended;

	extern s_tag_struct_definition import_animation_event_block;

	extern s_tag_struct_definition animation_transition_destination_block;

	extern s_tag_struct_definition animation_transition_source_block_struct;

	extern s_tag_struct_definition new_animation_blend_screen_block_struct;
	extern s_string_list_definition blend_screen_definition_flags;
	extern s_string_list_definition blend_screen_variable_sources;
	extern s_string_list_definition blend_screen_weight_sources;

	extern s_tag_struct_definition new_animation_function_overlay_block;
	extern s_string_list_definition function_overlay_definition_flags;

	extern s_tag_struct_definition blend_screen_item_definition_block;
	extern s_string_list_definition pose_overlay_item_definition_block_flags;

	extern s_tag_struct_definition function_overlay_item_definition_block;

	extern s_tag_struct_definition overlay_group_definition_block;

	extern s_tag_struct_definition animation_gait_block;
	extern s_string_list_definition animation_gait_directions;

	extern s_tag_struct_definition animation_gait_item_block;

	extern s_tag_struct_definition animation_gait_group_block;

	extern s_tag_struct_definition animation_ik_block_v1;

	extern s_tag_struct_definition animation_ik_block;
	extern s_string_list_definition animation_ik_target_enum_definition;

	extern s_tag_struct_definition animation_ik_set_item;
	extern s_string_list_definition animation_ik_set_item_flags;

	extern s_tag_struct_definition animation_ik_set;

	extern s_tag_struct_definition animation_sync_action_same_type_participant;
	extern s_string_list_definition animation_sync_action_flags_definition;

	extern s_tag_struct_definition animation_sync_action_other_type_participant;
	extern s_string_list_definition animation_sync_action_other_type_flags_definition;
	extern s_tag_reference_definition _reference$13_tagref;

	extern s_tag_struct_definition animation_sync_action_block;

	extern s_tag_struct_definition animation_sync_action_group_block;

	extern s_tag_struct_definition animation_entry_block;

	extern s_tag_struct_definition ranged_animation_entry_block_struct;

	extern s_tag_struct_definition damage_region_block;

	extern s_tag_struct_definition damage_direction_block;

	extern s_tag_struct_definition damage_animation_block;

	extern s_tag_struct_definition vehicle_suspension_block;

	extern s_tag_struct_definition animation_velocity_boundaries_struct_definition;

	extern s_tag_struct_definition animation_velocity_boundaries_block;

	extern s_tag_struct_definition animation_set_block;

	extern s_tag_struct_definition weapon_type_block_struct;

	extern s_tag_struct_definition triangulation_point_block;

	extern s_tag_struct_definition triangulation_triangle_block;

	extern s_tag_struct_definition triangulation_entry_block;

	extern s_tag_struct_definition animation_ranged_action_block;
	extern s_string_list_definition ranged_action_variable_sources;

	extern s_tag_struct_definition weapon_class_block_struct;

	extern s_tag_struct_definition animation_mode_block;
	extern s_string_list_definition animation_mode_flags;

	extern s_tag_struct_definition function_overlay_animation_block;
	extern s_string_list_definition function_overlay_animation_mode;

	extern s_tag_struct_definition animation_usage_block;
	extern s_string_list_definition animation_usage_enumeration;

	extern s_tag_struct_definition mode_or_stance_alias_block_struct;

	extern s_tag_struct_definition model_animation_variant_block;
	extern s_string_list_definition model_animation_variant_flags;

	extern s_tag_struct_definition animation_ik_chain_block;

	extern s_tag_struct_definition animation_graph_definitions_struct;
	extern s_string_list_definition public_animation_graph_flags;
	extern s_string_list_definition private_animation_graph_flags;
	extern s_string_list_definition compression_force_settings;
	extern s_tag_reference_definition frame_event_list_group_reference_tagref;

	extern s_tag_struct_definition animation_graph_contents_struct;

	extern s_tag_struct_definition inherited_animation_node_map_block;

	extern s_tag_struct_definition inherited_animation_node_map_flag_block;

	extern s_tag_struct_definition inherited_animation_block;

	extern s_tag_struct_definition weapon_class_lookup_block;

	extern s_tag_struct_definition additional_node_data_block;

	extern s_tag_struct_definition model_animation_runtime_data_struct;

	extern s_tag_struct_definition model_animation_tag_resource_member;

	extern s_tag_struct_definition model_animation_tag_resource_struct;

	extern s_tag_struct_definition model_animation_tag_resource_group;

	extern s_tag_struct_definition frame_event_list_struct_definition;

	extern s_tag_struct_definition model_animation_graph_block_struct;

	extern s_tag_struct_definition animation_graph_node_block;
	extern s_string_list_definition animation_node_model_flags;
	extern s_string_list_definition node_joint_flags;
	extern s_string_list_definition node_info_flags;

	extern s_tag_struct_definition animation_effect_event_block;

	extern s_tag_struct_definition character_physics_ground_struct;

	extern s_tag_struct_definition character_physics_flying_struct;
	extern s_string_list_definition flying_physics_flags;

	extern s_tag_struct_definition character_physics_struct;
	extern s_string_list_definition character_physics_flags;

	extern s_tag_struct_definition grounded_friction_struct_definition;

	extern s_tag_struct_definition old_material_effect_material_block;
	extern s_string_list_definition sweeneter_mode_enum;

	extern s_tag_struct_definition material_effect_block_v2;

	extern s_tag_struct_definition material_effects_block_struct;

	extern s_tag_struct_definition material_effect_material_block;
	extern s_tag_reference_definition _reference$11_tagref;

	extern s_tag_struct_definition player_information_block;

	extern s_tag_struct_definition player_representation_block;
	extern s_string_list_definition player_representation_flags;
	extern s_tag_reference_definition render_model_group_reference$3_tagref;
	extern s_tag_reference_definition unit_group_reference$3_tagref;

	extern s_tag_struct_definition location_name_block;

	extern s_tag_struct_definition location_name_globals_definition_struct_definition;

	extern s_tag_struct_definition input_mapping_function_block;

	extern s_tag_struct_definition gamepad_stick_info_block;
	extern s_string_list_definition input_mapping_shape_enum;

	extern s_tag_struct_definition controller_input_block;

	extern s_tag_struct_definition player_control_block;

	extern s_tag_struct_definition camera_obstruction_struct;

	extern s_tag_struct_definition camera_track_control_point_block;

	extern s_tag_struct_definition camera_track_struct_definition;
	extern s_string_list_definition camera_track_flags;

	extern s_tag_struct_definition simulated_input_stick_struct;
	extern s_string_list_definition direction_type_enum_definition;
	extern s_string_list_definition mapping_type_enum_definition;

	extern s_tag_struct_definition simulated_input_struct_definition;

	extern s_tag_struct_definition camera_impulse_struct;

	extern s_tag_struct_definition global_camera_impulse_block;

	extern s_tag_struct_definition camera_shake_struct;
	extern s_string_list_definition animated_camera_shake_playback_type_enum;
	extern s_string_list_definition animated_camera_shake_weight_type_enum;

	extern s_tag_struct_definition camera_shake_struct_definition;

	extern s_tag_struct_definition rumble_frequency_definition_struct;

	extern s_tag_struct_definition rumble_definition_struct;

	extern s_tag_struct_definition rumble_struct_definition;

	extern s_tag_struct_definition point_physics_struct_definition;
	extern s_string_list_definition point_physics_definition_flags;

	extern s_tag_struct_definition cheap_particle_scalar_object_function_struct;

	extern s_tag_struct_definition cheap_particle_emitter_struct_definition;
	extern s_string_list_definition cheap_particle_emitter_flags;
	extern s_tag_reference_definition bitmap_group_reference$6_tagref;
	extern s_tag_reference_definition cheap_particle_type_library_group_reference_tagref;

	extern s_tag_struct_definition cheap_particle_bitmap_reference_block;

	extern s_tag_struct_definition cheap_particle_type_block;
	extern s_string_list_definition cheap_particle_type_orientation;

	extern s_tag_struct_definition cheap_particle_type_library_struct_definition;

	extern s_tag_struct_definition anti_gravity_point_definition_block;
	extern s_string_list_definition anti_gravity_point_definition_flags;
	extern s_string_list_definition anti_gravity_point_definition_damping;

	extern s_tag_struct_definition friction_point_definition_block;
	extern s_string_list_definition friction_point_definition_flags;

	extern s_tag_struct_definition havok_vehicle_physics_struct;
	extern s_string_list_definition havok_vehicle_physics_definition_flags;
	extern s_string_list_definition physics_update_period_enum;

	extern s_tag_struct_definition walker_physics_leg_block;
	extern s_string_list_definition walker_physics_leg_group_enum;
	extern s_string_list_definition walker_physics_leg_side_enum;
	extern s_string_list_definition walker_physics_leg_flags;

	extern s_tag_struct_definition walker_physics_struct;

	extern s_tag_struct_definition boat_engine_definition_block;
	extern s_string_list_definition boat_flags;

	extern s_tag_struct_definition jetwash_definition_block;

	extern s_tag_struct_definition collision_kd_hierarchy_static_hash_table_headers_block;
	extern s_string_list_definition collision_kd_hierarchy_static_hash_table_cull_flags;

	extern s_tag_struct_definition collision_kd_hierarchy_static_nodes_block;

	extern s_tag_struct_definition super_node_mapping_index_array_struct_definition;

	extern s_tag_struct_definition super_node_mappings_block$2;

	extern s_tag_struct_definition cluster_table_block;

	extern s_tag_struct_definition collision_kd_hierarchy_static_hash_table_short_block;

	extern s_tag_struct_definition collision_kd_hierarchy_static_hash_table_data_block;

	extern s_tag_struct_definition collision_kd_hierarchy_static_in_use_masks_block;

	extern s_tag_struct_definition collision_kd_hierarchy_static_struct;

	extern s_tag_struct_definition scenario_scenery_resource_struct_definition;

	extern s_tag_struct_definition scenario_bipeds_resource_struct_definition;

	extern s_tag_struct_definition scenario_vehicles_resource_struct_definition;

	extern s_tag_struct_definition scenario_equipment_resource_struct_definition;

	extern s_tag_struct_definition scenario_weapons_resource_struct_definition;

	extern s_tag_struct_definition scenario_sound_scenery_resource_struct_definition;

	extern s_tag_struct_definition scenario_lights_resource_struct_definition;

	extern s_tag_struct_definition scenario_devices_resource_struct_definition;

	extern s_tag_struct_definition scenario_effect_scenery_resource_struct_definition;

	extern s_tag_struct_definition scenario_decals_resource_struct_definition;

	extern s_tag_struct_definition scenario_cinematics_resource_struct_definition;

	extern s_tag_struct_definition scenario_trigger_volumes_resource_struct_definition;

	extern s_tag_struct_definition scenario_performances_resource_struct_definition;

	extern s_tag_struct_definition scenario_dumplings_resource_struct_definition;

	extern s_tag_struct_definition scenario_cluster_data_resource_struct_definition;

	extern s_tag_struct_definition scenario_sky_references_resource_struct_definition;

	extern s_tag_struct_definition scenario_cubemap_resource_struct_definition;

	extern s_tag_struct_definition scenario_ai_resource_struct_definition;

	extern s_tag_struct_definition scenario_comments_resource_struct_definition;

	extern s_tag_struct_definition scenario_creature_resource_struct_definition;

	extern s_tag_struct_definition scenario_decorators_resource_struct_definition;

	extern s_tag_struct_definition scenario_structure_lighting_resource_struct_definition;

	extern s_tag_struct_definition scenario_hs_source_reference_block;
	extern s_tag_reference_definition scenario_hs_source_file_group_reference_tagref;

	extern s_tag_struct_definition scenario_ai_resource_reference_block;
	extern s_tag_reference_definition scenario_ai_resource_group_reference_tagref;

	extern s_tag_struct_definition scenario_split_resources_block_struct;
	extern s_tag_reference_definition scenario_scenery_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_bipeds_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_vehicles_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_equipment_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_weapons_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_lights_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_devices_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_effect_scenery_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_decals_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_cinematics_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_trigger_volumes_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_cluster_data_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_sound_scenery_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_comments_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_creature_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_structure_lighting_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_decorators_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_sky_references_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_cubemap_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_performances_resource_group_reference_tagref;
	extern s_tag_reference_definition scenario_dumplings_resource_group_reference_tagref;

	extern s_tag_struct_definition scenario_resources_block_struct;
	extern s_string_list_definition scenario_resource_flags_definition;

	extern s_tag_struct_definition structure_manifest_build_identifier_struct;

	extern s_tag_struct_definition structure_manifest_bsp_block;

	extern s_tag_struct_definition structure_manifest_struct;

	extern s_tag_struct_definition global_scenario_load_parameters_block;
	extern s_tag_reference_definition scenario_group_reference$2_tagref;

	extern s_tag_struct_definition sound_class_block_struct;
	extern s_string_list_definition sound_class_internal_flags_definition;
	extern s_string_list_definition sound_class_external_flags_definition;
	extern s_string_list_definition sound_class_cache_miss_mode_definition;
	extern s_string_list_definition sound_class_suppress_spatialization_string_defintion;
	extern s_string_list_definition sound_class_stereo_playback_definition;

	extern s_tag_struct_definition sound_classes_block_struct;

	extern s_tag_struct_definition global_sound_reverb_block;

	extern s_tag_struct_definition global_sound_look_up_table_distortion_block;
	extern s_string_list_definition look_up_table_flags_definition;

	extern s_tag_struct_definition global_sound_lowpass_block;

	extern s_tag_struct_definition sound_equalizer_band_settings_block_struct;
	extern s_string_list_definition equalizer_band_type_definition;

	extern s_tag_struct_definition global_sound_equalizer_block;

	extern s_tag_struct_definition sound_radio_settings_block_struct;
	extern s_string_list_definition radio_mix_setting_definition;

	extern s_tag_struct_definition single_variant_block;

	extern s_tag_struct_definition variant_globals_struct_definition;

	extern s_tag_struct_definition single_avatar_award_definition_block;
	extern s_string_list_definition global_avatar_award_enum;

	extern s_tag_struct_definition avatar_awards_struct_definition;

	extern s_tag_struct_definition tag_patch_block_struct;
	extern s_tag_reference_definition _reference$16_tagref;
	extern s_tag_reference_definition _reference$17_tagref;

	extern s_tag_struct_definition tag_package_manifest_block_struct;

	extern s_tag_struct_definition megalo_string_id_block;

	extern s_tag_struct_definition megalo_string_id_table_struct_definition;

	extern s_tag_struct_definition game_completion_rewards_falloff_point_block;

	extern s_tag_struct_definition game_completion_rewards_definition_block;

	extern s_tag_struct_definition game_completion_rewards_difficulty_block;

	extern s_tag_struct_definition game_completion_rewards_multiplayer_block;

	extern s_tag_struct_definition game_completion_rewards_never_online_block;

	extern s_tag_struct_definition game_completion_rewards_globals_struct_definition;

	extern s_tag_struct_definition challenge_block;
	extern s_string_list_definition challenge_definition_flags;
	extern s_string_list_definition challenge_progress_flags;
	extern s_string_list_definition skull_flags_definition;

	extern s_tag_struct_definition challenge_category_block;
	extern s_string_list_definition challenge_category_enum_definition;

	extern s_tag_struct_definition challenge_globals_definition_struct_definition;

	extern s_tag_struct_definition game_medal_block_struct;
	extern s_string_list_definition medal_class_enum;

	extern s_tag_struct_definition game_medal_globals_struct_definition;

	extern s_tag_struct_definition coop_spawning_globals_definition_struct_definition;
	extern s_string_list_definition coop_spawning_flags;
	extern s_string_list_definition safety_check_mode_enum;

	extern s_tag_struct_definition purchase_player_appearance_effect_model_permutation_block;
	extern s_string_list_definition player_model_customization_area_enum;

	extern s_tag_struct_definition purchase_player_appearance_effect_non_model_permutation_block;
	extern s_string_list_definition player_non_model_customization_area_enum;

	extern s_tag_struct_definition purchase_player_appearance_effect_visor_tint_block;

	extern s_tag_struct_definition purchase_player_appearance_effect_emblem_index_block;

	extern s_tag_struct_definition purchase_player_appearance_effect_voice_block;

	extern s_tag_struct_definition purchase_player_appearance_struct;

	extern s_tag_struct_definition purchase_prerequisite_grade_definition_block;
	extern s_string_list_definition player_grade_enum;
	extern s_string_list_definition player_sub_grade_enum;

	extern s_tag_struct_definition purchase_prerequisite_purchased_item_definition_block;

	extern s_tag_struct_definition purchase_prerequisites_unlockable_definition_block;

	extern s_tag_struct_definition purchase_prerequisites_definition_block;

	extern s_tag_struct_definition cookie_purchase_definition_block;
	extern s_string_list_definition cookie_purchase_flags;

	extern s_tag_struct_definition purchase_definition_reference_struct;

	extern s_tag_struct_definition cookie_purchase_definition_reference_block;

	extern s_tag_struct_definition cookie_purchase_family_definition_block;

	extern s_tag_struct_definition cookie_purchase_external_unlockable_block_definition;

	extern s_tag_struct_definition cookie_purchase_globals_struct_definition;

	extern s_tag_struct_definition cookie_award_definition_block;
	extern s_string_list_definition cookie_type_enum;

	extern s_tag_struct_definition cookie_globals_definition_struct_definition;

	extern s_tag_struct_definition commendation_block;
	extern s_string_list_definition commendation_progression_level_with_none_enum;

	extern s_tag_struct_definition commendation_globals_definition_struct_definition;
	extern s_string_list_definition commendation_progression_level_enum;

	extern s_tag_struct_definition game_engine_ai_traits_struct;
	extern s_string_list_definition ai_trait_vision_settings;
	extern s_string_list_definition ai_trait_sound_settings;
	extern s_string_list_definition ai_trait_luck_settings;
	extern s_string_list_definition global_ai_trait_weapon_settings;
	extern s_string_list_definition ai_trait_grenade_settings;

	extern s_tag_struct_definition game_engine_ai_traits_list_block;

	extern s_tag_struct_definition game_engine_miscellaneous_options_block;
	extern s_string_list_definition game_engine_miscellaneous_options_flags;

	extern s_tag_struct_definition game_engine_respawn_options_block;
	extern s_string_list_definition game_engine_respawn_options_flags;

	extern s_tag_struct_definition game_engine_social_options_block;
	extern s_string_list_definition game_engine_social_options_flags;

	extern s_tag_struct_definition game_engine_map_override_options_block;
	extern s_string_list_definition game_engine_map_override_options_flags;

	extern s_tag_struct_definition game_engine_team_options_team_block_struct_definition;
	extern s_string_list_definition game_engine_team_options_team_flags;
	extern s_string_list_definition game_engine_team_options_player_model_choice;

	extern s_tag_struct_definition game_engine_team_options_block;
	extern s_string_list_definition game_engine_team_options_model_override_type;
	extern s_string_list_definition game_engine_team_options_designator_switch_type;

	extern s_tag_struct_definition game_engine_sandbox_variant_block;
	extern s_string_list_definition sandbox_flags;
	extern s_string_list_definition sandbox_editing_mode;
	extern s_string_list_definition sandbox_respawn_time;

	extern s_tag_struct_definition game_engine_survival_set_properties_block;
	extern s_string_list_definition skull_flags;

	extern s_tag_struct_definition survival_wave_squad_block;

	extern s_tag_struct_definition game_engine_survival_wave_properties_struct;
	extern s_string_list_definition survival_wave_properties_flags;
	extern s_string_list_definition survival_wave_squad_advance_type_enum;

	extern s_tag_struct_definition game_engine_survival_bonus_wave_properties_struct;

	extern s_tag_struct_definition game_engine_survival_round_properties_block;

	extern s_tag_struct_definition game_engine_survival_custom_skull_block;

	extern s_tag_struct_definition game_engine_survival_variant_block;
	extern s_string_list_definition game_engine_survival_variant_flags;
	extern s_string_list_definition global_campaign_difficulty_enum;

	extern s_tag_struct_definition game_engine_campaign_variant_block;

	extern s_tag_struct_definition game_engine_settings_definition_struct_definition;
	extern s_string_list_definition game_engine_settings_flags;

	extern s_tag_struct_definition game_engine_globals_struct_definition;
	extern s_tag_reference_definition game_engine_settings_definition_group_reference_tagref;

	extern s_tag_struct_definition player_sub_grade_definition_block;

	extern s_tag_struct_definition player_grade_definition_block;

	extern s_tag_struct_definition player_grade_globals_definition_struct_definition;

	extern s_tag_struct_definition suppressed_incident_block;
	extern s_string_list_definition suppressed_incident_flags;

	extern s_tag_struct_definition specialized_incident_kill_implement_block;

	extern s_tag_struct_definition specialized_incident_object_properties_block;
	extern s_string_list_definition specialized_incident_kill_bucket_flags;
	extern s_string_list_definition campaign_metagame_bucket_type_with_none_enum;
	extern s_string_list_definition campaign_metagame_bucket_class_with_none_enum;

	extern s_tag_struct_definition specialized_incident_special_kill_type_block;
	extern s_string_list_definition specialized_incident_special_kill_type_enum;

	extern s_tag_struct_definition specialized_incident_block;

	extern s_tag_struct_definition incident_accumulator_child_incident_block;
	extern s_string_list_definition incident_accumulator_flags;

	extern s_tag_struct_definition incident_accumulator_block;
	extern s_string_list_definition incident_accumulator_aggregation_method_enum;
	extern s_string_list_definition incident_accumulator_reset_enum;

	extern s_tag_struct_definition incident_definition_block_struct;
	extern s_string_list_definition incident_definition_flags;

	extern s_tag_struct_definition incident_globals_definition_block_struct;

	extern s_tag_struct_definition incident_globals_block;
	extern s_tag_reference_definition incident_globals_definition_group_reference_tagref;

	extern s_tag_struct_definition incident_global_properties_definition_struct_definition;
	extern s_tag_reference_definition cookie_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition commendation_globals_definition_group_reference_tagref;

	extern s_tag_struct_definition survival_mode_wave_templates_struct;
	extern s_tag_reference_definition wave_template_group_reference_tagref;

	extern s_tag_struct_definition survival_spartan_voice;
	extern s_tag_reference_definition dialogue_group_reference$4_tagref;

	extern s_tag_struct_definition survival_mode_globals_struct_definition;

	extern s_tag_struct_definition bink_resource_struct;

	extern s_tag_struct_definition bink_struct_definition;

	extern s_tag_struct_definition scenario_cutscene_title_struct;
	extern s_string_list_definition text_justification_enum_definition;
	extern s_string_list_definition text_vertical_justification_enum_definition;
	extern s_string_list_definition global_font_id_enum_definition;

	extern s_tag_struct_definition cinematic_characters_block;

	extern s_tag_struct_definition cinematic_custom_script_block;

	extern s_tag_struct_definition camera_frame_dynamic_struct;

	extern s_tag_struct_definition camera_frame_constant_struct;

	extern s_tag_struct_definition camera_frame_struct;

	extern s_tag_struct_definition scenario_and_zone_set_struct;
	extern s_tag_reference_definition scenario_group_reference_tagref;

	extern s_tag_struct_definition cinematic_shot_frame_block;

	extern s_tag_struct_definition cinematic_shot_frame_dynamic_block;

	extern s_tag_struct_definition cinematic_shot_frame_constant_block;

	extern s_tag_struct_definition cinematic_shot_clip_subject_block;

	extern s_tag_struct_definition cinematic_shot_clip_block;

	extern s_tag_struct_definition cinematic_shot_dialogue_block;

	extern s_tag_struct_definition cinematic_shot_music_block;
	extern s_string_list_definition music_flags_enum;

	extern s_tag_struct_definition cinematic_shot_effect_block;
	extern s_string_list_definition cinematic_shot_effect_flags;

	extern s_tag_struct_definition cinematic_shot_object_function_keyframe_block;
	extern s_string_list_definition cinematic_shot_object_function_flags;

	extern s_tag_struct_definition cinematic_shot_object_function_block;

	extern s_tag_struct_definition cinematic_shot_screen_effect_block;

	extern s_tag_struct_definition cinematic_shot_custom_script_block;
	extern s_string_list_definition cinematic_shot_custom_script_flags;

	extern s_tag_struct_definition cinematic_shot_user_input_constraints_block;

	extern s_tag_struct_definition cinematic_shot_block;
	extern s_string_list_definition shot_flags_definition;

	extern s_tag_struct_definition scene_object_attachment_block;
	extern s_string_list_definition scene_object_attachment_flags;
	extern s_tag_reference_definition _reference$6_tagref;

	extern s_tag_struct_definition cinematic_scene_object_block_struct;
	extern s_string_list_definition scene_object_flags;
	extern s_string_list_definition cinematic_coop_type_flags;

	extern s_tag_struct_definition cinematic_shot_lighting_block;
	extern s_string_list_definition cinematic_shot_lighting_flags_definition;

	extern s_tag_struct_definition cinematic_extra_camera_frame_block;
	extern s_string_list_definition cinematic_extra_camera_frame_flags;

	extern s_tag_struct_definition cinematic_extra_camera_shot_block;

	extern s_tag_struct_definition cinematic_shot_extra_camera_block;

	extern s_tag_struct_definition cinematic_scene_struct_definition;
	extern s_string_list_definition scene_reset_object_lighting_enum;

	extern s_tag_struct_definition cinematic_scene_reference_block;
	extern s_tag_reference_definition cinematic_scene_group_reference_tagref;

	extern s_tag_struct_definition cinematic_shot_playback_data_block;

	extern s_tag_struct_definition cinematic_playback_data_block;

	extern s_tag_struct_definition cinematic_transition_global_fade_block;

	extern s_tag_struct_definition cinematic_transition_global_gain_block_struct;

	extern s_tag_struct_definition cinematic_transition_sound_class_gain_block_struct;

	extern s_tag_struct_definition cinematic_transition_sound_reference_block_struct;

	extern s_tag_struct_definition cinematic_transition_looping_sound_reference_block_struct;

	extern s_tag_struct_definition cinematic_transition_looping_sound_state_block_struct;
	extern s_string_list_definition cinematic_transition_looping_sound_alternate_flags;
	extern s_string_list_definition cinematic_transition_looping_sound_layer_flags;

	extern s_tag_struct_definition cinematic_transition_element_block;

	extern s_tag_struct_definition cinematic_transition_block_struct;

	extern s_tag_struct_definition cinematic_block_struct;
	extern s_string_list_definition cinematic_channel_type_enum;
	extern s_string_list_definition cinematic_flags;
	extern s_tag_reference_definition cinematic_transition_group_reference_tagref;
	extern s_tag_reference_definition bink_group_reference_tagref;

	extern s_tag_struct_definition scenario_cinematics_block;
	extern s_string_list_definition scenario_cinematics_flags;
	extern s_tag_reference_definition cinematic_group_reference_tagref;

	extern s_tag_struct_definition cinematics_globals_block;
	extern s_tag_reference_definition scenery_group_reference$3_tagref;

	extern s_tag_struct_definition cache_file_resource_type_identifier_block;

	extern s_tag_struct_definition cache_file_interop_type_identifier_block;

	extern s_tag_struct_definition cache_file_codec_identifier_block;

	extern s_tag_struct_definition cache_file_resource_fixup_location_block;

	extern s_tag_struct_definition cache_file_resource_interop_location_block;

	extern s_tag_struct_definition cache_file_shared_file_block;
	extern s_string_list_definition cache_file_shared_file_flags_definition;

	extern s_tag_struct_definition cache_file_resource_streaming_sublocation_block;

	extern s_tag_struct_definition cache_file_resource_streaming_sublocation_table_block;

	extern s_tag_struct_definition resource_hash_definition_struct_definition;

	extern s_tag_struct_definition resource_checksum_struct;

	extern s_tag_struct_definition cache_file_resource_location_struct;
	extern s_string_list_definition cache_file_tag_resource_location_flags;

	extern s_tag_struct_definition cache_file_resource_default_location_block;

	extern s_tag_struct_definition cache_file_resource_data_block;
	extern s_string_list_definition cache_file_resource_data_flags_definition;

	extern s_tag_struct_definition cache_file_tag_resources_bitvector_block;

	extern s_tag_struct_definition cache_file_tag_resource_usage_block_struct;

	extern s_tag_struct_definition cache_file_bsp_reference_block;

	extern s_tag_struct_definition cache_file_resource_owner_block;

	extern s_tag_struct_definition cache_file_resource_owner_reference_block;

	extern s_tag_struct_definition cache_file_zone_resource_visit_node_block_struct;

	extern s_tag_struct_definition cache_file_zone_resource_visit_node_link_block;

	extern s_tag_struct_definition cache_file_model_variant_usage_block;

	extern s_tag_struct_definition cache_file_model_variant_usage_reference_block;

	extern s_tag_struct_definition cache_file_character_usage_block;

	extern s_tag_struct_definition cache_file_tag_zone_manifest_struct;

	extern s_tag_struct_definition cache_file_zone_set_zone_usage_block;

	extern s_tag_struct_definition resource_category_block;

	extern s_tag_struct_definition cache_file_debug_resource_definition_block;

	extern s_tag_struct_definition cache_file_resource_layout_block_struct;
	extern s_string_list_definition cache_file_resource_global_zone_attachment_flags;

	extern s_tag_struct_definition cache_file_tag_resource_named_value_block;
	extern s_string_list_definition named_value_type_enum;

	extern s_tag_struct_definition cache_file_tag_resource_properties_block;

	extern s_tag_struct_definition debug_cache_file_zone_manifest_struct;

	extern s_tag_struct_definition cache_file_tag_parentage_block_struct;
	extern s_string_list_definition cache_file_tag_parentage_flags_definition;

	extern s_tag_struct_definition cache_file_tag_parentage_reference_block;

	extern s_tag_struct_definition cache_file_tag_resource_prediction_quantum_block;

	extern s_tag_struct_definition cache_file_tag_resource_prediction_atom_block;

	extern s_tag_struct_definition cache_file_tag_resource_prediction_molecule_atom_reference_block;

	extern s_tag_struct_definition cache_file_tag_resource_prediction_molecule_block;

	extern s_tag_struct_definition cache_file_tag_resource_prediction_molecule_keys_block;

	extern s_tag_struct_definition cache_file_tag_resource_prediction_table;

	extern s_tag_struct_definition cache_file_bsp_attachment_block;

	extern s_tag_struct_definition cache_file_bsp_game_attachments_block_struct;

	extern s_tag_struct_definition cache_file_resource_gestalt_block_struct;

	extern s_tag_struct_definition cache_file_resource_layout_table_block_struct;

	extern s_tag_struct_definition sound_gestalt_codec_block;

	extern s_tag_struct_definition sound_gestalt_playback_block;

	extern s_tag_struct_definition sound_gestalt_scale_block;

	extern s_tag_struct_definition sound_gestalt_import_names_block;

	extern s_tag_struct_definition sound_gestalt_pitch_range_parameters_block;

	extern s_tag_struct_definition sound_gestalt_permutations_block;

	extern s_tag_struct_definition sound_gestalt_permutation_languages_block_struct;

	extern s_tag_struct_definition sound_gestalt_pitch_ranges_block;

	extern s_tag_struct_definition sound_gestalt_custom_playback_block;

	extern s_tag_struct_definition sound_gestalt_runtime_permutation_bit_vector_block;

	extern s_tag_struct_definition sound_gestalt_promotions_block;

	extern s_tag_struct_definition sound_gestalt_facial_animation_block;

	extern s_tag_struct_definition sound_gestalt_layer_markers_block;

	extern s_tag_struct_definition sound_cache_file_gestalt_struct_definition;

	extern s_tag_struct_definition cache_file_sound_struct_definition;

	extern s_tag_struct_definition platform_sound_playback_component_block_struct;
	extern s_string_list_definition platform_sound_playback_component_flags;

	extern s_tag_struct_definition platform_sound_playback_lowpass_block_struct;

	extern s_tag_struct_definition platform_sound_playback_struct;
	extern s_string_list_definition platform_sound_effect_flags_definition;
	extern s_tag_reference_definition sound_radio_settings_group_reference_tagref;

	extern s_tag_struct_definition platform_sound_playback_block_struct;

	extern s_tag_struct_definition sound_effect_collection_block_struct;

	extern s_tag_struct_definition sound_effect_template_parameter_block;
	extern s_string_list_definition sound_effect_template_type_enum_definition;
	extern s_string_list_definition sound_effect_template_parameter_flags_definition;

	extern s_tag_struct_definition sound_effect_template_additional_sound_input_block;

	extern s_tag_struct_definition sound_effect_template_struct_definition;

	extern s_tag_struct_definition sound_effect_templates_block;
	extern s_string_list_definition sound_effect_template_flags_definition;

	extern s_tag_struct_definition communication_sounds_struct_definition;

	extern s_tag_struct_definition megalogamengine_sounds_struct_definition;

	extern s_tag_struct_definition detail_object_type_block;
	extern s_string_list_definition detail_object_type_flags_definition;

	extern s_tag_struct_definition detail_object_collection_struct_definition;
	extern s_string_list_definition detail_object_collection_type_enum_definition;

	extern s_tag_struct_definition global_detail_object_cells_block;

	extern s_tag_struct_definition global_detail_object_block;

	extern s_tag_struct_definition global_detail_object_counts_block;

	extern s_tag_struct_definition global_z_reference_vector_block;

	extern s_tag_struct_definition scenario_description_block;

	extern s_tag_struct_definition multiplayer_scenario_description_struct_definition;

	extern s_tag_struct_definition decal_definition_block;
	extern s_string_list_definition decal_flags;
	extern s_string_list_definition decal_pass_enum;

	extern s_tag_struct_definition decal_system_struct_definition;
	extern s_string_list_definition decal_system_flags;
	extern s_tag_reference_definition decal_system_group_reference$2_tagref;

	extern s_tag_struct_definition sound_environment_block_struct;

	extern s_tag_struct_definition camo_scalar_function_struct;

	extern s_tag_struct_definition camo_struct_definition;
	extern s_string_list_definition camo_flags;

	extern s_tag_struct_definition shield_scalar_function_struct;

	extern s_tag_struct_definition shield_color_function_struct;

	extern s_tag_struct_definition shield_impact_struct_definition;
	extern s_string_list_definition shield_flags;

	extern s_tag_struct_definition cinematic_dynamic_light_block;
	extern s_string_list_definition cinematic_dynamic_light_flags;
	extern s_tag_reference_definition light_group_reference$2_tagref;

	extern s_tag_struct_definition new_cinematic_lighting_struct_definition;

	extern s_tag_struct_definition faux_data_cluster_data;

	extern s_tag_struct_definition faux_data_instance_data;

	extern s_tag_struct_definition faux_data_global_cluster_instance_data;

	extern s_tag_struct_definition faux_data_global_cluster_data;

	extern s_tag_struct_definition faux_data_global_instance_definition_data;

	extern s_tag_struct_definition faux_data_global_instance_data;

	extern s_tag_struct_definition faux_data_global_material_data;
	extern s_tag_reference_definition render_method_group_reference$5_tagref;

	extern s_tag_struct_definition faux_data_bsp_global_data;

	extern s_tag_struct_definition faux_data_object_data;

	extern s_tag_struct_definition faux_data_dual_vmf_terms_struct_definition;

	extern s_tag_struct_definition faux_data_airprobe_lightgroup_value;

	extern s_tag_struct_definition faux_data_scenery_probe_lightgroup_value;

	extern s_tag_struct_definition faux_data_device_probe_lightgroup_value;

	extern s_tag_struct_definition faux_data_device_probes_lightgroup_value;

	extern s_tag_struct_definition faux_data_lightmap_group_data;

	extern s_tag_struct_definition faux_data_airprobe_value;

	extern s_tag_struct_definition faux_data_scenery_probe_value;

	extern s_tag_struct_definition faux_data_device_machine_probe_value;

	extern s_tag_struct_definition faux_data_device_machine_probes_value;

	extern s_tag_struct_definition scenario_faux_data_struct_definition;

	extern s_tag_struct_definition sound_combiner_definition_entry_block;

	extern s_tag_struct_definition sound_combiner_block_struct;

	extern s_tag_struct_definition particle_emitter_boat_hull_group_block;

	extern s_tag_struct_definition particle_emitter_boat_hull_shape_struct_definition;
	extern s_string_list_definition particle_emitter_boat_hull_distribution_type;

	extern s_tag_struct_definition particle_emitter_custom_point_block;

	extern s_tag_struct_definition particle_emitter_custom_points_struct_definition;
	extern s_tag_reference_definition particle_model_group_reference_tagref;

	extern s_tag_struct_definition fx_test_scalar_function_struct;

	extern s_tag_struct_definition fx_property_default_block;

	extern s_tag_struct_definition fx_property_block;
	extern s_string_list_definition fx_property_flags;
	extern s_string_list_definition fx_property_value_type_enum;
	extern s_string_list_definition fx_property_bitmap_filter_enum;
	extern s_string_list_definition fx_property_bitmap_address_enum;
	extern s_string_list_definition fx_property_bitmap_bias_enum;

	extern s_tag_struct_definition fx_test_struct_definition;

	extern s_tag_struct_definition bolt_definition_block;
	extern s_string_list_definition bolt_flags;

	extern s_tag_struct_definition lightning_system_struct_definition;

	extern s_tag_struct_definition beam_property_real;
	extern s_string_list_definition beam_state_input_enum;
	extern s_string_list_definition output_mod_enum;

	extern s_tag_struct_definition beam_property_real_rgb_color;

	extern s_tag_struct_definition beam_definition_block;
	extern s_string_list_definition beam_appearance_flags;
	extern s_string_list_definition beam_profile_shape_enum;

	extern s_tag_struct_definition beam_system_struct_definition;

	extern s_tag_struct_definition beam_property_real_point2d;

	extern s_tag_struct_definition contrail_property_scalar;
	extern s_string_list_definition contrail_state_input_enum;
	extern s_string_list_definition output_mod_enum$3;

	extern s_tag_struct_definition contrail_property_color;

	extern s_tag_struct_definition contrail_definition_block;
	extern s_string_list_definition contrail_appearance_flags;
	extern s_string_list_definition contrail_profile_shape_enum;

	extern s_tag_struct_definition contrail_system_struct_definition;

	extern s_tag_struct_definition contrail_property_real_vector3d;

	extern s_tag_struct_definition contrail_property_real_point2d;

	extern s_tag_struct_definition color_block;

	extern s_tag_struct_definition color_table_struct_definition;

	extern s_tag_struct_definition bitmap_texture_interop_resource_struct;

	extern s_tag_struct_definition bitmap_texture_interop_block_struct;

	extern s_tag_struct_definition bitmap_texture_interleaved_interop_resource_struct;

	extern s_tag_struct_definition bitmap_texture_interleaved_interop_block_struct;

	extern s_tag_struct_definition bitmap_block_struct;
	extern s_string_list_definition bitmap_usage_global_enum;
	extern s_string_list_definition bitmap_group_flags_def;
	extern s_string_list_definition bitmap_curve_override_enum;
	extern s_string_list_definition bitmap_usage_format_def;

	extern s_tag_struct_definition structure_design_block_struct;

	extern s_tag_struct_definition spring_linear_acceleration_block;

	extern s_tag_struct_definition spring_acceleration_struct_definition;

	extern s_tag_struct_definition game_performance_throttle_filter_struct;

	extern s_tag_struct_definition game_performance_throttle_profile_struct;

	extern s_tag_struct_definition game_performance_throttle_entries_block;

	extern s_tag_struct_definition game_performance_throttle_struct_definition;

	extern s_tag_struct_definition collision_model_material_block;

	extern s_tag_struct_definition collision_model_region_block;

	extern s_tag_struct_definition collision_model_pathfinding_sphere_block;
	extern s_string_list_definition pathfinding_sphere_flags;

	extern s_tag_struct_definition collision_model_bsp_block;

	extern s_tag_struct_definition collision_model_struct_definition;
	extern s_string_list_definition collision_model_flags;

	extern s_tag_struct_definition collision_model_permutation_block;

	extern s_tag_struct_definition collision_model_node_block;

	extern s_tag_struct_definition instance_imposter_block;
	extern s_string_list_definition instance_imposter_element_flags_definition;

	extern s_tag_struct_definition instance_imposter_checksum_block;

	extern s_tag_struct_definition instance_imposter_definition_struct_definition;
	extern s_string_list_definition instance_imposter_flags_definition;

	extern s_tag_struct_definition bitmap_usage_block;
	extern s_string_list_definition bitmap_curve_enum;
	extern s_string_list_definition bitmap_usage_flags_def;
	extern s_string_list_definition bitmap_usage_slicer_def;
	extern s_string_list_definition bitmap_usage_dicer_flags_def;
	extern s_string_list_definition bitmap_usage_packer_def;
	extern s_string_list_definition bitmap_usage_packer_flags_def;
	extern s_string_list_definition bitmap_types;
	extern s_string_list_definition bitmap_smallest_mip_def;
	extern s_string_list_definition bitmap_usage_downsample_filter_def;
	extern s_string_list_definition bitmap_usage_downsample_flags_def;
	extern s_string_list_definition bitmap_usage_swizzle_def;

	extern s_tag_struct_definition particle_property_scalar_struct_new;
	extern s_string_list_definition output_mod_enum$2;
	extern s_string_list_definition force_flags_definition;

	extern s_tag_struct_definition particle_property_color_struct_new;

	extern s_tag_struct_definition particle_property_real_point3d_struct_new;

	extern s_tag_struct_definition particle_property_real_vector3d_struct_new;

	extern s_tag_struct_definition property_editable_vector3d_interpolator;

	extern s_tag_struct_definition particle_property_real_vector3d_spherical_struct_new;

	extern s_tag_struct_definition camera_block;

	extern s_tag_struct_definition global_geometry_material_block;
	extern s_tag_reference_definition render_method_group_reference$2_tagref;
	extern s_string_list_definition global_geometry_material_lightmap_flags;

	extern s_tag_struct_definition global_self_track_block;

	extern s_tag_struct_definition error_point_node_index_array_struct_definition;

	extern s_tag_struct_definition error_point_node_weight_array_struct_definition;

	extern s_tag_struct_definition error_report_point_definition;

	extern s_tag_struct_definition error_report_vertices_block;

	extern s_tag_struct_definition error_report_vectors_block;

	extern s_tag_struct_definition error_report_line_point_array_struct_definition;

	extern s_tag_struct_definition error_report_lines_block;

	extern s_tag_struct_definition error_report_triangle_point_array_struct_definition;

	extern s_tag_struct_definition error_report_triangles_block;

	extern s_tag_struct_definition error_report_quad_point_array_struct_definition;

	extern s_tag_struct_definition error_report_quads_block;

	extern s_tag_struct_definition error_report_comments_block;

	extern s_tag_struct_definition error_reports_block;
	extern s_string_list_definition error_report_types;
	extern s_string_list_definition error_report_source;
	extern s_string_list_definition error_report_flags;

	extern s_tag_struct_definition global_error_report_categories_block;

	extern s_tag_struct_definition collision_geometry_shape_struct;

	extern s_tag_struct_definition mopp_bv_tree_shape_struct;

	extern s_tag_struct_definition collision_bsp_physics_block;

	extern s_tag_struct_definition supported_bitfield_struct_definition;

	extern s_tag_struct_definition breakable_surface_set_block;

	extern s_tag_struct_definition bsp3d_nodes_block_struct;

	extern s_tag_struct_definition bsp3d_kd_supdernodes_block;

	extern s_tag_struct_definition planes_block;

	extern s_tag_struct_definition collision_leaf_struct;
	extern s_string_list_definition leaf_flags;

	extern s_tag_struct_definition bsp2d_references_block;

	extern s_tag_struct_definition bsp2d_nodes_block;

	extern s_tag_struct_definition surfaces_block_struct;
	extern s_string_list_definition surface_flags;

	extern s_tag_struct_definition edges_block;

	extern s_tag_struct_definition vertices_block;

	extern s_tag_struct_definition global_collision_bsp_struct;

	extern s_tag_struct_definition global_collision_bsp_block;

	extern s_tag_struct_definition large_bsp3d_nodes_block;

	extern s_tag_struct_definition large_leaves_block;

	extern s_tag_struct_definition large_bsp2d_references_block;

	extern s_tag_struct_definition large_bsp2d_nodes_block;

	extern s_tag_struct_definition large_surfaces_block_struct;

	extern s_tag_struct_definition large_edges_block;

	extern s_tag_struct_definition large_vertices_block;

	extern s_tag_struct_definition global_large_collision_bsp_block;

	extern s_tag_struct_definition structure_soft_ceiling_triangle_block;

	extern s_tag_struct_definition structure_soft_ceiling_block;

	extern s_tag_struct_definition breakable_surface_key_table_block;

	extern s_tag_struct_definition structure_water_groups_block;

	extern s_tag_struct_definition structure_water_instance_planes_block;

	extern s_tag_struct_definition structure_water_instance_debug_triangles_block;

	extern s_tag_struct_definition structure_water_instances_block;

	extern s_tag_struct_definition soft_surfaces_definition_block;

	extern s_tag_struct_definition global_structure_physics_struct;

	extern s_tag_struct_definition global_structure_physics_design_struct;

	extern s_tag_struct_definition global_decorator_placement_block;
	extern s_string_list_definition decorator_placement_flags_definition;

	extern s_tag_struct_definition decorator_scenario_set_block;

	extern s_tag_struct_definition decorator_palette;

	extern s_tag_struct_definition decorator_brush_struct;
	extern s_string_list_definition decorator_left_brush_type_enum_definition;
	extern s_string_list_definition decorator_right_brush_type_enum_definition;
	extern s_string_list_definition decorator_brush_reapply_flags_definition;
	extern s_string_list_definition decorator_brush_render_flags_definition;
	extern s_string_list_definition decorator_brush_action_flags_definition;
	extern s_string_list_definition decorator_brush_shape_enum_definition;

	extern s_tag_struct_definition scenario_decorator_block;

	extern s_tag_struct_definition scenario_zone_debugger_block_definition_struct;

	extern s_tag_struct_definition hs_script_parameters_block;
	extern s_string_list_definition hs_types_enum;

	extern s_tag_struct_definition hs_scripts_block;
	extern s_string_list_definition hs_script_types_enum;

	extern s_tag_struct_definition hs_globals_block;

	extern s_tag_struct_definition hs_references_block;
	extern s_tag_reference_definition _reference$12_tagref;

	extern s_tag_struct_definition hs_source_files_block;
	extern s_string_list_definition hs_source_file_flags;

	extern s_tag_struct_definition hs_syntax_datum_block;

	extern s_tag_struct_definition hs_unit_seat_block;

	extern s_tag_struct_definition named_location_volume_point_block;

	extern s_tag_struct_definition scenario_named_location_volume_block_struct;

	extern s_tag_struct_definition recorded_animation_block;

	extern s_tag_struct_definition map_variant_object_variant_block;
	extern s_tag_reference_definition object_group_reference$7_tagref;

	extern s_tag_struct_definition map_variant_palette_entry_block;

	extern s_tag_struct_definition map_variant_palette_block;
	extern s_string_list_definition map_variant_palette_flags;

	extern s_tag_struct_definition door_encoded_pas_block;

	extern s_tag_struct_definition room_door_portal_encoded_pas_block;

	extern s_tag_struct_definition ai_deafening_encoded_pas_block;

	extern s_tag_struct_definition encoded_room_distances_block;

	extern s_tag_struct_definition game_portal_to_door_occluder_block;

	extern s_tag_struct_definition bsp_cluster_to_room_bounds;

	extern s_tag_struct_definition bsp_cluster_to_room_indices;

	extern s_tag_struct_definition game_audibility_block;

	extern s_tag_struct_definition biped_block_index_flags_block_struct;

	extern s_tag_struct_definition vehicle_block_index_flags_block_struct;

	extern s_tag_struct_definition weapon_block_index_flags_block_struct;

	extern s_tag_struct_definition equipment_block_index_flags_block_struct;

	extern s_tag_struct_definition scenery_block_index_flags_block_struct;

	extern s_tag_struct_definition machine_block_index_flags_block_struct;

	extern s_tag_struct_definition terminal_block_index_flags_block_struct;

	extern s_tag_struct_definition control_block_index_flags_block_struct;

	extern s_tag_struct_definition sound_scenery_block_index_flags_block_struct;

	extern s_tag_struct_definition crate_block_index_flags_block_struct;

	extern s_tag_struct_definition creature_block_index_flags_block_struct;

	extern s_tag_struct_definition giant_block_index_flags_block_struct;

	extern s_tag_struct_definition effect_scenery_block_index_flags_block_struct;

	extern s_tag_struct_definition character_block_index_flags_block_struct;

	extern s_tag_struct_definition budget_reference_block_index_flags_block_struct;

	extern s_tag_struct_definition scenario_designer_zone_block;
	extern s_string_list_definition scenario_designer_zone_flags_definition;

	extern s_tag_struct_definition structure_device_portal_association_block;

	extern s_tag_struct_definition game_portal_to_portal_mapping_block;

	extern s_tag_struct_definition occluding_portal_to_portal_mapping_block;

	extern s_tag_struct_definition structure_portal_device_mapping_block;

	extern s_tag_struct_definition g_scenario_editor_folder_block;

	extern s_tag_struct_definition structure_sound_cluster_portal_designators;

	extern s_tag_struct_definition structure_sound_cluster_interior_cluster_indices;

	extern s_tag_struct_definition structure_bsp_sound_cluster_block;

	extern s_tag_struct_definition object_type_drag_properties_block;
	extern s_tag_reference_definition water_physics_drag_properties_group_reference_tagref;

	extern s_tag_struct_definition materials_sweeteners_struct;
	extern s_tag_reference_definition render_water_ripple_group_reference_tagref;
	extern s_string_list_definition materials_sweeteners_inheritance_flags;

	extern s_tag_struct_definition underwater_proxies_block;

	extern s_tag_struct_definition wet_proxies_struct;

	extern s_tag_struct_definition materials_block$2;
	extern s_string_list_definition global_material_flags_definition;
	extern s_tag_reference_definition breakable_surface_group_reference_tagref;

	extern s_tag_struct_definition runtime_materials_block;

	extern s_tag_struct_definition material_physics_properties_struct;

	extern s_tag_struct_definition active_camo_level_definition_block;

	extern s_tag_struct_definition active_camo_globals_block;

	extern s_tag_struct_definition damage_decay_struct;

	extern s_tag_struct_definition damage_globals_block;

	extern s_tag_struct_definition shield_boost_block;

	extern s_tag_struct_definition armor_modifier_block;

	extern s_tag_struct_definition damage_group_block;

	extern s_tag_struct_definition game_globals_damage_block;

	extern s_tag_struct_definition interface_tag_references;
	extern s_tag_reference_definition color_table_group_reference_tagref;
	extern s_tag_reference_definition user_interface_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition chud_globals_definition_group_reference_tagref;

	extern s_tag_struct_definition difficulty_block;

	extern s_tag_struct_definition coop_difficulty_block_struct;

	extern s_tag_struct_definition game_mode_flags_struct;
	extern s_string_list_definition game_type_enum_definition;
	extern s_string_list_definition game_matchmaking_flags_definition;
	extern s_string_list_definition game_player_count_flags_definition;

	extern s_tag_struct_definition sound_permutation_language_info;

	extern s_tag_struct_definition sound_pitch_range_language_info;

	extern s_tag_struct_definition sound_language_info_block;

	extern s_tag_struct_definition boat_physics_definition_struct;

	extern s_tag_struct_definition sound_response_definition_struct;
	extern s_string_list_definition game_engine_sound_response_flags_definition;

	extern s_tag_struct_definition sound_response_definition_block;

	extern s_tag_struct_definition game_engine_event_block_struct;
	extern s_string_list_definition game_engine_event_audience_enum_definition;
	extern s_string_list_definition game_engine_event_response_context_enum_definition;
	extern s_string_list_definition game_engine_event_input_enum_definition;
	extern s_string_list_definition game_engine_event_splitscreen_suppression_enum_definition;
	extern s_string_list_definition game_engine_event_flags_definition;

	extern s_tag_struct_definition game_incident_daily_challenge_to_increment_block;

	extern s_tag_struct_definition game_incident_response_block_struct;

	extern s_tag_struct_definition bitmap_data_block_def;
	extern s_string_list_definition bitmap_more_flags_definition;
	extern s_string_list_definition bitmap_formats;
	extern s_string_list_definition bitmap_flags;

	extern s_tag_struct_definition bitmap_tight_bounds_block_def;

	extern s_tag_struct_definition bitmap_group_sprite_block_def;

	extern s_tag_struct_definition bitmap_group_sequence_block_def;

	extern s_tag_struct_definition render_texture_interop_definition_struct;
	extern s_string_list_definition boolean_enum_definition;

	extern s_tag_struct_definition render_texture_format_definition;

	extern s_tag_struct_definition render_texture_interleaved_interop_definition_struct;

	extern s_tag_struct_definition ai_spawn_conditions_struct;

	extern s_tag_struct_definition character_voice_region_permutation_filter_block_struct;

	extern s_tag_struct_definition character_voice_region_filter_block_struct;

	extern s_tag_struct_definition character_voice_block;
	extern s_tag_reference_definition dialogue_group_reference$2_tagref;

	extern s_tag_struct_definition character_variants_block;

	extern s_tag_struct_definition character_voice_properties_block;

	extern s_tag_struct_definition disallowed_weapons_for_trading_block;
	extern s_tag_reference_definition weapon_group_reference$4_tagref;

	extern s_tag_struct_definition character_general_block;
	extern s_string_list_definition general_flags;
	extern s_string_list_definition actor_type_enum;
	extern s_string_list_definition combat_positioning_enum;
	extern s_string_list_definition global_ai_grenade_type_enum;
	extern s_string_list_definition behavior_tree_root_enum;

	extern s_tag_struct_definition character_interact_block;

	extern s_tag_struct_definition character_emotions_situational_danger_block;
	extern s_string_list_definition prop_class_enum;

	extern s_tag_struct_definition character_emotions_block;

	extern s_tag_struct_definition character_placement_block;

	extern s_tag_struct_definition character_vitality_block;
	extern s_string_list_definition vitality_flags;
	extern s_tag_reference_definition weapon_group_reference$5_tagref;

	extern s_tag_struct_definition active_camo_perception_properties;

	extern s_tag_struct_definition character_perception_block_struct;
	extern s_string_list_definition actor_perception_mode_definition;
	extern s_string_list_definition perception_flags;

	extern s_tag_struct_definition character_target_block_struct;

	extern s_tag_struct_definition character_look_block;

	extern s_tag_struct_definition movement_stationary_pause_block;

	extern s_tag_struct_definition movement_throttle_block;

	extern s_tag_struct_definition movement_throttle_control_block;
	extern s_string_list_definition combat_status_enum_definition;
	extern s_string_list_definition movement_throttle_control_flags;

	extern s_tag_struct_definition character_movement_block;
	extern s_string_list_definition movement_flags;
	extern s_string_list_definition obstacle_ignore_enum;
	extern s_string_list_definition movement_hint_enum;

	extern s_tag_struct_definition character_throttle_style_block;

	extern s_tag_struct_definition movement_mapping_block;

	extern s_tag_struct_definition character_movement_set_block;

	extern s_tag_struct_definition character_flocking_block;

	extern s_tag_struct_definition character_swarm_block;

	extern s_tag_struct_definition evaluator_definition_block_struct;
	extern s_string_list_definition evaluator_enum;

	extern s_tag_struct_definition character_firing_point_evaluator_block_struct;
	extern s_string_list_definition evaluation_modes;

	extern s_tag_struct_definition character_engage_block;
	extern s_string_list_definition engage_flags;
	extern s_tag_reference_definition projectile_group_reference_tagref;

	extern s_tag_struct_definition character_evasion_block;

	extern s_tag_struct_definition character_cover_block;
	extern s_string_list_definition cover_flags;

	extern s_tag_struct_definition character_search_block;
	extern s_string_list_definition character_search_flags;

	extern s_tag_struct_definition character_presearch_block;
	extern s_string_list_definition generic_flags;

	extern s_tag_struct_definition character_retreat_block;
	extern s_string_list_definition character_retreat_flags;

	extern s_tag_struct_definition character_charge_difficulty_limits_block;

	extern s_tag_struct_definition character_charge_block;
	extern s_string_list_definition charge_flags;

	extern s_tag_struct_definition character_ready_block;

	extern s_tag_struct_definition character_weapons_block;
	extern s_string_list_definition weapon_flags;
	extern s_string_list_definition actor_special_fire_mode_enum;
	extern s_string_list_definition actor_special_fire_situation_enum;
	extern s_tag_reference_definition damage_effect_group_reference$2_tagref;

	extern s_tag_struct_definition character_firing_pattern_block;

	extern s_tag_struct_definition character_firing_pattern_properties_block;

	extern s_tag_struct_definition character_grenades_block;
	extern s_string_list_definition grenades_flags;
	extern s_string_list_definition actor_grenade_trajectory_enum;

	extern s_tag_struct_definition character_vehicle_block;
	extern s_tag_reference_definition unit_group_reference$2_tagref;
	extern s_tag_reference_definition style_group_reference$2_tagref;
	extern s_string_list_definition vehicle_flags;

	extern s_tag_struct_definition character_flying_movement_block_struct;

	extern s_tag_struct_definition character_idle_block;

	extern s_tag_struct_definition character_vocalization_block;

	extern s_tag_struct_definition character_vehicle_boarding_block;
	extern s_string_list_definition vehicle_boarding_flags;

	extern s_tag_struct_definition character_boarding_block;
	extern s_string_list_definition boarding_flags;

	extern s_tag_struct_definition character_kungfu_block;

	extern s_tag_struct_definition character_bunker_timings_struct;

	extern s_tag_struct_definition character_bunker_block;

	extern s_tag_struct_definition character_guardian_block;

	extern s_tag_struct_definition character_combatform_block;

	extern s_tag_struct_definition character_engineer_block;
	extern s_tag_reference_definition equipment_group_reference$2_tagref;

	extern s_tag_struct_definition character_inspect_block;

	extern s_tag_struct_definition character_scarab_block;

	extern s_tag_struct_definition character_morph_block;
	extern s_tag_reference_definition character_group_reference$4_tagref;
	extern s_tag_reference_definition muffin_group_reference$2_tagref;

	extern s_tag_struct_definition character_equipment_usage_block;
	extern s_string_list_definition character_equipment_usage_when_enum;
	extern s_string_list_definition character_equipment_usage_how_enum;

	extern s_tag_struct_definition character_equipment_block;
	extern s_string_list_definition character_equipment_flags;

	extern s_tag_struct_definition character_stimuli_response_block;

	extern s_tag_struct_definition character_activity_object_block;
	extern s_tag_reference_definition crate_group_reference$3_tagref;

	extern s_tag_struct_definition character_pain_screen_block;

	extern s_tag_struct_definition character_struct_definition;
	extern s_string_list_definition character_flags;
	extern s_tag_reference_definition unit_group_reference_tagref;
	extern s_tag_reference_definition creature_group_reference$2_tagref;

	extern s_tag_struct_definition ai_globals_gravemind_block;

	extern s_tag_struct_definition ai_globals_formation_block;
	extern s_tag_reference_definition formation_group_reference_tagref;

	extern s_tag_struct_definition ai_globals_squad_template_block;
	extern s_tag_reference_definition squad_template_group_reference_tagref;

	extern s_tag_struct_definition ai_globals_squad_template_sub_folder_block_struct;

	extern s_tag_struct_definition ai_globals_squad_template_folder_block_struct;

	extern s_tag_struct_definition ai_globals_performance_template_block;
	extern s_tag_reference_definition performance_template_group_reference_tagref;

	extern s_tag_struct_definition ai_globals_performance_template_sub_folder_block_struct;

	extern s_tag_struct_definition ai_globals_performance_template_folder_block_struct;

	extern s_tag_struct_definition ai_globals_custom_stimuli_block;

	extern s_tag_struct_definition ai_trait_vision_block_struct;

	extern s_tag_struct_definition ai_trait_sound_block_struct;

	extern s_tag_struct_definition ai_trait_luck_block_struct;

	extern s_tag_struct_definition ai_trait_grenade_block_struct;

	extern s_tag_struct_definition ai_globals_data_block_struct;
	extern s_tag_reference_definition ai_dialogue_globals_group_reference_tagref;

	extern s_tag_struct_definition ai_globals_struct_definition;

	extern s_tag_struct_definition character_palette_block;
	extern s_tag_reference_definition character_group_reference_tagref;

	extern s_tag_struct_definition big_battle_creature_palette_block;
	extern s_tag_reference_definition big_battle_creature_group_reference_tagref;

	extern s_tag_struct_definition ai_recording_reference_block;

	extern s_tag_struct_definition user_hint_line_segment_block;
	extern s_string_list_definition user_hint_geometry_flags;

	extern s_tag_struct_definition user_hint_parallelogram_block;
	extern s_string_list_definition parallelogram_points_invalid_flags;

	extern s_tag_struct_definition user_hint_jump_block;
	extern s_string_list_definition jump_flags;

	extern s_tag_struct_definition user_hint_climb_block;
	extern s_string_list_definition forced_hoist_height_enum;

	extern s_tag_struct_definition user_hint_well_point_block;
	extern s_string_list_definition user_hint_well_point_type_enum;

	extern s_tag_struct_definition user_hint_well_block;
	extern s_string_list_definition user_hint_well_geometry_flags;

	extern s_tag_struct_definition user_hint_flight_point_block;

	extern s_tag_struct_definition user_hint_flight_block;

	extern s_tag_struct_definition user_hint_volume_avoidance_struct;
	extern s_string_list_definition user_hint_avoidance_volume_enum;

	extern s_tag_struct_definition user_hint_spline_control_point_block_struct;
	extern s_string_list_definition user_hint_spline_segment_flags;

	extern s_tag_struct_definition user_hint_spline_intersect_point_block_struct;

	extern s_tag_struct_definition user_hint_spline_block;

	extern s_tag_struct_definition user_hint_sector_point_block;

	extern s_tag_struct_definition user_hint_cookie_cutter_block_struct;

	extern s_tag_struct_definition user_hint_flood_sector_block;

	extern s_tag_struct_definition user_hint_giant_sector_block;

	extern s_tag_struct_definition user_hint_giant_rail_block;

	extern s_tag_struct_definition user_hint_flood_block;

	extern s_tag_struct_definition user_hint_giant_block;

	extern s_tag_struct_definition user_hint_block;

	extern s_tag_struct_definition pathfinding_hints_block;
	extern s_string_list_definition hint_type_enum;

	extern s_tag_struct_definition special_movement_block;
	extern s_string_list_definition special_movement_flags;

	extern s_tag_struct_definition ai_reference_frame_block;
	extern s_string_list_definition ai_reference_frame_flags;

	extern s_tag_struct_definition wave_squad_specification_struct_struct;
	extern s_tag_reference_definition squad_template_group_reference$2_tagref;
	extern s_string_list_definition wave_placement_filter_enum;

	extern s_tag_struct_definition wave_template_block_struct;

	extern s_tag_struct_definition patrol_point_block;
	extern s_string_list_definition patrol_point_flags;
	extern s_string_list_definition g_activity_enum;

	extern s_tag_struct_definition spawn_points_block_struct;
	extern s_string_list_definition starting_location_flags;
	extern s_string_list_definition ai_placement_seat_preference_enum;
	extern s_string_list_definition actor_movement_modes;
	extern s_string_list_definition patrol_mode_enum;

	extern s_tag_struct_definition spawn_formation_block_struct;

	extern s_tag_struct_definition character_palette_choice_block_struct;

	extern s_tag_struct_definition weapon_palette_choice_block_struct;

	extern s_tag_struct_definition equipment_palette_choice_block_struct;

	extern s_tag_struct_definition cell_block_struct;
	extern s_string_list_definition major_upgrade_enum;

	extern s_tag_struct_definition squad_groups_block;

	extern s_tag_struct_definition squad_definition_internal_struct;

	extern s_tag_struct_definition squads_block_struct;
	extern s_string_list_definition squad_flags;
	extern s_string_list_definition ai_team_enum;

	extern s_tag_struct_definition character_ref_choice_block_struct;
	extern s_tag_reference_definition character_group_reference$6_tagref;

	extern s_tag_struct_definition weapon_ref_choice_block_struct;
	extern s_tag_reference_definition weapon_group_reference$9_tagref;

	extern s_tag_struct_definition equipment_ref_choice_block_struct;
	extern s_tag_reference_definition equipment_group_reference$6_tagref;

	extern s_tag_struct_definition cell_template_block_struct;
	extern s_tag_reference_definition vehicle_group_reference$4_tagref;

	extern s_tag_struct_definition squad_template_block_struct;

	extern s_tag_struct_definition formation_point_definition;

	extern s_tag_struct_definition formation_primitive_definition;
	extern s_string_list_definition formation_primitive_flags;

	extern s_tag_struct_definition formation_block_struct;

	extern s_tag_struct_definition flock_palette_block;
	extern s_tag_reference_definition flock_group_reference_tagref;

	extern s_tag_struct_definition flock_source_block;
	extern s_string_list_definition flock_source_flags;

	extern s_tag_struct_definition flock_destination_block;
	extern s_string_list_definition destination_type_enum;

	extern s_tag_struct_definition flock_instance_block;
	extern s_string_list_definition flock_flags;

	extern s_tag_struct_definition flock_struct_definition;

	extern s_tag_struct_definition mission_dialogue_variants_block;
	extern s_tag_reference_definition sound_group_reference$2_tagref;

	extern s_tag_struct_definition mission_dialogue_lines_block;

	extern s_tag_struct_definition ai_mission_dialogue_struct_definition;

	extern s_tag_struct_definition ai_scene_role_variants_block;

	extern s_tag_struct_definition ai_scene_role_block;
	extern s_string_list_definition role_group_enum;

	extern s_tag_struct_definition ai_scene_trigger_block;
	extern s_string_list_definition combination_rules_enum;

	extern s_tag_struct_definition ai_scene_block;
	extern s_string_list_definition scene_flags;

	extern s_tag_struct_definition ai_scenario_mission_dialogue_block;
	extern s_tag_reference_definition ai_mission_dialogue_group_reference_tagref;

	extern s_tag_struct_definition response_block;
	extern s_string_list_definition response_flags;
	extern s_string_list_definition response_type_enum;

	extern s_tag_struct_definition vocalization_definitions_block;
	extern s_string_list_definition priority_enum;
	extern s_string_list_definition vocalization_flags_definition;
	extern s_string_list_definition glance_type_enum;
	extern s_string_list_definition perception_type_enum;
	extern s_string_list_definition combat_status_enum;
	extern s_string_list_definition dialogue_animation_enum;
	extern s_string_list_definition dialogue_emotion_enum;

	extern s_tag_struct_definition vocalization_patterns_block;
	extern s_string_list_definition dialogue_names_enum;
	extern s_string_list_definition speaker_type_enum;
	extern s_string_list_definition hostility_enum;
	extern s_string_list_definition pattern_flags;
	extern s_string_list_definition dialogue_object_types_enum;
	extern s_string_list_definition speaker_behavior_enum;
	extern s_string_list_definition danger_enum;
	extern s_string_list_definition spatial_relation_enum;
	extern s_string_list_definition dialogue_condition_flags;
	extern s_string_list_definition damage_enum;
	extern s_string_list_definition game_type_enum;

	extern s_tag_struct_definition dialogue_data_block;

	extern s_tag_struct_definition involuntary_data_block;

	extern s_tag_struct_definition predicted_data_block;

	extern s_tag_struct_definition default_stimulus_suppressor_block_struct;

	extern s_tag_struct_definition ai_dialogue_globals_struct_definition;

	extern s_tag_struct_definition behavior_names_block;

	extern s_tag_struct_definition style_struct_definition;
	extern s_string_list_definition combat_status_enum$2;
	extern s_string_list_definition style_control_flags;
	extern s_string_list_definition behavior_set1;
	extern s_string_list_definition behavior_set2;
	extern s_string_list_definition behavior_set3;
	extern s_string_list_definition behavior_set4;
	extern s_string_list_definition behavior_set5;
	extern s_string_list_definition behavior_set6;
	extern s_string_list_definition behavior_set7;
	extern s_string_list_definition behavior_set8;

	extern s_tag_struct_definition style_palette_block;
	extern s_tag_reference_definition style_group_reference_tagref;

	extern s_tag_struct_definition order_completion_condition;
	extern s_string_list_definition condition_type_enum;
	extern s_string_list_definition completion_condition_flags;

	extern s_tag_struct_definition triggers_block;
	extern s_string_list_definition trigger_flags;

	extern s_tag_struct_definition trigger_references;
	extern s_string_list_definition trigger_ref_flags;

	extern s_tag_struct_definition secondary_set_trigger_block;
	extern s_string_list_definition order_ending_dialogue_enum;

	extern s_tag_struct_definition orders_block;
	extern s_string_list_definition order_flags;
	extern s_string_list_definition force_combat_status_enum;

	extern s_tag_struct_definition order_ending_block;

	extern s_tag_struct_definition cs_point_block_struct;

	extern s_tag_struct_definition cs_point_set_block;
	extern s_string_list_definition point_set_flags;

	extern s_tag_struct_definition cs_script_data_block;

	extern s_tag_struct_definition sector_link_block;
	extern s_string_list_definition sector_link_flags;

	extern s_tag_struct_definition sector_vertex_block;

	extern s_tag_struct_definition sector_block;
	extern s_string_list_definition sector_flags;

	extern s_tag_struct_definition ref_block;

	extern s_tag_struct_definition sector_bsp2d_nodes_block;

	extern s_tag_struct_definition environment_object_bsp_refs;

	extern s_tag_struct_definition environment_object_refs;
	extern s_string_list_definition environment_object_flags;

	extern s_tag_struct_definition instanced_geometry_reference_block;

	extern s_tag_struct_definition giant_pathfinding_data_block;

	extern s_tag_struct_definition pf_seam_link_block;

	extern s_tag_struct_definition pf_seam_block;

	extern s_tag_struct_definition pf_jump_index_block;

	extern s_tag_struct_definition pf_jump_seam_block;

	extern s_tag_struct_definition pf_door_block;

	extern s_tag_struct_definition pathfinding_data_block;

	extern s_tag_struct_definition firing_point_payload_block_struct;

	extern s_tag_struct_definition script_payload_block_struct;

	extern s_tag_struct_definition combat_sync_action_group_payload_block_struct;

	extern s_tag_struct_definition stimulus_payload_block_struct;

	extern s_tag_struct_definition combat_cue_payload_block_struct;
	extern s_string_list_definition g_firing_position_flags;
	extern s_string_list_definition g_firing_position_posture_flags;
	extern s_string_list_definition combat_cue_preference_enum;

	extern s_tag_struct_definition cue_payload_struct;

	extern s_tag_struct_definition task_distribution_block_struct;

	extern s_tag_struct_definition radial_distribution_block_struct;

	extern s_tag_struct_definition probability_distribution_block_struct;

	extern s_tag_struct_definition character_distribution_block_struct;
	extern s_string_list_definition distribution_character_flags;

	extern s_tag_struct_definition weapon_distribution_block_struct;

	extern s_tag_struct_definition cue_stimulus_distribution_struct;

	extern s_tag_struct_definition cue_distribution_struct;

	extern s_tag_struct_definition ai_cue_block_struct;
	extern s_string_list_definition cue_flags;

	extern s_tag_struct_definition ai_full_cue_block_struct;

	extern s_tag_struct_definition ai_quick_cue_block_struct;
	extern s_string_list_definition quick_cue_flags;

	extern s_tag_struct_definition ai_cue_template_block_struct;

	extern s_tag_struct_definition squad_patrol_member_block;

	extern s_tag_struct_definition squad_patrol_point_block;

	extern s_tag_struct_definition squad_patrol_waypoint_block;

	extern s_tag_struct_definition squad_patrol_transition_block;

	extern s_tag_struct_definition squad_patrol_block;

	extern s_tag_struct_definition flight_reference_block;

	extern s_tag_struct_definition area_cluster_occupancy_bitvector_array_struct_definition;

	extern s_tag_struct_definition area_sector_point_block;

	extern s_tag_struct_definition areas_block_struct;
	extern s_string_list_definition area_flags;
	extern s_string_list_definition generate_preset_enum;
	extern s_string_list_definition generate_flags;

	extern s_tag_struct_definition zone_block;
	extern s_string_list_definition zone_flags;

	extern s_tag_struct_definition script_fragment_block;
	extern s_string_list_definition fragment_state_enum;

	extern s_tag_struct_definition task_direction_point_block;

	extern s_tag_struct_definition task_direction_block_v2_struct;

	extern s_tag_struct_definition zone_set_block_struct;
	extern s_string_list_definition zone_set_type_enum;
	extern s_string_list_definition zone_set_flags;

	extern s_tag_struct_definition tasks_block_struct;
	extern s_string_list_definition task_flags_definition;
	extern s_string_list_definition inhibit_behavior_flags;
	extern s_string_list_definition task_movement_enum;
	extern s_string_list_definition task_follow_enum;
	extern s_string_list_definition task_follow_player_flags;
	extern s_string_list_definition task_dialogue_enum;
	extern s_string_list_definition task_runtime_flags;
	extern s_string_list_definition filter_flags;
	extern s_string_list_definition filter_enum;
	extern s_string_list_definition task_attitude_enum;

	extern s_tag_struct_definition objectives_block;
	extern s_string_list_definition objective_flags;

	extern s_tag_struct_definition opposing_objective_block;

	extern s_tag_struct_definition firing_positions_block;

	extern s_tag_struct_definition emblem_bitmap_list;

	extern s_tag_struct_definition emblem_transform;

	extern s_tag_struct_definition emblem_shape_list;

	extern s_tag_struct_definition emblem_layer;

	extern s_tag_struct_definition emblem_front_list;
	extern s_string_list_definition front_emblem_primary_layer;

	extern s_tag_struct_definition emblem_back_list;

	extern s_tag_struct_definition emblem_runtime_back_list;

	extern s_tag_struct_definition emblem_runtime_front_list;

	extern s_tag_struct_definition emblem_library_struct_definition;

	extern s_tag_struct_definition chud_widget_state_or_block;
	extern s_string_list_definition chud_widget_state_flags;
	extern s_string_list_definition chud_state_enum;

	extern s_tag_struct_definition chud_widget_state_and_block;

	extern s_tag_struct_definition chud_widget_state_editor_block;
	extern s_string_list_definition chud_widget_state_editor_data_type_enum;

	extern s_tag_struct_definition chud_widget_state_data_base_block_struct;

	extern s_tag_struct_definition chud_widget_state_data_struct;
	extern s_tag_reference_definition chud_widget_state_data_template_group_reference_tagref;

	extern s_tag_struct_definition chud_widget_state_data_template_struct_definition;

	extern s_tag_struct_definition chud_widget_placement_data_base_block;
	extern s_string_list_definition chud_curvature_res_flags;
	extern s_string_list_definition chud_anchor_type_enum;
	extern s_string_list_definition chud_widget_placement_flags;

	extern s_tag_struct_definition chud_widget_placement_data_struct;
	extern s_tag_reference_definition chud_widget_placement_data_template_group_reference_tagref;

	extern s_tag_struct_definition chud_widget_placement_data_template_struct_definition;

	extern s_tag_struct_definition chud_datasource_position_block;

	extern s_tag_struct_definition chud_datasource_resolution_block;

	extern s_tag_struct_definition chud_widget_datasource_base_block;
	extern s_string_list_definition chud_datasource_flags;
	extern s_string_list_definition chud_datasource_type_enum;

	extern s_tag_struct_definition chud_widget_datasource_struct;
	extern s_tag_reference_definition chud_widget_datasource_template_group_reference_tagref;

	extern s_tag_struct_definition chud_widget_datasource_template_struct_definition;

	extern s_tag_struct_definition chud_widget_render_data_base_block_struct;
	extern s_string_list_definition chud_shader_type_enum;
	extern s_string_list_definition chud_render_color_output_enum;
	extern s_string_list_definition chud_render_scalar_output_enum;
	extern s_string_list_definition render_blend_mode;

	extern s_tag_struct_definition chud_widget_render_data_struct;
	extern s_tag_reference_definition chud_widget_render_data_template_group_reference_tagref;

	extern s_tag_struct_definition chud_widget_render_data_template_struct_definition;

	extern s_tag_struct_definition chud_widget_animation_block_struct;
	extern s_string_list_definition chud_widget_animation_flags;
	extern s_string_list_definition chud_widget_animation_input_type_enum;
	extern s_tag_reference_definition chud_animation_definition_group_reference_tagref;

	extern s_tag_struct_definition chud_widget_animation_data_base_block;

	extern s_tag_struct_definition chud_widget_animation_data_struct;
	extern s_tag_reference_definition chud_widget_animation_data_template_group_reference_tagref;

	extern s_tag_struct_definition chud_widget_animation_data_template_struct_definition;

	extern s_tag_struct_definition chud_widget_base_struct;
	extern s_string_list_definition chud_scripting_class_enum;
	extern s_string_list_definition chud_widget_base_flags;
	extern s_string_list_definition chud_render_external_input_enum;

	extern s_tag_struct_definition chud_widget_bitmap_block;
	extern s_string_list_definition chud_widget_bitmap_flags;

	extern s_tag_struct_definition chud_widget_text_block_struct;
	extern s_string_list_definition chud_widget_text_flags;

	extern s_tag_struct_definition chud_widget_object_highlight_block;

	extern s_tag_struct_definition chud_widget_collection_block;

	extern s_tag_struct_definition chud_definition_info_struct;

	extern s_tag_struct_definition chud_widget_update_cache_block;

	extern s_tag_struct_definition chud_definition_block_struct;

	extern s_tag_struct_definition chud_keyframe_base_struct;

	extern s_tag_struct_definition chud_keyframe_position_block;

	extern s_tag_struct_definition chud_keyframe_rotation_block;

	extern s_tag_struct_definition chud_keyframe_scale_block;

	extern s_tag_struct_definition chud_keyframe_color_block;

	extern s_tag_struct_definition chud_keyframe_scalar_block;

	extern s_tag_struct_definition chud_keyframe_texture_block;

	extern s_tag_struct_definition chud_keyframe_external_input_block;

	extern s_tag_struct_definition chud_animation_position_block;

	extern s_tag_struct_definition chud_animation_rotation_block;

	extern s_tag_struct_definition chud_animation_scale_block;

	extern s_tag_struct_definition chud_animation_scalar_block;

	extern s_tag_struct_definition chud_animation_texture_block;

	extern s_tag_struct_definition chud_animation_external_input_a_block;

	extern s_tag_struct_definition chud_animation_external_input_b_block;

	extern s_tag_struct_definition chud_animation_color_block;

	extern s_tag_struct_definition chud_animation_definition_struct_definition;
	extern s_string_list_definition chud_animation_flags;

	extern s_tag_struct_definition screen_transform_basis_array_definition_struct_definition;

	extern s_tag_struct_definition chud_curvature_info_block;

	extern s_tag_struct_definition chud_sound_block;
	extern s_string_list_definition chud_sound_cue_flags;

	extern s_tag_struct_definition chud_config_info_block_struct;

	extern s_tag_struct_definition chud_damage_tracker_struct;

	extern s_tag_struct_definition chud_scripted_object_priority_definition;

	extern s_tag_struct_definition chud_globals_color_function_struct;

	extern s_tag_struct_definition chud_skin_info_block_struct;
	extern s_string_list_definition chud_skin_type_enum;
	extern s_string_list_definition directional_damage_flags_definition;

	extern s_tag_struct_definition chud_shader_block;

	extern s_tag_struct_definition chud_suck_profile_block;

	extern s_tag_struct_definition chud_state_category_block;

	extern s_tag_struct_definition chud_globals_definition_struct_definition;
	extern s_string_list_definition motion_sensor_flags;
	extern s_string_list_definition minimap_flags;

	extern s_tag_struct_definition property_long_value;

	extern s_tag_struct_definition property_real_value;

	extern s_tag_struct_definition property_string_id_value;

	extern s_tag_struct_definition property_tag_reference_value;
	extern s_tag_reference_definition _reference$8_tagref;

	extern s_tag_struct_definition property_text_value;

	extern s_tag_struct_definition property_argb_color_value;

	extern s_tag_struct_definition properties_struct;

	extern s_tag_struct_definition property_binding;
	extern s_string_list_definition property_binding_flags;
	extern s_string_list_definition binding_conversion_function_enum_definition;

	extern s_tag_struct_definition binding_conversion_long_comparison_block_definition;
	extern s_string_list_definition binding_conversion_comparison_operator_enum_definition;

	extern s_tag_struct_definition animation_scalar_function;

	extern s_tag_struct_definition animation_property_keyframe_real_value;

	extern s_tag_struct_definition animation_property_keyframe_argb_color_value;

	extern s_tag_struct_definition animation_component_real_property;
	extern s_string_list_definition animation_property_composition_type;
	extern s_string_list_definition animation_property_flags;

	extern s_tag_struct_definition animation_component_argb_color_property;

	extern s_tag_struct_definition animation_component_definition;

	extern s_tag_struct_definition animation_definition;

	extern s_tag_struct_definition static_data_column;
	extern s_string_list_definition property_type;

	extern s_tag_struct_definition static_data_struct;

	extern s_tag_struct_definition cui_static_data_struct_definition;

	extern s_tag_struct_definition static_data_table;

	extern s_tag_struct_definition expression_step;
	extern s_string_list_definition step_type;
	extern s_string_list_definition step_operator;
	extern s_string_list_definition step_variable;

	extern s_tag_struct_definition expression;

	extern s_tag_struct_definition template_instantiation_block_definition;
	extern s_tag_reference_definition cui_screen_group_reference_tagref;

	extern s_tag_struct_definition component_definition;
	extern s_string_list_definition component_definition_flags;

	extern s_tag_struct_definition component_index_block_definition;

	extern s_tag_struct_definition component_properties_definition;

	extern s_tag_struct_definition overlay_definition;

	extern s_tag_struct_definition property_editor_only_definition;
	extern s_string_list_definition editor_property_info_flags;

	extern s_tag_struct_definition component_editor_only_definition;

	extern s_tag_struct_definition animation_editor_only_definition;

	extern s_tag_struct_definition overlay_editor_only_definition;
	extern s_string_list_definition editor_overlay_info_flags;

	extern s_tag_struct_definition cui_screen_struct_definition;

	extern s_tag_struct_definition color_presets_block;

	extern s_tag_struct_definition color_list_block;

	extern s_tag_struct_definition tint_colors_block;

	extern s_tag_struct_definition gui_alert_description_block;
	extern s_string_list_definition gui_alert_flags;
	extern s_string_list_definition gui_error_category_enum;
	extern s_string_list_definition gui_error_icon_enum;

	extern s_tag_struct_definition gui_dialog_description_block;
	extern s_string_list_definition gui_dialog_flags;
	extern s_string_list_definition gui_dialog_choice_enum;
	extern s_string_list_definition gui_dialog_b_button_action_enum;

	extern s_tag_struct_definition user_interface_sounds_definition_struct_definition;

	extern s_tag_struct_definition pgcr_incident_block_struct;

	extern s_tag_struct_definition pgcr_player_to_category_entry_block;
	extern s_string_list_definition pgcr_player_type_enum;

	extern s_tag_struct_definition pgcr_enemy_to_category_entry_block;

	extern s_tag_struct_definition pgcr_enemy_to_category_list_block;
	extern s_string_list_definition pgcr_enemy_to_category_entry_flags;

	extern s_tag_struct_definition pgcr_enemy_to_category_mapping_definition_struct_definition;

	extern s_tag_struct_definition user_interface_shared_globals_definition_struct_definition;
	extern s_tag_reference_definition user_interface_sounds_definition_group_reference_tagref;

	extern s_tag_struct_definition cui_component_screen_reference_block_definition;
	extern s_tag_reference_definition cui_screen_group_reference$2_tagref;

	extern s_tag_struct_definition cui_overlay_camera_block_definition;
	extern s_string_list_definition cui_camera_pivot_corner_enum_definition;

	extern s_tag_struct_definition cui_player_model_camera_settings_definition;

	extern s_tag_struct_definition cui_player_model_controller_settings_definition;

	extern s_tag_struct_definition cui_player_model_transition_settings_definition;

	extern s_tag_struct_definition cui_active_roster_settings_block;

	extern s_tag_struct_definition campaign_state_screen_script_block_definition;

	extern s_tag_struct_definition user_interface_globals_definition_struct_definition;
	extern s_tag_reference_definition user_interface_shared_globals_definition_group_reference_tagref;
	extern s_tag_reference_definition multiplayer_variant_settings_interface_definition_group_reference_tagref;
	extern s_tag_reference_definition cookie_purchase_globals_group_reference_tagref;
	extern s_tag_reference_definition pgcr_enemy_to_category_mapping_definition_group_reference_tagref;

	extern s_tag_struct_definition text_value_pair_reference_block;
	extern s_string_list_definition text_value_pair_flags;
	extern s_string_list_definition text_value_pair_parameter_type;

	extern s_tag_struct_definition text_value_pair_definition_struct_definition;
	extern s_string_list_definition game_variant_parameters;

	extern s_tag_struct_definition sandbox_property_allowed_values_reference_block;

	extern s_tag_struct_definition sandbox_text_value_pair_definition_struct_definition;

	extern s_tag_struct_definition variant_option_block;
	extern s_string_list_definition game_engine_settings;
	extern s_tag_reference_definition text_value_pair_definition_group_reference_tagref;

	extern s_tag_struct_definition variant_setting_edit_reference_block;

	extern s_tag_struct_definition multiplayer_variant_settings_interface_definition_struct_definition;

	extern s_tag_struct_definition meter_struct_definition;
	extern s_string_list_definition meter_flags;
	extern s_tag_reference_definition bitmap_group_reference$9_tagref;
	extern s_string_list_definition color_interpolation_modes_enum;
	extern s_string_list_definition color_anchors_enum;

	extern s_tag_struct_definition load_screen_data_block;

	extern s_tag_struct_definition load_screen_globals_struct_definition;

	extern s_tag_struct_definition rasterizer_cache_file_globals_struct_definition;

	extern s_tag_struct_definition structure_lighting_generic_light_definition_block;
	extern s_string_list_definition lightmap_quality_flags;

	extern s_tag_struct_definition lightmapper_globals_struct_definition;

	extern s_tag_struct_definition solo_fog_parameters_struct_definition$2;

	extern s_tag_struct_definition fog_light_struct_definition$2;

	extern s_tag_struct_definition atmosphere_setting_block;
	extern s_string_list_definition atmosphere_flags$2;

	extern s_tag_struct_definition underwater_setting_block$2;

	extern s_tag_struct_definition sky_atm_parameters_struct_definition;

	extern s_tag_struct_definition mux_generator_material_block;
	extern s_tag_reference_definition shader_mux_material_group_reference_tagref;

	extern s_tag_struct_definition mux_generator_struct_definition;
	extern s_tag_reference_definition bitmap_group_reference$10_tagref;
	extern s_tag_reference_definition shader_mux_group_reference_tagref;

	extern s_tag_struct_definition render_water_ripple_struct_definition;
	extern s_string_list_definition ripple_behavior_flags;
	extern s_string_list_definition transition_function_enum;

	extern s_tag_struct_definition single_domain_blending_configuration_struct;

	extern s_tag_struct_definition single_domain_velocity_bumps_configuration_struct;

	extern s_tag_struct_definition single_domain_configuration_struct;

	extern s_tag_struct_definition simulation_interpolation_struct_definition;

	extern s_tag_struct_definition fluid_dynamics_squirter_block;

	extern s_tag_struct_definition fluid_dynamics_inflow_block;

	extern s_tag_struct_definition fluid_dynamics_outflow_block;

	extern s_tag_struct_definition fluid_dynamics_obstacle_block;

	extern s_tag_struct_definition g_single_scalar_function_evaluation_struct;

	extern s_tag_struct_definition fluid_dynamics_struct_definition;
	extern s_string_list_definition fluid_dynamics_flags;

	extern s_tag_struct_definition vocalization_stimuli_block_definition;
	extern s_string_list_definition vocalization_stimulus_flags;
	extern s_tag_reference_definition sound_group_reference$4_tagref;

	extern s_tag_struct_definition dialogue_block_struct;
	extern s_tag_reference_definition ai_dialogue_globals_group_reference$2_tagref;
	extern s_string_list_definition dialogue_flags;

	extern s_tag_struct_definition sound_references_block;

	extern s_tag_struct_definition stereo_system_struct_definition;

	extern s_tag_struct_definition states_block;

	extern s_tag_struct_definition rules_block;

	extern s_tag_struct_definition cellular_automata2d_struct_definition;

	extern s_tag_struct_definition cellular_automata_struct_definition;

	extern s_tag_struct_definition antenna_vertex_block;

	extern s_tag_struct_definition antenna_struct_definition;
	extern s_tag_reference_definition bitmap_group_reference$5_tagref;
	extern s_tag_reference_definition point_physics_group_reference_tagref;

	extern s_tag_struct_definition predicted_bitmaps_block;

	extern s_tag_struct_definition cheap_light_struct_definition;

	extern s_tag_struct_definition giant_buckle_parameters_block;
	extern s_string_list_definition slider_movement_patterns;

	extern s_tag_struct_definition collision_damage_function;

	extern s_tag_struct_definition collision_damage_struct_definition;

	extern s_tag_data_definition code_block;

	extern s_tag_data_definition dx9_compiled_shader_data;

	extern s_tag_data_definition xenon_compiled_shader_data;

	extern s_tag_data_definition code_block$2;

	extern s_tag_data_definition function_definition_data;

	extern s_tag_data_definition mesh_pca_data_definition;

	extern s_tag_data_definition user_data_definition;

	extern s_tag_data_definition editor_scenario_data_definition;

	extern s_tag_data_definition structure_bsp_cluster_encoded_sound_data;

	extern s_tag_data_definition render_geometry_vertex_buffer_data;

	extern s_tag_data_definition render_geometry_index_data;

	extern s_tag_data_definition mopp_code_data_definition;

	extern s_tag_data_definition utf8_string_data;

	extern s_tag_data_definition sound_resource_samples;

	extern s_tag_data_definition sound_samples;

	extern s_tag_data_definition compressed_facial_animation_curve_data;

	extern s_tag_data_definition error_report_string_data$2;

	extern s_tag_data_definition aligned_animation_data_definition_v1;

	extern s_tag_data_definition parameters_text_definition;

	extern s_tag_data_definition variant_resource_data;

	extern s_tag_data_definition bink_resource_data;

	extern s_tag_data_definition custom_script_data;

	extern s_tag_data_definition naive_control_data_definition;

	extern s_tag_data_definition naive_sample_data;

	extern s_tag_data_definition sound_effect_template_explanation;

	extern s_tag_data_definition bitmap_group_pixel_data_def;

	extern s_tag_data_definition bitmap_group_xenon_pixel_data_def;

	extern s_tag_data_definition bitmap_group_source_data_def;

	extern s_tag_data_definition error_report_string_data;

	extern s_tag_data_definition hs_source_data_definition;

	extern s_tag_data_definition hs_string_data_definition;

	extern s_tag_data_definition recorded_animation_event_stream_data;

	extern s_tag_data_definition base_render_texture_data;

	extern s_tag_data_definition high_res_render_texture_data;

	extern s_tag_data_definition meter_stencil_data_definition;

	extern s_tag_resource_definition render_geometry_api_resource_definition;

	extern s_tag_resource_definition structure_bsp_tag_resources;

	extern s_tag_resource_definition structure_bsp_cache_file_tag_resources;

	extern s_tag_resource_definition sound_resource_definition;

	extern s_tag_resource_definition facial_animation_resource_definition;

	extern s_tag_resource_definition model_animation_tag_resource;

	extern s_tag_resource_definition bink_resource;

	extern s_tag_resource_definition bitmap_texture_interop_resource;

	extern s_tag_resource_definition bitmap_texture_interleaved_interop_resource;

	extern s_tag_interop_definition render_vertex_buffer_interop_definition;

	extern s_tag_interop_definition render_index_buffer_interop_definition;

	extern s_tag_interop_definition render_texture_interop_definition;

	extern s_tag_interop_definition render_texture_interleaved_interop_definition;


} // namespace blofeld

} // namespace haloreach

