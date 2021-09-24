#include "platform-private-pch.h"
#include <iostream>

HANDLE console_mutex;

BCS_RESULT init_console(const char* console_window_title)
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

	console_mutex = CreateMutexA(NULL, FALSE, "console mutex");

	return BCS_S_OK;
}

BCS_RESULT deinit_console()
{
	BCS_RESULT rs = BCS_S_OK;

	BOOL close_mutex_result = CloseHandle(console_mutex);
	if (close_mutex_result != FALSE)
	{
		rs = BCS_E_FAIL;
	}

	return rs;
}

BCS_RESULT console_write(const char* format, ...)
{
	DWORD wait_for_mutex_result = WaitForSingleObject(console_mutex, INFINITE);
	if (wait_for_mutex_result != WAIT_OBJECT_0)
	{
		return BCS_E_FAIL;
	}

	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);

	BOOL release_mutex_result = ReleaseMutex(console_mutex);
	if (release_mutex_result == 0)
	{
		return BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT console_write_line(const char* format, ...)
{
	DWORD wait_for_mutex_result = WaitForSingleObject(console_mutex, INFINITE);
	if (wait_for_mutex_result != WAIT_OBJECT_0)
	{
		return BCS_E_FAIL;
	}

	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	puts("");

	BOOL release_mutex_result = ReleaseMutex(console_mutex);
	if (release_mutex_result == 0)
	{
		return BCS_E_FAIL;
	}

	return BCS_S_OK;
}
