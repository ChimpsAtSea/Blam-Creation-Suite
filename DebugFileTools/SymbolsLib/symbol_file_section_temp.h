#pragma once

struct s_symbol_file_section_temp
{
	uint32_t section_index;
	uint32_t rva;
	uint32_t length;
	char name_string[32];
	char class_string[32];
	s_symbol_file_section* section;
};
