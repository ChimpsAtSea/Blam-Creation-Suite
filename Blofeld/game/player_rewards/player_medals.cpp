#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(game_medal_globals_struct_definition)
{
	FIELD( _field_block, "tiers", &gameMedalTiers ),
	FIELD( _field_block, "medals", &game_medal_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gameMedalTiers, GameMedalTierDefinition::k_maximumGameMedalTierDefinitions)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "description" ),
	FIELD( _field_short_integer, "sequence index" ),
	FIELD( _field_short_integer, "point value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(game_medal_block, s_game_medal_definition::k_maximum_game_medal_definitions)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "description" ),
	FIELD( _field_short_integer, "sequence index" ),
	FIELD( _field_char_enum, "medal class" ),
	FIELD( _field_pad, "PAD1", 1 ),
	FIELD( _field_long_integer, "ordnance points#The number of ordnance points that are awarded to the player when they earn this medal." ),
	FIELD( _field_byte_integer, "ordnance multiplier#The ordnance multiplier to add to players ordnance multiplier when they earn this medal." ),
	FIELD( _field_byte_integer, "tier index#the tier that this medal belongs to" ),
	FIELD( _field_short_integer, "override point value#if greater than zero, this point value will be awarded to players instead of the tier\'s point value" ),
	FIELD( _field_terminator )
};

TAG_GROUP(game_medal_globals_block, GAME_MEDAL_GLOBALS_TAG)
{
	FIELD( _field_block, "tiers", &gameMedalTiers ),
	FIELD( _field_block, "medals", &game_medal_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

