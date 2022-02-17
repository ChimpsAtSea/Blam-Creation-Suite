#include "mandrilllib-private-pch.h"

c_cache_heap_chunk::c_cache_heap_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;
	
	parse_children(nullptr);
}
