#pragma once

struct nicename("vehicle") group('vehi') s_vehicle_definition
{
	enum nicename("Object Type") e_object_type : uint16_t
	{
		/*nicename("Biped")*/ _object_type_biped = 0ui16,
		/*nicename("Vehicle")*/ _object_type_vehicle = 1ui16,
		/*nicename("Weapon")*/ _object_type_weapon = 2ui16,
		/*nicename("Equipment")*/ _object_type_equipment = 3ui16,
		/*nicename("Terminal")*/ _object_type_terminal = 4ui16,
		/*nicename("Projectile")*/ _object_type_projectile = 5ui16,
		/*nicename("Scenery")*/ _object_type_scenery = 6ui16,
		/*nicename("Machine")*/ _object_type_machine = 7ui16,
		/*nicename("Control")*/ _object_type_control = 8ui16,
		/*nicename("Sound Scenery")*/ _object_type_sound_scenery = 9ui16,
		/*nicename("Crate")*/ _object_type_crate = 10ui16,
		/*nicename("Creature")*/ _object_type_creature = 11ui16,
		/*nicename("Giant")*/ _object_type_giant = 12ui16,
		/*nicename("Effect Scenery")*/ _object_type_effect_scenery = 13ui16,
	};

	enum nicename("Lightmap Shadow Mode Size") e_lightmap_shadow_mode_size : uint16_t
	{
		/*nicename("Default")*/ _lightmap_shadow_mode_size_default = 0ui16,
		/*nicename("Never")*/ _lightmap_shadow_mode_size_never = 1ui16,
		/*nicename("Always")*/ _lightmap_shadow_mode_size_always = 2ui16,
		/*nicename("Unknown")*/ _lightmap_shadow_mode_size_unknown = 3ui16,
	};

	enum nicename("Sweetener Size") e_sweetener_size : uint8_t
	{
		/*nicename("Small")*/ _sweetener_size_small = 0ui8,
		/*nicename("Medium")*/ _sweetener_size_medium = 1ui8,
		/*nicename("Large")*/ _sweetener_size_large = 2ui8,
	};

	enum nicename("Water Density") e_water_density : uint8_t
	{
		/*nicename("Default")*/ _water_density_default = 0ui8,
		/*nicename("Least")*/ _water_density_least = 1ui8,
		/*nicename("Some")*/ _water_density_some = 2ui8,
		/*nicename("Equal")*/ _water_density_equal = 3ui8,
		/*nicename("More")*/ _water_density_more = 4ui8,
		/*nicename("More Still")*/ _water_density_more_still = 5ui8,
		/*nicename("Lots More")*/ _water_density_lots_more = 6ui8,
	};

	enum nicename("Team") e_team : uint16_t
	{
		/*nicename("Default")*/ _team_default = 0ui16,
		/*nicename("Player")*/ _team_player = 1ui16,
		/*nicename("Human")*/ _team_human = 2ui16,
		/*nicename("Covenant")*/ _team_covenant = 3ui16,
		/*nicename("Brute")*/ _team_brute = 4ui16,
		/*nicename("Mule")*/ _team_mule = 5ui16,
		/*nicename("Spare")*/ _team_spare = 6ui16,
		/*nicename("Covenant Player")*/ _team_covenant_player = 7ui16,
	};

	enum nicename("Constant Sound Volume") e_constant_sound_volume : uint16_t
	{
		/*nicename("Silent")*/ _constant_sound_volume_silent = 0ui16,
		/*nicename("Medium")*/ _constant_sound_volume_medium = 1ui16,
		/*nicename("Loud")*/ _constant_sound_volume_loud = 2ui16,
		/*nicename("Shout")*/ _constant_sound_volume_shout = 3ui16,
		/*nicename("Quiet")*/ _constant_sound_volume_quiet = 4ui16,
	};

	enum nicename("Motion Sensor Blip Size") e_motion_sensor_blip_size : uint16_t
	{
		/*nicename("Medium")*/ _motion_sensor_blip_size_medium = 0ui16,
		/*nicename("Small")*/ _motion_sensor_blip_size_small = 1ui16,
		/*nicename("Large")*/ _motion_sensor_blip_size_large = 2ui16,
	};

	enum nicename("Item Scale") e_item_scale : uint16_t
	{
		/*nicename("Small")*/ _item_scale_small = 0ui16,
		/*nicename("Medium")*/ _item_scale_medium = 1ui16,
		/*nicename("Large")*/ _item_scale_large = 2ui16,
		/*nicename("Huge")*/ _item_scale_huge = 3ui16,
	};

	enum nicename("Grenade Type") e_grenade_type : uint16_t
	{
		/*nicename("Human Fragmentation")*/ _grenade_type_human_fragmentation = 0ui16,
		/*nicename("Covenant Plasma")*/ _grenade_type_covenant_plasma = 1ui16,
	};

	enum nicename("Player Training Vehicle Type") e_player_training_vehicle_type : uint8_t
	{
		/*nicename("None")*/ _player_training_vehicle_type_none = 0ui8,
		/*nicename("Warthog")*/ _player_training_vehicle_type_warthog = 1ui8,
		/*nicename("Warthog Turret")*/ _player_training_vehicle_type_warthog_turret = 2ui8,
		/*nicename("Ghost")*/ _player_training_vehicle_type_ghost = 3ui8,
		/*nicename("Banshee")*/ _player_training_vehicle_type_banshee = 4ui8,
		/*nicename("Tank")*/ _player_training_vehicle_type_tank = 5ui8,
		/*nicename("Wraith")*/ _player_training_vehicle_type_wraith = 6ui8,
	};

	enum nicename("Vehicle Size") e_vehicle_size : uint8_t
	{
		/*nicename("Small")*/ _vehicle_size_small = 0ui8,
		/*nicename("Large")*/ _vehicle_size_large = 1ui8,
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
		/*nicename("Circular Aiming")*/ _flags1_circular_aiming = 1ui32 << 0ui32,
		/*nicename("Destroyed After Dying")*/ _flags1_destroyed_after_dying = 1ui32 << 1ui32,
		/*nicename("Half-Speed Interpolation")*/ _flags1_half_speed_interpolation = 1ui32 << 2ui32,
		/*nicename("Fires From Camera")*/ _flags1_fires_from_camera = 1ui32 << 3ui32,
		/*nicename("Entrance Inside Bounding Sphere")*/ _flags1_entrance_inside_bounding_sphere = 1ui32 << 4ui32,
		/*nicename("Doesn't Show Readied Weapon")*/ _flags1_doesnt_show_readied_weapon = 1ui32 << 5ui32,
		/*nicename("Causes Passenger Dialogue")*/ _flags1_causes_passenger_dialogue = 1ui32 << 6ui32,
		/*nicename("Resists Pings")*/ _flags1_resists_pings = 1ui32 << 7ui32,
		/*nicename("Melee Attack Is Fatal")*/ _flags1_melee_attack_is_fatal = 1ui32 << 8ui32,
		/*nicename("Don't Reface During Pings")*/ _flags1_dont_reface_during_pings = 1ui32 << 9ui32,
		/*nicename("Has No Aiming")*/ _flags1_has_no_aiming = 1ui32 << 10ui32,
		/*nicename("Simple Creature")*/ _flags1_simple_creature = 1ui32 << 11ui32,
		/*nicename("Impact Melee Attaches To Unit")*/ _flags1_impact_melee_attaches_to_unit = 1ui32 << 12ui32,
		/*nicename("Impact Melee Dies On Shield")*/ _flags1_impact_melee_dies_on_shield = 1ui32 << 13ui32,
		/*nicename("Cannot Open Doors Automatically")*/ _flags1_cannot_open_doors_automatically = 1ui32 << 14ui32,
		/*nicename("Melee Attackers Cannot Attach")*/ _flags1_melee_attackers_cannot_attach = 1ui32 << 15ui32,
		/*nicename("Not Instantly Killed By Melee")*/ _flags1_not_instantly_killed_by_melee = 1ui32 << 16ui32,
		/*nicename("Shield Sapping")*/ _flags1_shield_sapping = 1ui32 << 17ui32,
		/*nicename("Runs Around Flaming")*/ _flags1_runs_around_flaming = 1ui32 << 18ui32,
		/*nicename("Inconsequential")*/ _flags1_inconsequential = 1ui32 << 19ui32,
		/*nicename("Special Cinematic Unit")*/ _flags1_special_cinematic_unit = 1ui32 << 20ui32,
		/*nicename("Ignored By Autoaiming")*/ _flags1_ignored_by_autoaiming = 1ui32 << 21ui32,
		/*nicename("Shields Fry Infection Forms")*/ _flags1_shields_fry_infection_forms = 1ui32 << 22ui32,
		/*nicename("Can Dual Wield")*/ _flags1_can_dual_wield = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
		/*nicename("Acts As Gunner For Parent")*/ _flags1_acts_as_gunner_for_parent = 1ui32 << 25ui32,
		/*nicename("Controlled By Parent Gunner")*/ _flags1_controlled_by_parent_gunner = 1ui32 << 26ui32,
		/*nicename("Parent's Primary Weapon")*/ _flags1_parents_primary_weapon = 1ui32 << 27ui32,
		/*nicename("Unit Has Boost")*/ _flags1_unit_has_boost = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
	};

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

	enum nicename("Camera Flags") b_camera_flags1 : uint8_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _camera_flags1_bit_0 = 1ui8 << 0ui8,
		/*nicename("Bit 1")*/ _camera_flags1_bit_1 = 1ui8 << 1ui8,
		/*nicename("Hides Player")*/ _camera_flags1_hides_player = 1ui8 << 2ui8,
		/*nicename("Bit 3")*/ _camera_flags1_bit_3 = 1ui8 << 3ui8,
		/*nicename("Bit 4")*/ _camera_flags1_bit_4 = 1ui8 << 4ui8,
		/*nicename("Bit 5")*/ _camera_flags1_bit_5 = 1ui8 << 5ui8,
		/*nicename("Bit 6")*/ _camera_flags1_bit_6 = 1ui8 << 6ui8,
		/*nicename("Bit 7")*/ _camera_flags1_bit_7 = 1ui8 << 7ui8,
	};

	enum nicename("Boost Flags") b_boost_flags : uint8_t /* bitfield */
	{
		/*nicename("Propels Unit Forward")*/ _boost_flags_propels_unit_forward = 1ui8 << 0ui8,
		/*nicename("Bit 1")*/ _boost_flags_bit_1 = 1ui8 << 1ui8,
		/*nicename("Bit 2")*/ _boost_flags_bit_2 = 1ui8 << 2ui8,
		/*nicename("Bit 3")*/ _boost_flags_bit_3 = 1ui8 << 3ui8,
		/*nicename("Bit 4")*/ _boost_flags_bit_4 = 1ui8 << 4ui8,
		/*nicename("Bit 5")*/ _boost_flags_bit_5 = 1ui8 << 5ui8,
		/*nicename("Bit 6")*/ _boost_flags_bit_6 = 1ui8 << 6ui8,
	};

	enum nicename("Flags") b_flags2 : uint32_t /* bitfield */
	{
		/*nicename("No Friction With Driver")*/ _flags2_no_friction_with_driver = 1ui32 << 0ui32,
		/*nicename("Autoaim When Teamless")*/ _flags2_autoaim_when_teamless = 1ui32 << 1ui32,
		/*nicename("AI Weapon Cannot Rotate")*/ _flags2_ai_weapon_cannot_rotate = 1ui32 << 2ui32,
		/*nicename("AI Does Not Require Driver")*/ _flags2_ai_does_not_require_driver = 1ui32 << 3ui32,
		/*nicename("AI Driver Enable")*/ _flags2_ai_driver_enable = 1ui32 << 4ui32,
		/*nicename("AI Driver Flying")*/ _flags2_ai_driver_flying = 1ui32 << 5ui32,
		/*nicename("AI Driver Can Sidestep")*/ _flags2_ai_driver_can_sidestep = 1ui32 << 6ui32,
		/*nicename("AI Driver Hovering")*/ _flags2_ai_driver_hovering = 1ui32 << 7ui32,
		/*nicename("Noncombat Vehicle")*/ _flags2_noncombat_vehicle = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags2_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags2_bit_10 = 1ui32 << 10ui32,
		/*nicename("Hydraulics")*/ _flags2_hydraulics = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags2_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags2_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags2_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags2_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags2_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags2_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags2_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags2_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags2_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags2_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags2_bit_22 = 1ui32 << 22ui32,
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

	enum nicename("Flags") b_flags3 : uint32_t /* bitfield */
	{
		/*nicename("Suspension")*/ _flags3_suspension = 1ui32 << 0ui32,
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

	enum nicename("Flags 2") b_flags_2 : uint32_t /* bitfield */
	{
		/*nicename("Suspensions lifts vehicle?")*/ _flags_2_suspensions_lifts_vehicle = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _flags_2_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _flags_2_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _flags_2_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _flags_2_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _flags_2_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _flags_2_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags_2_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags_2_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags_2_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags_2_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags_2_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags_2_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags_2_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags_2_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags_2_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags_2_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags_2_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags_2_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags_2_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags_2_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags_2_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags_2_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags_2_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags_2_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags_2_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags_2_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags_2_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags_2_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags_2_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags_2_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags_2_bit_31 = 1ui32 << 31ui32,
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
			/*nicename("Default")*/ _size_default = 0ui16,
			/*nicename("Tiny")*/ _size_tiny = 1ui16,
			/*nicename("Small")*/ _size_small = 2ui16,
			/*nicename("Medium")*/ _size_medium = 3ui16,
			/*nicename("Large")*/ _size_large = 4ui16,
			/*nicename("Huge")*/ _size_huge = 5ui16,
			/*nicename("Immobile")*/ _size_immobile = 6ui16,
		};

		enum nicename("Leap Jump Speed") e_leap_jump_speed : uint16_t
		{
			/*nicename("None")*/ _leap_jump_speed_none = 0ui16,
			/*nicename("Down")*/ _leap_jump_speed_down = 1ui16,
			/*nicename("Step")*/ _leap_jump_speed_step = 2ui16,
			/*nicename("Crouch")*/ _leap_jump_speed_crouch = 3ui16,
			/*nicename("Stand")*/ _leap_jump_speed_stand = 4ui16,
			/*nicename("Storey")*/ _leap_jump_speed_storey = 5ui16,
			/*nicename("Tower")*/ _leap_jump_speed_tower = 6ui16,
			/*nicename("Infinite")*/ _leap_jump_speed_infinite = 7ui16,
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
			/*nicename("None")*/ _change_color_none = 0ui16,
			/*nicename("Primary")*/ _change_color_primary = 1ui16,
			/*nicename("Secondary")*/ _change_color_secondary = 2ui16,
			/*nicename("Tertiary")*/ _change_color_tertiary = 3ui16,
			/*nicename("Quaternary")*/ _change_color_quaternary = 4ui16,
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
			/*nicename("Ordinary")*/ _object_type1_ordinary = 0ui8,
			/*nicename("Weapon")*/ _object_type1_weapon = 1ui8,
			/*nicename("Grenade")*/ _object_type1_grenade = 2ui8,
			/*nicename("Projectile")*/ _object_type1_projectile = 3ui8,
			/*nicename("Powerup")*/ _object_type1_powerup = 4ui8,
			/*nicename("Equipment")*/ _object_type1_equipment = 5ui8,
			/*nicename("Ammo Pack")*/ _object_type1_ammo_pack = 6ui8,
			/*nicename("Light Land Vehicle")*/ _object_type1_light_land_vehicle = 7ui8,
			/*nicename("Heavy Land Vehicle")*/ _object_type1_heavy_land_vehicle = 8ui8,
			/*nicename("Flying Vehicle")*/ _object_type1_flying_vehicle = 9ui8,
			/*nicename("Turret")*/ _object_type1_turret = 10ui8,
			/*nicename("Device")*/ _object_type1_device = 11ui8,
			/*nicename("Teleporter 2Way")*/ _object_type1_teleporter_2way = 12ui8,
			/*nicename("Teleporter Sender")*/ _object_type1_teleporter_sender = 13ui8,
			/*nicename("Teleporter Receiver")*/ _object_type1_teleporter_receiver = 14ui8,
			/*nicename("Player Spawn Location")*/ _object_type1_player_spawn_location = 15ui8,
			/*nicename("Player Respawn Zone")*/ _object_type1_player_respawn_zone = 16ui8,
			/*nicename("Secondary Objective")*/ _object_type1_secondary_objective = 17ui8,
			/*nicename("Primary Objective")*/ _object_type1_primary_objective = 18ui8,
			/*nicename("Named Location Area")*/ _object_type1_named_location_area = 19ui8,
			/*nicename("Danger Zone")*/ _object_type1_danger_zone = 20ui8,
			/*nicename("Fireteam 1 Respawn Zone")*/ _object_type1_fireteam_1_respawn_zone = 21ui8,
			/*nicename("Fireteam 2 Respawn Zone")*/ _object_type1_fireteam_2_respawn_zone = 22ui8,
			/*nicename("Fireteam 3 Respawn Zone")*/ _object_type1_fireteam_3_respawn_zone = 23ui8,
			/*nicename("Fireteam 4 Respawn Zone")*/ _object_type1_fireteam_4_respawn_zone = 24ui8,
			/*nicename("Safe Volume")*/ _object_type1_safe_volume = 25ui8,
			/*nicename("Kill Volume")*/ _object_type1_kill_volume = 26ui8,
			/*nicename("Cinematic Camera Position")*/ _object_type1_cinematic_camera_position = 27ui8,
		};

		enum nicename("Shape") e_shape : uint8_t
		{
			/*nicename("None")*/ _shape_none = 0ui8,
			/*nicename("Sphere")*/ _shape_sphere = 1ui8,
			/*nicename("Cylinder")*/ _shape_cylinder = 2ui8,
			/*nicename("Box")*/ _shape_box = 3ui8,
		};

		enum nicename("Spawn Timer Mode") e_spawn_timer_mode : uint8_t
		{
			/*nicename("On Death")*/ _spawn_timer_mode_on_death = 0ui8,
			/*nicename("On Disturbance")*/ _spawn_timer_mode_on_disturbance = 1ui8,
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

	struct nicename("Metagame Properties") s_metagame_properties_definition
	{
		enum nicename("Unit") e_unit : uint8_t
		{
			/*nicename("Brute")*/ _unit_brute = 0ui8,
			/*nicename("Grunt")*/ _unit_grunt = 1ui8,
			/*nicename("Jackal")*/ _unit_jackal = 2ui8,
			/*nicename("Skirmisher")*/ _unit_skirmisher = 3ui8,
			/*nicename("Marine")*/ _unit_marine = 4ui8,
			/*nicename("Spartan")*/ _unit_spartan = 5ui8,
			/*nicename("Bugger")*/ _unit_bugger = 6ui8,
			/*nicename("Hunter")*/ _unit_hunter = 7ui8,
			/*nicename("Flood Infection")*/ _unit_flood_infection = 8ui8,
			/*nicename("Flood Carrier")*/ _unit_flood_carrier = 9ui8,
			/*nicename("Flood Combat")*/ _unit_flood_combat = 10ui8,
			/*nicename("Flood Pureform")*/ _unit_flood_pureform = 11ui8,
			/*nicename("Sentinel")*/ _unit_sentinel = 12ui8,
			/*nicename("Elite")*/ _unit_elite = 13ui8,
			/*nicename("Engineer")*/ _unit_engineer = 14ui8,
			/*nicename("Mule")*/ _unit_mule = 15ui8,
			/*nicename("Turret")*/ _unit_turret = 16ui8,
			/*nicename("Mongoose")*/ _unit_mongoose = 17ui8,
			/*nicename("Warthog")*/ _unit_warthog = 18ui8,
			/*nicename("Scorpion")*/ _unit_scorpion = 19ui8,
			/*nicename("Falcon")*/ _unit_falcon = 20ui8,
			/*nicename("Pelican")*/ _unit_pelican = 21ui8,
			/*nicename("Revenant")*/ _unit_revenant = 22ui8,
			/*nicename("Seraph")*/ _unit_seraph = 23ui8,
			/*nicename("Shade")*/ _unit_shade = 24ui8,
			/*nicename("Watchtower")*/ _unit_watchtower = 25ui8,
			/*nicename("Ghost")*/ _unit_ghost = 26ui8,
			/*nicename("Space Banshee")*/ _unit_space_banshee = 27ui8,
			/*nicename("Mauler")*/ _unit_mauler = 28ui8,
			/*nicename("Wraith")*/ _unit_wraith = 29ui8,
			/*nicename("Banshee")*/ _unit_banshee = 30ui8,
			/*nicename("Phantom")*/ _unit_phantom = 31ui8,
			/*nicename("Scarab")*/ _unit_scarab = 32ui8,
			/*nicename("Guntower")*/ _unit_guntower = 33ui8,
			/*nicename("Tuning Fork")*/ _unit_tuning_fork = 34ui8,
		};

		enum nicename("Classification") e_classification : uint8_t
		{
			/*nicename("Infantry")*/ _classification_infantry = 0ui8,
			/*nicename("Leader")*/ _classification_leader = 1ui8,
			/*nicename("Hero")*/ _classification_hero = 2ui8,
			/*nicename("Specialist")*/ _classification_specialist = 3ui8,
			/*nicename("Light Vehicle")*/ _classification_light_vehicle = 4ui8,
			/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 5ui8,
			/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 6ui8,
			/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 7ui8,
		};

		enum nicename("Flags") b_flags2 : uint8_t /* bitfield */
		{
			/*nicename("Must Have Active Seats")*/ _flags2_must_have_active_seats = 1ui8 << 0ui8,
		};

		b_flags2 nicename("Flags") flags;
		e_unit nicename("Unit") unit;
		e_classification nicename("Classification") classification;
		int8_t __unknown0;
		int16_t nicename("Points") points;
		int16_t __unknown1;
	};

	struct nicename("Unit Screen Effects") s_unit_screen_effects_definition
	{
		TagReference nicename("Screen Effect") screen_effect_reference;
	};

	struct nicename("Camera Tracks") s_camera_tracks_definition
	{
		TagReference nicename("Track") track_reference;
		TagReference nicename("Screen Effect") screen_effect_reference;
	};

	struct nicename("Unknown") s_unknown3_definition
	{
		float __unknown0;
		Undefined32 __unknown1;
		DataReference __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		int16_t __unknown6;
		int16_t __unknown7;
		DataReference __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		int16_t __unknown12;
		int16_t __unknown13;
		DataReference __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
	};

	struct nicename("Unknown") s_unknown4_definition
	{
		struct nicename("Unknown") s_unknown5_definition
		{
			DataReference nicename("Function") function_data_reference;
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
		s_tag_block_definition<s_unknown5_definition> __unknown10;
	};

	struct nicename("Space Fighter Camera") s_space_fighter_camera_definition
	{
		struct nicename("Unknown") s_unknown6_definition
		{
			DataReference nicename("Function") function_data_reference;
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
		s_tag_block_definition<s_unknown6_definition> __unknown10;
	};

	struct nicename("Camera Tracks") s_camera_tracks1_definition
	{
		TagReference nicename("Track") track_reference;
		TagReference nicename("Screen Effect") screen_effect_reference;
	};

	struct nicename("Unknown") s_unknown7_definition
	{
		float __unknown0;
		Undefined32 __unknown1;
		DataReference __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		int16_t __unknown6;
		int16_t __unknown7;
		DataReference __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		int16_t __unknown12;
		int16_t __unknown13;
		DataReference __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
	};

	struct nicename("Unknown") s_unknown8_definition
	{
		struct nicename("Unknown") s_unknown9_definition
		{
			DataReference nicename("Function") function_data_reference;
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
		s_tag_block_definition<s_unknown9_definition> __unknown10;
	};

	struct nicename("Space Fighter Camera") s_space_fighter_camera1_definition
	{
		struct nicename("Unknown") s_unknown10_definition
		{
			DataReference nicename("Function") function_data_reference;
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
		s_tag_block_definition<s_unknown10_definition> __unknown10;
	};

	struct nicename("Postures") s_postures_definition
	{
		string_id nicename("Name") name;
		float nicename("Pill Offset I") pill_offset_i;
		float nicename("Pill Offset J") pill_offset_j;
		float nicename("Pill Offset K") pill_offset_k;
	};

	struct nicename("HUD Interfaces") s_hud_interfaces_definition
	{
		TagReference nicename("Unit HUD Interface") unit_hud_interface_reference;
	};

	struct nicename("Dialogue Variants") s_dialogue_variants_definition
	{
		int16_t nicename("Variant Number") variant_number;
		int16_t __unknown0;
		TagReference nicename("Dialogue") dialogue_reference;
	};

	struct nicename("Powered Seats") s_powered_seats_definition
	{
		float nicename("Driver Powerup Time") driver_powerup_time;
		float nicename("Driver Powerdown Time") driver_powerdown_time;
	};

	struct nicename("Weapons") s_weapons_definition
	{
		TagReference nicename("Weapon") weapon_reference;
		string_id nicename("Parent Marker") parent_marker;
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

	struct nicename("Seats") s_seats_definition
	{
		enum nicename("AI Seat Type") e_ai_seat_type : uint16_t
		{
			/*nicename("None")*/ _ai_seat_type_none = 0ui16,
			/*nicename("Passenger")*/ _ai_seat_type_passenger = 1ui16,
			/*nicename("Gunner")*/ _ai_seat_type_gunner = 2ui16,
			/*nicename("Small Cargo")*/ _ai_seat_type_small_cargo = 3ui16,
			/*nicename("Large Cargo")*/ _ai_seat_type_large_cargo = 4ui16,
			/*nicename("Driver")*/ _ai_seat_type_driver = 5ui16,
		};

		enum nicename("Flags") b_flags2 : uint32_t /* bitfield */
		{
			/*nicename("Invisible")*/ _flags2_invisible = 1ui32 << 0ui32,
			/*nicename("Locked")*/ _flags2_locked = 1ui32 << 1ui32,
			/*nicename("Driver")*/ _flags2_driver = 1ui32 << 2ui32,
			/*nicename("Gunner")*/ _flags2_gunner = 1ui32 << 3ui32,
			/*nicename("Third Person Camera")*/ _flags2_third_person_camera = 1ui32 << 4ui32,
			/*nicename("Allows Weapons")*/ _flags2_allows_weapons = 1ui32 << 5ui32,
			/*nicename("Third Person On Enter")*/ _flags2_third_person_on_enter = 1ui32 << 6ui32,
			/*nicename("First Person Camera Slaved To Gun")*/ _flags2_first_person_camera_slaved_to_gun = 1ui32 << 7ui32,
			/*nicename("Allow Vehicle Communication Animations")*/ _flags2_allow_vehicle_communication_animations = 1ui32 << 8ui32,
			/*nicename("Not Valid Without Driver")*/ _flags2_not_valid_without_driver = 1ui32 << 9ui32,
			/*nicename("Boarding Seat")*/ _flags2_boarding_seat = 1ui32 << 10ui32,
			/*nicename("AI Firing Disabled By Max Acceleration")*/ _flags2_ai_firing_disabled_by_max_acceleration = 1ui32 << 11ui32,
			/*nicename("Boarding Enters Seat")*/ _flags2_boarding_enters_seat = 1ui32 << 12ui32,
			/*nicename("Boarding Need Any Passenger")*/ _flags2_boarding_need_any_passenger = 1ui32 << 13ui32,
			/*nicename("Invalid For Player")*/ _flags2_invalid_for_player = 1ui32 << 14ui32,
			/*nicename("Invalid For Non-Player")*/ _flags2_invalid_for_non_player = 1ui32 << 15ui32,
			/*nicename("Bit 18")*/ _flags2_bit_18 = 1ui32 << 16ui32,
			/*nicename("Gunner (Player Only)")*/ _flags2_gunner_player_only = 1ui32 << 17ui32,
			/*nicename("Invisible Under Major Damage")*/ _flags2_invisible_under_major_damage = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags2_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags2_bit_20 = 1ui32 << 20ui32,
			/*nicename("Detachable Weapon")*/ _flags2_detachable_weapon = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags2_bit_22 = 1ui32 << 22ui32,
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

		enum nicename("Camera Flags") b_camera_flags2 : uint8_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _camera_flags2_bit_0 = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _camera_flags2_bit_1 = 1ui8 << 1ui8,
			/*nicename("Hides Player")*/ _camera_flags2_hides_player = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _camera_flags2_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _camera_flags2_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _camera_flags2_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _camera_flags2_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _camera_flags2_bit_7 = 1ui8 << 7ui8,
		};

		struct nicename("Camera Tracks") s_camera_tracks2_definition
		{
			TagReference nicename("Track") track_reference;
			TagReference nicename("Screen Effect") screen_effect_reference;
		};

		struct nicename("Unknown") s_unknown11_definition
		{
			float __unknown0;
			Undefined32 __unknown1;
			DataReference __unknown2;
			float __unknown3;
			float __unknown4;
			float __unknown5;
			int16_t __unknown6;
			int16_t __unknown7;
			DataReference __unknown8;
			float __unknown9;
			float __unknown10;
			float __unknown11;
			int16_t __unknown12;
			int16_t __unknown13;
			DataReference __unknown14;
			float __unknown15;
			float __unknown16;
			float __unknown17;
		};

		struct nicename("Unknown") s_unknown12_definition
		{
			struct nicename("Unknown") s_unknown13_definition
			{
				DataReference nicename("Function") function_data_reference;
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
			s_tag_block_definition<s_unknown13_definition> __unknown10;
		};

		struct nicename("Space Fighter Camera") s_space_fighter_camera2_definition
		{
			struct nicename("Unknown") s_unknown14_definition
			{
				DataReference nicename("Function") function_data_reference;
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
			s_tag_block_definition<s_unknown14_definition> __unknown10;
		};

		struct nicename("Unit HUD Interface") s_unit_hud_interface_definition
		{
			TagReference nicename("Unit HUD Interface") unit_hud_interface_reference;
		};

		b_flags2 nicename("Flags") flags;
		string_id nicename("Seat Animation") seat_animation;
		string_id nicename("Seat Marker Name") seat_marker_name;
		string_id nicename("Entry Marker(s) Name") entry_markers_name;
		string_id nicename("Boarding Grenade Marker") boarding_grenade_marker;
		string_id nicename("Boarding Grenade String") boarding_grenade_string;
		string_id nicename("Boarding Melee String") boarding_melee_string;
		string_id nicename("Detach Weapon String") detach_weapon_string;
		float nicename("Ping Scale") ping_scale;
		float nicename("Turnover Time") turnover_time;
		TagReference nicename("Spring Acceleration") spring_acceleration_reference;
		float nicename("AI Scariness") ai_scariness;
		e_ai_seat_type nicename("AI Seat Type") ai_seat_type;
		int16_t nicename("Boarding Seat") boarding_seat;
		Undefined32 nicename("block here") block_here;
		Undefined32 nicename("block here") block_here1;
		Undefined32 nicename("block here") block_here2;
		float nicename("Listener Interpolation Factor") listener_interpolation_factor;
		float nicename("Yaw Rate Bounds min") yaw_rate_bounds_min;
		float nicename("Yaw Rate Bounds max") yaw_rate_bounds_max;
		float nicename("Pitch Rate Bounds min") pitch_rate_bounds_min;
		float nicename("Pitch Rate Bounds max") pitch_rate_bounds_max;
		float __unknown0;
		float nicename("Minimum Speed Reference") minimum_speed_reference;
		float nicename("Maximum Speed Reference") maximum_speed_reference;
		float nicename("Speed Exponent") speed_exponent;
		b_camera_flags2 nicename("Camera Flags") camera_flags;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		string_id nicename("Camera Marker") camera_marker;
		float nicename("Pitch Auto-Level") pitch_auto_level;
		float nicename("Pitch Range min") pitch_range_min;
		float nicename("Pitch Range max") pitch_range_max;
		s_tag_block_definition<s_camera_tracks2_definition> nicename("Camera Tracks") camera_tracks_block;
		float nicename("Camera Stiffness min") camera_stiffness_min;
		float nicename("Camera Stiffness max") camera_stiffness_max;
		float __unknown4;
		float nicename("Camera Acceleration Speed") camera_acceleration_speed;
		float nicename("Camera Deceleration Speed") camera_deceleration_speed;
		float __unknown5;
		float nicename("Camera Field Of View") camera_field_of_view;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		s_tag_block_definition<s_unknown11_definition> __unknown12;
		s_tag_block_definition<s_unknown12_definition> __unknown13;
		s_tag_block_definition<s_space_fighter_camera2_definition> nicename("Space Fighter Camera") space_fighter_camera_block;
		s_tag_block_definition<s_unit_hud_interface_definition> nicename("Unit HUD Interface") unit_hud_interface_block;
		string_id nicename("Enter Seat String") enter_seat_string;
		float nicename("Yaw Range min") yaw_range_min;
		float nicename("Yaw Range max") yaw_range_max;
		TagReference nicename("Built-In Gunner") built_in_gunner_reference;
		float nicename("Entry Radius") entry_radius;
		float nicename("Entry Marker Cone Angle") entry_marker_cone_angle;
		float nicename("Entry Marker Facing Angle") entry_marker_facing_angle;
		float nicename("Maximum Relative Velocity") maximum_relative_velocity;
		float nicename("Powered Off Animation Speed") powered_off_animation_speed;
		float nicename("Powered On Animation Speed") powered_on_animation_speed;
		string_id nicename("Open Animation") open_animation;
		string_id nicename("Opening Animation") opening_animation;
		string_id nicename("Closing Animation") closing_animation;
		string_id nicename("Invisible Seat Region") invisible_seat_region;
		int32_t nicename("Runtime Invisible Seat Region Index") runtime_invisible_seat_region_index;
	};

	struct nicename("Tank Engine Motion Properties") s_tank_engine_motion_properties_definition
	{
		struct nicename("Gears") s_gears_definition
		{
			DataReference nicename("Loaded Torque Function") loaded_torque_function_data_reference;
			Undefined32 __unknown0;
			DataReference nicename("Cruising Torque Function") cruising_torque_function_data_reference;
			Undefined32 __unknown1;
			// Gearing : 
			float nicename("Min Time to Upshift") min_time_to_upshift;
			float nicename("Engine Upshift Scale") engine_upshift_scale;
			float nicename("Gear Ratio") gear_ratio;
			float nicename("Min Time to Downshift") min_time_to_downshift;
			float nicename("Engine Downshift Scale") engine_downshift_scale;
			Undefined32 __unknown2;
		};

		struct nicename("Braking") s_braking_definition
		{
			string_id nicename("Name") name;
			int32_t __unknown0;
		};

		float nicename("Steering Overdampen Cusp Angle 1") steering_overdampen_cusp_angle_1;
		float nicename("Steering Overdampen Cusp Angle 2") steering_overdampen_cusp_angle_2;
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent;
		float __unknown0;
		float nicename("Turn Rate") turn_rate;
		float nicename("Speed Back") speed_back;
		float nicename("Speed Left") speed_left;
		float nicename("Speed Right") speed_right;
		float nicename("Turning Speed Right") turning_speed_right;
		float nicename("Turning Speed Left") turning_speed_left;
		float nicename("Speed Left 2") speed_left_2;
		float nicename("Speed Right 2") speed_right_2;
		float nicename("Turning Speed Right 2") turning_speed_right_2;
		float nicename("Turning Speed Left 2") turning_speed_left_2;
		float nicename("Engine Momentum") engine_momentum;
		float nicename("Engine Maximum Angular Velocity") engine_maximum_angular_velocity;
		s_tag_block_definition<s_gears_definition> nicename("Gears") gears_block;
		TagReference nicename("Change Gear Sound") change_gear_sound_reference;
		s_tag_block_definition<s_braking_definition> nicename("Braking") braking_block;
		float __unknown1;
		float __unknown2;
	};

	struct nicename("Engine Motion Properties") s_engine_motion_properties_definition
	{
		struct nicename("Gears") s_gears1_definition
		{
			DataReference nicename("Loaded Torque Function") loaded_torque_function_data_reference;
			Undefined32 __unknown0;
			DataReference nicename("Cruising Torque Function") cruising_torque_function_data_reference;
			Undefined32 __unknown1;
			// Gearing : 
			float nicename("Min Time to Upshift") min_time_to_upshift;
			float nicename("Engine Upshift Scale") engine_upshift_scale;
			float nicename("Gear Ratio") gear_ratio;
			float nicename("Min Time to Downshift") min_time_to_downshift;
			float nicename("Engine Downshift Scale") engine_downshift_scale;
			Undefined32 __unknown2;
		};

		struct nicename("Braking") s_braking1_definition
		{
			string_id nicename("Name") name;
			int32_t __unknown0;
		};

		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle;
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent;
		float nicename("Maximum Left Turn") maximum_left_turn;
		float nicename("Maximum Right Turn (negative)") maximum_right_turn_negative;
		float nicename("Turn Rate") turn_rate;
		float nicename("Engine Momentum") engine_momentum;
		float nicename("Engine Maximum Angular Velocity") engine_maximum_angular_velocity;
		s_tag_block_definition<s_gears1_definition> nicename("Gears") gears_block;
		TagReference nicename("Change Gear Sound") change_gear_sound_reference;
		s_tag_block_definition<s_braking1_definition> nicename("Braking") braking_block;
		Undefined32 nicename("block here") block_here;
		Undefined32 nicename("block here") block_here1;
		Undefined32 nicename("block here") block_here2;
		float __unknown0;
		float __unknown1;
	};

	struct nicename("Dropship Motion Properties") s_dropship_motion_properties_definition
	{
		float nicename("Forward Acceleration") forward_acceleration;
		float nicename("Backward Acceleration") backward_acceleration;
		float __unknown0;
		float __unknown1;
		float nicename("Left Strafe Acceleration") left_strafe_acceleration;
		float nicename("Right Strafe Acceleration") right_strafe_acceleration;
		float __unknown2;
		float __unknown3;
		float nicename("Lift Acceleration") lift_acceleration;
		float nicename("Drop Acceleration") drop_acceleration;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
	};

	struct nicename("Antigravity Motion Properties") s_antigravity_motion_properties_definition
	{
		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle;
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent;
		float nicename("Maximum Forward Speed") maximum_forward_speed;
		float nicename("Maximum Reverse Speed") maximum_reverse_speed;
		float nicename("Speed Acceleration") speed_acceleration;
		float nicename("Speed Deceleration") speed_deceleration;
		float nicename("Maximum Left Slide") maximum_left_slide;
		float nicename("Maximum Right Slide") maximum_right_slide;
		float nicename("Slide Acceleration") slide_acceleration;
		float nicename("Slide Deceleration") slide_deceleration;
		float nicename("Direction Change?") direction_change;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		float nicename("Traction") traction;
		Undefined32 __unknown4;
		float nicename("Turning Rate") turning_rate;
		string_id __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		float __unknown9;
		string_id __unknown10;
		float __unknown11;
		float __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
		float __unknown18;
	};

	struct nicename("Jet Engine Motion Properties") s_jet_engine_motion_properties_definition
	{
		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle;
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent;
		float nicename("Maximum Left Turn") maximum_left_turn;
		float nicename("Maximum Right Turn (negative)") maximum_right_turn_negative;
		float nicename("Turn Rate") turn_rate;
		float nicename("Flying Speed") flying_speed;
		float nicename("Acceleration") acceleration;
		float nicename("Speed Acceleration") speed_acceleration;
		float nicename("Speed Deceleration") speed_deceleration;
		float nicename("Pitch Left Speed") pitch_left_speed;
		float nicename("Pitch Right Speed") pitch_right_speed;
		float nicename("Pitch Rate") pitch_rate;
		float nicename("Unpitch Rate") unpitch_rate;
		float nicename("Flight Stability") flight_stability;
		Undefined32 __unknown0;
		float nicename("Nose Angle") nose_angle;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float nicename("Falling Speed") falling_speed;
		float nicename("Falling Speed 2") falling_speed_2;
		float __unknown4;
		float __unknown5;
		float nicename("Idle Rise") idle_rise;
		float nicename("Idle Forward") idle_forward;
	};

	struct nicename("Turret Properties") s_turret_properties_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
	};

	struct nicename("Helicopter Motion Properties") s_helicopter_motion_properties_definition
	{
		struct nicename("Unknown") s_unknown15_definition
		{
			float __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			float __unknown4;
			float __unknown5;
			float __unknown6;
			float __unknown7;
		};

		float nicename("Max Left Turn") max_left_turn;
		float nicename("Max Right Turn") max_right_turn;
		float __unknown0;
		string_id nicename("Thrust Front Left") thrust_front_left;
		string_id nicename("Thrust Front Right") thrust_front_right;
		string_id nicename("Thrust") thrust;
		DataReference nicename("Function") function_data_reference;
		DataReference nicename("Function") function1_data_reference;
		float __unknown1;
		float nicename("Rise Speed") rise_speed;
		float __unknown2;
		float __unknown3;
		Undefined32 __unknown4;
		float nicename("Pitch min") pitch_min;
		float nicename("Pitch max") pitch_max;
		float nicename("Boost Acceleration Time") boost_acceleration_time;
		DataReference nicename("Function") function2_data_reference;
		DataReference nicename("Function") function3_data_reference;
		DataReference nicename("Function") function4_data_reference;
		s_tag_block_definition<s_unknown15_definition> __unknown5;
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
	};

	struct nicename("Space Fighter Motion Properties") s_space_fighter_motion_properties_definition
	{
		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle;
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		float __unknown12;
		Undefined32 __unknown13;
		Undefined32 __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
		float __unknown18;
		float __unknown19;
		Undefined32 __unknown20;
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
		float __unknown34;
		float __unknown35;
		float __unknown36;
		float __unknown37;
		float __unknown38;
		Undefined32 __unknown39;
		Undefined32 __unknown40;
		float __unknown41;
		DataReference nicename("Function") function_data_reference;
	};

	struct nicename("Anti Gravity Points") s_anti_gravity_points_definition
	{
		enum nicename("Flags") b_flags4 : uint32_t /* bitfield */
		{
			/*nicename("Gets Damage From Region")*/ _flags4_gets_damage_from_region = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _flags4_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _flags4_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags4_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags4_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags4_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags4_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags4_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags4_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags4_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags4_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags4_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags4_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags4_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags4_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags4_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags4_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags4_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags4_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags4_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags4_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags4_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags4_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags4_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags4_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags4_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags4_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags4_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags4_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags4_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags4_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags4_bit_31 = 1ui32 << 31ui32,
		};

		string_id nicename("Marker Name") marker_name;
		b_flags4 nicename("Flags") flags;
		float __unknown0;
		float nicename("Antigrav Strength") antigrav_strength;
		float nicename("Antigrav Height") antigrav_height;
		float nicename("Antigrav Dump Factor Up") antigrav_dump_factor_up;
		float nicename("Antigrav Dump Factor Down") antigrav_dump_factor_down;
		float nicename("Antigrav Normal k1") antigrav_normal_k1;
		float nicename("Antigrav Normal k0") antigrav_normal_k0;
		float nicename("Radius") radius;
		string_id nicename("Material") material;
		int16_t nicename("Global Material Index") global_material_index;
		int16_t nicename("Damage Source Region Index") damage_source_region_index;
		string_id nicename("Damage Source Region Name") damage_source_region_name;
		float nicename("Default State Error") default_state_error;
		float nicename("Minor Damage Error") minor_damage_error;
		float nicename("Medium Damage Error") medium_damage_error;
		float nicename("Major Damage Error") major_damage_error;
		float nicename("Destroyed State Error") destroyed_state_error;
	};

	struct nicename("Friction Points") s_friction_points_definition
	{
		enum nicename("Model State Destroyed") e_model_state_destroyed : uint16_t
		{
			/*nicename("Default")*/ _model_state_destroyed_default = 0ui16,
			/*nicename("Minor Damage")*/ _model_state_destroyed_minor_damage = 1ui16,
			/*nicename("Medium Damage")*/ _model_state_destroyed_medium_damage = 2ui16,
			/*nicename("Major Damage")*/ _model_state_destroyed_major_damage = 3ui16,
			/*nicename("Destroyed")*/ _model_state_destroyed_destroyed = 4ui16,
		};

		enum nicename("Flags") b_flags4 : uint32_t /* bitfield */
		{
			/*nicename("Gets Damage From Region")*/ _flags4_gets_damage_from_region = 1ui32 << 0ui32,
			/*nicename("Powered")*/ _flags4_powered = 1ui32 << 1ui32,
			/*nicename("Front Turning")*/ _flags4_front_turning = 1ui32 << 2ui32,
			/*nicename("Rear Turning")*/ _flags4_rear_turning = 1ui32 << 3ui32,
			/*nicename("Attached To E-Brake")*/ _flags4_attached_to_e_brake = 1ui32 << 4ui32,
			/*nicename("Can Be Destroyed")*/ _flags4_can_be_destroyed = 1ui32 << 5ui32,
			/*nicename("Bit 7")*/ _flags4_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags4_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags4_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags4_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags4_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags4_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags4_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags4_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags4_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags4_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags4_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags4_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags4_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags4_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags4_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags4_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags4_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags4_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags4_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags4_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags4_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags4_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags4_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags4_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags4_bit_31 = 1ui32 << 31ui32,
		};

		string_id nicename("Marker Name") marker_name;
		b_flags4 nicename("Flags") flags;
		float nicename("Fraction Of Total Mass") fraction_of_total_mass;
		float nicename("Radius") radius;
		float nicename("Damaged Radius") damaged_radius;
		float nicename("Moving Friction Velocity Diff") moving_friction_velocity_diff;
		float nicename("E-Brake Moving Friction") e_brake_moving_friction;
		float nicename("E-Brake Friction") e_brake_friction;
		float nicename("E-Brake Moving Friction Velocity Diff") e_brake_moving_friction_velocity_diff;
		string_id nicename("Collision Material Name") collision_material_name;
		int16_t nicename("Collision Global Material Index") collision_global_material_index;
		e_model_state_destroyed nicename("Model State Destroyed") model_state_destroyed;
		string_id nicename("Region Name") region_name;
		int32_t nicename("Region Index") region_index;
	};

	struct nicename("Tricks") s_tricks_definition
	{
		enum nicename("Initiate Direction") e_initiate_direction : uint8_t
		{
			/*nicename("Left")*/ _initiate_direction_left = 0ui8,
			/*nicename("Right")*/ _initiate_direction_right = 1ui8,
			/*nicename("Up")*/ _initiate_direction_up = 2ui8,
			/*nicename("Down")*/ _initiate_direction_down = 3ui8,
		};

		string_id nicename("Name") name;
		e_initiate_direction nicename("Initiate Direction") initiate_direction;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		float __unknown3;
		Undefined32 nicename("Distance Traveled") distance_traveled;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		Undefined32 nicename("Cooldown Time") cooldown_time;
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
	// UNIT : 
	b_flags1 nicename("Flags") flags1;
	e_team nicename("Team") team;
	e_constant_sound_volume nicename("Constant Sound Volume") constant_sound_volume;
	TagReference nicename("Hologram Unit") hologram_unit_reference;
	s_tag_block_definition<s_metagame_properties_definition> nicename("Metagame Properties") metagame_properties_block;
	s_tag_block_definition<s_unit_screen_effects_definition> nicename("Unit Screen Effects") unit_screen_effects_block;
	int32_t __unknown4;
	// Unit Camera : 
	b_camera_flags nicename("Camera Flags") camera_flags;
	int8_t __unknown5;
	int8_t __unknown6;
	int8_t __unknown7;
	string_id nicename("Camera Marker") camera_marker;
	float nicename("Pitch Auto-Level") pitch_auto_level;
	float nicename("Pitch Range min") pitch_range_min;
	float nicename("Pitch Range max") pitch_range_max;
	s_tag_block_definition<s_camera_tracks_definition> nicename("Camera Tracks") camera_tracks_block;
	float nicename("Camera Stiffness min") camera_stiffness_min;
	float nicename("Camera Stiffness max") camera_stiffness_max;
	float __unknown8;
	float nicename("Camera Acceleration Speed") camera_acceleration_speed;
	float nicename("Camera Deceleration Speed") camera_deceleration_speed;
	float __unknown9;
	float nicename("Camera Field Of View") camera_field_of_view;
	Undefined32 __unknown10;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	Undefined32 __unknown14;
	Undefined32 __unknown15;
	s_tag_block_definition<s_unknown3_definition> __unknown16;
	s_tag_block_definition<s_unknown4_definition> __unknown17;
	s_tag_block_definition<s_space_fighter_camera_definition> nicename("Space Fighter Camera") space_fighter_camera_block;
	// Assassination Camera : 
	b_camera_flags1 nicename("Camera Flags") camera_flags1;
	int8_t __unknown18;
	int8_t __unknown19;
	int8_t __unknown20;
	string_id nicename("Camera Marker") camera_marker1;
	float nicename("Pitch Auto-Level") pitch_auto_level1;
	float nicename("Pitch Range min") pitch_range_min1;
	float nicename("Pitch Range max") pitch_range_max1;
	s_tag_block_definition<s_camera_tracks1_definition> nicename("Camera Tracks") camera_tracks1_block;
	float nicename("Camera Stiffness min") camera_stiffness_min1;
	float nicename("Camera Stiffness max") camera_stiffness_max1;
	float __unknown21;
	float nicename("Camera Acceleration Speed") camera_acceleration_speed1;
	float nicename("Camera Deceleration Speed") camera_deceleration_speed1;
	float __unknown22;
	float nicename("Camera Field Of View") camera_field_of_view1;
	Undefined32 __unknown23;
	Undefined32 __unknown24;
	Undefined32 __unknown25;
	Undefined32 __unknown26;
	Undefined32 __unknown27;
	Undefined32 __unknown28;
	s_tag_block_definition<s_unknown7_definition> __unknown29;
	s_tag_block_definition<s_unknown8_definition> __unknown30;
	s_tag_block_definition<s_space_fighter_camera1_definition> nicename("Space Fighter Camera") space_fighter_camera1_block;
	TagReference nicename("Assassination Response") assassination_response_reference;
	TagReference nicename("Assassination Tool") assassination_tool_reference;
	string_id nicename("Assassination Tool Marker") assassination_tool_marker;
	string_id nicename("Assassination Tool Hand Marker") assassination_tool_hand_marker;
	string_id nicename("Assassination Tool Stow Anchor") assassination_tool_stow_anchor;
	TagReference nicename("Spring Acceleration") spring_acceleration_reference;
	float nicename("Soft Ping Threshold") soft_ping_threshold;
	float nicename("Soft Ping Interrupt Time") soft_ping_interrupt_time;
	float nicename("Hard Ping Threshold") hard_ping_threshold;
	float nicename("Hard Ping Interrupt Time") hard_ping_interrupt_time;
	float __unknown31;
	float nicename("Feign Death Threshold") feign_death_threshold;
	float nicename("Feign Death Time") feign_death_time;
	float nicename("Distance of Evade Animation") distance_of_evade_animation;
	float nicename("Distance of Dive Animation") distance_of_dive_animation;
	float __unknown32;
	float __unknown33;
	float __unknown34;
	float __unknown35;
	Undefined32 __unknown36;
	Undefined32 __unknown37;
	float __unknown38;
	Undefined32 __unknown39;
	float __unknown40;
	float __unknown41;
	float __unknown42;
	Undefined32 __unknown43;
	float __unknown44;
	float nicename("Feign Death Chance") feign_death_chance;
	float nicename("Feign Repeat Chance") feign_repeat_chance;
	TagReference nicename("Spawned Turret Character") spawned_turret_character_reference;
	int16_t nicename("Spawned Actor Count min") spawned_actor_count_min;
	int16_t nicename("Spawned Actor Count max") spawned_actor_count_max;
	float nicename("Spawned Velocity") spawned_velocity;
	string_id nicename("Aiming Pivot Marker") aiming_pivot_marker;
	float nicename("Aiming Velocity Maximum") aiming_velocity_maximum;
	float nicename("Aiming Acceleration Maximum") aiming_acceleration_maximum;
	float nicename("Casual Aiming Modifier") casual_aiming_modifier;
	float nicename("Looking Velocity Maximum") looking_velocity_maximum;
	float nicename("Looking Acceleration Maximum") looking_acceleration_maximum;
	Undefined32 __unknown45;
	string_id nicename("Right Hand Node") right_hand_node;
	string_id nicename("Left Hand Node") left_hand_node;
	string_id nicename("Preferred Gun Node") preferred_gun_node;
	string_id nicename("Preferred Grenade Node") preferred_grenade_node;
	Undefined32 __unknown46;
	TagReference nicename("AI Melee Damage") ai_melee_damage_reference;
	TagReference nicename("Melee Damage") melee_damage_reference;
	TagReference nicename("Boarding Melee Damage") boarding_melee_damage_reference;
	TagReference nicename("Boarding Melee Response") boarding_melee_response_reference;
	TagReference nicename("Ejection Melee Damage") ejection_melee_damage_reference;
	TagReference nicename("Ejection Melee Response") ejection_melee_response_reference;
	TagReference nicename("Landing Melee Damage") landing_melee_damage_reference;
	TagReference nicename("Flurry Melee Damage") flurry_melee_damage_reference;
	TagReference nicename("Obstacle Smash Melee Damage") obstacle_smash_melee_damage_reference;
	TagReference nicename("Assassination Damage") assassination_damage_reference;
	e_motion_sensor_blip_size nicename("Motion Sensor Blip Size") motion_sensor_blip_size;
	e_item_scale nicename("Item Scale") item_scale;
	string_id nicename("Equipment Variant") equipment_variant;
	string_id nicename("Dropped Equipment Variant") dropped_equipment_variant;
	s_tag_block_definition<s_postures_definition> nicename("Postures") postures_block;
	s_tag_block_definition<s_hud_interfaces_definition> nicename("HUD Interfaces") hud_interfaces_block;
	s_tag_block_definition<s_dialogue_variants_definition> nicename("Dialogue Variants") dialogue_variants_block;
	float nicename("Grenade Arc") grenade_arc;
	float nicename("Grenade Force") grenade_force;
	float nicename("Grenade Angle") grenade_angle;
	float nicename("Grenade Velocity") grenade_velocity;
	e_grenade_type nicename("Grenade Type") grenade_type;
	int16_t nicename("Grenade Count") grenade_count;
	s_tag_block_definition<s_powered_seats_definition> nicename("Powered Seats") powered_seats_block;
	s_tag_block_definition<s_weapons_definition> nicename("Weapons") weapons_block;
	s_tag_block_definition<s_target_tracking_definition> nicename("Target Tracking") target_tracking_block;
	s_tag_block_definition<s_seats_definition> nicename("Seats") seats_block;
	float __unknown47;
	float __unknown48;
	float nicename("EMP Radius") emp_radius;
	TagReference nicename("EMP Effect") emp_effect_reference;
	TagReference nicename("Boost Collision Damage") boost_collision_damage_reference;
	b_boost_flags nicename("Boost Flags") boost_flags;
	int8_t __unknown49;
	int8_t __unknown50;
	int8_t __unknown51;
	float nicename("Boost Peak Power") boost_peak_power;
	float nicename("Boost Rise Power") boost_rise_power;
	float nicename("Boost Fall Power") boost_fall_power;
	float nicename("Boost Gauge Decay Rate") boost_gauge_decay_rate;
	float nicename("Boost Gauge Recharge Delay") boost_gauge_recharge_delay;
	float nicename("Boost Gauge Recharge Rate") boost_gauge_recharge_rate;
	DataReference nicename("Boost Function") boost_function_data_reference;
	float nicename("Lipsync Attack Weight") lipsync_attack_weight;
	float nicename("Lipsync Decay Weight") lipsync_decay_weight;
	TagReference nicename("Detach Damage") detach_damage_reference;
	TagReference nicename("Detached Weapon") detached_weapon_reference;
	// VEHICLE : 
	b_flags2 nicename("Flags") flags2;
	s_tag_block_definition<s_tank_engine_motion_properties_definition> nicename("Tank Engine Motion Properties") tank_engine_motion_properties_block;
	s_tag_block_definition<s_engine_motion_properties_definition> nicename("Engine Motion Properties") engine_motion_properties_block;
	s_tag_block_definition<s_dropship_motion_properties_definition> nicename("Dropship Motion Properties") dropship_motion_properties_block;
	Undefined32 __unknown52;
	Undefined32 __unknown53;
	Undefined32 __unknown54;
	s_tag_block_definition<s_antigravity_motion_properties_definition> nicename("Antigravity Motion Properties") antigravity_motion_properties_block;
	s_tag_block_definition<s_jet_engine_motion_properties_definition> nicename("Jet Engine Motion Properties") jet_engine_motion_properties_block;
	s_tag_block_definition<s_turret_properties_definition> nicename("Turret Properties") turret_properties_block;
	Undefined32 __unknown55;
	Undefined32 __unknown56;
	Undefined32 __unknown57;
	s_tag_block_definition<s_helicopter_motion_properties_definition> nicename("Helicopter Motion Properties") helicopter_motion_properties_block;
	Undefined32 __unknown58;
	Undefined32 __unknown59;
	Undefined32 __unknown60;
	Undefined32 __unknown61;
	Undefined32 __unknown62;
	Undefined32 __unknown63;
	Undefined32 __unknown64;
	Undefined32 __unknown65;
	Undefined32 __unknown66;
	Undefined32 __unknown67;
	Undefined32 __unknown68;
	Undefined32 __unknown69;
	s_tag_block_definition<s_space_fighter_motion_properties_definition> nicename("Space Fighter Motion Properties") space_fighter_motion_properties_block;
	Undefined32 __unknown70;
	Undefined32 __unknown71;
	Undefined32 __unknown72;
	// Physics : 
	b_flags3 nicename("Flags") flags3;
	float nicename("Ground Friction") ground_friction;
	float nicename("Ground Depth") ground_depth;
	float nicename("Ground Damp Factor") ground_damp_factor;
	float nicename("Ground Moving Friction") ground_moving_friction;
	float nicename("Ground Maximum Slope 0") ground_maximum_slope_0;
	float nicename("Ground Maximum Slope 1 (Less Than Slope 0)") ground_maximum_slope_1_less_than_slope_0;
	float __unknown73;
	float nicename("Anti Gravity Bank Lift") anti_gravity_bank_lift;
	float nicename("Steering Bank Reaction Scale") steering_bank_reaction_scale;
	float nicename("Gravity Scale") gravity_scale;
	int16_t __unknown74;
	int16_t __unknown75;
	b_flags_2 nicename("Flags 2") flags_2;
	int32_t __unknown76;
	s_tag_block_definition<s_anti_gravity_points_definition> nicename("Anti Gravity Points") anti_gravity_points_block;
	s_tag_block_definition<s_friction_points_definition> nicename("Friction Points") friction_points_block;
	Undefined32 __unknown77;
	s_tag_block_definition<s_tricks_definition> nicename("Tricks") tricks_block;
	e_player_training_vehicle_type nicename("Player Training Vehicle Type") player_training_vehicle_type;
	e_vehicle_size nicename("Vehicle Size") vehicle_size;
	int8_t __unknown78;
	int8_t __unknown79;
	float nicename("Minimum Flipping Angular Velocity") minimum_flipping_angular_velocity;
	float nicename("Maximum Flipping Angular Velocity") maximum_flipping_angular_velocity;
	Undefined32 __unknown80;
	float __unknown81;
	float nicename("Seat Entrance Acceleration Scale") seat_entrance_acceleration_scale;
	float nicename("Seat Exit Acceleration Scale") seat_exit_acceleration_scale;
	float nicename("Flip Time") flip_time;
	string_id nicename("Flip Over Message") flip_over_message;
	TagReference nicename("Suspension Sound") suspension_sound_reference;
	TagReference nicename("Running Effect") running_effect_reference;
	TagReference nicename("Unknown Response") unknown_response_reference;
	TagReference nicename("Unknown Response") unknown_response1_reference;
};

