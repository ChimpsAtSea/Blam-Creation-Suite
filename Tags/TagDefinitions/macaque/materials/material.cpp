#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MATERIAL_STRUCT_DEFINITION_ID { 0x2EF5672B, 0xA9634408, 0x8E6FA15E, 0xB24C9B83 }
	TAG_BLOCK(
		material_block,
		"material_block",
		1,
		"c_material",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "material shader", &material_shader_reference },
		{ _field_block, "material parameters", &material_shader_parameter_block },
		{ _field_block, "postprocess definition", &material_postprocess_block },
		{ _field_string_id, "physics material name" },
		{ _field_string_id, "physics material name 2" },
		{ _field_string_id, "physics material name 3" },
		{ _field_string_id, "physics material name 4" },
		{ _field_real, "sort offset" },
		{ _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum },
		{ _field_char_enum, "sort layer", &global_sort_layer_enum_defintion },
		{ _field_byte_flags, "flags", &materialFlags },
		{ _field_byte_flags, "render flags", &materialRenderFlags },
		{ _field_char_enum, "Transparent Shadow Policy", &MaterialTransparentShadowPolicyEnum },
		FIELD_PAD("transparentshadowpad", nullptr, 3),
		{ _field_terminator }
	};

	TAG_GROUP(
		material_group,
		MATERIAL_TAG,
		nullptr,
		INVALID_TAG,
		material_block );

	#define MATERIAL_POSTPROCESS_BLOCK_ID { 0x1D50D0C3, 0xC85241C0, 0x9E5B9057, 0xCE98F3A3 }
	TAG_BLOCK(
		material_postprocess_block,
		"material_postprocess_block",
		1,
		"s_material_postprocess_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_POSTPROCESS_BLOCK_ID)
	{
		{ _field_block, "textures", &material_postprocess_texture_block },
		{ _field_block, "texture constants", &real_vector4d_block$3_block },
		{ _field_block, "real vectors", &real_vector4d_block$3_block },
		{ _field_block, "real vertex vectors", &real_vector4d_block$3_block },
		{ _field_block, "int constants", &int_block$3_block },
		{ _field_long_integer, "bool constants" },
		{ _field_long_integer, "used bool constants" },
		{ _field_long_integer, "bool render phase mask" },
		{ _field_long_integer, "vertex bool constants" },
		{ _field_long_integer, "used vertex bool constants" },
		{ _field_long_integer, "vertex bool render phase mask" },
		{ _field_block, "functions", &material_shader_function_parameter_block },
		{ _field_block, "function parameters", &functionParameterBlock_block },
		{ _field_block, "extern parameters", &externParameterBlock_block },
		{ _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum },
		{ _field_char_enum, "layer blend mode", &layerBlendModeEnum },
		{ _field_word_flags, "flags", &materialPostprocessFlags },
		{ _field_array, "runtime queryable properties table", &runtime_queryable_properties$3_array },
		{ _field_struct, "physics material 0", &material_type_struct },
		{ _field_struct, "physics material 1", &material_type_struct },
		{ _field_struct, "physics material 2", &material_type_struct },
		{ _field_struct, "physics material 3", &material_type_struct },
		{ _field_terminator }
	};

	#define MATERIAL_POSTPROCESS_TEXTURE_BLOCK_ID { 0xCD9812EC, 0x3CD64BE1, 0xB33BFE48, 0x0BBCA596 }
	TAG_BLOCK(
		material_postprocess_texture_block,
		"material_postprocess_texture_block",
		c_material::k_maximum_postprocess_textures,
		"s_material_postprocess_texture",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_POSTPROCESS_TEXTURE_BLOCK_ID)
	{
		{ _field_tag_reference, "bitmap reference", &global_bitmap_reference },
		{ _field_byte_integer, "address mode" },
		{ _field_byte_integer, "filter mode" },
		{ _field_byte_integer, "frame index parameter" },
		{ _field_byte_integer, "sampler index" },
		{ _field_char_integer, "level of smallest mipmap to use" },
		{ _field_char_integer, "level of largest mipmap to use" },
		{ _field_byte_integer, "render phase mask" },
		FIELD_PAD("DHaFS", nullptr, 1),
		{ _field_terminator }
	};

	#define REAL_VECTOR4D_BLOCK_ID { 0x97A81143, 0x6C1C43F9, 0x9055F558, 0xC20B4CF1 }
	TAG_BLOCK(
		real_vector4d_block$3_block,
		"real_vector4d_block",
		k_kilo,
		"real_vector4d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		REAL_VECTOR4D_BLOCK_ID)
	{
		{ _field_real_vector_3d, "vector" },
		{ _field_real, "vector w" },
		{ _field_terminator }
	};

	#define INT_BLOCK_ID { 0xE29C869D, 0xA4AD485B, 0xBF0BF7E6, 0x60402421 }
	TAG_BLOCK(
		int_block$3_block,
		"int_block",
		k_kilo,
		"int",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INT_BLOCK_ID)
	{
		{ _field_long_integer, "int value" },
		{ _field_terminator }
	};

	#define FUNCTIONPARAMETERBLOCK_ID { 0x25A1ECC0, 0xB81F4CBE, 0x9F9466E2, 0x80A9CFDB }
	TAG_BLOCK(
		functionParameterBlock_block,
		"functionParameterBlock",
		k_uint8_max,
		"s_materialFunctionParameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FUNCTIONPARAMETERBLOCK_ID)
	{
		{ _field_byte_integer, "function index" },
		{ _field_byte_integer, "render phase mask" },
		{ _field_byte_integer, "register index" },
		{ _field_byte_integer, "register offset" },
		{ _field_terminator }
	};

	#define EXTERNPARAMETERBLOCK_ID { 0x72118236, 0xB22C4F91, 0xA645DAAF, 0xABE7A5BB }
	TAG_BLOCK(
		externParameterBlock_block,
		"externParameterBlock",
		k_uint8_max,
		"s_materialExternParameter",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EXTERNPARAMETERBLOCK_ID)
	{
		{ _field_byte_integer, "extern index" },
		{ _field_byte_integer, "extern register" },
		{ _field_byte_integer, "extern offset" },
		{ _field_byte_integer, "render phase mask" },
		{ _field_terminator }
	};

	#define RUNTIME_QUERYABLE_PROPERTIES_ID { 0xC7C8D371, 0x1E1A4BB1, 0xBE9FC430, 0xBEC7DEBE }
	TAG_ARRAY(
		runtime_queryable_properties$3_array,
		"runtime_queryable_properties",
		s_material_postprocess_definition::k_runtime_queryable_properties_count,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RUNTIME_QUERYABLE_PROPERTIES_ID)
	{
		{ _field_short_block_index, "index", &g_null_block },
		{ _field_terminator }
	};

	#define MATERIAL_STRUCT_ID { 0x13810D23, 0x3C154406, 0xAA769459, 0xA7F03D07 }
	TAG_STRUCT(
		material_struct,
		"material_struct",
		"material_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_STRUCT_ID)
	{
		{ _field_tag_reference, "material shader", &material_shader_reference },
		{ _field_block, "material parameters", &material_shader_parameter_block },
		{ _field_block, "postprocess definition", &material_postprocess_block },
		{ _field_string_id, "physics material name" },
		{ _field_string_id, "physics material name 2" },
		{ _field_string_id, "physics material name 3" },
		{ _field_string_id, "physics material name 4" },
		{ _field_real, "sort offset" },
		{ _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum },
		{ _field_char_enum, "sort layer", &global_sort_layer_enum_defintion },
		{ _field_byte_flags, "flags", &materialFlags },
		{ _field_byte_flags, "render flags", &materialRenderFlags },
		{ _field_char_enum, "Transparent Shadow Policy", &MaterialTransparentShadowPolicyEnum },
		FIELD_PAD("transparentshadowpad", nullptr, 3),
		{ _field_terminator }
	};

	STRINGS(layerBlendModeEnum)
	{
		"none",
		"blended",
		"layered"
	};
	STRING_LIST(layerBlendModeEnum, layerBlendModeEnum_strings, _countof(layerBlendModeEnum_strings));

	STRINGS(materialPostprocessFlags)
	{
		"wireframe outline",
		"force single pass",
		"has pixel constant functions",
		"has vertex constant functions",
		"has texture transform functions",
		"has texture frame functions",
		"resolve screen before rendering",
		"disable atmosphere fog",
		"uses depth camera",
		"material is variable"
	};
	STRING_LIST(materialPostprocessFlags, materialPostprocessFlags_strings, _countof(materialPostprocessFlags_strings));

	STRINGS(materialFlags)
	{
		"converted from shader",
		"decal post lighting"
	};
	STRING_LIST(materialFlags, materialFlags_strings, _countof(materialFlags_strings));

	STRINGS(materialRenderFlags)
	{
		"resolve screen before rendering"
	};
	STRING_LIST(materialRenderFlags, materialRenderFlags_strings, _countof(materialRenderFlags_strings));

	STRINGS(MaterialTransparentShadowPolicyEnum)
	{
		"none",
		"render as decal (cheap)",
		"render with material (expensive)"
	};
	STRING_LIST(MaterialTransparentShadowPolicyEnum, MaterialTransparentShadowPolicyEnum_strings, _countof(MaterialTransparentShadowPolicyEnum_strings));

} // namespace macaque

} // namespace blofeld

