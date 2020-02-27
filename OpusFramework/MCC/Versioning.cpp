#include "opusframework-private-pch.h"

bool IsEngineLoaded(e_engine_type engine_type)
{
	const char* pGameExecutableStr = GetEngineModuleFileName(engine_type);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetEngineMemoryAddress(e_engine_type engine_type)
{
	switch (engine_type) // override for executable based engines which will always be the current module
	{
	case _engine_type_mcc:
	case _engine_type_eldorado:
		static HINSTANCE current_module = GetModuleHandle(NULL);
		return current_module;
	}

	const char* pGameExecutableStr = GetEngineModuleFileName(engine_type);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}