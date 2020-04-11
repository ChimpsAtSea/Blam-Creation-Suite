#pragma once

struct nicename("scenario_structure_lighting_info") tag_group('stli') s_scenario_structure_lighting_info_definition_legacy
{
	struct nicename("Unknown 0") s_unknown_0_definition_legacy
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
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
	};

	struct nicename("Unknown 1") s_unknown_1_definition_legacy
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
		s_undefined32_legacy __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		s_tag_reference_legacy __unknown17;
		s_tag_reference_legacy __unknown18;
		s_tag_reference_legacy __unknown19;
		s_tag_reference_legacy __unknown20;
	};

	struct nicename("Unknown 2") s_unknown_2_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		int32_t __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
	};

	struct nicename("Unknown 3") s_unknown_3_definition_legacy
	{
		string_id_legacy __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		s_undefined32_legacy __unknown5;
	};

	int32_t nicename("Checksum?") checksum;
	s_tag_block_legacy<s_unknown_0_definition_legacy> nicename("Unknown 0") unknown_0_block;
	s_tag_block_legacy<s_unknown_1_definition_legacy> nicename("Unknown 1") unknown_1_block;
	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	s_undefined32_legacy __unknown5;
	s_tag_block_legacy<s_unknown_2_definition_legacy> nicename("Unknown 2") unknown_2_block;
	s_tag_block_legacy<s_unknown_3_definition_legacy> nicename("Unknown 3") unknown_3_block;
};

