#include "tagfileserialization-private-pch.h"

c_tag_data_chunk::c_tag_data_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	data_length(),
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
	
	read_data();

	return rs;
}

void c_tag_data_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("size:0x%08lX", data_length);
}

BCS_RESULT c_tag_data_chunk::set_data(const void* data, uint32_t data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = c_chunk::set_data(data, data_size)))
	{
		return rs;
	}

	is_big_endian = false;
	read_data();

	return rs;
}

void c_tag_data_chunk::read_data()
{
	if (data)
	{
		delete[] data;
	}

	const char* src_data_ptr = get_chunk_data_start();

	data_length = chunk_size;
	data = new() char[data_length];
	memcpy(data, src_data_ptr, data_length);
	
}
