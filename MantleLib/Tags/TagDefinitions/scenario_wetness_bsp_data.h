#pragma once

struct nicename("scenario_wetness_bsp_data") group('wetn') s_scenario_wetness_bsp_data_definition
{
	struct nicename("Unknown 0") s_unknown_0_definition
	{
		int32_t __unknown0;
	};

	struct nicename("Unknown 1") s_unknown_1_definition
	{
		uint8_t __unknown0;
	};

	struct nicename("Unknown 2") s_unknown_2_definition
	{
		int32_t __unknown0;
	};

	struct nicename("Unknown 3") s_unknown_3_definition
	{
		int32_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
	};

	Undefined32 __unknown0;
	int32_t nicename("Structure Checksum 1") structure_checksum_1;
	int32_t nicename("Structure Checksum 2") structure_checksum_2;
	Undefined32 __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	Undefined32 __unknown4;
	TagReference nicename("Primary Map") primary_map_reference;
	s_tag_block_definition<s_unknown_0_definition> nicename("Unknown 0") unknown_0_block;
	s_tag_block_definition<s_unknown_1_definition> nicename("Unknown 1") unknown_1_block;
	s_tag_block_definition<s_unknown_2_definition> nicename("Unknown 2") unknown_2_block;
	s_tag_block_definition<s_unknown_3_definition> nicename("Unknown 3") unknown_3_block;
};

