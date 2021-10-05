#include "symbolsruntime-private-pch.h"

#pragma optimize("", off)

struct s_symbol_file_instance
{
	HMODULE module_handle;
	c_runtime_symbols* runtime_symbols;
	void* symbol_binary_buffer;
	unsigned long long symbol_binary_buffer_size;
};

static unsigned long num_symbol_file_instances;
static s_symbol_file_instance symbol_file_instances[64];

static BCS_RESULT symbol_manager_get_module_handle_by_pointer(const void* pointer, HMODULE& module_handle)
{
	BOOL get_module_handle_result = GetModuleHandleExW(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
		reinterpret_cast<LPCWSTR>(pointer),
		&module_handle);
	if (get_module_handle_result == 0)
	{
		return BCS_E_MODULE_NOT_FOUND;
	}
	return BCS_S_OK;
}

static BCS_RESULT symbol_manager_get_symbol_file_instance_by_module_handle(HMODULE module_handle, s_symbol_file_instance*& out_symbol_file_instance)
{
	// #TODO: replace this with a map function?

	for (unsigned long symbol_file_instance_index = 0; symbol_file_instance_index < num_symbol_file_instances; symbol_file_instance_index++)
	{
		s_symbol_file_instance& symbol_file_instance = symbol_file_instances[symbol_file_instance_index];

		if (symbol_file_instance.module_handle == module_handle)
		{
			out_symbol_file_instance = &symbol_file_instance;
			return BCS_S_OK;
		}
	}
	return BCS_E_NOT_FOUND;
}

static BCS_RESULT symbol_manager_load_symbol_file_instance_by_module_handle(HMODULE module_handle, s_symbol_file_instance*& out_symbol_file_instance)
{
	char symbol_binary_filepath[MAX_PATH];
	GetModuleFileNameA(module_handle, symbol_binary_filepath, _countof(symbol_binary_filepath));
	strcat(symbol_binary_filepath, ".sym");

	void* symbol_binary_buffer;
	unsigned long long symbol_binary_buffer_size;
	if (BCS_FAILED(filesystem_read_file_to_memory(symbol_binary_filepath, symbol_binary_buffer, symbol_binary_buffer_size)))
	{
		BCS_FAIL_RETURN(resources_read_resource_to_memory(_bcs_resource_type_symbols_blob, symbol_binary_buffer, symbol_binary_buffer_size));
	}
	else
	{
		console_write_line_with_debug("Loaded '%s' runtime symbols.", symbol_binary_filepath);
	}

	unsigned long symbol_file_instance_index = num_symbol_file_instances++;
	if (symbol_file_instance_index >= _countof(symbol_file_instances))
	{
		return BCS_E_OUT_OF_RANGE;
	}

	s_symbol_file_instance& symbol_file_instance = symbol_file_instances[symbol_file_instance_index];

	symbol_file_instance.module_handle = module_handle;
	symbol_file_instance.runtime_symbols = new c_runtime_symbols(module_handle, symbol_binary_buffer, symbol_binary_buffer_size);
	symbol_file_instance.symbol_binary_buffer = symbol_binary_buffer;
	symbol_file_instance.symbol_binary_buffer_size = symbol_binary_buffer_size;

	out_symbol_file_instance = &symbol_file_instance;

	return BCS_S_OK;
}

BCS_RESULT symbol_manager_get_public_symbol_by_pointer(const void* pointer, s_symbol_file_public*& public_symbol)
{
	HMODULE module_handle;
	BCS_FAIL_RETURN(symbol_manager_get_module_handle_by_pointer(pointer, module_handle));

	s_symbol_file_instance* symbol_file_instance;
	if (BCS_FAILED(symbol_manager_get_symbol_file_instance_by_module_handle(module_handle, symbol_file_instance)))
	{
		BCS_FAIL_RETURN(symbol_manager_load_symbol_file_instance_by_module_handle(module_handle, symbol_file_instance));
	}

	public_symbol = symbol_file_instance->runtime_symbols->get_public_symbol_by_virtual_address(pointer);
	if (public_symbol == nullptr)
	{
		return BCS_E_NOT_FOUND; // #TODO: refactor c_runtime_symbols and pipe the BCS_RESULT back out
	}
	return BCS_S_OK;
}

BCS_DEBUG_API BCS_RESULT symbol_manager_get_public_symbol_by_rva_plus_base(const void* module_instance, unsigned long long rva_plus_base, s_symbol_file_public*& public_symbol)
{
	return BCS_E_NOT_IMPLEMENTED;
}