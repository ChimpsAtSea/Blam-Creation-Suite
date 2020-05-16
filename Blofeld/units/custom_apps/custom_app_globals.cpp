#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(custom_app_globals_struct_definition)
{
	FIELD( _field_long_integer, "maximum active apps:(-1 = unlimited)" ),
	FIELD( _field_explanation, "Update Frequency" ),
	FIELD( _field_enum, "custom app update frequency" ),
	FIELD( _field_pad, "wahoo", 2 ),
	FIELD( _field_block, "custom apps", &custom_app_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(custom_app_block, k_maximum_custom_app_count)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "headerText" ),
	FIELD( _field_string_id, "helpText" ),
	FIELD( _field_string_id, "iconStringId" ),
	FIELD( _field_tag_reference, "hud screen reference" ),
	FIELD( _field_explanation, "Locked flag" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "woooo", 3 ),
	FIELD( _field_explanation, "Player Traits" ),
	FIELD( _field_block, "player traits", &game_engine_player_traits_block ),
	FIELD( _field_explanation, "Damage Type Modifiers" ),
	FIELD( _field_block, "damage type modifiers", &custom_app_damage_modifier_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(custom_app_damage_modifier_block, k_maximum_custom_app_damage_modifier_count)
{
	FIELD( _field_string_id, "damage type^" ),
	FIELD( _field_explanation, "damage resistance" ),
	FIELD( _field_real, "damage resistance multiplier" ),
	FIELD( _field_terminator )
};

TAG_GROUP(custom_app_globals_block, CUSTOM_APP_GLOBALS_TAG)
{
	FIELD( _field_long_integer, "maximum active apps:(-1 = unlimited)" ),
	FIELD( _field_explanation, "Update Frequency" ),
	FIELD( _field_enum, "custom app update frequency" ),
	FIELD( _field_pad, "wahoo", 2 ),
	FIELD( _field_block, "custom apps", &custom_app_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

