#include "mandrilllib-private-pch.h"

c_tag_group_layout_chunk::c_tag_group_layout_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	tag_group_layout_header(reinterpret_cast<s_tag_group_layout_header*>(chunk_data_begin))
{
	chunk_data_begin += sizeof(s_tag_group_layout_header);
	debug_point;

	parse_children(nullptr);
}
