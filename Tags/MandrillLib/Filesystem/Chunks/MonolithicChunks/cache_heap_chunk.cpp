#include "mandrilllib-private-pch.h"

c_cache_heap_chunk::c_cache_heap_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	debug_point;
}
