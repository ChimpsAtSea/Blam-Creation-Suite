#pragma once

struct nicename("Game Engine Settings Definition") group('wezr') s_game_engine_settings_definition_definition
{
	struct nicename("Trait Profiles") s_trait_profile_block_definition;
	struct nicename("AI Trait Profiles") s_ai_trait_profile_block_definition;
	struct nicename("Sandbox Variants") s_sandbox_variant_block_definition;
	struct nicename("Survival Variants") s_survival_variant_block_definition;

	Unknown32 __unknown; 
	s_tag_block_definition<s_trait_profile_block_definition> nicename("Trait Profiles") trait_profiles_block; 
	s_tag_block_definition<s_ai_trait_profile_block_definition> nicename("AI Trait Profiles") ai_trait_profiles_block; 
	s_tag_block_definition<s_sandbox_variant_block_definition> nicename("Sandbox Variants") sandbox_variants_block; 
	s_tag_block_definition<s_survival_variant_block_definition> nicename("Survival Variants") survival_variants_block; 
	Unknown32 __unknown2; 
	Unknown32 __unknown3; 
	Unknown32 __unknown4; 

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

	struct nicename("ai_trait_profile") s_ai_trait_profile_block_definition
	{
		string_id nicename("Name") name; 
		// comment
		signed char nicename("Vision") vision; 
		signed char nicename("Hearing") hearing; 
		signed char nicename("Luck") luck; 
		signed char nicename("Shootiness") shootiness; 
		signed char nicename("Grenades") grenades; 
		signed char nicename("Equipment Drop") equipment_drop; 
		signed char nicename("Assassination Immunity") assassination_immunity; 
		signed char nicename("Headshot Immunity") headshot_immunity; 
		signed char nicename("Damage Resistance") damage_resistance; 
		signed char nicename("Damage Modifier") damage_modifier; 
		signed char __unknown; 
		signed char __unknown2; 
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
		signed int nicename("Flags") flags; 
		signed short nicename("Edit Mode") edit_mode; 
		signed short nicename("Editor Respawn Time") editor_respawn_time; 
		string_id nicename("Editor Trait Profile") editor_trait_profile; 

		struct nicename("general_setting") s_general_setting_block_definition
		{
			unsigned char nicename("Flags") flags; 
			signed char nicename("Early Victory Win Count") early_victory_win_count; 
			signed char nicename("Time Limit") time_limit; 
			signed char nicename("Number of Rounds") number_of_rounds; 
			signed short nicename("Sudden Death") sudden_death; 
			signed short nicename("Grace Period") grace_period; 
		};

		struct nicename("respawn_setting") s_respawn_setting_block_definition
		{
			unsigned short nicename("Flags") flags; 
			signed char nicename("Lives Per Round") lives_per_round; 
			signed char nicename("Shared Team Lives") shared_team_lives; 
			signed char nicename("Respawn Time") respawn_time; 
			signed char nicename("Suicide Penalty") suicide_penalty; 
			signed char nicename("Betrayal Penalty") betrayal_penalty; 
			signed char nicename("Respawn Time Growth") respawn_time_growth; 
			string_id nicename("Respawn Trait Profile") respawn_trait_profile; 
			signed char nicename("Loadout Selection Time") loadout_selection_time; 
			signed char nicename("Respawn Trait Duration") respawn_trait_duration; 
			signed char __unknown; 
			signed char __unknown2; 
		};

		struct nicename("social_setting") s_social_setting_block_definition
		{
			signed int nicename("Flags") flags; 
		};

		struct nicename("map_override") s_map_override_block_definition
		{
			string_id nicename("Base Player Trait Profile") base_player_trait_profile; 
			string_id nicename("Weapon Set") weapon_set; 
			string_id nicename("Vehicle Set") vehicle_set; 
			string_id nicename("Overshield Trait Profile") overshield_trait_profile; 
			string_id nicename("Active Camo Trait Profile") active_camo_trait_profile; 
			string_id nicename("Custom Powerup Trait Profile") custom_powerup_trait_profile; 
			signed char nicename("Overshield Trait Duration") overshield_trait_duration; 
			signed char nicename("Active Camo Trait Duration") active_camo_trait_duration; 
			signed char nicename("Custom Powerup Trait Duration") custom_powerup_trait_duration; 
			unsigned char nicename("Flags") flags; 
		};

		struct nicename("team") s_team_block_definition
		{
			signed char nicename("Model Override") model_override; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			// comment
			unsigned char nicename("Team Flags") team_flags; 
			signed char nicename("Team Index") team_index; 
			signed char nicename("Team Model") team_model; 
			signed char nicename("Fireteam Count") fireteam_count; 
			string_id nicename("Team Name") team_name; 
			unsigned char nicename("Primary Alpha") primary_alpha; 
			unsigned char nicename("Primary Color r") primary_color_r; 
			unsigned char nicename("Primary Color g") primary_color_g; 
			unsigned char nicename("Primary Color b") primary_color_b; 
			unsigned char nicename("Secondary Alpha") secondary_alpha; 
			unsigned char nicename("Secondary Color r") secondary_color_r; 
			unsigned char nicename("Secondary Color g") secondary_color_g; 
			unsigned char nicename("Secondary Color b") secondary_color_b; 
			unsigned char nicename("UI Color a") ui_color_a; 
			unsigned char nicename("UI Color r") ui_color_r; 
			unsigned char nicename("UI Color g") ui_color_g; 
			unsigned char nicename("UI Color b") ui_color_b; 
			// comment
			unsigned char nicename("Team Flags") team_flags2; 
			signed char nicename("Team Index") team_index2; 
			signed char nicename("Team Model") team_model2; 
			signed char nicename("Fireteam Count") fireteam_count2; 
			string_id nicename("Team Name") team_name2; 
			unsigned char nicename("Primary Alpha") primary_alpha2; 
			unsigned char nicename("Primary Color r") primary_color_r2; 
			unsigned char nicename("Primary Color g") primary_color_g2; 
			unsigned char nicename("Primary Color b") primary_color_b2; 
			unsigned char nicename("Secondary Alpha") secondary_alpha2; 
			unsigned char nicename("Secondary Color r") secondary_color_r2; 
			unsigned char nicename("Secondary Color g") secondary_color_g2; 
			unsigned char nicename("Secondary Color b") secondary_color_b2; 
			unsigned char nicename("UI Color a") ui_color_a2; 
			unsigned char nicename("UI Color r") ui_color_r2; 
			unsigned char nicename("UI Color g") ui_color_g2; 
			unsigned char nicename("UI Color b") ui_color_b2; 
			// comment
			unsigned char nicename("Team Flags") team_flags3; 
			signed char nicename("Team Index") team_index3; 
			signed char nicename("Team Model") team_model3; 
			signed char nicename("Fireteam Count") fireteam_count3; 
			string_id nicename("Team Name") team_name3; 
			unsigned char nicename("Primary Alpha") primary_alpha3; 
			unsigned char nicename("Primary Color r") primary_color_r3; 
			unsigned char nicename("Primary Color g") primary_color_g3; 
			unsigned char nicename("Primary Color b") primary_color_b3; 
			unsigned char nicename("Secondary Alpha") secondary_alpha3; 
			unsigned char nicename("Secondary Color r") secondary_color_r3; 
			unsigned char nicename("Secondary Color g") secondary_color_g3; 
			unsigned char nicename("Secondary Color b") secondary_color_b3; 
			unsigned char nicename("UI Color a") ui_color_a3; 
			unsigned char nicename("UI Color r") ui_color_r3; 
			unsigned char nicename("UI Color g") ui_color_g3; 
			unsigned char nicename("UI Color b") ui_color_b3; 
			// comment
			unsigned char nicename("Team Flags") team_flags4; 
			signed char nicename("Team Index") team_index4; 
			signed char nicename("Team Model") team_model4; 
			signed char nicename("Fireteam Count") fireteam_count4; 
			string_id nicename("Team Name") team_name4; 
			unsigned char nicename("Primary Alpha") primary_alpha4; 
			unsigned char nicename("Primary Color r") primary_color_r4; 
			unsigned char nicename("Primary Color g") primary_color_g4; 
			unsigned char nicename("Primary Color b") primary_color_b4; 
			unsigned char nicename("Secondary Alpha") secondary_alpha4; 
			unsigned char nicename("Secondary Color r") secondary_color_r4; 
			unsigned char nicename("Secondary Color g") secondary_color_g4; 
			unsigned char nicename("Secondary Color b") secondary_color_b4; 
			unsigned char nicename("UI Color a") ui_color_a4; 
			unsigned char nicename("UI Color r") ui_color_r4; 
			unsigned char nicename("UI Color g") ui_color_g4; 
			unsigned char nicename("UI Color b") ui_color_b4; 
			// comment
			unsigned char nicename("Team Flags") team_flags5; 
			signed char nicename("Team Index") team_index5; 
			signed char nicename("Team Model") team_model5; 
			signed char nicename("Fireteam Count") fireteam_count5; 
			string_id nicename("Team Name") team_name5; 
			unsigned char nicename("Primary Alpha") primary_alpha5; 
			unsigned char nicename("Primary Color r") primary_color_r5; 
			unsigned char nicename("Primary Color g") primary_color_g5; 
			unsigned char nicename("Primary Color b") primary_color_b5; 
			unsigned char nicename("Secondary Alpha") secondary_alpha5; 
			unsigned char nicename("Secondary Color r") secondary_color_r5; 
			unsigned char nicename("Secondary Color g") secondary_color_g5; 
			unsigned char nicename("Secondary Color b") secondary_color_b5; 
			unsigned char nicename("UI Color a") ui_color_a5; 
			unsigned char nicename("UI Color r") ui_color_r5; 
			unsigned char nicename("UI Color g") ui_color_g5; 
			unsigned char nicename("UI Color b") ui_color_b5; 
			// comment
			unsigned char nicename("Team Flags") team_flags6; 
			signed char nicename("Team Index") team_index6; 
			signed char nicename("Team Model") team_model6; 
			signed char nicename("Fireteam Count") fireteam_count6; 
			string_id nicename("Team Name") team_name6; 
			unsigned char nicename("Primary Alpha") primary_alpha6; 
			unsigned char nicename("Primary Color r") primary_color_r6; 
			unsigned char nicename("Primary Color g") primary_color_g6; 
			unsigned char nicename("Primary Color b") primary_color_b6; 
			unsigned char nicename("Secondary Alpha") secondary_alpha6; 
			unsigned char nicename("Secondary Color r") secondary_color_r6; 
			unsigned char nicename("Secondary Color g") secondary_color_g6; 
			unsigned char nicename("Secondary Color b") secondary_color_b6; 
			unsigned char nicename("UI Color a") ui_color_a6; 
			unsigned char nicename("UI Color r") ui_color_r6; 
			unsigned char nicename("UI Color g") ui_color_g6; 
			unsigned char nicename("UI Color b") ui_color_b6; 
			// comment
			unsigned char nicename("Team Flags") team_flags7; 
			signed char nicename("Team Index") team_index7; 
			signed char nicename("Team Model") team_model7; 
			signed char nicename("Fireteam Count") fireteam_count7; 
			string_id __unknown4; 
			unsigned char nicename("Primary Alpha") primary_alpha7; 
			unsigned char nicename("Primary Color r") primary_color_r7; 
			unsigned char nicename("Primary Color g") primary_color_g7; 
			unsigned char nicename("Primary Color b") primary_color_b7; 
			unsigned char nicename("Secondary Alpha") secondary_alpha7; 
			unsigned char nicename("Secondary Color r") secondary_color_r7; 
			unsigned char nicename("Secondary Color g") secondary_color_g7; 
			unsigned char nicename("Secondary Color b") secondary_color_b7; 
			unsigned char nicename("UI Color a") ui_color_a7; 
			unsigned char nicename("UI Color r") ui_color_r7; 
			unsigned char nicename("UI Color g") ui_color_g7; 
			unsigned char nicename("UI Color b") ui_color_b7; 
			// comment
			unsigned char nicename("Team Flags") team_flags8; 
			signed char nicename("Team Index") team_index8; 
			signed char nicename("Team Model") team_model8; 
			signed char nicename("Fireteam Count") fireteam_count8; 
			string_id nicename("Team Name") team_name7; 
			unsigned char nicename("Primary Alpha") primary_alpha8; 
			unsigned char nicename("Primary Color r") primary_color_r8; 
			unsigned char nicename("Primary Color g") primary_color_g8; 
			unsigned char nicename("Primary Color b") primary_color_b8; 
			unsigned char nicename("Secondary Alpha") secondary_alpha8; 
			unsigned char nicename("Secondary Color r") secondary_color_r8; 
			unsigned char nicename("Secondary Color g") secondary_color_g8; 
			unsigned char nicename("Secondary Color b") secondary_color_b8; 
			unsigned char nicename("UI Color a") ui_color_a8; 
			unsigned char nicename("UI Color r") ui_color_r8; 
			unsigned char nicename("UI Color g") ui_color_g8; 
			unsigned char nicename("UI Color b") ui_color_b8; 
		};

		struct nicename("loadout") s_loadout_block_definition
		{
			struct nicename("Loadout Palette") s_loadout_palette_block_definition;

			unsigned char nicename("Flags") flags; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
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
		unsigned char nicename("Scenario Flags") scenario_flags; 
		signed char nicename("Campaign Difficulty Level") campaign_difficulty_level; 
		signed char nicename("Time Limit") time_limit; 
		signed char __unknown; 
		signed char nicename("Wave Limit") wave_limit; 
		signed char nicename("Bonus Lives Awarded") bonus_lives_awarded; 
		signed short nicename("Bonus Target") bonus_target; 
		signed short nicename("Bonus Lives On Elite Player Kill") bonus_lives_on_elite_player_kill; 
		signed short nicename("Extra Life Score Target") extra_life_score_target; 
		signed short nicename("Spartan Starting Lives") spartan_starting_lives; 
		signed short nicename("Elite Starting Lives") elite_starting_lives; 
		signed short nicename("Spartan Maximum Lives") spartan_maximum_lives; 
		signed short nicename("Generator Count") generator_count; 
		string_id nicename("Spartan Trait Profile") spartan_trait_profile; 
		string_id nicename("Elite Trait Profile") elite_trait_profile; 
		string_id nicename("AI Trait Profile") ai_trait_profile; 
		s_tag_block_definition<s_elite_respawn_setting_block_definition> nicename("Elite Respawn Settings") elite_respawn_settings_block; 
		s_tag_block_definition<s_unknown_skull_block_definition> __unknown_skulls_block; 
		s_tag_block_definition<s_round_block_definition> nicename("Rounds") rounds_block; 
		signed int nicename("Bonus Round Skulls") bonus_round_skulls; 
		signed short nicename("Bonus Round Duration") bonus_round_duration; 
		signed short __unknown2; 
		unsigned char nicename("Wave Flags") wave_flags; 
		unsigned char nicename("Squad Advance Type") squad_advance_type; 
		signed char __unknown3; 
		signed char __unknown4; 
		s_tag_block_definition<s_bonus_round_squad_block_definition> nicename("Bonus Round Squads") bonus_round_squads_block; 
		// comment
		s_tag_block_definition<s_custom_skull_trait_block_definition> nicename("Custom Skull Traits") custom_skull_traits_block; 

		struct nicename("general_setting") s_general_setting_block_definition
		{
			unsigned char nicename("Flags") flags; 
			signed char nicename("Early Victory Win Count") early_victory_win_count; 
			signed char nicename("Time Limit") time_limit; 
			signed char nicename("Number of Rounds") number_of_rounds; 
			signed short nicename("Sudden Death") sudden_death; 
			signed short nicename("Grace Period") grace_period; 
		};

		struct nicename("respawn_setting") s_respawn_setting_block_definition
		{
			unsigned short nicename("Flags") flags; 
			signed char nicename("Lives Per Round") lives_per_round; 
			signed char nicename("Shared Team Lives") shared_team_lives; 
			signed char nicename("Respawn Time") respawn_time; 
			signed char nicename("Suicide Penalty") suicide_penalty; 
			signed char nicename("Betrayal Penalty") betrayal_penalty; 
			signed char nicename("Respawn Time Growth") respawn_time_growth; 
			string_id nicename("Respawn Trait Profile") respawn_trait_profile; 
			signed char nicename("Loadout Selection Time") loadout_selection_time; 
			signed char nicename("Respawn Trait Duration") respawn_trait_duration; 
			signed char __unknown; 
			signed char __unknown2; 
		};

		struct nicename("social_setting") s_social_setting_block_definition
		{
			signed int nicename("Flags") flags; 
		};

		struct nicename("map_override") s_map_override_block_definition
		{
			string_id nicename("Base Player Trait Profile") base_player_trait_profile; 
			string_id nicename("Weapon Set") weapon_set; 
			string_id nicename("Vehicle Set") vehicle_set; 
			string_id nicename("Overshield Trait Profile") overshield_trait_profile; 
			string_id nicename("Active Camo Trait Profile") active_camo_trait_profile; 
			string_id nicename("Custom Powerup Trait Profile") custom_powerup_trait_profile; 
			signed char nicename("Overshield Trait Duration") overshield_trait_duration; 
			signed char nicename("Active Camo Trait Duration") active_camo_trait_duration; 
			signed char nicename("Custom Powerup Trait Duration") custom_powerup_trait_duration; 
			unsigned char nicename("Flags") flags; 
		};

		struct nicename("team") s_team_block_definition
		{
			signed char nicename("Model Override") model_override; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			// comment
			unsigned char nicename("Team Flags") team_flags; 
			signed char nicename("Team Index") team_index; 
			signed char nicename("Team Model") team_model; 
			signed char nicename("Fireteam Count") fireteam_count; 
			string_id nicename("Team Name") team_name; 
			unsigned char nicename("Primary Alpha") primary_alpha; 
			unsigned char nicename("Primary Color r") primary_color_r; 
			unsigned char nicename("Primary Color g") primary_color_g; 
			unsigned char nicename("Primary Color b") primary_color_b; 
			unsigned char nicename("Secondary Alpha") secondary_alpha; 
			unsigned char nicename("Secondary Color r") secondary_color_r; 
			unsigned char nicename("Secondary Color g") secondary_color_g; 
			unsigned char nicename("Secondary Color b") secondary_color_b; 
			unsigned char nicename("UI Color a") ui_color_a; 
			unsigned char nicename("UI Color r") ui_color_r; 
			unsigned char nicename("UI Color g") ui_color_g; 
			unsigned char nicename("UI Color b") ui_color_b; 
			// comment
			unsigned char nicename("Team Flags") team_flags2; 
			signed char nicename("Team Index") team_index2; 
			signed char nicename("Team Model") team_model2; 
			signed char nicename("Fireteam Count") fireteam_count2; 
			string_id nicename("Team Name") team_name2; 
			unsigned char nicename("Primary Alpha") primary_alpha2; 
			unsigned char nicename("Primary Color r") primary_color_r2; 
			unsigned char nicename("Primary Color g") primary_color_g2; 
			unsigned char nicename("Primary Color b") primary_color_b2; 
			unsigned char nicename("Secondary Alpha") secondary_alpha2; 
			unsigned char nicename("Secondary Color r") secondary_color_r2; 
			unsigned char nicename("Secondary Color g") secondary_color_g2; 
			unsigned char nicename("Secondary Color b") secondary_color_b2; 
			unsigned char nicename("UI Color a") ui_color_a2; 
			unsigned char nicename("UI Color r") ui_color_r2; 
			unsigned char nicename("UI Color g") ui_color_g2; 
			unsigned char nicename("UI Color b") ui_color_b2; 
			// comment
			unsigned char nicename("Team Flags") team_flags3; 
			signed char nicename("Team Index") team_index3; 
			signed char nicename("Team Model") team_model3; 
			signed char nicename("Fireteam Count") fireteam_count3; 
			string_id nicename("Team Name") team_name3; 
			unsigned char nicename("Primary Alpha") primary_alpha3; 
			unsigned char nicename("Primary Color r") primary_color_r3; 
			unsigned char nicename("Primary Color g") primary_color_g3; 
			unsigned char nicename("Primary Color b") primary_color_b3; 
			unsigned char nicename("Secondary Alpha") secondary_alpha3; 
			unsigned char nicename("Secondary Color r") secondary_color_r3; 
			unsigned char nicename("Secondary Color g") secondary_color_g3; 
			unsigned char nicename("Secondary Color b") secondary_color_b3; 
			unsigned char nicename("UI Color a") ui_color_a3; 
			unsigned char nicename("UI Color r") ui_color_r3; 
			unsigned char nicename("UI Color g") ui_color_g3; 
			unsigned char nicename("UI Color b") ui_color_b3; 
			// comment
			unsigned char nicename("Team Flags") team_flags4; 
			signed char nicename("Team Index") team_index4; 
			signed char nicename("Team Model") team_model4; 
			signed char nicename("Fireteam Count") fireteam_count4; 
			string_id nicename("Team Name") team_name4; 
			unsigned char nicename("Primary Alpha") primary_alpha4; 
			unsigned char nicename("Primary Color r") primary_color_r4; 
			unsigned char nicename("Primary Color g") primary_color_g4; 
			unsigned char nicename("Primary Color b") primary_color_b4; 
			unsigned char nicename("Secondary Alpha") secondary_alpha4; 
			unsigned char nicename("Secondary Color r") secondary_color_r4; 
			unsigned char nicename("Secondary Color g") secondary_color_g4; 
			unsigned char nicename("Secondary Color b") secondary_color_b4; 
			unsigned char nicename("UI Color a") ui_color_a4; 
			unsigned char nicename("UI Color r") ui_color_r4; 
			unsigned char nicename("UI Color g") ui_color_g4; 
			unsigned char nicename("UI Color b") ui_color_b4; 
			// comment
			unsigned char nicename("Team Flags") team_flags5; 
			signed char nicename("Team Index") team_index5; 
			signed char nicename("Team Model") team_model5; 
			signed char nicename("Fireteam Count") fireteam_count5; 
			string_id nicename("Team Name") team_name5; 
			unsigned char nicename("Primary Alpha") primary_alpha5; 
			unsigned char nicename("Primary Color r") primary_color_r5; 
			unsigned char nicename("Primary Color g") primary_color_g5; 
			unsigned char nicename("Primary Color b") primary_color_b5; 
			unsigned char nicename("Secondary Alpha") secondary_alpha5; 
			unsigned char nicename("Secondary Color r") secondary_color_r5; 
			unsigned char nicename("Secondary Color g") secondary_color_g5; 
			unsigned char nicename("Secondary Color b") secondary_color_b5; 
			unsigned char nicename("UI Color a") ui_color_a5; 
			unsigned char nicename("UI Color r") ui_color_r5; 
			unsigned char nicename("UI Color g") ui_color_g5; 
			unsigned char nicename("UI Color b") ui_color_b5; 
			// comment
			unsigned char nicename("Team Flags") team_flags6; 
			signed char nicename("Team Index") team_index6; 
			signed char nicename("Team Model") team_model6; 
			signed char nicename("Fireteam Count") fireteam_count6; 
			string_id nicename("Team Name") team_name6; 
			unsigned char nicename("Primary Alpha") primary_alpha6; 
			unsigned char nicename("Primary Color r") primary_color_r6; 
			unsigned char nicename("Primary Color g") primary_color_g6; 
			unsigned char nicename("Primary Color b") primary_color_b6; 
			unsigned char nicename("Secondary Alpha") secondary_alpha6; 
			unsigned char nicename("Secondary Color r") secondary_color_r6; 
			unsigned char nicename("Secondary Color g") secondary_color_g6; 
			unsigned char nicename("Secondary Color b") secondary_color_b6; 
			unsigned char nicename("UI Color a") ui_color_a6; 
			unsigned char nicename("UI Color r") ui_color_r6; 
			unsigned char nicename("UI Color g") ui_color_g6; 
			unsigned char nicename("UI Color b") ui_color_b6; 
			// comment
			unsigned char nicename("Team Flags") team_flags7; 
			signed char nicename("Team Index") team_index7; 
			signed char nicename("Team Model") team_model7; 
			signed char nicename("Fireteam Count") fireteam_count7; 
			string_id __unknown4; 
			unsigned char nicename("Primary Alpha") primary_alpha7; 
			unsigned char nicename("Primary Color r") primary_color_r7; 
			unsigned char nicename("Primary Color g") primary_color_g7; 
			unsigned char nicename("Primary Color b") primary_color_b7; 
			unsigned char nicename("Secondary Alpha") secondary_alpha7; 
			unsigned char nicename("Secondary Color r") secondary_color_r7; 
			unsigned char nicename("Secondary Color g") secondary_color_g7; 
			unsigned char nicename("Secondary Color b") secondary_color_b7; 
			unsigned char nicename("UI Color a") ui_color_a7; 
			unsigned char nicename("UI Color r") ui_color_r7; 
			unsigned char nicename("UI Color g") ui_color_g7; 
			unsigned char nicename("UI Color b") ui_color_b7; 
			// comment
			unsigned char nicename("Team Flags") team_flags8; 
			signed char nicename("Team Index") team_index8; 
			signed char nicename("Team Model") team_model8; 
			signed char nicename("Fireteam Count") fireteam_count8; 
			string_id nicename("Team Name") team_name7; 
			unsigned char nicename("Primary Alpha") primary_alpha8; 
			unsigned char nicename("Primary Color r") primary_color_r8; 
			unsigned char nicename("Primary Color g") primary_color_g8; 
			unsigned char nicename("Primary Color b") primary_color_b8; 
			unsigned char nicename("Secondary Alpha") secondary_alpha8; 
			unsigned char nicename("Secondary Color r") secondary_color_r8; 
			unsigned char nicename("Secondary Color g") secondary_color_g8; 
			unsigned char nicename("Secondary Color b") secondary_color_b8; 
			unsigned char nicename("UI Color a") ui_color_a8; 
			unsigned char nicename("UI Color r") ui_color_r8; 
			unsigned char nicename("UI Color g") ui_color_g8; 
			unsigned char nicename("UI Color b") ui_color_b8; 
		};

		struct nicename("loadout") s_loadout_block_definition
		{
			struct nicename("Loadout Palette") s_loadout_palette_block_definition;

			unsigned char nicename("Flags") flags; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			s_tag_block_definition<s_loadout_palette_block_definition> nicename("Loadout Palette") loadout_palette_block; 

			struct nicename("loadout_palette") s_loadout_palette_block_definition
			{
				string_id nicename("Loadout") loadout; 
			};
		};

		struct nicename("elite_respawn_setting") s_elite_respawn_setting_block_definition
		{
			unsigned short nicename("Flags") flags; 
			signed char nicename("Lives Per Round") lives_per_round; 
			signed char nicename("Shared Team Lives") shared_team_lives; 
			signed char nicename("Respawn Time") respawn_time; 
			signed char nicename("Suicide Penalty") suicide_penalty; 
			signed char nicename("Betrayal Penalty") betrayal_penalty; 
			signed char nicename("Respawn Time Growth") respawn_time_growth; 
			string_id nicename("Respawn Trait Profile") respawn_trait_profile; 
			signed char nicename("Loadout Selection Time") loadout_selection_time; 
			signed char nicename("Respawn Trait Duration") respawn_trait_duration; 
			signed char __unknown; 
			signed char __unknown2; 
		};

		struct s_unknown_skull_block_definition
		{
			unsigned short nicename("Skulls") skulls; 
		};

		struct nicename("round") s_round_block_definition
		{
			struct nicename("Squads") s_squad_block_definition;
			struct nicename("Squads") s_squad2_block_definition;
			struct nicename("Squads") s_squad3_block_definition;

			signed int nicename("Round Skulls") round_skulls; 
			// comment
			unsigned char nicename("Wave Flags") wave_flags; 
			unsigned char nicename("Squad Advance Type") squad_advance_type; 
			signed char __unknown; 
			signed char __unknown2; 
			s_tag_block_definition<s_squad_block_definition> nicename("Squads") squads_block; 
			// comment
			unsigned char nicename("Wave Flags") wave_flags2; 
			unsigned char nicename("Squad Advance Type") squad_advance_type2; 
			signed char __unknown3; 
			signed char __unknown4; 
			s_tag_block_definition<s_squad2_block_definition> nicename("Squads") squads2_block; 
			// comment
			unsigned char nicename("Wave Flags") wave_flags3; 
			unsigned char nicename("Squad Advance Type") squad_advance_type3; 
			signed char __unknown5; 
			signed char __unknown6; 
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
