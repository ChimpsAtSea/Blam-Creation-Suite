#include "mandrilllib-private-pch.h"

c_tag_string_id_chunk::c_tag_string_id_chunk(const void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(chunk_data, parent, reader),
	string()
{
	intptr_t string_length = chunk_data_end - chunk_data_begin;
	char* string_bufer = new char[string_length + 1];
	memcpy(string_bufer, chunk_data_begin, string_length);
	string_bufer[string_length] = 0;

	string = string_bufer;

	debug_point;

	log_pad();
	log_signature();
	console_write_line_verbose("'%s'", string);
}

c_tag_string_id_chunk::~c_tag_string_id_chunk()
{
	delete[] string;
}

void c_tag_string_id_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("'%s'", string);
}
