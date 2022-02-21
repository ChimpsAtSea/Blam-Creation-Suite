#pragma once

#include <blamlib/cseries/cseries.h>

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
	_campaign_difficulty_level_easy = 0,
	_campaign_difficulty_level_normal,
	_campaign_difficulty_level_heroic, // _campaign_difficulty_level_hard
	_campaign_difficulty_level_legendary, // _campaign_difficulty_level_impossible
	k_number_of_campaign_difficulty_levels
};

enum e_game_skulls
{
	_skull_iron,
	_skull_black_eye,
	_skull_tough_luck,
	_skull_catch,
	_skull_fog,
	_skull_famine,
	_skull_thunderstorm,
	_skull_tilt,
	_skull_mythic,
	_skull_assassin,
	_skull_blind,
	_skull_cowbell,
	_skull_birthday_party,
	_skull_daddy,
	_skull_red,
	_skull_yellow,
	_skull_blue,
	k_number_of_game_skulls
};
