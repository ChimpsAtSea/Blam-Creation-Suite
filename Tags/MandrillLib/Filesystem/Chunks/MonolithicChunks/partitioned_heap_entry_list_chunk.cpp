#include "mandrilllib-private-pch.h"

c_partitioned_heap_entry_list_chunk::c_partitioned_heap_entry_list_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	header(),
	entries()
{
	debug_point;

	const s_partitioned_heap_entry_list_header* src_header = reinterpret_cast<const s_partitioned_heap_entry_list_header*>(chunk_data_begin);
	header = chunk_byteswap(*src_header);

	if (header.count > 0)
	{
		entries = new s_partitioned_heap_entry[header.count];
		const s_partitioned_heap_entry* read_entries = next_contiguous_pointer<s_partitioned_heap_entry>(reinterpret_cast<const s_partitioned_heap_entry_list_header*>(chunk_data_begin));
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
