#include "platform-private-pch.h"

static void* current_process_module;

BCS_RESULT register_process_module(void* process_module)
{
	BCS_VALIDATE_ARGUMENT(process_module);
	current_process_module = process_module;
	return BCS_S_OK;
}

BCS_RESULT register_process_module_by_pointer(void* pointer)
{
	BCS_VALIDATE_ARGUMENT(pointer);

	BCS_RESULT rs = BCS_S_OK;

	HMODULE process_module = NULL;
	BOOL get_module_handle_result = GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, reinterpret_cast<LPCTSTR>(pointer), &process_module);
	if (get_module_handle_result == FALSE)
	{
		return BCS_E_FAIL;
	}
	if (process_module == NULL)
	{
		return BCS_E_FATAL;
	}
	
	if (BCS_FAILED(rs = register_process_module(process_module)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT get_process_module(void*& process_module)
{
	if (current_process_module == nullptr)
	{
		// #TODO: this is pretty terrible!
		// #TODO: fix with custom crt?
		current_process_module = GetModuleHandleA(NULL); 
	}
	process_module = current_process_module;
	return BCS_S_OK;
}
