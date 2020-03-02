#include "shared-private-pch.h"

void c_command_line::Init()
{

}

void c_command_line::Deinit()
{

}

bool c_command_line::has_command_line_arg(const char* pArgument)
{
	static LPSTR command_line = GetCommandLineA();
	return strstr(command_line, pArgument) != 0;
}

std::string c_command_line::get_command_line_arg(const char* command)
{
	if (has_command_line_arg(command))
	{
		static LPSTR command_line = GetCommandLineA();

		const char* command_start = strstr(command_line, command);
		const char* command_value_start = command_start + strlen(command);

		if (*command_value_start == ':')
		{
			std::string command_line_remainder = command_value_start + 1;
			return command_line_remainder.substr(0, command_line_remainder.find(' '));
		}
	}
	return "";
}
