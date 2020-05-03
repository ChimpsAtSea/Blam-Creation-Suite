#pragma once

// TODO: move this into a global context that all game hosts can use

/* ---------- constants */
constexpr const char* k_groundhog_engine_state_command_name = "engine_state";

/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_groundhog_engine_state_command :
	public c_console_command
{
public:

	c_groundhog_engine_state_command();
	~c_groundhog_engine_state_command();

	virtual bool execute_command(const std::vector<std::string> &arguments) override;
	virtual std::string get_command_info(const std::string &topic) const override;
	virtual std::string get_command_auto_complete(const std::vector<std::string> &Arguments) const override;

	void set_game_engine(IGameEngine* game_engine);

private:

	IGameEngine* g_game_engine;
};

/* ---------- globals */
/* ---------- prototypes */
