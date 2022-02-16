#include "mandrilllib-private-pch.h"

c_tag_struct_chunk::c_tag_struct_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(chunk_data, parent, reader)
{
	REFERENCE_ASSERT(reader);

	debug_point;

	parse_children(&reader);

	log_pad();
	log_signature();
	console_end_line_verbose();
}

void c_tag_struct_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("metadata:0x%08lu chunk_size:0x%08lu", metadata, chunk_size);
}
