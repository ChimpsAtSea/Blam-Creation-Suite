#include "shared-private-pch.h"


bool read_file_to_memory(const char* filepath, void** buffer, size_t* buffer_size)
{
	ASSERT(filepath != nullptr);
	ASSERT(buffer != nullptr);

	*buffer = nullptr;
	*buffer_size = 0;

	FILE* file_handle = fopen(filepath, "rb");
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

bool read_file_to_memory(const wchar_t* filepath, void** buffer, size_t* buffer_size)
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

bool write_file_from_memory(const char* filepath, const void* buffer, size_t buffer_size)
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
		SHCreateDirectoryEx(NULL, directory_buffer, NULL);
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

bool write_file_from_memory(const wchar_t* filepath, const void* buffer, size_t buffer_size)
{
	ASSERT(filepath != nullptr);
	if (buffer_size == 0) return false;
	ASSERT(buffer != nullptr);

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

// ------------- LEGACY -----------------

void FileSystemReadToBufferImpl(FILE* pFileHandle, char* buffer, size_t readLength)
{
	uint32_t iterations = 0;
	for (size_t currentPosition = 0; currentPosition < readLength; iterations++)
	{
		// prevent this from running into a madness number of iterations
		ASSERT(iterations != UINT32_MAX);

		size_t remainingDataLength = readLength - currentPosition;
		currentPosition += fread(&buffer[currentPosition], 1, remainingDataLength, pFileHandle);
	}
}


char* FileSystemReadToBuffer(const wchar_t* pFilePath, char* buffer, size_t buffer_size)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	if (fileSize > buffer_size)
	{
		return nullptr;
	}

	FileSystemReadToBufferImpl(pFileHandle, buffer, buffer_size);

	int fcloseResult = fclose(pFileHandle);
	ASSERT(fcloseResult == 0);

	return nullptr;
}


char* FileSystemReadToMemory(const wchar_t* pFilePath, size_t* pAllocatedSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	char* buffer = new char[fileSize + 1] {};
	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	FileSystemReadToBufferImpl(pFileHandle, buffer, fileSize);

	int fcloseResult = fclose(pFileHandle);
	ASSERT(fcloseResult == 0);

	return buffer;
}


size_t FileSystemGetFileSize(const wchar_t* pFilePath)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return 0;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	int fcloseResult = fclose(pFileHandle);
	ASSERT(fcloseResult == 0);

	return fileSize;
}


char* FileSystemReadToMemory2(const wchar_t* pFilePath, char* buffer, size_t* pAllocatedSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	FileSystemReadToBufferImpl(pFileHandle, buffer, fileSize);

	int fcloseResult = fclose(pFileHandle);
	ASSERT(fcloseResult == 0);

	return buffer;
}

const char* GetUserprofileVariable()
{
	static char szBuf[MAX_PATH] = { 0 };
	GetEnvironmentVariableA("USERPROFILE", szBuf, MAX_PATH);
	return static_cast<const char*>(szBuf);
};

bool DirectoryExists(const char* szPath)
{
	DWORD dwAttrib = GetFileAttributes(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

bool DirectoryExists(const wchar_t* szPath)
{
	DWORD dwAttrib = GetFileAttributesW(szPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
		(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}
