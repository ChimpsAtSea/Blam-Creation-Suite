#pragma once

class c_runtime_symbols
{
public:
	inline static uintptr_t get_base_virtual_address() { return static_cast<uintptr_t>(g_symbol_file_header ? g_symbol_file_header->preferred_load_address : 0); }
	static s_symbol_file_public* get_public_symbol_by_name(const char* symbol_name);
	static s_symbol_file_public* get_public_symbol_by_virtual_address(void* pointer);
	static s_symbol_file_header* g_symbol_file_header;
	static char* g_symbol_file_data;
	static size_t g_symbol_file_data_size;
};

