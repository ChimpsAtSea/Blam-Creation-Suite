#include "symbolsruntime-private-pch.h"

#define get_rva_plus_base(data, index) data[index].rva_plus_base

c_runtime_symbols::c_runtime_symbols(
	HMODULE module_handle, 
	void* symbol_file_data, 
	uint64_t symbol_file_data_size) :
	module_handle(module_handle),
	symbol_file_header(static_cast<s_symbol_file_header*>(symbol_file_data)),
	symbol_file_buffer(symbol_file_data),
	symbol_file_buffer_size(symbol_file_data_size)
{
	init();
}

c_runtime_symbols::~c_runtime_symbols()
{

}

void c_runtime_symbols::init()
{
	if (symbol_file_header == nullptr)
	{
		return;
	}

	uintptr_t symbol_file_data_address = reinterpret_cast<uintptr_t>(symbol_file_header);

	symbol_file_header->sections_offset += symbol_file_data_address;
	symbol_file_header->public_symbols_offset += symbol_file_data_address;
	symbol_file_header->static_symbols_offset += symbol_file_data_address;
	symbol_file_header->binary_name_offset += symbol_file_data_address;
	symbol_file_header->timestamp_string_offset += symbol_file_data_address;

	for (uint32_t section_index = 0; section_index < symbol_file_header->sections_count; section_index++)
	{
		s_symbol_file_section& section = symbol_file_header->sections[section_index];
		section.class_string_offset += symbol_file_data_address;
		section.name_string_offset += symbol_file_data_address;
	}

	for (uint32_t public_symbol_index = 0; public_symbol_index < symbol_file_header->public_symbols_count; public_symbol_index++)
	{
		s_symbol_file_public& public_symbol = symbol_file_header->public_symbols[public_symbol_index];
		public_symbol.lib_and_object_offset += symbol_file_data_address;
		public_symbol.mangled_symbol_name_offset += symbol_file_data_address;
		public_symbol.symbol_name_offset += symbol_file_data_address;
#ifndef _DEBUG
		public_symbol.complete_symbol_name_offset += symbol_file_data_address;
#endif
	}

	for (uint32_t static_symbol_index = 0; static_symbol_index < symbol_file_header->static_symbols_count; static_symbol_index++)
	{
		s_symbol_file_static& static_symbol = symbol_file_header->static_symbols[static_symbol_index];
		static_symbol.lib_and_object_offset += symbol_file_data_address;
		static_symbol.mangled_symbol_name_offset += symbol_file_data_address;
		static_symbol.symbol_name_offset += symbol_file_data_address;
#ifndef _DEBUG
		static_symbol.complete_symbol_name_offset += symbol_file_data_address;
#endif
	}

	BCS_RESULT validate_public_symbols_result = validate_public_symbols();
	ASSERT(BCS_SUCCEEDED(validate_public_symbols_result));
	BCS_RESULT validate_static_symbols_result = validate_static_symbols();
	ASSERT(BCS_SUCCEEDED(validate_static_symbols_result));
}

BCS_RESULT c_runtime_symbols::validate_public_symbols()
{
	uint64_t last = 0;
	for (uint32_t public_symbol_index = 0; public_symbol_index < symbol_file_header->public_symbols_count; public_symbol_index++)
	{
		s_symbol_file_public& public_symbol = symbol_file_header->public_symbols[public_symbol_index];

		if (last > public_symbol.rva_plus_base)
		{
			return BCS_E_FAIL;
		}
		last = public_symbol.rva_plus_base;
	}
	return BCS_S_OK;
}

BCS_RESULT c_runtime_symbols::validate_static_symbols()
{
	uint64_t last = 0;
	for (uint32_t static_symbol_index = 0; static_symbol_index < symbol_file_header->static_symbols_count; static_symbol_index++)
	{
		s_symbol_file_static& static_symbol = symbol_file_header->static_symbols[static_symbol_index];

		if (last > static_symbol.rva_plus_base)
		{
			return BCS_E_FAIL;
		}
		last = static_symbol.rva_plus_base;
	}
	return BCS_S_OK;
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_name(const char* symbol_name)
{
	if (symbol_file_header == nullptr)
	{
		return nullptr;
	}

	for (uint32_t public_symbol_index = 0; public_symbol_index < symbol_file_header->public_symbols_count; public_symbol_index++)
	{
		s_symbol_file_public& public_symbol = symbol_file_header->public_symbols[public_symbol_index];

		if (strcmp(public_symbol.symbol_name, symbol_name) == 0)
		{
			return &public_symbol;
		}
	}

	return nullptr;
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_relative_virtual_address(uint64_t relative_virtual_address)
{
	if (symbol_file_header == nullptr)
	{
		return nullptr;
	}

	uint64_t base_virtual_adress = symbol_file_header->preferred_load_address;
	uint64_t relative_virtual_address_plus_base = base_virtual_adress + relative_virtual_address;

	s_symbol_file_public* public_symbols = symbol_file_header->public_symbols;

	s_symbol_file_public* public_symbol_search_result = nullptr;
	_binary_search(
		symbol_file_header->public_symbols,
		symbol_file_header->public_symbols_count,
		get_rva_plus_base,
		relative_virtual_address_plus_base,
		public_symbol_search_result);
	return public_symbol_search_result;
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_base_virtual_address(uint64_t relative_virtual_address)
{
	if (symbol_file_header == nullptr)
	{
		return nullptr;
	}

	uint64_t base_virtual_adress = symbol_file_header->preferred_load_address;
	return get_public_symbol_by_relative_virtual_address(relative_virtual_address - base_virtual_adress);
}

s_symbol_file_public* c_runtime_symbols::get_public_symbol_by_virtual_address(const void* pointer)
{
	if (symbol_file_header == nullptr)
	{
		return nullptr;
	}

	uint64_t virtual_address = reinterpret_cast<uintptr_t>(pointer);
	uint64_t module_address = reinterpret_cast<uintptr_t>(module_handle);
	uint64_t relative_virtual_address = virtual_address - module_address;

	return get_public_symbol_by_relative_virtual_address(relative_virtual_address);
}
