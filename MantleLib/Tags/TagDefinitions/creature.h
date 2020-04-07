#pragma once

struct nicename("creature") tag_group('crea') s_creature_definition
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

	enum nicename("Motion Sensor Blip Size") e_motion_sensor_blip_size : uint16_t
	{
		/*nicename("Medium")*/ _motion_sensor_blip_size_medium = 0ui16,
		/*nicename("Small")*/ _motion_sensor_blip_size_small = 1ui16,
		/*nicename("Large")*/ _motion_sensor_blip_size_large = 2ui16,
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
		/*nicename("Bit 0")*/ _flags1_bit_0 = 1ui32 << 0ui32,
		/*nicename("Infection Form")*/ _flags1_infection_form = 1ui32 << 1ui32,
		/*nicename("Immune To Falling Damage")*/ _flags1_immune_to_falling_damage = 1ui32 << 2ui32,
		/*nicename("Rotate While Airborne")*/ _flags1_rotate_while_airborne = 1ui32 << 3ui32,
		/*nicename("Zapped By Shields")*/ _flags1_zapped_by_shields = 1ui32 << 4ui32,
		/*nicename("Attach Upon Impact")*/ _flags1_attach_upon_impact = 1ui32 << 5ui32,
		/*nicename("Not On Motion Sensor")*/ _flags1_not_on_motion_sensor = 1ui32 << 6ui32,
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
		/*nicename("Centered At Origin")*/ _flags2_centered_at_origin = 1ui32 << 0ui32,
		/*nicename("Shape Sperical")*/ _flags2_shape_sperical = 1ui32 << 1ui32,
		/*nicename("Use Player Physics")*/ _flags2_use_player_physics = 1ui32 << 2ui32,
		/*nicename("Climb Any Surface")*/ _flags2_climb_any_surface = 1ui32 << 3ui32,
		/*nicename("Flying")*/ _flags2_flying = 1ui32 << 4ui32,
		/*nicename("Not Physical")*/ _flags2_not_physical = 1ui32 << 5ui32,
		/*nicename("Dead Character Collision Group")*/ _flags2_dead_character_collision_group = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags2_bit_7 = 1ui32 << 7ui32,
		/*nicename("Never Rests")*/ _flags2_never_rests = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags2_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags2_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags2_bit_11 = 1ui32 << 11ui32,
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

	struct nicename("Dead Sphere Shapes") s_dead_sphere_shapes_definition
	{
		string_id nicename("Name") name;
		int8_t nicename("Material Index") material_index;
		int8_t __unknown0;
		int16_t nicename("Global Material Index") global_material_index;
		float nicename("Relative Mass Scale") relative_mass_scale;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Volume") volume;
		float nicename("Mass") mass;
		int16_t nicename("Overall Shape Index") overall_shape_index;
		int8_t nicename("Phantom Index") phantom_index;
		int8_t nicename("Interaction Unknown") interaction_unknown;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		Undefined32 __unknown3;
		int32_t nicename("Offset") offset;
		Undefined32 __unknown4;
		int32_t __unknown5;
		Undefined32 __unknown6;
		float nicename("Radius") radius;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		int16_t nicename("Size") size1;
		int16_t nicename("Count") count1;
		Undefined32 __unknown16;
		int32_t nicename("Offset") offset1;
		Undefined32 __unknown17;
		int32_t __unknown18;
		Undefined32 __unknown19;
		float nicename("Radius") radius1;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
		Undefined32 __unknown22;
		Undefined32 __unknown23;
		Undefined32 __unknown24;
		Undefined32 __unknown25;
		Undefined32 __unknown26;
		float nicename("Translation i") translation_i;
		float nicename("Translation j") translation_j;
		float nicename("Translation k") translation_k;
		float nicename("Translation Radius") translation_radius;
	};

	struct nicename("Pill Shapes") s_pill_shapes_definition
	{
		string_id nicename("Name") name;
		int8_t nicename("Material Index") material_index;
		int8_t __unknown0;
		int16_t nicename("Global Material Index") global_material_index;
		float nicename("Relative Mass Scale") relative_mass_scale;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Volume") volume;
		float nicename("Mass") mass;
		int16_t nicename("Overall Shape Index") overall_shape_index;
		int8_t nicename("Phantom Index") phantom_index;
		int8_t nicename("Interaction Unknown") interaction_unknown;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		Undefined32 __unknown3;
		int32_t nicename("Offset") offset;
		Undefined32 __unknown4;
		int32_t __unknown5;
		Undefined32 __unknown6;
		float nicename("Radius") radius;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		float nicename("Bottom i") bottom_i;
		float nicename("Bottom j") bottom_j;
		float nicename("Bottom k") bottom_k;
		float nicename("Bottom Radius") bottom_radius;
		float nicename("Top i") top_i;
		float nicename("Top j") top_j;
		float nicename("Top k") top_k;
		float nicename("Top Radius") top_radius;
	};

	struct nicename("Sphere Shapes") s_sphere_shapes_definition
	{
		string_id nicename("Name") name;
		int8_t nicename("Material Index") material_index;
		int8_t __unknown0;
		int16_t nicename("Global Material Index") global_material_index;
		float nicename("Relative Mass Scale") relative_mass_scale;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Volume") volume;
		float nicename("Mass") mass;
		int16_t nicename("Overall Shape Index") overall_shape_index;
		int8_t nicename("Phantom Index") phantom_index;
		int8_t nicename("Interaction Unknown") interaction_unknown;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		Undefined32 __unknown3;
		int32_t nicename("Offset") offset;
		Undefined32 __unknown4;
		int32_t __unknown5;
		Undefined32 __unknown6;
		float nicename("Radius") radius;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		Undefined32 __unknown13;
		Undefined32 __unknown14;
		Undefined32 __unknown15;
		int16_t nicename("Size") size1;
		int16_t nicename("Count") count1;
		Undefined32 __unknown16;
		int32_t nicename("Offset") offset1;
		Undefined32 __unknown17;
		int32_t __unknown18;
		Undefined32 __unknown19;
		float nicename("Radius") radius1;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
		Undefined32 __unknown22;
		Undefined32 __unknown23;
		Undefined32 __unknown24;
		Undefined32 __unknown25;
		Undefined32 __unknown26;
		float nicename("Translation i") translation_i;
		float nicename("Translation j") translation_j;
		float nicename("Translation k") translation_k;
		float nicename("Translation Radius") translation_radius;
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

		enum nicename("Flags") b_flags3 : uint8_t /* bitfield */
		{
			/*nicename("Must Have Active Seats")*/ _flags3_must_have_active_seats = 1ui8 << 0ui8,
		};

		b_flags3 nicename("Flags") flags;
		e_unit nicename("Unit") unit;
		e_classification nicename("Classification") classification;
		int8_t __unknown0;
		int16_t nicename("Points") points;
		int16_t __unknown1;
	};

	struct nicename("Unknown") s_unknown3_definition
	{
		DataReference nicename("Function") function_data_reference;
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
	// CREATURE : 
	b_flags1 nicename("Flags") flags1;
	e_team nicename("Team") team;
	e_motion_sensor_blip_size nicename("Motion Sensor Blip Size") motion_sensor_blip_size;
	float nicename("Turning Velocity Maximum") turning_velocity_maximum;
	float nicename("Turning Acceleration Maximum") turning_acceleration_maximum;
	float nicename("Casual Turing Modifer") casual_turing_modifer;
	float nicename("Autoaim Width") autoaim_width;
	// Physics : 
	b_flags2 nicename("Flags") flags2;
	float nicename("Height Standing") height_standing;
	float nicename("Height Crouching") height_crouching;
	float nicename("Radius") radius;
	float nicename("Mass") mass;
	string_id nicename("Living Material Name") living_material_name;
	string_id nicename("Dead Material Name") dead_material_name;
	int16_t nicename("Living Global Material Index") living_global_material_index;
	int16_t nicename("Dead Global Material Index") dead_global_material_index;
	s_tag_block_definition<s_dead_sphere_shapes_definition> nicename("Dead Sphere Shapes") dead_sphere_shapes_block;
	s_tag_block_definition<s_pill_shapes_definition> nicename("Pill Shapes") pill_shapes_block;
	s_tag_block_definition<s_sphere_shapes_definition> nicename("Sphere Shapes") sphere_shapes_block;
	// Ground : 
	float nicename("Maximum Slope Angle") maximum_slope_angle;
	float nicename("Downhill Falloff Angle") downhill_falloff_angle;
	float nicename("Downhill Cutoff Angle") downhill_cutoff_angle;
	float nicename("Uphill Falloff Angle") uphill_falloff_angle;
	float nicename("Uphill Cutoff Angle") uphill_cutoff_angle;
	float nicename("Downhill Velocity Scale") downhill_velocity_scale;
	float nicename("Uphill Velocity Scale") uphill_velocity_scale;
	float __unknown4;
	float __unknown5;
	float __unknown6;
	float __unknown7;
	float __unknown8;
	float __unknown9;
	float __unknown10;
	float nicename("Falling Velocity Scale") falling_velocity_scale;
	float __unknown11;
	float __unknown12;
	// Flying : 
	float nicename("Bank Angle") bank_angle;
	float nicename("Bank Apply Time") bank_apply_time;
	float nicename("Bank Decay Time") bank_decay_time;
	float nicename("Pitch Ratio") pitch_ratio;
	float nicename("Maximum Velocity") maximum_velocity;
	float nicename("Maximum Sidestep Velocity") maximum_sidestep_velocity;
	float nicename("Acceleration") acceleration;
	float nicename("Deceleration") deceleration;
	float nicename("Angular Velocity Maximum") angular_velocity_maximum;
	float nicename("Angular Acceleration Maximum") angular_acceleration_maximum;
	float nicename("Crouch Velocity Modifier") crouch_velocity_modifier;
	Undefined32 __unknown13;
	TagReference nicename("Impact Damage") impact_damage_reference;
	TagReference nicename("Impact Shield Damage") impact_shield_damage_reference;
	s_tag_block_definition<s_metagame_properties_definition> nicename("Metagame Properties") metagame_properties_block;
	float nicename("Destroy After Death Time min") destroy_after_death_time_min;
	float nicename("Destroy After Death Time max") destroy_after_death_time_max;
	int32_t __unknown14;
	TagReference nicename("Weapon Effect") weapon_effect_reference;
	Undefined32 __unknown15;
	Undefined32 __unknown16;
	Undefined32 __unknown17;
	TagReference __unknown18;
	Undefined32 __unknown19;
	Undefined32 __unknown20;
	Undefined32 __unknown21;
	s_tag_block_definition<s_unknown3_definition> __unknown22;
	TagReference nicename("Firing Effect") firing_effect_reference;
	Undefined32 __unknown23;
	Undefined32 __unknown24;
	TagReference nicename("Destruction Effect") destruction_effect_reference;
};

