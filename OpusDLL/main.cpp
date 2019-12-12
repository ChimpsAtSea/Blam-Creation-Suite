#include "opus-private-pch.h"

__declspec(dllexport) void opus() {};

extern void init_halo_reach_with_mcc(BuildVersion buildVersion, bool isMCC);
extern void deinit_halo_reach(BuildVersion buildVersion);
void haloreach_dll_loaded_callback()
{
	init_halo_reach_with_mcc(BuildVersion::Build_1_1211_0_0, true); // #TODO: Detect halo game id
}

typedef FARPROC(__stdcall GetProcAddressFunc)(HMODULE hModule, LPCSTR lpProcName);
GetProcAddressFunc* GetProcAddressPtr = nullptr;
FARPROC __stdcall GetProcAddressHook(HMODULE hModule, LPCSTR lpProcName)
{
	char pModuleFilename[MAX_PATH] = {};
	GetModuleFileNameA(hModule, pModuleFilename, sizeof(pModuleFilename));

	auto farproc = GetProcAddressPtr(hModule, lpProcName);

	static bool isHooked = false;
	if (!isHooked)
	{
		bool isHaloReach = strstr(pModuleFilename, "haloreach.dll") != 0;
		if (isHaloReach)
		{
			WriteLineVerbose("%s was hooked", pModuleFilename);
			isHooked = true;

			haloreach_dll_loaded_callback();
		}
	}

	return farproc;

}

void init()
{
	AllocConsole();
	(void)(freopen("CONOUT$", "w", stdout));

	init_detours();

	LPSTR pCommandLine = GetCommandLineA();
	WriteLineVerbose("Command Line: %s", pCommandLine);

	{
		//static void* OutputDebugStringW_Original;
		//create_dll_hook("KERNEL32.dll", "OutputDebugStringW", nullsub, OutputDebugStringW_Original);
		//static void* OutputDebugStringA_Original;
		//create_dll_hook("KERNEL32.dll", "OutputDebugStringA", nullsub, OutputDebugStringA_Original);
		create_dll_hook("KERNEL32.dll", "GetProcAddress", GetProcAddressHook, GetProcAddressPtr);
	}

	end_detours();
}

void deinit()
{

}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		init();
		break;
	case DLL_PROCESS_DETACH:
		deinit();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}