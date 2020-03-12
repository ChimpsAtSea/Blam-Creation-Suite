#pragma once

#include <cseries/cseries.h>

/* ---------- types */

enum e_game_mode
{
	_game_mode_none = NONE,
	_game_mode_campaign,
	_game_mode_survival,
	_game_mode_multiplayer,
	k_number_of_game_modes
};

enum e_campaign_difficulty_level
{
	_campaign_difficulty_level_easy,
	_campaign_difficulty_level_normal,
	_campaign_difficulty_level_heroic,
	_campaign_difficulty_level_legendary,
	k_number_of_campaign_difficulty_levels
};
