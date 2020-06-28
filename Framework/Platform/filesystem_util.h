#pragma once

BCSAPI bool filesystem_read_from_file_handle(FILE* file_handle, void* destination, size_t size);
BCSAPI bool filesystem_filepath_exists(const char* filepath);
BCSAPI bool filesystem_filepath_exists(const wchar_t* filepath);
BCSAPI bool filesystem_read_file_to_memory(const char* filepath, void** buffer, size_t* buffer_size = nullptr);
BCSAPI bool filesystem_read_file_to_memory(const wchar_t* filepath, void** buffer, size_t* buffer_size = nullptr);
BCSAPI bool filesystem_write_file_from_memory(const char* filepath, const void* buffer, size_t buffer_size);
BCSAPI bool filesystem_write_file_from_memory(const wchar_t* filepath, const void* buffer, size_t buffer_size);

template<typename T>
bool filesystem_read_file_to_memory(const char* filepath, T** buffer, size_t* buffer_size = nullptr)
{
	return filesystem_read_file_to_memory(filepath, (void**)buffer, buffer_size);
}

template<typename T>
bool filesystem_read_file_to_memory(const wchar_t* filepath, T** buffer, size_t* buffer_size = nullptr)
{
	return filesystem_read_file_to_memory(filepath, (void**)buffer, buffer_size);
}

const char* get_user_profile_environment_variable();
const wchar_t* get_user_profile_environment_variable_widechar();
BCSAPI bool filesystem_directory_exists(const wchar_t* szPath);
BCSAPI bool filesystem_directory_exists(const char* szPath);

BCSAPI void filesystem_iterate_directory(const wchar_t* directorypath, std::function<bool(const wchar_t* filepath)>& handler);

HRESULT filesystem_resolve_shell_link(HWND hwnd, LPCSTR lpszLinkFile, LPSTR lpszPath, int iPathBufferSize);
HRESULT filesystem_resolve_shell_link_wide(HWND hwnd, LPCSTR lpszLinkFile, LPWSTR lpszPath, int iPathBufferSize);

// ------------- LEGACY -----------------

BCSAPI char* filesystem_read_to_memory_legacy2(const wchar_t* filepathPath, char* buffer, size_t* pAllocatedSize);
BCSAPI size_t filesystem_get_file_size_legacy(const wchar_t* filepathPath);
BCSAPI char* filesystem_read_to_memory_legacy(const wchar_t* filepathPath, size_t* pAllocatedSize = nullptr);
