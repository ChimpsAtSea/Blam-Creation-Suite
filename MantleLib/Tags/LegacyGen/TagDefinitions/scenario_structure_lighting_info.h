#pragma once

struct nicename("scenario_structure_lighting_info") tag_group('stli') s_scenario_structure_lighting_info_definition
{
	struct nicename("Unknown 0") s_unknown_0_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		float __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		Undefined32 __unknown16;
		Undefined32 __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
	};

	struct nicename("Unknown 1") s_unknown_1_definition
	{
		int32_t __unknown0;
		int32_t __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		float __unknown9;
		float __unknown10;
		int32_t __unknown11;
		float __unknown12;
		Undefined32 __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		TagReference __unknown17;
		TagReference __unknown18;
		TagReference __unknown19;
		TagReference __unknown20;
	};

	struct nicename("Unknown 2") s_unknown_2_definition
	{
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		int32_t __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
	};

	struct nicename("Unknown 3") s_unknown_3_definition
	{
		DEPRECATED_string_id __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		Undefined32 __unknown5;
	};

	int32_t nicename("Checksum?") checksum;
	s_tag_block_definition<s_unknown_0_definition> nicename("Unknown 0") unknown_0_block;
	s_tag_block_definition<s_unknown_1_definition> nicename("Unknown 1") unknown_1_block;
	Undefined32 __unknown0;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	Undefined32 __unknown5;
	s_tag_block_definition<s_unknown_2_definition> nicename("Unknown 2") unknown_2_block;
	s_tag_block_definition<s_unknown_3_definition> nicename("Unknown 3") unknown_3_block;
};

