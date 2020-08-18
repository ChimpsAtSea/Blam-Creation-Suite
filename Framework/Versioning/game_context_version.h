#pragma once

enum e_game_context_version
{
	_game_context_version_1,
	_game_context_version_2,
	_game_context_version_3,
	_game_context_version_4,
};

constexpr e_game_context_version get_game_context_version_from_build(e_build build)
{
	if (build >= _build_mcc_1_1767_0_0)
	{
		return _game_context_version_4;
	}
	else if (build >= _build_mcc_1_1716_0_0)
	{
		return _game_context_version_3;
	}
	else if (build >= _build_mcc_1_1186_0_0)
	{
		return _game_context_version_2;
	}
	else
	{
		return _game_context_version_1;
	}
}
