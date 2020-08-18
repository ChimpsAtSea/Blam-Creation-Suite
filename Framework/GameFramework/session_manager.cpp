#include "gameframework-private-pch.h"

void c_session_manager::create_game_context(e_build build, GameContext** out_game_context)
{
	ASSERT(out_game_context);


	e_game_context_version game_context_version = get_game_context_version_from_build(build);
	switch (game_context_version)
	{
	case _game_context_version_1: c_console::write_line_verbose("Using game context version 1"); break;
	case _game_context_version_2: c_console::write_line_verbose("Using game context version 2"); break;
	case _game_context_version_3: c_console::write_line_verbose("Using game context version 3"); break;
	case _game_context_version_4: c_console::write_line_verbose("Using game context version 4"); break;
	}
	*out_game_context = new GameContext(game_context_version);
	ASSERT(*out_game_context);

	GameContext& game_context = **out_game_context;

	s_peer_context SquadAddress = { 0x2F385E2E95D4F33Ei64 };
	s_peer_context HostAddress = { 0xDEADBEEFDEADBEEFi64 };
	s_peer_context ClientAddress = { 0xCAFEBABECAFEBABEi64 };

	game_context.party = SquadAddress; // this is set

	game_context.peer_count = 1;
	game_context.player_count = 1;
	game_context.is_host = true;
	if (game_context.is_host == true)
	{
		game_context.local = HostAddress; // this is set
		game_context.host = HostAddress; // this is set
	}
	else
	{
		game_context.local = ClientAddress; // this is set
		game_context.host = HostAddress;
	}
}
