#pragma once

#include <utility>

extern void init_detours();
extern void end_detours();

void __create_hook(const char pName[], const char pModuleName[], size_t offset, size_t baseAddress, void* pHookFunction, void*& rpOriginal);
void __create_dll_hook(const char pModuleName[], const char* pProcedureName, void* pHookFunction, void*& rpOriginal);

template<size_t offset, typename Ta, typename Tb>
void create_hook(const char pModuleName[], size_t baseAddress, const char pName[], Ta hook, Tb& original)
{

	void* pOriginalPtr = nullptr;
	__create_hook(pName, pModuleName, offset, baseAddress, hook, pOriginalPtr);
	original = reinterpret_cast<Tb>(pOriginalPtr);
}

template<typename Ta, typename Tb>
void create_dll_hook(const char pModuleName[], const char* pProcedureName, Ta hook, Tb& original)
{

	void* pOriginalPtr = nullptr;
	__create_dll_hook(pModuleName, pProcedureName, hook, pOriginalPtr);
	original = reinterpret_cast<Tb>(pOriginalPtr);
}

template<size_t offset, typename T>
void populate_function_ptr(const char pModuleName[], size_t baseAddress, T& dest)
{
	// Find the function address
	const char* const pBaseAddress = reinterpret_cast<char*>(GetModuleHandleA(pModuleName));
	const char* const pFunctionAddress = pBaseAddress + (offset - baseAddress);

	dest = reinterpret_cast<T>(pFunctionAddress);
}

extern void nullsub();

