#include "mandrilllib-private-pch.h"

c_tag_data_chunk::c_tag_data_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(chunk_data, parent, reader),
	data()
{
	data_length = static_cast<unsigned long>(chunk_data_end - chunk_data_begin);
	data = new char[data_length];
	memcpy(data, chunk_data_begin, data_length);
	debug_point;

	log_pad();
	log_signature();
	console_write_line_verbose("size:0x%08lX", data_length);
}

c_tag_data_chunk::~c_tag_data_chunk()
{
	delete[] data;
}

void c_tag_data_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("size:0x%08lX", data_length);
}
