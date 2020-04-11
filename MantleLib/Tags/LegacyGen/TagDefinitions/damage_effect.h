#pragma once

struct nicename("damage_effect") tag_group('jpt!') s_damage_effect_definition
{
	enum nicename("Side Effect") e_side_effect : uint16_t
	{
		/*nicename("None")*/ _side_effect_none = 0ui16,
		/*nicename("Harmless")*/ _side_effect_harmless = 1ui16,
		/*nicename("Lethal To The Unsuspecting")*/ _side_effect_lethal_to_the_unsuspecting = 2ui16,
		/*nicename("Emp")*/ _side_effect_emp = 3ui16,
	};

	enum nicename("Category") e_category : uint16_t
	{
		/*nicename("None")*/ _category_none = 0ui16,
		/*nicename("Falling")*/ _category_falling = 1ui16,
		/*nicename("Bullet")*/ _category_bullet = 2ui16,
		/*nicename("Grenade")*/ _category_grenade = 3ui16,
		/*nicename("High Explosive")*/ _category_high_explosive = 4ui16,
		/*nicename("Sniper")*/ _category_sniper = 5ui16,
		/*nicename("Melee")*/ _category_melee = 6ui16,
		/*nicename("Flame")*/ _category_flame = 7ui16,
		/*nicename("Mounted Weapon")*/ _category_mounted_weapon = 8ui16,
		/*nicename("Vehicle")*/ _category_vehicle = 9ui16,
		/*nicename("Plasma")*/ _category_plasma = 10ui16,
		/*nicename("Needle")*/ _category_needle = 11ui16,
		/*nicename("Shotgun")*/ _category_shotgun = 12ui16,
	};

	enum nicename("Forced Death Dialogue") e_forced_death_dialogue : uint32_t
	{
		/*nicename("Default")*/ _forced_death_dialogue_default = 0ui32,
		/*nicename("dth")*/ _forced_death_dialogue_dth = 1ui32,
		/*nicename("dth_fall")*/ _forced_death_dialogue_dth_fall = 2ui32,
		/*nicename("dth_mjr")*/ _forced_death_dialogue_dth_mjr = 3ui32,
		/*nicename("dth_slw")*/ _forced_death_dialogue_dth_slw = 4ui32,
		/*nicename("dth_hdsht")*/ _forced_death_dialogue_dth_hdsht = 5ui32,
		/*nicename("dth_slnt")*/ _forced_death_dialogue_dth_slnt = 6ui32,
		/*nicename("dth_drama")*/ _forced_death_dialogue_dth_drama = 7ui32,
		/*nicename("dth_reanimated")*/ _forced_death_dialogue_dth_reanimated = 8ui32,
		/*nicename("thrwn")*/ _forced_death_dialogue_thrwn = 9ui32,
		/*nicename("die_space")*/ _forced_death_dialogue_die_space = 10ui32,
		/*nicename("die_ass")*/ _forced_death_dialogue_die_ass = 11ui32,
	};

	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Don't Scale Damage By Distance")*/ _flags_dont_scale_damage_by_distance = 1ui32 << 0ui32,
		/*nicename("Area Damage Players Only")*/ _flags_area_damage_players_only = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
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
		/*nicename("Does Not Hurt Owner")*/ _flags1_does_not_hurt_owner = 1ui32 << 0ui32,
		/*nicename("Can Cause Headshots")*/ _flags1_can_cause_headshots = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui32 << 2ui32,
		/*nicename("Pings Resistant Units")*/ _flags1_pings_resistant_units = 1ui32 << 3ui32,
		/*nicename("Does Not Hurt Friends")*/ _flags1_does_not_hurt_friends = 1ui32 << 4ui32,
		/*nicename("Does Not Ping Units")*/ _flags1_does_not_ping_units = 1ui32 << 5ui32,
		/*nicename("Detonates Explosives")*/ _flags1_detonates_explosives = 1ui32 << 6ui32,
		/*nicename("Only Hurts Shields")*/ _flags1_only_hurts_shields = 1ui32 << 7ui32,
		/*nicename("Causes Flaming Death")*/ _flags1_causes_flaming_death = 1ui32 << 8ui32,
		/*nicename("Skips Shields")*/ _flags1_skips_shields = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
		/*nicename("Ignore Seat Scale For Direct Damage")*/ _flags1_ignore_seat_scale_for_direct_damage = 1ui32 << 12ui32,
		/*nicename("Forces Hard Ping")*/ _flags1_forces_hard_ping = 1ui32 << 13ui32,
		/*nicename("Does Not Hurt Players")*/ _flags1_does_not_hurt_players = 1ui32 << 14ui32,
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

	struct nicename("Special Damages") s_special_damages_definition
	{
		string_id_legacy nicename("Special Damage") special_damage;
	};

	struct nicename("Ricochets") s_ricochets_definition
	{
		s_tag_reference_legacy nicename("Sound") sound_reference;
		int16_t __unknown0;
		int16_t __unknown1;
	};

	float nicename("Radius min") radius_min;
	float nicename("Radius max") radius_max;
	float nicename("Cutoff Scale") cutoff_scale;
	b_flags nicename("Flags") flags;
	e_side_effect nicename("Side Effect") side_effect;
	e_category nicename("Category") category;
	e_forced_death_dialogue nicename("Forced Death Dialogue") forced_death_dialogue;
	b_flags1 nicename("Flags") flags1;
	float nicename("Area Of Effect Core Radius") area_of_effect_core_radius;
	float nicename("Damage Lower Bound") damage_lower_bound;
	float nicename("Damage Upper Bound min") damage_upper_bound_min;
	float nicename("Damage Upper Bound max") damage_upper_bound_max;
	s_data_reference_legacy __unknown0;
	float nicename("Damage Inner Cone Angle") damage_inner_cone_angle;
	float nicename("Damage Outer Cone Angle") damage_outer_cone_angle;
	float nicename("Active Camoflage Damage") active_camoflage_damage;
	float nicename("Stun") stun;
	float nicename("Max Stun") max_stun;
	float nicename("Stun Time") stun_time;
	int32_t __unknown1;
	float nicename("Instantaneous Acceleration") instantaneous_acceleration;
	float nicename("Rider Direct Damage Scale") rider_direct_damage_scale;
	float nicename("Rider Max Transfer Damage") rider_max_transfer_damage;
	float nicename("Rider Min Transfer Damage") rider_min_transfer_damage;
	s_undefined32_legacy __unknown2;
	string_id_legacy nicename("General Damage") general_damage;
	string_id_legacy nicename("Specific Damage") specific_damage;
	s_tag_block_legacy<s_special_damages_definition> nicename("Special Damages") special_damages_block;
	float nicename("AI Stun Radius") ai_stun_radius;
	float nicename("AI Stun Bounds min") ai_stun_bounds_min;
	float nicename("AI Stun Bounds max") ai_stun_bounds_max;
	float nicename("Shake Radius") shake_radius;
	float nicename("EMP Radius") emp_radius;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	float __unknown5;
	s_tag_reference_legacy nicename("Damage Response") damage_response_reference;
	// Sound : 
	s_tag_reference_legacy nicename("Sound") sound1_reference;
	s_tag_block_legacy<s_ricochets_definition> nicename("Ricochets") ricochets_block;
	// Breaking Effect : 
	float nicename("Forward Velocity") forward_velocity;
	float nicename("Forward Radius") forward_radius;
	float nicename("Forward Exponent") forward_exponent;
	float nicename("Outward Velocity") outward_velocity;
	float nicename("Outward Radius") outward_radius;
	float nicename("Outward Exponent") outward_exponent;
};

