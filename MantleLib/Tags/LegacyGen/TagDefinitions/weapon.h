#pragma once

struct nicename("weapon") tag_group('weap') s_weapon_definition
{
	enum nicename("Object Type") e_object_type : uint16_t
	{
		/*nicename("Biped")*/ _object_type_biped = 1ui16,
		/*nicename("Vehicle")*/ _object_type_vehicle = 2ui16,
		/*nicename("Weapon")*/ _object_type_weapon = 3ui16,
		/*nicename("Equipment")*/ _object_type_equipment = 4ui16,
		/*nicename("Terminal")*/ _object_type_terminal = 5ui16,
		/*nicename("Projectile")*/ _object_type_projectile = 6ui16,
		/*nicename("Scenery")*/ _object_type_scenery = 7ui16,
		/*nicename("Machine")*/ _object_type_machine = 8ui16,
		/*nicename("Control")*/ _object_type_control = 9ui16,
		/*nicename("Sound Scenery")*/ _object_type_sound_scenery = 10ui16,
		/*nicename("Crate")*/ _object_type_crate = 11ui16,
		/*nicename("Creature")*/ _object_type_creature = 12ui16,
		/*nicename("Giant")*/ _object_type_giant = 13ui16,
		/*nicename("Effect Scenery")*/ _object_type_effect_scenery = 14ui16,
	};

	enum nicename("Lightmap Shadow Mode Size") e_lightmap_shadow_mode_size : uint16_t
	{
		/*nicename("Default")*/ _lightmap_shadow_mode_size_default = 1ui16,
		/*nicename("Never")*/ _lightmap_shadow_mode_size_never = 2ui16,
		/*nicename("Always")*/ _lightmap_shadow_mode_size_always = 3ui16,
		/*nicename("Unknown")*/ _lightmap_shadow_mode_size_unknown = 4ui16,
	};

	enum nicename("Sweetener Size") e_sweetener_size : uint8_t
	{
		/*nicename("Small")*/ _sweetener_size_small = 1ui8,
		/*nicename("Medium")*/ _sweetener_size_medium = 2ui8,
		/*nicename("Large")*/ _sweetener_size_large = 3ui8,
	};

	enum nicename("Water Density") e_water_density : uint8_t
	{
		/*nicename("Default")*/ _water_density_default = 1ui8,
		/*nicename("Least")*/ _water_density_least = 2ui8,
		/*nicename("Some")*/ _water_density_some = 3ui8,
		/*nicename("Equal")*/ _water_density_equal = 4ui8,
		/*nicename("More")*/ _water_density_more = 5ui8,
		/*nicename("More Still")*/ _water_density_more_still = 6ui8,
		/*nicename("Lots More")*/ _water_density_lots_more = 7ui8,
	};

	enum nicename("Secondary Trigger Mode") e_secondary_trigger_mode : uint16_t
	{
		/*nicename("Normal")*/ _secondary_trigger_mode_normal = 1ui16,
		/*nicename("Slaved To Primary")*/ _secondary_trigger_mode_slaved_to_primary = 2ui16,
		/*nicename("Inhibits Primary")*/ _secondary_trigger_mode_inhibits_primary = 3ui16,
		/*nicename("Loads Alternate Ammunition")*/ _secondary_trigger_mode_loads_alternate_ammunition = 4ui16,
		/*nicename("Loads Multiple Primary Ammunition")*/ _secondary_trigger_mode_loads_multiple_primary_ammunition = 5ui16,
	};

	enum nicename("Melee Damage Reporting Type") e_melee_damage_reporting_type : uint8_t
	{
		/*nicename("Guardians (Unknown)")*/ _melee_damage_reporting_type_guardians_unknown = 1ui8,
		/*nicename("Guardians")*/ _melee_damage_reporting_type_guardians = 2ui8,
		/*nicename("Guardians (Scripting)")*/ _melee_damage_reporting_type_guardians_scripting = 3ui8,
		/*nicename("Suicide")*/ _melee_damage_reporting_type_suicide = 4ui8,
		/*nicename("Magnum")*/ _melee_damage_reporting_type_magnum = 5ui8,
		/*nicename("Assault Rifle")*/ _melee_damage_reporting_type_assault_rifle = 6ui8,
		/*nicename("DMR")*/ _melee_damage_reporting_type_dmr = 7ui8,
		/*nicename("Shotgun")*/ _melee_damage_reporting_type_shotgun = 8ui8,
		/*nicename("Sniper Rifle")*/ _melee_damage_reporting_type_sniper_rifle = 9ui8,
		/*nicename("Rocket Launcher")*/ _melee_damage_reporting_type_rocket_launcher = 10ui8,
		/*nicename("Spartan Laser")*/ _melee_damage_reporting_type_spartan_laser = 11ui8,
		/*nicename("Frag Grenade")*/ _melee_damage_reporting_type_frag_grenade = 12ui8,
		/*nicename("Grenade Launcher")*/ _melee_damage_reporting_type_grenade_launcher = 13ui8,
		/*nicename("Plasma Pistol")*/ _melee_damage_reporting_type_plasma_pistol = 14ui8,
		/*nicename("Needler")*/ _melee_damage_reporting_type_needler = 15ui8,
		/*nicename("Plasma Rifle")*/ _melee_damage_reporting_type_plasma_rifle = 16ui8,
		/*nicename("Plasma Repeater")*/ _melee_damage_reporting_type_plasma_repeater = 17ui8,
		/*nicename("Needle Rifle")*/ _melee_damage_reporting_type_needle_rifle = 18ui8,
		/*nicename("Spiker")*/ _melee_damage_reporting_type_spiker = 19ui8,
		/*nicename("Plasma Launcher")*/ _melee_damage_reporting_type_plasma_launcher = 20ui8,
		/*nicename("Gravity Hammer")*/ _melee_damage_reporting_type_gravity_hammer = 21ui8,
		/*nicename("Energy Sword")*/ _melee_damage_reporting_type_energy_sword = 22ui8,
		/*nicename("Plasma Grenade")*/ _melee_damage_reporting_type_plasma_grenade = 23ui8,
		/*nicename("Concussion Rifle")*/ _melee_damage_reporting_type_concussion_rifle = 24ui8,
		/*nicename("Ghost")*/ _melee_damage_reporting_type_ghost = 25ui8,
		/*nicename("Revenant")*/ _melee_damage_reporting_type_revenant = 26ui8,
		/*nicename("Revenant Gunner")*/ _melee_damage_reporting_type_revenant_gunner = 27ui8,
		/*nicename("Wraith")*/ _melee_damage_reporting_type_wraith = 28ui8,
		/*nicename("Wraith Turret")*/ _melee_damage_reporting_type_wraith_turret = 29ui8,
		/*nicename("Banshee")*/ _melee_damage_reporting_type_banshee = 30ui8,
		/*nicename("Banshee Bomb")*/ _melee_damage_reporting_type_banshee_bomb = 31ui8,
		/*nicename("Seraph")*/ _melee_damage_reporting_type_seraph = 32ui8,
		/*nicename("Mongoose")*/ _melee_damage_reporting_type_mongoose = 33ui8,
		/*nicename("Warthog")*/ _melee_damage_reporting_type_warthog = 34ui8,
		/*nicename("Warthog Chaingun")*/ _melee_damage_reporting_type_warthog_chaingun = 35ui8,
		/*nicename("Warthog Gauss")*/ _melee_damage_reporting_type_warthog_gauss = 36ui8,
		/*nicename("Warthog Rocket")*/ _melee_damage_reporting_type_warthog_rocket = 37ui8,
		/*nicename("Scorpion")*/ _melee_damage_reporting_type_scorpion = 38ui8,
		/*nicename("Scorpion Turret")*/ _melee_damage_reporting_type_scorpion_turret = 39ui8,
		/*nicename("Falcon")*/ _melee_damage_reporting_type_falcon = 40ui8,
		/*nicename("Falcon Gunner")*/ _melee_damage_reporting_type_falcon_gunner = 41ui8,
		/*nicename("Falling")*/ _melee_damage_reporting_type_falling = 42ui8,
		/*nicename("Collision")*/ _melee_damage_reporting_type_collision = 43ui8,
		/*nicename("Melee")*/ _melee_damage_reporting_type_melee = 44ui8,
		/*nicename("Explosion")*/ _melee_damage_reporting_type_explosion = 45ui8,
		/*nicename("Birthday Explosion")*/ _melee_damage_reporting_type_birthday_explosion = 46ui8,
		/*nicename("Flag")*/ _melee_damage_reporting_type_flag = 47ui8,
		/*nicename("Bomb")*/ _melee_damage_reporting_type_bomb = 48ui8,
		/*nicename("Bomb Explosion")*/ _melee_damage_reporting_type_bomb_explosion = 49ui8,
		/*nicename("Ball")*/ _melee_damage_reporting_type_ball = 50ui8,
		/*nicename("Teleporter")*/ _melee_damage_reporting_type_teleporter = 51ui8,
		/*nicename("Transfer Damage")*/ _melee_damage_reporting_type_transfer_damage = 52ui8,
		/*nicename("Armor Lock")*/ _melee_damage_reporting_type_armor_lock = 53ui8,
		/*nicename("Target Locator")*/ _melee_damage_reporting_type_target_locator = 54ui8,
		/*nicename("Human Turret")*/ _melee_damage_reporting_type_human_turret = 55ui8,
		/*nicename("Plasma Cannon")*/ _melee_damage_reporting_type_plasma_cannon = 56ui8,
		/*nicename("Plasma Mortar")*/ _melee_damage_reporting_type_plasma_mortar = 57ui8,
		/*nicename("Plasma Turret")*/ _melee_damage_reporting_type_plasma_turret = 58ui8,
		/*nicename("Shade Turret")*/ _melee_damage_reporting_type_shade_turret = 59ui8,
		/*nicename("Sabre")*/ _melee_damage_reporting_type_sabre = 60ui8,
		/*nicename("SMG")*/ _melee_damage_reporting_type_smg = 61ui8,
		/*nicename("Carbine")*/ _melee_damage_reporting_type_carbine = 62ui8,
		/*nicename("Battle Rifle")*/ _melee_damage_reporting_type_battle_rifle = 63ui8,
		/*nicename("Focus Rifle")*/ _melee_damage_reporting_type_focus_rifle = 64ui8,
		/*nicename("Fuel Rod")*/ _melee_damage_reporting_type_fuel_rod = 65ui8,
		/*nicename("Missile Pod")*/ _melee_damage_reporting_type_missile_pod = 66ui8,
		/*nicename("Brute Shot")*/ _melee_damage_reporting_type_brute_shot = 67ui8,
		/*nicename("Flamethrower")*/ _melee_damage_reporting_type_flamethrower = 68ui8,
		/*nicename("Sentinel Gun")*/ _melee_damage_reporting_type_sentinel_gun = 69ui8,
		/*nicename("Spike Grenade")*/ _melee_damage_reporting_type_spike_grenade = 70ui8,
		/*nicename("Firebomb Grenade")*/ _melee_damage_reporting_type_firebomb_grenade = 71ui8,
		/*nicename("Elephant Turret")*/ _melee_damage_reporting_type_elephant_turret = 72ui8,
		/*nicename("Spectre")*/ _melee_damage_reporting_type_spectre = 73ui8,
		/*nicename("Spectre Gunner")*/ _melee_damage_reporting_type_spectre_gunner = 74ui8,
		/*nicename("Tank")*/ _melee_damage_reporting_type_tank = 75ui8,
		/*nicename("Chopper")*/ _melee_damage_reporting_type_chopper = 76ui8,
		/*nicename("Falcon")*/ _melee_damage_reporting_type_falcon1 = 77ui8,
		/*nicename("Mantis")*/ _melee_damage_reporting_type_mantis = 78ui8,
		/*nicename("Prowler")*/ _melee_damage_reporting_type_prowler = 79ui8,
		/*nicename("Sentinel Beam")*/ _melee_damage_reporting_type_sentinel_beam = 80ui8,
		/*nicename("Sentinel RPG")*/ _melee_damage_reporting_type_sentinel_rpg = 81ui8,
		/*nicename("Tripmine")*/ _melee_damage_reporting_type_tripmine = 82ui8,
	};

	enum nicename("Movement Penalized") e_movement_penalized : uint16_t
	{
		/*nicename("Always")*/ _movement_penalized_always = 1ui16,
		/*nicename("When Zoomed")*/ _movement_penalized_when_zoomed = 2ui16,
		/*nicename("When Zoomed or Reloading")*/ _movement_penalized_when_zoomed_or_reloading = 3ui16,
	};

	enum nicename("Weapon Type") e_weapon_type : uint16_t
	{
		/*nicename("Undefined")*/ _weapon_type_undefined = 1ui16,
		/*nicename("Shotgun")*/ _weapon_type_shotgun = 2ui16,
		/*nicename("Needler")*/ _weapon_type_needler = 3ui16,
		/*nicename("Plasma Pistol")*/ _weapon_type_plasma_pistol = 4ui16,
		/*nicename("Plasma Rifle")*/ _weapon_type_plasma_rifle = 5ui16,
		/*nicename("Rocket Launcher")*/ _weapon_type_rocket_launcher = 6ui16,
		/*nicename("Energy Sword")*/ _weapon_type_energy_sword = 7ui16,
		/*nicename("Spartan Laser")*/ _weapon_type_spartan_laser = 8ui16,
		/*nicename("Jackal Shield")*/ _weapon_type_jackal_shield = 9ui16,
		/*nicename("Fuel Rod")*/ _weapon_type_fuel_rod = 10ui16,
		/*nicename("Plasma Launcher")*/ _weapon_type_plasma_launcher = 11ui16,
	};

	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Does Not Cast Shadow")*/ _flags_does_not_cast_shadow = 1ui32 << 0ui32,
		/*nicename("Search Cardinal Direction Lightmaps on Failure")*/ _flags_search_cardinal_direction_lightmaps_on_failure = 1ui32 << 1ui32,
		/*nicename("Preserves Initial Damage Owner")*/ _flags_preserves_initial_damage_owner = 1ui32 << 2ui32,
		/*nicename("Not A Pathfinding Obstacle")*/ _flags_not_a_pathfinding_obstacle = 1ui32 << 3ui32,
		/*nicename("Extension Of Parent")*/ _flags_extension_of_parent = 1ui32 << 4ui32,
		/*nicename("Does Not Cause Collision Damage")*/ _flags_does_not_cause_collision_damage = 1ui32 << 5ui32,
		/*nicename("Early Mover")*/ _flags_early_mover = 1ui32 << 6ui32,
		/*nicename("Early Mover Localized Physics")*/ _flags_early_mover_localized_physics = 1ui32 << 7ui32,
		/*nicename("Use Static Massive Lightmap Sample")*/ _flags_use_static_massive_lightmap_sample = 1ui32 << 8ui32,
		/*nicename("Object Scales Attachments")*/ _flags_object_scales_attachments = 1ui32 << 9ui32,
		/*nicename("Inherits Player's Appearance")*/ _flags_inherits_players_appearance = 1ui32 << 10ui32,
		/*nicename("Non-Physical in Map Editor")*/ _flags_non_physical_in_map_editor = 1ui32 << 11ui32,
		/*nicename("Object Is Always On Ceiling")*/ _flags_object_is_always_on_ceiling = 1ui32 << 12ui32,
		/*nicename("Sample Environment Lighting Only Ignore Object Lighting")*/ _flags_sample_environment_lighting_only_ignore_object_lighting = 1ui32 << 13ui32,
		/*nicename("Effects Created By This Object Do Not Spawn Objects In Multiplayer")*/ _flags_effects_created_by_this_object_do_not_spawn_objects_in_multiplayer = 1ui32 << 14ui32,
		/*nicename("Does Not Collide With Camera")*/ _flags_does_not_collide_with_camera = 1ui32 << 15ui32,
		/*nicename("Force Collide With Camera")*/ _flags_force_collide_with_camera = 1ui32 << 16ui32,
		/*nicename("Damage Not Blocked By Obstructions")*/ _flags_damage_not_blocked_by_obstructions = 1ui32 << 17ui32,
		/*nicename("Does Not Damage Breakable Surfaces")*/ _flags_does_not_damage_breakable_surfaces = 1ui32 << 18ui32,
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
		/*nicename("Always Maintains Z Up")*/ _flags1_always_maintains_z_up = 1ui32 << 0ui32,
		/*nicename("Destroyed By Explosions")*/ _flags1_destroyed_by_explosions = 1ui32 << 1ui32,
		/*nicename("Unaffected By Gravity")*/ _flags1_unaffected_by_gravity = 1ui32 << 2ui32,
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

	enum nicename("Flags") b_flags2 : uint32_t /* bitfield */
	{
		/*nicename("Vertical Heat Display")*/ _flags2_vertical_heat_display = 1ui32 << 0ui32,
		/*nicename("Mutually Exclusive Triggers")*/ _flags2_mutually_exclusive_triggers = 1ui32 << 1ui32,
		/*nicename("Attacks Automatically On Bump")*/ _flags2_attacks_automatically_on_bump = 1ui32 << 2ui32,
		/*nicename("Must Be Readied")*/ _flags2_must_be_readied = 1ui32 << 3ui32,
		/*nicename("Doesn't Count Towards Maximum")*/ _flags2_doesnt_count_towards_maximum = 1ui32 << 4ui32,
		/*nicename("Aim Assists Only When Zoomed")*/ _flags2_aim_assists_only_when_zoomed = 1ui32 << 5ui32,
		/*nicename("Prevents Grenade Throwing")*/ _flags2_prevents_grenade_throwing = 1ui32 << 6ui32,
		/*nicename("Must Be Picked Up")*/ _flags2_must_be_picked_up = 1ui32 << 7ui32,
		/*nicename("Holds Triggers When Dropped")*/ _flags2_holds_triggers_when_dropped = 1ui32 << 8ui32,
		/*nicename("Prevents Melee Attack")*/ _flags2_prevents_melee_attack = 1ui32 << 9ui32,
		/*nicename("Detonates When Dropped")*/ _flags2_detonates_when_dropped = 1ui32 << 10ui32,
		/*nicename("Cannot Fire At Maximum Age")*/ _flags2_cannot_fire_at_maximum_age = 1ui32 << 11ui32,
		/*nicename("Secondary Trigger Overrides Grenades")*/ _flags2_secondary_trigger_overrides_grenades = 1ui32 << 12ui32,
		/*nicename("Does Not Depower Active Camo In Multiplayer")*/ _flags2_does_not_depower_active_camo_in_multiplayer = 1ui32 << 13ui32,
		/*nicename("Enables Integrated Night Vision")*/ _flags2_enables_integrated_night_vision = 1ui32 << 14ui32,
		/*nicename("AIs Use Weapon Melee Damage")*/ _flags2_ais_use_weapon_melee_damage = 1ui32 << 15ui32,
		/*nicename("Forces No Binoculars")*/ _flags2_forces_no_binoculars = 1ui32 << 16ui32,
		/*nicename("Loop FP Firing Animation")*/ _flags2_loop_fp_firing_animation = 1ui32 << 17ui32,
		/*nicename("Prevents Sprinting")*/ _flags2_prevents_sprinting = 1ui32 << 18ui32,
		/*nicename("Cannot Fire While Boosting")*/ _flags2_cannot_fire_while_boosting = 1ui32 << 19ui32,
		/*nicename("Prevents Driving")*/ _flags2_prevents_driving = 1ui32 << 20ui32,
		/*nicename("Third Person Camera")*/ _flags2_third_person_camera = 1ui32 << 21ui32,
		/*nicename("Can Be Dual Wielded")*/ _flags2_can_be_dual_wielded = 1ui32 << 22ui32,
		/*nicename("Can Only Be Dual Wielded")*/ _flags2_can_only_be_dual_wielded = 1ui32 << 23ui32,
		/*nicename("Melee Only")*/ _flags2_melee_only = 1ui32 << 24ui32,
		/*nicename("Can't Fire If Parent Dead")*/ _flags2_cant_fire_if_parent_dead = 1ui32 << 25ui32,
		/*nicename("Weapon Ages With Each Kill")*/ _flags2_weapon_ages_with_each_kill = 1ui32 << 26ui32,
		/*nicename("Weapon Uses Old Dual Fire Error Code")*/ _flags2_weapon_uses_old_dual_fire_error_code = 1ui32 << 27ui32,
		/*nicename("Primary Trigger Melee Attacks")*/ _flags2_primary_trigger_melee_attacks = 1ui32 << 28ui32,
		/*nicename("Cannot Be Used By Player")*/ _flags2_cannot_be_used_by_player = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags2_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags2_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("More Flags") b_more_flags : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _more_flags_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _more_flags_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _more_flags_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _more_flags_bit_3 = 1ui32 << 3ui32,
		/*nicename("Resets/No Swapping")*/ _more_flags_resets_no_swapping = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _more_flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _more_flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _more_flags_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _more_flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _more_flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _more_flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _more_flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _more_flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _more_flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _more_flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _more_flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _more_flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _more_flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _more_flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _more_flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _more_flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _more_flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _more_flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _more_flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _more_flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _more_flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _more_flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _more_flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _more_flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _more_flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _more_flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _more_flags_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Early Mover Properties") s_early_mover_properties_definition
	{
		string_id nicename("Name") name;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
	};

	struct nicename("AI Properties") s_ai_properties_definition
	{
		enum nicename("Size") e_size : uint16_t
		{
			/*nicename("Default")*/ _size_default = 1ui16,
			/*nicename("Tiny")*/ _size_tiny = 2ui16,
			/*nicename("Small")*/ _size_small = 3ui16,
			/*nicename("Medium")*/ _size_medium = 4ui16,
			/*nicename("Large")*/ _size_large = 5ui16,
			/*nicename("Huge")*/ _size_huge = 6ui16,
			/*nicename("Immobile")*/ _size_immobile = 7ui16,
		};

		enum nicename("Leap Jump Speed") e_leap_jump_speed : uint16_t
		{
			/*nicename("None")*/ _leap_jump_speed_none = 1ui16,
			/*nicename("Down")*/ _leap_jump_speed_down = 2ui16,
			/*nicename("Step")*/ _leap_jump_speed_step = 3ui16,
			/*nicename("Crouch")*/ _leap_jump_speed_crouch = 4ui16,
			/*nicename("Stand")*/ _leap_jump_speed_stand = 5ui16,
			/*nicename("Storey")*/ _leap_jump_speed_storey = 6ui16,
			/*nicename("Tower")*/ _leap_jump_speed_tower = 7ui16,
			/*nicename("Infinite")*/ _leap_jump_speed_infinite = 8ui16,
		};

		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Destroyable Cover")*/ _flags1_destroyable_cover = 1ui32 << 0ui32,
			/*nicename("Pathfinding Ignore When Dead")*/ _flags1_pathfinding_ignore_when_dead = 1ui32 << 1ui32,
			/*nicename("Dynamic Cover")*/ _flags1_dynamic_cover = 1ui32 << 2ui32,
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

		b_flags1 nicename("Flags") flags;
		string_id nicename("AI Type Name") ai_type_name;
		Undefined32 __unknown0;
		e_size nicename("Size") size;
		e_leap_jump_speed nicename("Leap Jump Speed") leap_jump_speed;
	};

	struct nicename("Functions") s_functions_definition
	{
		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Invert")*/ _flags1_invert = 1ui32 << 0ui32,
			/*nicename("Mapping Does Not Controls Active")*/ _flags1_mapping_does_not_controls_active = 1ui32 << 1ui32,
			/*nicename("Always Active")*/ _flags1_always_active = 1ui32 << 2ui32,
			/*nicename("Random Time Offset")*/ _flags1_random_time_offset = 1ui32 << 3ui32,
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

		struct nicename("Unknown") s_unknown_definition
		{
			int32_t __unknown0;
			float __unknown1;
			float __unknown2;
			Undefined32 __unknown3;
			float __unknown4;
			float __unknown5;
		};

		b_flags1 nicename("Flags") flags;
		string_id nicename("Import Name") import_name;
		string_id nicename("Export Name") export_name;
		string_id nicename("Turn Off With") turn_off_with;
		string_id __unknown0;
		float nicename("Minimum Value") minimum_value;
		DataReference nicename("Default Function") default_function_data_reference;
		string_id nicename("Scale By") scale_by;
		s_tag_block_definition<s_unknown_definition> __unknown1;
		int32_t nicename("'Function Related' Index") function_related_index;
	};

	struct nicename("Function Related") s_function_related_definition
	{
		int32_t nicename("Function Index") function_index;
	};

	struct nicename("Attachments") s_attachments_definition
	{
		enum nicename("Change Color") e_change_color : uint16_t
		{
			/*nicename("None")*/ _change_color_none = 1ui16,
			/*nicename("Primary")*/ _change_color_primary = 2ui16,
			/*nicename("Secondary")*/ _change_color_secondary = 3ui16,
			/*nicename("Tertiary")*/ _change_color_tertiary = 4ui16,
			/*nicename("Quaternary")*/ _change_color_quaternary = 5ui16,
		};

		TagReference nicename("Attachment") attachment_reference;
		string_id nicename("Marker") marker;
		e_change_color nicename("Change Color") change_color;
		int16_t __unknown0;
		string_id nicename("Primary Scale") primary_scale;
		string_id nicename("Secondary Scale") secondary_scale;
	};

	struct nicename("Material Responses") s_material_responses_definition
	{
		struct nicename("Unknown") s_unknown1_definition
		{
			string_id nicename("Material") material;
			DataReference __unknown0;
			float __unknown1;
			DataReference __unknown2;
			float __unknown3;
			Undefined32 __unknown4;
			Undefined32 __unknown5;
		};

		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		s_tag_block_definition<s_unknown1_definition> __unknown3;
	};

	struct nicename("Jet Wash") s_jet_wash_definition
	{
		string_id nicename("Marker") marker;
		float __unknown0;
		Undefined32 __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
	};

	struct nicename("Widgets") s_widgets_definition
	{
		TagReference nicename("Type") type_reference;
	};

	struct nicename("Change Color") s_change_color_definition
	{
		struct nicename("Initial Permutations") s_initial_permutations_definition
		{
			float nicename("Weight") weight;
			colorf nicename("Color Lower Bound") color_lower_bound;
			colorf nicename("Color Upper Bound") color_upper_bound;
			string_id nicename("Variant Name") variant_name;
		};

		struct nicename("Functions") s_functions1_definition
		{
			enum nicename("Scale Flags") b_scale_flags : uint32_t /* bitfield */
			{
				/*nicename("Blend In HSV")*/ _scale_flags_blend_in_hsv = 1ui32 << 0ui32,
				/*nicename("...More Colors")*/ _scale_flags_more_colors = 1ui32 << 1ui32,
				/*nicename("Bit 2")*/ _scale_flags_bit_2 = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _scale_flags_bit_3 = 1ui32 << 3ui32,
				/*nicename("Bit 4")*/ _scale_flags_bit_4 = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _scale_flags_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _scale_flags_bit_6 = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _scale_flags_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _scale_flags_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _scale_flags_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _scale_flags_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _scale_flags_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _scale_flags_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _scale_flags_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _scale_flags_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _scale_flags_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _scale_flags_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _scale_flags_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _scale_flags_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _scale_flags_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _scale_flags_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _scale_flags_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _scale_flags_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _scale_flags_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _scale_flags_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _scale_flags_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _scale_flags_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _scale_flags_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _scale_flags_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _scale_flags_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _scale_flags_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _scale_flags_bit_31 = 1ui32 << 31ui32,
			};

			b_scale_flags nicename("Scale Flags") scale_flags;
			colorf nicename("Color Lower Bound") color_lower_bound;
			colorf nicename("Color Upper Bound") color_upper_bound;
			string_id nicename("Darken By...") darken_by;
			string_id nicename("Scale By...") scale_by;
		};

		s_tag_block_definition<s_initial_permutations_definition> nicename("Initial Permutations") initial_permutations_block;
		s_tag_block_definition<s_functions1_definition> nicename("Functions") functions_block;
	};

	struct nicename("Predicted Resources") s_predicted_resources_definition
	{
		int16_t nicename("Type") type;
		int16_t nicename("Resource Index") resource_index;
		TagReference nicename("Tag Index") tag_index_reference;
	};

	struct nicename("Multiplayer Object Properties") s_multiplayer_object_properties_definition
	{
		enum nicename("Object Type") e_object_type1 : uint8_t
		{
			/*nicename("Ordinary")*/ _object_type1_ordinary = 1ui8,
			/*nicename("Weapon")*/ _object_type1_weapon = 2ui8,
			/*nicename("Grenade")*/ _object_type1_grenade = 3ui8,
			/*nicename("Projectile")*/ _object_type1_projectile = 4ui8,
			/*nicename("Powerup")*/ _object_type1_powerup = 5ui8,
			/*nicename("Equipment")*/ _object_type1_equipment = 6ui8,
			/*nicename("Ammo Pack")*/ _object_type1_ammo_pack = 7ui8,
			/*nicename("Light Land Vehicle")*/ _object_type1_light_land_vehicle = 8ui8,
			/*nicename("Heavy Land Vehicle")*/ _object_type1_heavy_land_vehicle = 9ui8,
			/*nicename("Flying Vehicle")*/ _object_type1_flying_vehicle = 10ui8,
			/*nicename("Turret")*/ _object_type1_turret = 11ui8,
			/*nicename("Device")*/ _object_type1_device = 12ui8,
			/*nicename("Teleporter 2Way")*/ _object_type1_teleporter_2way = 13ui8,
			/*nicename("Teleporter Sender")*/ _object_type1_teleporter_sender = 14ui8,
			/*nicename("Teleporter Receiver")*/ _object_type1_teleporter_receiver = 15ui8,
			/*nicename("Player Spawn Location")*/ _object_type1_player_spawn_location = 16ui8,
			/*nicename("Player Respawn Zone")*/ _object_type1_player_respawn_zone = 17ui8,
			/*nicename("Secondary Objective")*/ _object_type1_secondary_objective = 18ui8,
			/*nicename("Primary Objective")*/ _object_type1_primary_objective = 19ui8,
			/*nicename("Named Location Area")*/ _object_type1_named_location_area = 20ui8,
			/*nicename("Danger Zone")*/ _object_type1_danger_zone = 21ui8,
			/*nicename("Fireteam 1 Respawn Zone")*/ _object_type1_fireteam_1_respawn_zone = 22ui8,
			/*nicename("Fireteam 2 Respawn Zone")*/ _object_type1_fireteam_2_respawn_zone = 23ui8,
			/*nicename("Fireteam 3 Respawn Zone")*/ _object_type1_fireteam_3_respawn_zone = 24ui8,
			/*nicename("Fireteam 4 Respawn Zone")*/ _object_type1_fireteam_4_respawn_zone = 25ui8,
			/*nicename("Safe Volume")*/ _object_type1_safe_volume = 26ui8,
			/*nicename("Kill Volume")*/ _object_type1_kill_volume = 27ui8,
			/*nicename("Cinematic Camera Position")*/ _object_type1_cinematic_camera_position = 28ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 1ui8,
			/*nicename("Sphere")*/ _shape_sphere = 2ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 3ui8,
			/*nicename("Box")*/ _shape_box = 4ui8,
		};

		enum nicename("Spawn Timer Mode") e_spawn_timer_mode : uint8_t
		{
			/*nicename("On Death")*/ _spawn_timer_mode_on_death = 1ui8,
			/*nicename("On Disturbance")*/ _spawn_timer_mode_on_disturbance = 2ui8,
		};

		enum nicename("Teleporter Flags") b_teleporter_flags : uint8_t /* bitfield */
		{
			/*nicename("Disallows Players")*/ _teleporter_flags_disallows_players = 1ui8 << 0ui8,
			/*nicename("Allows Land Vehicles")*/ _teleporter_flags_allows_land_vehicles = 1ui8 << 1ui8,
			/*nicename("Allows Heavy Vehicles")*/ _teleporter_flags_allows_heavy_vehicles = 1ui8 << 2ui8,
			/*nicename("Allows Flying Vehicles")*/ _teleporter_flags_allows_flying_vehicles = 1ui8 << 3ui8,
			/*nicename("Allows Projectiles")*/ _teleporter_flags_allows_projectiles = 1ui8 << 4ui8,
		};

		enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
		{
			/*nicename("Editor Only")*/ _flags1_editor_only = 1ui16 << 0ui16,
			/*nicename("Phased Physics")*/ _flags1_phased_physics = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui16 << 5ui16,
			/*nicename("Soft Area Boundary")*/ _flags1_soft_area_boundary = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui16 << 15ui16,
		};

		int8_t __unknown0;
		e_object_type1 nicename("Object Type") object_type;
		b_teleporter_flags nicename("Teleporter Flags") teleporter_flags;
		int8_t __unknown1;
		float nicename("Radius/Width") radius_width;
		float nicename("Length") length;
		float nicename("Top") top;
		float nicename("Bottom") bottom;
		e_shape nicename("Shape") shape;
		e_spawn_timer_mode nicename("Spawn Timer Mode") spawn_timer_mode;
		int16_t nicename("Spawn Time") spawn_time;
		int16_t nicename("Abandon Time") abandon_time;
		b_flags1 nicename("Flags") flags;
		float __unknown2;
		int32_t __unknown3;
		int32_t __unknown4;
		TagReference nicename("Child Object") child_object_reference;
		int32_t __unknown5;
		TagReference nicename("Shape Shader") shape_shader_reference;
		TagReference nicename("Shader 2") shader_2_reference;
		TagReference __unknown6;
		TagReference __unknown7;
		TagReference nicename("Secondary Shader") secondary_shader_reference;
		TagReference __unknown8;
		TagReference __unknown9;
		TagReference __unknown10;
	};

	struct nicename("Unknown") s_unknown2_definition
	{
		TagReference __unknown0;
		TagReference __unknown1;
		TagReference __unknown2;
	};

	struct nicename("Predicted Bitmaps") s_predicted_bitmaps_definition
	{
		TagReference nicename("Bitmap") bitmap_reference;
	};

	struct nicename("Melee Damage") s_melee_damage_definition
	{
		float nicename("Damage Pyramid Angles y") damage_pyramid_angles_y;
		float nicename("Damage Pyramid Angles p") damage_pyramid_angles_p;
		float nicename("Damage Pyramid Depth") damage_pyramid_depth;
		float __unknown0;
		Undefined32 __unknown1;
		float __unknown2;
		TagReference nicename("1st Hit Damage") _1st_hit_damage_reference;
		TagReference nicename("1st Hit Response") _1st_hit_response_reference;
		TagReference nicename("2nd Hit Damage") _2nd_hit_damage_reference;
		TagReference nicename("2nd Hit Response") _2nd_hit_response_reference;
		TagReference nicename("3rd Hit Damage") _3rd_hit_damage_reference;
		TagReference nicename("3rd Hit Response") _3rd_hit_response_reference;
		TagReference nicename("Gun/Gun Clang Damage") gun_gun_clang_damage_reference;
		TagReference nicename("Gun/Gun Clang Response") gun_gun_clang_response_reference;
		TagReference nicename("Gun/Sword Clang Damage") gun_sword_clang_damage_reference;
		TagReference nicename("Gun/Sword Clang Response") gun_sword_clang_response_reference;
		TagReference nicename("Melee Effect") melee_effect_reference;
	};

	struct nicename("Target Tracking") s_target_tracking_definition
	{
		struct nicename("Tracking Types") s_tracking_types_definition
		{
			string_id nicename("Tracking Type") tracking_type;
		};

		s_tag_block_definition<s_tracking_types_definition> nicename("Tracking Types") tracking_types_block;
		float nicename("Acquire Time") acquire_time;
		float nicename("Grace Time") grace_time;
		float nicename("Decay Time") decay_time;
		TagReference nicename("Tracking Sound") tracking_sound_reference;
		TagReference nicename("Locked Sound") locked_sound_reference;
	};

	struct nicename("First Person") s_first_person_definition
	{
		TagReference nicename("First Person Model") first_person_model_reference;
		TagReference nicename("First Person Animations") first_person_animations_reference;
	};

	struct nicename("Predicted Resources") s_predicted_resources1_definition
	{
		int16_t nicename("Type") type;
		int16_t nicename("Resource Index") resource_index;
		TagReference nicename("Tag Index") tag_index_reference;
	};

	struct nicename("Magazines") s_magazines_definition
	{
		enum nicename("Flags") b_flags3 : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags3_bit_0 = 1ui32 << 0ui32,
			/*nicename("Wastes Rounds When Reloaded")*/ _flags3_wastes_rounds_when_reloaded = 1ui32 << 1ui32,
			/*nicename("Every Round Must Be Chambered")*/ _flags3_every_round_must_be_chambered = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags3_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags3_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags3_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags3_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags3_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags3_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags3_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags3_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags3_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags3_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags3_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags3_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags3_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags3_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags3_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags3_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags3_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags3_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags3_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags3_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags3_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags3_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags3_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags3_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags3_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags3_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags3_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags3_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags3_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Magazine Equipment") s_magazine_equipment_definition
		{
			int16_t nicename("Rounds (0 for Max)") rounds_0_for_max;
			int16_t __unknown0;
			TagReference nicename("Equipment") equipment_reference;
		};

		b_flags3 nicename("Flags") flags;
		int16_t nicename("Rounds Recharged") rounds_recharged;
		int16_t nicename("Rounds Total Initial") rounds_total_initial;
		int16_t nicename("Rounds Total Maximum") rounds_total_maximum;
		int16_t nicename("Rounds Total Loaded Maximum") rounds_total_loaded_maximum;
		int16_t nicename("Maximum Rounds Held") maximum_rounds_held;
		int16_t __unknown0;
		float nicename("Reload Time") reload_time;
		int16_t nicename("Rounds Reloaded") rounds_reloaded;
		int16_t __unknown1;
		float nicename("Chamber Time") chamber_time;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		TagReference nicename("Reloading Effect") reloading_effect_reference;
		TagReference nicename("Reloading Damage Effect") reloading_damage_effect_reference;
		TagReference nicename("Chambering Effect") chambering_effect_reference;
		TagReference nicename("Chambering Damage Effect") chambering_damage_effect_reference;
		s_tag_block_definition<s_magazine_equipment_definition> nicename("Magazine Equipment") magazine_equipment_block;
	};

	struct nicename("New Triggers") s_new_triggers_definition
	{
		enum nicename("Button Used") e_button_used : uint16_t
		{
			/*nicename("Right Trigger")*/ _button_used_right_trigger = 1ui16,
			/*nicename("Left Trigger")*/ _button_used_left_trigger = 2ui16,
			/*nicename("Melee Attack")*/ _button_used_melee_attack = 3ui16,
			/*nicename("Automated Fire")*/ _button_used_automated_fire = 4ui16,
			/*nicename("Right Bumper")*/ _button_used_right_bumper = 5ui16,
		};

		enum nicename("Behavior") e_behavior : uint16_t
		{
			/*nicename("Spew")*/ _behavior_spew = 1ui16,
			/*nicename("Latch")*/ _behavior_latch = 2ui16,
			/*nicename("Latch-Autofire")*/ _behavior_latch_autofire = 3ui16,
			/*nicename("Charge")*/ _behavior_charge = 4ui16,
			/*nicename("Latch-Zoom")*/ _behavior_latch_zoom = 5ui16,
			/*nicename("Latch-Rocketlauncher")*/ _behavior_latch_rocketlauncher = 6ui16,
			/*nicename("Spew-Charge")*/ _behavior_spew_charge = 7ui16,
			/*nicename("Charge-Melee")*/ _behavior_charge_melee = 8ui16,
		};

		enum nicename("Prediction") e_prediction : uint16_t
		{
			/*nicename("None")*/ _prediction_none = 1ui16,
			/*nicename("Spew")*/ _prediction_spew = 2ui16,
			/*nicename("Charge")*/ _prediction_charge = 3ui16,
		};

		enum nicename("Secondary Action") e_secondary_action : uint16_t
		{
			/*nicename("Fire")*/ _secondary_action_fire = 1ui16,
			/*nicename("Charge")*/ _secondary_action_charge = 2ui16,
			/*nicename("Track")*/ _secondary_action_track = 3ui16,
			/*nicename("Fire Other")*/ _secondary_action_fire_other = 4ui16,
		};

		enum nicename("Primary Action") e_primary_action : uint16_t
		{
			/*nicename("Fire")*/ _primary_action_fire = 1ui16,
			/*nicename("Charge")*/ _primary_action_charge = 2ui16,
			/*nicename("Track")*/ _primary_action_track = 3ui16,
			/*nicename("Fire Other")*/ _primary_action_fire_other = 4ui16,
		};

		enum nicename("Overcharge Action") e_overcharge_action : uint8_t
		{
			/*nicename("None")*/ _overcharge_action_none = 1ui8,
			/*nicename("Explode")*/ _overcharge_action_explode = 2ui8,
			/*nicename("Discharge")*/ _overcharge_action_discharge = 3ui8,
		};

		enum nicename("Charge Projectiles") e_charge_projectiles : uint8_t
		{
			/*nicename("Default")*/ _charge_projectiles_default = 1ui8,
			/*nicename("One For Every Charge Level")*/ _charge_projectiles_one_for_every_charge_level = 2ui8,
		};

		enum nicename("Flags") b_flags3 : uint32_t /* bitfield */
		{
			/*nicename("Autofire Single Action Only")*/ _flags3_autofire_single_action_only = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _flags3_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _flags3_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags3_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags3_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags3_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags3_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags3_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags3_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags3_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags3_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags3_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags3_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags3_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags3_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags3_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags3_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags3_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags3_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags3_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags3_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags3_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags3_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags3_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags3_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags3_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags3_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags3_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags3_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags3_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags3_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags3_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Charge Flags") b_charge_flags : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _charge_flags_bit_0 = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _charge_flags_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _charge_flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _charge_flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _charge_flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _charge_flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _charge_flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _charge_flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _charge_flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _charge_flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _charge_flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _charge_flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _charge_flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _charge_flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _charge_flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _charge_flags_bit_15 = 1ui16 << 15ui16,
		};

		struct nicename("Charge Levels") s_charge_levels_definition
		{
			float nicename("Percentage") percentage;
		};

		b_flags3 nicename("Flags") flags;
		e_button_used nicename("Button Used") button_used;
		e_behavior nicename("Behavior") behavior;
		int16_t nicename("Primary Barrel") primary_barrel;
		int16_t nicename("Secondary Barrel") secondary_barrel;
		e_prediction nicename("Prediction") prediction;
		int16_t __unknown0;
		float nicename("Autofire Time") autofire_time;
		float nicename("Autofire Throw") autofire_throw;
		e_secondary_action nicename("Secondary Action") secondary_action;
		e_primary_action nicename("Primary Action") primary_action;
		float nicename("Charging Time") charging_time;
		float nicename("Charged Time") charged_time;
		e_overcharge_action nicename("Overcharge Action") overcharge_action;
		e_charge_projectiles nicename("Charge Projectiles") charge_projectiles;
		b_charge_flags nicename("Charge Flags") charge_flags;
		float nicename("Charged Illumination") charged_illumination;
		TagReference nicename("Charging Effect") charging_effect_reference;
		TagReference nicename("Charging Damage Effect") charging_damage_effect_reference;
		TagReference nicename("Charging Response") charging_response_reference;
		float nicename("Charging Age Degeneration") charging_age_degeneration;
		TagReference nicename("Discharging Effect") discharging_effect_reference;
		TagReference nicename("Discharging Damage Effect") discharging_damage_effect_reference;
		s_tag_block_definition<s_charge_levels_definition> nicename("Charge Levels") charge_levels_block;
	};

	struct nicename("Barrels") s_barrels_definition
	{
		enum nicename("Prediction Type") e_prediction_type : uint16_t
		{
			/*nicename("None")*/ _prediction_type_none = 1ui16,
			/*nicename("Continuous")*/ _prediction_type_continuous = 2ui16,
			/*nicename("Instant")*/ _prediction_type_instant = 3ui16,
		};

		enum nicename("Firing Noise") e_firing_noise : uint16_t
		{
			/*nicename("Silent")*/ _firing_noise_silent = 1ui16,
			/*nicename("Medium")*/ _firing_noise_medium = 2ui16,
			/*nicename("Loud")*/ _firing_noise_loud = 3ui16,
			/*nicename("Shout")*/ _firing_noise_shout = 4ui16,
			/*nicename("Quiet")*/ _firing_noise_quiet = 5ui16,
		};

		enum nicename("Distribution Function") e_distribution_function : uint16_t
		{
			/*nicename("Point")*/ _distribution_function_point = 1ui16,
			/*nicename("Horizontal Fan")*/ _distribution_function_horizontal_fan = 2ui16,
		};

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

		enum nicename("Flags") b_flags3 : uint32_t /* bitfield */
		{
			/*nicename("Tracks Fired Projectile")*/ _flags3_tracks_fired_projectile = 1ui32 << 0ui32,
			/*nicename("Random Firing Effects")*/ _flags3_random_firing_effects = 1ui32 << 1ui32,
			/*nicename("Can Fire With Partial Ammo")*/ _flags3_can_fire_with_partial_ammo = 1ui32 << 2ui32,
			/*nicename("Projectiles Use Weapon Origin")*/ _flags3_projectiles_use_weapon_origin = 1ui32 << 3ui32,
			/*nicename("Ejects During Chamber")*/ _flags3_ejects_during_chamber = 1ui32 << 4ui32,
			/*nicename("Use Error When Unzoomed")*/ _flags3_use_error_when_unzoomed = 1ui32 << 5ui32,
			/*nicename("Projectile Vector Cannot Be Adjusted")*/ _flags3_projectile_vector_cannot_be_adjusted = 1ui32 << 6ui32,
			/*nicename("Projectiles Have Identical Error")*/ _flags3_projectiles_have_identical_error = 1ui32 << 7ui32,
			/*nicename("Projectiles Fire Parallel")*/ _flags3_projectiles_fire_parallel = 1ui32 << 8ui32,
			/*nicename("Cant Fire When Others Firing")*/ _flags3_cant_fire_when_others_firing = 1ui32 << 9ui32,
			/*nicename("Cant Fire When Others Recovering")*/ _flags3_cant_fire_when_others_recovering = 1ui32 << 10ui32,
			/*nicename("Don't Clear Fire Bit After Recovering")*/ _flags3_dont_clear_fire_bit_after_recovering = 1ui32 << 11ui32,
			/*nicename("Stagger Fire Across Multiple Markers")*/ _flags3_stagger_fire_across_multiple_markers = 1ui32 << 12ui32,
			/*nicename("Fires Locked Projectiles")*/ _flags3_fires_locked_projectiles = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags3_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags3_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags3_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags3_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags3_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags3_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags3_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags3_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags3_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags3_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags3_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags3_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags3_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags3_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags3_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags3_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags3_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags3_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Firing Penalty Function") s_firing_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Firing Crouched Penalty Function") s_firing_crouched_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Moving Penalty Function") s_moving_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Turning Penalty Function") s_turning_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Dual Firing Penalty Function") s_dual_firing_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Dual Firing Crouched Penalty Function") s_dual_firing_crouched_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Dual Moving Penalty Function") s_dual_moving_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("Dual Turning Penalty Function") s_dual_turning_penalty_function_definition
		{
			DataReference nicename("Function") function_data_reference;
		};

		struct nicename("First Person Offsets") s_first_person_offsets_definition
		{
			float nicename("First Person Offset x") first_person_offset_x;
			float nicename("First Person Offset y") first_person_offset_y;
			float nicename("First Person Offset z") first_person_offset_z;
		};

		struct nicename("Firing Effects") s_firing_effects_definition
		{
			int16_t nicename("Shot Count Lower Bound") shot_count_lower_bound;
			int16_t nicename("Shot Count Upper Bound") shot_count_upper_bound;
			TagReference nicename("Firing Effect") firing_effect_reference;
			TagReference nicename("Misfire Effect") misfire_effect_reference;
			TagReference nicename("Empty Effect") empty_effect_reference;
			TagReference nicename("Unknown Effect") unknown_effect_reference;
			TagReference nicename("Firing Response") firing_response_reference;
			TagReference nicename("Misfire Response") misfire_response_reference;
			TagReference nicename("Empty Response") empty_response_reference;
			TagReference nicename("Unknown Response") unknown_response_reference;
			TagReference nicename("Rider Firing Response") rider_firing_response_reference;
			TagReference nicename("Rider Misfire Response") rider_misfire_response_reference;
			TagReference nicename("Rider Empty Response") rider_empty_response_reference;
			TagReference nicename("Rider Unknown Response") rider_unknown_response_reference;
		};

		b_flags3 nicename("Flags") flags;
		float nicename("Rounds Per Second min") rounds_per_second_min;
		float nicename("Rounds Per Second max") rounds_per_second_max;
		string_id nicename("Acceleration Time Function") acceleration_time_function;
		float nicename("Acceleration Time") acceleration_time;
		string_id nicename("Deceleration Time Function") deceleration_time_function;
		float nicename("Deceleration Time") deceleration_time;
		float nicename("Barrel Spin Scale") barrel_spin_scale;
		float nicename("Blurred Rate of Fire") blurred_rate_of_fire;
		int16_t nicename("Shots Per Fire min") shots_per_fire_min;
		int16_t nicename("Shots Per Fire max") shots_per_fire_max;
		float nicename("Fire Recovery Time") fire_recovery_time;
		float nicename("Soft Recovery Fraction") soft_recovery_fraction;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		int16_t nicename("Magazine") magazine;
		int16_t nicename("Rounds Per Shot") rounds_per_shot;
		int16_t nicename("Minimum Rounds Loaded") minimum_rounds_loaded;
		int16_t nicename("Rounds Between Tracers") rounds_between_tracers;
		string_id nicename("Optional Barrel Marker Name") optional_barrel_marker_name;
		e_prediction_type nicename("Prediction Type") prediction_type;
		e_firing_noise nicename("Firing Noise") firing_noise;
		float __unknown2;
		// Error : 
		float nicename("Acceleration Time") acceleration_time1;
		float nicename("Deceleration Time") deceleration_time1;
		float nicename("Damage Error min") damage_error_min;
		float nicename("Damage Error max") damage_error_max;
		// Turning : 
		float nicename("Base Turning Speed") base_turning_speed;
		float nicename("Dynamic Turning Speed min") dynamic_turning_speed_min;
		float nicename("Dynamic Turning Speed max") dynamic_turning_speed_max;
		// Projectile : 
		e_distribution_function nicename("Distribution Function") distribution_function;
		int16_t nicename("Projectiles Per Shot") projectiles_per_shot;
		float nicename("Distribution Angle") distribution_angle;
		float nicename("Minimum Error") minimum_error;
		float nicename("Error Angle min") error_angle_min;
		float nicename("Error Angle max") error_angle_max;
		float nicename("Reload Penalty") reload_penalty;
		float nicename("Switch Penalty") switch_penalty;
		float nicename("Zoom Penalty") zoom_penalty;
		float nicename("Jump Penalty") jump_penalty;
		s_tag_block_definition<s_firing_penalty_function_definition> nicename("Firing Penalty Function") firing_penalty_function_block;
		s_tag_block_definition<s_firing_crouched_penalty_function_definition> nicename("Firing Crouched Penalty Function") firing_crouched_penalty_function_block;
		s_tag_block_definition<s_moving_penalty_function_definition> nicename("Moving Penalty Function") moving_penalty_function_block;
		s_tag_block_definition<s_turning_penalty_function_definition> nicename("Turning Penalty Function") turning_penalty_function_block;
		float nicename("Error Angle Maximum Rotation") error_angle_maximum_rotation;
		s_tag_block_definition<s_dual_firing_penalty_function_definition> nicename("Dual Firing Penalty Function") dual_firing_penalty_function_block;
		s_tag_block_definition<s_dual_firing_crouched_penalty_function_definition> nicename("Dual Firing Crouched Penalty Function") dual_firing_crouched_penalty_function_block;
		s_tag_block_definition<s_dual_moving_penalty_function_definition> nicename("Dual Moving Penalty Function") dual_moving_penalty_function_block;
		s_tag_block_definition<s_dual_turning_penalty_function_definition> nicename("Dual Turning Penalty Function") dual_turning_penalty_function_block;
		float nicename("Dual Error Angle Maximum Rotation") dual_error_angle_maximum_rotation;
		s_tag_block_definition<s_first_person_offsets_definition> nicename("First Person Offsets") first_person_offsets_block;
		e_damage_reporting_type nicename("Damage Reporting Type") damage_reporting_type;
		int8_t __unknown3;
		int16_t __unknown4;
		TagReference nicename("Initial Projectile") initial_projectile_reference;
		TagReference nicename("Trailing Projectile") trailing_projectile_reference;
		TagReference nicename("Damage Effect") damage_effect_reference;
		TagReference nicename("Crate Projectile") crate_projectile_reference;
		float nicename("Crate Projectile Speed") crate_projectile_speed;
		float nicename("Ejection Port Recovery Time") ejection_port_recovery_time;
		float nicename("Illumination Recovery Time") illumination_recovery_time;
		float nicename("Heat Generated Per Round") heat_generated_per_round;
		string_id nicename("Heat Per Round Function") heat_per_round_function;
		float nicename("Age Generated Per Round MP") age_generated_per_round_mp;
		float nicename("Age Generated Per Round SP") age_generated_per_round_sp;
		float nicename("Overload Time") overload_time;
		float nicename("Firing Effect Deceleration Time") firing_effect_deceleration_time;
		float __unknown5;
		float nicename("Rate Of Fire Acceleration Time") rate_of_fire_acceleration_time;
		float nicename("Rate Of Fire Deceleration Time") rate_of_fire_deceleration_time;
		float nicename("Bloom Rate of Decay") bloom_rate_of_decay;
		s_tag_block_definition<s_firing_effects_definition> nicename("Firing Effects") firing_effects_block;
	};

	struct nicename("Weapon Screen Effect") s_weapon_screen_effect_definition
	{
		enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
		{
			/*nicename("Disable Unit Effect When Active")*/ _flags3_disable_unit_effect_when_active = 1ui8 << 0ui8,
			/*nicename("Activate When Unzoomed")*/ _flags3_activate_when_unzoomed = 1ui8 << 1ui8,
			/*nicename("Activate When Zoomed Level 1")*/ _flags3_activate_when_zoomed_level_1 = 1ui8 << 2ui8,
			/*nicename("Activate When Zoomed Level 2")*/ _flags3_activate_when_zoomed_level_2 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _flags3_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _flags3_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags3_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags3_bit_7 = 1ui8 << 7ui8,
		};

		b_flags3 nicename("Flags") flags;
		int8_t __unknown0;
		int16_t __unknown1;
		TagReference nicename("Screen Effect") screen_effect_reference;
	};

	e_object_type nicename("Object Type") object_type;
	int16_t __unknown0;
	b_flags nicename("Flags") flags;
	float nicename("Bounding Radius") bounding_radius;
	float nicename("Bounding Offset X") bounding_offset_x;
	float nicename("Bounding Offset Y") bounding_offset_y;
	float nicename("Bounding Offset Z") bounding_offset_z;
	float nicename("Horizontal Acceleration Scale") horizontal_acceleration_scale;
	float nicename("Vertical Acceleration Scale") vertical_acceleration_scale;
	float nicename("Angular Acceleration Scale") angular_acceleration_scale;
	e_lightmap_shadow_mode_size nicename("Lightmap Shadow Mode Size") lightmap_shadow_mode_size;
	e_sweetener_size nicename("Sweetener Size") sweetener_size;
	e_water_density nicename("Water Density") water_density;
	int32_t __unknown1;
	float nicename("Dynamic Light Sphere Radius") dynamic_light_sphere_radius;
	float nicename("Dynamic Light Sphere X Offset") dynamic_light_sphere_x_offset;
	float nicename("Dynamic Light Sphere Y Offset") dynamic_light_sphere_y_offset;
	float nicename("Dynamic Light Sphere Z Offset") dynamic_light_sphere_z_offset;
	string_id nicename("Generic HUD Text") generic_hud_text;
	TagReference nicename("Generic Name List") generic_name_list_reference;
	TagReference nicename("Generic Service Tag List") generic_service_tag_list_reference;
	string_id nicename("Default Variant") default_variant;
	TagReference nicename("Model") model_reference;
	TagReference nicename("Crate Object") crate_object_reference;
	TagReference nicename("Collision Damage") collision_damage_reference;
	TagReference nicename("Brittle Collision Damage") brittle_collision_damage_reference;
	s_tag_block_definition<s_early_mover_properties_definition> nicename("Early Mover Properties") early_mover_properties_block;
	TagReference nicename("Creation Effect") creation_effect_reference;
	TagReference nicename("Material Effects") material_effects_reference;
	TagReference nicename("Melee Impact") melee_impact_reference;
	s_tag_block_definition<s_ai_properties_definition> nicename("AI Properties") ai_properties_block;
	s_tag_block_definition<s_functions_definition> nicename("Functions") functions_block;
	s_tag_block_definition<s_function_related_definition> nicename("Function Related") function_related_block;
	int16_t nicename("HUD Text Message Index") hud_text_message_index;
	int16_t __unknown2;
	s_tag_block_definition<s_attachments_definition> nicename("Attachments") attachments_block;
	s_tag_block_definition<s_material_responses_definition> nicename("Material Responses") material_responses_block;
	s_tag_block_definition<s_jet_wash_definition> nicename("Jet Wash") jet_wash_block;
	s_tag_block_definition<s_widgets_definition> nicename("Widgets") widgets_block;
	s_tag_block_definition<s_change_color_definition> nicename("Change Color") change_color_block;
	s_tag_block_definition<s_predicted_resources_definition> nicename("Predicted Resources") predicted_resources_block;
	s_tag_block_definition<s_multiplayer_object_properties_definition> nicename("Multiplayer Object Properties") multiplayer_object_properties_block;
	TagReference nicename("Simulation Interpolation") simulation_interpolation_reference;
	s_tag_block_definition<s_unknown2_definition> __unknown3;
	// ITEM : 
	b_flags1 nicename("Flags") flags1;
	int16_t nicename("OLD Message Index") old_message_index;
	int16_t nicename("Sort Order") sort_order;
	float nicename("OLD Multiplayer On-Ground Scale") old_multiplayer_on_ground_scale;
	float nicename("OLD Campaign On-Ground Scale") old_campaign_on_ground_scale;
	string_id nicename("Pickup Message") pickup_message;
	string_id nicename("Swap Message") swap_message;
	string_id nicename("Pickup Or Dual Wield Message") pickup_or_dual_wield_message;
	string_id nicename("Swap Or Dual Wield Message") swap_or_dual_wield_message;
	string_id nicename("Picked Up Message") picked_up_message;
	string_id nicename("Switch-To Message") switch_to_message;
	string_id nicename("Switch-To From AI Message") switch_to_from_ai_message;
	string_id nicename("All Weapons Empty Message") all_weapons_empty_message;
	string_id nicename("Overheated Message") overheated_message;
	TagReference nicename("Collision Sound") collision_sound_reference;
	s_tag_block_definition<s_predicted_bitmaps_definition> nicename("Predicted Bitmaps") predicted_bitmaps_block;
	TagReference nicename("Detonation Damage Effect") detonation_damage_effect_reference;
	float nicename("Detonation Delay min") detonation_delay_min;
	float nicename("Detonation Delay max") detonation_delay_max;
	TagReference nicename("Detonating Effect") detonating_effect_reference;
	TagReference nicename("Detonation Effect") detonation_effect_reference;
	float nicename("Global Ground Scale") global_ground_scale;
	float nicename("Small Hold Scale") small_hold_scale;
	float nicename("Small Holster Scale") small_holster_scale;
	float nicename("Large Hold Scale") large_hold_scale;
	float nicename("Large Holster Scale") large_holster_scale;
	float nicename("Medium Hold Scale") medium_hold_scale;
	float nicename("Medium Holster Scale") medium_holster_scale;
	float nicename("Huge Hold Scale") huge_hold_scale;
	float nicename("Huge Holster Scale") huge_holster_scale;
	TagReference nicename("Grounded Friction") grounded_friction_reference;
	// WEAPON : 
	b_flags2 nicename("Flags") flags2;
	b_more_flags nicename("More Flags") more_flags;
	string_id __unknown4;
	e_secondary_trigger_mode nicename("Secondary Trigger Mode") secondary_trigger_mode;
	int16_t nicename("Maximum Alternate Shots Loaded") maximum_alternate_shots_loaded;
	float nicename("Turn On Time") turn_on_time;
	float nicename("Ready Time") ready_time;
	TagReference nicename("Ready Effect") ready_effect_reference;
	TagReference nicename("Ready Damage Effect") ready_damage_effect_reference;
	float nicename("Heat Recovery Threshold") heat_recovery_threshold;
	float nicename("Overheated Threshold") overheated_threshold;
	float nicename("Heat Detonation Threshold") heat_detonation_threshold;
	float nicename("Heat Detonation Fraction") heat_detonation_fraction;
	float nicename("Heat Loss Per Second") heat_loss_per_second;
	string_id nicename("Heat Loss Function") heat_loss_function;
	string_id nicename("Custom Function 1") custom_function_1;
	float nicename("Custom Function Value") custom_function_value;
	Undefined32 __unknown5;
	float __unknown6;
	float nicename("Heat Illumination") heat_illumination;
	float nicename("Overheated Heat Loss Per Second") overheated_heat_loss_per_second;
	string_id nicename("Custom Function 2") custom_function_2;
	TagReference nicename("Overheated") overheated_reference;
	TagReference nicename("Overheat Damage Effect") overheat_damage_effect_reference;
	TagReference nicename("Detonation") detonation_reference;
	TagReference nicename("Detonation Damage Effect") detonation_damage_effect1_reference;
	s_tag_block_definition<s_melee_damage_definition> nicename("Melee Damage") melee_damage_block;
	TagReference nicename("Clash Effect") clash_effect_reference;
	e_melee_damage_reporting_type nicename("Melee Damage Reporting Type") melee_damage_reporting_type;
	int8_t __unknown7;
	int16_t nicename("Magnification Levels") magnification_levels;
	float nicename("Magnification Range min") magnification_range_min;
	float nicename("Magnification Range max") magnification_range_max;
	// Weapon Aim Assist : 
	float nicename("Autoaim Angle") autoaim_angle;
	float nicename("Autoaim Range Long") autoaim_range_long;
	float nicename("Autoaim Range Short") autoaim_range_short;
	float nicename("Autoaim Safe Radius") autoaim_safe_radius;
	float nicename("Magnetism Angle") magnetism_angle;
	float nicename("Magnetism Range Long") magnetism_range_long;
	float nicename("Magnetism Range Short") magnetism_range_short;
	float nicename("Magnetism Safe Radius") magnetism_safe_radius;
	float nicename("Deviation Angle") deviation_angle;
	Undefined32 __unknown8;
	Undefined32 __unknown9;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	s_tag_block_definition<s_target_tracking_definition> nicename("Target Tracking") target_tracking_block;
	Undefined32 __unknown14;
	Undefined32 __unknown15;
	Undefined32 __unknown16;
	Undefined32 __unknown17;
	e_movement_penalized nicename("Movement Penalized") movement_penalized;
	int16_t __unknown18;
	float nicename("Forwards Movement Penalty") forwards_movement_penalty;
	float nicename("Sideways Movement Penalty") sideways_movement_penalty;
	float nicename("AI Scariness") ai_scariness;
	float nicename("Weapon Power-On Time") weapon_power_on_time;
	float nicename("Weapon Power-Off Time") weapon_power_off_time;
	TagReference nicename("Weapon Power-On Effect") weapon_power_on_effect_reference;
	TagReference nicename("Weapon Power-Off Effect") weapon_power_off_effect_reference;
	float nicename("Age Heat Recovery Penalty") age_heat_recovery_penalty;
	float nicename("Age Rate of Fire Penalty") age_rate_of_fire_penalty;
	float nicename("Age Misfire Start") age_misfire_start;
	float nicename("Age Misfire Chance") age_misfire_chance;
	TagReference nicename("Pickup Sound") pickup_sound_reference;
	TagReference nicename("Zoom-In Sound") zoom_in_sound_reference;
	TagReference nicename("Zoom-Out Sound") zoom_out_sound_reference;
	float nicename("Active Camo Ding") active_camo_ding;
	string_id nicename("Handle Node") handle_node;
	string_id nicename("Weapon Class") weapon_class;
	string_id nicename("Weapon Name") weapon_name;
	e_weapon_type nicename("Weapon Type") weapon_type;
	int16_t __unknown19;
	Undefined32 __unknown20;
	Undefined32 __unknown21;
	Undefined32 __unknown22;
	Undefined32 __unknown23;
	s_tag_block_definition<s_first_person_definition> nicename("First Person") first_person_block;
	TagReference nicename("HUD Interface") hud_interface_reference;
	TagReference __unknown24;
	s_tag_block_definition<s_predicted_resources1_definition> nicename("Predicted Resources") predicted_resources1_block;
	s_tag_block_definition<s_magazines_definition> nicename("Magazines") magazines_block;
	s_tag_block_definition<s_new_triggers_definition> nicename("New Triggers") new_triggers_block;
	s_tag_block_definition<s_barrels_definition> nicename("Barrels") barrels_block;
	float __unknown25;
	float __unknown26;
	float nicename("Maximum Movement Acceleration") maximum_movement_acceleration;
	float nicename("Maximum Movement Velocity") maximum_movement_velocity;
	float nicename("Maximum Turning Acceleration") maximum_turning_acceleration;
	float nicename("Maximum Turning Velocity") maximum_turning_velocity;
	TagReference nicename("Deployed Vehicle") deployed_vehicle_reference;
	TagReference nicename("Deployed Weapon") deployed_weapon_reference;
	TagReference nicename("Age Model") age_model_reference;
	TagReference nicename("Age Weapon") age_weapon_reference;
	TagReference nicename("Aged Material Effects") aged_material_effects_reference;
	float nicename("Hammer Age Per Use MP") hammer_age_per_use_mp;
	float nicename("Hammer Age Per Use SP") hammer_age_per_use_sp;
	Undefined32 __unknown27;
	float nicename("First Person Weapon Offset i") first_person_weapon_offset_i;
	float nicename("First Person Weapon Offset j") first_person_weapon_offset_j;
	float nicename("First Person Weapon Offset k") first_person_weapon_offset_k;
	float nicename("First Person Scope Size i") first_person_scope_size_i;
	float nicename("First Person Scope Size j") first_person_scope_size_j;
	float nicename("Third Person Pitch Bounds min") third_person_pitch_bounds_min;
	float nicename("Third Person Pitch Bounds max") third_person_pitch_bounds_max;
	float nicename("Zoom Transition Time") zoom_transition_time;
	float nicename("Melee Weapon Delay") melee_weapon_delay;
	string_id nicename("Weapon Holster Marker") weapon_holster_marker;
	s_tag_block_definition<s_weapon_screen_effect_definition> nicename("Weapon Screen Effect") weapon_screen_effect_block;
};

