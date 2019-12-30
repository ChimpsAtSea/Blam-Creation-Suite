#pragma once

enum e_game_mode : int
{
	_game_mode_none,
	_game_mode_campaign,
	_game_mode_unknown2,
	_game_mode_multiplayer,
	_game_mode_unknown4,
	_game_mode_survival,
	_game_mode_unknown6,
	_game_mode_unknown7,
	_game_mode_unknown8,

	k_number_of_game_modes,
};

extern const char* game_mode_to_string(e_game_mode game_mode);
extern e_game_mode string_to_game_mode(const char* string);