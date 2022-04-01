#pragma once

struct s_partition_header
{
	unsigned long file_index;
};

struct s_lruv_persist_header
{
	char name[32];

	unsigned long __unknown20;

	unsigned long page_size_bits;

	unsigned long __unknown_count24;
	unsigned long __unknown_count28;

	unsigned long first_datum;
	unsigned long last_datum;

	unsigned long signature;
};

struct s_lruv_cache_block
{
	unsigned long current_datum;
	unsigned long unknown_datum;

	unsigned long size;
	unsigned long offset;

	unsigned long next_datum;
	unsigned long previous_datum;

	s_datum_footer footer;
};

struct s_lruv_cache_block_ex
{
	s_lruv_cache_block lruv_cache_block;
	unsigned long long size;
	unsigned long long offset;
};

class c_partition_chunk : public c_typed_chunk<'part', false>
{
public:
	s_partition_header partition_header;
	s_lruv_persist_header lruv_persist_header;
	s_data_array_persist_header data_array_persist_header;
	s_lruv_cache_block_ex* lruv_cache_blocks;

	c_partition_chunk(c_chunk& parent);
	~c_partition_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
};

