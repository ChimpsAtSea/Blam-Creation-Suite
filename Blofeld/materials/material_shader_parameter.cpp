#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(material_shader_parameter, s_material_shader_parameter::k_max_material_shader_parameters)
{
	FIELD( _field_string_id, "parameter name^*" ),
	FIELD( _field_long_enum, "parameter type*" ),
	FIELD( _field_long_integer, "parameter index*!" ),
	FIELD( _field_tag_reference, "bitmap" ),
	FIELD( _field_string_id, "bitmap path" ),
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_real, "real" ),
	FIELD( _field_real_vector_3d, "vector" ),
	FIELD( _field_long_integer, "int/bool" ),
	FIELD( _field_word_integer, "bitmap flags" ),
	FIELD( _field_word_integer, "bitmap filter mode" ),
	FIELD( _field_word_integer, "bitmap address mode" ),
	FIELD( _field_word_integer, "bitmap address mode x" ),
	FIELD( _field_word_integer, "bitmap address mode y" ),
	FIELD( _field_word_integer, "bitmap sharpen mode" ),
	FIELD( _field_byte_integer, "bitmap extern mode" ),
	FIELD( _field_byte_integer, "bitmap min mipmap" ),
	FIELD( _field_byte_integer, "bitmap max mipmap" ),
	FIELD( _field_byte_integer, "render phases used" ),
	FIELD( _field_block, "function parameters", &material_shader_function_parameter_block ),
	FIELD( _field_data, "display name*" ),
	FIELD( _field_data, "display group*" ),
	FIELD( _field_data, "display help text*" ),
	FIELD( _field_real, "display minimum" ),
	FIELD( _field_real, "display maximum" ),
	FIELD( _field_byte_integer, "register index*!" ),
	FIELD( _field_byte_integer, "register offset*!" ),
	FIELD( _field_byte_integer, "register count*!" ),
	FIELD( _field_char_enum, "register set*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(material_shader_function_parameter, s_material_shader_parameter::k_max_material_shader_parameters)
{
	FIELD( _field_long_enum, "type^" ),
	FIELD( _field_string_id, "input name" ),
	FIELD( _field_string_id, "range name" ),
	FIELD( _field_char_enum, "Output Modifier!" ),
	FIELD( _field_pad, "BVCG", 3 ),
	FIELD( _field_string_id, "Output Modifier Input!" ),
	FIELD( _field_real, "time period:seconds" ),
	FIELD( _field_explanation, "FUNCTION" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "function" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

