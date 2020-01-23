#pragma once

struct s_globals_definition
{
	struct s_havok_cleanup_resource_block_definition;
	struct s_sound_global_block_definition;
	struct s_ai_global_block_definition;
	struct s_damage_table_block_definition;
	struct s_sound_block_definition;
	struct s_camera_block_definition;
	struct s_thumbstick_deadzone_block_definition;
	struct s_player_control_block_definition;
	struct s_player_trait_default_block_definition;
	struct s_difficulty_block_definition;
	struct s_unknown45_block_definition;
	struct s_grenade_block_definition;
	struct s_soft_barrier_property_block_definition;
	struct s_interface_tag_block_definition;
	struct s_player_information_block_definition;
	struct s_player_representation_block_definition;
	struct s_falling_damage_block_definition;
	struct s_unknown56_block_definition;
	struct s_material_block_definition;
	struct s_player_color_block_definition;
	struct s_emblem_color_block_definition;
	struct s_visor_color_block_definition;
	struct s_forge_color_block_definition;
	struct s_cinematic_anchor_block_definition;
	struct s_metagame_global_block_definition;
	struct s_unknown130_block_definition;
	struct s_unknown132_block_definition;
	struct s_unknown134_block_definition;
	struct s_alt_material_block_definition;

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
	unsigned int unknown31;
	unsigned int unknown32;
	unsigned int unknown33;
	unsigned int unknown34;
	unsigned int unknown35;
	unsigned int unknown36;
	unsigned int unknown37;
	unsigned int unknown38;
	unsigned int unknown39;
	unsigned int unknown40;
	unsigned int unknown41;
	unsigned int unknown42;
	unsigned int unknown43;
	signed int language;
	s_tag_block_definition<s_havok_cleanup_resource_block_definition> havok_cleanup_resources;
	s_tag_block_definition<s_sound_global_block_definition> sound_globals;
	s_tag_block_definition<s_ai_global_block_definition> ai_globals;
	TagReference ai_globals2;
	s_tag_block_definition<s_damage_table_block_definition> damage_table2;
	TagReference unknown44;
	s_tag_block_definition<s_sound_block_definition> sounds;
	s_tag_block_definition<s_camera_block_definition> camera2;
	s_tag_block_definition<s_thumbstick_deadzone_block_definition> thumbstick_deadzones;
	s_tag_block_definition<s_player_control_block_definition> player_control2;
	s_tag_block_definition<s_player_trait_default_block_definition> player_trait_defaults;
	s_tag_block_definition<s_difficulty_block_definition> difficulty2;
	s_tag_block_definition<s_unknown45_block_definition> unknown46;
	s_tag_block_definition<s_grenade_block_definition> grenades;
	s_tag_block_definition<s_soft_barrier_property_block_definition> soft_barrier_properties;
	unsigned int unknown47;
	unsigned int unknown48;
	unsigned int unknown49;
	s_tag_block_definition<s_interface_tag_block_definition> interface_tags;
	unsigned int unknown50;
	unsigned int unknown51;
	unsigned int unknown52;
	unsigned int unknown53;
	unsigned int unknown54;
	unsigned int unknown55;
	s_tag_block_definition<s_player_information_block_definition> player_information2;
	s_tag_block_definition<s_player_representation_block_definition> player_representation2;
	s_tag_block_definition<s_falling_damage_block_definition> falling_damage2;
	s_tag_block_definition<s_unknown56_block_definition> unknown57;
	s_tag_block_definition<s_material_block_definition> materials;
	s_tag_block_definition<s_player_color_block_definition> player_colors;
	s_tag_block_definition<s_emblem_color_block_definition> emblem_colors;
	s_tag_block_definition<s_visor_color_block_definition> visor_colors;
	float elite_armor_shine_r;
	float elite_armor_shine_g;
	float elite_armor_shine_b;
	float elite_armor_color_r;
	float elite_armor_color_g;
	float elite_armor_color_b;
	s_tag_block_definition<s_forge_color_block_definition> forge_colors;
	TagReference game_engine_globals;
	TagReference multiplayer_globals;
	TagReference survival_globals;
	TagReference object_type_list;
	s_tag_block_definition<s_cinematic_anchor_block_definition> cinematic_anchors;
	s_tag_block_definition<s_metagame_global_block_definition> metagame_globals;
	TagReference medal_globals;
	unsigned int unknown58;
	unsigned int unknown59;
	unsigned int unknown60;
	unsigned int unknown61;
	unsigned int string_count;
	unsigned int locale_table_size;
	unsigned int locale_index_table_offset;
	unsigned int locale_data_index_offset;
	unsigned char index_table_hash[20];
	unsigned char string_data_hash[20];
	unsigned int unknown62;
	unsigned int unknown63;
	unsigned int unknown64;
	unsigned int unknown65;
	unsigned int unknown66;
	unsigned int unknown67;
	unsigned int string_count2;
	unsigned int locale_table_size2;
	unsigned int locale_index_table_offset2;
	unsigned int locale_data_index_offset2;
	unsigned char index_table_hash2[20];
	unsigned char string_data_hash2[20];
	unsigned int unknown68;
	unsigned int unknown69;
	unsigned int unknown70;
	unsigned int unknown71;
	unsigned int unknown72;
	unsigned int unknown73;
	unsigned int string_count3;
	unsigned int locale_table_size3;
	unsigned int locale_index_table_offset3;
	unsigned int locale_data_index_offset3;
	unsigned char index_table_hash3[20];
	unsigned char string_data_hash3[20];
	unsigned int unknown74;
	unsigned int unknown75;
	unsigned int unknown76;
	unsigned int unknown77;
	unsigned int unknown78;
	unsigned int unknown79;
	unsigned int string_count4;
	unsigned int locale_table_size4;
	unsigned int locale_index_table_offset4;
	unsigned int locale_data_index_offset4;
	unsigned char index_table_hash4[20];
	unsigned char string_data_hash4[20];
	unsigned int unknown80;
	unsigned int unknown81;
	unsigned int unknown82;
	unsigned int unknown83;
	unsigned int unknown84;
	unsigned int unknown85;
	unsigned int string_count5;
	unsigned int locale_table_size5;
	unsigned int locale_index_table_offset5;
	unsigned int locale_data_index_offset5;
	unsigned char index_table_hash5[20];
	unsigned char string_data_hash5[20];
	unsigned int unknown86;
	unsigned int unknown87;
	unsigned int unknown88;
	unsigned int unknown89;
	unsigned int unknown90;
	unsigned int unknown91;
	unsigned int string_count6;
	unsigned int locale_table_size6;
	unsigned int locale_index_table_offset6;
	unsigned int locale_data_index_offset6;
	unsigned char index_table_hash6[20];
	unsigned char string_data_hash6[20];
	unsigned int unknown92;
	unsigned int unknown93;
	unsigned int unknown94;
	unsigned int unknown95;
	unsigned int unknown96;
	unsigned int unknown97;
	unsigned int string_count7;
	unsigned int locale_table_size7;
	unsigned int locale_index_table_offset7;
	unsigned int locale_data_index_offset7;
	unsigned char index_table_hash7[20];
	unsigned char string_data_hash7[20];
	unsigned int unknown98;
	unsigned int unknown99;
	unsigned int unknown100;
	unsigned int unknown101;
	unsigned int unknown102;
	unsigned int unknown103;
	unsigned int string_count8;
	unsigned int locale_table_size8;
	unsigned int locale_index_table_offset8;
	unsigned int locale_data_index_offset8;
	unsigned char index_table_hash8[20];
	unsigned char string_data_hash8[20];
	unsigned int unknown104;
	unsigned int unknown105;
	unsigned int unknown106;
	unsigned int unknown107;
	unsigned int unknown108;
	unsigned int unknown109;
	unsigned int string_count9;
	unsigned int locale_table_size9;
	unsigned int locale_index_table_offset9;
	unsigned int locale_data_index_offset9;
	unsigned char index_table_hash9[20];
	unsigned char string_data_hash9[20];
	unsigned int unknown110;
	unsigned int unknown111;
	unsigned int unknown112;
	unsigned int unknown113;
	unsigned int unknown114;
	unsigned int unknown115;
	unsigned int string_count10;
	unsigned int locale_table_size10;
	unsigned int locale_index_table_offset10;
	unsigned int locale_data_index_offset10;
	unsigned char index_table_hash10[20];
	unsigned char string_data_hash10[20];
	unsigned int unknown116;
	unsigned int unknown117;
	unsigned int unknown118;
	unsigned int unknown119;
	unsigned int unknown120;
	unsigned int unknown121;
	unsigned int string_count11;
	unsigned int locale_table_size11;
	unsigned int locale_index_table_offset11;
	unsigned int locale_data_index_offset11;
	unsigned char index_table_hash11[20];
	unsigned char string_data_hash11[20];
	unsigned int unknown122;
	unsigned int unknown123;
	unsigned int unknown124;
	unsigned int unknown125;
	unsigned int unknown126;
	unsigned int unknown127;
	unsigned int string_count12;
	unsigned int locale_table_size12;
	unsigned int locale_index_table_offset12;
	unsigned int locale_data_index_offset12;
	unsigned char index_table_hash12[20];
	unsigned char string_data_hash12[20];
	unsigned int unknown128;
	unsigned int unknown129;
	TagReference rasterizer_globals;
	TagReference default_camera_effect;
	TagReference default_wind;
	TagReference weather_globals;
	TagReference default_damage_effect;
	TagReference default_collision_damage;
	string_id unknown_material;
	string_id unknown_material_2;
	signed short unknown_global_material_index;
	signed short unknown_2_global_material_index;
	TagReference effect_globals;
	TagReference collision_filter;
	TagReference grounded_friction;
	s_tag_block_definition<s_unknown130_block_definition> unknown131;
	TagReference incident_globals;
	TagReference player_grade_globals;
	TagReference player_customization_gobals;
	TagReference loadout_globals;
	TagReference challenge_gloabls;
	TagReference reward_globals;
	TagReference achievement_globals;
	TagReference avatar_award_globals;
	TagReference performance_throttle_globals;
	s_tag_block_definition<s_unknown132_block_definition> unknown133;
	s_tag_block_definition<s_unknown134_block_definition> unknown135;
	unsigned int unknown136;
	s_tag_block_definition<s_alt_material_block_definition> alt_materials;

	struct s_havok_cleanup_resource_definition
	{
		TagReference object_cleanup_effect;
	};

	struct s_sound_global_definition
	{
		struct s_fireteam_sound_block_definition;

		TagReference sound_classes;
		TagReference sound_effects;
		TagReference sound_mastering;
		TagReference sound_mix;
		TagReference sound_combat_dialogue_constants;
		TagReference sound_global_propagation;
		s_tag_block_definition<s_fireteam_sound_block_definition> fireteam_sounds;

		struct s_fireteam_sound_definition
		{
			TagReference sound;
		};
	};

	struct s_ai_global_definition
	{
		struct s_gravemind_property_block_definition;
		struct s_formation_block_definition;
		struct s_squad_template_block_definition;
		struct s_performance_template_block_definition;
		struct s_unknown23_block_definition;
		struct s_vision_trait_definition_block_definition;
		struct s_hearing_trait_definition_block_definition;
		struct s_luck_trait_definition_block_definition;
		struct s_grenade_trait_definition_block_definition;

		float unknown;
		float unknown2;
		float unknown3;
		float danger_broadly_facing;
		float danger_shooting_near;
		float danger_shooting_at;
		float danger_extremely_close;
		float danger_shield_damage;
		float danger_extended_shield_damage;
		float danger_body_damage;
		float danger_extended_body_damage;
		TagReference global_dialogue;
		string_id default_mission_dialogue_sound_effect;
		float jump_down;
		float jump_step;
		float jump_crouch;
		float jump_stand;
		float jump_storey;
		float jump_tower;
		float unknown4;
		float max_jump_down_height_down;
		float max_jump_down_height_step;
		float max_jump_down_height_crouch;
		float max_jump_down_height_stand;
		float max_jump_down_height_storey;
		float max_jump_down_height_tower;
		float unknown5;
		float hoist_step_min;
		float hoist_step_max;
		float hoist_crouch_min;
		float hoist_crouch_max;
		float hoist_stand_min;
		float hoist_stand_max;
		float vault_step_min;
		float vault_step_max;
		float vault_crouch_min;
		float vault_crouch_max;
		float unknown6;
		float unknown7;
		float unknown8;
		float unknown9;
		s_tag_block_definition<s_gravemind_property_block_definition> gravemind_properties;
		float scary_target_threshold;
		float scary_weapon_threshold;
		float unknown10;
		float unknown11;
		float unknown12;
		float unknown13;
		float unknown14;
		float unknown15;
		float unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
		s_tag_block_definition<s_formation_block_definition> formations;
		s_tag_block_definition<s_squad_template_block_definition> squad_templates;
		s_tag_block_definition<s_performance_template_block_definition> performance_templates;
		unsigned int unknown20;
		unsigned int unknown21;
		unsigned int unknown22;
		s_tag_block_definition<s_unknown23_block_definition> unknown24;
		unsigned int unknown25;
		unsigned int unknown26;
		unsigned int unknown27;
		unsigned int unknown28;
		unsigned int unknown29;
		unsigned int unknown30;
		unsigned int unknown31;
		unsigned int unknown32;
		unsigned int unknown33;
		unsigned int unknown34;
		unsigned int unknown35;
		unsigned int unknown36;
		unsigned int unknown37;
		unsigned int unknown38;
		signed short unknown39;
		signed short unknown40;
		signed short unknown41;
		signed short unknown42;
		signed short unknown43;
		signed short unknown44;
		s_tag_block_definition<s_vision_trait_definition_block_definition> vision_trait_definitions;
		s_tag_block_definition<s_hearing_trait_definition_block_definition> hearing_trait_definitions;
		s_tag_block_definition<s_luck_trait_definition_block_definition> luck_trait_definitions;
		s_tag_block_definition<s_grenade_trait_definition_block_definition> grenade_trait_definitions;
		unsigned int unknown45;
		unsigned int unknown46;
		unsigned int unknown47;
		signed short unknown48;
		signed short unknown49;
		signed short unknown50;
		signed short unknown51;

		struct s_gravemind_property_definition
		{
			float minimum_retreat_time;
			float ideal_retreat_time;
			float maximum_retreat_time;
		};

		struct s_formation_definition
		{
			TagReference formation2;
		};

		struct s_squad_template_definition
		{
			struct s_template_block_definition;

			string_id name;
			unsigned int unknown;
			unsigned int unknown2;
			unsigned int unknown3;
			s_tag_block_definition<s_template_block_definition> templates;

			struct s_template_definition
			{
				TagReference template2;
			};
		};

		struct s_performance_template_definition
		{
			struct s_character_block_definition;

			string_id name;
			s_tag_block_definition<s_character_block_definition> characters;
			unsigned int unknown;
			unsigned int unknown2;
			unsigned int unknown3;

			struct s_character_definition
			{
				struct s_template_block_definition;

				string_id name;
				s_tag_block_definition<s_template_block_definition> templates;

				struct s_template_definition
				{
					TagReference template2;
				};
			};
		};

		struct s_unknown_definition
		{
			struct s_unknown3_block_definition;
			struct s_unknown5_block_definition;
			struct s_unknown7_block_definition;

			string_id unknown2;
			s_tag_block_definition<s_unknown3_block_definition> unknown4;
			s_tag_block_definition<s_unknown5_block_definition> unknown6;
			s_tag_block_definition<s_unknown7_block_definition> unknown8;

			struct s_unknown_definition
			{
				float unknown2;
			};

			struct s_unknown_definition
			{
				string_id unknown2;
			};

			struct s_unknown_definition
			{
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
			};
		};

		struct s_vision_trait_definition_definition
		{
			float unknown;
			float unknown2;
		};

		struct s_hearing_trait_definition_definition
		{
			float unknown;
		};

		struct s_luck_trait_definition_definition
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
		};

		struct s_grenade_trait_definition_definition
		{
			float unknown;
			float unknown2;
			float unknown3;
			float unknown4;
			float unknown5;
			float unknown6;
			float unknown7;
		};
	};

	struct s_damage_table_definition
	{
		struct s_damage_group_block_definition;

		s_tag_block_definition<s_damage_group_block_definition> damage_groups;

		struct s_damage_group_definition
		{
			struct s_armor_modifier_block_definition;

			string_id name;
			s_tag_block_definition<s_armor_modifier_block_definition> armor_modifiers;

			struct s_armor_modifier_definition
			{
				string_id name;
				float damage_multiplier;
			};
		};
	};

	struct s_sound_definition
	{
		TagReference sound_obsolete;
	};

	struct s_camera_definition
	{
		TagReference default_unit_track;
		DataReference unknown;
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
		float unknown14;
		float unknown15;
		float unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
		float unknown20;
		float unknown21;
		float unknown22;
		float unknown23;
		float unknown24;
		float unknown25;
		float unknown26;
		float unknown27;
		signed short unknown28;
		signed short unknown29;
		float unknown30;
		float unknown31;
		float unknown32;
		float unknown33;
		float unknown34;
		float unknown35;
		float unknown36;
		float unknown37;
		float unknown38;
		float unknown39;
		float unknown40;
		float unknown41;
		float unknown42;
		float unknown43;
		float unknown44;
		float unknown45;
		float unknown46;
		float unknown47;
	};

	struct s_thumbstick_deadzone_definition
	{
		float minimum;
		float maximum;
	};

	struct s_player_control_definition
	{
		struct s_unknown_block_definition;
		struct s_unknown3_block_definition;

		s_tag_block_definition<s_unknown_block_definition> unknown2;
		s_tag_block_definition<s_unknown3_block_definition> unknown4;
		float magnetism_friction;
		float magnetism_adhesion;
		float inconsequential_target_scale;
		float crosshair_location_x;
		float crosshair_location_y;
		float unknown5;
		float unknown6;
		float unknown7;
		float look_autoleveling_scale;
		float gravity_scale;
		signed int minimum_autoleveling_ticks;
		float minimum_angle_for_vehicle_flipping;
		float minimum_action_hold_time;
		unsigned int unknown8;
		signed int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		float unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
		float unknown20;
		float unknown21;
		float unknown22;
		unsigned int unknown23;

		struct s_unknown_definition
		{
			struct s_unknown12_block_definition;

			signed char unknown2;
			signed char unknown3;
			signed char unknown4;
			signed char unknown5;
			float unknown6;
			float unknown7;
			float unknown8;
			float unknown9;
			float unknown10;
			float unknown11;
			s_tag_block_definition<s_unknown12_block_definition> unknown13;

			struct s_unknown_definition
			{
				DataReference unknown2;
			};
		};

		struct s_unknown_definition
		{
			struct s_unknown12_block_definition;

			signed char unknown2;
			signed char unknown3;
			signed char unknown4;
			signed char unknown5;
			float unknown6;
			float unknown7;
			float unknown8;
			float unknown9;
			float unknown10;
			float unknown11;
			s_tag_block_definition<s_unknown12_block_definition> unknown13;

			struct s_unknown_definition
			{
				DataReference unknown2;
			};
		};
	};

	struct s_player_trait_default_definition
	{
		struct s_shields_and_health_block_definition;
		struct s_weapons_and_damage_block_definition;
		struct s_movement_block_definition;
		struct s_appearance_block_definition;
		struct s_hud_block_definition;

		s_tag_block_definition<s_shields_and_health_block_definition> shields_and_health2;
		s_tag_block_definition<s_weapons_and_damage_block_definition> weapons_and_damage2;
		s_tag_block_definition<s_movement_block_definition> movement2;
		s_tag_block_definition<s_appearance_block_definition> appearance2;
		s_tag_block_definition<s_hud_block_definition> hud2;

		struct s_shields_and_health_definition
		{
			signed char damage_resistance;
			signed char health_multiplier;
			signed char health_recharge_rate;
			signed char shield_multiplier;
			signed char shield_recharge_rate;
			signed char shield_recharge_rate_2;
			signed char headshot_immunity;
			signed char shield_vampirism;
			signed char assassination_immunity;
			signed char deathless;
			signed char unknown;
			signed char unknown2;
		};

		struct s_weapons_and_damage_definition
		{
			signed char damage_modifier;
			signed char melee_damage_modifier;
			signed char grenade_regeneration;
			signed char weapon_pickup;
			signed char grenade_count;
			signed char infinite_ammo;
			signed char equipment_usage;
			signed char equipment_drop;
			signed char infinite_equipment;
			signed char unknown;
			signed char unknown2;
			signed char unknown3;
			string_id primary_weapon;
			string_id secondary_weapon;
			string_id equipment;
		};

		struct s_movement_definition
		{
			signed char player_speed;
			signed char player_gravity;
			signed char vehicle_use;
			signed char double_jump;
			signed int jump_height;
		};

		struct s_appearance_definition
		{
			signed char active_camo;
			signed char waypoint;
			signed char visible_name;
			signed char aura;
			signed char forced_color;
			signed char unknown;
			signed char unknown2;
			signed char unknown3;
		};

		struct s_hud_definition
		{
			signed char motion_tracker_mode;
			signed char motion_tracker_range;
			signed char directional_damage_indicator;
			signed char unknown;
		};
	};

	struct s_difficulty_definition
	{
		float easy_enemy_damage;
		float normal_enemy_damage;
		float hard_enemy_damage;
		float impossible_enemy_damage;
		float easy_enemy_vitality;
		float normal_enemy_vitality;
		float hard_enemy_vitality;
		float impossible_enemy_vitality;
		float easy_enemy_shield;
		float normal_enemy_shield;
		float hard_enemy_shield;
		float impossible_enemy_shield;
		float easy_enemy_recharge;
		float normal_enemy_recharge;
		float hard_enemy_recharge;
		float impossible_enemy_recharge;
		float easy_friend_damage;
		float normal_friend_damage;
		float hard_friend_damage;
		float impossible_friend_damage;
		float easy_friend_vitality;
		float normal_friend_vitality;
		float hard_friend_vitality;
		float impossible_friend_vitality;
		float easy_friend_shield;
		float normal_friend_shield;
		float hard_friend_shield;
		float impossible_friend_shield;
		float easy_friend_recharge;
		float normal_friend_recharge;
		float hard_friend_recharge;
		float impossible_friend_recharge;
		float easy_infection_forms;
		float normal_infection_forms;
		float hard_infection_forms;
		float impossible_infection_forms;
		float easy_unknown;
		float normal_unknown;
		float hard_unknown;
		float impossible_unknown;
		float easy_rate_of_fire;
		float normal_rate_of_fire;
		float hard_rate_of_fire;
		float impossible_rate_of_fire;
		float easy_projectile_error;
		float normal_projectile_error;
		float hard_projectile_error;
		float impossible_projectile_error;
		float easy_burst_error;
		float normal_burst_error;
		float hard_burst_error;
		float impossible_burst_error;
		float easy_target_delay;
		float normal_target_delay;
		float hard_target_delay;
		float impossible_target_delay;
		float easy_burst_separation;
		float normal_burst_separation;
		float hard_burst_separation;
		float impossible_burst_separation;
		float easy_target_tracking;
		float normal_target_tracking;
		float hard_target_tracking;
		float impossible_target_tracking;
		float easy_target_leading;
		float normal_target_leading;
		float hard_target_leading;
		float impossible_target_leading;
		float easy_overcharge_chance;
		float normal_overcharge_chance;
		float hard_overcharge_chance;
		float impossible_overcharge_chance;
		float easy_special_fire_delay;
		float normal_special_fire_delay;
		float hard_special_fire_delay;
		float impossible_special_fire_delay;
		float easy_guidance_vs_player;
		float normal_guidance_vs_player;
		float hard_guidance_vs_player;
		float impossible_guidance_vs_player;
		float easy_melee_delay_base;
		float normal_melee_delay_base;
		float hard_melee_delay_base;
		float impossible_melee_delay_base;
		float easy_melee_delay_scale;
		float normal_melee_delay_scale;
		float hard_melee_delay_scale;
		float impossible_melee_delay_scale;
		float easy_unknown2;
		float normal_unknown2;
		float hard_unknown2;
		float impossible_unknown2;
		float easy_grenade_chance_scale;
		float normal_grenade_chance_scale;
		float hard_grenade_chance_scale;
		float impossible_grenade_chance_scale;
		float easy_grenade_timer_scale;
		float normal_grenade_timer_scale;
		float hard_grenade_timer_scale;
		float impossible_grenade_timer_scale;
		float easy_unknown3;
		float normal_unknown3;
		float hard_unknown3;
		float impossible_unknown3;
		float easy_unknown4;
		float normal_unknown4;
		float hard_unknown4;
		float impossible_unknown4;
		float easy_unknown5;
		float normal_unknown5;
		float hard_unknown5;
		float impossible_unknown5;
		float easy_major_upgrade_normal;
		float normal_major_upgrade_normal;
		float hard_major_upgrade_normal;
		float impossible_major_upgrade_normal;
		float easy_major_upgrade_few;
		float normal_major_upgrade_few;
		float hard_major_upgrade_few;
		float impossible_major_upgrade_few;
		float easy_major_upgrade_many;
		float normal_major_upgrade_many;
		float hard_major_upgrade_many;
		float impossible_major_upgrade_many;
		float easy_player_vehicle_ram_chance;
		float normal_player_vehicle_ram_chance;
		float hard_player_vehicle_ram_chance;
		float impossible_player_vehicle_ram_chance;
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
		unsigned int unknown31;
		unsigned int unknown32;
		unsigned int unknown33;
	};

	struct s_unknown_definition
	{
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
		float unknown14;
		float unknown15;
		float unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
		float unknown20;
		float unknown21;
		float unknown22;
		float unknown23;
		float unknown24;
		float unknown25;
		float unknown26;
		float unknown27;
		float unknown28;
		float unknown29;
		float unknown30;
		float unknown31;
		float unknown32;
		float unknown33;
		float unknown34;
	};

	struct s_grenade_definition
	{
		signed short maximum_count;
		signed short unknown;
		float unknown2;
		TagReference throwing_effect;
		TagReference equipment;
		TagReference projectile;
	};

	struct s_soft_barrier_property_definition
	{
		unsigned int biped_give;
		unsigned int biped_bounciness;
		unsigned int biped_bumpiness;
		unsigned int unknown;
		unsigned int vehicle_give;
		unsigned int vehicle_bounciness;
		unsigned int vehicle_bumpiness;
	};

	struct s_interface_tag_definition
	{
		TagReference spinner;
		TagReference obsolete;
		TagReference screen_color_table;
		TagReference hud_color_table;
		TagReference editor_color_table;
		TagReference dialog_color_table;
		TagReference motion_sensor_sweep_bitmap;
		TagReference motion_sensor_sweep_bitmap_mask;
		TagReference multiplayer_hud_bitmap;
		TagReference hud_digits_definition;
		TagReference motion_sensor_blip_bitmap;
		TagReference interface_goo_map_1;
		TagReference interface_goo_map_2;
		TagReference interface_goo_map_3;
		TagReference main_menu_ui_globals;
		TagReference single_player_survival_ui_globals;
		TagReference multiplayer_ui_globals;
		TagReference hud_globals;
	};

	struct s_player_information_definition
	{
		float walking_speed;
		float run_forward;
		float run_backward;
		float run_sideways;
		float run_acceleration;
		float sneak_forward;
		float sneak_backward;
		float sneak_sideways;
		float sneak_acceleration;
		float airborne_acceleration;
		float grenade_origin_x;
		float grenade_origin_y;
		float grenade_origin_z;
		DataReference stun_function;
		float first_person_idle_time_min;
		float first_person_idle_time_max;
		float first_person_skip_fraction;
		TagReference timer_sound;
		TagReference timer_sound_zero;
		TagReference respawn_effect;
		TagReference unknown;
		signed int binoculars_zoom_count;
		float binocular_zoom_range_min;
		float binocular_zoom_range_max;
		TagReference flashlight_on;
		TagReference flashlight_off;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		float unknown6;
		float unknown7;
		float sprint_movement_speed_percentage;
		float sprint_look_speed_percentage;
		float unknown8;
		float unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		string_id sprint;
	};

	struct s_player_representation_definition
	{
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		TagReference hud;
		TagReference first_person_hands;
		TagReference first_person_body;
		TagReference third_person_unit;
		string_id third_person_variant;
		TagReference binoculars_zoom_in_sound;
		TagReference binoculars_zoom_out_sound;
		signed int player_information_index;
	};

	struct s_falling_damage_definition
	{
		TagReference falling_damage2;
		TagReference unknown;
		TagReference soft_landing;
		TagReference hard_landing;
		TagReference script_damage;
		float maximum_falling_distance;
		TagReference terminal_velocity_damage;
		TagReference missing_response;
		TagReference unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		unsigned int unknown9;
		float unknown10;
		float unknown11;
		float unknown12;
		float unknown13;
		unsigned int unknown14;
		float unknown15;
		float unknown16;
		float unknown17;
		float unknown18;
	};

	struct s_unknown_definition
	{
		float unknown2;
		float unknown3;
		float unknown4;
	};

	struct s_material_definition
	{
		struct s_object_water_drag_property_block_definition;
		struct s_water_interaction_block_definition;

		string_id name;
		string_id parent_name;
		signed short parent_index;
		unsigned short flags;
		string_id general_armor;
		string_id specific_armor;
		string_id wet_armor;
		signed short wet_armor_index;
		signed short unknown;
		signed short wet_armor_reference_index;
		signed short unknown2;
		unsigned int unknown3;
		float friction;
		float restitution;
		float density;
		TagReference global_water_drag_properties;
		s_tag_block_definition<s_object_water_drag_property_block_definition> object_water_drag_properties;
		float water_drag_unknown;
		float water_drag_unknown2;
		float water_drag_unknown3;
		float water_drag_unknown4;
		float water_drag_unknown5;
		float water_drag_unknown6;
		unsigned int water_drag_unknown7;
		TagReference breakable_surface;
		TagReference sound_sweetener_small;
		TagReference sound_sweetener_medium;
		TagReference sound_sweetener_large;
		TagReference sound_sweetener_rolling;
		TagReference sound_sweetener_grinding;
		TagReference sound_sweetener_melee_small;
		TagReference sound_sweetener_melee_medium;
		TagReference sound_sweetener_melee_large;
		TagReference effect_sweetener_small;
		TagReference effect_sweetener_medium;
		TagReference effect_sweetener_large;
		TagReference effect_sweetener_rolling;
		TagReference effect_sweetener_grinding;
		TagReference effect_sweetener_melee;
		TagReference water_ripple_small;
		TagReference water_ripple_medium;
		TagReference water_ripple_large;
		signed int sweetener_inheritance_flags;
		TagReference material_effects;
		s_tag_block_definition<s_water_interaction_block_definition> water_interaction2;

		struct s_object_water_drag_property_definition
		{
			TagReference water_drag_properties;
		};

		struct s_water_interaction_definition
		{
			string_id surface_name;
			string_id submerged_name;
			signed short surface_index;
			signed short submerged_index;
		};
	};

	struct s_player_color_definition
	{
		float color_r;
		float color_g;
		float color_b;
	};

	struct s_emblem_color_definition
	{
		float color_r;
		float color_g;
		float color_b;
	};

	struct s_visor_color_definition
	{
		string_id name;
		float primary_color_r;
		float primary_color_g;
		float primary_color_b;
		float secondary_color_r;
		float secondary_color_g;
		float secondary_color_b;
	};

	struct s_forge_color_definition
	{
		string_id name;
		float color_r;
		float color_g;
		float color_b;
	};

	struct s_cinematic_anchor_definition
	{
		TagReference cinematic_anchor2;
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
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
	};

	struct s_metagame_global_definition
	{
		struct s_medal_block_definition;
		struct s_difficulty_block_definition;
		struct s_skull_block_definition;

		s_tag_block_definition<s_medal_block_definition> medals;
		s_tag_block_definition<s_difficulty_block_definition> difficulty2;
		s_tag_block_definition<s_skull_block_definition> skulls;
		signed int unknown;
		signed int death_penalty;
		signed int betrayal_penalty;
		float multikill_window;
		float emp_window;

		struct s_medal_definition
		{
			string_id incident_name;
			float multiplier;
		};

		struct s_difficulty_definition
		{
			float multiplier;
		};

		struct s_skull_definition
		{
			float multiplier;
		};
	};

	struct s_unknown_definition
	{
		struct s_unknown8_block_definition;

		float unknown2;
		float unknown3;
		unsigned int unknown4;
		DataReference unknown5;
		DataReference unknown6;
		DataReference unknown7;
		s_tag_block_definition<s_unknown8_block_definition> unknown9;

		struct s_unknown_definition
		{
			float unknown2;
			float unknown3;
			float unknown4;
			float unknown5;
			DataReference unknown6;
		};
	};

	struct s_unknown_definition
	{
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
	};

	struct s_unknown_definition
	{
		DataReference unknown2;
	};

	struct s_alt_material_definition
	{
		struct s_object_water_drag_property_block_definition;
		struct s_water_interaction_block_definition;

		string_id name;
		string_id parent_name;
		signed short parent_index;
		unsigned short flags;
		string_id general_armor;
		string_id specific_armor;
		string_id wet_armor;
		signed short wet_armor_index;
		signed short unknown;
		signed short wet_armor_reference_index;
		signed short unknown2;
		unsigned int unknown3;
		float friction;
		float restitution;
		float density;
		TagReference global_water_drag_properties;
		s_tag_block_definition<s_object_water_drag_property_block_definition> object_water_drag_properties;
		float water_drag_unknown;
		float water_drag_unknown2;
		float water_drag_unknown3;
		float water_drag_unknown4;
		float water_drag_unknown5;
		float water_drag_unknown6;
		unsigned int water_drag_unknown7;
		TagReference breakable_surface;
		TagReference sound_sweetener_small;
		TagReference sound_sweetener_medium;
		TagReference sound_sweetener_large;
		TagReference sound_sweetener_rolling;
		TagReference sound_sweetener_grinding;
		TagReference sound_sweetener_melee_small;
		TagReference sound_sweetener_melee_medium;
		TagReference sound_sweetener_melee_large;
		TagReference effect_sweetener_small;
		TagReference effect_sweetener_medium;
		TagReference effect_sweetener_large;
		TagReference effect_sweetener_rolling;
		TagReference effect_sweetener_grinding;
		TagReference effect_sweetener_melee;
		TagReference water_ripple_small;
		TagReference water_ripple_medium;
		TagReference water_ripple_large;
		signed int sweetener_inheritance_flags;
		TagReference material_effects;
		s_tag_block_definition<s_water_interaction_block_definition> water_interaction2;

		struct s_object_water_drag_property_definition
		{
			TagReference water_drag_properties;
		};

		struct s_water_interaction_definition
		{
			string_id surface_name;
			string_id submerged_name;
			signed short surface_index;
			signed short submerged_index;
		};
	};
};
