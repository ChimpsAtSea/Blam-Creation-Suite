#include "mandrilllib-private-pch.h"

c_tag_dependency_chunk::c_tag_dependency_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;

	parse_children(nullptr);
}
