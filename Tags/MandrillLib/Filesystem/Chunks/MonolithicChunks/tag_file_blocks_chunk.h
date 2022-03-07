#pragma once

struct s_wide_data_array_header
{
	char name[32];

	unsigned long count;

	unsigned long __unknown28;
	unsigned long __unknown2C;

	unsigned long signature;
};

struct s_data_array_persist_header
{
	char name[32];

	unsigned long size;
	unsigned long count;
	unsigned long maximum_count;

	unsigned short flags;
	unsigned char __unknown2D;
	unsigned char alignment_bits;

	unsigned long signature;
};

struct s_wide_data_datum
{
	unsigned long datum_index;
	s_data_array_persist_header data_header;
};

struct s_datum_footer
{
	unsigned long __unknown0;
	unsigned long signature;
};

struct s_wide_data_cache_block
{
	unsigned long current_datum;
	unsigned long unknown_datum;

	unsigned long tag_heap_entry_index;
	unsigned long cache_heap_entry_index;

	s_datum_footer footer;
};

class c_tag_file_blocks_chunk : public c_typed_chunk<'blok', false>
{
public:
	s_wide_data_array_header wide_data_array_header;
	s_data_array_persist_header data_array_persist_header;
	s_wide_data_datum* wide_data_datums;
	s_wide_data_cache_block* wide_data_cache_blocks;
	unsigned long num_wide_data_cache_blocks;

	c_tag_file_blocks_chunk(c_chunk& parent);
	~c_tag_file_blocks_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

protected:
	void read_data_array(unsigned long count, s_wide_data_datum* src_wide_data_datums);
};
