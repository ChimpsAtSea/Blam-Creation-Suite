#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_persist_array_definition& value)
{
	byteswap_inplace(value.string_character_index);
	byteswap_inplace(value.count);
	byteswap_inplace(value.structure_entry_index);
}

c_array_definitions_chunk::c_array_definitions_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(),
	entry_count(chunk_size / sizeof(*entries))
{
	if (entry_count > 0)
	{
		const s_tag_persist_array_definition* src_entries = reinterpret_cast<const s_tag_persist_array_definition*>(chunk_data_begin);
		entries = new() s_tag_persist_array_definition[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_array_definition& entry = entries[entry_index];
			entry = src_entries[entry_index];
			byteswap_inplace(entry);
		}
	}

	debug_point;
}

c_array_definitions_chunk::~c_array_definitions_chunk()
{
	delete[] entries;
}

void c_array_definitions_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);

	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_array_definition entry = entries[index];
		if (layout_reader)
		{
			const char* string = layout_reader->get_string_by_string_character_index(entry.string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\tcount:0x%08X structure_entry_index:0x%08X %s", index, entry.count, entry.structure_entry_index, string);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\tcount:0x%08X structure_entry_index:0x%08X", index, entry.count, entry.structure_entry_index);
		}
	}
}
