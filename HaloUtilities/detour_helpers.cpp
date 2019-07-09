#include "haloutilities-private-pch.h"

void init_detours()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
}

void end_detours()
{
	DetourTransactionCommit();
}

void nullsub()
{

}

void __create_hook(const char pName[], const char pModuleName[], size_t offset, size_t baseAddress, void* pHookFunction, void*& rpOriginal)
{
	assert(pHookFunction);

	HMODULE hModule = GetModuleHandleA(pModuleName);
	assert(hModule);

	PVOID pPointer = reinterpret_cast<char*>(hModule) + (offset - baseAddress);
	PVOID* ppPointer = reinterpret_cast<void**>(&pPointer);
	PVOID pDetour = reinterpret_cast<void*>(pHookFunction);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook %s. Reason: %s", pName, detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked %s", pName);
	}
}

void __create_dll_hook(const char pModuleName[], const char* pProcedureName, void* pHookFunction, void*& rpOriginal)
{
	assert(pHookFunction);

	// Find the function address
	HMODULE hModule = GetModuleHandleA(pModuleName);
	assert(hModule);
	FARPROC pProc = GetProcAddress(hModule, pProcedureName);
	assert(pProc);

	rpOriginal = (void*)pProc;

	PVOID* ppPointer = reinterpret_cast<void**>(&pProc);
	PVOID pDetour = reinterpret_cast<void*>(pHookFunction);
	LONG detourAttachResult = DetourAttach(ppPointer, pDetour);

	if (detourAttachResult)
	{
		const char* detourAttachResultStr = GetDetourResultStr(detourAttachResult);
		WriteLineVerbose("Failed to hook %s %s. Reason: %s", pModuleName, pProcedureName, detourAttachResultStr);
	}
	else
	{
		WriteLineVerbose("Successfully hooked %s %s", pModuleName, pProcedureName);
	}
}