#pragma once

struct nicename("character") tag_group('char') s_character_definition_legacy
{
	enum nicename("Character Flags") b_character_flags : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _character_flags_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _character_flags_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _character_flags_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _character_flags_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _character_flags_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _character_flags_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _character_flags_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _character_flags_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _character_flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _character_flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _character_flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _character_flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _character_flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _character_flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _character_flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _character_flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _character_flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _character_flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _character_flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _character_flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _character_flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _character_flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _character_flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _character_flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _character_flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _character_flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _character_flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _character_flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _character_flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _character_flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _character_flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _character_flags_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Variants") s_variants_definition_legacy
	{
		struct nicename("Dialogue Variations") s_dialogue_variations_definition_legacy
		{
			s_tag_reference_legacy nicename("Dialogue") dialogue_reference;
			string_id_legacy nicename("Name") name;
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
		};

		string_id_legacy nicename("Variant") variant;
		int16_t nicename("Variant Index") variant_index;
		int16_t __unknown0;
		s_tag_block_legacy<s_dialogue_variations_definition_legacy> nicename("Dialogue Variations") dialogue_variations_block;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Unit Dialogue") s_unit_dialogue_definition_legacy
	{
		struct nicename("Dialogue Variations") s_dialogue_variations1_definition_legacy
		{
			s_tag_reference_legacy nicename("Dialogue") dialogue_reference;
			string_id_legacy nicename("Name") name;
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
		};

		s_tag_block_legacy<s_dialogue_variations1_definition_legacy> nicename("Dialogue Variations") dialogue_variations_block;
		string_id_legacy nicename("Radio Effect") radio_effect;
	};

	struct nicename("General Properties") s_general_properties_definition_legacy
	{
		enum nicename("Actor Type") e_actor_type : uint16_t
		{
			/*nicename("None")*/ _actor_type_none = 0ui16,
			/*nicename("Player")*/ _actor_type_player = 1ui16,
			/*nicename("Marine")*/ _actor_type_marine = 2ui16,
			/*nicename("Crew")*/ _actor_type_crew = 3ui16,
			/*nicename("Spartan")*/ _actor_type_spartan = 4ui16,
			/*nicename("Elite")*/ _actor_type_elite = 5ui16,
			/*nicename("Jackal")*/ _actor_type_jackal = 6ui16,
			/*nicename("Grunt")*/ _actor_type_grunt = 7ui16,
			/*nicename("Brute")*/ _actor_type_brute = 8ui16,
			/*nicename("Hunter")*/ _actor_type_hunter = 9ui16,
			/*nicename("Prophet")*/ _actor_type_prophet = 10ui16,
			/*nicename("Bugger")*/ _actor_type_bugger = 11ui16,
			/*nicename("Scarab")*/ _actor_type_scarab = 12ui16,
			/*nicename("Engineer")*/ _actor_type_engineer = 13ui16,
			/*nicename("Skirmisher")*/ _actor_type_skirmisher = 14ui16,
			/*nicename("Mule")*/ _actor_type_mule = 15ui16,
			/*nicename("Mounted Weapon")*/ _actor_type_mounted_weapon = 16ui16,
		};

		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Swarm")*/ _flags_swarm = 1ui32 << 0ui32,
			/*nicename("Flying")*/ _flags_flying = 1ui32 << 1ui32,
			/*nicename("Dual Wields")*/ _flags_dual_wields = 1ui32 << 2ui32,
			/*nicename("Uses Gravemind")*/ _flags_uses_gravemind = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Cannot Swap Weapons With Player")*/ _flags_cannot_swap_weapons_with_player = 1ui32 << 5ui32,
			/*nicename("Does Not Initially Backpack")*/ _flags_does_not_initially_backpack = 1ui32 << 6ui32,
			/*nicename("Revive on Death")*/ _flags_revive_on_death = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Civilian")*/ _flags_civilian = 1ui32 << 14ui32,
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

		struct nicename("Weapons") s_weapons_definition_legacy
		{
			s_tag_reference_legacy nicename("Weapon") weapon_reference;
		};

		b_flags nicename("Flags") flags;
		e_actor_type nicename("Actor Type") actor_type;
		int16_t __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		float nicename("Scariness") scariness;
		int16_t __unknown4;
		int16_t __unknown5;
		s_tag_block_legacy<s_weapons_definition_legacy> nicename("Weapons") weapons_block;
	};

	struct nicename("Unknown 1") s_unknown_1_definition_legacy
	{
		struct nicename("Unknown 2") s_unknown_2_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
			s_undefined32_legacy __unknown2;
		};

		s_tag_block_legacy<s_unknown_2_definition_legacy> nicename("Unknown 2") unknown_2_block;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Vitality Properties") s_vitality_properties_definition_legacy
	{
		enum nicename("Vitality Flags") b_vitality_flags : uint32_t /* bitfield */
		{
			/*nicename("Can Revive On Death")*/ _vitality_flags_can_revive_on_death = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _vitality_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _vitality_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _vitality_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _vitality_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _vitality_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _vitality_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _vitality_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _vitality_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _vitality_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _vitality_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _vitality_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _vitality_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _vitality_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _vitality_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _vitality_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _vitality_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _vitality_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _vitality_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _vitality_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _vitality_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _vitality_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _vitality_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _vitality_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _vitality_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _vitality_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _vitality_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _vitality_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _vitality_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _vitality_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _vitality_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _vitality_flags_bit_31 = 1ui32 << 31ui32,
		};

		b_vitality_flags nicename("Vitality Flags") vitality_flags;
		float nicename("Normal Body Vitality") normal_body_vitality;
		float nicename("Normal Shield Vitality") normal_shield_vitality;
		float nicename("Legendary Body Vitality") legendary_body_vitality;
		float nicename("Legendary Shield Vitality") legendary_shield_vitality;
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
		float nicename("Extended Shield Damage Threshold") extended_shield_damage_threshold;
		float nicename("Extended Body Damage Threshold") extended_body_damage_threshold;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_tag_reference_legacy nicename("Backup Weapon") backup_weapon_reference;
		s_undefined32_legacy __unknown13;
	};

	struct nicename("Placement Properties") s_placement_properties_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		float nicename("Few Upgrade Chance Easy") few_upgrade_chance_easy;
		float nicename("Few Upgrade Chance Normal") few_upgrade_chance_normal;
		float nicename("Few Upgrade Chance Heroic") few_upgrade_chance_heroic;
		float nicename("Few Upgrade Chance Legendary") few_upgrade_chance_legendary;
		float nicename("Normal Upgrade Chance Easy") normal_upgrade_chance_easy;
		float nicename("Normal Upgrade Chance Normal") normal_upgrade_chance_normal;
		float nicename("Normal Upgrade Chance Heroic") normal_upgrade_chance_heroic;
		float nicename("Normal Upgrade Chance Legendary") normal_upgrade_chance_legendary;
		float nicename("Many Upgrade Chance Easy") many_upgrade_chance_easy;
		float nicename("Many Upgrade Chance Normal") many_upgrade_chance_normal;
		float nicename("Many Upgrade Chance Heroic") many_upgrade_chance_heroic;
		float nicename("Many Upgrade Chance Legendary") many_upgrade_chance_legendary;
	};

	struct nicename("Perception Properties") s_perception_properties_definition_legacy
	{
		int16_t __unknown0;
		int16_t __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		float nicename("Central Vision Angle") central_vision_angle;
		float nicename("Max Vision Angle") max_vision_angle;
		float nicename("Peripheral Vision Angle") peripheral_vision_angle;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_data_reference_legacy __unknown21;
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
	};

	struct nicename("Unknown 5") s_unknown_5_definition_legacy
	{
		s_undefined32_legacy __unknown0;
	};

	struct nicename("Look Properties") s_look_properties_definition_legacy
	{
		float nicename("Maximum Aiming Deviation y") maximum_aiming_deviation_y;
		float nicename("Maximum Aiming Deviation p") maximum_aiming_deviation_p;
		float nicename("Maximum Looking Deviation y") maximum_looking_deviation_y;
		float nicename("Maximum Looking Deviation p") maximum_looking_deviation_p;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		float nicename("Noncombat Look Delta L") noncombat_look_delta_l;
		float nicename("Noncombat Look Delta R") noncombat_look_delta_r;
		float nicename("Combat Look Delta L") combat_look_delta_l;
		float nicename("Combat Look Delta R") combat_look_delta_r;
		float nicename("Noncombat Idle Looking min") noncombat_idle_looking_min;
		float nicename("Noncombat Idle Looking max") noncombat_idle_looking_max;
		float nicename("Noncombat Idle Aiming min") noncombat_idle_aiming_min;
		float nicename("Noncombat Idle Aiming max") noncombat_idle_aiming_max;
		float nicename("Combat Idle Looking min") combat_idle_looking_min;
		float nicename("Combat Idle Looking max") combat_idle_looking_max;
		float nicename("Combat Idle Aiming min") combat_idle_aiming_min;
		float nicename("Combat Idle Aiming max") combat_idle_aiming_max;
	};

	struct nicename("Movement Properties") s_movement_properties_definition_legacy
	{
		enum nicename("Obstace Leap Minimum Size") e_obstace_leap_minimum_size : uint16_t
		{
			/*nicename("None")*/ _obstace_leap_minimum_size_none = 0ui16,
			/*nicename("Tiny")*/ _obstace_leap_minimum_size_tiny = 1ui16,
			/*nicename("Small")*/ _obstace_leap_minimum_size_small = 2ui16,
			/*nicename("Medium")*/ _obstace_leap_minimum_size_medium = 3ui16,
			/*nicename("Large")*/ _obstace_leap_minimum_size_large = 4ui16,
			/*nicename("Huge")*/ _obstace_leap_minimum_size_huge = 5ui16,
			/*nicename("Immobile")*/ _obstace_leap_minimum_size_immobile = 6ui16,
		};

		enum nicename("Obstace Leap Maximum Size") e_obstace_leap_maximum_size : uint16_t
		{
			/*nicename("None")*/ _obstace_leap_maximum_size_none = 0ui16,
			/*nicename("Tiny")*/ _obstace_leap_maximum_size_tiny = 1ui16,
			/*nicename("Small")*/ _obstace_leap_maximum_size_small = 2ui16,
			/*nicename("Medium")*/ _obstace_leap_maximum_size_medium = 3ui16,
			/*nicename("Large")*/ _obstace_leap_maximum_size_large = 4ui16,
			/*nicename("Huge")*/ _obstace_leap_maximum_size_huge = 5ui16,
			/*nicename("Immobile")*/ _obstace_leap_maximum_size_immobile = 6ui16,
		};

		enum nicename("Obstace Ignore Size") e_obstace_ignore_size : uint16_t
		{
			/*nicename("None")*/ _obstace_ignore_size_none = 0ui16,
			/*nicename("Tiny")*/ _obstace_ignore_size_tiny = 1ui16,
			/*nicename("Small")*/ _obstace_ignore_size_small = 2ui16,
			/*nicename("Medium")*/ _obstace_ignore_size_medium = 3ui16,
			/*nicename("Large")*/ _obstace_ignore_size_large = 4ui16,
			/*nicename("Huge")*/ _obstace_ignore_size_huge = 5ui16,
			/*nicename("Immobile")*/ _obstace_ignore_size_immobile = 6ui16,
		};

		enum nicename("Obstace Smashable Size") e_obstace_smashable_size : uint16_t
		{
			/*nicename("None")*/ _obstace_smashable_size_none = 0ui16,
			/*nicename("Tiny")*/ _obstace_smashable_size_tiny = 1ui16,
			/*nicename("Small")*/ _obstace_smashable_size_small = 2ui16,
			/*nicename("Medium")*/ _obstace_smashable_size_medium = 3ui16,
			/*nicename("Large")*/ _obstace_smashable_size_large = 4ui16,
			/*nicename("Huge")*/ _obstace_smashable_size_huge = 5ui16,
			/*nicename("Immobile")*/ _obstace_smashable_size_immobile = 6ui16,
		};

		enum nicename("Jump Height") e_jump_height : uint32_t
		{
			/*nicename("None")*/ _jump_height_none = 0ui32,
			/*nicename("Down")*/ _jump_height_down = 1ui32,
			/*nicename("Step")*/ _jump_height_step = 2ui32,
			/*nicename("Crouch")*/ _jump_height_crouch = 3ui32,
			/*nicename("Stand")*/ _jump_height_stand = 4ui32,
			/*nicename("Storey")*/ _jump_height_storey = 5ui32,
			/*nicename("Tower")*/ _jump_height_tower = 6ui32,
			/*nicename("Infinite")*/ _jump_height_infinite = 7ui32,
		};

		enum nicename("Movement Flags") b_movement_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _movement_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _movement_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Prefer To Combat Near Friends")*/ _movement_flags_prefer_to_combat_near_friends = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _movement_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _movement_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _movement_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _movement_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _movement_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _movement_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _movement_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _movement_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _movement_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _movement_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _movement_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _movement_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _movement_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _movement_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _movement_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _movement_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _movement_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _movement_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _movement_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _movement_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _movement_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _movement_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _movement_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _movement_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _movement_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _movement_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _movement_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _movement_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _movement_flags_bit_31 = 1ui32 << 31ui32,
		};

		enum nicename("Movement Hint Flags") b_movement_hint_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _movement_hint_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _movement_hint_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _movement_hint_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _movement_hint_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _movement_hint_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _movement_hint_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _movement_hint_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _movement_hint_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _movement_hint_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _movement_hint_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _movement_hint_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _movement_hint_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _movement_hint_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _movement_hint_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _movement_hint_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _movement_hint_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _movement_hint_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _movement_hint_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _movement_hint_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _movement_hint_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _movement_hint_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _movement_hint_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _movement_hint_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _movement_hint_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _movement_hint_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _movement_hint_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _movement_hint_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _movement_hint_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _movement_hint_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _movement_hint_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _movement_hint_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _movement_hint_flags_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Unknown 10") s_unknown_10_definition_legacy
		{
			float __unknown0;
			int32_t __unknown1;
		};

		struct nicename("Unknown 11") s_unknown_11_definition_legacy
		{
			struct nicename("Unknown 12") s_unknown_12_definition_legacy
			{
				s_undefined32_legacy __unknown0;
				s_undefined32_legacy __unknown1;
			};

			int16_t __unknown0;
			int16_t __unknown1;
			s_tag_block_legacy<s_unknown_12_definition_legacy> nicename("Unknown 12") unknown_12_block;
		};

		b_movement_flags nicename("Movement Flags") movement_flags;
		float nicename("Pathfinding Radius") pathfinding_radius;
		float nicename("Destination Radius") destination_radius;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		float nicename("Dive Grenade Chance") dive_grenade_chance;
		s_undefined32_legacy __unknown5;
		e_obstace_leap_minimum_size nicename("Obstace Leap Minimum Size") obstace_leap_minimum_size;
		e_obstace_leap_maximum_size nicename("Obstace Leap Maximum Size") obstace_leap_maximum_size;
		e_obstace_ignore_size nicename("Obstace Ignore Size") obstace_ignore_size;
		e_obstace_smashable_size nicename("Obstace Smashable Size") obstace_smashable_size;
		e_jump_height nicename("Jump Height") jump_height;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		b_movement_hint_flags nicename("Movement Hint Flags") movement_hint_flags;
		int32_t __unknown9;
		s_undefined32_legacy __unknown10;
		s_tag_block_legacy<s_unknown_10_definition_legacy> nicename("Unknown 10") unknown_10_block;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_tag_block_legacy<s_unknown_11_definition_legacy> nicename("Unknown 11") unknown_11_block;
		s_undefined32_legacy __unknown13;
		float __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		int32_t __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
		s_undefined32_legacy __unknown24;
		s_undefined32_legacy __unknown25;
		s_undefined32_legacy __unknown26;
	};

	struct nicename("Unknown 8") s_unknown_8_definition_legacy
	{
		string_id_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_data_reference_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_data_reference_legacy __unknown5;
		string_id_legacy __unknown6;
	};

	struct nicename("Unknown 9") s_unknown_9_definition_legacy
	{
		struct nicename("Unknown 10") s_unknown_101_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			string_id_legacy __unknown1;
			string_id_legacy __unknown2;
			string_id_legacy __unknown3;
			string_id_legacy __unknown4;
			string_id_legacy __unknown5;
			string_id_legacy __unknown6;
			string_id_legacy __unknown7;
			string_id_legacy __unknown8;
			string_id_legacy __unknown9;
			string_id_legacy __unknown10;
			string_id_legacy __unknown11;
			string_id_legacy __unknown12;
			string_id_legacy __unknown13;
			string_id_legacy __unknown14;
			string_id_legacy __unknown15;
		};

		string_id_legacy __unknown0;
		s_tag_block_legacy<s_unknown_101_definition_legacy> nicename("Unknown 10") unknown_10_block;
	};

	struct nicename("Unknown 10") s_unknown_102_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Unknown 11") s_unknown_111_definition_legacy
	{
		struct nicename("Unknown 12") s_unknown_121_definition_legacy
		{
			int32_t __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
		};

		int32_t __unknown0;
		s_tag_block_legacy<s_unknown_121_definition_legacy> nicename("Unknown 12") unknown_12_block;
	};

	struct nicename("Unknown 12") s_unknown_122_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Engage Properties") s_engage_properties_definition_legacy
	{
		enum nicename("Engage Flags") b_engage_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _engage_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _engage_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _engage_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _engage_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _engage_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _engage_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _engage_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _engage_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _engage_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _engage_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _engage_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _engage_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _engage_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _engage_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _engage_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _engage_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _engage_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _engage_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _engage_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _engage_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _engage_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _engage_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _engage_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _engage_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _engage_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _engage_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _engage_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _engage_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _engage_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _engage_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _engage_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _engage_flags_bit_31 = 1ui32 << 31ui32,
		};

		b_engage_flags nicename("Engage Flags") engage_flags;
		s_undefined32_legacy __unknown0;
		float nicename("Crouch Danger Threshold") crouch_danger_threshold;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
		s_undefined32_legacy __unknown6;
		s_tag_reference_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		float __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
	};

	struct nicename("Charge Properties") s_charge_properties_definition_legacy
	{
		enum nicename("Charge Flags") b_charge_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _charge_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _charge_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _charge_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _charge_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _charge_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _charge_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _charge_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _charge_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _charge_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _charge_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _charge_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _charge_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _charge_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _charge_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _charge_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _charge_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _charge_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _charge_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _charge_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _charge_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _charge_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _charge_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _charge_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _charge_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _charge_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _charge_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _charge_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _charge_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _charge_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _charge_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _charge_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _charge_flags_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Unknown 17") s_unknown_17_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t __unknown2;
		};

		b_charge_flags nicename("Charge Flags") charge_flags;
		float nicename("Melee Consider Range") melee_consider_range;
		float nicename("Melee Chance") melee_chance;
		float nicename("Melee Attack Range") melee_attack_range;
		float nicename("Melee Abort Range") melee_abort_range;
		float nicename("Melee Attack Timeout") melee_attack_timeout;
		float nicename("Melee Attack Delay Timer") melee_attack_delay_timer;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		float nicename("Ideal Leap Velocity") ideal_leap_velocity;
		float nicename("Max Leap Velocity") max_leap_velocity;
		float nicename("Melee Leap Ballistic") melee_leap_ballistic;
		float nicename("Melee Delay Timer") melee_delay_timer;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_tag_reference_legacy nicename("Berserk Weapon") berserk_weapon_reference;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_tag_block_legacy<s_unknown_17_definition_legacy> nicename("Unknown 17") unknown_17_block;
	};

	struct nicename("Evasion Properties") s_evasion_properties_definition_legacy
	{
		float nicename("Evasion Danger Threshold") evasion_danger_threshold;
		float nicename("Evasion Delay Timer") evasion_delay_timer;
		float nicename("Evasion Chance") evasion_chance;
		float nicename("Evasion Proximity Threshold") evasion_proximity_threshold;
		float nicename("Dive Retreat Chance") dive_retreat_chance;
	};

	struct nicename("Cover Properties") s_cover_properties_definition_legacy
	{
		enum nicename("Cover Flags") b_cover_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _cover_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _cover_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _cover_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _cover_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _cover_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _cover_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _cover_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _cover_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _cover_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _cover_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _cover_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _cover_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _cover_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _cover_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _cover_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _cover_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _cover_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _cover_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _cover_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _cover_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _cover_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _cover_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _cover_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _cover_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _cover_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _cover_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _cover_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _cover_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _cover_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _cover_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _cover_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _cover_flags_bit_31 = 1ui32 << 31ui32,
		};

		b_cover_flags nicename("Cover Flags") cover_flags;
		float nicename("Hide Behind Cover Time min") hide_behind_cover_time_min;
		float nicename("Hide Behind Cover Time max") hide_behind_cover_time_max;
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
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		float nicename("Scary Target Threshold") scary_target_threshold;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
	};

	struct nicename("Retreat Properties") s_retreat_properties_definition_legacy
	{
		enum nicename("Retreat Flags") b_retreat_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _retreat_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _retreat_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _retreat_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _retreat_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _retreat_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _retreat_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _retreat_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _retreat_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _retreat_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _retreat_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _retreat_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _retreat_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _retreat_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _retreat_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _retreat_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _retreat_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _retreat_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _retreat_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _retreat_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _retreat_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _retreat_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _retreat_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _retreat_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _retreat_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _retreat_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _retreat_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _retreat_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _retreat_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _retreat_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _retreat_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _retreat_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _retreat_flags_bit_31 = 1ui32 << 31ui32,
		};

		b_retreat_flags nicename("Retreat Flags") retreat_flags;
		float nicename("Shield Threshold") shield_threshold;
		float nicename("Scary Target Threshold") scary_target_threshold;
		float nicename("Danger Threshold") danger_threshold;
		float nicename("Proximity Threshold") proximity_threshold;
		float nicename("Forced Cower Time Bounds min") forced_cower_time_bounds_min;
		float nicename("Forced Cower Time Bounds max") forced_cower_time_bounds_max;
		float nicename("Cower Time Bounds min") cower_time_bounds_min;
		float nicename("Cower Time Bounds max") cower_time_bounds_max;
		float nicename("Proximity Ambush Threshold") proximity_ambush_threshold;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		float nicename("Zig-Zag Angle") zig_zag_angle;
		float nicename("Zig-Zag Period") zig_zag_period;
		float nicename("Retreat Grenade Chance") retreat_grenade_chance;
		s_tag_reference_legacy nicename("Backup Weapon") backup_weapon_reference;
	};

	struct nicename("Search Properties") s_search_properties_definition_legacy
	{
		enum nicename("Search Flags") b_search_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _search_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _search_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _search_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _search_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _search_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _search_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _search_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _search_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _search_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _search_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _search_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _search_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _search_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _search_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _search_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _search_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _search_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _search_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _search_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _search_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _search_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _search_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _search_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _search_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _search_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _search_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _search_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _search_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _search_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _search_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _search_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _search_flags_bit_31 = 1ui32 << 31ui32,
		};

		b_search_flags nicename("Search Flags") search_flags;
		float nicename("Search Time min") search_time_min;
		float nicename("Search Time max") search_time_max;
		s_undefined32_legacy __unknown0;
		float nicename("Uncover Distance Bounds min") uncover_distance_bounds_min;
		float nicename("Uncover Distance Bounds max") uncover_distance_bounds_max;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Pre-Search Properties") s_pre_search_properties_definition_legacy
	{
		enum nicename("Pre-Search Flags") b_pre_search_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _pre_search_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _pre_search_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _pre_search_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _pre_search_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _pre_search_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _pre_search_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _pre_search_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _pre_search_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _pre_search_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _pre_search_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _pre_search_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _pre_search_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _pre_search_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _pre_search_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _pre_search_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _pre_search_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _pre_search_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _pre_search_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _pre_search_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _pre_search_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _pre_search_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _pre_search_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _pre_search_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _pre_search_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _pre_search_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _pre_search_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _pre_search_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _pre_search_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _pre_search_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _pre_search_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _pre_search_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _pre_search_flags_bit_31 = 1ui32 << 31ui32,
		};

		b_pre_search_flags nicename("Pre-Search Flags") pre_search_flags;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
	};

	struct nicename("Idle Properties") s_idle_properties_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		float nicename("Idle Pose Delay Time min") idle_pose_delay_time_min;
		float nicename("Idle Pose Delay Time max") idle_pose_delay_time_max;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
	};

	struct nicename("Vocalization Properties") s_vocalization_properties_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		float nicename("Look Comment Time") look_comment_time;
		float nicename("Look Long Comment Time") look_long_comment_time;
	};

	struct nicename("Boarding Properties") s_boarding_properties_definition_legacy
	{
		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Airborne Boarding")*/ _flags_airborne_boarding = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
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

		struct nicename("Boarding Vehicles") s_boarding_vehicles_definition_legacy
		{
			s_tag_reference_legacy nicename("Vehicle") vehicle_reference;
			int32_t __unknown0;
		};

		b_flags nicename("Flags") flags;
		float nicename("Max Distance") max_distance;
		float nicename("Abort Distance") abort_distance;
		float nicename("Max Speed") max_speed;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_tag_block_legacy<s_boarding_vehicles_definition_legacy> nicename("Boarding Vehicles") boarding_vehicles_block;
	};

	struct nicename("Unknown 23") s_unknown_23_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Unknown 24") s_unknown_24_definition_legacy
	{
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
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
	};

	struct nicename("Engineer Properties") s_engineer_properties_definition_legacy
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float nicename("Shield Amount") shield_amount;
		s_undefined32_legacy __unknown5;
		float __unknown6;
		float __unknown7;
		s_undefined32_legacy __unknown8;
		s_tag_reference_legacy __unknown9;
	};

	struct nicename("Unknown 28") s_unknown_28_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
	};

	struct nicename("Weapons Properties") s_weapons_properties_definition_legacy
	{
		enum nicename("Special Fire Mode") e_special_fire_mode : uint16_t
		{
			/*nicename("None")*/ _special_fire_mode_none = 0ui16,
			/*nicename("Overcharge")*/ _special_fire_mode_overcharge = 1ui16,
			/*nicename("Secondary Trigger")*/ _special_fire_mode_secondary_trigger = 2ui16,
		};

		enum nicename("Special Fire Situation") e_special_fire_situation : uint16_t
		{
			/*nicename("Never")*/ _special_fire_situation_never = 0ui16,
			/*nicename("Enemy Visible")*/ _special_fire_situation_enemy_visible = 1ui16,
			/*nicename("Enemy Out of Sight")*/ _special_fire_situation_enemy_out_of_sight = 2ui16,
			/*nicename("Strafing")*/ _special_fire_situation_strafing = 3ui16,
		};

		enum nicename("Weapon Flags") b_weapon_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _weapon_flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Must Crouch To Shoot")*/ _weapon_flags_must_crouch_to_shoot = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _weapon_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _weapon_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _weapon_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _weapon_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _weapon_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _weapon_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _weapon_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _weapon_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _weapon_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _weapon_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _weapon_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _weapon_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _weapon_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _weapon_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _weapon_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _weapon_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _weapon_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _weapon_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _weapon_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _weapon_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _weapon_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _weapon_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _weapon_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _weapon_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _weapon_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _weapon_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _weapon_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _weapon_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _weapon_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _weapon_flags_bit_31 = 1ui32 << 31ui32,
		};

		b_weapon_flags nicename("Weapon Flags") weapon_flags;
		s_tag_reference_legacy nicename("Weapon") weapon_reference;
		float nicename("Maximum Firing Range") maximum_firing_range;
		float nicename("Minimum Firing Range") minimum_firing_range;
		float nicename("Normal Combat Range min") normal_combat_range_min;
		float nicename("Normal Combat Range max") normal_combat_range_max;
		float nicename("Bombardment Range") bombardment_range;
		float nicename("Max Special Target Distance") max_special_target_distance;
		float nicename("Super Ballistic Range") super_ballistic_range;
		float nicename("Ballistic Firing Bounds min") ballistic_firing_bounds_min;
		float nicename("Ballistic Firing Bounds max") ballistic_firing_bounds_max;
		float nicename("Ballistic Fraction Bounds min") ballistic_fraction_bounds_min;
		float nicename("Ballistic Fraction Bounds max") ballistic_fraction_bounds_max;
		float nicename("First Burst Delay Time min") first_burst_delay_time_min;
		float nicename("First Burst Delay Time max") first_burst_delay_time_max;
		float nicename("Surprise Delay Time") surprise_delay_time;
		float nicename("Surprise Fire Wildly Time") surprise_fire_wildly_time;
		float nicename("Death Fire Wildly Chance") death_fire_wildly_chance;
		float nicename("Death Fire Wildly Time") death_fire_wildly_time;
		float nicename("Custom Stand Gun Offset i") custom_stand_gun_offset_i;
		float nicename("Custom Stand Gun Offset j") custom_stand_gun_offset_j;
		float nicename("Custom Stand Gun Offset k") custom_stand_gun_offset_k;
		float nicename("Custom Crouch Gun Offset i") custom_crouch_gun_offset_i;
		float nicename("Custom Crouch Gun Offset j") custom_crouch_gun_offset_j;
		float nicename("Custom Crouch Gun Offset k") custom_crouch_gun_offset_k;
		e_special_fire_mode nicename("Special Fire Mode") special_fire_mode;
		e_special_fire_situation nicename("Special Fire Situation") special_fire_situation;
		float nicename("Special Fire Chance") special_fire_chance;
		float nicename("Special Fire Delay") special_fire_delay;
		float nicename("Special Damage Modifier") special_damage_modifier;
		float nicename("Special Projectile Error") special_projectile_error;
		float nicename("Drop Weapon Loaded min") drop_weapon_loaded_min;
		float nicename("Drop Weapon Loaded max") drop_weapon_loaded_max;
		int16_t nicename("Drop Weapon Ammo min") drop_weapon_ammo_min;
		int16_t nicename("Drop Weapon Ammo max") drop_weapon_ammo_max;
		float nicename("Normal Accuracy Bounds min") normal_accuracy_bounds_min;
		float nicename("Normal Accuracy Bounds max") normal_accuracy_bounds_max;
		float nicename("Normal Accuracy Time") normal_accuracy_time;
		float nicename("Heroic Accuracy Bounds min") heroic_accuracy_bounds_min;
		float nicename("Heroic Accuracy Bounds max") heroic_accuracy_bounds_max;
		float nicename("Heroic Accuracy Time") heroic_accuracy_time;
		float nicename("Legendary Accuracy Bounds min") legendary_accuracy_bounds_min;
		float nicename("Legendary Accuracy Bounds max") legendary_accuracy_bounds_max;
		float nicename("Legendary Accuracy Time") legendary_accuracy_time;
		s_tag_reference_legacy nicename("Weapon Melee Damage") weapon_melee_damage_reference;
	};

	struct nicename("Firing Pattern Properties") s_firing_pattern_properties_definition_legacy
	{
		struct nicename("Firing Patterns") s_firing_patterns_definition_legacy
		{
			float nicename("Rate Of Fire") rate_of_fire;
			float nicename("Target Tracking") target_tracking;
			float nicename("Target Leading") target_leading;
			float nicename("Burst Origin Radius") burst_origin_radius;
			float nicename("Burst Origin Angle") burst_origin_angle;
			float nicename("Burst Return Length min") burst_return_length_min;
			float nicename("Burst Return Length max") burst_return_length_max;
			float nicename("Burst Return Angle") burst_return_angle;
			float nicename("Burst Duration min") burst_duration_min;
			float nicename("Burst Duration max") burst_duration_max;
			float nicename("Burst Separation min") burst_separation_min;
			float nicename("Burst Separation max") burst_separation_max;
			float nicename("Weapon Damage Modifier") weapon_damage_modifier;
			float nicename("Projectile Error") projectile_error;
			float nicename("Burst Angular Velocity") burst_angular_velocity;
			float nicename("Maximum Error Angle") maximum_error_angle;
		};

		s_tag_reference_legacy nicename("Weapon") weapon_reference;
		s_tag_block_legacy<s_firing_patterns_definition_legacy> nicename("Firing Patterns") firing_patterns_block;
	};

	struct nicename("Grenade Properties") s_grenade_properties_definition_legacy
	{
		enum nicename("Grenade Type") e_grenade_type : uint16_t
		{
			/*nicename("Frag")*/ _grenade_type_frag = 0ui16,
			/*nicename("Plasma")*/ _grenade_type_plasma = 1ui16,
		};

		enum nicename("Trajectory Type") e_trajectory_type : uint16_t
		{
			/*nicename("Toss")*/ _trajectory_type_toss = 0ui16,
			/*nicename("Lob")*/ _trajectory_type_lob = 1ui16,
			/*nicename("Bounce")*/ _trajectory_type_bounce = 2ui16,
		};

		int32_t nicename("Grenades Flags") grenades_flags;
		e_grenade_type nicename("Grenade Type") grenade_type;
		e_trajectory_type nicename("Trajectory Type") trajectory_type;
		int32_t nicename("Minimum Enemy Count") minimum_enemy_count;
		float nicename("Enemy Radius") enemy_radius;
		float nicename("Grenade Ideal Velocity") grenade_ideal_velocity;
		float nicename("Grenade Velocity") grenade_velocity;
		float nicename("Grenade Range min") grenade_range_min;
		float nicename("Grenade Range max") grenade_range_max;
		float nicename("Collateral Damage Radius") collateral_damage_radius;
		float nicename("Grenade Chance") grenade_chance;
		float nicename("Grenade Throw Delay") grenade_throw_delay;
		float nicename("Grenade Uncover Chance") grenade_uncover_chance;
		float nicename("Anti-Vehicle Grenade Chance") anti_vehicle_grenade_chance;
		int16_t nicename("Dropped Grenade Count min") dropped_grenade_count_min;
		int16_t nicename("Dropped Grenade Count max") dropped_grenade_count_max;
		float nicename("Don't Drop Grenades Chance") dont_drop_grenades_chance;
	};

	struct nicename("Vehicle Properties") s_vehicle_properties_definition_legacy
	{
		enum nicename("Obstacle Ignore Size") e_obstacle_ignore_size : uint16_t
		{
			/*nicename("None")*/ _obstacle_ignore_size_none = 0ui16,
			/*nicename("Tiny")*/ _obstacle_ignore_size_tiny = 1ui16,
			/*nicename("Small")*/ _obstacle_ignore_size_small = 2ui16,
			/*nicename("Medium")*/ _obstacle_ignore_size_medium = 3ui16,
			/*nicename("Large")*/ _obstacle_ignore_size_large = 4ui16,
			/*nicename("Huge")*/ _obstacle_ignore_size_huge = 5ui16,
			/*nicename("Immobile")*/ _obstacle_ignore_size_immobile = 6ui16,
		};

		enum nicename("Vehicle Flags") b_vehicle_flags : uint32_t /* bitfield */
		{
			/*nicename("Passengers Adopt Original Squad")*/ _vehicle_flags_passengers_adopt_original_squad = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _vehicle_flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _vehicle_flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _vehicle_flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _vehicle_flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _vehicle_flags_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _vehicle_flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _vehicle_flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _vehicle_flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _vehicle_flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _vehicle_flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _vehicle_flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _vehicle_flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _vehicle_flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _vehicle_flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _vehicle_flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _vehicle_flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _vehicle_flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _vehicle_flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _vehicle_flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _vehicle_flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _vehicle_flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _vehicle_flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _vehicle_flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _vehicle_flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _vehicle_flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _vehicle_flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _vehicle_flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _vehicle_flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _vehicle_flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _vehicle_flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _vehicle_flags_bit_31 = 1ui32 << 31ui32,
		};

		s_tag_reference_legacy nicename("Unit") unit_reference;
		s_tag_reference_legacy nicename("Style") style_reference;
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		b_vehicle_flags nicename("Vehicle Flags") vehicle_flags;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		float nicename("AI Pathfinding Radius") ai_pathfinding_radius;
		float nicename("AI Destination Radius") ai_destination_radius;
		float nicename("AI Deceleration Distance") ai_deceleration_distance;
		float nicename("AI Turning Radius") ai_turning_radius;
		float nicename("AI Inner Turning Radius") ai_inner_turning_radius;
		float nicename("AI Ideal Turning Radius") ai_ideal_turning_radius;
		float nicename("AI Banshee Steering Maximum") ai_banshee_steering_maximum;
		float nicename("AI Max Steering Angle") ai_max_steering_angle;
		float nicename("AI Max Steering Delta") ai_max_steering_delta;
		float nicename("AI Oversteering Scale") ai_oversteering_scale;
		float nicename("AI Oversteering Bounds min") ai_oversteering_bounds_min;
		float nicename("AI Oversteering Bounds max") ai_oversteering_bounds_max;
		float nicename("AI Side Slip Distance") ai_side_slip_distance;
		float nicename("AI Avoidance Distance") ai_avoidance_distance;
		float nicename("AI Minimum Urgency") ai_minimum_urgency;
		float __unknown21;
		s_undefined32_legacy __unknown22;
		float nicename("AI Throttle Maximum") ai_throttle_maximum;
		s_undefined32_legacy __unknown23;
		float nicename("AI Goal Minimum Throttle Scale") ai_goal_minimum_throttle_scale;
		float nicename("AI Turn Minimum Throttle Scale") ai_turn_minimum_throttle_scale;
		float nicename("AI Direction Minimum Throttle Scale") ai_direction_minimum_throttle_scale;
		s_undefined32_legacy __unknown24;
		float __unknown25;
		float nicename("AI Acceleration Scale") ai_acceleration_scale;
		float nicename("AI Throttle Blend") ai_throttle_blend;
		float nicename("Theoretical Max Speed") theoretical_max_speed;
		float nicename("Error Scale") error_scale;
		float nicename("AI Allowable Aim Deviation Angle") ai_allowable_aim_deviation_angle;
		float nicename("AI Charge Tight Angle Distance") ai_charge_tight_angle_distance;
		float nicename("AI Charge Tight Angle") ai_charge_tight_angle;
		float nicename("AI Charge Repeat Timeout") ai_charge_repeat_timeout;
		float nicename("AI Charge Look-Ahead Time") ai_charge_look_ahead_time;
		float nicename("AI Consider Distance") ai_consider_distance;
		float nicename("AI Charge Abort Distance") ai_charge_abort_distance;
		s_undefined32_legacy __unknown26;
		float nicename("Vehicle Ram Timeout") vehicle_ram_timeout;
		float nicename("Ram Paralysis Time") ram_paralysis_time;
		s_undefined32_legacy __unknown27;
		s_undefined32_legacy __unknown28;
		float nicename("AI Cover Minimum Distance") ai_cover_minimum_distance;
		float nicename("AI Cover Time") ai_cover_time;
		float nicename("AI Cover Minimum Boost Distance") ai_cover_minimum_boost_distance;
		float nicename("Turtling Recent Damage Threshold") turtling_recent_damage_threshold;
		float nicename("Turtling Minimum Time") turtling_minimum_time;
		float nicename("Turtling Timeout") turtling_timeout;
		e_obstacle_ignore_size nicename("Obstacle Ignore Size") obstacle_ignore_size;
		int16_t __unknown29;
		int16_t __unknown30;
		int16_t __unknown31;
	};

	struct nicename("Unknown 29") s_unknown_29_definition_legacy
	{
		s_tag_reference_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
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
		float __unknown37;
		float __unknown38;
		s_undefined32_legacy __unknown39;
		s_undefined32_legacy __unknown40;
		s_undefined32_legacy __unknown41;
		float __unknown42;
		s_undefined32_legacy __unknown43;
		s_undefined32_legacy __unknown44;
		s_undefined32_legacy __unknown45;
		s_undefined32_legacy __unknown46;
		s_undefined32_legacy __unknown47;
		float __unknown48;
		float __unknown49;
		float __unknown50;
		s_undefined32_legacy __unknown51;
		s_undefined32_legacy __unknown52;
	};

	struct nicename("Equipment Properties") s_equipment_properties_definition_legacy
	{
		struct nicename("Usage Conditions") s_usage_conditions_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
			float __unknown2;
			float __unknown3;
		};

		s_tag_reference_legacy nicename("Equipment") equipment_reference;
		int32_t __unknown0;
		float nicename("Usage Chance") usage_chance;
		s_tag_block_legacy<s_usage_conditions_definition_legacy> nicename("Usage Conditions") usage_conditions_block;
	};

	struct nicename("Stimuli") s_stimuli_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Stimuli Character") stimuli_character_reference;
	};

	struct nicename("Metagame Properties") s_metagame_properties_definition_legacy
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

		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Must Have Active Seats")*/ _flags_must_have_active_seats = 1ui8 << 0ui8,
		};

		b_flags nicename("Flags") flags;
		e_unit nicename("Unit") unit;
		e_classification nicename("Classification") classification;
		int8_t __unknown0;
		int16_t nicename("Points") points;
		int16_t __unknown1;
	};

	struct nicename("Unknown 37") s_unknown_37_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		float __unknown3;
		float __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
	};

	b_character_flags nicename("Character Flags") character_flags;
	s_tag_reference_legacy nicename("Parent Character") parent_character_reference;
	s_tag_reference_legacy nicename("Unit") unit_reference;
	s_tag_reference_legacy nicename("Creature") creature_reference;
	s_tag_reference_legacy nicename("Style") style_reference;
	s_tag_reference_legacy nicename("Major Character") major_character_reference;
	s_tag_block_legacy<s_variants_definition_legacy> nicename("Variants") variants_block;
	s_tag_block_legacy<s_unit_dialogue_definition_legacy> nicename("Unit Dialogue") unit_dialogue_block;
	s_tag_block_legacy<s_general_properties_definition_legacy> nicename("General Properties") general_properties_block;
	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	s_tag_block_legacy<s_unknown_1_definition_legacy> nicename("Unknown 1") unknown_1_block;
	s_tag_block_legacy<s_vitality_properties_definition_legacy> nicename("Vitality Properties") vitality_properties_block;
	s_tag_block_legacy<s_placement_properties_definition_legacy> nicename("Placement Properties") placement_properties_block;
	s_tag_block_legacy<s_perception_properties_definition_legacy> nicename("Perception Properties") perception_properties_block;
	s_tag_block_legacy<s_unknown_5_definition_legacy> nicename("Unknown 5") unknown_5_block;
	s_tag_block_legacy<s_look_properties_definition_legacy> nicename("Look Properties") look_properties_block;
	s_tag_block_legacy<s_movement_properties_definition_legacy> nicename("Movement Properties") movement_properties_block;
	s_tag_block_legacy<s_unknown_8_definition_legacy> nicename("Unknown 8") unknown_8_block;
	s_tag_block_legacy<s_unknown_9_definition_legacy> nicename("Unknown 9") unknown_9_block;
	s_tag_block_legacy<s_unknown_102_definition_legacy> nicename("Unknown 10") unknown_10_block;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	s_undefined32_legacy __unknown5;
	s_tag_block_legacy<s_unknown_111_definition_legacy> nicename("Unknown 11") unknown_11_block;
	s_tag_block_legacy<s_unknown_122_definition_legacy> nicename("Unknown 12") unknown_12_block;
	s_tag_block_legacy<s_engage_properties_definition_legacy> nicename("Engage Properties") engage_properties_block;
	s_tag_block_legacy<s_charge_properties_definition_legacy> nicename("Charge Properties") charge_properties_block;
	s_tag_block_legacy<s_evasion_properties_definition_legacy> nicename("Evasion Properties") evasion_properties_block;
	s_tag_block_legacy<s_cover_properties_definition_legacy> nicename("Cover Properties") cover_properties_block;
	s_tag_block_legacy<s_retreat_properties_definition_legacy> nicename("Retreat Properties") retreat_properties_block;
	s_tag_block_legacy<s_search_properties_definition_legacy> nicename("Search Properties") search_properties_block;
	s_tag_block_legacy<s_pre_search_properties_definition_legacy> nicename("Pre-Search Properties") pre_search_properties_block;
	s_tag_block_legacy<s_idle_properties_definition_legacy> nicename("Idle Properties") idle_properties_block;
	s_tag_block_legacy<s_vocalization_properties_definition_legacy> nicename("Vocalization Properties") vocalization_properties_block;
	s_tag_block_legacy<s_boarding_properties_definition_legacy> nicename("Boarding Properties") boarding_properties_block;
	s_tag_block_legacy<s_unknown_23_definition_legacy> nicename("Unknown 23") unknown_23_block;
	s_tag_block_legacy<s_unknown_24_definition_legacy> nicename("Unknown 24") unknown_24_block;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	s_undefined32_legacy __unknown8;
	s_undefined32_legacy __unknown9;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	s_tag_block_legacy<s_engineer_properties_definition_legacy> nicename("Engineer Properties") engineer_properties_block;
	s_tag_block_legacy<s_unknown_28_definition_legacy> nicename("Unknown 28") unknown_28_block;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_tag_block_legacy<s_weapons_properties_definition_legacy> nicename("Weapons Properties") weapons_properties_block;
	s_tag_block_legacy<s_firing_pattern_properties_definition_legacy> nicename("Firing Pattern Properties") firing_pattern_properties_block;
	s_tag_block_legacy<s_grenade_properties_definition_legacy> nicename("Grenade Properties") grenade_properties_block;
	s_tag_block_legacy<s_vehicle_properties_definition_legacy> nicename("Vehicle Properties") vehicle_properties_block;
	s_tag_block_legacy<s_unknown_29_definition_legacy> nicename("Unknown 29") unknown_29_block;
	s_undefined32_legacy __unknown15;
	s_undefined32_legacy __unknown16;
	s_undefined32_legacy __unknown17;
	s_tag_block_legacy<s_equipment_properties_definition_legacy> nicename("Equipment Properties") equipment_properties_block;
	s_tag_block_legacy<s_stimuli_definition_legacy> nicename("Stimuli") stimuli_block;
	s_tag_block_legacy<s_metagame_properties_definition_legacy> nicename("Metagame Properties") metagame_properties_block;
	s_undefined32_legacy __unknown18;
	s_undefined32_legacy __unknown19;
	s_undefined32_legacy __unknown20;
	s_tag_block_legacy<s_unknown_37_definition_legacy> nicename("Unknown 37") unknown_37_block;
};

