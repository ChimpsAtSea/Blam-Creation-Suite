#include "opusframework-private-pch.h"

bool IsHaloExecutableLoaded(EngineVersion engineVersion)
{
	const char* pGameExecutableStr = GetHaloExecutableString(engineVersion);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetLoadedHaloModule(EngineVersion engineVersion)
{
	const char* pGameExecutableStr = GetHaloExecutableString(engineVersion);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}