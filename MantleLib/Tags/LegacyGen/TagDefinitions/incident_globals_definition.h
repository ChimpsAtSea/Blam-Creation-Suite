#pragma once

struct nicename("incident_globals_definition") tag_group('ingd') s_incident_globals_definition_definition
{
	struct nicename("Incidents") s_incidents_definition
	{
		enum nicename("Not Allowed In Mode") b_not_allowed_in_mode : uint8_t /* bitfield */
		{
			/*nicename("Campaign")*/ _not_allowed_in_mode_campaign = 1ui8 << 0ui8,
			/*nicename("Firefight")*/ _not_allowed_in_mode_firefight = 1ui8 << 1ui8,
			/*nicename("Multiplayer")*/ _not_allowed_in_mode_multiplayer = 1ui8 << 2ui8,
		};

		enum nicename("Not Allowed In Mode Type") b_not_allowed_in_mode_type : uint8_t /* bitfield */
		{
			/*nicename("Custom Game")*/ _not_allowed_in_mode_type_custom_game = 1ui8 << 0ui8,
			/*nicename("Matchmaking")*/ _not_allowed_in_mode_type_matchmaking = 1ui8 << 1ui8,
		};

		enum nicename("Not Allowed On Difficulty") b_not_allowed_on_difficulty : uint8_t /* bitfield */
		{
			/*nicename("Easy")*/ _not_allowed_on_difficulty_easy = 1ui8 << 0ui8,
			/*nicename("Normal")*/ _not_allowed_on_difficulty_normal = 1ui8 << 1ui8,
			/*nicename("Heroic")*/ _not_allowed_on_difficulty_heroic = 1ui8 << 2ui8,
			/*nicename("Legendary")*/ _not_allowed_on_difficulty_legendary = 1ui8 << 3ui8,
		};

		struct nicename("Unknown") s_unknown_definition
		{
			string_id_legacy nicename("Incident") incident;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
		};

		struct nicename("Case Triggers") s_case_triggers_definition
		{
			struct nicename("Weapons Filter") s_weapons_filter_definition
			{
				enum nicename("Damage Reporting Type") e_damage_reporting_type : uint8_t
				{
					/*nicename("Guardians (Unknown)")*/ _damage_reporting_type_guardians_unknown = 1ui8,
					/*nicename("Guardians")*/ _damage_reporting_type_guardians = 2ui8,
					/*nicename("Guardians (Scripting)")*/ _damage_reporting_type_guardians_scripting = 3ui8,
					/*nicename("Suicide")*/ _damage_reporting_type_suicide = 4ui8,
					/*nicename("Magnum")*/ _damage_reporting_type_magnum = 5ui8,
					/*nicename("Assault Rifle")*/ _damage_reporting_type_assault_rifle = 6ui8,
					/*nicename("DMR")*/ _damage_reporting_type_dmr = 7ui8,
					/*nicename("Shotgun")*/ _damage_reporting_type_shotgun = 8ui8,
					/*nicename("Sniper Rifle")*/ _damage_reporting_type_sniper_rifle = 9ui8,
					/*nicename("Rocket Launcher")*/ _damage_reporting_type_rocket_launcher = 10ui8,
					/*nicename("Spartan Laser")*/ _damage_reporting_type_spartan_laser = 11ui8,
					/*nicename("Frag Grenade")*/ _damage_reporting_type_frag_grenade = 12ui8,
					/*nicename("Grenade Launcher")*/ _damage_reporting_type_grenade_launcher = 13ui8,
					/*nicename("Plasma Pistol")*/ _damage_reporting_type_plasma_pistol = 14ui8,
					/*nicename("Needler")*/ _damage_reporting_type_needler = 15ui8,
					/*nicename("Plasma Rifle")*/ _damage_reporting_type_plasma_rifle = 16ui8,
					/*nicename("Plasma Repeater")*/ _damage_reporting_type_plasma_repeater = 17ui8,
					/*nicename("Needle Rifle")*/ _damage_reporting_type_needle_rifle = 18ui8,
					/*nicename("Spiker")*/ _damage_reporting_type_spiker = 19ui8,
					/*nicename("Plasma Launcher")*/ _damage_reporting_type_plasma_launcher = 20ui8,
					/*nicename("Gravity Hammer")*/ _damage_reporting_type_gravity_hammer = 21ui8,
					/*nicename("Energy Sword")*/ _damage_reporting_type_energy_sword = 22ui8,
					/*nicename("Plasma Grenade")*/ _damage_reporting_type_plasma_grenade = 23ui8,
					/*nicename("Concussion Rifle")*/ _damage_reporting_type_concussion_rifle = 24ui8,
					/*nicename("Ghost")*/ _damage_reporting_type_ghost = 25ui8,
					/*nicename("Revenant")*/ _damage_reporting_type_revenant = 26ui8,
					/*nicename("Revenant Gunner")*/ _damage_reporting_type_revenant_gunner = 27ui8,
					/*nicename("Wraith")*/ _damage_reporting_type_wraith = 28ui8,
					/*nicename("Wraith Turret")*/ _damage_reporting_type_wraith_turret = 29ui8,
					/*nicename("Banshee")*/ _damage_reporting_type_banshee = 30ui8,
					/*nicename("Banshee Bomb")*/ _damage_reporting_type_banshee_bomb = 31ui8,
					/*nicename("Seraph")*/ _damage_reporting_type_seraph = 32ui8,
					/*nicename("Mongoose")*/ _damage_reporting_type_mongoose = 33ui8,
					/*nicename("Warthog")*/ _damage_reporting_type_warthog = 34ui8,
					/*nicename("Warthog Chaingun")*/ _damage_reporting_type_warthog_chaingun = 35ui8,
					/*nicename("Warthog Gauss")*/ _damage_reporting_type_warthog_gauss = 36ui8,
					/*nicename("Warthog Rocket")*/ _damage_reporting_type_warthog_rocket = 37ui8,
					/*nicename("Scorpion")*/ _damage_reporting_type_scorpion = 38ui8,
					/*nicename("Scorpion Turret")*/ _damage_reporting_type_scorpion_turret = 39ui8,
					/*nicename("Falcon")*/ _damage_reporting_type_falcon = 40ui8,
					/*nicename("Falcon Gunner")*/ _damage_reporting_type_falcon_gunner = 41ui8,
					/*nicename("Falling")*/ _damage_reporting_type_falling = 42ui8,
					/*nicename("Collision")*/ _damage_reporting_type_collision = 43ui8,
					/*nicename("Melee")*/ _damage_reporting_type_melee = 44ui8,
					/*nicename("Explosion")*/ _damage_reporting_type_explosion = 45ui8,
					/*nicename("Birthday Explosion")*/ _damage_reporting_type_birthday_explosion = 46ui8,
					/*nicename("Flag")*/ _damage_reporting_type_flag = 47ui8,
					/*nicename("Bomb")*/ _damage_reporting_type_bomb = 48ui8,
					/*nicename("Bomb Explosion")*/ _damage_reporting_type_bomb_explosion = 49ui8,
					/*nicename("Ball")*/ _damage_reporting_type_ball = 50ui8,
					/*nicename("Teleporter")*/ _damage_reporting_type_teleporter = 51ui8,
					/*nicename("Transfer Damage")*/ _damage_reporting_type_transfer_damage = 52ui8,
					/*nicename("Armor Lock")*/ _damage_reporting_type_armor_lock = 53ui8,
					/*nicename("Target Locator")*/ _damage_reporting_type_target_locator = 54ui8,
					/*nicename("Human Turret")*/ _damage_reporting_type_human_turret = 55ui8,
					/*nicename("Plasma Cannon")*/ _damage_reporting_type_plasma_cannon = 56ui8,
					/*nicename("Plasma Mortar")*/ _damage_reporting_type_plasma_mortar = 57ui8,
					/*nicename("Plasma Turret")*/ _damage_reporting_type_plasma_turret = 58ui8,
					/*nicename("Shade Turret")*/ _damage_reporting_type_shade_turret = 59ui8,
					/*nicename("Sabre")*/ _damage_reporting_type_sabre = 60ui8,
					/*nicename("SMG")*/ _damage_reporting_type_smg = 61ui8,
					/*nicename("Carbine")*/ _damage_reporting_type_carbine = 62ui8,
					/*nicename("Battle Rifle")*/ _damage_reporting_type_battle_rifle = 63ui8,
					/*nicename("Focus Rifle")*/ _damage_reporting_type_focus_rifle = 64ui8,
					/*nicename("Fuel Rod")*/ _damage_reporting_type_fuel_rod = 65ui8,
					/*nicename("Missile Pod")*/ _damage_reporting_type_missile_pod = 66ui8,
					/*nicename("Brute Shot")*/ _damage_reporting_type_brute_shot = 67ui8,
					/*nicename("Flamethrower")*/ _damage_reporting_type_flamethrower = 68ui8,
					/*nicename("Sentinel Gun")*/ _damage_reporting_type_sentinel_gun = 69ui8,
					/*nicename("Spike Grenade")*/ _damage_reporting_type_spike_grenade = 70ui8,
					/*nicename("Firebomb Grenade")*/ _damage_reporting_type_firebomb_grenade = 71ui8,
					/*nicename("Elephant Turret")*/ _damage_reporting_type_elephant_turret = 72ui8,
					/*nicename("Spectre")*/ _damage_reporting_type_spectre = 73ui8,
					/*nicename("Spectre Gunner")*/ _damage_reporting_type_spectre_gunner = 74ui8,
					/*nicename("Tank")*/ _damage_reporting_type_tank = 75ui8,
					/*nicename("Chopper")*/ _damage_reporting_type_chopper = 76ui8,
					/*nicename("Falcon")*/ _damage_reporting_type_falcon1 = 77ui8,
					/*nicename("Mantis")*/ _damage_reporting_type_mantis = 78ui8,
					/*nicename("Prowler")*/ _damage_reporting_type_prowler = 79ui8,
					/*nicename("Sentinel Beam")*/ _damage_reporting_type_sentinel_beam = 80ui8,
					/*nicename("Sentinel RPG")*/ _damage_reporting_type_sentinel_rpg = 81ui8,
					/*nicename("Tripmine")*/ _damage_reporting_type_tripmine = 82ui8,
				};

				e_damage_reporting_type nicename("Damage Reporting Type") damage_reporting_type;
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
			};

			struct nicename("Cause Unit") s_cause_unit_definition
			{
				enum nicename("Unit") e_unit : uint8_t
				{
					/*nicename("Any")*/ _unit_any = 1ui8,
					/*nicename("Brute")*/ _unit_brute = 2ui8,
					/*nicename("Grunt")*/ _unit_grunt = 3ui8,
					/*nicename("Jackal")*/ _unit_jackal = 4ui8,
					/*nicename("Skirmisher")*/ _unit_skirmisher = 5ui8,
					/*nicename("Marine")*/ _unit_marine = 6ui8,
					/*nicename("Spartan")*/ _unit_spartan = 7ui8,
					/*nicename("Bugger")*/ _unit_bugger = 8ui8,
					/*nicename("Hunter")*/ _unit_hunter = 9ui8,
					/*nicename("Flood Infection")*/ _unit_flood_infection = 10ui8,
					/*nicename("Flood Carrier")*/ _unit_flood_carrier = 11ui8,
					/*nicename("Flood Combat")*/ _unit_flood_combat = 12ui8,
					/*nicename("Flood Pureform")*/ _unit_flood_pureform = 13ui8,
					/*nicename("Sentinel")*/ _unit_sentinel = 14ui8,
					/*nicename("Elite")*/ _unit_elite = 15ui8,
					/*nicename("Engineer")*/ _unit_engineer = 16ui8,
					/*nicename("Mule")*/ _unit_mule = 17ui8,
					/*nicename("Turret")*/ _unit_turret = 18ui8,
					/*nicename("Mongoose")*/ _unit_mongoose = 19ui8,
					/*nicename("Warthog")*/ _unit_warthog = 20ui8,
					/*nicename("Scorpion")*/ _unit_scorpion = 21ui8,
					/*nicename("Falcon")*/ _unit_falcon = 22ui8,
					/*nicename("Pelican")*/ _unit_pelican = 23ui8,
					/*nicename("Revenant")*/ _unit_revenant = 24ui8,
					/*nicename("Seraph")*/ _unit_seraph = 25ui8,
					/*nicename("Shade")*/ _unit_shade = 26ui8,
					/*nicename("Watchtower")*/ _unit_watchtower = 27ui8,
					/*nicename("Ghost")*/ _unit_ghost = 28ui8,
					/*nicename("Space Banshee")*/ _unit_space_banshee = 29ui8,
					/*nicename("Mauler")*/ _unit_mauler = 30ui8,
					/*nicename("Wraith")*/ _unit_wraith = 31ui8,
					/*nicename("Banshee")*/ _unit_banshee = 32ui8,
					/*nicename("Phantom")*/ _unit_phantom = 33ui8,
					/*nicename("Scarab")*/ _unit_scarab = 34ui8,
					/*nicename("Guntower")*/ _unit_guntower = 35ui8,
					/*nicename("Tuning Fork")*/ _unit_tuning_fork = 36ui8,
				};

				enum nicename("Classification") e_classification : uint8_t
				{
					/*nicename("Any")*/ _classification_any = 1ui8,
					/*nicename("Infantry")*/ _classification_infantry = 2ui8,
					/*nicename("Leader")*/ _classification_leader = 3ui8,
					/*nicename("Hero")*/ _classification_hero = 4ui8,
					/*nicename("Specialist")*/ _classification_specialist = 5ui8,
					/*nicename("Light Vehicle")*/ _classification_light_vehicle = 6ui8,
					/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 7ui8,
					/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 8ui8,
					/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 9ui8,
				};

				enum nicename("Flags") b_flags : uint16_t /* bitfield */
				{
					/*nicename("Is Player")*/ _flags_is_player = 1ui16 << 0ui16,
					/*nicename("Is AI")*/ _flags_is_ai = 1ui16 << 1ui16,
					/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
					/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
					/*nicename("Is Sprinting")*/ _flags_is_sprinting = 1ui16 << 4ui16,
					/*nicename("Is Crouching")*/ _flags_is_crouching = 1ui16 << 5ui16,
					/*nicename("Is Reloading")*/ _flags_is_reloading = 1ui16 << 6ui16,
					/*nicename("Using Jetpack")*/ _flags_using_jetpack = 1ui16 << 7ui16,
					/*nicename("Is Not Assassinating")*/ _flags_is_not_assassinating = 1ui16 << 8ui16,
					/*nicename("Low Health")*/ _flags_low_health = 1ui16 << 9ui16,
					/*nicename("No Shields")*/ _flags_no_shields = 1ui16 << 10ui16,
					/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
					/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
					/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
					/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
					/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
				};

				b_flags nicename("Flags") flags;
				e_unit nicename("Unit") unit;
				e_classification nicename("Classification") classification;
				char nicename("Profile Name") profile_name[32];
			};

			struct nicename("Effect Unit") s_effect_unit_definition
			{
				enum nicename("Unit") e_unit : uint8_t
				{
					/*nicename("Any")*/ _unit_any = 1ui8,
					/*nicename("Brute")*/ _unit_brute = 2ui8,
					/*nicename("Grunt")*/ _unit_grunt = 3ui8,
					/*nicename("Jackal")*/ _unit_jackal = 4ui8,
					/*nicename("Skirmisher")*/ _unit_skirmisher = 5ui8,
					/*nicename("Marine")*/ _unit_marine = 6ui8,
					/*nicename("Spartan")*/ _unit_spartan = 7ui8,
					/*nicename("Bugger")*/ _unit_bugger = 8ui8,
					/*nicename("Hunter")*/ _unit_hunter = 9ui8,
					/*nicename("Flood Infection")*/ _unit_flood_infection = 10ui8,
					/*nicename("Flood Carrier")*/ _unit_flood_carrier = 11ui8,
					/*nicename("Flood Combat")*/ _unit_flood_combat = 12ui8,
					/*nicename("Flood Pureform")*/ _unit_flood_pureform = 13ui8,
					/*nicename("Sentinel")*/ _unit_sentinel = 14ui8,
					/*nicename("Elite")*/ _unit_elite = 15ui8,
					/*nicename("Engineer")*/ _unit_engineer = 16ui8,
					/*nicename("Mule")*/ _unit_mule = 17ui8,
					/*nicename("Turret")*/ _unit_turret = 18ui8,
					/*nicename("Mongoose")*/ _unit_mongoose = 19ui8,
					/*nicename("Warthog")*/ _unit_warthog = 20ui8,
					/*nicename("Scorpion")*/ _unit_scorpion = 21ui8,
					/*nicename("Falcon")*/ _unit_falcon = 22ui8,
					/*nicename("Pelican")*/ _unit_pelican = 23ui8,
					/*nicename("Revenant")*/ _unit_revenant = 24ui8,
					/*nicename("Seraph")*/ _unit_seraph = 25ui8,
					/*nicename("Shade")*/ _unit_shade = 26ui8,
					/*nicename("Watchtower")*/ _unit_watchtower = 27ui8,
					/*nicename("Ghost")*/ _unit_ghost = 28ui8,
					/*nicename("Space Banshee")*/ _unit_space_banshee = 29ui8,
					/*nicename("Mauler")*/ _unit_mauler = 30ui8,
					/*nicename("Wraith")*/ _unit_wraith = 31ui8,
					/*nicename("Banshee")*/ _unit_banshee = 32ui8,
					/*nicename("Phantom")*/ _unit_phantom = 33ui8,
					/*nicename("Scarab")*/ _unit_scarab = 34ui8,
					/*nicename("Guntower")*/ _unit_guntower = 35ui8,
					/*nicename("Tuning Fork")*/ _unit_tuning_fork = 36ui8,
				};

				enum nicename("Classification") e_classification : uint8_t
				{
					/*nicename("Any")*/ _classification_any = 1ui8,
					/*nicename("Infantry")*/ _classification_infantry = 2ui8,
					/*nicename("Leader")*/ _classification_leader = 3ui8,
					/*nicename("Hero")*/ _classification_hero = 4ui8,
					/*nicename("Specialist")*/ _classification_specialist = 5ui8,
					/*nicename("Light Vehicle")*/ _classification_light_vehicle = 6ui8,
					/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 7ui8,
					/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 8ui8,
					/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 9ui8,
				};

				enum nicename("Flags") b_flags : uint16_t /* bitfield */
				{
					/*nicename("Is Player")*/ _flags_is_player = 1ui16 << 0ui16,
					/*nicename("Is AI")*/ _flags_is_ai = 1ui16 << 1ui16,
					/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
					/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
					/*nicename("Is Sprinting")*/ _flags_is_sprinting = 1ui16 << 4ui16,
					/*nicename("Is Crouching")*/ _flags_is_crouching = 1ui16 << 5ui16,
					/*nicename("Is Reloading")*/ _flags_is_reloading = 1ui16 << 6ui16,
					/*nicename("Using Jetpack")*/ _flags_using_jetpack = 1ui16 << 7ui16,
					/*nicename("Is Not Assassinating")*/ _flags_is_not_assassinating = 1ui16 << 8ui16,
					/*nicename("Low Health")*/ _flags_low_health = 1ui16 << 9ui16,
					/*nicename("No Shields")*/ _flags_no_shields = 1ui16 << 10ui16,
					/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
					/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
					/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
					/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
					/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
				};

				b_flags nicename("Flags") flags;
				e_unit nicename("Unit") unit;
				e_classification nicename("Classification") classification;
				char nicename("Profile Name") profile_name[32];
			};

			struct nicename("Special Filters") s_special_filters_definition
			{
				enum nicename("Filter") e_filter : uint8_t
				{
					/*nicename("Headshot")*/ _filter_headshot = 1ui8,
					/*nicename("Stick")*/ _filter_stick = 2ui8,
					/*nicename("Backsmack")*/ _filter_backsmack = 3ui8,
					/*nicename("Assassination")*/ _filter_assassination = 4ui8,
					/*nicename("Supercombine")*/ _filter_supercombine = 5ui8,
					/*nicename("EMP")*/ _filter_emp = 6ui8,
					/*nicename("Melee")*/ _filter_melee = 7ui8,
					/*nicename("Splatter")*/ _filter_splatter = 8ui8,
				};

				e_filter nicename("Filter") filter;
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
			};

			string_id_legacy nicename("Parent Incident") parent_incident;
			s_undefined32_legacy __unknown0;
			s_tag_block_legacy<s_weapons_filter_definition> nicename("Weapons Filter") weapons_filter_block;
			s_tag_block_legacy<s_cause_unit_definition> nicename("Cause Unit") cause_unit_block;
			s_tag_block_legacy<s_effect_unit_definition> nicename("Effect Unit") effect_unit_block;
			s_tag_block_legacy<s_special_filters_definition> nicename("Special Filters") special_filters_block;
		};

		struct nicename("Cumulative Incident Triggers") s_cumulative_incident_triggers_definition
		{
			struct nicename("Trigger") s_trigger_definition
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int32_t nicename("Amount") amount;
				string_id_legacy nicename("Target Incident") target_incident;
			};

			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			s_tag_block_legacy<s_trigger_definition> nicename("Trigger") trigger_block;
		};

		struct nicename("Responses") s_responses_definition
		{
			enum nicename("Mode") b_mode : uint8_t /* bitfield */
			{
				/*nicename("Campaign")*/ _mode_campaign = 1ui8 << 0ui8,
				/*nicename("Firefight")*/ _mode_firefight = 1ui8 << 1ui8,
				/*nicename("Multiplayer")*/ _mode_multiplayer = 1ui8 << 2ui8,
			};

			enum nicename("Mode Type") b_mode_type : uint8_t /* bitfield */
			{
				/*nicename("Custom Game")*/ _mode_type_custom_game = 1ui8 << 0ui8,
				/*nicename("Matchmaking")*/ _mode_type_matchmaking = 1ui8 << 1ui8,
			};

			enum nicename("Difficulty") b_difficulty : uint8_t /* bitfield */
			{
				/*nicename("Easy")*/ _difficulty_easy = 1ui8 << 0ui8,
				/*nicename("Normal")*/ _difficulty_normal = 1ui8 << 1ui8,
				/*nicename("Heroic")*/ _difficulty_heroic = 1ui8 << 2ui8,
				/*nicename("Legendary")*/ _difficulty_legendary = 1ui8 << 3ui8,
			};

			struct nicename("Unknown") s_unknown1_definition
			{
				string_id_legacy __unknown0;
			};

			b_mode nicename("Mode") mode;
			b_mode_type nicename("Mode Type") mode_type;
			b_difficulty nicename("Difficulty") difficulty;
			int8_t __unknown0;
			s_undefined32_legacy __unknown1;
			string_id_legacy nicename("Event") event;
			string_id_legacy nicename("Medal") medal;
			string_id_legacy nicename("Commendation") commendation;
			string_id_legacy nicename("Achievement") achievement;
			string_id_legacy nicename("Avatar Award") avatar_award;
			s_tag_block_legacy<s_unknown1_definition> __unknown2;
			string_id_legacy nicename("Script") script;
			int16_t nicename("Script Index") script_index;
			int16_t __unknown3;
		};

		string_id_legacy nicename("Name") name;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		b_not_allowed_in_mode nicename("Not Allowed In Mode") not_allowed_in_mode;
		b_not_allowed_in_mode_type nicename("Not Allowed In Mode Type") not_allowed_in_mode_type;
		b_not_allowed_on_difficulty nicename("Not Allowed On Difficulty") not_allowed_on_difficulty;
		int8_t __unknown4;
		s_tag_block_legacy<s_unknown_definition> __unknown5;
		s_tag_block_legacy<s_case_triggers_definition> nicename("Case Triggers") case_triggers_block;
		s_tag_block_legacy<s_cumulative_incident_triggers_definition> nicename("Cumulative Incident Triggers") cumulative_incident_triggers_block;
		s_tag_block_legacy<s_responses_definition> nicename("Responses") responses_block;
	};

	s_undefined32_legacy __unknown0;
	s_tag_block_legacy<s_incidents_definition> nicename("Incidents") incidents_block;
};

