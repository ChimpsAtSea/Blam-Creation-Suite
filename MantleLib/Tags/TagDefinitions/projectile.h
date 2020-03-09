#pragma once

struct nicename("projectile") group('proj') s_projectile_definition
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

	enum nicename("Detonation Timer Starts") e_detonation_timer_starts : uint16_t
	{
		/*nicename("Immediately")*/ _detonation_timer_starts_immediately = 1ui16,
		/*nicename("After First Bounce")*/ _detonation_timer_starts_after_first_bounce = 2ui16,
		/*nicename("When At Rest")*/ _detonation_timer_starts_when_at_rest = 3ui16,
		/*nicename("After First Bounce Off Any Surface")*/ _detonation_timer_starts_after_first_bounce_off_any_surface = 4ui16,
	};

	enum nicename("Impact Noise") e_impact_noise : uint16_t
	{
		/*nicename("Silent")*/ _impact_noise_silent = 1ui16,
		/*nicename("Medium")*/ _impact_noise_medium = 2ui16,
		/*nicename("Loud")*/ _impact_noise_loud = 3ui16,
		/*nicename("Shout")*/ _impact_noise_shout = 4ui16,
		/*nicename("Quiet")*/ _impact_noise_quiet = 5ui16,
	};

	enum nicename("Detonation Noise") e_detonation_noise : uint16_t
	{
		/*nicename("Silent")*/ _detonation_noise_silent = 1ui16,
		/*nicename("Medium")*/ _detonation_noise_medium = 2ui16,
		/*nicename("Loud")*/ _detonation_noise_loud = 3ui16,
		/*nicename("Shout")*/ _detonation_noise_shout = 4ui16,
		/*nicename("Quiet")*/ _detonation_noise_quiet = 5ui16,
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
		/*nicename("Oriented Along Velocity")*/ _flags1_oriented_along_velocity = 1ui32 << 0ui32,
		/*nicename("AI Must Use Ballistic Aiming")*/ _flags1_ai_must_use_ballistic_aiming = 1ui32 << 1ui32,
		/*nicename("Detonation Max Time If Attached")*/ _flags1_detonation_max_time_if_attached = 1ui32 << 2ui32,
		/*nicename("Has Super Combining Explosion")*/ _flags1_has_super_combining_explosion = 1ui32 << 3ui32,
		/*nicename("Damage Scales Based On Distance")*/ _flags1_damage_scales_based_on_distance = 1ui32 << 4ui32,
		/*nicename("Travels Instantaneously")*/ _flags1_travels_instantaneously = 1ui32 << 5ui32,
		/*nicename("Steering Adjusts Orientation")*/ _flags1_steering_adjusts_orientation = 1ui32 << 6ui32,
		/*nicename("Don't Noise Up Steering")*/ _flags1_dont_noise_up_steering = 1ui32 << 7ui32,
		/*nicename("Can Track Behind Itself")*/ _flags1_can_track_behind_itself = 1ui32 << 8ui32,
		/*nicename("Robotron Steering")*/ _flags1_robotron_steering = 1ui32 << 9ui32,
		/*nicename("Faster When Owned By Player")*/ _flags1_faster_when_owned_by_player = 1ui32 << 10ui32,
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

	enum nicename("Super Detonation Object Types") b_super_detonation_object_types : uint16_t /* bitfield */
	{
		/*nicename("Biped")*/ _super_detonation_object_types_biped = 1ui16 << 0ui16,
		/*nicename("Vehicle")*/ _super_detonation_object_types_vehicle = 1ui16 << 1ui16,
		/*nicename("Weapon")*/ _super_detonation_object_types_weapon = 1ui16 << 2ui16,
		/*nicename("Equipment")*/ _super_detonation_object_types_equipment = 1ui16 << 3ui16,
		/*nicename("Terminal")*/ _super_detonation_object_types_terminal = 1ui16 << 4ui16,
		/*nicename("Projectile")*/ _super_detonation_object_types_projectile = 1ui16 << 5ui16,
		/*nicename("Scenery")*/ _super_detonation_object_types_scenery = 1ui16 << 6ui16,
		/*nicename("Machine")*/ _super_detonation_object_types_machine = 1ui16 << 7ui16,
		/*nicename("Control")*/ _super_detonation_object_types_control = 1ui16 << 8ui16,
		/*nicename("Sound Scenery")*/ _super_detonation_object_types_sound_scenery = 1ui16 << 9ui16,
		/*nicename("Crate")*/ _super_detonation_object_types_crate = 1ui16 << 10ui16,
		/*nicename("Creature")*/ _super_detonation_object_types_creature = 1ui16 << 11ui16,
		/*nicename("Giant")*/ _super_detonation_object_types_giant = 1ui16 << 12ui16,
		/*nicename("Effect Scenery")*/ _super_detonation_object_types_effect_scenery = 1ui16 << 13ui16,
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

	struct nicename("Material Responses") s_material_responses1_definition
	{
		enum nicename("Response") e_response : uint16_t
		{
			/*nicename("Impact (Detonate)")*/ _response_impact_detonate = 1ui16,
			/*nicename("Fizzle")*/ _response_fizzle = 2ui16,
			/*nicename("Overpenetrate")*/ _response_overpenetrate = 3ui16,
			/*nicename("Attach")*/ _response_attach = 4ui16,
			/*nicename("Bounce")*/ _response_bounce = 5ui16,
			/*nicename("Bounce (Dud)")*/ _response_bounce_dud = 6ui16,
			/*nicename("Fizzle (Ricochet)")*/ _response_fizzle_ricochet = 7ui16,
			/*nicename("Bounce (Unknown)")*/ _response_bounce_unknown = 8ui16,
			/*nicename("Airstrike")*/ _response_airstrike = 9ui16,
		};

		enum nicename("Response") e_response1 : uint16_t
		{
			/*nicename("Impact (Detonate)")*/ _response1_impact_detonate = 1ui16,
			/*nicename("Fizzle")*/ _response1_fizzle = 2ui16,
			/*nicename("Overpenetrate")*/ _response1_overpenetrate = 3ui16,
			/*nicename("Attach")*/ _response1_attach = 4ui16,
			/*nicename("Bounce")*/ _response1_bounce = 5ui16,
			/*nicename("Bounce (Dud)")*/ _response1_bounce_dud = 6ui16,
			/*nicename("Fizzle (Ricochet)")*/ _response1_fizzle_ricochet = 7ui16,
			/*nicename("Bounce (Unknown)")*/ _response1_bounce_unknown = 8ui16,
			/*nicename("Airstrike")*/ _response1_airstrike = 9ui16,
		};

		enum nicename("Scale Effects By") e_scale_effects_by : uint16_t
		{
			/*nicename("Damage")*/ _scale_effects_by_damage = 1ui16,
			/*nicename("Angle")*/ _scale_effects_by_angle = 2ui16,
		};

		enum nicename("Flags") b_flags2 : uint16_t /* bitfield */
		{
			/*nicename("Only Against Units")*/ _flags2_only_against_units = 1ui16 << 0ui16,
			/*nicename("Never Against Units")*/ _flags2_never_against_units = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags2_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags2_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags2_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags2_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags2_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags2_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags2_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags2_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags2_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags2_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags2_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags2_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags2_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags2_bit_15 = 1ui16 << 15ui16,
		};

		// Default Result : 
		e_response nicename("Response") response;
		int16_t __unknown0;
		string_id nicename("Material Name") material_name;
		int16_t nicename("Global Material Index") global_material_index;
		int16_t __unknown1;
		// Potential Result : 
		e_response1 nicename("Response") response1;
		b_flags2 nicename("Flags") flags;
		float nicename("Chance Fraction") chance_fraction;
		float nicename("Between Angle min") between_angle_min;
		float nicename("Between Angle max") between_angle_max;
		float nicename("And Velocity min") and_velocity_min;
		float nicename("And Velocity max") and_velocity_max;
		e_scale_effects_by nicename("Scale Effects By") scale_effects_by;
		int16_t __unknown2;
		float nicename("Angular Noise") angular_noise;
		float nicename("Velocity Noise") velocity_noise;
		// Penetration : 
		float nicename("Initial Friction") initial_friction;
		// Reflection : 
		float nicename("Parallel Friction") parallel_friction;
		float nicename("Perpendicular Friction") perpendicular_friction;
	};

	struct nicename("Unknown Material Responses") s_unknown_material_responses_definition
	{
		enum nicename("Response") e_response : uint16_t
		{
			/*nicename("Impact (Detonate)")*/ _response_impact_detonate = 1ui16,
			/*nicename("Fizzle")*/ _response_fizzle = 2ui16,
			/*nicename("Overpenetrate")*/ _response_overpenetrate = 3ui16,
			/*nicename("Attach")*/ _response_attach = 4ui16,
			/*nicename("Bounce")*/ _response_bounce = 5ui16,
			/*nicename("Bounce (Dud)")*/ _response_bounce_dud = 6ui16,
			/*nicename("Fizzle (Ricochet)")*/ _response_fizzle_ricochet = 7ui16,
			/*nicename("Bounce (Unknown)")*/ _response_bounce_unknown = 8ui16,
			/*nicename("Airstrike")*/ _response_airstrike = 9ui16,
		};

		enum nicename("Scale Effects By") e_scale_effects_by : uint16_t
		{
			/*nicename("Damage")*/ _scale_effects_by_damage = 1ui16,
			/*nicename("Angle")*/ _scale_effects_by_angle = 2ui16,
		};

		enum nicename("Flags") b_flags2 : uint16_t /* bitfield */
		{
			/*nicename("Only Against Units")*/ _flags2_only_against_units = 1ui16 << 0ui16,
			/*nicename("Never Against Units")*/ _flags2_never_against_units = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags2_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags2_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags2_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags2_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags2_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags2_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags2_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags2_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags2_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags2_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags2_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags2_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags2_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags2_bit_15 = 1ui16 << 15ui16,
		};

		string_id nicename("Material") material;
		int16_t nicename("Global Material Index") global_material_index;
		// Potential Result : 
		b_flags2 nicename("Flags") flags;
		float nicename("Chance Fraction") chance_fraction;
		float nicename("Between Angle min") between_angle_min;
		float nicename("Between Angle max") between_angle_max;
		float nicename("And Velocity min") and_velocity_min;
		float nicename("And Velocity max") and_velocity_max;
		e_response nicename("Response") response;
		e_scale_effects_by nicename("Scale Effects By") scale_effects_by;
		float nicename("Angular Noise") angular_noise;
		float nicename("Velocity Noise") velocity_noise;
		// Penetration : 
		float nicename("Penetration Initial Friction") penetration_initial_friction;
		// Reflection : 
		float nicename("Reflection Parallel Friction") reflection_parallel_friction;
		float nicename("Reflection Perpendicular Friction") reflection_perpendicular_friction;
	};

	struct nicename("Claymore Grenade") s_claymore_grenade_definition
	{
		float __unknown0;
		float __unknown1;
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

	struct nicename("Firebomb Grenade") s_firebomb_grenade_definition
	{
		float __unknown0;
	};

	struct nicename("Shotgun Properties") s_shotgun_properties_definition
	{
		int16_t nicename("Amount") amount;
		int16_t nicename("Distance") distance;
		float nicename("Accuracy") accuracy;
		float nicename("Spread Cone Angle") spread_cone_angle;
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
	// PROJECTILE : 
	b_flags1 nicename("Flags") flags1;
	e_detonation_timer_starts nicename("Detonation Timer Starts") detonation_timer_starts;
	e_impact_noise nicename("Impact Noise") impact_noise;
	float nicename("Collision Radius") collision_radius;
	float nicename("Arming Time") arming_time;
	float nicename("Danger Radius") danger_radius;
	float __unknown4;
	int16_t __unknown5;
	int16_t __unknown6;
	float nicename("Timer min") timer_min;
	float nicename("Timer max") timer_max;
	float nicename("Minimum Velocity") minimum_velocity;
	float nicename("Maximum Range") maximum_range;
	Undefined32 __unknown7;
	Undefined32 __unknown8;
	float nicename("Detonation Charge Time") detonation_charge_time;
	e_detonation_noise nicename("Detonation Noise") detonation_noise;
	int16_t nicename("Super Detonate Projectile Count") super_detonate_projectile_count;
	float nicename("Super Detonation Delay") super_detonation_delay;
	TagReference nicename("Detonation Started") detonation_started_reference;
	TagReference nicename("Airborne Detonation Effect") airborne_detonation_effect_reference;
	TagReference nicename("Ground Detonation Effect") ground_detonation_effect_reference;
	TagReference nicename("Detonation Damage") detonation_damage_reference;
	TagReference nicename("Attached Detonation Damage") attached_detonation_damage_reference;
	TagReference nicename("Super Detonation") super_detonation_reference;
	TagReference nicename("Super Detonation Damage") super_detonation_damage_reference;
	TagReference nicename("Detonation Sound") detonation_sound_reference;
	e_damage_reporting_type nicename("Damage Reporting Type") damage_reporting_type;
	int8_t __unknown9;
	b_super_detonation_object_types nicename("Super Detonation Object Types") super_detonation_object_types;
	TagReference nicename("Attached Super Detonation Damage") attached_super_detonation_damage_reference;
	float nicename("Material Effect Radius") material_effect_radius;
	TagReference nicename("Flyby Sound") flyby_sound_reference;
	TagReference nicename("Flyby Response") flyby_response_reference;
	float nicename("Flyby Effects Range") flyby_effects_range;
	TagReference nicename("Impact Effect") impact_effect_reference;
	TagReference __unknown10;
	TagReference nicename("Impact Damage") impact_damage_reference;
	float nicename("Boarding Detonation Time") boarding_detonation_time;
	TagReference nicename("Boarding Detonation Damage") boarding_detonation_damage_reference;
	TagReference nicename("Boarding Attached Detonation Damage") boarding_attached_detonation_damage_reference;
	float nicename("Air Gravity") air_gravity;
	float nicename("Air Damage Range min") air_damage_range_min;
	float nicename("Air Damage Range max") air_damage_range_max;
	float nicename("Water Gravity Scale") water_gravity_scale;
	float nicename("Water Damage min") water_damage_min;
	float nicename("Water Damage max") water_damage_max;
	float nicename("Initial Velocity") initial_velocity;
	float nicename("Final Velocity") final_velocity;
	Undefined32 __unknown11;
	float __unknown12;
	float __unknown13;
	float __unknown14;
	Undefined32 __unknown15;
	Undefined32 __unknown16;
	float nicename("Guided Angular Velocity Lower") guided_angular_velocity_lower;
	float nicename("Guided Angular Velocity Upper") guided_angular_velocity_upper;
	float __unknown17;
	float nicename("Acceleration Range min") acceleration_range_min;
	float nicename("Acceleration Range max") acceleration_range_max;
	float __unknown18;
	Undefined32 __unknown19;
	float nicename("Targeted Leading Fraction") targeted_leading_fraction;
	Undefined32 __unknown20;
	s_tag_block_definition<s_material_responses1_definition> nicename("Material Responses") material_responses1_block;
	s_tag_block_definition<s_unknown_material_responses_definition> nicename("Unknown Material Responses") unknown_material_responses_block;
	s_tag_block_definition<s_claymore_grenade_definition> nicename("Claymore Grenade") claymore_grenade_block;
	s_tag_block_definition<s_firebomb_grenade_definition> nicename("Firebomb Grenade") firebomb_grenade_block;
	s_tag_block_definition<s_shotgun_properties_definition> nicename("Shotgun Properties") shotgun_properties_block;
	TagReference nicename("Grounded Friction") grounded_friction_reference;
};

