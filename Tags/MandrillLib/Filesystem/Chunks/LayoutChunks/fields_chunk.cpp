#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_persist_field& value)
{
	byteswap_inplace(value.string_character_index);
	byteswap_inplace(value.field_type_index);
	byteswap_inplace(value.metadata);
}

c_fields_chunk::c_fields_chunk(const void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(),
	entry_count(chunk_size / sizeof(*entries))
{
	if (entry_count > 0)
	{
		const s_tag_persist_field* src_entries = reinterpret_cast<const s_tag_persist_field*>(chunk_data_begin);
		entries = new() s_tag_persist_field[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_field& entry = entries[entry_index];
			entry = src_entries[entry_index];
			byteswap_inplace(entry);
		}
	}

	debug_point;
}

c_fields_chunk::~c_fields_chunk()
{
	delete[] entries;
}

void c_fields_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_field entry = entries[index];
		if (layout_reader)
		{
			const char* name = layout_reader->get_string_by_string_character_index(entry.string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\tfield_type_index:0x%08X\tmetadata:0x%08X\t'%s'", index, entry.field_type_index, entry.metadata, name);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\tfield_type_index:0x%08X\tmetadata:0x%08X", index, entry.field_type_index, entry.metadata);
		}
	}
}