#include "mandrilllib-private-pch.h"

c_monolithic_tag_file_layout_registry_chunk::c_monolithic_tag_file_layout_registry_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent)
{
	debug_point;
}
