#include <halo1lib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

c_halo1_dev_console_command::c_halo1_dev_console_command() :
	g_game_engine(nullptr)
{
	c_console::register_command(k_halo1_dev_console_command_name, this);
}

c_halo1_dev_console_command::~c_halo1_dev_console_command()
{
	c_console::unregister_command(k_halo1_dev_console_command_name);
}

bool c_halo1_dev_console_command::execute_command(const std::vector<std::string>& arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_halo1_dev_console_command_name))
	{
		if (arguments.size() >= 2)
		{
			std::string command = "HS: ";
			for (size_t i = 1; i < arguments.size(); i++)
			{
				command += arguments[i];
				if (i < arguments.size() - 1)
				{
					command += " ";
				}
			}

			c_console::set_text_color(_console_color_info);
			g_game_engine->SendEngineCommand(command.c_str());
		}
		else return false;
	}
	return true;
}

std::string c_halo1_dev_console_command::get_command_info(const std::string& topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_halo1_dev_console_command_name))
		{
			return
				"Halo 1 dev console\n"
				"Usage: dev_console <command>\n";
		}
	}
	return "";
}

std::string c_halo1_dev_console_command::get_command_auto_complete(const std::vector<std::string>& Arguments) const
{
	return "";
}

void c_halo1_dev_console_command::set_game_engine(IGameEngine* game_engine)
{
	g_game_engine = game_engine;
}

/* ---------- private code */

