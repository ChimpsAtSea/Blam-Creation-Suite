#pragma once

typedef struct _MINIDUMP_HEADER MINIDUMP_HEADER;
typedef struct _MINIDUMP_DIRECTORY MINIDUMP_DIRECTORY;
typedef struct _MINIDUMP_MEMORY_LIST MINIDUMP_MEMORY_LIST;
typedef struct _MINIDUMP_MEMORY64_LIST MINIDUMP_MEMORY64_LIST;

class c_blamtoozle_minidump_tag_definition_reader :
	public c_blamtoozle_tag_definition_manager
{
public:
	c_blamtoozle_minidump_tag_definition_reader(const wchar_t* minidump_file_path);
	virtual ~c_blamtoozle_minidump_tag_definition_reader();

	virtual const char* va_to_pointer(ptr64 address);
	virtual const char* pa_to_pointer(ptr64 address);

	const wchar_t* minidump_file_path;
	union
	{
		void* minidump_data;
		const MINIDUMP_HEADER* minidump_header;
	};
	unsigned long long minidump_data_size;

	const MINIDUMP_DIRECTORY* minidump_directories;
	const MINIDUMP_DIRECTORY* minidump_memory_list_directory;
	const MINIDUMP_MEMORY_LIST* minidump_memory_list;
	const MINIDUMP_DIRECTORY* minidump_memory64_list_directory;
	const MINIDUMP_MEMORY64_LIST* minidump_memory64_list;

};
