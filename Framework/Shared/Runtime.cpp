#include "shared-private-pch.h"

HINSTANCE Runtime::GetCurrentModule()
{
	if (s_hInstance == NULL)
	{
		void* getCurrentModulePtr = GetCurrentModule;

		HMODULE hModule = NULL;
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, reinterpret_cast<LPCTSTR>(getCurrentModulePtr), &hModule);
		ASSERT(hModule != NULL);

		s_hInstance = hModule;
	}
	return s_hInstance;
}

HINSTANCE Runtime::s_hInstance = NULL;
