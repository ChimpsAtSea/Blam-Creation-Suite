#include "gameframework-private-pch.h"

void c_session_manager::create_game_options(s_engine_platform_build engine_platform_build, GameOptions** out_options)
{
	ASSERT(out_options);

	e_game_options_version game_options_version = get_game_options_version_from_build(engine_platform_build.build);
	switch (game_options_version)
	{
	case _game_options_version_0: console_write_line("Using game context version 0"); break;
	case _game_options_version_1: console_write_line("Using game context version 1"); break;
	case _game_options_version_2: console_write_line("Using game context version 2"); break;
	case _game_options_version_3: console_write_line("Using game context version 3"); break;
	}
	*out_options = new GameOptions(game_options_version);
	ASSERT(*out_options);

	GameOptions& options = **out_options;

	s_peer_context SquadAddress = { 0x2F385E2E95D4F33Ei64 };
	s_peer_context HostAddress = { 0xDEADBEEFDEADBEEFi64 };
	s_peer_context ClientAddress = { 0xCAFEBABECAFEBABEi64 };

	options.party = SquadAddress; // this is set

	options.peer_count = 1;
	options.player_count = 1;
	options.is_host = true;
	if (options.is_host == true)
	{
		options.local = HostAddress; // this is set
		options.host = HostAddress; // this is set
	}
	else
	{
		options.local = ClientAddress; // this is set
		options.host = HostAddress;
	}
}
