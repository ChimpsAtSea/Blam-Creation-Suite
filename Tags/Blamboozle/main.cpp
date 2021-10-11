#include "blamboozle-private-pch.h"

int wmain(int argc, const wchar_t** argv)
{
	init_command_line();
	init_console();

	int result = blamboozle_run();
	
	deinit_console();
	deinit_command_line();
	return result;
}