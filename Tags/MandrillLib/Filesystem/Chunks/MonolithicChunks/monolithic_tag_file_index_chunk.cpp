#include "mandrilllib-private-pch.h"

c_monolithic_tag_file_index_chunk::c_monolithic_tag_file_index_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;

	parse_children(nullptr);
}
