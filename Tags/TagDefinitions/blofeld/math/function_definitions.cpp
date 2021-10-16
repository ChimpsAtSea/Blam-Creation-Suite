#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		curve_scalar_group,
		CURVE_SCALAR_TAG,
		nullptr,
		INVALID_TAG,
		curve_scalar_block );

	TAG_BLOCK_FROM_STRUCT(
		curve_scalar_block,
		"curve_scalar_block",
		1,
		curve_scalar_struct_definition);

	#define CURVE_SCALAR_STRUCT_DEFINITION_ID { 0x0BB7E6B9, 0xE5B84B69, 0x88CAC7CC, 0xC7238AB4 }
	TAG_STRUCT_V6(
		curve_scalar_struct_definition,
		"curve_scalar_struct_definition",
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CURVE_SCALAR_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "function", &scalar_function_named_struct_default_one },
		{ _field_terminator }
	};

	#define MAPPING_FUNCTION_ID { 0x5A14A98F, 0x53FA4484, 0x801068D4, 0x0AF1459E }
	TAG_STRUCT_V6(
		mapping_function,
		"mapping_function",
		"mapping_function",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MAPPING_FUNCTION_ID)
	{
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_begin),
		{ _field_data, "data" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_end),
		{ _field_terminator }
	};

	#define SCALAR_FUNCTION_NAMED_STRUCT_DEFAULT_ONE_ID { 0x384EBA00, 0x2AA94534, 0xAD11D043, 0x4A23EF26 }
	TAG_STRUCT_V6(
		scalar_function_named_struct_default_one,
		"scalar_function_named_struct_default_one",
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCALAR_FUNCTION_NAMED_STRUCT_DEFAULT_ONE_ID)
	{
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "function", &mapping_function_default_one },
		{ _field_terminator }
	};

	#define MAPPING_FUNCTION_DEFAULT_ONE_ID { 0x9019ABA5, 0x4C5A4A1A, 0xAD1AF034, 0x11FDA1AD }
	TAG_STRUCT_V6(
		mapping_function_default_one,
		"mapping_function_default_one",
		"mapping_function_default_one",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MAPPING_FUNCTION_DEFAULT_ONE_ID)
	{
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_begin),
		{ _field_data, "data" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_end),
		{ _field_terminator }
	};

	#define SCALAR_FUNCTION_NAMED_STRUCT_ID { 0x72CB9289, 0x0276481E, 0x9467A351, 0xF56D7C18 }
	TAG_STRUCT_V6(
		scalar_function_named_struct,
		"scalar_function_named_struct",
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCALAR_FUNCTION_NAMED_STRUCT_ID)
	{
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "function", &mapping_function },
		{ _field_terminator }
	};

	#define COLOR_FUNCTION_NAMED_STRUCT_ID { 0xF9547F48, 0x47284440, 0xB0D43E8A, 0xBDD1F5FA }
	TAG_STRUCT_V6(
		color_function_named_struct,
		"color_function_named_struct",
		"c_function_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COLOR_FUNCTION_NAMED_STRUCT_ID)
	{
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "function", &mapping_function },
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

