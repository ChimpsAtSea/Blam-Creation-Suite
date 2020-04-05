#pragma once

struct nicename("player_model_customization_globals") tag_group('pmcg') s_player_model_customization_globals_definition
{
	struct nicename("Helmet") s_helmet_definition
	{
		struct nicename("Configuration") s_configuration_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Left Shoulder") s_left_shoulder_definition
	{
		struct nicename("Configuration") s_configuration1_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration1_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Right Shoulder") s_right_shoulder_definition
	{
		struct nicename("Configuration") s_configuration2_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration2_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Chest") s_chest_definition
	{
		struct nicename("Configuration") s_configuration3_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration3_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Wrist") s_wrist_definition
	{
		struct nicename("Configuration") s_configuration4_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration4_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Leg Utility") s_leg_utility_definition
	{
		struct nicename("Configuration") s_configuration5_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration5_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Knees") s_knees_definition
	{
		struct nicename("Configuration") s_configuration6_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration6_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Elite Armor") s_elite_armor_definition
	{
		struct nicename("Configuration") s_configuration7_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration7_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Armor Effects Dupe") s_armor_effects_dupe_definition
	{
		struct nicename("Configuration") s_configuration8_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration8_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Armor Effects") s_armor_effects_definition
	{
		struct nicename("Configuration") s_configuration9_definition
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id nicename("Region") region;
			string_id nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id nicename("Name") name;
		s_tag_block_definition<s_configuration9_definition> nicename("Configuration") configuration_block;
	};

	struct nicename("Male Base") s_male_base_definition
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id nicename("Region") region;
		string_id nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Female Base") s_female_base_definition
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id nicename("Region") region;
		string_id nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Spartan Base") s_spartan_base_definition
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id nicename("Region") region;
		string_id nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Elite Base") s_elite_base_definition
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id nicename("Region") region;
		string_id nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	TagReference nicename("Unused Spartan Model") unused_spartan_model_reference;
	TagReference nicename("Unused Elite Model") unused_elite_model_reference;
	s_tag_block_definition<s_helmet_definition> nicename("Helmet") helmet_block;
	s_tag_block_definition<s_left_shoulder_definition> nicename("Left Shoulder") left_shoulder_block;
	s_tag_block_definition<s_right_shoulder_definition> nicename("Right Shoulder") right_shoulder_block;
	s_tag_block_definition<s_chest_definition> nicename("Chest") chest_block;
	s_tag_block_definition<s_wrist_definition> nicename("Wrist") wrist_block;
	s_tag_block_definition<s_leg_utility_definition> nicename("Leg Utility") leg_utility_block;
	s_tag_block_definition<s_knees_definition> nicename("Knees") knees_block;
	s_tag_block_definition<s_elite_armor_definition> nicename("Elite Armor") elite_armor_block;
	s_tag_block_definition<s_armor_effects_dupe_definition> nicename("Armor Effects Dupe") armor_effects_dupe_block;
	s_tag_block_definition<s_armor_effects_definition> nicename("Armor Effects") armor_effects_block;
	s_tag_block_definition<s_male_base_definition> nicename("Male Base") male_base_block;
	s_tag_block_definition<s_female_base_definition> nicename("Female Base") female_base_block;
	s_tag_block_definition<s_spartan_base_definition> nicename("Spartan Base") spartan_base_block;
	s_tag_block_definition<s_elite_base_definition> nicename("Elite Base") elite_base_block;
};

