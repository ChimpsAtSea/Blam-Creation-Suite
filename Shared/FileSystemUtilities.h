#pragma once

char* FileSystemReadToMemory2(const wchar_t* pFilePath, char* pBuffer, size_t* pAllocatedSize);
size_t FileSystemGetFileSize(const wchar_t* pFilePath);
char* FileSystemReadToBuffer(const wchar_t* pFilePath, char* pBuffer, size_t bufferSize);
char* FileSystemReadToMemory(const wchar_t* pFilePath, size_t* pAllocatedSize = nullptr);

const char* GetUserprofileVariable();
bool DirectoryExists(const wchar_t* szPath);
bool DirectoryExists(const char* szPath);

