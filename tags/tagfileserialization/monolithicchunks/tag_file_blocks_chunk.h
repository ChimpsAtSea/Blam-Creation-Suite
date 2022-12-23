#pragma once

struct s_wide_data_array_header
{
	char name[32];

	uint32_t count;

	uint32_t __unknown28;
	uint32_t __unknown2C;

	uint32_t signature;
};

struct s_data_array_persist_header
{
	char name[32];

	uint32_t size;
	uint32_t count;
	uint32_t maximum_count;

	unsigned short flags;
	unsigned char __unknown2D;
	unsigned char alignment_bits;

	uint32_t signature;
};

struct s_wide_data_datum
{
	uint32_t datum_index;
	s_data_array_persist_header data_header;
};

struct s_datum_footer
{
	uint32_t __unknown0;
	uint32_t signature;
};

struct s_wide_data_cache_block
{
	uint32_t current_datum;
	uint32_t unknown_datum;

	uint32_t tag_heap_entry_index;
	uint32_t cache_heap_entry_index;

	s_datum_footer footer;
};

class c_tag_file_blocks_chunk : public c_typed_chunk<'blok', false>
{
public:
	s_wide_data_array_header wide_data_array_header;
	s_data_array_persist_header data_array_persist_header;
	s_wide_data_datum* wide_data_datums;
	s_wide_data_cache_block* wide_data_cache_blocks;
	uint32_t num_wide_data_cache_blocks;

	BCS_SHARED c_tag_file_blocks_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_file_blocks_chunk();

	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

protected:
	void read_data_array(uint32_t count, s_wide_data_datum* src_wide_data_datums);
};
