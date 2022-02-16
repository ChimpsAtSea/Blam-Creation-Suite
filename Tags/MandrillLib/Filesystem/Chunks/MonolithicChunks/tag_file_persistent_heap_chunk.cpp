#include "mandrilllib-private-pch.h"

c_tag_file_persistent_heap_chunk::c_tag_file_persistent_heap_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;

	parse_children(nullptr);
}
