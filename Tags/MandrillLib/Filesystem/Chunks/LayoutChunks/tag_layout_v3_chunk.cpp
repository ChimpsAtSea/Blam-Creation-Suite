#include "mandrilllib-private-pch.h"

c_tag_layout_v3_chunk::c_tag_layout_v3_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;

	parse_children(nullptr);
}

c_tag_layout_v3_chunk::~c_tag_layout_v3_chunk()
{
}
