#include "tagfileserialization-private-pch.h"

c_tag_file_heap_partition_config_chunk::c_tag_file_heap_partition_config_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	string_length(),
	string()
{
	
}

c_tag_file_heap_partition_config_chunk::~c_tag_file_heap_partition_config_chunk()
{
	delete[] string;
}

BCS_RESULT c_tag_file_heap_partition_config_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const uint32_t* string_length_ptr = reinterpret_cast<const uint32_t*>(get_chunk_data_start());
	const char* string_buffer_ptr = next_contiguous_pointer(char, string_length_ptr);

	string_length = chunk_byteswap(*string_length_ptr);

	if (string_length > 0)
	{
		string = new() char[string_length + 1];
		memcpy(string, string_buffer_ptr, string_length);
		string[string_length] = 0;
	}
	

	return rs;
}
