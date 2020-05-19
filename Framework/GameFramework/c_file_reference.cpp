#include "gameframework-private-pch.h"

c_file_reference::c_file_reference(LPCSTR pPath)
{
	filepath = pPath;
}

bool c_file_reference::open_file()
{
	filepath = fopen(filepath, "rb");
	if (filepath)
	{
		fseek(filepath, 0, SEEK_END);
		buffer_size = ftell(filepath);
		fseek(filepath, 0L, SEEK_SET);
		buffer = new char[buffer_size];
		memset(buffer, 0x00, buffer_size);

		fseek(filepath, 0L, SEEK_SET);
		size_t totalBytesRead = 0;
		do
		{
			size_t bytesToRead = buffer_size - totalBytesRead;
			fseek(filepath, static_cast<long>(totalBytesRead), SEEK_SET);
			size_t bytesRead = fread(buffer + totalBytesRead, 1, bytesToRead, filepath);
			totalBytesRead += bytesRead;
		} while (totalBytesRead < buffer_size);

		return true;
	}

	return false;
}

void c_file_reference::close_file()
{
	if (filepath)
	{
		buffer_size = 0;
		free(buffer);
		fclose(filepath);
	}
}

void c_file_reference::read_int8(__int8* value, long offset)
{
	read_type(value, offset);
}

void c_file_reference::read_uint8(unsigned __int8* value, long offset)
{
	read_type(value, offset);
}

void c_file_reference::read_int16(__int16* value, long offset, bool swapEndian)
{
	__int16 out = *value;
	read_type(&out, offset);
	*value = swapEndian ? (out >> 8) | (out << 8) : out;
}

void c_file_reference::read_uint16(unsigned __int16* value, long offset, bool swapEndian)
{
	unsigned __int16 out = *value;
	read_type(&out, offset);
	*value = swapEndian ? (out >> 8) | (out << 8) : out;
}

void c_file_reference::read_int32(__int32* value, long offset, bool swapEndian)
{
	__int32 out = *value;
	read_type(&out, offset);
	*value = swapEndian ? ((out >> 24) & 0xff) | ((out << 8) & 0xff0000) | ((out >> 8) & 0xff00) | ((out << 24) & 0xff000000) : out;
}

void c_file_reference::read_uint32(unsigned __int32* value, long offset, bool swapEndian)
{
	unsigned __int32 out = *value;
	read_type(&out, offset);
	*value = swapEndian ? ((out >> 24) & 0xff) | ((out << 8) & 0xff0000) | ((out >> 8) & 0xff00) | ((out << 24) & 0xff000000) : out;
}

void c_file_reference::read_string(std::string* value, size_t length, long offset)
{
	ASSERT(filepath != nullptr);
	*value = &buffer[offset];
}

void c_file_reference::read_string_long(std::wstring* value, size_t length, long offset, bool swapEndian)
{
	ASSERT(filepath != nullptr);
	*value = (wchar_t*)&buffer[swapEndian ? offset + 1 : offset];
}

void c_file_reference::read_string_long_as_string(std::string* value, size_t length, long offset, bool swapEndian)
{
	std::wstring out; read_string_long(&out, length, offset, swapEndian);
	*value = std::string(out.begin(), out.end());
}

void c_file_reference::read_string_as_string_long(std::wstring* value, size_t length, long offset)
{
	std::string out; read_string(&out, length, offset);
	*value = std::wstring(out.begin(), out.end());
}