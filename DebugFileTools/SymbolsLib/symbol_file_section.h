#pragma once

#pragma pack(push, 1)
struct s_symbol_file_section
{
	unsigned short section_index;
	unsigned long rva;
	unsigned long length;
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
