#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define POLYARTVERTEXBLOCK_ID { 0x118494C3, 0xB73F4B9B, 0xA4744DDC, 0x0674329B }
	TAG_BLOCK(
		polyartVertexBlock_block,
		"polyartVertexBlock",
		k_chudPolyArtVertexMaxCount,
		"PolyartVertex_Full",
		POLYARTVERTEXBLOCK_ID)
	{
		{ _field_short_integer, "half x*" },
		{ _field_short_integer, "half y*" },
		{ _field_short_integer, "half z*" },
		{ _field_short_integer, "half alpha*" },
		{ _field_short_integer, "half u*" },
		{ _field_short_integer, "half v*" },
		{ _field_terminator }
	};

	#define POLYARTINDEXBLOCK_ID { 0xA4C7CB01, 0x25404D14, 0xB5A27FA2, 0x93764DF2 }
	TAG_BLOCK(
		polyartIndexBlock_block,
		"polyartIndexBlock",
		PolyartIndex::k_chudPolyArtIndexMaxCount,
		"PolyartIndex",
		POLYARTINDEXBLOCK_ID)
	{
		{ _field_short_integer, "index*" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		vertexBuffersBlock_block,
		"vertexBuffersBlock",
		1,
		vertexBuffersBlock_struct);

	TAG_BLOCK_FROM_STRUCT(
		indexBuffersBlock_block,
		"indexBuffersBlock",
		1,
		indexBuffersBlock_struct);

	#define VERTEXBUFFERSBLOCK_STRUCT_ID { 0xF38916AB, 0xCA2A435E, 0xBCB353B1, 0x57130D3E }
	TAG_STRUCT(
		vertexBuffersBlock_struct,
		"vertexBuffersBlock_struct",
		"c_rasterizer_vertex_buffer",
		VERTEXBUFFERSBLOCK_STRUCT_ID)
	{
		{ _field_byte_integer, "declaration type*" },
		{ _field_byte_integer, "stride*" },
		{ _field_pad, "vertex buffer pad", 2 },
		{ _field_dword_integer, "count*" },
		{ _field_long_integer, "d3d hardware format*" },
		{ _field_terminator }
	};

	#define INDEXBUFFERSBLOCK_STRUCT_ID { 0xFB7AA38B, 0x3CE54625, 0xB96C0003, 0x60812BBC }
	TAG_STRUCT(
		indexBuffersBlock_struct,
		"indexBuffersBlock_struct",
		"c_rasterizer_index_buffer",
		INDEXBUFFERSBLOCK_STRUCT_ID)
	{
		{ _field_byte_integer, "declaration type*" },
		{ _field_byte_integer, "stride*" },
		{ _field_pad, "vertex buffer pad", 2 },
		{ _field_dword_integer, "count*" },
		{ _field_long_integer, "d3d hardware format*" },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

