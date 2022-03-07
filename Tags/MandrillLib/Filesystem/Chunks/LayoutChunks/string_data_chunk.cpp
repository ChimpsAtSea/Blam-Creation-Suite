#include "mandrilllib-private-pch.h"

c_string_data_chunk::c_string_data_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	debug_point;
}

void c_string_data_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("size:%08X", chunk_size);
	unsigned long offset = 0;
	const char* chunk_data_start = get_chunk_data_start();
	const char* chunk_data_end = get_chunk_data_end();
	for (const char* current_position = chunk_data_start; current_position < chunk_data_end; current_position++)
	{
		intptr_t offset = current_position - chunk_data_start;
		log_pad(); console_write_line_verbose("\t0x%zX\t%s", offset, current_position);
		current_position += strlen(current_position);
	}
}
