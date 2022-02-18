#include "mandrilllib-private-pch.h"

c_tag_header_chunk::c_tag_header_chunk(const void* chunk_data) :
	c_typed_chunk(chunk_data, nullptr)
{
	debug_point;

	log_pad();
	log_signature();
	console_end_line_verbose();
}
