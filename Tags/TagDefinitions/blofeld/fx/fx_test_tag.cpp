#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(fx_test, FX_TEST_TAG, fx_test_block_block );

	V5_TAG_BLOCK(fx_property_default_block, s_fx_test::k_max_defaults)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(fx_property_block, s_fx_test::k_max_properties)
	{
		{ _field_legacy, _field_string, "name^" },
		{ _field_legacy, _field_long_flags, "flags", &fx_property_flags },
		{ _field_legacy, _field_long_integer, "scope" },
		{ _field_legacy, _field_long_enum, "value type", &fx_property_value_type_enum },
		{ _field_legacy, _field_long_string, "expression" },
		{ _field_legacy, _field_long_string, "initialize" },
		{ _field_legacy, _field_long_string, "update" },
		{ _field_legacy, _field_block, "defaults", &fx_property_default_block_block },
		{ _field_legacy, _field_string_id, "default name" },
		{ _field_legacy, _field_tag_reference, "reference", &global_bitmap_reference },
		{ _field_legacy, _field_char_enum, "filter_mode", &fx_property_bitmap_filter_enum },
		{ _field_legacy, _field_char_enum, "address_mode_x", &fx_property_bitmap_address_enum },
		{ _field_legacy, _field_char_enum, "address_mode_y", &fx_property_bitmap_address_enum },
		{ _field_legacy, _field_char_enum, "mip_bias_mode", &fx_property_bitmap_bias_enum },
		{ _field_legacy, _field_struct, "function", &fx_test_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(fx_test_block, 1, fx_test_struct_definition_struct_definition );

	V5_TAG_STRUCT(fx_test_struct_definition)
	{
		{ _field_legacy, _field_block, "properties", &fx_property_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(fx_test_scalar_function_struct)
	{
		{ _field_legacy, _field_string_id, "Input Variable!" },
		{ _field_legacy, _field_string_id, "Range Variable!" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(fx_property_flags)
	{
		"predefined",
		"state",
		"derived"
	};
	STRING_LIST(fx_property_flags, fx_property_flags_strings, _countof(fx_property_flags_strings));

	STRINGS(fx_property_value_type_enum)
	{
		"default",
		"expression",
		"texture",
		"function"
	};
	STRING_LIST(fx_property_value_type_enum, fx_property_value_type_enum_strings, _countof(fx_property_value_type_enum_strings));

	STRINGS(fx_property_bitmap_filter_enum)
	{
		"default",
		"point",
		"bilinear",
		"trilinear",
		"anisotropic_2x",
		"anisotropic_4x"
	};
	STRING_LIST(fx_property_bitmap_filter_enum, fx_property_bitmap_filter_enum_strings, _countof(fx_property_bitmap_filter_enum_strings));

	STRINGS(fx_property_bitmap_address_enum)
	{
		"default",
		"wrap",
		"clamp",
		"mirror",
		"border"
	};
	STRING_LIST(fx_property_bitmap_address_enum, fx_property_bitmap_address_enum_strings, _countof(fx_property_bitmap_address_enum_strings));

	STRINGS(fx_property_bitmap_bias_enum)
	{
		"default",
		"bias 0",
		"bias 1",
		"bias 2",
		"bias 3"
	};
	STRING_LIST(fx_property_bitmap_bias_enum, fx_property_bitmap_bias_enum_strings, _countof(fx_property_bitmap_bias_enum_strings));

} // namespace blofeld

