#pragma once

class c_tag_file_heap_partition_config_chunk : public c_typed_chunk<'prpf'>
{
public:
	unsigned long string_length;
	const char* string_buffer;
	char* string;

	c_tag_file_heap_partition_config_chunk(const void* chunk_data, c_chunk& parent);
	~c_tag_file_heap_partition_config_chunk();
};
