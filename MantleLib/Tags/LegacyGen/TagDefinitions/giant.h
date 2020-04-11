#pragma once

struct nicename("giant") tag_group('gint') s_giant_definition
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

	enum nicename("Team") e_team : uint16_t
	{
		/*nicename("Default")*/ _team_default = 1ui16,
		/*nicename("Player")*/ _team_player = 2ui16,
		/*nicename("Human")*/ _team_human = 3ui16,
		/*nicename("Covenant")*/ _team_covenant = 4ui16,
		/*nicename("Brute")*/ _team_brute = 5ui16,
		/*nicename("Mule")*/ _team_mule = 6ui16,
		/*nicename("Spare")*/ _team_spare = 7ui16,
		/*nicename("Covenant Player")*/ _team_covenant_player = 8ui16,
	};

	enum nicename("Constant Sound Volume") e_constant_sound_volume : uint16_t
	{
		/*nicename("Silent")*/ _constant_sound_volume_silent = 1ui16,
		/*nicename("Medium")*/ _constant_sound_volume_medium = 2ui16,
		/*nicename("Loud")*/ _constant_sound_volume_loud = 3ui16,
		/*nicename("Shout")*/ _constant_sound_volume_shout = 4ui16,
		/*nicename("Quiet")*/ _constant_sound_volume_quiet = 5ui16,
	};

	enum nicename("Motion Sensor Blip Size") e_motion_sensor_blip_size : uint16_t
	{
		/*nicename("Medium")*/ _motion_sensor_blip_size_medium = 1ui16,
		/*nicename("Small")*/ _motion_sensor_blip_size_small = 2ui16,
		/*nicename("Large")*/ _motion_sensor_blip_size_large = 3ui16,
	};

	enum nicename("Item Scale") e_item_scale : uint16_t
	{
		/*nicename("Small")*/ _item_scale_small = 1ui16,
		/*nicename("Medium")*/ _item_scale_medium = 2ui16,
		/*nicename("Large")*/ _item_scale_large = 3ui16,
		/*nicename("Huge")*/ _item_scale_huge = 4ui16,
	};

	enum nicename("Grenade Type") e_grenade_type : uint16_t
	{
		/*nicename("Human Fragmentation")*/ _grenade_type_human_fragmentation = 1ui16,
		/*nicename("Covenant Plasma")*/ _grenade_type_covenant_plasma = 2ui16,
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

	struct nicename("Metagame Properties") s_metagame_properties_definition
	{
		enum nicename("Unit") e_unit : uint8_t
		{
			/*nicename("Brute")*/ _unit_brute = 1ui8,
			/*nicename("Grunt")*/ _unit_grunt = 2ui8,
			/*nicename("Jackal")*/ _unit_jackal = 3ui8,
			/*nicename("Skirmisher")*/ _unit_skirmisher = 4ui8,
			/*nicename("Marine")*/ _unit_marine = 5ui8,
			/*nicename("Spartan")*/ _unit_spartan = 6ui8,
			/*nicename("Bugger")*/ _unit_bugger = 7ui8,
			/*nicename("Hunter")*/ _unit_hunter = 8ui8,
			/*nicename("Flood Infection")*/ _unit_flood_infection = 9ui8,
			/*nicename("Flood Carrier")*/ _unit_flood_carrier = 10ui8,
			/*nicename("Flood Combat")*/ _unit_flood_combat = 11ui8,
			/*nicename("Flood Pureform")*/ _unit_flood_pureform = 12ui8,
			/*nicename("Sentinel")*/ _unit_sentinel = 13ui8,
			/*nicename("Elite")*/ _unit_elite = 14ui8,
			/*nicename("Engineer")*/ _unit_engineer = 15ui8,
			/*nicename("Mule")*/ _unit_mule = 16ui8,
			/*nicename("Turret")*/ _unit_turret = 17ui8,
			/*nicename("Mongoose")*/ _unit_mongoose = 18ui8,
			/*nicename("Warthog")*/ _unit_warthog = 19ui8,
			/*nicename("Scorpion")*/ _unit_scorpion = 20ui8,
			/*nicename("Falcon")*/ _unit_falcon = 21ui8,
			/*nicename("Pelican")*/ _unit_pelican = 22ui8,
			/*nicename("Revenant")*/ _unit_revenant = 23ui8,
			/*nicename("Seraph")*/ _unit_seraph = 24ui8,
			/*nicename("Shade")*/ _unit_shade = 25ui8,
			/*nicename("Watchtower")*/ _unit_watchtower = 26ui8,
			/*nicename("Ghost")*/ _unit_ghost = 27ui8,
			/*nicename("Space Banshee")*/ _unit_space_banshee = 28ui8,
			/*nicename("Mauler")*/ _unit_mauler = 29ui8,
			/*nicename("Wraith")*/ _unit_wraith = 30ui8,
			/*nicename("Banshee")*/ _unit_banshee = 31ui8,
			/*nicename("Phantom")*/ _unit_phantom = 32ui8,
			/*nicename("Scarab")*/ _unit_scarab = 33ui8,
			/*nicename("Guntower")*/ _unit_guntower = 34ui8,
			/*nicename("Tuning Fork")*/ _unit_tuning_fork = 35ui8,
		};

		enum nicename("Classification") e_classification : uint8_t
		{
			/*nicename("Infantry")*/ _classification_infantry = 1ui8,
			/*nicename("Leader")*/ _classification_leader = 2ui8,
			/*nicename("Hero")*/ _classification_hero = 3ui8,
			/*nicename("Specialist")*/ _classification_specialist = 4ui8,
			/*nicename("Light Vehicle")*/ _classification_light_vehicle = 5ui8,
			/*nicename("Heavy Vehicle")*/ _classification_heavy_vehicle = 6ui8,
			/*nicename("Giant Vehicle")*/ _classification_giant_vehicle = 7ui8,
			/*nicename("Standard Vehicle")*/ _classification_standard_vehicle = 8ui8,
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
		s_tag_reference_legacy nicename("Screen Effect") screen_effect_reference;
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

	struct nicename("Camera Tracks") s_camera_tracks1_definition
	{
		s_tag_reference_legacy nicename("Track") track_reference;
		s_tag_reference_legacy nicename("Screen Effect") screen_effect_reference;
	};

	struct nicename("Unknown") s_unknown7_definition
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

	struct nicename("Unknown") s_unknown8_definition
	{
		struct nicename("Unknown") s_unknown9_definition
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
		s_tag_block_legacy<s_unknown9_definition> __unknown10;
	};

	struct nicename("Space Fighter Camera") s_space_fighter_camera1_definition
	{
		struct nicename("Unknown") s_unknown10_definition
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
		s_tag_block_legacy<s_unknown10_definition> __unknown10;
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
		s_tag_reference_legacy nicename("Unit HUD Interface") unit_hud_interface_reference;
	};

	struct nicename("Dialogue Variants") s_dialogue_variants_definition
	{
		int16_t nicename("Variant Number") variant_number;
		int16_t __unknown0;
		s_tag_reference_legacy nicename("Dialogue") dialogue_reference;
	};

	struct nicename("Powered Seats") s_powered_seats_definition
	{
		float nicename("Driver Powerup Time") driver_powerup_time;
		float nicename("Driver Powerdown Time") driver_powerdown_time;
	};

	struct nicename("Weapons") s_weapons_definition
	{
		s_tag_reference_legacy nicename("Weapon") weapon_reference;
		string_id nicename("Parent Marker") parent_marker;
	};

	struct nicename("Target Tracking") s_target_tracking_definition
	{
		struct nicename("Tracking Types") s_tracking_types_definition
		{
			string_id nicename("Tracking Type") tracking_type;
		};

		s_tag_block_legacy<s_tracking_types_definition> nicename("Tracking Types") tracking_types_block;
		float nicename("Acquire Time") acquire_time;
		float nicename("Grace Time") grace_time;
		float nicename("Decay Time") decay_time;
		s_tag_reference_legacy nicename("Tracking Sound") tracking_sound_reference;
		s_tag_reference_legacy nicename("Locked Sound") locked_sound_reference;
	};

	struct nicename("Seats") s_seats_definition
	{
		enum nicename("AI Seat Type") e_ai_seat_type : uint16_t
		{
			/*nicename("None")*/ _ai_seat_type_none = 1ui16,
			/*nicename("Passenger")*/ _ai_seat_type_passenger = 2ui16,
			/*nicename("Gunner")*/ _ai_seat_type_gunner = 3ui16,
			/*nicename("Small Cargo")*/ _ai_seat_type_small_cargo = 4ui16,
			/*nicename("Large Cargo")*/ _ai_seat_type_large_cargo = 5ui16,
			/*nicename("Driver")*/ _ai_seat_type_driver = 6ui16,
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
			s_tag_reference_legacy nicename("Track") track_reference;
			s_tag_reference_legacy nicename("Screen Effect") screen_effect_reference;
		};

		struct nicename("Unknown") s_unknown11_definition
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

		struct nicename("Unknown") s_unknown12_definition
		{
			struct nicename("Unknown") s_unknown13_definition
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
			s_tag_block_legacy<s_unknown13_definition> __unknown10;
		};

		struct nicename("Space Fighter Camera") s_space_fighter_camera2_definition
		{
			struct nicename("Unknown") s_unknown14_definition
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
			s_tag_block_legacy<s_unknown14_definition> __unknown10;
		};

		struct nicename("Unit HUD Interface") s_unit_hud_interface_definition
		{
			s_tag_reference_legacy nicename("Unit HUD Interface") unit_hud_interface_reference;
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
		s_tag_reference_legacy nicename("Spring Acceleration") spring_acceleration_reference;
		float nicename("AI Scariness") ai_scariness;
		e_ai_seat_type nicename("AI Seat Type") ai_seat_type;
		int16_t nicename("Boarding Seat") boarding_seat;
		s_undefined32_legacy nicename("block here") block_here;
		s_undefined32_legacy nicename("block here") block_here1;
		s_undefined32_legacy nicename("block here") block_here2;
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
		s_tag_block_legacy<s_camera_tracks2_definition> nicename("Camera Tracks") camera_tracks_block;
		float nicename("Camera Stiffness min") camera_stiffness_min;
		float nicename("Camera Stiffness max") camera_stiffness_max;
		float __unknown4;
		float nicename("Camera Acceleration Speed") camera_acceleration_speed;
		float nicename("Camera Deceleration Speed") camera_deceleration_speed;
		float __unknown5;
		float nicename("Camera Field Of View") camera_field_of_view;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_tag_block_legacy<s_unknown11_definition> __unknown12;
		s_tag_block_legacy<s_unknown12_definition> __unknown13;
		s_tag_block_legacy<s_space_fighter_camera2_definition> nicename("Space Fighter Camera") space_fighter_camera_block;
		s_tag_block_legacy<s_unit_hud_interface_definition> nicename("Unit HUD Interface") unit_hud_interface_block;
		string_id nicename("Enter Seat String") enter_seat_string;
		float nicename("Yaw Range min") yaw_range_min;
		float nicename("Yaw Range max") yaw_range_max;
		s_tag_reference_legacy nicename("Built-In Gunner") built_in_gunner_reference;
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

	struct nicename("Buckling Parameters") s_buckling_parameters_definition
	{
		float __unknown0;
		int32_t __unknown1;
		float __unknown2;
		int32_t __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		string_id nicename("Marker") marker;
		float nicename("Scan Distance 1 Float") scan_distance_1_float;
		float nicename("Scan Distance 2 Float") scan_distance_2_float;
		int32_t nicename("Scan Distance 1 Integer") scan_distance_1_integer;
		int32_t nicename("Scan Distance 2 Integer") scan_distance_2_integer;
		float nicename("min") min;
		float nicename("max") max;
		float nicename("min") min1;
		float nicename("max") max1;
		string_id nicename("Buckle Animation") buckle_animation;
		string_id nicename("Buckle Wobble Animation") buckle_wobble_animation;
		string_id nicename("Buckle Wobble Animation") buckle_wobble_animation1;
		float __unknown9;
		float __unknown10;
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
	// UNIT : 
	b_flags1 nicename("Flags") flags1;
	e_team nicename("Team") team;
	e_constant_sound_volume nicename("Constant Sound Volume") constant_sound_volume;
	s_tag_reference_legacy nicename("Hologram Unit") hologram_unit_reference;
	s_tag_block_legacy<s_metagame_properties_definition> nicename("Metagame Properties") metagame_properties_block;
	s_tag_block_legacy<s_unit_screen_effects_definition> nicename("Unit Screen Effects") unit_screen_effects_block;
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
	s_tag_block_legacy<s_camera_tracks_definition> nicename("Camera Tracks") camera_tracks_block;
	float nicename("Camera Stiffness min") camera_stiffness_min;
	float nicename("Camera Stiffness max") camera_stiffness_max;
	float __unknown8;
	float nicename("Camera Acceleration Speed") camera_acceleration_speed;
	float nicename("Camera Deceleration Speed") camera_deceleration_speed;
	float __unknown9;
	float nicename("Camera Field Of View") camera_field_of_view;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
	s_tag_block_legacy<s_unknown3_definition> __unknown16;
	s_tag_block_legacy<s_unknown4_definition> __unknown17;
	s_tag_block_legacy<s_space_fighter_camera_definition> nicename("Space Fighter Camera") space_fighter_camera_block;
	// Assassination Camera : 
	b_camera_flags1 nicename("Camera Flags") camera_flags1;
	int8_t __unknown18;
	int8_t __unknown19;
	int8_t __unknown20;
	string_id nicename("Camera Marker") camera_marker1;
	float nicename("Pitch Auto-Level") pitch_auto_level1;
	float nicename("Pitch Range min") pitch_range_min1;
	float nicename("Pitch Range max") pitch_range_max1;
	s_tag_block_legacy<s_camera_tracks1_definition> nicename("Camera Tracks") camera_tracks1_block;
	float nicename("Camera Stiffness min") camera_stiffness_min1;
	float nicename("Camera Stiffness max") camera_stiffness_max1;
	float __unknown21;
	float nicename("Camera Acceleration Speed") camera_acceleration_speed1;
	float nicename("Camera Deceleration Speed") camera_deceleration_speed1;
	float __unknown22;
	float nicename("Camera Field Of View") camera_field_of_view1;
	s_undefined32_legacy __unknown23;
	s_undefined32_legacy __unknown24;
	s_undefined32_legacy __unknown25;
	s_undefined32_legacy __unknown26;
	s_undefined32_legacy __unknown27;
	s_undefined32_legacy __unknown28;
	s_tag_block_legacy<s_unknown7_definition> __unknown29;
	s_tag_block_legacy<s_unknown8_definition> __unknown30;
	s_tag_block_legacy<s_space_fighter_camera1_definition> nicename("Space Fighter Camera") space_fighter_camera1_block;
	s_tag_reference_legacy nicename("Assassination Response") assassination_response_reference;
	s_tag_reference_legacy nicename("Assassination Tool") assassination_tool_reference;
	string_id nicename("Assassination Tool Marker") assassination_tool_marker;
	string_id nicename("Assassination Tool Hand Marker") assassination_tool_hand_marker;
	string_id nicename("Assassination Tool Stow Anchor") assassination_tool_stow_anchor;
	s_tag_reference_legacy nicename("Spring Acceleration") spring_acceleration_reference;
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
	s_undefined32_legacy __unknown36;
	s_undefined32_legacy __unknown37;
	float __unknown38;
	s_undefined32_legacy __unknown39;
	float __unknown40;
	float __unknown41;
	float __unknown42;
	s_undefined32_legacy __unknown43;
	float __unknown44;
	float nicename("Feign Death Chance") feign_death_chance;
	float nicename("Feign Repeat Chance") feign_repeat_chance;
	s_tag_reference_legacy nicename("Spawned Turret Character") spawned_turret_character_reference;
	int16_t nicename("Spawned Actor Count min") spawned_actor_count_min;
	int16_t nicename("Spawned Actor Count max") spawned_actor_count_max;
	float nicename("Spawned Velocity") spawned_velocity;
	string_id nicename("Aiming Pivot Marker") aiming_pivot_marker;
	float nicename("Aiming Velocity Maximum") aiming_velocity_maximum;
	float nicename("Aiming Acceleration Maximum") aiming_acceleration_maximum;
	float nicename("Casual Aiming Modifier") casual_aiming_modifier;
	float nicename("Looking Velocity Maximum") looking_velocity_maximum;
	float nicename("Looking Acceleration Maximum") looking_acceleration_maximum;
	s_undefined32_legacy __unknown45;
	string_id nicename("Right Hand Node") right_hand_node;
	string_id nicename("Left Hand Node") left_hand_node;
	string_id nicename("Preferred Gun Node") preferred_gun_node;
	string_id nicename("Preferred Grenade Node") preferred_grenade_node;
	s_undefined32_legacy __unknown46;
	s_tag_reference_legacy nicename("AI Melee Damage") ai_melee_damage_reference;
	s_tag_reference_legacy nicename("Melee Damage") melee_damage_reference;
	s_tag_reference_legacy nicename("Boarding Melee Damage") boarding_melee_damage_reference;
	s_tag_reference_legacy nicename("Boarding Melee Response") boarding_melee_response_reference;
	s_tag_reference_legacy nicename("Ejection Melee Damage") ejection_melee_damage_reference;
	s_tag_reference_legacy nicename("Ejection Melee Response") ejection_melee_response_reference;
	s_tag_reference_legacy nicename("Landing Melee Damage") landing_melee_damage_reference;
	s_tag_reference_legacy nicename("Flurry Melee Damage") flurry_melee_damage_reference;
	s_tag_reference_legacy nicename("Obstacle Smash Melee Damage") obstacle_smash_melee_damage_reference;
	s_tag_reference_legacy nicename("Assassination Damage") assassination_damage_reference;
	e_motion_sensor_blip_size nicename("Motion Sensor Blip Size") motion_sensor_blip_size;
	e_item_scale nicename("Item Scale") item_scale;
	string_id nicename("Equipment Variant") equipment_variant;
	string_id nicename("Dropped Equipment Variant") dropped_equipment_variant;
	s_tag_block_legacy<s_postures_definition> nicename("Postures") postures_block;
	s_tag_block_legacy<s_hud_interfaces_definition> nicename("HUD Interfaces") hud_interfaces_block;
	s_tag_block_legacy<s_dialogue_variants_definition> nicename("Dialogue Variants") dialogue_variants_block;
	float nicename("Grenade Arc") grenade_arc;
	float nicename("Grenade Force") grenade_force;
	float nicename("Grenade Angle") grenade_angle;
	float nicename("Grenade Velocity") grenade_velocity;
	e_grenade_type nicename("Grenade Type") grenade_type;
	int16_t nicename("Grenade Count") grenade_count;
	s_tag_block_legacy<s_powered_seats_definition> nicename("Powered Seats") powered_seats_block;
	s_tag_block_legacy<s_weapons_definition> nicename("Weapons") weapons_block;
	s_tag_block_legacy<s_target_tracking_definition> nicename("Target Tracking") target_tracking_block;
	s_tag_block_legacy<s_seats_definition> nicename("Seats") seats_block;
	float __unknown47;
	float __unknown48;
	float nicename("EMP Radius") emp_radius;
	s_tag_reference_legacy nicename("EMP Effect") emp_effect_reference;
	s_tag_reference_legacy nicename("Boost Collision Damage") boost_collision_damage_reference;
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
	s_data_reference_legacy nicename("Boost Function") boost_function_data_reference;
	float nicename("Lipsync Attack Weight") lipsync_attack_weight;
	float nicename("Lipsync Decay Weight") lipsync_decay_weight;
	s_tag_reference_legacy nicename("Detach Damage") detach_damage_reference;
	s_tag_reference_legacy nicename("Detached Weapon") detached_weapon_reference;
	// GIANT : 
	s_undefined32_legacy __unknown52;
	float __unknown53;
	float __unknown54;
	float nicename("Animation Speed") animation_speed;
	float nicename("Animation Start Speed") animation_start_speed;
	float nicename("Vertical Force") vertical_force;
	float __unknown55;
	float __unknown56;
	float nicename("Leg Attach Radius") leg_attach_radius;
	float __unknown57;
	s_tag_block_legacy<s_buckling_parameters_definition> nicename("Buckling Parameters") buckling_parameters_block;
	float nicename("Toe Joint Extended Fraction") toe_joint_extended_fraction;
};

