#include "shared-private-pch.h"

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
