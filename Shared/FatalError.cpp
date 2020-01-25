#include "shared-private-pch.h"
#include "FatalError.h"

void __FatalErrorInternal(const wchar_t* pReason, const wchar_t* pFile, unsigned int line, ...)
{
	wchar_t pFatalErrorBuffer[2048] = {};
	va_list va_args;
	va_start(va_args, line);
	_vsnwprintf(pFatalErrorBuffer, _countof(pFatalErrorBuffer) - 1, pReason, va_args);
	va_end(va_args);

	pFatalErrorBuffer[_countof(pFatalErrorBuffer) - 1] = 0;

	if (IsDebuggerPresent())
	{
		_wassert(pFatalErrorBuffer, pFile, line);
	}
	else
	{
		int messageBoxResult = MessageBoxW(Window::GetWindowHandle(), pFatalErrorBuffer, L"Fatal Error", MB_ABORTRETRYIGNORE | MB_ICONERROR);
		if (messageBoxResult != IDIGNORE)
		{
			exit(1);
		}
	}
}
