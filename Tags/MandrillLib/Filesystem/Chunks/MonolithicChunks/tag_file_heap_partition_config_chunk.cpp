#include "mandrilllib-private-pch.h"

c_tag_file_heap_partition_config_chunk::c_tag_file_heap_partition_config_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	string_length(chunk_byteswap(*reinterpret_cast<unsigned long*>(chunk_data_begin))),
	string_buffer(static_cast<char*>(chunk_data_begin) + 4),
	string(nullptr)
{
	if (string_length > 0)
	{
		string = new char[string_length + 1];
		memcpy(string, string_buffer, string_length);
		string[string_length] = 0;
	}
	debug_point;
}

c_tag_file_heap_partition_config_chunk::~c_tag_file_heap_partition_config_chunk()
{
	delete[] string;
}
