#include "mandrilllib-private-pch.h"

c_tag_reference_chunk::c_tag_reference_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	group_tag(blofeld::INVALID_TAG),
	tag_filepath_without_extension()
{
}

c_tag_reference_chunk::~c_tag_reference_chunk()
{
	delete[] tag_filepath_without_extension;
}

BCS_RESULT c_tag_reference_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const char* chunk_data_start = get_chunk_data_start();
	intptr_t data_length = chunk_size;
	if (data_length >= 4)
	{
		intptr_t string_length = data_length - 4;
		group_tag = chunk_byteswap(*reinterpret_cast<const tag*>(chunk_data_start));
		tag_filepath_without_extension = new() char[string_length + 1];
		memcpy(tag_filepath_without_extension, chunk_data_start + sizeof(tag), string_length);
		tag_filepath_without_extension[string_length] = 0;
	}
	

	return rs;
}

void c_tag_reference_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("'%s'", tag_filepath_without_extension);
}
