#include <halo3lib-private-pch.h>

/* ---------- private constants */
/* ---------- private macros */
/* ---------- private types */
/* ---------- private classes */
/* ---------- globals */
/* ---------- private prototypes */
/* ---------- public code */

c_halo3_test_command::c_halo3_test_command()
{
	c_console::register_command(k_halo3_test_command_name, this);
}

c_halo3_test_command::~c_halo3_test_command()
{
	c_console::unregister_command(k_halo3_test_command_name);
}

extern char* halo3_tag_definition_get(unsigned long group, const char* tag_name);
extern char* halo3_tag_address_get(uint32_t tag_instance_address);
extern char* halo3_tag_definition_get(uint32_t index);
extern const char* halo3_tag_name_get(unsigned long tag_index);

void print_mainmenu_ui_globals()
{
	if (char *globals = halo3_tag_definition_get(blofeld::GLOBALS_TAG, "globals\\globals"); globals)
	{
		if (unsigned long interface_tag_block_count = *reinterpret_cast<unsigned long*>(&globals[0x134] + 0); interface_tag_block_count)
		{
			if (char* interface_tag = halo3_tag_address_get(*reinterpret_cast<unsigned long*>(&globals[0x134] + 4)); interface_tag)
			{
				if (unsigned long mainmenu_ui_globals_group = *reinterpret_cast<unsigned long*>(&interface_tag[0xE0] + 0); mainmenu_ui_globals_group == blofeld::USER_INTERFACE_GLOBALS_DEFINITION_TAG)
				{
					if (unsigned short mainmenu_ui_globals_index = *reinterpret_cast<unsigned short*>(&interface_tag[0xE0] + 12); mainmenu_ui_globals_index)
					{
						if (char* mainmenu_ui_globals = halo3_tag_definition_get(mainmenu_ui_globals_index); mainmenu_ui_globals)
						{
							// #TODO: get full name via the tag reference group index
							union { uint64_t value; char string[8]; } group;
							group.value = _byteswap_ulong(*reinterpret_cast<unsigned long*>(&interface_tag[0xE0] + 0));

							const char* mainmenu_ui_globals_name = halo3_tag_name_get(mainmenu_ui_globals_index);
							const char* mainmenu_ui_globals_group_short_name = group.string;
							c_console::write_line_verbose("mainmenu ui globals: '%s.%s'", mainmenu_ui_globals_name, mainmenu_ui_globals_group_short_name);
							debug_point;
						}
					}
				}
				else
				{
					c_console::write_line_verbose("no mainmenu ui globals tag exists or has the wrong group tag");
					debug_point;
				}
			}
		}
	}
}

bool c_halo3_test_command::execute_command(const std::vector<std::string>& arguments)
{
	if (arguments.empty()) return true;

	if (!arguments.front().compare(k_halo3_test_command_name))
	{
		if (arguments.size() >= 2)
		{
			const std::string& arg1 = arguments[1];

			c_console::set_text_color(_console_color_info);

			if (!arg1.compare("print_mainmenu_ui_globals"))
			{
				print_mainmenu_ui_globals();
			}
		}
		else return false;
	}
	return true;
}

std::string c_halo3_test_command::get_command_info(const std::string& topic) const
{
	if (!topic.empty())
	{
		if (!topic.compare(k_halo3_test_command_name))
		{
			return
				"Update test\n"
				"Usage: test <command>\n"
				"Commands: print_mainmenu_ui_globals";
		}
	}
	return "";
}

std::string c_halo3_test_command::get_command_auto_complete(const std::vector<std::string>& Arguments) const
{
	if (Arguments.size() > 1)
	{
		if (!Arguments[1].compare("p"))
		{
			return "print_mainmenu_ui_globals";
		}
	}

	return "";
}

/* ---------- private code */

