#pragma once

enum e_game_options_version
{
	_game_options_version_0,
	_game_options_version_1,
	_game_options_version_2,
	_game_options_version_3,

	k_number_of_game_options_versions
};

e_game_options_version get_game_options_version_from_build(e_build build);