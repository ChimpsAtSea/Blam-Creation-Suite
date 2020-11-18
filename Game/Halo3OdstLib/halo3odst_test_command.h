#pragma once

/* ---------- constants */
constexpr const char* k_halo3odst_test_command_name = "test";

/* ---------- macros */
/* ---------- types */
/* ---------- classes */

class c_halo3odst_test_command :
	public c_console_command
{
public:

	c_halo3odst_test_command();
	~c_halo3odst_test_command();

	virtual bool execute_command(const std::vector<std::string>& arguments) override;
	virtual std::string get_command_info(const std::string& topic) const override;
	virtual std::string get_command_auto_complete(const std::vector<std::string>& Arguments) const override;

private:

};

/* ---------- globals */
/* ---------- prototypes */
