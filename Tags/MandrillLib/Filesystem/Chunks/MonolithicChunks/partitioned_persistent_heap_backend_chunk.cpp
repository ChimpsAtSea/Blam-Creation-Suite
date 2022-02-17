#include "mandrilllib-private-pch.h"

c_partitioned_persistent_heap_backend_chunk::c_partitioned_persistent_heap_backend_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;

	parse_children(nullptr);
}
