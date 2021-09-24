#pragma once

struct s_symbol_file_header_temp
{
	const char* binary_name;
	const char* timestamp_string;
	unsigned long long preferred_load_address;
	unsigned long entry_point_section_index;
	unsigned long entry_point_rva;
	std::vector<s_symbol_file_section_temp> sections;
	std::vector<s_symbol_file_public_temp> public_symbols;
	std::vector<s_symbol_file_static_temp> static_symbols;
	std::mutex mutex;
};
