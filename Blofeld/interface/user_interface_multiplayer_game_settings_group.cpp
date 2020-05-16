#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(multiplayer_variant_settings_interface_definition, MULTIPLAYER_VARIANT_SETTINGS_INTERFACE_DEFINITION_TAG, multiplayer_variant_settings_interface_definition_block_block )

TAG_GROUP_FROM_BLOCK(sandbox_text_value_pair_definition, SANDBOX_TEXT_VALUE_PAIR_DEFINITION_TAG, sandbox_text_value_pair_definition_block_block )

TAG_GROUP_FROM_BLOCK(text_value_pair_definition, TEXT_VALUE_PAIR_DEFINITION_TAG, text_value_pair_definition_block_block )

TAG_BLOCK_FROM_STRUCT(multiplayer_variant_settings_interface_definition_block, 1, multiplayer_variant_settings_interface_definition_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(sandbox_text_value_pair_definition_block, 1, sandbox_text_value_pair_definition_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(text_value_pair_definition_block, 1, text_value_pair_definition_struct_definition_struct_definition );

TAG_BLOCK(variant_setting_edit_reference_block, k_maximum_game_setting_blocks)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_long_enum, "setting category^" ),
	FIELD( _field_block, "options", &variant_option_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(variant_option_block, k_maximum_variant_category_blocks)
{
	FIELD( _field_explanation, "SUB-CATEGORY" ),
	FIELD( _field_tag_reference, "sub-category" ),
	FIELD( _field_explanation, "PLAYER TRAIT" ),
	FIELD( _field_tag_reference, "player trait ui" ),
	FIELD( _field_long_enum, "player trait category" ),
	FIELD( _field_explanation, "CATEGORY NAME" ),
	FIELD( _field_string_id, "category name" ),
	FIELD( _field_explanation, "CATEGORY DESCRIPTION" ),
	FIELD( _field_string_id, "category description" ),
	FIELD( _field_explanation, "VALUE-PAIRS" ),
	FIELD( _field_tag_reference, "value pairs" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sandbox_property_allowed_values_reference_block, k_maximum_sandbox_property_values)
{
	FIELD( _field_string_id, "property name" ),
	FIELD( _field_char_enum, "parameter_type" ),
	FIELD( _field_pad, "blug", 3 ),
	FIELD( _field_block, "allowed values", &text_value_pair_reference_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(text_value_pair_reference_block, k_maximum_text_value_pairs_per_block)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "grug", 3 ),
	FIELD( _field_long_integer, "enumerated value" ),
	FIELD( _field_real, "real value" ),
	FIELD( _field_string_id, "string_id value" ),
	FIELD( _field_string_id, "label string id" ),
	FIELD( _field_string_id, "description string id" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(multiplayer_variant_settings_interface_definition_struct_definition)
{
	FIELD( _field_string_id, "name (unused)" ),
	FIELD( _field_block, "game engine settings", &variant_setting_edit_reference_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sandbox_text_value_pair_definition_struct_definition)
{
	FIELD( _field_block, "property values", &sandbox_property_allowed_values_reference_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(text_value_pair_definition_struct_definition)
{
	FIELD( _field_long_enum, "parameter" ),
	FIELD( _field_string_id, "name" ),
	FIELD( _field_string_id, "description text" ),
	FIELD( _field_char_enum, "parameter_type" ),
	FIELD( _field_pad, "shrug", 3 ),
	FIELD( _field_block, "text value pairs", &text_value_pair_reference_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

