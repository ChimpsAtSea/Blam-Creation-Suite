#pragma once

struct s_partitioned_heap_entry_list_header
{
	uint32_t count;
	uint32_t maximum_count;
};

struct s_partitioned_heap_entry
{
	uint32_t partition_index;
	uint32_t heap_datum;
};

class c_partitioned_heap_entry_list_chunk : public c_typed_chunk<'hpls', false>
{
public:
	s_partitioned_heap_entry_list_header header;
	s_partitioned_heap_entry* entries;

	c_partitioned_heap_entry_list_chunk(c_chunk& parent);
	~c_partitioned_heap_entry_list_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
};
