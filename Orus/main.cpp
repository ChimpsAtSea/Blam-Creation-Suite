#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

HMODULE HaloReach; //haloreach.dll

typedef signed __int64(__fastcall CreateGameEngineFunc)(void** a1);
CreateGameEngineFunc* CreateGameEngine = nullptr;

void* pHaloReachEngine = nullptr;
__int64 buffer[1024 * 1024 * 32] = {};
__int64 buffer2[1024 * 1024 * 32] = {};

void init_haloreach()
{
	HaloReach = LoadLibraryA("haloreach.dll");
	assert(HaloReach);

	CreateGameEngine = (CreateGameEngineFunc*)GetProcAddress(HaloReach, "CreateGameEngine");

	__int64 result = CreateGameEngine(&pHaloReachEngine);

	if (pHaloReachEngine)
	{

		(**(void(__fastcall * **)(ULONG_PTR, __int64, __int64, __int64, __int64))pHaloReachEngine)(
			reinterpret_cast<ULONG_PTR>(pHaloReachEngine),
			0,
			0,
			0,
			0);

		(*(void(__fastcall * *)(ULONG_PTR, __int64*, __int64*))(*(__int64*)pHaloReachEngine + 8i64))(
			reinterpret_cast<ULONG_PTR>(pHaloReachEngine),
			buffer,
			buffer2);


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