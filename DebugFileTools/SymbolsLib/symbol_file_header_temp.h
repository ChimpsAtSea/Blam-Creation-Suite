#pragma once

struct s_symbol_file_header_temp
{
	const char* binary_name;
	const char* timestamp_string;
	uint64_t preferred_load_address;
	uint32_t entry_point_section_index;
	uint32_t entry_point_rva;
	std::vector<s_symbol_file_section_temp> sections;
	std::vector<s_symbol_file_public_temp> public_symbols;
	std::vector<s_symbol_file_static_temp> static_symbols;
};
