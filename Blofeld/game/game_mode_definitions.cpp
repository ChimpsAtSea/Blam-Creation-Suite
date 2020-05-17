#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(game_type_enum_definition, 3)
	{
		OPTION("campaign"),
		OPTION("firefight"),
		OPTION("multiplayer"),
	};

	TAG_ENUM(game_matchmaking_flags_definition, 2)
	{
		OPTION("custom game"),
		OPTION("matchmaking"),
	};

	TAG_ENUM(game_player_count_flags_definition, 4)
	{
		OPTION("any"),
		OPTION("1 player only"),
		OPTION("4 players only"),
		OPTION("more than one player"),
	};

TAG_STRUCT(game_mode_flags_struct)
{
		FIELD( _field_byte_flags, "game mode", &game_type_enum_definition ),
		FIELD( _field_byte_flags, "matchmaking type", &game_matchmaking_flags_definition ),
		FIELD( _field_byte_flags, "difficulty", &global_campaign_difficulty_flags ),
		FIELD( _field_char_enum, "player count", &game_player_count_flags_definition ),
		FIELD( _field_terminator )
};

} // namespace blofeld

