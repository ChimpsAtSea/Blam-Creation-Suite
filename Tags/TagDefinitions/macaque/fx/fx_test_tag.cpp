#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		fx_test_group,
		FX_TEST_TAG,
		nullptr,
		INVALID_TAG,
		fx_test_block );

	TAG_BLOCK_FROM_STRUCT(
		fx_test_block,
		"fx_test_block",
		1,
		fx_test_struct_definition);

	#define FX_PROPERTY_BLOCK_ID { 0xD29AB5E2, 0xC52B48EC, 0x8C23C5A1, 0x73A0916C }
	TAG_BLOCK(
		fx_property_block,
		"fx_property_block",
		s_fx_test::k_max_properties,
		"s_fx_property",
		FX_PROPERTY_BLOCK_ID)
	{
		{ _field_string, "name" },
		{ _field_long_flags, "flags", &fx_property_flags },
		{ _field_long_integer, "scope" },
		{ _field_long_enum, "value type", &fx_property_value_type_enum },
		{ _field_long_string, "expression" },
		{ _field_long_string, "initialize" },
		{ _field_long_string, "update" },
		{ _field_block, "defaults", &fx_property_default_block },
		{ _field_string_id, "default name" },
		{ _field_tag_reference, "reference", &global_bitmap_reference },
		{ _field_char_enum, "filter_mode", &fx_property_bitmap_filter_enum },
		{ _field_char_enum, "address_mode_x", &fx_property_bitmap_address_enum },
		{ _field_char_enum, "address_mode_y", &fx_property_bitmap_address_enum },
		{ _field_char_enum, "mip_bias_mode", &fx_property_bitmap_bias_enum },
		{ _field_struct, "function", &fx_test_scalar_function_struct },
		{ _field_terminator }
	};

	#define FX_PROPERTY_DEFAULT_BLOCK_ID { 0x74DB675C, 0x010B406D, 0xABDD47F2, 0x4CA2C6AC }
	TAG_BLOCK(
		fx_property_default_block,
		"fx_property_default_block",
		s_fx_test::k_max_defaults,
		"s_fx_property::s_default",
		FX_PROPERTY_DEFAULT_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	#define FX_TEST_STRUCT_DEFINITION_ID { 0x330D5FF3, 0xA8A94198, 0x8EAB297D, 0x80E7192C }
	TAG_STRUCT(
		fx_test_struct_definition,
		"fx_test_struct_definition",
		"s_fx_test",
		FX_TEST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "properties", &fx_property_block },
		{ _field_terminator }
	};

	#define FX_TEST_SCALAR_FUNCTION_STRUCT_ID { 0x8F9D626F, 0x60834554, 0xA51B20AB, 0x5E9122B2 }
	TAG_STRUCT(
		fx_test_scalar_function_struct,
		"fx_test_scalar_function_struct",
		"s_fx_test_scalar_function",
		FX_TEST_SCALAR_FUNCTION_STRUCT_ID)
	{
		{ _field_string_id, "Input Variable", _field_id_function_input_scalar },
		{ _field_string_id, "Range Variable", _field_id_function_input_range },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_terminator }
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

} // namespace macaque

} // namespace blofeld

