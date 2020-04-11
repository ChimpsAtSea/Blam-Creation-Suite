#pragma once

struct nicename("effect") tag_group('effe') s_effect_definition
{
	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _flags_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Dark Casings?")*/ _flags_dark_casings = 1ui32 << 10ui32,
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

	struct nicename("Locations") s_locations_definition
	{
		string_id_legacy nicename("Marker Name") marker_name;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
	};

	struct nicename("Events") s_events_definition
	{
		struct nicename("Parts") s_parts_definition
		{
			enum nicename("Create In Environment") e_create_in_environment : uint16_t
			{
				/*nicename("Any Environment")*/ _create_in_environment_any_environment = 0ui16,
				/*nicename("Air Only")*/ _create_in_environment_air_only = 1ui16,
				/*nicename("Water Only")*/ _create_in_environment_water_only = 2ui16,
				/*nicename("Space Only")*/ _create_in_environment_space_only = 3ui16,
			};

			enum nicename("Create In Disposition") e_create_in_disposition : uint16_t
			{
				/*nicename("Either Mode")*/ _create_in_disposition_either_mode = 0ui16,
				/*nicename("Violent Mode Only")*/ _create_in_disposition_violent_mode_only = 1ui16,
				/*nicename("Nonviolent Mode Only")*/ _create_in_disposition_nonviolent_mode_only = 2ui16,
			};

			enum nicename("Camera Mode") e_camera_mode : uint8_t
			{
				/*nicename("Independent Of Camera Mode")*/ _camera_mode_independent_of_camera_mode = 0ui8,
				/*nicename("First Person Only")*/ _camera_mode_first_person_only = 1ui8,
				/*nicename("Third Person Only")*/ _camera_mode_third_person_only = 2ui8,
				/*nicename("Both First And Third")*/ _camera_mode_both_first_and_third = 3ui8,
			};

			enum nicename("Damage Reporting Type") e_damage_reporting_type : uint8_t
			{
				/*nicename("Guardians (Unknown)")*/ _damage_reporting_type_guardians_unknown = 0ui8,
				/*nicename("Guardians")*/ _damage_reporting_type_guardians = 1ui8,
				/*nicename("Guardians (Scripting)")*/ _damage_reporting_type_guardians_scripting = 2ui8,
				/*nicename("Suicide")*/ _damage_reporting_type_suicide = 3ui8,
				/*nicename("Magnum")*/ _damage_reporting_type_magnum = 4ui8,
				/*nicename("Assault Rifle")*/ _damage_reporting_type_assault_rifle = 5ui8,
				/*nicename("DMR")*/ _damage_reporting_type_dmr = 6ui8,
				/*nicename("Shotgun")*/ _damage_reporting_type_shotgun = 7ui8,
				/*nicename("Sniper Rifle")*/ _damage_reporting_type_sniper_rifle = 8ui8,
				/*nicename("Rocket Launcher")*/ _damage_reporting_type_rocket_launcher = 9ui8,
				/*nicename("Spartan Laser")*/ _damage_reporting_type_spartan_laser = 10ui8,
				/*nicename("Frag Grenade")*/ _damage_reporting_type_frag_grenade = 11ui8,
				/*nicename("Grenade Launcher")*/ _damage_reporting_type_grenade_launcher = 12ui8,
				/*nicename("Plasma Pistol")*/ _damage_reporting_type_plasma_pistol = 13ui8,
				/*nicename("Needler")*/ _damage_reporting_type_needler = 14ui8,
				/*nicename("Plasma Rifle")*/ _damage_reporting_type_plasma_rifle = 15ui8,
				/*nicename("Plasma Repeater")*/ _damage_reporting_type_plasma_repeater = 16ui8,
				/*nicename("Needle Rifle")*/ _damage_reporting_type_needle_rifle = 17ui8,
				/*nicename("Spiker")*/ _damage_reporting_type_spiker = 18ui8,
				/*nicename("Plasma Launcher")*/ _damage_reporting_type_plasma_launcher = 19ui8,
				/*nicename("Gravity Hammer")*/ _damage_reporting_type_gravity_hammer = 20ui8,
				/*nicename("Energy Sword")*/ _damage_reporting_type_energy_sword = 21ui8,
				/*nicename("Plasma Grenade")*/ _damage_reporting_type_plasma_grenade = 22ui8,
				/*nicename("Concussion Rifle")*/ _damage_reporting_type_concussion_rifle = 23ui8,
				/*nicename("Ghost")*/ _damage_reporting_type_ghost = 24ui8,
				/*nicename("Revenant")*/ _damage_reporting_type_revenant = 25ui8,
				/*nicename("Revenant Gunner")*/ _damage_reporting_type_revenant_gunner = 26ui8,
				/*nicename("Wraith")*/ _damage_reporting_type_wraith = 27ui8,
				/*nicename("Wraith Turret")*/ _damage_reporting_type_wraith_turret = 28ui8,
				/*nicename("Banshee")*/ _damage_reporting_type_banshee = 29ui8,
				/*nicename("Banshee Bomb")*/ _damage_reporting_type_banshee_bomb = 30ui8,
				/*nicename("Seraph")*/ _damage_reporting_type_seraph = 31ui8,
				/*nicename("Mongoose")*/ _damage_reporting_type_mongoose = 32ui8,
				/*nicename("Warthog")*/ _damage_reporting_type_warthog = 33ui8,
				/*nicename("Warthog Chaingun")*/ _damage_reporting_type_warthog_chaingun = 34ui8,
				/*nicename("Warthog Gauss")*/ _damage_reporting_type_warthog_gauss = 35ui8,
				/*nicename("Warthog Rocket")*/ _damage_reporting_type_warthog_rocket = 36ui8,
				/*nicename("Scorpion")*/ _damage_reporting_type_scorpion = 37ui8,
				/*nicename("Scorpion Turret")*/ _damage_reporting_type_scorpion_turret = 38ui8,
				/*nicename("Falcon")*/ _damage_reporting_type_falcon = 39ui8,
				/*nicename("Falcon Gunner")*/ _damage_reporting_type_falcon_gunner = 40ui8,
				/*nicename("Falling")*/ _damage_reporting_type_falling = 41ui8,
				/*nicename("Collision")*/ _damage_reporting_type_collision = 42ui8,
				/*nicename("Melee")*/ _damage_reporting_type_melee = 43ui8,
				/*nicename("Explosion")*/ _damage_reporting_type_explosion = 44ui8,
				/*nicename("Birthday Explosion")*/ _damage_reporting_type_birthday_explosion = 45ui8,
				/*nicename("Flag")*/ _damage_reporting_type_flag = 46ui8,
				/*nicename("Bomb")*/ _damage_reporting_type_bomb = 47ui8,
				/*nicename("Bomb Explosion")*/ _damage_reporting_type_bomb_explosion = 48ui8,
				/*nicename("Ball")*/ _damage_reporting_type_ball = 49ui8,
				/*nicename("Teleporter")*/ _damage_reporting_type_teleporter = 50ui8,
				/*nicename("Transfer Damage")*/ _damage_reporting_type_transfer_damage = 51ui8,
				/*nicename("Armor Lock")*/ _damage_reporting_type_armor_lock = 52ui8,
				/*nicename("Target Locator")*/ _damage_reporting_type_target_locator = 53ui8,
				/*nicename("Human Turret")*/ _damage_reporting_type_human_turret = 54ui8,
				/*nicename("Plasma Cannon")*/ _damage_reporting_type_plasma_cannon = 55ui8,
				/*nicename("Plasma Mortar")*/ _damage_reporting_type_plasma_mortar = 56ui8,
				/*nicename("Plasma Turret")*/ _damage_reporting_type_plasma_turret = 57ui8,
				/*nicename("Shade Turret")*/ _damage_reporting_type_shade_turret = 58ui8,
				/*nicename("Sabre")*/ _damage_reporting_type_sabre = 59ui8,
				/*nicename("SMG")*/ _damage_reporting_type_smg = 60ui8,
				/*nicename("Carbine")*/ _damage_reporting_type_carbine = 61ui8,
				/*nicename("Battle Rifle")*/ _damage_reporting_type_battle_rifle = 62ui8,
				/*nicename("Focus Rifle")*/ _damage_reporting_type_focus_rifle = 63ui8,
				/*nicename("Fuel Rod")*/ _damage_reporting_type_fuel_rod = 64ui8,
				/*nicename("Missile Pod")*/ _damage_reporting_type_missile_pod = 65ui8,
				/*nicename("Brute Shot")*/ _damage_reporting_type_brute_shot = 66ui8,
				/*nicename("Flamethrower")*/ _damage_reporting_type_flamethrower = 67ui8,
				/*nicename("Sentinel Gun")*/ _damage_reporting_type_sentinel_gun = 68ui8,
				/*nicename("Spike Grenade")*/ _damage_reporting_type_spike_grenade = 69ui8,
				/*nicename("Firebomb Grenade")*/ _damage_reporting_type_firebomb_grenade = 70ui8,
				/*nicename("Elephant Turret")*/ _damage_reporting_type_elephant_turret = 71ui8,
				/*nicename("Spectre")*/ _damage_reporting_type_spectre = 72ui8,
				/*nicename("Spectre Gunner")*/ _damage_reporting_type_spectre_gunner = 73ui8,
				/*nicename("Tank")*/ _damage_reporting_type_tank = 74ui8,
				/*nicename("Chopper")*/ _damage_reporting_type_chopper = 75ui8,
				/*nicename("Falcon")*/ _damage_reporting_type_falcon1 = 76ui8,
				/*nicename("Mantis")*/ _damage_reporting_type_mantis = 77ui8,
				/*nicename("Prowler")*/ _damage_reporting_type_prowler = 78ui8,
				/*nicename("Sentinel Beam")*/ _damage_reporting_type_sentinel_beam = 79ui8,
				/*nicename("Sentinel RPG")*/ _damage_reporting_type_sentinel_rpg = 80ui8,
				/*nicename("Tripmine")*/ _damage_reporting_type_tripmine = 81ui8,
			};

			enum nicename("A Scales Values") b_a_scales_values : uint32_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _a_scales_values_bit_0 = 1ui32 << 0ui32,
				/*nicename("Bit 1")*/ _a_scales_values_bit_1 = 1ui32 << 1ui32,
				/*nicename("Bit 2")*/ _a_scales_values_bit_2 = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _a_scales_values_bit_3 = 1ui32 << 3ui32,
				/*nicename("Bit 4")*/ _a_scales_values_bit_4 = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _a_scales_values_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _a_scales_values_bit_6 = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _a_scales_values_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _a_scales_values_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _a_scales_values_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _a_scales_values_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _a_scales_values_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _a_scales_values_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _a_scales_values_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _a_scales_values_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _a_scales_values_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _a_scales_values_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _a_scales_values_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _a_scales_values_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _a_scales_values_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _a_scales_values_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _a_scales_values_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _a_scales_values_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _a_scales_values_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _a_scales_values_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _a_scales_values_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _a_scales_values_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _a_scales_values_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _a_scales_values_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _a_scales_values_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _a_scales_values_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _a_scales_values_bit_31 = 1ui32 << 31ui32,
			};

			enum nicename("B Scales Values") b_b_scales_values : uint32_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _b_scales_values_bit_0 = 1ui32 << 0ui32,
				/*nicename("Bit 1")*/ _b_scales_values_bit_1 = 1ui32 << 1ui32,
				/*nicename("Bit 2")*/ _b_scales_values_bit_2 = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _b_scales_values_bit_3 = 1ui32 << 3ui32,
				/*nicename("Bit 4")*/ _b_scales_values_bit_4 = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _b_scales_values_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _b_scales_values_bit_6 = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _b_scales_values_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _b_scales_values_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _b_scales_values_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _b_scales_values_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _b_scales_values_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _b_scales_values_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _b_scales_values_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _b_scales_values_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _b_scales_values_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _b_scales_values_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _b_scales_values_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _b_scales_values_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _b_scales_values_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _b_scales_values_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _b_scales_values_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _b_scales_values_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _b_scales_values_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _b_scales_values_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _b_scales_values_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _b_scales_values_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _b_scales_values_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _b_scales_values_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _b_scales_values_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _b_scales_values_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _b_scales_values_bit_31 = 1ui32 << 31ui32,
			};

			e_create_in_environment nicename("Create In Environment") create_in_environment;
			e_create_in_disposition nicename("Create In Disposition") create_in_disposition;
			int16_t nicename("Location Index") location_index;
			int16_t __unknown0;
			int16_t __unknown1;
			int8_t __unknown2;
			e_camera_mode nicename("Camera Mode") camera_mode;
			// Anticipated Tag Class Note : For objects, use "ejbo" instead of the class. Otherwise, use the tag class but reversed (due to endian)
			char nicename("Anticipated Tag Class") anticipated_tag_class[4];
			e_damage_reporting_type nicename("Damage Reporting Type") damage_reporting_type;
			int8_t __unknown3;
			int8_t __unknown4;
			int8_t __unknown5;
			s_tag_reference_legacy nicename("Spawned Tag") spawned_tag_reference;
			float nicename("Velocity Bounds min") velocity_bounds_min;
			float nicename("Velocity Bounds max") velocity_bounds_max;
			float __unknown6;
			float __unknown7;
			float nicename("Velocity Cone Angle") velocity_cone_angle;
			float nicename("Angular Velocity Bounds min") angular_velocity_bounds_min;
			float nicename("Angular Velocity Bounds max") angular_velocity_bounds_max;
			float nicename("Radius Modifier Bounds min") radius_modifier_bounds_min;
			float nicename("Radius Modifier Bounds max") radius_modifier_bounds_max;
			float nicename("Origin Offset X") origin_offset_x;
			float nicename("Origin Offset Y") origin_offset_y;
			float nicename("Origin Offset Z") origin_offset_z;
			float nicename("Origin Rotation i") origin_rotation_i;
			float nicename("Origin Rotation j") origin_rotation_j;
			b_a_scales_values nicename("A Scales Values") a_scales_values;
			b_b_scales_values nicename("B Scales Values") b_scales_values;
		};

		struct nicename("Accelerations") s_accelerations_definition
		{
			enum nicename("Create In Environment") e_create_in_environment : uint16_t
			{
				/*nicename("Any Environment")*/ _create_in_environment_any_environment = 0ui16,
				/*nicename("Air Only")*/ _create_in_environment_air_only = 1ui16,
				/*nicename("Water Only")*/ _create_in_environment_water_only = 2ui16,
				/*nicename("Space Only")*/ _create_in_environment_space_only = 3ui16,
			};

			enum nicename("Create In Disposition") e_create_in_disposition : uint16_t
			{
				/*nicename("Either Mode")*/ _create_in_disposition_either_mode = 0ui16,
				/*nicename("Violent Mode Only")*/ _create_in_disposition_violent_mode_only = 1ui16,
				/*nicename("Nonviolent Mode Only")*/ _create_in_disposition_nonviolent_mode_only = 2ui16,
			};

			e_create_in_environment nicename("Create In Environment") create_in_environment;
			e_create_in_disposition nicename("Create In Disposition") create_in_disposition;
			int16_t nicename("Location Index") location_index;
			int16_t __unknown0;
			float nicename("Acceleration") acceleration;
			float nicename("Inner Cone Angle") inner_cone_angle;
			float nicename("Outer Cone Angle") outer_cone_angle;
		};

		struct nicename("Particle Systems") s_particle_systems_definition
		{
			enum nicename("Coordinate System") e_coordinate_system : uint16_t
			{
				/*nicename("World")*/ _coordinate_system_world = 0ui16,
				/*nicename("Local")*/ _coordinate_system_local = 1ui16,
				/*nicename("Parent")*/ _coordinate_system_parent = 2ui16,
			};

			enum nicename("Environment") e_environment : uint16_t
			{
				/*nicename("Any Environment")*/ _environment_any_environment = 0ui16,
				/*nicename("Air Only")*/ _environment_air_only = 1ui16,
				/*nicename("Water Only")*/ _environment_water_only = 2ui16,
				/*nicename("Space Only")*/ _environment_space_only = 3ui16,
			};

			enum nicename("Disposition") e_disposition : uint16_t
			{
				/*nicename("Either Mode")*/ _disposition_either_mode = 0ui16,
				/*nicename("Violent Mode Only")*/ _disposition_violent_mode_only = 1ui16,
				/*nicename("Nonviolent Mode Only")*/ _disposition_nonviolent_mode_only = 2ui16,
			};

			enum nicename("Camera Mode") e_camera_mode : uint16_t
			{
				/*nicename("Independent Of Camera Mode")*/ _camera_mode_independent_of_camera_mode = 0ui16,
				/*nicename("First Person Only")*/ _camera_mode_first_person_only = 1ui16,
				/*nicename("Third Person Only")*/ _camera_mode_third_person_only = 2ui16,
				/*nicename("Both First And Third")*/ _camera_mode_both_first_and_third = 3ui16,
			};

			enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui16 << 0ui16,
				/*nicename("Bit 1")*/ _flags1_bit_1 = 1ui16 << 1ui16,
				/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui16 << 2ui16,
				/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui16 << 3ui16,
				/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui16 << 4ui16,
				/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui16 << 5ui16,
				/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui16 << 6ui16,
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

			struct nicename("Emitters") s_emitters_definition
			{
				enum nicename("Output Kind") e_output_kind : uint8_t
				{
					/*nicename("None")*/ _output_kind_none = 0ui8,
					/*nicename("Plus")*/ _output_kind_plus = 1ui8,
					/*nicename("Times")*/ _output_kind_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind1 : uint8_t
				{
					/*nicename("None")*/ _output_kind1_none = 0ui8,
					/*nicename("Plus")*/ _output_kind1_plus = 1ui8,
					/*nicename("Times")*/ _output_kind1_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind2 : uint8_t
				{
					/*nicename("None")*/ _output_kind2_none = 0ui8,
					/*nicename("Plus")*/ _output_kind2_plus = 1ui8,
					/*nicename("Times")*/ _output_kind2_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind3 : uint8_t
				{
					/*nicename("None")*/ _output_kind3_none = 0ui8,
					/*nicename("Plus")*/ _output_kind3_plus = 1ui8,
					/*nicename("Times")*/ _output_kind3_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind4 : uint8_t
				{
					/*nicename("None")*/ _output_kind4_none = 0ui8,
					/*nicename("Plus")*/ _output_kind4_plus = 1ui8,
					/*nicename("Times")*/ _output_kind4_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind5 : uint8_t
				{
					/*nicename("None")*/ _output_kind5_none = 0ui8,
					/*nicename("Plus")*/ _output_kind5_plus = 1ui8,
					/*nicename("Times")*/ _output_kind5_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind6 : uint8_t
				{
					/*nicename("None")*/ _output_kind6_none = 0ui8,
					/*nicename("Plus")*/ _output_kind6_plus = 1ui8,
					/*nicename("Times")*/ _output_kind6_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind7 : uint8_t
				{
					/*nicename("None")*/ _output_kind7_none = 0ui8,
					/*nicename("Plus")*/ _output_kind7_plus = 1ui8,
					/*nicename("Times")*/ _output_kind7_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind8 : uint8_t
				{
					/*nicename("None")*/ _output_kind8_none = 0ui8,
					/*nicename("Plus")*/ _output_kind8_plus = 1ui8,
					/*nicename("Times")*/ _output_kind8_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind9 : uint8_t
				{
					/*nicename("None")*/ _output_kind9_none = 0ui8,
					/*nicename("Plus")*/ _output_kind9_plus = 1ui8,
					/*nicename("Times")*/ _output_kind9_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind10 : uint8_t
				{
					/*nicename("None")*/ _output_kind10_none = 0ui8,
					/*nicename("Plus")*/ _output_kind10_plus = 1ui8,
					/*nicename("Times")*/ _output_kind10_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind11 : uint8_t
				{
					/*nicename("None")*/ _output_kind11_none = 0ui8,
					/*nicename("Plus")*/ _output_kind11_plus = 1ui8,
					/*nicename("Times")*/ _output_kind11_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind12 : uint8_t
				{
					/*nicename("None")*/ _output_kind12_none = 0ui8,
					/*nicename("Plus")*/ _output_kind12_plus = 1ui8,
					/*nicename("Times")*/ _output_kind12_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind13 : uint8_t
				{
					/*nicename("None")*/ _output_kind13_none = 0ui8,
					/*nicename("Plus")*/ _output_kind13_plus = 1ui8,
					/*nicename("Times")*/ _output_kind13_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind14 : uint8_t
				{
					/*nicename("None")*/ _output_kind14_none = 0ui8,
					/*nicename("Plus")*/ _output_kind14_plus = 1ui8,
					/*nicename("Times")*/ _output_kind14_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind15 : uint8_t
				{
					/*nicename("None")*/ _output_kind15_none = 0ui8,
					/*nicename("Plus")*/ _output_kind15_plus = 1ui8,
					/*nicename("Times")*/ _output_kind15_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind16 : uint8_t
				{
					/*nicename("None")*/ _output_kind16_none = 0ui8,
					/*nicename("Plus")*/ _output_kind16_plus = 1ui8,
					/*nicename("Times")*/ _output_kind16_times = 2ui8,
				};

				enum nicename("Output Kind") e_output_kind17 : uint8_t
				{
					/*nicename("None")*/ _output_kind17_none = 0ui8,
					/*nicename("Plus")*/ _output_kind17_plus = 1ui8,
					/*nicename("Times")*/ _output_kind17_times = 2ui8,
				};

				enum b_unknown : uint16_t /* bitfield */
				{
					/*nicename("Bit 0")*/ _unknown_bit_0 = 1ui16 << 0ui16,
					/*nicename("Bit 1")*/ _unknown_bit_1 = 1ui16 << 1ui16,
					/*nicename("Bit 2")*/ _unknown_bit_2 = 1ui16 << 2ui16,
					/*nicename("Bit 3")*/ _unknown_bit_3 = 1ui16 << 3ui16,
					/*nicename("Bit 4")*/ _unknown_bit_4 = 1ui16 << 4ui16,
					/*nicename("Bit 5")*/ _unknown_bit_5 = 1ui16 << 5ui16,
					/*nicename("Bit 6")*/ _unknown_bit_6 = 1ui16 << 6ui16,
					/*nicename("Bit 7")*/ _unknown_bit_7 = 1ui16 << 7ui16,
					/*nicename("Bit 8")*/ _unknown_bit_8 = 1ui16 << 8ui16,
					/*nicename("Bit 9")*/ _unknown_bit_9 = 1ui16 << 9ui16,
					/*nicename("Bit 10")*/ _unknown_bit_10 = 1ui16 << 10ui16,
					/*nicename("Bit 11")*/ _unknown_bit_11 = 1ui16 << 11ui16,
					/*nicename("Bit 12")*/ _unknown_bit_12 = 1ui16 << 12ui16,
					/*nicename("Bit 13")*/ _unknown_bit_13 = 1ui16 << 13ui16,
					/*nicename("Bit 14")*/ _unknown_bit_14 = 1ui16 << 14ui16,
					/*nicename("Bit 15")*/ _unknown_bit_15 = 1ui16 << 15ui16,
				};

				struct nicename("Unknown") s_unknown_definition
				{
					struct nicename("Unknown") s_unknown1_definition
					{
						enum nicename("Output Kind") e_output_kind : uint8_t
						{
							/*nicename("None")*/ _output_kind_none = 0ui8,
							/*nicename("Plus")*/ _output_kind_plus = 1ui8,
							/*nicename("Times")*/ _output_kind_times = 2ui8,
						};

						s_undefined32_legacy __unknown0;
						int8_t nicename("Input") input;
						int8_t nicename("Input Range") input_range;
						e_output_kind nicename("Output Kind") output_kind;
						int8_t nicename("Output") output;
						s_data_reference_legacy __unknown1;
						s_undefined32_legacy __unknown2;
						s_undefined32_legacy __unknown3;
					};

					int32_t __unknown0;
					s_tag_block_legacy<s_unknown1_definition> __unknown1;
					s_undefined32_legacy __unknown2;
					s_undefined32_legacy __unknown3;
				};

				string_id_legacy nicename("Name") name;
				b_unknown __unknown0;
				int16_t __unknown1;
				s_undefined32_legacy __unknown2;
				s_tag_reference_legacy nicename("Custom Emitter Points") custom_emitter_points_reference;
				s_tag_reference_legacy __unknown3;
				s_undefined32_legacy __unknown4;
				s_undefined32_legacy __unknown5;
				s_undefined32_legacy __unknown6;
				s_undefined32_legacy __unknown7;
				s_undefined32_legacy __unknown8;
				s_undefined32_legacy __unknown9;
				s_undefined32_legacy __unknown10;
				int8_t nicename("Input") input;
				int8_t nicename("Input Range") input_range;
				e_output_kind nicename("Output Kind") output_kind;
				int8_t nicename("Output") output;
				s_data_reference_legacy __unknown11;
				s_undefined32_legacy __unknown12;
				s_undefined32_legacy __unknown13;
				s_undefined32_legacy __unknown14;
				s_undefined32_legacy __unknown15;
				s_undefined32_legacy __unknown16;
				s_undefined32_legacy __unknown17;
				s_undefined32_legacy __unknown18;
				s_undefined32_legacy __unknown19;
				int8_t nicename("Input") input1;
				int8_t nicename("Input Range") input_range1;
				e_output_kind1 nicename("Output Kind") output_kind1;
				int8_t nicename("Output") output1;
				s_data_reference_legacy __unknown20;
				s_undefined32_legacy __unknown21;
				s_undefined32_legacy __unknown22;
				s_undefined32_legacy __unknown23;
				s_undefined32_legacy __unknown24;
				s_undefined32_legacy __unknown25;
				s_undefined32_legacy __unknown26;
				s_undefined32_legacy __unknown27;
				s_undefined32_legacy __unknown28;
				int8_t nicename("Input") input2;
				int8_t nicename("Input Range") input_range2;
				e_output_kind2 nicename("Output Kind") output_kind2;
				int8_t nicename("Output") output2;
				s_data_reference_legacy __unknown29;
				s_undefined32_legacy __unknown30;
				s_undefined32_legacy __unknown31;
				int8_t nicename("Input") input3;
				int8_t nicename("Input Range") input_range3;
				e_output_kind3 nicename("Output Kind") output_kind3;
				int8_t nicename("Output") output3;
				s_data_reference_legacy __unknown32;
				s_undefined32_legacy __unknown33;
				s_undefined32_legacy __unknown34;
				int8_t nicename("Input") input4;
				int8_t nicename("Input Range") input_range4;
				e_output_kind4 nicename("Output Kind") output_kind4;
				int8_t nicename("Output") output4;
				s_data_reference_legacy __unknown35;
				s_undefined32_legacy __unknown36;
				s_undefined32_legacy __unknown37;
				int8_t nicename("Input") input5;
				int8_t nicename("Input Range") input_range5;
				e_output_kind5 nicename("Output Kind") output_kind5;
				int8_t nicename("Output") output5;
				s_data_reference_legacy __unknown38;
				s_undefined32_legacy __unknown39;
				s_undefined32_legacy __unknown40;
				int8_t nicename("Input") input6;
				int8_t nicename("Input Range") input_range6;
				e_output_kind6 nicename("Output Kind") output_kind6;
				int8_t nicename("Output") output6;
				s_data_reference_legacy __unknown41;
				s_undefined32_legacy __unknown42;
				s_undefined32_legacy __unknown43;
				int8_t nicename("Input") input7;
				int8_t nicename("Input Range") input_range7;
				e_output_kind7 nicename("Output Kind") output_kind7;
				int8_t nicename("Output") output7;
				s_data_reference_legacy __unknown44;
				s_undefined32_legacy __unknown45;
				s_undefined32_legacy __unknown46;
				int8_t nicename("Input") input8;
				int8_t nicename("Input Range") input_range8;
				e_output_kind8 nicename("Output Kind") output_kind8;
				int8_t nicename("Output") output8;
				s_data_reference_legacy __unknown47;
				s_undefined32_legacy __unknown48;
				s_undefined32_legacy __unknown49;
				s_tag_reference_legacy nicename("Particle Physics") particle_physics_reference;
				s_undefined32_legacy __unknown50;
				s_tag_block_legacy<s_unknown_definition> __unknown51;
				s_tag_reference_legacy nicename("Displacement Map") displacement_map_reference;
				int8_t nicename("Input") input9;
				int8_t nicename("Input Range") input_range9;
				e_output_kind9 nicename("Output Kind") output_kind9;
				int8_t nicename("Output") output9;
				s_data_reference_legacy __unknown52;
				s_undefined32_legacy __unknown53;
				s_undefined32_legacy __unknown54;
				s_undefined32_legacy __unknown55;
				s_undefined32_legacy __unknown56;
				s_undefined32_legacy __unknown57;
				s_undefined32_legacy __unknown58;
				s_undefined32_legacy __unknown59;
				s_undefined32_legacy __unknown60;
				int8_t nicename("Input") input10;
				int8_t nicename("Input Range") input_range10;
				e_output_kind10 nicename("Output Kind") output_kind10;
				int8_t nicename("Output") output10;
				s_data_reference_legacy __unknown61;
				s_undefined32_legacy __unknown62;
				s_undefined32_legacy __unknown63;
				int8_t nicename("Input") input11;
				int8_t nicename("Input Range") input_range11;
				e_output_kind11 nicename("Output Kind") output_kind11;
				int8_t nicename("Output") output11;
				s_data_reference_legacy __unknown64;
				s_undefined32_legacy __unknown65;
				s_undefined32_legacy __unknown66;
				int8_t nicename("Input") input12;
				int8_t nicename("Input Range") input_range12;
				e_output_kind12 nicename("Output Kind") output_kind12;
				int8_t nicename("Output") output12;
				s_data_reference_legacy __unknown67;
				s_undefined32_legacy __unknown68;
				s_undefined32_legacy __unknown69;
				int8_t nicename("Input") input13;
				int8_t nicename("Input Range") input_range13;
				e_output_kind13 nicename("Output Kind") output_kind13;
				int8_t nicename("Output") output13;
				s_data_reference_legacy __unknown70;
				s_undefined32_legacy __unknown71;
				s_undefined32_legacy __unknown72;
				int8_t nicename("Input") input14;
				int8_t nicename("Input Range") input_range14;
				e_output_kind14 nicename("Output Kind") output_kind14;
				int8_t nicename("Output") output14;
				s_data_reference_legacy nicename("Particle Scale") particle_scale_data_reference;
				s_undefined32_legacy __unknown73;
				s_undefined32_legacy __unknown74;
				int8_t nicename("Input") input15;
				int8_t nicename("Input Range") input_range15;
				e_output_kind15 nicename("Output Kind") output_kind15;
				int8_t nicename("Output") output15;
				s_data_reference_legacy nicename("Particle Tint") particle_tint_data_reference;
				s_undefined32_legacy __unknown75;
				s_undefined32_legacy __unknown76;
				int8_t nicename("Input") input16;
				int8_t nicename("Input Range") input_range16;
				e_output_kind16 nicename("Output Kind") output_kind16;
				int8_t nicename("Output") output16;
				s_data_reference_legacy nicename("Particle Alpha") particle_alpha_data_reference;
				s_undefined32_legacy __unknown77;
				s_undefined32_legacy __unknown78;
				int8_t nicename("Input") input17;
				int8_t nicename("Input Range") input_range17;
				e_output_kind17 nicename("Output Kind") output_kind17;
				int8_t nicename("Output") output17;
				s_data_reference_legacy nicename("Particle Alpha Black Point") particle_alpha_black_point_data_reference;
				s_undefined32_legacy __unknown79;
				s_undefined32_legacy __unknown80;
				int32_t __unknown81;
				int32_t __unknown82;
				int32_t __unknown83;
				int32_t nicename("Compiled Scenario Index") compiled_scenario_index;
				s_undefined32_legacy __unknown84;
				s_undefined32_legacy __unknown85;
				s_undefined32_legacy __unknown86;
			};

			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			s_tag_reference_legacy nicename("Particle") particle_reference;
			int16_t __unknown4;
			int16_t nicename("Location Index") location_index;
			e_coordinate_system nicename("Coordinate System") coordinate_system;
			e_environment nicename("Environment") environment;
			e_disposition nicename("Disposition") disposition;
			e_camera_mode nicename("Camera Mode") camera_mode;
			int16_t nicename("Sort Bias") sort_bias;
			b_flags1 nicename("Flags") flags;
			int16_t __unknown5;
			int16_t __unknown6;
			float __unknown7;
			float __unknown8;
			float __unknown9;
			float __unknown10;
			float nicename("Minimum View Distance 1") minimum_view_distance_1;
			float nicename("Minimum View Distance 2") minimum_view_distance_2;
			float __unknown11;
			float __unknown12;
			float __unknown13;
			float nicename("Maximum Viewing Distance") maximum_viewing_distance;
			float nicename("LOD In Distance") lod_in_distance;
			float nicename("LOD Feather In Delta") lod_feather_in_delta;
			float __unknown14;
			s_tag_block_legacy<s_emitters_definition> nicename("Emitters") emitters_block;
			float __unknown15;
			float __unknown16;
		};

		string_id_legacy nicename("Name") name;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		float nicename("Skip Fraction") skip_fraction;
		float nicename("Delay Bounds min") delay_bounds_min;
		float nicename("Delay Bounds max") delay_bounds_max;
		float nicename("Duration Bounds min") duration_bounds_min;
		float nicename("Duration Bounds max") duration_bounds_max;
		s_tag_block_legacy<s_parts_definition> nicename("Parts") parts_block;
		s_tag_block_legacy<s_accelerations_definition> nicename("Accelerations") accelerations_block;
		s_tag_block_legacy<s_particle_systems_definition> nicename("Particle Systems") particle_systems_block;
	};

	struct nicename("Looping Sounds") s_looping_sounds_definition
	{
		s_tag_reference_legacy nicename("Looping Sound") looping_sound_reference;
		int16_t nicename("Location Index") location_index;
		int16_t nicename("Event Index") event_index;
	};

	b_flags nicename("Flags") flags;
	int32_t __unknown0;
	float __unknown1;
	s_undefined32_legacy __unknown2;
	float __unknown3;
	int8_t __unknown4;
	int8_t __unknown5;
	int8_t __unknown6;
	int8_t __unknown7;
	int16_t __unknown8;
	int16_t __unknown9;
	s_undefined32_legacy __unknown10;
	s_tag_block_legacy<s_locations_definition> nicename("Locations") locations_block;
	s_tag_block_legacy<s_events_definition> nicename("Events") events_block;
	s_tag_block_legacy<s_looping_sounds_definition> nicename("Looping Sounds") looping_sounds_block;
	float nicename("Always Play Distance") always_play_distance;
	float nicename("Never Play Distance") never_play_distance;
	float __unknown11;
	float __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
};

