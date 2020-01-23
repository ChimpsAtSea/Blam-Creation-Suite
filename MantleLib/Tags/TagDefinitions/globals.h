#pragma once

struct nicename("Globals") group('matg') s_globals_definition
{
	struct nicename("Havok Cleanup Resources") s_havok_cleanup_resource_block_definition;
	struct nicename("Sound Globals") s_sound_global_block_definition;
	struct nicename("AI Globals") s_ai_global_block_definition;
	struct nicename("Damage Table") s_damage_table_block_definition;
	struct nicename("Sounds") s_sound_block_definition;
	struct nicename("Camera") s_camera_block_definition;
	struct nicename("Thumbstick Deadzones") s_thumbstick_deadzone_block_definition;
	struct nicename("Player Control") s_player_control_block_definition;
	struct nicename("Player Trait Defaults") s_player_trait_default_block_definition;
	struct nicename("Difficulty") s_difficulty_block_definition;
	struct s_unknown_block_definition;
	struct nicename("Grenades") s_grenade_block_definition;
	struct nicename("Soft Barrier Properties") s_soft_barrier_property_block_definition;
	struct nicename("Interface Tags") s_interface_tag_block_definition;
	struct nicename("Player Information") s_player_information_block_definition;
	struct nicename("Player Representation") s_player_representation_block_definition;
	struct nicename("Falling Damage") s_falling_damage_block_definition;
	struct s_unknown2_block_definition;
	struct nicename("Materials") s_material_block_definition;
	struct nicename("Player Colors") s_player_color_block_definition;
	struct nicename("Emblem Colors") s_emblem_color_block_definition;
	struct nicename("Visor Colors") s_visor_color_block_definition;
	struct nicename("Forge Colors") s_forge_color_block_definition;
	struct nicename("Cinematic Anchors") s_cinematic_anchor_block_definition;
	struct nicename("Metagame Globals") s_metagame_global_block_definition;
	struct s_unknown3_block_definition;
	struct s_unknown4_block_definition;
	struct s_unknown5_block_definition;
	struct nicename("Alt Materials") s_alt_material_block_definition;

	Unknown32 __unknown; 
	Unknown32 __unknown2; 
	Unknown32 __unknown3; 
	Unknown32 __unknown4; 
	Unknown32 __unknown5; 
	Unknown32 __unknown6; 
	Unknown32 __unknown7; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 
	Unknown32 __unknown10; 
	Unknown32 __unknown11; 
	Unknown32 __unknown12; 
	Unknown32 __unknown13; 
	Unknown32 __unknown14; 
	Unknown32 __unknown15; 
	Unknown32 __unknown16; 
	Unknown32 __unknown17; 
	Unknown32 __unknown18; 
	Unknown32 __unknown19; 
	Unknown32 __unknown20; 
	Unknown32 __unknown21; 
	Unknown32 __unknown22; 
	Unknown32 __unknown23; 
	Unknown32 __unknown24; 
	Unknown32 __unknown25; 
	Unknown32 __unknown26; 
	Unknown32 __unknown27; 
	Unknown32 __unknown28; 
	Unknown32 __unknown29; 
	Unknown32 __unknown30; 
	Unknown32 __unknown31; 
	Unknown32 __unknown32; 
	Unknown32 __unknown33; 
	Unknown32 __unknown34; 
	Unknown32 __unknown35; 
	Unknown32 __unknown36; 
	Unknown32 __unknown37; 
	Unknown32 __unknown38; 
	Unknown32 __unknown39; 
	Unknown32 __unknown40; 
	Unknown32 __unknown41; 
	Unknown32 __unknown42; 
	Unknown32 __unknown43; 
	signed int nicename("Language") language; 
	s_tag_block_definition<s_havok_cleanup_resource_block_definition> nicename("Havok Cleanup Resources") havok_cleanup_resources_block; 
	s_tag_block_definition<s_sound_global_block_definition> nicename("Sound Globals") sound_globals_block; 
	s_tag_block_definition<s_ai_global_block_definition> nicename("AI Globals") ai_globals_block; 
	TagReference nicename("AI Globals") ai_globals2_reference; 
	s_tag_block_definition<s_damage_table_block_definition> nicename("Damage Table") damage_table_block; 
	TagReference __unknown44_reference; 
	s_tag_block_definition<s_sound_block_definition> nicename("Sounds") sounds_block; 
	s_tag_block_definition<s_camera_block_definition> nicename("Camera") camera_block; 
	s_tag_block_definition<s_thumbstick_deadzone_block_definition> nicename("Thumbstick Deadzones") thumbstick_deadzones_block; 
	s_tag_block_definition<s_player_control_block_definition> nicename("Player Control") player_control_block; 
	s_tag_block_definition<s_player_trait_default_block_definition> nicename("Player Trait Defaults") player_trait_defaults_block; 
	s_tag_block_definition<s_difficulty_block_definition> nicename("Difficulty") difficulty_block; 
	s_tag_block_definition<s_unknown_block_definition> __unknown45_block; 
	s_tag_block_definition<s_grenade_block_definition> nicename("Grenades") grenades_block; 
	s_tag_block_definition<s_soft_barrier_property_block_definition> nicename("Soft Barrier Properties") soft_barrier_properties_block; 
	Unknown32 __unknown46; 
	Unknown32 __unknown47; 
	Unknown32 __unknown48; 
	s_tag_block_definition<s_interface_tag_block_definition> nicename("Interface Tags") interface_tags_block; 
	Unknown32 __unknown49; 
	Unknown32 __unknown50; 
	Unknown32 __unknown51; 
	Unknown32 __unknown52; 
	Unknown32 __unknown53; 
	Unknown32 __unknown54; 
	s_tag_block_definition<s_player_information_block_definition> nicename("Player Information") player_information_block; 
	s_tag_block_definition<s_player_representation_block_definition> nicename("Player Representation") player_representation_block; 
	s_tag_block_definition<s_falling_damage_block_definition> nicename("Falling Damage") falling_damage_block; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown55_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	s_tag_block_definition<s_player_color_block_definition> nicename("Player Colors") player_colors_block; 
	s_tag_block_definition<s_emblem_color_block_definition> nicename("Emblem Colors") emblem_colors_block; 
	s_tag_block_definition<s_visor_color_block_definition> nicename("Visor Colors") visor_colors_block; 
	float nicename("Elite Armor Shine r") elite_armor_shine_r; 
	float nicename("Elite Armor Shine g") elite_armor_shine_g; 
	float nicename("Elite Armor Shine b") elite_armor_shine_b; 
	float nicename("Elite Armor Color r") elite_armor_color_r; 
	float nicename("Elite Armor Color g") elite_armor_color_g; 
	float nicename("Elite Armor Color b") elite_armor_color_b; 
	s_tag_block_definition<s_forge_color_block_definition> nicename("Forge Colors") forge_colors_block; 
	TagReference nicename("Game Engine Globals") game_engine_globals_reference; 
	TagReference nicename("Multiplayer Globals") multiplayer_globals_reference; 
	TagReference nicename("Survival Globals") survival_globals_reference; 
	TagReference nicename("Object Type List") object_type_list_reference; 
	s_tag_block_definition<s_cinematic_anchor_block_definition> nicename("Cinematic Anchors") cinematic_anchors_block; 
	s_tag_block_definition<s_metagame_global_block_definition> nicename("Metagame Globals") metagame_globals_block; 
	TagReference nicename("Medal Globals") medal_globals_reference; 
	// comment
	unsigned int __unknown56; 
	unsigned int __unknown57; 
	unsigned int __unknown58; 
	unsigned int __unknown59; 
	unsigned int nicename("String Count") string_count; 
	unsigned int nicename("Locale Table Size") locale_table_size; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset; 
	unsigned char nicename("Index Table Hash") index_table_hash[20];
	unsigned char nicename("String Data Hash") string_data_hash[20];
	unsigned int __unknown60; 
	unsigned int __unknown61; 
	// comment
	unsigned int __unknown62; 
	unsigned int __unknown63; 
	unsigned int __unknown64; 
	unsigned int __unknown65; 
	unsigned int nicename("String Count") string_count2; 
	unsigned int nicename("Locale Table Size") locale_table_size2; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset2; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset2; 
	unsigned char nicename("Index Table Hash") index_table_hash2[20];
	unsigned char nicename("String Data Hash") string_data_hash2[20];
	unsigned int __unknown66; 
	unsigned int __unknown67; 
	// comment
	unsigned int __unknown68; 
	unsigned int __unknown69; 
	unsigned int __unknown70; 
	unsigned int __unknown71; 
	unsigned int nicename("String Count") string_count3; 
	unsigned int nicename("Locale Table Size") locale_table_size3; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset3; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset3; 
	unsigned char nicename("Index Table Hash") index_table_hash3[20];
	unsigned char nicename("String Data Hash") string_data_hash3[20];
	unsigned int __unknown72; 
	unsigned int __unknown73; 
	// comment
	unsigned int __unknown74; 
	unsigned int __unknown75; 
	unsigned int __unknown76; 
	unsigned int __unknown77; 
	unsigned int nicename("String Count") string_count4; 
	unsigned int nicename("Locale Table Size") locale_table_size4; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset4; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset4; 
	unsigned char nicename("Index Table Hash") index_table_hash4[20];
	unsigned char nicename("String Data Hash") string_data_hash4[20];
	unsigned int __unknown78; 
	unsigned int __unknown79; 
	// comment
	unsigned int __unknown80; 
	unsigned int __unknown81; 
	unsigned int __unknown82; 
	unsigned int __unknown83; 
	unsigned int nicename("String Count") string_count5; 
	unsigned int nicename("Locale Table Size") locale_table_size5; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset5; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset5; 
	unsigned char nicename("Index Table Hash") index_table_hash5[20];
	unsigned char nicename("String Data Hash") string_data_hash5[20];
	unsigned int __unknown84; 
	unsigned int __unknown85; 
	// comment
	unsigned int __unknown86; 
	unsigned int __unknown87; 
	unsigned int __unknown88; 
	unsigned int __unknown89; 
	unsigned int nicename("String Count") string_count6; 
	unsigned int nicename("Locale Table Size") locale_table_size6; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset6; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset6; 
	unsigned char nicename("Index Table Hash") index_table_hash6[20];
	unsigned char nicename("String Data Hash") string_data_hash6[20];
	unsigned int __unknown90; 
	unsigned int __unknown91; 
	// comment
	unsigned int __unknown92; 
	unsigned int __unknown93; 
	unsigned int __unknown94; 
	unsigned int __unknown95; 
	unsigned int nicename("String Count") string_count7; 
	unsigned int nicename("Locale Table Size") locale_table_size7; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset7; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset7; 
	unsigned char nicename("Index Table Hash") index_table_hash7[20];
	unsigned char nicename("String Data Hash") string_data_hash7[20];
	unsigned int __unknown96; 
	unsigned int __unknown97; 
	// comment
	unsigned int __unknown98; 
	unsigned int __unknown99; 
	unsigned int __unknown100; 
	unsigned int __unknown101; 
	unsigned int nicename("String Count") string_count8; 
	unsigned int nicename("Locale Table Size") locale_table_size8; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset8; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset8; 
	unsigned char nicename("Index Table Hash") index_table_hash8[20];
	unsigned char nicename("String Data Hash") string_data_hash8[20];
	unsigned int __unknown102; 
	unsigned int __unknown103; 
	// comment
	unsigned int __unknown104; 
	unsigned int __unknown105; 
	unsigned int __unknown106; 
	unsigned int __unknown107; 
	unsigned int nicename("String Count") string_count9; 
	unsigned int nicename("Locale Table Size") locale_table_size9; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset9; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset9; 
	unsigned char nicename("Index Table Hash") index_table_hash9[20];
	unsigned char nicename("String Data Hash") string_data_hash9[20];
	unsigned int __unknown108; 
	unsigned int __unknown109; 
	// comment
	unsigned int __unknown110; 
	unsigned int __unknown111; 
	unsigned int __unknown112; 
	unsigned int __unknown113; 
	unsigned int nicename("String Count") string_count10; 
	unsigned int nicename("Locale Table Size") locale_table_size10; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset10; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset10; 
	unsigned char nicename("Index Table Hash") index_table_hash10[20];
	unsigned char nicename("String Data Hash") string_data_hash10[20];
	unsigned int __unknown114; 
	unsigned int __unknown115; 
	// comment
	unsigned int __unknown116; 
	unsigned int __unknown117; 
	unsigned int __unknown118; 
	unsigned int __unknown119; 
	unsigned int nicename("String Count") string_count11; 
	unsigned int nicename("Locale Table Size") locale_table_size11; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset11; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset11; 
	unsigned char nicename("Index Table Hash") index_table_hash11[20];
	unsigned char nicename("String Data Hash") string_data_hash11[20];
	unsigned int __unknown120; 
	unsigned int __unknown121; 
	// comment
	unsigned int __unknown122; 
	unsigned int __unknown123; 
	unsigned int __unknown124; 
	unsigned int __unknown125; 
	unsigned int nicename("String Count") string_count12; 
	unsigned int nicename("Locale Table Size") locale_table_size12; 
	unsigned int nicename("Locale Index Table Offset") locale_index_table_offset12; 
	unsigned int nicename("Locale Data Index Offset") locale_data_index_offset12; 
	unsigned char nicename("Index Table Hash") index_table_hash12[20];
	unsigned char nicename("String Data Hash") string_data_hash12[20];
	unsigned int __unknown126; 
	unsigned int __unknown127; 
	TagReference nicename("Rasterizer Globals") rasterizer_globals_reference; 
	TagReference nicename("Default Camera Effect") default_camera_effect_reference; 
	TagReference nicename("Default Wind") default_wind_reference; 
	TagReference nicename("Weather Globals") weather_globals_reference; 
	TagReference nicename("Default Damage Effect") default_damage_effect_reference; 
	TagReference nicename("Default Collision Damage") default_collision_damage_reference; 
	string_id __unknown_material; 
	string_id __unknown_material_2; 
	signed short __unknown_global_material_index; 
	signed short __unknown_2_global_material_index; 
	TagReference nicename("Effect Globals") effect_globals_reference; 
	TagReference nicename("Collision Filter") collision_filter_reference; 
	TagReference nicename("Grounded Friction") grounded_friction_reference; 
	s_tag_block_definition<s_unknown3_block_definition> __unknown128_block; 
	TagReference nicename("Incident Globals") incident_globals_reference; 
	TagReference nicename("Player Grade Globals") player_grade_globals_reference; 
	TagReference nicename("Player Customization Gobals") player_customization_gobals_reference; 
	TagReference nicename("Loadout Globals") loadout_globals_reference; 
	TagReference nicename("Challenge Gloabls") challenge_gloabls_reference; 
	TagReference nicename("Reward Globals") reward_globals_reference; 
	TagReference nicename("Achievement Globals") achievement_globals_reference; 
	TagReference nicename("Avatar Award Globals") avatar_award_globals_reference; 
	TagReference nicename("Performance Throttle Globals") performance_throttle_globals_reference; 
	s_tag_block_definition<s_unknown4_block_definition> __unknown129_block; 
	s_tag_block_definition<s_unknown5_block_definition> __unknown130_block; 
	s_tag_block_definition<s_alt_material_block_definition> nicename("Alt Materials") alt_materials_block; 
	Unknown32 __unknown131; 

	struct nicename("havok_cleanup_resource") s_havok_cleanup_resource_block_definition
	{
		TagReference nicename("Object Cleanup Effect") object_cleanup_effect_reference; 
	};

	struct nicename("sound_global") s_sound_global_block_definition
	{
		struct nicename("Fireteam Sounds") s_fireteam_sound_block_definition;

		TagReference nicename("Sound Classes") sound_classes_reference; 
		TagReference nicename("Sound Effects") sound_effects_reference; 
		TagReference nicename("Sound Mastering") sound_mastering_reference; 
		TagReference nicename("Sound Mix") sound_mix_reference; 
		TagReference nicename("Sound Combat Dialogue Constants") sound_combat_dialogue_constants_reference; 
		TagReference nicename("Sound Global Propagation") sound_global_propagation_reference; 
		s_tag_block_definition<s_fireteam_sound_block_definition> nicename("Fireteam Sounds") fireteam_sounds_block; 

		struct nicename("fireteam_sound") s_fireteam_sound_block_definition
		{
			TagReference nicename("Sound") sound_reference; 
		};
	};

	struct nicename("ai_global") s_ai_global_block_definition
	{
		struct nicename("Gravemind Properties") s_gravemind_property_block_definition;
		struct nicename("Formations") s_formation_block_definition;
		struct nicename("Squad Templates") s_squad_template_block_definition;
		struct nicename("Performance Templates") s_performance_template_block_definition;
		struct s_unknown_block_definition;
		struct nicename("Vision Trait Definitions") s_vision_trait_definition_block_definition;
		struct nicename("Hearing Trait Definitions") s_hearing_trait_definition_block_definition;
		struct nicename("Luck Trait Definitions") s_luck_trait_definition_block_definition;
		struct nicename("Grenade Trait Definitions") s_grenade_trait_definition_block_definition;

		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float nicename("Danger Broadly Facing") danger_broadly_facing; 
		float nicename("Danger Shooting Near") danger_shooting_near; 
		float nicename("Danger Shooting At") danger_shooting_at; 
		float nicename("Danger Extremely Close") danger_extremely_close; 
		float nicename("Danger Shield Damage") danger_shield_damage; 
		float nicename("Danger Extended Shield Damage") danger_extended_shield_damage; 
		float nicename("Danger Body Damage") danger_body_damage; 
		float nicename("Danger Extended Body Damage") danger_extended_body_damage; 
		TagReference nicename("Global Dialogue") global_dialogue_reference; 
		string_id nicename("Default Mission Dialogue Sound Effect") default_mission_dialogue_sound_effect; 
		float nicename("Jump Down") jump_down; 
		float nicename("Jump Step") jump_step; 
		float nicename("Jump Crouch") jump_crouch; 
		float nicename("Jump Stand") jump_stand; 
		float nicename("Jump Storey") jump_storey; 
		float nicename("Jump Tower") jump_tower; 
		float __unknown4; 
		float nicename("Max Jump Down Height Down") max_jump_down_height_down; 
		float nicename("Max Jump Down Height Step") max_jump_down_height_step; 
		float nicename("Max Jump Down Height Crouch") max_jump_down_height_crouch; 
		float nicename("Max Jump Down Height Stand") max_jump_down_height_stand; 
		float nicename("Max Jump Down Height Storey") max_jump_down_height_storey; 
		float nicename("Max Jump Down Height Tower") max_jump_down_height_tower; 
		float __unknown5; 
		float nicename("Hoist Step min") hoist_step_min; 
		float nicename("Hoist Step max") hoist_step_max; 
		float nicename("Hoist Crouch min") hoist_crouch_min; 
		float nicename("Hoist Crouch max") hoist_crouch_max; 
		float nicename("Hoist Stand min") hoist_stand_min; 
		float nicename("Hoist Stand max") hoist_stand_max; 
		float nicename("Vault Step min") vault_step_min; 
		float nicename("Vault Step max") vault_step_max; 
		float nicename("Vault Crouch min") vault_crouch_min; 
		float nicename("Vault Crouch max") vault_crouch_max; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		s_tag_block_definition<s_gravemind_property_block_definition> nicename("Gravemind Properties") gravemind_properties_block; 
		float nicename("Scary Target Threshold") scary_target_threshold; 
		float nicename("Scary Weapon Threshold") scary_weapon_threshold; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		s_tag_block_definition<s_formation_block_definition> nicename("Formations") formations_block; 
		s_tag_block_definition<s_squad_template_block_definition> nicename("Squad Templates") squad_templates_block; 
		s_tag_block_definition<s_performance_template_block_definition> nicename("Performance Templates") performance_templates_block; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		s_tag_block_definition<s_unknown_block_definition> __unknown23_block; 
		Unknown32 __unknown24; 
		Unknown32 __unknown25; 
		Unknown32 __unknown26; 
		Unknown32 __unknown27; 
		Unknown32 __unknown28; 
		Unknown32 __unknown29; 
		Unknown32 __unknown30; 
		Unknown32 __unknown31; 
		Unknown32 __unknown32; 
		Unknown32 __unknown33; 
		Unknown32 __unknown34; 
		Unknown32 __unknown35; 
		Unknown32 __unknown36; 
		Unknown32 __unknown37; 
		signed short __unknown38; 
		signed short __unknown39; 
		signed short __unknown40; 
		signed short __unknown41; 
		signed short __unknown42; 
		signed short __unknown43; 
		s_tag_block_definition<s_vision_trait_definition_block_definition> nicename("Vision Trait Definitions") vision_trait_definitions_block; 
		s_tag_block_definition<s_hearing_trait_definition_block_definition> nicename("Hearing Trait Definitions") hearing_trait_definitions_block; 
		s_tag_block_definition<s_luck_trait_definition_block_definition> nicename("Luck Trait Definitions") luck_trait_definitions_block; 
		s_tag_block_definition<s_grenade_trait_definition_block_definition> nicename("Grenade Trait Definitions") grenade_trait_definitions_block; 
		Unknown32 __unknown44; 
		Unknown32 __unknown45; 
		Unknown32 __unknown46; 
		signed short __unknown47; 
		signed short __unknown48; 
		signed short __unknown49; 
		signed short __unknown50; 

		struct nicename("gravemind_property") s_gravemind_property_block_definition
		{
			float nicename("Minimum Retreat Time") minimum_retreat_time; 
			float nicename("Ideal Retreat Time") ideal_retreat_time; 
			float nicename("Maximum Retreat Time") maximum_retreat_time; 
		};

		struct nicename("formation") s_formation_block_definition
		{
			TagReference nicename("Formation") formation_reference; 
		};

		struct nicename("squad_template") s_squad_template_block_definition
		{
			struct nicename("Templates") s_template_block_definition;

			string_id nicename("Name") name; 
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 
			s_tag_block_definition<s_template_block_definition> nicename("Templates") templates_block; 

			struct nicename("template") s_template_block_definition
			{
				TagReference nicename("Template") template_reference; 
			};
		};

		struct nicename("performance_template") s_performance_template_block_definition
		{
			struct nicename("Characters") s_character_block_definition;

			string_id nicename("Name") name; 
			s_tag_block_definition<s_character_block_definition> nicename("Characters") characters_block; 
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 

			struct nicename("character") s_character_block_definition
			{
				struct nicename("Templates") s_template_block_definition;

				string_id nicename("Name") name; 
				s_tag_block_definition<s_template_block_definition> nicename("Templates") templates_block; 

				struct nicename("template") s_template_block_definition
				{
					TagReference nicename("Template") template_reference; 
				};
			};
		};

		struct s_unknown_block_definition
		{
			struct s_unknown2_block_definition;
			struct s_unknown3_block_definition;
			struct s_unknown4_block_definition;

			string_id __unknown; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
			s_tag_block_definition<s_unknown3_block_definition> __unknown3_block; 
			s_tag_block_definition<s_unknown4_block_definition> __unknown4_block; 

			struct s_unknown2_block_definition
			{
				float __unknown; 
			};

			struct s_unknown3_block_definition
			{
				string_id __unknown; 
			};

			struct s_unknown4_block_definition
			{
				Unknown32 __unknown; 
				Unknown32 __unknown2; 
				Unknown32 __unknown3; 
				Unknown32 __unknown4; 
				Unknown32 __unknown5; 
				Unknown32 __unknown6; 
				Unknown32 __unknown7; 
				Unknown32 __unknown8; 
				Unknown32 __unknown9; 
				Unknown32 __unknown10; 
				Unknown32 __unknown11; 
			};
		};

		struct nicename("vision_trait_definition") s_vision_trait_definition_block_definition
		{
			float __unknown; 
			float __unknown2; 
		};

		struct nicename("hearing_trait_definition") s_hearing_trait_definition_block_definition
		{
			float __unknown; 
		};

		struct nicename("luck_trait_definition") s_luck_trait_definition_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			float __unknown11; 
		};

		struct nicename("grenade_trait_definition") s_grenade_trait_definition_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
		};
	};

	struct nicename("damage_table") s_damage_table_block_definition
	{
		struct nicename("Damage Groups") s_damage_group_block_definition;

		s_tag_block_definition<s_damage_group_block_definition> nicename("Damage Groups") damage_groups_block; 

		struct nicename("damage_group") s_damage_group_block_definition
		{
			struct nicename("Armor Modifiers") s_armor_modifier_block_definition;

			string_id nicename("Name") name; 
			s_tag_block_definition<s_armor_modifier_block_definition> nicename("Armor Modifiers") armor_modifiers_block; 

			struct nicename("armor_modifier") s_armor_modifier_block_definition
			{
				string_id nicename("Name") name; 
				float nicename("Damage Multiplier") damage_multiplier; 
			};
		};
	};

	struct nicename("sound") s_sound_block_definition
	{
		TagReference nicename("Sound (Obsolete)") sound_obsolete_reference; 
	};

	struct nicename("camera") s_camera_block_definition
	{
		TagReference nicename("Default Unit Track") default_unit_track_reference; 
		DataReference __unknown_data_reference; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		float __unknown20; 
		float __unknown21; 
		float __unknown22; 
		float __unknown23; 
		float __unknown24; 
		float __unknown25; 
		float __unknown26; 
		float __unknown27; 
		signed short __unknown28; 
		signed short __unknown29; 
		float __unknown30; 
		float __unknown31; 
		float __unknown32; 
		float __unknown33; 
		float __unknown34; 
		float __unknown35; 
		float __unknown36; 
		float __unknown37; 
		float __unknown38; 
		float __unknown39; 
		float __unknown40; 
		float __unknown41; 
		float __unknown42; 
		float __unknown43; 
		float __unknown44; 
		float __unknown45; 
		float __unknown46; 
		float __unknown47; 
	};

	struct nicename("thumbstick_deadzone") s_thumbstick_deadzone_block_definition
	{
		float nicename("Minimum") minimum; 
		float nicename("Maximum") maximum; 
	};

	struct nicename("player_control") s_player_control_block_definition
	{
		struct s_unknown_block_definition;
		struct s_unknown2_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
		float nicename("Magnetism Friction") magnetism_friction; 
		float nicename("Magnetism Adhesion") magnetism_adhesion; 
		float nicename("Inconsequential Target Scale") inconsequential_target_scale; 
		float nicename("Crosshair Location x") crosshair_location_x; 
		float nicename("Crosshair Location y") crosshair_location_y; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float nicename("Look Autoleveling Scale") look_autoleveling_scale; 
		float nicename("Gravity Scale") gravity_scale; 
		signed int nicename("Minimum Autoleveling Ticks") minimum_autoleveling_ticks; 
		float nicename("Minimum Angle for Vehicle Flipping") minimum_angle_for_vehicle_flipping; 
		float nicename("Minimum Action Hold Time") minimum_action_hold_time; 
		Unknown32 __unknown6; 
		signed int __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		float __unknown20; 
		Unknown32 __unknown21; 

		struct s_unknown_block_definition
		{
			struct s_unknown2_block_definition;

			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed char __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown11_block; 

			struct s_unknown2_block_definition
			{
				DataReference __unknown_data_reference; 
			};
		};

		struct s_unknown2_block_definition
		{
			struct s_unknown_block_definition;

			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed char __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 

			struct s_unknown_block_definition
			{
				DataReference __unknown_data_reference; 
			};
		};
	};

	struct nicename("player_trait_default") s_player_trait_default_block_definition
	{
		struct nicename("Shields and Health") s_shields_and_health_block_definition;
		struct nicename("Weapons and Damage") s_weapons_and_damage_block_definition;
		struct nicename("Movement") s_movement_block_definition;
		struct nicename("Appearance") s_appearance_block_definition;
		struct nicename("HUD") s_hud_block_definition;

		s_tag_block_definition<s_shields_and_health_block_definition> nicename("Shields and Health") shields_and_health_block; 
		s_tag_block_definition<s_weapons_and_damage_block_definition> nicename("Weapons and Damage") weapons_and_damage_block; 
		s_tag_block_definition<s_movement_block_definition> nicename("Movement") movement_block; 
		s_tag_block_definition<s_appearance_block_definition> nicename("Appearance") appearance_block; 
		s_tag_block_definition<s_hud_block_definition> nicename("HUD") hud_block; 

		struct nicename("shields_and_health") s_shields_and_health_block_definition
		{
			signed char nicename("Damage Resistance") damage_resistance; 
			signed char nicename("Health Multiplier") health_multiplier; 
			signed char nicename("Health Recharge Rate") health_recharge_rate; 
			signed char nicename("Shield Multiplier") shield_multiplier; 
			signed char nicename("Shield Recharge Rate") shield_recharge_rate; 
			signed char nicename("Shield Recharge Rate 2") shield_recharge_rate_2; 
			signed char nicename("Headshot Immunity") headshot_immunity; 
			signed char nicename("Shield Vampirism") shield_vampirism; 
			signed char nicename("Assassination Immunity") assassination_immunity; 
			signed char nicename("Deathless") deathless; 
			signed char __unknown; 
			signed char __unknown2; 
		};

		struct nicename("weapons_and_damage") s_weapons_and_damage_block_definition
		{
			signed char nicename("Damage Modifier") damage_modifier; 
			signed char nicename("Melee Damage Modifier") melee_damage_modifier; 
			signed char nicename("Grenade Regeneration") grenade_regeneration; 
			signed char nicename("Weapon Pickup") weapon_pickup; 
			signed char nicename("Grenade Count") grenade_count; 
			signed char nicename("Infinite Ammo") infinite_ammo; 
			signed char nicename("Equipment Usage") equipment_usage; 
			signed char nicename("Equipment Drop") equipment_drop; 
			signed char nicename("Infinite Equipment") infinite_equipment; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			string_id nicename("Primary Weapon") primary_weapon; 
			string_id nicename("Secondary Weapon") secondary_weapon; 
			string_id nicename("Equipment") equipment; 
		};

		struct nicename("movement") s_movement_block_definition
		{
			signed char nicename("Player Speed") player_speed; 
			signed char nicename("Player Gravity") player_gravity; 
			signed char nicename("Vehicle Use") vehicle_use; 
			signed char nicename("Double Jump") double_jump; 
			// comment
			signed int nicename("Jump Height") jump_height; 
		};

		struct nicename("appearance") s_appearance_block_definition
		{
			signed char nicename("Active Camo") active_camo; 
			signed char nicename("Waypoint") waypoint; 
			signed char nicename("Visible Name") visible_name; 
			signed char nicename("Aura") aura; 
			signed char nicename("Forced Color") forced_color; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
		};

		struct nicename("hud") s_hud_block_definition
		{
			signed char nicename("Motion Tracker Mode") motion_tracker_mode; 
			signed char nicename("Motion Tracker Range") motion_tracker_range; 
			signed char nicename("Directional Damage Indicator") directional_damage_indicator; 
			signed char __unknown; 
		};
	};

	struct nicename("difficulty") s_difficulty_block_definition
	{
		float nicename("Easy Enemy Damage") easy_enemy_damage; 
		float nicename("Normal Enemy Damage") normal_enemy_damage; 
		float nicename("Hard Enemy Damage") hard_enemy_damage; 
		float nicename("Impossible Enemy Damage") impossible_enemy_damage; 
		float nicename("Easy Enemy Vitality") easy_enemy_vitality; 
		float nicename("Normal Enemy Vitality") normal_enemy_vitality; 
		float nicename("Hard Enemy Vitality") hard_enemy_vitality; 
		float nicename("Impossible Enemy Vitality") impossible_enemy_vitality; 
		float nicename("Easy Enemy Shield") easy_enemy_shield; 
		float nicename("Normal Enemy Shield") normal_enemy_shield; 
		float nicename("Hard Enemy Shield") hard_enemy_shield; 
		float nicename("Impossible Enemy Shield") impossible_enemy_shield; 
		float nicename("Easy Enemy Recharge") easy_enemy_recharge; 
		float nicename("Normal Enemy Recharge") normal_enemy_recharge; 
		float nicename("Hard Enemy Recharge") hard_enemy_recharge; 
		float nicename("Impossible Enemy Recharge") impossible_enemy_recharge; 
		float nicename("Easy Friend Damage") easy_friend_damage; 
		float nicename("Normal Friend Damage") normal_friend_damage; 
		float nicename("Hard Friend Damage") hard_friend_damage; 
		float nicename("Impossible Friend Damage") impossible_friend_damage; 
		float nicename("Easy Friend Vitality") easy_friend_vitality; 
		float nicename("Normal Friend Vitality") normal_friend_vitality; 
		float nicename("Hard Friend Vitality") hard_friend_vitality; 
		float nicename("Impossible Friend Vitality") impossible_friend_vitality; 
		float nicename("Easy Friend Shield") easy_friend_shield; 
		float nicename("Normal Friend Shield") normal_friend_shield; 
		float nicename("Hard Friend Shield") hard_friend_shield; 
		float nicename("Impossible Friend Shield") impossible_friend_shield; 
		float nicename("Easy Friend Recharge") easy_friend_recharge; 
		float nicename("Normal Friend Recharge") normal_friend_recharge; 
		float nicename("Hard Friend Recharge") hard_friend_recharge; 
		float nicename("Impossible Friend Recharge") impossible_friend_recharge; 
		float nicename("Easy Infection Forms") easy_infection_forms; 
		float nicename("Normal Infection Forms") normal_infection_forms; 
		float nicename("Hard Infection Forms") hard_infection_forms; 
		float nicename("Impossible Infection Forms") impossible_infection_forms; 
		float nicename("Easy Unknown") easy_unknown; 
		float nicename("Normal Unknown") normal_unknown; 
		float nicename("Hard Unknown") hard_unknown; 
		float nicename("Impossible Unknown") impossible_unknown; 
		float nicename("Easy Rate of Fire") easy_rate_of_fire; 
		float nicename("Normal Rate of Fire") normal_rate_of_fire; 
		float nicename("Hard Rate of Fire") hard_rate_of_fire; 
		float nicename("Impossible Rate of Fire") impossible_rate_of_fire; 
		float nicename("Easy Projectile Error") easy_projectile_error; 
		float nicename("Normal Projectile Error") normal_projectile_error; 
		float nicename("Hard Projectile Error") hard_projectile_error; 
		float nicename("Impossible Projectile Error") impossible_projectile_error; 
		float nicename("Easy Burst Error") easy_burst_error; 
		float nicename("Normal Burst Error") normal_burst_error; 
		float nicename("Hard Burst Error") hard_burst_error; 
		float nicename("Impossible Burst Error") impossible_burst_error; 
		float nicename("Easy Target Delay") easy_target_delay; 
		float nicename("Normal Target Delay") normal_target_delay; 
		float nicename("Hard Target Delay") hard_target_delay; 
		float nicename("Impossible Target Delay") impossible_target_delay; 
		float nicename("Easy Burst Separation") easy_burst_separation; 
		float nicename("Normal Burst Separation") normal_burst_separation; 
		float nicename("Hard Burst Separation") hard_burst_separation; 
		float nicename("Impossible Burst Separation") impossible_burst_separation; 
		float nicename("Easy Target Tracking") easy_target_tracking; 
		float nicename("Normal Target Tracking") normal_target_tracking; 
		float nicename("Hard Target Tracking") hard_target_tracking; 
		float nicename("Impossible Target Tracking") impossible_target_tracking; 
		float nicename("Easy Target Leading") easy_target_leading; 
		float nicename("Normal Target Leading") normal_target_leading; 
		float nicename("Hard Target Leading") hard_target_leading; 
		float nicename("Impossible Target Leading") impossible_target_leading; 
		float nicename("Easy Overcharge Chance") easy_overcharge_chance; 
		float nicename("Normal Overcharge Chance") normal_overcharge_chance; 
		float nicename("Hard Overcharge Chance") hard_overcharge_chance; 
		float nicename("Impossible Overcharge Chance") impossible_overcharge_chance; 
		float nicename("Easy Special Fire Delay") easy_special_fire_delay; 
		float nicename("Normal Special Fire Delay") normal_special_fire_delay; 
		float nicename("Hard Special Fire Delay") hard_special_fire_delay; 
		float nicename("Impossible Special Fire Delay") impossible_special_fire_delay; 
		float nicename("Easy Guidance vs Player") easy_guidance_vs_player; 
		float nicename("Normal Guidance vs Player") normal_guidance_vs_player; 
		float nicename("Hard Guidance vs Player") hard_guidance_vs_player; 
		float nicename("Impossible Guidance vs Player") impossible_guidance_vs_player; 
		float nicename("Easy Melee Delay Base") easy_melee_delay_base; 
		float nicename("Normal Melee Delay Base") normal_melee_delay_base; 
		float nicename("Hard Melee Delay Base") hard_melee_delay_base; 
		float nicename("Impossible Melee Delay Base") impossible_melee_delay_base; 
		float nicename("Easy Melee Delay Scale") easy_melee_delay_scale; 
		float nicename("Normal Melee Delay Scale") normal_melee_delay_scale; 
		float nicename("Hard Melee Delay Scale") hard_melee_delay_scale; 
		float nicename("Impossible Melee Delay Scale") impossible_melee_delay_scale; 
		float nicename("Easy Unknown") easy_unknown2; 
		float nicename("Normal Unknown") normal_unknown2; 
		float nicename("Hard Unknown") hard_unknown2; 
		float nicename("Impossible Unknown") impossible_unknown2; 
		float nicename("Easy Grenade Chance Scale") easy_grenade_chance_scale; 
		float nicename("Normal Grenade Chance Scale") normal_grenade_chance_scale; 
		float nicename("Hard Grenade Chance Scale") hard_grenade_chance_scale; 
		float nicename("Impossible Grenade Chance Scale") impossible_grenade_chance_scale; 
		float nicename("Easy Grenade Timer Scale") easy_grenade_timer_scale; 
		float nicename("Normal Grenade Timer Scale") normal_grenade_timer_scale; 
		float nicename("Hard Grenade Timer Scale") hard_grenade_timer_scale; 
		float nicename("Impossible Grenade Timer Scale") impossible_grenade_timer_scale; 
		float nicename("Easy Unknown") easy_unknown3; 
		float nicename("Normal Unknown") normal_unknown3; 
		float nicename("Hard Unknown") hard_unknown3; 
		float nicename("Impossible Unknown") impossible_unknown3; 
		float nicename("Easy Unknown") easy_unknown4; 
		float nicename("Normal Unknown") normal_unknown4; 
		float nicename("Hard Unknown") hard_unknown4; 
		float nicename("Impossible Unknown") impossible_unknown4; 
		float nicename("Easy Unknown") easy_unknown5; 
		float nicename("Normal Unknown") normal_unknown5; 
		float nicename("Hard Unknown") hard_unknown5; 
		float nicename("Impossible Unknown") impossible_unknown5; 
		float nicename("Easy Major Upgrade Normal") easy_major_upgrade_normal; 
		float nicename("Normal Major Upgrade Normal") normal_major_upgrade_normal; 
		float nicename("Hard Major Upgrade Normal") hard_major_upgrade_normal; 
		float nicename("Impossible Major Upgrade Normal") impossible_major_upgrade_normal; 
		float nicename("Easy Major Upgrade Few") easy_major_upgrade_few; 
		float nicename("Normal Major Upgrade Few") normal_major_upgrade_few; 
		float nicename("Hard Major Upgrade Few") hard_major_upgrade_few; 
		float nicename("Impossible Major Upgrade Few") impossible_major_upgrade_few; 
		float nicename("Easy Major Upgrade Many") easy_major_upgrade_many; 
		float nicename("Normal Major Upgrade Many") normal_major_upgrade_many; 
		float nicename("Hard Major Upgrade Many") hard_major_upgrade_many; 
		float nicename("Impossible Major Upgrade Many") impossible_major_upgrade_many; 
		float nicename("Easy Player Vehicle Ram Chance") easy_player_vehicle_ram_chance; 
		float nicename("Normal Player Vehicle Ram Chance") normal_player_vehicle_ram_chance; 
		float nicename("Hard Player Vehicle Ram Chance") hard_player_vehicle_ram_chance; 
		float nicename("Impossible Player Vehicle Ram Chance") impossible_player_vehicle_ram_chance; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		Unknown32 __unknown16; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		Unknown32 __unknown23; 
		Unknown32 __unknown24; 
		Unknown32 __unknown25; 
		Unknown32 __unknown26; 
		Unknown32 __unknown27; 
		Unknown32 __unknown28; 
		Unknown32 __unknown29; 
		Unknown32 __unknown30; 
		Unknown32 __unknown31; 
		Unknown32 __unknown32; 
		Unknown32 __unknown33; 
	};

	struct s_unknown_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		float __unknown20; 
		float __unknown21; 
		float __unknown22; 
		float __unknown23; 
		float __unknown24; 
		float __unknown25; 
		float __unknown26; 
		float __unknown27; 
		float __unknown28; 
		float __unknown29; 
		float __unknown30; 
		float __unknown31; 
		float __unknown32; 
		float __unknown33; 
	};

	struct nicename("grenade") s_grenade_block_definition
	{
		signed short nicename("Maximum Count") maximum_count; 
		signed short __unknown; 
		float __unknown2; 
		TagReference nicename("Throwing Effect") throwing_effect_reference; 
		TagReference nicename("Equipment") equipment_reference; 
		TagReference nicename("Projectile") projectile_reference; 
	};

	struct nicename("soft_barrier_property") s_soft_barrier_property_block_definition
	{
		Unknown32 __biped_give; 
		Unknown32 __biped_bounciness; 
		Unknown32 __biped_bumpiness; 
		Unknown32 __unknown; 
		Unknown32 __vehicle_give; 
		Unknown32 __vehicle_bounciness; 
		Unknown32 __vehicle_bumpiness; 
	};

	struct nicename("interface_tag") s_interface_tag_block_definition
	{
		TagReference nicename("Spinner") spinner_reference; 
		TagReference nicename("Obsolete") obsolete_reference; 
		TagReference nicename("Screen Color Table") screen_color_table_reference; 
		TagReference nicename("HUD Color Table") hud_color_table_reference; 
		TagReference nicename("Editor Color Table") editor_color_table_reference; 
		TagReference nicename("Dialog Color Table") dialog_color_table_reference; 
		TagReference nicename("Motion Sensor Sweep Bitmap") motion_sensor_sweep_bitmap_reference; 
		TagReference nicename("Motion Sensor Sweep Bitmap Mask") motion_sensor_sweep_bitmap_mask_reference; 
		TagReference nicename("Multiplayer HUD Bitmap") multiplayer_hud_bitmap_reference; 
		TagReference nicename("HUD Digits Definition") hud_digits_definition_reference; 
		TagReference nicename("Motion Sensor Blip Bitmap") motion_sensor_blip_bitmap_reference; 
		TagReference nicename("Interface Goo Map 1") interface_goo_map_1_reference; 
		TagReference nicename("Interface Goo Map 2") interface_goo_map_2_reference; 
		TagReference nicename("Interface Goo Map 3") interface_goo_map_3_reference; 
		TagReference nicename("Main Menu UI Globals") main_menu_ui_globals_reference; 
		TagReference nicename("Single Player/Survival UI Globals") single_player_survival_ui_globals_reference; 
		TagReference nicename("Multiplayer UI Globals") multiplayer_ui_globals_reference; 
		TagReference nicename("HUD Globals") hud_globals_reference; 
	};

	struct nicename("player_information") s_player_information_block_definition
	{
		float nicename("Walking Speed") walking_speed; 
		float nicename("Run Forward") run_forward; 
		float nicename("Run Backward") run_backward; 
		float nicename("Run Sideways") run_sideways; 
		float nicename("Run Acceleration") run_acceleration; 
		float nicename("Sneak Forward") sneak_forward; 
		float nicename("Sneak Backward") sneak_backward; 
		float nicename("Sneak Sideways") sneak_sideways; 
		float nicename("Sneak Acceleration") sneak_acceleration; 
		float nicename("Airborne Acceleration") airborne_acceleration; 
		float nicename("Grenade Origin x") grenade_origin_x; 
		float nicename("Grenade Origin y") grenade_origin_y; 
		float nicename("Grenade Origin z") grenade_origin_z; 
		DataReference nicename("Stun Function") stun_function_data_reference; 
		float nicename("First Person Idle Time min") first_person_idle_time_min; 
		float nicename("First Person Idle Time max") first_person_idle_time_max; 
		float nicename("First Person Skip Fraction") first_person_skip_fraction; 
		TagReference nicename("Timer Sound") timer_sound_reference; 
		TagReference nicename("Timer Sound Zero") timer_sound_zero_reference; 
		TagReference nicename("Respawn Effect") respawn_effect_reference; 
		TagReference __unknown_reference; 
		signed int nicename("Binoculars Zoom Count") binoculars_zoom_count; 
		float nicename("Binocular Zoom Range min") binocular_zoom_range_min; 
		float nicename("Binocular Zoom Range max") binocular_zoom_range_max; 
		TagReference nicename("Flashlight On") flashlight_on_reference; 
		TagReference nicename("Flashlight Off") flashlight_off_reference; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float nicename("Sprint Movement Speed Percentage") sprint_movement_speed_percentage; 
		float nicename("Sprint Look Speed Percentage") sprint_look_speed_percentage; 
		float __unknown8; 
		float __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		string_id nicename("Sprint") sprint; 
	};

	struct nicename("player_representation") s_player_representation_block_definition
	{
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		TagReference nicename("HUD") hud_reference; 
		TagReference nicename("First Person Hands") first_person_hands_reference; 
		TagReference nicename("First Person Body") first_person_body_reference; 
		TagReference nicename("Third Person Unit") third_person_unit_reference; 
		string_id nicename("Third Person Variant") third_person_variant; 
		TagReference nicename("Binoculars Zoom In Sound") binoculars_zoom_in_sound_reference; 
		TagReference nicename("Binoculars Zoom Out Sound") binoculars_zoom_out_sound_reference; 
		signed int nicename("Player Information Index") player_information_index; 
	};

	struct nicename("falling_damage") s_falling_damage_block_definition
	{
		TagReference nicename("Falling Damage") falling_damage_reference; 
		TagReference __unknown_reference; 
		TagReference nicename("Soft Landing") soft_landing_reference; 
		TagReference nicename("Hard Landing") hard_landing_reference; 
		TagReference nicename("Script Damage") script_damage_reference; 
		float nicename("Maximum Falling Distance") maximum_falling_distance; 
		TagReference nicename("Terminal Velocity Damage") terminal_velocity_damage_reference; 
		TagReference nicename("Missing Response") missing_response_reference; 
		TagReference __unknown2_reference; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		Unknown32 __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		Unknown32 __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
	};

	struct s_unknown2_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
	};

	struct nicename("material") s_material_block_definition
	{
		struct nicename("Object Water Drag Properties") s_object_water_drag_property_block_definition;
		struct nicename("Water Interaction") s_water_interaction_block_definition;

		string_id nicename("Name") name; 
		string_id nicename("Parent Name") parent_name; 
		signed short nicename("Parent Index") parent_index; 
		unsigned short nicename("Flags") flags; 
		string_id nicename("General Armor") general_armor; 
		string_id nicename("Specific Armor") specific_armor; 
		string_id nicename("Wet Armor") wet_armor; 
		signed short nicename("Wet Armor Index") wet_armor_index; 
		signed short __unknown; 
		signed short nicename("Wet Armor Reference Index") wet_armor_reference_index; 
		signed short __unknown2; 
		Unknown32 __unknown3; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Density") density; 
		TagReference nicename("Global Water Drag Properties") global_water_drag_properties_reference; 
		s_tag_block_definition<s_object_water_drag_property_block_definition> nicename("Object Water Drag Properties") object_water_drag_properties_block; 
		float nicename("Water Drag Unknown") water_drag_unknown; 
		float nicename("Water Drag Unknown") water_drag_unknown2; 
		float nicename("Water Drag Unknown") water_drag_unknown3; 
		float nicename("Water Drag Unknown") water_drag_unknown4; 
		float nicename("Water Drag Unknown") water_drag_unknown5; 
		float nicename("Water Drag Unknown") water_drag_unknown6; 
		Unknown32 __water_drag_unknown7; 
		TagReference nicename("Breakable Surface") breakable_surface_reference; 
		TagReference nicename("Sound Sweetener Small") sound_sweetener_small_reference; 
		TagReference nicename("Sound Sweetener Medium") sound_sweetener_medium_reference; 
		TagReference nicename("Sound Sweetener Large") sound_sweetener_large_reference; 
		TagReference nicename("Sound Sweetener Rolling") sound_sweetener_rolling_reference; 
		TagReference nicename("Sound Sweetener Grinding") sound_sweetener_grinding_reference; 
		TagReference nicename("Sound Sweetener Melee Small") sound_sweetener_melee_small_reference; 
		TagReference nicename("Sound Sweetener Melee Medium") sound_sweetener_melee_medium_reference; 
		TagReference nicename("Sound Sweetener Melee Large") sound_sweetener_melee_large_reference; 
		TagReference nicename("Effect Sweetener Small") effect_sweetener_small_reference; 
		TagReference nicename("Effect Sweetener Medium") effect_sweetener_medium_reference; 
		TagReference nicename("Effect Sweetener Large") effect_sweetener_large_reference; 
		TagReference nicename("Effect Sweetener Rolling") effect_sweetener_rolling_reference; 
		TagReference nicename("Effect Sweetener Grinding") effect_sweetener_grinding_reference; 
		TagReference nicename("Effect Sweetener Melee") effect_sweetener_melee_reference; 
		TagReference nicename("Water Ripple Small") water_ripple_small_reference; 
		TagReference nicename("Water Ripple Medium") water_ripple_medium_reference; 
		TagReference nicename("Water Ripple Large") water_ripple_large_reference; 
		signed int nicename("Sweetener Inheritance Flags") sweetener_inheritance_flags; 
		TagReference nicename("Material Effects") material_effects_reference; 
		s_tag_block_definition<s_water_interaction_block_definition> nicename("Water Interaction") water_interaction_block; 

		struct nicename("object_water_drag_property") s_object_water_drag_property_block_definition
		{
			TagReference nicename("Water Drag Properties") water_drag_properties_reference; 
		};

		struct nicename("water_interaction") s_water_interaction_block_definition
		{
			string_id nicename("Surface Name") surface_name; 
			string_id nicename("Submerged Name") submerged_name; 
			signed short nicename("Surface Index") surface_index; 
			signed short nicename("Submerged Index") submerged_index; 
		};
	};

	struct nicename("player_color") s_player_color_block_definition
	{
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
	};

	struct nicename("emblem_color") s_emblem_color_block_definition
	{
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
	};

	struct nicename("visor_color") s_visor_color_block_definition
	{
		string_id nicename("Name") name; 
		float nicename("Primary Color r") primary_color_r; 
		float nicename("Primary Color g") primary_color_g; 
		float nicename("Primary Color b") primary_color_b; 
		float nicename("Secondary Color r") secondary_color_r; 
		float nicename("Secondary Color g") secondary_color_g; 
		float nicename("Secondary Color b") secondary_color_b; 
	};

	struct nicename("forge_color") s_forge_color_block_definition
	{
		string_id nicename("Name") name; 
		float nicename("Color r") color_r; 
		float nicename("Color g") color_g; 
		float nicename("Color b") color_b; 
	};

	struct nicename("cinematic_anchor") s_cinematic_anchor_block_definition
	{
		TagReference nicename("Cinematic Anchor") cinematic_anchor_reference; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		Unknown32 __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
	};

	struct nicename("metagame_global") s_metagame_global_block_definition
	{
		struct nicename("Medals") s_medal_block_definition;
		struct nicename("Difficulty") s_difficulty_block_definition;
		struct nicename("Skulls") s_skull_block_definition;

		s_tag_block_definition<s_medal_block_definition> nicename("Medals") medals_block; 
		// comment
		s_tag_block_definition<s_difficulty_block_definition> nicename("Difficulty") difficulty_block; 
		// comment
		s_tag_block_definition<s_skull_block_definition> nicename("Skulls") skulls_block; 
		signed int __unknown; 
		signed int nicename("Death Penalty") death_penalty; 
		signed int nicename("Betrayal Penalty") betrayal_penalty; 
		float nicename("Multikill Window") multikill_window; 
		float nicename("EMP Window") emp_window; 

		struct nicename("medal") s_medal_block_definition
		{
			string_id nicename("Incident Name") incident_name; 
			float nicename("Multiplier") multiplier; 
		};

		struct nicename("difficulty") s_difficulty_block_definition
		{
			float nicename("Multiplier") multiplier; 
		};

		struct nicename("skull") s_skull_block_definition
		{
			float nicename("Multiplier") multiplier; 
		};
	};

	struct s_unknown3_block_definition
	{
		struct s_unknown_block_definition;

		float __unknown; 
		float __unknown2; 
		Unknown32 __unknown3; 
		DataReference __unknown4_data_reference; 
		DataReference __unknown5_data_reference; 
		DataReference __unknown6_data_reference; 
		s_tag_block_definition<s_unknown_block_definition> __unknown7_block; 

		struct s_unknown_block_definition
		{
			float __unknown; 
			float __unknown2; 
			float __unknown3; 
			float __unknown4; 
			DataReference __unknown5_data_reference; 
		};
	};

	struct s_unknown4_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
	};

	struct s_unknown5_block_definition
	{
		DataReference __unknown_data_reference; 
	};

	struct nicename("alt_material") s_alt_material_block_definition
	{
		struct nicename("Object Water Drag Properties") s_object_water_drag_property_block_definition;
		struct nicename("Water Interaction") s_water_interaction_block_definition;

		string_id nicename("Name") name; 
		string_id nicename("Parent Name") parent_name; 
		signed short nicename("Parent Index") parent_index; 
		unsigned short nicename("Flags") flags; 
		string_id nicename("General Armor") general_armor; 
		string_id nicename("Specific Armor") specific_armor; 
		string_id nicename("Wet Armor") wet_armor; 
		signed short nicename("Wet Armor Index") wet_armor_index; 
		signed short __unknown; 
		signed short nicename("Wet Armor Reference Index") wet_armor_reference_index; 
		signed short __unknown2; 
		Unknown32 __unknown3; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Density") density; 
		TagReference nicename("Global Water Drag Properties") global_water_drag_properties_reference; 
		s_tag_block_definition<s_object_water_drag_property_block_definition> nicename("Object Water Drag Properties") object_water_drag_properties_block; 
		float nicename("Water Drag Unknown") water_drag_unknown; 
		float nicename("Water Drag Unknown") water_drag_unknown2; 
		float nicename("Water Drag Unknown") water_drag_unknown3; 
		float nicename("Water Drag Unknown") water_drag_unknown4; 
		float nicename("Water Drag Unknown") water_drag_unknown5; 
		float nicename("Water Drag Unknown") water_drag_unknown6; 
		Unknown32 __water_drag_unknown7; 
		TagReference nicename("Breakable Surface") breakable_surface_reference; 
		TagReference nicename("Sound Sweetener Small") sound_sweetener_small_reference; 
		TagReference nicename("Sound Sweetener Medium") sound_sweetener_medium_reference; 
		TagReference nicename("Sound Sweetener Large") sound_sweetener_large_reference; 
		TagReference nicename("Sound Sweetener Rolling") sound_sweetener_rolling_reference; 
		TagReference nicename("Sound Sweetener Grinding") sound_sweetener_grinding_reference; 
		TagReference nicename("Sound Sweetener Melee Small") sound_sweetener_melee_small_reference; 
		TagReference nicename("Sound Sweetener Melee Medium") sound_sweetener_melee_medium_reference; 
		TagReference nicename("Sound Sweetener Melee Large") sound_sweetener_melee_large_reference; 
		TagReference nicename("Effect Sweetener Small") effect_sweetener_small_reference; 
		TagReference nicename("Effect Sweetener Medium") effect_sweetener_medium_reference; 
		TagReference nicename("Effect Sweetener Large") effect_sweetener_large_reference; 
		TagReference nicename("Effect Sweetener Rolling") effect_sweetener_rolling_reference; 
		TagReference nicename("Effect Sweetener Grinding") effect_sweetener_grinding_reference; 
		TagReference nicename("Effect Sweetener Melee") effect_sweetener_melee_reference; 
		TagReference nicename("Water Ripple Small") water_ripple_small_reference; 
		TagReference nicename("Water Ripple Medium") water_ripple_medium_reference; 
		TagReference nicename("Water Ripple Large") water_ripple_large_reference; 
		signed int nicename("Sweetener Inheritance Flags") sweetener_inheritance_flags; 
		TagReference nicename("Material Effects") material_effects_reference; 
		s_tag_block_definition<s_water_interaction_block_definition> nicename("Water Interaction") water_interaction_block; 

		struct nicename("object_water_drag_property") s_object_water_drag_property_block_definition
		{
			TagReference nicename("Water Drag Properties") water_drag_properties_reference; 
		};

		struct nicename("water_interaction") s_water_interaction_block_definition
		{
			string_id nicename("Surface Name") surface_name; 
			string_id nicename("Submerged Name") submerged_name; 
			signed short nicename("Surface Index") surface_index; 
			signed short nicename("Submerged Index") submerged_index; 
		};
	};
};
