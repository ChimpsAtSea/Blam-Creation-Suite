#pragma once

struct s_scenario_definition
{
	struct s_structure_bsp_block_definition;
	struct s_structure_design_block_definition;
	struct s_sky_reference_block_definition;
	struct s_bsp_group_block_definition;
	struct s_scenario_bsp_audibility_block_definition;
	struct s_scenario_zoneset_group_block_definition;
	struct s_object_name_block_definition;
	struct s_scenery_block_definition;
	struct s_scenery_palette_block_definition;
	struct s_biped_block_definition;
	struct s_biped_palette_block_definition;
	struct s_vehicle_block_definition;
	struct s_vehicle_palette_block_definition;
	struct s_equipment_block_definition;
	struct s_equipment_palette_block_definition;
	struct s_weapon_block_definition;
	struct s_weapon_palette_block_definition;
	struct s_device_group_block_definition;
	struct s_machine_block_definition;
	struct s_machine_palette_block_definition;
	struct s_terminal_block_definition;
	struct s_terminal_palette_block_definition;
	struct s_control_block_definition;
	struct s_control_palette_block_definition;
	struct s_sound_scenery_block_definition;
	struct s_sound_scenery_palette_block_definition;
	struct s_giant_block_definition;
	struct s_giant_palette_block_definition;
	struct s_effect_scenery_block_definition;
	struct s_effect_scenery_palette_block_definition;
	struct s_light_volume_block_definition;
	struct s_light_volumes_palette_block_definition;
	struct s_sandbox_palette_block_definition;
	struct s_legacy_sandbox_info_block_definition;
	struct s_soft_ceiling_block_definition;
	struct s_player_starting_profile_block_definition;
	struct s_player_starting_location_block_definition;
	struct s_trigger_volume_block_definition;
	struct s_unknown_22_block_definition;
	struct s_unknown_23_block_definition;
	struct s_unknown_28_block_definition;
	struct s_zoneset_switch_trigger_volume_block_definition;
	struct s_location_name_callout_block_definition;
	struct s_unknown_40_block_definition;
	struct s_unknown_40_3_block_definition;
	struct s_unknown_40_5_block_definition;
	struct s_unknown_41_block_definition;
	struct s_decal_block_definition;
	struct s_decal_palette_block_definition;
	struct s_squad_group_block_definition;
	struct s_squad_block_definition;
	struct s_zone_block_definition;
	struct s_unknown_43_block_definition;
	struct s_ai_cue_block_definition;
	struct s_character_palette_block_definition;
	struct s_ai_pathfinding_datum_block_definition;
	struct s_script_block_definition;
	struct s_global_block_definition;
	struct s_script_reference_block_definition;
	struct s_scripting_datum_block_definition;
	struct s_cutscene_flag_block_definition;
	struct s_cutscene_camera_point_block_definition;
	struct s_cutscene_title_block_definition;
	struct s_scenario_resource_block_definition;
	struct s_unit_seats_mapping_block_definition;
	struct s_scenario_kill_trigger_block_definition;
	struct s_scenario_safe_trigger_block_definition;
	struct s_scenario_mopp_trigger_block_definition;
	struct s_script_expression_block_definition;
	struct s_background_sound_environment_palette_block_definition;
	struct s_fog_block_definition;
	struct s_camera_fx_block_definition;
	struct s_weather_block_definition;
	struct s_scenario_cluster_datum_block_definition;
	struct s_spawn_datum_block_definition;
	struct s_crate_block_definition;
	struct s_crate_palette_block_definition;
	struct s_flock_palette_block_definition;
	struct s_flock_block_definition;
	struct s_creature_palette_block_definition;
	struct s_big_battle_creature_block_definition;
	struct s_editor_folder_block_definition;
	struct s_mission_dialogue_block_definition;
	struct s_unknown_59_block_definition;
	struct s_ai_objective_block_definition;
	struct s_designer_zoneset_block_definition;
	struct s_unknown_61_block_definition;
	struct s_particle_emitter_block_definition;
	struct s_unknown101_block_definition;
	struct s_cinematic_block_definition;
	struct s_cinematic_light_block_definition;
	struct s_scenario_metagame_block_definition;
	struct s_unknown_64_block_definition;
	struct s_unknown_65_block_definition;
	struct s_vignette_block_definition;
	struct s_unknown_66_block_definition;
	struct s_compiled_datum_block_definition;

	signed short map_type;
	unsigned short flags;
	signed int unknown;
	signed int campaign_id;
	signed int map_id;
	string_id scenario_name;
	signed short campaign_level_index;
	signed short unknown2;
	signed int unknown3;
	float local_north;
	float unknown4;
	float unknown5;
	unsigned int unknown6;
	unsigned int unknown7;
	float unknown8;
	float sandbox_budget;
	string_id default_vehicle_filter;
	TagReference performance_throttle_profile;
	s_tag_block_definition<s_structure_bsp_block_definition> structure_bsps;
	s_tag_block_definition<s_structure_design_block_definition> structure_design2;
	TagReference unknown9;
	TagReference unknown10;
	s_tag_block_definition<s_sky_reference_block_definition> sky_references;
	s_tag_block_definition<s_bsp_group_block_definition> bsp_groups;
	s_tag_block_definition<s_scenario_bsp_audibility_block_definition> scenario_bsp_audibility2;
	s_tag_block_definition<s_scenario_zoneset_group_block_definition> scenario_zoneset_groups;
	unsigned int unknown11;
	unsigned int unknown12;
	unsigned int unknown13;
	unsigned int unknown14;
	unsigned int unknown15;
	unsigned int unknown16;
	unsigned int unknown17;
	unsigned int unknown18;
	unsigned int unknown19;
	unsigned int unknown20;
	unsigned int unknown21;
	unsigned int unknown22;
	DataReference editor_scenario_data;
	unsigned int unknown23;
	unsigned int unknown24;
	unsigned int unknown25;
	s_tag_block_definition<s_object_name_block_definition> object_names;
	s_tag_block_definition<s_scenery_block_definition> scenery2;
	s_tag_block_definition<s_scenery_palette_block_definition> scenery_palette2;
	s_tag_block_definition<s_biped_block_definition> bipeds;
	s_tag_block_definition<s_biped_palette_block_definition> biped_palette2;
	s_tag_block_definition<s_vehicle_block_definition> vehicles;
	s_tag_block_definition<s_vehicle_palette_block_definition> vehicle_palette2;
	s_tag_block_definition<s_equipment_block_definition> equipment2;
	s_tag_block_definition<s_equipment_palette_block_definition> equipment_palette2;
	s_tag_block_definition<s_weapon_block_definition> weapons;
	s_tag_block_definition<s_weapon_palette_block_definition> weapon_palette2;
	s_tag_block_definition<s_device_group_block_definition> device_groups;
	s_tag_block_definition<s_machine_block_definition> machines;
	s_tag_block_definition<s_machine_palette_block_definition> machine_palette2;
	s_tag_block_definition<s_terminal_block_definition> terminals;
	s_tag_block_definition<s_terminal_palette_block_definition> terminal_palette2;
	s_tag_block_definition<s_control_block_definition> controls;
	s_tag_block_definition<s_control_palette_block_definition> control_palette2;
	s_tag_block_definition<s_sound_scenery_block_definition> sound_scenery2;
	s_tag_block_definition<s_sound_scenery_palette_block_definition> sound_scenery_palette2;
	s_tag_block_definition<s_giant_block_definition> giants;
	s_tag_block_definition<s_giant_palette_block_definition> giant_palette2;
	s_tag_block_definition<s_effect_scenery_block_definition> effect_scenery2;
	s_tag_block_definition<s_effect_scenery_palette_block_definition> effect_scenery_palette2;
	s_tag_block_definition<s_light_volume_block_definition> light_volumes;
	s_tag_block_definition<s_light_volumes_palette_block_definition> light_volumes_palette2;
	s_tag_block_definition<s_sandbox_palette_block_definition> sandbox_palette2;
	s_tag_block_definition<s_legacy_sandbox_info_block_definition> legacy_sandbox_info2;
	TagReference unknown26;
	unsigned int unknown27;
	unsigned int unknown28;
	unsigned int unknown29;
	s_tag_block_definition<s_soft_ceiling_block_definition> soft_ceilings;
	s_tag_block_definition<s_player_starting_profile_block_definition> player_starting_profile2;
	s_tag_block_definition<s_player_starting_location_block_definition> player_starting_locations;
	s_tag_block_definition<s_trigger_volume_block_definition> trigger_volumes;
	s_tag_block_definition<s_unknown_22_block_definition> unknown_22_2;
	s_tag_block_definition<s_unknown_23_block_definition> unknown_23_2;
	s_tag_block_definition<s_unknown_28_block_definition> unknown_28_2;
	unsigned int unknown30;
	unsigned int unknown31;
	unsigned int unknown32;
	unsigned int unknown33;
	unsigned int unknown34;
	unsigned int unknown35;
	s_tag_block_definition<s_zoneset_switch_trigger_volume_block_definition> zoneset_switch_trigger_volumes;
	s_tag_block_definition<s_location_name_callout_block_definition> location_name_callouts;
	TagReference airstrike_globals;
	unsigned int unknown36;
	unsigned int unknown37;
	unsigned int unknown38;
	s_tag_block_definition<s_unknown_40_block_definition> unknown_40_2;
	s_tag_block_definition<s_unknown_40_3_block_definition> unknown_40_4;
	s_tag_block_definition<s_unknown_40_5_block_definition> unknown_40_6;
	s_tag_block_definition<s_unknown_41_block_definition> unknown_41_2;
	unsigned int unknown39;
	unsigned int unknown40;
	unsigned int unknown41;
	unsigned int unknown42;
	unsigned int unknown43;
	unsigned int unknown44;
	unsigned int unknown45;
	unsigned int unknown46;
	unsigned int unknown47;
	unsigned int unknown48;
	unsigned int unknown49;
	unsigned int unknown50;
	unsigned int unknown51;
	unsigned int unknown52;
	unsigned int unknown53;
	s_tag_block_definition<s_decal_block_definition> decals;
	s_tag_block_definition<s_decal_palette_block_definition> decal_palette2;
	unsigned int unknown54;
	unsigned int unknown55;
	unsigned int unknown56;
	unsigned int unknown57;
	unsigned int unknown58;
	unsigned int unknown59;
	s_tag_block_definition<s_squad_group_block_definition> squad_groups;
	s_tag_block_definition<s_squad_block_definition> squads;
	s_tag_block_definition<s_zone_block_definition> zones;
	s_tag_block_definition<s_unknown_43_block_definition> unknown_43_2;
	s_tag_block_definition<s_ai_cue_block_definition> ai_cues;
	unsigned int unknown60;
	unsigned int unknown61;
	unsigned int unknown62;
	unsigned int unknown63;
	unsigned int unknown64;
	unsigned int unknown65;
	unsigned int unknown66;
	unsigned int unknown67;
	unsigned int unknown68;
	s_tag_block_definition<s_character_palette_block_definition> character_palette2;
	unsigned int unknown69;
	unsigned int unknown70;
	unsigned int unknown71;
	s_tag_block_definition<s_ai_pathfinding_datum_block_definition> ai_pathfinding_data;
	unsigned int unknown72;
	unsigned int unknown73;
	unsigned int unknown74;
	DataReference script_strings;
	s_tag_block_definition<s_script_block_definition> scripts;
	s_tag_block_definition<s_global_block_definition> globals;
	s_tag_block_definition<s_script_reference_block_definition> script_references;
	unsigned int unknown75;
	unsigned int unknown76;
	unsigned int unknown77;
	s_tag_block_definition<s_scripting_datum_block_definition> scripting_data;
	s_tag_block_definition<s_cutscene_flag_block_definition> cutscene_flags;
	s_tag_block_definition<s_cutscene_camera_point_block_definition> cutscene_camera_points;
	s_tag_block_definition<s_cutscene_title_block_definition> cutscene_titles;
	TagReference custom_object_name_strings;
	TagReference chapter_title_strings;
	s_tag_block_definition<s_scenario_resource_block_definition> scenario_resources;
	s_tag_block_definition<s_unit_seats_mapping_block_definition> unit_seats_mapping2;
	s_tag_block_definition<s_scenario_kill_trigger_block_definition> scenario_kill_triggers;
	s_tag_block_definition<s_scenario_safe_trigger_block_definition> scenario_safe_triggers;
	s_tag_block_definition<s_scenario_mopp_trigger_block_definition> scenario_mopp_triggers;
	unsigned int unknown78;
	unsigned int unknown79;
	unsigned int unknown80;
	unsigned int unknown81;
	unsigned int unknown82;
	unsigned int unknown83;
	s_tag_block_definition<s_script_expression_block_definition> script_expressions;
	unsigned int unknown84;
	unsigned int unknown85;
	unsigned int unknown86;
	unsigned int unknown87;
	unsigned int unknown88;
	unsigned int unknown89;
	s_tag_block_definition<s_background_sound_environment_palette_block_definition> background_sound_environment_palette2;
	s_tag_block_definition<s_fog_block_definition> fog2;
	s_tag_block_definition<s_camera_fx_block_definition> camera_fx2;
	s_tag_block_definition<s_weather_block_definition> weather2;
	s_tag_block_definition<s_scenario_cluster_datum_block_definition> scenario_cluster_data;
	signed int object_salts__1;
	signed int object_salts__2;
	signed int object_salts__3;
	signed int object_salts__4;
	signed int object_salts__5;
	signed int object_salts__6;
	signed int object_salts__7;
	signed int object_salts__8;
	signed int object_salts__9;
	signed int object_salts_10;
	signed int object_salts_11;
	signed int object_salts_12;
	signed int object_salts_13;
	signed int object_salts_14;
	signed int object_salts_15;
	signed int object_salts_16;
	signed int object_salts_17;
	signed int object_salts_18;
	signed int object_salts_19;
	signed int object_salts_20;
	signed int object_salts_21;
	signed int object_salts_22;
	signed int object_salts_23;
	signed int object_salts_24;
	signed int object_salts_25;
	signed int object_salts_26;
	signed int object_salts_27;
	signed int object_salts_28;
	signed int object_salts_29;
	signed int object_salts_30;
	signed int object_salts_31;
	signed int object_salts_32;
	s_tag_block_definition<s_spawn_datum_block_definition> spawn_data;
	TagReference sound_effects_collection;
	s_tag_block_definition<s_crate_block_definition> crates;
	s_tag_block_definition<s_crate_palette_block_definition> crate_palette2;
	s_tag_block_definition<s_flock_palette_block_definition> flock_palette2;
	s_tag_block_definition<s_flock_block_definition> flocks;
	TagReference subtitle_strings;
	unsigned int unknown90;
	unsigned int unknown91;
	unsigned int unknown92;
	s_tag_block_definition<s_creature_palette_block_definition> creature_palette2;
	s_tag_block_definition<s_big_battle_creature_block_definition> big_battle_creatures;
	s_tag_block_definition<s_editor_folder_block_definition> editor_folders;
	TagReference territory_location_name_strings;
	unsigned int unknown93;
	unsigned int unknown94;
	s_tag_block_definition<s_mission_dialogue_block_definition> mission_dialogue2;
	TagReference objective_strings;
	TagReference scenario_interpolator;
	unsigned int unknown95;
	unsigned int unknown96;
	unsigned int unknown97;
	TagReference default_camera_fx;
	TagReference default_screen_fx;
	TagReference ambient_occlusion_profile;
	TagReference sky_parameters;
	TagReference fog_parameters;
	TagReference global_lighting;
	TagReference lightmap;
	TagReference performance_throttles;
	s_tag_block_definition<s_unknown_59_block_definition> unknown_59_2;
	s_tag_block_definition<s_ai_objective_block_definition> ai_objectives;
	s_tag_block_definition<s_designer_zoneset_block_definition> designer_zonesets;
	s_tag_block_definition<s_unknown_61_block_definition> unknown_61_2;
	unsigned int unknown98;
	unsigned int unknown99;
	unsigned int unknown100;
	s_tag_block_definition<s_particle_emitter_block_definition> particle_emitters;
	s_tag_block_definition<s_unknown101_block_definition> unknown102;
	s_tag_block_definition<s_cinematic_block_definition> cinematics;
	s_tag_block_definition<s_cinematic_light_block_definition> cinematic_lights;
	unsigned int unknown103;
	unsigned int unknown104;
	unsigned int unknown105;
	s_tag_block_definition<s_scenario_metagame_block_definition> scenario_metagame2;
	s_tag_block_definition<s_unknown_64_block_definition> unknown_64_2;
	s_tag_block_definition<s_unknown_65_block_definition> unknown_65_2;
	unsigned int unknown106;
	unsigned int unknown107;
	unsigned int unknown108;
	unsigned int unknown109;
	unsigned int unknown110;
	unsigned int unknown111;
	unsigned int unknown112;
	unsigned int unknown113;
	unsigned int unknown114;
	s_tag_block_definition<s_vignette_block_definition> vignettes;
	TagReference map_location_globals;
	s_tag_block_definition<s_unknown_66_block_definition> unknown_66_2;
	TagReference mission_hud;
	TagReference required_resources;
	TagReference variant_globals;
	s_tag_block_definition<s_compiled_datum_block_definition> compiled_data;

	struct s_structure_bsp_definition
	{
		TagReference structure_bsp2;
		TagReference unknown;
		TagReference structure_lighting;
		TagReference unknown2;
		signed int unknown3;
		float unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned short flags;
		signed short unknown7;
		unsigned int unknown8;
		TagReference cubemap;
		TagReference wind;
		unsigned int unknown9;
		float unknown10;
		float unknown11;
		float unknown12;
		float unknown13;
		float unknown14;
		float unknown15;
		float unknown16;
		unsigned int unknown17;
		float unknown18;
		unsigned int unknown19;
		signed int unknown20;
		float gravity_percentage;
	};

	struct s_structure_design_definition
	{
		TagReference design;
		TagReference unknown;
	};

	struct s_sky_reference_definition
	{
		TagReference sky_object;
		float unknown;
		float unknown2;
		float unknown3;
		TagReference unknown4;
		signed short name_index;
		unsigned short active_bsps;
	};

	struct s_bsp_group_definition
	{
		struct s_bsp_checksum_block_definition;
		struct s_bsp_block_definition;
		struct s_bsp2_block_definition;

		signed int included_bsps;
		signed int unknown;
		s_tag_block_definition<s_bsp_checksum_block_definition> bsp_checksums;
		s_tag_block_definition<s_bsp_block_definition> bsps;
		s_tag_block_definition<s_bsp2_block_definition> bsps2;

		struct s_bsp_checksum_definition
		{
			signed int structure_checksum;
		};

		struct s_bsp_definition
		{
			struct s_cluster_block_definition;
			struct s_cluster2_block_definition;
			struct s_cluster_sky_block_definition;
			struct s_cluster_visible_sky_block_definition;
			struct s_unknown_block_definition;
			struct s_cluster3_block_definition;

			s_tag_block_definition<s_cluster_block_definition> clusters;
			s_tag_block_definition<s_cluster2_block_definition> clusters2;
			s_tag_block_definition<s_cluster_sky_block_definition> cluster_skies;
			s_tag_block_definition<s_cluster_visible_sky_block_definition> cluster_visible_skies;
			s_tag_block_definition<s_unknown_block_definition> unknown2;
			s_tag_block_definition<s_cluster3_block_definition> clusters3;

			struct s_cluster_definition
			{
				struct s_bsp_block_definition;

				s_tag_block_definition<s_bsp_block_definition> bsps;

				struct s_bsp_definition
				{
					struct s_unknown_block_definition;

					s_tag_block_definition<s_unknown_block_definition> unknown2;

					struct s_unknown_definition
					{
						signed int allow;
					};
				};
			};

			struct s_cluster_definition
			{
				struct s_bsp_block_definition;

				s_tag_block_definition<s_bsp_block_definition> bsps;

				struct s_bsp_definition
				{
					struct s_unknown_block_definition;

					s_tag_block_definition<s_unknown_block_definition> unknown2;

					struct s_unknown_definition
					{
						signed int show;
					};
				};
			};

			struct s_cluster_sky_definition
			{
				signed char sky_index;
			};

			struct s_cluster_visible_sky_definition
			{
				signed char sky_index;
			};

			struct s_unknown_definition
			{
				unsigned int unknown2;
			};

			struct s_cluster_definition
			{
				struct s_unknown_block_definition;
				struct s_unknown3_block_definition;
				struct s_unknown5_block_definition;

				s_tag_block_definition<s_unknown_block_definition> unknown2;
				s_tag_block_definition<s_unknown3_block_definition> unknown4;
				s_tag_block_definition<s_unknown5_block_definition> unknown6;

				struct s_unknown_definition
				{
					signed char unknown2;
					signed char unknown3;
				};

				struct s_unknown_definition
				{
					signed char unknown2;
					signed char unknown3;
				};

				struct s_unknown_definition
				{
					signed char unknown2;
					signed char unknown3;
				};
			};
		};

		struct s_bsp_definition
		{
			struct s_unknown_block_definition;
			struct s_unknown3_block_definition;

			s_tag_block_definition<s_unknown_block_definition> unknown2;
			s_tag_block_definition<s_unknown3_block_definition> unknown4;
			unsigned int unknown5;
			unsigned int unknown6;
			unsigned int unknown7;

			struct s_unknown_definition
			{
				signed short unknown2;
				signed short unknown3;
				signed int unknown4;
				signed short unknown5;
				signed short unknown6;
			};

			struct s_unknown_definition
			{
				signed short unknown2;
			};
		};
	};

	struct s_scenario_bsp_audibility_definition
	{
		struct s_encoded_door_pa_block_definition;
		struct s_cluster_door_portal_encoded_pa_block_definition;
		struct s_ai_deafening_pa_block_definition;
		struct s_cluster_distance_block_definition;
		struct s_bsp_block_definition;
		struct s_bsp_cluster_list_block_definition;
		struct s_cluster_mapping_block_definition;

		signed int door_portal_count;
		signed int unique_cluster_count;
		float cluster_distance_bounds_min;
		float cluster_distance_bounds_max;
		s_tag_block_definition<s_encoded_door_pa_block_definition> encoded_door_pas;
		s_tag_block_definition<s_cluster_door_portal_encoded_pa_block_definition> cluster_door_portal_encoded_pas;
		s_tag_block_definition<s_ai_deafening_pa_block_definition> ai_deafening_pas;
		s_tag_block_definition<s_cluster_distance_block_definition> cluster_distances;
		s_tag_block_definition<s_bsp_block_definition> bsps;
		s_tag_block_definition<s_bsp_cluster_list_block_definition> bsp_cluster_list2;
		s_tag_block_definition<s_cluster_mapping_block_definition> cluster_mapping2;

		struct s_encoded_door_pa_definition
		{
			signed int unknown;
		};

		struct s_cluster_door_portal_encoded_pa_definition
		{
			signed int unknown;
		};

		struct s_ai_deafening_pa_definition
		{
			signed int unknown;
		};

		struct s_cluster_distance_definition
		{
			signed char unknown;
		};

		struct s_bsp_definition
		{
			signed int start;
			signed int count;
		};

		struct s_bsp_cluster_list_definition
		{
			signed int start_index;
			signed int cluster_count;
		};

		struct s_cluster_mapping_definition
		{
			signed short index;
		};
	};

	struct s_scenario_zoneset_group_definition
	{
		struct s_unknown_6_block_definition;

		string_id name;
		char name_string[256];
		signed int bsp_group_index;
		signed int unknown;
		signed int loaded_bsps_1;
		signed int unknown2;
		signed int loaded_bsps_2;
		signed int unknown3;
		signed int loaded_designer_zonesets;
		signed int unloaded_designer_zonesets;
		signed int loaded_cinematic_zonesets;
		signed int bsp_atlas_index;
		signed int scenario_bsp_audibility_index;
		s_tag_block_definition<s_unknown_6_block_definition> unknown_6_2;

		struct s_unknown_6_definition
		{
			struct s_bsp_block_definition;

			s_tag_block_definition<s_bsp_block_definition> bsps;

			struct s_bsp_definition
			{
				struct s_cluster_block_definition;

				s_tag_block_definition<s_cluster_block_definition> clusters;

				struct s_cluster_definition
				{
					struct s_unknown_6_block_definition;

					s_tag_block_definition<s_unknown_6_block_definition> unknown_6_2;

					struct s_unknown_6_definition
					{
						unsigned int unknown;
					};
				};
			};
		};
	};

	struct s_object_name_definition
	{
		string_id name;
		signed short type;
		signed short placement_index;
	};

	struct s_scenery_definition
	{
		struct s_node_positioning_block_definition;
		struct s_pathfinding_reference_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		signed short pathfinding_policy;
		signed short lightmapping_policy;
		s_tag_block_definition<s_pathfinding_reference_block_definition> pathfinding_references;
		signed short unknown12;
		signed short unknown13;
		char custom_label[32];
		signed int symmetry;
		signed char unknown14;
		signed char team;
		signed short unknown15;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown16;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown17;
		signed short attached_name_index;
		unsigned int unknown18;
		unsigned int unknown19;
		unsigned int unknown20;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};

		struct s_pathfinding_reference_definition
		{
			signed short bsp_index;
			signed short pathfinding_object_index;
		};
	};

	struct s_scenery_palette_definition
	{
		TagReference scenery;
	};

	struct s_biped_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		float body_vitality_percentage;
		signed int flags;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_biped_palette_definition
	{
		TagReference biped;
	};

	struct s_vehicle_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		float body_vitality_percentage;
		signed int flags;
		char custom_label[32];
		signed int symmetry;
		signed char unknown12;
		signed char team;
		signed short unknown13;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown14;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown15;
		signed short attached_name_index;
		unsigned int unknown16;
		unsigned int unknown17;
		unsigned int unknown18;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_vehicle_palette_definition
	{
		TagReference vehicle;
	};

	struct s_equipment_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		signed int equipment_flags;
		char custom_label[32];
		signed int symmetry;
		signed char unknown9;
		signed char team;
		signed short unknown10;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown11;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown12;
		signed short attached_name_index;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_equipment_palette_definition
	{
		TagReference equipment;
	};

	struct s_weapon_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		signed short rounds_left;
		signed short rounds_loaded;
		signed int weapon_flags;
		char custom_label[32];
		signed int symmetry;
		signed char unknown12;
		signed char team;
		signed short unknown13;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown14;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown15;
		signed short attached_name_index;
		unsigned int unknown16;
		unsigned int unknown17;
		unsigned int unknown18;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_weapon_palette_definition
	{
		TagReference weapon;
	};

	struct s_device_group_definition
	{
		char name[32];
		float initial_value;
		signed int flags;
		signed short editor_folder_index;
		signed short unknown;
	};

	struct s_machine_definition
	{
		struct s_node_positioning_block_definition;
		struct s_pathfinding_reference_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		signed short power_group;
		signed short position_group;
		signed int device_flags;
		signed int machine_flags;
		s_tag_block_definition<s_pathfinding_reference_block_definition> pathfinding_references;
		signed short pathfinding_policy;
		signed short unknown12;
		char custom_label[32];
		signed int symmetry;
		signed char unknown13;
		signed char team;
		signed short unknown14;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown15;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown16;
		signed short attached_name_index;
		unsigned int unknown17;
		unsigned int unknown18;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};

		struct s_pathfinding_reference_definition
		{
			signed short bsp_index;
			signed short pathfinding_object_index;
		};
	};

	struct s_machine_palette_definition
	{
		TagReference machine;
	};

	struct s_terminal_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		signed short power_group;
		signed short position_group;
		signed int device_flags;
		unsigned int unknown12;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_terminal_palette_definition
	{
		TagReference terminal;
	};

	struct s_control_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		signed short power_group;
		signed short position_group;
		signed int device_flags;
		signed int unknown12;
		signed int control_flags;
		signed short unknown13;
		signed short unknown14;
		char custom_label[32];
		signed int symmetry;
		signed char unknown15;
		signed char team;
		signed short unknown16;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown17;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown18;
		signed short attached_name_index;
		unsigned int unknown19;
		unsigned int unknown20;
		unsigned int unknown21;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_control_palette_definition
	{
		TagReference control;
	};

	struct s_sound_scenery_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		signed int volume_type;
		unsigned int unknown9;
		float unknown10;
		float unknown11;
		unsigned int unknown12;
		float unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		float unknown16;
		unsigned int unknown17;
		unsigned int unknown18;
		float unknown19;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_sound_scenery_palette_definition
	{
		TagReference sound_scenery;
	};

	struct s_giant_definition
	{
		struct s_node_positioning_block_definition;
		struct s_pathfinding_reference_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		unsigned char active_change_colors;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		float body_vitality_percentage;
		signed int flags;
		signed short unknown12;
		signed short unknown13;
		s_tag_block_definition<s_pathfinding_reference_block_definition> pathfinding_references;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};

		struct s_pathfinding_reference_definition
		{
			signed short bsp_index;
			signed short pathfinding_object_index;
		};
	};

	struct s_giant_palette_definition
	{
		TagReference giant;
	};

	struct s_effect_scenery_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		char custom_label[32];
		signed int symmetry;
		signed char unknown9;
		signed char team;
		signed short unknown10;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown11;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown12;
		signed short attached_name_index;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_effect_scenery_palette_definition
	{
		TagReference effect_scenery;
	};

	struct s_light_volume_definition
	{
		struct s_node_positioning_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		signed short power_group;
		signed short position_group;
		signed int device_flags;
		signed short type2;
		unsigned short flags;
		signed short lightmap_type;
		unsigned short lightmap_flags;
		float lightmap_half_life;
		float lightmap_light_scale;
		float x;
		float y;
		float z;
		float width;
		float height_scale;
		float field_of_view;
		float falloff_distance;
		float cutoff_distance;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};
	};

	struct s_light_volumes_palette_definition
	{
		TagReference light_volume;
	};

	struct s_sandbox_palette_definition
	{
		struct s_entry_block_definition;

		string_id name;
		unsigned char flags;
		signed char unknown;
		signed char thorage;
		signed char unknown2;
		s_tag_block_definition<s_entry_block_definition> entries;

		struct s_entry_definition
		{
			struct s_entry_variant_block_definition;

			string_id name;
			s_tag_block_definition<s_entry_variant_block_definition> entry_variants;
			signed int entry_count;
			signed int entry_price;
			signed char thorage;
			signed char unknown;
			signed char unknown2;
			signed char unknown3;

			struct s_entry_variant_definition
			{
				string_id name;
				TagReference palette_object;
				string_id palette_object_variant;
			};
		};
	};

	struct s_legacy_sandbox_info_definition
	{
		struct s_build_block_definition;

		s_tag_block_definition<s_build_block_definition> builds;

		struct s_build_definition
		{
			unsigned int unknown;
			signed int quota_count;
			unsigned int unknown2;
			unsigned int unknown3;
			char build_number[32];
		};
	};

	struct s_soft_ceiling_definition
	{
		signed short type;
		signed short unknown;
		string_id name;
		signed short unknown2;
		signed short unknown3;
	};

	struct s_player_starting_profile_definition
	{
		char name[32];
		float starting_health_damage;
		float starting_shield_damage;
		TagReference primary_weapon;
		signed short rounds_loaded;
		signed short rounds_total;
		TagReference secondary_weapon;
		signed short rounds_loaded2;
		signed short rounds_total2;
		unsigned char starting_frag_grenade_count;
		unsigned char starting_plasma_grenade_count;
		unsigned char starting_unused_grenade_count;
		unsigned char starting_unused_grenade_count2;
		TagReference equipment;
		signed short unknown;
		signed short unknown2;
	};

	struct s_player_starting_location_definition
	{
		float position_x;
		float position_y;
		float position_z;
		float facing_y;
		float facing_p;
		signed short unknown;
		signed short unknown2;
		signed short editor_folder_index;
		signed short unknown3;
	};

	struct s_trigger_volume_definition
	{
		struct s_unknown11_block_definition;
		struct s_unknown13_block_definition;

		string_id name;
		signed short object_name;
		signed short unknown;
		string_id node_name;
		signed short unknown2;
		signed short unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		float unknown9;
		float position_x;
		float position_y;
		float position_z;
		float extents_x;
		float extents_y;
		float extents_z;
		float unknown10;
		s_tag_block_definition<s_unknown11_block_definition> unknown12;
		s_tag_block_definition<s_unknown13_block_definition> unknown14;
		float unknown15;
		float unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
		float unknown20;
		float unknown21;
		signed short kill_volume;
		signed short editor_folder_index;

		struct s_unknown_definition
		{
			float unknown2;
			float unknown3;
			float unknown4;
			float unknown5;
			float unknown6;
		};

		struct s_unknown_definition
		{
			unsigned int unknown2;
			unsigned int unknown3;
			float unknown4;
			float unknown5;
			unsigned int unknown6;
			unsigned int unknown7;
			float unknown8;
			float unknown9;
			float unknown10;
			float unknown11;
			unsigned int unknown12;
			float unknown13;
			float unknown14;
			float unknown15;
			unsigned int unknown16;
			float unknown17;
			float unknown18;
			float unknown19;
			unsigned int unknown20;
			float unknown21;
			float unknown22;
			float unknown23;
			float unknown24;
			float unknown25;
			float unknown26;
			float unknown27;
			unsigned int unknown28;
			unsigned int unknown29;
		};
	};

	struct s_unknown_22_definition
	{
		struct s_unknown_23_block_definition;

		s_tag_block_definition<s_unknown_23_block_definition> unknown_23_2;
		float unknown;
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		signed short unknown9;
		signed short unknown10;
		float unknown11;
		float unknown12;

		struct s_unknown_23_definition
		{
			float x;
			float y;
			float z;
		};
	};

	struct s_unknown_23_definition
	{
		float unknown;
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		float unknown9;
		float unknown10;
		float unknown11;
		float unknown12;
		float unknown13;
		signed short unknown14;
		signed short unknown15;
		signed short unknown16;
		signed short unknown17;
		signed short unknown18;
		signed short unknown19;
		signed short unknown20;
		signed short unknown21;
	};

	struct s_unknown_28_definition
	{
		struct s_unknown_29_block_definition;
		struct s_unknown_30_block_definition;

		s_tag_block_definition<s_unknown_29_block_definition> unknown_29_2;
		s_tag_block_definition<s_unknown_30_block_definition> unknown_30_2;
		float unknown;
		float unknown2;
		float unknown3;
		unsigned int unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		signed short unknown9;
		signed short unknown10;

		struct s_unknown_29_definition
		{
			float unknown;
			float unknown2;
			float unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
		};

		struct s_unknown_30_definition
		{
			float unknown;
			float unknown2;
			float unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
		};
	};

	struct s_zoneset_switch_trigger_volume_definition
	{
		signed short unknown;
		signed short included_zoneset_index;
		signed short trigger_volume;
		signed short sole_zoneset_index;
	};

	struct s_location_name_callout_definition
	{
		struct s_location_bounds_point_block_definition;

		s_tag_block_definition<s_location_bounds_point_block_definition> location_bounds_points;
		float unknown;
		float unknown2;
		string_id name;

		struct s_location_bounds_point_definition
		{
			float x;
			float y;
			float z;
			unsigned int unknown;
			unsigned int unknown2;
		};
	};

	struct s_unknown_40_definition
	{
		float unknown;
		float unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
	};

	struct s_unknown_40_definition
	{
		float unknown;
		float unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
	};

	struct s_unknown_40_definition
	{
		float unknown;
		float unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
	};

	struct s_unknown_41_definition
	{
		float unknown;
		float unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
	};

	struct s_decal_definition
	{
		signed short palette_index;
		signed char yaw;
		signed char pitch;
		float i;
		float j;
		float k;
		float w;
		float x;
		float y;
		float z;
		float scale_min;
		float scale_max;
	};

	struct s_decal_palette_definition
	{
		TagReference decal;
	};

	struct s_squad_group_definition
	{
		char name[32];
		signed short parent_index;
		signed short objective_index;
		signed short unknown;
		signed short editor_folder_index;
	};

	struct s_squad_definition
	{
		struct s_group_location_block_definition;
		struct s_single_location_block_definition;
		struct s_squad_a_block_definition;
		struct s_squad_b_block_definition;

		char name[32];
		signed int flags;
		signed short team;
		signed short parent_squad_group_index;
		signed short parent_zone;
		signed short objective_index;
		signed short objective_role_index;
		signed short editor_folder_index;
		s_tag_block_definition<s_group_location_block_definition> group_locations;
		s_tag_block_definition<s_single_location_block_definition> single_locations;
		unsigned int unknown;
		string_id squad_template_name;
		unsigned int squad_template;
		s_tag_block_definition<s_squad_a_block_definition> squad_a2;
		s_tag_block_definition<s_squad_b_block_definition> squad_b2;

		struct s_group_location_definition
		{
			struct s_multi_state_block_definition;

			signed short unknown;
			signed short unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
			string_id name;
			float position_x;
			float position_y;
			float position_z;
			signed short reference_frame;
			signed short unknown5;
			float facing_i;
			float facing_j;
			float facing_k;
			string_id formation_type;
			float unknown6;
			signed short unknown7;
			signed short command_script_index;
			string_id command_script_name;
			string_id initial_state;
			signed short unknown8;
			signed short unknown9;
			signed short unknown10;
			signed short unknown11;
			s_tag_block_definition<s_multi_state_block_definition> multi_state2;

			struct s_multi_state_definition
			{
				signed short unknown;
				signed short unknown2;
				float unknown3;
				float unknown4;
				string_id state;
				unsigned int unknown5;
				string_id command_script_name;
				signed short command_script_index;
				signed short unknown6;
			};
		};

		struct s_single_location_definition
		{
			struct s_multi_state_block_definition;

			signed short unknown;
			signed short unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
			string_id name;
			signed short squad_member_index;
			signed short unknown5;
			float position_x;
			float position_y;
			float position_z;
			signed short reference_frame;
			signed short unknown6;
			float facing_i;
			float facing_j;
			float facing_k;
			unsigned short flags;
			signed short character_type;
			signed short initial_primary_weapon;
			signed short initial_secondary_weapon;
			signed short initial_equipment;
			signed short vehicle;
			signed short seat_type;
			signed short grenade_type;
			signed short swarm_count;
			signed short unknown7;
			string_id actor_variant;
			string_id vehicle_variant;
			string_id unknown8;
			float initial_movement_distance;
			signed short initial_movement_mode;
			signed short emitter_vehicle;
			signed short emitter_giant;
			signed short emitter_biped;
			string_id command_script_name;
			signed short command_script_index;
			signed short unknown9;
			string_id initial_state;
			signed short unknown10;
			signed short unknown11;
			signed short unknown12;
			signed short unknown13;
			s_tag_block_definition<s_multi_state_block_definition> multi_state2;

			struct s_multi_state_definition
			{
				signed short unknown;
				signed short unknown2;
				float unknown3;
				float unknown4;
				string_id state;
				unsigned int unknown5;
				string_id command_script_name;
				signed short command_script_index;
				signed short unknown6;
			};
		};

		struct s_squad_a_definition
		{
			struct s_actor_block_definition;
			struct s_weapon_block_definition;
			struct s_secondary_weapon_block_definition;
			struct s_equipment_block_definition;

			string_id name;
			unsigned short difficulty;
			signed short unknown;
			signed short minimum_round;
			signed short maximum_round;
			signed short unknown2;
			signed short unknown3;
			signed short count;
			signed short unknown4;
			s_tag_block_definition<s_actor_block_definition> actors;
			s_tag_block_definition<s_weapon_block_definition> weapons;
			s_tag_block_definition<s_secondary_weapon_block_definition> secondary_weapons;
			s_tag_block_definition<s_equipment_block_definition> equipment2;
			signed short unknown5;
			signed short vehicle;
			string_id vehicle_variant;
			string_id command_script_name;
			signed short command_script_index;
			signed short unknown6;
			string_id unknown7;
			unsigned int unknown8;
			signed short unknown9;
			signed short unknown10;
			unsigned int unknown11;
			unsigned int unknown12;
			unsigned int unknown13;

			struct s_actor_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short character;
				signed short probability;
			};

			struct s_weapon_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short weapon2;
				signed short probability;
			};

			struct s_secondary_weapon_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short weapon;
				signed short probability;
			};

			struct s_equipment_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short equipment2;
				signed short probability;
			};
		};

		struct s_squad_b_definition
		{
			struct s_actor_block_definition;
			struct s_weapon_block_definition;
			struct s_secondary_weapon_block_definition;
			struct s_equipment_block_definition;

			string_id name;
			unsigned short difficulty;
			signed short unknown;
			signed short minimum_round;
			signed short maximum_round;
			signed short unknown2;
			signed short unknown3;
			signed short count;
			signed short unknown4;
			s_tag_block_definition<s_actor_block_definition> actors;
			s_tag_block_definition<s_weapon_block_definition> weapons;
			s_tag_block_definition<s_secondary_weapon_block_definition> secondary_weapons;
			s_tag_block_definition<s_equipment_block_definition> equipment2;
			signed short unknown5;
			signed short vehicle;
			string_id vehicle_variant;
			string_id command_script_name;
			signed short command_script_index;
			signed short unknown6;
			string_id unknown7;
			unsigned int unknown8;
			signed short unknown9;
			signed short unknown10;
			unsigned int unknown11;
			unsigned int unknown12;
			unsigned int unknown13;

			struct s_actor_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short character;
				signed short probability;
			};

			struct s_weapon_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short weapon2;
				signed short probability;
			};

			struct s_secondary_weapon_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short weapon;
				signed short probability;
			};

			struct s_equipment_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short minimum_round;
				signed short maximum_round;
				unsigned int unknown3;
				signed short equipment2;
				signed short probability;
			};
		};
	};

	struct s_zone_definition
	{
		struct s_firing_position_block_definition;
		struct s_area_block_definition;

		char name[32];
		signed short unknown;
		signed short unknown2;
		s_tag_block_definition<s_firing_position_block_definition> firing_positions;
		s_tag_block_definition<s_area_block_definition> areas;
		signed short unknown3;
		signed short unknown4;

		struct s_firing_position_definition
		{
			float position_x;
			float position_y;
			float position_z;
			signed short reference_frame;
			signed short unknown;
			unsigned short flags;
			signed short unknown2;
			signed short area_index;
			signed short cluster_index;
			signed int unknown3;
			float normal_y;
			float normal_p;
			unsigned int unknown4;
		};

		struct s_area_definition
		{
			struct s_flight_hint_block_definition;
			struct s_unknown_50_block_definition;

			char name[32];
			signed int area_flags;
			float position_x;
			float position_y;
			float position_z;
			signed int unknown;
			float unknown2;
			signed short firing_position_start_index;
			signed short firing_position_count;
			signed short unknown3;
			signed short unknown4;
			signed int unknown5;
			unsigned int unknown6;
			unsigned int unknown7;
			unsigned int unknown8;
			unsigned int unknown9;
			unsigned int unknown10;
			unsigned int unknown11;
			signed short manual_reference_frame;
			signed short unknown12;
			s_tag_block_definition<s_flight_hint_block_definition> flight_hints;
			s_tag_block_definition<s_unknown_50_block_definition> unknown_50_2;
			signed short unknown13;
			signed short unknown14;
			unsigned int unknown15;
			unsigned int unknown16;
			unsigned int unknown17;
			unsigned int unknown18;
			unsigned int unknown19;
			unsigned int unknown20;
			unsigned int unknown21;
			unsigned int unknown22;
			unsigned int unknown23;
			unsigned int unknown24;
			unsigned int unknown25;

			struct s_flight_hint_definition
			{
				signed short flight_hint_index;
				signed short poit_index;
				unsigned int unknown;
			};

			struct s_unknown_50_definition
			{
				float position_x;
				float position_y;
				float position_z;
				signed short unknown;
				signed short unknown2;
				float facing_y;
				float facing_p;
			};
		};
	};

	struct s_unknown_43_definition
	{
		struct s_unknown_44_block_definition;
		struct s_unknown_45_block_definition;

		string_id unknown;
		s_tag_block_definition<s_unknown_44_block_definition> unknown_44_2;
		s_tag_block_definition<s_unknown_45_block_definition> unknown_45_2;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		signed short unknown5;
		signed short unknown6;

		struct s_unknown_44_definition
		{
			signed short unknown;
			signed short unknown2;
		};

		struct s_unknown_45_definition
		{
			signed short unknown;
			signed short unknown2;
			float unknown3;
			float unknown4;
			float unknown5;
			float unknown6;
		};
	};

	struct s_ai_cue_definition
	{
		struct s_unknown_45_block_definition;
		struct s_unknown_46_block_definition;
		struct s_unknown_47_block_definition;
		struct s_unknown_48_block_definition;
		struct s_unknown_49_block_definition;
		struct s_unknown_50_block_definition;
		struct s_actor_stimulus_block_definition;

		string_id unknown;
		signed short unknown2;
		signed short unknown3;
		float x;
		float y;
		float z;
		signed int unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		s_tag_block_definition<s_unknown_45_block_definition> unknown_45_2;
		s_tag_block_definition<s_unknown_46_block_definition> unknown_46_2;
		s_tag_block_definition<s_unknown_47_block_definition> unknown_47_2;
		s_tag_block_definition<s_unknown_48_block_definition> unknown_48_2;
		s_tag_block_definition<s_unknown_49_block_definition> unknown_49_2;
		s_tag_block_definition<s_unknown_50_block_definition> unknown_50_2;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		s_tag_block_definition<s_actor_stimulus_block_definition> actor_stimuli;
		unsigned int unknown14;
		unsigned int unknown15;
		unsigned int unknown16;
		unsigned int unknown17;

		struct s_unknown_45_definition
		{
			signed short unknown;
			signed short unknown2;
		};

		struct s_unknown_46_definition
		{
			float unknown;
			unsigned int unknown2;
		};

		struct s_unknown_47_definition
		{
			float unknown;
		};

		struct s_unknown_48_definition
		{
			signed short unknown;
			signed short unknown2;
		};

		struct s_unknown_49_definition
		{
			signed short unknown;
			signed short unknown2;
		};

		struct s_unknown_50_definition
		{
			float unknown;
		};

		struct s_actor_stimulus_definition
		{
			string_id actor_name;
		};
	};

	struct s_character_palette_definition
	{
		TagReference character;
	};

	struct s_ai_pathfinding_datum_definition
	{
		struct s_unknown_36_block_definition;
		struct s_unknown_37_block_definition;
		struct s_unknown_38_block_definition;
		struct s_unknown_38_3_block_definition;
		struct s_unknown_52_block_definition;
		struct s_unknown_53_block_definition;
		struct s_unknown_54_block_definition;
		struct s_unknown_39_block_definition;
		struct s_unknown_53_3_block_definition;
		struct s_unknown_41_block_definition;

		s_tag_block_definition<s_unknown_36_block_definition> unknown_36_2;
		s_tag_block_definition<s_unknown_37_block_definition> unknown_37_2;
		s_tag_block_definition<s_unknown_38_block_definition> unknown_38_2;
		s_tag_block_definition<s_unknown_38_3_block_definition> unknown_38_4;
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		s_tag_block_definition<s_unknown_52_block_definition> unknown_52_2;
		s_tag_block_definition<s_unknown_53_block_definition> unknown_53_2;
		s_tag_block_definition<s_unknown_54_block_definition> unknown_54_2;
		s_tag_block_definition<s_unknown_39_block_definition> unknown_39_2;
		s_tag_block_definition<s_unknown_53_3_block_definition> unknown_53_4;
		s_tag_block_definition<s_unknown_41_block_definition> unknown_41_2;

		struct s_unknown_36_definition
		{
			unsigned int unknown;
			float unknown2;
			float unknown3;
			float unknown4;
			signed short unknown5;
			signed short unknown6;
			float unknown7;
			float unknown8;
			float unknown9;
			signed short unknown10;
			signed short unknown11;
		};

		struct s_unknown_37_definition
		{
			unsigned int unknown;
			float unknown2;
			float unknown3;
			float unknown4;
			signed short unknown5;
			signed short unknown6;
			float unknown7;
			float unknown8;
			float unknown9;
			signed short unknown10;
			signed short unknown11;
			float unknown12;
			float unknown13;
			float unknown14;
			signed short unknown15;
			signed short unknown16;
			float unknown17;
			float unknown18;
			float unknown19;
			signed short unknown20;
			signed short unknown21;
			signed short unknown22;
			signed short unknown23;
		};

		struct s_unknown_38_definition
		{
			signed short unknown;
			signed short unknown2;
			signed short unknown3;
			signed short unknown4;
		};

		struct s_unknown_38_definition
		{
			signed short unknown;
			signed short unknown2;
			signed short unknown3;
			signed short unknown4;
		};

		struct s_unknown_52_definition
		{
			struct s_unknown_53_block_definition;

			s_tag_block_definition<s_unknown_53_block_definition> unknown_53_2;

			struct s_unknown_53_definition
			{
				float unknown;
				float unknown2;
				float unknown3;
			};
		};

		struct s_unknown_53_definition
		{
			signed int unknown;
			float unknown2;
			float unknown3;
			float unknown4;
			float unknown5;
			float unknown6;
			float unknown7;
			float unknown8;
			float unknown9;
			signed short unknown10;
			signed short unknown11;
			signed int unknown12;
		};

		struct s_unknown_54_definition
		{
			struct s_unknown_55_block_definition;
			struct s_unknown_56_block_definition;

			string_id unknown;
			float unknown2;
			float unknown3;
			s_tag_block_definition<s_unknown_55_block_definition> unknown_55_2;
			signed short unknown4;
			signed short unknown5;
			s_tag_block_definition<s_unknown_56_block_definition> unknown_56_2;

			struct s_unknown_55_definition
			{
				unsigned int unknown;
				float unknown2;
				float unknown3;
				float unknown4;
				float unknown5;
				float unknown6;
				float unknown7;
				float unknown8;
			};

			struct s_unknown_56_definition
			{
				signed short unknown;
				signed short unknown2;
				unsigned int unknown3;
				unsigned int unknown4;
				unsigned int unknown5;
				unsigned int unknown6;
				unsigned int unknown7;
				unsigned int unknown8;
			};
		};

		struct s_unknown_39_definition
		{
			struct s_unknown_40_block_definition;

			s_tag_block_definition<s_unknown_40_block_definition> unknown_40_2;
			float unknown;
			float unknown2;

			struct s_unknown_40_definition
			{
				float unknown;
				float unknown2;
				float unknown3;
				signed short unknown4;
				signed short unknown5;
				float unknown6;
				float unknown7;
			};
		};

		struct s_unknown_53_definition
		{
			struct s_unknown_54_block_definition;

			s_tag_block_definition<s_unknown_54_block_definition> unknown_54_2;
			unsigned int unknown;
			unsigned int unknown2;
			unsigned int unknown3;

			struct s_unknown_54_definition
			{
				struct s_unknown_55_block_definition;

				s_tag_block_definition<s_unknown_55_block_definition> unknown_55_2;

				struct s_unknown_55_definition
				{
					unsigned int unknown;
					unsigned int unknown2;
					unsigned int unknown3;
					unsigned int unknown4;
					unsigned int unknown5;
					unsigned int unknown6;
				};
			};
		};

		struct s_unknown_41_definition
		{
			unsigned int unknown;
			unsigned int unknown2;
			unsigned int unknown3;
		};
	};

	struct s_script_definition
	{
		struct s_parameter_block_definition;

		string_id name;
		signed short script_type;
		signed short return_type;
		unsigned short root_expression_salt;
		unsigned short root_expression_index;
		s_tag_block_definition<s_parameter_block_definition> parameters;

		struct s_parameter_definition
		{
			char name[32];
			signed short type;
			signed short unknown;
		};
	};

	struct s_global_definition
	{
		char name[32];
		signed short type;
		signed short unknown;
		unsigned short initialization_expression_salt;
		unsigned short initialization_expression_index;
	};

	struct s_script_reference_definition
	{
		TagReference references;
	};

	struct s_scripting_datum_definition
	{
		struct s_point_set_block_definition;

		s_tag_block_definition<s_point_set_block_definition> point_sets;
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		unsigned int unknown16;
		unsigned int unknown17;
		unsigned int unknown18;
		unsigned int unknown19;
		unsigned int unknown20;
		unsigned int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		unsigned int unknown24;
		unsigned int unknown25;
		unsigned int unknown26;
		unsigned int unknown27;
		unsigned int unknown28;
		unsigned int unknown29;
		unsigned int unknown30;

		struct s_point_set_definition
		{
			struct s_point_block_definition;

			char name[32];
			s_tag_block_definition<s_point_block_definition> points;
			signed short bsp_index;
			signed short manual_reference_frame;
			signed int flags;
			signed short editor_folder_index;
			signed short unknown;

			struct s_point_definition
			{
				char name[32];
				string_id name2;
				float position_x;
				float position_y;
				float position_z;
				signed short reference_frame;
				signed short unknown;
				signed int surface_index;
				float facing_direction_y;
				float facing_direction_p;
			};
		};
	};

	struct s_cutscene_flag_definition
	{
		unsigned int unknown;
		string_id name;
		float position_x;
		float position_y;
		float position_z;
		float facing_y;
		float facing_p;
		signed short editor_folder_index;
		signed short unknown2;
	};

	struct s_cutscene_camera_point_definition
	{
		unsigned short flags;
		signed short type;
		char unknown[32];
		unsigned int unknown2;
		float position_x;
		float position_y;
		float position_z;
		float orientation_y;
		float orientation_p;
		float orientation_r;
	};

	struct s_cutscene_title_definition
	{
		string_id name;
		unsigned int unknown;
		float unknown2;
		float unknown3;
		float unknown4;
		signed short justification;
		signed short vertical_justification;
		signed short font;
		signed short unknown5;
		unsigned char text_color_a;
		unsigned char text_color_r;
		unsigned char text_color_g;
		unsigned char text_color_b;
		unsigned char shadow_color_a;
		unsigned char shadow_color_r;
		unsigned char shadow_color_g;
		unsigned char shadow_color_b;
		float fade_in_time;
		float uptime;
		float fade_out_time;
	};

	struct s_scenario_resource_definition
	{
		struct s_script_source_block_definition;
		struct s_ai_resource_block_definition;
		struct s_reference_block_definition;

		signed int unknown;
		s_tag_block_definition<s_script_source_block_definition> script_source2;
		s_tag_block_definition<s_ai_resource_block_definition> ai_resources;
		s_tag_block_definition<s_reference_block_definition> references;

		struct s_script_source_definition
		{
			TagReference hs_source_file;
		};

		struct s_ai_resource_definition
		{
			TagReference ai_resource2;
		};

		struct s_reference_definition
		{
			TagReference scenery_resource;
			TagReference bipeds_resource;
			TagReference vehicles_resource;
			TagReference equipment_resource;
			TagReference weapons_resource;
			TagReference sound_scenery_resource;
			TagReference lights_resource;
			TagReference devices_resource;
			TagReference effect_scenery_resource;
			TagReference decals_resource;
			TagReference cinematics_resource;
			TagReference trigger_volumes_resource;
			TagReference cluster_data_resource;
			TagReference comments_resource;
			TagReference creature_resource;
			TagReference structure_lighing_resource;
			TagReference decorators_resource;
			TagReference sky_references_resource;
			TagReference cubemap_resource;
			TagReference performances_resource;
			TagReference dumplings_resource;
		};
	};

	struct s_unit_seats_mapping_definition
	{
		unsigned int unit;
		signed int seats;
		signed int seats_2;
	};

	struct s_scenario_kill_trigger_definition
	{
		signed short trigger_volume;
		unsigned char flags;
		signed char unknown;
	};

	struct s_scenario_safe_trigger_definition
	{
		signed short trigger_volume;
		unsigned char flags;
		signed char unknown;
	};

	struct s_scenario_mopp_trigger_definition
	{
		struct s_mopp_code_block_definition;

		signed int unknown;
		s_tag_block_definition<s_mopp_code_block_definition> mopp_codes;

		struct s_mopp_code_definition
		{
			struct s_datum_block_definition;

			signed int unknown;
			unsigned int unknown2;
			signed short size;
			signed short count;
			signed int offset;
			unsigned int unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
			unsigned int unknown6;
			unsigned int unknown7;
			float offset_x;
			float offset_y;
			float offset_z;
			float offset_scale;
			unsigned int unknown8;
			unsigned int unknown9;
			signed int data_size;
			unsigned int data_capacity;
			unsigned int unknown10;
			unsigned int unknown11;
			unsigned int unknown12;
			unsigned int unknown13;
			s_tag_block_definition<s_datum_block_definition> data;
			unsigned int unknown14;

			struct s_datum_definition
			{
				unsigned char data_byte;
			};
		};
	};

	struct s_script_expression_definition
	{
		unsigned short salt;
		unsigned short opcode;
		signed short value_type;
		signed short expression_type;
		unsigned short next_expression_salt;
		unsigned short next_expression_index;
		unsigned int string_address;
		signed char value_03_msb;
		signed char value_02_byte;
		signed char value_01_byte;
		signed char value_00_lsb;
		signed short line_number;
		signed short unknown;
	};

	struct s_background_sound_environment_palette_definition
	{
		string_id name;
		TagReference sound_environment;
		signed int unknown;
		float cutoff_distance;
		float interpolation_speed;
		TagReference background_sound;
		TagReference inside_cluster_sound;
		TagReference transition_in;
		TagReference transition_out;
		float cutoff_distance2;
		signed int scale_flags;
		float interior_scale;
		float portal_scale;
		float exterior_scale;
		float interpolation_speed2;
	};

	struct s_fog_definition
	{
		string_id name;
		signed short unknown;
		signed short unknown2;
		TagReference fog2;
	};

	struct s_camera_fx_definition
	{
		string_id name;
		TagReference camera_fx2;
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
	};

	struct s_weather_definition
	{
		string_id name;
		TagReference weather2;
	};

	struct s_scenario_cluster_datum_definition
	{
		struct s_cluster_centroid_block_definition;
		struct s_background_sound_environment_block_definition;
		struct s_fog_block_definition;
		struct s_camera_fx_block_definition;
		struct s_weather_block_definition;

		TagReference bsp;
		signed int bsp_checksum;
		s_tag_block_definition<s_cluster_centroid_block_definition> cluster_centroids;
		signed int unknown;
		s_tag_block_definition<s_background_sound_environment_block_definition> background_sound_environments;
		s_tag_block_definition<s_fog_block_definition> fog2;
		s_tag_block_definition<s_camera_fx_block_definition> camera_fx2;
		s_tag_block_definition<s_weather_block_definition> weather2;

		struct s_cluster_centroid_definition
		{
			float centroid_x;
			float centroid_y;
			float centroid_z;
		};

		struct s_background_sound_environment_definition
		{
			signed short background_sound_environment_index;
			signed short unknown;
		};

		struct s_fog_definition
		{
			signed short fog_index;
			signed short unknown;
		};

		struct s_camera_fx_definition
		{
			signed short camera_fx_index;
			signed short unknown;
		};

		struct s_weather_definition
		{
			signed short weather_index;
			signed short unknown;
		};
	};

	struct s_spawn_datum_definition
	{
		float unknown;
	};

	struct s_crate_definition
	{
		struct s_node_positioning_block_definition;
		struct s_unknown14_block_definition;

		signed short palette_index;
		signed short name_index;
		signed int placement_flags;
		float position_x;
		float position_y;
		float position_z;
		float rotation_i;
		float rotation_j;
		float rotation_k;
		float scale;
		s_tag_block_definition<s_node_positioning_block_definition> node_positioning2;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char bsp_policy;
		unsigned short old_manual_bsp_flags_now_zonesets;
		signed short unknown4;
		string_id unique_name;
		unsigned short unique_id_salt;
		unsigned short unique_id_index;
		signed short origin_bsp_index;
		signed char type;
		signed char source;
		signed short editor_folder_index;
		signed short unknown5;
		signed short unknown6;
		signed short parent_name_index;
		string_id child_name;
		string_id unknown7;
		unsigned short allowed_zonesets;
		signed short unknown8;
		string_id variant;
		signed short unknown9;
		unsigned char active_change_colors;
		signed char unknown10;
		signed char unknown11;
		signed char unknown12;
		unsigned char primary_color_a;
		unsigned char primary_color_r;
		unsigned char primary_color_g;
		unsigned char primary_color_b;
		unsigned char secondary_color_a;
		unsigned char secondary_color_r;
		unsigned char secondary_color_g;
		unsigned char secondary_color_b;
		unsigned char tertiary_color_a;
		unsigned char tertiary_color_r;
		unsigned char tertiary_color_g;
		unsigned char tertiary_color_b;
		unsigned char quaternary_color_a;
		unsigned char quaternary_color_r;
		unsigned char quaternary_color_g;
		unsigned char quaternary_color_b;
		unsigned int unknown13;
		s_tag_block_definition<s_unknown14_block_definition> unknown15;
		char custom_label[32];
		signed int symmetry;
		signed char unknown16;
		signed char team;
		signed short unknown17;
		signed char spawn_sequence;
		signed char runtime_minimum;
		signed char runtime_maximum;
		unsigned char multiplayer_flags;
		signed short spawn_time;
		signed short abandon_time;
		float shape_width_radius;
		float shape_length;
		float shape_top;
		float shape_bottom;
		signed char shape;
		signed char unknown18;
		unsigned char teleporter_channel;
		unsigned char teleporter_flags;
		string_id location_string;
		signed short unknown19;
		signed short attached_name_index;
		unsigned int unknown20;
		unsigned int unknown21;
		unsigned int unknown22;

		struct s_node_positioning_definition
		{
			struct s_node_flag_block_definition;
			struct s_orientation_block_definition;
			struct s_node_flags_readable_block_definition;
			struct s_orientations_readable_block_definition;

			signed short node_count;
			signed short unknown;
			s_tag_block_definition<s_node_flag_block_definition> node_flags;
			s_tag_block_definition<s_orientation_block_definition> orientations;
			s_tag_block_definition<s_node_flags_readable_block_definition> node_flags_readable2;
			s_tag_block_definition<s_orientations_readable_block_definition> orientations_readable2;

			struct s_node_flag_definition
			{
				unsigned char flags;
			};

			struct s_orientation_definition
			{
				signed short rotation_x,_y,_z,_w;
			};

			struct s_node_flags_readable_definition
			{
				unsigned char flags;
				unsigned char flags2;
				unsigned char flags3;
				unsigned char flags4;
			};

			struct s_orientations_readable_definition
			{
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
			};
		};

		struct s_unknown_definition
		{
			unsigned int unknown2;
		};
	};

	struct s_crate_palette_definition
	{
		TagReference crate;
	};

	struct s_flock_palette_definition
	{
		TagReference flock;
	};

	struct s_flock_definition
	{
		struct s_source_block_definition;
		struct s_sink_block_definition;

		string_id name;
		signed short flock_palette_index;
		signed short bsp_index;
		signed short bounding_trigger_volume;
		signed short unknown;
		float unknown2;
		s_tag_block_definition<s_source_block_definition> sources;
		s_tag_block_definition<s_sink_block_definition> sinks;
		float production_frequency_min;
		float production_frequency_max;
		float scale_min;
		float scale_max;
		float unknown3;
		float unknown4;
		float unknown5;
		signed short creature_palette_index;
		signed short unknown6;
		signed short boid_count_min;
		signed short boid_count_max;
		signed short unknown7;
		signed short unknown8;
		float unknown9;

		struct s_source_definition
		{
			string_id name;
			signed int unknown;
			float position_x;
			float position_y;
			float position_z;
			float starting_y;
			float starting_p;
			float radius;
			float weight;
			signed char unknown2;
			signed char unknown3;
			signed char unknown4;
			signed char unknown5;
		};

		struct s_sink_definition
		{
			string_id name;
			unsigned int unknown;
			float position_x;
			float position_y;
			float position_z;
			float radius;
			unsigned int unknown2;
			signed short unknown3;
			signed short unknown4;
		};
	};

	struct s_creature_palette_definition
	{
		TagReference creature;
	};

	struct s_big_battle_creature_definition
	{
		TagReference big_battle_creature2;
	};

	struct s_editor_folder_definition
	{
		signed int parent_folder;
		char name[256];
	};

	struct s_mission_dialogue_definition
	{
		TagReference mission_dialogue2;
	};

	struct s_unknown_59_definition
	{
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		signed short unknown5;
		signed short unknown6;
		signed short unknown7;
		signed short unknown8;
		signed short unknown9;
		signed short unknown10;
	};

	struct s_ai_objective_definition
	{
		struct s_unknown_78_block_definition;
		struct s_role_block_definition;

		string_id name;
		s_tag_block_definition<s_unknown_78_block_definition> unknown_78_2;
		signed short unknown;
		signed short zone;
		signed short unknown2;
		signed short editor_folder_index;
		s_tag_block_definition<s_role_block_definition> roles;

		struct s_unknown_78_definition
		{
			unsigned int unknown;
		};

		struct s_role_definition
		{
			struct s_condition_block_definition;
			struct s_unknown_63_block_definition;
			struct s_point_geometry_block_definition;

			signed short unknown;
			signed short unknown2;
			signed short unknown3;
			signed short unknown4;
			signed short unknown5;
			signed short unknown6;
			float unknown7;
			float unknown8;
			signed short unknown9;
			signed short unknown10;
			unsigned int unknown11;
			unsigned int unknown12;
			unsigned int unknown13;
			string_id command_script_name_1;
			string_id command_script_name_2;
			string_id command_script_name_3;
			signed short command_script_index_1;
			signed short command_script_index_2;
			signed short command_script_index_3;
			signed short unknown14;
			signed short unknown15;
			signed short unknown16;
			signed short unknown17;
			signed short unknown18;
			string_id task;
			signed short hierarchy_level_from_100;
			signed short previous_role;
			signed short next_role;
			signed short parent_role;
			s_tag_block_definition<s_condition_block_definition> conditions;
			signed short script_index;
			signed short unknown19;
			signed short unknown20;
			signed short filter;
			signed short min;
			signed short max;
			signed short bodies;
			signed short unknown21;
			unsigned int unknown22;
			s_tag_block_definition<s_unknown_63_block_definition> unknown_63_2;
			s_tag_block_definition<s_point_geometry_block_definition> point_geometry2;

			struct s_condition_definition
			{
				string_id name;
				char condition2[32];
				signed short unknown;
				signed short unknown2;
			};

			struct s_unknown_63_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short unknown3;
				signed short unknown4;
				float unknown5;
				signed short unknown6;
				signed short unknown7;
				unsigned int unknown8;
				unsigned int unknown9;
				unsigned int unknown10;
			};

			struct s_point_geometry_definition
			{
				struct s_point_block_definition;

				s_tag_block_definition<s_point_block_definition> points;

				struct s_point_definition
				{
					float point_x;
					float point_y;
					float point_z;
					signed short reference_frame;
					signed short unknown;
				};
			};
		};
	};

	struct s_designer_zoneset_definition
	{
		struct s_biped_block_definition;
		struct s_vehicle_block_definition;
		struct s_weapon_block_definition;
		struct s_equipment_block_definition;
		struct s_scenery_block_definition;
		struct s_machine_block_definition;
		struct s_terminal_block_definition;
		struct s_control_block_definition;
		struct s_unknown2_block_definition;
		struct s_crate_block_definition;
		struct s_creature_block_definition;
		struct s_giant_block_definition;
		struct s_unknown4_block_definition;
		struct s_character_block_definition;

		string_id name;
		unsigned int unknown;
		s_tag_block_definition<s_biped_block_definition> bipeds;
		s_tag_block_definition<s_vehicle_block_definition> vehicles;
		s_tag_block_definition<s_weapon_block_definition> weapons;
		s_tag_block_definition<s_equipment_block_definition> equipment2;
		s_tag_block_definition<s_scenery_block_definition> scenery2;
		s_tag_block_definition<s_machine_block_definition> machines;
		s_tag_block_definition<s_terminal_block_definition> terminals;
		s_tag_block_definition<s_control_block_definition> controls;
		s_tag_block_definition<s_unknown2_block_definition> unknown3;
		s_tag_block_definition<s_crate_block_definition> crates;
		s_tag_block_definition<s_creature_block_definition> creatures;
		s_tag_block_definition<s_giant_block_definition> giants;
		s_tag_block_definition<s_unknown4_block_definition> unknown5;
		s_tag_block_definition<s_character_block_definition> characters;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;

		struct s_biped_definition
		{
			signed short palette_index;
		};

		struct s_vehicle_definition
		{
			signed short palette_index;
		};

		struct s_weapon_definition
		{
			signed short palette_index;
		};

		struct s_equipment_definition
		{
			signed short palette_index;
		};

		struct s_scenery_definition
		{
			signed short palette_index;
		};

		struct s_machine_definition
		{
			signed short palette_index;
		};

		struct s_terminal_definition
		{
			signed short palette_index;
		};

		struct s_control_definition
		{
			signed short palette_index;
		};

		struct s_unknown_definition
		{
			signed short palette_index;
		};

		struct s_crate_definition
		{
			signed short palette_index;
		};

		struct s_creature_definition
		{
			signed short palette_index;
		};

		struct s_giant_definition
		{
			signed short palette_index;
		};

		struct s_unknown_definition
		{
			signed short palette_index;
		};

		struct s_character_definition
		{
			signed short palette_index;
		};
	};

	struct s_unknown_61_definition
	{
		signed short unknown;
		signed short unknown2;
	};

	struct s_particle_emitter_definition
	{
		TagReference emitter;
	};

	struct s_unknown_definition
	{
		unsigned int unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
	};

	struct s_cinematic_definition
	{
		string_id name;
		TagReference cinematic2;
	};

	struct s_cinematic_light_definition
	{
		string_id name;
		TagReference light;
	};

	struct s_scenario_metagame_definition
	{
		struct s_time_multiplier_block_definition;

		float par_score;
		s_tag_block_definition<s_time_multiplier_block_definition> time_multipliers;

		struct s_time_multiplier_definition
		{
			float time;
			float multiplier;
		};
	};

	struct s_unknown_64_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
	};

	struct s_unknown_65_definition
	{
		struct s_unknown_85_block_definition;

		string_id unknown;
		float unknown2;
		float unknown3;
		float unknown4;
		signed short unknown5;
		signed short unknown6;
		s_tag_block_definition<s_unknown_85_block_definition> unknown_85_2;

		struct s_unknown_85_definition
		{
			float unknown;
			float unknown2;
			float unknown3;
			unsigned int unknown4;
		};
	};

	struct s_vignette_definition
	{
		struct s_unknown_86_block_definition;
		struct s_unknown_87_block_definition;
		struct s_unknown_85_block_definition;

		string_id unknown;
		string_id unknown2;
		string_id unknown3;
		signed short unknown4;
		signed short unknown5;
		signed short unknown6;
		signed short unknown7;
		s_tag_block_definition<s_unknown_86_block_definition> unknown_86_2;
		s_tag_block_definition<s_unknown_87_block_definition> unknown_87_2;
		float x;
		float y;
		float z;
		float yaw;
		float pitch;
		float unknown8;
		float unknown9;
		float unknown10;
		string_id performane_template_name;
		unsigned int performance_template;
		s_tag_block_definition<s_unknown_85_block_definition> unknown_85_2;

		struct s_unknown_86_definition
		{
			signed int unknown;
			string_id unknown2;
			signed short unknown3;
			signed short unknown4;
			signed short unknown5;
			signed short unknown6;
			signed int unknown7;
		};

		struct s_unknown_87_definition
		{
			struct s_script_block_definition;
			struct s_unknown_89_block_definition;
			struct s_animation_block_definition;
			struct s_unknown_88_block_definition;
			struct s_unknown_91_block_definition;

			string_id unknown;
			signed short unknown2;
			signed short unknown3;
			signed short unknown4;
			signed short unknown5;
			signed int unknown6;
			s_tag_block_definition<s_script_block_definition> script2;
			s_tag_block_definition<s_unknown_89_block_definition> unknown_89_2;
			s_tag_block_definition<s_animation_block_definition> animation2;
			s_tag_block_definition<s_unknown_88_block_definition> unknown_88_2;
			unsigned int zunknown;
			unsigned int zunknown2;
			unsigned int zunknown3;
			s_tag_block_definition<s_unknown_91_block_definition> unknown_91_2;
			unsigned int zunknown4;
			unsigned int zunknown5;
			unsigned int zunknown6;

			struct s_script_definition
			{
				signed short unknown;
				signed short unknown2;
				char script2[512];
			};

			struct s_unknown_89_definition
			{
				signed int unknown;
				signed short unknown2;
				signed short unknown3;
				signed int unknown4;
				signed int unknown5;
			};

			struct s_animation_definition
			{
				signed short unknown;
				signed short unknown2;
				signed short unknown3;
				signed short unknown4;
				string_id animation2;
				unsigned int zunknown;
				float unknown5;
				unsigned int zunknown2;
				unsigned int zunknown3;
			};

			struct s_unknown_88_definition
			{
				string_id unknown;
				float unknown2;
				signed short unknown3;
				signed short unknown4;
				unsigned int zunknown;
				unsigned int zunknown2;
				unsigned int zunknown3;
			};

			struct s_unknown_91_definition
			{
				signed int unknown;
				float unknown2;
			};
		};

		struct s_unknown_85_definition
		{
			signed short unknown;
			signed short unknown2;
		};
	};

	struct s_unknown_66_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
	};

	struct s_compiled_datum_definition
	{
		unsigned int effe_compiled_data_pointer;
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int beam_compiled_data_pointer;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int cntl_compiled_data_pointer;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int ltvl_compiled_data_pointer;
		unsigned int unknown7;
		unsigned int unknown8;
	};
};
