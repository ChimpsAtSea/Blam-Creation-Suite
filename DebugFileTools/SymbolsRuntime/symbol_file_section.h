#pragma once

#pragma pack(push, 1)
struct s_symbol_file_section
{
	unsigned short section_index;
	uint32_t rva;
	uint32_t length;
	union
	{
		uintptr_t name_string_offset;
		const char* name_string;
	};
	union
	{
		uintptr_t class_string_offset;
		const char* class_string;
	};
};
#pragma pack(pop)
