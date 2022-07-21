#pragma once

struct s_symbol_file_public_temp
{
	uint32_t section_index;
	uint32_t rva;
	uint64_t rva_plus_base;

	static constexpr size_t k_lib_and_object_size = 256;
	static constexpr size_t k_symbol_name_size = 1024;
	static constexpr size_t k_complete_symbol_name_size = 1536;
	static constexpr size_t k_mangled_symbol_name_buffer_size = 512;
	static constexpr size_t k_auxillary_size = 256;

	//std::string lib_and_object;
	//std::string symbol_name;
	//std::string complete_symbol_name;
	//std::string mangled_symbol_name_buffer;

	
	char lib_and_object[k_lib_and_object_size];

	char symbol_name[k_symbol_name_size];
#ifndef _DEBUG
	char complete_symbol_name[k_complete_symbol_name_size];
#endif
	char mangled_symbol_name_buffer[k_mangled_symbol_name_buffer_size];

	char auxillary[4][k_auxillary_size];

	s_symbol_file_public* public_symbol;
};
