#include "mandrilllib-private-pch.h"

c_build_identifier_chunk::c_build_identifier_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	id()
{
	debug_point;
}

BCS_RESULT c_build_identifier_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const unsigned long long* id_ptr = reinterpret_cast<const unsigned long long*>(get_chunk_data_start());

	id = chunk_byteswap(*id_ptr);

	return rs;
}
