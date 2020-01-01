#pragma once

namespace opus
{
	char* FileSystemReadToBuffer(const wchar_t* pFilePath, char* pBuffer, size_t bufferSize);
	char* FileSystemReadToMemory(const wchar_t* pFilePath, size_t* pAllocatedSize = nullptr);
}




