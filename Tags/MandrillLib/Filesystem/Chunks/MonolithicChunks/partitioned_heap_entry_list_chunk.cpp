#include "mandrilllib-private-pch.h"

c_partitioned_heap_entry_list_chunk::c_partitioned_heap_entry_list_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	header(chunk_byteswap(*reinterpret_cast<s_partitioned_heap_entry_list_header*>(chunk_data_begin))),
	entries(nullptr)
{
	debug_point;

	if (header.count > 0)
	{
		entries = new s_partitioned_heap_entry[header.count];
		s_partitioned_heap_entry* read_entries = next_contiguous_pointer<s_partitioned_heap_entry>(reinterpret_cast<s_partitioned_heap_entry_list_header*>(chunk_data_begin));
		for (unsigned long entry_index = 0; entry_index < header.count; entry_index++)
		{
			entries[entry_index] = read_entries[entry_index];
			chunk_byteswap_inplace(entries[entry_index]);
		}
	}
}

template<> void byteswap_inplace(s_partitioned_heap_entry_list_header& value)
{
	byteswap_inplace(value.count);
	byteswap_inplace(value.maximum_count);
}

template<> void byteswap_inplace(s_partitioned_heap_entry& value)
{
	byteswap_inplace(value.partition_index);
	byteswap_inplace(value.heap_datum);
}
