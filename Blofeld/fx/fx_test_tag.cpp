#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(fx_test, FX_TEST_TAG, fx_test_block_block );

TAG_BLOCK_FROM_STRUCT(fx_test_block, 1, fx_test_struct_definition_struct_definition );

TAG_BLOCK(fx_property_block, s_fx_test::k_max_properties)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_integer, "scope" ),
	FIELD( _field_long_enum, "value type" ),
	FIELD( _field_long_string, "expression" ),
	FIELD( _field_long_string, "initialize" ),
	FIELD( _field_long_string, "update" ),
	FIELD( _field_block, "defaults", &fx_property_default_block_block ),
	FIELD( _field_string_id, "default name" ),
	FIELD( _field_tag_reference, "reference" ),
	FIELD( _field_char_enum, "filter_mode" ),
	FIELD( _field_char_enum, "address_mode_x" ),
	FIELD( _field_char_enum, "address_mode_y" ),
	FIELD( _field_char_enum, "mip_bias_mode" ),
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

