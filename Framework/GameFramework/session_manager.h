#pragma once

class GameOptions;

class c_session_player
{
public:
	std::string player_name;
};

class c_session_manager
{
public:
	std::vector<c_session_player*> players;
	c_session_player* host;
	c_session_player* local_players;

	static void create_game_options(e_build build, GameOptions** out_options);
};

