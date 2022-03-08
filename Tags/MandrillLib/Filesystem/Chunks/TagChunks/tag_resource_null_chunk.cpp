#include "mandrilllib-private-pch.h"

c_tag_resource_null_chunk::c_tag_resource_null_chunk(c_chunk& parent) :
	c_typed_chunk(&parent)
{
	debug_point;
}

c_tag_resource_null_chunk::~c_tag_resource_null_chunk()
{
}
