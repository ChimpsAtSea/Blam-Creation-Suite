#include "shared-private-pch.h"

void c_command_line::Init()
{

}

void c_command_line::Deinit()
{

}

bool c_command_line::has_command_line_arg(const char* pArgument)
{
	static LPSTR sCommandLine = GetCommandLineA();
	return strstr(sCommandLine, pArgument) != 0;
}
