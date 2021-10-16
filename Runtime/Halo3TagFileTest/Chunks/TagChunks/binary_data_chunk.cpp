#include "halo3tagfiletest-private-pch.h"

c_binary_data_chunk::c_binary_data_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;

	log_pad();
	log_signature();
	console_end_line_verbose();
}
