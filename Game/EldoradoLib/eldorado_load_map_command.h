#pragma once

/* ---------- constants */
constexpr const char* k_eldorado_load_map_command_name = "loadmap";

/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_eldorado_load_map_command :
	public c_console_command
{
public:

	c_eldorado_load_map_command();
	~c_eldorado_load_map_command();

	virtual bool execute_command(const std::vector<std::string>& arguments) override;
	virtual std::string get_command_info(const std::string& topic) const override;
	virtual std::string get_command_auto_complete(const std::vector<std::string>& Arguments) const override;
};

/* ---------- globals */
/* ---------- prototypes */
