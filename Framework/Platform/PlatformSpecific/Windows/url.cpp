#include "platform-private-pch.h"

BCS_RESULT open_url(const char* url)
{
	INT_PTR shell_execute_result = reinterpret_cast<INT_PTR>(ShellExecuteA(0, 0, url, 0, 0, SW_SHOW));
	if (shell_execute_result < 32) // https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shellexecutea#return-value
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT open_url(const wchar_t* url)
{
	INT_PTR shell_execute_result = reinterpret_cast<INT_PTR>(ShellExecuteW(0, 0, url, 0, 0, SW_SHOW));
	if (shell_execute_result < 32) // https://docs.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shellexecutea#return-value
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
