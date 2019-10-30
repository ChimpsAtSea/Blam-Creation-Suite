#include "haloshared-private-pch.h"

const char* game_mode_to_string(e_game_mode game_mode)
{
	switch (game_mode)
	{
	case _game_mode_none:
		return "none";
	case _game_mode_campaign:
		return "campaign";
	case _game_mode_multiplayer:
		return "multiplayer";
	case _game_mode_survival:
		return "survival";
	}
	return nullptr;
}

e_game_mode string_to_game_mode(const char* string)
{
	for (int i = _game_mode_none; i < k_number_of_game_modes; i++)
	{
		e_game_mode game_mode = static_cast<e_game_mode>(i);
		const char *game_mode_str = game_mode_to_string(game_mode);

		if (game_mode_str != nullptr && (strcmp(string, game_mode_str) == 0))
		{
			return game_mode;
		}
	}
	return _game_mode_none;
}