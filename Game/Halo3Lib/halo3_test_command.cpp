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

extern char* halo3_tag_address_get(uint32_t tag_instance_address);
extern char* halo3_tag_definition_get(uint32_t index);
extern const char* halo3_tag_name_get(unsigned long tag_index);
extern unsigned long halo3_tag_index_by_name_get(const char* tag_name);

unsigned long block_count_get(char* address) { return *reinterpret_cast<unsigned long*>(address + 0); }
unsigned long block_address_get(char* address) { return *reinterpret_cast<unsigned long*>(address + 4); }
unsigned short reference_index_get(char* address) { return *reinterpret_cast<unsigned short*>(address + 12); }

void print_mainmenu_ui_globals()
{
	unsigned long globals_index = halo3_tag_index_by_name_get("globals\\globals");
	if (char* globals = halo3_tag_definition_get(globals_index); globals)
	{
		if (unsigned long interface_tag_block_count = block_count_get(globals + 0x134); interface_tag_block_count)
		{
			unsigned long interface_tag_block_address = block_address_get(globals + 0x134);
			if (char* interface_tag = halo3_tag_address_get(interface_tag_block_address); interface_tag)
			{
				if (unsigned short mainmenu_ui_globals_index = reference_index_get(interface_tag + 0xE0); mainmenu_ui_globals_index)
				{
					if (char* mainmenu_ui_globals = halo3_tag_definition_get(mainmenu_ui_globals_index); mainmenu_ui_globals)
					{
						const char* mainmenu_ui_globals_name = halo3_tag_name_get(mainmenu_ui_globals_index);
						c_console::write_line_verbose("mainmenu ui globals: '%s'", mainmenu_ui_globals_name);
						debug_point;
					}
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

