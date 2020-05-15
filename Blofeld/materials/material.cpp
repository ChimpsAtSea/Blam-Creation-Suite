#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(material_postprocess, 1)
{
	{ _field_block, "textures", &material_postprocess_texture_block },
	{ _field_block, "texture constants", &real_vector4d_block },
	{ _field_block, "real vectors", &real_vector4d_block },
	{ _field_block, "real vertex vectors", &real_vector4d_block },
	{ _field_block, "int constants", &int_block },
	{ _field_long_integer, "bool constants" },
	{ _field_long_integer, "used bool constants" },
	{ _field_long_integer, "bool render phase mask" },
	{ _field_long_integer, "vertex bool constants" },
	{ _field_long_integer, "used vertex bool constants" },
	{ _field_long_integer, "vertex bool render phase mask" },
	{ _field_block, "functions", &material_shader_function_parameter_block },
	{ _field_block, "function parameters", &functionParameterBlock_block },
	{ _field_block, "extern parameters", &externParameterBlock_block },
	{ _field_char_enum, "alpha blend mode" },
	{ _field_char_enum, "layer blend mode" },
	{ _field_word_flags, "flags" },
	{ _field_array, "runtime queryable properties table" },
	{ _field_struct, "physics material 0!" },
	{ _field_struct, "physics material 1!" },
	{ _field_struct, "physics material 2!" },
	{ _field_struct, "physics material 3!" },
	{ _field_terminator },
};

TAG_BLOCK(material_postprocess_texture, c_material::k_maximum_postprocess_textures)
{
	{ _field_tag_reference, "bitmap reference" },
	{ _field_byte_integer, "address mode" },
	{ _field_byte_integer, "filter mode" },
	{ _field_byte_integer, "frame index parameter" },
	{ _field_byte_integer, "sampler index" },
	{ _field_char_integer, "level of smallest mipmap to use" },
	{ _field_char_integer, "level of largest mipmap to use" },
	{ _field_byte_integer, "render phase mask" },
	{ _field_pad, "DHaFS", 1 },
	{ _field_terminator },
};

TAG_BLOCK(real_vector4d, k_kilo)
{
	{ _field_real_vector_3d, "vector" },
	{ _field_real, "vector w" },
	{ _field_terminator },
};

TAG_BLOCK(int, k_kilo)
{
	{ _field_long_integer, "int value" },
	{ _field_terminator },
};

TAG_BLOCK(functionParameterBlock, k_uint8_max)
{
	{ _field_byte_integer, "function index" },
	{ _field_byte_integer, "render phase mask" },
	{ _field_byte_integer, "register index" },
	{ _field_byte_integer, "register offset" },
	{ _field_terminator },
};

TAG_BLOCK(externParameterBlock, k_uint8_max)
{
	{ _field_byte_integer, "extern index" },
	{ _field_byte_integer, "extern register" },
	{ _field_byte_integer, "extern offset" },
	{ _field_byte_integer, "render phase mask" },
	{ _field_terminator },
};

TAG_GROUP(material, MATERIAL_TAG)
{
	{ _field_tag_reference, "material shader" },
	{ _field_block, "material parameters", &material_shader_parameter_block },
	{ _field_block, "postprocess definition!", &material_postprocess_block },
	{ _field_string_id, "physics material name" },
	{ _field_string_id, "physics material name 2" },
	{ _field_string_id, "physics material name 3" },
	{ _field_string_id, "physics material name 4" },
	{ _field_real, "sort offset" },
	{ _field_char_enum, "alpha blend mode" },
	{ _field_char_enum, "sort layer*" },
	{ _field_byte_flags, "flags!" },
	{ _field_byte_flags, "render flags!" },
	{ _field_char_enum, "Transparent Shadow Policy" },
	{ _field_pad, "transparentshadowpad", 3 },
	{ _field_terminator },
};

} // namespace blofeld

