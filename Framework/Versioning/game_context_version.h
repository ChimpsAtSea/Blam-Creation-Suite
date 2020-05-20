#pragma once

enum e_game_context_version
{
	_game_context_version_1,
	_game_context_version_2,
	_game_context_version_3,
};

constexpr e_game_context_version get_game_context_version_from_build(e_build build)
{
	if (build >= _build_mcc_1_1367_0_0)
	{
		return _game_context_version_3;
	}
	if (build >= _build_mcc_1_1186_0_0)
	{
		return _game_context_version_2;
	}
	else
	{
		return _game_context_version_1;
	}
}
