#pragma once

#pragma pack(push, 1)
struct s_symbol_file_header
{
	uint64_t public_symbols_count : 24;
	uint64_t static_symbols_count : 24;
	uint64_t sections_count : 16;
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
	uint32_t entry_point_rva;
	union
	{
		unsigned short entry_point_section_index;
		struct
		{
			uint64_t : 16;
			uint64_t preferred_load_address : 48;
		};
	};
};
#pragma pack(pop)
