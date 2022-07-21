#pragma once

class c_runtime_symbols
{
public:
	c_runtime_symbols(
		HMODULE module_handle,
		void* symbol_file_data, 
		uint64_t symbol_file_data_size);
	~c_runtime_symbols();

	inline uintptr_t get_base_virtual_address() { return static_cast<uintptr_t>(symbol_file_header ? symbol_file_header->preferred_load_address : 0); }
	s_symbol_file_public* get_public_symbol_by_name(const char* symbol_name);
	s_symbol_file_public* get_public_symbol_by_relative_virtual_address(uint64_t relative_virtual_address);
	s_symbol_file_public* get_public_symbol_by_base_virtual_address(uint64_t relative_virtual_address);
	s_symbol_file_public* get_public_symbol_by_virtual_address(const void* pointer);

	BCS_RESULT validate_public_symbols();
	BCS_RESULT validate_static_symbols();
protected:
	HMODULE module_handle;
	s_symbol_file_header* symbol_file_header;
	void* symbol_file_buffer;
	uint64_t symbol_file_buffer_size;

	void init();
};

