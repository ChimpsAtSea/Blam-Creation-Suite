#pragma once

#include <utility>

extern const char* GetDetourResultStr(LONG detourAttachResult);
extern void init_detours();
extern void end_detours();

extern void memcpy_virtual(
	const void* dst,
	const void* src,
	size_t size
);

extern void copy_from_address(EngineVersion engineVersion, BuildVersion buildVersion, intptr_t offset, void *data, size_t length);
extern void copy_to_address(EngineVersion engineVersion, BuildVersion buildVersion, intptr_t offset, void* data, size_t length);
extern void nop_address(EngineVersion engineVersion, BuildVersion buildVersion, intptr_t offset, size_t count);

#define roundup(n, denominator) (((n + denominator - 1) / denominator ) * denominator )

//TODO: Accept an instruction type to look for
template<typename T>
T* BackpropagateFunctionPointer(T* instructionPtr, int maxSteps)
{
	static const size_t kFunctionAlignmentSize = 16;

	const char* currentPointer = reinterpret_cast<const char*>(instructionPtr);

	currentPointer = reinterpret_cast<char*>(roundup(reinterpret_cast<size_t>(currentPointer), kFunctionAlignmentSize));

	for (int i = 0; i < maxSteps; i++)
	{
		currentPointer -= kFunctionAlignmentSize;


		char currentByte = currentPointer[0];
		char peekBackByte = currentPointer[-1];
		// assuming that this function will be aligned and have a missing space! this should be improved. Use IDA database?
		if (peekBackByte == char(0xCC))
		{
			switch (currentByte)
			{
			case 0x48: // TEST
				// looking for a push instruction!??
				//TODO: Identify the correct cases
				//TODO: Ensure 0x40 is correct
			case 0x40: //PUSH 
			case 0x55: //PUSH
			case 0x56: //PUSH
			case 0x57: //PUSH
				return reinterpret_cast<T*>(reinterpret_cast<size_t>(currentPointer));
			}
		}
	}

	return nullptr;
}

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

template<typename Ta, typename Tb>
LONG create_hook(EngineVersion engineVersion, BuildVersion buildVersion, size_t offset, const char pName[], Ta hook, Tb& rOriginal)
{
	if (offset == -1)
	{
		return 0;

	}

	char* const pModule = reinterpret_cast<char*>(GetEngineMemoryAddress(engineVersion));
	size_t const baseAddress = GetBuildBaseAddress(buildVersion);

	rOriginal = (Tb)(pModule + (offset - baseAddress));

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
	return detourAttachResult;
}

template<BuildVersion buildVersion, size_t offset, typename Ta, typename Tb>
LONG create_hook(const char pName[], Ta hook, Tb& rOriginal)
{
	return create_hook(buildVersion, offset, pName, hook, rOriginal);
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

template<typename T>
void populate_function_ptr(const char pModuleName[], size_t baseAddress, size_t offset, T& dest)
{
	// Find the function address
	char* const pBaseAddress = reinterpret_cast<char*>(GetModuleHandleA(pModuleName));
	char* const pFunctionAddress = pBaseAddress + (offset - baseAddress);

	dest = reinterpret_cast<T>(pFunctionAddress);
}

template<size_t offset, typename T>
void populate_function_ptr(const char pModuleName[], size_t baseAddress, T& dest)
{
	populate_function_ptr(pModuleName, baseAddress, offset, dest);
}

template<BuildVersion buildVersion, size_t offset, typename T>
void populate_function_ptr(T& dest)
{
	// Find the function address
	char* const pModule = reinterpret_cast<char*>(GetBuildBaseAddress(buildVersion));
	size_t const baseAddress = GetBuildBaseAddress(buildVersion);
	char* const pFunctionAddress = pModule + (offset - baseAddress);

	dest = reinterpret_cast<T>(pFunctionAddress);
}

template<size_t offset, typename T>
T get_function_ptr(const char pModuleName[], size_t baseAddress)
{
	T result = nullptr;
	populate_function_ptr<offset, T>(pModuleName, baseAddress, result);
	return result;
}

template<BuildVersion buildVersion, size_t offset, typename T>
T get_function_ptr()
{
	T result = nullptr;
	populate_function_ptr<buildVersion, offset, T>(result);
	return result;
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