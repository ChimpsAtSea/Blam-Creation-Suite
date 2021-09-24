#pragma once

class c_infinite_file_entry_block_map
{
public:
	c_infinite_file_entry_block_map(
		long file_entry_index,
		c_infinite_module_file_reader& cache_reader,
		const char* string_buffer,
		const infinite::s_module_block_entry* block_entries,
		const void* file_entry_pointer,
		s_engine_platform_build engine_platform_build
	);

	~c_infinite_file_entry_block_map();

	bool is_valid();
	BCS_RESULT map(void*& data);
	BCS_RESULT unmap(void* data);

public:
	long file_entry_index;
	long tag_index;
	infinite::c_infinite_generic_module_file_entry file_entry;
	const char* filepath;
	std::vector<c_infinite_file_entry_block_map*> resource_file_entry_block_maps;

protected:
	c_infinite_module_file_reader& cache_reader;
	const infinite::s_module_block_entry* block_entries;
	char* mapped_data;

	BCS_RESULT unpack_blocks(char*& data);
};


