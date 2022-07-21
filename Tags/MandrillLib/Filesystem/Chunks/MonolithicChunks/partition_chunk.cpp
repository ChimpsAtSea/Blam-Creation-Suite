#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_partition_header& value)
{
	byteswap_inplace(value.file_index);
}

template<> void byteswap_inplace(s_lruv_persist_header& value)
{
	byteswap_inplace(value.__unknown20);
	byteswap_inplace(value.page_size_bits);
	byteswap_inplace(value.__unknown_count24);
	byteswap_inplace(value.__unknown_count28);
	byteswap_inplace(value.first_datum);
	byteswap_inplace(value.last_datum);
	byteswap_inplace(value.signature);
}

template<> void byteswap_inplace(s_data_array_persist_header& value)
{
	byteswap_inplace(value.size);
	byteswap_inplace(value.count);
	byteswap_inplace(value.maximum_count);
	byteswap_inplace(value.flags);
	byteswap_inplace(value.__unknown2D);
	byteswap_inplace(value.alignment_bits);
	byteswap_inplace(value.signature);
}

template<> void byteswap_inplace(s_datum_footer& value)
{
	byteswap_inplace(value.__unknown0);
	byteswap_inplace(value.signature);
}

template<> void byteswap_inplace(s_lruv_cache_block& value)
{
	byteswap_inplace(value.current_datum);
	byteswap_inplace(value.unknown_datum);
	byteswap_inplace(value.size);
	byteswap_inplace(value.offset);
	byteswap_inplace(value.next_datum);
	byteswap_inplace(value.previous_datum);
	byteswap_inplace(value.footer);
}

c_partition_chunk::c_partition_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	partition_header(),
	lruv_persist_header(),
	data_array_persist_header(),
	lruv_cache_blocks()
{


	
}

c_partition_chunk::~c_partition_chunk()
{
	delete[] lruv_cache_blocks;
}

BCS_RESULT c_partition_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const s_partition_header* src_partition_header = reinterpret_cast<const s_partition_header*>(get_chunk_data_start());
	const s_lruv_persist_header* src_lruv_persist_header = next_contiguous_pointer(s_lruv_persist_header, src_partition_header);
	const s_data_array_persist_header* src_data_array_persist_header = next_contiguous_pointer(s_data_array_persist_header, src_lruv_persist_header);
	const s_lruv_cache_block* src_lruv_cache_blocks = next_contiguous_pointer(s_lruv_cache_block, src_data_array_persist_header);

	partition_header = chunk_byteswap(*src_partition_header);
	lruv_persist_header = chunk_byteswap(*src_lruv_persist_header);
	data_array_persist_header = chunk_byteswap(*src_data_array_persist_header);
	lruv_cache_blocks = new() s_lruv_cache_block_ex[data_array_persist_header.count];

	for (uint32_t lruv_cache_block_index = 0; lruv_cache_block_index < data_array_persist_header.count; lruv_cache_block_index++)
	{
		s_lruv_cache_block_ex& lruv_cache_block_ex = lruv_cache_blocks[lruv_cache_block_index];
		lruv_cache_block_ex.lruv_cache_block = src_lruv_cache_blocks[lruv_cache_block_index];
		chunk_byteswap_inplace(lruv_cache_block_ex.lruv_cache_block);

		lruv_cache_block_ex.size = static_cast<uint64_t>(lruv_cache_block_ex.lruv_cache_block.size) * 512ull;
		lruv_cache_block_ex.offset = static_cast<uint64_t>(lruv_cache_block_ex.lruv_cache_block.offset) * 512ull;
	}

	return rs;
}
