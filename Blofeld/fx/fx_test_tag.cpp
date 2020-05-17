#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(fx_property_flags, 3)
	{
		OPTION("predefined"),
		OPTION("state"),
		OPTION("derived"),
	};

	TAG_ENUM(fx_property_value_type_enum, 4)
	{
		OPTION("default"),
		OPTION("expression"),
		OPTION("texture"),
		OPTION("function"),
	};

	TAG_ENUM(fx_property_bitmap_filter_enum, 6)
	{
		OPTION("default"),
		OPTION("point"),
		OPTION("bilinear"),
		OPTION("trilinear"),
		OPTION("anisotropic_2x"),
		OPTION("anisotropic_4x"),
	};

	TAG_ENUM(fx_property_bitmap_address_enum, 5)
	{
		OPTION("default"),
		OPTION("wrap"),
		OPTION("clamp"),
		OPTION("mirror"),
		OPTION("border"),
	};

	TAG_ENUM(fx_property_bitmap_bias_enum, 5)
	{
		OPTION("default"),
		OPTION("bias 0"),
		OPTION("bias 1"),
		OPTION("bias 2"),
		OPTION("bias 3"),
	};

	TAG_GROUP_FROM_BLOCK(fx_test, FX_TEST_TAG, fx_test_block_block );

	TAG_BLOCK_FROM_STRUCT(fx_test_block, 1, fx_test_struct_definition_struct_definition );

	TAG_BLOCK(fx_property_block, s_fx_test::k_max_properties)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_long_flags, "flags", &fx_property_flags ),
		FIELD( _field_long_integer, "scope" ),
		FIELD( _field_long_enum, "value type", &fx_property_value_type_enum ),
		FIELD( _field_long_string, "expression" ),
		FIELD( _field_long_string, "initialize" ),
		FIELD( _field_long_string, "update" ),
		FIELD( _field_block, "defaults", &fx_property_default_block_block ),
		FIELD( _field_string_id, "default name" ),
		FIELD( _field_tag_reference, "reference" ),
		FIELD( _field_char_enum, "filter_mode", &fx_property_bitmap_filter_enum ),
		FIELD( _field_char_enum, "address_mode_x", &fx_property_bitmap_address_enum ),
		FIELD( _field_char_enum, "address_mode_y", &fx_property_bitmap_address_enum ),
		FIELD( _field_char_enum, "mip_bias_mode", &fx_property_bitmap_bias_enum ),
		FIELD( _field_struct, "function", &fx_test_scalar_function_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(fx_property_default_block, s_fx_test::k_max_defaults)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(fx_test_struct_definition)
{
		FIELD( _field_block, "properties", &fx_property_block_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(fx_test_scalar_function_struct)
{
		FIELD( _field_string_id, "Input Variable!" ),
		FIELD( _field_string_id, "Range Variable!" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
};

} // namespace blofeld

