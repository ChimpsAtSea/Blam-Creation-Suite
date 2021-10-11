#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define MATERIAL_SHADER_BANK_STRUCT_DEFINITION_ID { 0xB8F8C973, 0x40FF466B, 0x89CFF6B7, 0xD45234AF }
	TAG_BLOCK(
		material_shader_bank_block,
		"material_shader_bank_block",
		1,
		"c_material_shader_bank",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_SHADER_BANK_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "compiled vertex shaders", FIELD_FLAG_READ_ONLY, &compiled_vertex_shader_block },
		{ _field_block, "compiled vertex shader hashes", FIELD_FLAG_READ_ONLY, &compiled_shader_hash_block },
		{ _field_block, "compiled vertex shader binding info", FIELD_FLAG_READ_ONLY, &vertexShaderUniqueBindingInfoBlock_block },
		{ _field_block, "compiled pixel shaders", FIELD_FLAG_READ_ONLY, &compiled_pixel_shader_block },
		{ _field_block, "compiled pixel shader hashes", FIELD_FLAG_READ_ONLY, &compiled_shader_hash_block },
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
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
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
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VERTEXSHADERUNIQUEBINDINGINFOBLOCK_ID)
	{
		{ _field_long_integer, "VertexType" },
		{ _field_long_integer, "EntryPoint" },
		{ _field_long_block_index, "PixelShaderIndex", &compiled_pixel_shader_block },
		{ _field_terminator }
	};



} // namespace blofeld

