#include <halo3odstlib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

void halo3odst_update_engine_state(IGameEngine* game_engine, const std::string engine_state_str)
{
	if (game_engine != nullptr)
	{
		if (!engine_state_str.compare("pause"))
		{
			c_console::write_line_verbose("Pausing game");
			game_engine->update_engine_state(_engine_state_pause);
		}
		else if (!engine_state_str.compare("unpause"))
		{
			c_console::write_line_verbose("Unpausing game");
			game_engine->update_engine_state(_engine_state_unpause);
		}
		else if (!engine_state_str.compare("end"))
		{
			c_console::write_line_verbose("Ending game");
			game_engine->update_engine_state(_engine_state_game_end);
		}
		else if (!engine_state_str.compare("restart"))
		{
			c_console::write_line_verbose("Restarting level");
			game_engine->update_engine_state(_engine_state_restart_level);
		}
		else if (!engine_state_str.compare("revert"))
		{
			c_console::write_line_verbose("Restarting checkpoint");
			game_engine->update_engine_state(_engine_state_restart_checkpoint);
		}
		else if (!engine_state_str.compare("save"))
		{
			c_console::write_line_verbose("Saving game variant");
			game_engine->update_engine_state(_engine_state_game_variant_save);

			c_console::write_line_verbose("Saving map variant");
			game_engine->update_engine_state(_engine_state_map_variant_save);
		}

		return;
	}

	c_console::write_line_verbose("Unable to update engine state");
}

c_halo3odst_engine_state_command::c_halo3odst_engine_state_command() :
	g_game_engine(nullptr)
{
	c_console::register_command(k_halo3odst_engine_state_command_name, this);
}

c_halo3odst_engine_state_command::~c_halo3odst_engine_state_command()
{
	c_console::unregister_command(k_halo3odst_engine_state_command_name);
}

bool c_halo3odst_engine_state_command::execute_command(const std::vector<std::string> &arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_halo3odst_engine_state_command_name))
	{
		if (arguments.size() >= 2)
		{
			const std::string &engine_state = arguments[1];

			c_console::set_text_color(_console_color_info);
			halo3odst_update_engine_state(g_game_engine, engine_state);
		}
		else return false;
	}
	return true;
}

std::string c_halo3odst_engine_state_command::get_command_info(const std::string &topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_halo3odst_engine_state_command_name))
		{
			return
				"Update engine state\n"
				"Usage: engine_state <state>\n"
				"States: pause, unpause, end, restart, revert, save";
		}
	}
	return "";
}

std::string c_halo3odst_engine_state_command::get_command_auto_complete(const std::vector<std::string> &Arguments) const
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

void c_halo3odst_engine_state_command::set_game_engine(IGameEngine* game_engine)
{
	g_game_engine = game_engine;
}

/* ---------- private code */

