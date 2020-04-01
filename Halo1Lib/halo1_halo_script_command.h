#pragma once
#include <Halo1Lib\halo1_game_host.scripting.inl>

// TODO: move this into a global context that all game hosts can use

/* ---------- constants */
constexpr const char *k_halo1_halo_script_command_name = "halo_script";

/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_halo1_halo_script_command :
	public c_console_command
{
public:

	c_halo1_halo_script_command();
	~c_halo1_halo_script_command();

	virtual bool execute_command(const std::vector<std::string> &arguments) override;
	virtual std::string get_command_info(const std::string &topic) const override;
	virtual std::string get_command_auto_complete(const std::vector<std::string> &Arguments) const override;

private:
};

/* ---------- globals */
/* ---------- prototypes */
