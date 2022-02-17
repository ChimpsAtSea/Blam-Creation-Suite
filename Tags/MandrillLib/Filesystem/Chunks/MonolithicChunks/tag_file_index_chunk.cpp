#include "mandrilllib-private-pch.h"

c_tag_file_index_chunk::c_tag_file_index_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	tag_file_index_header(),
	compressed_tag_file_index_entries(),
	name_buffer()
{
	const s_tag_file_index_header* src_tag_file_index_header = reinterpret_cast<const s_tag_file_index_header*>(chunk_data_begin);
	const s_compressed_tag_file_index_entry* src_compressed_tag_file_index_entry = next_contiguous_pointer<s_compressed_tag_file_index_entry>(src_tag_file_index_header);

	tag_file_index_header = chunk_byteswap(*src_tag_file_index_header);
	compressed_tag_file_index_entries = new s_compressed_tag_file_index_entry[tag_file_index_header.compressed_entry_count];
	name_buffer = reinterpret_cast<const char*>(src_compressed_tag_file_index_entry + tag_file_index_header.compressed_entry_count);

	for (unsigned long compressed_entry_index = 0; compressed_entry_index < tag_file_index_header.compressed_entry_count; compressed_entry_index++)
	{
		s_compressed_tag_file_index_entry& compressed_tag_file_index_entry = compressed_tag_file_index_entries[compressed_entry_index];
		compressed_tag_file_index_entry = src_compressed_tag_file_index_entry[compressed_entry_index];
		chunk_byteswap_inplace(compressed_tag_file_index_entry);

		const char* name = name_buffer + compressed_tag_file_index_entry.name_offset;

		debug_point;

	}

	debug_point;
}

c_tag_file_index_chunk::~c_tag_file_index_chunk()
{
	delete[] compressed_tag_file_index_entries;
}

template<> void byteswap_inplace(s_tag_file_index_header& value)
{
	byteswap_inplace(value.size);
	byteswap_inplace(value.version);
	byteswap_inplace(value.tag_file_count);
	byteswap_inplace(value.__unknownC);
	byteswap_inplace(value.creator_tag);
	byteswap_inplace(value.compressed_entry_count);
	byteswap_inplace(value.creator_name_offset);
	byteswap_inplace(value.compressed_entries_size);
	byteswap_inplace(value.compressed_entries_address);
	byteswap_inplace(value.__unknown30);
	byteswap_inplace(value.name_buffer_size);
	byteswap_inplace(value.name_buffer_address);
}

template<> void byteswap_inplace(s_compressed_tag_file_index_entry& value)
{
	byteswap_inplace(value.group_tag);
	byteswap_inplace(value.filetime_low);
	byteswap_inplace(value.filetime_high);
	byteswap_inplace(value.wide_block_index);
	byteswap_inplace(value.wide_block_datum_index);
	byteswap_inplace(value.tag_index);
	byteswap_inplace(value.name_offset);
}
