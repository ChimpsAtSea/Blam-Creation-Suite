#include "opusframework-private-pch.h"

bool IsEngineLoaded(EngineVersion engineVersion)
{
	const char* pGameExecutableStr = GetEngineModuleFileName(engineVersion);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetEngineMemoryAddress(EngineVersion engineVersion)
{
	switch (engineVersion) // override for executable based engines which will always be the current module
	{
	case EngineVersion::MCC:
	case EngineVersion::Eldorado:
		static HINSTANCE current_module = GetModuleHandle(NULL);
		return current_module;
	}

	const char* pGameExecutableStr = GetEngineModuleFileName(engineVersion);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}