#pragma once

class c_fsb_validate : c_console_command
{
public:
	
	c_fsb_validate();
	~c_fsb_validate();
	virtual bool execute_command(const std::vector<std::string>& arguments) override;
	virtual std::string get_command_info(const std::string& topic) const override;
};

