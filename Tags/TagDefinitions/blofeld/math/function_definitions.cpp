#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(curve_scalar, CURVE_SCALAR_TAG, curve_scalar_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(curve_scalar_block, 1, curve_scalar_struct_definition_struct_definition );

	V5_TAG_STRUCT(mapping_function)
	{
		{ _field_custom },
		{ _field_data, "data" },
		{ _field_custom },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(scalar_function_named_struct_default_one)
	{
		{ _field_custom },
		{ _field_struct, "function", &mapping_function_default_one_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(mapping_function_default_one)
	{
		{ _field_custom },
		{ _field_data, "data" },
		{ _field_custom },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(scalar_function_named_struct)
	{
		{ _field_custom },
		{ _field_struct, "function", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(curve_scalar_struct_definition)
	{
		{ _field_struct, "function", &scalar_function_named_struct_default_one_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(color_function_named_struct)
	{
		{ _field_custom },
		{ _field_struct, "function", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	STRINGS(function_type_enum_definition)
	{
		"identity",
		"constant",
		"transition",
		"periodic",
		"linear",
		"linear key",
		"multi linear key",
		"spline",
		"multi spline",
		"exponent",
		"spline2"
	};
	STRING_LIST(function_type_enum_definition, function_type_enum_definition_strings, _countof(function_type_enum_definition_strings));

	STRINGS(color_graph_type_enum_definition)
	{
		"scalar (intensity)",
		"constant",
		"2-color",
		"3-color",
		"4-color"
	};
	STRING_LIST(color_graph_type_enum_definition, color_graph_type_enum_definition_strings, _countof(color_graph_type_enum_definition_strings));

} // namespace blofeld

