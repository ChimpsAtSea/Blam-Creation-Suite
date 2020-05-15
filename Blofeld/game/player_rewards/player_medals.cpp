#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(gameMedalTiers, GameMedalTierDefinition::k_maximumGameMedalTierDefinitions)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "description" },
	{ _field_short_integer, "sequence index" },
	{ _field_short_integer, "point value" },
	{ _field_terminator },
};

TAG_BLOCK(game_medal, s_game_medal_definition::k_maximum_game_medal_definitions)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "description" },
	{ _field_short_integer, "sequence index" },
	{ _field_char_enum, "medal class" },
	{ _field_pad, "PAD1", 1 },
	{ _field_long_integer, "ordnance points#The number of ordnance points that are awarded to the player when they earn this medal." },
	{ _field_byte_integer, "ordnance multiplier#The ordnance multiplier to add to players ordnance multiplier when they earn this medal." },
	{ _field_byte_integer, "tier index#the tier that this medal belongs to" },
	{ _field_short_integer, "override point value#if greater than zero, this point value will be awarded to players instead of the tier\'s point value" },
	{ _field_terminator },
};

TAG_GROUP(game_medal_globals, GAME_MEDAL_GLOBALS_TAG)
{
	{ _field_block, "tiers", &gameMedalTiers_block },
	{ _field_block, "medals", &game_medal_block },
	{ _field_terminator },
};

} // namespace blofeld

