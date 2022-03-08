#include "mandrilllib-private-pch.h"

c_tag_data_chunk::c_tag_data_chunk(c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(parent, reader),
	data()
{

}

c_tag_data_chunk::~c_tag_data_chunk()
{
	delete[] data;
}

BCS_RESULT c_tag_data_chunk::read_chunk(void* userdata, const void* _data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, _data, use_read_only, parse_children)))
	{
		return rs;
	}
	
	const char* src_data_ptr = get_chunk_data_start();

	data_length = chunk_size;
	data = new() char[data_length];
	memcpy(data, src_data_ptr, data_length);
	debug_point;

	log_pad();
	log_signature();
	console_write_line_verbose("size:0x%08lX", data_length);

	return rs;
}

void c_tag_data_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("size:0x%08lX", data_length);
}
