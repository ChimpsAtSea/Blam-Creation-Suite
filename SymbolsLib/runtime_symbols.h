#pragma once

class c_runtime_symbols
{
public:
	c_runtime_symbols(char* symbol_file_data, size_t symbol_file_data_size);

	static c_runtime_symbols& runtime();

	inline uintptr_t get_base_virtual_address() { return static_cast<uintptr_t>(symbol_file_header ? symbol_file_header->preferred_load_address : 0); }
	s_symbol_file_public* get_public_symbol_by_name(const char* symbol_name);
	s_symbol_file_public* get_public_symbol_by_relative_virtual_address(uint64_t relative_virtual_address);
	s_symbol_file_public* get_public_symbol_by_base_virtual_address(uint64_t relative_virtual_address);
	s_symbol_file_public* get_public_symbol_by_virtual_address(void* pointer);

protected:
	bool is_initialized;
	s_symbol_file_header* symbol_file_header;
	char* symbol_file_data;
	size_t symbol_file_data_size;

	void init();

private:
	static c_runtime_symbols* runtime_symbols;
	c_runtime_symbols();
};

