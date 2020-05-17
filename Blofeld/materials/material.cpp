#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(material, MATERIAL_TAG)
	{
		FIELD( _field_tag_reference, "material shader" ),
		FIELD( _field_block, "material parameters", &material_shader_parameter_block_block ),
		FIELD( _field_block, "postprocess definition!", &material_postprocess_block_block ),
		FIELD( _field_string_id, "physics material name" ),
		FIELD( _field_string_id, "physics material name 2" ),
		FIELD( _field_string_id, "physics material name 3" ),
		FIELD( _field_string_id, "physics material name 4" ),
		FIELD( _field_real, "sort offset" ),
		FIELD( _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum ),
		FIELD( _field_char_enum, "sort layer*", &global_sort_layer_enum_defintion ),
		FIELD( _field_byte_flags, "flags!", &materialFlags ),
		FIELD( _field_byte_flags, "render flags!", &materialRenderFlags ),
		FIELD( _field_char_enum, "Transparent Shadow Policy", &MaterialTransparentShadowPolicyEnum ),
		FIELD( _field_pad, "transparentshadowpad", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(material_postprocess_texture_block, c_material::k_maximum_postprocess_textures)
	{
		FIELD( _field_tag_reference, "bitmap reference" ),
		FIELD( _field_byte_integer, "address mode" ),
		FIELD( _field_byte_integer, "filter mode" ),
		FIELD( _field_byte_integer, "frame index parameter" ),
		FIELD( _field_byte_integer, "sampler index" ),
		FIELD( _field_char_integer, "level of smallest mipmap to use" ),
		FIELD( _field_char_integer, "level of largest mipmap to use" ),
		FIELD( _field_byte_integer, "render phase mask" ),
		FIELD( _field_pad, "DHaFS", 1 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(real_vector4d_block$3, k_kilo)
	{
		FIELD( _field_real_vector_3d, "vector" ),
		FIELD( _field_real, "vector w" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(int_block$3, k_kilo)
	{
		FIELD( _field_long_integer, "int value" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(functionParameterBlock, k_uint8_max)
	{
		FIELD( _field_byte_integer, "function index" ),
		FIELD( _field_byte_integer, "render phase mask" ),
		FIELD( _field_byte_integer, "register index" ),
		FIELD( _field_byte_integer, "register offset" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(externParameterBlock, k_uint8_max)
	{
		FIELD( _field_byte_integer, "extern index" ),
		FIELD( _field_byte_integer, "extern register" ),
		FIELD( _field_byte_integer, "extern offset" ),
		FIELD( _field_byte_integer, "render phase mask" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(material_postprocess_block, 1)
	{
		FIELD( _field_block, "textures", &material_postprocess_texture_block_block ),
		FIELD( _field_block, "texture constants", &real_vector4d_block$3_block ),
		FIELD( _field_block, "real vectors", &real_vector4d_block$3_block ),
		FIELD( _field_block, "real vertex vectors", &real_vector4d_block$3_block ),
		FIELD( _field_block, "int constants", &int_block$3_block ),
		FIELD( _field_long_integer, "bool constants" ),
		FIELD( _field_long_integer, "used bool constants" ),
		FIELD( _field_long_integer, "bool render phase mask" ),
		FIELD( _field_long_integer, "vertex bool constants" ),
		FIELD( _field_long_integer, "used vertex bool constants" ),
		FIELD( _field_long_integer, "vertex bool render phase mask" ),
		FIELD( _field_block, "functions", &material_shader_function_parameter_block_block ),
		FIELD( _field_block, "function parameters", &functionParameterBlock_block ),
		FIELD( _field_block, "extern parameters", &externParameterBlock_block ),
		FIELD( _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum ),
		FIELD( _field_char_enum, "layer blend mode", &layerBlendModeEnum ),
		FIELD( _field_word_flags, "flags", &materialPostprocessFlags ),
		FIELD( _field_array, "runtime queryable properties table", &runtime_queryable_properties$3_array ),
		FIELD( _field_struct, "physics material 0!", &material_type_struct_struct_definition ),
		FIELD( _field_struct, "physics material 1!", &material_type_struct_struct_definition ),
		FIELD( _field_struct, "physics material 2!", &material_type_struct_struct_definition ),
		FIELD( _field_struct, "physics material 3!", &material_type_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(runtime_queryable_properties$3, s_material_postprocess_definition::k_runtime_queryable_properties_count)
	{
		FIELD( _field_short_block_index, "index" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(material_struct)
	{
		FIELD( _field_tag_reference, "material shader" ),
		FIELD( _field_block, "material parameters", &material_shader_parameter_block_block ),
		FIELD( _field_block, "postprocess definition!", &material_postprocess_block_block ),
		FIELD( _field_string_id, "physics material name" ),
		FIELD( _field_string_id, "physics material name 2" ),
		FIELD( _field_string_id, "physics material name 3" ),
		FIELD( _field_string_id, "physics material name 4" ),
		FIELD( _field_real, "sort offset" ),
		FIELD( _field_char_enum, "alpha blend mode", &alpha_blend_mode_enum ),
		FIELD( _field_char_enum, "sort layer*", &global_sort_layer_enum_defintion ),
		FIELD( _field_byte_flags, "flags!", &materialFlags ),
		FIELD( _field_byte_flags, "render flags!", &materialRenderFlags ),
		FIELD( _field_char_enum, "Transparent Shadow Policy", &MaterialTransparentShadowPolicyEnum ),
		FIELD( _field_pad, "transparentshadowpad", 3 ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(layerBlendModeEnum, 3)
	{
		OPTION("none"),
		OPTION("blended"),
		OPTION("layered"),
	};

	TAG_ENUM(materialPostprocessFlags, 10)
	{
		OPTION("wireframe outline"),
		OPTION("force single pass"),
		OPTION("has pixel constant functions"),
		OPTION("has vertex constant functions"),
		OPTION("has texture transform functions"),
		OPTION("has texture frame functions"),
		OPTION("resolve screen before rendering"),
		OPTION("disable atmosphere fog"),
		OPTION("uses depth camera"),
		OPTION("material is variable"),
	};

	TAG_ENUM(materialFlags, 2)
	{
		OPTION("converted from shader"),
		OPTION("decal post lighting"),
	};

	TAG_ENUM(materialRenderFlags, 1)
	{
		OPTION("resolve screen before rendering"),
	};

	TAG_ENUM(MaterialTransparentShadowPolicyEnum, 3)
	{
		OPTION("none"),
		OPTION("render as decal (cheap)"),
		OPTION("render with material (expensive)"),
	};

} // namespace blofeld

