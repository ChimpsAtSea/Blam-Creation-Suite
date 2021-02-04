#include "gameframework-private-pch.h"

IFileAccess::IFileAccess(LPCSTR pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);

	int result = vsnprintf_s(s_filePath, MAX_PATH, _TRUNCATE, pFormat, args);
	va_end(args);
}

IFileAccess::~IFileAccess()
{
	strcpy(s_filePath, "");
}

bool IFileAccess::FileOpen(FileAccessType accessType)
{
	switch (accessType)
	{
	case FileAccessType::Read:
		if (s_filepath = fopen(s_filePath, "rb"))
		{
			fseek(s_filepath, 0, SEEK_END);
			s_size = ftell(s_filepath);
			fseek(s_filepath, 0L, SEEK_SET);
			s_buffer = new char[s_size];
			memset(s_buffer, 0x00, s_size);

			return true;
		}
		break;
	case FileAccessType::Write:
		if (s_filepath = fopen(s_filePath, "wb"))
		{
			return true;
		}
		break;
	}
	return false;
}

void IFileAccess::FileClose()
{
	if (s_filepath)
	{
		if (s_buffer)
		{
			free(s_buffer);
			s_size = 0;
		}
		fclose(s_filepath);
	}
	memset(s_filePath, 0, sizeof(s_filePath));
}

char *IFileAccess::FileRead(size_t &rBufferSize)
{
	if (s_filepath)
	{
		fseek(s_filepath, 0L, SEEK_SET);
		size_t totalBytesRead = 0;
		do
		{
			size_t bytesToRead = s_size - totalBytesRead;
			fseek(s_filepath, static_cast<long>(totalBytesRead), SEEK_SET);
			size_t bytesRead = fread(s_buffer + totalBytesRead, 1, bytesToRead, s_filepath);
			totalBytesRead += bytesRead;
		} while (totalBytesRead < s_size);
	}

	rBufferSize = s_size;
	return s_buffer;
}

void IFileAccess::FileWrite(char *buffer, size_t size)
{
	if (s_filepath)
	{
		fseek(s_filepath, 0L, SEEK_SET);
		size_t totalBytesRead = 0;
		do
		{
			size_t bytesToRead = size - totalBytesRead;
			fseek(s_filepath, static_cast<long>(totalBytesRead), SEEK_SET);
			size_t bytesRead = fwrite(buffer + totalBytesRead, 1, bytesToRead, s_filepath);
			totalBytesRead += bytesRead;
		} while (totalBytesRead < size);
	}
}

LPCSTR IFileAccess::get_filepath()
{
	return s_filePath;
}