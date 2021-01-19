#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(material_shader_bank, MATERIAL_SHADER_BANK_TAG)
	{
		{ _field_block, "compiled vertex shaders*", &compiled_vertex_shader_block_block },
		{ _field_block, "compiled vertex shader hashes*", &compiled_shader_hash_block_block },
		{ _field_block, "compiled vertex shader binding info*", &vertexShaderUniqueBindingInfoBlock_block },
		{ _field_block, "compiled pixel shaders*", &compiled_pixel_shader_block_block },
		{ _field_block, "compiled pixel shader hashes*", &compiled_shader_hash_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(compiled_shader_hash_block, kshaderBlockCount)
	{
		{ _field_long_integer, "hash" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(vertexShaderUniqueBindingInfoBlock, kshaderBlockCount)
	{
		{ _field_long_integer, "VertexType" },
		{ _field_long_integer, "EntryPoint" },
		{ _field_long_block_index, "PixelShaderIndex" },
		{ _field_terminator }
	};

} // namespace blofeld

