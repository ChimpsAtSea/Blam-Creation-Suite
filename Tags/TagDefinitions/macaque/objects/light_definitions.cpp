#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		light_group,
		LIGHT_TAG,
		nullptr,
		INVALID_TAG,
		light_block );

	TAG_BLOCK_FROM_STRUCT(
		light_block,
		"light_block",
		1,
		light_struct_definition);

	#define LIGHT_STRUCT_DEFINITION_ID { 0x671EB9F2, 0xB6AF482D, 0x902D0F25, 0xEDB665A1 }
	TAG_STRUCT(
		light_struct_definition,
		"light_struct_definition",
		"dynamic_light_definition",
		LIGHT_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct },
		{ _field_terminator }
	};

	#define LIGHT_COLOR_FUNCTION_STRUCT_ID { 0x3DBB8F1A, 0x54F94FD0, 0x9D24DA91, 0x297A3078 }
	TAG_STRUCT(
		light_color_function_struct,
		"light_color_function_struct",
		"light_function",
		LIGHT_COLOR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable!", nullptr, 'fnin' },
		{ _field_string_id, "Range Variable!", nullptr, 'fnir' },
		{ _field_enum, "Output Modifier!", &output_mod_enum },
		{ _field_pad, "BVCG", 2 },
		{ _field_string_id, "Output Modifier Input!", nullptr, 'fnom' },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	#define LIGHT_SCALAR_FUNCTION_STRUCT_ID { 0x26AA4A83, 0x42B4434A, 0x93ACA3CB, 0x08A920CD }
	TAG_STRUCT(
		light_scalar_function_struct,
		"light_scalar_function_struct",
		"light_function",
		LIGHT_SCALAR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable!", nullptr, 'fnin' },
		{ _field_string_id, "Range Variable!", nullptr, 'fnir' },
		{ _field_enum, "Output Modifier!", &output_mod_enum },
		{ _field_pad, "BVCG", 2 },
		{ _field_string_id, "Output Modifier Input!", nullptr, 'fnom' },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
	};

	STRINGS(output_mod_enum$4)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum$4, output_mod_enum$4_strings, _countof(output_mod_enum$4_strings));

} // namespace macaque

} // namespace blofeld

