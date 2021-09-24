#include <halo4lib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

void halo4_engine_state_update(IGameEngine* game_engine, const std::string engine_state_str)
{
	if (game_engine != nullptr)
	{
		if (!engine_state_str.compare("pause"))
		{
			console_write_line("Pausing game");
			game_engine->EngineStateUpdate(_engine_state_pause);
		}
		else if (!engine_state_str.compare("unpause"))
		{
			console_write_line("Unpausing game");
			game_engine->EngineStateUpdate(_engine_state_unpause);
		}
		else if (!engine_state_str.compare("end"))
		{
			console_write_line("Ending game");
			game_engine->EngineStateUpdate(_engine_state_game_end);
		}
		else if (!engine_state_str.compare("restart"))
		{
			console_write_line("Restarting level");
			game_engine->EngineStateUpdate(_engine_state_restart_level);
		}
		else if (!engine_state_str.compare("revert"))
		{
			console_write_line("Restarting checkpoint");
			game_engine->EngineStateUpdate(_engine_state_restart_checkpoint);
		}
		else if (!engine_state_str.compare("save"))
		{
			console_write_line("Saving game variant");
			game_engine->EngineStateUpdate(_engine_state_game_variant_save);

			console_write_line("Saving map variant");
			game_engine->EngineStateUpdate(_engine_state_map_variant_save);
		}

		return;
	}

	console_write_line("Unable to update engine state");
}

c_halo4_engine_state_command::c_halo4_engine_state_command() :
	g_game_engine(nullptr)
{
	c_console::register_command(k_halo4_engine_state_command_name, this);
}

c_halo4_engine_state_command::~c_halo4_engine_state_command()
{
	c_console::unregister_command(k_halo4_engine_state_command_name);
}

bool c_halo4_engine_state_command::execute_command(const std::vector<std::string> &arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_halo4_engine_state_command_name))
	{
		if (arguments.size() >= 2)
		{
			const std::string &engine_state = arguments[1];

			c_console::set_text_color(_console_color_info);
			halo4_engine_state_update(g_game_engine, engine_state);
		}
		else return false;
	}
	return true;
}

std::string c_halo4_engine_state_command::get_command_info(const std::string &topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_halo4_engine_state_command_name))
		{
			return
				"Update engine state\n"
				"Usage: engine_state <state>\n"
				"States: pause, unpause, end, restart, revert, save";
		}
	}
	return "";
}

std::string c_halo4_engine_state_command::get_command_auto_complete(const std::vector<std::string> &Arguments) const
{
	if (Arguments.size() > 1)
	{
		if (!Arguments[1].compare("p"))
		{
			return "pause";
		}
		else if (!Arguments[1].compare("u"))
		{
			return "unpause";
		}
		else if (!Arguments[1].compare("e"))
		{
			return "end";
		}
		else if (!Arguments[1].compare("res"))
		{
			return "restart";
		}
		else if (!Arguments[1].compare("rev"))
		{
			return "revert";
		}
		else if (!Arguments[1].compare("s"))
		{
			return "save";
		}
	}

	return "";
}

void c_halo4_engine_state_command::set_game_engine(IGameEngine* game_engine)
{
	g_game_engine = game_engine;
}

/* ---------- private code */

