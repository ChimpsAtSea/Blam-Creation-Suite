#include "platform-private-pch.h"

//HANDLE console_mutex;
static bool console_verbose = false;

BCS_RESULT init_console()
{
	console_verbose = BCS_SUCCEEDED(command_line_has_argument("verbose"));
	//console_mutex = CreateMutexA(NULL, FALSE, "console mutex");

	return BCS_S_OK;
}

BCS_RESULT alloc_console(const char* console_window_title)
{
	AllocConsole();
	(void)freopen("CONIN$", "r", stdin);
	(void)freopen("CONOUT$", "w", stdout);
	(void)freopen("CONOUT$", "w", stderr);

	if (console_window_title)
	{
		BCS_CHAR_TO_WIDECHAR_STACK(console_window_title, console_window_title_wc);
		SetConsoleTitleW(console_window_title_wc);
	}
	EnableMenuItem(GetSystemMenu(GetConsoleWindow(), FALSE), SC_CLOSE & SC_MINIMIZE | SC_MAXIMIZE, MF_GRAYED);
	DrawMenuBar(GetConsoleWindow());

	std::ios::sync_with_stdio();

	return BCS_S_OK;
}

BCS_RESULT deinit_console()
{
	BCS_RESULT rs = BCS_S_OK;

	//BOOL close_mutex_result = CloseHandle(console_mutex);
	//if (close_mutex_result != FALSE)
	//{
	//	rs = BCS_E_FAIL;
	//}

	return rs;
}

bool console_is_verbose()
{
	return console_verbose;
}

BCS_RESULT console_write(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);

	return BCS_S_OK;
}

BCS_RESULT console_write_line(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	puts("");

	return BCS_S_OK;
}

BCS_RESULT console_end_line()
{
	puts("");
	return BCS_S_OK;
}

BCS_RESULT console_write_line_with_debug(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	int requested_buffer_size = vsnprintf(nullptr, 0, format, args);
	if (requested_buffer_size <= 0)
	{
		return BCS_E_FAIL;
	}
	char* output_buffer = static_cast<char*>(tracked_malloca(requested_buffer_size + 2));
	int written_buffer_size = vsnprintf(output_buffer, requested_buffer_size + 1, format, args);
	output_buffer[requested_buffer_size + 1] = 0; // make sure null terminated
	output_buffer[requested_buffer_size] = '\n'; // append new line
	OutputDebugStringA(output_buffer);
	output_buffer[requested_buffer_size] = 0; // make sure null terminated
	puts(output_buffer);
	tracked_freea(output_buffer);
	va_end(args);

	return BCS_S_OK;
}

BCS_RESULT console_write_verbose(const char* format, ...)
{
	if (console_verbose)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
	}

	return BCS_S_OK;
}

BCS_RESULT console_write_line_verbose(const char* format, ...)
{
	if (console_verbose)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
		puts("");
	}

	return BCS_S_OK;
}

BCS_RESULT console_end_line_verbose()
{
	if (console_verbose)
	{
		puts("");
	}

	return BCS_S_OK;
}
