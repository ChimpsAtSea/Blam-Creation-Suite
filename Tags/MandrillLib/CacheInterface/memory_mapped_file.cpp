#include "mandrilllib-private-pch.h"

struct t_memory_mapped_file
{
	HANDLE file_handle;
	HANDLE file_map_handle;
	QWORD file_size;
	void* file_view;
	bool is_read_only;
};

BCS_RESULT create_memory_mapped_file(const char* filepath, bool read_only, t_memory_mapped_file** file)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_CHAR_TO_WIDECHAR_STACK(filepath, filepath_wc);
	return create_memory_mapped_file(filepath, read_only, file);
}

BCS_RESULT create_memory_mapped_file(const wchar_t* filepath, bool read_only, t_memory_mapped_file** file)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(read_only));
	BCS_VALIDATE_ARGUMENT(file);

	if (!read_only)
	{
		return BCS_E_NOT_IMPLEMENTED; // #TODO
	}

	HANDLE file_handle = CreateFileW(filepath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		// #TODO: include GetLastError
		return BCS_E_FAIL;
	}

	LARGE_INTEGER file_size;
	BOOL get_file_size_result = GetFileSizeEx(file_handle, &file_size);
	if (get_file_size_result == FALSE)
	{
		// #TODO: include GetLastError ???
		return BCS_E_FAIL;
	}

	HANDLE file_map_handle = CreateFileMappingW(file_handle, NULL, PAGE_READONLY, file_size.HighPart, file_size.LowPart, NULL);
	if (file_map_handle == INVALID_HANDLE_VALUE)
	{
		// #TODO: include GetLastError
		return BCS_E_FAIL;
	}

	void* file_view = MapViewOfFile(file_map_handle, FILE_MAP_READ, 0, 0, static_cast<SIZE_T>(file_size.QuadPart));
	if (file_map_handle == INVALID_HANDLE_VALUE)
	{
		// #TODO: include GetLastError
		return BCS_E_FAIL;
	}

	t_memory_mapped_file& file_storage = *(*file = new t_memory_mapped_file());
	file_storage.file_handle = file_handle;
	file_storage.file_map_handle = file_map_handle;
	file_storage.file_size = file_size.HighPart;
	file_storage.file_view = file_view;

	return BCS_S_OK;
}

BCS_RESULT destroy_memory_mapped_file(t_memory_mapped_file* file)
{
	if (file->file_map_handle)
	{
		BOOL unmap_view_of_file_result = UnmapViewOfFile(file->file_map_handle);
		if (unmap_view_of_file_result == FALSE)
		{
			// #TODO: include GetLastError ???
			return BCS_E_FAIL;
		}
	}

	if (file->file_handle)
	{
		BOOL close_handle_result = CloseHandle(file->file_handle);
		if (close_handle_result == FALSE)
		{
			// #TODO: include GetLastError ???
			return BCS_E_FAIL;
		}
	}

	delete file;

	return BCS_S_OK;
}

BCS_RESULT get_memory_mapped_file_info(t_memory_mapped_file* file, s_memory_mapped_file_info* file_info)
{
	BCS_VALIDATE_ARGUMENT(file);
	BCS_VALIDATE_ARGUMENT(file_info);

	file_info->read_only = file->is_read_only;
	file_info->file_view_begin = static_cast<char*>(file->file_view);
	file_info->file_view_end = reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(file->file_view) + static_cast<uintptr_t>(file->file_size));
	file_info->file_size = file->file_size;

	return BCS_S_OK;
}
