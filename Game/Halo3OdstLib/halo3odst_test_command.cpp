#include <halo3odstlib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */


/* ---------- public code */

c_halo3odst_test_command::c_halo3odst_test_command()
{
	c_console::register_command(k_halo3odst_test_command_name, this);
}

c_halo3odst_test_command::~c_halo3odst_test_command()
{
	c_console::unregister_command(k_halo3odst_test_command_name);
}

bool c_halo3odst_test_command::execute_command(const std::vector<std::string>& arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_halo3odst_test_command_name))
	{
		if (arguments.size() >= 2)
		{
			const std::string& arg1 = arguments[1];

			c_console::set_text_color(_console_color_info);

		}
		else return false;
	}
	return true;
}

std::string c_halo3odst_test_command::get_command_info(const std::string& topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_halo3odst_test_command_name))
		{
			return
				"test\n"
				"Usage: test <command>\n"
				"Commands:\n";
		}
	}
	return "";
}

std::string c_halo3odst_test_command::get_command_auto_complete(const std::vector<std::string>& Arguments) const
{
	if (Arguments.size() > 1)
	{
	}

	return "";
}

/* ---------- private code */

