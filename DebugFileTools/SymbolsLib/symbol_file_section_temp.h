#pragma once

struct s_symbol_file_section_temp
{
	unsigned long section_index;
	unsigned long rva;
	unsigned long length;
	char name_string[32];
	char class_string[32];
	s_symbol_file_section* section;
};
