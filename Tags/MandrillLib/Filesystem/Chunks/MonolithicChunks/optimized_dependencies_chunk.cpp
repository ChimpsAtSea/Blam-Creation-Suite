#include "mandrilllib-private-pch.h"

c_optimized_dependencies_chunk::c_optimized_dependencies_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;
}
