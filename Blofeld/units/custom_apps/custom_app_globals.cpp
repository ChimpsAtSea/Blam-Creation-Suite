#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(custom_app, k_maximum_custom_app_count)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "headerText" },
	{ _field_string_id, "helpText" },
	{ _field_string_id, "iconStringId" },
	{ _field_tag_reference, "hud screen reference" },
	{ _field_explanation, "Locked flag" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "woooo", 3 },
	{ _field_explanation, "Player Traits" },
	{ _field_block, "player traits", &game_engine_player_traits_block },
	{ _field_explanation, "Damage Type Modifiers" },
	{ _field_block, "damage type modifiers", &custom_app_damage_modifier_block },
	{ _field_terminator },
};

TAG_BLOCK(custom_app_damage_modifier, k_maximum_custom_app_damage_modifier_count)
{
	{ _field_string_id, "damage type^" },
	{ _field_explanation, "damage resistance" },
	{ _field_real, "damage resistance multiplier" },
	{ _field_terminator },
};

TAG_GROUP(custom_app_globals, CUSTOM_APP_GLOBALS_TAG)
{
	{ _field_long_integer, "maximum active apps:(-1 = unlimited)" },
	{ _field_explanation, "Update Frequency" },
	{ _field_enum, "custom app update frequency" },
	{ _field_pad, "wahoo", 2 },
	{ _field_block, "custom apps", &custom_app_block },
	{ _field_terminator },
};

} // namespace blofeld

