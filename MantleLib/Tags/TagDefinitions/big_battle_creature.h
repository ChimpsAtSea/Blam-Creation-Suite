#pragma once

struct nicename("big_battle_creature") tag_group('bbcr') s_big_battle_creature_definition
{
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

	enum nicename("Motion Sensor Blip Size") e_motion_sensor_blip_size : uint16_t
	{
		/*nicename("Medium")*/ _motion_sensor_blip_size_medium = 1ui16,
		/*nicename("Small")*/ _motion_sensor_blip_size_small = 2ui16,
		/*nicename("Large")*/ _motion_sensor_blip_size_large = 3ui16,
	};

	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _flags_bit_0 = 1ui32 << 0ui32,
		/*nicename("Infection Form")*/ _flags_infection_form = 1ui32 << 1ui32,
		/*nicename("Immune To Falling Damage")*/ _flags_immune_to_falling_damage = 1ui32 << 2ui32,
		/*nicename("Rotate While Airborne")*/ _flags_rotate_while_airborne = 1ui32 << 3ui32,
		/*nicename("Zapped By Shields")*/ _flags_zapped_by_shields = 1ui32 << 4ui32,
		/*nicename("Attach Upon Impact")*/ _flags_attach_upon_impact = 1ui32 << 5ui32,
		/*nicename("Not On Motion Sensor")*/ _flags_not_on_motion_sensor = 1ui32 << 6ui32,
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
		/*nicename("Centered At Origin")*/ _flags1_centered_at_origin = 1ui32 << 0ui32,
		/*nicename("Shape Sperical")*/ _flags1_shape_sperical = 1ui32 << 1ui32,
		/*nicename("Use Player Physics")*/ _flags1_use_player_physics = 1ui32 << 2ui32,
		/*nicename("Climb Any Surface")*/ _flags1_climb_any_surface = 1ui32 << 3ui32,
		/*nicename("Flying")*/ _flags1_flying = 1ui32 << 4ui32,
		/*nicename("Not Physical")*/ _flags1_not_physical = 1ui32 << 5ui32,
		/*nicename("Dead Character Collision Group")*/ _flags1_dead_character_collision_group = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
		/*nicename("Never Rests")*/ _flags1_never_rests = 1ui32 << 8ui32,
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

	struct nicename("Unknown") s_unknown_definition
	{
		DataReference nicename("Function") function_data_reference;
	};

	b_flags nicename("Flags") flags;
	e_team nicename("Team") team;
	e_motion_sensor_blip_size nicename("Motion Sensor Blip Size") motion_sensor_blip_size;
	float nicename("Turning Velocity Maximum") turning_velocity_maximum;
	float nicename("Turning Acceleration Maximum") turning_acceleration_maximum;
	float nicename("Casual Turing Modifer") casual_turing_modifer;
	float nicename("Autoaim Width") autoaim_width;
	// Physics : 
	b_flags1 nicename("Flags") flags1;
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
	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	float __unknown4;
	float __unknown5;
	float __unknown6;
	float nicename("Falling Velocity Scale") falling_velocity_scale;
	float __unknown7;
	float __unknown8;
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
	Undefined32 __unknown9;
	TagReference nicename("Impact Damage") impact_damage_reference;
	TagReference nicename("Impact Shield Damage") impact_shield_damage_reference;
	s_tag_block_definition<s_metagame_properties_definition> nicename("Metagame Properties") metagame_properties_block;
	float nicename("Destroy After Death Time min") destroy_after_death_time_min;
	float nicename("Destroy After Death Time max") destroy_after_death_time_max;
	int32_t __unknown10;
	TagReference nicename("Weapon Effect") weapon_effect_reference;
	Undefined32 __unknown11;
	Undefined32 __unknown12;
	Undefined32 __unknown13;
	TagReference __unknown14;
	Undefined32 __unknown15;
	Undefined32 __unknown16;
	Undefined32 __unknown17;
	s_tag_block_definition<s_unknown_definition> __unknown18;
	TagReference nicename("Firing Effect") firing_effect_reference;
	Undefined32 __unknown19;
	Undefined32 __unknown20;
	TagReference nicename("Destruction Effect") destruction_effect_reference;
	TagReference nicename("Imposter Model") imposter_model_reference;
};

