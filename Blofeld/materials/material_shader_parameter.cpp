#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(material_shader_parameter, s_material_shader_parameter::k_max_material_shader_parameters)
{
	{ _field_string_id, "parameter name^*" },
	{ _field_long_enum, "parameter type*" },
	{ _field_long_integer, "parameter index*!" },
	{ _field_tag_reference, "bitmap" },
	{ _field_string_id, "bitmap path" },
	{ _field_real_argb_color, "color" },
	{ _field_real, "real" },
	{ _field_real_vector_3d, "vector" },
	{ _field_long_integer, "int/bool" },
	{ _field_word_integer, "bitmap flags" },
	{ _field_word_integer, "bitmap filter mode" },
	{ _field_word_integer, "bitmap address mode" },
	{ _field_word_integer, "bitmap address mode x" },
	{ _field_word_integer, "bitmap address mode y" },
	{ _field_word_integer, "bitmap sharpen mode" },
	{ _field_byte_integer, "bitmap extern mode" },
	{ _field_byte_integer, "bitmap min mipmap" },
	{ _field_byte_integer, "bitmap max mipmap" },
	{ _field_byte_integer, "render phases used" },
	{ _field_block, "function parameters", &material_shader_function_parameter_block },
	{ _field_data, "display name*" },
	{ _field_data, "display group*" },
	{ _field_data, "display help text*" },
	{ _field_real, "display minimum" },
	{ _field_real, "display maximum" },
	{ _field_byte_integer, "register index*!" },
	{ _field_byte_integer, "register offset*!" },
	{ _field_byte_integer, "register count*!" },
	{ _field_char_enum, "register set*!" },
	{ _field_terminator },
};

TAG_BLOCK(material_shader_function_parameter, s_material_shader_parameter::k_max_material_shader_parameters)
{
	{ _field_long_enum, "type^" },
	{ _field_string_id, "input name" },
	{ _field_string_id, "range name" },
	{ _field_char_enum, "Output Modifier!" },
	{ _field_pad, "BVCG", 3 },
	{ _field_string_id, "Output Modifier Input!" },
	{ _field_real, "time period:seconds" },
	{ _field_explanation, "FUNCTION" },
	{ _field_custom },
	{ _field_struct, "function" },
	{ _field_terminator },
};

} // namespace blofeld

