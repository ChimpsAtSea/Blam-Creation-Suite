#include "opusframework-private-pch.h"

bool IsHaloExecutableLoaded(BuildVersion buildVersion)
{
	const char* pGameExecutableStr = GetHaloExecutableString(buildVersion);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetLoadedHaloModule(BuildVersion buildVersion)
{
	const char* pGameExecutableStr = GetHaloExecutableString(buildVersion);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}