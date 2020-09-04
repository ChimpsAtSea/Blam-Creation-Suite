#include "versioning-private-pch.h"

e_game_context_version get_game_context_version_from_build(e_build build)
{
	if (build >= _build_mcc_1_1767_0_0)
	{
		return _game_context_version_4;
	}
	else if (build >= _build_mcc_1_1367_0_0)
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