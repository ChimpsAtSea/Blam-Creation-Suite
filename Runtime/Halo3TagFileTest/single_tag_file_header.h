#pragma once

struct s_single_tag_file_header
{
	unsigned long unknown0;
	unsigned long unknown4;
	unsigned long unknown8;
	unsigned long unknownC;
	unsigned long unknown10;
	unsigned long unknown14;
	unsigned long unknown18;
	unsigned long unknown1C;

	unsigned long unknown20;
	unsigned long unknown24; // 1
	unsigned long unknown28; // 1
	unsigned long unknown2C; // ULONG_MAX

	tag group_tag;
	unsigned long group_version; // 2
	unsigned long crc32; // hash?
	unsigned long blam; // 'BLAM'
};
