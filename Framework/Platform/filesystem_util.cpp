#include "platform-private-pch.h"

bool filesystem_read_from_file_handle(FILE* file_handle, void* destination, size_t size)
{
	const long long read_beginning = _ftelli64(file_handle);
	_fseeki64(file_handle, 0, SEEK_END);
	const long long file_end = _ftelli64(file_handle);
	_fseeki64(file_handle, read_beginning, SEEK_SET);
	const long long read_end_expected = read_beginning + static_cast<long long>(size);

	if (read_beginning == file_end)
	{
		return false;
	}

	char* output_data = static_cast<char*>(destination);

	const long long read_position = read_beginning;
	const long long read_end = __min(file_end, read_end_expected);
	size_t remaining_size = size;
	for (long long read_position = read_beginning; read_position < read_end;)
	{
		size_t bytes_read = fread(output_data, 1, remaining_size, file_handle);
		remaining_size -= bytes_read;
		read_position += static_cast<long long>(bytes_read);
	}

	if (read_end_expected > read_end)
	{
		return false;
	}
	return true;
}

bool filesystem_filepath_exists(const char* filepath)
{
	bool path_file_exists_result = PathFileExistsA(filepath);
	return path_file_exists_result;
}

bool filesystem_filepath_exists(const wchar_t* filepath)
{
	bool path_file_exists_result = PathFileExistsW(filepath);
	return path_file_exists_result;
}

bool filesystem_read_file_to_memory(const char* filepath, void** buffer, size_t* buffer_size)
{
	ASSERT(filepath != nullptr);
	ASSERT(buffer != nullptr);

	*buffer = nullptr;
	if (buffer_size != nullptr)
	{
		*buffer_size = 0;
	}

	FILE* file_handle = fopen(filepath, "rb");
	if (file_handle)
	{
		fseek(file_handle, 0, SEEK_END);
		size_t file_size = static_cast<size_t>(_ftelli64(file_handle));
		fseek(file_handle, 0, SEEK_SET);

		*buffer = new char[file_size] {};
		if (buffer_size != nullptr)
		{
			*buffer_size = file_size;
		}

		size_t bytes_read = 0;
		while (bytes_read < file_size)
		{
			bytes_read += fread(reinterpret_cast<char*>(*buffer) + bytes_read, 1, file_size - bytes_read, file_handle);
		}

		fclose(file_handle);

		return true;
	}
	return false;
}

bool filesystem_read_file_to_memory(const wchar_t* filepath, void** buffer, size_t* buffer_size)
{
	ASSERT(filepath != nullptr);
	ASSERT(buffer != nullptr);

	*buffer = nullptr;
	*buffer_size = 0;

	FILE* file_handle = _wfopen(filepath, L"rb");
	if (file_handle)
	{
		fseek(file_handle, 0, SEEK_END);
		size_t file_size = static_cast<size_t>(_ftelli64(file_handle));
		fseek(file_handle, 0, SEEK_SET);

		*buffer = new char[file_size] {};
		*buffer_size = file_size;

		size_t bytes_read = 0;
		while (bytes_read < file_size)
		{
			bytes_read += fread(reinterpret_cast<char*>(*buffer) + bytes_read, 1, file_size - bytes_read, file_handle);
		}

		fclose(file_handle);

		return true;
	}
	return false;
}

bool filesystem_write_file_from_memory(const char* filepath, const void* buffer, size_t buffer_size)
{
	ASSERT(!IsBadReadPtr(buffer, 1));
	ASSERT(filepath != nullptr);
	if (buffer_size == 0) return false;
	ASSERT(buffer != nullptr);

	char directory_buffer[MAX_PATH + 1];
	GetFullPathNameA(filepath, MAX_PATH, directory_buffer, NULL);
	PathRemoveFileSpecA(directory_buffer);
	bool path_file_exists_result = PathFileExistsA(directory_buffer);
	if (!path_file_exists_result)
	{
		SHCreateDirectoryExA(NULL, directory_buffer, NULL);
	}

	FILE* file_handle = fopen(filepath, "wb");
	if (file_handle)
	{
		fseek(file_handle, 0, SEEK_SET);

		size_t bytes_written = 0;
		while (bytes_written < buffer_size)
		{
			bytes_written += fwrite(reinterpret_cast<const char*>(buffer) + bytes_written, 1, buffer_size - bytes_written, file_handle);
		}

		fflush(file_handle);
		fclose(file_handle);

		return true;
	}
	return false;
}

bool filesystem_write_file_from_memory(const wchar_t* filepath, const void* buffer, size_t buffer_size)
{
	ASSERT(!IsBadReadPtr(buffer, 1));
	ASSERT(filepath != nullptr);
	if (buffer_size == 0) return false;
	ASSERT(buffer != nullptr);

	wchar_t directory_buffer[MAX_PATH + 1];
	GetFullPathNameW(filepath, MAX_PATH, directory_buffer, NULL);
	PathRemoveFileSpecW(directory_buffer);
	bool path_file_exists_result = PathFileExistsW(directory_buffer);
	if (!path_file_exists_result)
	{
		SHCreateDirectoryExW(NULL, directory_buffer, NULL);
	}

	FILE* file_handle = _wfopen(filepath, L"wb");
	if (file_handle)
	{
		fseek(file_handle, 0, SEEK_SET);

		size_t bytes_written = 0;
		while (bytes_written < buffer_size)
		{
			bytes_written += fwrite(reinterpret_cast<const char*>(buffer) + bytes_written, 1, buffer_size - bytes_written, file_handle);
		}

		fflush(file_handle);
		fclose(file_handle);

		return true;
	}
	return false;
}

bool filesystem_directory_exists(const char* directorypath)
{
	DWORD file_attributes = GetFileAttributesA(directorypath);

	bool result = file_attributes != INVALID_FILE_ATTRIBUTES && file_attributes & FILE_ATTRIBUTE_DIRECTORY;
	return result;
}

bool filesystem_directory_exists(const wchar_t* directorypath)
{
	DWORD file_attributes = GetFileAttributesW(directorypath);

	bool result = file_attributes != INVALID_FILE_ATTRIBUTES && file_attributes & FILE_ATTRIBUTE_DIRECTORY;
	return result;
}


// ------------- LEGACY -----------------

void filesystem_read_to_buffer_legacy_impl(FILE* file_handle, char* buffer, size_t read_length)
{
	uint32_t iterations = 0;
	for (size_t current_position = 0; current_position < read_length; iterations++)
	{
		// prevent this from running into a madness number of iterations
		ASSERT(iterations != UINT32_MAX);

		size_t remainingDataLength = read_length - current_position;
		current_position += fread(&buffer[current_position], 1, remainingDataLength, file_handle);
	}
}

char* filesystem_read_to_memory_legacy(const wchar_t* filepathPath, size_t* pAllocatedSize)
{
	FILE* file_handle = _wfopen(filepathPath, L"rb");
	if (file_handle == nullptr)
	{
		return nullptr;
	}

	fseek(file_handle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(file_handle));
	fseek(file_handle, 0, SEEK_SET);

	char* buffer = new char[fileSize + 1] {};
	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	filesystem_read_to_buffer_legacy_impl(file_handle, buffer, fileSize);

	int fcloseResult = fclose(file_handle);
	ASSERT(fcloseResult == 0);

	return buffer;
}


size_t filesystem_get_file_size_legacy(const wchar_t* filepathPath)
{
	FILE* file_handle = _wfopen(filepathPath, L"rb");
	if (file_handle == nullptr)
	{
		return 0;
	}

	fseek(file_handle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(file_handle));
	fseek(file_handle, 0, SEEK_SET);

	int fcloseResult = fclose(file_handle);
	ASSERT(fcloseResult == 0);

	return fileSize;
}


char* filesystem_read_to_memory_legacy2(const wchar_t* filepathPath, char* buffer, size_t* pAllocatedSize)
{
	FILE* file_handle = _wfopen(filepathPath, L"rb");
	if (file_handle == nullptr)
	{
		return nullptr;
	}

	fseek(file_handle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(file_handle));
	fseek(file_handle, 0, SEEK_SET);

	size_t read_length = fileSize;
	if (pAllocatedSize)
	{
		if (*pAllocatedSize > 0)
		{
			read_length = __min(*pAllocatedSize, read_length);
			*pAllocatedSize = read_length;
		}
		else
		{
			*pAllocatedSize = fileSize;
		}
	}

	filesystem_read_to_buffer_legacy_impl(file_handle, buffer, read_length);

	int fcloseResult = fclose(file_handle);
	ASSERT(fcloseResult == 0);

	return buffer;
}

const char* get_user_profile_environment_variable()
{
	static char user_profile_environment_variable[MAX_PATH] = { };
	if (*user_profile_environment_variable == 0)
	{
		GetEnvironmentVariableA("USERPROFILE", user_profile_environment_variable, MAX_PATH);
	}
	return static_cast<const char*>(user_profile_environment_variable);
}

const wchar_t* get_user_profile_environment_variable_widechar()
{
	static wchar_t user_profile_environment_variable[MAX_PATH] = { };
	if (*user_profile_environment_variable == 0)
	{
		GetEnvironmentVariableW(L"USERPROFILE", user_profile_environment_variable, MAX_PATH);
	}
	return static_cast<const wchar_t*>(user_profile_environment_variable);
}
