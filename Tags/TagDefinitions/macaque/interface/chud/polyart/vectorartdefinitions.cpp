#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define VECTORART_ASSET_STRUCT_DEFINITION_ID { 0x6AAD9915, 0x5B314294, 0x830B2083, 0x1FE05B82 }
	TAG_BLOCK(
		vectorart_asset_block,
		"vectorart_asset_block",
		1,
		"VectorartAsset",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE),
		VECTORART_ASSET_STRUCT_DEFINITION_ID)
	{
		{ _field_char_enum, "runtime flags", &g_polyartAssetStateFlags },
		FIELD_PAD("MERP", nullptr, 3),
		{ _field_real, "antialiasing extent size" },
		{ _field_real, "import fudge factor (suggested 0.5)" },
		{ _field_real_point_2d, "bounds" },
		{ _field_real, "curve smoothness" },
		{ _field_block, "vertices", &polyartVertexBlock_block },
		{ _field_block, "indices", &polyartIndexBlock_block },
		{ _field_block, "pc vertex buffers", &vertexBuffersBlock_block },
		{ _field_block, "pc index buffers", &indexBuffersBlock_block },
		{ _field_api_interop, "vertex buffer interop", &vectorartVertexBufferDescriptorStruct },
		{ _field_api_interop, "index buffer interop", &polyartIndexBufferDescriptorStruct },
		{ _field_terminator }
	};

	TAG_GROUP(
		vectorart_asset_group,
		VECTORART_ASSET_TAG,
		nullptr,
		INVALID_TAG,
		vectorart_asset_block );

	#define VECTORARTVERTEXBUFFERDESCRIPTORSTRUCT_ID { 0x09DC8488, 0x852B4195, 0x8B27777E, 0x98E00F6C }
	TAG_STRUCT(
		vectorartVertexBufferDescriptorStruct,
		"vectorartVertexBufferDescriptorStruct",
		"VectorartVertexBufferDescriptor",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		VECTORARTVERTEXBUFFERDESCRIPTORSTRUCT_ID)
	{
		{ _field_data, "vertices" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

