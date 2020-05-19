#pragma once

struct nicename("squad_template") tag_group('sqtm') s_squad_template_definition_legacy
{
	struct nicename("Squad") s_squad_definition_legacy
	{
		enum nicename("Difficulty") b_difficulty : uint16_t /* bitfield */
		{
			/*nicename("Easy")*/ _difficulty_easy = 1ui16 << 0ui16,
			/*nicename("Normal")*/ _difficulty_normal = 1ui16 << 1ui16,
			/*nicename("Heroic")*/ _difficulty_heroic = 1ui16 << 2ui16,
			/*nicename("Legendary")*/ _difficulty_legendary = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _difficulty_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _difficulty_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _difficulty_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _difficulty_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _difficulty_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _difficulty_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _difficulty_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _difficulty_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _difficulty_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _difficulty_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _difficulty_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _difficulty_bit_15 = 1ui16 << 15ui16,
		};

		struct nicename("Actors") s_actors_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t nicename("Minimum Round") minimum_round;
			int16_t nicename("Maximum Round") maximum_round;
			s_undefined32_legacy __unknown2;
			s_tag_reference_legacy nicename("Character") character_reference;
			int16_t nicename("Probability") probability;
			int16_t __unknown3;
		};

		struct nicename("Weapons") s_weapons_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t nicename("Minimum Round") minimum_round;
			int16_t nicename("Maximum Round") maximum_round;
			s_undefined32_legacy __unknown2;
			s_tag_reference_legacy nicename("Weapon") weapon_reference;
			int16_t nicename("Probability") probability;
			int16_t __unknown3;
		};

		struct nicename("Secondary Weapons") s_secondary_weapons_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t nicename("Minimum Round") minimum_round;
			int16_t nicename("Maximum Round") maximum_round;
			s_undefined32_legacy __unknown2;
			s_tag_reference_legacy nicename("Weapon") weapon_reference;
			int16_t nicename("Probability") probability;
			int16_t __unknown3;
		};

		struct nicename("Equipment") s_equipment_definition_legacy
		{
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t nicename("Minimum Round") minimum_round;
			int16_t nicename("Maximum Round") maximum_round;
			s_undefined32_legacy __unknown2;
			s_tag_reference_legacy nicename("Equipment") equipment_reference;
			int16_t nicename("Probability") probability;
			int16_t __unknown3;
		};

		string_id_legacy nicename("Name") name;
		b_difficulty nicename("Difficulty") difficulty;
		int16_t __unknown0;
		int16_t nicename("Minimum Round") minimum_round;
		int16_t nicename("Maximum Round") maximum_round;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t nicename("Count") count;
		int16_t __unknown3;
		s_tag_block_legacy<s_actors_definition_legacy> nicename("Actors") actors_block;
		s_tag_block_legacy<s_weapons_definition_legacy> nicename("Weapons") weapons_block;
		s_tag_block_legacy<s_secondary_weapons_definition_legacy> nicename("Secondary Weapons") secondary_weapons_block;
		s_tag_block_legacy<s_equipment_definition_legacy> nicename("Equipment") equipment_block;
		s_undefined32_legacy __unknown4;
		s_tag_reference_legacy nicename("Vehicle") vehicle_reference;
		string_id_legacy nicename("Vehicle Variant") vehicle_variant;
		s_undefined32_legacy __unknown5;
	};

	string_id_legacy nicename("Name") name;
	s_tag_block_legacy<s_squad_definition_legacy> nicename("Squad") squad_block;
};

