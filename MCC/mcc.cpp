#include "mcc-private-pch.h"

#define MCCExecutable "MCC-Win64-Shipping_Debug.exe"
#define MCCBaseAddress 0x140000000
#define HaloReachDLL "HaloReach.dll"
#define HaloReachBase 0x180000000

bool createGameEngineIsHooked = false;
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

void(__fastcall* InitThreadPtr)(IGameEngine*, GameEngineHostCallback*, __int64);
void __fastcall InitThreadHook(IGameEngine*, GameEngineHostCallback*, struct_b1& data)
{
	unsigned __int64 gap0_checksum = checksum(data.gap0, sizeof(data.gap0));
	unsigned __int64 gap2B414_checksum = checksum(data.gap2B414, sizeof(data.gap2B414));
	unsigned __int64 gap2B43C_checksum = checksum(data.gap2B43C, sizeof(data.gap2B43C));
	unsigned __int64 gap2B448_checksum = checksum(data.gap2B448, sizeof(data.gap2B448));
	unsigned __int64 gap2B460_checksum = checksum(data.gap2B460, sizeof(data.gap2B460));
	unsigned __int64 gap2B758_checksum = checksum(data.gap2B758	, sizeof(data.gap2B758));
	

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

	if (!createGameEngineIsHooked)
	{
		bool isHaloReach = strstr(pModuleFilename, "haloreach.dll") != nullptr;
		if (isHaloReach)
		{
			createGameEngineIsHooked = true;

			init_detours();
			create_dll_hook(HaloReachDLL, "CreateGameEngine", CreateGameEngineHook, CreateGameEngine);
			end_detours();
		}
	}

	return farproc;

}


Opus::Opus()
{
	init_detours();

	AllocConsole();
	freopen("CONOUT$", "w", stdout);




	// GetProcAddress

	create_dll_hook("KERNEL32.dll", "GetProcAddress", GetProcAddressHook, GetProcAddressPtr);
	//create_hook<0x180012730>(HaloReachDLL, HaloReachBase, "game_get_haloreach_path", game_get_haloreach_path_hook, game_get_haloreach_path);
	//populate_function_ptr<0x18034A630>(HaloReachDLL, HaloReachBase, game_options_new);



	end_detours();
}

Opus::~Opus()
{




}

