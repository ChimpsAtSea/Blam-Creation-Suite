#include "platform-private-pch.h"

HINSTANCE c_runtime_util::get_current_module()
{
	if (s_hInstance == NULL)
	{
		void* get_current_module_pointer = get_current_module;

		HMODULE hModule = NULL;
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, reinterpret_cast<LPCTSTR>(get_current_module_pointer), &hModule);
		ASSERT(hModule != NULL);

		s_hInstance = hModule;
	}
	return s_hInstance;
}

HINSTANCE c_runtime_util::s_hInstance = NULL;
