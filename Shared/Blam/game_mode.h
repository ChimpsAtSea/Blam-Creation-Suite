#pragma once

enum e_game_mode : int
{
	_game_mode_none,
	_game_mode_campaign,
	_game_mode_spartan_ops,
	_game_mode_multiplayer,
	_game_mode_ui_shell,
	_game_mode_firefight,
	k_number_of_game_modes,
};

constexpr const char* game_mode_to_string(e_game_mode game_mode)
{
	switch (game_mode)
	{
	case _game_mode_none: return "_game_mode_none";
	case _game_mode_campaign: return "_game_mode_campaign";
	case _game_mode_spartan_ops: return "_game_mode_spartan_ops";
	case _game_mode_multiplayer: return "_game_mode_multiplayer";
	case _game_mode_ui_shell: return "_game_mode_ui_shell";
	case _game_mode_firefight: return "_game_mode_firefight";
	}
	return nullptr;
}

constexpr const char* game_mode_to_local_string(e_game_mode game_mode)
{
	switch (game_mode)
	{
	case _game_mode_none: return "None";
	case _game_mode_campaign: return "Campaign";
	case _game_mode_spartan_ops: return "Spartan Ops";
	case _game_mode_multiplayer: return "Multiplayer";
	case _game_mode_ui_shell: return "UI";
	case _game_mode_firefight: return "Firefight";
	}
	return nullptr;
}

static inline e_game_mode string_to_game_mode(const char* game_mode_string)
{
	for (underlying(e_game_mode) current_game_mode = 0; current_game_mode < k_number_of_game_modes; current_game_mode++)
	{
		const char* current_game_mode_string = game_mode_to_string(static_cast<e_game_mode>(current_game_mode));

		if (strcmp(current_game_mode_string, game_mode_string) == 0)
		{
			return static_cast<e_game_mode>(current_game_mode);
		}
	}
	return _game_mode_none;
}
