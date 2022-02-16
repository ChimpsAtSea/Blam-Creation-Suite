#include "mandrilllib-private-pch.h"

c_build_identifier_chunk::c_build_identifier_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	id(chunk_byteswap(*reinterpret_cast<unsigned long long*>(chunk_data_begin)))
{
	debug_point;
}
