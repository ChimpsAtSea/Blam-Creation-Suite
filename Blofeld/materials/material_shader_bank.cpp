#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(compiled_shader_hash, kshaderBlockCount)
{
	{ _field_long_integer, "hash" },
	{ _field_terminator },
};

TAG_BLOCK(vertexShaderUniqueBindingInfoBlock, kshaderBlockCount)
{
	{ _field_long_integer, "VertexType" },
	{ _field_long_integer, "EntryPoint" },
	{ _field_long_block_index, "PixelShaderIndex" },
	{ _field_terminator },
};

TAG_GROUP(material_shader_bank, MATERIAL_SHADER_BANK_TAG)
{
	{ _field_block, "compiled vertex shaders*", &compiled_vertex_shader_block },
	{ _field_block, "compiled vertex shader hashes*", &compiled_shader_hash_block },
	{ _field_block, "compiled vertex shader binding info*", &vertexShaderUniqueBindingInfoBlock_block },
	{ _field_block, "compiled pixel shaders*", &compiled_pixel_shader_block },
	{ _field_block, "compiled pixel shader hashes*", &compiled_shader_hash_block },
	{ _field_terminator },
};

} // namespace blofeld

