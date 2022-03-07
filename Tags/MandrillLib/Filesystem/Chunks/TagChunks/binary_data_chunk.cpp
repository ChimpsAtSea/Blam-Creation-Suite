#include "mandrilllib-private-pch.h"

c_binary_data_chunk::c_binary_data_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	debug_point;

	log_pad();
	log_signature();
	console_end_line_verbose();
}
