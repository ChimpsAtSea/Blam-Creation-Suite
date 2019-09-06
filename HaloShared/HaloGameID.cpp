#include "haloshared-private-pch.h"

bool IsHaloExecutableLoaded(HaloGameID gameID)
{
	const char* pGameExecutableStr = GetHaloExecutableString(gameID);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetLoadedHaloModule(HaloGameID gameID)
{
	const char* pGameExecutableStr = GetHaloExecutableString(gameID);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}