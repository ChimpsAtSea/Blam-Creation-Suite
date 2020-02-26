#include "opusframework-private-pch.h"

bool IsEngineLoaded(Engine engine)
{
	const char* pGameExecutableStr = GetEngineModuleFileName(engine);
	return GetModuleHandle(pGameExecutableStr);
}

void* GetEngineMemoryAddress(Engine engine)
{
	switch (engine) // override for executable based engines which will always be the current module
	{
	case Engine::MCC:
	case Engine::Eldorado:
		static HINSTANCE current_module = GetModuleHandle(NULL);
		return current_module;
	}

	const char* pGameExecutableStr = GetEngineModuleFileName(engine);
	HMODULE hModule = GetModuleHandleA(pGameExecutableStr);
	return static_cast<void*>(hModule);
}