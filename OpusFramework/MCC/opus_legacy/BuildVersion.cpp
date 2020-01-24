#include "opusframework-private-pch.h"

bool IsEngineLoaded(EngineVersion engineVersion)
{
	const char* pGameExecutableStr = GetEngineFilename(engineVersion);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetEngineMemoryAddress(EngineVersion engineVersion)
{
	const char* pGameExecutableStr = GetEngineFilename(engineVersion);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}