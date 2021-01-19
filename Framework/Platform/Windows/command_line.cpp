#include "platform-private-pch.h"

void c_command_line::Init()
{

}

void c_command_line::Deinit()
{

}

bool c_command_line::has_command_line_arg(const char* pArgument)
{
	static LPSTR command_line = GetCommandLineA();
	const char* string_search = strstr(command_line, pArgument);
	size_t search_length = strlen(pArgument);
	while (string_search != nullptr)
	{
		const char* string_search_end = string_search + search_length;
		switch (*string_search_end)
		{
		case '\0':
		case ' ':
		case ':':
			return true;
		}

		string_search = strstr(string_search + 1, pArgument);
	}
	return false;
}

std::string c_command_line::get_command_line_arg(const char* command)
{
	static LPSTR const command_line = GetCommandLineA();

	uint32_t command_length = strlen(command);

	const char* command_start = command_line;
	while (command_start = strstr(command_start, command))
	{
		const char* command_value_start = command_start + command_length;

		if (*command_value_start == ':')
		{
			std::string command_line_remainder = command_value_start + 1;
			command_line_remainder = command_line_remainder.substr(0, command_line_remainder.find(' '));
			return command_line_remainder;
		}

		command_start = command_value_start;
	}

	return "";
}

std::wstring c_command_line::get_command_line_warg(const char* command)
{
	// #TODO: Proper wide char version
	std::string argument = get_command_line_arg(command);
	return std::wstring(argument.begin(), argument.end());
}

int c_command_line::get_argc()
{
	return __argc;
}

const char** c_command_line::get_argv()
{
	return const_cast<const char**>(__argv);
}

const wchar_t** c_command_line::get_wargv()
{
	return const_cast<const wchar_t**>(__wargv);
}
