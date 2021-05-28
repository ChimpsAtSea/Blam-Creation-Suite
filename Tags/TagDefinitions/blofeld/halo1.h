#pragma once

namespace blofeld
{
namespace halo1 {

	static constexpr unsigned long MODEL_TAG = 'mode';
	extern s_tag_group model_group;
	extern s_tag_block_definition model;
	extern s_tag_struct_definition model_struct_definition;
	extern c_versioned_string_list unnamed_enum_strings;
	extern s_string_list_definition unnamed_enum;

	extern s_tag_block_definition model_shader_reference_block;
	extern s_tag_struct_definition model_shader_reference_block_struct_definition;
	extern s_tag_reference_definition shader_reference;

	extern s_tag_block_definition model_geometry_block;
	extern s_tag_struct_definition model_geometry_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$3_strings;
	extern s_string_list_definition unnamed_enum$3;

	extern s_tag_block_definition model_geometry_part_block;
	extern s_tag_struct_definition model_geometry_part_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$4_strings;
	extern s_string_list_definition unnamed_enum$4;

	extern s_tag_block_definition model_triangle_block;
	extern s_tag_struct_definition model_triangle_block_struct_definition;

	extern s_tag_block_definition model_vertex_compressed_block;
	extern s_tag_struct_definition model_vertex_compressed_block_struct_definition;

	extern s_tag_block_definition model_vertex_uncompressed_block;
	extern s_tag_struct_definition model_vertex_uncompressed_block_struct_definition;

	extern s_tag_block_definition model_region_block;
	extern s_tag_struct_definition model_region_block_struct_definition;

	extern s_tag_block_definition model_region_permutation_block;
	extern s_tag_struct_definition model_region_permutation_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$2_strings;
	extern s_string_list_definition unnamed_enum$2;

	extern s_tag_block_definition model_region_permutation_marker_block;
	extern s_tag_struct_definition model_region_permutation_marker_block_struct_definition;

	extern s_tag_block_definition model_node_block;
	extern s_tag_struct_definition model_node_block_struct_definition;

	extern s_tag_block_definition model_markers_block;
	extern s_tag_struct_definition model_markers_block_struct_definition;

	extern s_tag_block_definition model_marker_instance_block;
	extern s_tag_struct_definition model_marker_instance_block_struct_definition;


	static constexpr unsigned long GBXMODEL_TAG = 'mod2';
	extern s_tag_group gbxmodel_group;
	extern s_tag_block_definition gbxmodel;
	extern s_tag_struct_definition gbxmodel_struct_definition;

	extern s_tag_block_definition gbxmodel_geometry_block;
	extern s_tag_struct_definition gbxmodel_geometry_block_struct_definition;

	extern s_tag_block_definition gbxmodel_geometry_part_block;
	extern s_tag_struct_definition gbxmodel_geometry_part_block_struct_definition;

	extern s_tag_block_definition gbxmodel_region_block;
	extern s_tag_struct_definition gbxmodel_region_block_struct_definition;

	extern s_tag_block_definition gbxmodel_region_permutation_block;
	extern s_tag_struct_definition gbxmodel_region_permutation_block_struct_definition;


	static constexpr unsigned long MODEL_ANIMATIONS_TAG = 'antr';
	extern s_tag_group model_animations_group;
	extern s_tag_block_definition model_animations;
	extern s_tag_struct_definition model_animations_struct_definition;
	extern c_versioned_string_list unnamed_enum$10_strings;
	extern s_string_list_definition unnamed_enum$10;

	extern s_tag_block_definition animation_block;
	extern s_tag_struct_definition animation_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$5_strings;
	extern s_string_list_definition unnamed_enum$5;
	extern c_versioned_string_list unnamed_enum$6_strings;
	extern s_string_list_definition unnamed_enum$6;
	extern c_versioned_string_list unnamed_enum$7_strings;
	extern s_string_list_definition unnamed_enum$7;

	extern s_tag_array_definition animation_block__node_scale_flag_data_array;
	extern s_tag_struct_definition animation_block__node_scale_flag_data_array_struct_definition;

	extern s_tag_array_definition animation_block__node_rotation_flag_data_array;
	extern s_tag_struct_definition animation_block__node_rotation_flag_data_array_struct_definition;

	extern s_tag_array_definition animation_block__node_trans_flag_data_array;
	extern s_tag_struct_definition animation_block__node_trans_flag_data_array_struct_definition;

	extern s_tag_block_definition animation_graph_node_block;
	extern s_tag_struct_definition animation_graph_node_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$11_strings;
	extern s_string_list_definition unnamed_enum$11;

	extern s_tag_block_definition animation_graph_sound_reference_block;
	extern s_tag_struct_definition animation_graph_sound_reference_block_struct_definition;
	extern s_tag_reference_definition sound_reference;

	extern s_tag_block_definition animation_graph_first_person_weapon_animations_block;
	extern s_tag_struct_definition animation_graph_first_person_weapon_animations_block_struct_definition;

	extern s_tag_block_definition first_person_weapon_block;
	extern s_tag_struct_definition first_person_weapon_block_struct_definition;

	extern s_tag_block_definition unit_damage_animations;
	extern s_tag_struct_definition unit_damage_animations_struct_definition;

	extern s_tag_block_definition device_animations;
	extern s_tag_struct_definition device_animations_struct_definition;

	extern s_tag_block_definition device_animation_block;
	extern s_tag_struct_definition device_animation_block_struct_definition;

	extern s_tag_block_definition animation_graph_vehicle_animations_block;
	extern s_tag_struct_definition animation_graph_vehicle_animations_block_struct_definition;

	extern s_tag_block_definition suspension_animation_block;
	extern s_tag_struct_definition suspension_animation_block_struct_definition;

	extern s_tag_block_definition vehicle_animation_block;
	extern s_tag_struct_definition vehicle_animation_block_struct_definition;

	extern s_tag_block_definition animation_graph_weapon_animations_block;
	extern s_tag_struct_definition animation_graph_weapon_animations_block_struct_definition;

	extern s_tag_block_definition weapon_animation_block;
	extern s_tag_struct_definition weapon_animation_block_struct_definition;

	extern s_tag_block_definition animation_graph_unit_seat_block;
	extern s_tag_struct_definition animation_graph_unit_seat_block_struct_definition;

	extern s_tag_block_definition animation_graph_weapon_block;
	extern s_tag_struct_definition animation_graph_weapon_block_struct_definition;

	extern s_tag_block_definition animation_graph_weapon_type_block;
	extern s_tag_struct_definition animation_graph_weapon_type_block_struct_definition;

	extern s_tag_block_definition weapon_type_animation_block;
	extern s_tag_struct_definition weapon_type_animation_block_struct_definition;

	extern s_tag_block_definition animation_graph_unit_seat_ik_point;
	extern s_tag_struct_definition animation_graph_unit_seat_ik_point_struct_definition;

	extern s_tag_block_definition weapon_class_animation_block;
	extern s_tag_struct_definition weapon_class_animation_block_struct_definition;

	extern s_tag_block_definition unit_seat_animation_block;
	extern s_tag_struct_definition unit_seat_animation_block_struct_definition;

	extern s_tag_block_definition animation_graph_object_overlay;
	extern s_tag_struct_definition animation_graph_object_overlay_struct_definition;
	extern c_versioned_string_list unnamed_enum$8_strings;
	extern s_string_list_definition unnamed_enum$8;
	extern c_versioned_string_list unnamed_enum$9_strings;
	extern s_string_list_definition unnamed_enum$9;


	static constexpr unsigned long BITMAP_TAG = 'bitm';
	extern s_tag_group bitmap_group;
	extern s_tag_block_definition bitmap;
	extern s_tag_struct_definition bitmap_struct_definition;
	extern c_versioned_string_list unnamed_enum$12_strings;
	extern s_string_list_definition unnamed_enum$12;
	extern c_versioned_string_list unnamed_enum$13_strings;
	extern s_string_list_definition unnamed_enum$13;
	extern c_versioned_string_list unnamed_enum$14_strings;
	extern s_string_list_definition unnamed_enum$14;
	extern c_versioned_string_list unnamed_enum$15_strings;
	extern s_string_list_definition unnamed_enum$15;
	extern c_versioned_string_list unnamed_enum$16_strings;
	extern s_string_list_definition unnamed_enum$16;
	extern c_versioned_string_list unnamed_enum$17_strings;
	extern s_string_list_definition unnamed_enum$17;

	extern s_tag_block_definition bitmap_data_block;
	extern s_tag_struct_definition bitmap_data_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$18_strings;
	extern s_string_list_definition unnamed_enum$18;
	extern c_versioned_string_list unnamed_enum$19_strings;
	extern s_string_list_definition unnamed_enum$19;
	extern c_versioned_string_list unnamed_enum$20_strings;
	extern s_string_list_definition unnamed_enum$20;

	extern s_tag_block_definition bitmap_group_sequence_block;
	extern s_tag_struct_definition bitmap_group_sequence_block_struct_definition;

	extern s_tag_block_definition bitmap_group_sprite_block;
	extern s_tag_struct_definition bitmap_group_sprite_block_struct_definition;


	static constexpr unsigned long COLOR_TABLE_TAG = 'colo';
	extern s_tag_group color_table_group;
	extern s_tag_block_definition color_table;
	extern s_tag_struct_definition color_table_struct_definition;

	extern s_tag_block_definition color_block;
	extern s_tag_struct_definition color_block_struct_definition;


	static constexpr unsigned long STRING_LIST_TAG = 'str#';
	extern s_tag_group string_list_group;
	extern s_tag_block_definition string_list;
	extern s_tag_struct_definition string_list_struct_definition;

	extern s_tag_block_definition string_reference;
	extern s_tag_struct_definition string_reference_struct_definition;


	static constexpr unsigned long UNICODE_STRING_LIST_TAG = 'ustr';
	extern s_tag_group unicode_string_list_group;
	extern s_tag_block_definition unicode_string_list;
	extern s_tag_struct_definition unicode_string_list_struct_definition;

	extern s_tag_block_definition string_reference$2;
	extern s_tag_struct_definition string_reference$2_struct_definition;


	static constexpr unsigned long FONT_TAG = 'font';
	extern s_tag_group font_group;
	extern s_tag_block_definition font;
	extern s_tag_struct_definition font_struct_definition;
	extern s_tag_reference_definition font_reference;

	extern s_tag_block_definition character;
	extern s_tag_struct_definition character_struct_definition;

	extern s_tag_block_definition font_character_tables;
	extern s_tag_struct_definition font_character_tables_struct_definition;

	extern s_tag_block_definition font_character_table;
	extern s_tag_struct_definition font_character_table_struct_definition;


	static constexpr unsigned long PHYSICS_TAG = 'phys';
	extern s_tag_group physics_group;
	extern s_tag_block_definition physics;
	extern s_tag_struct_definition physics_struct_definition;

	extern s_tag_block_definition mass_point_block;
	extern s_tag_struct_definition mass_point_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$34_strings;
	extern s_string_list_definition unnamed_enum$34;
	extern c_versioned_string_list unnamed_enum$35_strings;
	extern s_string_list_definition unnamed_enum$35;

	extern s_tag_block_definition powered_mass_point_block;
	extern s_tag_struct_definition powered_mass_point_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$33_strings;
	extern s_string_list_definition unnamed_enum$33;

	extern s_tag_block_definition inertial_matrix_block;
	extern s_tag_struct_definition inertial_matrix_block_struct_definition;


	static constexpr unsigned long OBJECT_TAG = 'obje';
	extern s_tag_group object_group;
	extern s_tag_block_definition object;
	extern s_tag_struct_definition object_struct_definition;
	extern c_versioned_string_list unnamed_enum$36_strings;
	extern s_string_list_definition unnamed_enum$36;
	extern s_tag_reference_definition gbxmodel_reference;
	extern s_tag_reference_definition model_animations_reference;
	extern s_tag_reference_definition model_collision_geometry_reference;
	extern s_tag_reference_definition physics_reference;
	extern s_tag_reference_definition effect_reference;
	extern c_versioned_string_list unnamed_enum$37_strings;
	extern s_string_list_definition unnamed_enum$37;

	extern s_tag_block_definition predicted_resource_block;
	extern s_tag_struct_definition predicted_resource_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$46_strings;
	extern s_string_list_definition unnamed_enum$46;

	extern s_tag_block_definition object_change_colors;
	extern s_tag_struct_definition object_change_colors_struct_definition;
	extern c_versioned_string_list unnamed_enum$41_strings;
	extern s_string_list_definition unnamed_enum$41;
	extern c_versioned_string_list unnamed_enum$45_strings;
	extern s_string_list_definition unnamed_enum$45;

	extern s_tag_block_definition object_change_color_permutations;
	extern s_tag_struct_definition object_change_color_permutations_struct_definition;

	extern s_tag_block_definition object_function_block;
	extern s_tag_struct_definition object_function_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$40_strings;
	extern s_string_list_definition unnamed_enum$40;
	extern c_versioned_string_list unnamed_enum$42_strings;
	extern s_string_list_definition unnamed_enum$42;
	extern c_versioned_string_list unnamed_enum$43_strings;
	extern s_string_list_definition unnamed_enum$43;
	extern c_versioned_string_list unnamed_enum$44_strings;
	extern s_string_list_definition unnamed_enum$44;

	extern s_tag_block_definition object_widget_block;
	extern s_tag_struct_definition object_widget_block_struct_definition;
	extern s_tag_reference_definition flag_antenna_glow_light_volume_lightning_reference;

	extern s_tag_block_definition object_attachment_block;
	extern s_tag_struct_definition object_attachment_block_struct_definition;
	extern s_tag_reference_definition light_light_volume_contrail_particle_system_effect_sound_looping_reference;
	extern c_versioned_string_list unnamed_enum$38_strings;
	extern s_string_list_definition unnamed_enum$38;
	extern c_versioned_string_list unnamed_enum$39_strings;
	extern s_string_list_definition unnamed_enum$39;


	static constexpr unsigned long CONTRAIL_TAG = 'cont';
	extern s_tag_group contrail_group;
	extern s_tag_block_definition contrail;
	extern s_tag_struct_definition contrail_struct_definition;
	extern c_versioned_string_list unnamed_enum$47_strings;
	extern s_string_list_definition unnamed_enum$47;
	extern c_versioned_string_list unnamed_enum$48_strings;
	extern s_string_list_definition unnamed_enum$48;
	extern c_versioned_string_list unnamed_enum$49_strings;
	extern s_string_list_definition unnamed_enum$49;
	extern s_tag_reference_definition bitmap_reference;
	extern c_versioned_string_list unnamed_enum$50_strings;
	extern s_string_list_definition unnamed_enum$50;
	extern c_versioned_string_list unnamed_enum$51_strings;
	extern s_string_list_definition unnamed_enum$51;
	extern c_versioned_string_list unnamed_enum$52_strings;
	extern s_string_list_definition unnamed_enum$52;
	extern c_versioned_string_list unnamed_enum$53_strings;
	extern s_string_list_definition unnamed_enum$53;
	extern c_versioned_string_list unnamed_enum$54_strings;
	extern s_string_list_definition unnamed_enum$54;

	extern s_tag_block_definition contrail_point_states_block;
	extern s_tag_struct_definition contrail_point_states_block_struct_definition;
	extern s_tag_reference_definition point_physics_reference;
	extern c_versioned_string_list unnamed_enum$55_strings;
	extern s_string_list_definition unnamed_enum$55;


	static constexpr unsigned long LIGHT_TAG = 'ligh';
	extern s_tag_group light_group;
	extern s_tag_block_definition light;
	extern s_tag_struct_definition light_struct_definition;
	extern c_versioned_string_list unnamed_enum$65_strings;
	extern s_string_list_definition unnamed_enum$65;
	extern s_tag_reference_definition lens_flare_reference;


	static constexpr unsigned long EFFECT_TAG = 'effe';
	extern s_tag_group effect_group;
	extern s_tag_block_definition effect;
	extern s_tag_struct_definition effect_struct_definition;
	extern c_versioned_string_list unnamed_enum$66_strings;
	extern s_string_list_definition unnamed_enum$66;

	extern s_tag_block_definition effect_event_block;
	extern s_tag_struct_definition effect_event_block_struct_definition;

	extern s_tag_block_definition effect_particles_block;
	extern s_tag_struct_definition effect_particles_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$67_strings;
	extern s_string_list_definition unnamed_enum$67;
	extern c_versioned_string_list unnamed_enum$68_strings;
	extern s_string_list_definition unnamed_enum$68;
	extern c_versioned_string_list unnamed_enum$71_strings;
	extern s_string_list_definition unnamed_enum$71;
	extern s_tag_reference_definition particle_reference;
	extern c_versioned_string_list unnamed_enum$72_strings;
	extern s_string_list_definition unnamed_enum$72;
	extern c_versioned_string_list unnamed_enum$73_strings;
	extern s_string_list_definition unnamed_enum$73;
	extern c_versioned_string_list unnamed_enum$74_strings;
	extern s_string_list_definition unnamed_enum$74;

	extern s_tag_block_definition effect_part_block;
	extern s_tag_struct_definition effect_part_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$69_strings;
	extern s_string_list_definition unnamed_enum$69;
	extern s_tag_reference_definition damage_effect_object_particle_system_sound_decal_light_reference;
	extern c_versioned_string_list unnamed_enum$70_strings;
	extern s_string_list_definition unnamed_enum$70;

	extern s_tag_block_definition effect_locations_block;
	extern s_tag_struct_definition effect_locations_block_struct_definition;


	static constexpr unsigned long PARTICLE_TAG = 'part';
	extern s_tag_group particle_group;
	extern s_tag_block_definition particle;
	extern s_tag_struct_definition particle_struct_definition;
	extern c_versioned_string_list unnamed_enum$75_strings;
	extern s_string_list_definition unnamed_enum$75;
	extern s_tag_reference_definition material_effects_reference;
	extern s_tag_reference_definition sound_effect_reference$2;
	extern c_versioned_string_list unnamed_enum$76_strings;
	extern s_string_list_definition unnamed_enum$76;


	static constexpr unsigned long GLOBALS_TAG = 'matg';
	extern s_tag_group globals_group;
	extern s_tag_block_definition globals;
	extern s_tag_struct_definition globals_struct_definition;

	extern s_tag_block_definition playlist_autogenerate_choice_block;
	extern s_tag_struct_definition playlist_autogenerate_choice_block_struct_definition;

	extern s_tag_block_definition materials_block;
	extern s_tag_struct_definition materials_block_struct_definition;

	extern s_tag_block_definition breakable_surface_particle_effect_block;
	extern s_tag_struct_definition breakable_surface_particle_effect_block_struct_definition;
	extern s_tag_reference_definition particle_reference$2;
	extern c_versioned_string_list unnamed_enum$78_strings;
	extern s_string_list_definition unnamed_enum$78;

	extern s_tag_block_definition falling_damage_block;
	extern s_tag_struct_definition falling_damage_block_struct_definition;
	extern s_tag_reference_definition damage_effect_reference;

	extern s_tag_block_definition first_person_interface_block;
	extern s_tag_struct_definition first_person_interface_block_struct_definition;
	extern s_tag_reference_definition gbxmodel_reference$3;
	extern s_tag_reference_definition meter_reference;

	extern s_tag_block_definition player_information_block;
	extern s_tag_struct_definition player_information_block_struct_definition;
	extern s_tag_reference_definition unit_reference;

	extern s_tag_block_definition multiplayer_information_block;
	extern s_tag_struct_definition multiplayer_information_block_struct_definition;
	extern s_tag_reference_definition item_reference;

	extern s_tag_block_definition sounds_block;
	extern s_tag_struct_definition sounds_block_struct_definition;
	extern s_tag_reference_definition sound_reference$2;

	extern s_tag_block_definition vehicles_block;
	extern s_tag_struct_definition vehicles_block_struct_definition;
	extern s_tag_reference_definition vehicle_reference;

	extern s_tag_block_definition cheat_powerups_block;
	extern s_tag_struct_definition cheat_powerups_block_struct_definition;
	extern s_tag_reference_definition equipment_reference;

	extern s_tag_block_definition cheat_weapons_block;
	extern s_tag_struct_definition cheat_weapons_block_struct_definition;

	extern s_tag_block_definition interface_tag_references;
	extern s_tag_struct_definition interface_tag_references_struct_definition;
	extern s_tag_reference_definition color_table_reference;
	extern s_tag_reference_definition hud_globals_reference;
	extern s_tag_reference_definition string_list_reference;
	extern s_tag_reference_definition hud_number_reference;

	extern s_tag_block_definition rasterizer_data_block;
	extern s_tag_struct_definition rasterizer_data_block_struct_definition;
	extern s_tag_reference_definition bitmap_reference$2;
	extern c_versioned_string_list unnamed_enum$77_strings;
	extern s_string_list_definition unnamed_enum$77;

	extern s_tag_block_definition grenades_block;
	extern s_tag_struct_definition grenades_block_struct_definition;
	extern s_tag_reference_definition grenade_hud_interface_reference;
	extern s_tag_reference_definition projectile_reference;

	extern s_tag_block_definition difficulty_block;
	extern s_tag_struct_definition difficulty_block_struct_definition;

	extern s_tag_block_definition player_control_block;
	extern s_tag_struct_definition player_control_block_struct_definition;

	extern s_tag_block_definition look_function_block;
	extern s_tag_struct_definition look_function_block_struct_definition;

	extern s_tag_block_definition camera_block;
	extern s_tag_struct_definition camera_block_struct_definition;
	extern s_tag_reference_definition camera_track_reference;

	extern s_tag_block_definition sound_block;
	extern s_tag_struct_definition sound_block_struct_definition;


	static constexpr unsigned long SOUND_TAG = 'snd!';
	extern s_tag_group sound_group;
	extern s_tag_block_definition sound;
	extern s_tag_struct_definition sound_struct_definition;
	extern c_versioned_string_list unnamed_enum$79_strings;
	extern s_string_list_definition unnamed_enum$79;
	extern c_versioned_string_list unnamed_enum$80_strings;
	extern s_string_list_definition unnamed_enum$80;
	extern c_versioned_string_list unnamed_enum$81_strings;
	extern s_string_list_definition unnamed_enum$81;
	extern c_versioned_string_list unnamed_enum$82_strings;
	extern s_string_list_definition unnamed_enum$82;
	extern c_versioned_string_list unnamed_enum$83_strings;
	extern s_string_list_definition unnamed_enum$83;

	extern s_tag_block_definition sound_pitch_range_block;
	extern s_tag_struct_definition sound_pitch_range_block_struct_definition;

	extern s_tag_block_definition sound_permutations_block;
	extern s_tag_struct_definition sound_permutations_block_struct_definition;


	static constexpr unsigned long SOUND_LOOPING_TAG = 'lsnd';
	extern s_tag_group sound_looping_group;
	extern s_tag_block_definition sound_looping;
	extern s_tag_struct_definition sound_looping_struct_definition;
	extern c_versioned_string_list unnamed_enum$84_strings;
	extern s_string_list_definition unnamed_enum$84;
	extern s_tag_reference_definition continuous_damage_effect_reference;

	extern s_tag_block_definition looping_sound_detail_block;
	extern s_tag_struct_definition looping_sound_detail_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$86_strings;
	extern s_string_list_definition unnamed_enum$86;

	extern s_tag_block_definition looping_sound_track_block;
	extern s_tag_struct_definition looping_sound_track_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$85_strings;
	extern s_string_list_definition unnamed_enum$85;


	static constexpr unsigned long ITEM_TAG = 'item';
	extern s_tag_group item_group;
	extern s_tag_block_definition item;
	extern s_tag_struct_definition item_struct_definition;
	extern c_versioned_string_list unnamed_enum$87_strings;
	extern s_string_list_definition unnamed_enum$87;
	extern c_versioned_string_list unnamed_enum$88_strings;
	extern s_string_list_definition unnamed_enum$88;


	static constexpr unsigned long EQUIPMENT_TAG = 'eqip';
	extern s_tag_group equipment_group;
	extern s_tag_block_definition equipment;
	extern s_tag_struct_definition equipment_struct_definition;
	extern c_versioned_string_list unnamed_enum$89_strings;
	extern s_string_list_definition unnamed_enum$89;
	extern c_versioned_string_list unnamed_enum$26_strings;
	extern s_string_list_definition unnamed_enum$26;


	static constexpr unsigned long FLAG_TAG = 'flag';
	extern s_tag_group flag_group;
	extern s_tag_block_definition flag;
	extern s_tag_struct_definition flag_struct_definition;
	extern c_versioned_string_list unnamed_enum$90_strings;
	extern s_string_list_definition unnamed_enum$90;
	extern c_versioned_string_list unnamed_enum$91_strings;
	extern s_string_list_definition unnamed_enum$91;
	extern c_versioned_string_list unnamed_enum$92_strings;
	extern s_string_list_definition unnamed_enum$92;

	extern s_tag_block_definition flag_attachment_point_block;
	extern s_tag_struct_definition flag_attachment_point_block_struct_definition;


	static constexpr unsigned long ANTENNA_TAG = 'ant!';
	extern s_tag_group antenna_group;
	extern s_tag_block_definition antenna;
	extern s_tag_struct_definition antenna_struct_definition;
	extern s_tag_reference_definition bitmap_reference$3;

	extern s_tag_block_definition antenna_vertex_block;
	extern s_tag_struct_definition antenna_vertex_block_struct_definition;


	static constexpr unsigned long SPHEROID_TAG = 'boom';
	extern s_tag_group spheroid_group;
	extern s_tag_block_definition spheroid;
	extern s_tag_struct_definition spheroid_struct_definition;


	static constexpr unsigned long WEATHER_PARTICLE_SYSTEM_TAG = 'rain';
	extern s_tag_group weather_particle_system_group;
	extern s_tag_block_definition weather_particle_system;
	extern s_tag_struct_definition weather_particle_system_struct_definition;
	extern c_versioned_string_list unnamed_enum$93_strings;
	extern s_string_list_definition unnamed_enum$93;

	extern s_tag_block_definition weather_particle_type_block;
	extern s_tag_struct_definition weather_particle_type_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$94_strings;
	extern s_string_list_definition unnamed_enum$94;
	extern c_versioned_string_list unnamed_enum$95_strings;
	extern s_string_list_definition unnamed_enum$95;


	static constexpr unsigned long GLOW_TAG = 'glw!';
	extern s_tag_group glow_group;
	extern s_tag_block_definition glow;
	extern s_tag_struct_definition glow_struct_definition;
	extern c_versioned_string_list unnamed_enum$96_strings;
	extern s_string_list_definition unnamed_enum$96;
	extern c_versioned_string_list unnamed_enum$97_strings;
	extern s_string_list_definition unnamed_enum$97;
	extern c_versioned_string_list unnamed_enum$98_strings;
	extern s_string_list_definition unnamed_enum$98;
	extern c_versioned_string_list unnamed_enum$99_strings;
	extern s_string_list_definition unnamed_enum$99;
	extern c_versioned_string_list unnamed_enum$100_strings;
	extern s_string_list_definition unnamed_enum$100;


	static constexpr unsigned long LIGHT_VOLUME_TAG = 'mgs2';
	extern s_tag_group light_volume_group;
	extern s_tag_block_definition light_volume;
	extern s_tag_struct_definition light_volume_struct_definition;
	extern c_versioned_string_list unnamed_enum$101_strings;
	extern s_string_list_definition unnamed_enum$101;

	extern s_tag_block_definition light_volume_frame_block;
	extern s_tag_struct_definition light_volume_frame_block_struct_definition;


	static constexpr unsigned long LIGHTNING_TAG = 'elec';
	extern s_tag_group lightning_group;
	extern s_tag_block_definition lightning;
	extern s_tag_struct_definition lightning_struct_definition;

	extern s_tag_block_definition lightning_shader_block;
	extern s_tag_struct_definition lightning_shader_block_struct_definition;

	extern s_tag_block_definition lightning_marker_block;
	extern s_tag_struct_definition lightning_marker_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$102_strings;
	extern s_string_list_definition unnamed_enum$102;


	static constexpr unsigned long CAMERA_TRACK_TAG = 'trak';
	extern s_tag_group camera_track_group;
	extern s_tag_block_definition camera_track;
	extern s_tag_struct_definition camera_track_struct_definition;
	extern c_versioned_string_list unnamed_enum$103_strings;
	extern s_string_list_definition unnamed_enum$103;

	extern s_tag_block_definition camera_track_control_point_block;
	extern s_tag_struct_definition camera_track_control_point_block_struct_definition;


	static constexpr unsigned long PARTICLE_SYSTEM_TAG = 'pctl';
	extern s_tag_group particle_system_group;
	extern s_tag_block_definition particle_system;
	extern s_tag_struct_definition particle_system_struct_definition;
	extern c_versioned_string_list unnamed_enum$104_strings;
	extern s_string_list_definition unnamed_enum$104;
	extern c_versioned_string_list unnamed_enum$105_strings;
	extern s_string_list_definition unnamed_enum$105;

	extern s_tag_block_definition particle_system_types_block;
	extern s_tag_struct_definition particle_system_types_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$106_strings;
	extern s_string_list_definition unnamed_enum$106;
	extern c_versioned_string_list unnamed_enum$107_strings;
	extern s_string_list_definition unnamed_enum$107;
	extern c_versioned_string_list unnamed_enum$108_strings;
	extern s_string_list_definition unnamed_enum$108;

	extern s_tag_block_definition particle_system_type_particle_states_block;
	extern s_tag_struct_definition particle_system_type_particle_states_block_struct_definition;

	extern s_tag_block_definition particle_system_physics_constants_block;
	extern s_tag_struct_definition particle_system_physics_constants_block_struct_definition;

	extern s_tag_block_definition particle_system_type_states_block;
	extern s_tag_struct_definition particle_system_type_states_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$109_strings;
	extern s_string_list_definition unnamed_enum$109;


	static constexpr unsigned long PREFERENCES_NETWORK_GAME_TAG = 'ngpr';
	extern s_tag_group preferences_network_game_group;
	extern s_tag_block_definition preferences_network_game;
	extern s_tag_struct_definition preferences_network_game_struct_definition;


	static constexpr unsigned long PROJECTILE_TAG = 'proj';
	extern s_tag_group projectile_group;
	extern s_tag_block_definition projectile;
	extern s_tag_struct_definition projectile_struct_definition;
	extern c_versioned_string_list unnamed_enum$110_strings;
	extern s_string_list_definition unnamed_enum$110;
	extern c_versioned_string_list unnamed_enum$111_strings;
	extern s_string_list_definition unnamed_enum$111;
	extern c_versioned_string_list unnamed_enum$23_strings;
	extern s_string_list_definition unnamed_enum$23;
	extern c_versioned_string_list unnamed_enum$112_strings;
	extern s_string_list_definition unnamed_enum$112;

	extern s_tag_block_definition projectile_material_response_block;
	extern s_tag_struct_definition projectile_material_response_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$113_strings;
	extern s_string_list_definition unnamed_enum$113;
	extern c_versioned_string_list unnamed_enum$114_strings;
	extern s_string_list_definition unnamed_enum$114;
	extern c_versioned_string_list unnamed_enum$115_strings;
	extern s_string_list_definition unnamed_enum$115;
	extern c_versioned_string_list unnamed_enum$116_strings;
	extern s_string_list_definition unnamed_enum$116;


	static constexpr unsigned long MODEL_COLLISION_GEOMETRY_TAG = 'coll';
	extern s_tag_group model_collision_geometry_group;
	extern s_tag_block_definition model_collision_geometry;
	extern s_tag_struct_definition model_collision_geometry_struct_definition;
	extern c_versioned_string_list unnamed_enum$117_strings;
	extern s_string_list_definition unnamed_enum$117;
	extern c_versioned_string_list unnamed_enum$119_strings;
	extern s_string_list_definition unnamed_enum$119;

	extern s_tag_block_definition node;
	extern s_tag_struct_definition node_struct_definition;

	extern s_tag_block_definition bsp;
	extern s_tag_struct_definition bsp_struct_definition;

	extern s_tag_block_definition vertex;
	extern s_tag_struct_definition vertex_struct_definition;

	extern s_tag_block_definition edge;
	extern s_tag_struct_definition edge_struct_definition;

	extern s_tag_block_definition surface;
	extern s_tag_struct_definition surface_struct_definition;
	extern c_versioned_string_list unnamed_enum$122_strings;
	extern s_string_list_definition unnamed_enum$122;

	extern s_tag_block_definition bsp2d_node;
	extern s_tag_struct_definition bsp2d_node_struct_definition;

	extern s_tag_block_definition bsp2d_reference;
	extern s_tag_struct_definition bsp2d_reference_struct_definition;

	extern s_tag_block_definition leaf;
	extern s_tag_struct_definition leaf_struct_definition;
	extern c_versioned_string_list unnamed_enum$121_strings;
	extern s_string_list_definition unnamed_enum$121;

	extern s_tag_block_definition plane;
	extern s_tag_struct_definition plane_struct_definition;

	extern s_tag_block_definition bsp3d_node;
	extern s_tag_struct_definition bsp3d_node_struct_definition;

	extern s_tag_block_definition sphere;
	extern s_tag_struct_definition sphere_struct_definition;

	extern s_tag_block_definition damage_modifiers_block;
	extern s_tag_struct_definition damage_modifiers_block_struct_definition;

	extern s_tag_block_definition damage_regions_block;
	extern s_tag_struct_definition damage_regions_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$120_strings;
	extern s_string_list_definition unnamed_enum$120;

	extern s_tag_block_definition damage_permutations_block;
	extern s_tag_struct_definition damage_permutations_block_struct_definition;

	extern s_tag_block_definition damage_materials_block;
	extern s_tag_struct_definition damage_materials_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$118_strings;
	extern s_string_list_definition unnamed_enum$118;


	static constexpr unsigned long DEVICE_TAG = 'devi';
	extern s_tag_group device_group;
	extern s_tag_block_definition device;
	extern s_tag_struct_definition device_struct_definition;
	extern c_versioned_string_list unnamed_enum$123_strings;
	extern s_string_list_definition unnamed_enum$123;
	extern c_versioned_string_list unnamed_enum$124_strings;
	extern s_string_list_definition unnamed_enum$124;
	extern s_tag_reference_definition sound_effect_reference$3;


	static constexpr unsigned long DEVICE_MACHINE_TAG = 'mach';
	extern s_tag_group device_machine_group;
	extern s_tag_block_definition device_machine;
	extern s_tag_struct_definition device_machine_struct_definition;
	extern c_versioned_string_list unnamed_enum$125_strings;
	extern s_string_list_definition unnamed_enum$125;
	extern c_versioned_string_list unnamed_enum$126_strings;
	extern s_string_list_definition unnamed_enum$126;
	extern c_versioned_string_list unnamed_enum$127_strings;
	extern s_string_list_definition unnamed_enum$127;


	static constexpr unsigned long DEVICE_CONTROL_TAG = 'ctrl';
	extern s_tag_group device_control_group;
	extern s_tag_block_definition device_control;
	extern s_tag_struct_definition device_control_struct_definition;
	extern c_versioned_string_list unnamed_enum$128_strings;
	extern s_string_list_definition unnamed_enum$128;
	extern c_versioned_string_list unnamed_enum$129_strings;
	extern s_string_list_definition unnamed_enum$129;


	static constexpr unsigned long DEVICE_LIGHT_FIXTURE_TAG = 'lifi';
	extern s_tag_group device_light_fixture_group;
	extern s_tag_block_definition device_light_fixture;
	extern s_tag_struct_definition device_light_fixture_struct_definition;


	static constexpr unsigned long POINT_PHYSICS_TAG = 'pphy';
	extern s_tag_group point_physics_group;
	extern s_tag_block_definition point_physics;
	extern s_tag_struct_definition point_physics_struct_definition;
	extern c_versioned_string_list unnamed_enum$130_strings;
	extern s_string_list_definition unnamed_enum$130;


	static constexpr unsigned long SCENARIO_STRUCTURE_BSP_TAG = 'sbsp';
	extern s_tag_group scenario_structure_bsp_group;
	extern s_tag_block_definition scenario_structure_bsp;
	extern s_tag_struct_definition scenario_structure_bsp_struct_definition;

	extern s_tag_block_definition global_leaf_portal_block;
	extern s_tag_struct_definition global_leaf_portal_block_struct_definition;

	extern s_tag_block_definition leaf_portal_vertex_block;
	extern s_tag_struct_definition leaf_portal_vertex_block_struct_definition;

	extern s_tag_block_definition global_map_leaf_block;
	extern s_tag_struct_definition global_map_leaf_block_struct_definition;

	extern s_tag_block_definition map_leaf_portal_index_block;
	extern s_tag_struct_definition map_leaf_portal_index_block_struct_definition;

	extern s_tag_block_definition map_leaf_face_block;
	extern s_tag_struct_definition map_leaf_face_block_struct_definition;

	extern s_tag_block_definition map_leaf_face_vertex_block;
	extern s_tag_struct_definition map_leaf_face_vertex_block_struct_definition;

	extern s_tag_block_definition structure_bsp_runtime_decal_block;
	extern s_tag_struct_definition structure_bsp_runtime_decal_block_struct_definition;

	extern s_tag_block_definition structure_bsp_detail_object_data_block;
	extern s_tag_struct_definition structure_bsp_detail_object_data_block_struct_definition;

	extern s_tag_block_definition global_z_reference_vector_block;
	extern s_tag_struct_definition global_z_reference_vector_block_struct_definition;

	extern s_tag_block_definition global_detail_object_counts_block;
	extern s_tag_struct_definition global_detail_object_counts_block_struct_definition;

	extern s_tag_block_definition global_detail_object_block;
	extern s_tag_struct_definition global_detail_object_block_struct_definition;

	extern s_tag_block_definition global_detail_object_cells_block;
	extern s_tag_struct_definition global_detail_object_cells_block_struct_definition;

	extern s_tag_block_definition structure_bsp_marker_block;
	extern s_tag_struct_definition structure_bsp_marker_block_struct_definition;

	extern s_tag_block_definition structure_bsp_sound_environment_palette_block;
	extern s_tag_struct_definition structure_bsp_sound_environment_palette_block_struct_definition;
	extern s_tag_reference_definition sound_environment_reference;

	extern s_tag_block_definition structure_bsp_background_sound_palette_block;
	extern s_tag_struct_definition structure_bsp_background_sound_palette_block_struct_definition;
	extern s_tag_reference_definition sound_looping_reference;

	extern s_tag_block_definition structure_bsp_pathfinding_edges_block;
	extern s_tag_struct_definition structure_bsp_pathfinding_edges_block_struct_definition;

	extern s_tag_block_definition structure_bsp_pathfinding_surfaces_block;
	extern s_tag_struct_definition structure_bsp_pathfinding_surfaces_block_struct_definition;

	extern s_tag_block_definition structure_bsp_weather_polyhedron_block;
	extern s_tag_struct_definition structure_bsp_weather_polyhedron_block_struct_definition;

	extern s_tag_block_definition structure_bsp_weather_polyhedron_plane_block;
	extern s_tag_struct_definition structure_bsp_weather_polyhedron_plane_block_struct_definition;

	extern s_tag_block_definition structure_bsp_weather_palette_block;
	extern s_tag_struct_definition structure_bsp_weather_palette_block_struct_definition;
	extern s_tag_reference_definition weather_particle_system_reference;
	extern s_tag_reference_definition wind_reference;

	extern s_tag_block_definition structure_bsp_fog_palette_block;
	extern s_tag_struct_definition structure_bsp_fog_palette_block_struct_definition;
	extern s_tag_reference_definition fog_reference;

	extern s_tag_block_definition structure_bsp_fog_region_block;
	extern s_tag_struct_definition structure_bsp_fog_region_block_struct_definition;

	extern s_tag_block_definition structure_bsp_fog_plane_block;
	extern s_tag_struct_definition structure_bsp_fog_plane_block_struct_definition;

	extern s_tag_block_definition structure_bsp_fog_plane_vertex_block;
	extern s_tag_struct_definition structure_bsp_fog_plane_vertex_block_struct_definition;

	extern s_tag_block_definition structure_bsp_breakable_surface_block;
	extern s_tag_struct_definition structure_bsp_breakable_surface_block_struct_definition;

	extern s_tag_block_definition structure_bsp_cluster_portal_block;
	extern s_tag_struct_definition structure_bsp_cluster_portal_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$132_strings;
	extern s_string_list_definition unnamed_enum$132;

	extern s_tag_block_definition structure_bsp_cluster_portal_vertex_block;
	extern s_tag_struct_definition structure_bsp_cluster_portal_vertex_block_struct_definition;

	extern s_tag_block_definition structure_bsp_cluster_block;
	extern s_tag_struct_definition structure_bsp_cluster_block_struct_definition;

	extern s_tag_block_definition structure_bsp_cluster_portal_index_block;
	extern s_tag_struct_definition structure_bsp_cluster_portal_index_block_struct_definition;

	extern s_tag_block_definition structure_bsp_mirror_block;
	extern s_tag_struct_definition structure_bsp_mirror_block_struct_definition;

	extern s_tag_block_definition structure_bsp_mirror_vertex_block;
	extern s_tag_struct_definition structure_bsp_mirror_vertex_block_struct_definition;

	extern s_tag_block_definition structure_bsp_cluster_surface_index_block;
	extern s_tag_struct_definition structure_bsp_cluster_surface_index_block_struct_definition;

	extern s_tag_block_definition structure_bsp_subcluster_block;
	extern s_tag_struct_definition structure_bsp_subcluster_block_struct_definition;

	extern s_tag_block_definition structure_bsp_subcluster_surface_index_block;
	extern s_tag_struct_definition structure_bsp_subcluster_surface_index_block_struct_definition;

	extern s_tag_block_definition structure_bsp_lens_flare_marker_block;
	extern s_tag_struct_definition structure_bsp_lens_flare_marker_block_struct_definition;

	extern s_tag_block_definition structure_bsp_lens_flare_block;
	extern s_tag_struct_definition structure_bsp_lens_flare_block_struct_definition;
	extern s_tag_reference_definition lens_flare_reference$2;

	extern s_tag_block_definition structure_bsp_lightmap_block;
	extern s_tag_struct_definition structure_bsp_lightmap_block_struct_definition;

	extern s_tag_block_definition structure_bsp_material_block;
	extern s_tag_struct_definition structure_bsp_material_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$131_strings;
	extern s_string_list_definition unnamed_enum$131;

	extern s_tag_array_definition structure_bsp_material_block__vertex_buffers_array;
	extern s_tag_struct_definition structure_bsp_material_block__vertex_buffers_array_struct_definition;

	extern s_tag_block_definition structure_bsp_surface_block;
	extern s_tag_struct_definition structure_bsp_surface_block_struct_definition;

	extern s_tag_array_definition structure_bsp_surface_block__vertices_array;
	extern s_tag_struct_definition structure_bsp_surface_block__vertices_array_struct_definition;

	extern s_tag_block_definition structure_bsp_surface_reference_block;
	extern s_tag_struct_definition structure_bsp_surface_reference_block_struct_definition;

	extern s_tag_block_definition structure_bsp_leaf_block;
	extern s_tag_struct_definition structure_bsp_leaf_block_struct_definition;

	extern s_tag_block_definition structure_bsp_node_block;
	extern s_tag_struct_definition structure_bsp_node_block_struct_definition;

	extern s_tag_block_definition bsp$2;
	extern s_tag_struct_definition bsp$2_struct_definition;

	extern s_tag_block_definition structure_collision_materials_block;
	extern s_tag_struct_definition structure_collision_materials_block_struct_definition;


	static constexpr unsigned long SCENARIO_TAG = 'scnr';
	extern s_tag_group scenario_group;
	extern s_tag_block_definition scenario;
	extern s_tag_struct_definition scenario_struct_definition;
	extern s_tag_reference_definition scenario_structure_bsp_reference;
	extern s_tag_reference_definition sky_reference;
	extern c_versioned_string_list unnamed_enum$133_strings;
	extern s_string_list_definition unnamed_enum$133;
	extern c_versioned_string_list unnamed_enum$134_strings;
	extern s_string_list_definition unnamed_enum$134;
	extern s_tag_reference_definition unicode_string_list_reference;
	extern s_tag_reference_definition hud_message_text_reference;

	extern s_tag_block_definition scenario_structure_bsps_block;
	extern s_tag_struct_definition scenario_structure_bsps_block_struct_definition;

	extern s_tag_block_definition scenario_cutscene_title_block;
	extern s_tag_struct_definition scenario_cutscene_title_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$172_strings;
	extern s_string_list_definition unnamed_enum$172;

	extern s_tag_block_definition scenario_cutscene_camera_point_block;
	extern s_tag_struct_definition scenario_cutscene_camera_point_block_struct_definition;

	extern s_tag_block_definition scenario_cutscene_flag_block;
	extern s_tag_struct_definition scenario_cutscene_flag_block_struct_definition;

	extern s_tag_block_definition hs_source_files_block;
	extern s_tag_struct_definition hs_source_files_block_struct_definition;

	extern s_tag_block_definition hs_references_block;
	extern s_tag_struct_definition hs_references_block_struct_definition;
	extern s_tag_reference_definition _reference;

	extern s_tag_block_definition hs_globals_block;
	extern s_tag_struct_definition hs_globals_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$171_strings;
	extern s_string_list_definition unnamed_enum$171;

	extern s_tag_block_definition hs_scripts_block;
	extern s_tag_struct_definition hs_scripts_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$170_strings;
	extern s_string_list_definition unnamed_enum$170;

	extern s_tag_block_definition ai_conversation_block;
	extern s_tag_struct_definition ai_conversation_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$164_strings;
	extern s_string_list_definition unnamed_enum$164;

	extern s_tag_block_definition ai_conversation_line_block;
	extern s_tag_struct_definition ai_conversation_line_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$168_strings;
	extern s_string_list_definition unnamed_enum$168;
	extern c_versioned_string_list unnamed_enum$169_strings;
	extern s_string_list_definition unnamed_enum$169;

	extern s_tag_block_definition ai_conversation_participant_block;
	extern s_tag_struct_definition ai_conversation_participant_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$165_strings;
	extern s_string_list_definition unnamed_enum$165;
	extern c_versioned_string_list unnamed_enum$166_strings;
	extern s_string_list_definition unnamed_enum$166;
	extern c_versioned_string_list unnamed_enum$167_strings;
	extern s_string_list_definition unnamed_enum$167;

	extern s_tag_block_definition ai_recording_reference_block;
	extern s_tag_struct_definition ai_recording_reference_block_struct_definition;

	extern s_tag_block_definition ai_script_reference_block;
	extern s_tag_struct_definition ai_script_reference_block_struct_definition;

	extern s_tag_block_definition ai_animation_reference_block;
	extern s_tag_struct_definition ai_animation_reference_block_struct_definition;
	extern s_tag_reference_definition model_animations_reference$3;

	extern s_tag_block_definition ai_command_list_block;
	extern s_tag_struct_definition ai_command_list_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$161_strings;
	extern s_string_list_definition unnamed_enum$161;

	extern s_tag_block_definition ai_command_point_block;
	extern s_tag_struct_definition ai_command_point_block_struct_definition;

	extern s_tag_block_definition ai_command_block;
	extern s_tag_struct_definition ai_command_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$162_strings;
	extern s_string_list_definition unnamed_enum$162;

	extern s_tag_block_definition encounter_block;
	extern s_tag_struct_definition encounter_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$150_strings;
	extern s_string_list_definition unnamed_enum$150;
	extern c_versioned_string_list unnamed_enum$151_strings;
	extern s_string_list_definition unnamed_enum$151;
	extern c_versioned_string_list unnamed_enum$152_strings;
	extern s_string_list_definition unnamed_enum$152;

	extern s_tag_block_definition scenario_players_block;
	extern s_tag_struct_definition scenario_players_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$146_strings;
	extern s_string_list_definition unnamed_enum$146;

	extern s_tag_block_definition firing_positions_block;
	extern s_tag_struct_definition firing_positions_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$163_strings;
	extern s_string_list_definition unnamed_enum$163;

	extern s_tag_block_definition platoons_block;
	extern s_tag_struct_definition platoons_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$153_strings;
	extern s_string_list_definition unnamed_enum$153;
	extern c_versioned_string_list unnamed_enum$154_strings;
	extern s_string_list_definition unnamed_enum$154;

	extern s_tag_block_definition squads_block;
	extern s_tag_struct_definition squads_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$155_strings;
	extern s_string_list_definition unnamed_enum$155;
	extern c_versioned_string_list unnamed_enum$156_strings;
	extern s_string_list_definition unnamed_enum$156;
	extern c_versioned_string_list unnamed_enum$157_strings;
	extern s_string_list_definition unnamed_enum$157;
	extern c_versioned_string_list unnamed_enum$158_strings;
	extern s_string_list_definition unnamed_enum$158;
	extern c_versioned_string_list unnamed_enum$159_strings;
	extern s_string_list_definition unnamed_enum$159;

	extern s_tag_block_definition actor_starting_locations_block;
	extern s_tag_struct_definition actor_starting_locations_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$160_strings;
	extern s_string_list_definition unnamed_enum$160;

	extern s_tag_block_definition move_positions_block;
	extern s_tag_struct_definition move_positions_block_struct_definition;

	extern s_tag_block_definition actor_palette_block;
	extern s_tag_struct_definition actor_palette_block_struct_definition;
	extern s_tag_reference_definition actor_variant_reference$3;

	extern s_tag_block_definition scenario_detail_object_collection_palette_block;
	extern s_tag_struct_definition scenario_detail_object_collection_palette_block_struct_definition;
	extern s_tag_reference_definition detail_object_collection_reference;

	extern s_tag_block_definition scenario_decal_palette_block;
	extern s_tag_struct_definition scenario_decal_palette_block_struct_definition;
	extern s_tag_reference_definition decal_reference;

	extern s_tag_block_definition scenario_decals_block;
	extern s_tag_struct_definition scenario_decals_block_struct_definition;

	extern s_tag_block_definition scenario_bsp_switch_trigger_volume_block;
	extern s_tag_struct_definition scenario_bsp_switch_trigger_volume_block_struct_definition;

	extern s_tag_block_definition scenario_starting_equipment_block;
	extern s_tag_struct_definition scenario_starting_equipment_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$149_strings;
	extern s_string_list_definition unnamed_enum$149;
	extern s_tag_reference_definition item_collection_reference;

	extern s_tag_block_definition scenario_netgame_equipment_block;
	extern s_tag_struct_definition scenario_netgame_equipment_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$148_strings;
	extern s_string_list_definition unnamed_enum$148;

	extern s_tag_block_definition scenario_netgame_flags_block;
	extern s_tag_struct_definition scenario_netgame_flags_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$147_strings;
	extern s_string_list_definition unnamed_enum$147;

	extern s_tag_block_definition recorded_animation_block;
	extern s_tag_struct_definition recorded_animation_block_struct_definition;

	extern s_tag_block_definition scenario_trigger_volume_block;
	extern s_tag_struct_definition scenario_trigger_volume_block_struct_definition;

	extern s_tag_array_definition scenario_trigger_volume_block___array;
	extern s_tag_struct_definition scenario_trigger_volume_block___array_struct_definition;

	extern s_tag_block_definition scenario_profiles_block;
	extern s_tag_struct_definition scenario_profiles_block_struct_definition;
	extern s_tag_reference_definition weapon_reference$3;

	extern s_tag_block_definition scenario_sound_scenery_palette_block;
	extern s_tag_struct_definition scenario_sound_scenery_palette_block_struct_definition;
	extern s_tag_reference_definition sound_scenery_reference;

	extern s_tag_block_definition scenario_sound_scenery_block;
	extern s_tag_struct_definition scenario_sound_scenery_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$137_strings;
	extern s_string_list_definition unnamed_enum$137;

	extern s_tag_block_definition scenario_light_fixture_palette_block;
	extern s_tag_struct_definition scenario_light_fixture_palette_block_struct_definition;
	extern s_tag_reference_definition device_light_fixture_reference;

	extern s_tag_block_definition scenario_light_fixture_block;
	extern s_tag_struct_definition scenario_light_fixture_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$143_strings;
	extern s_string_list_definition unnamed_enum$143;

	extern s_tag_block_definition scenario_control_palette_block;
	extern s_tag_struct_definition scenario_control_palette_block_struct_definition;
	extern s_tag_reference_definition device_control_reference;

	extern s_tag_block_definition scenario_control_block;
	extern s_tag_struct_definition scenario_control_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$145_strings;
	extern s_string_list_definition unnamed_enum$145;

	extern s_tag_block_definition scenario_machine_palette_block;
	extern s_tag_struct_definition scenario_machine_palette_block_struct_definition;
	extern s_tag_reference_definition device_machine_reference;

	extern s_tag_block_definition scenario_machine_block;
	extern s_tag_struct_definition scenario_machine_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$144_strings;
	extern s_string_list_definition unnamed_enum$144;

	extern s_tag_block_definition device_group_block$2;
	extern s_tag_struct_definition device_group_block$2_struct_definition;
	extern c_versioned_string_list unnamed_enum$142_strings;
	extern s_string_list_definition unnamed_enum$142;

	extern s_tag_block_definition scenario_weapon_palette_block;
	extern s_tag_struct_definition scenario_weapon_palette_block_struct_definition;
	extern s_tag_reference_definition weapon_reference$2;

	extern s_tag_block_definition scenario_weapon_block;
	extern s_tag_struct_definition scenario_weapon_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$141_strings;
	extern s_string_list_definition unnamed_enum$141;

	extern s_tag_block_definition scenario_equipment_palette_block;
	extern s_tag_struct_definition scenario_equipment_palette_block_struct_definition;
	extern s_tag_reference_definition equipment_reference$2;

	extern s_tag_block_definition scenario_equipment_block;
	extern s_tag_struct_definition scenario_equipment_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$140_strings;
	extern s_string_list_definition unnamed_enum$140;

	extern s_tag_block_definition scenario_vehicle_palette_block;
	extern s_tag_struct_definition scenario_vehicle_palette_block_struct_definition;
	extern s_tag_reference_definition vehicle_reference$2;

	extern s_tag_block_definition scenario_vehicle_block;
	extern s_tag_struct_definition scenario_vehicle_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$138_strings;
	extern s_string_list_definition unnamed_enum$138;
	extern c_versioned_string_list unnamed_enum$139_strings;
	extern s_string_list_definition unnamed_enum$139;

	extern s_tag_block_definition scenario_biped_palette_block;
	extern s_tag_struct_definition scenario_biped_palette_block_struct_definition;
	extern s_tag_reference_definition biped_reference;

	extern s_tag_block_definition scenario_biped_block;
	extern s_tag_struct_definition scenario_biped_block_struct_definition;

	extern s_tag_block_definition scenario_scenery_palette_block;
	extern s_tag_struct_definition scenario_scenery_palette_block_struct_definition;
	extern s_tag_reference_definition scenery_reference;

	extern s_tag_block_definition scenario_scenery_block;
	extern s_tag_struct_definition scenario_scenery_block_struct_definition;

	extern s_tag_block_definition scenario_object_names_block;
	extern s_tag_struct_definition scenario_object_names_block_struct_definition;

	extern s_tag_block_definition editor_comment_block;
	extern s_tag_struct_definition editor_comment_block_struct_definition;

	extern s_tag_block_definition scenario_function_block;
	extern s_tag_struct_definition scenario_function_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$135_strings;
	extern s_string_list_definition unnamed_enum$135;
	extern c_versioned_string_list unnamed_enum$136_strings;
	extern s_string_list_definition unnamed_enum$136;

	extern s_tag_block_definition scenario_child_scenario_block;
	extern s_tag_struct_definition scenario_child_scenario_block_struct_definition;
	extern s_tag_reference_definition scenario_reference;

	extern s_tag_block_definition scenario_sky_reference_block;
	extern s_tag_struct_definition scenario_sky_reference_block_struct_definition;


	static constexpr unsigned long SHADER_TAG = 'shdr';
	extern s_tag_group shader_group;
	extern s_tag_block_definition shader;
	extern s_tag_struct_definition shader_struct_definition;
	extern c_versioned_string_list unnamed_enum$173_strings;
	extern s_string_list_definition unnamed_enum$173;
	extern c_versioned_string_list unnamed_enum$174_strings;
	extern s_string_list_definition unnamed_enum$174;
	extern c_versioned_string_list unnamed_enum$175_strings;
	extern s_string_list_definition unnamed_enum$175;


	static constexpr unsigned long SHADER_ENVIRONMENT_TAG = 'senv';
	extern s_tag_group shader_environment_group;
	extern s_tag_block_definition shader_environment;
	extern s_tag_struct_definition shader_environment_struct_definition;
	extern c_versioned_string_list unnamed_enum$176_strings;
	extern s_string_list_definition unnamed_enum$176;
	extern c_versioned_string_list unnamed_enum$177_strings;
	extern s_string_list_definition unnamed_enum$177;
	extern c_versioned_string_list unnamed_enum$178_strings;
	extern s_string_list_definition unnamed_enum$178;
	extern c_versioned_string_list unnamed_enum$179_strings;
	extern s_string_list_definition unnamed_enum$179;
	extern c_versioned_string_list unnamed_enum$180_strings;
	extern s_string_list_definition unnamed_enum$180;
	extern c_versioned_string_list unnamed_enum$181_strings;
	extern s_string_list_definition unnamed_enum$181;
	extern c_versioned_string_list unnamed_enum$182_strings;
	extern s_string_list_definition unnamed_enum$182;
	extern c_versioned_string_list unnamed_enum$183_strings;
	extern s_string_list_definition unnamed_enum$183;


	static constexpr unsigned long SHADER_MODEL_TAG = 'soso';
	extern s_tag_group shader_model_group;
	extern s_tag_block_definition shader_model;
	extern s_tag_struct_definition shader_model_struct_definition;
	extern c_versioned_string_list unnamed_enum$184_strings;
	extern s_string_list_definition unnamed_enum$184;
	extern c_versioned_string_list unnamed_enum$185_strings;
	extern s_string_list_definition unnamed_enum$185;
	extern c_versioned_string_list unnamed_enum$186_strings;
	extern s_string_list_definition unnamed_enum$186;
	extern c_versioned_string_list unnamed_enum$187_strings;
	extern s_string_list_definition unnamed_enum$187;


	static constexpr unsigned long SHADER_TRANSPARENT_GENERIC_TAG = 'sotr';
	extern s_tag_group shader_transparent_generic_group;
	extern s_tag_block_definition shader_transparent_generic;
	extern s_tag_struct_definition shader_transparent_generic_struct_definition;
	extern c_versioned_string_list unnamed_enum$188_strings;
	extern s_string_list_definition unnamed_enum$188;
	extern c_versioned_string_list unnamed_enum$189_strings;
	extern s_string_list_definition unnamed_enum$189;

	extern s_tag_block_definition shader_transparent_generic_stage_block;
	extern s_tag_struct_definition shader_transparent_generic_stage_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$191_strings;
	extern s_string_list_definition unnamed_enum$191;
	extern c_versioned_string_list unnamed_enum$192_strings;
	extern s_string_list_definition unnamed_enum$192;
	extern c_versioned_string_list unnamed_enum$193_strings;
	extern s_string_list_definition unnamed_enum$193;
	extern c_versioned_string_list unnamed_enum$194_strings;
	extern s_string_list_definition unnamed_enum$194;
	extern c_versioned_string_list unnamed_enum$195_strings;
	extern s_string_list_definition unnamed_enum$195;
	extern c_versioned_string_list unnamed_enum$196_strings;
	extern s_string_list_definition unnamed_enum$196;
	extern c_versioned_string_list unnamed_enum$197_strings;
	extern s_string_list_definition unnamed_enum$197;
	extern c_versioned_string_list unnamed_enum$198_strings;
	extern s_string_list_definition unnamed_enum$198;

	extern s_tag_block_definition shader_transparent_generic_map_block;
	extern s_tag_struct_definition shader_transparent_generic_map_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$190_strings;
	extern s_string_list_definition unnamed_enum$190;

	extern s_tag_block_definition shader_transparent_layer_block;
	extern s_tag_struct_definition shader_transparent_layer_block_struct_definition;


	static constexpr unsigned long SHADER_TRANSPARENT_CHICAGO_TAG = 'schi';
	extern s_tag_group shader_transparent_chicago_group;
	extern s_tag_block_definition shader_transparent_chicago;
	extern s_tag_struct_definition shader_transparent_chicago_struct_definition;
	extern c_versioned_string_list unnamed_enum$199_strings;
	extern s_string_list_definition unnamed_enum$199;
	extern c_versioned_string_list unnamed_enum$202_strings;
	extern s_string_list_definition unnamed_enum$202;

	extern s_tag_block_definition shader_transparent_chicago_map_block;
	extern s_tag_struct_definition shader_transparent_chicago_map_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$200_strings;
	extern s_string_list_definition unnamed_enum$200;
	extern c_versioned_string_list unnamed_enum$201_strings;
	extern s_string_list_definition unnamed_enum$201;


	static constexpr unsigned long SHADER_TRANSPARENT_CHICAGO_EXTENDED_TAG = 'scex';
	extern s_tag_group shader_transparent_chicago_extended_group;
	extern s_tag_block_definition shader_transparent_chicago_extended;
	extern s_tag_struct_definition shader_transparent_chicago_extended_struct_definition;


	static constexpr unsigned long SHADER_TRANSPARENT_WATER_TAG = 'swat';
	extern s_tag_group shader_transparent_water_group;
	extern s_tag_block_definition shader_transparent_water;
	extern s_tag_struct_definition shader_transparent_water_struct_definition;
	extern c_versioned_string_list unnamed_enum$203_strings;
	extern s_string_list_definition unnamed_enum$203;

	extern s_tag_block_definition shader_transparent_water_ripple_block;
	extern s_tag_struct_definition shader_transparent_water_ripple_block_struct_definition;


	static constexpr unsigned long SHADER_TRANSPARENT_GLASS_TAG = 'sgla';
	extern s_tag_group shader_transparent_glass_group;
	extern s_tag_block_definition shader_transparent_glass;
	extern s_tag_struct_definition shader_transparent_glass_struct_definition;
	extern c_versioned_string_list unnamed_enum$204_strings;
	extern s_string_list_definition unnamed_enum$204;
	extern c_versioned_string_list unnamed_enum$205_strings;
	extern s_string_list_definition unnamed_enum$205;


	static constexpr unsigned long SHADER_TRANSPARENT_METER_TAG = 'smet';
	extern s_tag_group shader_transparent_meter_group;
	extern s_tag_block_definition shader_transparent_meter;
	extern s_tag_struct_definition shader_transparent_meter_struct_definition;
	extern c_versioned_string_list unnamed_enum$206_strings;
	extern s_string_list_definition unnamed_enum$206;


	static constexpr unsigned long SHADER_TRANSPARENT_PLASMA_TAG = 'spla';
	extern s_tag_group shader_transparent_plasma_group;
	extern s_tag_block_definition shader_transparent_plasma;
	extern s_tag_struct_definition shader_transparent_plasma_struct_definition;


	static constexpr unsigned long ACTOR_TAG = 'actr';
	extern s_tag_group actor_group;
	extern s_tag_block_definition actor;
	extern s_tag_struct_definition actor_struct_definition;
	extern c_versioned_string_list unnamed_enum$207_strings;
	extern s_string_list_definition unnamed_enum$207;
	extern c_versioned_string_list unnamed_enum$208_strings;
	extern s_string_list_definition unnamed_enum$208;
	extern s_tag_reference_definition weapon_reference$4;
	extern c_versioned_string_list unnamed_enum$209_strings;
	extern s_string_list_definition unnamed_enum$209;
	extern c_versioned_string_list unnamed_enum$210_strings;
	extern s_string_list_definition unnamed_enum$210;
	extern s_tag_reference_definition actor_reference;


	static constexpr unsigned long ACTOR_VARIANT_TAG = 'actv';
	extern s_tag_group actor_variant_group;
	extern s_tag_block_definition actor_variant;
	extern s_tag_struct_definition actor_variant_struct_definition;
	extern c_versioned_string_list unnamed_enum$211_strings;
	extern s_string_list_definition unnamed_enum$211;
	extern s_tag_reference_definition unit_reference$2;
	extern s_tag_reference_definition actor_variant_reference$4;
	extern c_versioned_string_list unnamed_enum$212_strings;
	extern s_string_list_definition unnamed_enum$212;
	extern c_versioned_string_list unnamed_enum$213_strings;
	extern s_string_list_definition unnamed_enum$213;
	extern c_versioned_string_list unnamed_enum$214_strings;
	extern s_string_list_definition unnamed_enum$214;
	extern c_versioned_string_list unnamed_enum$215_strings;
	extern s_string_list_definition unnamed_enum$215;
	extern c_versioned_string_list unnamed_enum$216_strings;
	extern s_string_list_definition unnamed_enum$216;

	extern s_tag_block_definition actor_variant_change_colors_block;
	extern s_tag_struct_definition actor_variant_change_colors_block_struct_definition;


	static constexpr unsigned long SKY_TAG = 'sky ';
	extern s_tag_group sky_group;
	extern s_tag_block_definition sky;
	extern s_tag_struct_definition sky_struct_definition;
	extern s_tag_reference_definition gbxmodel_reference$4;
	extern s_tag_reference_definition model_animations_reference$4;
	extern s_tag_reference_definition fog_reference$2;

	extern s_tag_block_definition sky_light_block;
	extern s_tag_struct_definition sky_light_block_struct_definition;
	extern s_tag_reference_definition lens_flare_reference$3;
	extern c_versioned_string_list unnamed_enum$217_strings;
	extern s_string_list_definition unnamed_enum$217;

	extern s_tag_block_definition sky_animation_block;
	extern s_tag_struct_definition sky_animation_block_struct_definition;

	extern s_tag_block_definition sky_shader_function_block;
	extern s_tag_struct_definition sky_shader_function_block_struct_definition;


	static constexpr unsigned long WIND_TAG = 'wind';
	extern s_tag_group wind_group;
	extern s_tag_block_definition wind;
	extern s_tag_struct_definition wind_struct_definition;


	static constexpr unsigned long SOUND_ENVIRONMENT_TAG = 'snde';
	extern s_tag_group sound_environment_group;
	extern s_tag_block_definition sound_environment;
	extern s_tag_struct_definition sound_environment_struct_definition;


	static constexpr unsigned long LENS_FLARE_TAG = 'lens';
	extern s_tag_group lens_flare_group;
	extern s_tag_block_definition lens_flare;
	extern s_tag_struct_definition lens_flare_struct_definition;
	extern c_versioned_string_list unnamed_enum$218_strings;
	extern s_string_list_definition unnamed_enum$218;
	extern c_versioned_string_list unnamed_enum$219_strings;
	extern s_string_list_definition unnamed_enum$219;
	extern c_versioned_string_list unnamed_enum$220_strings;
	extern s_string_list_definition unnamed_enum$220;

	extern s_tag_block_definition lens_flare_reflection_block;
	extern s_tag_struct_definition lens_flare_reflection_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$221_strings;
	extern s_string_list_definition unnamed_enum$221;
	extern c_versioned_string_list unnamed_enum$222_strings;
	extern s_string_list_definition unnamed_enum$222;
	extern c_versioned_string_list unnamed_enum$223_strings;
	extern s_string_list_definition unnamed_enum$223;


	static constexpr unsigned long FOG_TAG = 'fog ';
	extern s_tag_group fog_group;
	extern s_tag_block_definition fog;
	extern s_tag_struct_definition fog_struct_definition;
	extern c_versioned_string_list unnamed_enum$224_strings;
	extern s_string_list_definition unnamed_enum$224;
	extern c_versioned_string_list unnamed_enum$225_strings;
	extern s_string_list_definition unnamed_enum$225;
	extern s_tag_reference_definition sound_environment_reference$2;


	static constexpr unsigned long PLACEHOLDER_TAG = 'plac';
	extern s_tag_group placeholder_group;
	extern s_tag_block_definition placeholder;
	extern s_tag_struct_definition placeholder_struct_definition;


	static constexpr unsigned long METER_TAG = 'metr';
	extern s_tag_group meter_group;
	extern s_tag_block_definition meter;
	extern s_tag_struct_definition meter_struct_definition;
	extern c_versioned_string_list unnamed_enum$226_strings;
	extern s_string_list_definition unnamed_enum$226;
	extern s_tag_reference_definition bitmap_reference$4;
	extern c_versioned_string_list unnamed_enum$227_strings;
	extern s_string_list_definition unnamed_enum$227;
	extern c_versioned_string_list unnamed_enum$228_strings;
	extern s_string_list_definition unnamed_enum$228;


	static constexpr unsigned long DECAL_TAG = 'deca';
	extern s_tag_group decal_group;
	extern s_tag_block_definition decal;
	extern s_tag_struct_definition decal_struct_definition;
	extern c_versioned_string_list unnamed_enum$229_strings;
	extern s_string_list_definition unnamed_enum$229;
	extern c_versioned_string_list unnamed_enum$230_strings;
	extern s_string_list_definition unnamed_enum$230;
	extern c_versioned_string_list unnamed_enum$231_strings;
	extern s_string_list_definition unnamed_enum$231;
	extern s_tag_reference_definition decal_reference$2;


	static constexpr unsigned long DAMAGE_EFFECT_TAG = 'jpt!';
	extern s_tag_group damage_effect_group;
	extern s_tag_block_definition damage_effect;
	extern s_tag_struct_definition damage_effect_struct_definition;
	extern c_versioned_string_list unnamed_enum$232_strings;
	extern s_string_list_definition unnamed_enum$232;
	extern c_versioned_string_list unnamed_enum$233_strings;
	extern s_string_list_definition unnamed_enum$233;
	extern c_versioned_string_list unnamed_enum$234_strings;
	extern s_string_list_definition unnamed_enum$234;
	extern c_versioned_string_list unnamed_enum$235_strings;
	extern s_string_list_definition unnamed_enum$235;
	extern c_versioned_string_list unnamed_enum$236_strings;
	extern s_string_list_definition unnamed_enum$236;
	extern c_versioned_string_list unnamed_enum$237_strings;
	extern s_string_list_definition unnamed_enum$237;


	static constexpr unsigned long DIALOGUE_TAG = 'udlg';
	extern s_tag_group dialogue_group;
	extern s_tag_block_definition dialogue;
	extern s_tag_struct_definition dialogue_struct_definition;
	extern s_tag_reference_definition sound_reference$3;


	static constexpr unsigned long ITEM_COLLECTION_TAG = 'itmc';
	extern s_tag_group item_collection_group;
	extern s_tag_block_definition item_collection;
	extern s_tag_struct_definition item_collection_struct_definition;

	extern s_tag_block_definition item_permutation;
	extern s_tag_struct_definition item_permutation_struct_definition;


	static constexpr unsigned long WEAPON_HUD_INTERFACE_TAG = 'wphi';
	extern s_tag_group weapon_hud_interface_group;
	extern s_tag_block_definition weapon_hud_interface;
	extern s_tag_struct_definition weapon_hud_interface_struct_definition;
	extern s_tag_reference_definition weapon_hud_interface_reference;
	extern c_versioned_string_list unnamed_enum$238_strings;
	extern s_string_list_definition unnamed_enum$238;
	extern c_versioned_string_list unnamed_enum$239_strings;
	extern s_string_list_definition unnamed_enum$239;
	extern c_versioned_string_list unnamed_enum$261_strings;
	extern s_string_list_definition unnamed_enum$261;

	extern s_tag_block_definition global_hud_screen_effect_definition;
	extern s_tag_struct_definition global_hud_screen_effect_definition_struct_definition;
	extern c_versioned_string_list unnamed_enum$257_strings;
	extern s_string_list_definition unnamed_enum$257;
	extern c_versioned_string_list unnamed_enum$258_strings;
	extern s_string_list_definition unnamed_enum$258;
	extern c_versioned_string_list unnamed_enum$259_strings;
	extern s_string_list_definition unnamed_enum$259;
	extern c_versioned_string_list unnamed_enum$260_strings;
	extern s_string_list_definition unnamed_enum$260;

	extern s_tag_block_definition weapon_hud_overlays_block;
	extern s_tag_struct_definition weapon_hud_overlays_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$240_strings;
	extern s_string_list_definition unnamed_enum$240;
	extern c_versioned_string_list unnamed_enum$241_strings;
	extern s_string_list_definition unnamed_enum$241;

	extern s_tag_block_definition weapon_hud_overlay_block;
	extern s_tag_struct_definition weapon_hud_overlay_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$242_strings;
	extern s_string_list_definition unnamed_enum$242;
	extern c_versioned_string_list unnamed_enum$243_strings;
	extern s_string_list_definition unnamed_enum$243;
	extern c_versioned_string_list unnamed_enum$255_strings;
	extern s_string_list_definition unnamed_enum$255;
	extern c_versioned_string_list unnamed_enum$256_strings;
	extern s_string_list_definition unnamed_enum$256;

	extern s_tag_block_definition weapon_hud_crosshair_block;
	extern s_tag_struct_definition weapon_hud_crosshair_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$253_strings;
	extern s_string_list_definition unnamed_enum$253;

	extern s_tag_block_definition weapon_hud_crosshair_item_block;
	extern s_tag_struct_definition weapon_hud_crosshair_item_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$254_strings;
	extern s_string_list_definition unnamed_enum$254;

	extern s_tag_block_definition weapon_hud_number_block;
	extern s_tag_struct_definition weapon_hud_number_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$251_strings;
	extern s_string_list_definition unnamed_enum$251;
	extern c_versioned_string_list unnamed_enum$252_strings;
	extern s_string_list_definition unnamed_enum$252;

	extern s_tag_block_definition weapon_hud_meter_block;
	extern s_tag_struct_definition weapon_hud_meter_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$250_strings;
	extern s_string_list_definition unnamed_enum$250;

	extern s_tag_block_definition weapon_hud_static_block;
	extern s_tag_struct_definition weapon_hud_static_block_struct_definition;

	extern s_tag_block_definition global_hud_multitexture_overlay_definition;
	extern s_tag_struct_definition global_hud_multitexture_overlay_definition_struct_definition;
	extern c_versioned_string_list unnamed_enum$244_strings;
	extern s_string_list_definition unnamed_enum$244;
	extern c_versioned_string_list unnamed_enum$245_strings;
	extern s_string_list_definition unnamed_enum$245;
	extern c_versioned_string_list unnamed_enum$246_strings;
	extern s_string_list_definition unnamed_enum$246;

	extern s_tag_block_definition global_hud_multitexture_overlay_effector_definition;
	extern s_tag_struct_definition global_hud_multitexture_overlay_effector_definition_struct_definition;
	extern c_versioned_string_list unnamed_enum$247_strings;
	extern s_string_list_definition unnamed_enum$247;
	extern c_versioned_string_list unnamed_enum$248_strings;
	extern s_string_list_definition unnamed_enum$248;
	extern c_versioned_string_list unnamed_enum$249_strings;
	extern s_string_list_definition unnamed_enum$249;


	static constexpr unsigned long GRENADE_HUD_INTERFACE_TAG = 'grhi';
	extern s_tag_group grenade_hud_interface_group;
	extern s_tag_block_definition grenade_hud_interface;
	extern s_tag_struct_definition grenade_hud_interface_struct_definition;

	extern s_tag_block_definition grenade_hud_sound_block;
	extern s_tag_struct_definition grenade_hud_sound_block_struct_definition;
	extern s_tag_reference_definition sound_sound_looping_reference;
	extern c_versioned_string_list unnamed_enum$263_strings;
	extern s_string_list_definition unnamed_enum$263;

	extern s_tag_block_definition grenade_hud_overlay_block;
	extern s_tag_struct_definition grenade_hud_overlay_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$262_strings;
	extern s_string_list_definition unnamed_enum$262;


	static constexpr unsigned long UNIT_HUD_INTERFACE_TAG = 'unhi';
	extern s_tag_group unit_hud_interface_group;
	extern s_tag_block_definition unit_hud_interface;
	extern s_tag_struct_definition unit_hud_interface_struct_definition;

	extern s_tag_block_definition unit_hud_auxilary_panel_block;
	extern s_tag_struct_definition unit_hud_auxilary_panel_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$267_strings;
	extern s_string_list_definition unnamed_enum$267;
	extern c_versioned_string_list unnamed_enum$268_strings;
	extern s_string_list_definition unnamed_enum$268;

	extern s_tag_block_definition unit_hud_sound_block;
	extern s_tag_struct_definition unit_hud_sound_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$266_strings;
	extern s_string_list_definition unnamed_enum$266;

	extern s_tag_block_definition unit_hud_auxilary_overlay_block;
	extern s_tag_struct_definition unit_hud_auxilary_overlay_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$264_strings;
	extern s_string_list_definition unnamed_enum$264;
	extern c_versioned_string_list unnamed_enum$265_strings;
	extern s_string_list_definition unnamed_enum$265;


	static constexpr unsigned long HUD_NUMBER_TAG = 'hud#';
	extern s_tag_group hud_number_group;
	extern s_tag_block_definition hud_number;
	extern s_tag_struct_definition hud_number_struct_definition;


	static constexpr unsigned long HUD_GLOBALS_TAG = 'hudg';
	extern s_tag_group hud_globals_group;
	extern s_tag_block_definition hud_globals;
	extern s_tag_struct_definition hud_globals_struct_definition;
	extern s_tag_reference_definition unicode_string_list_reference$2;
	extern s_tag_reference_definition hud_message_text_reference$2;

	extern s_tag_block_definition hud_waypoint_arrow_block;
	extern s_tag_struct_definition hud_waypoint_arrow_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$269_strings;
	extern s_string_list_definition unnamed_enum$269;

	extern s_tag_block_definition hud_button_icon_block;
	extern s_tag_struct_definition hud_button_icon_block_struct_definition;


	static constexpr unsigned long VIRTUAL_KEYBOARD_TAG = 'vcky';
	extern s_tag_group virtual_keyboard_group;
	extern s_tag_block_definition virtual_keyboard;
	extern s_tag_struct_definition virtual_keyboard_struct_definition;

	extern s_tag_block_definition virtual_key_block;
	extern s_tag_struct_definition virtual_key_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$270_strings;
	extern s_string_list_definition unnamed_enum$270;


	static constexpr unsigned long MULTIPLAYER_SCENARIO_DESCRIPTION_TAG = 'mply';
	extern s_tag_group multiplayer_scenario_description_group;
	extern s_tag_block_definition multiplayer_scenario_description;
	extern s_tag_struct_definition multiplayer_scenario_description_struct_definition;

	extern s_tag_block_definition scenario_description_block;
	extern s_tag_struct_definition scenario_description_block_struct_definition;


	static constexpr unsigned long DETAIL_OBJECT_COLLECTION_TAG = 'dobc';
	extern s_tag_group detail_object_collection_group;
	extern s_tag_block_definition detail_object_collection;
	extern s_tag_struct_definition detail_object_collection_struct_definition;
	extern c_versioned_string_list unnamed_enum$271_strings;
	extern s_string_list_definition unnamed_enum$271;

	extern s_tag_block_definition detail_object_type_block;
	extern s_tag_struct_definition detail_object_type_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$272_strings;
	extern s_string_list_definition unnamed_enum$272;


	static constexpr unsigned long SOUND_SCENERY_TAG = 'ssce';
	extern s_tag_group sound_scenery_group;
	extern s_tag_block_definition sound_scenery;
	extern s_tag_struct_definition sound_scenery_struct_definition;


	static constexpr unsigned long HUD_MESSAGE_TEXT_TAG = 'hmt ';
	extern s_tag_group hud_message_text_group;
	extern s_tag_block_definition hud_message_text;
	extern s_tag_struct_definition hud_message_text_struct_definition;

	extern s_tag_block_definition hud_messages_block;
	extern s_tag_struct_definition hud_messages_block_struct_definition;

	extern s_tag_block_definition hud_message_elements_block;
	extern s_tag_struct_definition hud_message_elements_block_struct_definition;


	static constexpr unsigned long UI_WIDGET_DEFINITION_TAG = 'DeLa';
	extern s_tag_group ui_widget_definition_group;
	extern s_tag_block_definition ui_widget_definition;
	extern s_tag_struct_definition ui_widget_definition_struct_definition;
	extern c_versioned_string_list unnamed_enum$273_strings;
	extern s_string_list_definition unnamed_enum$273;
	extern c_versioned_string_list unnamed_enum$274_strings;
	extern s_string_list_definition unnamed_enum$274;
	extern c_versioned_string_list unnamed_enum$275_strings;
	extern s_string_list_definition unnamed_enum$275;
	extern c_versioned_string_list unnamed_enum$281_strings;
	extern s_string_list_definition unnamed_enum$281;
	extern c_versioned_string_list unnamed_enum$282_strings;
	extern s_string_list_definition unnamed_enum$282;
	extern c_versioned_string_list unnamed_enum$283_strings;
	extern s_string_list_definition unnamed_enum$283;
	extern s_tag_reference_definition ui_widget_definition_reference;

	extern s_tag_block_definition child_widget_reference_block;
	extern s_tag_struct_definition child_widget_reference_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$285_strings;
	extern s_string_list_definition unnamed_enum$285;

	extern s_tag_block_definition conditional_widget_reference_block;
	extern s_tag_struct_definition conditional_widget_reference_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$284_strings;
	extern s_string_list_definition unnamed_enum$284;

	extern s_tag_block_definition search_and_replace_reference_block;
	extern s_tag_struct_definition search_and_replace_reference_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$280_strings;
	extern s_string_list_definition unnamed_enum$280;

	extern s_tag_block_definition event_handler_references_block;
	extern s_tag_struct_definition event_handler_references_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$277_strings;
	extern s_string_list_definition unnamed_enum$277;
	extern c_versioned_string_list unnamed_enum$278_strings;
	extern s_string_list_definition unnamed_enum$278;
	extern c_versioned_string_list unnamed_enum$279_strings;
	extern s_string_list_definition unnamed_enum$279;

	extern s_tag_block_definition game_data_input_references_block;
	extern s_tag_struct_definition game_data_input_references_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$276_strings;
	extern s_string_list_definition unnamed_enum$276;


	static constexpr unsigned long UI_WIDGET_COLLECTION_TAG = 'Soul';
	extern s_tag_group ui_widget_collection_group;
	extern s_tag_block_definition ui_widget_collection;
	extern s_tag_struct_definition ui_widget_collection_struct_definition;

	extern s_tag_block_definition ui_widget_references_block;
	extern s_tag_struct_definition ui_widget_references_block_struct_definition;


	static constexpr unsigned long CONTINUOUS_DAMAGE_EFFECT_TAG = 'cdmg';
	extern s_tag_group continuous_damage_effect_group;
	extern s_tag_block_definition continuous_damage_effect;
	extern s_tag_struct_definition continuous_damage_effect_struct_definition;


	static constexpr unsigned long MATERIAL_EFFECTS_TAG = 'foot';
	extern s_tag_group material_effects_group;
	extern s_tag_block_definition material_effects;
	extern s_tag_struct_definition material_effects_struct_definition;

	extern s_tag_block_definition material_effect_block;
	extern s_tag_struct_definition material_effect_block_struct_definition;

	extern s_tag_block_definition material_effect_material_block;
	extern s_tag_struct_definition material_effect_material_block_struct_definition;


	static constexpr unsigned long GARBAGE_TAG = 'garb';
	extern s_tag_group garbage_group;
	extern s_tag_block_definition garbage;
	extern s_tag_struct_definition garbage_struct_definition;


	static constexpr unsigned long TAG_COLLECTION_TAG = 'tagc';
	extern s_tag_group tag_collection_group;
	extern s_tag_block_definition tag_collection;
	extern s_tag_struct_definition tag_collection_struct_definition;

	extern s_tag_block_definition tag_reference;
	extern s_tag_struct_definition tag_reference_struct_definition;
	extern s_tag_reference_definition _reference$2;


	static constexpr unsigned long INPUT_DEVICE_DEFAULTS_TAG = 'devc';
	extern s_tag_group input_device_defaults_group;
	extern s_tag_block_definition input_device_defaults;
	extern s_tag_struct_definition input_device_defaults_struct_definition;
	extern c_versioned_string_list unnamed_enum$286_strings;
	extern s_string_list_definition unnamed_enum$286;
	extern c_versioned_string_list unnamed_enum$287_strings;
	extern s_string_list_definition unnamed_enum$287;


	static constexpr unsigned long UNIT_TAG = 'unit';
	extern s_tag_group unit_group;
	extern s_tag_block_definition unit;
	extern s_tag_struct_definition unit_struct_definition;
	extern c_versioned_string_list unnamed_enum$21_strings;
	extern s_string_list_definition unnamed_enum$21;
	extern c_versioned_string_list unnamed_enum$22_strings;
	extern s_string_list_definition unnamed_enum$22;
	extern c_versioned_string_list unnamed_enum$24_strings;
	extern s_string_list_definition unnamed_enum$24;
	extern s_tag_reference_definition actor_variant_reference;
	extern c_versioned_string_list unnamed_enum$25_strings;
	extern s_string_list_definition unnamed_enum$25;

	extern s_tag_block_definition unit_seat_block;
	extern s_tag_struct_definition unit_seat_block_struct_definition;
	extern c_versioned_string_list unnamed_enum$27_strings;
	extern s_string_list_definition unnamed_enum$27;
	extern s_tag_reference_definition actor_variant_reference$2;

	extern s_tag_block_definition unit_hud_reference_block;
	extern s_tag_struct_definition unit_hud_reference_block_struct_definition;
	extern s_tag_reference_definition unit_hud_interface_reference;

	extern s_tag_block_definition unit_camera_track_block;
	extern s_tag_struct_definition unit_camera_track_block_struct_definition;

	extern s_tag_block_definition unit_weapon_block;
	extern s_tag_struct_definition unit_weapon_block_struct_definition;
	extern s_tag_reference_definition weapon_reference;

	extern s_tag_block_definition powered_seat_block;
	extern s_tag_struct_definition powered_seat_block_struct_definition;

	extern s_tag_block_definition dialogue_variant_block;
	extern s_tag_struct_definition dialogue_variant_block_struct_definition;
	extern s_tag_reference_definition dialogue_reference;


	static constexpr unsigned long BIPED_TAG = 'bipd';
	extern s_tag_group biped_group;
	extern s_tag_block_definition biped;
	extern s_tag_struct_definition biped_struct_definition;
	extern c_versioned_string_list unnamed_enum$28_strings;
	extern s_string_list_definition unnamed_enum$28;
	extern c_versioned_string_list unnamed_enum$29_strings;
	extern s_string_list_definition unnamed_enum$29;

	extern s_tag_block_definition contact_point_block;
	extern s_tag_struct_definition contact_point_block_struct_definition;


	static constexpr unsigned long VEHICLE_TAG = 'vehi';
	extern s_tag_group vehicle_group;
	extern s_tag_block_definition vehicle;
	extern s_tag_struct_definition vehicle_struct_definition;
	extern c_versioned_string_list unnamed_enum$30_strings;
	extern s_string_list_definition unnamed_enum$30;
	extern c_versioned_string_list unnamed_enum$31_strings;
	extern s_string_list_definition unnamed_enum$31;
	extern c_versioned_string_list unnamed_enum$32_strings;
	extern s_string_list_definition unnamed_enum$32;


	static constexpr unsigned long SCENERY_TAG = 'scen';
	extern s_tag_group scenery_group;
	extern s_tag_block_definition scenery;
	extern s_tag_struct_definition scenery_struct_definition;


	static constexpr unsigned long WEAPON_TAG = 'weap';
	extern s_tag_group weapon_group;
	extern s_tag_block_definition weapon;
	extern s_tag_struct_definition weapon_struct_definition;
	extern c_versioned_string_list unnamed_enum$56_strings;
	extern s_string_list_definition unnamed_enum$56;
	extern c_versioned_string_list unnamed_enum$57_strings;
	extern s_string_list_definition unnamed_enum$57;
	extern c_versioned_string_list unnamed_enum$58_strings;
	extern s_string_list_definition unnamed_enum$58;
	extern s_tag_reference_definition sound_effect_reference;
	extern c_versioned_string_list unnamed_enum$59_strings;
	extern s_string_list_definition unnamed_enum$59;
	extern s_tag_reference_definition gbxmodel_reference$2;
	extern s_tag_reference_definition model_animations_reference$2;
	extern c_versioned_string_list unnamed_enum$60_strings;
	extern s_string_list_definition unnamed_enum$60;

	extern s_tag_block_definition triggers;
	extern s_tag_struct_definition triggers_struct_definition;
	extern c_versioned_string_list unnamed_enum$62_strings;
	extern s_string_list_definition unnamed_enum$62;
	extern c_versioned_string_list unnamed_enum$63_strings;
	extern s_string_list_definition unnamed_enum$63;
	extern c_versioned_string_list unnamed_enum$64_strings;
	extern s_string_list_definition unnamed_enum$64;

	extern s_tag_block_definition trigger_firing_effect_block;
	extern s_tag_struct_definition trigger_firing_effect_block_struct_definition;

	extern s_tag_block_definition magazines;
	extern s_tag_struct_definition magazines_struct_definition;
	extern c_versioned_string_list unnamed_enum$61_strings;
	extern s_string_list_definition unnamed_enum$61;

	extern s_tag_block_definition magazine_objects;
	extern s_tag_struct_definition magazine_objects_struct_definition;



} // namespace blofeld

} // namespace halo1

