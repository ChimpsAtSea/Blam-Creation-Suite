#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MATERIAL_SHADER_BANK_STRUCT_DEFINITION_ID { 0xB8F8C973, 0x40FF466B, 0x89CFF6B7, 0xD45234AF }
	TAG_BLOCK(
		material_shader_bank_block,
		"material_shader_bank_block",
		1,
		"c_material_shader_bank",
		MATERIAL_SHADER_BANK_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "compiled vertex shaders*", &compiled_vertex_shader_block },
		{ _field_block, "compiled vertex shader hashes*", &compiled_shader_hash_block },
		{ _field_block, "compiled vertex shader binding info*", &vertexShaderUniqueBindingInfoBlock_block },
		{ _field_block, "compiled pixel shaders*", &compiled_pixel_shader_block },
		{ _field_block, "compiled pixel shader hashes*", &compiled_shader_hash_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		material_shader_bank_group,
		MATERIAL_SHADER_BANK_TAG,
		nullptr,
		INVALID_TAG,
		material_shader_bank_block );

	#define COMPILED_SHADER_HASH_BLOCK_ID { 0xEC4EC556, 0x049248BC, 0xACFA5D9C, 0x3A703A9A }
	TAG_BLOCK(
		compiled_shader_hash_block,
		"compiled_shader_hash_block",
		kshaderBlockCount,
		"long",
		COMPILED_SHADER_HASH_BLOCK_ID)
	{
		{ _field_long_integer, "hash" },
		{ _field_terminator }
	};

	#define VERTEXSHADERUNIQUEBINDINGINFOBLOCK_ID { 0x1A5E3365, 0x8552445A, 0xA543DD7B, 0xB368406F }
	TAG_BLOCK(
		vertexShaderUniqueBindingInfoBlock_block,
		"vertexShaderUniqueBindingInfoBlock",
		kshaderBlockCount,
		"VertexShaderUniqueBindingInfo",
		VERTEXSHADERUNIQUEBINDINGINFOBLOCK_ID)
	{
		{ _field_long_integer, "VertexType" },
		{ _field_long_integer, "EntryPoint" },
		{ _field_long_block_index, "PixelShaderIndex" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

