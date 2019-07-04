#include <windows.h>
#include <stdio.h>
#include <assert.h>

void init_simple_network();
void deinit_simple_network();

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:

		init_simple_network();

		break;
	case DLL_PROCESS_DETACH:
		deinit_simple_network();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
