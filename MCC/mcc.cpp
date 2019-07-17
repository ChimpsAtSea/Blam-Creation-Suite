#include "mcc-private-pch.h"

#define MCCExecutable "MCC-Win64-Shipping_Debug.exe"
#define MCCBaseAddress 0x140000000
#define HaloReachDLL "HaloReach.dll"
#define HaloReachBase 0x180000000

void haloreach_dll_loaded_callback();

bool initThreadIsHooked = false;

unsigned __int64 checksum(void* data, size_t size)
{
	unsigned __int64 sum = 0;
	size_t offset = 0;
	while (offset < size)
	{
		sum += ((unsigned char*)data)[offset++];
	}
	return sum;
}

void(__fastcall* InitThreadPtr)(IGameEngine*, GameEngineHostCallback*, s_game_launch_data& data);
void __fastcall InitThreadHook(IGameEngine* _this, GameEngineHostCallback* a1, s_game_launch_data& data)
{
	static s_game_launch_data game_launch_data = s_game_launch_data(data);

	InitThreadPtr(_this, a1, game_launch_data);
}


typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
CreateGameEngineFunc* CreateGameEngine = nullptr;
signed __int64 __fastcall CreateGameEngineHook(IGameEngine** ppGameEngine)
{
	auto result = CreateGameEngine(ppGameEngine);

	if (initThreadIsHooked == false)
	{
		initThreadIsHooked = true;

		init_detours();

		create_hook("IGameEngine::InitThread", (*ppGameEngine)->vftbl->InitThread, InitThreadHook, InitThreadPtr);

		end_detours();
	}
	
	return result;
}

typedef FARPROC(__stdcall GetProcAddressFunc)(HMODULE hModule, LPCSTR lpProcName);
GetProcAddressFunc* GetProcAddressPtr = nullptr;
FARPROC __stdcall GetProcAddressHook(HMODULE hModule, LPCSTR lpProcName)
{
	char pModuleFilename[MAX_PATH] = {};
	GetModuleFileNameA(hModule, pModuleFilename, sizeof(pModuleFilename));

	auto farproc = GetProcAddressPtr(hModule, lpProcName);

	if (!isHooked)
	{
		bool isHaloReach = strstr(pModuleFilename, "haloreach.dll") != nullptr;
		if (isHaloReach)
		{
			isHooked = true;

			// reset hook states
			initThreadIsHooked = false;

			haloreach_dll_loaded_callback();
		}
	}

	return farproc;

}

void nullsub()
{

}

void haloreach_dll_loaded_callback()
{
	useCustomGameEngineHostCallback = false;
	useCustomGameWindow = false;
	halo_reach_path = "haloreach\\";
	init_haloreach_hooks();

	init_detours();
	create_dll_hook(HaloReachDLL, "CreateGameEngine", CreateGameEngineHook, CreateGameEngine);
	printf("0x%p\n", GetModuleHandleA(HaloReachDLL));
	printf("0x180000000\n");
	end_detours();
}

Opus::Opus()
{
	AllocConsole();
	(void)(freopen("CONOUT$", "w", stdout));

	init_detours();
	static void* OutputDebugStringW_Original;
	create_dll_hook("KERNEL32.dll", "OutputDebugStringW", nullsub, OutputDebugStringW_Original);
	static void* OutputDebugStringA_Original;
	create_dll_hook("KERNEL32.dll", "OutputDebugStringA", nullsub, OutputDebugStringA_Original);
	create_dll_hook("KERNEL32.dll", "GetProcAddress", GetProcAddressHook, GetProcAddressPtr);
	end_detours();
}

Opus::~Opus()
{




}

