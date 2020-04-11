#pragma once

enum e_mcc_game_mode : int
{
	_mcc_game_mode_none,
	_mcc_game_mode_campaign,
	_mcc_game_mode_spartan_ops,
	_mcc_game_mode_multiplayer,
	_mcc_game_mode_ui_shell,
	_mcc_game_mode_firefight,
	k_number_of_mcc_game_modes,
};

constexpr const char* mcc_mcc_game_mode_to_string(e_mcc_game_mode game_mode)
{
	switch (game_mode)
	{
	case _mcc_game_mode_none: return "_mcc_game_mode_none";
	case _mcc_game_mode_campaign: return "_mcc_game_mode_campaign";
	case _mcc_game_mode_spartan_ops: return "_mcc_game_mode_spartan_ops";
	case _mcc_game_mode_multiplayer: return "_mcc_game_mode_multiplayer";
	case _mcc_game_mode_ui_shell: return "_mcc_game_mode_ui_shell";
	case _mcc_game_mode_firefight: return "_mcc_game_mode_firefight";
	}
	return nullptr;
}

constexpr const char* mcc_mcc_game_mode_to_local_string(e_mcc_game_mode game_mode)
{
	switch (game_mode)
	{
	case _mcc_game_mode_none: return "None";
	case _mcc_game_mode_campaign: return "Campaign";
	case _mcc_game_mode_spartan_ops: return "Spartan Ops";
	case _mcc_game_mode_multiplayer: return "Multiplayer";
	case _mcc_game_mode_ui_shell: return "UI";
	case _mcc_game_mode_firefight: return "Firefight";
	}
	return nullptr;
}

static inline e_mcc_game_mode string_to_mcc_game_mode(const char* game_mode_string)
{
	for (underlying(e_mcc_game_mode) current_game_mode = 0; current_game_mode < k_number_of_mcc_game_modes; current_game_mode++)
	{
		const char* current_mcc_game_mode_string = mcc_mcc_game_mode_to_string(static_cast<e_mcc_game_mode>(current_game_mode));

		if (strcmp(current_mcc_game_mode_string, game_mode_string) == 0)
		{
			return static_cast<e_mcc_game_mode>(current_game_mode);
		}
	}
	return _mcc_game_mode_none;
}
