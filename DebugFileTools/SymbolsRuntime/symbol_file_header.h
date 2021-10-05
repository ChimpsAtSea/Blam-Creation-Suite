#pragma once

#pragma pack(push, 1)
struct s_symbol_file_header
{
	unsigned long long public_symbols_count : 24;
	unsigned long long static_symbols_count : 24;
	unsigned long long sections_count : 16;
	union
	{
		uintptr_t public_symbols_offset;
		s_symbol_file_public* public_symbols;
	};
	union
	{
		uintptr_t static_symbols_offset;
		s_symbol_file_static* static_symbols;
	};
	union
	{
		uintptr_t sections_offset;
		s_symbol_file_section* sections;
	};

	union
	{
		uintptr_t binary_name_offset;
		const char* binary_name;
	};
	union
	{
		uintptr_t timestamp_string_offset;
		const char* timestamp_string;
	};
	unsigned long entry_point_rva;
	union
	{
		unsigned short entry_point_section_index;
		struct
		{
			unsigned long long : 16;
			unsigned long long preferred_load_address : 48;
		};
	};
};
#pragma pack(pop)
