#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(material, MATERIAL_TAG)
	{
		{ _field_tag_reference, "material shader", &material_shader_reference },
		{ _field_block, "material parameters", &material_shader_parameter_block_block },
		{ _field_block, "postprocess definition!", &material_postprocess_block_block },
		{ _field_string_id, "physics material name" },
		{ _field_string_id, "physics material name 2" },
		{ _field_string_id, "physics material name 3" },
		{ _field_string_id, "physics material name 4" },
		{ _field_real, "sort offset" },
		{ _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum },
		{ _field_char_enum, "sort layer*", &global_sort_layer_enum_defintion },
		{ _field_byte_flags, "flags!", &materialFlags },
		{ _field_byte_flags, "render flags!", &materialRenderFlags },
		{ _field_char_enum, "Transparent Shadow Policy", &MaterialTransparentShadowPolicyEnum },
		{ _field_pad, "transparentshadowpad", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK(material_postprocess_texture_block, c_material::k_maximum_postprocess_textures)
	{
		{ _field_tag_reference, "bitmap reference", &global_bitmap_reference },
		{ _field_byte_integer, "address mode" },
		{ _field_byte_integer, "filter mode" },
		{ _field_byte_integer, "frame index parameter" },
		{ _field_byte_integer, "sampler index" },
		{ _field_char_integer, "level of smallest mipmap to use" },
		{ _field_char_integer, "level of largest mipmap to use" },
		{ _field_byte_integer, "render phase mask" },
		{ _field_pad, "DHaFS", 1 },
		{ _field_terminator }
	};

	TAG_BLOCK(real_vector4d_block$3, k_kilo)
	{
		{ _field_real_vector_3d, "vector" },
		{ _field_real, "vector w" },
		{ _field_terminator }
	};

	TAG_BLOCK(int_block$3, k_kilo)
	{
		{ _field_long_integer, "int value" },
		{ _field_terminator }
	};

	TAG_BLOCK(functionParameterBlock, k_uint8_max)
	{
		{ _field_byte_integer, "function index" },
		{ _field_byte_integer, "render phase mask" },
		{ _field_byte_integer, "register index" },
		{ _field_byte_integer, "register offset" },
		{ _field_terminator }
	};

	TAG_BLOCK(externParameterBlock, k_uint8_max)
	{
		{ _field_byte_integer, "extern index" },
		{ _field_byte_integer, "extern register" },
		{ _field_byte_integer, "extern offset" },
		{ _field_byte_integer, "render phase mask" },
		{ _field_terminator }
	};

	TAG_BLOCK(material_postprocess_block, 1)
	{
		{ _field_block, "textures", &material_postprocess_texture_block_block },
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
		{ _field_block, "functions", &material_shader_function_parameter_block_block },
		{ _field_block, "function parameters", &functionParameterBlock_block },
		{ _field_block, "extern parameters", &externParameterBlock_block },
		{ _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum },
		{ _field_char_enum, "layer blend mode", &layerBlendModeEnum },
		{ _field_word_flags, "flags", &materialPostprocessFlags },
		{ _field_array, "runtime queryable properties table", &runtime_queryable_properties$3_array },
		{ _field_struct, "physics material 0!", &material_type_struct_struct_definition },
		{ _field_struct, "physics material 1!", &material_type_struct_struct_definition },
		{ _field_struct, "physics material 2!", &material_type_struct_struct_definition },
		{ _field_struct, "physics material 3!", &material_type_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_ARRAY(runtime_queryable_properties$3, s_material_postprocess_definition::k_runtime_queryable_properties_count)
	{
		{ _field_short_block_index, "index" },
		{ _field_terminator }
	};

	TAG_STRUCT(material_struct)
	{
		{ _field_tag_reference, "material shader", &material_shader_reference },
		{ _field_block, "material parameters", &material_shader_parameter_block_block },
		{ _field_block, "postprocess definition!", &material_postprocess_block_block },
		{ _field_string_id, "physics material name" },
		{ _field_string_id, "physics material name 2" },
		{ _field_string_id, "physics material name 3" },
		{ _field_string_id, "physics material name 4" },
		{ _field_real, "sort offset" },
		{ _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum },
		{ _field_char_enum, "sort layer*", &global_sort_layer_enum_defintion },
		{ _field_byte_flags, "flags!", &materialFlags },
		{ _field_byte_flags, "render flags!", &materialRenderFlags },
		{ _field_char_enum, "Transparent Shadow Policy", &MaterialTransparentShadowPolicyEnum },
		{ _field_pad, "transparentshadowpad", 3 },
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

} // namespace blofeld

