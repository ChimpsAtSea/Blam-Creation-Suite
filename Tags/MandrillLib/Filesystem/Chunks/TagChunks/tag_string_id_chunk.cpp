#include "mandrilllib-private-pch.h"

c_tag_string_id_chunk::c_tag_string_id_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(chunk_data, parent, reader),
	string()
{
	intptr_t string_length = chunk_data_end - chunk_data_begin;
	string = new char[string_length + 1];
	memcpy(string, chunk_data_begin, string_length);
	string[string_length] = 0;

	debug_point;

	log_pad();
	log_signature();
	console_write_line_verbose("'%s'", string);
}

c_tag_string_id_chunk::~c_tag_string_id_chunk()
{
	delete[] string;
}

void c_tag_string_id_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line_verbose("'%s'", string);
}
