#pragma once

typedef struct
{
	bool read_only;
	char* file_view_begin;
	char* file_view_end;
	uint64_t file_size;

} s_memory_mapped_file_info;

BCS_RESULT create_memory_mapped_file(const char* filepath, bool read_only, struct t_memory_mapped_file** file);
BCS_RESULT create_memory_mapped_file(const wchar_t* filepath, bool read_only, struct t_memory_mapped_file** file);
BCS_RESULT destroy_memory_mapped_file(struct t_memory_mapped_file* file);

BCS_RESULT get_memory_mapped_file_info(t_memory_mapped_file* file, s_memory_mapped_file_info* file_info);

