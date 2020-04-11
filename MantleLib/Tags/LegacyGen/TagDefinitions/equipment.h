#pragma once

struct nicename("equipment") tag_group('eqip') s_equipment_definition
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

	enum nicename("Equipment Type") e_equipment_type : uint16_t
	{
		/*nicename("Armor Ability")*/ _equipment_type_armor_ability = 1ui16,
		/*nicename("Grenade")*/ _equipment_type_grenade = 2ui16,
		/*nicename("Powerup")*/ _equipment_type_powerup = 3ui16,
	};

	enum nicename("Activation Type") e_activation_type : uint8_t
	{
		/*nicename("Toggle")*/ _activation_type_toggle = 1ui8,
		/*nicename("Held")*/ _activation_type_held = 2ui8,
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
		/*nicename("Bit 0")*/ _flags2_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _flags2_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _flags2_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _flags2_bit_3 = 1ui32 << 3ui32,
		/*nicename("Third Person Camera When Active")*/ _flags2_third_person_camera_when_active = 1ui32 << 4ui32,
		/*nicename("Third Person Camera")*/ _flags2_third_person_camera = 1ui32 << 5ui32,
		/*nicename("Hide Crosshair When Active")*/ _flags2_hide_crosshair_when_active = 1ui32 << 6ui32,
		/*nicename("Cannot Activate When Jumping")*/ _flags2_cannot_activate_when_jumping = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags2_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags2_bit_9 = 1ui32 << 9ui32,
		/*nicename("Cannot Activate In Seats")*/ _flags2_cannot_activate_in_seats = 1ui32 << 10ui32,
		/*nicename("Deactivates When Shooting")*/ _flags2_deactivates_when_shooting = 1ui32 << 11ui32,
		/*nicename("Deactivates When Meleeing")*/ _flags2_deactivates_when_meleeing = 1ui32 << 12ui32,
		/*nicename("Deactivates When Using Grenades")*/ _flags2_deactivates_when_using_grenades = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags2_bit_14 = 1ui32 << 14ui32,
		/*nicename("Override User's Primary Color")*/ _flags2_override_users_primary_color = 1ui32 << 15ui32,
		/*nicename("Override User's Secondary Color")*/ _flags2_override_users_secondary_color = 1ui32 << 16ui32,
		/*nicename("Dampens Sounds")*/ _flags2_dampens_sounds = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags2_bit_18 = 1ui32 << 18ui32,
		/*nicename("Cannot Shoot Immediately After")*/ _flags2_cannot_shoot_immediately_after = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags2_bit_20 = 1ui32 << 20ui32,
		/*nicename("Backpacks Weapon")*/ _flags2_backpacks_weapon = 1ui32 << 21ui32,
		/*nicename("Cannot Be Picked Up")*/ _flags2_cannot_be_picked_up = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags2_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags2_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags2_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags2_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags2_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags2_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags2_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags2_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags2_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Early Mover Properties") s_early_mover_properties_definition
	{
		string_id nicename("Name") name;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
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
		s_undefined32_legacy __unknown0;
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
			s_undefined32_legacy __unknown3;
			float __unknown4;
			float __unknown5;
		};

		b_flags1 nicename("Flags") flags;
		string_id nicename("Import Name") import_name;
		string_id nicename("Export Name") export_name;
		string_id nicename("Turn Off With") turn_off_with;
		string_id __unknown0;
		float nicename("Minimum Value") minimum_value;
		s_data_reference_legacy nicename("Default Function") default_function_data_reference;
		string_id nicename("Scale By") scale_by;
		s_tag_block_legacy<s_unknown_definition> __unknown1;
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

		s_tag_reference_legacy nicename("Attachment") attachment_reference;
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
			s_data_reference_legacy __unknown0;
			float __unknown1;
			s_data_reference_legacy __unknown2;
			float __unknown3;
			s_undefined32_legacy __unknown4;
			s_undefined32_legacy __unknown5;
		};

		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_tag_block_legacy<s_unknown1_definition> __unknown3;
	};

	struct nicename("Jet Wash") s_jet_wash_definition
	{
		string_id nicename("Marker") marker;
		float __unknown0;
		s_undefined32_legacy __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
	};

	struct nicename("Widgets") s_widgets_definition
	{
		s_tag_reference_legacy nicename("Type") type_reference;
	};

	struct nicename("Change Color") s_change_color_definition
	{
		struct nicename("Initial Permutations") s_initial_permutations_definition
		{
			float nicename("Weight") weight;
			s_colorf_legacy nicename("Color Lower Bound") color_lower_bound;
			s_colorf_legacy nicename("Color Upper Bound") color_upper_bound;
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
			s_colorf_legacy nicename("Color Lower Bound") color_lower_bound;
			s_colorf_legacy nicename("Color Upper Bound") color_upper_bound;
			string_id nicename("Darken By...") darken_by;
			string_id nicename("Scale By...") scale_by;
		};

		s_tag_block_legacy<s_initial_permutations_definition> nicename("Initial Permutations") initial_permutations_block;
		s_tag_block_legacy<s_functions1_definition> nicename("Functions") functions_block;
	};

	struct nicename("Predicted Resources") s_predicted_resources_definition
	{
		int16_t nicename("Type") type;
		int16_t nicename("Resource Index") resource_index;
		s_tag_reference_legacy nicename("Tag Index") tag_index_reference;
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
		s_tag_reference_legacy nicename("Child Object") child_object_reference;
		int32_t __unknown5;
		s_tag_reference_legacy nicename("Shape Shader") shape_shader_reference;
		s_tag_reference_legacy nicename("Shader 2") shader_2_reference;
		s_tag_reference_legacy __unknown6;
		s_tag_reference_legacy __unknown7;
		s_tag_reference_legacy nicename("Secondary Shader") secondary_shader_reference;
		s_tag_reference_legacy __unknown8;
		s_tag_reference_legacy __unknown9;
		s_tag_reference_legacy __unknown10;
	};

	struct nicename("Unknown") s_unknown2_definition
	{
		s_tag_reference_legacy __unknown0;
		s_tag_reference_legacy __unknown1;
		s_tag_reference_legacy __unknown2;
	};

	struct nicename("Predicted Bitmaps") s_predicted_bitmaps_definition
	{
		s_tag_reference_legacy nicename("Bitmap") bitmap_reference;
	};

	struct nicename("Equipment Camera") s_equipment_camera_definition
	{
		enum nicename("Camera Flags") b_camera_flags : uint8_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _camera_flags_bit_0 = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _camera_flags_bit_1 = 1ui8 << 1ui8,
			/*nicename("Hides Player")*/ _camera_flags_hides_player = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _camera_flags_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _camera_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _camera_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _camera_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _camera_flags_bit_7 = 1ui8 << 7ui8,
		};

		struct nicename("Camera Tracks") s_camera_tracks_definition
		{
			s_tag_reference_legacy nicename("Track") track_reference;
			s_tag_reference_legacy nicename("Screen Effect") screen_effect_reference;
		};

		struct nicename("Unknown") s_unknown3_definition
		{
			float __unknown0;
			s_undefined32_legacy __unknown1;
			s_data_reference_legacy __unknown2;
			float __unknown3;
			float __unknown4;
			float __unknown5;
			int16_t __unknown6;
			int16_t __unknown7;
			s_data_reference_legacy __unknown8;
			float __unknown9;
			float __unknown10;
			float __unknown11;
			int16_t __unknown12;
			int16_t __unknown13;
			s_data_reference_legacy __unknown14;
			float __unknown15;
			float __unknown16;
			float __unknown17;
		};

		struct nicename("Unknown") s_unknown4_definition
		{
			struct nicename("Unknown") s_unknown5_definition
			{
				s_data_reference_legacy nicename("Function") function_data_reference;
			};

			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			float __unknown4;
			float __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			float __unknown9;
			s_tag_block_legacy<s_unknown5_definition> __unknown10;
		};

		struct nicename("Space Fighter Camera") s_space_fighter_camera_definition
		{
			struct nicename("Unknown") s_unknown6_definition
			{
				s_data_reference_legacy nicename("Function") function_data_reference;
			};

			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			float __unknown4;
			float __unknown5;
			float __unknown6;
			float __unknown7;
			float __unknown8;
			float __unknown9;
			s_tag_block_legacy<s_unknown6_definition> __unknown10;
		};

		b_camera_flags nicename("Camera Flags") camera_flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		string_id nicename("Camera Marker") camera_marker;
		float nicename("Pitch Auto-Level") pitch_auto_level;
		float nicename("Pitch Range min") pitch_range_min;
		float nicename("Pitch Range max") pitch_range_max;
		s_tag_block_legacy<s_camera_tracks_definition> nicename("Camera Tracks") camera_tracks_block;
		float nicename("Camera Stiffness min") camera_stiffness_min;
		float nicename("Camera Stiffness max") camera_stiffness_max;
		float __unknown3;
		float nicename("Camera Acceleration Speed") camera_acceleration_speed;
		float nicename("Camera Deceleration Speed") camera_deceleration_speed;
		float __unknown4;
		float nicename("Camera Field Of View") camera_field_of_view;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_tag_block_legacy<s_unknown3_definition> __unknown11;
		s_tag_block_legacy<s_unknown4_definition> __unknown12;
		s_tag_block_legacy<s_space_fighter_camera_definition> nicename("Space Fighter Camera") space_fighter_camera_block;
	};

	struct nicename("Powerup") s_powerup_definition
	{
		enum nicename("Powerup Trait Set") e_powerup_trait_set : uint32_t
		{
			/*nicename("Red")*/ _powerup_trait_set_red = 1ui32,
			/*nicename("Blue")*/ _powerup_trait_set_blue = 2ui32,
			/*nicename("Yellow")*/ _powerup_trait_set_yellow = 3ui32,
		};

		e_powerup_trait_set nicename("Powerup Trait Set") powerup_trait_set;
	};

	struct nicename("Object Creation") s_object_creation_definition
	{
		s_tag_reference_legacy nicename("Object") object_reference;
		s_tag_reference_legacy __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float nicename("Object Force") object_force;
		int16_t __unknown4;
		int16_t __unknown5;
	};

	struct nicename("Destruction") s_destruction_definition
	{
		s_tag_reference_legacy nicename("Destroy Effect") destroy_effect_reference;
		s_tag_reference_legacy nicename("Destroy Damage Effect") destroy_damage_effect_reference;
		float __unknown0;
		float nicename("Self Destruction Time") self_destruction_time;
		float __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
	};

	struct nicename("Radar Manipulation") s_radar_manipulation_definition
	{
		float __unknown0;
		float nicename("Fake Blip Radius") fake_blip_radius;
		int32_t nicename("Fake Blip Count") fake_blip_count;
		float __unknown1;
	};

	struct nicename("Armor Lockup") s_armor_lockup_definition
	{
		struct nicename("EMP Discharge Levels") s_emp_discharge_levels_definition
		{
			float nicename("Charge Level") charge_level;
			float __unknown0;
			s_tag_reference_legacy nicename("Discharge Effect") discharge_effect_reference;
		};

		string_id nicename("Material Name") material_name;
		int16_t nicename("Global Material Index") global_material_index;
		int16_t __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_tag_reference_legacy nicename("Collision Damage") collision_damage_reference;
		s_tag_reference_legacy nicename("AI Reflection Damage") ai_reflection_damage_reference;
		s_tag_reference_legacy nicename("Player Reflection Damage") player_reflection_damage_reference;
		string_id nicename("Biped Active Damage Section") biped_active_damage_section;
		string_id nicename("Biped Deactivated Damage Section") biped_deactivated_damage_section;
		s_data_reference_legacy nicename("Function") function_data_reference;
		s_undefined32_legacy __unknown3;
		s_data_reference_legacy nicename("Function") function1_data_reference;
		s_tag_block_legacy<s_emp_discharge_levels_definition> nicename("EMP Discharge Levels") emp_discharge_levels_block;
	};

	struct nicename("Regenerator") s_regenerator_definition
	{
		enum nicename("Flags") b_flags3 : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags3_bit_0 = 1ui32 << 0ui32,
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

		b_flags3 nicename("Flags") flags;
		string_id nicename("Center Marker") center_marker;
		float __unknown0;
	};

	struct nicename("Runtime") s_runtime_definition
	{
		struct nicename("Traits When Active") s_traits_when_active_definition
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

			s_tag_block_legacy<s_shields_and_health_definition> nicename("Shields and Health") shields_and_health_block;
			s_tag_block_legacy<s_weapons_and_damage_definition> nicename("Weapons and Damage") weapons_and_damage_block;
			s_tag_block_legacy<s_movement_definition> nicename("Movement") movement_block;
			s_tag_block_legacy<s_appearance_definition> nicename("Appearance") appearance_block;
			s_tag_block_legacy<s_hud_definition> nicename("HUD") hud_block;
		};

		struct nicename("Traits When Inactive") s_traits_when_inactive_definition
		{
			struct nicename("Shields and Health") s_shields_and_health1_definition
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

			struct nicename("Weapons and Damage") s_weapons_and_damage1_definition
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

			struct nicename("Movement") s_movement1_definition
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

			struct nicename("Appearance") s_appearance1_definition
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

			struct nicename("HUD") s_hud1_definition
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

			s_tag_block_legacy<s_shields_and_health1_definition> nicename("Shields and Health") shields_and_health_block;
			s_tag_block_legacy<s_weapons_and_damage1_definition> nicename("Weapons and Damage") weapons_and_damage_block;
			s_tag_block_legacy<s_movement1_definition> nicename("Movement") movement_block;
			s_tag_block_legacy<s_appearance1_definition> nicename("Appearance") appearance_block;
			s_tag_block_legacy<s_hud1_definition> nicename("HUD") hud_block;
		};

		s_undefined32_legacy __unknown0;
		s_tag_block_legacy<s_traits_when_active_definition> nicename("Traits When Active") traits_when_active_block;
		s_tag_block_legacy<s_traits_when_inactive_definition> nicename("Traits When Inactive") traits_when_inactive_block;
	};

	struct nicename("Invisibility Unknown") s_invisibility_unknown_definition
	{
		struct nicename("Unknown") s_unknown7_definition
		{
			struct nicename("Unknown") s_unknown8_definition
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
			};

			s_tag_block_legacy<s_unknown8_definition> __unknown0;
		};

		struct nicename("Unknown") s_unknown9_definition
		{
			struct nicename("Unknown") s_unknown10_definition
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
			};

			s_tag_block_legacy<s_unknown10_definition> __unknown0;
		};

		s_tag_block_legacy<s_unknown7_definition> __unknown0;
		s_tag_block_legacy<s_unknown9_definition> __unknown1;
	};

	struct nicename("Jetpack") s_jetpack_definition
	{
		s_data_reference_legacy nicename("Function") function_data_reference;
		float nicename("Downforce When Falling") downforce_when_falling;
		float nicename("Airtime") airtime;
		float nicename("Falling Velocity Defuse") falling_velocity_defuse;
		s_undefined32_legacy __unknown0;
		float nicename("Vertical Force") vertical_force;
		float nicename("Terminal Velocity Time") terminal_velocity_time;
	};

	struct nicename("Hologram Properties") s_hologram_properties_definition
	{
		enum nicename("Flags") b_flags3 : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags3_bit_0 = 1ui32 << 0ui32,
			/*nicename("Collides With BSP A")*/ _flags3_collides_with_bsp_a = 1ui32 << 1ui32,
			/*nicename("Collides With Vehicles")*/ _flags3_collides_with_vehicles = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags3_bit_3 = 1ui32 << 3ui32,
			/*nicename("Collides With BSP B")*/ _flags3_collides_with_bsp_b = 1ui32 << 4ui32,
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

		float nicename("Time Active") time_active;
		b_flags3 nicename("Flags") flags;
		s_tag_reference_legacy nicename("Create Effect") create_effect_reference;
		s_tag_reference_legacy nicename("Active Effect") active_effect_reference;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_tag_reference_legacy nicename("Destruction Effect") destruction_effect_reference;
		float nicename("Stability min") stability_min;
		float nicename("Stability max") stability_max;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Evade") s_evade_definition
	{
		string_id nicename("Forward Animation") forward_animation;
		string_id nicename("Left Animation") left_animation;
		string_id nicename("Back Animation") back_animation;
		string_id nicename("Right Animation") right_animation;
	};

	struct nicename("Sprint") s_sprint_definition
	{
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
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
	s_tag_reference_legacy nicename("Generic Name List") generic_name_list_reference;
	s_tag_reference_legacy nicename("Generic Service Tag List") generic_service_tag_list_reference;
	string_id nicename("Default Variant") default_variant;
	s_tag_reference_legacy nicename("Model") model_reference;
	s_tag_reference_legacy nicename("Crate Object") crate_object_reference;
	s_tag_reference_legacy nicename("Collision Damage") collision_damage_reference;
	s_tag_reference_legacy nicename("Brittle Collision Damage") brittle_collision_damage_reference;
	s_tag_block_legacy<s_early_mover_properties_definition> nicename("Early Mover Properties") early_mover_properties_block;
	s_tag_reference_legacy nicename("Creation Effect") creation_effect_reference;
	s_tag_reference_legacy nicename("Material Effects") material_effects_reference;
	s_tag_reference_legacy nicename("Melee Impact") melee_impact_reference;
	s_tag_block_legacy<s_ai_properties_definition> nicename("AI Properties") ai_properties_block;
	s_tag_block_legacy<s_functions_definition> nicename("Functions") functions_block;
	s_tag_block_legacy<s_function_related_definition> nicename("Function Related") function_related_block;
	int16_t nicename("HUD Text Message Index") hud_text_message_index;
	int16_t __unknown2;
	s_tag_block_legacy<s_attachments_definition> nicename("Attachments") attachments_block;
	s_tag_block_legacy<s_material_responses_definition> nicename("Material Responses") material_responses_block;
	s_tag_block_legacy<s_jet_wash_definition> nicename("Jet Wash") jet_wash_block;
	s_tag_block_legacy<s_widgets_definition> nicename("Widgets") widgets_block;
	s_tag_block_legacy<s_change_color_definition> nicename("Change Color") change_color_block;
	s_tag_block_legacy<s_predicted_resources_definition> nicename("Predicted Resources") predicted_resources_block;
	s_tag_block_legacy<s_multiplayer_object_properties_definition> nicename("Multiplayer Object Properties") multiplayer_object_properties_block;
	s_tag_reference_legacy nicename("Simulation Interpolation") simulation_interpolation_reference;
	s_tag_block_legacy<s_unknown2_definition> __unknown3;
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
	s_tag_reference_legacy nicename("Collision Sound") collision_sound_reference;
	s_tag_block_legacy<s_predicted_bitmaps_definition> nicename("Predicted Bitmaps") predicted_bitmaps_block;
	s_tag_reference_legacy nicename("Detonation Damage Effect") detonation_damage_effect_reference;
	float nicename("Detonation Delay min") detonation_delay_min;
	float nicename("Detonation Delay max") detonation_delay_max;
	s_tag_reference_legacy nicename("Detonating Effect") detonating_effect_reference;
	s_tag_reference_legacy nicename("Detonation Effect") detonation_effect_reference;
	float nicename("Global Ground Scale") global_ground_scale;
	float nicename("Small Hold Scale") small_hold_scale;
	float nicename("Small Holster Scale") small_holster_scale;
	float nicename("Large Hold Scale") large_hold_scale;
	float nicename("Large Holster Scale") large_holster_scale;
	float nicename("Medium Hold Scale") medium_hold_scale;
	float nicename("Medium Holster Scale") medium_holster_scale;
	float nicename("Huge Hold Scale") huge_hold_scale;
	float nicename("Huge Holster Scale") huge_holster_scale;
	s_tag_reference_legacy nicename("Grounded Friction") grounded_friction_reference;
	// EQUIPMENT : 
	float nicename("Use Delay") use_delay;
	float nicename("Use Duration") use_duration;
	float __unknown4;
	s_undefined32_legacy __unknown5;
	float nicename("Recharge Delay") recharge_delay;
	float nicename("Minimum Charge Fraction") minimum_charge_fraction;
	float nicename("Initial Energy Use Amount") initial_energy_use_amount;
	float nicename("Final Energy Use Amount") final_energy_use_amount;
	float nicename("Active Energy Use Amount") active_energy_use_amount;
	float nicename("Recharge Rate") recharge_rate;
	s_data_reference_legacy nicename("Dynamic Charge Function") dynamic_charge_function_data_reference;
	float nicename("Dynamic Charge Rate") dynamic_charge_rate;
	b_flags2 nicename("Flags") flags2;
	e_equipment_type nicename("Equipment Type") equipment_type;
	e_activation_type nicename("Activation Type") activation_type;
	int8_t __unknown6;
	string_id nicename("Biped Stow Marker") biped_stow_marker;
	s_colorf_legacy nicename("Primary Color") primary_color;
	s_colorf_legacy nicename("Secondary Color") secondary_color;
	s_undefined32_legacy __unknown7;
	s_undefined32_legacy __unknown8;
	float __unknown9;
	string_id __unknown10;
	s_tag_block_legacy<s_equipment_camera_definition> nicename("Equipment Camera") equipment_camera_block;
	s_tag_block_legacy<s_powerup_definition> nicename("Powerup") powerup_block;
	s_tag_block_legacy<s_object_creation_definition> nicename("Object Creation") object_creation_block;
	s_tag_block_legacy<s_destruction_definition> nicename("Destruction") destruction_block;
	s_tag_block_legacy<s_radar_manipulation_definition> nicename("Radar Manipulation") radar_manipulation_block;
	s_undefined32_legacy __unknown11;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_tag_block_legacy<s_armor_lockup_definition> nicename("Armor Lockup") armor_lockup_block;
	s_tag_block_legacy<s_regenerator_definition> nicename("Regenerator") regenerator_block;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
	s_undefined32_legacy __unknown16;
	s_tag_block_legacy<s_runtime_definition> nicename("Runtime") runtime_block;
	s_tag_block_legacy<s_invisibility_unknown_definition> nicename("Invisibility Unknown") invisibility_unknown_block;
	s_undefined32_legacy __unknown17;
	s_undefined32_legacy __unknown18;
	s_undefined32_legacy __unknown19;
	s_undefined32_legacy __unknown20;
	s_undefined32_legacy __unknown21;
	s_undefined32_legacy __unknown22;
	s_undefined32_legacy __unknown23;
	s_undefined32_legacy __unknown24;
	s_undefined32_legacy __unknown25;
	s_undefined32_legacy __unknown26;
	s_undefined32_legacy __unknown27;
	s_undefined32_legacy __unknown28;
	s_undefined32_legacy __unknown29;
	s_undefined32_legacy __unknown30;
	s_undefined32_legacy __unknown31;
	s_undefined32_legacy __unknown32;
	s_undefined32_legacy __unknown33;
	s_undefined32_legacy __unknown34;
	s_undefined32_legacy __unknown35;
	s_undefined32_legacy __unknown36;
	s_undefined32_legacy __unknown37;
	s_tag_block_legacy<s_jetpack_definition> nicename("Jetpack") jetpack_block;
	s_tag_block_legacy<s_hologram_properties_definition> nicename("Hologram Properties") hologram_properties_block;
	s_undefined32_legacy __unknown38;
	s_undefined32_legacy __unknown39;
	s_undefined32_legacy __unknown40;
	s_tag_block_legacy<s_evade_definition> nicename("Evade") evade_block;
	s_undefined32_legacy __unknown41;
	s_undefined32_legacy __unknown42;
	s_undefined32_legacy __unknown43;
	s_tag_block_legacy<s_sprint_definition> nicename("Sprint") sprint_block;
	e_damage_reporting_type nicename("Damage Reporting Type") damage_reporting_type;
	int8_t __unknown44;
	int8_t __unknown45;
	int8_t __unknown46;
	s_tag_reference_legacy nicename("HUD Interface") hud_interface_reference;
	s_tag_reference_legacy nicename("Pickup Sound") pickup_sound_reference;
	s_tag_reference_legacy nicename("Empty Sound") empty_sound_reference;
	s_tag_reference_legacy nicename("Activation Effect") activation_effect_reference;
	s_tag_reference_legacy nicename("Active Effect") active_effect_reference;
	s_tag_reference_legacy nicename("Deactivation Effect") deactivation_effect_reference;
	s_tag_reference_legacy __unknown47;
	string_id nicename("Enter Animation") enter_animation;
	string_id nicename("Idle Animation") idle_animation;
	string_id nicename("Exit Animation") exit_animation;
	s_undefined32_legacy __unknown48;
};

