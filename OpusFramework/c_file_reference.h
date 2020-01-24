#pragma once

struct c_file_reference
{
	LPCSTR pFileName;
	FILE* pFile;
	char* pBuffer;
	size_t bufferSize;

	c_file_reference(LPCSTR pPath);

	bool open_file();

	void close_file();

	template<typename T>
	void read_type(T* value, long offset = 0)
	{
		assert(pFile);
		*value = *(T*)&pBuffer[offset];
	}

	void read_int8(__int8* value, long offset = 0);
	void read_uint8(unsigned __int8* value, long offset = 0);
	void read_int16(__int16* value, long offset = 0, bool swapEndian = false);
	void read_uint16(unsigned __int16* value, long offset = 0, bool swapEndian = false);
	void read_int32(__int32* value, long offset = 0, bool swapEndian = false);
	void read_uint32(unsigned __int32* value, long offset = 0, bool swapEndian = false);
	void read_string(std::string* value, size_t length, long offset = 0);
	void read_string_long(std::wstring* value, size_t length, long offset = 0, bool swapEndian = false);
	void read_string_long_as_string(std::string* value, size_t length, long offset = 0, bool swapEndian = false);
	void read_string_as_string_long(std::wstring* value, size_t length, long offset = 0);
};