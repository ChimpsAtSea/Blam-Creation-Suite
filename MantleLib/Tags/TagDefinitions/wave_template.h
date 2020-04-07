#pragma once

struct nicename("wave_template") tag_group('wave') s_wave_template_definition
{
	struct nicename("Wave Template") s_wave_template1_definition
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

		TagReference nicename("Squad Template") squad_template_reference;
		b_difficulty nicename("Difficulty") difficulty;
		int16_t __unknown0;
		int16_t nicename("Minimum Round") minimum_round;
		int16_t nicename("Maximum Round") maximum_round;
		int16_t __unknown1;
		int16_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		int8_t __unknown6;
		int32_t __unknown7;
	};

	s_tag_block_definition<s_wave_template1_definition> nicename("Wave Template") wave_template_block;
};

