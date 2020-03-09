#pragma once

struct nicename("model") group('hlmt') s_model_definition
{
	enum nicename("Collision Damage Reporting Type") e_collision_damage_reporting_type : uint8_t
	{
		/*nicename("Guardians (Unknown)")*/ _collision_damage_reporting_type_guardians_unknown = 1ui8,
		/*nicename("Guardians")*/ _collision_damage_reporting_type_guardians = 2ui8,
		/*nicename("Guardians (Scripting)")*/ _collision_damage_reporting_type_guardians_scripting = 3ui8,
		/*nicename("Suicide")*/ _collision_damage_reporting_type_suicide = 4ui8,
		/*nicename("Magnum")*/ _collision_damage_reporting_type_magnum = 5ui8,
		/*nicename("Assault Rifle")*/ _collision_damage_reporting_type_assault_rifle = 6ui8,
		/*nicename("DMR")*/ _collision_damage_reporting_type_dmr = 7ui8,
		/*nicename("Shotgun")*/ _collision_damage_reporting_type_shotgun = 8ui8,
		/*nicename("Sniper Rifle")*/ _collision_damage_reporting_type_sniper_rifle = 9ui8,
		/*nicename("Rocket Launcher")*/ _collision_damage_reporting_type_rocket_launcher = 10ui8,
		/*nicename("Spartan Laser")*/ _collision_damage_reporting_type_spartan_laser = 11ui8,
		/*nicename("Frag Grenade")*/ _collision_damage_reporting_type_frag_grenade = 12ui8,
		/*nicename("Grenade Launcher")*/ _collision_damage_reporting_type_grenade_launcher = 13ui8,
		/*nicename("Plasma Pistol")*/ _collision_damage_reporting_type_plasma_pistol = 14ui8,
		/*nicename("Needler")*/ _collision_damage_reporting_type_needler = 15ui8,
		/*nicename("Plasma Rifle")*/ _collision_damage_reporting_type_plasma_rifle = 16ui8,
		/*nicename("Plasma Repeater")*/ _collision_damage_reporting_type_plasma_repeater = 17ui8,
		/*nicename("Needle Rifle")*/ _collision_damage_reporting_type_needle_rifle = 18ui8,
		/*nicename("Spiker")*/ _collision_damage_reporting_type_spiker = 19ui8,
		/*nicename("Plasma Launcher")*/ _collision_damage_reporting_type_plasma_launcher = 20ui8,
		/*nicename("Gravity Hammer")*/ _collision_damage_reporting_type_gravity_hammer = 21ui8,
		/*nicename("Energy Sword")*/ _collision_damage_reporting_type_energy_sword = 22ui8,
		/*nicename("Plasma Grenade")*/ _collision_damage_reporting_type_plasma_grenade = 23ui8,
		/*nicename("Concussion Rifle")*/ _collision_damage_reporting_type_concussion_rifle = 24ui8,
		/*nicename("Ghost")*/ _collision_damage_reporting_type_ghost = 25ui8,
		/*nicename("Revenant")*/ _collision_damage_reporting_type_revenant = 26ui8,
		/*nicename("Revenant Gunner")*/ _collision_damage_reporting_type_revenant_gunner = 27ui8,
		/*nicename("Wraith")*/ _collision_damage_reporting_type_wraith = 28ui8,
		/*nicename("Wraith Turret")*/ _collision_damage_reporting_type_wraith_turret = 29ui8,
		/*nicename("Banshee")*/ _collision_damage_reporting_type_banshee = 30ui8,
		/*nicename("Banshee Bomb")*/ _collision_damage_reporting_type_banshee_bomb = 31ui8,
		/*nicename("Seraph")*/ _collision_damage_reporting_type_seraph = 32ui8,
		/*nicename("Mongoose")*/ _collision_damage_reporting_type_mongoose = 33ui8,
		/*nicename("Warthog")*/ _collision_damage_reporting_type_warthog = 34ui8,
		/*nicename("Warthog Chaingun")*/ _collision_damage_reporting_type_warthog_chaingun = 35ui8,
		/*nicename("Warthog Gauss")*/ _collision_damage_reporting_type_warthog_gauss = 36ui8,
		/*nicename("Warthog Rocket")*/ _collision_damage_reporting_type_warthog_rocket = 37ui8,
		/*nicename("Scorpion")*/ _collision_damage_reporting_type_scorpion = 38ui8,
		/*nicename("Scorpion Turret")*/ _collision_damage_reporting_type_scorpion_turret = 39ui8,
		/*nicename("Falcon")*/ _collision_damage_reporting_type_falcon = 40ui8,
		/*nicename("Falcon Gunner")*/ _collision_damage_reporting_type_falcon_gunner = 41ui8,
		/*nicename("Falling")*/ _collision_damage_reporting_type_falling = 42ui8,
		/*nicename("Collision")*/ _collision_damage_reporting_type_collision = 43ui8,
		/*nicename("Melee")*/ _collision_damage_reporting_type_melee = 44ui8,
		/*nicename("Explosion")*/ _collision_damage_reporting_type_explosion = 45ui8,
		/*nicename("Birthday Explosion")*/ _collision_damage_reporting_type_birthday_explosion = 46ui8,
		/*nicename("Flag")*/ _collision_damage_reporting_type_flag = 47ui8,
		/*nicename("Bomb")*/ _collision_damage_reporting_type_bomb = 48ui8,
		/*nicename("Bomb Explosion")*/ _collision_damage_reporting_type_bomb_explosion = 49ui8,
		/*nicename("Ball")*/ _collision_damage_reporting_type_ball = 50ui8,
		/*nicename("Teleporter")*/ _collision_damage_reporting_type_teleporter = 51ui8,
		/*nicename("Transfer Damage")*/ _collision_damage_reporting_type_transfer_damage = 52ui8,
		/*nicename("Armor Lock")*/ _collision_damage_reporting_type_armor_lock = 53ui8,
		/*nicename("Target Locator")*/ _collision_damage_reporting_type_target_locator = 54ui8,
		/*nicename("Human Turret")*/ _collision_damage_reporting_type_human_turret = 55ui8,
		/*nicename("Plasma Cannon")*/ _collision_damage_reporting_type_plasma_cannon = 56ui8,
		/*nicename("Plasma Mortar")*/ _collision_damage_reporting_type_plasma_mortar = 57ui8,
		/*nicename("Plasma Turret")*/ _collision_damage_reporting_type_plasma_turret = 58ui8,
		/*nicename("Shade Turret")*/ _collision_damage_reporting_type_shade_turret = 59ui8,
		/*nicename("Sabre")*/ _collision_damage_reporting_type_sabre = 60ui8,
		/*nicename("SMG")*/ _collision_damage_reporting_type_smg = 61ui8,
		/*nicename("Carbine")*/ _collision_damage_reporting_type_carbine = 62ui8,
		/*nicename("Battle Rifle")*/ _collision_damage_reporting_type_battle_rifle = 63ui8,
		/*nicename("Focus Rifle")*/ _collision_damage_reporting_type_focus_rifle = 64ui8,
		/*nicename("Fuel Rod")*/ _collision_damage_reporting_type_fuel_rod = 65ui8,
		/*nicename("Missile Pod")*/ _collision_damage_reporting_type_missile_pod = 66ui8,
		/*nicename("Brute Shot")*/ _collision_damage_reporting_type_brute_shot = 67ui8,
		/*nicename("Flamethrower")*/ _collision_damage_reporting_type_flamethrower = 68ui8,
		/*nicename("Sentinel Gun")*/ _collision_damage_reporting_type_sentinel_gun = 69ui8,
		/*nicename("Spike Grenade")*/ _collision_damage_reporting_type_spike_grenade = 70ui8,
		/*nicename("Firebomb Grenade")*/ _collision_damage_reporting_type_firebomb_grenade = 71ui8,
		/*nicename("Elephant Turret")*/ _collision_damage_reporting_type_elephant_turret = 72ui8,
		/*nicename("Spectre")*/ _collision_damage_reporting_type_spectre = 73ui8,
		/*nicename("Spectre Gunner")*/ _collision_damage_reporting_type_spectre_gunner = 74ui8,
		/*nicename("Tank")*/ _collision_damage_reporting_type_tank = 75ui8,
		/*nicename("Chopper")*/ _collision_damage_reporting_type_chopper = 76ui8,
		/*nicename("Falcon")*/ _collision_damage_reporting_type_falcon1 = 77ui8,
		/*nicename("Mantis")*/ _collision_damage_reporting_type_mantis = 78ui8,
		/*nicename("Prowler")*/ _collision_damage_reporting_type_prowler = 79ui8,
		/*nicename("Sentinel Beam")*/ _collision_damage_reporting_type_sentinel_beam = 80ui8,
		/*nicename("Sentinel RPG")*/ _collision_damage_reporting_type_sentinel_rpg = 81ui8,
		/*nicename("Tripmine")*/ _collision_damage_reporting_type_tripmine = 82ui8,
	};

	enum nicename("Response Damage Reporting Type") e_response_damage_reporting_type : uint8_t
	{
		/*nicename("Guardians (Unknown)")*/ _response_damage_reporting_type_guardians_unknown = 1ui8,
		/*nicename("Guardians")*/ _response_damage_reporting_type_guardians = 2ui8,
		/*nicename("Guardians (Scripting)")*/ _response_damage_reporting_type_guardians_scripting = 3ui8,
		/*nicename("Suicide")*/ _response_damage_reporting_type_suicide = 4ui8,
		/*nicename("Magnum")*/ _response_damage_reporting_type_magnum = 5ui8,
		/*nicename("Assault Rifle")*/ _response_damage_reporting_type_assault_rifle = 6ui8,
		/*nicename("DMR")*/ _response_damage_reporting_type_dmr = 7ui8,
		/*nicename("Shotgun")*/ _response_damage_reporting_type_shotgun = 8ui8,
		/*nicename("Sniper Rifle")*/ _response_damage_reporting_type_sniper_rifle = 9ui8,
		/*nicename("Rocket Launcher")*/ _response_damage_reporting_type_rocket_launcher = 10ui8,
		/*nicename("Spartan Laser")*/ _response_damage_reporting_type_spartan_laser = 11ui8,
		/*nicename("Frag Grenade")*/ _response_damage_reporting_type_frag_grenade = 12ui8,
		/*nicename("Grenade Launcher")*/ _response_damage_reporting_type_grenade_launcher = 13ui8,
		/*nicename("Plasma Pistol")*/ _response_damage_reporting_type_plasma_pistol = 14ui8,
		/*nicename("Needler")*/ _response_damage_reporting_type_needler = 15ui8,
		/*nicename("Plasma Rifle")*/ _response_damage_reporting_type_plasma_rifle = 16ui8,
		/*nicename("Plasma Repeater")*/ _response_damage_reporting_type_plasma_repeater = 17ui8,
		/*nicename("Needle Rifle")*/ _response_damage_reporting_type_needle_rifle = 18ui8,
		/*nicename("Spiker")*/ _response_damage_reporting_type_spiker = 19ui8,
		/*nicename("Plasma Launcher")*/ _response_damage_reporting_type_plasma_launcher = 20ui8,
		/*nicename("Gravity Hammer")*/ _response_damage_reporting_type_gravity_hammer = 21ui8,
		/*nicename("Energy Sword")*/ _response_damage_reporting_type_energy_sword = 22ui8,
		/*nicename("Plasma Grenade")*/ _response_damage_reporting_type_plasma_grenade = 23ui8,
		/*nicename("Concussion Rifle")*/ _response_damage_reporting_type_concussion_rifle = 24ui8,
		/*nicename("Ghost")*/ _response_damage_reporting_type_ghost = 25ui8,
		/*nicename("Revenant")*/ _response_damage_reporting_type_revenant = 26ui8,
		/*nicename("Revenant Gunner")*/ _response_damage_reporting_type_revenant_gunner = 27ui8,
		/*nicename("Wraith")*/ _response_damage_reporting_type_wraith = 28ui8,
		/*nicename("Wraith Turret")*/ _response_damage_reporting_type_wraith_turret = 29ui8,
		/*nicename("Banshee")*/ _response_damage_reporting_type_banshee = 30ui8,
		/*nicename("Banshee Bomb")*/ _response_damage_reporting_type_banshee_bomb = 31ui8,
		/*nicename("Seraph")*/ _response_damage_reporting_type_seraph = 32ui8,
		/*nicename("Mongoose")*/ _response_damage_reporting_type_mongoose = 33ui8,
		/*nicename("Warthog")*/ _response_damage_reporting_type_warthog = 34ui8,
		/*nicename("Warthog Chaingun")*/ _response_damage_reporting_type_warthog_chaingun = 35ui8,
		/*nicename("Warthog Gauss")*/ _response_damage_reporting_type_warthog_gauss = 36ui8,
		/*nicename("Warthog Rocket")*/ _response_damage_reporting_type_warthog_rocket = 37ui8,
		/*nicename("Scorpion")*/ _response_damage_reporting_type_scorpion = 38ui8,
		/*nicename("Scorpion Turret")*/ _response_damage_reporting_type_scorpion_turret = 39ui8,
		/*nicename("Falcon")*/ _response_damage_reporting_type_falcon = 40ui8,
		/*nicename("Falcon Gunner")*/ _response_damage_reporting_type_falcon_gunner = 41ui8,
		/*nicename("Falling")*/ _response_damage_reporting_type_falling = 42ui8,
		/*nicename("Collision")*/ _response_damage_reporting_type_collision = 43ui8,
		/*nicename("Melee")*/ _response_damage_reporting_type_melee = 44ui8,
		/*nicename("Explosion")*/ _response_damage_reporting_type_explosion = 45ui8,
		/*nicename("Birthday Explosion")*/ _response_damage_reporting_type_birthday_explosion = 46ui8,
		/*nicename("Flag")*/ _response_damage_reporting_type_flag = 47ui8,
		/*nicename("Bomb")*/ _response_damage_reporting_type_bomb = 48ui8,
		/*nicename("Bomb Explosion")*/ _response_damage_reporting_type_bomb_explosion = 49ui8,
		/*nicename("Ball")*/ _response_damage_reporting_type_ball = 50ui8,
		/*nicename("Teleporter")*/ _response_damage_reporting_type_teleporter = 51ui8,
		/*nicename("Transfer Damage")*/ _response_damage_reporting_type_transfer_damage = 52ui8,
		/*nicename("Armor Lock")*/ _response_damage_reporting_type_armor_lock = 53ui8,
		/*nicename("Target Locator")*/ _response_damage_reporting_type_target_locator = 54ui8,
		/*nicename("Human Turret")*/ _response_damage_reporting_type_human_turret = 55ui8,
		/*nicename("Plasma Cannon")*/ _response_damage_reporting_type_plasma_cannon = 56ui8,
		/*nicename("Plasma Mortar")*/ _response_damage_reporting_type_plasma_mortar = 57ui8,
		/*nicename("Plasma Turret")*/ _response_damage_reporting_type_plasma_turret = 58ui8,
		/*nicename("Shade Turret")*/ _response_damage_reporting_type_shade_turret = 59ui8,
		/*nicename("Sabre")*/ _response_damage_reporting_type_sabre = 60ui8,
		/*nicename("SMG")*/ _response_damage_reporting_type_smg = 61ui8,
		/*nicename("Carbine")*/ _response_damage_reporting_type_carbine = 62ui8,
		/*nicename("Battle Rifle")*/ _response_damage_reporting_type_battle_rifle = 63ui8,
		/*nicename("Focus Rifle")*/ _response_damage_reporting_type_focus_rifle = 64ui8,
		/*nicename("Fuel Rod")*/ _response_damage_reporting_type_fuel_rod = 65ui8,
		/*nicename("Missile Pod")*/ _response_damage_reporting_type_missile_pod = 66ui8,
		/*nicename("Brute Shot")*/ _response_damage_reporting_type_brute_shot = 67ui8,
		/*nicename("Flamethrower")*/ _response_damage_reporting_type_flamethrower = 68ui8,
		/*nicename("Sentinel Gun")*/ _response_damage_reporting_type_sentinel_gun = 69ui8,
		/*nicename("Spike Grenade")*/ _response_damage_reporting_type_spike_grenade = 70ui8,
		/*nicename("Firebomb Grenade")*/ _response_damage_reporting_type_firebomb_grenade = 71ui8,
		/*nicename("Elephant Turret")*/ _response_damage_reporting_type_elephant_turret = 72ui8,
		/*nicename("Spectre")*/ _response_damage_reporting_type_spectre = 73ui8,
		/*nicename("Spectre Gunner")*/ _response_damage_reporting_type_spectre_gunner = 74ui8,
		/*nicename("Tank")*/ _response_damage_reporting_type_tank = 75ui8,
		/*nicename("Chopper")*/ _response_damage_reporting_type_chopper = 76ui8,
		/*nicename("Falcon")*/ _response_damage_reporting_type_falcon1 = 77ui8,
		/*nicename("Mantis")*/ _response_damage_reporting_type_mantis = 78ui8,
		/*nicename("Prowler")*/ _response_damage_reporting_type_prowler = 79ui8,
		/*nicename("Sentinel Beam")*/ _response_damage_reporting_type_sentinel_beam = 80ui8,
		/*nicename("Sentinel RPG")*/ _response_damage_reporting_type_sentinel_rpg = 81ui8,
		/*nicename("Tripmine")*/ _response_damage_reporting_type_tripmine = 82ui8,
	};

	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Takes Damage For Children")*/ _flags_takes_damage_for_children = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
		/*nicename("Cannot Die From Damage")*/ _flags_cannot_die_from_damage = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
	{
		/*nicename("Active Camo Always On")*/ _flags1_active_camo_always_on = 1ui32 << 0ui32,
		/*nicename("Active Camo Always Merge")*/ _flags1_active_camo_always_merge = 1ui32 << 1ui32,
		/*nicename("Active Camo Never Merge")*/ _flags1_active_camo_never_merge = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 1") b_render_only_node_flags_1 : uint32_t /* bitfield */
	{
		/*nicename("Node 0")*/ _render_only_node_flags_1_node_0 = 1ui32 << 0ui32,
		/*nicename("Node 1")*/ _render_only_node_flags_1_node_1 = 1ui32 << 1ui32,
		/*nicename("Node 2")*/ _render_only_node_flags_1_node_2 = 1ui32 << 2ui32,
		/*nicename("Node 3")*/ _render_only_node_flags_1_node_3 = 1ui32 << 3ui32,
		/*nicename("Node 4")*/ _render_only_node_flags_1_node_4 = 1ui32 << 4ui32,
		/*nicename("Node 5")*/ _render_only_node_flags_1_node_5 = 1ui32 << 5ui32,
		/*nicename("Node 6")*/ _render_only_node_flags_1_node_6 = 1ui32 << 6ui32,
		/*nicename("Node 7")*/ _render_only_node_flags_1_node_7 = 1ui32 << 7ui32,
		/*nicename("Node 8")*/ _render_only_node_flags_1_node_8 = 1ui32 << 8ui32,
		/*nicename("Node 9")*/ _render_only_node_flags_1_node_9 = 1ui32 << 9ui32,
		/*nicename("Node 10")*/ _render_only_node_flags_1_node_10 = 1ui32 << 10ui32,
		/*nicename("Node 11")*/ _render_only_node_flags_1_node_11 = 1ui32 << 11ui32,
		/*nicename("Node 12")*/ _render_only_node_flags_1_node_12 = 1ui32 << 12ui32,
		/*nicename("Node 13")*/ _render_only_node_flags_1_node_13 = 1ui32 << 13ui32,
		/*nicename("Node 14")*/ _render_only_node_flags_1_node_14 = 1ui32 << 14ui32,
		/*nicename("Node 15")*/ _render_only_node_flags_1_node_15 = 1ui32 << 15ui32,
		/*nicename("Node 16")*/ _render_only_node_flags_1_node_16 = 1ui32 << 16ui32,
		/*nicename("Node 17")*/ _render_only_node_flags_1_node_17 = 1ui32 << 17ui32,
		/*nicename("Node 18")*/ _render_only_node_flags_1_node_18 = 1ui32 << 18ui32,
		/*nicename("Node 19")*/ _render_only_node_flags_1_node_19 = 1ui32 << 19ui32,
		/*nicename("Node 20")*/ _render_only_node_flags_1_node_20 = 1ui32 << 20ui32,
		/*nicename("Node 21")*/ _render_only_node_flags_1_node_21 = 1ui32 << 21ui32,
		/*nicename("Node 22")*/ _render_only_node_flags_1_node_22 = 1ui32 << 22ui32,
		/*nicename("Node 23")*/ _render_only_node_flags_1_node_23 = 1ui32 << 23ui32,
		/*nicename("Node 24")*/ _render_only_node_flags_1_node_24 = 1ui32 << 24ui32,
		/*nicename("Node 25")*/ _render_only_node_flags_1_node_25 = 1ui32 << 25ui32,
		/*nicename("Node 26")*/ _render_only_node_flags_1_node_26 = 1ui32 << 26ui32,
		/*nicename("Node 27")*/ _render_only_node_flags_1_node_27 = 1ui32 << 27ui32,
		/*nicename("Node 28")*/ _render_only_node_flags_1_node_28 = 1ui32 << 28ui32,
		/*nicename("Node 29")*/ _render_only_node_flags_1_node_29 = 1ui32 << 29ui32,
		/*nicename("Node 30")*/ _render_only_node_flags_1_node_30 = 1ui32 << 30ui32,
		/*nicename("Node 31")*/ _render_only_node_flags_1_node_31 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 2") b_render_only_node_flags_2 : uint32_t /* bitfield */
	{
		/*nicename("Node 32")*/ _render_only_node_flags_2_node_32 = 1ui32 << 0ui32,
		/*nicename("Node 33")*/ _render_only_node_flags_2_node_33 = 1ui32 << 1ui32,
		/*nicename("Node 34")*/ _render_only_node_flags_2_node_34 = 1ui32 << 2ui32,
		/*nicename("Node 35")*/ _render_only_node_flags_2_node_35 = 1ui32 << 3ui32,
		/*nicename("Node 36")*/ _render_only_node_flags_2_node_36 = 1ui32 << 4ui32,
		/*nicename("Node 37")*/ _render_only_node_flags_2_node_37 = 1ui32 << 5ui32,
		/*nicename("Node 38")*/ _render_only_node_flags_2_node_38 = 1ui32 << 6ui32,
		/*nicename("Node 39")*/ _render_only_node_flags_2_node_39 = 1ui32 << 7ui32,
		/*nicename("Node 40")*/ _render_only_node_flags_2_node_40 = 1ui32 << 8ui32,
		/*nicename("Node 41")*/ _render_only_node_flags_2_node_41 = 1ui32 << 9ui32,
		/*nicename("Node 42")*/ _render_only_node_flags_2_node_42 = 1ui32 << 10ui32,
		/*nicename("Node 43")*/ _render_only_node_flags_2_node_43 = 1ui32 << 11ui32,
		/*nicename("Node 44")*/ _render_only_node_flags_2_node_44 = 1ui32 << 12ui32,
		/*nicename("Node 45")*/ _render_only_node_flags_2_node_45 = 1ui32 << 13ui32,
		/*nicename("Node 46")*/ _render_only_node_flags_2_node_46 = 1ui32 << 14ui32,
		/*nicename("Node 47")*/ _render_only_node_flags_2_node_47 = 1ui32 << 15ui32,
		/*nicename("Node 48")*/ _render_only_node_flags_2_node_48 = 1ui32 << 16ui32,
		/*nicename("Node 49")*/ _render_only_node_flags_2_node_49 = 1ui32 << 17ui32,
		/*nicename("Node 50")*/ _render_only_node_flags_2_node_50 = 1ui32 << 18ui32,
		/*nicename("Node 51")*/ _render_only_node_flags_2_node_51 = 1ui32 << 19ui32,
		/*nicename("Node 52")*/ _render_only_node_flags_2_node_52 = 1ui32 << 20ui32,
		/*nicename("Node 53")*/ _render_only_node_flags_2_node_53 = 1ui32 << 21ui32,
		/*nicename("Node 54")*/ _render_only_node_flags_2_node_54 = 1ui32 << 22ui32,
		/*nicename("Node 55")*/ _render_only_node_flags_2_node_55 = 1ui32 << 23ui32,
		/*nicename("Node 56")*/ _render_only_node_flags_2_node_56 = 1ui32 << 24ui32,
		/*nicename("Node 57")*/ _render_only_node_flags_2_node_57 = 1ui32 << 25ui32,
		/*nicename("Node 58")*/ _render_only_node_flags_2_node_58 = 1ui32 << 26ui32,
		/*nicename("Node 59")*/ _render_only_node_flags_2_node_59 = 1ui32 << 27ui32,
		/*nicename("Node 60")*/ _render_only_node_flags_2_node_60 = 1ui32 << 28ui32,
		/*nicename("Node 61")*/ _render_only_node_flags_2_node_61 = 1ui32 << 29ui32,
		/*nicename("Node 62")*/ _render_only_node_flags_2_node_62 = 1ui32 << 30ui32,
		/*nicename("Node 63")*/ _render_only_node_flags_2_node_63 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 3") b_render_only_node_flags_3 : uint32_t /* bitfield */
	{
		/*nicename("Node 64")*/ _render_only_node_flags_3_node_64 = 1ui32 << 0ui32,
		/*nicename("Node 65")*/ _render_only_node_flags_3_node_65 = 1ui32 << 1ui32,
		/*nicename("Node 66")*/ _render_only_node_flags_3_node_66 = 1ui32 << 2ui32,
		/*nicename("Node 67")*/ _render_only_node_flags_3_node_67 = 1ui32 << 3ui32,
		/*nicename("Node 68")*/ _render_only_node_flags_3_node_68 = 1ui32 << 4ui32,
		/*nicename("Node 69")*/ _render_only_node_flags_3_node_69 = 1ui32 << 5ui32,
		/*nicename("Node 70")*/ _render_only_node_flags_3_node_70 = 1ui32 << 6ui32,
		/*nicename("Node 71")*/ _render_only_node_flags_3_node_71 = 1ui32 << 7ui32,
		/*nicename("Node 72")*/ _render_only_node_flags_3_node_72 = 1ui32 << 8ui32,
		/*nicename("Node 73")*/ _render_only_node_flags_3_node_73 = 1ui32 << 9ui32,
		/*nicename("Node 74")*/ _render_only_node_flags_3_node_74 = 1ui32 << 10ui32,
		/*nicename("Node 75")*/ _render_only_node_flags_3_node_75 = 1ui32 << 11ui32,
		/*nicename("Node 76")*/ _render_only_node_flags_3_node_76 = 1ui32 << 12ui32,
		/*nicename("Node 77")*/ _render_only_node_flags_3_node_77 = 1ui32 << 13ui32,
		/*nicename("Node 78")*/ _render_only_node_flags_3_node_78 = 1ui32 << 14ui32,
		/*nicename("Node 79")*/ _render_only_node_flags_3_node_79 = 1ui32 << 15ui32,
		/*nicename("Node 80")*/ _render_only_node_flags_3_node_80 = 1ui32 << 16ui32,
		/*nicename("Node 81")*/ _render_only_node_flags_3_node_81 = 1ui32 << 17ui32,
		/*nicename("Node 82")*/ _render_only_node_flags_3_node_82 = 1ui32 << 18ui32,
		/*nicename("Node 83")*/ _render_only_node_flags_3_node_83 = 1ui32 << 19ui32,
		/*nicename("Node 84")*/ _render_only_node_flags_3_node_84 = 1ui32 << 20ui32,
		/*nicename("Node 85")*/ _render_only_node_flags_3_node_85 = 1ui32 << 21ui32,
		/*nicename("Node 86")*/ _render_only_node_flags_3_node_86 = 1ui32 << 22ui32,
		/*nicename("Node 87")*/ _render_only_node_flags_3_node_87 = 1ui32 << 23ui32,
		/*nicename("Node 88")*/ _render_only_node_flags_3_node_88 = 1ui32 << 24ui32,
		/*nicename("Node 89")*/ _render_only_node_flags_3_node_89 = 1ui32 << 25ui32,
		/*nicename("Node 90")*/ _render_only_node_flags_3_node_90 = 1ui32 << 26ui32,
		/*nicename("Node 91")*/ _render_only_node_flags_3_node_91 = 1ui32 << 27ui32,
		/*nicename("Node 92")*/ _render_only_node_flags_3_node_92 = 1ui32 << 28ui32,
		/*nicename("Node 93")*/ _render_only_node_flags_3_node_93 = 1ui32 << 29ui32,
		/*nicename("Node 94")*/ _render_only_node_flags_3_node_94 = 1ui32 << 30ui32,
		/*nicename("Node 95")*/ _render_only_node_flags_3_node_95 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 4") b_render_only_node_flags_4 : uint32_t /* bitfield */
	{
		/*nicename("Node 96")*/ _render_only_node_flags_4_node_96 = 1ui32 << 0ui32,
		/*nicename("Node 97")*/ _render_only_node_flags_4_node_97 = 1ui32 << 1ui32,
		/*nicename("Node 98")*/ _render_only_node_flags_4_node_98 = 1ui32 << 2ui32,
		/*nicename("Node 99")*/ _render_only_node_flags_4_node_99 = 1ui32 << 3ui32,
		/*nicename("Node 100")*/ _render_only_node_flags_4_node_100 = 1ui32 << 4ui32,
		/*nicename("Node 101")*/ _render_only_node_flags_4_node_101 = 1ui32 << 5ui32,
		/*nicename("Node 102")*/ _render_only_node_flags_4_node_102 = 1ui32 << 6ui32,
		/*nicename("Node 103")*/ _render_only_node_flags_4_node_103 = 1ui32 << 7ui32,
		/*nicename("Node 104")*/ _render_only_node_flags_4_node_104 = 1ui32 << 8ui32,
		/*nicename("Node 105")*/ _render_only_node_flags_4_node_105 = 1ui32 << 9ui32,
		/*nicename("Node 106")*/ _render_only_node_flags_4_node_106 = 1ui32 << 10ui32,
		/*nicename("Node 107")*/ _render_only_node_flags_4_node_107 = 1ui32 << 11ui32,
		/*nicename("Node 108")*/ _render_only_node_flags_4_node_108 = 1ui32 << 12ui32,
		/*nicename("Node 109")*/ _render_only_node_flags_4_node_109 = 1ui32 << 13ui32,
		/*nicename("Node 110")*/ _render_only_node_flags_4_node_110 = 1ui32 << 14ui32,
		/*nicename("Node 111")*/ _render_only_node_flags_4_node_111 = 1ui32 << 15ui32,
		/*nicename("Node 112")*/ _render_only_node_flags_4_node_112 = 1ui32 << 16ui32,
		/*nicename("Node 113")*/ _render_only_node_flags_4_node_113 = 1ui32 << 17ui32,
		/*nicename("Node 114")*/ _render_only_node_flags_4_node_114 = 1ui32 << 18ui32,
		/*nicename("Node 115")*/ _render_only_node_flags_4_node_115 = 1ui32 << 19ui32,
		/*nicename("Node 116")*/ _render_only_node_flags_4_node_116 = 1ui32 << 20ui32,
		/*nicename("Node 117")*/ _render_only_node_flags_4_node_117 = 1ui32 << 21ui32,
		/*nicename("Node 118")*/ _render_only_node_flags_4_node_118 = 1ui32 << 22ui32,
		/*nicename("Node 119")*/ _render_only_node_flags_4_node_119 = 1ui32 << 23ui32,
		/*nicename("Node 120")*/ _render_only_node_flags_4_node_120 = 1ui32 << 24ui32,
		/*nicename("Node 121")*/ _render_only_node_flags_4_node_121 = 1ui32 << 25ui32,
		/*nicename("Node 122")*/ _render_only_node_flags_4_node_122 = 1ui32 << 26ui32,
		/*nicename("Node 123")*/ _render_only_node_flags_4_node_123 = 1ui32 << 27ui32,
		/*nicename("Node 124")*/ _render_only_node_flags_4_node_124 = 1ui32 << 28ui32,
		/*nicename("Node 125")*/ _render_only_node_flags_4_node_125 = 1ui32 << 29ui32,
		/*nicename("Node 126")*/ _render_only_node_flags_4_node_126 = 1ui32 << 30ui32,
		/*nicename("Node 127")*/ _render_only_node_flags_4_node_127 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 5") b_render_only_node_flags_5 : uint32_t /* bitfield */
	{
		/*nicename("Node 128")*/ _render_only_node_flags_5_node_128 = 1ui32 << 0ui32,
		/*nicename("Node 129")*/ _render_only_node_flags_5_node_129 = 1ui32 << 1ui32,
		/*nicename("Node 130")*/ _render_only_node_flags_5_node_130 = 1ui32 << 2ui32,
		/*nicename("Node 131")*/ _render_only_node_flags_5_node_131 = 1ui32 << 3ui32,
		/*nicename("Node 132")*/ _render_only_node_flags_5_node_132 = 1ui32 << 4ui32,
		/*nicename("Node 133")*/ _render_only_node_flags_5_node_133 = 1ui32 << 5ui32,
		/*nicename("Node 134")*/ _render_only_node_flags_5_node_134 = 1ui32 << 6ui32,
		/*nicename("Node 135")*/ _render_only_node_flags_5_node_135 = 1ui32 << 7ui32,
		/*nicename("Node 136")*/ _render_only_node_flags_5_node_136 = 1ui32 << 8ui32,
		/*nicename("Node 137")*/ _render_only_node_flags_5_node_137 = 1ui32 << 9ui32,
		/*nicename("Node 138")*/ _render_only_node_flags_5_node_138 = 1ui32 << 10ui32,
		/*nicename("Node 139")*/ _render_only_node_flags_5_node_139 = 1ui32 << 11ui32,
		/*nicename("Node 140")*/ _render_only_node_flags_5_node_140 = 1ui32 << 12ui32,
		/*nicename("Node 141")*/ _render_only_node_flags_5_node_141 = 1ui32 << 13ui32,
		/*nicename("Node 142")*/ _render_only_node_flags_5_node_142 = 1ui32 << 14ui32,
		/*nicename("Node 143")*/ _render_only_node_flags_5_node_143 = 1ui32 << 15ui32,
		/*nicename("Node 144")*/ _render_only_node_flags_5_node_144 = 1ui32 << 16ui32,
		/*nicename("Node 145")*/ _render_only_node_flags_5_node_145 = 1ui32 << 17ui32,
		/*nicename("Node 146")*/ _render_only_node_flags_5_node_146 = 1ui32 << 18ui32,
		/*nicename("Node 147")*/ _render_only_node_flags_5_node_147 = 1ui32 << 19ui32,
		/*nicename("Node 148")*/ _render_only_node_flags_5_node_148 = 1ui32 << 20ui32,
		/*nicename("Node 149")*/ _render_only_node_flags_5_node_149 = 1ui32 << 21ui32,
		/*nicename("Node 150")*/ _render_only_node_flags_5_node_150 = 1ui32 << 22ui32,
		/*nicename("Node 151")*/ _render_only_node_flags_5_node_151 = 1ui32 << 23ui32,
		/*nicename("Node 152")*/ _render_only_node_flags_5_node_152 = 1ui32 << 24ui32,
		/*nicename("Node 153")*/ _render_only_node_flags_5_node_153 = 1ui32 << 25ui32,
		/*nicename("Node 154")*/ _render_only_node_flags_5_node_154 = 1ui32 << 26ui32,
		/*nicename("Node 155")*/ _render_only_node_flags_5_node_155 = 1ui32 << 27ui32,
		/*nicename("Node 156")*/ _render_only_node_flags_5_node_156 = 1ui32 << 28ui32,
		/*nicename("Node 157")*/ _render_only_node_flags_5_node_157 = 1ui32 << 29ui32,
		/*nicename("Node 158")*/ _render_only_node_flags_5_node_158 = 1ui32 << 30ui32,
		/*nicename("Node 159")*/ _render_only_node_flags_5_node_159 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 6") b_render_only_node_flags_6 : uint32_t /* bitfield */
	{
		/*nicename("Node 160")*/ _render_only_node_flags_6_node_160 = 1ui32 << 0ui32,
		/*nicename("Node 161")*/ _render_only_node_flags_6_node_161 = 1ui32 << 1ui32,
		/*nicename("Node 162")*/ _render_only_node_flags_6_node_162 = 1ui32 << 2ui32,
		/*nicename("Node 163")*/ _render_only_node_flags_6_node_163 = 1ui32 << 3ui32,
		/*nicename("Node 164")*/ _render_only_node_flags_6_node_164 = 1ui32 << 4ui32,
		/*nicename("Node 165")*/ _render_only_node_flags_6_node_165 = 1ui32 << 5ui32,
		/*nicename("Node 166")*/ _render_only_node_flags_6_node_166 = 1ui32 << 6ui32,
		/*nicename("Node 167")*/ _render_only_node_flags_6_node_167 = 1ui32 << 7ui32,
		/*nicename("Node 168")*/ _render_only_node_flags_6_node_168 = 1ui32 << 8ui32,
		/*nicename("Node 169")*/ _render_only_node_flags_6_node_169 = 1ui32 << 9ui32,
		/*nicename("Node 170")*/ _render_only_node_flags_6_node_170 = 1ui32 << 10ui32,
		/*nicename("Node 171")*/ _render_only_node_flags_6_node_171 = 1ui32 << 11ui32,
		/*nicename("Node 172")*/ _render_only_node_flags_6_node_172 = 1ui32 << 12ui32,
		/*nicename("Node 173")*/ _render_only_node_flags_6_node_173 = 1ui32 << 13ui32,
		/*nicename("Node 174")*/ _render_only_node_flags_6_node_174 = 1ui32 << 14ui32,
		/*nicename("Node 175")*/ _render_only_node_flags_6_node_175 = 1ui32 << 15ui32,
		/*nicename("Node 176")*/ _render_only_node_flags_6_node_176 = 1ui32 << 16ui32,
		/*nicename("Node 177")*/ _render_only_node_flags_6_node_177 = 1ui32 << 17ui32,
		/*nicename("Node 178")*/ _render_only_node_flags_6_node_178 = 1ui32 << 18ui32,
		/*nicename("Node 179")*/ _render_only_node_flags_6_node_179 = 1ui32 << 19ui32,
		/*nicename("Node 180")*/ _render_only_node_flags_6_node_180 = 1ui32 << 20ui32,
		/*nicename("Node 181")*/ _render_only_node_flags_6_node_181 = 1ui32 << 21ui32,
		/*nicename("Node 182")*/ _render_only_node_flags_6_node_182 = 1ui32 << 22ui32,
		/*nicename("Node 183")*/ _render_only_node_flags_6_node_183 = 1ui32 << 23ui32,
		/*nicename("Node 184")*/ _render_only_node_flags_6_node_184 = 1ui32 << 24ui32,
		/*nicename("Node 185")*/ _render_only_node_flags_6_node_185 = 1ui32 << 25ui32,
		/*nicename("Node 186")*/ _render_only_node_flags_6_node_186 = 1ui32 << 26ui32,
		/*nicename("Node 187")*/ _render_only_node_flags_6_node_187 = 1ui32 << 27ui32,
		/*nicename("Node 188")*/ _render_only_node_flags_6_node_188 = 1ui32 << 28ui32,
		/*nicename("Node 189")*/ _render_only_node_flags_6_node_189 = 1ui32 << 29ui32,
		/*nicename("Node 190")*/ _render_only_node_flags_6_node_190 = 1ui32 << 30ui32,
		/*nicename("Node 191")*/ _render_only_node_flags_6_node_191 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 7") b_render_only_node_flags_7 : uint32_t /* bitfield */
	{
		/*nicename("Node 192")*/ _render_only_node_flags_7_node_192 = 1ui32 << 0ui32,
		/*nicename("Node 193")*/ _render_only_node_flags_7_node_193 = 1ui32 << 1ui32,
		/*nicename("Node 194")*/ _render_only_node_flags_7_node_194 = 1ui32 << 2ui32,
		/*nicename("Node 195")*/ _render_only_node_flags_7_node_195 = 1ui32 << 3ui32,
		/*nicename("Node 196")*/ _render_only_node_flags_7_node_196 = 1ui32 << 4ui32,
		/*nicename("Node 197")*/ _render_only_node_flags_7_node_197 = 1ui32 << 5ui32,
		/*nicename("Node 198")*/ _render_only_node_flags_7_node_198 = 1ui32 << 6ui32,
		/*nicename("Node 199")*/ _render_only_node_flags_7_node_199 = 1ui32 << 7ui32,
		/*nicename("Node 200")*/ _render_only_node_flags_7_node_200 = 1ui32 << 8ui32,
		/*nicename("Node 201")*/ _render_only_node_flags_7_node_201 = 1ui32 << 9ui32,
		/*nicename("Node 202")*/ _render_only_node_flags_7_node_202 = 1ui32 << 10ui32,
		/*nicename("Node 203")*/ _render_only_node_flags_7_node_203 = 1ui32 << 11ui32,
		/*nicename("Node 204")*/ _render_only_node_flags_7_node_204 = 1ui32 << 12ui32,
		/*nicename("Node 205")*/ _render_only_node_flags_7_node_205 = 1ui32 << 13ui32,
		/*nicename("Node 206")*/ _render_only_node_flags_7_node_206 = 1ui32 << 14ui32,
		/*nicename("Node 207")*/ _render_only_node_flags_7_node_207 = 1ui32 << 15ui32,
		/*nicename("Node 208")*/ _render_only_node_flags_7_node_208 = 1ui32 << 16ui32,
		/*nicename("Node 209")*/ _render_only_node_flags_7_node_209 = 1ui32 << 17ui32,
		/*nicename("Node 210")*/ _render_only_node_flags_7_node_210 = 1ui32 << 18ui32,
		/*nicename("Node 211")*/ _render_only_node_flags_7_node_211 = 1ui32 << 19ui32,
		/*nicename("Node 212")*/ _render_only_node_flags_7_node_212 = 1ui32 << 20ui32,
		/*nicename("Node 213")*/ _render_only_node_flags_7_node_213 = 1ui32 << 21ui32,
		/*nicename("Node 214")*/ _render_only_node_flags_7_node_214 = 1ui32 << 22ui32,
		/*nicename("Node 215")*/ _render_only_node_flags_7_node_215 = 1ui32 << 23ui32,
		/*nicename("Node 216")*/ _render_only_node_flags_7_node_216 = 1ui32 << 24ui32,
		/*nicename("Node 217")*/ _render_only_node_flags_7_node_217 = 1ui32 << 25ui32,
		/*nicename("Node 218")*/ _render_only_node_flags_7_node_218 = 1ui32 << 26ui32,
		/*nicename("Node 219")*/ _render_only_node_flags_7_node_219 = 1ui32 << 27ui32,
		/*nicename("Node 220")*/ _render_only_node_flags_7_node_220 = 1ui32 << 28ui32,
		/*nicename("Node 221")*/ _render_only_node_flags_7_node_221 = 1ui32 << 29ui32,
		/*nicename("Node 222")*/ _render_only_node_flags_7_node_222 = 1ui32 << 30ui32,
		/*nicename("Node 223")*/ _render_only_node_flags_7_node_223 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Node Flags 8") b_render_only_node_flags_8 : uint32_t /* bitfield */
	{
		/*nicename("Node 224")*/ _render_only_node_flags_8_node_224 = 1ui32 << 0ui32,
		/*nicename("Node 225")*/ _render_only_node_flags_8_node_225 = 1ui32 << 1ui32,
		/*nicename("Node 226")*/ _render_only_node_flags_8_node_226 = 1ui32 << 2ui32,
		/*nicename("Node 227")*/ _render_only_node_flags_8_node_227 = 1ui32 << 3ui32,
		/*nicename("Node 228")*/ _render_only_node_flags_8_node_228 = 1ui32 << 4ui32,
		/*nicename("Node 229")*/ _render_only_node_flags_8_node_229 = 1ui32 << 5ui32,
		/*nicename("Node 230")*/ _render_only_node_flags_8_node_230 = 1ui32 << 6ui32,
		/*nicename("Node 231")*/ _render_only_node_flags_8_node_231 = 1ui32 << 7ui32,
		/*nicename("Node 232")*/ _render_only_node_flags_8_node_232 = 1ui32 << 8ui32,
		/*nicename("Node 233")*/ _render_only_node_flags_8_node_233 = 1ui32 << 9ui32,
		/*nicename("Node 234")*/ _render_only_node_flags_8_node_234 = 1ui32 << 10ui32,
		/*nicename("Node 235")*/ _render_only_node_flags_8_node_235 = 1ui32 << 11ui32,
		/*nicename("Node 236")*/ _render_only_node_flags_8_node_236 = 1ui32 << 12ui32,
		/*nicename("Node 237")*/ _render_only_node_flags_8_node_237 = 1ui32 << 13ui32,
		/*nicename("Node 238")*/ _render_only_node_flags_8_node_238 = 1ui32 << 14ui32,
		/*nicename("Node 239")*/ _render_only_node_flags_8_node_239 = 1ui32 << 15ui32,
		/*nicename("Node 240")*/ _render_only_node_flags_8_node_240 = 1ui32 << 16ui32,
		/*nicename("Node 241")*/ _render_only_node_flags_8_node_241 = 1ui32 << 17ui32,
		/*nicename("Node 242")*/ _render_only_node_flags_8_node_242 = 1ui32 << 18ui32,
		/*nicename("Node 243")*/ _render_only_node_flags_8_node_243 = 1ui32 << 19ui32,
		/*nicename("Node 244")*/ _render_only_node_flags_8_node_244 = 1ui32 << 20ui32,
		/*nicename("Node 245")*/ _render_only_node_flags_8_node_245 = 1ui32 << 21ui32,
		/*nicename("Node 246")*/ _render_only_node_flags_8_node_246 = 1ui32 << 22ui32,
		/*nicename("Node 247")*/ _render_only_node_flags_8_node_247 = 1ui32 << 23ui32,
		/*nicename("Node 248")*/ _render_only_node_flags_8_node_248 = 1ui32 << 24ui32,
		/*nicename("Node 249")*/ _render_only_node_flags_8_node_249 = 1ui32 << 25ui32,
		/*nicename("Node 250")*/ _render_only_node_flags_8_node_250 = 1ui32 << 26ui32,
		/*nicename("Node 251")*/ _render_only_node_flags_8_node_251 = 1ui32 << 27ui32,
		/*nicename("Node 252")*/ _render_only_node_flags_8_node_252 = 1ui32 << 28ui32,
		/*nicename("Node 253")*/ _render_only_node_flags_8_node_253 = 1ui32 << 29ui32,
		/*nicename("Node 254")*/ _render_only_node_flags_8_node_254 = 1ui32 << 30ui32,
		/*nicename("Node 255")*/ _render_only_node_flags_8_node_255 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 1") b_render_only_section_flags_1 : uint32_t /* bitfield */
	{
		/*nicename("Section 0")*/ _render_only_section_flags_1_section_0 = 1ui32 << 0ui32,
		/*nicename("Section 1")*/ _render_only_section_flags_1_section_1 = 1ui32 << 1ui32,
		/*nicename("Section 2")*/ _render_only_section_flags_1_section_2 = 1ui32 << 2ui32,
		/*nicename("Section 3")*/ _render_only_section_flags_1_section_3 = 1ui32 << 3ui32,
		/*nicename("Section 4")*/ _render_only_section_flags_1_section_4 = 1ui32 << 4ui32,
		/*nicename("Section 5")*/ _render_only_section_flags_1_section_5 = 1ui32 << 5ui32,
		/*nicename("Section 6")*/ _render_only_section_flags_1_section_6 = 1ui32 << 6ui32,
		/*nicename("Section 7")*/ _render_only_section_flags_1_section_7 = 1ui32 << 7ui32,
		/*nicename("Section 8")*/ _render_only_section_flags_1_section_8 = 1ui32 << 8ui32,
		/*nicename("Section 9")*/ _render_only_section_flags_1_section_9 = 1ui32 << 9ui32,
		/*nicename("Section 10")*/ _render_only_section_flags_1_section_10 = 1ui32 << 10ui32,
		/*nicename("Section 11")*/ _render_only_section_flags_1_section_11 = 1ui32 << 11ui32,
		/*nicename("Section 12")*/ _render_only_section_flags_1_section_12 = 1ui32 << 12ui32,
		/*nicename("Section 13")*/ _render_only_section_flags_1_section_13 = 1ui32 << 13ui32,
		/*nicename("Section 14")*/ _render_only_section_flags_1_section_14 = 1ui32 << 14ui32,
		/*nicename("Section 15")*/ _render_only_section_flags_1_section_15 = 1ui32 << 15ui32,
		/*nicename("Section 16")*/ _render_only_section_flags_1_section_16 = 1ui32 << 16ui32,
		/*nicename("Section 17")*/ _render_only_section_flags_1_section_17 = 1ui32 << 17ui32,
		/*nicename("Section 18")*/ _render_only_section_flags_1_section_18 = 1ui32 << 18ui32,
		/*nicename("Section 19")*/ _render_only_section_flags_1_section_19 = 1ui32 << 19ui32,
		/*nicename("Section 20")*/ _render_only_section_flags_1_section_20 = 1ui32 << 20ui32,
		/*nicename("Section 21")*/ _render_only_section_flags_1_section_21 = 1ui32 << 21ui32,
		/*nicename("Section 22")*/ _render_only_section_flags_1_section_22 = 1ui32 << 22ui32,
		/*nicename("Section 23")*/ _render_only_section_flags_1_section_23 = 1ui32 << 23ui32,
		/*nicename("Section 24")*/ _render_only_section_flags_1_section_24 = 1ui32 << 24ui32,
		/*nicename("Section 25")*/ _render_only_section_flags_1_section_25 = 1ui32 << 25ui32,
		/*nicename("Section 26")*/ _render_only_section_flags_1_section_26 = 1ui32 << 26ui32,
		/*nicename("Section 27")*/ _render_only_section_flags_1_section_27 = 1ui32 << 27ui32,
		/*nicename("Section 28")*/ _render_only_section_flags_1_section_28 = 1ui32 << 28ui32,
		/*nicename("Section 29")*/ _render_only_section_flags_1_section_29 = 1ui32 << 29ui32,
		/*nicename("Section 30")*/ _render_only_section_flags_1_section_30 = 1ui32 << 30ui32,
		/*nicename("Section 31")*/ _render_only_section_flags_1_section_31 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 2") b_render_only_section_flags_2 : uint32_t /* bitfield */
	{
		/*nicename("Section 32")*/ _render_only_section_flags_2_section_32 = 1ui32 << 0ui32,
		/*nicename("Section 33")*/ _render_only_section_flags_2_section_33 = 1ui32 << 1ui32,
		/*nicename("Section 34")*/ _render_only_section_flags_2_section_34 = 1ui32 << 2ui32,
		/*nicename("Section 35")*/ _render_only_section_flags_2_section_35 = 1ui32 << 3ui32,
		/*nicename("Section 36")*/ _render_only_section_flags_2_section_36 = 1ui32 << 4ui32,
		/*nicename("Section 37")*/ _render_only_section_flags_2_section_37 = 1ui32 << 5ui32,
		/*nicename("Section 38")*/ _render_only_section_flags_2_section_38 = 1ui32 << 6ui32,
		/*nicename("Section 39")*/ _render_only_section_flags_2_section_39 = 1ui32 << 7ui32,
		/*nicename("Section 40")*/ _render_only_section_flags_2_section_40 = 1ui32 << 8ui32,
		/*nicename("Section 41")*/ _render_only_section_flags_2_section_41 = 1ui32 << 9ui32,
		/*nicename("Section 42")*/ _render_only_section_flags_2_section_42 = 1ui32 << 10ui32,
		/*nicename("Section 43")*/ _render_only_section_flags_2_section_43 = 1ui32 << 11ui32,
		/*nicename("Section 44")*/ _render_only_section_flags_2_section_44 = 1ui32 << 12ui32,
		/*nicename("Section 45")*/ _render_only_section_flags_2_section_45 = 1ui32 << 13ui32,
		/*nicename("Section 46")*/ _render_only_section_flags_2_section_46 = 1ui32 << 14ui32,
		/*nicename("Section 47")*/ _render_only_section_flags_2_section_47 = 1ui32 << 15ui32,
		/*nicename("Section 48")*/ _render_only_section_flags_2_section_48 = 1ui32 << 16ui32,
		/*nicename("Section 49")*/ _render_only_section_flags_2_section_49 = 1ui32 << 17ui32,
		/*nicename("Section 50")*/ _render_only_section_flags_2_section_50 = 1ui32 << 18ui32,
		/*nicename("Section 51")*/ _render_only_section_flags_2_section_51 = 1ui32 << 19ui32,
		/*nicename("Section 52")*/ _render_only_section_flags_2_section_52 = 1ui32 << 20ui32,
		/*nicename("Section 53")*/ _render_only_section_flags_2_section_53 = 1ui32 << 21ui32,
		/*nicename("Section 54")*/ _render_only_section_flags_2_section_54 = 1ui32 << 22ui32,
		/*nicename("Section 55")*/ _render_only_section_flags_2_section_55 = 1ui32 << 23ui32,
		/*nicename("Section 56")*/ _render_only_section_flags_2_section_56 = 1ui32 << 24ui32,
		/*nicename("Section 57")*/ _render_only_section_flags_2_section_57 = 1ui32 << 25ui32,
		/*nicename("Section 58")*/ _render_only_section_flags_2_section_58 = 1ui32 << 26ui32,
		/*nicename("Section 59")*/ _render_only_section_flags_2_section_59 = 1ui32 << 27ui32,
		/*nicename("Section 60")*/ _render_only_section_flags_2_section_60 = 1ui32 << 28ui32,
		/*nicename("Section 61")*/ _render_only_section_flags_2_section_61 = 1ui32 << 29ui32,
		/*nicename("Section 62")*/ _render_only_section_flags_2_section_62 = 1ui32 << 30ui32,
		/*nicename("Section 63")*/ _render_only_section_flags_2_section_63 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 3") b_render_only_section_flags_3 : uint32_t /* bitfield */
	{
		/*nicename("Section 64")*/ _render_only_section_flags_3_section_64 = 1ui32 << 0ui32,
		/*nicename("Section 65")*/ _render_only_section_flags_3_section_65 = 1ui32 << 1ui32,
		/*nicename("Section 66")*/ _render_only_section_flags_3_section_66 = 1ui32 << 2ui32,
		/*nicename("Section 67")*/ _render_only_section_flags_3_section_67 = 1ui32 << 3ui32,
		/*nicename("Section 68")*/ _render_only_section_flags_3_section_68 = 1ui32 << 4ui32,
		/*nicename("Section 69")*/ _render_only_section_flags_3_section_69 = 1ui32 << 5ui32,
		/*nicename("Section 70")*/ _render_only_section_flags_3_section_70 = 1ui32 << 6ui32,
		/*nicename("Section 71")*/ _render_only_section_flags_3_section_71 = 1ui32 << 7ui32,
		/*nicename("Section 72")*/ _render_only_section_flags_3_section_72 = 1ui32 << 8ui32,
		/*nicename("Section 73")*/ _render_only_section_flags_3_section_73 = 1ui32 << 9ui32,
		/*nicename("Section 74")*/ _render_only_section_flags_3_section_74 = 1ui32 << 10ui32,
		/*nicename("Section 75")*/ _render_only_section_flags_3_section_75 = 1ui32 << 11ui32,
		/*nicename("Section 76")*/ _render_only_section_flags_3_section_76 = 1ui32 << 12ui32,
		/*nicename("Section 77")*/ _render_only_section_flags_3_section_77 = 1ui32 << 13ui32,
		/*nicename("Section 78")*/ _render_only_section_flags_3_section_78 = 1ui32 << 14ui32,
		/*nicename("Section 79")*/ _render_only_section_flags_3_section_79 = 1ui32 << 15ui32,
		/*nicename("Section 80")*/ _render_only_section_flags_3_section_80 = 1ui32 << 16ui32,
		/*nicename("Section 81")*/ _render_only_section_flags_3_section_81 = 1ui32 << 17ui32,
		/*nicename("Section 82")*/ _render_only_section_flags_3_section_82 = 1ui32 << 18ui32,
		/*nicename("Section 83")*/ _render_only_section_flags_3_section_83 = 1ui32 << 19ui32,
		/*nicename("Section 84")*/ _render_only_section_flags_3_section_84 = 1ui32 << 20ui32,
		/*nicename("Section 85")*/ _render_only_section_flags_3_section_85 = 1ui32 << 21ui32,
		/*nicename("Section 86")*/ _render_only_section_flags_3_section_86 = 1ui32 << 22ui32,
		/*nicename("Section 87")*/ _render_only_section_flags_3_section_87 = 1ui32 << 23ui32,
		/*nicename("Section 88")*/ _render_only_section_flags_3_section_88 = 1ui32 << 24ui32,
		/*nicename("Section 89")*/ _render_only_section_flags_3_section_89 = 1ui32 << 25ui32,
		/*nicename("Section 90")*/ _render_only_section_flags_3_section_90 = 1ui32 << 26ui32,
		/*nicename("Section 91")*/ _render_only_section_flags_3_section_91 = 1ui32 << 27ui32,
		/*nicename("Section 92")*/ _render_only_section_flags_3_section_92 = 1ui32 << 28ui32,
		/*nicename("Section 93")*/ _render_only_section_flags_3_section_93 = 1ui32 << 29ui32,
		/*nicename("Section 94")*/ _render_only_section_flags_3_section_94 = 1ui32 << 30ui32,
		/*nicename("Section 95")*/ _render_only_section_flags_3_section_95 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 4") b_render_only_section_flags_4 : uint32_t /* bitfield */
	{
		/*nicename("Section 96")*/ _render_only_section_flags_4_section_96 = 1ui32 << 0ui32,
		/*nicename("Section 97")*/ _render_only_section_flags_4_section_97 = 1ui32 << 1ui32,
		/*nicename("Section 98")*/ _render_only_section_flags_4_section_98 = 1ui32 << 2ui32,
		/*nicename("Section 99")*/ _render_only_section_flags_4_section_99 = 1ui32 << 3ui32,
		/*nicename("Section 100")*/ _render_only_section_flags_4_section_100 = 1ui32 << 4ui32,
		/*nicename("Section 101")*/ _render_only_section_flags_4_section_101 = 1ui32 << 5ui32,
		/*nicename("Section 102")*/ _render_only_section_flags_4_section_102 = 1ui32 << 6ui32,
		/*nicename("Section 103")*/ _render_only_section_flags_4_section_103 = 1ui32 << 7ui32,
		/*nicename("Section 104")*/ _render_only_section_flags_4_section_104 = 1ui32 << 8ui32,
		/*nicename("Section 105")*/ _render_only_section_flags_4_section_105 = 1ui32 << 9ui32,
		/*nicename("Section 106")*/ _render_only_section_flags_4_section_106 = 1ui32 << 10ui32,
		/*nicename("Section 107")*/ _render_only_section_flags_4_section_107 = 1ui32 << 11ui32,
		/*nicename("Section 108")*/ _render_only_section_flags_4_section_108 = 1ui32 << 12ui32,
		/*nicename("Section 109")*/ _render_only_section_flags_4_section_109 = 1ui32 << 13ui32,
		/*nicename("Section 110")*/ _render_only_section_flags_4_section_110 = 1ui32 << 14ui32,
		/*nicename("Section 111")*/ _render_only_section_flags_4_section_111 = 1ui32 << 15ui32,
		/*nicename("Section 112")*/ _render_only_section_flags_4_section_112 = 1ui32 << 16ui32,
		/*nicename("Section 113")*/ _render_only_section_flags_4_section_113 = 1ui32 << 17ui32,
		/*nicename("Section 114")*/ _render_only_section_flags_4_section_114 = 1ui32 << 18ui32,
		/*nicename("Section 115")*/ _render_only_section_flags_4_section_115 = 1ui32 << 19ui32,
		/*nicename("Section 116")*/ _render_only_section_flags_4_section_116 = 1ui32 << 20ui32,
		/*nicename("Section 117")*/ _render_only_section_flags_4_section_117 = 1ui32 << 21ui32,
		/*nicename("Section 118")*/ _render_only_section_flags_4_section_118 = 1ui32 << 22ui32,
		/*nicename("Section 119")*/ _render_only_section_flags_4_section_119 = 1ui32 << 23ui32,
		/*nicename("Section 120")*/ _render_only_section_flags_4_section_120 = 1ui32 << 24ui32,
		/*nicename("Section 121")*/ _render_only_section_flags_4_section_121 = 1ui32 << 25ui32,
		/*nicename("Section 122")*/ _render_only_section_flags_4_section_122 = 1ui32 << 26ui32,
		/*nicename("Section 123")*/ _render_only_section_flags_4_section_123 = 1ui32 << 27ui32,
		/*nicename("Section 124")*/ _render_only_section_flags_4_section_124 = 1ui32 << 28ui32,
		/*nicename("Section 125")*/ _render_only_section_flags_4_section_125 = 1ui32 << 29ui32,
		/*nicename("Section 126")*/ _render_only_section_flags_4_section_126 = 1ui32 << 30ui32,
		/*nicename("Section 127")*/ _render_only_section_flags_4_section_127 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 5") b_render_only_section_flags_5 : uint32_t /* bitfield */
	{
		/*nicename("Section 128")*/ _render_only_section_flags_5_section_128 = 1ui32 << 0ui32,
		/*nicename("Section 129")*/ _render_only_section_flags_5_section_129 = 1ui32 << 1ui32,
		/*nicename("Section 130")*/ _render_only_section_flags_5_section_130 = 1ui32 << 2ui32,
		/*nicename("Section 131")*/ _render_only_section_flags_5_section_131 = 1ui32 << 3ui32,
		/*nicename("Section 132")*/ _render_only_section_flags_5_section_132 = 1ui32 << 4ui32,
		/*nicename("Section 133")*/ _render_only_section_flags_5_section_133 = 1ui32 << 5ui32,
		/*nicename("Section 134")*/ _render_only_section_flags_5_section_134 = 1ui32 << 6ui32,
		/*nicename("Section 135")*/ _render_only_section_flags_5_section_135 = 1ui32 << 7ui32,
		/*nicename("Section 136")*/ _render_only_section_flags_5_section_136 = 1ui32 << 8ui32,
		/*nicename("Section 137")*/ _render_only_section_flags_5_section_137 = 1ui32 << 9ui32,
		/*nicename("Section 138")*/ _render_only_section_flags_5_section_138 = 1ui32 << 10ui32,
		/*nicename("Section 139")*/ _render_only_section_flags_5_section_139 = 1ui32 << 11ui32,
		/*nicename("Section 140")*/ _render_only_section_flags_5_section_140 = 1ui32 << 12ui32,
		/*nicename("Section 141")*/ _render_only_section_flags_5_section_141 = 1ui32 << 13ui32,
		/*nicename("Section 142")*/ _render_only_section_flags_5_section_142 = 1ui32 << 14ui32,
		/*nicename("Section 143")*/ _render_only_section_flags_5_section_143 = 1ui32 << 15ui32,
		/*nicename("Section 144")*/ _render_only_section_flags_5_section_144 = 1ui32 << 16ui32,
		/*nicename("Section 145")*/ _render_only_section_flags_5_section_145 = 1ui32 << 17ui32,
		/*nicename("Section 146")*/ _render_only_section_flags_5_section_146 = 1ui32 << 18ui32,
		/*nicename("Section 147")*/ _render_only_section_flags_5_section_147 = 1ui32 << 19ui32,
		/*nicename("Section 148")*/ _render_only_section_flags_5_section_148 = 1ui32 << 20ui32,
		/*nicename("Section 149")*/ _render_only_section_flags_5_section_149 = 1ui32 << 21ui32,
		/*nicename("Section 150")*/ _render_only_section_flags_5_section_150 = 1ui32 << 22ui32,
		/*nicename("Section 151")*/ _render_only_section_flags_5_section_151 = 1ui32 << 23ui32,
		/*nicename("Section 152")*/ _render_only_section_flags_5_section_152 = 1ui32 << 24ui32,
		/*nicename("Section 153")*/ _render_only_section_flags_5_section_153 = 1ui32 << 25ui32,
		/*nicename("Section 154")*/ _render_only_section_flags_5_section_154 = 1ui32 << 26ui32,
		/*nicename("Section 155")*/ _render_only_section_flags_5_section_155 = 1ui32 << 27ui32,
		/*nicename("Section 156")*/ _render_only_section_flags_5_section_156 = 1ui32 << 28ui32,
		/*nicename("Section 157")*/ _render_only_section_flags_5_section_157 = 1ui32 << 29ui32,
		/*nicename("Section 158")*/ _render_only_section_flags_5_section_158 = 1ui32 << 30ui32,
		/*nicename("Section 159")*/ _render_only_section_flags_5_section_159 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 6") b_render_only_section_flags_6 : uint32_t /* bitfield */
	{
		/*nicename("Section 160")*/ _render_only_section_flags_6_section_160 = 1ui32 << 0ui32,
		/*nicename("Section 161")*/ _render_only_section_flags_6_section_161 = 1ui32 << 1ui32,
		/*nicename("Section 162")*/ _render_only_section_flags_6_section_162 = 1ui32 << 2ui32,
		/*nicename("Section 163")*/ _render_only_section_flags_6_section_163 = 1ui32 << 3ui32,
		/*nicename("Section 164")*/ _render_only_section_flags_6_section_164 = 1ui32 << 4ui32,
		/*nicename("Section 165")*/ _render_only_section_flags_6_section_165 = 1ui32 << 5ui32,
		/*nicename("Section 166")*/ _render_only_section_flags_6_section_166 = 1ui32 << 6ui32,
		/*nicename("Section 167")*/ _render_only_section_flags_6_section_167 = 1ui32 << 7ui32,
		/*nicename("Section 168")*/ _render_only_section_flags_6_section_168 = 1ui32 << 8ui32,
		/*nicename("Section 169")*/ _render_only_section_flags_6_section_169 = 1ui32 << 9ui32,
		/*nicename("Section 170")*/ _render_only_section_flags_6_section_170 = 1ui32 << 10ui32,
		/*nicename("Section 171")*/ _render_only_section_flags_6_section_171 = 1ui32 << 11ui32,
		/*nicename("Section 172")*/ _render_only_section_flags_6_section_172 = 1ui32 << 12ui32,
		/*nicename("Section 173")*/ _render_only_section_flags_6_section_173 = 1ui32 << 13ui32,
		/*nicename("Section 174")*/ _render_only_section_flags_6_section_174 = 1ui32 << 14ui32,
		/*nicename("Section 175")*/ _render_only_section_flags_6_section_175 = 1ui32 << 15ui32,
		/*nicename("Section 176")*/ _render_only_section_flags_6_section_176 = 1ui32 << 16ui32,
		/*nicename("Section 177")*/ _render_only_section_flags_6_section_177 = 1ui32 << 17ui32,
		/*nicename("Section 178")*/ _render_only_section_flags_6_section_178 = 1ui32 << 18ui32,
		/*nicename("Section 179")*/ _render_only_section_flags_6_section_179 = 1ui32 << 19ui32,
		/*nicename("Section 180")*/ _render_only_section_flags_6_section_180 = 1ui32 << 20ui32,
		/*nicename("Section 181")*/ _render_only_section_flags_6_section_181 = 1ui32 << 21ui32,
		/*nicename("Section 182")*/ _render_only_section_flags_6_section_182 = 1ui32 << 22ui32,
		/*nicename("Section 183")*/ _render_only_section_flags_6_section_183 = 1ui32 << 23ui32,
		/*nicename("Section 184")*/ _render_only_section_flags_6_section_184 = 1ui32 << 24ui32,
		/*nicename("Section 185")*/ _render_only_section_flags_6_section_185 = 1ui32 << 25ui32,
		/*nicename("Section 186")*/ _render_only_section_flags_6_section_186 = 1ui32 << 26ui32,
		/*nicename("Section 187")*/ _render_only_section_flags_6_section_187 = 1ui32 << 27ui32,
		/*nicename("Section 188")*/ _render_only_section_flags_6_section_188 = 1ui32 << 28ui32,
		/*nicename("Section 189")*/ _render_only_section_flags_6_section_189 = 1ui32 << 29ui32,
		/*nicename("Section 190")*/ _render_only_section_flags_6_section_190 = 1ui32 << 30ui32,
		/*nicename("Section 191")*/ _render_only_section_flags_6_section_191 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 7") b_render_only_section_flags_7 : uint32_t /* bitfield */
	{
		/*nicename("Section 192")*/ _render_only_section_flags_7_section_192 = 1ui32 << 0ui32,
		/*nicename("Section 193")*/ _render_only_section_flags_7_section_193 = 1ui32 << 1ui32,
		/*nicename("Section 194")*/ _render_only_section_flags_7_section_194 = 1ui32 << 2ui32,
		/*nicename("Section 195")*/ _render_only_section_flags_7_section_195 = 1ui32 << 3ui32,
		/*nicename("Section 196")*/ _render_only_section_flags_7_section_196 = 1ui32 << 4ui32,
		/*nicename("Section 197")*/ _render_only_section_flags_7_section_197 = 1ui32 << 5ui32,
		/*nicename("Section 198")*/ _render_only_section_flags_7_section_198 = 1ui32 << 6ui32,
		/*nicename("Section 199")*/ _render_only_section_flags_7_section_199 = 1ui32 << 7ui32,
		/*nicename("Section 200")*/ _render_only_section_flags_7_section_200 = 1ui32 << 8ui32,
		/*nicename("Section 201")*/ _render_only_section_flags_7_section_201 = 1ui32 << 9ui32,
		/*nicename("Section 202")*/ _render_only_section_flags_7_section_202 = 1ui32 << 10ui32,
		/*nicename("Section 203")*/ _render_only_section_flags_7_section_203 = 1ui32 << 11ui32,
		/*nicename("Section 204")*/ _render_only_section_flags_7_section_204 = 1ui32 << 12ui32,
		/*nicename("Section 205")*/ _render_only_section_flags_7_section_205 = 1ui32 << 13ui32,
		/*nicename("Section 206")*/ _render_only_section_flags_7_section_206 = 1ui32 << 14ui32,
		/*nicename("Section 207")*/ _render_only_section_flags_7_section_207 = 1ui32 << 15ui32,
		/*nicename("Section 208")*/ _render_only_section_flags_7_section_208 = 1ui32 << 16ui32,
		/*nicename("Section 209")*/ _render_only_section_flags_7_section_209 = 1ui32 << 17ui32,
		/*nicename("Section 210")*/ _render_only_section_flags_7_section_210 = 1ui32 << 18ui32,
		/*nicename("Section 211")*/ _render_only_section_flags_7_section_211 = 1ui32 << 19ui32,
		/*nicename("Section 212")*/ _render_only_section_flags_7_section_212 = 1ui32 << 20ui32,
		/*nicename("Section 213")*/ _render_only_section_flags_7_section_213 = 1ui32 << 21ui32,
		/*nicename("Section 214")*/ _render_only_section_flags_7_section_214 = 1ui32 << 22ui32,
		/*nicename("Section 215")*/ _render_only_section_flags_7_section_215 = 1ui32 << 23ui32,
		/*nicename("Section 216")*/ _render_only_section_flags_7_section_216 = 1ui32 << 24ui32,
		/*nicename("Section 217")*/ _render_only_section_flags_7_section_217 = 1ui32 << 25ui32,
		/*nicename("Section 218")*/ _render_only_section_flags_7_section_218 = 1ui32 << 26ui32,
		/*nicename("Section 219")*/ _render_only_section_flags_7_section_219 = 1ui32 << 27ui32,
		/*nicename("Section 220")*/ _render_only_section_flags_7_section_220 = 1ui32 << 28ui32,
		/*nicename("Section 221")*/ _render_only_section_flags_7_section_221 = 1ui32 << 29ui32,
		/*nicename("Section 222")*/ _render_only_section_flags_7_section_222 = 1ui32 << 30ui32,
		/*nicename("Section 223")*/ _render_only_section_flags_7_section_223 = 1ui32 << 31ui32,
	};

	enum nicename("Render-Only Section Flags 8") b_render_only_section_flags_8 : uint32_t /* bitfield */
	{
		/*nicename("Section 224")*/ _render_only_section_flags_8_section_224 = 1ui32 << 0ui32,
		/*nicename("Section 225")*/ _render_only_section_flags_8_section_225 = 1ui32 << 1ui32,
		/*nicename("Section 226")*/ _render_only_section_flags_8_section_226 = 1ui32 << 2ui32,
		/*nicename("Section 227")*/ _render_only_section_flags_8_section_227 = 1ui32 << 3ui32,
		/*nicename("Section 228")*/ _render_only_section_flags_8_section_228 = 1ui32 << 4ui32,
		/*nicename("Section 229")*/ _render_only_section_flags_8_section_229 = 1ui32 << 5ui32,
		/*nicename("Section 230")*/ _render_only_section_flags_8_section_230 = 1ui32 << 6ui32,
		/*nicename("Section 231")*/ _render_only_section_flags_8_section_231 = 1ui32 << 7ui32,
		/*nicename("Section 232")*/ _render_only_section_flags_8_section_232 = 1ui32 << 8ui32,
		/*nicename("Section 233")*/ _render_only_section_flags_8_section_233 = 1ui32 << 9ui32,
		/*nicename("Section 234")*/ _render_only_section_flags_8_section_234 = 1ui32 << 10ui32,
		/*nicename("Section 235")*/ _render_only_section_flags_8_section_235 = 1ui32 << 11ui32,
		/*nicename("Section 236")*/ _render_only_section_flags_8_section_236 = 1ui32 << 12ui32,
		/*nicename("Section 237")*/ _render_only_section_flags_8_section_237 = 1ui32 << 13ui32,
		/*nicename("Section 238")*/ _render_only_section_flags_8_section_238 = 1ui32 << 14ui32,
		/*nicename("Section 239")*/ _render_only_section_flags_8_section_239 = 1ui32 << 15ui32,
		/*nicename("Section 240")*/ _render_only_section_flags_8_section_240 = 1ui32 << 16ui32,
		/*nicename("Section 241")*/ _render_only_section_flags_8_section_241 = 1ui32 << 17ui32,
		/*nicename("Section 242")*/ _render_only_section_flags_8_section_242 = 1ui32 << 18ui32,
		/*nicename("Section 243")*/ _render_only_section_flags_8_section_243 = 1ui32 << 19ui32,
		/*nicename("Section 244")*/ _render_only_section_flags_8_section_244 = 1ui32 << 20ui32,
		/*nicename("Section 245")*/ _render_only_section_flags_8_section_245 = 1ui32 << 21ui32,
		/*nicename("Section 246")*/ _render_only_section_flags_8_section_246 = 1ui32 << 22ui32,
		/*nicename("Section 247")*/ _render_only_section_flags_8_section_247 = 1ui32 << 23ui32,
		/*nicename("Section 248")*/ _render_only_section_flags_8_section_248 = 1ui32 << 24ui32,
		/*nicename("Section 249")*/ _render_only_section_flags_8_section_249 = 1ui32 << 25ui32,
		/*nicename("Section 250")*/ _render_only_section_flags_8_section_250 = 1ui32 << 26ui32,
		/*nicename("Section 251")*/ _render_only_section_flags_8_section_251 = 1ui32 << 27ui32,
		/*nicename("Section 252")*/ _render_only_section_flags_8_section_252 = 1ui32 << 28ui32,
		/*nicename("Section 253")*/ _render_only_section_flags_8_section_253 = 1ui32 << 29ui32,
		/*nicename("Section 254")*/ _render_only_section_flags_8_section_254 = 1ui32 << 30ui32,
		/*nicename("Section 255")*/ _render_only_section_flags_8_section_255 = 1ui32 << 31ui32,
	};

	enum nicename("Runtime Flags") b_runtime_flags : uint32_t /* bitfield */
	{
		/*nicename("Contains Runtime Nodes")*/ _runtime_flags_contains_runtime_nodes = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _runtime_flags_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _runtime_flags_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _runtime_flags_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _runtime_flags_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _runtime_flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _runtime_flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _runtime_flags_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _runtime_flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _runtime_flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _runtime_flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _runtime_flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _runtime_flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _runtime_flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _runtime_flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _runtime_flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _runtime_flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _runtime_flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _runtime_flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _runtime_flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _runtime_flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _runtime_flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _runtime_flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _runtime_flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _runtime_flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _runtime_flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _runtime_flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _runtime_flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _runtime_flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _runtime_flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _runtime_flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _runtime_flags_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Variants") s_variants_definition
	{
		struct nicename("Regions") s_regions_definition
		{
			enum nicename("Sort Order") e_sort_order : uint32_t
			{
				/*nicename("No Sorting")*/ _sort_order_no_sorting = 1ui32,
				/*nicename("-5 (Closest)")*/ _sort_order__5_closest = 2ui32,
				/*nicename("-4")*/ _sort_order__4 = 3ui32,
				/*nicename("-3")*/ _sort_order__3 = 4ui32,
				/*nicename("-2")*/ _sort_order__2 = 5ui32,
				/*nicename("-1")*/ _sort_order__1 = 6ui32,
				/*nicename("0 (Same As Model)")*/ _sort_order__0_same_as_model = 7ui32,
				/*nicename("1")*/ _sort_order__11 = 8ui32,
				/*nicename("2")*/ _sort_order__21 = 9ui32,
				/*nicename("3")*/ _sort_order__31 = 10ui32,
				/*nicename("4")*/ _sort_order__41 = 11ui32,
				/*nicename("5 (Farthest)")*/ _sort_order__5_farthest = 12ui32,
			};

			struct nicename("Permutation") s_permutation_definition
			{
				enum nicename("Flags") b_flags : uint8_t /* bitfield */
				{
					/*nicename("Copy States To All Permutations")*/ _flags_copy_states_to_all_permutations = 1ui8 << 0ui8,
				};

				struct nicename("States") s_states_definition
				{
					enum nicename("State") e_state : uint16_t
					{
						/*nicename("Default")*/ _state_default = 1ui16,
						/*nicename("Minor Damage")*/ _state_minor_damage = 2ui16,
						/*nicename("Medium Damage")*/ _state_medium_damage = 3ui16,
						/*nicename("Major Damage")*/ _state_major_damage = 4ui16,
						/*nicename("Destroyed")*/ _state_destroyed = 5ui16,
					};

					enum nicename("Property Flags") b_property_flags : uint8_t /* bitfield */
					{
						/*nicename("Blurred")*/ _property_flags_blurred = 1ui8 << 0ui8,
						/*nicename("Hella Blurred")*/ _property_flags_hella_blurred = 1ui8 << 1ui8,
						/*nicename("Shielded")*/ _property_flags_shielded = 1ui8 << 2ui8,
						/*nicename("Bit 3")*/ _property_flags_bit_3 = 1ui8 << 3ui8,
						/*nicename("Bit 4")*/ _property_flags_bit_4 = 1ui8 << 4ui8,
						/*nicename("Bit 5")*/ _property_flags_bit_5 = 1ui8 << 5ui8,
						/*nicename("Bit 6")*/ _property_flags_bit_6 = 1ui8 << 6ui8,
						/*nicename("Bit 7")*/ _property_flags_bit_7 = 1ui8 << 7ui8,
					};

					string_id nicename("Name") name;
					int8_t nicename("Model Permutation Index") model_permutation_index;
					b_property_flags nicename("Property Flags") property_flags;
					e_state nicename("State") state;
					float nicename("Initial Probability") initial_probability;
				};

				string_id nicename("Name") name;
				int8_t nicename("Model Permutation Index") model_permutation_index;
				b_flags nicename("Flags") flags;
				int8_t __unknown0;
				int8_t __unknown1;
				float nicename("Probability") probability;
				s_tag_block_definition<s_states_definition> nicename("States") states_block;
				Undefined32 __unknown2;
				Undefined32 __unknown3;
				Undefined32 __unknown4;
			};

			string_id nicename("Name") name;
			int8_t nicename("Model Region Index") model_region_index;
			int8_t __unknown0;
			int16_t nicename("Parent Variant Index") parent_variant_index;
			s_tag_block_definition<s_permutation_definition> nicename("Permutation") permutation_block;
			e_sort_order nicename("Sort Order") sort_order;
		};

		struct nicename("Objects") s_objects_definition
		{
			string_id nicename("Parent Marker") parent_marker;
			string_id nicename("Child Marker") child_marker;
			string_id nicename("Object Variant") object_variant;
			TagReference nicename("Child Object") child_object_reference;
			int16_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		int8_t nicename("Model Region 0 Index") model_region_0_index;
		int8_t nicename("Model Region 1 Index") model_region_1_index;
		int8_t nicename("Model Region 2 Index") model_region_2_index;
		int8_t nicename("Model Region 3 Index") model_region_3_index;
		int8_t nicename("Model Region 4 Index") model_region_4_index;
		int8_t nicename("Model Region 5 Index") model_region_5_index;
		int8_t nicename("Model Region 6 Index") model_region_6_index;
		int8_t nicename("Model Region 7 Index") model_region_7_index;
		int8_t nicename("Model Region 8 Index") model_region_8_index;
		int8_t nicename("Model Region 9 Index") model_region_9_index;
		int8_t nicename("Model Region 10 Index") model_region_10_index;
		int8_t nicename("Model Region 11 Index") model_region_11_index;
		int8_t nicename("Model Region 12 Index") model_region_12_index;
		int8_t nicename("Model Region 13 Index") model_region_13_index;
		int8_t nicename("Model Region 14 Index") model_region_14_index;
		int8_t nicename("Model Region 15 Index") model_region_15_index;
		s_tag_block_definition<s_regions_definition> nicename("Regions") regions_block;
		s_tag_block_definition<s_objects_definition> nicename("Objects") objects_block;
		int32_t nicename("Instance Group Index") instance_group_index;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		string_id __unknown0;
	};

	struct nicename("Instance Groups") s_instance_groups_definition
	{
		string_id nicename("Name") name;
		int32_t __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		float nicename("Probability") probability;
	};

	struct nicename("Materials") s_materials_definition
	{
		string_id nicename("Material Name") material_name;
		int16_t __unknown0;
		int16_t nicename("Damage Section Index") damage_section_index;
		int16_t __unknown1;
		int16_t __unknown2;
		string_id nicename("Material Name") material_name1;
		int16_t nicename("Global Material Index") global_material_index;
		int16_t __unknown3;
	};

	struct nicename("Omaha Materials") s_omaha_materials_definition
	{
		string_id nicename("Material Name") material_name;
		int16_t __unknown0;
		int16_t nicename("Damage Section Index") damage_section_index;
		int16_t __unknown1;
		int16_t __unknown2;
		string_id nicename("Material Name") material_name1;
		int16_t nicename("Global Material Index") global_material_index;
		int16_t __unknown3;
	};

	struct nicename("New Damage Info") s_new_damage_info_definition
	{
		enum nicename("Collision Damage Reporting Type") e_collision_damage_reporting_type : uint8_t
		{
			/*nicename("Guardians (Unknown)")*/ _collision_damage_reporting_type_guardians_unknown = 1ui8,
			/*nicename("Guardians")*/ _collision_damage_reporting_type_guardians = 2ui8,
			/*nicename("Guardians (Scripting)")*/ _collision_damage_reporting_type_guardians_scripting = 3ui8,
			/*nicename("Suicide")*/ _collision_damage_reporting_type_suicide = 4ui8,
			/*nicename("Magnum")*/ _collision_damage_reporting_type_magnum = 5ui8,
			/*nicename("Assault Rifle")*/ _collision_damage_reporting_type_assault_rifle = 6ui8,
			/*nicename("DMR")*/ _collision_damage_reporting_type_dmr = 7ui8,
			/*nicename("Shotgun")*/ _collision_damage_reporting_type_shotgun = 8ui8,
			/*nicename("Sniper Rifle")*/ _collision_damage_reporting_type_sniper_rifle = 9ui8,
			/*nicename("Rocket Launcher")*/ _collision_damage_reporting_type_rocket_launcher = 10ui8,
			/*nicename("Spartan Laser")*/ _collision_damage_reporting_type_spartan_laser = 11ui8,
			/*nicename("Frag Grenade")*/ _collision_damage_reporting_type_frag_grenade = 12ui8,
			/*nicename("Grenade Launcher")*/ _collision_damage_reporting_type_grenade_launcher = 13ui8,
			/*nicename("Plasma Pistol")*/ _collision_damage_reporting_type_plasma_pistol = 14ui8,
			/*nicename("Needler")*/ _collision_damage_reporting_type_needler = 15ui8,
			/*nicename("Plasma Rifle")*/ _collision_damage_reporting_type_plasma_rifle = 16ui8,
			/*nicename("Plasma Repeater")*/ _collision_damage_reporting_type_plasma_repeater = 17ui8,
			/*nicename("Needle Rifle")*/ _collision_damage_reporting_type_needle_rifle = 18ui8,
			/*nicename("Spiker")*/ _collision_damage_reporting_type_spiker = 19ui8,
			/*nicename("Plasma Launcher")*/ _collision_damage_reporting_type_plasma_launcher = 20ui8,
			/*nicename("Gravity Hammer")*/ _collision_damage_reporting_type_gravity_hammer = 21ui8,
			/*nicename("Energy Sword")*/ _collision_damage_reporting_type_energy_sword = 22ui8,
			/*nicename("Plasma Grenade")*/ _collision_damage_reporting_type_plasma_grenade = 23ui8,
			/*nicename("Concussion Rifle")*/ _collision_damage_reporting_type_concussion_rifle = 24ui8,
			/*nicename("Ghost")*/ _collision_damage_reporting_type_ghost = 25ui8,
			/*nicename("Revenant")*/ _collision_damage_reporting_type_revenant = 26ui8,
			/*nicename("Revenant Gunner")*/ _collision_damage_reporting_type_revenant_gunner = 27ui8,
			/*nicename("Wraith")*/ _collision_damage_reporting_type_wraith = 28ui8,
			/*nicename("Wraith Turret")*/ _collision_damage_reporting_type_wraith_turret = 29ui8,
			/*nicename("Banshee")*/ _collision_damage_reporting_type_banshee = 30ui8,
			/*nicename("Banshee Bomb")*/ _collision_damage_reporting_type_banshee_bomb = 31ui8,
			/*nicename("Seraph")*/ _collision_damage_reporting_type_seraph = 32ui8,
			/*nicename("Mongoose")*/ _collision_damage_reporting_type_mongoose = 33ui8,
			/*nicename("Warthog")*/ _collision_damage_reporting_type_warthog = 34ui8,
			/*nicename("Warthog Chaingun")*/ _collision_damage_reporting_type_warthog_chaingun = 35ui8,
			/*nicename("Warthog Gauss")*/ _collision_damage_reporting_type_warthog_gauss = 36ui8,
			/*nicename("Warthog Rocket")*/ _collision_damage_reporting_type_warthog_rocket = 37ui8,
			/*nicename("Scorpion")*/ _collision_damage_reporting_type_scorpion = 38ui8,
			/*nicename("Scorpion Turret")*/ _collision_damage_reporting_type_scorpion_turret = 39ui8,
			/*nicename("Falcon")*/ _collision_damage_reporting_type_falcon = 40ui8,
			/*nicename("Falcon Gunner")*/ _collision_damage_reporting_type_falcon_gunner = 41ui8,
			/*nicename("Falling")*/ _collision_damage_reporting_type_falling = 42ui8,
			/*nicename("Collision")*/ _collision_damage_reporting_type_collision = 43ui8,
			/*nicename("Melee")*/ _collision_damage_reporting_type_melee = 44ui8,
			/*nicename("Explosion")*/ _collision_damage_reporting_type_explosion = 45ui8,
			/*nicename("Birthday Explosion")*/ _collision_damage_reporting_type_birthday_explosion = 46ui8,
			/*nicename("Flag")*/ _collision_damage_reporting_type_flag = 47ui8,
			/*nicename("Bomb")*/ _collision_damage_reporting_type_bomb = 48ui8,
			/*nicename("Bomb Explosion")*/ _collision_damage_reporting_type_bomb_explosion = 49ui8,
			/*nicename("Ball")*/ _collision_damage_reporting_type_ball = 50ui8,
			/*nicename("Teleporter")*/ _collision_damage_reporting_type_teleporter = 51ui8,
			/*nicename("Transfer Damage")*/ _collision_damage_reporting_type_transfer_damage = 52ui8,
			/*nicename("Armor Lock")*/ _collision_damage_reporting_type_armor_lock = 53ui8,
			/*nicename("Target Locator")*/ _collision_damage_reporting_type_target_locator = 54ui8,
			/*nicename("Human Turret")*/ _collision_damage_reporting_type_human_turret = 55ui8,
			/*nicename("Plasma Cannon")*/ _collision_damage_reporting_type_plasma_cannon = 56ui8,
			/*nicename("Plasma Mortar")*/ _collision_damage_reporting_type_plasma_mortar = 57ui8,
			/*nicename("Plasma Turret")*/ _collision_damage_reporting_type_plasma_turret = 58ui8,
			/*nicename("Shade Turret")*/ _collision_damage_reporting_type_shade_turret = 59ui8,
			/*nicename("Sabre")*/ _collision_damage_reporting_type_sabre = 60ui8,
			/*nicename("SMG")*/ _collision_damage_reporting_type_smg = 61ui8,
			/*nicename("Carbine")*/ _collision_damage_reporting_type_carbine = 62ui8,
			/*nicename("Battle Rifle")*/ _collision_damage_reporting_type_battle_rifle = 63ui8,
			/*nicename("Focus Rifle")*/ _collision_damage_reporting_type_focus_rifle = 64ui8,
			/*nicename("Fuel Rod")*/ _collision_damage_reporting_type_fuel_rod = 65ui8,
			/*nicename("Missile Pod")*/ _collision_damage_reporting_type_missile_pod = 66ui8,
			/*nicename("Brute Shot")*/ _collision_damage_reporting_type_brute_shot = 67ui8,
			/*nicename("Flamethrower")*/ _collision_damage_reporting_type_flamethrower = 68ui8,
			/*nicename("Sentinel Gun")*/ _collision_damage_reporting_type_sentinel_gun = 69ui8,
			/*nicename("Spike Grenade")*/ _collision_damage_reporting_type_spike_grenade = 70ui8,
			/*nicename("Firebomb Grenade")*/ _collision_damage_reporting_type_firebomb_grenade = 71ui8,
			/*nicename("Elephant Turret")*/ _collision_damage_reporting_type_elephant_turret = 72ui8,
			/*nicename("Spectre")*/ _collision_damage_reporting_type_spectre = 73ui8,
			/*nicename("Spectre Gunner")*/ _collision_damage_reporting_type_spectre_gunner = 74ui8,
			/*nicename("Tank")*/ _collision_damage_reporting_type_tank = 75ui8,
			/*nicename("Chopper")*/ _collision_damage_reporting_type_chopper = 76ui8,
			/*nicename("Falcon")*/ _collision_damage_reporting_type_falcon1 = 77ui8,
			/*nicename("Mantis")*/ _collision_damage_reporting_type_mantis = 78ui8,
			/*nicename("Prowler")*/ _collision_damage_reporting_type_prowler = 79ui8,
			/*nicename("Sentinel Beam")*/ _collision_damage_reporting_type_sentinel_beam = 80ui8,
			/*nicename("Sentinel RPG")*/ _collision_damage_reporting_type_sentinel_rpg = 81ui8,
			/*nicename("Tripmine")*/ _collision_damage_reporting_type_tripmine = 82ui8,
		};

		enum nicename("Response Damage Reporting Type") e_response_damage_reporting_type : uint8_t
		{
			/*nicename("Guardians (Unknown)")*/ _response_damage_reporting_type_guardians_unknown = 1ui8,
			/*nicename("Guardians")*/ _response_damage_reporting_type_guardians = 2ui8,
			/*nicename("Guardians (Scripting)")*/ _response_damage_reporting_type_guardians_scripting = 3ui8,
			/*nicename("Suicide")*/ _response_damage_reporting_type_suicide = 4ui8,
			/*nicename("Magnum")*/ _response_damage_reporting_type_magnum = 5ui8,
			/*nicename("Assault Rifle")*/ _response_damage_reporting_type_assault_rifle = 6ui8,
			/*nicename("DMR")*/ _response_damage_reporting_type_dmr = 7ui8,
			/*nicename("Shotgun")*/ _response_damage_reporting_type_shotgun = 8ui8,
			/*nicename("Sniper Rifle")*/ _response_damage_reporting_type_sniper_rifle = 9ui8,
			/*nicename("Rocket Launcher")*/ _response_damage_reporting_type_rocket_launcher = 10ui8,
			/*nicename("Spartan Laser")*/ _response_damage_reporting_type_spartan_laser = 11ui8,
			/*nicename("Frag Grenade")*/ _response_damage_reporting_type_frag_grenade = 12ui8,
			/*nicename("Grenade Launcher")*/ _response_damage_reporting_type_grenade_launcher = 13ui8,
			/*nicename("Plasma Pistol")*/ _response_damage_reporting_type_plasma_pistol = 14ui8,
			/*nicename("Needler")*/ _response_damage_reporting_type_needler = 15ui8,
			/*nicename("Plasma Rifle")*/ _response_damage_reporting_type_plasma_rifle = 16ui8,
			/*nicename("Plasma Repeater")*/ _response_damage_reporting_type_plasma_repeater = 17ui8,
			/*nicename("Needle Rifle")*/ _response_damage_reporting_type_needle_rifle = 18ui8,
			/*nicename("Spiker")*/ _response_damage_reporting_type_spiker = 19ui8,
			/*nicename("Plasma Launcher")*/ _response_damage_reporting_type_plasma_launcher = 20ui8,
			/*nicename("Gravity Hammer")*/ _response_damage_reporting_type_gravity_hammer = 21ui8,
			/*nicename("Energy Sword")*/ _response_damage_reporting_type_energy_sword = 22ui8,
			/*nicename("Plasma Grenade")*/ _response_damage_reporting_type_plasma_grenade = 23ui8,
			/*nicename("Concussion Rifle")*/ _response_damage_reporting_type_concussion_rifle = 24ui8,
			/*nicename("Ghost")*/ _response_damage_reporting_type_ghost = 25ui8,
			/*nicename("Revenant")*/ _response_damage_reporting_type_revenant = 26ui8,
			/*nicename("Revenant Gunner")*/ _response_damage_reporting_type_revenant_gunner = 27ui8,
			/*nicename("Wraith")*/ _response_damage_reporting_type_wraith = 28ui8,
			/*nicename("Wraith Turret")*/ _response_damage_reporting_type_wraith_turret = 29ui8,
			/*nicename("Banshee")*/ _response_damage_reporting_type_banshee = 30ui8,
			/*nicename("Banshee Bomb")*/ _response_damage_reporting_type_banshee_bomb = 31ui8,
			/*nicename("Seraph")*/ _response_damage_reporting_type_seraph = 32ui8,
			/*nicename("Mongoose")*/ _response_damage_reporting_type_mongoose = 33ui8,
			/*nicename("Warthog")*/ _response_damage_reporting_type_warthog = 34ui8,
			/*nicename("Warthog Chaingun")*/ _response_damage_reporting_type_warthog_chaingun = 35ui8,
			/*nicename("Warthog Gauss")*/ _response_damage_reporting_type_warthog_gauss = 36ui8,
			/*nicename("Warthog Rocket")*/ _response_damage_reporting_type_warthog_rocket = 37ui8,
			/*nicename("Scorpion")*/ _response_damage_reporting_type_scorpion = 38ui8,
			/*nicename("Scorpion Turret")*/ _response_damage_reporting_type_scorpion_turret = 39ui8,
			/*nicename("Falcon")*/ _response_damage_reporting_type_falcon = 40ui8,
			/*nicename("Falcon Gunner")*/ _response_damage_reporting_type_falcon_gunner = 41ui8,
			/*nicename("Falling")*/ _response_damage_reporting_type_falling = 42ui8,
			/*nicename("Collision")*/ _response_damage_reporting_type_collision = 43ui8,
			/*nicename("Melee")*/ _response_damage_reporting_type_melee = 44ui8,
			/*nicename("Explosion")*/ _response_damage_reporting_type_explosion = 45ui8,
			/*nicename("Birthday Explosion")*/ _response_damage_reporting_type_birthday_explosion = 46ui8,
			/*nicename("Flag")*/ _response_damage_reporting_type_flag = 47ui8,
			/*nicename("Bomb")*/ _response_damage_reporting_type_bomb = 48ui8,
			/*nicename("Bomb Explosion")*/ _response_damage_reporting_type_bomb_explosion = 49ui8,
			/*nicename("Ball")*/ _response_damage_reporting_type_ball = 50ui8,
			/*nicename("Teleporter")*/ _response_damage_reporting_type_teleporter = 51ui8,
			/*nicename("Transfer Damage")*/ _response_damage_reporting_type_transfer_damage = 52ui8,
			/*nicename("Armor Lock")*/ _response_damage_reporting_type_armor_lock = 53ui8,
			/*nicename("Target Locator")*/ _response_damage_reporting_type_target_locator = 54ui8,
			/*nicename("Human Turret")*/ _response_damage_reporting_type_human_turret = 55ui8,
			/*nicename("Plasma Cannon")*/ _response_damage_reporting_type_plasma_cannon = 56ui8,
			/*nicename("Plasma Mortar")*/ _response_damage_reporting_type_plasma_mortar = 57ui8,
			/*nicename("Plasma Turret")*/ _response_damage_reporting_type_plasma_turret = 58ui8,
			/*nicename("Shade Turret")*/ _response_damage_reporting_type_shade_turret = 59ui8,
			/*nicename("Sabre")*/ _response_damage_reporting_type_sabre = 60ui8,
			/*nicename("SMG")*/ _response_damage_reporting_type_smg = 61ui8,
			/*nicename("Carbine")*/ _response_damage_reporting_type_carbine = 62ui8,
			/*nicename("Battle Rifle")*/ _response_damage_reporting_type_battle_rifle = 63ui8,
			/*nicename("Focus Rifle")*/ _response_damage_reporting_type_focus_rifle = 64ui8,
			/*nicename("Fuel Rod")*/ _response_damage_reporting_type_fuel_rod = 65ui8,
			/*nicename("Missile Pod")*/ _response_damage_reporting_type_missile_pod = 66ui8,
			/*nicename("Brute Shot")*/ _response_damage_reporting_type_brute_shot = 67ui8,
			/*nicename("Flamethrower")*/ _response_damage_reporting_type_flamethrower = 68ui8,
			/*nicename("Sentinel Gun")*/ _response_damage_reporting_type_sentinel_gun = 69ui8,
			/*nicename("Spike Grenade")*/ _response_damage_reporting_type_spike_grenade = 70ui8,
			/*nicename("Firebomb Grenade")*/ _response_damage_reporting_type_firebomb_grenade = 71ui8,
			/*nicename("Elephant Turret")*/ _response_damage_reporting_type_elephant_turret = 72ui8,
			/*nicename("Spectre")*/ _response_damage_reporting_type_spectre = 73ui8,
			/*nicename("Spectre Gunner")*/ _response_damage_reporting_type_spectre_gunner = 74ui8,
			/*nicename("Tank")*/ _response_damage_reporting_type_tank = 75ui8,
			/*nicename("Chopper")*/ _response_damage_reporting_type_chopper = 76ui8,
			/*nicename("Falcon")*/ _response_damage_reporting_type_falcon1 = 77ui8,
			/*nicename("Mantis")*/ _response_damage_reporting_type_mantis = 78ui8,
			/*nicename("Prowler")*/ _response_damage_reporting_type_prowler = 79ui8,
			/*nicename("Sentinel Beam")*/ _response_damage_reporting_type_sentinel_beam = 80ui8,
			/*nicename("Sentinel RPG")*/ _response_damage_reporting_type_sentinel_rpg = 81ui8,
			/*nicename("Tripmine")*/ _response_damage_reporting_type_tripmine = 82ui8,
		};

		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Takes Shield Damage For Children")*/ _flags_takes_shield_damage_for_children = 1ui32 << 0ui32,
			/*nicename("Takes Body Damage For Children")*/ _flags_takes_body_damage_for_children = 1ui32 << 1ui32,
			/*nicename("Always Shields Friendly Damage")*/ _flags_always_shields_friendly_damage = 1ui32 << 2ui32,
			/*nicename("Passes Area Damage To Children")*/ _flags_passes_area_damage_to_children = 1ui32 << 3ui32,
			/*nicename("Parent Never Takes Body Damage For Children")*/ _flags_parent_never_takes_body_damage_for_children = 1ui32 << 4ui32,
			/*nicename("Only Damaged By Explosives")*/ _flags_only_damaged_by_explosives = 1ui32 << 5ui32,
			/*nicename("Parent Never Takes Shield Damage For Children")*/ _flags_parent_never_takes_shield_damage_for_children = 1ui32 << 6ui32,
			/*nicename("Cannot Die From Damage")*/ _flags_cannot_die_from_damage = 1ui32 << 7ui32,
			/*nicename("Passes Attached Damage To Riders")*/ _flags_passes_attached_damage_to_riders = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Only Damaged By Player")*/ _flags_only_damaged_by_player = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Damage Sections") s_damage_sections_definition
		{
			enum nicename("Flags") b_flags : uint32_t /* bitfield */
			{
				/*nicename("Absorbs Body Damage")*/ _flags_absorbs_body_damage = 1ui32 << 0ui32,
				/*nicename("Takes Full Damage When Object Dies")*/ _flags_takes_full_damage_when_object_dies = 1ui32 << 1ui32,
				/*nicename("Cannot Die With Riders")*/ _flags_cannot_die_with_riders = 1ui32 << 2ui32,
				/*nicename("Takes Full Damage When Object Destroyed")*/ _flags_takes_full_damage_when_object_destroyed = 1ui32 << 3ui32,
				/*nicename("Restored On Ressurection")*/ _flags_restored_on_ressurection = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
				/*nicename("Headshotable")*/ _flags_headshotable = 1ui32 << 7ui32,
				/*nicename("Ignores Shields")*/ _flags_ignores_shields = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
			};

			struct nicename("Instant Responses") s_instant_responses_definition
			{
				enum nicename("Response Type") e_response_type : uint16_t
				{
					/*nicename("Recieves All Damage")*/ _response_type_recieves_all_damage = 1ui16,
					/*nicename("Recieves Area Effect Damage")*/ _response_type_recieves_area_effect_damage = 2ui16,
					/*nicename("Recieves Local Damage")*/ _response_type_recieves_local_damage = 3ui16,
				};

				enum nicename("Constraint Damage Type") e_constraint_damage_type : uint16_t
				{
					/*nicename("None")*/ _constraint_damage_type_none = 1ui16,
					/*nicename("Destroy One of Group")*/ _constraint_damage_type_destroy_one_of_group = 2ui16,
					/*nicename("Destroy Entire Group")*/ _constraint_damage_type_destroy_entire_group = 3ui16,
					/*nicename("Loosen One of Group")*/ _constraint_damage_type_loosen_one_of_group = 4ui16,
					/*nicename("Loosen Entire Group")*/ _constraint_damage_type_loosen_entire_group = 5ui16,
				};

				enum nicename("New State") e_new_state : uint16_t
				{
					/*nicename("Default")*/ _new_state_default = 1ui16,
					/*nicename("Minor Damage")*/ _new_state_minor_damage = 2ui16,
					/*nicename("Medium Damage")*/ _new_state_medium_damage = 3ui16,
					/*nicename("Major Damage")*/ _new_state_major_damage = 4ui16,
					/*nicename("Destroyed")*/ _new_state_destroyed = 5ui16,
				};

				enum nicename("Secondary New State") e_secondary_new_state : uint16_t
				{
					/*nicename("Default")*/ _secondary_new_state_default = 1ui16,
					/*nicename("Minor Damage")*/ _secondary_new_state_minor_damage = 2ui16,
					/*nicename("Medium Damage")*/ _secondary_new_state_medium_damage = 3ui16,
					/*nicename("Major Damage")*/ _secondary_new_state_major_damage = 4ui16,
					/*nicename("Destroyed")*/ _secondary_new_state_destroyed = 5ui16,
				};

				enum nicename("Unknown Special Damage") e_unknown_special_damage : uint16_t
				{
					/*nicename("None")*/ _unknown_special_damage_none = 1ui16,
					/*nicename("1")*/ _unknown_special_damage__1 = 2ui16,
					/*nicename("2")*/ _unknown_special_damage__2 = 3ui16,
					/*nicename("3")*/ _unknown_special_damage__3 = 4ui16,
				};

				enum nicename("Flags") b_flags : uint32_t /* bitfield */
				{
					/*nicename("Kills Object")*/ _flags_kills_object = 1ui32 << 0ui32,
					/*nicename("Inhibits Melee Attack")*/ _flags_inhibits_melee_attack = 1ui32 << 1ui32,
					/*nicename("Inhibits Weapon Attack")*/ _flags_inhibits_weapon_attack = 1ui32 << 2ui32,
					/*nicename("Inhibits Walking")*/ _flags_inhibits_walking = 1ui32 << 3ui32,
					/*nicename("Forces Drop Weapon")*/ _flags_forces_drop_weapon = 1ui32 << 4ui32,
					/*nicename("Kills Weapon Primary Trigger")*/ _flags_kills_weapon_primary_trigger = 1ui32 << 5ui32,
					/*nicename("Kills Weapon Secondary Trigger")*/ _flags_kills_weapon_secondary_trigger = 1ui32 << 6ui32,
					/*nicename("Destroys Object")*/ _flags_destroys_object = 1ui32 << 7ui32,
					/*nicename("Damages Weapon Primary Trigger")*/ _flags_damages_weapon_primary_trigger = 1ui32 << 8ui32,
					/*nicename("Damages Weapon Secondary Trigger")*/ _flags_damages_weapon_secondary_trigger = 1ui32 << 9ui32,
					/*nicename("Light Damage Left Turn")*/ _flags_light_damage_left_turn = 1ui32 << 10ui32,
					/*nicename("Major Damage Left Turn")*/ _flags_major_damage_left_turn = 1ui32 << 11ui32,
					/*nicename("Light Damage Right Turn")*/ _flags_light_damage_right_turn = 1ui32 << 12ui32,
					/*nicename("Major Damage Right Turn")*/ _flags_major_damage_right_turn = 1ui32 << 13ui32,
					/*nicename("Light Damage Engine")*/ _flags_light_damage_engine = 1ui32 << 14ui32,
					/*nicename("Major Damage Engine")*/ _flags_major_damage_engine = 1ui32 << 15ui32,
					/*nicename("Kills Object (No Player Solo)")*/ _flags_kills_object_no_player_solo = 1ui32 << 16ui32,
					/*nicename("Causes Detonation")*/ _flags_causes_detonation = 1ui32 << 17ui32,
					/*nicename("Destroy All Group Constraints")*/ _flags_destroy_all_group_constraints = 1ui32 << 18ui32,
					/*nicename("Kills Variant Objects")*/ _flags_kills_variant_objects = 1ui32 << 19ui32,
					/*nicename("Force Unattached Effects")*/ _flags_force_unattached_effects = 1ui32 << 20ui32,
					/*nicename("Fires Under Threshold")*/ _flags_fires_under_threshold = 1ui32 << 21ui32,
					/*nicename("Triggers Special Death")*/ _flags_triggers_special_death = 1ui32 << 22ui32,
					/*nicename("Only On Special Death")*/ _flags_only_on_special_death = 1ui32 << 23ui32,
					/*nicename("Only NOT On Special Death")*/ _flags_only_not_on_special_death = 1ui32 << 24ui32,
					/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
					/*nicename("Causes Detonation In Single Player")*/ _flags_causes_detonation_in_single_player = 1ui32 << 26ui32,
					/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
					/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
					/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
					/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
					/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
				};

				e_response_type nicename("Response Type") response_type;
				e_constraint_damage_type nicename("Constraint Damage Type") constraint_damage_type;
				string_id nicename("Trigger") trigger;
				b_flags nicename("Flags") flags;
				float nicename("Damage Threshold") damage_threshold;
				int32_t __unknown0;
				float __unknown1;
				TagReference nicename("Primary Transition Effect") primary_transition_effect_reference;
				TagReference nicename("Secondary Transition Effect") secondary_transition_effect_reference;
				TagReference nicename("Transition Damage Effect") transition_damage_effect_reference;
				string_id nicename("Region") region;
				e_new_state nicename("New State") new_state;
				int16_t nicename("Runtime Region Index") runtime_region_index;
				string_id nicename("Secondary Region") secondary_region;
				e_secondary_new_state nicename("Secondary New State") secondary_new_state;
				int16_t nicename("Secondary Runtime Region Index") secondary_runtime_region_index;
				int16_t __unknown2;
				e_unknown_special_damage nicename("Unknown Special Damage") unknown_special_damage;
				string_id nicename("Special Damage Case") special_damage_case;
				string_id nicename("Effect Marker Name") effect_marker_name;
				string_id nicename("Damage Effect Marker Name") damage_effect_marker_name;
				float nicename("Response Delay") response_delay;
				TagReference nicename("Delay Effect") delay_effect_reference;
				string_id nicename("Delay Effect Marker Name") delay_effect_marker_name;
				string_id nicename("Ejecting Seat Label") ejecting_seat_label;
				float nicename("Skip Fraction") skip_fraction;
				string_id nicename("Destroyed Child Object Marker Name") destroyed_child_object_marker_name;
				float nicename("Total Damage Threshold") total_damage_threshold;
			};

			string_id nicename("Name") name;
			b_flags nicename("Flags") flags;
			float nicename("Vitality Percentage") vitality_percentage;
			s_tag_block_definition<s_instant_responses_definition> nicename("Instant Responses") instant_responses_block;
			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
			Undefined32 __unknown5;
			float nicename("Stun Time") stun_time;
			float nicename("Recharge Time") recharge_time;
			float __unknown6;
			string_id nicename("Resurrection Region Name") resurrection_region_name;
			int16_t nicename("Ressurection Region Runtime Index") ressurection_region_runtime_index;
			int16_t __unknown7;
		};

		struct nicename("Nodes") s_nodes_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			Undefined32 __unknown4;
		};

		struct nicename("Damage Seats") s_damage_seats_definition
		{
			struct nicename("Unknown") s_unknown1_definition
			{
				string_id nicename("Node") node;
				int16_t __unknown0;
				int16_t __unknown1;
				Undefined32 __unknown2;
				Undefined32 __unknown3;
				Undefined32 __unknown4;
				Undefined32 __unknown5;
				Undefined32 __unknown6;
				Undefined32 __unknown7;
				Undefined32 __unknown8;
				Undefined32 __unknown9;
				Undefined32 __unknown10;
			};

			string_id nicename("Seat Label") seat_label;
			float nicename("Direct Damage Scale") direct_damage_scale;
			float nicename("Damage Transfer Fall-Off Radius") damage_transfer_fall_off_radius;
			float nicename("Maximum Transfer Damage Scale") maximum_transfer_damage_scale;
			float nicename("Minimum Transfer-Damage Scale") minimum_transfer_damage_scale;
			s_tag_block_definition<s_unknown1_definition> __unknown0;
		};

		struct nicename("Damage Constraints") s_damage_constraints_definition
		{
			enum nicename("Type") e_type : uint16_t
			{
				/*nicename("Hinge")*/ _type_hinge = 1ui16,
				/*nicename("Limited Hinge")*/ _type_limited_hinge = 2ui16,
				/*nicename("Ragdoll")*/ _type_ragdoll = 3ui16,
				/*nicename("Stiff Spring")*/ _type_stiff_spring = 4ui16,
				/*nicename("Ball and Socket")*/ _type_ball_and_socket = 5ui16,
				/*nicename("Prismatic")*/ _type_prismatic = 6ui16,
			};

			string_id nicename("Physics Model Constraint Name") physics_model_constraint_name;
			string_id nicename("Damage Constraint Name") damage_constraint_name;
			string_id nicename("Damage Constraint Group Name") damage_constraint_group_name;
			float nicename("Group Probability Scale") group_probability_scale;
			e_type nicename("Type") type;
			int16_t nicename("Index") index;
		};

		b_flags nicename("Flags") flags;
		string_id nicename("Global Indirect Material") global_indirect_material;
		int16_t nicename("Indirect Damage Section") indirect_damage_section;
		int16_t __unknown0;
		Undefined32 __unknown1;
		e_collision_damage_reporting_type nicename("Collision Damage Reporting Type") collision_damage_reporting_type;
		e_response_damage_reporting_type nicename("Response Damage Reporting Type") response_damage_reporting_type;
		int16_t __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		float nicename("Maximum Vitality") maximum_vitality;
		float nicename("Minimum Stun Damage") minimum_stun_damage;
		float nicename("Stun Time") stun_time;
		float nicename("Recharge Time") recharge_time;
		float nicename("Recharge Fraction") recharge_fraction;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
		Undefined32 __unknown22;
		Undefined32 __unknown23;
		float nicename("Maximum Shield Vitality") maximum_shield_vitality;
		string_id nicename("Global Shield Material Name") global_shield_material_name;
		float nicename("Minimum Stun Damage") minimum_stun_damage1;
		float nicename("Stun Time") stun_time1;
		float nicename("Recharge Time") recharge_time1;
		Undefined32 __unknown24;
		Undefined32 __unknown25;
		Undefined32 __unknown26;
		TagReference nicename("Shield Damaged Effect") shield_damaged_effect_reference;
		TagReference nicename("Shield Depletion Effect") shield_depletion_effect_reference;
		TagReference nicename("Shield Recharge Effect") shield_recharge_effect_reference;
		s_tag_block_definition<s_damage_sections_definition> nicename("Damage Sections") damage_sections_block;
		s_tag_block_definition<s_nodes_definition> nicename("Nodes") nodes_block;
		int16_t nicename("Global Shield Material Index") global_shield_material_index;
		int16_t nicename("Global Indirect Material Index") global_indirect_material_index;
		float __unknown27;
		Undefined32 __unknown28;
		Undefined32 __unknown29;
		s_tag_block_definition<s_damage_seats_definition> nicename("Damage Seats") damage_seats_block;
		s_tag_block_definition<s_damage_constraints_definition> nicename("Damage Constraints") damage_constraints_block;
	};

	struct nicename("Omaha Damage Sections") s_omaha_damage_sections_definition
	{
		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Headshottable")*/ _flags1_headshottable = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Health Functions") s_health_functions_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Health Levels") s_health_levels_definition
		{
			float nicename("Percentage") percentage;
		};

		struct nicename("Omaha Instant Responses") s_omaha_instant_responses_definition
		{
			enum nicename("Unknown Special Damage") e_unknown_special_damage : uint16_t
			{
				/*nicename("None")*/ _unknown_special_damage_none = 1ui16,
				/*nicename("1")*/ _unknown_special_damage__1 = 2ui16,
				/*nicename("2")*/ _unknown_special_damage__2 = 3ui16,
				/*nicename("3")*/ _unknown_special_damage__3 = 4ui16,
			};

			enum nicename("Constraint Damage Type") e_constraint_damage_type : uint16_t
			{
				/*nicename("None")*/ _constraint_damage_type_none = 1ui16,
				/*nicename("Destroy One of Group")*/ _constraint_damage_type_destroy_one_of_group = 2ui16,
				/*nicename("Destroy Entire Group")*/ _constraint_damage_type_destroy_entire_group = 3ui16,
				/*nicename("Loosen One of Group")*/ _constraint_damage_type_loosen_one_of_group = 4ui16,
				/*nicename("Loosen Entire Group")*/ _constraint_damage_type_loosen_entire_group = 5ui16,
			};

			enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
			{
				/*nicename("Kills Object")*/ _flags1_kills_object = 1ui32 << 0ui32,
				/*nicename("Inhibits Melee Attack")*/ _flags1_inhibits_melee_attack = 1ui32 << 1ui32,
				/*nicename("Inhibits Weapon Attack")*/ _flags1_inhibits_weapon_attack = 1ui32 << 2ui32,
				/*nicename("Inhibits Walking")*/ _flags1_inhibits_walking = 1ui32 << 3ui32,
				/*nicename("Forces Drop Weapon")*/ _flags1_forces_drop_weapon = 1ui32 << 4ui32,
				/*nicename("Kills Weapon Primary Trigger")*/ _flags1_kills_weapon_primary_trigger = 1ui32 << 5ui32,
				/*nicename("Kills Weapon Secondary Trigger")*/ _flags1_kills_weapon_secondary_trigger = 1ui32 << 6ui32,
				/*nicename("Destroys Object")*/ _flags1_destroys_object = 1ui32 << 7ui32,
				/*nicename("Causes Detonation")*/ _flags1_causes_detonation = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
				/*nicename("Causes Detonation In Single Player")*/ _flags1_causes_detonation_in_single_player = 1ui32 << 19ui32,
				/*nicename("Silent Transition Effects")*/ _flags1_silent_transition_effects = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
			};

			struct nicename("Region State Changes") s_region_state_changes_definition
			{
				enum nicename("New State") e_new_state : uint16_t
				{
					/*nicename("Default")*/ _new_state_default = 1ui16,
					/*nicename("Minor Damage")*/ _new_state_minor_damage = 2ui16,
					/*nicename("Medium Damage")*/ _new_state_medium_damage = 3ui16,
					/*nicename("Major Damage")*/ _new_state_major_damage = 4ui16,
					/*nicename("Destroyed")*/ _new_state_destroyed = 5ui16,
				};

				string_id nicename("Region") region;
				e_new_state nicename("New State") new_state;
				int16_t nicename("Runtime Region Index") runtime_region_index;
			};

			struct nicename("Unknown") s_unknown2_definition
			{
				int32_t __unknown0;
				float __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				string_id nicename("Seat Label") seat_label;
			};

			struct nicename("Seat Ejaculation") s_seat_ejaculation_definition
			{
				string_id nicename("Ejecting Seat Label") ejecting_seat_label;
			};

			b_flags1 nicename("Flags") flags;
			string_id nicename("Trigger") trigger;
			float nicename("Damage Threshold") damage_threshold;
			TagReference nicename("Primary Transition Effect") primary_transition_effect_reference;
			string_id nicename("Primary Transition Effect Marker Name") primary_transition_effect_marker_name;
			TagReference nicename("Secondary Transition Effect") secondary_transition_effect_reference;
			string_id nicename("Secondary Transition Effect Marker Name") secondary_transition_effect_marker_name;
			TagReference nicename("Transition Damage Effect") transition_damage_effect_reference;
			string_id nicename("Transition Damage Effect Marker Name") transition_damage_effect_marker_name;
			TagReference nicename("Constant Effect") constant_effect_reference;
			s_tag_block_definition<s_region_state_changes_definition> nicename("Region State Changes") region_state_changes_block;
			s_tag_block_definition<s_unknown2_definition> __unknown0;
			int16_t __unknown1;
			e_unknown_special_damage nicename("Unknown Special Damage") unknown_special_damage;
			string_id nicename("Special Damage Case") special_damage_case;
			float nicename("Response Delay") response_delay;
			TagReference nicename("Delay Effect") delay_effect_reference;
			string_id nicename("Delay Effect Marker Name") delay_effect_marker_name;
			s_tag_block_definition<s_seat_ejaculation_definition> nicename("Seat Ejaculation") seat_ejaculation_block;
			float nicename("Skip Fraction") skip_fraction;
			string_id nicename("Destroyed Child Object Marker Name") destroyed_child_object_marker_name;
			float nicename("Total Damage Threshold") total_damage_threshold;
			string_id nicename("Constraint Group Name") constraint_group_name;
			e_constraint_damage_type nicename("Constraint Damage Type") constraint_damage_type;
			int16_t __unknown2;
		};

		struct nicename("Unknown") s_unknown3_definition
		{
			int32_t __unknown0;
			float __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
			string_id nicename("Seat Label") seat_label;
		};

		struct nicename("Unknown") s_unknown4_definition
		{
			int32_t __unknown0;
			float __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
			string_id nicename("Seat Label") seat_label;
		};

		struct nicename("Shield Impact") s_shield_impact_definition
		{
			TagReference nicename("Third Person") third_person_reference;
			TagReference nicename("First Person") first_person_reference;
		};

		string_id nicename("Name") name;
		b_flags1 nicename("Flags") flags;
		float nicename("Vitality Percentage") vitality_percentage;
		string_id nicename("Global Material") global_material;
		float nicename("Health Recharge Delay") health_recharge_delay;
		Undefined32 __unknown0;
		float __unknown1;
		s_tag_block_definition<s_health_functions_definition> nicename("Health Functions") health_functions_block;
		s_tag_block_definition<s_health_levels_definition> nicename("Health Levels") health_levels_block;
		TagReference nicename("Recharge Effect") recharge_effect_reference;
		float __unknown2;
		TagReference nicename("Precharge Effect") precharge_effect_reference;
		float __unknown3;
		TagReference __unknown4;
		float __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		float __unknown8;
		float __unknown9;
		Undefined32 __unknown10;
		s_tag_block_definition<s_omaha_instant_responses_definition> nicename("Omaha Instant Responses") omaha_instant_responses_block;
		s_tag_block_definition<s_unknown3_definition> __unknown11;
		s_tag_block_definition<s_unknown4_definition> __unknown12;
		s_tag_block_definition<s_shield_impact_definition> nicename("Shield Impact") shield_impact_block;
		float nicename("Recharge Time") recharge_time;
		string_id nicename("Resurrection Region Name") resurrection_region_name;
		int16_t nicename("Ressurection Region Runtime Index") ressurection_region_runtime_index;
		int16_t nicename("Global Material Index") global_material_index;
	};

	struct nicename("Omaha Damage Constraints") s_omaha_damage_constraints_definition
	{
		enum nicename("Type") e_type : uint16_t
		{
			/*nicename("Hinge")*/ _type_hinge = 1ui16,
			/*nicename("Limited Hinge")*/ _type_limited_hinge = 2ui16,
			/*nicename("Ragdoll")*/ _type_ragdoll = 3ui16,
			/*nicename("Stiff Spring")*/ _type_stiff_spring = 4ui16,
			/*nicename("Ball and Socket")*/ _type_ball_and_socket = 5ui16,
			/*nicename("Prismatic")*/ _type_prismatic = 6ui16,
		};

		string_id nicename("Physics Model Constraint Name") physics_model_constraint_name;
		string_id nicename("Damage Constraint Name") damage_constraint_name;
		string_id nicename("Damage Constraint Group Name") damage_constraint_group_name;
		float nicename("Group Probability Scale") group_probability_scale;
		e_type nicename("Type") type;
		int16_t nicename("Index") index;
	};

	struct nicename("Omaha Nodes") s_omaha_nodes_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
	};

	struct nicename("Targets") s_targets_definition
	{
		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Locked By Human Tracking")*/ _flags1_locked_by_human_tracking = 1ui32 << 0ui32,
			/*nicename("Locked By Plasma Tracking")*/ _flags1_locked_by_plasma_tracking = 1ui32 << 1ui32,
			/*nicename("Headshot")*/ _flags1_headshot = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Vulnerable")*/ _flags1_vulnerable = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Always Locked By Plasma Tracking")*/ _flags1_always_locked_by_plasma_tracking = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		string_id nicename("Marker Name") marker_name;
		float nicename("Size") size;
		float nicename("Cone Angle") cone_angle;
		int16_t nicename("Damage Section") damage_section;
		int16_t nicename("Variant") variant;
		float nicename("Targeting Relevance") targeting_relevance;
		Undefined32 __unknown0;
		b_flags1 nicename("Flags") flags;
		float nicename("Lock-On Distance") lock_on_distance;
		string_id nicename("Target Filter") target_filter;
	};

	struct nicename("Omaha Targets") s_omaha_targets_definition
	{
		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Locked By Human Tracking")*/ _flags1_locked_by_human_tracking = 1ui32 << 0ui32,
			/*nicename("Locked By Plasma Tracking")*/ _flags1_locked_by_plasma_tracking = 1ui32 << 1ui32,
			/*nicename("Headshot")*/ _flags1_headshot = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Vulnerable")*/ _flags1_vulnerable = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Always Locked By Plasma Tracking")*/ _flags1_always_locked_by_plasma_tracking = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		string_id nicename("Marker Name") marker_name;
		float nicename("Size") size;
		float nicename("Cone Angle") cone_angle;
		int16_t nicename("Damage Section") damage_section;
		int16_t nicename("Variant") variant;
		float nicename("Targeting Relevance") targeting_relevance;
		Undefined32 __unknown4;
		b_flags1 nicename("Flags") flags;
		float nicename("Lock-On Distance") lock_on_distance;
		string_id nicename("Target Filter") target_filter;
	};

	struct nicename("Collision Regions") s_collision_regions_definition
	{
		struct nicename("Permutations") s_permutations_definition
		{
			enum nicename("Flags") b_flags1 : uint8_t /* bitfield */
			{
				/*nicename("Cannot Be Chosen Randomly")*/ _flags1_cannot_be_chosen_randomly = 1ui8 << 0ui8,
				/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui8 << 1ui8,
				/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui8 << 2ui8,
				/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui8 << 3ui8,
				/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui8 << 4ui8,
				/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui8 << 5ui8,
				/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui8 << 6ui8,
				/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui8 << 7ui8,
			};

			string_id nicename("Name") name;
			b_flags1 nicename("Flags") flags;
			int8_t nicename("Collision Permutation Index") collision_permutation_index;
			int8_t nicename("Physics Permutation Index") physics_permutation_index;
			int8_t __unknown0;
		};

		string_id nicename("Name") name;
		int8_t nicename("Collision Region Index") collision_region_index;
		int8_t nicename("Physics Region Index") physics_region_index;
		int8_t __unknown0;
		int8_t __unknown1;
		s_tag_block_definition<s_permutations_definition> nicename("Permutations") permutations_block;
	};

	struct nicename("Nodes") s_nodes1_definition
	{
		string_id nicename("Name") name;
		int16_t nicename("Parent Node") parent_node;
		int16_t nicename("First Child Node") first_child_node;
		int16_t nicename("Next Sibling Node") next_sibling_node;
		int16_t nicename("Import Node Index") import_node_index;
		float nicename("Default Translation x") default_translation_x;
		float nicename("Default Translation y") default_translation_y;
		float nicename("Default Translation z") default_translation_z;
		float nicename("Default Rotation i") default_rotation_i;
		float nicename("Default Rotation j") default_rotation_j;
		float nicename("Default Rotation k") default_rotation_k;
		float nicename("Default Rotation w") default_rotation_w;
		float nicename("Default Scale") default_scale;
		float nicename("Inverse Forward i") inverse_forward_i;
		float nicename("Inverse Forward j") inverse_forward_j;
		float nicename("Inverse Forward k") inverse_forward_k;
		float nicename("Inverse Left i") inverse_left_i;
		float nicename("Inverse Left j") inverse_left_j;
		float nicename("Inverse Left k") inverse_left_k;
		float nicename("Inverse Up i") inverse_up_i;
		float nicename("Inverse Up j") inverse_up_j;
		float nicename("Inverse Up k") inverse_up_k;
		float nicename("Inverse Position x") inverse_position_x;
		float nicename("Inverse Position y") inverse_position_y;
		float nicename("Inverse Position z") inverse_position_z;
	};

	struct nicename("Unknown 12") s_unknown_12_definition
	{
		string_id nicename("Region") region;
		string_id nicename("Permutation") permutation;
	};

	struct nicename("Unknown 13") s_unknown_13_definition
	{
		string_id __unknown0;
		int32_t __unknown1;
	};

	struct nicename("Unknown 14") s_unknown_14_definition
	{
		string_id nicename("Marker") marker;
		Undefined32 __unknown0;
		string_id nicename("Marker") marker1;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
	};

	TagReference nicename("Model") model_reference;
	TagReference nicename("Collision Model") collision_model_reference;
	TagReference nicename("Animation") animation_reference;
	TagReference nicename("Physics Model") physics_model_reference;
	TagReference nicename("Imposter Model") imposter_model_reference;
	int32_t nicename("Model Checksum") model_checksum;
	int32_t nicename("Collision Model Checksum") collision_model_checksum;
	float nicename("Reduce To L1 (super low)") reduce_to_l1_super_low;
	float nicename("Reduce To L2 (low)") reduce_to_l2_low;
	float nicename("Reduce To L3 (medium)") reduce_to_l3_medium;
	float nicename("Reduce To L4 (high)") reduce_to_l4_high;
	float nicename("Reduce To L5 (super high)") reduce_to_l5_super_high;
	int16_t __unknown0;
	int16_t __unknown1;
	float nicename("Decal Reduce To L1 (super low)") decal_reduce_to_l1_super_low;
	float nicename("Decal Reduce To L2 (low)") decal_reduce_to_l2_low;
	float nicename("Decal Reduce To L3 (medium)") decal_reduce_to_l3_medium;
	float nicename("Decal Reduce To L4 (high)") decal_reduce_to_l4_high;
	float nicename("Decal Reduce To L5 (super high)") decal_reduce_to_l5_super_high;
	s_tag_block_definition<s_variants_definition> nicename("Variants") variants_block;
	s_tag_block_definition<s_unknown_definition> __unknown2;
	s_tag_block_definition<s_instance_groups_definition> nicename("Instance Groups") instance_groups_block;
	s_tag_block_definition<s_materials_definition> nicename("Materials") materials_block;
	s_tag_block_definition<s_omaha_materials_definition> nicename("Omaha Materials") omaha_materials_block;
	s_tag_block_definition<s_new_damage_info_definition> nicename("New Damage Info") new_damage_info_block;
	// Omaha Damage Info : "New Damage Info" above is obsolete, all the good stuff is gonna be under here.
	b_flags nicename("Flags") flags;
	float nicename("Base Vitality") base_vitality;
	string_id nicename("Base Global Material") base_global_material;
	int16_t __unknown3;
	int16_t __unknown4;
	e_collision_damage_reporting_type nicename("Collision Damage Reporting Type") collision_damage_reporting_type;
	e_response_damage_reporting_type nicename("Response Damage Reporting Type") response_damage_reporting_type;
	int16_t __unknown5;
	s_tag_block_definition<s_omaha_damage_sections_definition> nicename("Omaha Damage Sections") omaha_damage_sections_block;
	s_tag_block_definition<s_omaha_damage_constraints_definition> nicename("Omaha Damage Constraints") omaha_damage_constraints_block;
	s_tag_block_definition<s_omaha_nodes_definition> nicename("Omaha Nodes") omaha_nodes_block;
	int16_t nicename("Base Global Materal Index") base_global_materal_index;
	int16_t __unknown6;
	s_tag_block_definition<s_targets_definition> nicename("Targets") targets_block;
	s_tag_block_definition<s_omaha_targets_definition> nicename("Omaha Targets") omaha_targets_block;
	s_tag_block_definition<s_collision_regions_definition> nicename("Collision Regions") collision_regions_block;
	s_tag_block_definition<s_nodes1_definition> nicename("Nodes") nodes_block;
	Undefined32 __unknown7;
	TagReference nicename("Primary Dialogue") primary_dialogue_reference;
	TagReference nicename("Secondary Dialogue") secondary_dialogue_reference;
	b_flags1 nicename("Flags") flags1;
	string_id nicename("Default Dialogue Effect") default_dialogue_effect;
	b_render_only_node_flags_1 nicename("Render-Only Node Flags 1") render_only_node_flags_1;
	b_render_only_node_flags_2 nicename("Render-Only Node Flags 2") render_only_node_flags_2;
	b_render_only_node_flags_3 nicename("Render-Only Node Flags 3") render_only_node_flags_3;
	b_render_only_node_flags_4 nicename("Render-Only Node Flags 4") render_only_node_flags_4;
	b_render_only_node_flags_5 nicename("Render-Only Node Flags 5") render_only_node_flags_5;
	b_render_only_node_flags_6 nicename("Render-Only Node Flags 6") render_only_node_flags_6;
	b_render_only_node_flags_7 nicename("Render-Only Node Flags 7") render_only_node_flags_7;
	b_render_only_node_flags_8 nicename("Render-Only Node Flags 8") render_only_node_flags_8;
	b_render_only_section_flags_1 nicename("Render-Only Section Flags 1") render_only_section_flags_1;
	b_render_only_section_flags_2 nicename("Render-Only Section Flags 2") render_only_section_flags_2;
	b_render_only_section_flags_3 nicename("Render-Only Section Flags 3") render_only_section_flags_3;
	b_render_only_section_flags_4 nicename("Render-Only Section Flags 4") render_only_section_flags_4;
	b_render_only_section_flags_5 nicename("Render-Only Section Flags 5") render_only_section_flags_5;
	b_render_only_section_flags_6 nicename("Render-Only Section Flags 6") render_only_section_flags_6;
	b_render_only_section_flags_7 nicename("Render-Only Section Flags 7") render_only_section_flags_7;
	b_render_only_section_flags_8 nicename("Render-Only Section Flags 8") render_only_section_flags_8;
	b_runtime_flags nicename("Runtime Flags") runtime_flags;
	Undefined32 nicename("Scenario Load Parameters Block") scenario_load_parameters_block;
	Undefined32 nicename("Scenario Load Parameters Block") scenario_load_parameters_block1;
	Undefined32 nicename("Scenario Load Parameters Block") scenario_load_parameters_block2;
	Undefined32 __unknown8;
	float __unknown9;
	float __unknown10;
	float __unknown11;
	float __unknown12;
	int16_t __unknown13;
	int16_t __unknown14;
	s_tag_block_definition<s_unknown_12_definition> nicename("Unknown 12") unknown_12_block;
	s_tag_block_definition<s_unknown_13_definition> nicename("Unknown 13") unknown_13_block;
	s_tag_block_definition<s_unknown_14_definition> nicename("Unknown 14") unknown_14_block;
	TagReference nicename("Shield Impact Third Person") shield_impact_third_person_reference;
	TagReference nicename("Shield Impact First Person") shield_impact_first_person_reference;
	// Model Object Data : 
	float nicename("Radius") radius;
	float nicename("Offset X") offset_x;
	float nicename("Offset Y") offset_y;
	float nicename("Offset Z") offset_z;
};

