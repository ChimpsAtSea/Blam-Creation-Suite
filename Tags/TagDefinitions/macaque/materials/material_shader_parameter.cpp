#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MATERIAL_SHADER_PARAMETER_BLOCK_ID { 0x5E4B3E06, 0x18A84736, 0xBECF963F, 0x42CAD69D }
	TAG_BLOCK(
		material_shader_parameter_block,
		"material_shader_parameter_block",
		s_material_shader_parameter::k_max_material_shader_parameters,
		"s_material_shader_parameter",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_SHADER_PARAMETER_BLOCK_ID)
	{
		{ _field_string_id, "parameter name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_long_enum, "parameter type", FIELD_FLAG_READ_ONLY, &material_shader_parameter_type_enum },
		{ _field_long_integer, "parameter index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_tag_reference, "bitmap", &bitmap_reference$7 },
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
		{ _field_data, "display name", FIELD_FLAG_READ_ONLY },
		{ _field_data, "display group", FIELD_FLAG_READ_ONLY },
		{ _field_data, "display help text", FIELD_FLAG_READ_ONLY },
		{ _field_real, "display minimum" },
		{ _field_real, "display maximum" },
		{ _field_byte_integer, "register index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "register offset", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_byte_integer, "register count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_enum, "register set", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &register_set_enum },
		{ _field_terminator }
	};

	#define MATERIAL_SHADER_FUNCTION_PARAMETER_BLOCK_ID { 0x5471F0E3, 0xF54D4472, 0xAD55A516, 0x9A007BED }
	TAG_BLOCK(
		material_shader_function_parameter_block,
		"material_shader_function_parameter_block",
		s_material_shader_parameter::k_max_material_shader_parameters,
		"s_material_shader_function_parameter",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_SHADER_FUNCTION_PARAMETER_BLOCK_ID)
	{
		{ _field_long_enum, "type", FIELD_FLAG_INDEX, &material_animated_parameter_type_enum },
		{ _field_string_id, "input name", _field_id_function_input_scalar },
		{ _field_string_id, "range name", _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", FIELD_FLAG_UNKNOWN0, &materialFunctionOutputModEnum, _field_id_fnop },
		FIELD_PAD("BVCG", nullptr, 3),
		{ _field_string_id, "Output Modifier Input", FIELD_FLAG_UNKNOWN0, _field_id_function_output_modifier },
		{ _field_real, "time period", nullptr, "seconds", _field_id_function_unknown },
		FIELD_EXPLANATION("FUNCTION", nullptr, ""),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_default),
		{ _field_struct, "function", &mapping_function },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

