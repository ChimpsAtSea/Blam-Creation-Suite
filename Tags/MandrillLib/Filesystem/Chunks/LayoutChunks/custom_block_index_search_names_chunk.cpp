#include "mandrilllib-private-pch.h"

c_custom_block_index_search_names_chunk::c_custom_block_index_search_names_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	offsets(),
	entry_count(chunk_size / sizeof(*offsets))
{
	if (entry_count > 0)
	{
		const s_tag_persist_string_character_index* src_offsets = reinterpret_cast<const s_tag_persist_string_character_index*>(get_chunk_data_start());
		offsets = new() s_tag_persist_string_character_index[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_string_character_index& offset = offsets[entry_index];
			offset = src_offsets[entry_index];
			byteswap_inplace(offset);
		}
	}

	debug_point;
}

c_custom_block_index_search_names_chunk::~c_custom_block_index_search_names_chunk()
{
	delete[] offsets;
}

void c_custom_block_index_search_names_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("entry_count:0x%08X", entry_count);

	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_string_character_index string_character_index = offsets[index];
		if (string_debugger)
		{
			const char* string = string_debugger->get_string_by_string_character_index(string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X\t%s", index, string_character_index.offset, string);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X", index, string_character_index.offset);
		}
	}
}
