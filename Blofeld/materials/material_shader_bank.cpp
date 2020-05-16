#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(material_shader_bank, MATERIAL_SHADER_BANK_TAG)
{
	FIELD( _field_block, "compiled vertex shaders*", &compiled_vertex_shader_block_block ),
	FIELD( _field_block, "compiled vertex shader hashes*", &compiled_shader_hash_block_block ),
	FIELD( _field_block, "compiled vertex shader binding info*", &vertexShaderUniqueBindingInfoBlock_block ),
	FIELD( _field_block, "compiled pixel shaders*", &compiled_pixel_shader_block_block ),
	FIELD( _field_block, "compiled pixel shader hashes*", &compiled_shader_hash_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(compiled_shader_hash_block, kshaderBlockCount)
{
	FIELD( _field_long_integer, "hash" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vertexShaderUniqueBindingInfoBlock, kshaderBlockCount)
{
	FIELD( _field_long_integer, "VertexType" ),
	FIELD( _field_long_integer, "EntryPoint" ),
	FIELD( _field_long_block_index, "PixelShaderIndex" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

