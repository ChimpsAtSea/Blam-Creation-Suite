#include "orus-private-pch.h"
#include <stdio.h>

#define this _this

HMODULE HaloReach; //haloreach.dll

typedef signed __int64(__fastcall CreateGameEngineFunc)(IGameEngine** ppGameEngine);
CreateGameEngineFunc* CreateGameEngine = nullptr;

IGameEngine* pHaloReachEngine = nullptr;
__int64 buffer[1024 * 1024 * 32] = {};
__int64 buffer2[1024 * 1024 * 64] = {};


GameEvents gameEvents;
GameEvents_vftbl gameEventsVftbl;

void nullsub()
{

}

GUID* __fastcall GetGuid(GameEvents* this, GUID* rGuid)
{
	GUID* result; // rax

	result = rGuid;
	*rGuid = this->guid;
	return result;
}

void init_haloreach()
{
	gameEvents.vftbl = &gameEventsVftbl;

	gameEventsVftbl.function1 = nullsub;
	gameEventsVftbl.function2 = nullsub;
	gameEventsVftbl.function3 = nullsub;
	gameEventsVftbl.function4 = nullsub;
	gameEventsVftbl.function5 = nullsub;
	gameEventsVftbl.function6 = nullsub;
	gameEventsVftbl.function7 = nullsub;
	gameEventsVftbl.function8 = nullsub;
	gameEventsVftbl.function9 = nullsub;
	gameEventsVftbl.function10 = nullsub;
	gameEventsVftbl.function11 = nullsub;
	gameEventsVftbl.function12 = nullsub;
	gameEventsVftbl.function13 = nullsub;
	gameEventsVftbl.function14 = nullsub;
	gameEventsVftbl.function15 = nullsub;
	gameEventsVftbl.function16 = nullsub;
	gameEventsVftbl.function17 = nullsub;
	gameEventsVftbl.function18 = nullsub;
	gameEventsVftbl.function19 = nullsub;
	gameEventsVftbl.function20 = nullsub;
	gameEventsVftbl.function21 = nullsub;
	gameEventsVftbl.function22 = nullsub;
	gameEventsVftbl.function23 = nullsub;
	gameEventsVftbl.function24 = nullsub;
	gameEventsVftbl.function25 = nullsub;
	gameEventsVftbl.function26 = nullsub;
	gameEventsVftbl.function27 = nullsub;
	gameEventsVftbl.function28 = nullsub;
	gameEventsVftbl.function29 = nullsub;
	gameEventsVftbl.function30 = nullsub;
	gameEventsVftbl.function31 = nullsub;

	typedef void(__fastcall function32)(GameEvents*, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD, _QWORD, _DWORD, _QWORD);
	gameEventsVftbl.function32 = (function32*)nullsub;

	gameEventsVftbl.function33 = nullsub;
	gameEventsVftbl.function34 = nullsub;
	gameEventsVftbl.function35 = nullsub;
	gameEventsVftbl.function36 = nullsub;
	gameEventsVftbl.function37 = nullsub;
	gameEventsVftbl.function38 = nullsub;
	gameEventsVftbl.function39 = nullsub;
	gameEventsVftbl.function40 = nullsub;
	gameEventsVftbl.function41 = nullsub;
	gameEventsVftbl.function42 = nullsub;
	gameEventsVftbl.function43 = nullsub;
	gameEventsVftbl.function44 = nullsub;
	gameEventsVftbl.function45 = nullsub;
	gameEventsVftbl.function46 = nullsub;
	gameEventsVftbl.function47 = nullsub;
	gameEventsVftbl.function48 = nullsub;
	gameEventsVftbl.function49 = nullsub;
	gameEventsVftbl.function50 = nullsub;
	gameEventsVftbl.function51 = nullsub;
	gameEventsVftbl.function52 = nullsub;
	gameEventsVftbl.function53 = nullsub;
	gameEventsVftbl.function54 = nullsub;
	gameEventsVftbl.function55 = nullsub;
	gameEventsVftbl.function56 = nullsub;
	gameEventsVftbl.function57 = nullsub;
	gameEventsVftbl.function58 = nullsub;
	gameEventsVftbl.function59 = nullsub;
	gameEventsVftbl.function60 = nullsub;
	gameEventsVftbl.function61 = nullsub;
	gameEventsVftbl.function62 = nullsub;
	gameEventsVftbl.function63 = nullsub;
	gameEventsVftbl.function64 = nullsub;
	gameEventsVftbl.function65 = nullsub;
	gameEventsVftbl.function66 = nullsub;
	gameEventsVftbl.function67 = nullsub;
	gameEventsVftbl.function68 = nullsub;
	gameEventsVftbl.function69 = nullsub;
	gameEventsVftbl.function70 = nullsub;
	gameEventsVftbl.function71 = nullsub;
	gameEventsVftbl.function72 = nullsub;
	gameEventsVftbl.function73 = nullsub;
	gameEventsVftbl.function74 = nullsub;
	gameEventsVftbl.function75 = nullsub;
	gameEventsVftbl.function76 = nullsub;
	gameEventsVftbl.function77 = nullsub;
	gameEventsVftbl.function78 = nullsub;
	gameEventsVftbl.function79 = nullsub;
	gameEventsVftbl.function80 = nullsub;
	gameEventsVftbl.function81 = nullsub;
	gameEventsVftbl.function82 = nullsub;
	gameEventsVftbl.function83 = nullsub;
	gameEventsVftbl.function84 = nullsub;
	gameEventsVftbl.function85 = nullsub;
	gameEventsVftbl.function86 = nullsub;
	gameEventsVftbl.function87 = nullsub;
	gameEventsVftbl.function88 = nullsub;
	gameEventsVftbl.function89 = nullsub;
	gameEventsVftbl.function90 = nullsub;
	gameEventsVftbl.function91 = nullsub;
	gameEventsVftbl.function92 = nullsub;
	gameEventsVftbl.function93 = nullsub;
	gameEventsVftbl.function94 = nullsub;
	gameEventsVftbl.function95 = nullsub;
	gameEventsVftbl.function96 = nullsub;
	gameEventsVftbl.function97 = nullsub;
	gameEventsVftbl.function98 = nullsub;
	gameEventsVftbl.function99 = nullsub;
	gameEventsVftbl.function100 = nullsub;
	gameEventsVftbl.function101 = nullsub;
	gameEventsVftbl.function102 = nullsub;
	gameEventsVftbl.function103 = nullsub;
	gameEventsVftbl.function104 = nullsub;
	gameEventsVftbl.function105 = nullsub;
	gameEventsVftbl.function106 = nullsub;
	gameEventsVftbl.function107 = nullsub;
	gameEventsVftbl.function108 = nullsub;
	gameEventsVftbl.function109 = nullsub;
	gameEventsVftbl.function110 = nullsub;
	gameEventsVftbl.function111 = nullsub;
	gameEventsVftbl.function112 = nullsub;
	gameEventsVftbl.function113 = nullsub;
	gameEventsVftbl.function114 = nullsub;
	gameEventsVftbl.function115 = nullsub;
	gameEventsVftbl.function116 = nullsub;
	gameEventsVftbl.function117 = nullsub;
	gameEventsVftbl.function118 = nullsub;
	gameEventsVftbl.function119 = nullsub;
	gameEventsVftbl.function120 = nullsub;
	gameEventsVftbl.function121 = nullsub;
	gameEventsVftbl.function122 = nullsub;
	//GUID* (__fastcall * GetGuid)(GameEvents*, GUID*) = nullsub;
	gameEventsVftbl.GetGuid = GetGuid;
	gameEventsVftbl.function124 = nullsub;
	gameEventsVftbl.function125 = nullsub;
	gameEventsVftbl.function126 = nullsub;



	HaloReach = LoadLibraryA("haloreach.dll");

	printf("0x%p", HaloReach);
	printf("0x180000000");
	assert(HaloReach);


	CreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(HaloReach, "CreateGameEngine");

	__int64 result = CreateGameEngine(&pHaloReachEngine);

	if (pHaloReachEngine)
	{
		pHaloReachEngine->vftbl->init_graphics(pHaloReachEngine, 0, 0, 0, 0);
		pHaloReachEngine->vftbl->init_thread(pHaloReachEngine, &gameEvents, reinterpret_cast<long long>(buffer2));

	}

}

void deinit_haloreach()
{

	FreeLibrary(HaloReach);
}

int main()
{
	init_haloreach();

	while (true)
	{
		Sleep(1);
	}

	//_aligned_free(pHaloReachEngine);

	//deinit_haloreach();
}