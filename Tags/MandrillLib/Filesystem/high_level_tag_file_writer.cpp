#include "mandrilllib-private-pch.h"

static constexpr size_t y = sizeof(s_engine_platform_build);

c_high_level_tag_file_writer::c_high_level_tag_file_writer(const char* _filepath, h_tag& tag) :
	filepath(strdup(_filepath)),
	tag(tag)
{
	const char* helloworld = tag.tag_filename;
	filesystem_write_file_from_memory("tag_file_writer_test.bitmap", helloworld, strlen(helloworld));

	s_single_tag_file_header tag_file_header;

	tag_file_header.unknown0 = 0;
	tag_file_header.unknown4 = 0;
	tag_file_header.unknown8 = 0;
	tag_file_header.unknownC = 0;
	tag_file_header.unknown10 = 0;
	tag_file_header.unknown14 = 0;
	tag_file_header.unknown18 = 0;
	tag_file_header.unknown1C = 0;
	tag_file_header.unknown20 = 0;
	tag_file_header.unknown24 = 1;
	tag_file_header.unknown28 = 1;
	tag_file_header.unknown2C = ULONG_MAX;
	tag_file_header.group_tag = tag.group->tag_group.group_tag;
	//tag_file_header.group_version = tag.group->tag_group.version;
	tag_file_header.group_version = 7; // #TODO: How to handle this? This has been written specifically for the Bitmap group
	tag_file_header.crc32 = 0; // #TODO: Calculate this just before writing the data
	tag_file_header.blam = 'BLAM';


	c_tag_header_chunk* header_chunk = new c_tag_header_chunk();



		debug_point;
}

c_high_level_tag_file_writer::~c_high_level_tag_file_writer()
{
	untracked_free(filepath);
}
