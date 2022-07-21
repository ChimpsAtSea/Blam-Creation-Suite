#pragma once

struct s_tag_file_index_header
{
	uint32_t size;
	uint32_t version;
	uint32_t tag_file_count;
	uint32_t __unknownC;
	s_system_global_unique_identifier creator_tag;
	uint32_t compressed_entry_count;
	uint32_t creator_name_offset;
	uint32_t compressed_entries_size;
	uint32_t compressed_entries_address;
	uint32_t __unknown30;
	uint32_t name_buffer_size;
	uint32_t name_buffer_address;
};

struct s_compressed_tag_file_index_entry
{
	uint32_t group_tag;
	uint32_t filetime_low;
	uint32_t filetime_high;

	uint32_t wide_block_index;
	uint32_t wide_block_datum_index;

	uint32_t tag_index;
	uint32_t name_offset;
};

class c_tag_file_index_chunk : public c_typed_chunk<'indx', false>
{
public:
	s_tag_file_index_header tag_file_index_header;
	s_compressed_tag_file_index_entry* compressed_tag_file_index_entries;
	const char* name_buffer;

	c_tag_file_index_chunk(c_chunk& parent);
	~c_tag_file_index_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
};
