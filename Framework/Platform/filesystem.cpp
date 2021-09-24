#include "platform-private-pch.h"


const char* filesystem_extract_filepath_filename(const char* filepath)
{
	return PathFindFileNameA(filepath);
}

const wchar_t* filesystem_extract_filepath_filename(const wchar_t* filepath)
{
	return PathFindFileNameW(filepath);
}

BCS_RESULT filesystem_filepath_exists(const char* filepath)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BOOL file_path_exists = PathFileExistsA(filepath);
	if (!file_path_exists)
	{
		return BCS_E_NOT_FOUND;
	}
	return BCS_S_OK;
}

BCS_RESULT filesystem_filepath_exists(const wchar_t* filepath)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BOOL file_path_exists = PathFileExistsW(filepath);
	if (!file_path_exists)
	{
		return BCS_E_NOT_FOUND;
	}
	return BCS_S_OK;
}

BCS_RESULT filesystem_directory_exists(const char* filepath)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	DWORD file_attributes = GetFileAttributesA(filepath);
	if (file_attributes == INVALID_FILE_ATTRIBUTES)
	{
		return BCS_E_NOT_FOUND;
	}
	if (file_attributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		return BCS_S_OK;
	}
	return BCS_E_FAIL;
}

BCS_RESULT filesystem_directory_exists(const wchar_t* filepath)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	DWORD file_attributes = GetFileAttributesW(filepath);
	if (file_attributes == INVALID_FILE_ATTRIBUTES)
	{
		return BCS_E_NOT_FOUND;
	}
	if (file_attributes & FILE_ATTRIBUTE_DIRECTORY)
	{
		return BCS_S_OK;
	}
	return BCS_E_FAIL;
}

BCS_RESULT filesystem_get_file_size(const char* filepath, unsigned long long& out_file_size)
{
	BCS_RESULT rs = BCS_S_OK;

	HANDLE file_handle = CreateFileA(
		filepath,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		DWORD last_error = GetLastError();
		return BCS_E_FAIL;
	}

	ULARGE_INTEGER file_size;
	file_size.LowPart = GetFileSize(file_handle, &file_size.HighPart);
	out_file_size = file_size.QuadPart;

	BOOL close_handle_result = CloseHandle(file_handle);
	if (close_handle_result == FALSE)
	{
		rs = BCS_E_CLEANUP_FAIL;
	}

	return rs;
}

BCS_RESULT filesystem_get_file_size(const wchar_t* filepath, unsigned long long& out_file_size)
{
	BCS_RESULT rs = BCS_S_OK;

	HANDLE file_handle = CreateFileW(
		filepath,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		DWORD last_error = GetLastError();
		return BCS_E_FAIL;
	}

	ULARGE_INTEGER file_size;
	file_size.LowPart = GetFileSize(file_handle, &file_size.HighPart);
	out_file_size = file_size.QuadPart;

	BOOL close_handle_result = CloseHandle(file_handle);
	if (close_handle_result == FALSE)
	{
		rs = BCS_E_CLEANUP_FAIL;
	}

	return rs;
}

static BCS_RESULT filesystem_copy_memory_mapped_file_to_buffer(t_memory_mapped_file* file, void* buffer, unsigned long long& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	s_memory_mapped_file_info file_info;
	if (BCS_FAILED(rs = get_memory_mapped_file_info(file, file_info)))
	{
		return rs;
	}

	unsigned long long read_bytes = __min(buffer_size, file_info.file_size);
	memcpy(buffer, file_info.file_view_begin, read_bytes);
	buffer_size = read_bytes;

	if (BCS_FAILED(rs = destroy_memory_mapped_file(file)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT filesystem_copy_file_to_buffer(const char* filepath, void* buffer, unsigned long long& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	t_memory_mapped_file* file;
	if (BCS_FAILED(rs = create_memory_mapped_file(filepath, true, file)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = filesystem_copy_memory_mapped_file_to_buffer(file, buffer, buffer_size)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT filesystem_copy_file_to_buffer(const wchar_t* filepath, void* buffer, unsigned long long& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	t_memory_mapped_file* file;
	if (BCS_FAILED(rs = create_memory_mapped_file(filepath, true, file)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = filesystem_copy_memory_mapped_file_to_buffer(file, buffer, buffer_size)))
	{
		return rs;
	}

	return rs;
}

static BCS_RESULT filesystem_read_file_to_memory(HANDLE file_handle, void*& buffer, unsigned long long& buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	ULARGE_INTEGER file_size;
	file_size.LowPart = GetFileSize(file_handle, &file_size.HighPart);
	buffer_size = file_size.QuadPart;

	if (buffer_size == 0)
	{
		buffer = nullptr;
	}
	else
	{
		char* file_data_buffer = new char[buffer_size];
		buffer = file_data_buffer;
		unsigned long long number_of_bytes_remaining = file_size.QuadPart;
		while (number_of_bytes_remaining > 0)
		{
			DWORD number_of_bytes_to_read = static_cast<DWORD>(__min(number_of_bytes_remaining, 0x40000000)); // max 1GiB per iteration
			DWORD number_of_bytes_read = 0;
			BOOL read_file_result = ReadFile(file_handle, file_data_buffer, number_of_bytes_to_read, &number_of_bytes_read, NULL);
			if (read_file_result == FALSE)
			{
				rs = BCS_E_FAIL;
				break;
			}
			file_data_buffer += number_of_bytes_read;
			number_of_bytes_remaining -= number_of_bytes_read;
		}
	}

	BOOL close_handle_result = CloseHandle(file_handle);
	if (close_handle_result == FALSE)
	{
		rs = BCS_E_CLEANUP_FAIL;
	}

	if (BCS_FAILED(rs))
	{
		delete buffer;
		buffer = nullptr;
		buffer_size = 0;
	}

	return rs;
}

BCS_RESULT filesystem_read_file_to_memory(const char* filepath, void*& buffer, unsigned long long& buffer_size)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	//BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	HANDLE file_handle = CreateFileA(
		filepath,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		DWORD last_error = GetLastError();
		return BCS_E_FAIL;
	}

	return filesystem_read_file_to_memory(file_handle, buffer, buffer_size);
}

BCS_RESULT filesystem_read_file_to_memory(const wchar_t* filepath, void*& buffer, unsigned long long& buffer_size)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	//BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	HANDLE file_handle = CreateFileW(
		filepath,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		return BCS_E_FAIL;
	}

	return filesystem_read_file_to_memory(file_handle, buffer, buffer_size);
}

static BCS_RESULT filesystem_write_file_from_memory(HANDLE file_handle, const void* buffer, unsigned long long buffer_size)
{
	BCS_RESULT rs = BCS_S_OK;

	const char* file_data_buffer = static_cast<const char*>(buffer);
	unsigned long long number_of_bytes_remaining = buffer_size;
	while (number_of_bytes_remaining > 0)
	{
		DWORD number_of_bytes_to_read = static_cast<DWORD>(__min(number_of_bytes_remaining, 0x40000000)); // max 1GiB per iteration
		DWORD number_of_bytes_read = 0;
		BOOL read_file_result = WriteFile(file_handle, file_data_buffer, number_of_bytes_to_read, &number_of_bytes_read, NULL);
		if (read_file_result == FALSE)
		{
			rs = BCS_E_FAIL;
			break;
		}
		file_data_buffer += number_of_bytes_read;
		number_of_bytes_remaining -= number_of_bytes_read;
	}

	BOOL close_handle_result = CloseHandle(file_handle);
	if (close_handle_result == FALSE)
	{
		rs = BCS_E_CLEANUP_FAIL;
	}

	if (BCS_FAILED(rs))
	{
		delete buffer;
		buffer = nullptr;
		buffer_size = 0;
	}

	return rs;
}

BCS_RESULT filesystem_write_file_from_memory(const char* filepath, const void* buffer, unsigned long long buffer_size, e_filesystem_write_mode mode)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	//BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	if (mode == _filesystem_write_mode_check_for_changes)
	{
		t_memory_mapped_file* memory_mapped_file;
		if (BCS_SUCCEEDED(create_memory_mapped_file(filepath, true, memory_mapped_file)))
		{
			s_memory_mapped_file_info file_info;
			BCS_FAIL_RETURN(get_memory_mapped_file_info(memory_mapped_file, file_info));

			bool is_same =
				file_info.file_size == buffer_size &&
				memcmp(file_info.file_view_begin, buffer, __min(buffer_size, buffer_size)) == 0;

			BCS_FAIL_RETURN(destroy_memory_mapped_file(memory_mapped_file));

			if (is_same)
			{
				// no need to update the file
				return BCS_S_NO_CHANGES_MADE;
			}
		}
	}

	HANDLE file_handle = CreateFileA(
		filepath,
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		DWORD last_error = GetLastError();
		return BCS_E_FAIL;
	}

	return filesystem_write_file_from_memory(file_handle, buffer, buffer_size);
}

BCS_RESULT filesystem_write_file_from_memory(const wchar_t* filepath, const void* buffer, unsigned long long buffer_size, e_filesystem_write_mode mode)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	//BCS_FAIL_RETURN(filesystem_filepath_exists(filepath));

	if (mode == _filesystem_write_mode_check_for_changes)
	{
		t_memory_mapped_file* memory_mapped_file;
		if (BCS_SUCCEEDED(create_memory_mapped_file(filepath, true, memory_mapped_file)))
		{
			s_memory_mapped_file_info file_info;
			BCS_FAIL_RETURN(get_memory_mapped_file_info(memory_mapped_file, file_info));

			bool is_same =
				file_info.file_size == buffer_size &&
				memcmp(file_info.file_view_begin, buffer, __min(buffer_size, buffer_size));

			BCS_FAIL_RETURN(destroy_memory_mapped_file(memory_mapped_file));

			if (is_same)
			{
				// no need to update the file
				return BCS_S_NO_CHANGES_MADE;
			}
		}
	}

	HANDLE file_handle = CreateFileW(
		filepath,
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (file_handle == INVALID_HANDLE_VALUE)
	{
		return BCS_E_FAIL;
	}

	return filesystem_write_file_from_memory(file_handle, buffer, buffer_size);
}

struct t_memory_mapped_file
{
	HANDLE file_handle;
	HANDLE file_map_handle;
	LONGLONG file_size;
	void* file_view;
	bool is_read_only;
};

BCS_RESULT create_memory_mapped_file(const char* filepath, bool read_only, t_memory_mapped_file*& file)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_CHAR_TO_WIDECHAR_STACK(filepath, filepath_wc);
	return create_memory_mapped_file(filepath_wc, read_only, file);
}

BCS_RESULT create_memory_mapped_file(const wchar_t* filepath, bool read_only, t_memory_mapped_file*& file)
{
	BCS_VALIDATE_ARGUMENT(filepath);
	BCS_VALIDATE_ARGUMENT(IS_VALID_BOOLEAN(read_only));

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

	LARGE_INTEGER mapped_file_size;
	BOOL get_file_size_result = GetFileSizeEx(file_handle, &mapped_file_size);
	if (get_file_size_result == FALSE)
	{
		// #TODO: include GetLastError ???
		return BCS_E_FAIL;
	}

	HANDLE file_map_handle = CreateFileMappingW(file_handle, NULL, PAGE_READONLY, mapped_file_size.HighPart, mapped_file_size.LowPart, NULL);
	if (file_map_handle == INVALID_HANDLE_VALUE)
	{
		// #TODO: include GetLastError
		return BCS_E_FAIL;
	}

	void* file_view = MapViewOfFile(file_map_handle, FILE_MAP_READ, 0, 0, static_cast<SIZE_T>(mapped_file_size.QuadPart));
	if (file_map_handle == INVALID_HANDLE_VALUE)
	{
		// #TODO: include GetLastError
		return BCS_E_FAIL;
	}

	t_memory_mapped_file& file_storage = *(file = new t_memory_mapped_file());
	file_storage.file_handle = file_handle;
	file_storage.file_map_handle = file_map_handle;
	file_storage.file_size = mapped_file_size.QuadPart;
	file_storage.file_view = file_view;

	return BCS_S_OK;
}

BCS_RESULT destroy_memory_mapped_file(t_memory_mapped_file* file)
{
	if (file->file_map_handle)
	{
		BOOL unmap_view_of_file_result = UnmapViewOfFile(file->file_view);
		if (unmap_view_of_file_result == FALSE)
		{
			DWORD error = GetLastError();

			// #TODO: include GetLastError ???
			return BCS_E_FAIL;
		}
	}

	if (file->file_map_handle)
	{
		BOOL close_handle_result = CloseHandle(file->file_map_handle);
		if (close_handle_result == FALSE)
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

BCS_RESULT get_memory_mapped_file_info(t_memory_mapped_file* file, s_memory_mapped_file_info& file_info)
{
	BCS_VALIDATE_ARGUMENT(file);

	file_info.read_only = file->is_read_only;
	file_info.file_view_begin = static_cast<char*>(file->file_view);
	file_info.file_view_end = reinterpret_cast<char*>(reinterpret_cast<uintptr_t>(file->file_view) + static_cast<uintptr_t>(file->file_size));
	file_info.file_size = static_cast<unsigned long long>(file->file_size);

	return BCS_S_OK;
}

BCS_RESULT filesystem_traverse_directory_folders(const wchar_t* directory_path, t_traverse_callback callback, void* userdata, const wchar_t* relative_directory_path)
{
	wchar_t directory_path_buffer[MAX_PATH];
	_snwprintf_s(directory_path_buffer, MAX_PATH, L"%s*", directory_path);

	bool continue_search = callback(userdata, directory_path, relative_directory_path);
	if (!continue_search)
	{
		return BCS_S_SEARCH_STOP;
	}

	WIN32_FIND_DATAW file;
	HANDLE search_handle = FindFirstFileW(directory_path_buffer, &file);
	if (search_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if ((!lstrcmpW(file.cFileName, L".")) || (!lstrcmpW(file.cFileName, L"..")))
				{
					continue;
				}

				wchar_t relative_directory_path_buffer[MAX_PATH];
				_snwprintf_s(relative_directory_path_buffer, MAX_PATH, L"%s%s\\", relative_directory_path, file.cFileName);
				_snwprintf_s(directory_path_buffer, MAX_PATH, L"%s%s\\", directory_path, file.cFileName);

				BCS_RESULT traverse_result = filesystem_traverse_directory_folders(directory_path_buffer, callback, userdata, relative_directory_path_buffer);
				if (BCS_FAILED(traverse_result) || traverse_result == BCS_S_SEARCH_STOP)
				{
					return traverse_result;
				}
			}
		} while (FindNextFileW(search_handle, &file));

		FindClose(search_handle);
	}
	return BCS_S_OK;
}

BCS_RESULT filesystem_traverse_directory_files(const wchar_t* directory, const wchar_t* search_criteria, t_traverse_callback callback, void* userdata, const wchar_t* relative_directory_path)
{
	BCS_VALIDATE_ARGUMENT(directory);
	if (search_criteria == nullptr) search_criteria = L"";
	BCS_VALIDATE_ARGUMENT(callback);

	wchar_t directory_buffer[MAX_PATH];
	wcsncpy(directory_buffer, directory, MAX_PATH);
	PathRemoveBackslashW(directory_buffer);

	wchar_t search_criteria_directory_buffer[MAX_PATH];
	wcsncpy(search_criteria_directory_buffer, search_criteria, MAX_PATH);
	PathRemoveFileSpecW(search_criteria_directory_buffer);
	if (*search_criteria_directory_buffer)
	{
		wcsncpy(search_criteria_directory_buffer, L"\\", MAX_PATH);
	}

	wchar_t search_buffer[MAX_PATH];
	_snwprintf(search_buffer, MAX_PATH, L"%s\\%s", directory_buffer, search_criteria);

	WIN32_FIND_DATAW find_data;
	HANDLE find_file_handle = FindFirstFileExW(search_buffer, FindExInfoBasic, &find_data, FindExSearchNameMatch, NULL, 0);

	if (find_file_handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			wchar_t filepath[MAX_PATH];
			_snwprintf(filepath, MAX_PATH, L"%s\\%s%s", directory_buffer, search_criteria_directory_buffer, find_data.cFileName);

			const wchar_t* relative_filepath = filepath + wcslen(directory_buffer);

			bool continue_search = callback(userdata, filepath, relative_filepath);
			if (!continue_search)
			{
				break;
			}

		} while (FindNextFile(find_file_handle, &find_data));
	}

	FindClose(find_file_handle);

	return BCS_S_OK;
}

#include "filesystem.deprecated.inl"
