#pragma once

enum e_game_context_version
{
	_game_context_version_1,
	_game_context_version_2,
	_game_context_version_3,
	_game_context_version_4,
};

e_game_context_version get_game_context_version_from_build(e_build build);