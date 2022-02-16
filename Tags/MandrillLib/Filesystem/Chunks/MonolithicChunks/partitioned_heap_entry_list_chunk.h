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

class c_partitioned_heap_entry_list_chunk : public c_typed_chunk<'hpls'>
{
public:
	s_partitioned_heap_entry_list_header header;
	s_partitioned_heap_entry* entries;

	c_partitioned_heap_entry_list_chunk(void* chunk_data, c_chunk& parent);
};
