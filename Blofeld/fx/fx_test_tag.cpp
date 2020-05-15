#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(fx_property, s_fx_test::k_max_properties)
{
	FIELD( _field_string, "name^" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_integer, "scope" ),
	FIELD( _field_long_enum, "value type" ),
	FIELD( _field_long_string, "expression" ),
	FIELD( _field_long_string, "initialize" ),
	FIELD( _field_long_string, "update" ),
	FIELD( _field_block, "defaults", &fx_property_default_block ),
	FIELD( _field_string_id, "default name" ),
	FIELD( _field_tag_reference, "reference" ),
	FIELD( _field_char_enum, "filter_mode" ),
	FIELD( _field_char_enum, "address_mode_x" ),
	FIELD( _field_char_enum, "address_mode_y" ),
	FIELD( _field_char_enum, "mip_bias_mode" ),
	FIELD( _field_struct, "function" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(fx_property_default, s_fx_test::k_max_defaults)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(fx_test, FX_TEST_TAG)
{
	FIELD( _field_block, "properties", &fx_property_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

