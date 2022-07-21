#pragma once

namespace blofeld
{
namespace halo2
{
namespace pc64
{

	static constexpr uint32_t AI_DIALOGUE_GLOBALS_TAG = 'adlg';
	extern s_tag_group ai_dialogue_globals_group;

	static constexpr uint32_t AI_MISSION_DIALOGUE_TAG = 'mdlg';
	extern s_tag_group ai_mission_dialogue_group;

	static constexpr uint32_t ANTENNA_TAG = 'ant!';
	extern s_tag_group antenna_group;

	static constexpr uint32_t BIPED_TAG = 'bipd';
	extern s_tag_group biped_group;

	static constexpr uint32_t BITMAP_TAG = 'bitm';
	extern s_tag_group bitmap_group;

	static constexpr uint32_t BREAKABLE_SURFACE_TAG = 'bsdt';
	extern s_tag_group breakable_surface_group;

	static constexpr uint32_t CACHE_FILE_SOUND_TAG = '$#!+';
	extern s_tag_group cache_file_sound_group;

	static constexpr uint32_t CAMERA_TRACK_TAG = 'trak';
	extern s_tag_group camera_track_group;

	static constexpr uint32_t CELLULAR_AUTOMATA_TAG = 'devo';
	extern s_tag_group cellular_automata_group;

	static constexpr uint32_t CELLULAR_AUTOMATA2D_TAG = 'whip';
	extern s_tag_group cellular_automata2d_group;

	static constexpr uint32_t CHARACTER_TAG = 'char';
	extern s_tag_group character_group;

	static constexpr uint32_t CHOCOLATE_MOUNTAIN_TAG = 'gldf';
	extern s_tag_group chocolate_mountain_group;

	static constexpr uint32_t CLOTH_TAG = 'clwd';
	extern s_tag_group cloth_group;

	static constexpr uint32_t COLLISION_MODEL_TAG = 'coll';
	extern s_tag_group collision_model_group;

	static constexpr uint32_t COLONY_TAG = 'coln';
	extern s_tag_group colony_group;

	static constexpr uint32_t COLOR_TABLE_TAG = 'colo';
	extern s_tag_group color_table_group;

	static constexpr uint32_t CONTRAIL_TAG = 'cont';
	extern s_tag_group contrail_group;

	static constexpr uint32_t CRATE_TAG = 'bloc';
	extern s_tag_group crate_group;

	static constexpr uint32_t CREATURE_TAG = 'crea';
	extern s_tag_group creature_group;

	static constexpr uint32_t DAMAGE_EFFECT_TAG = 'jpt!';
	extern s_tag_group damage_effect_group;

	static constexpr uint32_t DECAL_TAG = 'deca';
	extern s_tag_group decal_group;

	static constexpr uint32_t DECORATOR_SET_TAG = 'DECR';
	extern s_tag_group decorator_set_group;

	static constexpr uint32_t DECORATORS_TAG = 'DECP';
	extern s_tag_group decorators_group;

	static constexpr uint32_t DETAIL_OBJECT_COLLECTION_TAG = 'dobc';
	extern s_tag_group detail_object_collection_group;

	static constexpr uint32_t DEVICE_TAG = 'devi';
	extern s_tag_group device_group;

	static constexpr uint32_t DEVICE_CONTROL_TAG = 'ctrl';
	extern s_tag_group device_control_group;

	static constexpr uint32_t DEVICE_LIGHT_FIXTURE_TAG = 'lifi';
	extern s_tag_group device_light_fixture_group;

	static constexpr uint32_t DEVICE_MACHINE_TAG = 'mach';
	extern s_tag_group device_machine_group;

	static constexpr uint32_t DIALOGUE_TAG = 'udlg';
	extern s_tag_group dialogue_group;

	static constexpr uint32_t EFFECT_TAG = 'effe';
	extern s_tag_group effect_group;

	static constexpr uint32_t EQUIPMENT_TAG = 'eqip';
	extern s_tag_group equipment_group;

	static constexpr uint32_t GARBAGE_TAG = 'garb';
	extern s_tag_group garbage_group;

	static constexpr uint32_t GLOBALS_TAG = 'matg';
	extern s_tag_group globals_group;

	static constexpr uint32_t GRENADE_HUD_INTERFACE_TAG = 'grhi';
	extern s_tag_group grenade_hud_interface_group;

	static constexpr uint32_t HUD_GLOBALS_TAG = 'hudg';
	extern s_tag_group hud_globals_group;

	static constexpr uint32_t HUD_MESSAGE_TEXT_TAG = 'hmt ';
	extern s_tag_group hud_message_text_group;

	static constexpr uint32_t HUD_NUMBER_TAG = 'hud#';
	extern s_tag_group hud_number_group;

	static constexpr uint32_t ITEM_TAG = 'item';
	extern s_tag_group item_group;

	static constexpr uint32_t ITEM_COLLECTION_TAG = 'itmc';
	extern s_tag_group item_collection_group;

	static constexpr uint32_t LENS_FLARE_TAG = 'lens';
	extern s_tag_group lens_flare_group;

	static constexpr uint32_t LIGHT_TAG = 'ligh';
	extern s_tag_group light_group;

	static constexpr uint32_t LIGHT_VOLUME_TAG = 'MGS2';
	extern s_tag_group light_volume_group;

	static constexpr uint32_t LIQUID_TAG = 'tdtl';
	extern s_tag_group liquid_group;

	static constexpr uint32_t MATERIAL_EFFECTS_TAG = 'foot';
	extern s_tag_group material_effects_group;

	static constexpr uint32_t MATERIAL_PHYSICS_TAG = 'mpdt';
	extern s_tag_group material_physics_group;

	static constexpr uint32_t METER_TAG = 'metr';
	extern s_tag_group meter_group;

	static constexpr uint32_t MODEL_TAG = 'hlmt';
	extern s_tag_group model_group;

	static constexpr uint32_t MODEL_ANIMATION_GRAPH_TAG = 'jmad';
	extern s_tag_group model_animation_graph_group;

	static constexpr uint32_t MOUSE_CURSOR_DEFINITION_TAG = 'mcsr';
	extern s_tag_group mouse_cursor_definition_group;

	static constexpr uint32_t MULTILINGUAL_UNICODE_STRING_LIST_TAG = 'unic';
	extern s_tag_group multilingual_unicode_string_list_group;

	static constexpr uint32_t MULTIPLAYER_GLOBALS_TAG = 'mulg';
	extern s_tag_group multiplayer_globals_group;

	static constexpr uint32_t MULTIPLAYER_SCENARIO_DESCRIPTION_TAG = 'mply';
	extern s_tag_group multiplayer_scenario_description_group;

	static constexpr uint32_t MULTIPLAYER_VARIANT_SETTINGS_INTERFACE_DEFINITION_TAG = 'goof';
	extern s_tag_group multiplayer_variant_settings_interface_definition_group;

	static constexpr uint32_t NEW_HUD_DEFINITION_TAG = 'nhdt';
	extern s_tag_group new_hud_definition_group;

	static constexpr uint32_t OBJECT_TAG = 'obje';
	extern s_tag_group object_group;

	static constexpr uint32_t PARTICLE_TAG = 'prt3';
	extern s_tag_group particle_group;

	static constexpr uint32_t PARTICLE_MODEL_TAG = 'PRTM';
	extern s_tag_group particle_model_group;

	static constexpr uint32_t PARTICLE_PHYSICS_TAG = 'pmov';
	extern s_tag_group particle_physics_group;

	static constexpr uint32_t PATCHY_FOG_TAG = 'fpch';
	extern s_tag_group patchy_fog_group;

	static constexpr uint32_t PHYSICS_TAG = 'phys';
	extern s_tag_group physics_group;

	static constexpr uint32_t PHYSICS_MODEL_TAG = 'phmo';
	extern s_tag_group physics_model_group;

	static constexpr uint32_t PIXEL_SHADER_TAG = 'pixl';
	extern s_tag_group pixel_shader_group;

	static constexpr uint32_t PLANAR_FOG_TAG = 'fog ';
	extern s_tag_group planar_fog_group;

	static constexpr uint32_t POINT_PHYSICS_TAG = 'pphy';
	extern s_tag_group point_physics_group;

	static constexpr uint32_t PROJECTILE_TAG = 'proj';
	extern s_tag_group projectile_group;

	static constexpr uint32_t RENDER_MODEL_TAG = 'mode';
	extern s_tag_group render_model_group;

	static constexpr uint32_t SCENARIO_TAG = 'scnr';
	extern s_tag_group scenario_group;

	static constexpr uint32_t SCENARIO_AI_RESOURCE_TAG = 'ai**';
	extern s_tag_group scenario_ai_resource_group;

	static constexpr uint32_t SCENARIO_BIPEDS_RESOURCE_TAG = '*ipd';
	extern s_tag_group scenario_bipeds_resource_group;

	static constexpr uint32_t SCENARIO_CINEMATICS_RESOURCE_TAG = 'cin*';
	extern s_tag_group scenario_cinematics_resource_group;

	static constexpr uint32_t SCENARIO_CLUSTER_DATA_RESOURCE_TAG = 'clu*';
	extern s_tag_group scenario_cluster_data_resource_group;

	static constexpr uint32_t SCENARIO_COMMENTS_RESOURCE_TAG = '/**/';
	extern s_tag_group scenario_comments_resource_group;

	static constexpr uint32_t SCENARIO_CREATURE_RESOURCE_TAG = '*rea';
	extern s_tag_group scenario_creature_resource_group;

	static constexpr uint32_t SCENARIO_DECALS_RESOURCE_TAG = 'dec*';
	extern s_tag_group scenario_decals_resource_group;

	static constexpr uint32_t SCENARIO_DECORATORS_RESOURCE_TAG = 'dc*s';
	extern s_tag_group scenario_decorators_resource_group;

	static constexpr uint32_t SCENARIO_DEVICES_RESOURCE_TAG = 'dgr*';
	extern s_tag_group scenario_devices_resource_group;

	static constexpr uint32_t SCENARIO_EQUIPMENT_RESOURCE_TAG = '*qip';
	extern s_tag_group scenario_equipment_resource_group;

	static constexpr uint32_t SCENARIO_HS_SOURCE_FILE_TAG = 'hsc*';
	extern s_tag_group scenario_hs_source_file_group;

	static constexpr uint32_t SCENARIO_LIGHTS_RESOURCE_TAG = '*igh';
	extern s_tag_group scenario_lights_resource_group;

	static constexpr uint32_t SCENARIO_SCENERY_RESOURCE_TAG = '*cen';
	extern s_tag_group scenario_scenery_resource_group;

	static constexpr uint32_t SCENARIO_SOUND_SCENERY_RESOURCE_TAG = '*sce';
	extern s_tag_group scenario_sound_scenery_resource_group;

	static constexpr uint32_t SCENARIO_STRUCTURE_BSP_TAG = 'sbsp';
	extern s_tag_group scenario_structure_bsp_group;

	static constexpr uint32_t SCENARIO_STRUCTURE_LIGHTING_RESOURCE_TAG = 'sslt';
	extern s_tag_group scenario_structure_lighting_resource_group;

	static constexpr uint32_t SCENARIO_STRUCTURE_LIGHTMAP_TAG = 'ltmp';
	extern s_tag_group scenario_structure_lightmap_group;

	static constexpr uint32_t SCENARIO_TRIGGER_VOLUMES_RESOURCE_TAG = 'trg*';
	extern s_tag_group scenario_trigger_volumes_resource_group;

	static constexpr uint32_t SCENARIO_VEHICLES_RESOURCE_TAG = '*ehi';
	extern s_tag_group scenario_vehicles_resource_group;

	static constexpr uint32_t SCENARIO_WEAPONS_RESOURCE_TAG = '*eap';
	extern s_tag_group scenario_weapons_resource_group;

	static constexpr uint32_t SCENERY_TAG = 'scen';
	extern s_tag_group scenery_group;

	static constexpr uint32_t SCREEN_EFFECT_TAG = 'egor';
	extern s_tag_group screen_effect_group;

	static constexpr uint32_t SHADER_TAG = 'shad';
	extern s_tag_group shader_group;

	static constexpr uint32_t SHADER_LIGHT_RESPONSE_TAG = 'slit';
	extern s_tag_group shader_light_response_group;

	static constexpr uint32_t SHADER_PASS_TAG = 'spas';
	extern s_tag_group shader_pass_group;

	static constexpr uint32_t SHADER_TEMPLATE_TAG = 'stem';
	extern s_tag_group shader_template_group;

	static constexpr uint32_t SKY_TAG = 'sky ';
	extern s_tag_group sky_group;

	static constexpr uint32_t SOUND_TAG = 'snd!';
	extern s_tag_group sound_group;

	static constexpr uint32_t SOUND_CACHE_FILE_GESTALT_TAG = 'ugh!';
	extern s_tag_group sound_cache_file_gestalt_group;

	static constexpr uint32_t SOUND_CLASSES_TAG = 'sncl';
	extern s_tag_group sound_classes_group;

	static constexpr uint32_t SOUND_DIALOGUE_CONSTANTS_TAG = 'spk!';
	extern s_tag_group sound_dialogue_constants_group;

	static constexpr uint32_t SOUND_EFFECT_COLLECTION_TAG = 'sfx+';
	extern s_tag_group sound_effect_collection_group;

	static constexpr uint32_t SOUND_EFFECT_TEMPLATE_TAG = '<fx>';
	extern s_tag_group sound_effect_template_group;

	static constexpr uint32_t SOUND_ENVIRONMENT_TAG = 'snde';
	extern s_tag_group sound_environment_group;

	static constexpr uint32_t SOUND_LOOPING_TAG = 'lsnd';
	extern s_tag_group sound_looping_group;

	static constexpr uint32_t SOUND_MIX_TAG = 'snmx';
	extern s_tag_group sound_mix_group;

	static constexpr uint32_t SOUND_SCENERY_TAG = 'ssce';
	extern s_tag_group sound_scenery_group;

	static constexpr uint32_t STEREO_SYSTEM_TAG = 'BooM';
	extern s_tag_group stereo_system_group;

	static constexpr uint32_t STYLE_TAG = 'styl';
	extern s_tag_group style_group;

	static constexpr uint32_t TEXT_VALUE_PAIR_DEFINITION_TAG = 'sily';
	extern s_tag_group text_value_pair_definition_group;

	static constexpr uint32_t UNIT_TAG = 'unit';
	extern s_tag_group unit_group;

	static constexpr uint32_t UNIT_HUD_INTERFACE_TAG = 'unhi';
	extern s_tag_group unit_hud_interface_group;

	static constexpr uint32_t USER_INTERFACE_GLOBALS_DEFINITION_TAG = 'wgtz';
	extern s_tag_group user_interface_globals_definition_group;

	static constexpr uint32_t USER_INTERFACE_LIST_SKIN_DEFINITION_TAG = 'skin';
	extern s_tag_group user_interface_list_skin_definition_group;

	static constexpr uint32_t USER_INTERFACE_SCREEN_WIDGET_DEFINITION_TAG = 'wgit';
	extern s_tag_group user_interface_screen_widget_definition_group;

	static constexpr uint32_t USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG = 'wigl';
	extern s_tag_group user_interface_shared_globals_definition_group;

	static constexpr uint32_t VEHICLE_TAG = 'vehi';
	extern s_tag_group vehicle_group;

	static constexpr uint32_t VEHICLE_COLLECTION_TAG = 'vehc';
	extern s_tag_group vehicle_collection_group;

	static constexpr uint32_t VERTEX_SHADER_TAG = 'vrtx';
	extern s_tag_group vertex_shader_group;

	static constexpr uint32_t WEAPON_TAG = 'weap';
	extern s_tag_group weapon_group;

	static constexpr uint32_t WEAPON_HUD_INTERFACE_TAG = 'wphi';
	extern s_tag_group weapon_hud_interface_group;

	static constexpr uint32_t WEATHER_SYSTEM_TAG = 'weat';
	extern s_tag_group weather_system_group;

	static constexpr uint32_t WIND_TAG = 'wind';
	extern s_tag_group wind_group;

	extern s_tag_block_definition old_global_damage_resistance_struct_block;

	extern s_tag_block_definition unused_structure_bsp_node_block;

	extern s_tag_block_definition actor_palette_block;

	extern s_tag_block_definition actor_starting_locations_block;

	extern s_tag_block_definition additional_node_data_block;

	extern s_tag_block_definition ai_animation_reference_block;

	extern s_tag_block_definition ai_conversation_block;

	extern s_tag_block_definition ai_conversation_line_block;

	extern s_tag_block_definition ai_conversation_participant_block;

	extern s_tag_block_definition ai_deafening_encoded_pas_block;

	extern s_tag_block_definition ai_dialogue_globals_group_block;

	extern s_tag_block_definition ai_globals_block;

	extern s_tag_block_definition ai_globals_gravemind_block;

	extern s_tag_block_definition ai_mission_dialogue_group_block;

	extern s_tag_block_definition ai_recording_reference_block;

	extern s_tag_block_definition ai_scenario_mission_dialogue_block;

	extern s_tag_block_definition ai_scene_block;

	extern s_tag_block_definition ai_scene_role_block;

	extern s_tag_block_definition ai_scene_role_variants_block;

	extern s_tag_block_definition ai_scene_trigger_block;

	extern s_tag_block_definition ai_script_reference_block;

	extern s_tag_block_definition aim_assist_struct_block;

	extern s_tag_block_definition ambient_light_struct_block;

	extern s_tag_block_definition angular_velocity_lower_bound_struct_block;

	extern s_tag_block_definition animation_aiming_screen_struct_block;

	extern s_tag_block_definition animation_blend_screen_block;

	extern s_tag_block_definition animation_destination_state_struct_block;

	extern s_tag_block_definition animation_effect_event_block;

	extern s_tag_block_definition animation_entry_block;

	extern s_tag_block_definition animation_frame_event_block;

	extern s_tag_block_definition animation_graph_contents_struct_block;

	extern s_tag_block_definition animation_graph_effect_reference_block;

	extern s_tag_block_definition animation_graph_node_block;

	extern s_tag_block_definition animation_graph_resources_struct_block;

	extern s_tag_block_definition animation_graph_sound_reference_block;

	extern s_tag_block_definition animation_ik_block;

	extern s_tag_block_definition animation_index_struct_block;

	extern s_tag_block_definition animation_mode_block;

	extern s_tag_block_definition animation_pool_block;

	extern s_tag_block_definition animation_reference_block;

	extern s_tag_block_definition animation_sound_event_block;

	extern s_tag_block_definition animation_transition_block;

	extern s_tag_block_definition animation_transition_destination_block;

	extern s_tag_block_definition animation_transition_state_struct_block;

	extern s_tag_block_definition antenna_group_block;

	extern s_tag_block_definition antenna_vertex_block;

	extern s_tag_block_definition anti_gravity_point_definition_block;

	extern s_tag_block_definition area_set_block;

	extern s_tag_block_definition areas_block;

	extern s_tag_block_definition armor_modifier_block;

	extern s_tag_block_definition background_animation_keyframe_reference_block;

	extern s_tag_block_definition ball_and_socket_constraints_block;

	extern s_tag_block_definition barrel_firing_effect_block;

	extern s_tag_block_definition beam_block;

	extern s_tag_block_definition behavior_names_block;

	extern s_tag_block_definition biped_group_block;

	extern s_tag_block_definition biped_lock_on_data_struct_block;

	extern s_tag_block_definition bitmap_group_block;

	extern s_tag_block_definition bitmap_block_reference_block;

	extern s_tag_block_definition bitmap_data_block;

	extern s_tag_block_definition bitmap_group_sequence_block;

	extern s_tag_block_definition bitmap_group_sprite_block;

	extern s_tag_block_definition bitmap_native_info_struct_block;

	extern s_tag_block_definition bitmap_native_mipmap_info_block;

	extern s_tag_block_definition boxes_block;

	extern s_tag_block_definition breakable_surface_group_block;

	extern s_tag_block_definition breakable_surface_key_table_block;

	extern s_tag_block_definition bsp2d_nodes_block;

	extern s_tag_block_definition bsp2d_references_block;

	extern s_tag_block_definition bsp3d_nodes_block;

	extern s_tag_block_definition bsp_leaf_block;

	extern s_tag_block_definition bsp_surface_reference_block;

	extern s_tag_block_definition button_widget_reference_block;

	extern s_tag_block_definition byte_block;

	extern s_tag_block_definition cache_file_sound_group_block;

	extern s_tag_block_definition cached_data_block$2;

	extern s_tag_block_definition cached_data_block;

	extern s_tag_block_definition camera_block;

	extern s_tag_block_definition camera_track_group_block;

	extern s_tag_block_definition camera_track_control_point_block;

	extern s_tag_block_definition campaign_metagame_bucket_block;

	extern s_tag_block_definition campaign_metagame_bucket_struct_block;

	extern s_tag_block_definition cellular_automata2d_group_block;

	extern s_tag_block_definition cellular_automata_group_block;

	extern s_tag_block_definition character_group_block;

	extern s_tag_block_definition character_boarding_block;

	extern s_tag_block_definition character_boss_block;

	extern s_tag_block_definition character_charge_block;

	extern s_tag_block_definition character_cover_block;

	extern s_tag_block_definition character_engage_block;

	extern s_tag_block_definition character_evasion_block;

	extern s_tag_block_definition character_firing_pattern_block;

	extern s_tag_block_definition character_firing_pattern_properties_block;

	extern s_tag_block_definition character_general_block;

	extern s_tag_block_definition character_grenades_block;

	extern s_tag_block_definition character_idle_block;

	extern s_tag_block_definition character_look_block;

	extern s_tag_block_definition character_movement_block;

	extern s_tag_block_definition character_palette_block;

	extern s_tag_block_definition character_perception_block;

	extern s_tag_block_definition character_physics_dead_struct_block;

	extern s_tag_block_definition character_physics_flying_struct_block;

	extern s_tag_block_definition character_physics_ground_struct_block;

	extern s_tag_block_definition character_physics_sentinel_struct_block;

	extern s_tag_block_definition character_physics_struct_block;

	extern s_tag_block_definition character_placement_block;

	extern s_tag_block_definition character_presearch_block;

	extern s_tag_block_definition character_ready_block;

	extern s_tag_block_definition character_retreat_block;

	extern s_tag_block_definition character_search_block;

	extern s_tag_block_definition character_swarm_block;

	extern s_tag_block_definition character_variants_block;

	extern s_tag_block_definition character_vehicle_block;

	extern s_tag_block_definition character_vitality_block;

	extern s_tag_block_definition character_vocalization_block;

	extern s_tag_block_definition character_weapons_block;

	extern s_tag_block_definition cheat_powerups_block;

	extern s_tag_block_definition cheat_weapons_block;

	extern s_tag_block_definition chocolate_mountain_group_block;

	extern s_tag_block_definition cloth_group_block;

	extern s_tag_block_definition cloth_indices_block;

	extern s_tag_block_definition cloth_links_block;

	extern s_tag_block_definition cloth_properties_block;

	extern s_tag_block_definition cloth_vertices_block;

	extern s_tag_block_definition cluster_door_portal_encoded_pas_block;

	extern s_tag_block_definition collision_bsp_physics_block;

	extern s_tag_block_definition collision_damage_block;

	extern s_tag_block_definition collision_model_group_block;

	extern s_tag_block_definition collision_model_bsp_block;

	extern s_tag_block_definition collision_model_material_block;

	extern s_tag_block_definition collision_model_node_block;

	extern s_tag_block_definition collision_model_pathfinding_sphere_block;

	extern s_tag_block_definition collision_model_permutation_block;

	extern s_tag_block_definition collision_model_region_block;

	extern s_tag_block_definition colony_group_block;

	extern s_tag_block_definition color_block;

	extern s_tag_block_definition color_function_struct_block;

	extern s_tag_block_definition color_table_group_block;

	extern s_tag_block_definition constraint_bodies_struct_block;

	extern s_tag_block_definition contact_point_block;

	extern s_tag_block_definition contact_point_block_v1_block;

	extern s_tag_block_definition contrail_group_block;

	extern s_tag_block_definition contrail_point_states_block;

	extern s_tag_block_definition crate_group_block;

	extern s_tag_block_definition create_new_variant_struct_block;

	extern s_tag_block_definition creature_group_block;

	extern s_tag_block_definition cs_point_block;

	extern s_tag_block_definition cs_point_set_block;

	extern s_tag_block_definition cs_script_data_block;

	extern s_tag_block_definition custom_references_block;

	extern s_tag_block_definition damage_animation_block;

	extern s_tag_block_definition damage_constraint_info_block;

	extern s_tag_block_definition damage_direction_block;

	extern s_tag_block_definition damage_effect_group_block;

	extern s_tag_block_definition damage_effect_player_response_block;

	extern s_tag_block_definition damage_effect_sound_effect_definition_block;

	extern s_tag_block_definition damage_group_block;

	extern s_tag_block_definition damage_outer_cone_angle_struct_block;

	extern s_tag_block_definition damage_region_block;

	extern s_tag_block_definition damage_seat_info_block;

	extern s_tag_block_definition decal_group_block;

	extern s_tag_block_definition decal_vertices_block;

	extern s_tag_block_definition decorator_cache_block_block;

	extern s_tag_block_definition decorator_cache_block_data_block;

	extern s_tag_block_definition decorator_cell_collection_block;

	extern s_tag_block_definition decorator_classes_block;

	extern s_tag_block_definition decorator_group_block;

	extern s_tag_block_definition decorator_model_indices_block;

	extern s_tag_block_definition decorator_model_vertices_block;

	extern s_tag_block_definition decorator_models_block;

	extern s_tag_block_definition decorator_permutations_block;

	extern s_tag_block_definition decorator_placement_block;

	extern s_tag_block_definition decorator_placement_definition_block;

	extern s_tag_block_definition decorator_projected_decal_block;

	extern s_tag_block_definition decorator_set_group_block;

	extern s_tag_block_definition decorator_shader_reference_block;

	extern s_tag_block_definition decorators_group_block;

	extern s_tag_block_definition detail_object_collection_group_block;

	extern s_tag_block_definition detail_object_type_block;

	extern s_tag_block_definition device_group_block;

	extern s_tag_block_definition device_control_group_block;

	extern s_tag_block_definition device_group_block$2;

	extern s_tag_block_definition device_light_fixture_group_block;

	extern s_tag_block_definition device_machine_group_block;

	extern s_tag_block_definition dialogue_group_block;

	extern s_tag_block_definition dialogue_data_block;

	extern s_tag_block_definition dialogue_variant_block;

	extern s_tag_block_definition difficulty_block;

	extern s_tag_block_definition dont_use_me_scenario_environment_object_block;

	extern s_tag_block_definition door_encoded_pas_block;

	extern s_tag_block_definition dynamic_spawn_zone_overload_block;

	extern s_tag_block_definition edges_block;

	extern s_tag_block_definition editor_comment_block;

	extern s_tag_block_definition effect_accelerations_block;

	extern s_tag_block_definition effect_group_block;

	extern s_tag_block_definition effect_event_block;

	extern s_tag_block_definition effect_locations_block;

	extern s_tag_block_definition effect_part_block;

	extern s_tag_block_definition encoded_cluster_distances_block;

	extern s_tag_block_definition environment_object_bsp_refs_block;

	extern s_tag_block_definition environment_object_nodes_block;

	extern s_tag_block_definition environment_object_refs_block;

	extern s_tag_block_definition equipment_group_block;

	extern s_tag_block_definition error_report_comments_block;

	extern s_tag_block_definition error_report_lines_block;

	extern s_tag_block_definition error_report_quads_block;

	extern s_tag_block_definition error_report_triangles_block;

	extern s_tag_block_definition error_report_vectors_block;

	extern s_tag_block_definition error_report_vertices_block;

	extern s_tag_block_definition error_reports_block;

	extern s_tag_block_definition extern_reference_block;

	extern s_tag_block_definition falling_damage_block;

	extern s_tag_block_definition firing_positions_block;

	extern s_tag_block_definition flight_reference_block;

	extern s_tag_block_definition flock_definition_block;

	extern s_tag_block_definition flock_sink_block;

	extern s_tag_block_definition flock_source_block;

	extern s_tag_block_definition friction_point_definition_block;

	extern s_tag_block_definition g_default_variant_settings_block;

	extern s_tag_block_definition g_default_variants_block;

	extern s_tag_block_definition g_null_block;

	extern s_tag_block_definition g_scenario_editor_folder_block;

	extern s_tag_block_definition game_engine_assault_event_block;

	extern s_tag_block_definition game_engine_ctf_event_block;

	extern s_tag_block_definition game_engine_flavor_event_block;

	extern s_tag_block_definition game_engine_general_event_block;

	extern s_tag_block_definition game_engine_juggernaut_event_block;

	extern s_tag_block_definition game_engine_king_event_block;

	extern s_tag_block_definition game_engine_oddball_event_block;

	extern s_tag_block_definition game_engine_slayer_event_block;

	extern s_tag_block_definition game_engine_status_response_block;

	extern s_tag_block_definition game_engine_territories_event_block;

	extern s_tag_block_definition game_globals_damage_block;

	extern s_tag_block_definition game_portal_to_portal_mapping_block;

	extern s_tag_block_definition garbage_group_block;

	extern s_tag_block_definition gear_block;

	extern s_tag_block_definition gloal_wind_primitives_block;

	extern s_tag_block_definition global_collision_bsp_block;

	extern s_tag_block_definition global_collision_bsp_struct_block;

	extern s_tag_block_definition global_damage_info_block;

	extern s_tag_block_definition global_damage_nodes_block;

	extern s_tag_block_definition global_damage_section_block;

	extern s_tag_block_definition global_detail_object_block;

	extern s_tag_block_definition global_detail_object_cells_block;

	extern s_tag_block_definition global_detail_object_counts_block;

	extern s_tag_block_definition global_error_report_categories_block;

	extern s_tag_block_definition global_geometry_block_info_struct_block;

	extern s_tag_block_definition global_geometry_block_resource_block;

	extern s_tag_block_definition global_geometry_compression_info_block;

	extern s_tag_block_definition global_geometry_explicit_edge_block;

	extern s_tag_block_definition global_geometry_isq_info_struct_block;

	extern s_tag_block_definition global_geometry_material_block;

	extern s_tag_block_definition global_geometry_material_property_block;

	extern s_tag_block_definition global_geometry_part_block;

	extern s_tag_block_definition global_geometry_part_block_new_block;

	extern s_tag_block_definition global_geometry_plane_block;

	extern s_tag_block_definition global_geometry_point_data_index_block;

	extern s_tag_block_definition global_geometry_point_data_struct_block;

	extern s_tag_block_definition global_geometry_raw_point_block;

	extern s_tag_block_definition global_geometry_rigid_plane_group_block;

	extern s_tag_block_definition global_geometry_rigid_point_group_block;

	extern s_tag_block_definition global_geometry_section_info_struct_block;

	extern s_tag_block_definition global_geometry_section_raw_vertex_block;

	extern s_tag_block_definition global_geometry_section_strip_index_block;

	extern s_tag_block_definition global_geometry_section_struct_block;

	extern s_tag_block_definition global_geometry_section_vertex_buffer_block;

	extern s_tag_block_definition global_hud_multitexture_overlay_definition_block;

	extern s_tag_block_definition global_hud_multitexture_overlay_effector_definition_block;

	extern s_tag_block_definition global_hud_screen_effect_definition_block;

	extern s_tag_block_definition global_leaf_connection_block;

	extern s_tag_block_definition global_map_leaf_block;

	extern s_tag_block_definition global_new_hud_globals_constants_struct_block;

	extern s_tag_block_definition global_new_hud_globals_struct_block;

	extern s_tag_block_definition global_particle_system_lite_block;

	extern s_tag_block_definition global_scenario_load_parameters_block;

	extern s_tag_block_definition global_shader_parameter_block;

	extern s_tag_block_definition global_structure_physics_struct_block;

	extern s_tag_block_definition global_subparts_block;

	extern s_tag_block_definition global_tag_import_info_block;

	extern s_tag_block_definition global_ui_campaign_level_block;

	extern s_tag_block_definition global_ui_multiplayer_level_block;

	extern s_tag_block_definition global_visibility_bounds_block;

	extern s_tag_block_definition global_water_definitions_block;

	extern s_tag_block_definition global_weather_background_plate_block;

	extern s_tag_block_definition global_wind_model_struct_block;

	extern s_tag_block_definition global_z_reference_vector_block;

	extern s_tag_block_definition globals_group_block;

	extern s_tag_block_definition grenade_and_powerup_struct_block;

	extern s_tag_block_definition grenade_block;

	extern s_tag_block_definition grenade_hud_interface_group_block;

	extern s_tag_block_definition grenade_hud_overlay_block;

	extern s_tag_block_definition grenade_hud_sound_block;

	extern s_tag_block_definition grenades_block;

	extern s_tag_block_definition havok_cleanup_resources_block;

	extern s_tag_block_definition havok_vehicle_physics_struct_block;

	extern s_tag_block_definition hinge_constraints_block;

	extern s_tag_block_definition hs_globals_block;

	extern s_tag_block_definition hs_references_block;

	extern s_tag_block_definition hs_scripts_block;

	extern s_tag_block_definition hs_source_files_group_block;

	extern s_tag_block_definition hs_unit_seat_block;

	extern s_tag_block_definition hud_bitmap_widgets_block;

	extern s_tag_block_definition hud_block_reference_block;

	extern s_tag_block_definition hud_button_icon_block;

	extern s_tag_block_definition hud_dashlights_block;

	extern s_tag_block_definition hud_globals_group_block;

	extern s_tag_block_definition hud_message_elements_block;

	extern s_tag_block_definition hud_message_text_group_block;

	extern s_tag_block_definition hud_messages_block;

	extern s_tag_block_definition hud_number_group_block;

	extern s_tag_block_definition hud_screen_effect_widgets_block;

	extern s_tag_block_definition hud_text_widgets_block;

	extern s_tag_block_definition hud_waypoint_arrow_block;

	extern s_tag_block_definition hud_waypoint_arrow_block$2;

	extern s_tag_block_definition hud_waypoint_block;

	extern s_tag_block_definition hud_widget_effect_block;

	extern s_tag_block_definition hud_widget_effect_function_struct_block;

	extern s_tag_block_definition hud_widget_inputs_struct_block;

	extern s_tag_block_definition hud_widget_state_definition_struct_block;

	extern s_tag_block_definition indices_block;

	extern s_tag_block_definition inertial_matrix_block;

	extern s_tag_block_definition inherited_animation_block;

	extern s_tag_block_definition inherited_animation_node_map_block;

	extern s_tag_block_definition inherited_animation_node_map_flag_block;

	extern s_tag_block_definition instanced_geometry_reference_block;

	extern s_tag_block_definition instantaneous_damage_repsonse_block;

	extern s_tag_block_definition instantaneous_response_damage_effect_marker_struct_block;

	extern s_tag_block_definition instantaneous_response_damage_effect_struct_block;

	extern s_tag_block_definition interface_tag_references_block;

	extern s_tag_block_definition involuntary_data_block;

	extern s_tag_block_definition item_group_block;

	extern s_tag_block_definition item_collection_group_block;

	extern s_tag_block_definition item_permutation_block;

	extern s_tag_block_definition large_bsp2d_nodes_block;

	extern s_tag_block_definition large_bsp2d_references_block;

	extern s_tag_block_definition large_bsp3d_nodes_block;

	extern s_tag_block_definition large_edges_block;

	extern s_tag_block_definition large_leaves_block;

	extern s_tag_block_definition large_sound_permutations_block;

	extern s_tag_block_definition large_sound_pitch_range_block;

	extern s_tag_block_definition large_sound_playback_parameters_struct_block;

	extern s_tag_block_definition large_sound_scale_modifiers_struct_block;

	extern s_tag_block_definition large_surfaces_block;

	extern s_tag_block_definition large_vertices_block;

	extern s_tag_block_definition leaf_connection_vertex_block;

	extern s_tag_block_definition leaves_block;

	extern s_tag_block_definition lens_flare_group_block;

	extern s_tag_block_definition lens_flare_color_animation_block;

	extern s_tag_block_definition lens_flare_reflection_block;

	extern s_tag_block_definition lens_flare_scalar_animation_block;

	extern s_tag_block_definition light_group_block;

	extern s_tag_block_definition light_brightness_animation_block;

	extern s_tag_block_definition light_color_animation_block;

	extern s_tag_block_definition light_gel_animation_block;

	extern s_tag_block_definition light_volume_aspect_block;

	extern s_tag_block_definition light_volume_group_block;

	extern s_tag_block_definition light_volume_runtime_offset_block;

	extern s_tag_block_definition light_volume_volume_block;

	extern s_tag_block_definition lighting_variables_block;

	extern s_tag_block_definition lightmap_bucket_raw_vertex_block;

	extern s_tag_block_definition lightmap_geometry_render_info_block;

	extern s_tag_block_definition lightmap_geometry_section_block;

	extern s_tag_block_definition lightmap_geometry_section_cache_data_block;

	extern s_tag_block_definition lightmap_instance_bucket_reference_block;

	extern s_tag_block_definition lightmap_instance_bucket_section_offset_block;

	extern s_tag_block_definition lightmap_scenery_object_info_block;

	extern s_tag_block_definition lightmap_shadows_struct_block;

	extern s_tag_block_definition lightmap_vertex_buffer_bucket_block;

	extern s_tag_block_definition lightmap_vertex_buffer_bucket_cache_data_block;

	extern s_tag_block_definition limited_hinge_constraints_block;

	extern s_tag_block_definition liquid_arc_block;

	extern s_tag_block_definition liquid_group_block;

	extern s_tag_block_definition liquid_core_block;

	extern s_tag_block_definition list_reference_block;

	extern s_tag_block_definition list_shapes_block;

	extern s_tag_block_definition list_skin_reference_block;

	extern s_tag_block_definition lists_block;

	extern s_tag_block_definition local_bitmap_reference_block;

	extern s_tag_block_definition local_string_id_list_section_reference_block;

	extern s_tag_block_definition local_string_id_list_string_reference_block;

	extern s_tag_block_definition long_block;

	extern s_tag_block_definition look_function_block;

	extern s_tag_block_definition looping_sound_detail_block;

	extern s_tag_block_definition looping_sound_track_block;

	extern s_tag_block_definition magazine_objects_block;

	extern s_tag_block_definition magazines_block;

	extern s_tag_block_definition map_leaf_connection_index_block;

	extern s_tag_block_definition map_leaf_face_block;

	extern s_tag_block_definition map_leaf_face_vertex_block;

	extern s_tag_block_definition mapping_function_block;

	extern s_tag_block_definition mass_distributions_block;

	extern s_tag_block_definition mass_point_block;

	extern s_tag_block_definition material_effect_block_v1_block;

	extern s_tag_block_definition material_effect_block_v2_block;

	extern s_tag_block_definition material_effect_material_block;

	extern s_tag_block_definition material_effect_material_block_old_v1_block;

	extern s_tag_block_definition material_effects_group_block;

	extern s_tag_block_definition material_physics_group_block;

	extern s_tag_block_definition material_physics_properties_struct_block;

	extern s_tag_block_definition materials_block$2;

	extern s_tag_block_definition materials_block;

	extern s_tag_block_definition materials_sweeteners_struct_block;

	extern s_tag_block_definition melee_aim_assist_struct_block;

	extern s_tag_block_definition melee_damage_parameters_struct_block;

	extern s_tag_block_definition meter_group_block;

	extern s_tag_block_definition mission_dialogue_lines_block;

	extern s_tag_block_definition mission_dialogue_variants_block;

	extern s_tag_block_definition model_animation_graph_group_block;

	extern s_tag_block_definition model_animation_runtime_data_struct_block;

	extern s_tag_block_definition model_group_block;

	extern s_tag_block_definition model_material_block;

	extern s_tag_block_definition model_node_block;

	extern s_tag_block_definition model_object_data_block;

	extern s_tag_block_definition model_permutation_block;

	extern s_tag_block_definition model_region_block;

	extern s_tag_block_definition model_target_block;

	extern s_tag_block_definition model_target_lock_on_data_struct_block;

	extern s_tag_block_definition model_variant_block;

	extern s_tag_block_definition model_variant_object_block;

	extern s_tag_block_definition model_variant_permutation_block;

	extern s_tag_block_definition model_variant_region_block;

	extern s_tag_block_definition model_variant_state_block;

	extern s_tag_block_definition mopps_block;

	extern s_tag_block_definition mouse_cursor_bitmap_reference_block;

	extern s_tag_block_definition mouse_cursor_definition_group_block;

	extern s_tag_block_definition move_positions_block;

	extern s_tag_block_definition multi_spheres_block;

	extern s_tag_block_definition multilingual_unicode_string_list_group_block;

	extern s_tag_block_definition multilingual_unicode_string_reference_block;

	extern s_tag_block_definition multiplayer_color_block;

	extern s_tag_block_definition multiplayer_color_block$2;

	extern s_tag_block_definition multiplayer_constants_block;

	extern s_tag_block_definition multiplayer_globals_group_block;

	extern s_tag_block_definition multiplayer_information_block;

	extern s_tag_block_definition multiplayer_runtime_block;

	extern s_tag_block_definition multiplayer_scenario_description_group_block;

	extern s_tag_block_definition multiplayer_ui_block;

	extern s_tag_block_definition multiplayer_universal_block;

	extern s_tag_block_definition multiplayer_variant_settings_interface_definition_group_block;

	extern s_tag_block_definition new_hud_dashlight_data_struct_block;

	extern s_tag_block_definition new_hud_definition_group_block;

	extern s_tag_block_definition new_hud_sound_block;

	extern s_tag_block_definition node_render_leaves_block;

	extern s_tag_block_definition nodes_block;

	extern s_tag_block_definition null_block;

	extern s_tag_block_definition object_ai_properties_block;

	extern s_tag_block_definition object_animation_block;

	extern s_tag_block_definition object_attachment_block;

	extern s_tag_block_definition object_group_block;

	extern s_tag_block_definition object_change_color_function_block;

	extern s_tag_block_definition object_change_color_initial_permutation_block;

	extern s_tag_block_definition object_change_colors_block;

	extern s_tag_block_definition object_function_block;

	extern s_tag_block_definition object_space_node_data_block;

	extern s_tag_block_definition object_space_node_data_block_v0_block;

	extern s_tag_block_definition object_widget_block;

	extern s_tag_block_definition occluder_to_machine_door_mapping_block;

	extern s_tag_block_definition old_material_effect_material_block;

	extern s_tag_block_definition old_materials_block;

	extern s_tag_block_definition old_object_function_block;

	extern s_tag_block_definition old_scenario_device_struct_block;

	extern s_tag_block_definition old_scenario_unit_struct_block;

	extern s_tag_block_definition old_sound_permutation_info_block;

	extern s_tag_block_definition old_sound_permutations_block;

	extern s_tag_block_definition old_sound_pitch_range_block;

	extern s_tag_block_definition old_unused_object_identifiers_block;

	extern s_tag_block_definition old_unused_strucure_physics_block;

	extern s_tag_block_definition order_completion_block;

	extern s_tag_block_definition order_completion_condition_block;

	extern s_tag_block_definition order_ending_block;

	extern s_tag_block_definition orders_block;

	extern s_tag_block_definition packed_data_sizes_struct_block;

	extern s_tag_block_definition particle_group_block;

	extern s_tag_block_definition particle_controller_block;

	extern s_tag_block_definition particle_controller_parameters_block;

	extern s_tag_block_definition particle_model_group_block;

	extern s_tag_block_definition particle_model_indices_block;

	extern s_tag_block_definition particle_model_vertices_block;

	extern s_tag_block_definition particle_models_block;

	extern s_tag_block_definition particle_physics_group_block;

	extern s_tag_block_definition particle_property_color_struct_new_block;

	extern s_tag_block_definition particle_property_scalar_struct_new_block;

	extern s_tag_block_definition particle_system_definition_block_new_block;

	extern s_tag_block_definition particle_system_emitter_definition_block;

	extern s_tag_block_definition particle_system_lite_data_block;

	extern s_tag_block_definition particles_render_data_block;

	extern s_tag_block_definition particles_update_data_block;

	extern s_tag_block_definition patchy_fog_group_block;

	extern s_tag_block_definition pathfinding_data_block;

	extern s_tag_block_definition pathfinding_hints_block;

	extern s_tag_block_definition pathfinding_object_index_list_block;

	extern s_tag_block_definition permutations_block;

	extern s_tag_block_definition persistent_background_animation_block;

	extern s_tag_block_definition phantom_types_block;

	extern s_tag_block_definition phantoms_block;

	extern s_tag_block_definition physics_group_block;

	extern s_tag_block_definition physics_model_group_block;

	extern s_tag_block_definition physics_model_constraint_edge_constraint_block;

	extern s_tag_block_definition physics_model_node_constraint_edge_block;

	extern s_tag_block_definition pills_block;

	extern s_tag_block_definition pixel32_block;

	extern s_tag_block_definition pixel_shader_group_block;

	extern s_tag_block_definition pixel_shader_combiner_block;

	extern s_tag_block_definition pixel_shader_constant_block;

	extern s_tag_block_definition pixel_shader_extern_map_block;

	extern s_tag_block_definition pixel_shader_fragment_block;

	extern s_tag_block_definition pixel_shader_index_block;

	extern s_tag_block_definition pixel_shader_permutation_block;

	extern s_tag_block_definition pixel_shader_permutation_new_block;

	extern s_tag_block_definition planar_fog_group_block;

	extern s_tag_block_definition planar_fog_patchy_fog_block;

	extern s_tag_block_definition planes_block;

	extern s_tag_block_definition platform_sound_effect_block;

	extern s_tag_block_definition platform_sound_effect_collection_block;

	extern s_tag_block_definition platform_sound_effect_constant_block;

	extern s_tag_block_definition platform_sound_effect_function_block;

	extern s_tag_block_definition platform_sound_effect_override_descriptor_block;

	extern s_tag_block_definition platform_sound_effect_template_block;

	extern s_tag_block_definition platform_sound_effect_template_collection_block;

	extern s_tag_block_definition platform_sound_effect_template_component_block;

	extern s_tag_block_definition platform_sound_filter_block;

	extern s_tag_block_definition platform_sound_filter_lfo_block;

	extern s_tag_block_definition platform_sound_override_mixbins_block;

	extern s_tag_block_definition platform_sound_pitch_lfo_block;

	extern s_tag_block_definition platform_sound_playback_block;

	extern s_tag_block_definition platform_sound_playback_struct_block;

	extern s_tag_block_definition player_block_reference_block;

	extern s_tag_block_definition player_control_block;

	extern s_tag_block_definition player_information_block;

	extern s_tag_block_definition player_representation_block;

	extern s_tag_block_definition player_training_entry_data_block;

	extern s_tag_block_definition point_block_reference_block;

	extern s_tag_block_definition point_physics_group_block;

	extern s_tag_block_definition point_to_path_curve_block;

	extern s_tag_block_definition point_to_path_curve_point_block;

	extern s_tag_block_definition polyhedra_block;

	extern s_tag_block_definition polyhedron_four_vectors_block;

	extern s_tag_block_definition polyhedron_plane_equations_block;

	extern s_tag_block_definition powered_mass_point_block;

	extern s_tag_block_definition powered_seat_block;

	extern s_tag_block_definition powerup_block;

	extern s_tag_block_definition precache_list_block;

	extern s_tag_block_definition predicted_bitmaps_block;

	extern s_tag_block_definition predicted_resource_block;

	extern s_tag_block_definition primary_light_struct_block;

	extern s_tag_block_definition prismatic_constraints_block;

	extern s_tag_block_definition projectile_group_block;

	extern s_tag_block_definition projectile_material_response_block;

	extern s_tag_block_definition prt_cluster_basis_block;

	extern s_tag_block_definition prt_info_block;

	extern s_tag_block_definition prt_lod_info_block;

	extern s_tag_block_definition prt_raw_pca_data_block;

	extern s_tag_block_definition prt_section_info_block;

	extern s_tag_block_definition prt_vertex_buffers_block;

	extern s_tag_block_definition quantized_orientation_struct_block;

	extern s_tag_block_definition ragdoll_constraints_block;

	extern s_tag_block_definition rasterizer_data_block;

	extern s_tag_block_definition rasterizer_screen_effect_convolution_block;

	extern s_tag_block_definition rasterizer_screen_effect_pass_reference_block;

	extern s_tag_block_definition rasterizer_screen_effect_texcoord_generation_advanced_control_block;

	extern s_tag_block_definition real_block;

	extern s_tag_block_definition real_vector4d_block;

	extern s_tag_block_definition recorded_animation_block;

	extern s_tag_block_definition ref_block;

	extern s_tag_block_definition regions_block;

	extern s_tag_block_definition render_lighting_struct_block;

	extern s_tag_block_definition render_model_backward_shared_edge_block;

	extern s_tag_block_definition render_model_group_block;

	extern s_tag_block_definition render_model_compound_node_block;

	extern s_tag_block_definition render_model_dsq_raw_vertex_block;

	extern s_tag_block_definition render_model_dsq_silhouette_quad_block;

	extern s_tag_block_definition render_model_dsq_strip_index_block;

	extern s_tag_block_definition render_model_forward_shared_edge_block;

	extern s_tag_block_definition render_model_invalid_section_pairs_block;

	extern s_tag_block_definition render_model_marker_block;

	extern s_tag_block_definition render_model_marker_group_block;

	extern s_tag_block_definition render_model_node_block;

	extern s_tag_block_definition render_model_node_map_block;

	extern s_tag_block_definition render_model_node_map_block_old_block;

	extern s_tag_block_definition render_model_permutation_block;

	extern s_tag_block_definition render_model_region_block;

	extern s_tag_block_definition render_model_section_block;

	extern s_tag_block_definition render_model_section_data_block;

	extern s_tag_block_definition render_model_section_group_block;

	extern s_tag_block_definition render_model_shared_edge_group_block;

	extern s_tag_block_definition render_state_block;

	extern s_tag_block_definition render_state_parameter_block;

	extern s_tag_block_definition response_block;

	extern s_tag_block_definition rigid_bodies_block;

	extern s_tag_block_definition rigid_body_indices_block;

	extern s_tag_block_definition rules_block;

	extern s_tag_block_definition runtime_campaign_level_block;

	extern s_tag_block_definition runtime_levels_definition_block;

	extern s_tag_block_definition s_text_value_pair_blocks_block_unused_block;

	extern s_tag_block_definition s_text_value_pair_reference_block_unused_block;

	extern s_tag_block_definition scalar_function_struct_block;

	extern s_tag_block_definition scenario_ai_resource_group_block;

	extern s_tag_block_definition scenario_ai_resource_reference_block;

	extern s_tag_block_definition scenario_atmospheric_fog_mixer_block;

	extern s_tag_block_definition scenario_atmospheric_fog_palette_block;

	extern s_tag_block_definition scenario_biped_block;

	extern s_tag_block_definition scenario_biped_palette_block;

	extern s_tag_block_definition scenario_bipeds_resource_group_block;

	extern s_tag_block_definition scenario_group_block;

	extern s_tag_block_definition scenario_bsp_switch_transition_volume_block;

	extern s_tag_block_definition scenario_bsp_switch_trigger_volume_block;

	extern s_tag_block_definition scenario_child_scenario_block;

	extern s_tag_block_definition scenario_cinematics_resource_group_block;

	extern s_tag_block_definition scenario_cluster_atmospheric_fog_properties_block;

	extern s_tag_block_definition scenario_cluster_background_sounds_block;

	extern s_tag_block_definition scenario_cluster_data_block;

	extern s_tag_block_definition scenario_cluster_data_resource_group_block;

	extern s_tag_block_definition scenario_cluster_points_block;

	extern s_tag_block_definition scenario_cluster_sound_environments_block;

	extern s_tag_block_definition scenario_cluster_weather_properties_block;

	extern s_tag_block_definition scenario_comments_resource_group_block;

	extern s_tag_block_definition scenario_control_block;

	extern s_tag_block_definition scenario_control_palette_block;

	extern s_tag_block_definition scenario_control_struct_block;

	extern s_tag_block_definition scenario_crate_block;

	extern s_tag_block_definition scenario_crate_palette_block;

	extern s_tag_block_definition scenario_creature_block;

	extern s_tag_block_definition scenario_creature_palette_block;

	extern s_tag_block_definition scenario_creature_resource_group_block;

	extern s_tag_block_definition scenario_cutscene_camera_point_block;

	extern s_tag_block_definition scenario_cutscene_flag_block;

	extern s_tag_block_definition scenario_cutscene_title_block;

	extern s_tag_block_definition scenario_decal_palette_block;

	extern s_tag_block_definition scenario_decals_block;

	extern s_tag_block_definition scenario_decals_resource_group_block;

	extern s_tag_block_definition scenario_decorator_set_palette_entry_block;

	extern s_tag_block_definition scenario_decorators_resource_group_block;

	extern s_tag_block_definition scenario_description_block;

	extern s_tag_block_definition scenario_detail_object_collection_palette_block;

	extern s_tag_block_definition scenario_device_struct_block;

	extern s_tag_block_definition scenario_devices_resource_group_block;

	extern s_tag_block_definition scenario_equipment_block;

	extern s_tag_block_definition scenario_equipment_datum_struct_block;

	extern s_tag_block_definition scenario_equipment_palette_block;

	extern s_tag_block_definition scenario_equipment_resource_group_block;

	extern s_tag_block_definition scenario_function_block;

	extern s_tag_block_definition scenario_hs_source_reference_block;

	extern s_tag_block_definition scenario_interpolator_block;

	extern s_tag_block_definition scenario_kill_trigger_volumes_block;

	extern s_tag_block_definition scenario_level_data_block;

	extern s_tag_block_definition scenario_light_block;

	extern s_tag_block_definition scenario_light_fixture_block;

	extern s_tag_block_definition scenario_light_fixture_palette_block;

	extern s_tag_block_definition scenario_light_fixture_struct_block;

	extern s_tag_block_definition scenario_light_palette_block;

	extern s_tag_block_definition scenario_light_struct_block;

	extern s_tag_block_definition scenario_lights_resource_group_block;

	extern s_tag_block_definition scenario_machine_block;

	extern s_tag_block_definition scenario_machine_palette_block;

	extern s_tag_block_definition scenario_machine_struct_v2_block;

	extern s_tag_block_definition scenario_machine_struct_v3_block;

	extern s_tag_block_definition scenario_netgame_equipment_block;

	extern s_tag_block_definition scenario_netgame_equipment_orientation_struct_block;

	extern s_tag_block_definition scenario_netpoints_block;

	extern s_tag_block_definition scenario_object_datum_struct_block;

	extern s_tag_block_definition scenario_object_id_struct_block;

	extern s_tag_block_definition scenario_object_names_block;

	extern s_tag_block_definition scenario_object_permutation_struct_block;

	extern s_tag_block_definition scenario_planar_fog_palette_block;

	extern s_tag_block_definition scenario_players_block;

	extern s_tag_block_definition scenario_profiles_block;

	extern s_tag_block_definition scenario_resource_reference_block;

	extern s_tag_block_definition scenario_resources_block;

	extern s_tag_block_definition scenario_scenery_block;

	extern s_tag_block_definition scenario_scenery_datum_struct_v2_block;

	extern s_tag_block_definition scenario_scenery_datum_struct_v3_block;

	extern s_tag_block_definition scenario_scenery_datum_struct_v4_block;

	extern s_tag_block_definition scenario_scenery_palette_block;

	extern s_tag_block_definition scenario_scenery_resource_group_block;

	extern s_tag_block_definition scenario_screen_effect_reference_block;

	extern s_tag_block_definition scenario_simulation_definition_table_block;

	extern s_tag_block_definition scenario_sky_reference_block;

	extern s_tag_block_definition scenario_sound_scenery_block;

	extern s_tag_block_definition scenario_sound_scenery_palette_block;

	extern s_tag_block_definition scenario_sound_scenery_resource_group_block;

	extern s_tag_block_definition scenario_spawn_data_block;

	extern s_tag_block_definition scenario_spherical_harmonic_lighting_point_block;

	extern s_tag_block_definition scenario_starting_equipment_block;

	extern s_tag_block_definition scenario_structure_bsp_group_block;

	extern s_tag_block_definition scenario_structure_bsp_reference_block;

	extern s_tag_block_definition scenario_structure_bsp_spherical_harmonic_lighting_block;

	extern s_tag_block_definition scenario_structure_lighting_resource_group_block;

	extern s_tag_block_definition scenario_structure_lightmap_group_block;

	extern s_tag_block_definition scenario_trigger_volume_block;

	extern s_tag_block_definition scenario_trigger_volumes_resource_group_block;

	extern s_tag_block_definition scenario_unit_struct_block;

	extern s_tag_block_definition scenario_vehicle_block;

	extern s_tag_block_definition scenario_vehicle_palette_block;

	extern s_tag_block_definition scenario_vehicles_resource_group_block;

	extern s_tag_block_definition scenario_weapon_block;

	extern s_tag_block_definition scenario_weapon_datum_struct_block;

	extern s_tag_block_definition scenario_weapon_palette_block;

	extern s_tag_block_definition scenario_weapons_resource_group_block;

	extern s_tag_block_definition scenery_group_block;

	extern s_tag_block_definition screen_animation_keyframe_reference_block;

	extern s_tag_block_definition screen_effect_group_block;

	extern s_tag_block_definition screen_effect_bonus_struct_block;

	extern s_tag_block_definition screen_flash_definition_struct_block;

	extern s_tag_block_definition secondary_light_struct_block;

	extern s_tag_block_definition secondary_set_trigger_block;

	extern s_tag_block_definition secondary_zone_set_block;

	extern s_tag_block_definition section_render_leaves_block;

	extern s_tag_block_definition sector_block;

	extern s_tag_block_definition sector_bsp2d_nodes_block;

	extern s_tag_block_definition sector_link_block;

	extern s_tag_block_definition sector_vertex_block;

	extern s_tag_block_definition shader_animation_property_block;

	extern s_tag_block_definition shader_group_block;

	extern s_tag_block_definition shader_gpu_state_reference_struct_block;

	extern s_tag_block_definition shader_gpu_state_struct_block;

	extern s_tag_block_definition shader_light_response_group_block;

	extern s_tag_block_definition shader_pass_group_block;

	extern s_tag_block_definition shader_pass_implementation_block;

	extern s_tag_block_definition shader_pass_parameter_block;

	extern s_tag_block_definition shader_pass_postprocess_constant_info_new_block;

	extern s_tag_block_definition shader_pass_postprocess_constant_new_block;

	extern s_tag_block_definition shader_pass_postprocess_definition_new_block;

	extern s_tag_block_definition shader_pass_postprocess_extern_new_block;

	extern s_tag_block_definition shader_pass_postprocess_implementation_block;

	extern s_tag_block_definition shader_pass_postprocess_implementation_new_block;

	extern s_tag_block_definition shader_pass_postprocess_texture_new_block;

	extern s_tag_block_definition shader_pass_postprocess_texture_state_block;

	extern s_tag_block_definition shader_pass_texture_block;

	extern s_tag_block_definition shader_pass_vertex_shader_constant_block;

	extern s_tag_block_definition shader_postprocess_animated_parameter_new_block;

	extern s_tag_block_definition shader_postprocess_animated_parameter_reference_new_block;

	extern s_tag_block_definition shader_postprocess_bitmap_block;

	extern s_tag_block_definition shader_postprocess_bitmap_new_block;

	extern s_tag_block_definition shader_postprocess_bitmap_property_block;

	extern s_tag_block_definition shader_postprocess_bitmap_transform_block;

	extern s_tag_block_definition shader_postprocess_bitmap_transform_overlay_block;

	extern s_tag_block_definition shader_postprocess_color_block;

	extern s_tag_block_definition shader_postprocess_color_overlay_block;

	extern s_tag_block_definition shader_postprocess_color_property_block;

	extern s_tag_block_definition shader_postprocess_definition_new_block;

	extern s_tag_block_definition shader_postprocess_implementation_block;

	extern s_tag_block_definition shader_postprocess_implementation_new_block;

	extern s_tag_block_definition shader_postprocess_layer_block;

	extern s_tag_block_definition shader_postprocess_level_of_detail_block;

	extern s_tag_block_definition shader_postprocess_level_of_detail_new_block;

	extern s_tag_block_definition shader_postprocess_overlay_new_block;

	extern s_tag_block_definition shader_postprocess_overlay_reference_new_block;

	extern s_tag_block_definition shader_postprocess_pass_block;

	extern s_tag_block_definition shader_postprocess_pixel_shader_block;

	extern s_tag_block_definition shader_postprocess_pixel_shader_constant_defaults_block;

	extern s_tag_block_definition shader_postprocess_value_block;

	extern s_tag_block_definition shader_postprocess_value_overlay_block;

	extern s_tag_block_definition shader_postprocess_value_property_block;

	extern s_tag_block_definition shader_postprocess_vertex_shader_constant_block;

	extern s_tag_block_definition shader_properties_block;

	extern s_tag_block_definition shader_state_alpha_blend_state_block;

	extern s_tag_block_definition shader_state_alpha_test_state_block;

	extern s_tag_block_definition shader_state_channels_state_block;

	extern s_tag_block_definition shader_state_constant_block;

	extern s_tag_block_definition shader_state_cull_state_block;

	extern s_tag_block_definition shader_state_depth_state_block;

	extern s_tag_block_definition shader_state_fill_state_block;

	extern s_tag_block_definition shader_state_misc_state_block;

	extern s_tag_block_definition shader_template_group_block;

	extern s_tag_block_definition shader_template_category_block;

	extern s_tag_block_definition shader_template_level_of_detail_block;

	extern s_tag_block_definition shader_template_parameter_block;

	extern s_tag_block_definition shader_template_pass_reference_block;

	extern s_tag_block_definition shader_template_postprocess_definition_new_block;

	extern s_tag_block_definition shader_template_postprocess_implementation_new_block;

	extern s_tag_block_definition shader_template_postprocess_level_of_detail_new_block;

	extern s_tag_block_definition shader_template_postprocess_pass_new_block;

	extern s_tag_block_definition shader_template_postprocess_remapping_new_block;

	extern s_tag_block_definition shader_template_property_block;

	extern s_tag_block_definition shader_template_runtime_external_light_response_index_block;

	extern s_tag_block_definition shader_texture_state_address_state_block;

	extern s_tag_block_definition shader_texture_state_constant_block;

	extern s_tag_block_definition shader_texture_state_filter_state_block;

	extern s_tag_block_definition shader_texture_state_kill_state_block;

	extern s_tag_block_definition shader_texture_state_misc_state_block;

	extern s_tag_block_definition shape_block_reference_block;

	extern s_tag_block_definition shape_group_reference_block;

	extern s_tag_block_definition simple_platform_sound_playback_struct_block;

	extern s_tag_block_definition single_animation_reference_block;

	extern s_tag_block_definition skill_to_rank_mapping_block;

	extern s_tag_block_definition sky_animation_block;

	extern s_tag_block_definition sky_atmospheric_fog_block;

	extern s_tag_block_definition sky_group_block;

	extern s_tag_block_definition sky_cubemap_block;

	extern s_tag_block_definition sky_fog_block;

	extern s_tag_block_definition sky_light_block;

	extern s_tag_block_definition sky_light_fog_block;

	extern s_tag_block_definition sky_patchy_fog_block;

	extern s_tag_block_definition sky_radiosity_light_block;

	extern s_tag_block_definition sky_shader_function_block;

	extern s_tag_block_definition small_bsp3d_nodes_block;

	extern s_tag_block_definition sound_block;

	extern s_tag_block_definition sound_group_block;

	extern s_tag_block_definition sound_cache_file_gestalt_group_block;

	extern s_tag_block_definition sound_class_block;

	extern s_tag_block_definition sound_class_ducker_block_definition_block;

	extern s_tag_block_definition sound_classes_group_block;

	extern s_tag_block_definition sound_definition_language_permutation_info_block;

	extern s_tag_block_definition sound_dialogue_constants_group_block;

	extern s_tag_block_definition sound_effect_collection_group_block;

	extern s_tag_block_definition sound_effect_component_block;

	extern s_tag_block_definition sound_effect_override_parameters_block;

	extern s_tag_block_definition sound_effect_overrides_block;

	extern s_tag_block_definition sound_effect_playback_block;

	extern s_tag_block_definition sound_effect_struct_definition_block;

	extern s_tag_block_definition sound_effect_template_additional_sound_input_block;

	extern s_tag_block_definition sound_effect_template_group_block;

	extern s_tag_block_definition sound_effect_template_parameter_block;

	extern s_tag_block_definition sound_effect_templates_block;

	extern s_tag_block_definition sound_encoded_dialogue_section_block;

	extern s_tag_block_definition sound_environment_group_block;

	extern s_tag_block_definition sound_extra_info_block;

	extern s_tag_block_definition sound_gestalt_codec_block;

	extern s_tag_block_definition sound_gestalt_custom_playback_block;

	extern s_tag_block_definition sound_gestalt_extra_info_block;

	extern s_tag_block_definition sound_gestalt_import_names_block;

	extern s_tag_block_definition sound_gestalt_language_chunks_block;

	extern s_tag_block_definition sound_gestalt_lowpass_block;

	extern s_tag_block_definition sound_gestalt_permutation_language_data_block;

	extern s_tag_block_definition sound_gestalt_permutations_block;

	extern s_tag_block_definition sound_gestalt_pitch_range_parameters_block;

	extern s_tag_block_definition sound_gestalt_pitch_ranges_block;

	extern s_tag_block_definition sound_gestalt_playback_block;

	extern s_tag_block_definition sound_gestalt_promotions_block;

	extern s_tag_block_definition sound_gestalt_reflections_block;

	extern s_tag_block_definition sound_gestalt_remastered_sound_references_block;

	extern s_tag_block_definition sound_gestalt_runtime_permutation_bit_vector_block;

	extern s_tag_block_definition sound_gestalt_scale_block;

	extern s_tag_block_definition sound_global_mix_struct_block;

	extern s_tag_block_definition sound_globals_block;

	extern s_tag_block_definition sound_looping_group_block;

	extern s_tag_block_definition sound_lowpass_struct_block;

	extern s_tag_block_definition sound_mix_group_block;

	extern s_tag_block_definition sound_permutation_chunk_block;

	extern s_tag_block_definition sound_permutation_dialogue_info_block;

	extern s_tag_block_definition sound_permutation_marker_block;

	extern s_tag_block_definition sound_permutation_raw_info_block;

	extern s_tag_block_definition sound_permutation_raw_info_block_old_block;

	extern s_tag_block_definition sound_permutations_block;

	extern s_tag_block_definition sound_pitch_range_block;

	extern s_tag_block_definition sound_platform_sound_playback_block;

	extern s_tag_block_definition sound_playback_parameter_definition_block;

	extern s_tag_block_definition sound_playback_parameters_struct_block;

	extern s_tag_block_definition sound_promotion_parameters_struct_block;

	extern s_tag_block_definition sound_promotion_rule_block;

	extern s_tag_block_definition sound_promotion_runtime_timer_block;

	extern s_tag_block_definition sound_references_block;

	extern s_tag_block_definition sound_reflection_block;

	extern s_tag_block_definition sound_reflection_parameters_struct_block;

	extern s_tag_block_definition sound_response_definition_block;

	extern s_tag_block_definition sound_response_extra_sounds_struct_block;

	extern s_tag_block_definition sound_scale_modifiers_struct_block;

	extern s_tag_block_definition sound_scenery_group_block;

	extern s_tag_block_definition sound_scenery_datum_struct_block;

	extern s_tag_block_definition sounds_block;

	extern s_tag_block_definition sounds_block$2;

	extern s_tag_block_definition special_movement_block;

	extern s_tag_block_definition spheres_block;

	extern s_tag_block_definition sprite_vertices_block;

	extern s_tag_block_definition squad_groups_block;

	extern s_tag_block_definition squads_block;

	extern s_tag_block_definition states_block;

	extern s_tag_block_definition static_spawn_zone_block;

	extern s_tag_block_definition static_spawn_zone_data_struct_block;

	extern s_tag_block_definition stereo_system_group_block;

	extern s_tag_block_definition stiff_spring_constraints_block;

	extern s_tag_block_definition structure_bsp_audibility_block;

	extern s_tag_block_definition structure_bsp_background_sound_palette_block;

	extern s_tag_block_definition structure_bsp_breakable_surface_block;

	extern s_tag_block_definition structure_bsp_cluster_block;

	extern s_tag_block_definition structure_bsp_cluster_data_block;

	extern s_tag_block_definition structure_bsp_cluster_data_block_new_block;

	extern s_tag_block_definition structure_bsp_cluster_debug_info_block;

	extern s_tag_block_definition structure_bsp_cluster_havok_shape_block;

	extern s_tag_block_definition structure_bsp_cluster_instanced_geometry_index_block;

	extern s_tag_block_definition structure_bsp_cluster_lightmap_data_block;

	extern s_tag_block_definition structure_bsp_cluster_lightmap_duplicate_index_block;

	extern s_tag_block_definition structure_bsp_cluster_lightmap_index_block;

	extern s_tag_block_definition structure_bsp_cluster_lightmap_texture_coordinate_block;

	extern s_tag_block_definition structure_bsp_cluster_mopp_shape_block;

	extern s_tag_block_definition structure_bsp_cluster_portal_block;

	extern s_tag_block_definition structure_bsp_cluster_portal_index_block;

	extern s_tag_block_definition structure_bsp_cluster_portal_vertex_block;

	extern s_tag_block_definition structure_bsp_cluster_visibility_mopp_leaf_block;

	extern s_tag_block_definition structure_bsp_conveyor_surface_block;

	extern s_tag_block_definition structure_bsp_debug_info_block;

	extern s_tag_block_definition structure_bsp_debug_info_indices_block;

	extern s_tag_block_definition structure_bsp_debug_info_render_line_block;

	extern s_tag_block_definition structure_bsp_detail_object_data_block;

	extern s_tag_block_definition structure_bsp_environment_object_block;

	extern s_tag_block_definition structure_bsp_environment_object_palette_block;

	extern s_tag_block_definition structure_bsp_fake_lightprobes_block;

	extern s_tag_block_definition structure_bsp_fog_plane_block;

	extern s_tag_block_definition structure_bsp_fog_plane_debug_info_block;

	extern s_tag_block_definition structure_bsp_fog_zone_debug_info_block;

	extern s_tag_block_definition structure_bsp_instanced_geometry_definition_block;

	extern s_tag_block_definition structure_bsp_instanced_geometry_instances_block;

	extern s_tag_block_definition structure_bsp_leaf_block;

	extern s_tag_block_definition structure_bsp_lightmap_data_block;

	extern s_tag_block_definition structure_bsp_marker_block;

	extern s_tag_block_definition structure_bsp_pathfinding_edges_block;

	extern s_tag_block_definition structure_bsp_precomputed_lighting_block;

	extern s_tag_block_definition structure_bsp_runtime_decal_block;

	extern s_tag_block_definition structure_bsp_sky_owner_cluster_block;

	extern s_tag_block_definition structure_bsp_sound_cluster_block;

	extern s_tag_block_definition structure_bsp_sound_environment_palette_block;

	extern s_tag_block_definition structure_bsp_surface_reference_block;

	extern s_tag_block_definition structure_bsp_weather_palette_block;

	extern s_tag_block_definition structure_bsp_weather_polyhedron_block;

	extern s_tag_block_definition structure_bsp_weather_polyhedron_plane_block;

	extern s_tag_block_definition structure_collision_materials_block;

	extern s_tag_block_definition structure_device_portal_association_block;

	extern s_tag_block_definition structure_indices_segment_block;

	extern s_tag_block_definition structure_indices_segment_reference_block;

	extern s_tag_block_definition structure_instanced_geometry_render_info_struct_block;

	extern s_tag_block_definition structure_lightmap_bsp_leaf_block;

	extern s_tag_block_definition structure_lightmap_group_block;

	extern s_tag_block_definition structure_lightmap_lighting_environment_block;

	extern s_tag_block_definition structure_lightmap_palette_color_block;

	extern s_tag_block_definition structure_lightmap_sampling_info_block;

	extern s_tag_block_definition structure_lightmap_surface_block;

	extern s_tag_block_definition structure_portal_device_mapping_block;

	extern s_tag_block_definition structure_shared_edge_block;

	extern s_tag_block_definition structure_shared_edge_group_block;

	extern s_tag_block_definition structure_sound_cluster_interior_cluster_indices_block;

	extern s_tag_block_definition structure_sound_cluster_portal_designators_block;

	extern s_tag_block_definition structure_strip_segment_first_triangle_index_block;

	extern s_tag_block_definition structure_subcluster_block;

	extern s_tag_block_definition structure_subcluster_boundary_block;

	extern s_tag_block_definition style_group_block;

	extern s_tag_block_definition style_palette_block;

	extern s_tag_block_definition super_detonation_damage_struct_block;

	extern s_tag_block_definition surface_flags_block;

	extern s_tag_block_definition surfaces_block;

	extern s_tag_block_definition syntax_datum_block;

	extern s_tag_block_definition table_view_list_item_reference_block;

	extern s_tag_block_definition table_view_list_reference_block;

	extern s_tag_block_definition table_view_list_row_reference_block;

	extern s_tag_block_definition tag_block_index_block;

	extern s_tag_block_definition tag_block_index_struct_block;

	extern s_tag_block_definition tag_import_file_block;

	extern s_tag_block_definition text_block_reference_block;

	extern s_tag_block_definition text_value_pair_block;

	extern s_tag_block_definition text_value_pair_definition_group_block;

	extern s_tag_block_definition text_value_pair_reference_block;

	extern s_tag_block_definition texture_block;

	extern s_tag_block_definition texture_stage_state_block;

	extern s_tag_block_definition texture_stage_state_parameter_block;

	extern s_tag_block_definition torque_curve_struct_block;

	extern s_tag_block_definition transparent_planes_block;

	extern s_tag_block_definition triangles_block;

	extern s_tag_block_definition trigger_references_block;

	extern s_tag_block_definition triggers_block;

	extern s_tag_block_definition ui_campaign_block;

	extern s_tag_block_definition ui_error_block;

	extern s_tag_block_definition ui_error_category_block;

	extern s_tag_block_definition ui_levels_definition_block;

	extern s_tag_block_definition ui_light_reference_block;

	extern s_tag_block_definition ui_model_scene_reference_block;

	extern s_tag_block_definition ui_object_reference_block;

	extern s_tag_block_definition unit_additional_node_names_struct_block;

	extern s_tag_block_definition unit_group_block;

	extern s_tag_block_definition unit_boarding_melee_struct_block;

	extern s_tag_block_definition unit_boost_struct_block;

	extern s_tag_block_definition unit_camera_struct_block;

	extern s_tag_block_definition unit_camera_track_block;

	extern s_tag_block_definition unit_hud_auxilary_overlay_block;

	extern s_tag_block_definition unit_hud_auxilary_panel_block;

	extern s_tag_block_definition unit_hud_interface_group_block;

	extern s_tag_block_definition unit_hud_reference_block;

	extern s_tag_block_definition unit_hud_sound_block;

	extern s_tag_block_definition unit_lipsync_scales_struct_block;

	extern s_tag_block_definition unit_postures_block;

	extern s_tag_block_definition unit_seat_acceleration_struct_block;

	extern s_tag_block_definition unit_seat_block;

	extern s_tag_block_definition unit_weapon_block;

	extern s_tag_block_definition user_hint_block;

	extern s_tag_block_definition user_hint_climb_block;

	extern s_tag_block_definition user_hint_flight_block;

	extern s_tag_block_definition user_hint_flight_point_block;

	extern s_tag_block_definition user_hint_jump_block;

	extern s_tag_block_definition user_hint_line_segment_block;

	extern s_tag_block_definition user_hint_parallelogram_block;

	extern s_tag_block_definition user_hint_point_block;

	extern s_tag_block_definition user_hint_polygon_block;

	extern s_tag_block_definition user_hint_ray_block;

	extern s_tag_block_definition user_hint_well_block;

	extern s_tag_block_definition user_hint_well_point_block;

	extern s_tag_block_definition user_interface_globals_definition_group_block;

	extern s_tag_block_definition user_interface_list_skin_definition_group_block;

	extern s_tag_block_definition user_interface_screen_widget_definition_group_block;

	extern s_tag_block_definition user_interface_shared_globals_definition_group_block;

	extern s_tag_block_definition user_interface_widget_reference_block;

	extern s_tag_block_definition variant_setting_edit_reference_block;

	extern s_tag_block_definition vehicle_group_block;

	extern s_tag_block_definition vehicle_collection_group_block;

	extern s_tag_block_definition vehicle_permutation_block;

	extern s_tag_block_definition vehicle_phantom_shape_block;

	extern s_tag_block_definition vehicle_suspension_block;

	extern s_tag_block_definition vehicles_block$2;

	extern s_tag_block_definition vehicles_block;

	extern s_tag_block_definition vertex_shader_group_block;

	extern s_tag_block_definition vertex_shader_classification_block;

	extern s_tag_block_definition vertex_shader_constant_block;

	extern s_tag_block_definition vertex_shader_reference_block;

	extern s_tag_block_definition vertices_block;

	extern s_tag_block_definition vibration_definition_struct_block;

	extern s_tag_block_definition vibration_frequency_definition_struct_block;

	extern s_tag_block_definition visibility_mopp_reorder_table_block;

	extern s_tag_block_definition visibility_struct_block;

	extern s_tag_block_definition vocalization_definitions_block_0_block;

	extern s_tag_block_definition vocalization_definitions_block_1_block;

	extern s_tag_block_definition vocalization_definitions_block_2_block;

	extern s_tag_block_definition vocalization_definitions_block_3_block;

	extern s_tag_block_definition vocalization_definitions_block_4_block;

	extern s_tag_block_definition vocalization_definitions_block_5_block;

	extern s_tag_block_definition vocalization_patterns_block;

	extern s_tag_block_definition water_geometry_section_block;

	extern s_tag_block_definition weapon_barrel_damage_effect_struct_block;

	extern s_tag_block_definition weapon_barrels_block;

	extern s_tag_block_definition weapon_group_block;

	extern s_tag_block_definition weapon_class_block;

	extern s_tag_block_definition weapon_class_lookup_block;

	extern s_tag_block_definition weapon_first_person_interface_block;

	extern s_tag_block_definition weapon_hud_crosshair_block;

	extern s_tag_block_definition weapon_hud_crosshair_item_block;

	extern s_tag_block_definition weapon_hud_interface_group_block;

	extern s_tag_block_definition weapon_hud_meter_block;

	extern s_tag_block_definition weapon_hud_number_block;

	extern s_tag_block_definition weapon_hud_overlay_block;

	extern s_tag_block_definition weapon_hud_overlays_block;

	extern s_tag_block_definition weapon_hud_static_block;

	extern s_tag_block_definition weapon_interface_struct_block;

	extern s_tag_block_definition weapon_shared_interface_struct_block;

	extern s_tag_block_definition weapon_tracking_struct_block;

	extern s_tag_block_definition weapon_trigger_autofire_struct_block;

	extern s_tag_block_definition weapon_trigger_charging_struct_block;

	extern s_tag_block_definition weapon_triggers_block;

	extern s_tag_block_definition weapon_type_block;

	extern s_tag_block_definition weapons_block;

	extern s_tag_block_definition weather_system_group_block;

	extern s_tag_block_definition wind_group_block;

	extern s_tag_block_definition window_pane_reference_block;

	extern s_tag_block_definition zone_block;

	extern s_tag_block_definition zone_set_block;

	extern s_tag_array_definition unnamed_array;

	extern s_tag_array_definition unnamed_array$10;

	extern s_tag_array_definition unnamed_array$11;

	extern s_tag_array_definition unnamed_array$12;

	extern s_tag_array_definition unnamed_array$13;

	extern s_tag_array_definition unnamed_array$14;

	extern s_tag_array_definition unnamed_array$15;

	extern s_tag_array_definition unnamed_array$16;

	extern s_tag_array_definition unnamed_array$17;

	extern s_tag_array_definition unnamed_array$18;

	extern s_tag_array_definition unnamed_array$19;

	extern s_tag_array_definition unnamed_array$2;

	extern s_tag_array_definition unnamed_array$20;

	extern s_tag_array_definition unnamed_array$21;

	extern s_tag_array_definition unnamed_array$22;

	extern s_tag_array_definition unnamed_array$23;

	extern s_tag_array_definition unnamed_array$24;

	extern s_tag_array_definition unnamed_array$25;

	extern s_tag_array_definition unnamed_array$26;

	extern s_tag_array_definition unnamed_array$27;

	extern s_tag_array_definition unnamed_array$28;

	extern s_tag_array_definition unnamed_array$29;

	extern s_tag_array_definition unnamed_array$3;

	extern s_tag_array_definition unnamed_array$30;

	extern s_tag_array_definition unnamed_array$31;

	extern s_tag_array_definition unnamed_array$32;

	extern s_tag_array_definition unnamed_array$33;

	extern s_tag_array_definition unnamed_array$34;

	extern s_tag_array_definition unnamed_array$35;

	extern s_tag_array_definition unnamed_array$36;

	extern s_tag_array_definition unnamed_array$37;

	extern s_tag_array_definition unnamed_array$38;

	extern s_tag_array_definition unnamed_array$39;

	extern s_tag_array_definition unnamed_array$4;

	extern s_tag_array_definition unnamed_array$40;

	extern s_tag_array_definition unnamed_array$41;

	extern s_tag_array_definition unnamed_array$42;

	extern s_tag_array_definition unnamed_array$43;

	extern s_tag_array_definition unnamed_array$44;

	extern s_tag_array_definition unnamed_array$45;

	extern s_tag_array_definition unnamed_array$46;

	extern s_tag_array_definition unnamed_array$47;

	extern s_tag_array_definition unnamed_array$48;

	extern s_tag_array_definition unnamed_array$49;

	extern s_tag_array_definition unnamed_array$5;

	extern s_tag_array_definition unnamed_array$50;

	extern s_tag_array_definition unnamed_array$51;

	extern s_tag_array_definition unnamed_array$52;

	extern s_tag_array_definition unnamed_array$6;

	extern s_tag_array_definition unnamed_array$7;

	extern s_tag_array_definition unnamed_array$8;

	extern s_tag_array_definition unnamed_array$9;

	extern s_tag_struct_definition old_global_damage_resistance_struct_struct_definition;

	extern s_tag_struct_definition unused_structure_bsp_node_block_struct_definition;

	extern s_tag_struct_definition actor_palette_block_struct_definition;

	extern s_tag_struct_definition actor_starting_location_struct_definition;
	extern s_string_list_definition unnamed_enum$69;
	extern s_string_list_definition unnamed_enum$70;
	extern s_string_list_definition unnamed_enum$68;
	extern s_string_list_definition unnamed_enum$71;
	extern s_tag_reference_definition weapon_group_reference$2;

	extern s_tag_struct_definition additional_node_data_block_struct_definition;

	extern s_tag_struct_definition ai_animation_reference_block_struct_definition;
	extern s_tag_reference_definition model_animation_graph_group_reference;

	extern s_tag_struct_definition ai_conversation_block_struct_definition;
	extern s_string_list_definition unnamed_enum$88;

	extern s_tag_struct_definition ai_conversation_line_block_struct_definition;
	extern s_string_list_definition unnamed_enum$89;
	extern s_string_list_definition unnamed_enum$90;
	extern s_tag_reference_definition sound_group_reference;

	extern s_tag_struct_definition ai_conversation_participant_block_struct_definition;

	extern s_tag_struct_definition ai_deafening_encoded_pas_block_struct_definition;

	extern s_tag_struct_definition ai_dialogue_globals_block_struct_definition;

	extern s_tag_struct_definition ai_globals_block_struct_definition;
	extern s_tag_reference_definition ai_dialogue_globals_group_reference;

	extern s_tag_struct_definition ai_globals_gravemind_block_struct_definition;

	extern s_tag_struct_definition ai_mission_dialogue_block_struct_definition;

	extern s_tag_struct_definition ai_recording_reference_block_struct_definition;

	extern s_tag_struct_definition ai_scenario_mission_dialogue_block_struct_definition;
	extern s_tag_reference_definition ai_mission_dialogue_group_reference;

	extern s_tag_struct_definition ai_scene_block_struct_definition;
	extern s_string_list_definition unnamed_enum$93;

	extern s_tag_struct_definition ai_scene_role_block_struct_definition;
	extern s_string_list_definition unnamed_enum$94;

	extern s_tag_struct_definition ai_scene_role_variants_block_struct_definition;

	extern s_tag_struct_definition ai_scene_trigger_block_struct_definition;
	extern s_string_list_definition unnamed_enum$82;

	extern s_tag_struct_definition ai_script_reference_block_struct_definition;

	extern s_tag_struct_definition aim_assist_struct_struct_definition;

	extern s_tag_struct_definition ambient_light_struct_struct_definition;

	extern s_tag_struct_definition angular_velocity_lower_bound_struct_definition;

	extern s_tag_struct_definition animation_aiming_screen_struct_struct_definition;

	extern s_tag_struct_definition animation_blend_screen_block_struct_definition;

	extern s_tag_struct_definition animation_destination_state_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$255;

	extern s_tag_struct_definition animation_entry_block_struct_definition;

	extern s_tag_struct_definition animation_frame_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$253;

	extern s_tag_struct_definition animation_graph_contents_struct_struct_definition;

	extern s_tag_struct_definition animation_graph_effect_reference_block_struct_definition;
	extern s_tag_reference_definition effect_group_reference;
	extern s_string_list_definition unnamed_enum$246;

	extern s_tag_struct_definition animation_graph_node_struct_definition;
	extern s_string_list_definition unnamed_enum$244;
	extern s_string_list_definition unnamed_enum$245;

	extern s_tag_struct_definition animation_graph_sound_reference_block_struct_definition;

	extern s_tag_struct_definition animation_ik_block_struct_definition;

	extern s_tag_struct_definition animation_index_struct_struct_definition;

	extern s_tag_struct_definition animation_mode_block_struct_definition;

	extern s_tag_struct_definition animation_pool_struct_definition;
	extern s_string_list_definition unnamed_enum$247;
	extern s_string_list_definition unnamed_enum$248;
	extern s_string_list_definition unnamed_enum$249;
	extern s_string_list_definition unnamed_enum$250;
	extern s_string_list_definition unnamed_enum$251;
	extern s_string_list_definition unnamed_enum$252;

	extern s_tag_struct_definition animation_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$550;
	extern s_string_list_definition unnamed_enum$551;

	extern s_tag_struct_definition animation_resources_struct_definition;
	extern s_tag_reference_definition model_animation_graph_group_reference$2;
	extern s_string_list_definition unnamed_enum$242;
	extern s_string_list_definition unnamed_enum$243;

	extern s_tag_struct_definition animation_sound_event_block_struct_definition;

	extern s_tag_struct_definition animation_transition_block_struct_definition;

	extern s_tag_struct_definition animation_transition_destination_block_struct_definition;

	extern s_tag_struct_definition animation_transition_state_struct_struct_definition;

	extern s_tag_struct_definition antenna_block_struct_definition;
	extern s_tag_reference_definition bitmap_group_reference$2;
	extern s_tag_reference_definition point_physics_group_reference;

	extern s_tag_struct_definition antenna_vertex_block_struct_definition;

	extern s_tag_struct_definition anti_gravity_point_definition_block_struct_definition;
	extern s_string_list_definition unnamed_enum$512;

	extern s_tag_struct_definition area_set_block_struct_definition;

	extern s_tag_struct_definition area_struct_definition;
	extern s_string_list_definition unnamed_enum$74;

	extern s_tag_struct_definition armor_modifier_block_struct_definition;

	extern s_tag_struct_definition array$42;

	extern s_tag_struct_definition array$43;

	extern s_tag_struct_definition array$26;

	extern s_tag_struct_definition array$2;

	extern s_tag_struct_definition array$46;

	extern s_tag_struct_definition array$45;

	extern s_tag_struct_definition array$44;

	extern s_tag_struct_definition array$27;

	extern s_tag_struct_definition array$48;

	extern s_tag_struct_definition array$47;

	extern s_tag_struct_definition array;

	extern s_tag_struct_definition array$18;

	extern s_tag_struct_definition array$17;

	extern s_tag_struct_definition array$9;

	extern s_tag_struct_definition array$8;

	extern s_tag_struct_definition array$16;

	extern s_tag_struct_definition array$52;

	extern s_tag_struct_definition array$15;

	extern s_tag_struct_definition array$14;

	extern s_tag_struct_definition array$13;

	extern s_tag_struct_definition array$12;

	extern s_tag_struct_definition array$11;

	extern s_tag_struct_definition array$10;

	extern s_tag_struct_definition array$7;

	extern s_tag_struct_definition array$6;

	extern s_tag_struct_definition array$5;

	extern s_tag_struct_definition array$4;

	extern s_tag_struct_definition array$24;

	extern s_tag_struct_definition array$25;

	extern s_tag_struct_definition array$28;

	extern s_tag_struct_definition array$29;

	extern s_tag_struct_definition array$3;

	extern s_tag_struct_definition array$23;

	extern s_tag_struct_definition array$30;

	extern s_tag_struct_definition array$35;

	extern s_tag_struct_definition array$21;

	extern s_tag_struct_definition array$20;

	extern s_tag_struct_definition array$19;

	extern s_tag_struct_definition array$31;

	extern s_tag_struct_definition array$32;

	extern s_tag_struct_definition array$22;

	extern s_tag_struct_definition array$51;

	extern s_tag_struct_definition array$33;

	extern s_tag_struct_definition array$50;

	extern s_tag_struct_definition array$49;

	extern s_tag_struct_definition array$34;

	extern s_tag_struct_definition array$36;

	extern s_tag_struct_definition array$37;

	extern s_tag_struct_definition array$38;

	extern s_tag_struct_definition array$39;

	extern s_tag_struct_definition array$40;

	extern s_tag_struct_definition array$41;

	extern s_tag_struct_definition background_animation_keyframe_reference_block_struct_definition;

	extern s_tag_struct_definition ball_and_socket_constraints_block_struct_definition;

	extern s_tag_struct_definition barrel_firing_effect_struct_definition;
	extern s_tag_reference_definition sound_group_effect_group_reference$2;
	extern s_tag_reference_definition damage_effect_group_reference;

	extern s_tag_struct_definition beam_block_struct_definition;
	extern s_tag_reference_definition shader_group_reference;

	extern s_tag_struct_definition behavior_names_block_struct_definition;

	extern s_tag_struct_definition biped_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$96;
	extern s_string_list_definition unnamed_enum$97;
	extern s_string_list_definition unnamed_enum$98;
	extern s_tag_reference_definition model_group_reference;
	extern s_tag_reference_definition crate_group_reference$2;
	extern s_tag_reference_definition material_effects_group_reference;
	extern s_string_list_definition unnamed_enum$106;
	extern s_string_list_definition unnamed_enum$107;
	extern s_string_list_definition unnamed_enum$108;
	extern s_tag_reference_definition character_group_reference$2;
	extern s_string_list_definition unnamed_enum$109;
	extern s_string_list_definition unnamed_enum$112;
	extern s_string_list_definition unnamed_enum$115;
	extern s_tag_reference_definition character_group_reference$3;
	extern s_string_list_definition unnamed_enum$119;

	extern s_tag_struct_definition biped_lock_on_data_struct_definition;
	extern s_string_list_definition unnamed_enum$116;

	extern s_tag_struct_definition bitmap_block_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$426;
	extern s_string_list_definition unnamed_enum$424;
	extern s_string_list_definition unnamed_enum$427;
	extern s_tag_reference_definition bitmap_group_reference;

	extern s_tag_struct_definition bitmap_block_struct_definition;
	extern s_string_list_definition unnamed_enum$120;
	extern s_string_list_definition unnamed_enum$121;
	extern s_string_list_definition unnamed_enum$122;
	extern s_string_list_definition unnamed_enum$123;
	extern s_string_list_definition unnamed_enum$124;
	extern s_string_list_definition unnamed_enum$125;
	extern s_string_list_definition unnamed_enum$126;
	extern s_string_list_definition unnamed_enum$132;

	extern s_tag_struct_definition bitmap_group_sequence_block_struct_definition;

	extern s_tag_struct_definition bitmap_group_sprite_block_struct_definition;

	extern s_tag_struct_definition bitmap_native_info_struct_struct_definition;

	extern s_tag_struct_definition bitmap_native_mipmap_info_block_struct_definition;

	extern s_tag_struct_definition bitmap_tags_struct_definition;
	extern s_string_list_definition unnamed_enum$127;
	extern s_string_list_definition unnamed_enum$128;
	extern s_string_list_definition unnamed_enum$129;
	extern s_string_list_definition unnamed_enum$130;
	extern s_string_list_definition unnamed_enum$131;

	extern s_tag_struct_definition boxes_block_struct_definition;
	extern s_string_list_definition unnamed_enum$118;

	extern s_tag_struct_definition breakable_surface_block_struct_definition;

	extern s_tag_struct_definition breakable_surface_key_table_block_struct_definition;

	extern s_tag_struct_definition bsp2d_nodes_block_struct_definition;

	extern s_tag_struct_definition bsp2d_references_block_struct_definition;

	extern s_tag_struct_definition bsp3d_nodes_block_struct_definition;

	extern s_tag_struct_definition bsp_leaf_block_struct_definition;

	extern s_tag_struct_definition bsp_surface_reference_block_struct_definition;

	extern s_tag_struct_definition button_widget_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$423;
	extern s_string_list_definition unnamed_enum$425;
	extern s_string_list_definition unnamed_enum$538;

	extern s_tag_struct_definition byte_block_struct_definition;

	extern s_tag_struct_definition cache_file_sound_block_struct_definition;
	extern s_string_list_definition unnamed_enum;
	extern s_string_list_definition unnamed_enum$2;

	extern s_tag_struct_definition cached_data_block_struct_definition$2;

	extern s_tag_struct_definition cached_data_block_struct_definition;

	extern s_tag_struct_definition camera_block_struct_definition;
	extern s_tag_reference_definition camera_track_group_reference;

	extern s_tag_struct_definition camera_track_block_struct_definition;
	extern s_string_list_definition unnamed_enum$496;

	extern s_tag_struct_definition camera_track_control_point_block_struct_definition;

	extern s_tag_struct_definition campaign_metagame_bucket_block_struct_definition;
	extern s_string_list_definition unnamed_enum$110;
	extern s_string_list_definition unnamed_enum$111;

	extern s_tag_struct_definition cellular_automata2d_block_struct_definition;
	extern s_string_list_definition unnamed_enum$104;

	extern s_tag_struct_definition cellular_automata_block_struct_definition;

	extern s_tag_struct_definition character_boarding_block_struct_definition;
	extern s_string_list_definition unnamed_enum$146;

	extern s_tag_struct_definition character_boss_block_struct_definition;

	extern s_tag_struct_definition character_cover_block_struct_definition;
	extern s_string_list_definition unnamed_enum$138;

	extern s_tag_struct_definition character_engage_block_struct_definition;
	extern s_string_list_definition unnamed_enum$142;

	extern s_tag_struct_definition character_evasion_block_struct_definition;

	extern s_tag_struct_definition character_firing_pattern_block_struct_definition;

	extern s_tag_struct_definition character_firing_pattern_properties_block_struct_definition;
	extern s_tag_reference_definition weapon_group_reference$5;

	extern s_tag_struct_definition character_general_block_struct_definition;
	extern s_string_list_definition unnamed_enum$135;
	extern s_string_list_definition unnamed_enum$136;

	extern s_tag_struct_definition character_grenades_block_struct_definition;
	extern s_string_list_definition unnamed_enum$150;

	extern s_tag_struct_definition character_idle_block_struct_definition;

	extern s_tag_struct_definition character_look_block_struct_definition;

	extern s_tag_struct_definition character_movement_block_struct_definition;
	extern s_string_list_definition unnamed_enum$139;
	extern s_string_list_definition unnamed_enum$140;
	extern s_string_list_definition unnamed_enum$101;
	extern s_string_list_definition unnamed_enum$141;

	extern s_tag_struct_definition character_palette_block_struct_definition;
	extern s_tag_reference_definition character_group_reference;

	extern s_tag_struct_definition character_perception_block_struct_definition;

	extern s_tag_struct_definition character_physics_dead_struct_struct_definition;

	extern s_tag_struct_definition character_physics_flying_struct_struct_definition;

	extern s_tag_struct_definition character_physics_ground_struct_struct_definition;

	extern s_tag_struct_definition character_physics_sentinel_struct_struct_definition;

	extern s_tag_struct_definition character_physics_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$117;

	extern s_tag_struct_definition character_placement_block_struct_definition;

	extern s_tag_struct_definition character_ready_block_struct_definition;

	extern s_tag_struct_definition character_retreat_block_struct_definition;
	extern s_string_list_definition unnamed_enum$144;
	extern s_tag_reference_definition weapon_group_reference$4;

	extern s_tag_struct_definition character_search_block_struct_definition;
	extern s_string_list_definition unnamed_enum$145;

	extern s_tag_struct_definition character_swarm_block_struct_definition;

	extern s_tag_struct_definition character_tag_v3_struct_definition;
	extern s_string_list_definition unnamed_enum$134;
	extern s_tag_reference_definition character_group_reference$4;
	extern s_tag_reference_definition unit_group_reference;
	extern s_tag_reference_definition creature_group_reference$3;
	extern s_tag_reference_definition style_group_reference$2;
	extern s_tag_reference_definition character_group_reference$5;

	extern s_tag_struct_definition character_variants_block_struct_definition;

	extern s_tag_struct_definition character_vitality_block_struct_definition;
	extern s_string_list_definition unnamed_enum$137;

	extern s_tag_struct_definition character_vocalization_block_struct_definition;

	extern s_tag_struct_definition charge_struct_definition;
	extern s_string_list_definition unnamed_enum$143;

	extern s_tag_struct_definition cheat_powerups_block_struct_definition;
	extern s_tag_reference_definition equipment_group_reference$2;

	extern s_tag_struct_definition cheat_weapons_block_struct_definition;
	extern s_tag_reference_definition item_group_reference;

	extern s_tag_struct_definition chocolate_mountain_block_struct_definition;

	extern s_tag_struct_definition cloth_block_struct_definition;
	extern s_string_list_definition unnamed_enum$156;

	extern s_tag_struct_definition cloth_indices_block_struct_definition;

	extern s_tag_struct_definition cloth_links_block_struct_definition;

	extern s_tag_struct_definition cloth_properties_struct_definition;
	extern s_string_list_definition unnamed_enum$157;

	extern s_tag_struct_definition cloth_vertices_block_struct_definition;

	extern s_tag_struct_definition cluster_door_portal_encoded_pas_block_struct_definition;

	extern s_tag_struct_definition collision_bsp_physics_block_struct_definition;

	extern s_tag_struct_definition collision_bsp_struct_definition;

	extern s_tag_struct_definition collision_damage_block_struct_definition;

	extern s_tag_struct_definition collision_edge_struct_definition;

	extern s_tag_struct_definition collision_model_bsp_block_struct_definition;

	extern s_tag_struct_definition collision_model_fields_current_struct_definition;
	extern s_string_list_definition unnamed_enum$160;

	extern s_tag_struct_definition collision_model_material_block_struct_definition;

	extern s_tag_struct_definition collision_model_node_fields_current_struct_definition;

	extern s_tag_struct_definition collision_model_pathfinding_sphere_block_struct_definition;
	extern s_string_list_definition unnamed_enum$163;

	extern s_tag_struct_definition collision_model_permutation_fields_current_struct_definition;

	extern s_tag_struct_definition collision_model_region_block_struct_definition;

	extern s_tag_struct_definition colony_block_struct_definition;
	extern s_string_list_definition unnamed_enum$164;

	extern s_tag_struct_definition color_block_struct_definition;

	extern s_tag_struct_definition color_function_struct_struct_definition;

	extern s_tag_struct_definition color_table_block_struct_definition;

	extern s_tag_struct_definition constraint_bodies_struct_struct_definition;

	extern s_tag_struct_definition contact_point_block_struct_definition;

	extern s_tag_struct_definition contact_point_block_v1_struct_definition;

	extern s_tag_struct_definition contrail_block_struct_definition;
	extern s_string_list_definition unnamed_enum$165;
	extern s_string_list_definition unnamed_enum$166;
	extern s_string_list_definition unnamed_enum$167;
	extern s_string_list_definition unnamed_enum$168;
	extern s_string_list_definition unnamed_enum$169;
	extern s_string_list_definition unnamed_enum$170;
	extern s_string_list_definition unnamed_enum$171;
	extern s_string_list_definition unnamed_enum$172;
	extern s_string_list_definition unnamed_enum$173;

	extern s_tag_struct_definition contrail_point_states_block_struct_definition;
	extern s_string_list_definition unnamed_enum$174;

	extern s_tag_struct_definition crate_block_struct_definition;
	extern s_string_list_definition unnamed_enum$133;

	extern s_tag_struct_definition create_new_variant_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$204;

	extern s_tag_struct_definition creature_block_struct_definition;
	extern s_string_list_definition unnamed_enum$175;
	extern s_string_list_definition unnamed_enum$176;

	extern s_tag_struct_definition cs_point_set_struct_definition;
	extern s_string_list_definition unnamed_enum$91;

	extern s_tag_struct_definition cs_point_struct_definition;

	extern s_tag_struct_definition cs_script_data_block_struct_definition;

	extern s_tag_struct_definition custom_references_block_struct_definition;
	extern s_tag_reference_definition _reference$2;

	extern s_tag_struct_definition damage_animation_block_struct_definition;

	extern s_tag_struct_definition damage_constraint_info_block_struct_definition;

	extern s_tag_struct_definition damage_direction_block_struct_definition;

	extern s_tag_struct_definition damage_effect_player_response_block_struct_definition;
	extern s_string_list_definition unnamed_enum$261;

	extern s_tag_struct_definition damage_effect_sound_effect_definition_struct_definition;

	extern s_tag_struct_definition damage_effect_struct_definition;
	extern s_string_list_definition unnamed_enum$257;
	extern s_string_list_definition unnamed_enum$258;
	extern s_string_list_definition unnamed_enum$259;
	extern s_string_list_definition unnamed_enum$260;
	extern s_string_list_definition unnamed_enum$264;
	extern s_string_list_definition unnamed_enum$262;
	extern s_string_list_definition unnamed_enum$263;

	extern s_tag_struct_definition damage_group_block_struct_definition;

	extern s_tag_struct_definition damage_outer_cone_angle_struct_definition;

	extern s_tag_struct_definition damage_region_block_struct_definition;

	extern s_tag_struct_definition damage_seat_info_block_struct_definition;

	extern s_tag_struct_definition decal_block_struct_definition;
	extern s_string_list_definition unnamed_enum$181;
	extern s_string_list_definition unnamed_enum$182;
	extern s_string_list_definition unnamed_enum$183;
	extern s_tag_reference_definition decal_group_reference$2;

	extern s_tag_struct_definition decal_vertices_block_struct_definition;

	extern s_tag_struct_definition decorator_cache_block_block_struct_definition;

	extern s_tag_struct_definition decorator_cache_block_data_v2_struct_definition;

	extern s_tag_struct_definition decorator_cache_definition_struct_definition;

	extern s_tag_struct_definition decorator_cell_collection_block_struct_definition;

	extern s_tag_struct_definition decorator_classes_block_struct_definition;
	extern s_string_list_definition unnamed_enum$31;

	extern s_tag_struct_definition decorator_group_block_struct_definition;

	extern s_tag_struct_definition decorator_model_indices_block_struct_definition;

	extern s_tag_struct_definition decorator_model_vertices_block_struct_definition;

	extern s_tag_struct_definition decorator_models_block_struct_definition;

	extern s_tag_struct_definition decorator_permutations_block_struct_definition;
	extern s_string_list_definition unnamed_enum$32;
	extern s_string_list_definition unnamed_enum$33;

	extern s_tag_struct_definition decorator_placement_block_struct_definition;

	extern s_tag_struct_definition decorator_projected_decal_block_struct_definition;

	extern s_tag_struct_definition decorator_set_struct_definition;

	extern s_tag_struct_definition decorator_shader_reference_block_struct_definition;

	extern s_tag_struct_definition detail_object_collection_block_struct_definition;
	extern s_string_list_definition unnamed_enum$187;

	extern s_tag_struct_definition detail_object_type_block_struct_definition;
	extern s_string_list_definition unnamed_enum$188;

	extern s_tag_struct_definition device_block_struct_definition;
	extern s_string_list_definition unnamed_enum$177;
	extern s_string_list_definition unnamed_enum$178;
	extern s_tag_reference_definition sound_group_effect_group_reference;

	extern s_tag_struct_definition device_control_block_struct_definition;
	extern s_string_list_definition unnamed_enum$179;
	extern s_string_list_definition unnamed_enum$180;

	extern s_tag_struct_definition device_group_block_struct_definition;
	extern s_string_list_definition unnamed_enum$184;

	extern s_tag_struct_definition device_light_fixture_block_struct_definition;

	extern s_tag_struct_definition device_machine_block_struct_definition;
	extern s_string_list_definition unnamed_enum$297;
	extern s_string_list_definition unnamed_enum$298;
	extern s_string_list_definition unnamed_enum$299;
	extern s_string_list_definition unnamed_enum$300;

	extern s_tag_struct_definition dialogue_data_block_struct_definition;

	extern s_tag_struct_definition dialogue_variant_block_struct_definition;
	extern s_tag_reference_definition dialogue_group_reference;

	extern s_tag_struct_definition difficulty_block_struct_definition;

	extern s_tag_struct_definition dont_use_me_scenario_environment_object_block_struct_definition;

	extern s_tag_struct_definition door_encoded_pas_block_struct_definition;

	extern s_tag_struct_definition dynamic_spawn_zone_overload_block_struct_definition;
	extern s_string_list_definition unnamed_enum$408;

	extern s_tag_struct_definition editor_comment_block_struct_definition;
	extern s_string_list_definition unnamed_enum$24;

	extern s_tag_struct_definition effect_accelerations_block_struct_definition;
	extern s_string_list_definition unnamed_enum$40;
	extern s_string_list_definition unnamed_enum$41;

	extern s_tag_struct_definition effect_block_struct_definition;
	extern s_string_list_definition unnamed_enum$189;
	extern s_tag_reference_definition sound_looping_group_reference;

	extern s_tag_struct_definition effect_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$190;

	extern s_tag_struct_definition effect_locations_block_struct_definition;

	extern s_tag_struct_definition effect_part_block_struct_definition;
	extern s_string_list_definition unnamed_enum$191;
	extern s_tag_reference_definition damage_effect_group_object_group_sound_group_decal_group_colony_group_light_group_light_volume_group_liquid_group_lens_flare_group_character_group_reference;
	extern s_string_list_definition unnamed_enum$192;

	extern s_tag_struct_definition encoded_cluster_distances_block_struct_definition;

	extern s_tag_struct_definition environment_object_bsp_ref_struct_definition;

	extern s_tag_struct_definition environment_object_node_ref_struct_definition;
	extern s_string_list_definition unnamed_enum$375;

	extern s_tag_struct_definition environment_object_ref_struct_definition;
	extern s_string_list_definition unnamed_enum$374;

	extern s_tag_struct_definition equipment_block_struct_definition;
	extern s_string_list_definition unnamed_enum$197;
	extern s_string_list_definition unnamed_enum$198;

	extern s_tag_struct_definition error_report_comments_block_struct_definition;

	extern s_tag_struct_definition error_report_lines_block_struct_definition;

	extern s_tag_struct_definition error_report_quads_block_struct_definition;

	extern s_tag_struct_definition error_report_triangles_block_struct_definition;

	extern s_tag_struct_definition error_report_vectors_block_struct_definition;

	extern s_tag_struct_definition error_report_vertices_block_struct_definition;

	extern s_tag_struct_definition error_reports_block_struct_definition;
	extern s_string_list_definition unnamed_enum$158;
	extern s_string_list_definition unnamed_enum$159;

	extern s_tag_struct_definition extern_reference_block_struct_definition;

	extern s_tag_struct_definition falling_damage_block_struct_definition;

	extern s_tag_struct_definition firing_position_struct_definition;
	extern s_string_list_definition unnamed_enum$73;

	extern s_tag_struct_definition flight_reference_block_struct_definition;

	extern s_tag_struct_definition flock_definition_block_struct_definition;
	extern s_string_list_definition unnamed_enum$95;
	extern s_tag_reference_definition creature_group_reference$2;

	extern s_tag_struct_definition flock_sink_block_struct_definition;

	extern s_tag_struct_definition flock_source_block_struct_definition;

	extern s_tag_struct_definition friction_point_definition_block_struct_definition;
	extern s_string_list_definition unnamed_enum$513;
	extern s_string_list_definition unnamed_enum$514;
	extern s_string_list_definition unnamed_enum$223;

	extern s_tag_struct_definition function_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$28;

	extern s_tag_struct_definition g_default_variant_settings_block_struct_definition;
	extern s_string_list_definition unnamed_enum$205;

	extern s_tag_struct_definition g_default_variants_block_struct_definition;

	extern s_tag_struct_definition g_dialogue_definition_struct_definition;
	extern s_tag_reference_definition ai_dialogue_globals_group_reference$2;
	extern s_string_list_definition unnamed_enum$497;

	extern s_tag_struct_definition g_new_scenario_object_datum_struct_definition;
	extern s_string_list_definition unnamed_enum$4;
	extern s_string_list_definition unnamed_enum$5;
	extern s_string_list_definition unnamed_enum$8;

	extern s_tag_struct_definition g_null_block_struct_definition;

	extern s_tag_struct_definition g_scenario_editor_folder_block_struct_definition;

	extern s_tag_struct_definition g_sound_effect_override_parameters_struct_definition;

	extern s_tag_struct_definition g_sound_effect_template_collection_struct_definition;
	extern s_string_list_definition unnamed_enum$25;

	extern s_tag_struct_definition g_sound_effect_template_struct_definition;

	extern s_tag_struct_definition g_sound_permutation_chunk_struct_definition;

	extern s_tag_struct_definition g_vocalization_fields_v2_0_struct_definition;
	extern s_string_list_definition unnamed_enum$45;
	extern s_string_list_definition unnamed_enum$46;
	extern s_string_list_definition unnamed_enum$47;
	extern s_string_list_definition unnamed_enum$48;
	extern s_string_list_definition unnamed_enum$49;
	extern s_string_list_definition unnamed_enum$50;
	extern s_string_list_definition unnamed_enum$51;

	extern s_tag_struct_definition g_vocalization_fields_v2_1_struct_definition;

	extern s_tag_struct_definition g_vocalization_fields_v2_2_struct_definition;

	extern s_tag_struct_definition g_vocalization_fields_v2_3_struct_definition;

	extern s_tag_struct_definition g_vocalization_fields_v2_4_struct_definition;

	extern s_tag_struct_definition g_vocalization_fields_v2_5_struct_definition;

	extern s_tag_struct_definition g_vocalization_sound_references_struct_definition;
	extern s_string_list_definition unnamed_enum$498;
	extern s_tag_reference_definition sound_group_reference$3;

	extern s_tag_struct_definition game_engine_assault_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$303;
	extern s_string_list_definition unnamed_enum$326;
	extern s_string_list_definition unnamed_enum$305;
	extern s_string_list_definition unnamed_enum$306;
	extern s_string_list_definition unnamed_enum$307;

	extern s_tag_struct_definition game_engine_ctf_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$309;

	extern s_tag_struct_definition game_engine_flavor_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$323;

	extern s_tag_struct_definition game_engine_general_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$304;

	extern s_tag_struct_definition game_engine_juggernaut_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$324;

	extern s_tag_struct_definition game_engine_king_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$311;

	extern s_tag_struct_definition game_engine_oddball_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$310;

	extern s_tag_struct_definition game_engine_slayer_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$308;

	extern s_tag_struct_definition game_engine_status_response_block_struct_definition;
	extern s_string_list_definition unnamed_enum$327;
	extern s_string_list_definition unnamed_enum$328;
	extern s_tag_reference_definition _reference$4;

	extern s_tag_struct_definition game_engine_territories_event_block_struct_definition;
	extern s_string_list_definition unnamed_enum$325;

	extern s_tag_struct_definition game_globals_damage_block_struct_definition;

	extern s_tag_struct_definition game_portal_to_portal_mapping_block_struct_definition;

	extern s_tag_struct_definition garbage_block_struct_definition;

	extern s_tag_struct_definition gear_block_struct_definition;

	extern s_tag_struct_definition geometry_section_fieldset_new_struct_definition;

	extern s_tag_struct_definition gloal_wind_primitives_block_struct_definition;
	extern s_string_list_definition unnamed_enum$534;

	extern s_tag_struct_definition global_damage_info_block_struct_definition;
	extern s_string_list_definition unnamed_enum$227;
	extern s_string_list_definition unnamed_enum$228;

	extern s_tag_struct_definition global_damage_nodes_block_struct_definition;

	extern s_tag_struct_definition global_damage_section_block_struct_definition;
	extern s_string_list_definition unnamed_enum$229;

	extern s_tag_struct_definition global_detail_object_block_struct_definition;

	extern s_tag_struct_definition global_detail_object_cells_block_struct_definition;

	extern s_tag_struct_definition global_detail_object_counts_block_struct_definition;

	extern s_tag_struct_definition global_error_report_categories_block_struct_definition;

	extern s_tag_struct_definition global_geometry_block_info_struct_struct_definition;

	extern s_tag_struct_definition global_geometry_block_resource_block_struct_definition;
	extern s_string_list_definition unnamed_enum$30;

	extern s_tag_struct_definition global_geometry_compression_info_block_struct_definition;

	extern s_tag_struct_definition global_geometry_explicit_edge_block_struct_definition;

	extern s_tag_struct_definition global_geometry_isq_info_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$320;

	extern s_tag_struct_definition global_geometry_material_block_struct_definition;

	extern s_tag_struct_definition global_geometry_material_property_block_struct_definition;
	extern s_string_list_definition unnamed_enum$322;

	extern s_tag_struct_definition global_geometry_part_block_new_struct_definition;
	extern s_string_list_definition unnamed_enum$290;
	extern s_string_list_definition unnamed_enum$291;

	extern s_tag_struct_definition global_geometry_part_block_struct_definition;
	extern s_string_list_definition unnamed_enum$292;
	extern s_string_list_definition unnamed_enum$293;

	extern s_tag_struct_definition global_geometry_plane_block_struct_definition;

	extern s_tag_struct_definition global_geometry_point_data_index_block_struct_definition;

	extern s_tag_struct_definition global_geometry_point_data_struct_struct_definition;

	extern s_tag_struct_definition global_geometry_raw_point_block_struct_definition;

	extern s_tag_struct_definition global_geometry_rigid_plane_group_block_struct_definition;

	extern s_tag_struct_definition global_geometry_rigid_point_group_block_struct_definition;

	extern s_tag_struct_definition global_geometry_section_info_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$287;
	extern s_string_list_definition unnamed_enum$288;
	extern s_string_list_definition unnamed_enum$289;

	extern s_tag_struct_definition global_geometry_section_raw_vertex_block_struct_definition;

	extern s_tag_struct_definition global_geometry_section_strip_index_block_struct_definition;

	extern s_tag_struct_definition global_geometry_section_vertex_buffer_block_struct_definition;

	extern s_tag_struct_definition global_hud_multitexture_overlay_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$209;
	extern s_string_list_definition unnamed_enum$210;
	extern s_string_list_definition unnamed_enum$211;

	extern s_tag_struct_definition global_hud_multitexture_overlay_effector_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$212;
	extern s_string_list_definition unnamed_enum$213;
	extern s_string_list_definition unnamed_enum$214;

	extern s_tag_struct_definition global_hud_screen_effect_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$560;
	extern s_string_list_definition unnamed_enum$561;
	extern s_tag_reference_definition screen_effect_group_reference;

	extern s_tag_struct_definition global_leaf_connection_block_struct_definition;

	extern s_tag_struct_definition global_map_leaf_block_struct_definition;

	extern s_tag_struct_definition global_new_hud_globals_constants_struct_struct_definition;
	extern s_tag_reference_definition sound_group_sound_looping_group_reference$2;

	extern s_tag_struct_definition global_new_hud_globals_struct_struct_definition;
	extern s_tag_reference_definition multilingual_unicode_string_list_group_reference;

	extern s_tag_struct_definition global_particle_system_lite_block_struct_definition;
	extern s_string_list_definition unnamed_enum$532;

	extern s_tag_struct_definition global_scenario_load_parameters_block_struct_definition;
	extern s_tag_reference_definition scenario_group_reference;

	extern s_tag_struct_definition global_shader_parameter_block_struct_definition;
	extern s_string_list_definition unnamed_enum$365;

	extern s_tag_struct_definition global_subparts_block_struct_definition;

	extern s_tag_struct_definition global_tag_import_info_block_struct_definition;

	extern s_tag_struct_definition global_ui_campaign_level_block_struct_definition;

	extern s_tag_struct_definition global_ui_multiplayer_level_block_struct_definition;
	extern s_string_list_definition unnamed_enum$314;

	extern s_tag_struct_definition global_visibility_bounds_block_struct_definition;

	extern s_tag_struct_definition global_water_definitions_block_struct_definition;

	extern s_tag_struct_definition global_weather_background_plate_block_struct_definition;
	extern s_string_list_definition unnamed_enum$533;

	extern s_tag_struct_definition global_wind_model_struct_struct_definition;

	extern s_tag_struct_definition global_z_reference_vector_block_struct_definition;

	extern s_tag_struct_definition globals_block_struct_definition;
	extern s_string_list_definition unnamed_enum$301;
	extern s_tag_reference_definition multiplayer_globals_group_reference;
	extern s_tag_reference_definition chocolate_mountain_group_reference;

	extern s_tag_struct_definition grenade_and_powerup_struct_definition;

	extern s_tag_struct_definition grenade_block_struct_definition;

	extern s_tag_struct_definition grenade_hud_interface_block_struct_definition;
	extern s_string_list_definition unnamed_enum$206;
	extern s_string_list_definition unnamed_enum$207;
	extern s_string_list_definition unnamed_enum$208;
	extern s_string_list_definition unnamed_enum$215;
	extern s_string_list_definition unnamed_enum$219;

	extern s_tag_struct_definition grenade_hud_overlay_block_struct_definition;
	extern s_string_list_definition unnamed_enum$216;
	extern s_string_list_definition unnamed_enum$217;

	extern s_tag_struct_definition grenade_hud_sound_block_struct_definition;
	extern s_string_list_definition unnamed_enum$218;

	extern s_tag_struct_definition grenades_block_struct_definition;
	extern s_tag_reference_definition projectile_group_reference;

	extern s_tag_struct_definition havok_cleanup_resources_block_struct_definition;

	extern s_tag_struct_definition havok_vehicle_physics_struct_definition;
	extern s_string_list_definition unnamed_enum$511;

	extern s_tag_struct_definition hinge_constraints_block_struct_definition;

	extern s_tag_struct_definition hints_v2_struct_definition;
	extern s_string_list_definition unnamed_enum$376;

	extern s_tag_struct_definition hs_globals_block_struct_definition;
	extern s_string_list_definition unnamed_enum$405;

	extern s_tag_struct_definition hs_references_block_struct_definition;
	extern s_tag_reference_definition _reference$5;

	extern s_tag_struct_definition hs_scripts_block_struct_definition;
	extern s_string_list_definition unnamed_enum$404;

	extern s_tag_struct_definition hs_source_files_block_struct_definition;

	extern s_tag_struct_definition hs_unit_seat_block_struct_definition;

	extern s_tag_struct_definition hud_bitmap_widgets_struct_definition;
	extern s_string_list_definition unnamed_enum$334;
	extern s_string_list_definition unnamed_enum$335;
	extern s_string_list_definition unnamed_enum$337;

	extern s_tag_struct_definition hud_block_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$428;

	extern s_tag_struct_definition hud_button_icon_block_struct_definition;

	extern s_tag_struct_definition hud_dashlights_block_struct_definition;
	extern s_string_list_definition unnamed_enum$239;

	extern s_tag_struct_definition hud_globals_block_struct_definition;
	extern s_tag_reference_definition hud_message_text_group_reference;

	extern s_tag_struct_definition hud_message_elements_block_struct_definition;

	extern s_tag_struct_definition hud_message_text_block_struct_definition;

	extern s_tag_struct_definition hud_messages_block_struct_definition;

	extern s_tag_struct_definition hud_number_block_struct_definition;

	extern s_tag_struct_definition hud_screen_effect_widgets_struct_definition;
	extern s_string_list_definition unnamed_enum$341;

	extern s_tag_struct_definition hud_text_widgets_struct_definition;
	extern s_string_list_definition unnamed_enum$338;
	extern s_string_list_definition unnamed_enum$339;
	extern s_string_list_definition unnamed_enum$340;

	extern s_tag_struct_definition hud_waypoint_arrow_block_struct_definition;
	extern s_string_list_definition unnamed_enum$238;

	extern s_tag_struct_definition hud_waypoint_arrow_block_struct_definition$2;

	extern s_tag_struct_definition hud_waypoint_block_struct_definition;

	extern s_tag_struct_definition hud_widget_effect_block_struct_definition;
	extern s_string_list_definition unnamed_enum$336;

	extern s_tag_struct_definition hud_widget_effect_function_struct_struct_definition;

	extern s_tag_struct_definition hud_widget_inputs_struct_definition;
	extern s_string_list_definition unnamed_enum$329;

	extern s_tag_struct_definition hud_widget_state_definition_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$330;
	extern s_string_list_definition unnamed_enum$331;
	extern s_string_list_definition unnamed_enum$332;
	extern s_string_list_definition unnamed_enum$333;

	extern s_tag_struct_definition indices_block_struct_definition;

	extern s_tag_struct_definition inertial_matrix_block_struct_definition;

	extern s_tag_struct_definition inherited_animation_block_struct_definition;

	extern s_tag_struct_definition inherited_animation_node_map_block_struct_definition;

	extern s_tag_struct_definition inherited_animation_node_map_flag_block_struct_definition;

	extern s_tag_struct_definition instanced_geometry_instance_struct_definition;
	extern s_string_list_definition unnamed_enum$382;
	extern s_string_list_definition unnamed_enum$383;
	extern s_string_list_definition unnamed_enum$384;

	extern s_tag_struct_definition instanced_geometry_reference_block_struct_definition;

	extern s_tag_struct_definition instantaneous_damage_repsonse_block_struct_definition;
	extern s_string_list_definition unnamed_enum$230;
	extern s_string_list_definition unnamed_enum$231;
	extern s_string_list_definition unnamed_enum$232;

	extern s_tag_struct_definition instantaneous_response_damage_effect_marker_struct_definition;

	extern s_tag_struct_definition instantaneous_response_damage_effect_struct_definition;

	extern s_tag_struct_definition interface_tag_references_struct_definition;
	extern s_tag_reference_definition color_table_group_reference;
	extern s_tag_reference_definition hud_globals_group_reference;
	extern s_tag_reference_definition hud_number_group_reference;
	extern s_tag_reference_definition user_interface_globals_definition_group_reference;

	extern s_tag_struct_definition involuntary_data_block_struct_definition;

	extern s_tag_struct_definition item_block_struct_definition;

	extern s_tag_struct_definition item_collection_block_struct_definition;

	extern s_tag_struct_definition item_permutation_struct_definition;

	extern s_tag_struct_definition large_bsp2d_nodes_block_struct_definition;

	extern s_tag_struct_definition large_bsp2d_references_block_struct_definition;

	extern s_tag_struct_definition large_bsp3d_nodes_block_struct_definition;

	extern s_tag_struct_definition large_edges_block_struct_definition;

	extern s_tag_struct_definition large_leaves_block_struct_definition;
	extern s_string_list_definition unnamed_enum$161;

	extern s_tag_struct_definition large_sound_permutations_block_struct_definition;
	extern s_string_list_definition unnamed_enum$445;

	extern s_tag_struct_definition large_sound_pitch_range_block_struct_definition;

	extern s_tag_struct_definition large_sound_playback_parameters_struct_definition;
	extern s_string_list_definition unnamed_enum$443;

	extern s_tag_struct_definition large_sound_scale_modifiers_struct_struct_definition;

	extern s_tag_struct_definition large_surfaces_block_struct_definition;
	extern s_string_list_definition unnamed_enum$162;

	extern s_tag_struct_definition large_vertices_block_struct_definition;

	extern s_tag_struct_definition leaf_connection_vertex_block_struct_definition;

	extern s_tag_struct_definition leaves_block_struct_definition;

	extern s_tag_struct_definition lens_flare_block_struct_definition;
	extern s_string_list_definition unnamed_enum$265;
	extern s_string_list_definition unnamed_enum$266;
	extern s_string_list_definition unnamed_enum$267;
	extern s_string_list_definition unnamed_enum$268;
	extern s_string_list_definition unnamed_enum$270;

	extern s_tag_struct_definition lens_flare_color_animation_block_struct_definition;

	extern s_tag_struct_definition lens_flare_reflection_block_struct_definition;
	extern s_string_list_definition unnamed_enum$269;

	extern s_tag_struct_definition lens_flare_scalar_animation_block_struct_definition;

	extern s_tag_struct_definition light_block_struct_definition;
	extern s_string_list_definition unnamed_enum$271;
	extern s_string_list_definition unnamed_enum$18;
	extern s_string_list_definition unnamed_enum$272;
	extern s_string_list_definition unnamed_enum$273;
	extern s_string_list_definition unnamed_enum$274;
	extern s_string_list_definition unnamed_enum$275;
	extern s_string_list_definition unnamed_enum$276;
	extern s_string_list_definition unnamed_enum$277;
	extern s_tag_reference_definition lens_flare_group_reference;
	extern s_tag_reference_definition light_volume_group_reference;
	extern s_string_list_definition unnamed_enum$278;
	extern s_string_list_definition unnamed_enum$279;
	extern s_string_list_definition unnamed_enum$280;

	extern s_tag_struct_definition light_brightness_animation_block_struct_definition;

	extern s_tag_struct_definition light_color_animation_block_struct_definition;

	extern s_tag_struct_definition light_gel_animation_block_struct_definition;

	extern s_tag_struct_definition light_volume_aspect_block_struct_definition;

	extern s_tag_struct_definition light_volume_block_struct_definition;

	extern s_tag_struct_definition light_volume_runtime_offset_block_struct_definition;

	extern s_tag_struct_definition light_volume_volume_block_struct_definition;
	extern s_string_list_definition unnamed_enum$34;

	extern s_tag_struct_definition lighting_variables_block_struct_definition;
	extern s_string_list_definition unnamed_enum$202;

	extern s_tag_struct_definition lightmap_bucket_raw_vertex_block_struct_definition;

	extern s_tag_struct_definition lightmap_geometry_render_info_block_struct_definition;

	extern s_tag_struct_definition lightmap_geometry_section_block_struct_definition;

	extern s_tag_struct_definition lightmap_geometry_section_cache_data_block_struct_definition;

	extern s_tag_struct_definition lightmap_instance_bucket_reference_block_struct_definition;

	extern s_tag_struct_definition lightmap_instance_bucket_section_offset_block_struct_definition;

	extern s_tag_struct_definition lightmap_scenery_object_info_block_struct_definition;

	extern s_tag_struct_definition lightmap_shadows_struct_struct_definition;

	extern s_tag_struct_definition lightmap_vertex_buffer_bucket_block_struct_definition;
	extern s_string_list_definition unnamed_enum$296;

	extern s_tag_struct_definition lightmap_vertex_buffer_bucket_cache_data_block_struct_definition;

	extern s_tag_struct_definition limited_hinge_constraints_block_struct_definition;

	extern s_tag_struct_definition links_v2_struct_definition;
	extern s_string_list_definition unnamed_enum$373;

	extern s_tag_struct_definition liquid_arc_block_struct_definition;
	extern s_string_list_definition unnamed_enum$493;
	extern s_string_list_definition unnamed_enum$494;
	extern s_string_list_definition unnamed_enum$495;

	extern s_tag_struct_definition liquid_block_struct_definition;
	extern s_string_list_definition unnamed_enum$492;

	extern s_tag_struct_definition liquid_core_block_struct_definition;

	extern s_tag_struct_definition list_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$539;
	extern s_string_list_definition unnamed_enum$540;

	extern s_tag_struct_definition list_shapes_block_struct_definition;

	extern s_tag_struct_definition list_skin_reference_block_struct_definition;
	extern s_tag_reference_definition user_interface_list_skin_definition_group_reference;

	extern s_tag_struct_definition lists_block_struct_definition;

	extern s_tag_struct_definition local_bitmap_reference_block_struct_definition;

	extern s_tag_struct_definition local_string_id_list_section_reference_block_struct_definition;

	extern s_tag_struct_definition local_string_id_list_string_reference_block_struct_definition;

	extern s_tag_struct_definition long_block_struct_definition;

	extern s_tag_struct_definition look_function_block_struct_definition;

	extern s_tag_struct_definition looping_sound_detail_struct_definition;
	extern s_string_list_definition unnamed_enum$284;

	extern s_tag_struct_definition looping_sound_struct_definition;
	extern s_string_list_definition unnamed_enum$281;
	extern s_tag_reference_definition _reference;

	extern s_tag_struct_definition looping_sound_track_struct_definition;
	extern s_string_list_definition unnamed_enum$282;
	extern s_string_list_definition unnamed_enum$283;

	extern s_tag_struct_definition map_leaf_connection_index_block_struct_definition;

	extern s_tag_struct_definition map_leaf_face_block_struct_definition;

	extern s_tag_struct_definition map_leaf_face_vertex_block_struct_definition;

	extern s_tag_struct_definition mass_distributions_block_struct_definition;

	extern s_tag_struct_definition mass_point_block_struct_definition;
	extern s_string_list_definition unnamed_enum$353;
	extern s_string_list_definition unnamed_enum$354;

	extern s_tag_struct_definition material_effect_block_v1_struct_definition;

	extern s_tag_struct_definition material_effect_block_v2_struct_definition;

	extern s_tag_struct_definition material_effect_material_block_old_v1_struct_definition;
	extern s_tag_reference_definition sound_group_sound_looping_group_reference;
	extern s_string_list_definition unnamed_enum$200;

	extern s_tag_struct_definition material_effect_material_struct_definition;
	extern s_tag_reference_definition sound_group_sound_looping_group_effect_group_reference;

	extern s_tag_struct_definition material_effects_struct_definition;

	extern s_tag_struct_definition material_physics_block_struct_definition;

	extern s_tag_struct_definition material_physics_properties_struct_definition;

	extern s_tag_struct_definition materials_block_struct_definition$2;
	extern s_string_list_definition unnamed_enum$350;

	extern s_tag_struct_definition materials_block_struct_definition;
	extern s_string_list_definition unnamed_enum$312;
	extern s_string_list_definition unnamed_enum$226;
	extern s_tag_reference_definition material_physics_group_reference;
	extern s_tag_reference_definition breakable_surface_group_reference;

	extern s_tag_struct_definition materials_sweeteners_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$313;

	extern s_tag_struct_definition melee_aim_assist_struct_definition;

	extern s_tag_struct_definition melee_damage_parameters_struct_definition;

	extern s_tag_struct_definition meter_block_struct_definition;
	extern s_string_list_definition unnamed_enum$315;
	extern s_tag_reference_definition bitmap_group_reference$5;
	extern s_string_list_definition unnamed_enum$316;
	extern s_string_list_definition unnamed_enum$317;

	extern s_tag_struct_definition mission_dialogue_lines_block_struct_definition;

	extern s_tag_struct_definition mission_dialogue_variants_block_struct_definition;
	extern s_tag_reference_definition sound_group_reference$2;

	extern s_tag_struct_definition model_animation_graph_block_struct_definition;

	extern s_tag_struct_definition model_animation_runtime_data_struct_struct_definition;

	extern s_tag_struct_definition model_group_struct_definition;
	extern s_tag_reference_definition render_model_group_reference;
	extern s_tag_reference_definition collision_model_group_reference;
	extern s_tag_reference_definition physics_group_reference;
	extern s_tag_reference_definition physics_model_group_reference;
	extern s_string_list_definition unnamed_enum$220;
	extern s_tag_reference_definition dialogue_group_reference$2;
	extern s_string_list_definition unnamed_enum$236;
	extern s_string_list_definition unnamed_enum$237;

	extern s_tag_struct_definition model_material_block_struct_definition;

	extern s_tag_struct_definition model_node_block_struct_definition;

	extern s_tag_struct_definition model_object_data_block_struct_definition;
	extern s_string_list_definition unnamed_enum$235;

	extern s_tag_struct_definition model_permutation_block_struct_definition;
	extern s_string_list_definition unnamed_enum$234;

	extern s_tag_struct_definition model_region_block_struct_definition;

	extern s_tag_struct_definition model_target_block_struct_definition;

	extern s_tag_struct_definition model_target_lock_on_data_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$233;

	extern s_tag_struct_definition model_variant_block_struct_definition;

	extern s_tag_struct_definition model_variant_object_block_struct_definition;
	extern s_tag_reference_definition object_group_reference;

	extern s_tag_struct_definition model_variant_permutation_block_struct_definition;
	extern s_string_list_definition unnamed_enum$221;

	extern s_tag_struct_definition model_variant_region_block_struct_definition;
	extern s_string_list_definition unnamed_enum$225;

	extern s_tag_struct_definition model_variant_state_struct_definition;
	extern s_string_list_definition unnamed_enum$222;
	extern s_tag_reference_definition effect_group_reference$2;
	extern s_string_list_definition unnamed_enum$224;

	extern s_tag_struct_definition mopps_block_struct_definition;

	extern s_tag_struct_definition mouse_cursor_bitmap_reference_block_struct_definition;

	extern s_tag_struct_definition mouse_cursor_definition_block_struct_definition;

	extern s_tag_struct_definition move_positions_block_struct_definition;

	extern s_tag_struct_definition multi_spheres_block_struct_definition;

	extern s_tag_struct_definition multilingual_unicode_string_list_block_struct_definition;

	extern s_tag_struct_definition multilingual_unicode_string_reference_block_struct_definition;

	extern s_tag_struct_definition multiplayer_color_block_struct_definition;

	extern s_tag_struct_definition multiplayer_color_block_struct_definition$2;

	extern s_tag_struct_definition multiplayer_constants_block_struct_definition;

	extern s_tag_struct_definition multiplayer_globals_block_struct_definition;

	extern s_tag_struct_definition multiplayer_information_block_struct_definition;
	extern s_tag_reference_definition unit_group_reference$3;

	extern s_tag_struct_definition multiplayer_runtime_global_struct_definition;
	extern s_tag_reference_definition unit_group_reference$5;
	extern s_tag_reference_definition item_collection_group_reference;
	extern s_tag_reference_definition new_hud_definition_group_reference;

	extern s_tag_struct_definition multiplayer_scenario_description_block_struct_definition;

	extern s_tag_struct_definition multiplayer_ui_block_struct_definition;

	extern s_tag_struct_definition multiplayer_universal_block_struct_definition;

	extern s_tag_struct_definition multiplayer_variant_settings_interface_definition_block_struct_definition;
	extern s_tag_reference_definition user_interface_screen_widget_definition_group_reference;

	extern s_tag_struct_definition new_hud_dashlight_data_struct_struct_definition;

	extern s_tag_struct_definition new_hud_definition_block_struct_definition;

	extern s_tag_struct_definition new_hud_sound_block_struct_definition;
	extern s_string_list_definition unnamed_enum$240;

	extern s_tag_struct_definition node_render_leaves_block_struct_definition;

	extern s_tag_struct_definition nodes_block_struct_definition;
	extern s_string_list_definition unnamed_enum$351;

	extern s_tag_struct_definition null_block_struct_definition;

	extern s_tag_struct_definition object_ai_properties_block_struct_definition;
	extern s_string_list_definition unnamed_enum$99;
	extern s_string_list_definition unnamed_enum$100;

	extern s_tag_struct_definition object_animation_block_struct_definition;
	extern s_string_list_definition unnamed_enum$256;

	extern s_tag_struct_definition object_attachment_block_struct_definition;
	extern s_tag_reference_definition light_group_light_volume_group_liquid_group_contrail_group_effect_group_sound_looping_group_lens_flare_group_reference;
	extern s_string_list_definition unnamed_enum$103;

	extern s_tag_struct_definition object_block_struct_definition;

	extern s_tag_struct_definition object_change_color_function_struct_definition;

	extern s_tag_struct_definition object_change_color_initial_permutation_struct_definition;

	extern s_tag_struct_definition object_change_colors_struct_definition;

	extern s_tag_struct_definition object_function_block_struct_definition;
	extern s_string_list_definition unnamed_enum$102;

	extern s_tag_struct_definition object_space_node_data_block_struct_definition;
	extern s_string_list_definition unnamed_enum$254;

	extern s_tag_struct_definition object_space_node_data_block_v0_struct_definition;

	extern s_tag_struct_definition object_widget_block_struct_definition;
	extern s_tag_reference_definition antenna_group_cloth_group_cellular_automata_group_cellular_automata2d_group_stereo_system_group_liquid_group_reference;

	extern s_tag_struct_definition occluder_to_machine_door_mapping_struct_definition;

	extern s_tag_struct_definition old_material_effect_material_block_struct_definition;

	extern s_tag_struct_definition old_materials_block_struct_definition;

	extern s_tag_struct_definition old_object_function_block_struct_definition;

	extern s_tag_struct_definition old_scenario_device_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$17;

	extern s_tag_struct_definition old_scenario_unit_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$16;

	extern s_tag_struct_definition old_sound_permutation_info_block_struct_definition;

	extern s_tag_struct_definition old_sound_permutations_block_struct_definition;

	extern s_tag_struct_definition old_sound_pitch_range_block_struct_definition;

	extern s_tag_struct_definition old_unused_object_identifiers_block_struct_definition;

	extern s_tag_struct_definition old_unused_strucure_physics_block_struct_definition;

	extern s_tag_struct_definition order_completion_block_struct_definition;

	extern s_tag_struct_definition order_completion_condition_struct_definition;
	extern s_string_list_definition unnamed_enum$86;
	extern s_string_list_definition unnamed_enum$87;

	extern s_tag_struct_definition order_ending_block_struct_definition;
	extern s_string_list_definition unnamed_enum$83;

	extern s_tag_struct_definition orders_v3_struct_definition;
	extern s_string_list_definition unnamed_enum$79;
	extern s_string_list_definition unnamed_enum$80;

	extern s_tag_struct_definition packed_data_sizes_struct_struct_definition;

	extern s_tag_struct_definition particle_block_struct_definition;
	extern s_string_list_definition unnamed_enum$35;
	extern s_string_list_definition unnamed_enum$36;
	extern s_tag_reference_definition shader_template_group_reference;
	extern s_tag_reference_definition effect_group_sound_group_material_effects_group_reference$2;

	extern s_tag_struct_definition particle_controller_parameters_struct_definition;

	extern s_tag_struct_definition particle_controller_struct_definition;
	extern s_string_list_definition unnamed_enum$356;

	extern s_tag_struct_definition particle_model_block_struct_definition;
	extern s_tag_reference_definition effect_group_sound_group_material_effects_group_reference;

	extern s_tag_struct_definition particle_model_indices_block_struct_definition;

	extern s_tag_struct_definition particle_model_vertices_block_struct_definition;

	extern s_tag_struct_definition particle_models_block_struct_definition;

	extern s_tag_struct_definition particle_physics_block_struct_definition;
	extern s_tag_reference_definition particle_physics_group_reference$2;
	extern s_string_list_definition unnamed_enum$355;

	extern s_tag_struct_definition particle_property_color_struct_new_struct_definition;
	extern s_string_list_definition unnamed_enum$37;
	extern s_string_list_definition unnamed_enum$38;

	extern s_tag_struct_definition particle_property_scalar_struct_new_struct_definition;

	extern s_tag_struct_definition particle_system_definition_block_struct_definition;
	extern s_tag_reference_definition particle_group_particle_model_group_reference;
	extern s_string_list_definition unnamed_enum$39;
	extern s_string_list_definition unnamed_enum$42;
	extern s_string_list_definition unnamed_enum$43;

	extern s_tag_struct_definition particle_system_emitter_definition_block_struct_definition;
	extern s_tag_reference_definition particle_physics_group_reference;
	extern s_string_list_definition unnamed_enum$44;

	extern s_tag_struct_definition particle_system_lite_data_block_struct_definition;

	extern s_tag_struct_definition particles_render_data_block_struct_definition;

	extern s_tag_struct_definition particles_update_data_block_struct_definition;

	extern s_tag_struct_definition patchy_fog_block_struct_definition;
	extern s_string_list_definition unnamed_enum$201;

	extern s_tag_struct_definition pathfinding_data_block_struct_definition;

	extern s_tag_struct_definition pathfinding_object_index_list_block_struct_definition;

	extern s_tag_struct_definition permutations_block_struct_definition;

	extern s_tag_struct_definition persistent_background_animation_block_struct_definition;

	extern s_tag_struct_definition phantom_type_struct_definition;
	extern s_string_list_definition unnamed_enum$343;
	extern s_string_list_definition unnamed_enum$344;
	extern s_string_list_definition unnamed_enum$345;

	extern s_tag_struct_definition phantoms_block_struct_definition;

	extern s_tag_struct_definition physics_block_struct_definition;

	extern s_tag_struct_definition physics_model_constraint_edge_constraint_block_struct_definition;
	extern s_string_list_definition unnamed_enum$346;
	extern s_string_list_definition unnamed_enum$347;

	extern s_tag_struct_definition physics_model_node_constraint_edge_block_struct_definition;

	extern s_tag_struct_definition physics_model_struct_definition;
	extern s_string_list_definition unnamed_enum$342;

	extern s_tag_struct_definition pills_block_struct_definition;

	extern s_tag_struct_definition pixel32_block_struct_definition;

	extern s_tag_struct_definition pixel_shader_block_struct_definition;

	extern s_tag_struct_definition pixel_shader_combiner_block_struct_definition;

	extern s_tag_struct_definition pixel_shader_constant_block_struct_definition;
	extern s_string_list_definition unnamed_enum$481;

	extern s_tag_struct_definition pixel_shader_extern_map_block_struct_definition;

	extern s_tag_struct_definition pixel_shader_fragment_block_struct_definition;

	extern s_tag_struct_definition pixel_shader_index_block_struct_definition;

	extern s_tag_struct_definition pixel_shader_permutation_block_struct_definition;
	extern s_string_list_definition unnamed_enum$480;

	extern s_tag_struct_definition pixel_shader_permutation_new_block_struct_definition;

	extern s_tag_struct_definition planar_fog_block_struct_definition;
	extern s_string_list_definition unnamed_enum$199;
	extern s_tag_reference_definition sound_environment_group_reference$2;

	extern s_tag_struct_definition planar_fog_patchy_fog_block_struct_definition;
	extern s_tag_reference_definition patchy_fog_group_reference$2;

	extern s_tag_struct_definition planes_block_struct_definition;

	extern s_tag_struct_definition platform_sound_effect_block_struct_definition;

	extern s_tag_struct_definition platform_sound_effect_collection_block_struct_definition;

	extern s_tag_struct_definition platform_sound_effect_constant_block_struct_definition;

	extern s_tag_struct_definition platform_sound_effect_function_block_struct_definition;
	extern s_string_list_definition unnamed_enum$29;

	extern s_tag_struct_definition platform_sound_effect_override_descriptor_block_struct_definition;

	extern s_tag_struct_definition platform_sound_effect_template_block_struct_definition;

	extern s_tag_struct_definition platform_sound_effect_template_collection_block_struct_definition;

	extern s_tag_struct_definition platform_sound_effect_template_component_block_struct_definition;

	extern s_tag_struct_definition platform_sound_filter_block_struct_definition;
	extern s_string_list_definition unnamed_enum$414;

	extern s_tag_struct_definition platform_sound_filter_lfo_block_struct_definition;

	extern s_tag_struct_definition platform_sound_override_mixbins_block_struct_definition;
	extern s_string_list_definition unnamed_enum$412;

	extern s_tag_struct_definition platform_sound_pitch_lfo_block_struct_definition;

	extern s_tag_struct_definition platform_sound_playback_block_struct_definition;

	extern s_tag_struct_definition platform_sound_playback_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$413;

	extern s_tag_struct_definition player_block_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$429;

	extern s_tag_struct_definition player_control_block_struct_definition;

	extern s_tag_struct_definition player_information_block_struct_definition;

	extern s_tag_struct_definition player_representation_block_struct_definition;
	extern s_tag_reference_definition render_model_group_reference$2;
	extern s_tag_reference_definition unit_group_reference$4;

	extern s_tag_struct_definition player_training_entry_data_block_struct_definition;
	extern s_string_list_definition unnamed_enum$241;

	extern s_tag_struct_definition point_block_reference_block_struct_definition;

	extern s_tag_struct_definition point_physics_block_struct_definition;
	extern s_string_list_definition unnamed_enum$357;

	extern s_tag_struct_definition point_to_path_curve_block_struct_definition;

	extern s_tag_struct_definition point_to_path_curve_point_block_struct_definition;

	extern s_tag_struct_definition polyhedra_block_struct_definition;

	extern s_tag_struct_definition polyhedron_four_vectors_block_struct_definition;

	extern s_tag_struct_definition polyhedron_plane_equations_block_struct_definition;

	extern s_tag_struct_definition powered_mass_point_block_struct_definition;
	extern s_string_list_definition unnamed_enum$352;

	extern s_tag_struct_definition powered_seat_block_struct_definition;

	extern s_tag_struct_definition powerup_block_struct_definition;

	extern s_tag_struct_definition precache_list_block_struct_definition;

	extern s_tag_struct_definition predicted_bitmaps_block_struct_definition;

	extern s_tag_struct_definition predicted_resource_block_struct_definition;
	extern s_string_list_definition unnamed_enum$105;

	extern s_tag_struct_definition presearch_struct_definition;

	extern s_tag_struct_definition primary_light_struct_struct_definition;

	extern s_tag_struct_definition prismatic_constraints_block_struct_definition;

	extern s_tag_struct_definition projectile_material_response_block_struct_definition;
	extern s_string_list_definition unnamed_enum$360;
	extern s_string_list_definition unnamed_enum$361;
	extern s_string_list_definition unnamed_enum$362;
	extern s_string_list_definition unnamed_enum$363;

	extern s_tag_struct_definition projectile_struct_definition;
	extern s_string_list_definition unnamed_enum$358;
	extern s_string_list_definition unnamed_enum$359;
	extern s_string_list_definition unnamed_enum$364;

	extern s_tag_struct_definition prt_cluster_basis_block_struct_definition;

	extern s_tag_struct_definition prt_info_block_struct_definition;

	extern s_tag_struct_definition prt_lod_info_block_struct_definition;

	extern s_tag_struct_definition prt_raw_pca_data_block_struct_definition;

	extern s_tag_struct_definition prt_section_info_block_struct_definition;

	extern s_tag_struct_definition prt_vertex_buffers_block_struct_definition;

	extern s_tag_struct_definition quantized_orientation_struct_struct_definition;

	extern s_tag_struct_definition ragdoll_constraints_block_struct_definition;

	extern s_tag_struct_definition rasterizer_data_block_struct_definition;
	extern s_tag_reference_definition bitmap_group_reference$4;
	extern s_string_list_definition unnamed_enum$302;

	extern s_tag_struct_definition rasterizer_screen_effect_convolution_block_struct_definition;
	extern s_string_list_definition unnamed_enum$196;

	extern s_tag_struct_definition rasterizer_screen_effect_pass_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$193;
	extern s_string_list_definition unnamed_enum$195;

	extern s_tag_struct_definition rasterizer_screen_effect_texcoord_generation_advanced_control_block_struct_definition;
	extern s_string_list_definition unnamed_enum$194;

	extern s_tag_struct_definition real_block_struct_definition;

	extern s_tag_struct_definition real_vector4d_block_struct_definition;

	extern s_tag_struct_definition recorded_animation_block_struct_definition;

	extern s_tag_struct_definition ref_block_struct_definition;

	extern s_tag_struct_definition regions_block_struct_definition;

	extern s_tag_struct_definition render_lighting_struct_struct_definition;

	extern s_tag_struct_definition render_model_backward_shared_edge_block_struct_definition;

	extern s_tag_struct_definition render_model_block_struct_definition;
	extern s_string_list_definition unnamed_enum$318;

	extern s_tag_struct_definition render_model_compound_node_block_struct_definition;

	extern s_tag_struct_definition render_model_dsq_raw_vertex_block_struct_definition;

	extern s_tag_struct_definition render_model_dsq_silhouette_quad_block_struct_definition;

	extern s_tag_struct_definition render_model_dsq_strip_index_block_struct_definition;

	extern s_tag_struct_definition render_model_forward_shared_edge_block_struct_definition;

	extern s_tag_struct_definition render_model_invalid_section_pairs_block_struct_definition;

	extern s_tag_struct_definition render_model_marker_block_struct_definition;

	extern s_tag_struct_definition render_model_marker_group_block_struct_definition;

	extern s_tag_struct_definition render_model_node_block_struct_definition;

	extern s_tag_struct_definition render_model_node_map_block_old_struct_definition;

	extern s_tag_struct_definition render_model_node_map_block_struct_definition;

	extern s_tag_struct_definition render_model_permutation_block_struct_definition;

	extern s_tag_struct_definition render_model_region_block_struct_definition;

	extern s_tag_struct_definition render_model_section_block_struct_definition;
	extern s_string_list_definition unnamed_enum$319;

	extern s_tag_struct_definition render_model_section_data_tag_field_new_struct_definition;

	extern s_tag_struct_definition render_model_section_group_block_struct_definition;
	extern s_string_list_definition unnamed_enum$321;

	extern s_tag_struct_definition render_model_shared_edge_group_block_struct_definition;

	extern s_tag_struct_definition render_state_block_struct_definition;

	extern s_tag_struct_definition render_state_parameter_block_struct_definition;

	extern s_tag_struct_definition response_block_struct_definition;
	extern s_string_list_definition unnamed_enum$52;
	extern s_string_list_definition unnamed_enum$53;

	extern s_tag_struct_definition rigid_bodies_block_struct_definition;
	extern s_string_list_definition unnamed_enum$348;
	extern s_string_list_definition unnamed_enum$349;

	extern s_tag_struct_definition rigid_body_indices_block_struct_definition;

	extern s_tag_struct_definition rules_block_struct_definition;

	extern s_tag_struct_definition runtime_campaign_level_block_struct_definition;

	extern s_tag_struct_definition runtime_levels_definition_block_struct_definition;

	extern s_tag_struct_definition s_effect_event_struct_definition;

	extern s_tag_struct_definition s_text_value_pair_blocks_block_unused_struct_definition;

	extern s_tag_struct_definition s_text_value_pair_reference_block_unused_struct_definition;
	extern s_string_list_definition unnamed_enum$541;
	extern s_string_list_definition unnamed_enum$542;

	extern s_tag_struct_definition scalar_function_struct_struct_definition;

	extern s_tag_struct_definition scenario_ai_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_ai_resource_reference_block_struct_definition;
	extern s_tag_reference_definition scenario_ai_resource_group_reference;

	extern s_tag_struct_definition scenario_atmospheric_fog_mixer_block_struct_definition;

	extern s_tag_struct_definition scenario_atmospheric_fog_palette_struct_definition;
	extern s_tag_reference_definition patchy_fog_group_reference;
	extern s_string_list_definition unnamed_enum$155;

	extern s_tag_struct_definition scenario_biped_palette_block_struct_definition;
	extern s_tag_reference_definition biped_group_reference;

	extern s_tag_struct_definition scenario_biped_struct_definition;

	extern s_tag_struct_definition scenario_bipeds_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_bsp_switch_transition_volume_block_struct_definition;

	extern s_tag_struct_definition scenario_bsp_switch_trigger_volume_block_struct_definition;

	extern s_tag_struct_definition scenario_child_scenario_block_struct_definition;
	extern s_tag_reference_definition scenario_group_reference$2;

	extern s_tag_struct_definition scenario_cinematics_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_cluster_atmospheric_fog_properties_block_struct_definition;

	extern s_tag_struct_definition scenario_cluster_background_sounds_block_struct_definition;

	extern s_tag_struct_definition scenario_cluster_data_block_struct_definition;
	extern s_tag_reference_definition scenario_structure_bsp_group_reference;

	extern s_tag_struct_definition scenario_cluster_data_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_cluster_points_block_struct_definition;

	extern s_tag_struct_definition scenario_cluster_sound_environments_block_struct_definition;

	extern s_tag_struct_definition scenario_cluster_weather_properties_block_struct_definition;

	extern s_tag_struct_definition scenario_comments_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_control_palette_block_struct_definition;
	extern s_tag_reference_definition device_control_group_reference;

	extern s_tag_struct_definition scenario_control_struct_definition;
	extern s_string_list_definition unnamed_enum$186;

	extern s_tag_struct_definition scenario_control_struct_struct_definition;

	extern s_tag_struct_definition scenario_crate_block_struct_definition;

	extern s_tag_struct_definition scenario_crate_palette_block_struct_definition;
	extern s_tag_reference_definition crate_group_reference;

	extern s_tag_struct_definition scenario_creature_block_struct_definition;

	extern s_tag_struct_definition scenario_creature_palette_block_struct_definition;
	extern s_tag_reference_definition creature_group_reference;

	extern s_tag_struct_definition scenario_creature_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_cutscene_camera_point_block_struct_definition;
	extern s_string_list_definition unnamed_enum$152;
	extern s_string_list_definition unnamed_enum$153;

	extern s_tag_struct_definition scenario_cutscene_flag_block_struct_definition;

	extern s_tag_struct_definition scenario_cutscene_title_block_struct_definition;
	extern s_string_list_definition unnamed_enum$406;
	extern s_string_list_definition unnamed_enum$407;

	extern s_tag_struct_definition scenario_decal_palette_block_struct_definition;
	extern s_tag_reference_definition decal_group_reference;

	extern s_tag_struct_definition scenario_decals_block_struct_definition;

	extern s_tag_struct_definition scenario_decals_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_decorator_set_palette_entry_block_struct_definition;
	extern s_tag_reference_definition decorator_set_group_reference;

	extern s_tag_struct_definition scenario_decorators_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_description_block_struct_definition;

	extern s_tag_struct_definition scenario_detail_object_collection_palette_block_struct_definition;
	extern s_tag_reference_definition detail_object_collection_group_reference;

	extern s_tag_struct_definition scenario_device_struct_struct_definition;

	extern s_tag_struct_definition scenario_devices_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_equipment_datum_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$22;

	extern s_tag_struct_definition scenario_equipment_palette_block_struct_definition;
	extern s_tag_reference_definition equipment_group_reference;

	extern s_tag_struct_definition scenario_equipment_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_equipment_struct_definition;

	extern s_tag_struct_definition scenario_function_block_struct_definition;
	extern s_string_list_definition unnamed_enum$395;
	extern s_string_list_definition unnamed_enum$396;
	extern s_string_list_definition unnamed_enum$397;

	extern s_tag_struct_definition scenario_hs_source_reference_block_struct_definition;
	extern s_tag_reference_definition scenario_hs_source_file_group_reference;

	extern s_tag_struct_definition scenario_interpolator_block_struct_definition;

	extern s_tag_struct_definition scenario_kill_trigger_volumes_block_struct_definition;

	extern s_tag_struct_definition scenario_level_data_block_struct_definition;

	extern s_tag_struct_definition scenario_light_fixture_palette_block_struct_definition;
	extern s_tag_reference_definition device_light_fixture_group_reference;

	extern s_tag_struct_definition scenario_light_fixture_struct_definition;

	extern s_tag_struct_definition scenario_light_fixture_struct_struct_definition;

	extern s_tag_struct_definition scenario_light_palette_block_struct_definition;
	extern s_tag_reference_definition light_group_reference;

	extern s_tag_struct_definition scenario_light_struct_definition;
	extern s_string_list_definition unnamed_enum$19;
	extern s_string_list_definition unnamed_enum$20;
	extern s_string_list_definition unnamed_enum$21;

	extern s_tag_struct_definition scenario_light_struct_struct_definition;

	extern s_tag_struct_definition scenario_lights_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_machine_palette_block_struct_definition;
	extern s_tag_reference_definition device_machine_group_reference;

	extern s_tag_struct_definition scenario_machine_struct_definition;
	extern s_string_list_definition unnamed_enum$185;

	extern s_tag_struct_definition scenario_machine_struct_v2_struct_definition;

	extern s_tag_struct_definition scenario_machine_struct_v3_struct_definition;

	extern s_tag_struct_definition scenario_netgame_equipment_block_struct_definition;
	extern s_string_list_definition unnamed_enum$400;
	extern s_string_list_definition unnamed_enum$76;
	extern s_string_list_definition unnamed_enum$401;
	extern s_string_list_definition unnamed_enum$402;
	extern s_tag_reference_definition item_collection_group_vehicle_collection_group_reference;

	extern s_tag_struct_definition scenario_netgame_equipment_orientation_struct_struct_definition;

	extern s_tag_struct_definition scenario_netpoint_struct_definition;
	extern s_string_list_definition unnamed_enum$398;
	extern s_string_list_definition unnamed_enum$75;
	extern s_string_list_definition unnamed_enum$399;
	extern s_tag_reference_definition item_collection_group_reference$2;

	extern s_tag_struct_definition scenario_object_id_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$6;
	extern s_string_list_definition unnamed_enum$7;

	extern s_tag_struct_definition scenario_object_names_block_struct_definition;

	extern s_tag_struct_definition scenario_object_permutation_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$9;

	extern s_tag_struct_definition scenario_planar_fog_palette_struct_definition;
	extern s_tag_reference_definition planar_fog_group_reference;

	extern s_tag_struct_definition scenario_players_block_struct_definition;
	extern s_string_list_definition unnamed_enum$77;
	extern s_string_list_definition unnamed_enum$78;

	extern s_tag_struct_definition scenario_profiles_block_struct_definition;
	extern s_tag_reference_definition weapon_group_reference$6;

	extern s_tag_struct_definition scenario_resource_reference_block_struct_definition;
	extern s_tag_reference_definition _reference$6;

	extern s_tag_struct_definition scenario_resources_block_struct_definition;

	extern s_tag_struct_definition scenario_scenery_datum_struct_v2_struct_definition;
	extern s_string_list_definition unnamed_enum$13;
	extern s_string_list_definition unnamed_enum$10;
	extern s_string_list_definition unnamed_enum$14;

	extern s_tag_struct_definition scenario_scenery_datum_struct_v3_struct_definition;
	extern s_string_list_definition unnamed_enum$11;

	extern s_tag_struct_definition scenario_scenery_datum_struct_v4_struct_definition;
	extern s_string_list_definition unnamed_enum$12;

	extern s_tag_struct_definition scenario_scenery_palette_block_struct_definition;
	extern s_tag_reference_definition scenery_group_reference;

	extern s_tag_struct_definition scenario_scenery_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_scenery_struct_definition;

	extern s_tag_struct_definition scenario_screen_effect_reference_block_struct_definition;

	extern s_tag_struct_definition scenario_simulation_definition_table_block_struct_definition;

	extern s_tag_struct_definition scenario_sky_reference_block_struct_definition;
	extern s_tag_reference_definition sky_group_reference;

	extern s_tag_struct_definition scenario_sound_scenery_palette_block_struct_definition;
	extern s_tag_reference_definition sound_scenery_group_reference;

	extern s_tag_struct_definition scenario_sound_scenery_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_sound_scenery_struct_definition;

	extern s_tag_struct_definition scenario_spawn_data_block_struct_definition;

	extern s_tag_struct_definition scenario_spherical_harmonic_lighting_point_struct_definition;

	extern s_tag_struct_definition scenario_starting_equipment_block_struct_definition;
	extern s_string_list_definition unnamed_enum$403;

	extern s_tag_struct_definition scenario_struct_definition;
	extern s_string_list_definition unnamed_enum$393;
	extern s_string_list_definition unnamed_enum$394;
	extern s_tag_reference_definition hud_message_text_group_reference$2;
	extern s_tag_reference_definition sound_effect_collection_group_reference;

	extern s_tag_struct_definition scenario_structure_bsp_fieldset_old_struct_definition;
	extern s_tag_reference_definition decorators_group_reference;

	extern s_tag_struct_definition scenario_structure_bsp_reference_struct_definition;
	extern s_tag_reference_definition scenario_structure_lightmap_group_reference;
	extern s_string_list_definition unnamed_enum$3;

	extern s_tag_struct_definition scenario_structure_bsp_spherical_harmonic_lighting_block_struct_definition;

	extern s_tag_struct_definition scenario_structure_lighting_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_structure_lightmap_block_struct_definition;

	extern s_tag_struct_definition scenario_trigger_volume_struct_definition;

	extern s_tag_struct_definition scenario_trigger_volumes_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_unit_struct_struct_definition;

	extern s_tag_struct_definition scenario_vehicle_palette_block_struct_definition;
	extern s_tag_reference_definition vehicle_group_reference;

	extern s_tag_struct_definition scenario_vehicle_struct_definition;

	extern s_tag_struct_definition scenario_vehicles_resource_block_struct_definition;

	extern s_tag_struct_definition scenario_weapon_datum_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$15;

	extern s_tag_struct_definition scenario_weapon_palette_block_struct_definition;
	extern s_tag_reference_definition weapon_group_reference;

	extern s_tag_struct_definition scenario_weapon_struct_definition;

	extern s_tag_struct_definition scenario_weapons_resource_block_struct_definition;

	extern s_tag_struct_definition scenery_struct_definition;
	extern s_string_list_definition unnamed_enum$388;
	extern s_string_list_definition unnamed_enum$389;
	extern s_string_list_definition unnamed_enum$390;
	extern s_string_list_definition unnamed_enum$391;
	extern s_string_list_definition unnamed_enum$392;

	extern s_tag_struct_definition screen_animation_keyframe_reference_block_struct_definition;

	extern s_tag_struct_definition screen_effect_block_struct_definition;

	extern s_tag_struct_definition screen_effect_bonus_struct_definition;

	extern s_tag_struct_definition screen_flash_definition_struct_struct_definition;

	extern s_tag_struct_definition secondary_light_struct_struct_definition;

	extern s_tag_struct_definition secondary_set_trigger_block_struct_definition;

	extern s_tag_struct_definition section_render_leaves_block_struct_definition;

	extern s_tag_struct_definition sector_bsp2d_nodes_block_struct_definition;

	extern s_tag_struct_definition sector_vertex_block_struct_definition;

	extern s_tag_struct_definition sectors_v3_struct_definition;
	extern s_string_list_definition unnamed_enum$372;

	extern s_tag_struct_definition shader_animation_property_block_struct_definition;
	extern s_string_list_definition unnamed_enum$366;

	extern s_tag_struct_definition shader_block_struct_definition;
	extern s_string_list_definition unnamed_enum$416;
	extern s_tag_reference_definition shader_light_response_group_reference;
	extern s_string_list_definition unnamed_enum$417;
	extern s_string_list_definition unnamed_enum$418;
	extern s_string_list_definition unnamed_enum$419;

	extern s_tag_struct_definition shader_gpu_state_reference_struct_struct_definition;

	extern s_tag_struct_definition shader_gpu_state_struct_struct_definition;

	extern s_tag_struct_definition shader_light_response_block_struct_definition;

	extern s_tag_struct_definition shader_pass_block_struct_definition;

	extern s_tag_struct_definition shader_pass_implementation_block_struct_definition;
	extern s_string_list_definition unnamed_enum$449;
	extern s_tag_reference_definition vertex_shader_group_reference$2;
	extern s_string_list_definition unnamed_enum$463;
	extern s_string_list_definition unnamed_enum$464;
	extern s_string_list_definition unnamed_enum$465;
	extern s_tag_reference_definition pixel_shader_group_reference;

	extern s_tag_struct_definition shader_pass_parameter_block_struct_definition;
	extern s_string_list_definition unnamed_enum$447;
	extern s_string_list_definition unnamed_enum$448;

	extern s_tag_struct_definition shader_pass_postprocess_constant_info_new_block_struct_definition;

	extern s_tag_struct_definition shader_pass_postprocess_constant_new_block_struct_definition;

	extern s_tag_struct_definition shader_pass_postprocess_definition_new_block_struct_definition;

	extern s_tag_struct_definition shader_pass_postprocess_extern_new_block_struct_definition;

	extern s_tag_struct_definition shader_pass_postprocess_implementation_block_struct_definition;
	extern s_tag_reference_definition vertex_shader_group_reference$3;

	extern s_tag_struct_definition shader_pass_postprocess_implementation_new_block_struct_definition;

	extern s_tag_struct_definition shader_pass_postprocess_texture_new_block_struct_definition;

	extern s_tag_struct_definition shader_pass_postprocess_texture_state_block_struct_definition;

	extern s_tag_struct_definition shader_pass_texture_block_struct_definition;
	extern s_string_list_definition unnamed_enum$450;
	extern s_string_list_definition unnamed_enum$451;
	extern s_string_list_definition unnamed_enum$452;

	extern s_tag_struct_definition shader_pass_vertex_shader_constant_block_struct_definition;
	extern s_string_list_definition unnamed_enum$460;
	extern s_string_list_definition unnamed_enum$461;
	extern s_string_list_definition unnamed_enum$462;

	extern s_tag_struct_definition shader_postprocess_animated_parameter_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_animated_parameter_reference_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_bitmap_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_bitmap_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_bitmap_property_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_bitmap_transform_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_bitmap_transform_overlay_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_color_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_color_overlay_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_color_property_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_definition_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_implementation_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_implementation_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_layer_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_level_of_detail_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_level_of_detail_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_overlay_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_overlay_reference_new_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_pass_block_struct_definition;
	extern s_tag_reference_definition shader_pass_group_reference;

	extern s_tag_struct_definition shader_postprocess_pixel_shader_constant_defaults_struct_definition;

	extern s_tag_struct_definition shader_postprocess_pixel_shader_struct_definition;

	extern s_tag_struct_definition shader_postprocess_value_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_value_overlay_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_value_property_block_struct_definition;

	extern s_tag_struct_definition shader_postprocess_vertex_shader_constant_block_struct_definition;

	extern s_tag_struct_definition shader_properties_block_struct_definition;

	extern s_tag_struct_definition shader_state_alpha_blend_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$467;
	extern s_string_list_definition unnamed_enum$468;
	extern s_string_list_definition unnamed_enum$469;

	extern s_tag_struct_definition shader_state_alpha_test_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$470;
	extern s_string_list_definition unnamed_enum$471;

	extern s_tag_struct_definition shader_state_channels_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$466;

	extern s_tag_struct_definition shader_state_constant_block_struct_definition;
	extern s_string_list_definition unnamed_enum$479;

	extern s_tag_struct_definition shader_state_cull_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$474;
	extern s_string_list_definition unnamed_enum$475;

	extern s_tag_struct_definition shader_state_depth_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$472;
	extern s_string_list_definition unnamed_enum$473;

	extern s_tag_struct_definition shader_state_fill_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$476;
	extern s_string_list_definition unnamed_enum$477;

	extern s_tag_struct_definition shader_state_misc_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$478;

	extern s_tag_struct_definition shader_template_block_struct_definition;
	extern s_string_list_definition unnamed_enum$482;
	extern s_string_list_definition unnamed_enum$435;

	extern s_tag_struct_definition shader_template_category_block_struct_definition;

	extern s_tag_struct_definition shader_template_level_of_detail_block_struct_definition;

	extern s_tag_struct_definition shader_template_parameter_block_struct_definition;
	extern s_string_list_definition unnamed_enum$432;
	extern s_string_list_definition unnamed_enum$433;
	extern s_string_list_definition unnamed_enum$434;

	extern s_tag_struct_definition shader_template_pass_reference_block_struct_definition;
	extern s_tag_reference_definition shader_pass_group_reference$2;

	extern s_tag_struct_definition shader_template_postprocess_definition_new_block_struct_definition;

	extern s_tag_struct_definition shader_template_postprocess_implementation_new_block_struct_definition;

	extern s_tag_struct_definition shader_template_postprocess_level_of_detail_new_block_struct_definition;

	extern s_tag_struct_definition shader_template_postprocess_pass_new_block_struct_definition;

	extern s_tag_struct_definition shader_template_postprocess_remapping_new_block_struct_definition;

	extern s_tag_struct_definition shader_template_property_block_struct_definition;
	extern s_string_list_definition unnamed_enum$483;

	extern s_tag_struct_definition shader_template_runtime_external_light_response_index_block_struct_definition;

	extern s_tag_struct_definition shader_texture_state_address_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$453;

	extern s_tag_struct_definition shader_texture_state_constant_block_struct_definition;
	extern s_string_list_definition unnamed_enum$459;

	extern s_tag_struct_definition shader_texture_state_filter_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$454;
	extern s_string_list_definition unnamed_enum$455;

	extern s_tag_struct_definition shader_texture_state_kill_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$456;
	extern s_string_list_definition unnamed_enum$457;

	extern s_tag_struct_definition shader_texture_state_misc_state_block_struct_definition;
	extern s_string_list_definition unnamed_enum$458;

	extern s_tag_struct_definition shape_block_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$552;

	extern s_tag_struct_definition shape_group_reference_block_struct_definition;

	extern s_tag_struct_definition simple_platform_sound_playback_struct_struct_definition;

	extern s_tag_struct_definition single_animation_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$422;

	extern s_tag_struct_definition skill_to_rank_mapping_block_struct_definition;

	extern s_tag_struct_definition sky_animation_block_struct_definition;

	extern s_tag_struct_definition sky_atmospheric_fog_block_struct_definition;

	extern s_tag_struct_definition sky_block_struct_definition;
	extern s_tag_reference_definition render_model_group_reference$4;
	extern s_string_list_definition unnamed_enum$430;

	extern s_tag_struct_definition sky_cubemap_block_struct_definition;
	extern s_tag_reference_definition bitmap_group_reference$7;

	extern s_tag_struct_definition sky_fog_block_struct_definition;

	extern s_tag_struct_definition sky_light_block_struct_definition;
	extern s_tag_reference_definition lens_flare_group_reference$2;

	extern s_tag_struct_definition sky_light_fog_block_struct_definition;

	extern s_tag_struct_definition sky_patchy_fog_block_struct_definition;
	extern s_tag_reference_definition patchy_fog_group_reference$3;

	extern s_tag_struct_definition sky_radiosity_light_block_struct_definition;
	extern s_string_list_definition unnamed_enum$431;

	extern s_tag_struct_definition sky_shader_function_block_struct_definition;

	extern s_tag_struct_definition small_bsp3d_nodes_block_struct_definition;

	extern s_tag_struct_definition sound_block_struct_definition;
	extern s_tag_reference_definition _reference$3;

	extern s_tag_struct_definition sound_cache_file_gestalt_block_struct_definition;

	extern s_tag_struct_definition sound_class_block_v4_struct_definition;
	extern s_string_list_definition unnamed_enum$436;
	extern s_string_list_definition unnamed_enum$437;
	extern s_string_list_definition unnamed_enum$438;
	extern s_string_list_definition unnamed_enum$439;

	extern s_tag_struct_definition sound_class_ducker_block_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$440;

	extern s_tag_struct_definition sound_class_struct_definition;

	extern s_tag_struct_definition sound_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$441;
	extern s_string_list_definition unnamed_enum$442;
	extern s_string_list_definition unnamed_enum$444;

	extern s_tag_struct_definition sound_dialogue_constants_block_struct_definition;

	extern s_tag_struct_definition sound_effect_collection_block_struct_definition;

	extern s_tag_struct_definition sound_effect_component_block_struct_definition;
	extern s_tag_reference_definition sound_looping_group_sound_group_reference;
	extern s_string_list_definition unnamed_enum$415;

	extern s_tag_struct_definition sound_effect_overrides_block_struct_definition;

	extern s_tag_struct_definition sound_effect_playback_block_struct_definition;

	extern s_tag_struct_definition sound_effect_struct_definition_struct_definition;
	extern s_tag_reference_definition sound_effect_template_group_reference;

	extern s_tag_struct_definition sound_effect_template_additional_sound_input_block_struct_definition;

	extern s_tag_struct_definition sound_effect_template_parameter_block_struct_definition;
	extern s_string_list_definition unnamed_enum$26;
	extern s_string_list_definition unnamed_enum$27;

	extern s_tag_struct_definition sound_encoded_dialogue_section_block_struct_definition;

	extern s_tag_struct_definition sound_environment_definition_struct_definition;

	extern s_tag_struct_definition sound_extra_info_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_codec_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_custom_playback_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_extra_info_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_import_names_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_language_chunks_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_lowpass_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_permutation_language_data_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_permutations_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_pitch_range_parameters_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_pitch_ranges_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_playback_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_promotions_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_reflections_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_remastered_sound_references_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_runtime_permutation_bit_vector_block_struct_definition;

	extern s_tag_struct_definition sound_gestalt_scale_block_struct_definition;

	extern s_tag_struct_definition sound_global_mix_struct_struct_definition;

	extern s_tag_struct_definition sound_globals_struct_definition;
	extern s_tag_reference_definition sound_classes_group_reference;
	extern s_tag_reference_definition sound_mix_group_reference;
	extern s_tag_reference_definition sound_dialogue_constants_group_reference;

	extern s_tag_struct_definition sound_lowpass_struct_struct_definition;

	extern s_tag_struct_definition sound_mix_block_struct_definition;

	extern s_tag_struct_definition sound_permutation_dialogue_info_block_struct_definition;

	extern s_tag_struct_definition sound_permutation_language_info_struct_definition;
	extern s_string_list_definition unnamed_enum$446;

	extern s_tag_struct_definition sound_permutation_marker_block_struct_definition;

	extern s_tag_struct_definition sound_permutation_raw_info_block_old_struct_definition$2;

	extern s_tag_struct_definition sound_permutation_raw_info_block_struct_definition;

	extern s_tag_struct_definition sound_permutations_block_struct_definition;

	extern s_tag_struct_definition sound_pitch_range_block_struct_definition;

	extern s_tag_struct_definition sound_platform_sound_playback_block_struct_definition;

	extern s_tag_struct_definition sound_playback_parameter_definition_struct_definition;

	extern s_tag_struct_definition sound_playback_parameters_struct_struct_definition;

	extern s_tag_struct_definition sound_promotion_parameter_struct_definition;

	extern s_tag_struct_definition sound_promotion_rule_block_struct_definition;

	extern s_tag_struct_definition sound_promotion_runtime_timer_block_struct_definition;

	extern s_tag_struct_definition sound_reflection_block_struct_definition;

	extern s_tag_struct_definition sound_reflection_parameters_struct_struct_definition;

	extern s_tag_struct_definition sound_response_definition_block_struct_definition;

	extern s_tag_struct_definition sound_response_extra_sounds_struct_definition;

	extern s_tag_struct_definition sound_scale_modifiers_struct_struct_definition;

	extern s_tag_struct_definition sound_scenery_block_struct_definition;

	extern s_tag_struct_definition sound_scenery_datum_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$23;

	extern s_tag_struct_definition sounds_block_struct_definition;

	extern s_tag_struct_definition sounds_block_struct_definition$2;

	extern s_tag_struct_definition special_movement_block_struct_definition;
	extern s_string_list_definition unnamed_enum$85;

	extern s_tag_struct_definition spheres_block_struct_definition;

	extern s_tag_struct_definition sprite_vertices_block_struct_definition;

	extern s_tag_struct_definition squad_groups_block_struct_definition;

	extern s_tag_struct_definition squads_v3_struct_definition;
	extern s_string_list_definition unnamed_enum$65;
	extern s_string_list_definition unnamed_enum$66;
	extern s_string_list_definition unnamed_enum$67;

	extern s_tag_struct_definition states_block_struct_definition;

	extern s_tag_struct_definition static_spawn_zone_block_struct_definition;

	extern s_tag_struct_definition static_spawn_zone_data_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$409;
	extern s_string_list_definition unnamed_enum$410;
	extern s_string_list_definition unnamed_enum$411;

	extern s_tag_struct_definition stereo_system_block_struct_definition;

	extern s_tag_struct_definition stiff_spring_constraints_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_audibility_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_background_sound_palette_block_struct_definition;
	extern s_string_list_definition unnamed_enum$154;

	extern s_tag_struct_definition structure_bsp_breakable_surface_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_data_block_new_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_data_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_debug_info_block_struct_definition;
	extern s_string_list_definition unnamed_enum$385;
	extern s_string_list_definition unnamed_enum$386;

	extern s_tag_struct_definition structure_bsp_cluster_havok_shape_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_instanced_geometry_index_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_lightmap_data_block_struct_definition;
	extern s_string_list_definition unnamed_enum$370;
	extern s_string_list_definition unnamed_enum$371;

	extern s_tag_struct_definition structure_bsp_cluster_lightmap_duplicate_index_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_lightmap_index_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_lightmap_texture_coordinate_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_mopp_shape_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_portal_block_struct_definition;
	extern s_string_list_definition unnamed_enum$367;

	extern s_tag_struct_definition structure_bsp_cluster_portal_index_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_portal_vertex_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_cluster_struct_definition;
	extern s_string_list_definition unnamed_enum$369;

	extern s_tag_struct_definition structure_bsp_cluster_visibility_mopp_leaf_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_conveyor_surface_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_debug_info_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_debug_info_indices_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_debug_info_render_line_block_struct_definition;
	extern s_string_list_definition unnamed_enum$387;

	extern s_tag_struct_definition structure_bsp_detail_object_data_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_environment_object_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_environment_object_palette_block_struct_definition;
	extern s_tag_reference_definition scenery_group_reference$2;
	extern s_tag_reference_definition render_model_group_reference$3;

	extern s_tag_struct_definition structure_bsp_fake_lightprobes_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_fog_plane_block_struct_definition;
	extern s_string_list_definition unnamed_enum$368;

	extern s_tag_struct_definition structure_bsp_fog_plane_debug_info_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_fog_zone_debug_info_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_instanced_geometry_definition_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_leaf_struct_definition;

	extern s_tag_struct_definition structure_bsp_lightmap_data_block_struct_definition;
	extern s_tag_reference_definition bitmap_group_reference$6;

	extern s_tag_struct_definition structure_bsp_marker_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_pathfinding_edges_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_precomputed_lighting_block_struct_definition;
	extern s_string_list_definition unnamed_enum$381;

	extern s_tag_struct_definition structure_bsp_runtime_decal_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_sky_owner_cluster_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_sound_cluster_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_sound_environment_palette_block_struct_definition;
	extern s_tag_reference_definition sound_environment_group_reference;

	extern s_tag_struct_definition structure_bsp_surface_reference_struct_definition;

	extern s_tag_struct_definition structure_bsp_weather_palette_block_struct_definition;
	extern s_tag_reference_definition weather_system_group_reference;
	extern s_tag_reference_definition wind_group_reference;

	extern s_tag_struct_definition structure_bsp_weather_polyhedron_block_struct_definition;

	extern s_tag_struct_definition structure_bsp_weather_polyhedron_plane_block_struct_definition;

	extern s_tag_struct_definition structure_collision_materials_block_struct_definition;

	extern s_tag_struct_definition structure_device_portal_association_block_struct_definition;

	extern s_tag_struct_definition structure_indices_segment_block_struct_definition;

	extern s_tag_struct_definition structure_indices_segment_reference_block_struct_definition;

	extern s_tag_struct_definition structure_instanced_geometry_render_info_struct_definition;

	extern s_tag_struct_definition structure_lightmap_bsp_leaf_block_struct_definition;

	extern s_tag_struct_definition structure_lightmap_group_block_struct_definition;
	extern s_string_list_definition unnamed_enum$285;
	extern s_string_list_definition unnamed_enum$286;
	extern s_tag_reference_definition bitmap_group_reference$3;

	extern s_tag_struct_definition structure_lightmap_lighting_environment_block_struct_definition;
	extern s_string_list_definition unnamed_enum$294;
	extern s_string_list_definition unnamed_enum$295;

	extern s_tag_struct_definition structure_lightmap_palette_color_block_struct_definition;

	extern s_tag_struct_definition structure_lightmap_sampling_info_block_struct_definition;

	extern s_tag_struct_definition structure_lightmap_surface_block_struct_definition;

	extern s_tag_struct_definition structure_physics_struct_struct_definition;

	extern s_tag_struct_definition structure_portal_device_mapping_block_struct_definition;

	extern s_tag_struct_definition structure_shared_edge_block_struct_definition;

	extern s_tag_struct_definition structure_shared_edge_group_block_struct_definition;

	extern s_tag_struct_definition structure_sound_cluster_interior_cluster_indices_struct_definition;

	extern s_tag_struct_definition structure_sound_cluster_portal_designators_struct_definition;

	extern s_tag_struct_definition structure_strip_segment_first_triangle_index_block_struct_definition;

	extern s_tag_struct_definition structure_subcluster_block_struct_definition;

	extern s_tag_struct_definition structure_subcluster_boundary_block_struct_definition;

	extern s_tag_struct_definition style_block_struct_definition;
	extern s_string_list_definition unnamed_enum$484;
	extern s_string_list_definition unnamed_enum$60;
	extern s_string_list_definition unnamed_enum$485;
	extern s_string_list_definition unnamed_enum$486;
	extern s_string_list_definition unnamed_enum$487;
	extern s_string_list_definition unnamed_enum$488;
	extern s_string_list_definition unnamed_enum$489;
	extern s_string_list_definition unnamed_enum$490;
	extern s_string_list_definition unnamed_enum$491;

	extern s_tag_struct_definition style_palette_block_struct_definition;
	extern s_tag_reference_definition style_group_reference;

	extern s_tag_struct_definition super_detonation_damage_struct_definition;

	extern s_tag_struct_definition surface_flags_block_struct_definition;

	extern s_tag_struct_definition surfaces_block_struct_definition;

	extern s_tag_struct_definition syntax_datum_block_struct_definition;

	extern s_tag_struct_definition table_view_list_item_reference_block_struct_definition;

	extern s_tag_struct_definition table_view_list_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$543;

	extern s_tag_struct_definition table_view_list_row_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$544;

	extern s_tag_struct_definition tag_block_index_block_struct_definition;

	extern s_tag_struct_definition tag_block_index_struct_struct_definition;

	extern s_tag_struct_definition tag_import_file_block_struct_definition;

	extern s_tag_struct_definition text_block_reference_block_struct_definition;

	extern s_tag_struct_definition text_value_pair_block_struct_definition;
	extern s_tag_reference_definition text_value_pair_definition_group_reference;

	extern s_tag_struct_definition text_value_pair_definition_block_struct_definition;

	extern s_tag_struct_definition text_value_pair_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$420;

	extern s_tag_struct_definition texture_block_struct_definition;

	extern s_tag_struct_definition texture_stage_state_block_struct_definition;

	extern s_tag_struct_definition texture_stage_state_parameter_block_struct_definition;

	extern s_tag_struct_definition torque_curve_struct_struct_definition;

	extern s_tag_struct_definition transparent_planes_block_struct_definition;

	extern s_tag_struct_definition triangles_block_struct_definition;

	extern s_tag_struct_definition trigger_references_struct_definition;
	extern s_string_list_definition unnamed_enum$84;

	extern s_tag_struct_definition triggers_block_struct_definition;
	extern s_string_list_definition unnamed_enum$92;

	extern s_tag_struct_definition ui_campaign_block_struct_definition;

	extern s_tag_struct_definition ui_error_block_struct_definition;
	extern s_string_list_definition unnamed_enum$549;
	extern s_string_list_definition unnamed_enum$547;
	extern s_string_list_definition unnamed_enum$548;

	extern s_tag_struct_definition ui_error_category_block_struct_definition;

	extern s_tag_struct_definition ui_levels_definition_block_struct_definition;

	extern s_tag_struct_definition ui_light_reference_block_struct_definition;

	extern s_tag_struct_definition ui_model_scene_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$545;

	extern s_tag_struct_definition ui_object_reference_block_struct_definition;

	extern s_tag_struct_definition unit_additional_node_names_struct_definition;

	extern s_tag_struct_definition unit_block_struct_definition;

	extern s_tag_struct_definition unit_boarding_melee_struct_definition;

	extern s_tag_struct_definition unit_boost_struct_struct_definition;

	extern s_tag_struct_definition unit_camera_struct_struct_definition;

	extern s_tag_struct_definition unit_camera_track_block_struct_definition;

	extern s_tag_struct_definition unit_hud_auxilary_overlay_block_struct_definition;
	extern s_string_list_definition unnamed_enum$500;
	extern s_string_list_definition unnamed_enum$501;

	extern s_tag_struct_definition unit_hud_auxilary_panel_block_struct_definition;
	extern s_string_list_definition unnamed_enum$503;
	extern s_string_list_definition unnamed_enum$499;
	extern s_string_list_definition unnamed_enum$504;

	extern s_tag_struct_definition unit_hud_interface_block_struct_definition;

	extern s_tag_struct_definition unit_hud_reference_block_struct_definition;

	extern s_tag_struct_definition unit_hud_sound_block_struct_definition;
	extern s_string_list_definition unnamed_enum$502;

	extern s_tag_struct_definition unit_lipsync_scales_struct_definition;

	extern s_tag_struct_definition unit_postures_block_struct_definition;

	extern s_tag_struct_definition unit_seat_acceleration_struct_struct_definition;

	extern s_tag_struct_definition unit_seat_struct_definition;
	extern s_string_list_definition unnamed_enum$113;
	extern s_string_list_definition unnamed_enum$114;

	extern s_tag_struct_definition unit_weapon_block_struct_definition;
	extern s_tag_reference_definition weapon_group_reference$3;

	extern s_tag_struct_definition user_hint_block_struct_definition;

	extern s_tag_struct_definition user_hint_climb_block_struct_definition;
	extern s_string_list_definition unnamed_enum$377;

	extern s_tag_struct_definition user_hint_flight_block_struct_definition;

	extern s_tag_struct_definition user_hint_flight_point_block_struct_definition;

	extern s_tag_struct_definition user_hint_jump_block_struct_definition;
	extern s_string_list_definition unnamed_enum$378;

	extern s_tag_struct_definition user_hint_line_segment_struct_definition;

	extern s_tag_struct_definition user_hint_parallelogram_struct_definition;

	extern s_tag_struct_definition user_hint_point_struct_definition;

	extern s_tag_struct_definition user_hint_polygon_block_struct_definition;

	extern s_tag_struct_definition user_hint_ray_struct_definition;

	extern s_tag_struct_definition user_hint_well_block_struct_definition;
	extern s_string_list_definition unnamed_enum$379;

	extern s_tag_struct_definition user_hint_well_point_block_struct_definition;
	extern s_string_list_definition unnamed_enum$380;

	extern s_tag_struct_definition user_interface_globals_definition_block_struct_definition;
	extern s_tag_reference_definition user_interface_shared_globals_definition_group_reference;
	extern s_tag_reference_definition multiplayer_variant_settings_interface_definition_group_reference;

	extern s_tag_struct_definition user_interface_list_skin_definition_block_struct_definition;
	extern s_string_list_definition unnamed_enum$421;

	extern s_tag_struct_definition user_interface_screen_widget_definition_block_struct_definition;
	extern s_string_list_definition unnamed_enum$535;
	extern s_string_list_definition unnamed_enum$536;
	extern s_string_list_definition unnamed_enum$537;
	extern s_string_list_definition unnamed_enum$546;
	extern s_tag_reference_definition mouse_cursor_definition_group_reference;

	extern s_tag_struct_definition user_interface_shared_globals_definition_block_struct_definition;

	extern s_tag_struct_definition user_interface_widget_reference_block_struct_definition;

	extern s_tag_struct_definition variant_setting_edit_reference_block_struct_definition;
	extern s_string_list_definition unnamed_enum$203;

	extern s_tag_struct_definition vehicle_block_struct_definition;
	extern s_string_list_definition unnamed_enum$505;
	extern s_string_list_definition unnamed_enum$506;
	extern s_string_list_definition unnamed_enum$507;
	extern s_string_list_definition unnamed_enum$508;
	extern s_string_list_definition unnamed_enum$509;
	extern s_string_list_definition unnamed_enum$510;

	extern s_tag_struct_definition vehicle_collection_block_struct_definition;

	extern s_tag_struct_definition vehicle_permutation_struct_definition;
	extern s_tag_reference_definition vehicle_group_reference$4;

	extern s_tag_struct_definition vehicle_phantom_shape_block_struct_definition;
	extern s_string_list_definition unnamed_enum$515;

	extern s_tag_struct_definition vehicle_struct_definition;
	extern s_tag_reference_definition unit_group_reference$2;
	extern s_string_list_definition unnamed_enum$151;

	extern s_tag_struct_definition vehicle_suspension_block_struct_definition;

	extern s_tag_struct_definition vehicles_block_struct_definition;
	extern s_tag_reference_definition vehicle_group_reference$2;

	extern s_tag_struct_definition vehicles_block_struct_definition$2;
	extern s_tag_reference_definition vehicle_group_reference$3;

	extern s_tag_struct_definition vertex_shader_block_struct_definition;

	extern s_tag_struct_definition vertex_shader_classification_block_struct_definition;

	extern s_tag_struct_definition vertex_shader_constant_block_struct_definition;

	extern s_tag_struct_definition vertex_shader_reference_block_struct_definition;
	extern s_tag_reference_definition vertex_shader_group_reference;

	extern s_tag_struct_definition vertices_block_struct_definition;

	extern s_tag_struct_definition vibration_definition_struct_struct_definition;

	extern s_tag_struct_definition vibration_frequency_definition_struct_struct_definition;

	extern s_tag_struct_definition visibility_mopp_reorder_table_block_struct_definition;

	extern s_tag_struct_definition visibility_struct_struct_definition;

	extern s_tag_struct_definition vocalization_patterns_block_struct_definition;
	extern s_string_list_definition unnamed_enum$54;
	extern s_string_list_definition unnamed_enum$55;
	extern s_string_list_definition unnamed_enum$56;
	extern s_string_list_definition unnamed_enum$57;
	extern s_string_list_definition unnamed_enum$58;
	extern s_string_list_definition unnamed_enum$59;
	extern s_string_list_definition unnamed_enum$61;
	extern s_string_list_definition unnamed_enum$62;
	extern s_string_list_definition unnamed_enum$63;
	extern s_string_list_definition unnamed_enum$64;

	extern s_tag_struct_definition water_geometry_section_block_struct_definition;

	extern s_tag_struct_definition weapon_ammunition_object_struct_definition;

	extern s_tag_struct_definition weapon_barrel_damage_effect_struct_definition;

	extern s_tag_struct_definition weapon_barrel_definition_struct_definition;
	extern s_string_list_definition unnamed_enum$529;
	extern s_string_list_definition unnamed_enum$530;
	extern s_string_list_definition unnamed_enum$531;

	extern s_tag_struct_definition weapon_class_block_struct_definition;

	extern s_tag_struct_definition weapon_class_lookup_block_struct_definition;

	extern s_tag_struct_definition weapon_first_person_interface_block_struct_definition;
	extern s_tag_reference_definition render_model_group_reference$5;
	extern s_tag_reference_definition model_animation_graph_group_reference$3;

	extern s_tag_struct_definition weapon_hud_crosshair_block_struct_definition;
	extern s_string_list_definition unnamed_enum$557;
	extern s_string_list_definition unnamed_enum$555;

	extern s_tag_struct_definition weapon_hud_crosshair_item_block_struct_definition;
	extern s_string_list_definition unnamed_enum$558;

	extern s_tag_struct_definition weapon_hud_interface_block_struct_definition;
	extern s_tag_reference_definition weapon_hud_interface_group_reference;
	extern s_string_list_definition unnamed_enum$553;

	extern s_tag_struct_definition weapon_hud_meter_block_struct_definition;
	extern s_string_list_definition unnamed_enum$554;

	extern s_tag_struct_definition weapon_hud_number_block_struct_definition;
	extern s_string_list_definition unnamed_enum$556;

	extern s_tag_struct_definition weapon_hud_overlay_block_struct_definition;
	extern s_string_list_definition unnamed_enum$559;

	extern s_tag_struct_definition weapon_hud_overlays_block_struct_definition;

	extern s_tag_struct_definition weapon_hud_static_block_struct_definition;

	extern s_tag_struct_definition weapon_interface_struct_struct_definition;

	extern s_tag_struct_definition weapon_magazine_struct_definition;
	extern s_string_list_definition unnamed_enum$522;

	extern s_tag_struct_definition weapon_shared_interface_struct_struct_definition;

	extern s_tag_struct_definition weapon_struct_definition$3;
	extern s_string_list_definition unnamed_enum$516;
	extern s_string_list_definition unnamed_enum$517;
	extern s_string_list_definition unnamed_enum$518;
	extern s_string_list_definition unnamed_enum$519;
	extern s_string_list_definition unnamed_enum$520;
	extern s_tag_reference_definition vehicle_group_reference$5;
	extern s_tag_reference_definition weapon_group_reference$7;
	extern s_tag_reference_definition render_model_group_reference$6;
	extern s_tag_reference_definition character_group_reference$6;

	extern s_tag_struct_definition weapon_struct_definition;
	extern s_string_list_definition unnamed_enum$147;
	extern s_string_list_definition unnamed_enum$148;
	extern s_string_list_definition unnamed_enum$149;
	extern s_tag_reference_definition damage_effect_group_reference$2;

	extern s_tag_struct_definition weapon_tracking_struct_definition;
	extern s_string_list_definition unnamed_enum$521;

	extern s_tag_struct_definition weapon_trigger_autofire_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$527;

	extern s_tag_struct_definition weapon_trigger_charging_struct_struct_definition;
	extern s_string_list_definition unnamed_enum$528;

	extern s_tag_struct_definition weapon_triggers_struct_definition;
	extern s_string_list_definition unnamed_enum$523;
	extern s_string_list_definition unnamed_enum$524;
	extern s_string_list_definition unnamed_enum$525;
	extern s_string_list_definition unnamed_enum$526;

	extern s_tag_struct_definition weapon_type_block_struct_definition;

	extern s_tag_struct_definition weapons_block_struct_definition;

	extern s_tag_struct_definition weather_system_block_struct_definition;

	extern s_tag_struct_definition wind_block_struct_definition;

	extern s_tag_struct_definition window_pane_reference_block_struct_definition;

	extern s_tag_struct_definition zone_set_struct_definition;
	extern s_string_list_definition unnamed_enum$81;

	extern s_tag_struct_definition zone_v2_struct_definition;
	extern s_string_list_definition unnamed_enum$72;

	extern s_tag_data_definition aligned_animation_data_definition;

	extern s_tag_data_definition animation_data_definition;

	extern s_tag_data_definition bitmap_pixel_data;

	extern s_tag_data_definition cluster_mopp_code_data;

	extern s_tag_data_definition cluster_remap_table_tag_data_definition;

	extern s_tag_data_definition code_block;

	extern s_tag_data_definition color_plate_data;

	extern s_tag_data_definition compiled_pixel_shader_block;

	extern s_tag_data_definition compiled_shader_block;

	extern s_tag_data_definition editor_scenario_data_definition;

	extern s_tag_data_definition error_report_string_data$2;

	extern s_tag_data_definition error_report_string_data;

	extern s_tag_data_definition generic_tag_data;

	extern s_tag_data_definition global_geometry_runtime_plane_data_definition;

	extern s_tag_data_definition global_geometry_runtime_point_data_definition;

	extern s_tag_data_definition global_section_mopp_code_data;

	extern s_tag_data_definition hs_old_syntax_data_definition;

	extern s_tag_data_definition hs_source_data_definition;

	extern s_tag_data_definition hs_string_data_definition;

	extern s_tag_data_definition large_permutation_sound_samples;

	extern s_tag_data_definition meter_stencil_data_definition;

	extern s_tag_data_definition mopp_code_data;

	extern s_tag_data_definition mopp_codes_data;

	extern s_tag_data_definition mopp_codes_data$2;

	extern s_tag_data_definition old_sound_samples;

	extern s_tag_data_definition old_unused_mopp_code_data;

	extern s_tag_data_definition parameters_text_definition;

	extern s_tag_data_definition projection_tag_data_definition;

	extern s_tag_data_definition rasterizer_screen_effect_text_definition;

	extern s_tag_data_definition recorded_animation_event_stream_data;

	extern s_tag_data_definition shader_postprocess_compiled_pixel_shader_data;

	extern s_tag_data_definition shader_text_definition;

	extern s_tag_data_definition sound_effect_hardware_format_data_definition;

	extern s_tag_data_definition sound_effect_template_explanation;

	extern s_tag_data_definition sound_lipsync_data;

	extern s_tag_data_definition sound_mouth_data;

	extern s_tag_data_definition sound_samples;

	extern s_tag_data_definition sound_subtitle_data;

	extern s_tag_data_definition string_data_definition;

	extern s_tag_data_definition structure_bsp_cluster_data_definition;

	extern s_tag_data_definition structure_bsp_cluster_encoded_sound_data;

	extern s_tag_data_definition structure_bsp_cluster_visibility_mopp_code_data;

	extern s_tag_data_definition structure_bsp_cluster_visibility_subcluster_bitvector;

	extern s_tag_data_definition tag_import_file_zipped_data_definition;

	extern s_tag_data_definition utf8_string_data;

	extern s_tag_data_definition visibility_clusters_tag_data_definition;

	extern s_tag_data_definition visibility_volumes_table_tag_data_definition;


} // namespace pc64

} // namespace halo2

} // namespace blofeld

