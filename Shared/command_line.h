#pragma once

class c_command_line
{
public:
	static void Init();
	static void Deinit();
	static bool has_command_line_arg(const char* pArgument);
	static std::string get_command_line_arg(const char* command);
};

