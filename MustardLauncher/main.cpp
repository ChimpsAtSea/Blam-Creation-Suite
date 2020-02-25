#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <DbgHelp.h>
#include <stdio.h>
#include <assert.h>
#include <windows.h>

#pragma optimize("", off)

char thread_local g_thread_local_data[32 * 1024] = {}; // 32KiB of TLS data storage

int main(int argc, const char* argv[])
{
	HINSTANCE mustard_module = LoadLibraryA("Mustard.dll");

	// mustard should completely hijack the process.
	// this code should be considered unreachable.

	if (mustard_module == NULL)
	{
		_wassert(L"Failed to load module 'mustard.dll'", _CRT_WIDE(__FILE__), __LINE__);
	}
	else
	{
		_wassert(L"Unexpected error. Mustard module did not exit process", _CRT_WIDE(__FILE__), __LINE__);
	}

	memset(g_thread_local_data, static_cast<int>(reinterpret_cast<intptr_t>(mustard_module)), sizeof(g_thread_local_data));
	return g_thread_local_data[_countof(g_thread_local_data)-1] | 1;
}
