#include "mandrilllib-private-pch.h"

c_string_data_chunk::c_string_data_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;
}

void c_string_data_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line_verbose("size:%08X\n", chunk_size);
	unsigned long offset = 0;
	for (char* current_position = chunk_data_begin; current_position < chunk_data_end; current_position++)
	{
		intptr_t offset = current_position - chunk_data_begin;
		log_pad(); console_write_line_verbose("\t0x%zX\t%s", offset, current_position);
		current_position += strlen(current_position);
	}
}
