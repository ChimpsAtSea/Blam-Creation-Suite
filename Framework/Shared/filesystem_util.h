#pragma once

bool filepath_exists(const char* filepath);
bool filepath_exists(const wchar_t* filepath);
bool read_file_to_memory(const char* filepath, void** buffer, size_t* buffer_size);
bool write_file_from_memory(const char* filepath, const void* buffer, size_t buffer_size);
bool read_file_to_memory(const wchar_t* filepath, void** buffer, size_t* buffer_size);
bool write_file_from_memory(const wchar_t* filepath, const void* buffer, size_t buffer_size);

template<typename T>
bool read_file_to_memory(const char* filepath, T** buffer, size_t* buffer_size)
{
	return read_file_to_memory(filepath, (void**)buffer, buffer_size);
}

template<typename T>
bool read_file_to_memory(const wchar_t* filepath, T** buffer, size_t* buffer_size)
{
	return read_file_to_memory(filepath, (void**)buffer, buffer_size);
}



// ------------- LEGACY -----------------

char* FileSystemReadToMemory2(const wchar_t* filepathPath, char* buffer, size_t* pAllocatedSize);
size_t FileSystemGetFileSize(const wchar_t* filepathPath);
char* FileSystemReadToBuffer(const wchar_t* filepathPath, char* buffer, size_t buffer_size);
char* FileSystemReadToMemory(const wchar_t* filepathPath, size_t* pAllocatedSize = nullptr);

const char* GetUserprofileVariable();
bool DirectoryExists(const wchar_t* szPath);
bool DirectoryExists(const char* szPath);

