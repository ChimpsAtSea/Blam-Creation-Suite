#pragma once

class c_command_line
{
public:
	static void Init();
	static void Deinit();
	static bool has_command_line_arg(const char* pArgument);
	static std::string get_command_line_arg(const char* command);
	static std::wstring get_command_line_warg(const char* command);
	static int get_argc();
	static const char** get_argv();
	static const wchar_t** get_wargv();
};

