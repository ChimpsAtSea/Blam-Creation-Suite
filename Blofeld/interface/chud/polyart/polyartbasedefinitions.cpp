#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(polyartVertexBlock, k_chudPolyArtVertexMaxCount)
{
	FIELD( _field_short_integer, "half x*" ),
	FIELD( _field_short_integer, "half y*" ),
	FIELD( _field_short_integer, "half z*" ),
	FIELD( _field_short_integer, "half alpha*" ),
	FIELD( _field_short_integer, "half u*" ),
	FIELD( _field_short_integer, "half v*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(polyartIndexBlock, PolyartIndex::k_chudPolyArtIndexMaxCount)
{
	FIELD( _field_short_integer, "index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(vertexBuffersBlock, 1, vertexBuffersBlock_struct_struct_definition );

TAG_BLOCK_FROM_STRUCT(indexBuffersBlock, 1, indexBuffersBlock_struct_struct_definition );

TAG_STRUCT(vertexBuffersBlock_struct)
{
	FIELD( _field_byte_integer, "declaration type*" ),
	FIELD( _field_byte_integer, "stride*" ),
	FIELD( _field_pad, "vertex buffer pad", 2 ),
	FIELD( _field_dword_integer, "count*" ),
	FIELD( _field_long_integer, "d3d hardware format*" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(indexBuffersBlock_struct)
{
	FIELD( _field_byte_integer, "declaration type*" ),
	FIELD( _field_byte_integer, "stride*" ),
	FIELD( _field_pad, "vertex buffer pad", 2 ),
	FIELD( _field_dword_integer, "count*" ),
	FIELD( _field_long_integer, "d3d hardware format*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

