#pragma once

struct s_partitioned_heap_entry_list_header
{
	unsigned long count;
	unsigned long maximum_count;
};

struct s_partitioned_heap_entry
{
	unsigned long partition_index;
	unsigned long heap_datum;
};

class c_partitioned_heap_entry_list_chunk : public c_typed_chunk<'hpls', false>
{
public:
	s_partitioned_heap_entry_list_header header;
	s_partitioned_heap_entry* entries;

	c_partitioned_heap_entry_list_chunk(c_chunk& parent);
	~c_partitioned_heap_entry_list_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);
};
