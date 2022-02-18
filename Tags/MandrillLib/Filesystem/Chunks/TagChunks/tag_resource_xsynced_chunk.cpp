#include "mandrilllib-private-pch.h"

c_tag_resource_xsynced_chunk::c_tag_resource_xsynced_chunk(const void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(chunk_data, parent, reader)
{
	debug_point;
}

c_tag_resource_xsynced_chunk::~c_tag_resource_xsynced_chunk()
{
}
