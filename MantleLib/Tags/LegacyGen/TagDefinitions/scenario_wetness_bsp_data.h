#pragma once

struct nicename("scenario_wetness_bsp_data") tag_group('wetn') s_scenario_wetness_bsp_data_definition_legacy
{
	struct nicename("Unknown 0") s_unknown_0_definition_legacy
	{
		int32_t __unknown0;
	};

	struct nicename("Unknown 1") s_unknown_1_definition_legacy
	{
		uint8_t __unknown0;
	};

	struct nicename("Unknown 2") s_unknown_2_definition_legacy
	{
		int32_t __unknown0;
	};

	struct nicename("Unknown 3") s_unknown_3_definition_legacy
	{
		int32_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
	};

	s_undefined32_legacy __unknown0;
	int32_t nicename("Structure Checksum 1") structure_checksum_1;
	int32_t nicename("Structure Checksum 2") structure_checksum_2;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	s_tag_reference_legacy nicename("Primary Map") primary_map_reference;
	s_tag_block_legacy<s_unknown_0_definition_legacy> nicename("Unknown 0") unknown_0_block;
	s_tag_block_legacy<s_unknown_1_definition_legacy> nicename("Unknown 1") unknown_1_block;
	s_tag_block_legacy<s_unknown_2_definition_legacy> nicename("Unknown 2") unknown_2_block;
	s_tag_block_legacy<s_unknown_3_definition_legacy> nicename("Unknown 3") unknown_3_block;
};

