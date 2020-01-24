#include "shared-private-pch.h"

void CommandLine::Init()
{

}

void CommandLine::Deinit()
{

}

bool CommandLine::HasCommandLineArg(const char* pArgument)
{
	static LPSTR sCommandLine = GetCommandLineA();
	return strstr(sCommandLine, pArgument) != 0;
}
