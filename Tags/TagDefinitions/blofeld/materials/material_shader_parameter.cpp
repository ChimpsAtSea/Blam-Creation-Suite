#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(material_shader_function_parameter_block, s_material_shader_parameter::k_max_material_shader_parameters)
	{
		{ _field_legacy, _field_long_enum, "type^", &material_animated_parameter_type_enum },
		{ _field_legacy, _field_string_id, "input name" },
		{ _field_legacy, _field_string_id, "range name" },
		{ _field_legacy, _field_char_enum, "Output Modifier!", &materialFunctionOutputModEnum },
		{ _field_legacy, _field_pad, "BVCG", 3 },
		{ _field_legacy, _field_string_id, "Output Modifier Input!" },
		{ _field_legacy, _field_real, "time period:seconds" },
		{ _field_legacy, _field_explanation, "FUNCTION", "" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "function", &mapping_function_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(material_shader_parameter_block, s_material_shader_parameter::k_max_material_shader_parameters)
	{
		{ _field_legacy, _field_string_id, "parameter name^*" },
		{ _field_legacy, _field_long_enum, "parameter type*", &material_shader_parameter_type_enum },
		{ _field_legacy, _field_long_integer, "parameter index*!" },
		{ _field_legacy, _field_tag_reference, "bitmap", &bitmap_reference$7 },
		{ _field_legacy, _field_string_id, "bitmap path" },
		{ _field_legacy, _field_real_argb_color, "color" },
		{ _field_legacy, _field_real, "real" },
		{ _field_legacy, _field_real_vector_3d, "vector" },
		{ _field_legacy, _field_long_integer, "int/bool" },
		{ _field_legacy, _field_word_integer, "bitmap flags" },
		{ _field_legacy, _field_word_integer, "bitmap filter mode" },
		{ _field_legacy, _field_word_integer, "bitmap address mode" },
		{ _field_legacy, _field_word_integer, "bitmap address mode x" },
		{ _field_legacy, _field_word_integer, "bitmap address mode y" },
		{ _field_legacy, _field_word_integer, "bitmap sharpen mode" },
		{ _field_legacy, _field_byte_integer, "bitmap extern mode" },
		{ _field_legacy, _field_byte_integer, "bitmap min mipmap" },
		{ _field_legacy, _field_byte_integer, "bitmap max mipmap" },
		{ _field_legacy, _field_byte_integer, "render phases used" },
		{ _field_legacy, _field_block, "function parameters", &material_shader_function_parameter_block_block },
		{ _field_legacy, _field_data, "display name*" },
		{ _field_legacy, _field_data, "display group*" },
		{ _field_legacy, _field_data, "display help text*" },
		{ _field_legacy, _field_real, "display minimum" },
		{ _field_legacy, _field_real, "display maximum" },
		{ _field_legacy, _field_byte_integer, "register index*!" },
		{ _field_legacy, _field_byte_integer, "register offset*!" },
		{ _field_legacy, _field_byte_integer, "register count*!" },
		{ _field_legacy, _field_char_enum, "register set*!", &register_set_enum },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(material_shader_parameter_type_enum)
	{
		"bitmap",
		"real",
		"int",
		"bool",
		"color"
	};
	STRING_LIST(material_shader_parameter_type_enum, material_shader_parameter_type_enum_strings, _countof(material_shader_parameter_type_enum_strings));

	STRINGS(material_animated_parameter_type_enum)
	{
		"value",
		"color",
		"scale uniform",
		"scale u",
		"scale v",
		"offset u",
		"offset v",
		"frame index",
		"alpha"
	};
	STRING_LIST(material_animated_parameter_type_enum, material_animated_parameter_type_enum_strings, _countof(material_animated_parameter_type_enum_strings));

	STRINGS(materialFunctionOutputModEnum)
	{
		" ",
		"Add",
		"Multiply"
	};
	STRING_LIST(materialFunctionOutputModEnum, materialFunctionOutputModEnum_strings, _countof(materialFunctionOutputModEnum_strings));

} // namespace blofeld

