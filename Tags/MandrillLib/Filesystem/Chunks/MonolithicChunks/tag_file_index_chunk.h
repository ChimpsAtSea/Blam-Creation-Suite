#pragma once

struct s_tag_file_index_header
{
	unsigned long size;
	unsigned long version;
	unsigned long tag_file_count;
	unsigned long __unknownC;
	s_system_global_unique_identifier creator_tag;
	unsigned long compressed_entry_count;
	unsigned long creator_name_offset;
	unsigned long compressed_entries_size;
	unsigned long compressed_entries_address;
	unsigned long __unknown30;
	unsigned long name_buffer_size;
	unsigned long name_buffer_address;
};

struct s_compressed_tag_file_index_entry
{
	unsigned long group_tag;
	unsigned long filetime_low;
	unsigned long filetime_high;

	unsigned long wide_block_index;
	unsigned long wide_block_datum_index;

	unsigned long tag_index;
	unsigned long name_offset;
};

class c_tag_file_index_chunk : public c_typed_chunk<'indx'>
{
public:
	s_tag_file_index_header tag_file_index_header;
	s_compressed_tag_file_index_entry* compressed_tag_file_index_entries;
	const char* name_buffer;

	c_tag_file_index_chunk(const void* chunk_data, c_chunk& parent);
	~c_tag_file_index_chunk();
};
