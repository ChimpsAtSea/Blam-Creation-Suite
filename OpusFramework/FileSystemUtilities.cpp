#include "opusframework-private-pch.h"

using namespace opus;

void FileSystemReadToBufferImpl(FILE* pFileHandle, char* pBuffer, size_t readLength)
{
	uint32_t iterations = 0;
	for (size_t currentPosition = 0; currentPosition < readLength; iterations++)
	{
		// prevent this from running into a madness number of iterations
		assert(iterations != UINT32_MAX); 

		size_t remainingDataLength = readLength - currentPosition;
		currentPosition += fread(&pBuffer[currentPosition], 1, remainingDataLength, pFileHandle);
	}
}

char* opus::FileSystemReadToBuffer(const wchar_t* pFilePath, char* pBuffer, size_t bufferSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	if (fileSize > bufferSize)
	{
		return nullptr;
	}

	FileSystemReadToBufferImpl(pFileHandle, pBuffer, bufferSize);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return nullptr;
}

char* opus::FileSystemReadToMemory(const wchar_t* pFilePath, size_t* pAllocatedSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	char* pBuffer = new char[fileSize] {};
	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	FileSystemReadToBufferImpl(pFileHandle, pBuffer, fileSize);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return pBuffer;
}
