#pragma once

struct nicename("player_model_customization_globals") tag_group('pmcg') s_player_model_customization_globals_definition_legacy
{
	struct nicename("Helmet") s_helmet_definition_legacy
	{
		struct nicename("Configuration") s_configuration_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Left Shoulder") s_left_shoulder_definition_legacy
	{
		struct nicename("Configuration") s_configuration1_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration1_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Right Shoulder") s_right_shoulder_definition_legacy
	{
		struct nicename("Configuration") s_configuration2_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration2_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Chest") s_chest_definition_legacy
	{
		struct nicename("Configuration") s_configuration3_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration3_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Wrist") s_wrist_definition_legacy
	{
		struct nicename("Configuration") s_configuration4_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration4_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Leg Utility") s_leg_utility_definition_legacy
	{
		struct nicename("Configuration") s_configuration5_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration5_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Knees") s_knees_definition_legacy
	{
		struct nicename("Configuration") s_configuration6_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration6_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Elite Armor") s_elite_armor_definition_legacy
	{
		struct nicename("Configuration") s_configuration7_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration7_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Armor Effects Dupe") s_armor_effects_dupe_definition_legacy
	{
		struct nicename("Configuration") s_configuration8_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration8_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Armor Effects") s_armor_effects_definition_legacy
	{
		struct nicename("Configuration") s_configuration9_definition_legacy
		{
			enum nicename("Flags") b_flags : uint8_t /* bitfield */
			{
				/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
				/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
				/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
			};

			string_id_legacy nicename("Region") region;
			string_id_legacy nicename("Permutation") permutation;
			b_flags nicename("Flags") flags;
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_configuration9_definition_legacy> nicename("Configuration") configuration_block;
	};

	struct nicename("Male Base") s_male_base_definition_legacy
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id_legacy nicename("Region") region;
		string_id_legacy nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Female Base") s_female_base_definition_legacy
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id_legacy nicename("Region") region;
		string_id_legacy nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Spartan Base") s_spartan_base_definition_legacy
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id_legacy nicename("Region") region;
		string_id_legacy nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Elite Base") s_elite_base_definition_legacy
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Male Specific")*/ _flags_male_specific = 1ui8 << 0ui8,
			/*nicename("Female Specific")*/ _flags_female_specific = 1ui8 << 1ui8,
			/*nicename("Move Elite Mandibles For Helmet")*/ _flags_move_elite_mandibles_for_helmet = 1ui8 << 2ui8,
		};

		string_id_legacy nicename("Region") region;
		string_id_legacy nicename("Permutation") permutation;
		b_flags nicename("Flags") flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	s_tag_reference_legacy nicename("Unused Spartan Model") unused_spartan_model_reference;
	s_tag_reference_legacy nicename("Unused Elite Model") unused_elite_model_reference;
	s_tag_block_legacy<s_helmet_definition_legacy> nicename("Helmet") helmet_block;
	s_tag_block_legacy<s_left_shoulder_definition_legacy> nicename("Left Shoulder") left_shoulder_block;
	s_tag_block_legacy<s_right_shoulder_definition_legacy> nicename("Right Shoulder") right_shoulder_block;
	s_tag_block_legacy<s_chest_definition_legacy> nicename("Chest") chest_block;
	s_tag_block_legacy<s_wrist_definition_legacy> nicename("Wrist") wrist_block;
	s_tag_block_legacy<s_leg_utility_definition_legacy> nicename("Leg Utility") leg_utility_block;
	s_tag_block_legacy<s_knees_definition_legacy> nicename("Knees") knees_block;
	s_tag_block_legacy<s_elite_armor_definition_legacy> nicename("Elite Armor") elite_armor_block;
	s_tag_block_legacy<s_armor_effects_dupe_definition_legacy> nicename("Armor Effects Dupe") armor_effects_dupe_block;
	s_tag_block_legacy<s_armor_effects_definition_legacy> nicename("Armor Effects") armor_effects_block;
	s_tag_block_legacy<s_male_base_definition_legacy> nicename("Male Base") male_base_block;
	s_tag_block_legacy<s_female_base_definition_legacy> nicename("Female Base") female_base_block;
	s_tag_block_legacy<s_spartan_base_definition_legacy> nicename("Spartan Base") spartan_base_block;
	s_tag_block_legacy<s_elite_base_definition_legacy> nicename("Elite Base") elite_base_block;
};

