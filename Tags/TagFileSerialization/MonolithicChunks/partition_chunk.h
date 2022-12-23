#pragma once

struct s_partition_header
{
	uint32_t file_index;
};

struct s_lruv_persist_header
{
	char name[32];

	uint32_t __unknown20;

	uint32_t page_size_bits;

	uint32_t __unknown_count24;
	uint32_t __unknown_count28;

	uint32_t first_datum;
	uint32_t last_datum;

	uint32_t signature;
};

struct s_lruv_cache_block
{
	uint32_t current_datum;
	uint32_t unknown_datum;

	uint32_t size;
	uint32_t offset;

	uint32_t next_datum;
	uint32_t previous_datum;

	s_datum_footer footer;
};

struct s_lruv_cache_block_ex
{
	s_lruv_cache_block lruv_cache_block;
	uint64_t size;
	uint64_t offset;
};

class c_partition_chunk : public c_typed_chunk<'part', false>
{
public:
	s_partition_header partition_header;
	s_lruv_persist_header lruv_persist_header;
	s_data_array_persist_header data_array_persist_header;
	s_lruv_cache_block_ex* lruv_cache_blocks;

	BCS_SHARED c_partition_chunk(c_chunk& parent);
	BCS_SHARED ~c_partition_chunk();
	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
};

