#pragma once

class CommandLine
{
public:
	static void Init();
	static void Deinit();
	static bool HasCommandLineArg(const char* pArgument);
};

