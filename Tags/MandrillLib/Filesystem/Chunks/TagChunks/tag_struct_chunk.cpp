#include "mandrilllib-private-pch.h"

c_tag_struct_chunk::c_tag_struct_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	
}

void c_tag_struct_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("metadata:0x%08lu chunk_size:0x%08lu", metadata, chunk_size);
}
