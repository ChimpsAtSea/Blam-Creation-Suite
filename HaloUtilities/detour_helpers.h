#pragma once

#include <utility>

extern void init_detours();
extern void end_detours();

template<typename Ta, typename Tb>
void create_hook(const char pName[], void* pTargetFunction, Ta hook, Tb& rOriginal)
{
	rOriginal = (Tb)(pTargetFunction);

	PVOID* ppPointer = reinterpret_cast<void**>(&rOriginal);
	PVOID pDetour = reinterpret_cast<void*>(hook);
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

template<size_t offset, typename Ta, typename Tb>
void create_hook(const char pModuleName[], size_t baseAddress, const char pName[], Ta hook, Tb& rOriginal)
{
	rOriginal = (Tb)(reinterpret_cast<char*>(GetModuleHandleA(pModuleName)) + (offset - baseAddress));

	PVOID* ppPointer = reinterpret_cast<void**>(&rOriginal);
	PVOID pDetour = reinterpret_cast<void*>(hook);
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

template<typename Ta, typename Tb>
void create_dll_hook(const char pModuleName[], const char* pProcedureName, Ta hook, Tb& rOriginal)
{
	// Find the function address
	HMODULE hModule = GetModuleHandleA(pModuleName);
	assert(hModule);
	FARPROC RegisterClassExAProc = GetProcAddress(hModule, pProcedureName);
	assert(RegisterClassExAProc);

	rOriginal = (Tb)RegisterClassExAProc;

	if (hook)
	{
		PVOID* ppPointer = reinterpret_cast<void**>(&rOriginal);
		PVOID pDetour = reinterpret_cast<void*>(hook);
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
}

template<size_t offset, typename T>
void populate_function_ptr(const char pModuleName[], size_t baseAddress, T& dest)
{
	// Find the function address
	char* const pBaseAddress = reinterpret_cast<char*>(GetModuleHandleA(pModuleName));
	char* const pFunctionAddress = pBaseAddress + (offset - baseAddress);

	dest = reinterpret_cast<T>(pFunctionAddress);
}

template<size_t offset>
void nop_address(const char pModuleName[], size_t baseAddress, size_t count)
{
	// Find the function address
	char* const pBaseAddress = reinterpret_cast<char*>(GetModuleHandleA(pModuleName));
	char* const pDataAddress = pBaseAddress + (offset - baseAddress);

	for (size_t i = 0; i < count; i++)
	{
		pDataAddress[i] = 0x90;
	}
}