#include "mandrilllib-private-pch.h"

c_tag_heap_chunk::c_tag_heap_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	debug_point;
}
