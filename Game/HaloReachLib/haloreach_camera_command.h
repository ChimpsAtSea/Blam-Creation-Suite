#pragma once

// TODO: move this into a global context that all game hosts can use

/* ---------- constants */
constexpr const char *k_haloreach_camera_command_name = "camera";

/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_haloreach_camera_command :
	public c_console_command
{
public:

	c_haloreach_camera_command();
	~c_haloreach_camera_command();

	virtual bool execute_command(const std::vector<std::string> &arguments) override;
	virtual std::string get_command_info(const std::string &topic) const override;
	virtual std::string get_command_auto_complete(const std::vector<std::string> &Arguments) const override;

	void read_config();

private:
};

/* ---------- globals */
/* ---------- prototypes */
