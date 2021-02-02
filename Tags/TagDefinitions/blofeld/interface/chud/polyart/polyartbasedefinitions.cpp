#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(polyartVertexBlock, k_chudPolyArtVertexMaxCount)
	{
		{ _field_legacy, _field_short_integer, "half x*" },
		{ _field_legacy, _field_short_integer, "half y*" },
		{ _field_legacy, _field_short_integer, "half z*" },
		{ _field_legacy, _field_short_integer, "half alpha*" },
		{ _field_legacy, _field_short_integer, "half u*" },
		{ _field_legacy, _field_short_integer, "half v*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(polyartIndexBlock, PolyartIndex::k_chudPolyArtIndexMaxCount)
	{
		{ _field_legacy, _field_short_integer, "index*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(vertexBuffersBlock, 1, vertexBuffersBlock_struct_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(indexBuffersBlock, 1, indexBuffersBlock_struct_struct_definition );

	V5_TAG_STRUCT(vertexBuffersBlock_struct)
	{
		{ _field_legacy, _field_byte_integer, "declaration type*" },
		{ _field_legacy, _field_byte_integer, "stride*" },
		{ _field_legacy, _field_pad, "vertex buffer pad", 2 },
		{ _field_legacy, _field_dword_integer, "count*" },
		{ _field_legacy, _field_long_integer, "d3d hardware format*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(indexBuffersBlock_struct)
	{
		{ _field_legacy, _field_byte_integer, "declaration type*" },
		{ _field_legacy, _field_byte_integer, "stride*" },
		{ _field_legacy, _field_pad, "vertex buffer pad", 2 },
		{ _field_legacy, _field_dword_integer, "count*" },
		{ _field_legacy, _field_long_integer, "d3d hardware format*" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(g_polyartAssetStateFlags)
	{
		"processed*!",
		"available*!"
	};
	STRING_LIST(g_polyartAssetStateFlags, g_polyartAssetStateFlags_strings, _countof(g_polyartAssetStateFlags_strings));

	STRINGS(PolyartVertexFormatTypeEnum)
	{
		"Position",
		"Position And UV"
	};
	STRING_LIST(PolyartVertexFormatTypeEnum, PolyartVertexFormatTypeEnum_strings, _countof(PolyartVertexFormatTypeEnum_strings));

} // namespace blofeld

