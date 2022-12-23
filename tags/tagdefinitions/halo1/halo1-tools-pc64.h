#pragma once

namespace blofeld::halo1::pc64
{

	static constexpr uint32_t ACTOR_TAG = 'actr';
	BCS_SHARED extern s_tag_group actor_group;

	static constexpr uint32_t ACTOR_VARIANT_TAG = 'actv';
	BCS_SHARED extern s_tag_group actor_variant_group;

	static constexpr uint32_t ANTENNA_TAG = 'ant!';
	BCS_SHARED extern s_tag_group antenna_group;

	static constexpr uint32_t BIPED_TAG = 'bipd';
	BCS_SHARED extern s_tag_group biped_group;

	static constexpr uint32_t BITMAP_TAG = 'bitm';
	BCS_SHARED extern s_tag_group bitmap_group;

	static constexpr uint32_t CAMERA_TRACK_TAG = 'trak';
	BCS_SHARED extern s_tag_group camera_track_group;

	static constexpr uint32_t COLOR_TABLE_TAG = 'colo';
	BCS_SHARED extern s_tag_group color_table_group;

	static constexpr uint32_t CONTINUOUS_DAMAGE_EFFECT_TAG = 'cdmg';
	BCS_SHARED extern s_tag_group continuous_damage_effect_group;

	static constexpr uint32_t CONTRAIL_TAG = 'cont';
	BCS_SHARED extern s_tag_group contrail_group;

	static constexpr uint32_t DAMAGE_EFFECT_TAG = 'jpt!';
	BCS_SHARED extern s_tag_group damage_effect_group;

	static constexpr uint32_t DECAL_TAG = 'deca';
	BCS_SHARED extern s_tag_group decal_group;

	static constexpr uint32_t DETAIL_OBJECT_COLLECTION_TAG = 'dobc';
	BCS_SHARED extern s_tag_group detail_object_collection_group;

	static constexpr uint32_t DEVICE_TAG = 'devi';
	BCS_SHARED extern s_tag_group device_group;

	static constexpr uint32_t DEVICE_CONTROL_TAG = 'ctrl';
	BCS_SHARED extern s_tag_group device_control_group;

	static constexpr uint32_t DEVICE_LIGHT_FIXTURE_TAG = 'lifi';
	BCS_SHARED extern s_tag_group device_light_fixture_group;

	static constexpr uint32_t DEVICE_MACHINE_TAG = 'mach';
	BCS_SHARED extern s_tag_group device_machine_group;

	static constexpr uint32_t DIALOGUE_TAG = 'udlg';
	BCS_SHARED extern s_tag_group dialogue_group;

	static constexpr uint32_t EFFECT_TAG = 'effe';
	BCS_SHARED extern s_tag_group effect_group;

	static constexpr uint32_t EQUIPMENT_TAG = 'eqip';
	BCS_SHARED extern s_tag_group equipment_group;

	static constexpr uint32_t FLAG_TAG = 'flag';
	BCS_SHARED extern s_tag_group flag_group;

	static constexpr uint32_t FOG_TAG = 'fog ';
	BCS_SHARED extern s_tag_group fog_group;

	static constexpr uint32_t FONT_TAG = 'font';
	BCS_SHARED extern s_tag_group font_group;

	static constexpr uint32_t GARBAGE_TAG = 'garb';
	BCS_SHARED extern s_tag_group garbage_group;

	static constexpr uint32_t GBXMODEL_TAG = 'mod2';
	BCS_SHARED extern s_tag_group gbxmodel_group;

	static constexpr uint32_t GLOBALS_TAG = 'matg';
	BCS_SHARED extern s_tag_group globals_group;

	static constexpr uint32_t GLOW_TAG = 'glw!';
	BCS_SHARED extern s_tag_group glow_group;

	static constexpr uint32_t GRENADE_HUD_INTERFACE_TAG = 'grhi';
	BCS_SHARED extern s_tag_group grenade_hud_interface_group;

	static constexpr uint32_t HUD_GLOBALS_TAG = 'hudg';
	BCS_SHARED extern s_tag_group hud_globals_group;

	static constexpr uint32_t HUD_MESSAGE_TEXT_TAG = 'hmt ';
	BCS_SHARED extern s_tag_group hud_message_text_group;

	static constexpr uint32_t HUD_NUMBER_TAG = 'hud#';
	BCS_SHARED extern s_tag_group hud_number_group;

	static constexpr uint32_t INPUT_DEVICE_DEFAULTS_TAG = 'devc';
	BCS_SHARED extern s_tag_group input_device_defaults_group;

	static constexpr uint32_t ITEM_TAG = 'item';
	BCS_SHARED extern s_tag_group item_group;

	static constexpr uint32_t ITEM_COLLECTION_TAG = 'itmc';
	BCS_SHARED extern s_tag_group item_collection_group;

	static constexpr uint32_t LENS_FLARE_TAG = 'lens';
	BCS_SHARED extern s_tag_group lens_flare_group;

	static constexpr uint32_t LIGHT_TAG = 'ligh';
	BCS_SHARED extern s_tag_group light_group;

	static constexpr uint32_t LIGHT_VOLUME_TAG = 'mgs2';
	BCS_SHARED extern s_tag_group light_volume_group;

	static constexpr uint32_t LIGHTNING_TAG = 'elec';
	BCS_SHARED extern s_tag_group lightning_group;

	static constexpr uint32_t MATERIAL_EFFECTS_TAG = 'foot';
	BCS_SHARED extern s_tag_group material_effects_group;

	static constexpr uint32_t METER_TAG = 'metr';
	BCS_SHARED extern s_tag_group meter_group;

	static constexpr uint32_t MODEL_TAG = 'mode';
	BCS_SHARED extern s_tag_group model_group;

	static constexpr uint32_t MODEL_ANIMATIONS_TAG = 'antr';
	BCS_SHARED extern s_tag_group model_animations_group;

	static constexpr uint32_t MODEL_COLLISION_GEOMETRY_TAG = 'coll';
	BCS_SHARED extern s_tag_group model_collision_geometry_group;

	static constexpr uint32_t MULTIPLAYER_SCENARIO_DESCRIPTION_TAG = 'mply';
	BCS_SHARED extern s_tag_group multiplayer_scenario_description_group;

	static constexpr uint32_t OBJECT_TAG = 'obje';
	BCS_SHARED extern s_tag_group object_group;

	static constexpr uint32_t PARTICLE_TAG = 'part';
	BCS_SHARED extern s_tag_group particle_group;

	static constexpr uint32_t PARTICLE_SYSTEM_TAG = 'pctl';
	BCS_SHARED extern s_tag_group particle_system_group;

	static constexpr uint32_t PHYSICS_TAG = 'phys';
	BCS_SHARED extern s_tag_group physics_group;

	static constexpr uint32_t PLACEHOLDER_TAG = 'plac';
	BCS_SHARED extern s_tag_group placeholder_group;

	static constexpr uint32_t POINT_PHYSICS_TAG = 'pphy';
	BCS_SHARED extern s_tag_group point_physics_group;

	static constexpr uint32_t PREFERENCES_NETWORK_GAME_TAG = 'ngpr';
	BCS_SHARED extern s_tag_group preferences_network_game_group;

	static constexpr uint32_t PROJECTILE_TAG = 'proj';
	BCS_SHARED extern s_tag_group projectile_group;

	static constexpr uint32_t SCENARIO_TAG = 'scnr';
	BCS_SHARED extern s_tag_group scenario_group;

	static constexpr uint32_t SCENARIO_STRUCTURE_BSP_TAG = 'sbsp';
	BCS_SHARED extern s_tag_group scenario_structure_bsp_group;

	static constexpr uint32_t SCENERY_TAG = 'scen';
	BCS_SHARED extern s_tag_group scenery_group;

	static constexpr uint32_t SHADER_TAG = 'shdr';
	BCS_SHARED extern s_tag_group shader_group;

	static constexpr uint32_t SHADER_ENVIRONMENT_TAG = 'senv';
	BCS_SHARED extern s_tag_group shader_environment_group;

	static constexpr uint32_t SHADER_MODEL_TAG = 'soso';
	BCS_SHARED extern s_tag_group shader_model_group;

	static constexpr uint32_t SHADER_TRANSPARENT_CHICAGO_TAG = 'schi';
	BCS_SHARED extern s_tag_group shader_transparent_chicago_group;

	static constexpr uint32_t SHADER_TRANSPARENT_CHICAGO_EXTENDED_TAG = 'scex';
	BCS_SHARED extern s_tag_group shader_transparent_chicago_extended_group;

	static constexpr uint32_t SHADER_TRANSPARENT_GENERIC_TAG = 'sotr';
	BCS_SHARED extern s_tag_group shader_transparent_generic_group;

	static constexpr uint32_t SHADER_TRANSPARENT_GLASS_TAG = 'sgla';
	BCS_SHARED extern s_tag_group shader_transparent_glass_group;

	static constexpr uint32_t SHADER_TRANSPARENT_METER_TAG = 'smet';
	BCS_SHARED extern s_tag_group shader_transparent_meter_group;

	static constexpr uint32_t SHADER_TRANSPARENT_PLASMA_TAG = 'spla';
	BCS_SHARED extern s_tag_group shader_transparent_plasma_group;

	static constexpr uint32_t SHADER_TRANSPARENT_WATER_TAG = 'swat';
	BCS_SHARED extern s_tag_group shader_transparent_water_group;

	static constexpr uint32_t SKY_TAG = 'sky ';
	BCS_SHARED extern s_tag_group sky_group;

	static constexpr uint32_t SOUND_TAG = 'snd!';
	BCS_SHARED extern s_tag_group sound_group;

	static constexpr uint32_t SOUND_ENVIRONMENT_TAG = 'snde';
	BCS_SHARED extern s_tag_group sound_environment_group;

	static constexpr uint32_t SOUND_LOOPING_TAG = 'lsnd';
	BCS_SHARED extern s_tag_group sound_looping_group;

	static constexpr uint32_t SOUND_SCENERY_TAG = 'ssce';
	BCS_SHARED extern s_tag_group sound_scenery_group;

	static constexpr uint32_t STRING_LIST_TAG = 'str#';
	BCS_SHARED extern s_tag_group string_list_group;

	static constexpr uint32_t TAG_COLLECTION_TAG = 'tagc';
	BCS_SHARED extern s_tag_group tag_collection_group;

	static constexpr uint32_t UI_WIDGET_COLLECTION_TAG = 'Soul';
	BCS_SHARED extern s_tag_group ui_widget_collection_group;

	static constexpr uint32_t UI_WIDGET_DEFINITION_TAG = 'DeLa';
	BCS_SHARED extern s_tag_group ui_widget_definition_group;

	static constexpr uint32_t UNICODE_STRING_LIST_TAG = 'ustr';
	BCS_SHARED extern s_tag_group unicode_string_list_group;

	static constexpr uint32_t UNIT_TAG = 'unit';
	BCS_SHARED extern s_tag_group unit_group;

	static constexpr uint32_t UNIT_HUD_INTERFACE_TAG = 'unhi';
	BCS_SHARED extern s_tag_group unit_hud_interface_group;

	static constexpr uint32_t VEHICLE_TAG = 'vehi';
	BCS_SHARED extern s_tag_group vehicle_group;

	static constexpr uint32_t VIRTUAL_KEYBOARD_TAG = 'vcky';
	BCS_SHARED extern s_tag_group virtual_keyboard_group;

	static constexpr uint32_t WEAPON_TAG = 'weap';
	BCS_SHARED extern s_tag_group weapon_group;

	static constexpr uint32_t WEAPON_HUD_INTERFACE_TAG = 'wphi';
	BCS_SHARED extern s_tag_group weapon_hud_interface_group;

	static constexpr uint32_t WEATHER_PARTICLE_SYSTEM_TAG = 'rain';
	BCS_SHARED extern s_tag_group weather_particle_system_group;

	static constexpr uint32_t WIND_TAG = 'wind';
	BCS_SHARED extern s_tag_group wind_group;

	BCS_SHARED extern s_tag_block_definition actor_group_block;

	BCS_SHARED extern s_tag_block_definition actor_palette_block;

	BCS_SHARED extern s_tag_block_definition actor_starting_locations_block;

	BCS_SHARED extern s_tag_block_definition actor_variant_group_block;

	BCS_SHARED extern s_tag_block_definition actor_variant_change_colors_block;

	BCS_SHARED extern s_tag_block_definition ai_animation_reference_block;

	BCS_SHARED extern s_tag_block_definition ai_command_block;

	BCS_SHARED extern s_tag_block_definition ai_command_list_block;

	BCS_SHARED extern s_tag_block_definition ai_command_point_block;

	BCS_SHARED extern s_tag_block_definition ai_conversation_block;

	BCS_SHARED extern s_tag_block_definition ai_conversation_line_block;

	BCS_SHARED extern s_tag_block_definition ai_conversation_participant_block;

	BCS_SHARED extern s_tag_block_definition ai_recording_reference_block;

	BCS_SHARED extern s_tag_block_definition ai_script_reference_block;

	BCS_SHARED extern s_tag_block_definition animation_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_first_person_weapon_animations_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_node_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_object_overlay_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_sound_reference_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_unit_seat_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_unit_seat_ik_point_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_vehicle_animations_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_weapon_animations_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_weapon_block;

	BCS_SHARED extern s_tag_block_definition animation_graph_weapon_type_block;

	BCS_SHARED extern s_tag_block_definition antenna_group_block;

	BCS_SHARED extern s_tag_block_definition antenna_vertex_block;

	BCS_SHARED extern s_tag_block_definition biped_group_block;

	BCS_SHARED extern s_tag_block_definition bitmap_group_block;

	BCS_SHARED extern s_tag_block_definition bitmap_data_block;

	BCS_SHARED extern s_tag_block_definition bitmap_group_sequence_block;

	BCS_SHARED extern s_tag_block_definition bitmap_group_sprite_block;

	BCS_SHARED extern s_tag_block_definition breakable_surface_particle_effect_block;

	BCS_SHARED extern s_tag_block_definition bsp2d_nodes_block;

	BCS_SHARED extern s_tag_block_definition bsp2d_references_block;

	BCS_SHARED extern s_tag_block_definition bsp3d_nodes_block;

	BCS_SHARED extern s_tag_block_definition camera_block;

	BCS_SHARED extern s_tag_block_definition camera_track_group_block;

	BCS_SHARED extern s_tag_block_definition camera_track_control_point_block;

	BCS_SHARED extern s_tag_block_definition cheat_powerups_block;

	BCS_SHARED extern s_tag_block_definition cheat_weapons_block;

	BCS_SHARED extern s_tag_block_definition child_widget_reference_block;

	BCS_SHARED extern s_tag_block_definition collision_bsp_block;

	BCS_SHARED extern s_tag_block_definition collision_bsps_block;

	BCS_SHARED extern s_tag_block_definition collision_nodes_block;

	BCS_SHARED extern s_tag_block_definition color_block;

	BCS_SHARED extern s_tag_block_definition color_table_group_block;

	BCS_SHARED extern s_tag_block_definition conditional_widget_reference_block;

	BCS_SHARED extern s_tag_block_definition contact_point_block;

	BCS_SHARED extern s_tag_block_definition continuous_damage_effect_group_block;

	BCS_SHARED extern s_tag_block_definition contrail_group_block;

	BCS_SHARED extern s_tag_block_definition contrail_point_states_block;

	BCS_SHARED extern s_tag_block_definition damage_effect_group_block;

	BCS_SHARED extern s_tag_block_definition damage_materials_block;

	BCS_SHARED extern s_tag_block_definition damage_modifiers_block;

	BCS_SHARED extern s_tag_block_definition damage_permutations_block;

	BCS_SHARED extern s_tag_block_definition damage_regions_block;

	BCS_SHARED extern s_tag_block_definition decal_group_block;

	BCS_SHARED extern s_tag_block_definition detail_object_collection_group_block;

	BCS_SHARED extern s_tag_block_definition detail_object_type_block;

	BCS_SHARED extern s_tag_block_definition device_animation_block;

	BCS_SHARED extern s_tag_block_definition device_animations_block;

	BCS_SHARED extern s_tag_block_definition device_group_block;

	BCS_SHARED extern s_tag_block_definition device_control_group_block;

	BCS_SHARED extern s_tag_block_definition device_group_block$2;

	BCS_SHARED extern s_tag_block_definition device_light_fixture_group_block;

	BCS_SHARED extern s_tag_block_definition device_machine_group_block;

	BCS_SHARED extern s_tag_block_definition dialogue_group_block;

	BCS_SHARED extern s_tag_block_definition dialogue_variant_block;

	BCS_SHARED extern s_tag_block_definition difficulty_block;

	BCS_SHARED extern s_tag_block_definition edges_block;

	BCS_SHARED extern s_tag_block_definition editor_comment_block;

	BCS_SHARED extern s_tag_block_definition effect_group_block;

	BCS_SHARED extern s_tag_block_definition effect_event_block;

	BCS_SHARED extern s_tag_block_definition effect_locations_block;

	BCS_SHARED extern s_tag_block_definition effect_part_block;

	BCS_SHARED extern s_tag_block_definition effect_particles_block;

	BCS_SHARED extern s_tag_block_definition encounter_block;

	BCS_SHARED extern s_tag_block_definition equipment_group_block;

	BCS_SHARED extern s_tag_block_definition event_handler_references_block;

	BCS_SHARED extern s_tag_block_definition falling_damage_block;

	BCS_SHARED extern s_tag_block_definition firing_positions_block;

	BCS_SHARED extern s_tag_block_definition first_person_interface_block;

	BCS_SHARED extern s_tag_block_definition first_person_weapon_block;

	BCS_SHARED extern s_tag_block_definition flag_attachment_point_block;

	BCS_SHARED extern s_tag_block_definition flag_group_block;

	BCS_SHARED extern s_tag_block_definition fog_group_block;

	BCS_SHARED extern s_tag_block_definition font_group_block;

	BCS_SHARED extern s_tag_block_definition font_character_block;

	BCS_SHARED extern s_tag_block_definition font_character_table_block;

	BCS_SHARED extern s_tag_block_definition font_character_tables_block;

	BCS_SHARED extern s_tag_block_definition game_data_input_references_block;

	BCS_SHARED extern s_tag_block_definition garbage_group_block;

	BCS_SHARED extern s_tag_block_definition gbxmodel_group_block;

	BCS_SHARED extern s_tag_block_definition gbxmodel_geometry_block;

	BCS_SHARED extern s_tag_block_definition gbxmodel_geometry_part_block;

	BCS_SHARED extern s_tag_block_definition gbxmodel_region_block;

	BCS_SHARED extern s_tag_block_definition gbxmodel_region_permutation_block;

	BCS_SHARED extern s_tag_block_definition gg_sound_block;

	BCS_SHARED extern s_tag_block_definition global_detail_object_block;

	BCS_SHARED extern s_tag_block_definition global_detail_object_cells_block;

	BCS_SHARED extern s_tag_block_definition global_detail_object_counts_block;

	BCS_SHARED extern s_tag_block_definition global_hud_multitexture_overlay_definition_block;

	BCS_SHARED extern s_tag_block_definition global_hud_multitexture_overlay_effector_definition_block;

	BCS_SHARED extern s_tag_block_definition global_hud_screen_effect_definition_block;

	BCS_SHARED extern s_tag_block_definition global_leaf_portal_block;

	BCS_SHARED extern s_tag_block_definition global_map_leaf_block;

	BCS_SHARED extern s_tag_block_definition global_z_reference_vector_block;

	BCS_SHARED extern s_tag_block_definition globals_group_block;

	BCS_SHARED extern s_tag_block_definition glow_group_block;

	BCS_SHARED extern s_tag_block_definition grenade_hud_interface_group_block;

	BCS_SHARED extern s_tag_block_definition grenade_hud_overlay_block;

	BCS_SHARED extern s_tag_block_definition grenade_hud_sound_block;

	BCS_SHARED extern s_tag_block_definition grenades_block;

	BCS_SHARED extern s_tag_block_definition hs_globals_block;

	BCS_SHARED extern s_tag_block_definition hs_references_block;

	BCS_SHARED extern s_tag_block_definition hs_scripts_block;

	BCS_SHARED extern s_tag_block_definition hs_source_files_block;

	BCS_SHARED extern s_tag_block_definition hud_bitmap_remap_element_block_definition_block;

	BCS_SHARED extern s_tag_block_definition hud_bitmap_remaps_block_definition_block;

	BCS_SHARED extern s_tag_block_definition hud_button_icon_block;

	BCS_SHARED extern s_tag_block_definition hud_globals_group_block;

	BCS_SHARED extern s_tag_block_definition hud_message_elements_block;

	BCS_SHARED extern s_tag_block_definition hud_message_text_group_block;

	BCS_SHARED extern s_tag_block_definition hud_messages_block;

	BCS_SHARED extern s_tag_block_definition hud_number_group_block;

	BCS_SHARED extern s_tag_block_definition hud_waypoint_arrow_block;

	BCS_SHARED extern s_tag_block_definition inertial_matrix_block;

	BCS_SHARED extern s_tag_block_definition input_device_defaults_group_block;

	BCS_SHARED extern s_tag_block_definition interface_tag_references_block;

	BCS_SHARED extern s_tag_block_definition item_group_block;

	BCS_SHARED extern s_tag_block_definition item_collection_group_block;

	BCS_SHARED extern s_tag_block_definition item_permutation_block;

	BCS_SHARED extern s_tag_block_definition leaf_portal_vertex_block;

	BCS_SHARED extern s_tag_block_definition leaves_block;

	BCS_SHARED extern s_tag_block_definition lens_flare_group_block;

	BCS_SHARED extern s_tag_block_definition lens_flare_reflection_block;

	BCS_SHARED extern s_tag_block_definition light_group_block;

	BCS_SHARED extern s_tag_block_definition light_volume_group_block;

	BCS_SHARED extern s_tag_block_definition light_volume_frame_block;

	BCS_SHARED extern s_tag_block_definition lightning_group_block;

	BCS_SHARED extern s_tag_block_definition lightning_marker_block;

	BCS_SHARED extern s_tag_block_definition lightning_shader_block;

	BCS_SHARED extern s_tag_block_definition look_function_block;

	BCS_SHARED extern s_tag_block_definition looping_sound_detail_block;

	BCS_SHARED extern s_tag_block_definition looping_sound_track_block;

	BCS_SHARED extern s_tag_block_definition magazine_objects_block;

	BCS_SHARED extern s_tag_block_definition magazines_block;

	BCS_SHARED extern s_tag_block_definition map_leaf_face_block;

	BCS_SHARED extern s_tag_block_definition map_leaf_face_vertex_block;

	BCS_SHARED extern s_tag_block_definition map_leaf_portal_index_block;

	BCS_SHARED extern s_tag_block_definition mass_point_block;

	BCS_SHARED extern s_tag_block_definition material_effect_block;

	BCS_SHARED extern s_tag_block_definition material_effect_material_block;

	BCS_SHARED extern s_tag_block_definition material_effects_group_block;

	BCS_SHARED extern s_tag_block_definition materials_block;

	BCS_SHARED extern s_tag_block_definition meter_group_block;

	BCS_SHARED extern s_tag_block_definition model_animations_group_block;

	BCS_SHARED extern s_tag_block_definition model_group_block;

	BCS_SHARED extern s_tag_block_definition model_collision_geometry_group_block;

	BCS_SHARED extern s_tag_block_definition model_geometry_block;

	BCS_SHARED extern s_tag_block_definition model_geometry_part_block;

	BCS_SHARED extern s_tag_block_definition model_marker_instance_block;

	BCS_SHARED extern s_tag_block_definition model_markers_block;

	BCS_SHARED extern s_tag_block_definition model_node_block;

	BCS_SHARED extern s_tag_block_definition model_region_block;

	BCS_SHARED extern s_tag_block_definition model_region_permutation_block;

	BCS_SHARED extern s_tag_block_definition model_region_permutation_marker_block;

	BCS_SHARED extern s_tag_block_definition model_shader_reference_block;

	BCS_SHARED extern s_tag_block_definition model_triangle_block;

	BCS_SHARED extern s_tag_block_definition model_vertex_compressed_block;

	BCS_SHARED extern s_tag_block_definition model_vertex_uncompressed_block;

	BCS_SHARED extern s_tag_block_definition move_positions_block;

	BCS_SHARED extern s_tag_block_definition multiplayer_information_block;

	BCS_SHARED extern s_tag_block_definition multiplayer_scenario_description_group_block;

	BCS_SHARED extern s_tag_block_definition object_attachment_block;

	BCS_SHARED extern s_tag_block_definition object_group_block;

	BCS_SHARED extern s_tag_block_definition object_change_color_permutations_block;

	BCS_SHARED extern s_tag_block_definition object_change_colors_block;

	BCS_SHARED extern s_tag_block_definition object_function_block;

	BCS_SHARED extern s_tag_block_definition object_widget_block;

	BCS_SHARED extern s_tag_block_definition particle_group_block;

	BCS_SHARED extern s_tag_block_definition particle_system_group_block;

	BCS_SHARED extern s_tag_block_definition particle_system_physics_constants_block;

	BCS_SHARED extern s_tag_block_definition particle_system_type_particle_states_block;

	BCS_SHARED extern s_tag_block_definition particle_system_type_states_block;

	BCS_SHARED extern s_tag_block_definition particle_system_types_block;

	BCS_SHARED extern s_tag_block_definition pathfinding_spheres_block;

	BCS_SHARED extern s_tag_block_definition physics_group_block;

	BCS_SHARED extern s_tag_block_definition placeholder_group_block;

	BCS_SHARED extern s_tag_block_definition planes_block;

	BCS_SHARED extern s_tag_block_definition platoons_block;

	BCS_SHARED extern s_tag_block_definition player_control_block;

	BCS_SHARED extern s_tag_block_definition player_information_block;

	BCS_SHARED extern s_tag_block_definition playlist_autogenerate_choice_block;

	BCS_SHARED extern s_tag_block_definition point_physics_group_block;

	BCS_SHARED extern s_tag_block_definition powered_mass_point_block;

	BCS_SHARED extern s_tag_block_definition powered_seat_block;

	BCS_SHARED extern s_tag_block_definition predicted_resource_block;

	BCS_SHARED extern s_tag_block_definition preferences_network_game_group_block;

	BCS_SHARED extern s_tag_block_definition projectile_group_block;

	BCS_SHARED extern s_tag_block_definition projectile_material_response_block;

	BCS_SHARED extern s_tag_block_definition rasterizer_data_block;

	BCS_SHARED extern s_tag_block_definition recorded_animation_block;

	BCS_SHARED extern s_tag_block_definition scenario_biped_block;

	BCS_SHARED extern s_tag_block_definition scenario_biped_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_group_block;

	BCS_SHARED extern s_tag_block_definition scenario_bsp_switch_trigger_volume_block;

	BCS_SHARED extern s_tag_block_definition scenario_child_scenario_block;

	BCS_SHARED extern s_tag_block_definition scenario_control_block;

	BCS_SHARED extern s_tag_block_definition scenario_control_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_cutscene_camera_point_block;

	BCS_SHARED extern s_tag_block_definition scenario_cutscene_flag_block;

	BCS_SHARED extern s_tag_block_definition scenario_cutscene_title_block;

	BCS_SHARED extern s_tag_block_definition scenario_decal_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_decals_block;

	BCS_SHARED extern s_tag_block_definition scenario_description_block;

	BCS_SHARED extern s_tag_block_definition scenario_detail_object_collection_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_equipment_block;

	BCS_SHARED extern s_tag_block_definition scenario_equipment_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_function_block;

	BCS_SHARED extern s_tag_block_definition scenario_light_fixture_block;

	BCS_SHARED extern s_tag_block_definition scenario_light_fixture_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_machine_block;

	BCS_SHARED extern s_tag_block_definition scenario_machine_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_netgame_equipment_block;

	BCS_SHARED extern s_tag_block_definition scenario_netgame_flags_block;

	BCS_SHARED extern s_tag_block_definition scenario_object_names_block;

	BCS_SHARED extern s_tag_block_definition scenario_players_block;

	BCS_SHARED extern s_tag_block_definition scenario_profiles_block;

	BCS_SHARED extern s_tag_block_definition scenario_scavenger_hunt_object_block;

	BCS_SHARED extern s_tag_block_definition scenario_scenery_block;

	BCS_SHARED extern s_tag_block_definition scenario_scenery_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_sky_reference_block;

	BCS_SHARED extern s_tag_block_definition scenario_sound_scenery_block;

	BCS_SHARED extern s_tag_block_definition scenario_sound_scenery_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_starting_equipment_block;

	BCS_SHARED extern s_tag_block_definition scenario_structure_bsp_group_block;

	BCS_SHARED extern s_tag_block_definition scenario_structure_bsps_block;

	BCS_SHARED extern s_tag_block_definition scenario_trigger_volume_block;

	BCS_SHARED extern s_tag_block_definition scenario_vehicle_block;

	BCS_SHARED extern s_tag_block_definition scenario_vehicle_palette_block;

	BCS_SHARED extern s_tag_block_definition scenario_weapon_block;

	BCS_SHARED extern s_tag_block_definition scenario_weapon_palette_block;

	BCS_SHARED extern s_tag_block_definition scenery_group_block;

	BCS_SHARED extern s_tag_block_definition search_and_replace_reference_block;

	BCS_SHARED extern s_tag_block_definition shader_group_block;

	BCS_SHARED extern s_tag_block_definition shader_environment_group_block;

	BCS_SHARED extern s_tag_block_definition shader_model_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_chicago_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_chicago_extended_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_chicago_map_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_generic_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_generic_map_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_generic_stage_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_glass_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_layer_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_meter_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_plasma_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_water_group_block;

	BCS_SHARED extern s_tag_block_definition shader_transparent_water_ripple_block;

	BCS_SHARED extern s_tag_block_definition sky_animation_block;

	BCS_SHARED extern s_tag_block_definition sky_group_block;

	BCS_SHARED extern s_tag_block_definition sky_light_block;

	BCS_SHARED extern s_tag_block_definition sky_shader_function_block;

	BCS_SHARED extern s_tag_block_definition sound_group_block;

	BCS_SHARED extern s_tag_block_definition sound_environment_group_block;

	BCS_SHARED extern s_tag_block_definition sound_looping_group_block;

	BCS_SHARED extern s_tag_block_definition sound_permutations_block;

	BCS_SHARED extern s_tag_block_definition sound_pitch_range_block;

	BCS_SHARED extern s_tag_block_definition sound_scenery_group_block;

	BCS_SHARED extern s_tag_block_definition sounds_block;

	BCS_SHARED extern s_tag_block_definition squads_block;

	BCS_SHARED extern s_tag_block_definition string_list_group_block;

	BCS_SHARED extern s_tag_block_definition string_list_string_reference_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_background_sound_palette_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_breakable_surface_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_cluster_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_cluster_portal_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_cluster_portal_index_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_cluster_portal_vertex_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_cluster_surface_index_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_detail_object_data_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_fog_palette_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_fog_plane_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_fog_plane_vertex_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_fog_region_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_leaf_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_lens_flare_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_lens_flare_marker_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_lightmap_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_marker_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_material_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_mirror_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_mirror_vertex_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_node_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_pathfinding_edges_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_pathfinding_surfaces_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_runtime_decal_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_sound_environment_palette_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_subcluster_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_subcluster_surface_index_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_surface_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_surface_reference_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_weather_palette_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_weather_polyhedron_block;

	BCS_SHARED extern s_tag_block_definition structure_bsp_weather_polyhedron_plane_block;

	BCS_SHARED extern s_tag_block_definition structure_collision_materials_block;

	BCS_SHARED extern s_tag_block_definition surfaces_block;

	BCS_SHARED extern s_tag_block_definition suspension_animation_block;

	BCS_SHARED extern s_tag_block_definition tag_collection_group_block;

	BCS_SHARED extern s_tag_block_definition tag_collection_tag_reference_block;

	BCS_SHARED extern s_tag_block_definition trigger_firing_effect_block;

	BCS_SHARED extern s_tag_block_definition triggers_block;

	BCS_SHARED extern s_tag_block_definition ui_widget_collection_group_block;

	BCS_SHARED extern s_tag_block_definition ui_widget_definition_group_block;

	BCS_SHARED extern s_tag_block_definition ui_widget_references_block;

	BCS_SHARED extern s_tag_block_definition unicode_string_list_group_block;

	BCS_SHARED extern s_tag_block_definition unicode_string_list_string_reference_block;

	BCS_SHARED extern s_tag_block_definition unit_group_block;

	BCS_SHARED extern s_tag_block_definition unit_camera_track_block;

	BCS_SHARED extern s_tag_block_definition unit_damage_animations_block;

	BCS_SHARED extern s_tag_block_definition unit_hud_auxilary_overlay_block;

	BCS_SHARED extern s_tag_block_definition unit_hud_auxilary_panel_block;

	BCS_SHARED extern s_tag_block_definition unit_hud_interface_group_block;

	BCS_SHARED extern s_tag_block_definition unit_hud_reference_block;

	BCS_SHARED extern s_tag_block_definition unit_hud_sound_block;

	BCS_SHARED extern s_tag_block_definition unit_seat_animation_block;

	BCS_SHARED extern s_tag_block_definition unit_seat_block;

	BCS_SHARED extern s_tag_block_definition unit_weapon_block;

	BCS_SHARED extern s_tag_block_definition vehicle_animation_block;

	BCS_SHARED extern s_tag_block_definition vehicle_group_block;

	BCS_SHARED extern s_tag_block_definition vehicles_block;

	BCS_SHARED extern s_tag_block_definition vertices_block;

	BCS_SHARED extern s_tag_block_definition virtual_key_block;

	BCS_SHARED extern s_tag_block_definition virtual_keyboard_group_block;

	BCS_SHARED extern s_tag_block_definition weapon_animation_block;

	BCS_SHARED extern s_tag_block_definition weapon_group_block;

	BCS_SHARED extern s_tag_block_definition weapon_class_animation_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_crosshair_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_crosshair_item_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_interface_group_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_meter_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_number_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_overlay_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_overlays_block;

	BCS_SHARED extern s_tag_block_definition weapon_hud_static_block;

	BCS_SHARED extern s_tag_block_definition weapon_type_animation_block;

	BCS_SHARED extern s_tag_block_definition weather_particle_system_group_block;

	BCS_SHARED extern s_tag_block_definition weather_particle_type_block;

	BCS_SHARED extern s_tag_block_definition wind_group_block;

	BCS_SHARED extern s_tag_array_definition unnamed_array;

	BCS_SHARED extern s_tag_array_definition unnamed_array$2;

	BCS_SHARED extern s_tag_array_definition unnamed_array$3;

	BCS_SHARED extern s_tag_array_definition unnamed_array$4;

	BCS_SHARED extern s_tag_array_definition unnamed_array$5;

	BCS_SHARED extern s_tag_array_definition unnamed_array$6;

	BCS_SHARED extern s_tag_array_definition unnamed_array$7;

	BCS_SHARED extern s_tag_struct_definition actor_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$14;
	BCS_SHARED extern s_string_list_definition unnamed_enum$15;
	BCS_SHARED extern s_string_list_definition unnamed_enum$16;
	BCS_SHARED extern s_tag_reference_definition weapon_group_reference;
	BCS_SHARED extern s_tag_reference_definition projectile_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$17;
	BCS_SHARED extern s_string_list_definition unnamed_enum$18;
	BCS_SHARED extern s_tag_reference_definition actor_group_reference;

	BCS_SHARED extern s_tag_struct_definition actor_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition actor_variant_group_reference$4;

	BCS_SHARED extern s_tag_struct_definition actor_starting_locations_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$216;
	BCS_SHARED extern s_string_list_definition unnamed_enum$211;

	BCS_SHARED extern s_tag_struct_definition actor_variant_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$19;
	BCS_SHARED extern s_tag_reference_definition unit_group_reference;
	BCS_SHARED extern s_tag_reference_definition actor_variant_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$20;
	BCS_SHARED extern s_string_list_definition unnamed_enum$21;
	BCS_SHARED extern s_string_list_definition unnamed_enum$22;
	BCS_SHARED extern s_string_list_definition unnamed_enum$23;
	BCS_SHARED extern s_string_list_definition unnamed_enum$24;
	BCS_SHARED extern s_string_list_definition unnamed_enum$25;
	BCS_SHARED extern s_string_list_definition unnamed_enum$26;
	BCS_SHARED extern s_string_list_definition unnamed_enum$27;
	BCS_SHARED extern s_tag_reference_definition equipment_group_reference;

	BCS_SHARED extern s_tag_struct_definition actor_variant_change_colors_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition ai_animation_reference_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition model_animations_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition ai_command_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$221;

	BCS_SHARED extern s_tag_struct_definition ai_command_list_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$220;

	BCS_SHARED extern s_tag_struct_definition ai_command_point_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition ai_conversation_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$222;

	BCS_SHARED extern s_tag_struct_definition ai_conversation_line_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$225;
	BCS_SHARED extern s_string_list_definition unnamed_enum$226;
	BCS_SHARED extern s_tag_reference_definition sound_group_reference;

	BCS_SHARED extern s_tag_struct_definition ai_conversation_participant_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$223;
	BCS_SHARED extern s_string_list_definition unnamed_enum$224;

	BCS_SHARED extern s_tag_struct_definition ai_recording_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition ai_script_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$32;
	BCS_SHARED extern s_string_list_definition unnamed_enum$33;
	BCS_SHARED extern s_string_list_definition unnamed_enum$34;

	BCS_SHARED extern s_tag_struct_definition animation_graph_first_person_weapon_animations_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_graph_node_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$31;

	BCS_SHARED extern s_tag_struct_definition animation_graph_object_overlay_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$28;
	BCS_SHARED extern s_string_list_definition unnamed_enum$29;

	BCS_SHARED extern s_tag_struct_definition animation_graph_sound_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_graph_unit_seat_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_graph_unit_seat_ik_point_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_graph_vehicle_animations_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_graph_weapon_animations_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_graph_weapon_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition animation_graph_weapon_type_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition antenna_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition bitmap_group_reference$2;
	BCS_SHARED extern s_tag_reference_definition point_physics_group_reference;

	BCS_SHARED extern s_tag_struct_definition antenna_vertex_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition array$2;

	BCS_SHARED extern s_tag_struct_definition array$3;

	BCS_SHARED extern s_tag_struct_definition array$4;

	BCS_SHARED extern s_tag_struct_definition array$7;

	BCS_SHARED extern s_tag_struct_definition array$6;

	BCS_SHARED extern s_tag_struct_definition array$5;

	BCS_SHARED extern s_tag_struct_definition array;

	BCS_SHARED extern s_tag_struct_definition biped_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$35;
	BCS_SHARED extern s_tag_reference_definition gbxmodel_group_reference;
	BCS_SHARED extern s_tag_reference_definition model_animations_group_reference;
	BCS_SHARED extern s_tag_reference_definition model_collision_geometry_group_reference;
	BCS_SHARED extern s_tag_reference_definition physics_group_reference;
	BCS_SHARED extern s_tag_reference_definition shader_group_reference;
	BCS_SHARED extern s_tag_reference_definition effect_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$36;
	BCS_SHARED extern s_string_list_definition unnamed_enum$46;
	BCS_SHARED extern s_string_list_definition unnamed_enum$47;
	BCS_SHARED extern s_string_list_definition unnamed_enum$48;
	BCS_SHARED extern s_string_list_definition unnamed_enum$49;
	BCS_SHARED extern s_tag_reference_definition actor_variant_group_reference$2;
	BCS_SHARED extern s_tag_reference_definition damage_effect_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$50;
	BCS_SHARED extern s_string_list_definition unnamed_enum$52;
	BCS_SHARED extern s_string_list_definition unnamed_enum$53;
	BCS_SHARED extern s_tag_reference_definition material_effects_group_reference;

	BCS_SHARED extern s_tag_struct_definition bitmap_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$54;
	BCS_SHARED extern s_string_list_definition unnamed_enum$55;
	BCS_SHARED extern s_string_list_definition unnamed_enum$56;
	BCS_SHARED extern s_string_list_definition unnamed_enum$57;
	BCS_SHARED extern s_string_list_definition unnamed_enum$58;
	BCS_SHARED extern s_string_list_definition unnamed_enum$59;

	BCS_SHARED extern s_tag_struct_definition bitmap_data_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$60;
	BCS_SHARED extern s_string_list_definition unnamed_enum$61;
	BCS_SHARED extern s_string_list_definition unnamed_enum$62;

	BCS_SHARED extern s_tag_struct_definition bitmap_group_sequence_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition bitmap_group_sprite_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition breakable_surface_particle_effect_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition particle_group_reference$2;
	BCS_SHARED extern s_string_list_definition unnamed_enum$149;

	BCS_SHARED extern s_tag_struct_definition bsp2d_nodes_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition bsp2d_references_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition bsp3d_nodes_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition camera_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition camera_track_group_reference;

	BCS_SHARED extern s_tag_struct_definition camera_track_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$264;

	BCS_SHARED extern s_tag_struct_definition camera_track_control_point_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition cheat_powerups_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition cheat_weapons_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition item_group_reference;

	BCS_SHARED extern s_tag_struct_definition child_widget_reference_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition ui_widget_definition_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$13;

	BCS_SHARED extern s_tag_struct_definition collision_bsp_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition collision_bsps_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition collision_nodes_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition color_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition color_table_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition conditional_widget_reference_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$12;

	BCS_SHARED extern s_tag_struct_definition contact_point_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition continuous_damage_effect_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$41;
	BCS_SHARED extern s_string_list_definition unnamed_enum$63;
	BCS_SHARED extern s_string_list_definition unnamed_enum$64;
	BCS_SHARED extern s_string_list_definition unnamed_enum$65;

	BCS_SHARED extern s_tag_struct_definition contrail_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$72;
	BCS_SHARED extern s_string_list_definition unnamed_enum$73;
	BCS_SHARED extern s_string_list_definition unnamed_enum$74;
	BCS_SHARED extern s_tag_reference_definition bitmap_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$75;
	BCS_SHARED extern s_string_list_definition unnamed_enum$76;
	BCS_SHARED extern s_string_list_definition unnamed_enum$77;
	BCS_SHARED extern s_string_list_definition unnamed_enum$78;
	BCS_SHARED extern s_string_list_definition unnamed_enum$79;
	BCS_SHARED extern s_string_list_definition unnamed_enum$37;

	BCS_SHARED extern s_tag_struct_definition contrail_point_states_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$80;

	BCS_SHARED extern s_tag_struct_definition damage_effect_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$132;
	BCS_SHARED extern s_string_list_definition unnamed_enum$133;
	BCS_SHARED extern s_string_list_definition unnamed_enum$134;
	BCS_SHARED extern s_string_list_definition unnamed_enum$42;

	BCS_SHARED extern s_tag_struct_definition damage_materials_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$68;
	BCS_SHARED extern s_string_list_definition unnamed_enum$67;

	BCS_SHARED extern s_tag_struct_definition damage_modifiers_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition damage_permutations_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition damage_regions_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$69;

	BCS_SHARED extern s_tag_struct_definition decal_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$85;
	BCS_SHARED extern s_string_list_definition unnamed_enum$86;
	BCS_SHARED extern s_string_list_definition unnamed_enum$87;
	BCS_SHARED extern s_tag_reference_definition decal_group_reference;

	BCS_SHARED extern s_tag_struct_definition detail_object_collection_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$90;

	BCS_SHARED extern s_tag_struct_definition detail_object_type_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$91;

	BCS_SHARED extern s_tag_struct_definition device_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition device_animations_struct_definition;

	BCS_SHARED extern s_tag_struct_definition device_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$81;
	BCS_SHARED extern s_string_list_definition unnamed_enum$82;
	BCS_SHARED extern s_tag_reference_definition sound_group_effect_group_reference;

	BCS_SHARED extern s_tag_struct_definition device_control_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$83;
	BCS_SHARED extern s_string_list_definition unnamed_enum$84;

	BCS_SHARED extern s_tag_struct_definition device_group_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$200;

	BCS_SHARED extern s_tag_struct_definition device_light_fixture_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition device_machine_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$145;
	BCS_SHARED extern s_string_list_definition unnamed_enum$146;
	BCS_SHARED extern s_string_list_definition unnamed_enum$147;

	BCS_SHARED extern s_tag_struct_definition dialogue_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition sound_group_reference$3;

	BCS_SHARED extern s_tag_struct_definition dialogue_variant_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition dialogue_group_reference;

	BCS_SHARED extern s_tag_struct_definition difficulty_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition edges_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition editor_comment_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition effect_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$92;

	BCS_SHARED extern s_tag_struct_definition effect_event_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition effect_locations_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition effect_part_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$93;
	BCS_SHARED extern s_string_list_definition unnamed_enum$94;
	BCS_SHARED extern s_string_list_definition unnamed_enum$95;
	BCS_SHARED extern s_tag_reference_definition damage_effect_group_object_group_particle_system_group_sound_group_decal_group_light_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$96;

	BCS_SHARED extern s_tag_struct_definition effect_particles_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$97;
	BCS_SHARED extern s_tag_reference_definition particle_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$98;
	BCS_SHARED extern s_string_list_definition unnamed_enum$99;
	BCS_SHARED extern s_string_list_definition unnamed_enum$100;

	BCS_SHARED extern s_tag_struct_definition encounter_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$208;
	BCS_SHARED extern s_string_list_definition unnamed_enum$209;
	BCS_SHARED extern s_string_list_definition unnamed_enum$210;

	BCS_SHARED extern s_tag_struct_definition equipment_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$102;
	BCS_SHARED extern s_string_list_definition unnamed_enum$103;
	BCS_SHARED extern s_string_list_definition unnamed_enum$104;

	BCS_SHARED extern s_tag_struct_definition event_handler_references_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$5;
	BCS_SHARED extern s_string_list_definition unnamed_enum$6;
	BCS_SHARED extern s_string_list_definition unnamed_enum$7;

	BCS_SHARED extern s_tag_struct_definition falling_damage_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition firing_positions_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$219;

	BCS_SHARED extern s_tag_struct_definition first_person_interface_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition gbxmodel_group_reference$2;
	BCS_SHARED extern s_tag_reference_definition meter_group_reference;

	BCS_SHARED extern s_tag_struct_definition first_person_weapon_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition flag_attachment_point_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition flag_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$105;
	BCS_SHARED extern s_string_list_definition unnamed_enum$106;
	BCS_SHARED extern s_string_list_definition unnamed_enum$107;

	BCS_SHARED extern s_tag_struct_definition fog_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$108;
	BCS_SHARED extern s_string_list_definition unnamed_enum$109;
	BCS_SHARED extern s_tag_reference_definition sound_looping_group_reference;
	BCS_SHARED extern s_tag_reference_definition sound_environment_group_reference;

	BCS_SHARED extern s_tag_struct_definition font_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition font_group_reference;

	BCS_SHARED extern s_tag_struct_definition font_character_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition font_character_table_struct_definition;

	BCS_SHARED extern s_tag_struct_definition font_character_tables_struct_definition;

	BCS_SHARED extern s_tag_struct_definition game_data_input_references_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$4;

	BCS_SHARED extern s_tag_struct_definition garbage_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition gbxmodel_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$154;

	BCS_SHARED extern s_tag_struct_definition gbxmodel_geometry_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$156;

	BCS_SHARED extern s_tag_struct_definition gbxmodel_geometry_part_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$157;

	BCS_SHARED extern s_tag_struct_definition gbxmodel_region_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition gbxmodel_region_permutation_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$155;

	BCS_SHARED extern s_tag_struct_definition gg_sound_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition global_detail_object_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition global_detail_object_cells_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition global_detail_object_counts_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition global_hud_multitexture_overlay_definition_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$118;
	BCS_SHARED extern s_string_list_definition unnamed_enum$119;
	BCS_SHARED extern s_string_list_definition unnamed_enum$120;

	BCS_SHARED extern s_tag_struct_definition global_hud_multitexture_overlay_effector_definition_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$121;
	BCS_SHARED extern s_string_list_definition unnamed_enum$122;
	BCS_SHARED extern s_string_list_definition unnamed_enum$123;

	BCS_SHARED extern s_tag_struct_definition global_hud_screen_effect_definition_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$293;
	BCS_SHARED extern s_string_list_definition unnamed_enum$294;
	BCS_SHARED extern s_string_list_definition unnamed_enum$295;
	BCS_SHARED extern s_string_list_definition unnamed_enum$296;

	BCS_SHARED extern s_tag_struct_definition global_leaf_portal_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition global_map_leaf_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition global_z_reference_vector_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition globals_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition glow_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$110;
	BCS_SHARED extern s_string_list_definition unnamed_enum$111;
	BCS_SHARED extern s_string_list_definition unnamed_enum$112;
	BCS_SHARED extern s_string_list_definition unnamed_enum$113;
	BCS_SHARED extern s_string_list_definition unnamed_enum$114;

	BCS_SHARED extern s_tag_struct_definition grenade_hud_interface_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$115;
	BCS_SHARED extern s_string_list_definition unnamed_enum$116;
	BCS_SHARED extern s_string_list_definition unnamed_enum$117;
	BCS_SHARED extern s_string_list_definition unnamed_enum$124;
	BCS_SHARED extern s_string_list_definition unnamed_enum$128;

	BCS_SHARED extern s_tag_struct_definition grenade_hud_overlay_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$125;
	BCS_SHARED extern s_string_list_definition unnamed_enum$126;

	BCS_SHARED extern s_tag_struct_definition grenade_hud_sound_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition sound_group_sound_looping_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$127;

	BCS_SHARED extern s_tag_struct_definition grenades_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition grenade_hud_interface_group_reference;

	BCS_SHARED extern s_tag_struct_definition hs_globals_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$228;

	BCS_SHARED extern s_tag_struct_definition hs_references_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition _reference;

	BCS_SHARED extern s_tag_struct_definition hs_scripts_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$227;

	BCS_SHARED extern s_tag_struct_definition hs_source_files_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition hud_bitmap_remap_element_block_definition_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$130;
	BCS_SHARED extern s_string_list_definition unnamed_enum$131;

	BCS_SHARED extern s_tag_struct_definition hud_bitmap_remaps_block_definition_struct_definition;

	BCS_SHARED extern s_tag_struct_definition hud_button_icon_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition hud_globals_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition unicode_string_list_group_reference;
	BCS_SHARED extern s_tag_reference_definition hud_message_text_group_reference;
	BCS_SHARED extern s_tag_reference_definition weapon_hud_interface_group_reference;

	BCS_SHARED extern s_tag_struct_definition hud_message_elements_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition hud_message_text_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition hud_messages_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition hud_number_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition hud_waypoint_arrow_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$129;

	BCS_SHARED extern s_tag_struct_definition inertial_matrix_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition input_device_defaults_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$88;
	BCS_SHARED extern s_string_list_definition unnamed_enum$89;

	BCS_SHARED extern s_tag_struct_definition interface_tag_references_struct_definition;
	BCS_SHARED extern s_tag_reference_definition color_table_group_reference;
	BCS_SHARED extern s_tag_reference_definition hud_globals_group_reference;
	BCS_SHARED extern s_tag_reference_definition string_list_group_reference;
	BCS_SHARED extern s_tag_reference_definition hud_number_group_reference;

	BCS_SHARED extern s_tag_struct_definition item_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition item_collection_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition item_permutation_struct_definition;

	BCS_SHARED extern s_tag_struct_definition leaf_portal_vertex_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition leaves_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$70;

	BCS_SHARED extern s_tag_struct_definition lens_flare_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$135;
	BCS_SHARED extern s_string_list_definition unnamed_enum$136;
	BCS_SHARED extern s_string_list_definition unnamed_enum$137;

	BCS_SHARED extern s_tag_struct_definition lens_flare_reflection_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$138;
	BCS_SHARED extern s_string_list_definition unnamed_enum$139;
	BCS_SHARED extern s_string_list_definition unnamed_enum$140;

	BCS_SHARED extern s_tag_struct_definition light_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$141;
	BCS_SHARED extern s_string_list_definition unnamed_enum$44;
	BCS_SHARED extern s_tag_reference_definition lens_flare_group_reference;

	BCS_SHARED extern s_tag_struct_definition light_volume_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$153;

	BCS_SHARED extern s_tag_struct_definition light_volume_frame_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition lightning_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$38;

	BCS_SHARED extern s_tag_struct_definition lightning_marker_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$101;

	BCS_SHARED extern s_tag_struct_definition lightning_shader_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition look_function_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition looping_sound_detail_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$144;

	BCS_SHARED extern s_tag_struct_definition looping_sound_track_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$143;

	BCS_SHARED extern s_tag_struct_definition magazine_objects_struct_definition;

	BCS_SHARED extern s_tag_struct_definition magazines_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$280;
	BCS_SHARED extern s_tag_reference_definition sound_group_effect_group_reference$3;

	BCS_SHARED extern s_tag_struct_definition map_leaf_face_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition map_leaf_face_vertex_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition map_leaf_portal_index_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition mass_point_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$167;
	BCS_SHARED extern s_string_list_definition unnamed_enum$168;

	BCS_SHARED extern s_tag_struct_definition material_effect_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition material_effect_material_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition material_effects_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition materials_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition meter_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$150;
	BCS_SHARED extern s_tag_reference_definition bitmap_group_reference$4;
	BCS_SHARED extern s_string_list_definition unnamed_enum$151;
	BCS_SHARED extern s_string_list_definition unnamed_enum$152;

	BCS_SHARED extern s_tag_struct_definition model_animations_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$30;

	BCS_SHARED extern s_tag_struct_definition model_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_collision_geometry_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$66;

	BCS_SHARED extern s_tag_struct_definition model_geometry_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_geometry_part_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_marker_instance_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_markers_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_node_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_region_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_region_permutation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_region_permutation_marker_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_shader_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_triangle_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_vertex_compressed_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition model_vertex_uncompressed_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition move_positions_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition multiplayer_information_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition unit_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition multiplayer_scenario_description_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition object_attachment_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition light_group_light_volume_group_contrail_group_particle_system_group_effect_group_sound_looping_group_reference;

	BCS_SHARED extern s_tag_struct_definition object_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition object_change_color_permutations_struct_definition;

	BCS_SHARED extern s_tag_struct_definition object_change_colors_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$40;

	BCS_SHARED extern s_tag_struct_definition object_function_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$39;
	BCS_SHARED extern s_string_list_definition unnamed_enum$43;

	BCS_SHARED extern s_tag_struct_definition object_widget_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition flag_group_antenna_group_glow_group_light_volume_group_lightning_group_reference;

	BCS_SHARED extern s_tag_struct_definition particle_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$158;
	BCS_SHARED extern s_tag_reference_definition sound_group_effect_group_reference$2;
	BCS_SHARED extern s_string_list_definition unnamed_enum$159;

	BCS_SHARED extern s_tag_struct_definition particle_system_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$160;
	BCS_SHARED extern s_string_list_definition unnamed_enum$161;

	BCS_SHARED extern s_tag_struct_definition particle_system_physics_constants_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition particle_system_type_particle_states_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition particle_system_type_states_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$164;
	BCS_SHARED extern s_string_list_definition unnamed_enum$165;

	BCS_SHARED extern s_tag_struct_definition particle_system_types_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$162;
	BCS_SHARED extern s_string_list_definition unnamed_enum$163;

	BCS_SHARED extern s_tag_struct_definition pathfinding_spheres_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition physics_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition placeholder_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition planes_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition platoons_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$217;
	BCS_SHARED extern s_string_list_definition unnamed_enum$218;

	BCS_SHARED extern s_tag_struct_definition player_control_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition player_information_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition playlist_autogenerate_choice_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition point_physics_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$169;

	BCS_SHARED extern s_tag_struct_definition powered_mass_point_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$166;

	BCS_SHARED extern s_tag_struct_definition powered_seat_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition predicted_resource_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$45;

	BCS_SHARED extern s_tag_struct_definition preferences_network_game_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition projectile_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$170;
	BCS_SHARED extern s_string_list_definition unnamed_enum$171;
	BCS_SHARED extern s_string_list_definition unnamed_enum$172;

	BCS_SHARED extern s_tag_struct_definition projectile_material_response_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$173;
	BCS_SHARED extern s_string_list_definition unnamed_enum$174;
	BCS_SHARED extern s_string_list_definition unnamed_enum$175;
	BCS_SHARED extern s_string_list_definition unnamed_enum$176;

	BCS_SHARED extern s_tag_struct_definition rasterizer_data_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition bitmap_group_reference$3;
	BCS_SHARED extern s_string_list_definition unnamed_enum$148;

	BCS_SHARED extern s_tag_struct_definition recorded_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_biped_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$195;
	BCS_SHARED extern s_string_list_definition unnamed_enum$196;

	BCS_SHARED extern s_tag_struct_definition scenario_biped_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition biped_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition scenario_structure_bsp_group_reference;
	BCS_SHARED extern s_tag_reference_definition sky_group_reference;
	BCS_SHARED extern s_string_list_definition unnamed_enum$191;
	BCS_SHARED extern s_string_list_definition unnamed_enum$192;
	BCS_SHARED extern s_tag_reference_definition unicode_string_list_group_reference$2;
	BCS_SHARED extern s_tag_reference_definition hud_message_text_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition scenario_bsp_switch_trigger_volume_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_child_scenario_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition scenario_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_control_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$201;
	BCS_SHARED extern s_string_list_definition unnamed_enum$203;

	BCS_SHARED extern s_tag_struct_definition scenario_control_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition device_control_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_cutscene_camera_point_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_cutscene_flag_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_cutscene_title_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$229;
	BCS_SHARED extern s_string_list_definition unnamed_enum$230;
	BCS_SHARED extern s_string_list_definition unnamed_enum$231;

	BCS_SHARED extern s_tag_struct_definition scenario_decal_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition decal_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition scenario_decals_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_description_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_detail_object_collection_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition detail_object_collection_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_equipment_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$198;

	BCS_SHARED extern s_tag_struct_definition scenario_equipment_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition equipment_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition scenario_function_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$193;
	BCS_SHARED extern s_string_list_definition unnamed_enum$194;

	BCS_SHARED extern s_tag_struct_definition scenario_light_fixture_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_light_fixture_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition device_light_fixture_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_machine_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$202;

	BCS_SHARED extern s_tag_struct_definition scenario_machine_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition device_machine_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_netgame_equipment_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$206;
	BCS_SHARED extern s_string_list_definition unnamed_enum$204;
	BCS_SHARED extern s_tag_reference_definition item_collection_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_netgame_flags_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$205;

	BCS_SHARED extern s_tag_struct_definition scenario_object_names_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_players_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_profiles_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition weapon_group_reference$4;

	BCS_SHARED extern s_tag_struct_definition scenario_scavenger_hunt_object_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_scenery_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_scenery_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition scenery_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_sky_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_sound_scenery_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_sound_scenery_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition sound_scenery_group_reference;

	BCS_SHARED extern s_tag_struct_definition scenario_starting_equipment_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$207;

	BCS_SHARED extern s_tag_struct_definition scenario_structure_bsp_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_structure_bsps_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_trigger_volume_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition scenario_vehicle_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$197;

	BCS_SHARED extern s_tag_struct_definition scenario_vehicle_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition vehicle_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition scenario_weapon_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$199;

	BCS_SHARED extern s_tag_struct_definition scenario_weapon_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition weapon_group_reference$3;

	BCS_SHARED extern s_tag_struct_definition scenery_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$182;

	BCS_SHARED extern s_tag_struct_definition search_and_replace_reference_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$8;

	BCS_SHARED extern s_tag_struct_definition shader_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$183;
	BCS_SHARED extern s_string_list_definition unnamed_enum$184;
	BCS_SHARED extern s_string_list_definition unnamed_enum$185;

	BCS_SHARED extern s_tag_struct_definition shader_environment_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$232;
	BCS_SHARED extern s_string_list_definition unnamed_enum$233;
	BCS_SHARED extern s_tag_reference_definition lens_flare_group_reference$2;
	BCS_SHARED extern s_string_list_definition unnamed_enum$234;
	BCS_SHARED extern s_string_list_definition unnamed_enum$235;
	BCS_SHARED extern s_string_list_definition unnamed_enum$236;
	BCS_SHARED extern s_string_list_definition unnamed_enum$237;
	BCS_SHARED extern s_string_list_definition unnamed_enum$238;
	BCS_SHARED extern s_string_list_definition unnamed_enum$239;

	BCS_SHARED extern s_tag_struct_definition shader_model_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$249;
	BCS_SHARED extern s_string_list_definition unnamed_enum$250;
	BCS_SHARED extern s_string_list_definition unnamed_enum$251;
	BCS_SHARED extern s_string_list_definition unnamed_enum$252;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_chicago_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$186;
	BCS_SHARED extern s_string_list_definition unnamed_enum$187;
	BCS_SHARED extern s_string_list_definition unnamed_enum$190;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_chicago_extended_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_chicago_map_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$188;
	BCS_SHARED extern s_string_list_definition unnamed_enum$189;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_generic_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$253;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_generic_map_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$254;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_generic_stage_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$255;
	BCS_SHARED extern s_string_list_definition unnamed_enum$256;
	BCS_SHARED extern s_string_list_definition unnamed_enum$257;
	BCS_SHARED extern s_string_list_definition unnamed_enum$258;
	BCS_SHARED extern s_string_list_definition unnamed_enum$259;
	BCS_SHARED extern s_string_list_definition unnamed_enum$260;
	BCS_SHARED extern s_string_list_definition unnamed_enum$261;
	BCS_SHARED extern s_string_list_definition unnamed_enum$262;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_glass_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$240;
	BCS_SHARED extern s_string_list_definition unnamed_enum$241;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_layer_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_meter_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$243;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_plasma_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_water_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$263;

	BCS_SHARED extern s_tag_struct_definition shader_transparent_water_ripple_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition sky_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition sky_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition gbxmodel_group_reference$3;
	BCS_SHARED extern s_tag_reference_definition model_animations_group_reference$3;
	BCS_SHARED extern s_tag_reference_definition fog_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition sky_light_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition lens_flare_group_reference$3;
	BCS_SHARED extern s_string_list_definition unnamed_enum$242;

	BCS_SHARED extern s_tag_struct_definition sky_shader_function_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition sound_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$244;
	BCS_SHARED extern s_string_list_definition unnamed_enum$245;
	BCS_SHARED extern s_string_list_definition unnamed_enum$246;
	BCS_SHARED extern s_string_list_definition unnamed_enum$247;
	BCS_SHARED extern s_string_list_definition unnamed_enum$248;

	BCS_SHARED extern s_tag_struct_definition sound_environment_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition sound_looping_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$142;
	BCS_SHARED extern s_tag_reference_definition continuous_damage_effect_group_reference;

	BCS_SHARED extern s_tag_struct_definition sound_permutations_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition sound_pitch_range_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition sound_scenery_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition sounds_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition sound_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition squads_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$212;
	BCS_SHARED extern s_string_list_definition unnamed_enum$213;
	BCS_SHARED extern s_string_list_definition unnamed_enum$214;
	BCS_SHARED extern s_string_list_definition unnamed_enum$215;

	BCS_SHARED extern s_tag_struct_definition string_list_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition string_list_string_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_background_sound_palette_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_breakable_surface_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_cluster_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_cluster_portal_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$181;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_cluster_portal_index_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_cluster_portal_vertex_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_cluster_surface_index_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_detail_object_data_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_fog_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition fog_group_reference;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_fog_plane_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_fog_plane_vertex_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_fog_region_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_leaf_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_lens_flare_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_lens_flare_marker_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_lightmap_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_marker_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_material_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$180;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_mirror_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_mirror_vertex_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_node_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_pathfinding_edges_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_pathfinding_surfaces_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_runtime_decal_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_sound_environment_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition sound_environment_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_subcluster_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_subcluster_surface_index_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_surface_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_surface_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_weather_palette_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition weather_particle_system_group_reference;
	BCS_SHARED extern s_tag_reference_definition wind_group_reference;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_weather_polyhedron_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_bsp_weather_polyhedron_plane_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition structure_collision_materials_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition surfaces_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$71;

	BCS_SHARED extern s_tag_struct_definition suspension_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition tag_collection_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition tag_collection_tag_reference_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition _reference$2;

	BCS_SHARED extern s_tag_struct_definition trigger_firing_effect_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition triggers_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$281;
	BCS_SHARED extern s_string_list_definition unnamed_enum$282;
	BCS_SHARED extern s_string_list_definition unnamed_enum$283;
	BCS_SHARED extern s_string_list_definition unnamed_enum$284;

	BCS_SHARED extern s_tag_struct_definition ui_widget_collection_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition ui_widget_definition_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum;
	BCS_SHARED extern s_string_list_definition unnamed_enum$2;
	BCS_SHARED extern s_string_list_definition unnamed_enum$3;
	BCS_SHARED extern s_string_list_definition unnamed_enum$9;
	BCS_SHARED extern s_string_list_definition unnamed_enum$10;
	BCS_SHARED extern s_string_list_definition unnamed_enum$11;

	BCS_SHARED extern s_tag_struct_definition ui_widget_references_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unicode_string_list_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unicode_string_list_string_reference_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unit_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unit_camera_track_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unit_damage_animations_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unit_hud_auxilary_overlay_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$266;
	BCS_SHARED extern s_string_list_definition unnamed_enum$267;

	BCS_SHARED extern s_tag_struct_definition unit_hud_auxilary_panel_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$269;
	BCS_SHARED extern s_string_list_definition unnamed_enum$265;
	BCS_SHARED extern s_string_list_definition unnamed_enum$270;

	BCS_SHARED extern s_tag_struct_definition unit_hud_interface_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unit_hud_reference_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition unit_hud_interface_group_reference;

	BCS_SHARED extern s_tag_struct_definition unit_hud_sound_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$268;

	BCS_SHARED extern s_tag_struct_definition unit_seat_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition unit_seat_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$51;
	BCS_SHARED extern s_tag_reference_definition actor_variant_group_reference$3;

	BCS_SHARED extern s_tag_struct_definition unit_weapon_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition weapon_group_reference$2;

	BCS_SHARED extern s_tag_struct_definition vehicle_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition vehicle_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$272;
	BCS_SHARED extern s_string_list_definition unnamed_enum$273;
	BCS_SHARED extern s_string_list_definition unnamed_enum$274;

	BCS_SHARED extern s_tag_struct_definition vehicles_block_struct_definition;
	BCS_SHARED extern s_tag_reference_definition vehicle_group_reference;

	BCS_SHARED extern s_tag_struct_definition vertices_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition virtual_key_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$271;

	BCS_SHARED extern s_tag_struct_definition virtual_keyboard_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition weapon_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition weapon_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$275;
	BCS_SHARED extern s_string_list_definition unnamed_enum$276;
	BCS_SHARED extern s_string_list_definition unnamed_enum$277;
	BCS_SHARED extern s_string_list_definition unnamed_enum$278;
	BCS_SHARED extern s_tag_reference_definition gbxmodel_group_reference$4;
	BCS_SHARED extern s_tag_reference_definition model_animations_group_reference$4;
	BCS_SHARED extern s_string_list_definition unnamed_enum$279;

	BCS_SHARED extern s_tag_struct_definition weapon_class_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_crosshair_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$290;
	BCS_SHARED extern s_string_list_definition unnamed_enum$287;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_crosshair_item_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$291;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_interface_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$285;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_meter_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$286;
	BCS_SHARED extern s_string_list_definition unnamed_enum$288;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_number_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$289;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_overlay_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$292;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_overlays_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition weapon_hud_static_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition weapon_type_animation_block_struct_definition;

	BCS_SHARED extern s_tag_struct_definition weather_particle_system_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$177;

	BCS_SHARED extern s_tag_struct_definition weather_particle_type_block_struct_definition;
	BCS_SHARED extern s_string_list_definition unnamed_enum$178;
	BCS_SHARED extern s_string_list_definition unnamed_enum$179;

	BCS_SHARED extern s_tag_struct_definition wind_block_struct_definition;

	BCS_SHARED extern s_tag_data_definition animation_default_data_definition;

	BCS_SHARED extern s_tag_data_definition animation_frame_data_definition;

	BCS_SHARED extern s_tag_data_definition bitmap_pixel_data;

	BCS_SHARED extern s_tag_data_definition color_plate_data;

	BCS_SHARED extern s_tag_data_definition deviceid_data;

	BCS_SHARED extern s_tag_data_definition editor_comment_data_definition;

	BCS_SHARED extern s_tag_data_definition editor_scenario_data_definition;

	BCS_SHARED extern s_tag_data_definition frame_info_data_definition;

	BCS_SHARED extern s_tag_data_definition hs_source_data_definition;

	BCS_SHARED extern s_tag_data_definition hs_string_data_definition;

	BCS_SHARED extern s_tag_data_definition hs_syntax_data_definition;

	BCS_SHARED extern s_tag_data_definition meter_stencil_data_definition;

	BCS_SHARED extern s_tag_data_definition pixels;

	BCS_SHARED extern s_tag_data_definition player_profile_data;

	BCS_SHARED extern s_tag_data_definition recorded_animation_event_stream_data;

	BCS_SHARED extern s_tag_data_definition sound_mouth_data;

	BCS_SHARED extern s_tag_data_definition sound_samples;

	BCS_SHARED extern s_tag_data_definition sound_subtitle_data;

	BCS_SHARED extern s_tag_data_definition string_data;

	BCS_SHARED extern s_tag_data_definition string_data$3;

	BCS_SHARED extern s_tag_data_definition string_data$2;

	BCS_SHARED extern s_tag_data_definition structure_bsp_cluster_data_definition;

	BCS_SHARED extern s_tag_data_definition structure_bsp_cluster_encoded_sound_data;

	BCS_SHARED extern s_tag_data_definition structure_bsp_compressed_vertex_data_definition;

	BCS_SHARED extern s_tag_data_definition structure_bsp_uncompressed_vertex_data_definition;

}
