#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <DbgHelp.h>
#include <stdio.h>
#include <assert.h>
#include <windows.h>

#pragma warning( disable : 4474 ) // ignore printf arguments
#pragma optimize("", off)

int thread_local g_thread_local_data[10240] = {};

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	{ //  force some random data into g_thread_local_data
		int value;
		memset(g_thread_local_data, static_cast<int>(reinterpret_cast<intptr_t>(&value)), sizeof(g_thread_local_data));
	}

	HINSTANCE mustard_module = LoadLibraryA("Mustard.dll");
	if (mustard_module == NULL)
	{
		printf("failed to load Mustard.dll\n");
		return 3;
	}
	FARPROC mustard_entry_point_func = GetProcAddress(mustard_module, "main");
	typedef int (main_func)();
	main_func* mustard_entry_point = reinterpret_cast<main_func*>(mustard_entry_point_func);
	if (mustard_entry_point == nullptr)
	{
		printf("failed to find Mustard.dll::main\n");
		return 2;
	}

	int result = mustard_entry_point();
	printf("", g_thread_local_data[_countof(g_thread_local_data) - 1] | 1); // here to prevent optimization
	return result;
}

int main()
{
	SetThreadErrorMode(SEM_NOGPFAULTERRORBOX, NULL);
	SetErrorMode(SEM_NOGPFAULTERRORBOX);

	HMODULE hInstance = NULL;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)WinMain, &hInstance);

	LPSTR lpCmdLine = GetCommandLineA();

	return WinMain(hInstance, NULL, lpCmdLine, SW_SHOWNORMAL);
}
