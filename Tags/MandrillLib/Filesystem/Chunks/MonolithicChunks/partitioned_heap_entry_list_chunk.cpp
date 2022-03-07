#include "mandrilllib-private-pch.h"

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

c_partitioned_heap_entry_list_chunk::c_partitioned_heap_entry_list_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	header(),
	entries()
{
	debug_point;


}

c_partitioned_heap_entry_list_chunk::~c_partitioned_heap_entry_list_chunk()
{
	delete[] entries;
}

BCS_RESULT c_partitioned_heap_entry_list_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const s_partitioned_heap_entry_list_header* src_header = reinterpret_cast<const s_partitioned_heap_entry_list_header*>(get_chunk_data_start());
	header = chunk_byteswap(*src_header);

	if (header.count > 0)
	{
		entries = new() s_partitioned_heap_entry[header.count];
		const s_partitioned_heap_entry* read_entries = next_contiguous_pointer<s_partitioned_heap_entry>(reinterpret_cast<const s_partitioned_heap_entry_list_header*>(src_header));
		for (unsigned long entry_index = 0; entry_index < header.count; entry_index++)
		{
			entries[entry_index] = read_entries[entry_index];
			chunk_byteswap_inplace(entries[entry_index]);
		}
	}

	return rs;
}
