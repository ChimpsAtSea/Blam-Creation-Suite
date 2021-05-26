#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define POLYARTVERTEXBLOCK_ID { 0x118494C3, 0xB73F4B9B, 0xA4744DDC, 0x0674329B }
	TAG_BLOCK(
		polyartVertexBlock_block,
		"polyartVertexBlock",
		k_chudPolyArtVertexMaxCount,
		"PolyartVertex_Full",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		POLYARTVERTEXBLOCK_ID)
	{
		{ _field_short_integer, "half x", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "half y", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "half z", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "half alpha", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "half u", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "half v", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define POLYARTINDEXBLOCK_ID { 0xA4C7CB01, 0x25404D14, 0xB5A27FA2, 0x93764DF2 }
	TAG_BLOCK(
		polyartIndexBlock_block,
		"polyartIndexBlock",
		PolyartIndex::k_chudPolyArtIndexMaxCount,
		"PolyartIndex",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		POLYARTINDEXBLOCK_ID)
	{
		{ _field_short_integer, "index", FIELD_FLAG_READ_ONLY },
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
		SET_DELETE_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VERTEXBUFFERSBLOCK_STRUCT_ID)
	{
		{ _field_byte_integer, "declaration type", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "stride", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("vertex buffer pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_dword_integer, "count", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "d3d hardware format", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define INDEXBUFFERSBLOCK_STRUCT_ID { 0xFB7AA38B, 0x3CE54625, 0xB96C0003, 0x60812BBC }
	TAG_STRUCT(
		indexBuffersBlock_struct,
		"indexBuffersBlock_struct",
		"c_rasterizer_index_buffer",
		SET_DELETE_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INDEXBUFFERSBLOCK_STRUCT_ID)
	{
		{ _field_byte_integer, "declaration type", FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "stride", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("vertex buffer pad", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_dword_integer, "count", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "d3d hardware format", FIELD_FLAG_READ_ONLY },
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



} // namespace blofeld

