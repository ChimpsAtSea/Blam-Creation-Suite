#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_wide_data_array_header& value)
{
	byteswap_inplace(value.count);
	byteswap_inplace(value.__unknown28);
	byteswap_inplace(value.__unknown2C);
	byteswap_inplace(value.signature);
}

template<> void byteswap_inplace(s_wide_data_datum& value)
{
	byteswap_inplace(value.datum_index);
	byteswap_inplace(value.data_header);
}

template<> void byteswap_inplace(s_wide_data_cache_block& value)
{
	byteswap_inplace(value.current_datum);
	byteswap_inplace(value.unknown_datum);
	byteswap_inplace(value.tag_heap_entry_index);
	byteswap_inplace(value.cache_heap_entry_index);
	byteswap_inplace(value.footer);
}

c_tag_file_blocks_chunk::c_tag_file_blocks_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	wide_data_array_header(),
	data_array_persist_header(),
	wide_data_datums(),
	wide_data_cache_blocks(),
	num_wide_data_cache_blocks()
{


	debug_point;
}

c_tag_file_blocks_chunk::~c_tag_file_blocks_chunk()
{
	delete[] wide_data_cache_blocks;
	delete[] wide_data_datums;
}

BCS_RESULT c_tag_file_blocks_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const s_wide_data_array_header* src_wide_data_array_header = reinterpret_cast<const s_wide_data_array_header*>(get_chunk_data_start());
	const s_data_array_persist_header* src_data_array_persist_header = next_contiguous_pointer<s_data_array_persist_header>(src_wide_data_array_header);

	wide_data_array_header = chunk_byteswap(*src_wide_data_array_header);
	data_array_persist_header = chunk_byteswap(*src_data_array_persist_header);

	if (data_array_persist_header.count > 0)
	{
		const s_wide_data_datum* src_current_wide_data_datum;
		{
			src_current_wide_data_datum = next_contiguous_pointer<s_wide_data_datum>(src_data_array_persist_header);

			wide_data_datums = new() s_wide_data_datum[data_array_persist_header.count];

			for (unsigned long wide_data_datum_index = 0; wide_data_datum_index < data_array_persist_header.count; wide_data_datum_index++)
			{
				s_wide_data_datum& wide_data_datum = wide_data_datums[wide_data_datum_index];
				wide_data_datum = *src_current_wide_data_datum;
				chunk_byteswap_inplace(wide_data_datum);

				num_wide_data_cache_blocks += wide_data_datum.data_header.count;

				const s_wide_data_cache_block* src_wide_data_cache_block = next_contiguous_pointer<s_wide_data_cache_block>(src_current_wide_data_datum);

				const unsigned long* src_signature0 = reinterpret_cast<const unsigned long*>(src_wide_data_cache_block + wide_data_datum.data_header.count);
				const unsigned long* src_signature1 = next_contiguous_pointer(src_signature0);
				ASSERT(chunk_byteswap(*src_signature0) == 'd@ft');
				ASSERT(chunk_byteswap(*src_signature1) == '!@#$');

				src_current_wide_data_datum = next_contiguous_pointer<s_wide_data_datum>(src_signature1);

				debug_point;
			}
		}

		{
			src_current_wide_data_datum = next_contiguous_pointer<s_wide_data_datum>(src_data_array_persist_header);

			wide_data_cache_blocks = new() s_wide_data_cache_block[num_wide_data_cache_blocks];
			s_wide_data_cache_block* wide_data_cache_blocks_pos = wide_data_cache_blocks;

			for (unsigned long wide_data_datum_index = 0; wide_data_datum_index < data_array_persist_header.count; wide_data_datum_index++)
			{
				s_wide_data_datum& wide_data_datum = wide_data_datums[wide_data_datum_index];
				wide_data_datum = *src_current_wide_data_datum;
				chunk_byteswap_inplace(wide_data_datum);

				const s_wide_data_cache_block* src_wide_data_cache_block = next_contiguous_pointer<s_wide_data_cache_block>(src_current_wide_data_datum);
				for (unsigned long wide_data_cache_block_index = 0; wide_data_cache_block_index < wide_data_datum.data_header.count; wide_data_cache_block_index++)
				{
					s_wide_data_cache_block& wide_data_cache_block = *wide_data_cache_blocks_pos;
					wide_data_cache_block = src_wide_data_cache_block[wide_data_cache_block_index];
					chunk_byteswap_inplace(wide_data_cache_block);

					wide_data_cache_blocks_pos++;

					debug_point;
				}

				const unsigned long* src_signature0 = reinterpret_cast<const unsigned long*>(src_wide_data_cache_block + wide_data_datum.data_header.count);
				const unsigned long* src_signature1 = next_contiguous_pointer(src_signature0);
				ASSERT(chunk_byteswap(*src_signature0) == 'd@ft');
				ASSERT(chunk_byteswap(*src_signature1) == '!@#$');

				src_current_wide_data_datum = next_contiguous_pointer<s_wide_data_datum>(src_signature1);

				debug_point;
			}
		}

		const unsigned long* src_signature0 = reinterpret_cast<const unsigned long*>(src_current_wide_data_datum);
		const unsigned long* src_signature1 = next_contiguous_pointer(src_signature0);
		ASSERT(chunk_byteswap(*src_signature0) == 'd@ft');
		ASSERT(chunk_byteswap(*src_signature1) == 'load');

		const void* current_read_position = next_contiguous_pointer(src_signature1);
		ASSERT(current_read_position == get_chunk_data_end());

		debug_point;
	}

	return rs;
}
