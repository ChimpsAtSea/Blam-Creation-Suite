#pragma once
class c_high_level_tag_file_writer
{
public:
	BCS_DEBUG_API c_high_level_tag_file_writer(const char* filepath, h_tag& tag);
	BCS_DEBUG_API ~c_high_level_tag_file_writer();

	h_tag& tag;
	const char* filepath;
};
