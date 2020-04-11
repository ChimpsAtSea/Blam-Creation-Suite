#pragma once

struct nicename("dialogue") tag_group('udlg') s_dialogue_definition
{
	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Female")*/ _flags_female = 1ui32 << 0ui32,
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

	struct nicename("Vocalizations") s_vocalizations_definition
	{
		struct nicename("Sound") s_sound_definition
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_tag_reference_legacy nicename("Sound") sound_reference;
		};

		string_id_legacy nicename("Vocalization") vocalization;
		s_tag_block_legacy<s_sound_definition> nicename("Sound") sound_block;
	};

	s_tag_reference_legacy nicename("Global Dialogue Info") global_dialogue_info_reference;
	b_flags nicename("Flags") flags;
	s_tag_block_legacy<s_vocalizations_definition> nicename("Vocalizations") vocalizations_block;
	string_id_legacy nicename("Mission Dialogue Designator") mission_dialogue_designator;
};

