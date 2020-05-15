#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(fx_property, s_fx_test::k_max_properties)
{
	{ _field_string, "name^" },
	{ _field_long_flags, "flags" },
	{ _field_long_integer, "scope" },
	{ _field_long_enum, "value type" },
	{ _field_long_string, "expression" },
	{ _field_long_string, "initialize" },
	{ _field_long_string, "update" },
	{ _field_block, "defaults", &fx_property_default_block },
	{ _field_string_id, "default name" },
	{ _field_tag_reference, "reference" },
	{ _field_char_enum, "filter_mode" },
	{ _field_char_enum, "address_mode_x" },
	{ _field_char_enum, "address_mode_y" },
	{ _field_char_enum, "mip_bias_mode" },
	{ _field_struct, "function" },
	{ _field_terminator },
};

TAG_BLOCK(fx_property_default, s_fx_test::k_max_defaults)
{
	{ _field_string_id, "name^" },
	{ _field_terminator },
};

TAG_GROUP(fx_test, FX_TEST_TAG)
{
	{ _field_block, "properties", &fx_property_block },
	{ _field_terminator },
};

} // namespace blofeld

