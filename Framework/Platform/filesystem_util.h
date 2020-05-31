#pragma once

bool filesystem_filepath_exists(const char* filepath);
bool filesystem_filepath_exists(const wchar_t* filepath);
bool filesystem_read_file_to_memory(const char* filepath, void** buffer, size_t* buffer_size);
bool filesystem_write_file_from_memory(const char* filepath, const void* buffer, size_t buffer_size);
bool filesystem_read_file_to_memory(const wchar_t* filepath, void** buffer, size_t* buffer_size);
bool filesystem_write_file_from_memory(const wchar_t* filepath, const void* buffer, size_t buffer_size);

template<typename T>
bool filesystem_read_file_to_memory(const char* filepath, T** buffer, size_t* buffer_size)
{
	return filesystem_read_file_to_memory(filepath, (void**)buffer, buffer_size);
}

template<typename T>
bool filesystem_read_file_to_memory(const wchar_t* filepath, T** buffer, size_t* buffer_size)
{
	return filesystem_read_file_to_memory(filepath, (void**)buffer, buffer_size);
}

const char* get_user_profile_environment_variable();
const wchar_t* get_user_profile_environment_variable_widechar();
bool filesystem_directory_exists(const wchar_t* szPath);
bool filesystem_directory_exists(const char* szPath);



// ------------- LEGACY -----------------

char* filesystem_read_to_memory_legacy2(const wchar_t* filepathPath, char* buffer, size_t* pAllocatedSize);
size_t filesystem_get_file_size_legacy(const wchar_t* filepathPath);
char* filesystem_read_to_memory_legacy(const wchar_t* filepathPath, size_t* pAllocatedSize = nullptr);
