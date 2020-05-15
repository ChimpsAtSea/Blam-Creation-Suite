#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(polyartVertexBlock, k_chudPolyArtVertexMaxCount)
{
	{ _field_short_integer, "half x*" },
	{ _field_short_integer, "half y*" },
	{ _field_short_integer, "half z*" },
	{ _field_short_integer, "half alpha*" },
	{ _field_short_integer, "half u*" },
	{ _field_short_integer, "half v*" },
	{ _field_terminator },
};

TAG_BLOCK(polyartIndexBlock, PolyartIndex::k_chudPolyArtIndexMaxCount)
{
	{ _field_short_integer, "index*" },
	{ _field_terminator },
};

TAG_BLOCK(vertexBuffersBlock, 1)
{
	{ _field_byte_integer, "declaration type*" },
	{ _field_byte_integer, "stride*" },
	{ _field_pad, "vertex buffer pad", 2 },
	{ _field_dword_integer, "count*" },
	{ _field_long_integer, "d3d hardware format*" },
	{ _field_terminator },
};

TAG_BLOCK(indexBuffersBlock, 1)
{
	{ _field_byte_integer, "declaration type*" },
	{ _field_byte_integer, "stride*" },
	{ _field_pad, "vertex buffer pad", 2 },
	{ _field_dword_integer, "count*" },
	{ _field_long_integer, "d3d hardware format*" },
	{ _field_terminator },
};

} // namespace blofeld

