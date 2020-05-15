#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(variant_setting_edit_reference, k_maximum_game_setting_blocks)
{
	{ _field_string_id, "name" },
	{ _field_long_enum, "setting category^" },
	{ _field_block, "options", &variant_option_block },
	{ _field_terminator },
};

TAG_BLOCK(variant_option, k_maximum_variant_category_blocks)
{
	{ _field_explanation, "SUB-CATEGORY" },
	{ _field_tag_reference, "sub-category" },
	{ _field_explanation, "PLAYER TRAIT" },
	{ _field_tag_reference, "player trait ui" },
	{ _field_long_enum, "player trait category" },
	{ _field_explanation, "CATEGORY NAME" },
	{ _field_string_id, "category name" },
	{ _field_explanation, "CATEGORY DESCRIPTION" },
	{ _field_string_id, "category description" },
	{ _field_explanation, "VALUE-PAIRS" },
	{ _field_tag_reference, "value pairs" },
	{ _field_terminator },
};

TAG_BLOCK(sandbox_property_allowed_values_reference, k_maximum_sandbox_property_values)
{
	{ _field_string_id, "property name" },
	{ _field_char_enum, "parameter_type" },
	{ _field_pad, "blug", 3 },
	{ _field_block, "allowed values", &text_value_pair_reference_block },
	{ _field_terminator },
};

TAG_BLOCK(text_value_pair_reference, k_maximum_text_value_pairs_per_block)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "grug", 3 },
	{ _field_long_integer, "enumerated value" },
	{ _field_real, "real value" },
	{ _field_string_id, "string_id value" },
	{ _field_string_id, "label string id" },
	{ _field_string_id, "description string id" },
	{ _field_terminator },
};

TAG_GROUP(multiplayer_variant_settings_interface_definition, MULTIPLAYER_VARIANT_SETTINGS_INTERFACE_DEFINITION_TAG)
{
	{ _field_string_id, "name (unused)" },
	{ _field_block, "game engine settings", &variant_setting_edit_reference_block },
	{ _field_terminator },
};

TAG_GROUP(sandbox_text_value_pair_definition, SANDBOX_TEXT_VALUE_PAIR_DEFINITION_TAG)
{
	{ _field_block, "property values", &sandbox_property_allowed_values_reference_block },
	{ _field_terminator },
};

TAG_GROUP(text_value_pair_definition, TEXT_VALUE_PAIR_DEFINITION_TAG)
{
	{ _field_long_enum, "parameter" },
	{ _field_string_id, "name" },
	{ _field_string_id, "description text" },
	{ _field_char_enum, "parameter_type" },
	{ _field_pad, "shrug", 3 },
	{ _field_block, "text value pairs", &text_value_pair_reference_block },
	{ _field_terminator },
};

} // namespace blofeld

