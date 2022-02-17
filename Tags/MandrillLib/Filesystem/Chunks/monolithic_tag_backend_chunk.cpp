#include "mandrilllib-private-pch.h"

c_monolithic_tag_backend_chunk::c_monolithic_tag_backend_chunk(const void* chunk_data) :
	c_typed_chunk(chunk_data, nullptr)
{
	debug_point;
}

c_monolithic_tag_backend_chunk::~c_monolithic_tag_backend_chunk()
{

}
