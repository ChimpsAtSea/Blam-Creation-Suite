#pragma once

struct s_tag_file_header
{
	uint32_t unknown0;
	uint32_t unknown4;
	uint32_t unknown8;
	uint32_t unknownC;
	uint32_t unknown10;
	uint32_t unknown14;
	uint32_t unknown18;
	uint32_t unknown1C;

	uint32_t unknown20;
	uint32_t unknown24; // 1
	uint32_t unknown28; // 1
	uint32_t unknown2C; // ULONG_MAX

	tag group_tag;
	uint32_t group_version; // 2
	uint32_t crc32; // hash?
	uint32_t blam; // 'BLAM'
};
