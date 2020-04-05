#pragma once

struct nicename("cookie_purchase_globals") tag_group('cpgd') s_cookie_purchase_globals_definition
{
	struct nicename("Helmet Families") s_helmet_families_definition
	{
		struct nicename("Family Members") s_family_members_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Left Shoulder Families") s_left_shoulder_families_definition
	{
		struct nicename("Family Members") s_family_members1_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members1_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Right Shoulder Families") s_right_shoulder_families_definition
	{
		struct nicename("Family Members") s_family_members2_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members2_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Chest Families") s_chest_families_definition
	{
		struct nicename("Family Members") s_family_members3_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members3_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Wrist Families") s_wrist_families_definition
	{
		struct nicename("Family Members") s_family_members4_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members4_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Leg Utility Families") s_leg_utility_families_definition
	{
		struct nicename("Family Members") s_family_members5_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members5_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Visor Color Families") s_visor_color_families_definition
	{
		struct nicename("Family Members") s_family_members6_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members6_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Knee Guard Families") s_knee_guard_families_definition
	{
		struct nicename("Family Members") s_family_members7_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members7_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Armor Effect Families") s_armor_effect_families_definition
	{
		struct nicename("Family Members") s_family_members8_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members8_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Elite Armor Families") s_elite_armor_families_definition
	{
		struct nicename("Family Members") s_family_members9_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members9_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Camo Pattern Families") s_camo_pattern_families_definition
	{
		struct nicename("Family Members") s_family_members10_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members10_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Paint Scheme Families") s_paint_scheme_families_definition
	{
		struct nicename("Family Members") s_family_members11_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members11_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Firefight Voice Families") s_firefight_voice_families_definition
	{
		struct nicename("Family Members") s_family_members12_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		string_id nicename("Name") name;
		string_id nicename("Description") description;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon Index") icon_index;
		s_tag_block_definition<s_family_members12_definition> nicename("Family Members") family_members_block;
	};

	struct nicename("Entry Table") s_entry_table_definition
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Automatically Purchase When Available")*/ _flags_automatically_purchase_when_available = 1ui8 << 0ui8,
			/*nicename("Default")*/ _flags_default = 1ui8 << 1ui8,
			/*nicename("Special")*/ _flags_special = 1ui8 << 2ui8,
			/*nicename("Unlockable")*/ _flags_unlockable = 1ui8 << 3ui8,
			/*nicename("BNet Sink")*/ _flags_bnet_sink = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
		};

		struct nicename("Armor Piece Info") s_armor_piece_info_definition
		{
			enum nicename("Armor Type") e_armor_type : uint8_t
			{
				/*nicename("Helmet")*/ _armor_type_helmet = 1ui8,
				/*nicename("Left Shoulder")*/ _armor_type_left_shoulder = 2ui8,
				/*nicename("Right Shoulder")*/ _armor_type_right_shoulder = 3ui8,
				/*nicename("Chest")*/ _armor_type_chest = 4ui8,
				/*nicename("Wrist")*/ _armor_type_wrist = 5ui8,
				/*nicename("Leg Utility")*/ _armor_type_leg_utility = 6ui8,
				/*nicename("Knee Guards")*/ _armor_type_knee_guards = 7ui8,
				/*nicename("Elite Armor")*/ _armor_type_elite_armor = 8ui8,
			};

			e_armor_type nicename("Armor Type") armor_type;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			string_id nicename("Name") name;
		};

		struct nicename("Armor Effect Info") s_armor_effect_info_definition
		{
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			string_id nicename("Name") name;
		};

		struct nicename("Visor Color Info") s_visor_color_info_definition
		{
			string_id nicename("Name") name;
		};

		struct nicename("Unknown/Unused") s_unknown_unused_definition
		{
			string_id nicename("Name") name;
		};

		struct nicename("FF Voice Info") s_ff_voice_info_definition
		{
			string_id nicename("Name") name;
		};

		struct nicename("Viewable At Rank...") s_viewable_at_rank_definition
		{
			enum nicename("Rank") e_rank : uint8_t
			{
				/*nicename("Recruit")*/ _rank_recruit = 1ui8,
				/*nicename("Corporal")*/ _rank_corporal = 2ui8,
				/*nicename("Sergeant")*/ _rank_sergeant = 3ui8,
				/*nicename("Warrant Officer")*/ _rank_warrant_officer = 4ui8,
				/*nicename("Captain")*/ _rank_captain = 5ui8,
				/*nicename("Major")*/ _rank_major = 6ui8,
				/*nicename("Lt. Colonel")*/ _rank_lt_colonel = 7ui8,
				/*nicename("Commander")*/ _rank_commander = 8ui8,
				/*nicename("Colonel")*/ _rank_colonel = 9ui8,
				/*nicename("Brigadier")*/ _rank_brigadier = 10ui8,
				/*nicename("General")*/ _rank_general = 11ui8,
				/*nicename("Field Marshall")*/ _rank_field_marshall = 12ui8,
				/*nicename("Hero")*/ _rank_hero = 13ui8,
				/*nicename("Legend")*/ _rank_legend = 14ui8,
				/*nicename("Mythic")*/ _rank_mythic = 15ui8,
				/*nicename("Noble")*/ _rank_noble = 16ui8,
				/*nicename("Eclipse")*/ _rank_eclipse = 17ui8,
				/*nicename("Nova")*/ _rank_nova = 18ui8,
				/*nicename("Forerunner")*/ _rank_forerunner = 19ui8,
				/*nicename("Reclaimer")*/ _rank_reclaimer = 20ui8,
				/*nicename("Inheritor")*/ _rank_inheritor = 21ui8,
			};

			e_rank nicename("Rank") rank;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		struct nicename("Viewable After... Is Purchased") s_viewable_after_is_purchased_definition
		{
			int16_t nicename("Required Entry") required_entry;
			int16_t __unknown0;
		};

		struct nicename("DLC View Lock") s_dlc_view_lock_definition
		{
			string_id nicename("Name") name;
		};

		struct nicename("Purchasable At Rank...") s_purchasable_at_rank_definition
		{
			enum nicename("Rank") e_rank : uint8_t
			{
				/*nicename("Recruit")*/ _rank_recruit = 1ui8,
				/*nicename("Corporal")*/ _rank_corporal = 2ui8,
				/*nicename("Sergeant")*/ _rank_sergeant = 3ui8,
				/*nicename("Warrant Officer")*/ _rank_warrant_officer = 4ui8,
				/*nicename("Captain")*/ _rank_captain = 5ui8,
				/*nicename("Major")*/ _rank_major = 6ui8,
				/*nicename("Lt. Colonel")*/ _rank_lt_colonel = 7ui8,
				/*nicename("Commander")*/ _rank_commander = 8ui8,
				/*nicename("Colonel")*/ _rank_colonel = 9ui8,
				/*nicename("Brigadier")*/ _rank_brigadier = 10ui8,
				/*nicename("General")*/ _rank_general = 11ui8,
				/*nicename("Field Marshall")*/ _rank_field_marshall = 12ui8,
				/*nicename("Hero")*/ _rank_hero = 13ui8,
				/*nicename("Legend")*/ _rank_legend = 14ui8,
				/*nicename("Mythic")*/ _rank_mythic = 15ui8,
				/*nicename("Noble")*/ _rank_noble = 16ui8,
				/*nicename("Eclipse")*/ _rank_eclipse = 17ui8,
				/*nicename("Nova")*/ _rank_nova = 18ui8,
				/*nicename("Forerunner")*/ _rank_forerunner = 19ui8,
				/*nicename("Reclaimer")*/ _rank_reclaimer = 20ui8,
				/*nicename("Inheritor")*/ _rank_inheritor = 21ui8,
			};

			e_rank nicename("Rank") rank;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		struct nicename("Purchasable After... Is Purchased") s_purchasable_after_is_purchased_definition
		{
			int16_t nicename("Required Entry") required_entry;
			int16_t __unknown0;
		};

		struct nicename("DLC Purchase Lock") s_dlc_purchase_lock_definition
		{
			string_id nicename("Name") name;
		};

		string_id nicename("Entry Name") entry_name;
		string_id nicename("Game Name") game_name;
		string_id nicename("Description") description;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		TagReference nicename("Icon Bitmap") icon_bitmap_reference;
		int32_t nicename("Icon") icon;
		int32_t nicename("Price") price;
		s_tag_block_definition<s_armor_piece_info_definition> nicename("Armor Piece Info") armor_piece_info_block;
		s_tag_block_definition<s_armor_effect_info_definition> nicename("Armor Effect Info") armor_effect_info_block;
		s_tag_block_definition<s_visor_color_info_definition> nicename("Visor Color Info") visor_color_info_block;
		s_tag_block_definition<s_unknown_unused_definition> nicename("Unknown/Unused") unknown_unused_block;
		s_tag_block_definition<s_ff_voice_info_definition> nicename("FF Voice Info") ff_voice_info_block;
		s_tag_block_definition<s_viewable_at_rank_definition> nicename("Viewable At Rank...") viewable_at_rank_block;
		s_tag_block_definition<s_viewable_after_is_purchased_definition> nicename("Viewable After... Is Purchased") viewable_after_is_purchased_block;
		string_id nicename("Requirement View Description") requirement_view_description;
		s_tag_block_definition<s_dlc_view_lock_definition> nicename("DLC View Lock") dlc_view_lock_block;
		string_id nicename("DLC View Description") dlc_view_description;
		s_tag_block_definition<s_purchasable_at_rank_definition> nicename("Purchasable At Rank...") purchasable_at_rank_block;
		s_tag_block_definition<s_purchasable_after_is_purchased_definition> nicename("Purchasable After... Is Purchased") purchasable_after_is_purchased_block;
		string_id nicename("Requirement Purchase Description") requirement_purchase_description;
		s_tag_block_definition<s_dlc_purchase_lock_definition> nicename("DLC Purchase Lock") dlc_purchase_lock_block;
		string_id nicename("DLC Purchase Description") dlc_purchase_description;
	};

	struct nicename("DLC Unlocks") s_dlc_unlocks_definition
	{
		struct nicename("Entry") s_entry_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		s_tag_block_definition<s_entry_definition> nicename("Entry") entry_block;
	};

	struct nicename("Waypoint Unlocks") s_waypoint_unlocks_definition
	{
		struct nicename("Entry") s_entry1_definition
		{
			int16_t nicename("Entry Index") entry_index;
			int16_t __unknown0;
		};

		s_tag_block_definition<s_entry1_definition> nicename("Entry") entry_block;
	};

	s_tag_block_definition<s_helmet_families_definition> nicename("Helmet Families") helmet_families_block;
	s_tag_block_definition<s_left_shoulder_families_definition> nicename("Left Shoulder Families") left_shoulder_families_block;
	s_tag_block_definition<s_right_shoulder_families_definition> nicename("Right Shoulder Families") right_shoulder_families_block;
	s_tag_block_definition<s_chest_families_definition> nicename("Chest Families") chest_families_block;
	s_tag_block_definition<s_wrist_families_definition> nicename("Wrist Families") wrist_families_block;
	s_tag_block_definition<s_leg_utility_families_definition> nicename("Leg Utility Families") leg_utility_families_block;
	s_tag_block_definition<s_visor_color_families_definition> nicename("Visor Color Families") visor_color_families_block;
	s_tag_block_definition<s_knee_guard_families_definition> nicename("Knee Guard Families") knee_guard_families_block;
	s_tag_block_definition<s_armor_effect_families_definition> nicename("Armor Effect Families") armor_effect_families_block;
	s_tag_block_definition<s_elite_armor_families_definition> nicename("Elite Armor Families") elite_armor_families_block;
	s_tag_block_definition<s_camo_pattern_families_definition> nicename("Camo Pattern Families") camo_pattern_families_block;
	s_tag_block_definition<s_paint_scheme_families_definition> nicename("Paint Scheme Families") paint_scheme_families_block;
	s_tag_block_definition<s_firefight_voice_families_definition> nicename("Firefight Voice Families") firefight_voice_families_block;
	s_tag_block_definition<s_entry_table_definition> nicename("Entry Table") entry_table_block;
	s_tag_block_definition<s_dlc_unlocks_definition> nicename("DLC Unlocks") dlc_unlocks_block;
	s_tag_block_definition<s_waypoint_unlocks_definition> nicename("Waypoint Unlocks") waypoint_unlocks_block;
};

