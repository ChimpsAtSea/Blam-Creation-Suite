#pragma once

struct nicename("Game Engine Settings Definition") group('wezr') s_game_engine_settings_definition_definition
{
	struct nicename("Trait Profiles") s_trait_profile_block_definition;
	struct nicename("AI Trait Profiles") s_ai_trait_profile_block_definition;
	struct nicename("Sandbox Variants") s_sandbox_variant_block_definition;
	struct nicename("Survival Variants") s_survival_variant_block_definition;

	Undefined32 __unknown; 
	s_tag_block_definition<s_trait_profile_block_definition> nicename("Trait Profiles") trait_profiles_block; 
	s_tag_block_definition<s_ai_trait_profile_block_definition> nicename("AI Trait Profiles") ai_trait_profiles_block; 
	s_tag_block_definition<s_sandbox_variant_block_definition> nicename("Sandbox Variants") sandbox_variants_block; 
	s_tag_block_definition<s_survival_variant_block_definition> nicename("Survival Variants") survival_variants_block; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 
	Undefined32 __unknown4; 

	struct nicename("trait_profile") s_trait_profile_block_definition
	{
		struct nicename("Shields and Health") s_shields_and_health_block_definition;
		struct nicename("Weapons and Damage") s_weapons_and_damage_block_definition;
		struct nicename("Movement") s_movement_block_definition;
		struct nicename("Appearance") s_appearance_block_definition;
		struct nicename("HUD") s_hud_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_shields_and_health_block_definition> nicename("Shields and Health") shields_and_health_block; 
		s_tag_block_definition<s_weapons_and_damage_block_definition> nicename("Weapons and Damage") weapons_and_damage_block; 
		s_tag_block_definition<s_movement_block_definition> nicename("Movement") movement_block; 
		s_tag_block_definition<s_appearance_block_definition> nicename("Appearance") appearance_block; 
		s_tag_block_definition<s_hud_block_definition> nicename("HUD") hud_block; 

		struct nicename("shields_and_health") s_shields_and_health_block_definition
		{
			int8_t nicename("Damage Resistance") damage_resistance; 
			int8_t nicename("Health Multiplier") health_multiplier; 
			int8_t nicename("Health Recharge Rate") health_recharge_rate; 
			int8_t nicename("Shield Multiplier") shield_multiplier; 
			int8_t nicename("Shield Recharge Rate") shield_recharge_rate; 
			int8_t nicename("Shield Recharge Rate 2") shield_recharge_rate_2; 
			int8_t nicename("Headshot Immunity") headshot_immunity; 
			int8_t nicename("Shield Vampirism") shield_vampirism; 
			int8_t nicename("Assassination Immunity") assassination_immunity; 
			int8_t nicename("Deathless") deathless; 
			int8_t __unknown; 
			int8_t __unknown2; 
		};

		struct nicename("weapons_and_damage") s_weapons_and_damage_block_definition
		{
			int8_t nicename("Damage Modifier") damage_modifier; 
			int8_t nicename("Melee Damage Modifier") melee_damage_modifier; 
			int8_t nicename("Grenade Regeneration") grenade_regeneration; 
			int8_t nicename("Weapon Pickup") weapon_pickup; 
			int8_t nicename("Grenade Count") grenade_count; 
			int8_t nicename("Infinite Ammo") infinite_ammo; 
			int8_t nicename("Equipment Usage") equipment_usage; 
			int8_t nicename("Equipment Drop") equipment_drop; 
			int8_t nicename("Infinite Equipment") infinite_equipment; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			string_id nicename("Primary Weapon") primary_weapon; 
			string_id nicename("Secondary Weapon") secondary_weapon; 
			string_id nicename("Equipment") equipment; 
		};

		struct nicename("movement") s_movement_block_definition
		{
			int8_t nicename("Player Speed") player_speed; 
			int8_t nicename("Player Gravity") player_gravity; 
			int8_t nicename("Vehicle Use") vehicle_use; 
			int8_t nicename("Double Jump") double_jump; 
			// comment
			int32_t nicename("Jump Height") jump_height; 
		};

		struct nicename("appearance") s_appearance_block_definition
		{
			int8_t nicename("Active Camo") active_camo; 
			int8_t nicename("Waypoint") waypoint; 
			int8_t nicename("Visible Name") visible_name; 
			int8_t nicename("Aura") aura; 
			int8_t nicename("Forced Color") forced_color; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
		};

		struct nicename("hud") s_hud_block_definition
		{
			int8_t nicename("Motion Tracker Mode") motion_tracker_mode; 
			int8_t nicename("Motion Tracker Range") motion_tracker_range; 
			int8_t nicename("Directional Damage Indicator") directional_damage_indicator; 
			int8_t __unknown; 
		};
	};

	struct nicename("ai_trait_profile") s_ai_trait_profile_block_definition
	{
		string_id nicename("Name") name; 
		// comment
		int8_t nicename("Vision") vision; 
		int8_t nicename("Hearing") hearing; 
		int8_t nicename("Luck") luck; 
		int8_t nicename("Shootiness") shootiness; 
		int8_t nicename("Grenades") grenades; 
		int8_t nicename("Equipment Drop") equipment_drop; 
		int8_t nicename("Assassination Immunity") assassination_immunity; 
		int8_t nicename("Headshot Immunity") headshot_immunity; 
		int8_t nicename("Damage Resistance") damage_resistance; 
		int8_t nicename("Damage Modifier") damage_modifier; 
		int8_t __unknown; 
		int8_t __unknown2; 
	};

	struct nicename("sandbox_variant") s_sandbox_variant_block_definition
	{
		struct nicename("General Settings") s_general_setting_block_definition;
		struct nicename("Respawn Settings") s_respawn_setting_block_definition;
		struct nicename("Social Settings") s_social_setting_block_definition;
		struct nicename("Map Overrides") s_map_override_block_definition;
		struct nicename("Teams") s_team_block_definition;
		struct nicename("Loadouts") s_loadout_block_definition;

		string_id nicename("Variant Name") variant_name; 
		string_id nicename("Variant Description") variant_description; 
		s_tag_block_definition<s_general_setting_block_definition> nicename("General Settings") general_settings_block; 
		s_tag_block_definition<s_respawn_setting_block_definition> nicename("Respawn Settings") respawn_settings_block; 
		s_tag_block_definition<s_social_setting_block_definition> nicename("Social Settings") social_settings_block; 
		s_tag_block_definition<s_map_override_block_definition> nicename("Map Overrides") map_overrides_block; 
		s_tag_block_definition<s_team_block_definition> nicename("Teams") teams_block; 
		s_tag_block_definition<s_loadout_block_definition> nicename("Loadouts") loadouts_block; 
		int32_t nicename("Flags") flags; 
		int16_t nicename("Edit Mode") edit_mode; 
		int16_t nicename("Editor Respawn Time") editor_respawn_time; 
		string_id nicename("Editor Trait Profile") editor_trait_profile; 

		struct nicename("general_setting") s_general_setting_block_definition
		{
			uint8_t nicename("Flags") flags; 
			int8_t nicename("Early Victory Win Count") early_victory_win_count; 
			int8_t nicename("Time Limit") time_limit; 
			int8_t nicename("Number of Rounds") number_of_rounds; 
			int16_t nicename("Sudden Death") sudden_death; 
			int16_t nicename("Grace Period") grace_period; 
		};

		struct nicename("respawn_setting") s_respawn_setting_block_definition
		{
			uint16_t nicename("Flags") flags; 
			int8_t nicename("Lives Per Round") lives_per_round; 
			int8_t nicename("Shared Team Lives") shared_team_lives; 
			int8_t nicename("Respawn Time") respawn_time; 
			int8_t nicename("Suicide Penalty") suicide_penalty; 
			int8_t nicename("Betrayal Penalty") betrayal_penalty; 
			int8_t nicename("Respawn Time Growth") respawn_time_growth; 
			string_id nicename("Respawn Trait Profile") respawn_trait_profile; 
			int8_t nicename("Loadout Selection Time") loadout_selection_time; 
			int8_t nicename("Respawn Trait Duration") respawn_trait_duration; 
			int8_t __unknown; 
			int8_t __unknown2; 
		};

		struct nicename("social_setting") s_social_setting_block_definition
		{
			int32_t nicename("Flags") flags; 
		};

		struct nicename("map_override") s_map_override_block_definition
		{
			string_id nicename("Base Player Trait Profile") base_player_trait_profile; 
			string_id nicename("Weapon Set") weapon_set; 
			string_id nicename("Vehicle Set") vehicle_set; 
			string_id nicename("Overshield Trait Profile") overshield_trait_profile; 
			string_id nicename("Active Camo Trait Profile") active_camo_trait_profile; 
			string_id nicename("Custom Powerup Trait Profile") custom_powerup_trait_profile; 
			int8_t nicename("Overshield Trait Duration") overshield_trait_duration; 
			int8_t nicename("Active Camo Trait Duration") active_camo_trait_duration; 
			int8_t nicename("Custom Powerup Trait Duration") custom_powerup_trait_duration; 
			uint8_t nicename("Flags") flags; 
		};

		struct nicename("team") s_team_block_definition
		{
			int8_t nicename("Model Override") model_override; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			// comment
			uint8_t nicename("Team Flags") team_flags; 
			int8_t nicename("Team Index") team_index; 
			int8_t nicename("Team Model") team_model; 
			int8_t nicename("Fireteam Count") fireteam_count; 
			string_id nicename("Team Name") team_name; 
			uint8_t nicename("Primary Alpha") primary_alpha; 
			uint8_t nicename("Primary Color r") primary_color_r; 
			uint8_t nicename("Primary Color g") primary_color_g; 
			uint8_t nicename("Primary Color b") primary_color_b; 
			uint8_t nicename("Secondary Alpha") secondary_alpha; 
			uint8_t nicename("Secondary Color r") secondary_color_r; 
			uint8_t nicename("Secondary Color g") secondary_color_g; 
			uint8_t nicename("Secondary Color b") secondary_color_b; 
			uint8_t nicename("UI Color a") ui_color_a; 
			uint8_t nicename("UI Color r") ui_color_r; 
			uint8_t nicename("UI Color g") ui_color_g; 
			uint8_t nicename("UI Color b") ui_color_b; 
			// comment
			uint8_t nicename("Team Flags") team_flags2; 
			int8_t nicename("Team Index") team_index2; 
			int8_t nicename("Team Model") team_model2; 
			int8_t nicename("Fireteam Count") fireteam_count2; 
			string_id nicename("Team Name") team_name2; 
			uint8_t nicename("Primary Alpha") primary_alpha2; 
			uint8_t nicename("Primary Color r") primary_color_r2; 
			uint8_t nicename("Primary Color g") primary_color_g2; 
			uint8_t nicename("Primary Color b") primary_color_b2; 
			uint8_t nicename("Secondary Alpha") secondary_alpha2; 
			uint8_t nicename("Secondary Color r") secondary_color_r2; 
			uint8_t nicename("Secondary Color g") secondary_color_g2; 
			uint8_t nicename("Secondary Color b") secondary_color_b2; 
			uint8_t nicename("UI Color a") ui_color_a2; 
			uint8_t nicename("UI Color r") ui_color_r2; 
			uint8_t nicename("UI Color g") ui_color_g2; 
			uint8_t nicename("UI Color b") ui_color_b2; 
			// comment
			uint8_t nicename("Team Flags") team_flags3; 
			int8_t nicename("Team Index") team_index3; 
			int8_t nicename("Team Model") team_model3; 
			int8_t nicename("Fireteam Count") fireteam_count3; 
			string_id nicename("Team Name") team_name3; 
			uint8_t nicename("Primary Alpha") primary_alpha3; 
			uint8_t nicename("Primary Color r") primary_color_r3; 
			uint8_t nicename("Primary Color g") primary_color_g3; 
			uint8_t nicename("Primary Color b") primary_color_b3; 
			uint8_t nicename("Secondary Alpha") secondary_alpha3; 
			uint8_t nicename("Secondary Color r") secondary_color_r3; 
			uint8_t nicename("Secondary Color g") secondary_color_g3; 
			uint8_t nicename("Secondary Color b") secondary_color_b3; 
			uint8_t nicename("UI Color a") ui_color_a3; 
			uint8_t nicename("UI Color r") ui_color_r3; 
			uint8_t nicename("UI Color g") ui_color_g3; 
			uint8_t nicename("UI Color b") ui_color_b3; 
			// comment
			uint8_t nicename("Team Flags") team_flags4; 
			int8_t nicename("Team Index") team_index4; 
			int8_t nicename("Team Model") team_model4; 
			int8_t nicename("Fireteam Count") fireteam_count4; 
			string_id nicename("Team Name") team_name4; 
			uint8_t nicename("Primary Alpha") primary_alpha4; 
			uint8_t nicename("Primary Color r") primary_color_r4; 
			uint8_t nicename("Primary Color g") primary_color_g4; 
			uint8_t nicename("Primary Color b") primary_color_b4; 
			uint8_t nicename("Secondary Alpha") secondary_alpha4; 
			uint8_t nicename("Secondary Color r") secondary_color_r4; 
			uint8_t nicename("Secondary Color g") secondary_color_g4; 
			uint8_t nicename("Secondary Color b") secondary_color_b4; 
			uint8_t nicename("UI Color a") ui_color_a4; 
			uint8_t nicename("UI Color r") ui_color_r4; 
			uint8_t nicename("UI Color g") ui_color_g4; 
			uint8_t nicename("UI Color b") ui_color_b4; 
			// comment
			uint8_t nicename("Team Flags") team_flags5; 
			int8_t nicename("Team Index") team_index5; 
			int8_t nicename("Team Model") team_model5; 
			int8_t nicename("Fireteam Count") fireteam_count5; 
			string_id nicename("Team Name") team_name5; 
			uint8_t nicename("Primary Alpha") primary_alpha5; 
			uint8_t nicename("Primary Color r") primary_color_r5; 
			uint8_t nicename("Primary Color g") primary_color_g5; 
			uint8_t nicename("Primary Color b") primary_color_b5; 
			uint8_t nicename("Secondary Alpha") secondary_alpha5; 
			uint8_t nicename("Secondary Color r") secondary_color_r5; 
			uint8_t nicename("Secondary Color g") secondary_color_g5; 
			uint8_t nicename("Secondary Color b") secondary_color_b5; 
			uint8_t nicename("UI Color a") ui_color_a5; 
			uint8_t nicename("UI Color r") ui_color_r5; 
			uint8_t nicename("UI Color g") ui_color_g5; 
			uint8_t nicename("UI Color b") ui_color_b5; 
			// comment
			uint8_t nicename("Team Flags") team_flags6; 
			int8_t nicename("Team Index") team_index6; 
			int8_t nicename("Team Model") team_model6; 
			int8_t nicename("Fireteam Count") fireteam_count6; 
			string_id nicename("Team Name") team_name6; 
			uint8_t nicename("Primary Alpha") primary_alpha6; 
			uint8_t nicename("Primary Color r") primary_color_r6; 
			uint8_t nicename("Primary Color g") primary_color_g6; 
			uint8_t nicename("Primary Color b") primary_color_b6; 
			uint8_t nicename("Secondary Alpha") secondary_alpha6; 
			uint8_t nicename("Secondary Color r") secondary_color_r6; 
			uint8_t nicename("Secondary Color g") secondary_color_g6; 
			uint8_t nicename("Secondary Color b") secondary_color_b6; 
			uint8_t nicename("UI Color a") ui_color_a6; 
			uint8_t nicename("UI Color r") ui_color_r6; 
			uint8_t nicename("UI Color g") ui_color_g6; 
			uint8_t nicename("UI Color b") ui_color_b6; 
			// comment
			uint8_t nicename("Team Flags") team_flags7; 
			int8_t nicename("Team Index") team_index7; 
			int8_t nicename("Team Model") team_model7; 
			int8_t nicename("Fireteam Count") fireteam_count7; 
			string_id __unknown4; 
			uint8_t nicename("Primary Alpha") primary_alpha7; 
			uint8_t nicename("Primary Color r") primary_color_r7; 
			uint8_t nicename("Primary Color g") primary_color_g7; 
			uint8_t nicename("Primary Color b") primary_color_b7; 
			uint8_t nicename("Secondary Alpha") secondary_alpha7; 
			uint8_t nicename("Secondary Color r") secondary_color_r7; 
			uint8_t nicename("Secondary Color g") secondary_color_g7; 
			uint8_t nicename("Secondary Color b") secondary_color_b7; 
			uint8_t nicename("UI Color a") ui_color_a7; 
			uint8_t nicename("UI Color r") ui_color_r7; 
			uint8_t nicename("UI Color g") ui_color_g7; 
			uint8_t nicename("UI Color b") ui_color_b7; 
			// comment
			uint8_t nicename("Team Flags") team_flags8; 
			int8_t nicename("Team Index") team_index8; 
			int8_t nicename("Team Model") team_model8; 
			int8_t nicename("Fireteam Count") fireteam_count8; 
			string_id nicename("Team Name") team_name7; 
			uint8_t nicename("Primary Alpha") primary_alpha8; 
			uint8_t nicename("Primary Color r") primary_color_r8; 
			uint8_t nicename("Primary Color g") primary_color_g8; 
			uint8_t nicename("Primary Color b") primary_color_b8; 
			uint8_t nicename("Secondary Alpha") secondary_alpha8; 
			uint8_t nicename("Secondary Color r") secondary_color_r8; 
			uint8_t nicename("Secondary Color g") secondary_color_g8; 
			uint8_t nicename("Secondary Color b") secondary_color_b8; 
			uint8_t nicename("UI Color a") ui_color_a8; 
			uint8_t nicename("UI Color r") ui_color_r8; 
			uint8_t nicename("UI Color g") ui_color_g8; 
			uint8_t nicename("UI Color b") ui_color_b8; 
		};

		struct nicename("loadout") s_loadout_block_definition
		{
			struct nicename("Loadout Palette") s_loadout_palette_block_definition;

			uint8_t nicename("Flags") flags; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			s_tag_block_definition<s_loadout_palette_block_definition> nicename("Loadout Palette") loadout_palette_block; 

			struct nicename("loadout_palette") s_loadout_palette_block_definition
			{
				string_id nicename("Loadout") loadout; 
			};
		};
	};

	struct nicename("survival_variant") s_survival_variant_block_definition
	{
		struct nicename("General Settings") s_general_setting_block_definition;
		struct nicename("Respawn Settings") s_respawn_setting_block_definition;
		struct nicename("Social Settings") s_social_setting_block_definition;
		struct nicename("Map Overrides") s_map_override_block_definition;
		struct nicename("Teams") s_team_block_definition;
		struct nicename("Loadouts") s_loadout_block_definition;
		struct nicename("Elite Respawn Settings") s_elite_respawn_setting_block_definition;
		struct s_unknown_skull_block_definition;
		struct nicename("Rounds") s_round_block_definition;
		struct nicename("Bonus Round Squads") s_bonus_round_squad_block_definition;
		struct nicename("Custom Skull Traits") s_custom_skull_trait_block_definition;

		string_id nicename("Variant Name") variant_name; 
		string_id nicename("Variant Description") variant_description; 
		s_tag_block_definition<s_general_setting_block_definition> nicename("General Settings") general_settings_block; 
		s_tag_block_definition<s_respawn_setting_block_definition> nicename("Respawn Settings") respawn_settings_block; 
		s_tag_block_definition<s_social_setting_block_definition> nicename("Social Settings") social_settings_block; 
		s_tag_block_definition<s_map_override_block_definition> nicename("Map Overrides") map_overrides_block; 
		s_tag_block_definition<s_team_block_definition> nicename("Teams") teams_block; 
		s_tag_block_definition<s_loadout_block_definition> nicename("Loadouts") loadouts_block; 
		uint8_t nicename("Scenario Flags") scenario_flags; 
		int8_t nicename("Campaign Difficulty Level") campaign_difficulty_level; 
		int8_t nicename("Time Limit") time_limit; 
		int8_t __unknown; 
		int8_t nicename("Wave Limit") wave_limit; 
		int8_t nicename("Bonus Lives Awarded") bonus_lives_awarded; 
		int16_t nicename("Bonus Target") bonus_target; 
		int16_t nicename("Bonus Lives On Elite Player Kill") bonus_lives_on_elite_player_kill; 
		int16_t nicename("Extra Life Score Target") extra_life_score_target; 
		int16_t nicename("Spartan Starting Lives") spartan_starting_lives; 
		int16_t nicename("Elite Starting Lives") elite_starting_lives; 
		int16_t nicename("Spartan Maximum Lives") spartan_maximum_lives; 
		int16_t nicename("Generator Count") generator_count; 
		string_id nicename("Spartan Trait Profile") spartan_trait_profile; 
		string_id nicename("Elite Trait Profile") elite_trait_profile; 
		string_id nicename("AI Trait Profile") ai_trait_profile; 
		s_tag_block_definition<s_elite_respawn_setting_block_definition> nicename("Elite Respawn Settings") elite_respawn_settings_block; 
		s_tag_block_definition<s_unknown_skull_block_definition> __unknown_skulls_block; 
		s_tag_block_definition<s_round_block_definition> nicename("Rounds") rounds_block; 
		int32_t nicename("Bonus Round Skulls") bonus_round_skulls; 
		int16_t nicename("Bonus Round Duration") bonus_round_duration; 
		int16_t __unknown2; 
		uint8_t nicename("Wave Flags") wave_flags; 
		uint8_t nicename("Squad Advance Type") squad_advance_type; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		s_tag_block_definition<s_bonus_round_squad_block_definition> nicename("Bonus Round Squads") bonus_round_squads_block; 
		// comment
		s_tag_block_definition<s_custom_skull_trait_block_definition> nicename("Custom Skull Traits") custom_skull_traits_block; 

		struct nicename("general_setting") s_general_setting_block_definition
		{
			uint8_t nicename("Flags") flags; 
			int8_t nicename("Early Victory Win Count") early_victory_win_count; 
			int8_t nicename("Time Limit") time_limit; 
			int8_t nicename("Number of Rounds") number_of_rounds; 
			int16_t nicename("Sudden Death") sudden_death; 
			int16_t nicename("Grace Period") grace_period; 
		};

		struct nicename("respawn_setting") s_respawn_setting_block_definition
		{
			uint16_t nicename("Flags") flags; 
			int8_t nicename("Lives Per Round") lives_per_round; 
			int8_t nicename("Shared Team Lives") shared_team_lives; 
			int8_t nicename("Respawn Time") respawn_time; 
			int8_t nicename("Suicide Penalty") suicide_penalty; 
			int8_t nicename("Betrayal Penalty") betrayal_penalty; 
			int8_t nicename("Respawn Time Growth") respawn_time_growth; 
			string_id nicename("Respawn Trait Profile") respawn_trait_profile; 
			int8_t nicename("Loadout Selection Time") loadout_selection_time; 
			int8_t nicename("Respawn Trait Duration") respawn_trait_duration; 
			int8_t __unknown; 
			int8_t __unknown2; 
		};

		struct nicename("social_setting") s_social_setting_block_definition
		{
			int32_t nicename("Flags") flags; 
		};

		struct nicename("map_override") s_map_override_block_definition
		{
			string_id nicename("Base Player Trait Profile") base_player_trait_profile; 
			string_id nicename("Weapon Set") weapon_set; 
			string_id nicename("Vehicle Set") vehicle_set; 
			string_id nicename("Overshield Trait Profile") overshield_trait_profile; 
			string_id nicename("Active Camo Trait Profile") active_camo_trait_profile; 
			string_id nicename("Custom Powerup Trait Profile") custom_powerup_trait_profile; 
			int8_t nicename("Overshield Trait Duration") overshield_trait_duration; 
			int8_t nicename("Active Camo Trait Duration") active_camo_trait_duration; 
			int8_t nicename("Custom Powerup Trait Duration") custom_powerup_trait_duration; 
			uint8_t nicename("Flags") flags; 
		};

		struct nicename("team") s_team_block_definition
		{
			int8_t nicename("Model Override") model_override; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			// comment
			uint8_t nicename("Team Flags") team_flags; 
			int8_t nicename("Team Index") team_index; 
			int8_t nicename("Team Model") team_model; 
			int8_t nicename("Fireteam Count") fireteam_count; 
			string_id nicename("Team Name") team_name; 
			uint8_t nicename("Primary Alpha") primary_alpha; 
			uint8_t nicename("Primary Color r") primary_color_r; 
			uint8_t nicename("Primary Color g") primary_color_g; 
			uint8_t nicename("Primary Color b") primary_color_b; 
			uint8_t nicename("Secondary Alpha") secondary_alpha; 
			uint8_t nicename("Secondary Color r") secondary_color_r; 
			uint8_t nicename("Secondary Color g") secondary_color_g; 
			uint8_t nicename("Secondary Color b") secondary_color_b; 
			uint8_t nicename("UI Color a") ui_color_a; 
			uint8_t nicename("UI Color r") ui_color_r; 
			uint8_t nicename("UI Color g") ui_color_g; 
			uint8_t nicename("UI Color b") ui_color_b; 
			// comment
			uint8_t nicename("Team Flags") team_flags2; 
			int8_t nicename("Team Index") team_index2; 
			int8_t nicename("Team Model") team_model2; 
			int8_t nicename("Fireteam Count") fireteam_count2; 
			string_id nicename("Team Name") team_name2; 
			uint8_t nicename("Primary Alpha") primary_alpha2; 
			uint8_t nicename("Primary Color r") primary_color_r2; 
			uint8_t nicename("Primary Color g") primary_color_g2; 
			uint8_t nicename("Primary Color b") primary_color_b2; 
			uint8_t nicename("Secondary Alpha") secondary_alpha2; 
			uint8_t nicename("Secondary Color r") secondary_color_r2; 
			uint8_t nicename("Secondary Color g") secondary_color_g2; 
			uint8_t nicename("Secondary Color b") secondary_color_b2; 
			uint8_t nicename("UI Color a") ui_color_a2; 
			uint8_t nicename("UI Color r") ui_color_r2; 
			uint8_t nicename("UI Color g") ui_color_g2; 
			uint8_t nicename("UI Color b") ui_color_b2; 
			// comment
			uint8_t nicename("Team Flags") team_flags3; 
			int8_t nicename("Team Index") team_index3; 
			int8_t nicename("Team Model") team_model3; 
			int8_t nicename("Fireteam Count") fireteam_count3; 
			string_id nicename("Team Name") team_name3; 
			uint8_t nicename("Primary Alpha") primary_alpha3; 
			uint8_t nicename("Primary Color r") primary_color_r3; 
			uint8_t nicename("Primary Color g") primary_color_g3; 
			uint8_t nicename("Primary Color b") primary_color_b3; 
			uint8_t nicename("Secondary Alpha") secondary_alpha3; 
			uint8_t nicename("Secondary Color r") secondary_color_r3; 
			uint8_t nicename("Secondary Color g") secondary_color_g3; 
			uint8_t nicename("Secondary Color b") secondary_color_b3; 
			uint8_t nicename("UI Color a") ui_color_a3; 
			uint8_t nicename("UI Color r") ui_color_r3; 
			uint8_t nicename("UI Color g") ui_color_g3; 
			uint8_t nicename("UI Color b") ui_color_b3; 
			// comment
			uint8_t nicename("Team Flags") team_flags4; 
			int8_t nicename("Team Index") team_index4; 
			int8_t nicename("Team Model") team_model4; 
			int8_t nicename("Fireteam Count") fireteam_count4; 
			string_id nicename("Team Name") team_name4; 
			uint8_t nicename("Primary Alpha") primary_alpha4; 
			uint8_t nicename("Primary Color r") primary_color_r4; 
			uint8_t nicename("Primary Color g") primary_color_g4; 
			uint8_t nicename("Primary Color b") primary_color_b4; 
			uint8_t nicename("Secondary Alpha") secondary_alpha4; 
			uint8_t nicename("Secondary Color r") secondary_color_r4; 
			uint8_t nicename("Secondary Color g") secondary_color_g4; 
			uint8_t nicename("Secondary Color b") secondary_color_b4; 
			uint8_t nicename("UI Color a") ui_color_a4; 
			uint8_t nicename("UI Color r") ui_color_r4; 
			uint8_t nicename("UI Color g") ui_color_g4; 
			uint8_t nicename("UI Color b") ui_color_b4; 
			// comment
			uint8_t nicename("Team Flags") team_flags5; 
			int8_t nicename("Team Index") team_index5; 
			int8_t nicename("Team Model") team_model5; 
			int8_t nicename("Fireteam Count") fireteam_count5; 
			string_id nicename("Team Name") team_name5; 
			uint8_t nicename("Primary Alpha") primary_alpha5; 
			uint8_t nicename("Primary Color r") primary_color_r5; 
			uint8_t nicename("Primary Color g") primary_color_g5; 
			uint8_t nicename("Primary Color b") primary_color_b5; 
			uint8_t nicename("Secondary Alpha") secondary_alpha5; 
			uint8_t nicename("Secondary Color r") secondary_color_r5; 
			uint8_t nicename("Secondary Color g") secondary_color_g5; 
			uint8_t nicename("Secondary Color b") secondary_color_b5; 
			uint8_t nicename("UI Color a") ui_color_a5; 
			uint8_t nicename("UI Color r") ui_color_r5; 
			uint8_t nicename("UI Color g") ui_color_g5; 
			uint8_t nicename("UI Color b") ui_color_b5; 
			// comment
			uint8_t nicename("Team Flags") team_flags6; 
			int8_t nicename("Team Index") team_index6; 
			int8_t nicename("Team Model") team_model6; 
			int8_t nicename("Fireteam Count") fireteam_count6; 
			string_id nicename("Team Name") team_name6; 
			uint8_t nicename("Primary Alpha") primary_alpha6; 
			uint8_t nicename("Primary Color r") primary_color_r6; 
			uint8_t nicename("Primary Color g") primary_color_g6; 
			uint8_t nicename("Primary Color b") primary_color_b6; 
			uint8_t nicename("Secondary Alpha") secondary_alpha6; 
			uint8_t nicename("Secondary Color r") secondary_color_r6; 
			uint8_t nicename("Secondary Color g") secondary_color_g6; 
			uint8_t nicename("Secondary Color b") secondary_color_b6; 
			uint8_t nicename("UI Color a") ui_color_a6; 
			uint8_t nicename("UI Color r") ui_color_r6; 
			uint8_t nicename("UI Color g") ui_color_g6; 
			uint8_t nicename("UI Color b") ui_color_b6; 
			// comment
			uint8_t nicename("Team Flags") team_flags7; 
			int8_t nicename("Team Index") team_index7; 
			int8_t nicename("Team Model") team_model7; 
			int8_t nicename("Fireteam Count") fireteam_count7; 
			string_id __unknown4; 
			uint8_t nicename("Primary Alpha") primary_alpha7; 
			uint8_t nicename("Primary Color r") primary_color_r7; 
			uint8_t nicename("Primary Color g") primary_color_g7; 
			uint8_t nicename("Primary Color b") primary_color_b7; 
			uint8_t nicename("Secondary Alpha") secondary_alpha7; 
			uint8_t nicename("Secondary Color r") secondary_color_r7; 
			uint8_t nicename("Secondary Color g") secondary_color_g7; 
			uint8_t nicename("Secondary Color b") secondary_color_b7; 
			uint8_t nicename("UI Color a") ui_color_a7; 
			uint8_t nicename("UI Color r") ui_color_r7; 
			uint8_t nicename("UI Color g") ui_color_g7; 
			uint8_t nicename("UI Color b") ui_color_b7; 
			// comment
			uint8_t nicename("Team Flags") team_flags8; 
			int8_t nicename("Team Index") team_index8; 
			int8_t nicename("Team Model") team_model8; 
			int8_t nicename("Fireteam Count") fireteam_count8; 
			string_id nicename("Team Name") team_name7; 
			uint8_t nicename("Primary Alpha") primary_alpha8; 
			uint8_t nicename("Primary Color r") primary_color_r8; 
			uint8_t nicename("Primary Color g") primary_color_g8; 
			uint8_t nicename("Primary Color b") primary_color_b8; 
			uint8_t nicename("Secondary Alpha") secondary_alpha8; 
			uint8_t nicename("Secondary Color r") secondary_color_r8; 
			uint8_t nicename("Secondary Color g") secondary_color_g8; 
			uint8_t nicename("Secondary Color b") secondary_color_b8; 
			uint8_t nicename("UI Color a") ui_color_a8; 
			uint8_t nicename("UI Color r") ui_color_r8; 
			uint8_t nicename("UI Color g") ui_color_g8; 
			uint8_t nicename("UI Color b") ui_color_b8; 
		};

		struct nicename("loadout") s_loadout_block_definition
		{
			struct nicename("Loadout Palette") s_loadout_palette_block_definition;

			uint8_t nicename("Flags") flags; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			s_tag_block_definition<s_loadout_palette_block_definition> nicename("Loadout Palette") loadout_palette_block; 

			struct nicename("loadout_palette") s_loadout_palette_block_definition
			{
				string_id nicename("Loadout") loadout; 
			};
		};

		struct nicename("elite_respawn_setting") s_elite_respawn_setting_block_definition
		{
			uint16_t nicename("Flags") flags; 
			int8_t nicename("Lives Per Round") lives_per_round; 
			int8_t nicename("Shared Team Lives") shared_team_lives; 
			int8_t nicename("Respawn Time") respawn_time; 
			int8_t nicename("Suicide Penalty") suicide_penalty; 
			int8_t nicename("Betrayal Penalty") betrayal_penalty; 
			int8_t nicename("Respawn Time Growth") respawn_time_growth; 
			string_id nicename("Respawn Trait Profile") respawn_trait_profile; 
			int8_t nicename("Loadout Selection Time") loadout_selection_time; 
			int8_t nicename("Respawn Trait Duration") respawn_trait_duration; 
			int8_t __unknown; 
			int8_t __unknown2; 
		};

		struct s_unknown_skull_block_definition
		{
			uint16_t nicename("Skulls") skulls; 
		};

		struct nicename("round") s_round_block_definition
		{
			struct nicename("Squads") s_squad_block_definition;
			struct nicename("Squads") s_squad2_block_definition;
			struct nicename("Squads") s_squad3_block_definition;

			int32_t nicename("Round Skulls") round_skulls; 
			// comment
			uint8_t nicename("Wave Flags") wave_flags; 
			uint8_t nicename("Squad Advance Type") squad_advance_type; 
			int8_t __unknown; 
			int8_t __unknown2; 
			s_tag_block_definition<s_squad_block_definition> nicename("Squads") squads_block; 
			// comment
			uint8_t nicename("Wave Flags") wave_flags2; 
			uint8_t nicename("Squad Advance Type") squad_advance_type2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			s_tag_block_definition<s_squad2_block_definition> nicename("Squads") squads2_block; 
			// comment
			uint8_t nicename("Wave Flags") wave_flags3; 
			uint8_t nicename("Squad Advance Type") squad_advance_type3; 
			int8_t __unknown5; 
			int8_t __unknown6; 
			s_tag_block_definition<s_squad3_block_definition> nicename("Squads") squads3_block; 

			struct nicename("squad") s_squad_block_definition
			{
				string_id nicename("Enemy") enemy; 
			};

			struct nicename("squad2") s_squad2_block_definition
			{
				string_id nicename("Enemy") enemy; 
			};

			struct nicename("squad3") s_squad3_block_definition
			{
				string_id nicename("Enemy") enemy; 
			};
		};

		struct nicename("bonus_round_squad") s_bonus_round_squad_block_definition
		{
			string_id nicename("Enemy") enemy; 
		};

		struct nicename("custom_skull_trait") s_custom_skull_trait_block_definition
		{
			string_id nicename("Spartan Player Trait Profile") spartan_player_trait_profile; 
			string_id nicename("Elite Player Trait Profile") elite_player_trait_profile; 
			string_id nicename("AI Trait Profile") ai_trait_profile; 
		};
	};
};
