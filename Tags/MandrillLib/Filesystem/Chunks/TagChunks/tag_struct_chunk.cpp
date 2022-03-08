#include "mandrilllib-private-pch.h"

c_tag_struct_chunk::c_tag_struct_chunk(c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(parent, reader)
{
	REFERENCE_ASSERT(reader);

	debug_point;

	log_pad();
	log_signature();
	console_end_line_verbose();
}

void c_tag_struct_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("metadata:0x%08lu chunk_size:0x%08lu", metadata, chunk_size);
}
