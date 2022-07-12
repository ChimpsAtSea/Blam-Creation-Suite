#include "blamtoozle-private-pch.h"

c_blamtoozle_file_stream::c_blamtoozle_file_stream(c_blamtoozle_source_generator& _source_generator, const wchar_t* _file_path) :
	source_generator(_source_generator),
	file_path(wcsdup(_file_path)),
	stream()
{
}

c_blamtoozle_file_stream::~c_blamtoozle_file_stream()
{
	untracked_free(file_path);
}

void c_blamtoozle_file_stream::write()
{
	std::string stream_string = stream.str();

	BCS_RESULT rs = filesystem_write_file_from_memory(file_path, stream_string.c_str(), stream_string.size(), _filesystem_write_mode_check_for_changes);
	ASSERT(BCS_SUCCEEDED(rs));
	if (rs != BCS_S_NO_CHANGES_MADE)
	{
		console_write_line("Updated %S", file_path);
	}
}
