#pragma once

struct nicename("game_engine_settings_definition") tag_group('wezr') s_game_engine_settings_definition_definition
{
	struct nicename("Trait Profiles") s_trait_profiles_definition
	{
		struct nicename("Shields and Health") s_shields_and_health_definition
		{
			enum nicename("Damage Resistance") e_damage_resistance : uint8_t
			{
				/*nicename("Unchanged")*/ _damage_resistance_unchanged = 1ui8,
				/*nicename("10%")*/ _damage_resistance__10 = 2ui8,
				/*nicename("50%")*/ _damage_resistance__50 = 3ui8,
				/*nicename("90%")*/ _damage_resistance__90 = 4ui8,
				/*nicename("100%")*/ _damage_resistance__100 = 5ui8,
				/*nicename("110%")*/ _damage_resistance__110 = 6ui8,
				/*nicename("150%")*/ _damage_resistance__150 = 7ui8,
				/*nicename("200%")*/ _damage_resistance__200 = 8ui8,
				/*nicename("300%")*/ _damage_resistance__300 = 9ui8,
				/*nicename("500%")*/ _damage_resistance__500 = 10ui8,
				/*nicename("1000%")*/ _damage_resistance__1000 = 11ui8,
				/*nicename("2000%")*/ _damage_resistance__2000 = 12ui8,
				/*nicename("Invulnerable")*/ _damage_resistance_invulnerable = 13ui8,
			};

			enum nicename("Health Multiplier") e_health_multiplier : uint8_t
			{
				/*nicename("Unchanged")*/ _health_multiplier_unchanged = 1ui8,
				/*nicename("0%")*/ _health_multiplier__0 = 2ui8,
				/*nicename("100%")*/ _health_multiplier__100 = 3ui8,
				/*nicename("150%")*/ _health_multiplier__150 = 4ui8,
				/*nicename("200%")*/ _health_multiplier__200 = 5ui8,
				/*nicename("300%")*/ _health_multiplier__300 = 6ui8,
				/*nicename("400%")*/ _health_multiplier__400 = 7ui8,
			};

			enum nicename("Health Recharge Rate") e_health_recharge_rate : uint8_t
			{
				/*nicename("Unchanged")*/ _health_recharge_rate_unchanged = 1ui8,
				/*nicename("-25%")*/ _health_recharge_rate__25 = 2ui8,
				/*nicename("-10%")*/ _health_recharge_rate__10 = 3ui8,
				/*nicename("-5%")*/ _health_recharge_rate__5 = 4ui8,
				/*nicename("0%")*/ _health_recharge_rate__0 = 5ui8,
				/*nicename("10%")*/ _health_recharge_rate__101 = 6ui8,
				/*nicename("25%")*/ _health_recharge_rate__251 = 7ui8,
				/*nicename("50%")*/ _health_recharge_rate__50 = 8ui8,
				/*nicename("75%")*/ _health_recharge_rate__75 = 9ui8,
				/*nicename("90%")*/ _health_recharge_rate__90 = 10ui8,
				/*nicename("100%")*/ _health_recharge_rate__100 = 11ui8,
				/*nicename("110%")*/ _health_recharge_rate__110 = 12ui8,
				/*nicename("125%")*/ _health_recharge_rate__125 = 13ui8,
				/*nicename("150%")*/ _health_recharge_rate__150 = 14ui8,
				/*nicename("200%")*/ _health_recharge_rate__200 = 15ui8,
			};

			enum nicename("Shield Multiplier") e_shield_multiplier : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_multiplier_unchanged = 1ui8,
				/*nicename("No Shields")*/ _shield_multiplier_no_shields = 2ui8,
				/*nicename("Normal Shields")*/ _shield_multiplier_normal_shields = 3ui8,
				/*nicename("1.5x Overshields")*/ _shield_multiplier__15x_overshields = 4ui8,
				/*nicename("2x Overshields")*/ _shield_multiplier__2x_overshields = 5ui8,
				/*nicename("3x Overshields")*/ _shield_multiplier__3x_overshields = 6ui8,
				/*nicename("4x Overshields")*/ _shield_multiplier__4x_overshields = 7ui8,
			};

			enum nicename("Shield Recharge Rate") e_shield_recharge_rate : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_recharge_rate_unchanged = 1ui8,
				/*nicename("-25%")*/ _shield_recharge_rate__25 = 2ui8,
				/*nicename("-10%")*/ _shield_recharge_rate__10 = 3ui8,
				/*nicename("-5%")*/ _shield_recharge_rate__5 = 4ui8,
				/*nicename("0%")*/ _shield_recharge_rate__0 = 5ui8,
				/*nicename("10%")*/ _shield_recharge_rate__101 = 6ui8,
				/*nicename("25%")*/ _shield_recharge_rate__251 = 7ui8,
				/*nicename("50%")*/ _shield_recharge_rate__50 = 8ui8,
				/*nicename("75%")*/ _shield_recharge_rate__75 = 9ui8,
				/*nicename("90%")*/ _shield_recharge_rate__90 = 10ui8,
				/*nicename("100%")*/ _shield_recharge_rate__100 = 11ui8,
				/*nicename("110%")*/ _shield_recharge_rate__110 = 12ui8,
				/*nicename("125%")*/ _shield_recharge_rate__125 = 13ui8,
				/*nicename("150%")*/ _shield_recharge_rate__150 = 14ui8,
				/*nicename("200%")*/ _shield_recharge_rate__200 = 15ui8,
			};

			enum nicename("Shield Recharge Rate 2") e_shield_recharge_rate_2 : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_recharge_rate_2_unchanged = 1ui8,
				/*nicename("-25%")*/ _shield_recharge_rate_2__25 = 2ui8,
				/*nicename("-10%")*/ _shield_recharge_rate_2__10 = 3ui8,
				/*nicename("-5%")*/ _shield_recharge_rate_2__5 = 4ui8,
				/*nicename("0%")*/ _shield_recharge_rate_2__0 = 5ui8,
				/*nicename("10%")*/ _shield_recharge_rate_2__101 = 6ui8,
				/*nicename("25%")*/ _shield_recharge_rate_2__251 = 7ui8,
				/*nicename("50%")*/ _shield_recharge_rate_2__50 = 8ui8,
				/*nicename("75%")*/ _shield_recharge_rate_2__75 = 9ui8,
				/*nicename("90%")*/ _shield_recharge_rate_2__90 = 10ui8,
				/*nicename("100%")*/ _shield_recharge_rate_2__100 = 11ui8,
				/*nicename("110%")*/ _shield_recharge_rate_2__110 = 12ui8,
				/*nicename("125%")*/ _shield_recharge_rate_2__125 = 13ui8,
				/*nicename("150%")*/ _shield_recharge_rate_2__150 = 14ui8,
				/*nicename("200%")*/ _shield_recharge_rate_2__200 = 15ui8,
			};

			enum nicename("Headshot Immunity") e_headshot_immunity : uint8_t
			{
				/*nicename("Unchanged")*/ _headshot_immunity_unchanged = 1ui8,
				/*nicename("Disabled")*/ _headshot_immunity_disabled = 2ui8,
				/*nicename("Enabled")*/ _headshot_immunity_enabled = 3ui8,
			};

			enum nicename("Shield Vampirism") e_shield_vampirism : uint8_t
			{
				/*nicename("Unchanged")*/ _shield_vampirism_unchanged = 1ui8,
				/*nicename("Disabled")*/ _shield_vampirism_disabled = 2ui8,
				/*nicename("10%")*/ _shield_vampirism__10 = 3ui8,
				/*nicename("25%")*/ _shield_vampirism__25 = 4ui8,
				/*nicename("50%")*/ _shield_vampirism__50 = 5ui8,
				/*nicename("100%")*/ _shield_vampirism__100 = 6ui8,
			};

			enum nicename("Assassination Immunity") e_assassination_immunity : uint8_t
			{
				/*nicename("Unchanged")*/ _assassination_immunity_unchanged = 1ui8,
				/*nicename("Disabled")*/ _assassination_immunity_disabled = 2ui8,
				/*nicename("Enabled")*/ _assassination_immunity_enabled = 3ui8,
			};

			enum nicename("Deathless") e_deathless : uint8_t
			{
				/*nicename("Unchanged")*/ _deathless_unchanged = 1ui8,
				/*nicename("Disabled")*/ _deathless_disabled = 2ui8,
				/*nicename("Enabled")*/ _deathless_enabled = 3ui8,
			};

			e_damage_resistance nicename("Damage Resistance") damage_resistance;
			e_health_multiplier nicename("Health Multiplier") health_multiplier;
			e_health_recharge_rate nicename("Health Recharge Rate") health_recharge_rate;
			e_shield_multiplier nicename("Shield Multiplier") shield_multiplier;
			e_shield_recharge_rate nicename("Shield Recharge Rate") shield_recharge_rate;
			e_shield_recharge_rate_2 nicename("Shield Recharge Rate 2") shield_recharge_rate_2;
			e_headshot_immunity nicename("Headshot Immunity") headshot_immunity;
			e_shield_vampirism nicename("Shield Vampirism") shield_vampirism;
			e_assassination_immunity nicename("Assassination Immunity") assassination_immunity;
			e_deathless nicename("Deathless") deathless;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		struct nicename("Weapons and Damage") s_weapons_and_damage_definition
		{
			enum nicename("Damage Modifier") e_damage_modifier : uint8_t
			{
				/*nicename("Unchanged")*/ _damage_modifier_unchanged = 1ui8,
				/*nicename("0%")*/ _damage_modifier__0 = 2ui8,
				/*nicename("25%")*/ _damage_modifier__25 = 3ui8,
				/*nicename("50%")*/ _damage_modifier__50 = 4ui8,
				/*nicename("75%")*/ _damage_modifier__75 = 5ui8,
				/*nicename("90%")*/ _damage_modifier__90 = 6ui8,
				/*nicename("100%")*/ _damage_modifier__100 = 7ui8,
				/*nicename("110%")*/ _damage_modifier__110 = 8ui8,
				/*nicename("125%")*/ _damage_modifier__125 = 9ui8,
				/*nicename("150%")*/ _damage_modifier__150 = 10ui8,
				/*nicename("200%")*/ _damage_modifier__200 = 11ui8,
				/*nicename("300%")*/ _damage_modifier__300 = 12ui8,
				/*nicename("Instant Kill")*/ _damage_modifier_instant_kill = 13ui8,
			};

			enum nicename("Melee Damage Modifier") e_melee_damage_modifier : uint8_t
			{
				/*nicename("Unchanged")*/ _melee_damage_modifier_unchanged = 1ui8,
				/*nicename("0%")*/ _melee_damage_modifier__0 = 2ui8,
				/*nicename("25%")*/ _melee_damage_modifier__25 = 3ui8,
				/*nicename("50%")*/ _melee_damage_modifier__50 = 4ui8,
				/*nicename("75%")*/ _melee_damage_modifier__75 = 5ui8,
				/*nicename("90%")*/ _melee_damage_modifier__90 = 6ui8,
				/*nicename("100%")*/ _melee_damage_modifier__100 = 7ui8,
				/*nicename("110%")*/ _melee_damage_modifier__110 = 8ui8,
				/*nicename("125%")*/ _melee_damage_modifier__125 = 9ui8,
				/*nicename("150%")*/ _melee_damage_modifier__150 = 10ui8,
				/*nicename("200%")*/ _melee_damage_modifier__200 = 11ui8,
				/*nicename("300%")*/ _melee_damage_modifier__300 = 12ui8,
				/*nicename("Instant Kill")*/ _melee_damage_modifier_instant_kill = 13ui8,
			};

			enum nicename("Grenade Regeneration") e_grenade_regeneration : uint8_t
			{
				/*nicename("Unchanged")*/ _grenade_regeneration_unchanged = 1ui8,
				/*nicename("Disabled")*/ _grenade_regeneration_disabled = 2ui8,
				/*nicename("Enabled")*/ _grenade_regeneration_enabled = 3ui8,
			};

			enum nicename("Weapon Pickup") e_weapon_pickup : uint8_t
			{
				/*nicename("Unchanged")*/ _weapon_pickup_unchanged = 1ui8,
				/*nicename("Disabled")*/ _weapon_pickup_disabled = 2ui8,
				/*nicename("Enabled")*/ _weapon_pickup_enabled = 3ui8,
			};

			enum nicename("Grenade Count") e_grenade_count : uint8_t
			{
				/*nicename("Unchanged")*/ _grenade_count_unchanged = 1ui8,
				/*nicename("Map Default")*/ _grenade_count_map_default = 2ui8,
				/*nicename("None")*/ _grenade_count_none = 3ui8,
				/*nicename("1 Frag")*/ _grenade_count__1_frag = 4ui8,
				/*nicename("2 Frags")*/ _grenade_count__2_frags = 5ui8,
				/*nicename("3 Frags")*/ _grenade_count__3_frags = 6ui8,
				/*nicename("4 Frags")*/ _grenade_count__4_frags = 7ui8,
				/*nicename("1 Plasma")*/ _grenade_count__1_plasma = 8ui8,
				/*nicename("2 Plasmas")*/ _grenade_count__2_plasmas = 9ui8,
				/*nicename("3 Plasmas")*/ _grenade_count__3_plasmas = 10ui8,
				/*nicename("4 Plasmas")*/ _grenade_count__4_plasmas = 11ui8,
				/*nicename("1x Each")*/ _grenade_count__1x_each = 12ui8,
				/*nicename("2x Each")*/ _grenade_count__2x_each = 13ui8,
				/*nicename("3x Each")*/ _grenade_count__3x_each = 14ui8,
				/*nicename("4x Each")*/ _grenade_count__4x_each = 15ui8,
			};

			enum nicename("Infinite Ammo") e_infinite_ammo : uint8_t
			{
				/*nicename("Unchanged")*/ _infinite_ammo_unchanged = 1ui8,
				/*nicename("Disabled")*/ _infinite_ammo_disabled = 2ui8,
				/*nicename("Enabled")*/ _infinite_ammo_enabled = 3ui8,
				/*nicename("Bottomless Clip")*/ _infinite_ammo_bottomless_clip = 4ui8,
			};

			enum nicename("Equipment Usage") e_equipment_usage : uint8_t
			{
				/*nicename("Unchanged")*/ _equipment_usage_unchanged = 1ui8,
				/*nicename("Disabled")*/ _equipment_usage_disabled = 2ui8,
				/*nicename("Enabled")*/ _equipment_usage_enabled = 3ui8,
				/*nicename("Unknown")*/ _equipment_usage_unknown = 4ui8,
			};

			enum nicename("Equipment Drop") e_equipment_drop : uint8_t
			{
				/*nicename("Unchanged")*/ _equipment_drop_unchanged = 1ui8,
				/*nicename("Disabled")*/ _equipment_drop_disabled = 2ui8,
				/*nicename("Enabled")*/ _equipment_drop_enabled = 3ui8,
			};

			enum nicename("Infinite Equipment") e_infinite_equipment : uint8_t
			{
				/*nicename("Unchanged")*/ _infinite_equipment_unchanged = 1ui8,
				/*nicename("Disabled")*/ _infinite_equipment_disabled = 2ui8,
				/*nicename("Enabled")*/ _infinite_equipment_enabled = 3ui8,
			};

			e_damage_modifier nicename("Damage Modifier") damage_modifier;
			e_melee_damage_modifier nicename("Melee Damage Modifier") melee_damage_modifier;
			e_grenade_regeneration nicename("Grenade Regeneration") grenade_regeneration;
			e_weapon_pickup nicename("Weapon Pickup") weapon_pickup;
			e_grenade_count nicename("Grenade Count") grenade_count;
			e_infinite_ammo nicename("Infinite Ammo") infinite_ammo;
			e_equipment_usage nicename("Equipment Usage") equipment_usage;
			e_equipment_drop nicename("Equipment Drop") equipment_drop;
			e_infinite_equipment nicename("Infinite Equipment") infinite_equipment;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			string_id nicename("Primary Weapon") primary_weapon;
			string_id nicename("Secondary Weapon") secondary_weapon;
			string_id nicename("Equipment") equipment;
		};

		struct nicename("Movement") s_movement_definition
		{
			enum nicename("Player Speed") e_player_speed : uint8_t
			{
				/*nicename("Unchanged")*/ _player_speed_unchanged = 1ui8,
				/*nicename("0%")*/ _player_speed__0 = 2ui8,
				/*nicename("25%")*/ _player_speed__25 = 3ui8,
				/*nicename("50%")*/ _player_speed__50 = 4ui8,
				/*nicename("75%")*/ _player_speed__75 = 5ui8,
				/*nicename("90%")*/ _player_speed__90 = 6ui8,
				/*nicename("100%")*/ _player_speed__100 = 7ui8,
				/*nicename("110%")*/ _player_speed__110 = 8ui8,
				/*nicename("120%")*/ _player_speed__120 = 9ui8,
				/*nicename("130%")*/ _player_speed__130 = 10ui8,
				/*nicename("140%")*/ _player_speed__140 = 11ui8,
				/*nicename("150%")*/ _player_speed__150 = 12ui8,
				/*nicename("160%")*/ _player_speed__160 = 13ui8,
				/*nicename("170%")*/ _player_speed__170 = 14ui8,
				/*nicename("180%")*/ _player_speed__180 = 15ui8,
				/*nicename("190%")*/ _player_speed__190 = 16ui8,
				/*nicename("200%")*/ _player_speed__200 = 17ui8,
				/*nicename("300%")*/ _player_speed__300 = 18ui8,
			};

			enum nicename("Player Gravity") e_player_gravity : uint8_t
			{
				/*nicename("Unchanged")*/ _player_gravity_unchanged = 1ui8,
				/*nicename("50%")*/ _player_gravity__50 = 2ui8,
				/*nicename("75%")*/ _player_gravity__75 = 3ui8,
				/*nicename("100%")*/ _player_gravity__100 = 4ui8,
				/*nicename("150%")*/ _player_gravity__150 = 5ui8,
				/*nicename("200%")*/ _player_gravity__200 = 6ui8,
				/*nicename("250%")*/ _player_gravity__250 = 7ui8,
				/*nicename("300%")*/ _player_gravity__300 = 8ui8,
				/*nicename("350%")*/ _player_gravity__350 = 9ui8,
				/*nicename("400%")*/ _player_gravity__400 = 10ui8,
				/*nicename("450%")*/ _player_gravity__450 = 11ui8,
				/*nicename("500%")*/ _player_gravity__500 = 12ui8,
				/*nicename("550%")*/ _player_gravity__550 = 13ui8,
				/*nicename("600%")*/ _player_gravity__600 = 14ui8,
			};

			enum nicename("Vehicle Use") e_vehicle_use : uint8_t
			{
				/*nicename("Unchanged")*/ _vehicle_use_unchanged = 1ui8,
				/*nicename("None")*/ _vehicle_use_none = 2ui8,
				/*nicename("Passenger Only")*/ _vehicle_use_passenger_only = 3ui8,
				/*nicename("Driver Only")*/ _vehicle_use_driver_only = 4ui8,
				/*nicename("Gunner Only")*/ _vehicle_use_gunner_only = 5ui8,
				/*nicename("No Passenger")*/ _vehicle_use_no_passenger = 6ui8,
				/*nicename("No Driver")*/ _vehicle_use_no_driver = 7ui8,
				/*nicename("No Gunner")*/ _vehicle_use_no_gunner = 8ui8,
				/*nicename("Full Use")*/ _vehicle_use_full_use = 9ui8,
			};

			enum nicename("Double Jump") e_double_jump : uint8_t
			{
				/*nicename("Unchanged")*/ _double_jump_unchanged = 1ui8,
				/*nicename("Disabled")*/ _double_jump_disabled = 2ui8,
				/*nicename("Enabled")*/ _double_jump_enabled = 3ui8,
			};

			e_player_speed nicename("Player Speed") player_speed;
			e_player_gravity nicename("Player Gravity") player_gravity;
			e_vehicle_use nicename("Vehicle Use") vehicle_use;
			e_double_jump nicename("Double Jump") double_jump;
			// Jump Height : This is a percentage, and can be any integer up to 400. -1 Is unchanged/default.
			int32_t nicename("Jump Height") jump_height1;
		};

		struct nicename("Appearance") s_appearance_definition
		{
			enum nicename("Active Camo") e_active_camo : uint8_t
			{
				/*nicename("Unchanged")*/ _active_camo_unchanged = 1ui8,
				/*nicename("Disabled")*/ _active_camo_disabled = 2ui8,
				/*nicename("Bad Camo")*/ _active_camo_bad_camo = 3ui8,
				/*nicename("Poor Camo")*/ _active_camo_poor_camo = 4ui8,
				/*nicename("Good Camo")*/ _active_camo_good_camo = 5ui8,
				/*nicename("Invisible")*/ _active_camo_invisible = 6ui8,
			};

			enum nicename("Waypoint") e_waypoint : uint8_t
			{
				/*nicename("Unchanged")*/ _waypoint_unchanged = 1ui8,
				/*nicename("None")*/ _waypoint_none = 2ui8,
				/*nicename("Visible To Allies")*/ _waypoint_visible_to_allies = 3ui8,
				/*nicename("Visible To Everyone")*/ _waypoint_visible_to_everyone = 4ui8,
			};

			enum nicename("Visible Name") e_visible_name : uint8_t
			{
				/*nicename("Unchanged")*/ _visible_name_unchanged = 1ui8,
				/*nicename("None")*/ _visible_name_none = 2ui8,
				/*nicename("Visible To Allies")*/ _visible_name_visible_to_allies = 3ui8,
				/*nicename("Visible To Everyone")*/ _visible_name_visible_to_everyone = 4ui8,
			};

			enum nicename("Aura") e_aura : uint8_t
			{
				/*nicename("Unchanged")*/ _aura_unchanged = 1ui8,
				/*nicename("Disabled")*/ _aura_disabled = 2ui8,
				/*nicename("Team")*/ _aura_team = 3ui8,
				/*nicename("Black")*/ _aura_black = 4ui8,
				/*nicename("White")*/ _aura_white = 5ui8,
			};

			enum nicename("Forced Color") e_forced_color : uint8_t
			{
				/*nicename("Unchanged")*/ _forced_color_unchanged = 1ui8,
				/*nicename("Disabled")*/ _forced_color_disabled = 2ui8,
				/*nicename("Red")*/ _forced_color_red = 3ui8,
				/*nicename("Blue")*/ _forced_color_blue = 4ui8,
				/*nicename("Green")*/ _forced_color_green = 5ui8,
				/*nicename("Orange")*/ _forced_color_orange = 6ui8,
				/*nicename("Purple")*/ _forced_color_purple = 7ui8,
				/*nicename("Gold")*/ _forced_color_gold = 8ui8,
				/*nicename("Brown")*/ _forced_color_brown = 9ui8,
				/*nicename("Pink")*/ _forced_color_pink = 10ui8,
				/*nicename("White")*/ _forced_color_white = 11ui8,
				/*nicename("Black")*/ _forced_color_black = 12ui8,
				/*nicename("Zombie")*/ _forced_color_zombie = 13ui8,
				/*nicename("Pink (Unused)")*/ _forced_color_pink_unused = 14ui8,
			};

			e_active_camo nicename("Active Camo") active_camo;
			e_waypoint nicename("Waypoint") waypoint;
			e_visible_name nicename("Visible Name") visible_name;
			e_aura nicename("Aura") aura;
			e_forced_color nicename("Forced Color") forced_color;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		struct nicename("HUD") s_hud_definition
		{
			enum nicename("Motion Tracker Mode") e_motion_tracker_mode : uint8_t
			{
				/*nicename("Unchanged")*/ _motion_tracker_mode_unchanged = 1ui8,
				/*nicename("Disabled")*/ _motion_tracker_mode_disabled = 2ui8,
				/*nicename("Ally Movement")*/ _motion_tracker_mode_ally_movement = 3ui8,
				/*nicename("Player Movement")*/ _motion_tracker_mode_player_movement = 4ui8,
				/*nicename("Player Locations")*/ _motion_tracker_mode_player_locations = 5ui8,
			};

			enum nicename("Motion Tracker Range") e_motion_tracker_range : uint8_t
			{
				/*nicename("Unchanged")*/ _motion_tracker_range_unchanged = 1ui8,
				/*nicename("10m")*/ _motion_tracker_range__10m = 2ui8,
				/*nicename("15m")*/ _motion_tracker_range__15m = 3ui8,
				/*nicename("25m")*/ _motion_tracker_range__25m = 4ui8,
				/*nicename("50m")*/ _motion_tracker_range__50m = 5ui8,
				/*nicename("75m")*/ _motion_tracker_range__75m = 6ui8,
				/*nicename("100m")*/ _motion_tracker_range__100m = 7ui8,
				/*nicename("150m")*/ _motion_tracker_range__150m = 8ui8,
			};

			enum nicename("Directional Damage Indicator") e_directional_damage_indicator : uint8_t
			{
				/*nicename("Unchanged")*/ _directional_damage_indicator_unchanged = 1ui8,
				/*nicename("Disabled")*/ _directional_damage_indicator_disabled = 2ui8,
				/*nicename("Enabled")*/ _directional_damage_indicator_enabled = 3ui8,
			};

			e_motion_tracker_mode nicename("Motion Tracker Mode") motion_tracker_mode;
			e_motion_tracker_range nicename("Motion Tracker Range") motion_tracker_range;
			e_directional_damage_indicator nicename("Directional Damage Indicator") directional_damage_indicator;
			int8_t __unknown0;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_shields_and_health_definition> nicename("Shields and Health") shields_and_health_block;
		s_tag_block_definition<s_weapons_and_damage_definition> nicename("Weapons and Damage") weapons_and_damage_block;
		s_tag_block_definition<s_movement_definition> nicename("Movement") movement_block;
		s_tag_block_definition<s_appearance_definition> nicename("Appearance") appearance_block;
		s_tag_block_definition<s_hud_definition> nicename("HUD") hud_block;
	};

	struct nicename("AI Trait Profiles") s_ai_trait_profiles_definition
	{
		enum nicename("Vision") e_vision : uint8_t
		{
			/*nicename("Unchanged")*/ _vision_unchanged = 1ui8,
			/*nicename("Normal")*/ _vision_normal = 2ui8,
			/*nicename("Blind (0)")*/ _vision_blind_0 = 3ui8,
			/*nicename("Near Sighted (1)")*/ _vision_near_sighted_1 = 4ui8,
			/*nicename("Eagle Eye (2)")*/ _vision_eagle_eye_2 = 5ui8,
		};

		enum nicename("Hearing") e_hearing : uint8_t
		{
			/*nicename("Unchanged")*/ _hearing_unchanged = 1ui8,
			/*nicename("Normal")*/ _hearing_normal = 2ui8,
			/*nicename("Deaf (0)")*/ _hearing_deaf_0 = 3ui8,
			/*nicename("Sharp (1)")*/ _hearing_sharp_1 = 4ui8,
		};

		enum nicename("Luck") e_luck : uint8_t
		{
			/*nicename("Unchanged")*/ _luck_unchanged = 1ui8,
			/*nicename("Normal")*/ _luck_normal = 2ui8,
			/*nicename("Unlucky (0)")*/ _luck_unlucky_0 = 3ui8,
			/*nicename("Lucky (1)")*/ _luck_lucky_1 = 4ui8,
			/*nicename("Leprechaun (2)")*/ _luck_leprechaun_2 = 5ui8,
		};

		enum nicename("Shootiness") e_shootiness : uint8_t
		{
			/*nicename("Unchanged")*/ _shootiness_unchanged = 1ui8,
			/*nicename("Normal")*/ _shootiness_normal = 2ui8,
			/*nicename("Marksman")*/ _shootiness_marksman = 3ui8,
			/*nicename("Trigger Happy")*/ _shootiness_trigger_happy = 4ui8,
		};

		enum nicename("Grenades") e_grenades : uint8_t
		{
			/*nicename("Unchanged")*/ _grenades_unchanged = 1ui8,
			/*nicename("Normal")*/ _grenades_normal = 2ui8,
			/*nicename("None (0)")*/ _grenades_none_0 = 3ui8,
			/*nicename("Catch (1)")*/ _grenades_catch_1 = 4ui8,
		};

		enum nicename("Equipment Drop") e_equipment_drop : uint8_t
		{
			/*nicename("Unchanged")*/ _equipment_drop_unchanged = 1ui8,
			/*nicename("Enabled")*/ _equipment_drop_enabled = 2ui8,
			/*nicename("Disabled")*/ _equipment_drop_disabled = 3ui8,
		};

		enum nicename("Assassination Immunity") e_assassination_immunity : uint8_t
		{
			/*nicename("Unchanged")*/ _assassination_immunity_unchanged = 1ui8,
			/*nicename("Disabled")*/ _assassination_immunity_disabled = 2ui8,
			/*nicename("Enabled")*/ _assassination_immunity_enabled = 3ui8,
		};

		enum nicename("Headshot Immunity") e_headshot_immunity : uint8_t
		{
			/*nicename("Unchanged")*/ _headshot_immunity_unchanged = 1ui8,
			/*nicename("Disabled")*/ _headshot_immunity_disabled = 2ui8,
			/*nicename("Enabled")*/ _headshot_immunity_enabled = 3ui8,
		};

		enum nicename("Damage Resistance") e_damage_resistance : uint8_t
		{
			/*nicename("Unchanged")*/ _damage_resistance_unchanged = 1ui8,
			/*nicename("10%")*/ _damage_resistance__10 = 2ui8,
			/*nicename("50%")*/ _damage_resistance__50 = 3ui8,
			/*nicename("90%")*/ _damage_resistance__90 = 4ui8,
			/*nicename("100%")*/ _damage_resistance__100 = 5ui8,
			/*nicename("110%")*/ _damage_resistance__110 = 6ui8,
			/*nicename("150%")*/ _damage_resistance__150 = 7ui8,
			/*nicename("200%")*/ _damage_resistance__200 = 8ui8,
			/*nicename("300%")*/ _damage_resistance__300 = 9ui8,
			/*nicename("500%")*/ _damage_resistance__500 = 10ui8,
			/*nicename("1000%")*/ _damage_resistance__1000 = 11ui8,
			/*nicename("2000%")*/ _damage_resistance__2000 = 12ui8,
			/*nicename("Invulnerable")*/ _damage_resistance_invulnerable = 13ui8,
		};

		enum nicename("Damage Modifier") e_damage_modifier : uint8_t
		{
			/*nicename("Unchanged")*/ _damage_modifier_unchanged = 1ui8,
			/*nicename("0%")*/ _damage_modifier__0 = 2ui8,
			/*nicename("25%")*/ _damage_modifier__25 = 3ui8,
			/*nicename("50%")*/ _damage_modifier__50 = 4ui8,
			/*nicename("75%")*/ _damage_modifier__75 = 5ui8,
			/*nicename("90%")*/ _damage_modifier__90 = 6ui8,
			/*nicename("100%")*/ _damage_modifier__100 = 7ui8,
			/*nicename("110%")*/ _damage_modifier__110 = 8ui8,
			/*nicename("125%")*/ _damage_modifier__125 = 9ui8,
			/*nicename("150%")*/ _damage_modifier__150 = 10ui8,
			/*nicename("200%")*/ _damage_modifier__200 = 11ui8,
			/*nicename("300%")*/ _damage_modifier__300 = 12ui8,
			/*nicename("Instant Kill")*/ _damage_modifier_instant_kill = 13ui8,
		};

		string_id nicename("Name") name;
		// Traits : The corresponding values for Vision, Hearing, Luck, and Grenades are set in AIGL, the number in parenthesis is the index for its block
		e_vision nicename("Vision") vision;
		e_hearing nicename("Hearing") hearing;
		e_luck nicename("Luck") luck;
		e_shootiness nicename("Shootiness") shootiness;
		e_grenades nicename("Grenades") grenades;
		e_equipment_drop nicename("Equipment Drop") equipment_drop;
		e_assassination_immunity nicename("Assassination Immunity") assassination_immunity;
		e_headshot_immunity nicename("Headshot Immunity") headshot_immunity;
		e_damage_resistance nicename("Damage Resistance") damage_resistance;
		e_damage_modifier nicename("Damage Modifier") damage_modifier;
		int8_t __unknown0;
		int8_t __unknown1;
	};

	struct nicename("Sandbox Variants") s_sandbox_variants_definition
	{
		enum nicename("Edit Mode") e_edit_mode : uint16_t
		{
			/*nicename("Everyone")*/ _edit_mode_everyone = 1ui16,
			/*nicename("Leader Only")*/ _edit_mode_leader_only = 2ui16,
		};

		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Open Channel Voice Enabled")*/ _flags_open_channel_voice_enabled = 1ui32 << 0ui32,
			/*nicename("Unknown")*/ _flags_unknown = 1ui32 << 1ui32,
		};

		struct nicename("General Settings") s_general_settings_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Teams Enabled")*/ _flags_teams_enabled = 1ui8 << 0ui8,
				/*nicename("Round Resets Players")*/ _flags_round_resets_players = 1ui8 << 1ui8,
				/*nicename("Round Resets Map")*/ _flags_round_resets_map = 1ui8 << 2ui8,
			};

			b_flags nicename("Flags") flags;
			int8_t nicename("Early Victory Win Count") early_victory_win_count;
			int8_t nicename("Time Limit") time_limit;
			int8_t nicename("Number of Rounds") number_of_rounds;
			int16_t nicename("Sudden Death") sudden_death;
			int16_t nicename("Grace Period") grace_period;
		};

		struct nicename("Respawn Settings") s_respawn_settings_definition
		{
			enum nicename("Flags") b_flags : uint16_t /* bitfield */
			{
				/*nicename("Inherit Respawn Time")*/ _flags_inherit_respawn_time = 1ui16 << 0ui16,
				/*nicename("Respawn With Team")*/ _flags_respawn_with_team = 1ui16 << 1ui16,
				/*nicename("Respawn At Location")*/ _flags_respawn_at_location = 1ui16 << 2ui16,
				/*nicename("Respawn On Kills")*/ _flags_respawn_on_kills = 1ui16 << 3ui16,
			};

			b_flags nicename("Flags") flags;
			int8_t nicename("Lives Per Round") lives_per_round;
			int8_t nicename("Shared Team Lives") shared_team_lives;
			int8_t nicename("Respawn Time") respawn_time;
			int8_t nicename("Suicide Penalty") suicide_penalty;
			int8_t nicename("Betrayal Penalty") betrayal_penalty;
			int8_t nicename("Respawn Time Growth") respawn_time_growth;
			string_id nicename("Respawn Trait Profile") respawn_trait_profile;
			int8_t nicename("Loadout Selection Time") loadout_selection_time;
			int8_t nicename("Respawn Trait Duration") respawn_trait_duration;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		struct nicename("Social Settings") s_social_settings_definition
		{
			enum nicename("Flags") b_flags : uint32_t /* bitfield */
			{
				/*nicename("Observers Enabled")*/ _flags_observers_enabled = 1ui32 << 0ui32,
				/*nicename("Team Changing Enabled")*/ _flags_team_changing_enabled = 1ui32 << 1ui32,
				/*nicename("Balanced Team Changing")*/ _flags_balanced_team_changing = 1ui32 << 2ui32,
				/*nicename("Friendly Fire Enabled")*/ _flags_friendly_fire_enabled = 1ui32 << 3ui32,
				/*nicename("Betrayal Booting Enabled")*/ _flags_betrayal_booting_enabled = 1ui32 << 4ui32,
				/*nicename("Enemy Voice Enabled")*/ _flags_enemy_voice_enabled = 1ui32 << 5ui32,
				/*nicename("Open Channel Voice Enabled")*/ _flags_open_channel_voice_enabled = 1ui32 << 6ui32,
				/*nicename("Dead Player Voice Enabled")*/ _flags_dead_player_voice_enabled = 1ui32 << 7ui32,
			};

			b_flags nicename("Flags") flags;
		};

		struct nicename("Map Overrides") s_map_overrides_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Grenades On Map")*/ _flags_grenades_on_map = 1ui8 << 0ui8,
				/*nicename("Shortcuts On Map")*/ _flags_shortcuts_on_map = 1ui8 << 1ui8,
				/*nicename("Abilities On Map")*/ _flags_abilities_on_map = 1ui8 << 2ui8,
				/*nicename("Powerups On Map")*/ _flags_powerups_on_map = 1ui8 << 3ui8,
				/*nicename("Turrets On Map")*/ _flags_turrets_on_map = 1ui8 << 4ui8,
				/*nicename("Indestructable Vehicles")*/ _flags_indestructable_vehicles = 1ui8 << 5ui8,
			};

			string_id nicename("Base Player Trait Profile") base_player_trait_profile;
			string_id nicename("Weapon Set") weapon_set;
			string_id nicename("Vehicle Set") vehicle_set;
			string_id nicename("Overshield Trait Profile") overshield_trait_profile;
			string_id nicename("Active Camo Trait Profile") active_camo_trait_profile;
			string_id nicename("Custom Powerup Trait Profile") custom_powerup_trait_profile;
			int8_t nicename("Overshield Trait Duration") overshield_trait_duration;
			int8_t nicename("Active Camo Trait Duration") active_camo_trait_duration;
			int8_t nicename("Custom Powerup Trait Duration") custom_powerup_trait_duration;
			b_flags nicename("Flags") flags;
		};

		struct nicename("Teams") s_teams_definition
		{
			enum nicename("Model Override") e_model_override : uint8_t
			{
				/*nicename("Player Default")*/ _model_override_player_default = 1ui8,
				/*nicename("All Spartans")*/ _model_override_all_spartans = 2ui8,
				/*nicename("All Elites")*/ _model_override_all_elites = 3ui8,
				/*nicename("Team Default")*/ _model_override_team_default = 4ui8,
				/*nicename("Survival (Red Spartans Blue Elites Only)")*/ _model_override_survival_red_spartans_blue_elites_only = 5ui8,
			};

			enum nicename("Team Model") e_team_model : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model1 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model1_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model1_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model2 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model2_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model2_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model3 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model3_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model3_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model4 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model4_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model4_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model5 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model5_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model5_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model6 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model6_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model6_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model7 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model7_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model7_elite = 2ui8,
			};

			enum nicename("Team Flags") b_team_flags : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags1 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags1_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags1_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags1_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags1_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags2 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags2_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags2_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags2_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags2_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags3 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags3_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags3_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags3_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags3_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags4 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags4_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags4_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags4_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags4_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags5 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags5_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags5_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags5_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags5_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags6 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags6_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags6_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags6_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags6_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags7 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags7_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags7_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags7_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags7_override_ui_color = 1ui8 << 3ui8,
			};

			e_model_override nicename("Model Override") model_override;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			// Team 0 : 
			b_team_flags nicename("Team Flags") team_flags;
			int8_t nicename("Team Index") team_index;
			e_team_model nicename("Team Model") team_model;
			int8_t nicename("Fireteam Count") fireteam_count;
			string_id nicename("Team Name") team_name;
			uint8_t nicename("Primary Alpha") primary_alpha;
			color24 nicename("Primary Color") primary_color;
			uint8_t nicename("Secondary Alpha") secondary_alpha;
			color24 nicename("Secondary Color") secondary_color;
			color32 nicename("UI Color") ui_color;
			// Team 1 : 
			b_team_flags1 nicename("Team Flags") team_flags1;
			int8_t nicename("Team Index") team_index1;
			e_team_model1 nicename("Team Model") team_model1;
			int8_t nicename("Fireteam Count") fireteam_count1;
			string_id nicename("Team Name") team_name1;
			uint8_t nicename("Primary Alpha") primary_alpha1;
			color24 nicename("Primary Color") primary_color1;
			uint8_t nicename("Secondary Alpha") secondary_alpha1;
			color24 nicename("Secondary Color") secondary_color1;
			color32 nicename("UI Color") ui_color1;
			// Team 2 : 
			b_team_flags2 nicename("Team Flags") team_flags2;
			int8_t nicename("Team Index") team_index2;
			e_team_model2 nicename("Team Model") team_model2;
			int8_t nicename("Fireteam Count") fireteam_count2;
			string_id nicename("Team Name") team_name2;
			uint8_t nicename("Primary Alpha") primary_alpha2;
			color24 nicename("Primary Color") primary_color2;
			uint8_t nicename("Secondary Alpha") secondary_alpha2;
			color24 nicename("Secondary Color") secondary_color2;
			color32 nicename("UI Color") ui_color2;
			// Team 3 : 
			b_team_flags3 nicename("Team Flags") team_flags3;
			int8_t nicename("Team Index") team_index3;
			e_team_model3 nicename("Team Model") team_model3;
			int8_t nicename("Fireteam Count") fireteam_count3;
			string_id nicename("Team Name") team_name3;
			uint8_t nicename("Primary Alpha") primary_alpha3;
			color24 nicename("Primary Color") primary_color3;
			uint8_t nicename("Secondary Alpha") secondary_alpha3;
			color24 nicename("Secondary Color") secondary_color3;
			color32 nicename("UI Color") ui_color3;
			// Team 4 : 
			b_team_flags4 nicename("Team Flags") team_flags4;
			int8_t nicename("Team Index") team_index4;
			e_team_model4 nicename("Team Model") team_model4;
			int8_t nicename("Fireteam Count") fireteam_count4;
			string_id nicename("Team Name") team_name4;
			uint8_t nicename("Primary Alpha") primary_alpha4;
			color24 nicename("Primary Color") primary_color4;
			uint8_t nicename("Secondary Alpha") secondary_alpha4;
			color24 nicename("Secondary Color") secondary_color4;
			color32 nicename("UI Color") ui_color4;
			// Team 5 : 
			b_team_flags5 nicename("Team Flags") team_flags5;
			int8_t nicename("Team Index") team_index5;
			e_team_model5 nicename("Team Model") team_model5;
			int8_t nicename("Fireteam Count") fireteam_count5;
			string_id nicename("Team Name") team_name5;
			uint8_t nicename("Primary Alpha") primary_alpha5;
			color24 nicename("Primary Color") primary_color5;
			uint8_t nicename("Secondary Alpha") secondary_alpha5;
			color24 nicename("Secondary Color") secondary_color5;
			color32 nicename("UI Color") ui_color5;
			// Team 6 : 
			b_team_flags6 nicename("Team Flags") team_flags6;
			int8_t nicename("Team Index") team_index6;
			e_team_model6 nicename("Team Model") team_model6;
			int8_t nicename("Fireteam Count") fireteam_count6;
			string_id __unknown3;
			uint8_t nicename("Primary Alpha") primary_alpha6;
			color24 nicename("Primary Color") primary_color6;
			uint8_t nicename("Secondary Alpha") secondary_alpha6;
			color24 nicename("Secondary Color") secondary_color6;
			color32 nicename("UI Color") ui_color6;
			// Team 7 : 
			b_team_flags7 nicename("Team Flags") team_flags7;
			int8_t nicename("Team Index") team_index7;
			e_team_model7 nicename("Team Model") team_model7;
			int8_t nicename("Fireteam Count") fireteam_count7;
			string_id nicename("Team Name") team_name6;
			uint8_t nicename("Primary Alpha") primary_alpha7;
			color24 nicename("Primary Color") primary_color7;
			uint8_t nicename("Secondary Alpha") secondary_alpha7;
			color24 nicename("Secondary Color") secondary_color7;
			color32 nicename("UI Color") ui_color7;
		};

		struct nicename("Loadouts") s_loadouts_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Spartan Initial Selection")*/ _flags_spartan_initial_selection = 1ui8 << 0ui8,
				/*nicename("Elite Initial Selection")*/ _flags_elite_initial_selection = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
			};

			struct nicename("Loadout Palette") s_loadout_palette_definition
			{
				string_id nicename("Loadout") loadout;
			};

			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			s_tag_block_definition<s_loadout_palette_definition> nicename("Loadout Palette") loadout_palette_block;
		};

		string_id nicename("Variant Name") variant_name;
		string_id nicename("Variant Description") variant_description;
		s_tag_block_definition<s_general_settings_definition> nicename("General Settings") general_settings_block;
		s_tag_block_definition<s_respawn_settings_definition> nicename("Respawn Settings") respawn_settings_block;
		s_tag_block_definition<s_social_settings_definition> nicename("Social Settings") social_settings_block;
		s_tag_block_definition<s_map_overrides_definition> nicename("Map Overrides") map_overrides_block;
		s_tag_block_definition<s_teams_definition> nicename("Teams") teams_block;
		s_tag_block_definition<s_loadouts_definition> nicename("Loadouts") loadouts_block;
		b_flags nicename("Flags") flags;
		e_edit_mode nicename("Edit Mode") edit_mode;
		int16_t nicename("Editor Respawn Time") editor_respawn_time;
		string_id nicename("Editor Trait Profile") editor_trait_profile;
	};

	struct nicename("Survival Variants") s_survival_variants_definition
	{
		enum nicename("Campaign Difficulty Level") e_campaign_difficulty_level : uint8_t
		{
			/*nicename("Unchanged")*/ _campaign_difficulty_level_unchanged = 1ui8,
			/*nicename("Easy")*/ _campaign_difficulty_level_easy = 2ui8,
			/*nicename("Normal")*/ _campaign_difficulty_level_normal = 3ui8,
			/*nicename("Heroic")*/ _campaign_difficulty_level_heroic = 4ui8,
			/*nicename("Legendary")*/ _campaign_difficulty_level_legendary = 5ui8,
		};

		enum nicename("Generator Count") e_generator_count : uint16_t
		{
			/*nicename("None")*/ _generator_count_none = 1ui16,
			/*nicename("1 Generator")*/ _generator_count__1_generator = 2ui16,
			/*nicename("2 Generators")*/ _generator_count__2_generators = 3ui16,
			/*nicename("3 Generators")*/ _generator_count__3_generators = 4ui16,
		};

		enum nicename("Scenario Flags") b_scenario_flags : uint8_t /* bitfield */
		{
			/*nicename("Hazards")*/ _scenario_flags_hazards = 1ui8 << 0ui8,
			/*nicename("One Generator To Lose")*/ _scenario_flags_one_generator_to_lose = 1ui8 << 1ui8,
			/*nicename("Random Generator Order")*/ _scenario_flags_random_generator_order = 1ui8 << 2ui8,
			/*nicename("Weapon Drops")*/ _scenario_flags_weapon_drops = 1ui8 << 3ui8,
			/*nicename("Ammo Crates")*/ _scenario_flags_ammo_crates = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _scenario_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _scenario_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _scenario_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Bonus Round Skulls") b_bonus_round_skulls : uint32_t /* bitfield */
		{
			/*nicename("Iron")*/ _bonus_round_skulls_iron = 1ui32 << 0ui32,
			/*nicename("Black Eye")*/ _bonus_round_skulls_black_eye = 1ui32 << 1ui32,
			/*nicename("Tough Luck")*/ _bonus_round_skulls_tough_luck = 1ui32 << 2ui32,
			/*nicename("Catch")*/ _bonus_round_skulls_catch = 1ui32 << 3ui32,
			/*nicename("Cloud")*/ _bonus_round_skulls_cloud = 1ui32 << 4ui32,
			/*nicename("Famine")*/ _bonus_round_skulls_famine = 1ui32 << 5ui32,
			/*nicename("Thunderstorm")*/ _bonus_round_skulls_thunderstorm = 1ui32 << 6ui32,
			/*nicename("Tilt")*/ _bonus_round_skulls_tilt = 1ui32 << 7ui32,
			/*nicename("Mythic")*/ _bonus_round_skulls_mythic = 1ui32 << 8ui32,
			/*nicename("Assassin")*/ _bonus_round_skulls_assassin = 1ui32 << 9ui32,
			/*nicename("Blind")*/ _bonus_round_skulls_blind = 1ui32 << 10ui32,
			/*nicename("Cowbell")*/ _bonus_round_skulls_cowbell = 1ui32 << 11ui32,
			/*nicename("Grunt Brithday")*/ _bonus_round_skulls_grunt_brithday = 1ui32 << 12ui32,
			/*nicename("IWHBYD")*/ _bonus_round_skulls_iwhbyd = 1ui32 << 13ui32,
			/*nicename("Red Custom")*/ _bonus_round_skulls_red_custom = 1ui32 << 14ui32,
			/*nicename("Yellow Custom")*/ _bonus_round_skulls_yellow_custom = 1ui32 << 15ui32,
			/*nicename("Blue Custom")*/ _bonus_round_skulls_blue_custom = 1ui32 << 16ui32,
		};

		enum nicename("Wave Flags") b_wave_flags : uint8_t /* bitfield */
		{
			/*nicename("Uses Dropship")*/ _wave_flags_uses_dropship = 1ui8 << 0ui8,
		};

		enum nicename("Squad Advance Type") b_squad_advance_type : uint8_t /* bitfield */
		{
			/*nicename("Ordered")*/ _squad_advance_type_ordered = 1ui8 << 0ui8,
		};

		struct nicename("General Settings") s_general_settings1_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Teams Enabled")*/ _flags_teams_enabled = 1ui8 << 0ui8,
				/*nicename("Round Resets Players")*/ _flags_round_resets_players = 1ui8 << 1ui8,
				/*nicename("Round Resets Map")*/ _flags_round_resets_map = 1ui8 << 2ui8,
			};

			b_flags nicename("Flags") flags;
			int8_t nicename("Early Victory Win Count") early_victory_win_count;
			int8_t nicename("Time Limit") time_limit;
			int8_t nicename("Number of Rounds") number_of_rounds;
			int16_t nicename("Sudden Death") sudden_death;
			int16_t nicename("Grace Period") grace_period;
		};

		struct nicename("Respawn Settings") s_respawn_settings1_definition
		{
			enum nicename("Flags") b_flags : uint16_t /* bitfield */
			{
				/*nicename("Inherit Respawn Time")*/ _flags_inherit_respawn_time = 1ui16 << 0ui16,
				/*nicename("Respawn With Team")*/ _flags_respawn_with_team = 1ui16 << 1ui16,
				/*nicename("Respawn At Location")*/ _flags_respawn_at_location = 1ui16 << 2ui16,
				/*nicename("Respawn On Kills")*/ _flags_respawn_on_kills = 1ui16 << 3ui16,
			};

			b_flags nicename("Flags") flags;
			int8_t nicename("Lives Per Round") lives_per_round;
			int8_t nicename("Shared Team Lives") shared_team_lives;
			int8_t nicename("Respawn Time") respawn_time;
			int8_t nicename("Suicide Penalty") suicide_penalty;
			int8_t nicename("Betrayal Penalty") betrayal_penalty;
			int8_t nicename("Respawn Time Growth") respawn_time_growth;
			string_id nicename("Respawn Trait Profile") respawn_trait_profile;
			int8_t nicename("Loadout Selection Time") loadout_selection_time;
			int8_t nicename("Respawn Trait Duration") respawn_trait_duration;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		struct nicename("Social Settings") s_social_settings1_definition
		{
			enum nicename("Flags") b_flags : uint32_t /* bitfield */
			{
				/*nicename("Observers Enabled")*/ _flags_observers_enabled = 1ui32 << 0ui32,
				/*nicename("Team Changing Enabled")*/ _flags_team_changing_enabled = 1ui32 << 1ui32,
				/*nicename("Balanced Team Changing")*/ _flags_balanced_team_changing = 1ui32 << 2ui32,
				/*nicename("Friendly Fire Enabled")*/ _flags_friendly_fire_enabled = 1ui32 << 3ui32,
				/*nicename("Betrayal Booting Enabled")*/ _flags_betrayal_booting_enabled = 1ui32 << 4ui32,
				/*nicename("Enemy Voice Enabled")*/ _flags_enemy_voice_enabled = 1ui32 << 5ui32,
				/*nicename("Open Channel Voice Enabled")*/ _flags_open_channel_voice_enabled = 1ui32 << 6ui32,
				/*nicename("Dead Player Voice Enabled")*/ _flags_dead_player_voice_enabled = 1ui32 << 7ui32,
			};

			b_flags nicename("Flags") flags;
		};

		struct nicename("Map Overrides") s_map_overrides1_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Grenades On Map")*/ _flags_grenades_on_map = 1ui8 << 0ui8,
				/*nicename("Shortcuts On Map")*/ _flags_shortcuts_on_map = 1ui8 << 1ui8,
				/*nicename("Abilities On Map")*/ _flags_abilities_on_map = 1ui8 << 2ui8,
				/*nicename("Powerups On Map")*/ _flags_powerups_on_map = 1ui8 << 3ui8,
				/*nicename("Turrets On Map")*/ _flags_turrets_on_map = 1ui8 << 4ui8,
				/*nicename("Indestructable Vehicles")*/ _flags_indestructable_vehicles = 1ui8 << 5ui8,
			};

			string_id nicename("Base Player Trait Profile") base_player_trait_profile;
			string_id nicename("Weapon Set") weapon_set;
			string_id nicename("Vehicle Set") vehicle_set;
			string_id nicename("Overshield Trait Profile") overshield_trait_profile;
			string_id nicename("Active Camo Trait Profile") active_camo_trait_profile;
			string_id nicename("Custom Powerup Trait Profile") custom_powerup_trait_profile;
			int8_t nicename("Overshield Trait Duration") overshield_trait_duration;
			int8_t nicename("Active Camo Trait Duration") active_camo_trait_duration;
			int8_t nicename("Custom Powerup Trait Duration") custom_powerup_trait_duration;
			b_flags nicename("Flags") flags;
		};

		struct nicename("Teams") s_teams1_definition
		{
			enum nicename("Model Override") e_model_override : uint8_t
			{
				/*nicename("Player Default")*/ _model_override_player_default = 1ui8,
				/*nicename("All Spartans")*/ _model_override_all_spartans = 2ui8,
				/*nicename("All Elites")*/ _model_override_all_elites = 3ui8,
				/*nicename("Team Default")*/ _model_override_team_default = 4ui8,
				/*nicename("Survival (Red Spartans Blue Elites Only)")*/ _model_override_survival_red_spartans_blue_elites_only = 5ui8,
			};

			enum nicename("Team Model") e_team_model : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model1 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model1_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model1_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model2 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model2_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model2_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model3 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model3_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model3_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model4 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model4_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model4_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model5 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model5_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model5_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model6 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model6_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model6_elite = 2ui8,
			};

			enum nicename("Team Model") e_team_model7 : uint8_t
			{
				/*nicename("Spartan/Default")*/ _team_model7_spartan_default = 1ui8,
				/*nicename("Elite")*/ _team_model7_elite = 2ui8,
			};

			enum nicename("Team Flags") b_team_flags : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags1 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags1_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags1_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags1_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags1_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags2 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags2_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags2_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags2_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags2_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags3 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags3_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags3_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags3_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags3_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags4 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags4_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags4_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags4_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags4_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags5 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags5_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags5_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags5_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags5_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags6 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags6_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags6_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags6_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags6_override_ui_color = 1ui8 << 3ui8,
			};

			enum nicename("Team Flags") b_team_flags7 : uint8_t /* bitfield */
			{
				/*nicename("Enabled")*/ _team_flags7_enabled = 1ui8 << 0ui8,
				/*nicename("Override Primary Color")*/ _team_flags7_override_primary_color = 1ui8 << 1ui8,
				/*nicename("Override Secondary Color")*/ _team_flags7_override_secondary_color = 1ui8 << 2ui8,
				/*nicename("Override UI Color")*/ _team_flags7_override_ui_color = 1ui8 << 3ui8,
			};

			e_model_override nicename("Model Override") model_override;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			// Team 0 : 
			b_team_flags nicename("Team Flags") team_flags;
			int8_t nicename("Team Index") team_index;
			e_team_model nicename("Team Model") team_model;
			int8_t nicename("Fireteam Count") fireteam_count;
			string_id nicename("Team Name") team_name;
			uint8_t nicename("Primary Alpha") primary_alpha;
			color24 nicename("Primary Color") primary_color;
			uint8_t nicename("Secondary Alpha") secondary_alpha;
			color24 nicename("Secondary Color") secondary_color;
			color32 nicename("UI Color") ui_color;
			// Team 1 : 
			b_team_flags1 nicename("Team Flags") team_flags1;
			int8_t nicename("Team Index") team_index1;
			e_team_model1 nicename("Team Model") team_model1;
			int8_t nicename("Fireteam Count") fireteam_count1;
			string_id nicename("Team Name") team_name1;
			uint8_t nicename("Primary Alpha") primary_alpha1;
			color24 nicename("Primary Color") primary_color1;
			uint8_t nicename("Secondary Alpha") secondary_alpha1;
			color24 nicename("Secondary Color") secondary_color1;
			color32 nicename("UI Color") ui_color1;
			// Team 2 : 
			b_team_flags2 nicename("Team Flags") team_flags2;
			int8_t nicename("Team Index") team_index2;
			e_team_model2 nicename("Team Model") team_model2;
			int8_t nicename("Fireteam Count") fireteam_count2;
			string_id nicename("Team Name") team_name2;
			uint8_t nicename("Primary Alpha") primary_alpha2;
			color24 nicename("Primary Color") primary_color2;
			uint8_t nicename("Secondary Alpha") secondary_alpha2;
			color24 nicename("Secondary Color") secondary_color2;
			color32 nicename("UI Color") ui_color2;
			// Team 3 : 
			b_team_flags3 nicename("Team Flags") team_flags3;
			int8_t nicename("Team Index") team_index3;
			e_team_model3 nicename("Team Model") team_model3;
			int8_t nicename("Fireteam Count") fireteam_count3;
			string_id nicename("Team Name") team_name3;
			uint8_t nicename("Primary Alpha") primary_alpha3;
			color24 nicename("Primary Color") primary_color3;
			uint8_t nicename("Secondary Alpha") secondary_alpha3;
			color24 nicename("Secondary Color") secondary_color3;
			color32 nicename("UI Color") ui_color3;
			// Team 4 : 
			b_team_flags4 nicename("Team Flags") team_flags4;
			int8_t nicename("Team Index") team_index4;
			e_team_model4 nicename("Team Model") team_model4;
			int8_t nicename("Fireteam Count") fireteam_count4;
			string_id nicename("Team Name") team_name4;
			uint8_t nicename("Primary Alpha") primary_alpha4;
			color24 nicename("Primary Color") primary_color4;
			uint8_t nicename("Secondary Alpha") secondary_alpha4;
			color24 nicename("Secondary Color") secondary_color4;
			color32 nicename("UI Color") ui_color4;
			// Team 5 : 
			b_team_flags5 nicename("Team Flags") team_flags5;
			int8_t nicename("Team Index") team_index5;
			e_team_model5 nicename("Team Model") team_model5;
			int8_t nicename("Fireteam Count") fireteam_count5;
			string_id nicename("Team Name") team_name5;
			uint8_t nicename("Primary Alpha") primary_alpha5;
			color24 nicename("Primary Color") primary_color5;
			uint8_t nicename("Secondary Alpha") secondary_alpha5;
			color24 nicename("Secondary Color") secondary_color5;
			color32 nicename("UI Color") ui_color5;
			// Team 6 : 
			b_team_flags6 nicename("Team Flags") team_flags6;
			int8_t nicename("Team Index") team_index6;
			e_team_model6 nicename("Team Model") team_model6;
			int8_t nicename("Fireteam Count") fireteam_count6;
			string_id __unknown3;
			uint8_t nicename("Primary Alpha") primary_alpha6;
			color24 nicename("Primary Color") primary_color6;
			uint8_t nicename("Secondary Alpha") secondary_alpha6;
			color24 nicename("Secondary Color") secondary_color6;
			color32 nicename("UI Color") ui_color6;
			// Team 7 : 
			b_team_flags7 nicename("Team Flags") team_flags7;
			int8_t nicename("Team Index") team_index7;
			e_team_model7 nicename("Team Model") team_model7;
			int8_t nicename("Fireteam Count") fireteam_count7;
			string_id nicename("Team Name") team_name6;
			uint8_t nicename("Primary Alpha") primary_alpha7;
			color24 nicename("Primary Color") primary_color7;
			uint8_t nicename("Secondary Alpha") secondary_alpha7;
			color24 nicename("Secondary Color") secondary_color7;
			color32 nicename("UI Color") ui_color7;
		};

		struct nicename("Loadouts") s_loadouts1_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Spartan Initial Selection")*/ _flags_spartan_initial_selection = 1ui8 << 0ui8,
				/*nicename("Elite Initial Selection")*/ _flags_elite_initial_selection = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
			};

			struct nicename("Loadout Palette") s_loadout_palette1_definition
			{
				string_id nicename("Loadout") loadout;
			};

			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			s_tag_block_definition<s_loadout_palette1_definition> nicename("Loadout Palette") loadout_palette_block;
		};

		struct nicename("Elite Respawn Settings") s_elite_respawn_settings_definition
		{
			enum nicename("Flags") b_flags : uint16_t /* bitfield */
			{
				/*nicename("Inherit Respawn Time")*/ _flags_inherit_respawn_time = 1ui16 << 0ui16,
				/*nicename("Respawn With Team")*/ _flags_respawn_with_team = 1ui16 << 1ui16,
				/*nicename("Respawn At Location")*/ _flags_respawn_at_location = 1ui16 << 2ui16,
				/*nicename("Respawn On Kills")*/ _flags_respawn_on_kills = 1ui16 << 3ui16,
			};

			b_flags nicename("Flags") flags;
			int8_t nicename("Lives Per Round") lives_per_round;
			int8_t nicename("Shared Team Lives") shared_team_lives;
			int8_t nicename("Respawn Time") respawn_time;
			int8_t nicename("Suicide Penalty") suicide_penalty;
			int8_t nicename("Betrayal Penalty") betrayal_penalty;
			int8_t nicename("Respawn Time Growth") respawn_time_growth;
			string_id nicename("Respawn Trait Profile") respawn_trait_profile;
			int8_t nicename("Loadout Selection Time") loadout_selection_time;
			int8_t nicename("Respawn Trait Duration") respawn_trait_duration;
			int8_t __unknown0;
			int8_t __unknown1;
		};

		struct nicename("Unknown Skulls") s_unknown_skulls_definition
		{
			enum nicename("Skulls") b_skulls : uint16_t /* bitfield */
			{
				/*nicename("Iron")*/ _skulls_iron = 1ui16 << 0ui16,
				/*nicename("Black Eye")*/ _skulls_black_eye = 1ui16 << 1ui16,
				/*nicename("Tough Luck")*/ _skulls_tough_luck = 1ui16 << 2ui16,
				/*nicename("Catch")*/ _skulls_catch = 1ui16 << 3ui16,
				/*nicename("Cloud")*/ _skulls_cloud = 1ui16 << 4ui16,
				/*nicename("Famine")*/ _skulls_famine = 1ui16 << 5ui16,
				/*nicename("Thunderstorm")*/ _skulls_thunderstorm = 1ui16 << 6ui16,
				/*nicename("Tilt")*/ _skulls_tilt = 1ui16 << 7ui16,
				/*nicename("Mythic")*/ _skulls_mythic = 1ui16 << 8ui16,
				/*nicename("Assassin")*/ _skulls_assassin = 1ui16 << 9ui16,
				/*nicename("Blind")*/ _skulls_blind = 1ui16 << 10ui16,
				/*nicename("Cowbell")*/ _skulls_cowbell = 1ui16 << 11ui16,
				/*nicename("Grunt Brithday")*/ _skulls_grunt_brithday = 1ui16 << 12ui16,
				/*nicename("IWHBYD")*/ _skulls_iwhbyd = 1ui16 << 13ui16,
			};

			b_skulls nicename("Skulls") skulls;
		};

		struct nicename("Rounds") s_rounds_definition
		{
			enum nicename("Round Skulls") b_round_skulls : uint32_t /* bitfield */
			{
				/*nicename("Iron")*/ _round_skulls_iron = 1ui32 << 0ui32,
				/*nicename("Black Eye")*/ _round_skulls_black_eye = 1ui32 << 1ui32,
				/*nicename("Tough Luck")*/ _round_skulls_tough_luck = 1ui32 << 2ui32,
				/*nicename("Catch")*/ _round_skulls_catch = 1ui32 << 3ui32,
				/*nicename("Cloud")*/ _round_skulls_cloud = 1ui32 << 4ui32,
				/*nicename("Famine")*/ _round_skulls_famine = 1ui32 << 5ui32,
				/*nicename("Thunderstorm")*/ _round_skulls_thunderstorm = 1ui32 << 6ui32,
				/*nicename("Tilt")*/ _round_skulls_tilt = 1ui32 << 7ui32,
				/*nicename("Mythic")*/ _round_skulls_mythic = 1ui32 << 8ui32,
				/*nicename("Assassin")*/ _round_skulls_assassin = 1ui32 << 9ui32,
				/*nicename("Blind")*/ _round_skulls_blind = 1ui32 << 10ui32,
				/*nicename("Cowbell")*/ _round_skulls_cowbell = 1ui32 << 11ui32,
				/*nicename("Grunt Brithday")*/ _round_skulls_grunt_brithday = 1ui32 << 12ui32,
				/*nicename("IWHBYD")*/ _round_skulls_iwhbyd = 1ui32 << 13ui32,
				/*nicename("Red Custom")*/ _round_skulls_red_custom = 1ui32 << 14ui32,
				/*nicename("Yellow Custom")*/ _round_skulls_yellow_custom = 1ui32 << 15ui32,
				/*nicename("Blue Custom")*/ _round_skulls_blue_custom = 1ui32 << 16ui32,
			};

			enum nicename("Wave Flags") b_wave_flags : uint8_t /* bitfield */
			{
				/*nicename("Uses Dropship")*/ _wave_flags_uses_dropship = 1ui8 << 0ui8,
			};

			enum nicename("Squad Advance Type") b_squad_advance_type : uint8_t /* bitfield */
			{
				/*nicename("Ordered")*/ _squad_advance_type_ordered = 1ui8 << 0ui8,
			};

			enum nicename("Wave Flags") b_wave_flags1 : uint8_t /* bitfield */
			{
				/*nicename("Uses Dropship")*/ _wave_flags1_uses_dropship = 1ui8 << 0ui8,
			};

			enum nicename("Squad Advance Type") b_squad_advance_type1 : uint8_t /* bitfield */
			{
				/*nicename("Ordered")*/ _squad_advance_type1_ordered = 1ui8 << 0ui8,
			};

			enum nicename("Wave Flags") b_wave_flags2 : uint8_t /* bitfield */
			{
				/*nicename("Uses Dropship")*/ _wave_flags2_uses_dropship = 1ui8 << 0ui8,
			};

			enum nicename("Squad Advance Type") b_squad_advance_type2 : uint8_t /* bitfield */
			{
				/*nicename("Ordered")*/ _squad_advance_type2_ordered = 1ui8 << 0ui8,
			};

			struct nicename("Squads") s_squads_definition
			{
				string_id nicename("Enemy") enemy;
			};

			struct nicename("Squads") s_squads1_definition
			{
				string_id nicename("Enemy") enemy;
			};

			struct nicename("Squads") s_squads2_definition
			{
				string_id nicename("Enemy") enemy;
			};

			b_round_skulls nicename("Round Skulls") round_skulls;
			// Initial Wave : 
			b_wave_flags nicename("Wave Flags") wave_flags;
			b_squad_advance_type nicename("Squad Advance Type") squad_advance_type;
			int8_t __unknown0;
			int8_t __unknown1;
			s_tag_block_definition<s_squads_definition> nicename("Squads") squads_block;
			// Main Wave : 
			b_wave_flags1 nicename("Wave Flags") wave_flags1;
			b_squad_advance_type1 nicename("Squad Advance Type") squad_advance_type1;
			int8_t __unknown2;
			int8_t __unknown3;
			s_tag_block_definition<s_squads1_definition> nicename("Squads") squads1_block;
			// Boss Wave : 
			b_wave_flags2 nicename("Wave Flags") wave_flags2;
			b_squad_advance_type2 nicename("Squad Advance Type") squad_advance_type2;
			int8_t __unknown4;
			int8_t __unknown5;
			s_tag_block_definition<s_squads2_definition> nicename("Squads") squads2_block;
		};

		struct nicename("Bonus Round Squads") s_bonus_round_squads_definition
		{
			string_id nicename("Enemy") enemy;
		};

		struct nicename("Custom Skull Traits") s_custom_skull_traits_definition
		{
			string_id nicename("Spartan Player Trait Profile") spartan_player_trait_profile;
			string_id nicename("Elite Player Trait Profile") elite_player_trait_profile;
			string_id nicename("AI Trait Profile") ai_trait_profile;
		};

		string_id nicename("Variant Name") variant_name;
		string_id nicename("Variant Description") variant_description;
		s_tag_block_definition<s_general_settings1_definition> nicename("General Settings") general_settings_block;
		s_tag_block_definition<s_respawn_settings1_definition> nicename("Respawn Settings") respawn_settings_block;
		s_tag_block_definition<s_social_settings1_definition> nicename("Social Settings") social_settings_block;
		s_tag_block_definition<s_map_overrides1_definition> nicename("Map Overrides") map_overrides_block;
		s_tag_block_definition<s_teams1_definition> nicename("Teams") teams_block;
		s_tag_block_definition<s_loadouts1_definition> nicename("Loadouts") loadouts_block;
		b_scenario_flags nicename("Scenario Flags") scenario_flags;
		e_campaign_difficulty_level nicename("Campaign Difficulty Level") campaign_difficulty_level;
		int8_t nicename("Time Limit") time_limit;
		int8_t __unknown0;
		int8_t nicename("Wave Limit") wave_limit;
		int8_t nicename("Bonus Lives Awarded") bonus_lives_awarded;
		int16_t nicename("Bonus Target") bonus_target;
		int16_t nicename("Bonus Lives On Elite Player Kill") bonus_lives_on_elite_player_kill;
		int16_t nicename("Extra Life Score Target") extra_life_score_target;
		int16_t nicename("Spartan Starting Lives") spartan_starting_lives;
		int16_t nicename("Elite Starting Lives") elite_starting_lives;
		int16_t nicename("Spartan Maximum Lives") spartan_maximum_lives;
		e_generator_count nicename("Generator Count") generator_count;
		string_id nicename("Spartan Trait Profile") spartan_trait_profile;
		string_id nicename("Elite Trait Profile") elite_trait_profile;
		string_id nicename("AI Trait Profile") ai_trait_profile;
		s_tag_block_definition<s_elite_respawn_settings_definition> nicename("Elite Respawn Settings") elite_respawn_settings_block;
		s_tag_block_definition<s_unknown_skulls_definition> nicename("Unknown Skulls") unknown_skulls_block;
		s_tag_block_definition<s_rounds_definition> nicename("Rounds") rounds_block;
		b_bonus_round_skulls nicename("Bonus Round Skulls") bonus_round_skulls;
		int16_t nicename("Bonus Round Duration") bonus_round_duration;
		int16_t __unknown1;
		b_wave_flags nicename("Wave Flags") wave_flags;
		b_squad_advance_type nicename("Squad Advance Type") squad_advance_type;
		int8_t __unknown2;
		int8_t __unknown3;
		s_tag_block_definition<s_bonus_round_squads_definition> nicename("Bonus Round Squads") bonus_round_squads_block;
		/* Custom Skulls : Index 0 - Red
		   Index 1 - Yellow
		   Index 2 - Blue */
		s_tag_block_definition<s_custom_skull_traits_definition> nicename("Custom Skull Traits") custom_skull_traits_block;
	};

	Undefined32 __unknown0;
	s_tag_block_definition<s_trait_profiles_definition> nicename("Trait Profiles") trait_profiles_block;
	s_tag_block_definition<s_ai_trait_profiles_definition> nicename("AI Trait Profiles") ai_trait_profiles_block;
	s_tag_block_definition<s_sandbox_variants_definition> nicename("Sandbox Variants") sandbox_variants_block;
	s_tag_block_definition<s_survival_variants_definition> nicename("Survival Variants") survival_variants_block;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
};

