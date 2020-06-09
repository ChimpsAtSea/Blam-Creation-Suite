#include <groundhoglib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

void groundhog_update_engine_state(IGameEngine* game_engine, const std::string engine_state_str)
{
	if (game_engine != nullptr)
	{
		if (!engine_state_str.compare("pause"))
		{
			c_console::write_line_verbose("Pausing game");
			game_engine->UpdateEngineState(eEngineState::Pause);
		}
		else if (!engine_state_str.compare("unpause"))
		{
			c_console::write_line_verbose("Unpausing game");
			game_engine->UpdateEngineState(eEngineState::Unpause);
		}
		else if (!engine_state_str.compare("end"))
		{
			c_console::write_line_verbose("Ending game");
			game_engine->UpdateEngineState(eEngineState::EndGame);
		}
		else if (!engine_state_str.compare("restart"))
		{
			c_console::write_line_verbose("Restarting level");
			game_engine->UpdateEngineState(eEngineState::RestartLevel);
		}
		else if (!engine_state_str.compare("revert"))
		{
			c_console::write_line_verbose("Restarting checkpoint");
			game_engine->UpdateEngineState(eEngineState::RestartCheckpoint);
		}
		else if (!engine_state_str.compare("save"))
		{
			c_console::write_line_verbose("Saving game variant");
			game_engine->UpdateEngineState(eEngineState::SaveGameVariant);

			c_console::write_line_verbose("Saving map variant");
			game_engine->UpdateEngineState(eEngineState::SaveMapVariant);
		}

		return;
	}

	c_console::write_line_verbose("Unable to update engine state");
}

c_groundhog_engine_state_command::c_groundhog_engine_state_command() :
	g_game_engine(nullptr)
{
	c_console::register_command(k_groundhog_engine_state_command_name, this);
}

c_groundhog_engine_state_command::~c_groundhog_engine_state_command()
{
	c_console::unregister_command(k_groundhog_engine_state_command_name);
}

bool c_groundhog_engine_state_command::execute_command(const std::vector<std::string> &arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_groundhog_engine_state_command_name))
	{
		if (arguments.size() >= 2)
		{
			const std::string &engine_state = arguments[1];

			c_console::set_text_color(_console_color_info);
			groundhog_update_engine_state(g_game_engine, engine_state);
		}
		else return false;
	}
	return true;
}

std::string c_groundhog_engine_state_command::get_command_info(const std::string &topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_groundhog_engine_state_command_name))
		{
			return
				"Update engine state\n"
				"Usage: engine_state_str <state>";
		}
	}
	return "";
}

std::string c_groundhog_engine_state_command::get_command_auto_complete(const std::vector<std::string> &Arguments) const
{
	return ""; // todo;
}

void c_groundhog_engine_state_command::set_game_engine(IGameEngine* game_engine)
{
	g_game_engine = game_engine;
}

/* ---------- private code */

