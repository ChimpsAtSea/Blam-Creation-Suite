#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_persist_field& value)
{
	byteswap_inplace(value.string_character_index);
	byteswap_inplace(value.field_type_index);
	byteswap_inplace(value.metadata);
}

c_fields_chunk::c_fields_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	entries(),
	entry_count()
{
	
}

c_fields_chunk::~c_fields_chunk()
{
	delete[] entries;
}

BCS_RESULT c_fields_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	read_entries();

	return rs;
}

void c_fields_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_field entry = entries[index];
		if (string_debugger)
		{
			const char* name = string_debugger->get_string_by_string_character_index(entry.string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\tfield_type_index:0x%08X\tmetadata:0x%08X\t'%s'", index, entry.field_type_index, entry.metadata, name);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\tstring_character_index:0x%08X\tfield_type_index:0x%08X\tmetadata:0x%08X", index, entry.string_character_index.offset, entry.field_type_index, entry.metadata);
		}
	}
}

BCS_RESULT c_fields_chunk::set_data(const void* data, unsigned long data_size)
{
	BCS_RESULT rs = BCS_S_OK;

	if (BCS_FAILED(rs = c_chunk::set_data(data, data_size)))
	{
		return rs;
	}

	is_big_endian = false;
	read_entries();

	return rs;
}

void c_fields_chunk::read_entries()
{
	if (entries)
	{
		delete[] entries;
	}

	entry_count = chunk_size / sizeof(*entries);
	if (entry_count > 0)
	{
		const s_tag_persist_field* src_entries = reinterpret_cast<const s_tag_persist_field*>(get_chunk_data_start());
		entries = new() s_tag_persist_field[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_field& entry = entries[entry_index];
			entry = src_entries[entry_index];
			chunk_byteswap_inplace(entry);
		}
	}
}