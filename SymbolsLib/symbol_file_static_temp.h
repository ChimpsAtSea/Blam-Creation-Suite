#pragma once

struct s_symbol_file_static_temp
{
	uint32_t section_index;
	uint32_t rva;
	uint64_t rva_plus_base;
	char lib_and_object[256];

	char symbol_name[512];
#ifndef _DEBUG
	char complete_symbol_name[2048];
#endif
	char mangled_symbol_name_buffer[2048];

	s_symbol_file_static* static_symbol;
};
