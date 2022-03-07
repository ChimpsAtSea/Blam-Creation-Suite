#include "mandrilllib-private-pch.h"

c_tag_header_chunk::c_tag_header_chunk() :
	c_typed_chunk(nullptr)
{
	debug_point;

	log_pad();
	log_signature();
	console_end_line_verbose();
}
