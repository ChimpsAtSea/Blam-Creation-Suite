#pragma once

enum e_game_mode : int
{
	_game_mode_none,

	_game_mode_campaign,
	_game_mode_multiplayer,

	// we assume these
	//_game_mode_map_editor,
	//_game_mode_saved_film,

	_game_mode_survival = 5,

	k_number_of_game_modes,
};

extern const char* game_mode_to_string(e_game_mode game_mode);
extern e_game_mode string_to_game_mode(const char* string);