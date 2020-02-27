#include <eldoradolib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

c_eldorado_load_map_command::c_eldorado_load_map_command()
{
	c_console::register_command(k_eldorado_load_map_command_name, this);
}

c_eldorado_load_map_command::~c_eldorado_load_map_command()
{
	c_console::unregister_command(k_eldorado_load_map_command_name);
}

bool c_eldorado_load_map_command::execute_command(const std::vector<std::string>& arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_eldorado_load_map_command_name))
	{
		if (arguments.size() == 2)
		{
			const std::string& map_name = arguments[1];

			c_console::set_text_color(_console_color_info);
			write_line_verbose("Loading map %s", map_name.c_str());
		}
		else return false;
	}
	return true;
}

std::string c_eldorado_load_map_command::get_command_info(const std::string& topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_eldorado_load_map_command_name))
		{
			return
				"Load a map\n"
				"Usage: loadmap <map name>";
		}
	}
	return "";
}

std::string c_eldorado_load_map_command::get_command_auto_complete(const std::vector<std::string>& Arguments) const
{
	return ""; // todo;
}

/* ---------- private code */

