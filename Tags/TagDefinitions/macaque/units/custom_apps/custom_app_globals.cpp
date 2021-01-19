#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		custom_app_globals_group,
		CUSTOM_APP_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		custom_app_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		custom_app_globals_block,
		"custom_app_globals_block",
		1,
		custom_app_globals_struct_definition);

	#define CUSTOM_APP_BLOCK_ID { 0x3E548E96, 0xE9C04229, 0xB3D38DCF, 0xEED8E942 }
	TAG_BLOCK(
		custom_app_block,
		"custom_app_block",
		k_maximum_custom_app_count,
		"s_custom_app_definition",
		CUSTOM_APP_BLOCK_ID)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "headerText" },
		{ _field_string_id, "helpText" },
		{ _field_string_id, "iconStringId" },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_explanation, "Locked flag", "If you lock an app that you currently have installed and then XSync, the game may assert.  If so, relaunch and you\'ll be fine.  It\'s nothing to worry about." },
		{ _field_byte_flags, "flags", &custom_app_flags },
		{ _field_pad, "woooo", 3 },
		{ _field_explanation, "Player Traits", "Player traits that are applied to the player when they have this app." },
		{ _field_block, "player traits", &game_engine_player_traits_block },
		{ _field_explanation, "Damage Type Modifiers", "Damage modifiers per damage type." },
		{ _field_block, "damage type modifiers", &custom_app_damage_modifier_block },
		{ _field_terminator }
	};

	#define CUSTOM_APP_DAMAGE_MODIFIER_BLOCK_ID { 0xE8032A12, 0xD5E44CB0, 0x9AEEFD83, 0xFB0999D4 }
	TAG_BLOCK(
		custom_app_damage_modifier_block,
		"custom_app_damage_modifier_block",
		k_maximum_custom_app_damage_modifier_count,
		"s_custom_app_damage_modifier_definition",
		CUSTOM_APP_DAMAGE_MODIFIER_BLOCK_ID)
	{
		{ _field_string_id, "damage type^" },
		{ _field_explanation, "damage resistance", "Any damage taken is divided by this number.  If you put -1, that means \"invulnerable\"." },
		{ _field_real, "damage resistance multiplier" },
		{ _field_terminator }
	};

	#define CUSTOM_APP_GLOBALS_STRUCT_DEFINITION_ID { 0x9C8EE695, 0x95D442FD, 0xAE8AADB4, 0x368822CA }
	TAG_STRUCT(
		custom_app_globals_struct_definition,
		"custom_app_globals_struct_definition",
		"s_custom_app_globals_definition",
		CUSTOM_APP_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "maximum active apps:(-1 = unlimited)" },
		{ _field_explanation, "Update Frequency", "The players can enter the Custom App menu at any time during a game and change their apps.  This enum determines when those changes take effect, in terms of gameplay effects." },
		{ _field_enum, "custom app update frequency", &custom_app_update_frequencies },
		{ _field_pad, "wahoo", 2 },
		{ _field_block, "custom apps", &custom_app_block },
		{ _field_terminator }
	};

	STRINGS(custom_app_flags$2)
	{
		"locked (cannot be used ever by anyone)"
	};
	STRING_LIST(custom_app_flags$2, custom_app_flags$2_strings, _countof(custom_app_flags$2_strings));

	STRINGS(custom_app_update_frequencies)
	{
		"update instantly#not supported",
		"update on respawn",
		"update on game start"
	};
	STRING_LIST(custom_app_update_frequencies, custom_app_update_frequencies_strings, _countof(custom_app_update_frequencies_strings));

	TAG_REFERENCE(global_custom_app_globals_reference, CUSTOM_APP_GLOBALS_TAG);

} // namespace macaque

} // namespace blofeld

