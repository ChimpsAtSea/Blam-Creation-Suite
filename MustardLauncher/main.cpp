#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <DbgHelp.h>
#include <stdio.h>
#include <assert.h>
#include <windows.h>

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

	HINSTANCE project21 = LoadLibraryA("Mustard.dll");
	if (project21 == NULL)
	{
		printf("failed to load project21.dll\n");
		return 1;
	}
	FARPROC project21_main = GetProcAddress(project21, "main");
	typedef int (main_func)();
	main_func* project21_main_ptr = reinterpret_cast<main_func*>(project21_main);
	if (project21_main_ptr == nullptr)
	{
		printf("failed to find project21.dll::main\n");
		return 1;
	}

	int result = project21_main_ptr();
	return g_thread_local_data[_countof(g_thread_local_data)-1] | 1;
}
