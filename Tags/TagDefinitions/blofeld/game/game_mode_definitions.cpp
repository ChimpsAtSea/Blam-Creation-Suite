#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define GAME_MODE_FLAGS_STRUCT_ID { 0xA7F78373, 0x6E914D1A, 0xA0806AF6, 0xFDC24EA0 }
	TAG_STRUCT(
		game_mode_flags_struct,
		"game_mode_flags_struct",
		"s_game_mode_flags",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GAME_MODE_FLAGS_STRUCT_ID)
	{
		{ _field_byte_flags, "game mode", &game_type_enum_definition },
		{ _field_byte_flags, "matchmaking type", &game_matchmaking_flags_definition },
		{ _field_byte_flags, "difficulty", &global_campaign_difficulty_flags },
		{ _field_char_enum, "player count", &game_player_count_flags_definition },
		{ _field_terminator }
	};

	STRINGS(game_type_enum_definition)
	{
		"campaign",
		"firefight",
		"multiplayer"
	};
	STRING_LIST(game_type_enum_definition, game_type_enum_definition_strings, _countof(game_type_enum_definition_strings));

	STRINGS(game_matchmaking_flags_definition)
	{
		"custom game",
		"matchmaking"
	};
	STRING_LIST(game_matchmaking_flags_definition, game_matchmaking_flags_definition_strings, _countof(game_matchmaking_flags_definition_strings));

	STRINGS(game_player_count_flags_definition)
	{
		"any",
		"1 player only",
		"4 players only",
		"more than one player"
	};
	STRING_LIST(game_player_count_flags_definition, game_player_count_flags_definition_strings, _countof(game_player_count_flags_definition_strings));



} // namespace blofeld

