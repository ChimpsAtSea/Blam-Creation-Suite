#pragma once

nicename("globals") struct s_globals_definition
{
	nicename("Havok Cleanup Resources") struct s_havok_cleanup_resource_block_definition;
	nicename("Sound Globals") struct s_sound_global_block_definition;
	nicename("AI Globals") struct s_ai_global_block_definition;
	nicename("Damage Table") struct s_damage_table_block_definition;
	nicename("Sounds") struct s_sound_block_definition;
	nicename("Camera") struct s_camera_block_definition;
	nicename("Thumbstick Deadzones") struct s_thumbstick_deadzone_block_definition;
	nicename("Player Control") struct s_player_control_block_definition;
	nicename("Player Trait Defaults") struct s_player_trait_default_block_definition;
	nicename("Difficulty") struct s_difficulty_block_definition;
	nicename("Unknown") struct s_unknown45_block_definition;
	nicename("Grenades") struct s_grenade_block_definition;
	nicename("Soft Barrier Properties") struct s_soft_barrier_property_block_definition;
	nicename("Interface Tags") struct s_interface_tag_block_definition;
	nicename("Player Information") struct s_player_information_block_definition;
	nicename("Player Representation") struct s_player_representation_block_definition;
	nicename("Falling Damage") struct s_falling_damage_block_definition;
	nicename("Unknown") struct s_unknown56_block_definition;
	nicename("Materials") struct s_material_block_definition;
	nicename("Player Colors") struct s_player_color_block_definition;
	nicename("Emblem Colors") struct s_emblem_color_block_definition;
	nicename("Visor Colors") struct s_visor_color_block_definition;
	nicename("Forge Colors") struct s_forge_color_block_definition;
	nicename("Cinematic Anchors") struct s_cinematic_anchor_block_definition;
	nicename("Metagame Globals") struct s_metagame_global_block_definition;
	nicename("Unknown") struct s_unknown130_block_definition;
	nicename("Unknown") struct s_unknown132_block_definition;
	nicename("Unknown") struct s_unknown134_block_definition;
	nicename("Alt Materials") struct s_alt_material_block_definition;

	nicename("Unknown") unsigned int unknown;
	nicename("Unknown") unsigned int unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") unsigned int unknown5;
	nicename("Unknown") unsigned int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") unsigned int unknown9;
	nicename("Unknown") unsigned int unknown10;
	nicename("Unknown") unsigned int unknown11;
	nicename("Unknown") unsigned int unknown12;
	nicename("Unknown") unsigned int unknown13;
	nicename("Unknown") unsigned int unknown14;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") unsigned int unknown16;
	nicename("Unknown") unsigned int unknown17;
	nicename("Unknown") unsigned int unknown18;
	nicename("Unknown") unsigned int unknown19;
	nicename("Unknown") unsigned int unknown20;
	nicename("Unknown") unsigned int unknown21;
	nicename("Unknown") unsigned int unknown22;
	nicename("Unknown") unsigned int unknown23;
	nicename("Unknown") unsigned int unknown24;
	nicename("Unknown") unsigned int unknown25;
	nicename("Unknown") unsigned int unknown26;
	nicename("Unknown") unsigned int unknown27;
	nicename("Unknown") unsigned int unknown28;
	nicename("Unknown") unsigned int unknown29;
	nicename("Unknown") unsigned int unknown30;
	nicename("Unknown") unsigned int unknown31;
	nicename("Unknown") unsigned int unknown32;
	nicename("Unknown") unsigned int unknown33;
	nicename("Unknown") unsigned int unknown34;
	nicename("Unknown") unsigned int unknown35;
	nicename("Unknown") unsigned int unknown36;
	nicename("Unknown") unsigned int unknown37;
	nicename("Unknown") unsigned int unknown38;
	nicename("Unknown") unsigned int unknown39;
	nicename("Unknown") unsigned int unknown40;
	nicename("Unknown") unsigned int unknown41;
	nicename("Unknown") unsigned int unknown42;
	nicename("Unknown") unsigned int unknown43;
	nicename("Language") signed int language;
	nicename("Havok Cleanup Resources") s_tag_block_definition<s_havok_cleanup_resource_block_definition> havok_cleanup_resources;
	nicename("Sound Globals") s_tag_block_definition<s_sound_global_block_definition> sound_globals;
	nicename("AI Globals") s_tag_block_definition<s_ai_global_block_definition> ai_globals;
	nicename("AI Globals") TagReference ai_globals2;
	nicename("Damage Table") s_tag_block_definition<s_damage_table_block_definition> damage_table2;
	nicename("Unknown") TagReference unknown44;
	nicename("Sounds") s_tag_block_definition<s_sound_block_definition> sounds;
	nicename("Camera") s_tag_block_definition<s_camera_block_definition> camera2;
	nicename("Thumbstick Deadzones") s_tag_block_definition<s_thumbstick_deadzone_block_definition> thumbstick_deadzones;
	nicename("Player Control") s_tag_block_definition<s_player_control_block_definition> player_control2;
	nicename("Player Trait Defaults") s_tag_block_definition<s_player_trait_default_block_definition> player_trait_defaults;
	nicename("Difficulty") s_tag_block_definition<s_difficulty_block_definition> difficulty2;
	nicename("Unknown") s_tag_block_definition<s_unknown45_block_definition> unknown46;
	nicename("Grenades") s_tag_block_definition<s_grenade_block_definition> grenades;
	nicename("Soft Barrier Properties") s_tag_block_definition<s_soft_barrier_property_block_definition> soft_barrier_properties;
	nicename("Unknown") unsigned int unknown47;
	nicename("Unknown") unsigned int unknown48;
	nicename("Unknown") unsigned int unknown49;
	nicename("Interface Tags") s_tag_block_definition<s_interface_tag_block_definition> interface_tags;
	nicename("Unknown") unsigned int unknown50;
	nicename("Unknown") unsigned int unknown51;
	nicename("Unknown") unsigned int unknown52;
	nicename("Unknown") unsigned int unknown53;
	nicename("Unknown") unsigned int unknown54;
	nicename("Unknown") unsigned int unknown55;
	nicename("Player Information") s_tag_block_definition<s_player_information_block_definition> player_information2;
	nicename("Player Representation") s_tag_block_definition<s_player_representation_block_definition> player_representation2;
	nicename("Falling Damage") s_tag_block_definition<s_falling_damage_block_definition> falling_damage2;
	nicename("Unknown") s_tag_block_definition<s_unknown56_block_definition> unknown57;
	nicename("Materials") s_tag_block_definition<s_material_block_definition> materials;
	nicename("Player Colors") s_tag_block_definition<s_player_color_block_definition> player_colors;
	nicename("Emblem Colors") s_tag_block_definition<s_emblem_color_block_definition> emblem_colors;
	nicename("Visor Colors") s_tag_block_definition<s_visor_color_block_definition> visor_colors;
	nicename("Elite Armor Shine r") float elite_armor_shine_r;
	nicename("Elite Armor Shine g") float elite_armor_shine_g;
	nicename("Elite Armor Shine b") float elite_armor_shine_b;
	nicename("Elite Armor Color r") float elite_armor_color_r;
	nicename("Elite Armor Color g") float elite_armor_color_g;
	nicename("Elite Armor Color b") float elite_armor_color_b;
	nicename("Forge Colors") s_tag_block_definition<s_forge_color_block_definition> forge_colors;
	nicename("Game Engine Globals") TagReference game_engine_globals;
	nicename("Multiplayer Globals") TagReference multiplayer_globals;
	nicename("Survival Globals") TagReference survival_globals;
	nicename("Object Type List") TagReference object_type_list;
	nicename("Cinematic Anchors") s_tag_block_definition<s_cinematic_anchor_block_definition> cinematic_anchors;
	nicename("Metagame Globals") s_tag_block_definition<s_metagame_global_block_definition> metagame_globals;
	nicename("Medal Globals") TagReference medal_globals;
	nicename("Unknown") unsigned int unknown58;
	nicename("Unknown") unsigned int unknown59;
	nicename("Unknown") unsigned int unknown60;
	nicename("Unknown") unsigned int unknown61;
	nicename("String Count") unsigned int string_count;
	nicename("Locale Table Size") unsigned int locale_table_size;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset;
	nicename("Index Table Hash") unsigned char index_table_hash[20];
	nicename("String Data Hash") unsigned char string_data_hash[20];
	nicename("Unknown") unsigned int unknown62;
	nicename("Unknown") unsigned int unknown63;
	nicename("Unknown") unsigned int unknown64;
	nicename("Unknown") unsigned int unknown65;
	nicename("Unknown") unsigned int unknown66;
	nicename("Unknown") unsigned int unknown67;
	nicename("String Count") unsigned int string_count2;
	nicename("Locale Table Size") unsigned int locale_table_size2;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset2;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset2;
	nicename("Index Table Hash") unsigned char index_table_hash2[20];
	nicename("String Data Hash") unsigned char string_data_hash2[20];
	nicename("Unknown") unsigned int unknown68;
	nicename("Unknown") unsigned int unknown69;
	nicename("Unknown") unsigned int unknown70;
	nicename("Unknown") unsigned int unknown71;
	nicename("Unknown") unsigned int unknown72;
	nicename("Unknown") unsigned int unknown73;
	nicename("String Count") unsigned int string_count3;
	nicename("Locale Table Size") unsigned int locale_table_size3;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset3;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset3;
	nicename("Index Table Hash") unsigned char index_table_hash3[20];
	nicename("String Data Hash") unsigned char string_data_hash3[20];
	nicename("Unknown") unsigned int unknown74;
	nicename("Unknown") unsigned int unknown75;
	nicename("Unknown") unsigned int unknown76;
	nicename("Unknown") unsigned int unknown77;
	nicename("Unknown") unsigned int unknown78;
	nicename("Unknown") unsigned int unknown79;
	nicename("String Count") unsigned int string_count4;
	nicename("Locale Table Size") unsigned int locale_table_size4;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset4;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset4;
	nicename("Index Table Hash") unsigned char index_table_hash4[20];
	nicename("String Data Hash") unsigned char string_data_hash4[20];
	nicename("Unknown") unsigned int unknown80;
	nicename("Unknown") unsigned int unknown81;
	nicename("Unknown") unsigned int unknown82;
	nicename("Unknown") unsigned int unknown83;
	nicename("Unknown") unsigned int unknown84;
	nicename("Unknown") unsigned int unknown85;
	nicename("String Count") unsigned int string_count5;
	nicename("Locale Table Size") unsigned int locale_table_size5;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset5;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset5;
	nicename("Index Table Hash") unsigned char index_table_hash5[20];
	nicename("String Data Hash") unsigned char string_data_hash5[20];
	nicename("Unknown") unsigned int unknown86;
	nicename("Unknown") unsigned int unknown87;
	nicename("Unknown") unsigned int unknown88;
	nicename("Unknown") unsigned int unknown89;
	nicename("Unknown") unsigned int unknown90;
	nicename("Unknown") unsigned int unknown91;
	nicename("String Count") unsigned int string_count6;
	nicename("Locale Table Size") unsigned int locale_table_size6;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset6;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset6;
	nicename("Index Table Hash") unsigned char index_table_hash6[20];
	nicename("String Data Hash") unsigned char string_data_hash6[20];
	nicename("Unknown") unsigned int unknown92;
	nicename("Unknown") unsigned int unknown93;
	nicename("Unknown") unsigned int unknown94;
	nicename("Unknown") unsigned int unknown95;
	nicename("Unknown") unsigned int unknown96;
	nicename("Unknown") unsigned int unknown97;
	nicename("String Count") unsigned int string_count7;
	nicename("Locale Table Size") unsigned int locale_table_size7;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset7;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset7;
	nicename("Index Table Hash") unsigned char index_table_hash7[20];
	nicename("String Data Hash") unsigned char string_data_hash7[20];
	nicename("Unknown") unsigned int unknown98;
	nicename("Unknown") unsigned int unknown99;
	nicename("Unknown") unsigned int unknown100;
	nicename("Unknown") unsigned int unknown101;
	nicename("Unknown") unsigned int unknown102;
	nicename("Unknown") unsigned int unknown103;
	nicename("String Count") unsigned int string_count8;
	nicename("Locale Table Size") unsigned int locale_table_size8;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset8;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset8;
	nicename("Index Table Hash") unsigned char index_table_hash8[20];
	nicename("String Data Hash") unsigned char string_data_hash8[20];
	nicename("Unknown") unsigned int unknown104;
	nicename("Unknown") unsigned int unknown105;
	nicename("Unknown") unsigned int unknown106;
	nicename("Unknown") unsigned int unknown107;
	nicename("Unknown") unsigned int unknown108;
	nicename("Unknown") unsigned int unknown109;
	nicename("String Count") unsigned int string_count9;
	nicename("Locale Table Size") unsigned int locale_table_size9;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset9;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset9;
	nicename("Index Table Hash") unsigned char index_table_hash9[20];
	nicename("String Data Hash") unsigned char string_data_hash9[20];
	nicename("Unknown") unsigned int unknown110;
	nicename("Unknown") unsigned int unknown111;
	nicename("Unknown") unsigned int unknown112;
	nicename("Unknown") unsigned int unknown113;
	nicename("Unknown") unsigned int unknown114;
	nicename("Unknown") unsigned int unknown115;
	nicename("String Count") unsigned int string_count10;
	nicename("Locale Table Size") unsigned int locale_table_size10;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset10;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset10;
	nicename("Index Table Hash") unsigned char index_table_hash10[20];
	nicename("String Data Hash") unsigned char string_data_hash10[20];
	nicename("Unknown") unsigned int unknown116;
	nicename("Unknown") unsigned int unknown117;
	nicename("Unknown") unsigned int unknown118;
	nicename("Unknown") unsigned int unknown119;
	nicename("Unknown") unsigned int unknown120;
	nicename("Unknown") unsigned int unknown121;
	nicename("String Count") unsigned int string_count11;
	nicename("Locale Table Size") unsigned int locale_table_size11;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset11;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset11;
	nicename("Index Table Hash") unsigned char index_table_hash11[20];
	nicename("String Data Hash") unsigned char string_data_hash11[20];
	nicename("Unknown") unsigned int unknown122;
	nicename("Unknown") unsigned int unknown123;
	nicename("Unknown") unsigned int unknown124;
	nicename("Unknown") unsigned int unknown125;
	nicename("Unknown") unsigned int unknown126;
	nicename("Unknown") unsigned int unknown127;
	nicename("String Count") unsigned int string_count12;
	nicename("Locale Table Size") unsigned int locale_table_size12;
	nicename("Locale Index Table Offset") unsigned int locale_index_table_offset12;
	nicename("Locale Data Index Offset") unsigned int locale_data_index_offset12;
	nicename("Index Table Hash") unsigned char index_table_hash12[20];
	nicename("String Data Hash") unsigned char string_data_hash12[20];
	nicename("Unknown") unsigned int unknown128;
	nicename("Unknown") unsigned int unknown129;
	nicename("Rasterizer Globals") TagReference rasterizer_globals;
	nicename("Default Camera Effect") TagReference default_camera_effect;
	nicename("Default Wind") TagReference default_wind;
	nicename("Weather Globals") TagReference weather_globals;
	nicename("Default Damage Effect") TagReference default_damage_effect;
	nicename("Default Collision Damage") TagReference default_collision_damage;
	nicename("Unknown Material") string_id unknown_material;
	nicename("Unknown Material 2") string_id unknown_material_2;
	nicename("Unknown Global Material Index") signed short unknown_global_material_index;
	nicename("Unknown 2 Global Material Index") signed short unknown_2_global_material_index;
	nicename("Effect Globals") TagReference effect_globals;
	nicename("Collision Filter") TagReference collision_filter;
	nicename("Grounded Friction") TagReference grounded_friction;
	nicename("Unknown") s_tag_block_definition<s_unknown130_block_definition> unknown131;
	nicename("Incident Globals") TagReference incident_globals;
	nicename("Player Grade Globals") TagReference player_grade_globals;
	nicename("Player Customization Gobals") TagReference player_customization_gobals;
	nicename("Loadout Globals") TagReference loadout_globals;
	nicename("Challenge Gloabls") TagReference challenge_gloabls;
	nicename("Reward Globals") TagReference reward_globals;
	nicename("Achievement Globals") TagReference achievement_globals;
	nicename("Avatar Award Globals") TagReference avatar_award_globals;
	nicename("Performance Throttle Globals") TagReference performance_throttle_globals;
	nicename("Unknown") s_tag_block_definition<s_unknown132_block_definition> unknown133;
	nicename("Unknown") s_tag_block_definition<s_unknown134_block_definition> unknown135;
	nicename("Unknown") unsigned int unknown136;
	nicename("Alt Materials") s_tag_block_definition<s_alt_material_block_definition> alt_materials;

	nicename("Havok Cleanup Resource") struct s_havok_cleanup_resource_definition
	{
		nicename("Object Cleanup Effect") TagReference object_cleanup_effect;
	};

	nicename("Sound Global") struct s_sound_global_definition
	{
		nicename("Fireteam Sounds") struct s_fireteam_sound_block_definition;

		nicename("Sound Classes") TagReference sound_classes;
		nicename("Sound Effects") TagReference sound_effects;
		nicename("Sound Mastering") TagReference sound_mastering;
		nicename("Sound Mix") TagReference sound_mix;
		nicename("Sound Combat Dialogue Constants") TagReference sound_combat_dialogue_constants;
		nicename("Sound Global Propagation") TagReference sound_global_propagation;
		nicename("Fireteam Sounds") s_tag_block_definition<s_fireteam_sound_block_definition> fireteam_sounds;

		nicename("Fireteam Sound") struct s_fireteam_sound_definition
		{
			nicename("Sound") TagReference sound;
		};
	};

	nicename("AI Global") struct s_ai_global_definition
	{
		nicename("Gravemind Properties") struct s_gravemind_property_block_definition;
		nicename("Formations") struct s_formation_block_definition;
		nicename("Squad Templates") struct s_squad_template_block_definition;
		nicename("Performance Templates") struct s_performance_template_block_definition;
		nicename("Unknown") struct s_unknown23_block_definition;
		nicename("Vision Trait Definitions") struct s_vision_trait_definition_block_definition;
		nicename("Hearing Trait Definitions") struct s_hearing_trait_definition_block_definition;
		nicename("Luck Trait Definitions") struct s_luck_trait_definition_block_definition;
		nicename("Grenade Trait Definitions") struct s_grenade_trait_definition_block_definition;

		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Danger Broadly Facing") float danger_broadly_facing;
		nicename("Danger Shooting Near") float danger_shooting_near;
		nicename("Danger Shooting At") float danger_shooting_at;
		nicename("Danger Extremely Close") float danger_extremely_close;
		nicename("Danger Shield Damage") float danger_shield_damage;
		nicename("Danger Extended Shield Damage") float danger_extended_shield_damage;
		nicename("Danger Body Damage") float danger_body_damage;
		nicename("Danger Extended Body Damage") float danger_extended_body_damage;
		nicename("Global Dialogue") TagReference global_dialogue;
		nicename("Default Mission Dialogue Sound Effect") string_id default_mission_dialogue_sound_effect;
		nicename("Jump Down") float jump_down;
		nicename("Jump Step") float jump_step;
		nicename("Jump Crouch") float jump_crouch;
		nicename("Jump Stand") float jump_stand;
		nicename("Jump Storey") float jump_storey;
		nicename("Jump Tower") float jump_tower;
		nicename("Unknown") float unknown4;
		nicename("Max Jump Down Height Down") float max_jump_down_height_down;
		nicename("Max Jump Down Height Step") float max_jump_down_height_step;
		nicename("Max Jump Down Height Crouch") float max_jump_down_height_crouch;
		nicename("Max Jump Down Height Stand") float max_jump_down_height_stand;
		nicename("Max Jump Down Height Storey") float max_jump_down_height_storey;
		nicename("Max Jump Down Height Tower") float max_jump_down_height_tower;
		nicename("Unknown") float unknown5;
		nicename("Hoist Step min") float hoist_step_min;
		nicename("Hoist Step max") float hoist_step_max;
		nicename("Hoist Crouch min") float hoist_crouch_min;
		nicename("Hoist Crouch max") float hoist_crouch_max;
		nicename("Hoist Stand min") float hoist_stand_min;
		nicename("Hoist Stand max") float hoist_stand_max;
		nicename("Vault Step min") float vault_step_min;
		nicename("Vault Step max") float vault_step_max;
		nicename("Vault Crouch min") float vault_crouch_min;
		nicename("Vault Crouch max") float vault_crouch_max;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Gravemind Properties") s_tag_block_definition<s_gravemind_property_block_definition> gravemind_properties;
		nicename("Scary Target Threshold") float scary_target_threshold;
		nicename("Scary Weapon Threshold") float scary_weapon_threshold;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") float unknown14;
		nicename("Unknown") float unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
		nicename("Formations") s_tag_block_definition<s_formation_block_definition> formations;
		nicename("Squad Templates") s_tag_block_definition<s_squad_template_block_definition> squad_templates;
		nicename("Performance Templates") s_tag_block_definition<s_performance_template_block_definition> performance_templates;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") s_tag_block_definition<s_unknown23_block_definition> unknown24;
		nicename("Unknown") unsigned int unknown25;
		nicename("Unknown") unsigned int unknown26;
		nicename("Unknown") unsigned int unknown27;
		nicename("Unknown") unsigned int unknown28;
		nicename("Unknown") unsigned int unknown29;
		nicename("Unknown") unsigned int unknown30;
		nicename("Unknown") unsigned int unknown31;
		nicename("Unknown") unsigned int unknown32;
		nicename("Unknown") unsigned int unknown33;
		nicename("Unknown") unsigned int unknown34;
		nicename("Unknown") unsigned int unknown35;
		nicename("Unknown") unsigned int unknown36;
		nicename("Unknown") unsigned int unknown37;
		nicename("Unknown") unsigned int unknown38;
		nicename("Unknown") signed short unknown39;
		nicename("Unknown") signed short unknown40;
		nicename("Unknown") signed short unknown41;
		nicename("Unknown") signed short unknown42;
		nicename("Unknown") signed short unknown43;
		nicename("Unknown") signed short unknown44;
		nicename("Vision Trait Definitions") s_tag_block_definition<s_vision_trait_definition_block_definition> vision_trait_definitions;
		nicename("Hearing Trait Definitions") s_tag_block_definition<s_hearing_trait_definition_block_definition> hearing_trait_definitions;
		nicename("Luck Trait Definitions") s_tag_block_definition<s_luck_trait_definition_block_definition> luck_trait_definitions;
		nicename("Grenade Trait Definitions") s_tag_block_definition<s_grenade_trait_definition_block_definition> grenade_trait_definitions;
		nicename("Unknown") unsigned int unknown45;
		nicename("Unknown") unsigned int unknown46;
		nicename("Unknown") unsigned int unknown47;
		nicename("Unknown") signed short unknown48;
		nicename("Unknown") signed short unknown49;
		nicename("Unknown") signed short unknown50;
		nicename("Unknown") signed short unknown51;

		nicename("Gravemind Property") struct s_gravemind_property_definition
		{
			nicename("Minimum Retreat Time") float minimum_retreat_time;
			nicename("Ideal Retreat Time") float ideal_retreat_time;
			nicename("Maximum Retreat Time") float maximum_retreat_time;
		};

		nicename("Formation") struct s_formation_definition
		{
			nicename("Formation") TagReference formation2;
		};

		nicename("Squad Template") struct s_squad_template_definition
		{
			nicename("Templates") struct s_template_block_definition;

			nicename("Name") string_id name;
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Templates") s_tag_block_definition<s_template_block_definition> templates;

			nicename("Template") struct s_template_definition
			{
				nicename("Template") TagReference template2;
			};
		};

		nicename("Performance Template") struct s_performance_template_definition
		{
			nicename("Characters") struct s_character_block_definition;

			nicename("Name") string_id name;
			nicename("Characters") s_tag_block_definition<s_character_block_definition> characters;
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;

			nicename("Character") struct s_character_definition
			{
				nicename("Templates") struct s_template_block_definition;

				nicename("Name") string_id name;
				nicename("Templates") s_tag_block_definition<s_template_block_definition> templates;

				nicename("Template") struct s_template_definition
				{
					nicename("Template") TagReference template2;
				};
			};
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") struct s_unknown3_block_definition;
			nicename("Unknown") struct s_unknown5_block_definition;
			nicename("Unknown") struct s_unknown7_block_definition;

			nicename("Unknown") string_id unknown2;
			nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
			nicename("Unknown") s_tag_block_definition<s_unknown5_block_definition> unknown6;
			nicename("Unknown") s_tag_block_definition<s_unknown7_block_definition> unknown8;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") float unknown2;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") string_id unknown2;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") unsigned int unknown2;
				nicename("Unknown") unsigned int unknown3;
				nicename("Unknown") unsigned int unknown4;
				nicename("Unknown") unsigned int unknown5;
				nicename("Unknown") unsigned int unknown6;
				nicename("Unknown") unsigned int unknown7;
				nicename("Unknown") unsigned int unknown8;
				nicename("Unknown") unsigned int unknown9;
				nicename("Unknown") unsigned int unknown10;
				nicename("Unknown") unsigned int unknown11;
				nicename("Unknown") unsigned int unknown12;
			};
		};

		nicename("Vision Trait Definition") struct s_vision_trait_definition_definition
		{
			nicename("Unknown") float unknown;
			nicename("Unknown") float unknown2;
		};

		nicename("Hearing Trait Definition") struct s_hearing_trait_definition_definition
		{
			nicename("Unknown") float unknown;
		};

		nicename("Luck Trait Definition") struct s_luck_trait_definition_definition
		{
			nicename("Unknown") float unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") float unknown10;
			nicename("Unknown") float unknown11;
		};

		nicename("Grenade Trait Definition") struct s_grenade_trait_definition_definition
		{
			nicename("Unknown") float unknown;
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
		};
	};

	nicename("Damage Table") struct s_damage_table_definition
	{
		nicename("Damage Groups") struct s_damage_group_block_definition;

		nicename("Damage Groups") s_tag_block_definition<s_damage_group_block_definition> damage_groups;

		nicename("Damage Group") struct s_damage_group_definition
		{
			nicename("Armor Modifiers") struct s_armor_modifier_block_definition;

			nicename("Name") string_id name;
			nicename("Armor Modifiers") s_tag_block_definition<s_armor_modifier_block_definition> armor_modifiers;

			nicename("Armor Modifier") struct s_armor_modifier_definition
			{
				nicename("Name") string_id name;
				nicename("Damage Multiplier") float damage_multiplier;
			};
		};
	};

	nicename("Sound") struct s_sound_definition
	{
		nicename("Sound (Obsolete)") TagReference sound_obsolete;
	};

	nicename("Camera") struct s_camera_definition
	{
		nicename("Default Unit Track") TagReference default_unit_track;
		nicename("Unknown") DataReference unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") float unknown14;
		nicename("Unknown") float unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
		nicename("Unknown") float unknown20;
		nicename("Unknown") float unknown21;
		nicename("Unknown") float unknown22;
		nicename("Unknown") float unknown23;
		nicename("Unknown") float unknown24;
		nicename("Unknown") float unknown25;
		nicename("Unknown") float unknown26;
		nicename("Unknown") float unknown27;
		nicename("Unknown") signed short unknown28;
		nicename("Unknown") signed short unknown29;
		nicename("Unknown") float unknown30;
		nicename("Unknown") float unknown31;
		nicename("Unknown") float unknown32;
		nicename("Unknown") float unknown33;
		nicename("Unknown") float unknown34;
		nicename("Unknown") float unknown35;
		nicename("Unknown") float unknown36;
		nicename("Unknown") float unknown37;
		nicename("Unknown") float unknown38;
		nicename("Unknown") float unknown39;
		nicename("Unknown") float unknown40;
		nicename("Unknown") float unknown41;
		nicename("Unknown") float unknown42;
		nicename("Unknown") float unknown43;
		nicename("Unknown") float unknown44;
		nicename("Unknown") float unknown45;
		nicename("Unknown") float unknown46;
		nicename("Unknown") float unknown47;
	};

	nicename("Thumbstick Deadzone") struct s_thumbstick_deadzone_definition
	{
		nicename("Minimum") float minimum;
		nicename("Maximum") float maximum;
	};

	nicename("Player Control") struct s_player_control_definition
	{
		nicename("Unknown") struct s_unknown_block_definition;
		nicename("Unknown") struct s_unknown3_block_definition;

		nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
		nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
		nicename("Magnetism Friction") float magnetism_friction;
		nicename("Magnetism Adhesion") float magnetism_adhesion;
		nicename("Inconsequential Target Scale") float inconsequential_target_scale;
		nicename("Crosshair Location x") float crosshair_location_x;
		nicename("Crosshair Location y") float crosshair_location_y;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Look Autoleveling Scale") float look_autoleveling_scale;
		nicename("Gravity Scale") float gravity_scale;
		nicename("Minimum Autoleveling Ticks") signed int minimum_autoleveling_ticks;
		nicename("Minimum Angle for Vehicle Flipping") float minimum_angle_for_vehicle_flipping;
		nicename("Minimum Action Hold Time") float minimum_action_hold_time;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") signed int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
		nicename("Unknown") float unknown20;
		nicename("Unknown") float unknown21;
		nicename("Unknown") float unknown22;
		nicename("Unknown") unsigned int unknown23;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") struct s_unknown12_block_definition;

			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") float unknown10;
			nicename("Unknown") float unknown11;
			nicename("Unknown") s_tag_block_definition<s_unknown12_block_definition> unknown13;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") DataReference unknown2;
			};
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") struct s_unknown12_block_definition;

			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") float unknown10;
			nicename("Unknown") float unknown11;
			nicename("Unknown") s_tag_block_definition<s_unknown12_block_definition> unknown13;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") DataReference unknown2;
			};
		};
	};

	nicename("Player Trait Default") struct s_player_trait_default_definition
	{
		nicename("Shields and Health") struct s_shields_and_health_block_definition;
		nicename("Weapons and Damage") struct s_weapons_and_damage_block_definition;
		nicename("Movement") struct s_movement_block_definition;
		nicename("Appearance") struct s_appearance_block_definition;
		nicename("HUD") struct s_hud_block_definition;

		nicename("Shields and Health") s_tag_block_definition<s_shields_and_health_block_definition> shields_and_health2;
		nicename("Weapons and Damage") s_tag_block_definition<s_weapons_and_damage_block_definition> weapons_and_damage2;
		nicename("Movement") s_tag_block_definition<s_movement_block_definition> movement2;
		nicename("Appearance") s_tag_block_definition<s_appearance_block_definition> appearance2;
		nicename("HUD") s_tag_block_definition<s_hud_block_definition> hud2;

		nicename("Shields and Health") struct s_shields_and_health_definition
		{
			nicename("Damage Resistance") signed char damage_resistance;
			nicename("Health Multiplier") signed char health_multiplier;
			nicename("Health Recharge Rate") signed char health_recharge_rate;
			nicename("Shield Multiplier") signed char shield_multiplier;
			nicename("Shield Recharge Rate") signed char shield_recharge_rate;
			nicename("Shield Recharge Rate 2") signed char shield_recharge_rate_2;
			nicename("Headshot Immunity") signed char headshot_immunity;
			nicename("Shield Vampirism") signed char shield_vampirism;
			nicename("Assassination Immunity") signed char assassination_immunity;
			nicename("Deathless") signed char deathless;
			nicename("Unknown") signed char unknown;
			nicename("Unknown") signed char unknown2;
		};

		nicename("Weapons and Damage") struct s_weapons_and_damage_definition
		{
			nicename("Damage Modifier") signed char damage_modifier;
			nicename("Melee Damage Modifier") signed char melee_damage_modifier;
			nicename("Grenade Regeneration") signed char grenade_regeneration;
			nicename("Weapon Pickup") signed char weapon_pickup;
			nicename("Grenade Count") signed char grenade_count;
			nicename("Infinite Ammo") signed char infinite_ammo;
			nicename("Equipment Usage") signed char equipment_usage;
			nicename("Equipment Drop") signed char equipment_drop;
			nicename("Infinite Equipment") signed char infinite_equipment;
			nicename("Unknown") signed char unknown;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Primary Weapon") string_id primary_weapon;
			nicename("Secondary Weapon") string_id secondary_weapon;
			nicename("Equipment") string_id equipment;
		};

		nicename("Movement") struct s_movement_definition
		{
			nicename("Player Speed") signed char player_speed;
			nicename("Player Gravity") signed char player_gravity;
			nicename("Vehicle Use") signed char vehicle_use;
			nicename("Double Jump") signed char double_jump;
			nicename("Jump Height") signed int jump_height;
		};

		nicename("Appearance") struct s_appearance_definition
		{
			nicename("Active Camo") signed char active_camo;
			nicename("Waypoint") signed char waypoint;
			nicename("Visible Name") signed char visible_name;
			nicename("Aura") signed char aura;
			nicename("Forced Color") signed char forced_color;
			nicename("Unknown") signed char unknown;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
		};

		nicename("HUD") struct s_hud_definition
		{
			nicename("Motion Tracker Mode") signed char motion_tracker_mode;
			nicename("Motion Tracker Range") signed char motion_tracker_range;
			nicename("Directional Damage Indicator") signed char directional_damage_indicator;
			nicename("Unknown") signed char unknown;
		};
	};

	nicename("Difficulty") struct s_difficulty_definition
	{
		nicename("Easy Enemy Damage") float easy_enemy_damage;
		nicename("Normal Enemy Damage") float normal_enemy_damage;
		nicename("Hard Enemy Damage") float hard_enemy_damage;
		nicename("Impossible Enemy Damage") float impossible_enemy_damage;
		nicename("Easy Enemy Vitality") float easy_enemy_vitality;
		nicename("Normal Enemy Vitality") float normal_enemy_vitality;
		nicename("Hard Enemy Vitality") float hard_enemy_vitality;
		nicename("Impossible Enemy Vitality") float impossible_enemy_vitality;
		nicename("Easy Enemy Shield") float easy_enemy_shield;
		nicename("Normal Enemy Shield") float normal_enemy_shield;
		nicename("Hard Enemy Shield") float hard_enemy_shield;
		nicename("Impossible Enemy Shield") float impossible_enemy_shield;
		nicename("Easy Enemy Recharge") float easy_enemy_recharge;
		nicename("Normal Enemy Recharge") float normal_enemy_recharge;
		nicename("Hard Enemy Recharge") float hard_enemy_recharge;
		nicename("Impossible Enemy Recharge") float impossible_enemy_recharge;
		nicename("Easy Friend Damage") float easy_friend_damage;
		nicename("Normal Friend Damage") float normal_friend_damage;
		nicename("Hard Friend Damage") float hard_friend_damage;
		nicename("Impossible Friend Damage") float impossible_friend_damage;
		nicename("Easy Friend Vitality") float easy_friend_vitality;
		nicename("Normal Friend Vitality") float normal_friend_vitality;
		nicename("Hard Friend Vitality") float hard_friend_vitality;
		nicename("Impossible Friend Vitality") float impossible_friend_vitality;
		nicename("Easy Friend Shield") float easy_friend_shield;
		nicename("Normal Friend Shield") float normal_friend_shield;
		nicename("Hard Friend Shield") float hard_friend_shield;
		nicename("Impossible Friend Shield") float impossible_friend_shield;
		nicename("Easy Friend Recharge") float easy_friend_recharge;
		nicename("Normal Friend Recharge") float normal_friend_recharge;
		nicename("Hard Friend Recharge") float hard_friend_recharge;
		nicename("Impossible Friend Recharge") float impossible_friend_recharge;
		nicename("Easy Infection Forms") float easy_infection_forms;
		nicename("Normal Infection Forms") float normal_infection_forms;
		nicename("Hard Infection Forms") float hard_infection_forms;
		nicename("Impossible Infection Forms") float impossible_infection_forms;
		nicename("Easy Unknown") float easy_unknown;
		nicename("Normal Unknown") float normal_unknown;
		nicename("Hard Unknown") float hard_unknown;
		nicename("Impossible Unknown") float impossible_unknown;
		nicename("Easy Rate of Fire") float easy_rate_of_fire;
		nicename("Normal Rate of Fire") float normal_rate_of_fire;
		nicename("Hard Rate of Fire") float hard_rate_of_fire;
		nicename("Impossible Rate of Fire") float impossible_rate_of_fire;
		nicename("Easy Projectile Error") float easy_projectile_error;
		nicename("Normal Projectile Error") float normal_projectile_error;
		nicename("Hard Projectile Error") float hard_projectile_error;
		nicename("Impossible Projectile Error") float impossible_projectile_error;
		nicename("Easy Burst Error") float easy_burst_error;
		nicename("Normal Burst Error") float normal_burst_error;
		nicename("Hard Burst Error") float hard_burst_error;
		nicename("Impossible Burst Error") float impossible_burst_error;
		nicename("Easy Target Delay") float easy_target_delay;
		nicename("Normal Target Delay") float normal_target_delay;
		nicename("Hard Target Delay") float hard_target_delay;
		nicename("Impossible Target Delay") float impossible_target_delay;
		nicename("Easy Burst Separation") float easy_burst_separation;
		nicename("Normal Burst Separation") float normal_burst_separation;
		nicename("Hard Burst Separation") float hard_burst_separation;
		nicename("Impossible Burst Separation") float impossible_burst_separation;
		nicename("Easy Target Tracking") float easy_target_tracking;
		nicename("Normal Target Tracking") float normal_target_tracking;
		nicename("Hard Target Tracking") float hard_target_tracking;
		nicename("Impossible Target Tracking") float impossible_target_tracking;
		nicename("Easy Target Leading") float easy_target_leading;
		nicename("Normal Target Leading") float normal_target_leading;
		nicename("Hard Target Leading") float hard_target_leading;
		nicename("Impossible Target Leading") float impossible_target_leading;
		nicename("Easy Overcharge Chance") float easy_overcharge_chance;
		nicename("Normal Overcharge Chance") float normal_overcharge_chance;
		nicename("Hard Overcharge Chance") float hard_overcharge_chance;
		nicename("Impossible Overcharge Chance") float impossible_overcharge_chance;
		nicename("Easy Special Fire Delay") float easy_special_fire_delay;
		nicename("Normal Special Fire Delay") float normal_special_fire_delay;
		nicename("Hard Special Fire Delay") float hard_special_fire_delay;
		nicename("Impossible Special Fire Delay") float impossible_special_fire_delay;
		nicename("Easy Guidance vs Player") float easy_guidance_vs_player;
		nicename("Normal Guidance vs Player") float normal_guidance_vs_player;
		nicename("Hard Guidance vs Player") float hard_guidance_vs_player;
		nicename("Impossible Guidance vs Player") float impossible_guidance_vs_player;
		nicename("Easy Melee Delay Base") float easy_melee_delay_base;
		nicename("Normal Melee Delay Base") float normal_melee_delay_base;
		nicename("Hard Melee Delay Base") float hard_melee_delay_base;
		nicename("Impossible Melee Delay Base") float impossible_melee_delay_base;
		nicename("Easy Melee Delay Scale") float easy_melee_delay_scale;
		nicename("Normal Melee Delay Scale") float normal_melee_delay_scale;
		nicename("Hard Melee Delay Scale") float hard_melee_delay_scale;
		nicename("Impossible Melee Delay Scale") float impossible_melee_delay_scale;
		nicename("Easy Unknown") float easy_unknown2;
		nicename("Normal Unknown") float normal_unknown2;
		nicename("Hard Unknown") float hard_unknown2;
		nicename("Impossible Unknown") float impossible_unknown2;
		nicename("Easy Grenade Chance Scale") float easy_grenade_chance_scale;
		nicename("Normal Grenade Chance Scale") float normal_grenade_chance_scale;
		nicename("Hard Grenade Chance Scale") float hard_grenade_chance_scale;
		nicename("Impossible Grenade Chance Scale") float impossible_grenade_chance_scale;
		nicename("Easy Grenade Timer Scale") float easy_grenade_timer_scale;
		nicename("Normal Grenade Timer Scale") float normal_grenade_timer_scale;
		nicename("Hard Grenade Timer Scale") float hard_grenade_timer_scale;
		nicename("Impossible Grenade Timer Scale") float impossible_grenade_timer_scale;
		nicename("Easy Unknown") float easy_unknown3;
		nicename("Normal Unknown") float normal_unknown3;
		nicename("Hard Unknown") float hard_unknown3;
		nicename("Impossible Unknown") float impossible_unknown3;
		nicename("Easy Unknown") float easy_unknown4;
		nicename("Normal Unknown") float normal_unknown4;
		nicename("Hard Unknown") float hard_unknown4;
		nicename("Impossible Unknown") float impossible_unknown4;
		nicename("Easy Unknown") float easy_unknown5;
		nicename("Normal Unknown") float normal_unknown5;
		nicename("Hard Unknown") float hard_unknown5;
		nicename("Impossible Unknown") float impossible_unknown5;
		nicename("Easy Major Upgrade Normal") float easy_major_upgrade_normal;
		nicename("Normal Major Upgrade Normal") float normal_major_upgrade_normal;
		nicename("Hard Major Upgrade Normal") float hard_major_upgrade_normal;
		nicename("Impossible Major Upgrade Normal") float impossible_major_upgrade_normal;
		nicename("Easy Major Upgrade Few") float easy_major_upgrade_few;
		nicename("Normal Major Upgrade Few") float normal_major_upgrade_few;
		nicename("Hard Major Upgrade Few") float hard_major_upgrade_few;
		nicename("Impossible Major Upgrade Few") float impossible_major_upgrade_few;
		nicename("Easy Major Upgrade Many") float easy_major_upgrade_many;
		nicename("Normal Major Upgrade Many") float normal_major_upgrade_many;
		nicename("Hard Major Upgrade Many") float hard_major_upgrade_many;
		nicename("Impossible Major Upgrade Many") float impossible_major_upgrade_many;
		nicename("Easy Player Vehicle Ram Chance") float easy_player_vehicle_ram_chance;
		nicename("Normal Player Vehicle Ram Chance") float normal_player_vehicle_ram_chance;
		nicename("Hard Player Vehicle Ram Chance") float hard_player_vehicle_ram_chance;
		nicename("Impossible Player Vehicle Ram Chance") float impossible_player_vehicle_ram_chance;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") unsigned int unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") unsigned int unknown23;
		nicename("Unknown") unsigned int unknown24;
		nicename("Unknown") unsigned int unknown25;
		nicename("Unknown") unsigned int unknown26;
		nicename("Unknown") unsigned int unknown27;
		nicename("Unknown") unsigned int unknown28;
		nicename("Unknown") unsigned int unknown29;
		nicename("Unknown") unsigned int unknown30;
		nicename("Unknown") unsigned int unknown31;
		nicename("Unknown") unsigned int unknown32;
		nicename("Unknown") unsigned int unknown33;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") float unknown14;
		nicename("Unknown") float unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
		nicename("Unknown") float unknown20;
		nicename("Unknown") float unknown21;
		nicename("Unknown") float unknown22;
		nicename("Unknown") float unknown23;
		nicename("Unknown") float unknown24;
		nicename("Unknown") float unknown25;
		nicename("Unknown") float unknown26;
		nicename("Unknown") float unknown27;
		nicename("Unknown") float unknown28;
		nicename("Unknown") float unknown29;
		nicename("Unknown") float unknown30;
		nicename("Unknown") float unknown31;
		nicename("Unknown") float unknown32;
		nicename("Unknown") float unknown33;
		nicename("Unknown") float unknown34;
	};

	nicename("Grenade") struct s_grenade_definition
	{
		nicename("Maximum Count") signed short maximum_count;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") float unknown2;
		nicename("Throwing Effect") TagReference throwing_effect;
		nicename("Equipment") TagReference equipment;
		nicename("Projectile") TagReference projectile;
	};

	nicename("Soft Barrier Property") struct s_soft_barrier_property_definition
	{
		nicename("Biped Give") unsigned int biped_give;
		nicename("Biped Bounciness") unsigned int biped_bounciness;
		nicename("Biped Bumpiness") unsigned int biped_bumpiness;
		nicename("Unknown") unsigned int unknown;
		nicename("Vehicle Give") unsigned int vehicle_give;
		nicename("Vehicle Bounciness") unsigned int vehicle_bounciness;
		nicename("Vehicle Bumpiness") unsigned int vehicle_bumpiness;
	};

	nicename("Interface Tag") struct s_interface_tag_definition
	{
		nicename("Spinner") TagReference spinner;
		nicename("Obsolete") TagReference obsolete;
		nicename("Screen Color Table") TagReference screen_color_table;
		nicename("HUD Color Table") TagReference hud_color_table;
		nicename("Editor Color Table") TagReference editor_color_table;
		nicename("Dialog Color Table") TagReference dialog_color_table;
		nicename("Motion Sensor Sweep Bitmap") TagReference motion_sensor_sweep_bitmap;
		nicename("Motion Sensor Sweep Bitmap Mask") TagReference motion_sensor_sweep_bitmap_mask;
		nicename("Multiplayer HUD Bitmap") TagReference multiplayer_hud_bitmap;
		nicename("HUD Digits Definition") TagReference hud_digits_definition;
		nicename("Motion Sensor Blip Bitmap") TagReference motion_sensor_blip_bitmap;
		nicename("Interface Goo Map 1") TagReference interface_goo_map_1;
		nicename("Interface Goo Map 2") TagReference interface_goo_map_2;
		nicename("Interface Goo Map 3") TagReference interface_goo_map_3;
		nicename("Main Menu UI Globals") TagReference main_menu_ui_globals;
		nicename("Single Player/Survival UI Globals") TagReference single_player_survival_ui_globals;
		nicename("Multiplayer UI Globals") TagReference multiplayer_ui_globals;
		nicename("HUD Globals") TagReference hud_globals;
	};

	nicename("Player Information") struct s_player_information_definition
	{
		nicename("Walking Speed") float walking_speed;
		nicename("Run Forward") float run_forward;
		nicename("Run Backward") float run_backward;
		nicename("Run Sideways") float run_sideways;
		nicename("Run Acceleration") float run_acceleration;
		nicename("Sneak Forward") float sneak_forward;
		nicename("Sneak Backward") float sneak_backward;
		nicename("Sneak Sideways") float sneak_sideways;
		nicename("Sneak Acceleration") float sneak_acceleration;
		nicename("Airborne Acceleration") float airborne_acceleration;
		nicename("Grenade Origin x") float grenade_origin_x;
		nicename("Grenade Origin y") float grenade_origin_y;
		nicename("Grenade Origin z") float grenade_origin_z;
		nicename("Stun Function") DataReference stun_function;
		nicename("First Person Idle Time min") float first_person_idle_time_min;
		nicename("First Person Idle Time max") float first_person_idle_time_max;
		nicename("First Person Skip Fraction") float first_person_skip_fraction;
		nicename("Timer Sound") TagReference timer_sound;
		nicename("Timer Sound Zero") TagReference timer_sound_zero;
		nicename("Respawn Effect") TagReference respawn_effect;
		nicename("Unknown") TagReference unknown;
		nicename("Binoculars Zoom Count") signed int binoculars_zoom_count;
		nicename("Binocular Zoom Range min") float binocular_zoom_range_min;
		nicename("Binocular Zoom Range max") float binocular_zoom_range_max;
		nicename("Flashlight On") TagReference flashlight_on;
		nicename("Flashlight Off") TagReference flashlight_off;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Sprint Movement Speed Percentage") float sprint_movement_speed_percentage;
		nicename("Sprint Look Speed Percentage") float sprint_look_speed_percentage;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Sprint") string_id sprint;
	};

	nicename("Player Representation") struct s_player_representation_definition
	{
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("HUD") TagReference hud;
		nicename("First Person Hands") TagReference first_person_hands;
		nicename("First Person Body") TagReference first_person_body;
		nicename("Third Person Unit") TagReference third_person_unit;
		nicename("Third Person Variant") string_id third_person_variant;
		nicename("Binoculars Zoom In Sound") TagReference binoculars_zoom_in_sound;
		nicename("Binoculars Zoom Out Sound") TagReference binoculars_zoom_out_sound;
		nicename("Player Information Index") signed int player_information_index;
	};

	nicename("Falling Damage") struct s_falling_damage_definition
	{
		nicename("Falling Damage") TagReference falling_damage2;
		nicename("Unknown") TagReference unknown;
		nicename("Soft Landing") TagReference soft_landing;
		nicename("Hard Landing") TagReference hard_landing;
		nicename("Script Damage") TagReference script_damage;
		nicename("Maximum Falling Distance") float maximum_falling_distance;
		nicename("Terminal Velocity Damage") TagReference terminal_velocity_damage;
		nicename("Missing Response") TagReference missing_response;
		nicename("Unknown") TagReference unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") float unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
	};

	nicename("Material") struct s_material_definition
	{
		nicename("Object Water Drag Properties") struct s_object_water_drag_property_block_definition;
		nicename("Water Interaction") struct s_water_interaction_block_definition;

		nicename("Name") string_id name;
		nicename("Parent Name") string_id parent_name;
		nicename("Parent Index") signed short parent_index;
		nicename("Flags") unsigned short flags;
		nicename("General Armor") string_id general_armor;
		nicename("Specific Armor") string_id specific_armor;
		nicename("Wet Armor") string_id wet_armor;
		nicename("Wet Armor Index") signed short wet_armor_index;
		nicename("Unknown") signed short unknown;
		nicename("Wet Armor Reference Index") signed short wet_armor_reference_index;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Friction") float friction;
		nicename("Restitution") float restitution;
		nicename("Density") float density;
		nicename("Global Water Drag Properties") TagReference global_water_drag_properties;
		nicename("Object Water Drag Properties") s_tag_block_definition<s_object_water_drag_property_block_definition> object_water_drag_properties;
		nicename("Water Drag Unknown") float water_drag_unknown;
		nicename("Water Drag Unknown") float water_drag_unknown2;
		nicename("Water Drag Unknown") float water_drag_unknown3;
		nicename("Water Drag Unknown") float water_drag_unknown4;
		nicename("Water Drag Unknown") float water_drag_unknown5;
		nicename("Water Drag Unknown") float water_drag_unknown6;
		nicename("Water Drag Unknown") unsigned int water_drag_unknown7;
		nicename("Breakable Surface") TagReference breakable_surface;
		nicename("Sound Sweetener Small") TagReference sound_sweetener_small;
		nicename("Sound Sweetener Medium") TagReference sound_sweetener_medium;
		nicename("Sound Sweetener Large") TagReference sound_sweetener_large;
		nicename("Sound Sweetener Rolling") TagReference sound_sweetener_rolling;
		nicename("Sound Sweetener Grinding") TagReference sound_sweetener_grinding;
		nicename("Sound Sweetener Melee Small") TagReference sound_sweetener_melee_small;
		nicename("Sound Sweetener Melee Medium") TagReference sound_sweetener_melee_medium;
		nicename("Sound Sweetener Melee Large") TagReference sound_sweetener_melee_large;
		nicename("Effect Sweetener Small") TagReference effect_sweetener_small;
		nicename("Effect Sweetener Medium") TagReference effect_sweetener_medium;
		nicename("Effect Sweetener Large") TagReference effect_sweetener_large;
		nicename("Effect Sweetener Rolling") TagReference effect_sweetener_rolling;
		nicename("Effect Sweetener Grinding") TagReference effect_sweetener_grinding;
		nicename("Effect Sweetener Melee") TagReference effect_sweetener_melee;
		nicename("Water Ripple Small") TagReference water_ripple_small;
		nicename("Water Ripple Medium") TagReference water_ripple_medium;
		nicename("Water Ripple Large") TagReference water_ripple_large;
		nicename("Sweetener Inheritance Flags") signed int sweetener_inheritance_flags;
		nicename("Material Effects") TagReference material_effects;
		nicename("Water Interaction") s_tag_block_definition<s_water_interaction_block_definition> water_interaction2;

		nicename("Object Water Drag Property") struct s_object_water_drag_property_definition
		{
			nicename("Water Drag Properties") TagReference water_drag_properties;
		};

		nicename("Water Interaction") struct s_water_interaction_definition
		{
			nicename("Surface Name") string_id surface_name;
			nicename("Submerged Name") string_id submerged_name;
			nicename("Surface Index") signed short surface_index;
			nicename("Submerged Index") signed short submerged_index;
		};
	};

	nicename("Player Color") struct s_player_color_definition
	{
		nicename("Color r") float color_r;
		nicename("Color g") float color_g;
		nicename("Color b") float color_b;
	};

	nicename("Emblem Color") struct s_emblem_color_definition
	{
		nicename("Color r") float color_r;
		nicename("Color g") float color_g;
		nicename("Color b") float color_b;
	};

	nicename("Visor Color") struct s_visor_color_definition
	{
		nicename("Name") string_id name;
		nicename("Primary Color r") float primary_color_r;
		nicename("Primary Color g") float primary_color_g;
		nicename("Primary Color b") float primary_color_b;
		nicename("Secondary Color r") float secondary_color_r;
		nicename("Secondary Color g") float secondary_color_g;
		nicename("Secondary Color b") float secondary_color_b;
	};

	nicename("Forge Color") struct s_forge_color_definition
	{
		nicename("Name") string_id name;
		nicename("Color r") float color_r;
		nicename("Color g") float color_g;
		nicename("Color b") float color_b;
	};

	nicename("Cinematic Anchor") struct s_cinematic_anchor_definition
	{
		nicename("Cinematic Anchor") TagReference cinematic_anchor2;
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
	};

	nicename("Metagame Global") struct s_metagame_global_definition
	{
		nicename("Medals") struct s_medal_block_definition;
		nicename("Difficulty") struct s_difficulty_block_definition;
		nicename("Skulls") struct s_skull_block_definition;

		nicename("Medals") s_tag_block_definition<s_medal_block_definition> medals;
		nicename("Difficulty") s_tag_block_definition<s_difficulty_block_definition> difficulty2;
		nicename("Skulls") s_tag_block_definition<s_skull_block_definition> skulls;
		nicename("Unknown") signed int unknown;
		nicename("Death Penalty") signed int death_penalty;
		nicename("Betrayal Penalty") signed int betrayal_penalty;
		nicename("Multikill Window") float multikill_window;
		nicename("EMP Window") float emp_window;

		nicename("Medal") struct s_medal_definition
		{
			nicename("Incident Name") string_id incident_name;
			nicename("Multiplier") float multiplier;
		};

		nicename("Difficulty") struct s_difficulty_definition
		{
			nicename("Multiplier") float multiplier;
		};

		nicename("Skull") struct s_skull_definition
		{
			nicename("Multiplier") float multiplier;
		};
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") struct s_unknown8_block_definition;

		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") DataReference unknown5;
		nicename("Unknown") DataReference unknown6;
		nicename("Unknown") DataReference unknown7;
		nicename("Unknown") s_tag_block_definition<s_unknown8_block_definition> unknown9;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") float unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") DataReference unknown6;
		};
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") DataReference unknown2;
	};

	nicename("Alt Material") struct s_alt_material_definition
	{
		nicename("Object Water Drag Properties") struct s_object_water_drag_property_block_definition;
		nicename("Water Interaction") struct s_water_interaction_block_definition;

		nicename("Name") string_id name;
		nicename("Parent Name") string_id parent_name;
		nicename("Parent Index") signed short parent_index;
		nicename("Flags") unsigned short flags;
		nicename("General Armor") string_id general_armor;
		nicename("Specific Armor") string_id specific_armor;
		nicename("Wet Armor") string_id wet_armor;
		nicename("Wet Armor Index") signed short wet_armor_index;
		nicename("Unknown") signed short unknown;
		nicename("Wet Armor Reference Index") signed short wet_armor_reference_index;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Friction") float friction;
		nicename("Restitution") float restitution;
		nicename("Density") float density;
		nicename("Global Water Drag Properties") TagReference global_water_drag_properties;
		nicename("Object Water Drag Properties") s_tag_block_definition<s_object_water_drag_property_block_definition> object_water_drag_properties;
		nicename("Water Drag Unknown") float water_drag_unknown;
		nicename("Water Drag Unknown") float water_drag_unknown2;
		nicename("Water Drag Unknown") float water_drag_unknown3;
		nicename("Water Drag Unknown") float water_drag_unknown4;
		nicename("Water Drag Unknown") float water_drag_unknown5;
		nicename("Water Drag Unknown") float water_drag_unknown6;
		nicename("Water Drag Unknown") unsigned int water_drag_unknown7;
		nicename("Breakable Surface") TagReference breakable_surface;
		nicename("Sound Sweetener Small") TagReference sound_sweetener_small;
		nicename("Sound Sweetener Medium") TagReference sound_sweetener_medium;
		nicename("Sound Sweetener Large") TagReference sound_sweetener_large;
		nicename("Sound Sweetener Rolling") TagReference sound_sweetener_rolling;
		nicename("Sound Sweetener Grinding") TagReference sound_sweetener_grinding;
		nicename("Sound Sweetener Melee Small") TagReference sound_sweetener_melee_small;
		nicename("Sound Sweetener Melee Medium") TagReference sound_sweetener_melee_medium;
		nicename("Sound Sweetener Melee Large") TagReference sound_sweetener_melee_large;
		nicename("Effect Sweetener Small") TagReference effect_sweetener_small;
		nicename("Effect Sweetener Medium") TagReference effect_sweetener_medium;
		nicename("Effect Sweetener Large") TagReference effect_sweetener_large;
		nicename("Effect Sweetener Rolling") TagReference effect_sweetener_rolling;
		nicename("Effect Sweetener Grinding") TagReference effect_sweetener_grinding;
		nicename("Effect Sweetener Melee") TagReference effect_sweetener_melee;
		nicename("Water Ripple Small") TagReference water_ripple_small;
		nicename("Water Ripple Medium") TagReference water_ripple_medium;
		nicename("Water Ripple Large") TagReference water_ripple_large;
		nicename("Sweetener Inheritance Flags") signed int sweetener_inheritance_flags;
		nicename("Material Effects") TagReference material_effects;
		nicename("Water Interaction") s_tag_block_definition<s_water_interaction_block_definition> water_interaction2;

		nicename("Object Water Drag Property") struct s_object_water_drag_property_definition
		{
			nicename("Water Drag Properties") TagReference water_drag_properties;
		};

		nicename("Water Interaction") struct s_water_interaction_definition
		{
			nicename("Surface Name") string_id surface_name;
			nicename("Submerged Name") string_id submerged_name;
			nicename("Surface Index") signed short surface_index;
			nicename("Submerged Index") signed short submerged_index;
		};
	};
};
