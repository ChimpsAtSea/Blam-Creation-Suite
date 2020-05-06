#include "blamboozle-private-pch.h"

const char* c_console::g_console_executable_name = "Blamboozle";

int wmain(int argc, const wchar_t** argv)
{
	int result = blamboozle_run();

	return result;
}