#include "mandrilllib-private-pch.h"

c_tag_resource_exploded_chunk::c_tag_resource_exploded_chunk(c_chunk& parent, c_single_tag_file_reader& reader) :
	c_typed_single_tag_file_reader_chunk(parent, reader)
{
	debug_point;
}

c_tag_resource_exploded_chunk::~c_tag_resource_exploded_chunk()
{
}
