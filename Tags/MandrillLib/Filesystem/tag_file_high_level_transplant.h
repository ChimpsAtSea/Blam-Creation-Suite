#pragma once

struct s_tag_file_header;
class c_high_level_tag_file_reader;
class c_chunk;
class c_tag_group_layout_chunk;
class c_binary_data_chunk;

class c_tag_file_high_level_transplant
{
public:
	void* tag_file_data;
	uint64_t tag_file_data_size;

	c_high_level_tag_file_reader* high_level_tag_file_reader;

	s_engine_platform_build engine_platform_build;

	BCS_SHARED c_tag_file_high_level_transplant(const char* filepath, s_engine_platform_build engine_platform_build);
	BCS_SHARED ~c_tag_file_high_level_transplant();
	BCS_SHARED BCS_RESULT parse_tag(h_prototype*& prototype, blofeld::s_tag_group const*& blofeld_tag_group);
};

