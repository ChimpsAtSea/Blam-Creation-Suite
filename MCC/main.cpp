#include "mcc-private-pch.h"

void init_simple_network();
void deinit_simple_network();

Opus* pOpus = nullptr;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		init_simple_network();
		assert(pOpus == nullptr);
		pOpus = new Opus();
	}
	break;
	case DLL_PROCESS_DETACH:
	{
		deinit_simple_network();
		assert(pOpus);
		delete pOpus;
		pOpus = nullptr;
	}
	break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
