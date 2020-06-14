#include "platform-private-pch.h"

void __fatal_error_internal(const wchar_t* reason, const wchar_t* filepath, unsigned int line, ...)
{
	wchar_t fatal_error_buffer[2048] = {};
	va_list va_args;
	va_start(va_args, line);
	_vsnwprintf(fatal_error_buffer, _countof(fatal_error_buffer) - 1, reason, va_args);
	va_end(va_args);

	fatal_error_buffer[_countof(fatal_error_buffer) - 1] = 0;

	if (IsDebuggerPresent())
	{
		_wassert(fatal_error_buffer, filepath, line);
	}
	else
	{
		int message_box_result = MessageBoxW(NULL, fatal_error_buffer, L"Fatal Error", MB_ABORTRETRYIGNORE | MB_ICONERROR);
		if (message_box_result != IDIGNORE)
		{
			exit(1);
		}
	}
}
