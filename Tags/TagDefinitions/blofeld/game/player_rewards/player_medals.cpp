#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(game_medal_globals, GAME_MEDAL_GLOBALS_TAG, game_medal_globals_block_block );

	V5_TAG_BLOCK(gameMedalTiers, GameMedalTierDefinition::k_maximumGameMedalTierDefinitions)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "description" },
		{ _field_short_integer, "sequence index" },
		{ _field_short_integer, "point value" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(game_medal_block, s_game_medal_definition::k_maximum_game_medal_definitions)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "description" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 8 },
		{ _field_real, "scale x" },
		{ _field_real, "scale y" },
		{ _field_char_integer, "sequence index" },
		{ _field_char_enum, "medal class", &medal_class_enum },
		{ _field_byte_integer, "tier index#the tier that this medal belongs to" },
		{ _field_pad, "PAD1", 1 },
		{ _field_short_integer, "override point value#if greater than zero, this point value will be awarded to players instead of the tier\'s point value" },
		{ _field_pad, "PAD1", 2 },

		{ _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_short_integer, "sequence index" },
		{ _field_char_enum, "medal class", &medal_class_enum },
		{ _field_pad, "PAD1", 1 },
		{ _field_long_integer, "ordnance points#The number of ordnance points that are awarded to the player when they earn this medal." },
		{ _field_byte_integer, "ordnance multiplier#The ordnance multiplier to add to players ordnance multiplier when they earn this medal." },
		{ _field_byte_integer, "tier index#the tier that this medal belongs to" },
		{ _field_short_integer, "override point value#if greater than zero, this point value will be awarded to players instead of the tier\'s point value" },

		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(game_medal_globals_block, 1, game_medal_globals_struct_definition_struct_definition );

	V5_TAG_STRUCT(game_medal_globals_struct_definition)
	{
		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "tiers", &gameMedalTiers_block },
		{ _field_block, "medals", &game_medal_block_block },
		{ _field_terminator }
	};

	STRINGS(medal_class_enum)
	{
		"special",
		"role spree",
		"spree",
		"multikill",
		"objectives",
		"circumstance",
		"finesse"
	};
	STRING_LIST(medal_class_enum, medal_class_enum_strings, _countof(medal_class_enum_strings));

} // namespace blofeld

