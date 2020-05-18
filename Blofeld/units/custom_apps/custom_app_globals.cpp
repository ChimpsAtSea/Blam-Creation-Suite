#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(custom_app_globals, CUSTOM_APP_GLOBALS_TAG, custom_app_globals_block_block );

	TAG_BLOCK(custom_app_damage_modifier_block, k_maximum_custom_app_damage_modifier_count)
	{
		{ _field_string_id, "damage type^" },
		{ _field_explanation, "damage resistance" },
		{ _field_real, "damage resistance multiplier" },
		{ _field_terminator }
	};

	TAG_BLOCK(custom_app_block, k_maximum_custom_app_count)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "headerText" },
		{ _field_string_id, "helpText" },
		{ _field_string_id, "iconStringId" },
		{ _field_tag_reference, "hud screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_explanation, "Locked flag" },
		{ _field_byte_flags, "flags", &custom_app_flags },
		{ _field_pad, "woooo", 3 },
		{ _field_explanation, "Player Traits" },
		{ _field_block, "player traits", &game_engine_player_traits_block_block },
		{ _field_explanation, "Damage Type Modifiers" },
		{ _field_block, "damage type modifiers", &custom_app_damage_modifier_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(custom_app_globals_block, 1, custom_app_globals_struct_definition_struct_definition );

	TAG_STRUCT(custom_app_globals_struct_definition)
	{
		{ _field_long_integer, "maximum active apps:(-1 = unlimited)" },
		{ _field_explanation, "Update Frequency" },
		{ _field_enum, "custom app update frequency", &custom_app_update_frequencies },
		{ _field_pad, "wahoo", 2 },
		{ _field_block, "custom apps", &custom_app_block_block },
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

} // namespace blofeld

