#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_persist_field_type& value)
{
	byteswap_inplace(value.string_character_index);
	byteswap_inplace(value.size);
	byteswap_inplace(value.metadata);
}

c_field_types_chunk::c_field_types_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	entries(),
	entry_count()
{

	debug_point;
}

c_field_types_chunk::~c_field_types_chunk()
{
	delete[] entries;
}

BCS_RESULT c_field_types_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	read_entries();

	return rs;
}

void c_field_types_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_field_type entry = entries[index];
		if (string_debugger)
		{
			const char* _typename = string_debugger->get_string_by_string_character_index(entry.string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\tsize:0x%08X metadata:%i %s", index, entry.size, static_cast<int>(entry.metadata), _typename);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\tsize:0x%08X metadata:%i string_character_index:0x%08X", index, entry.size, static_cast<int>(entry.metadata), entry.string_character_index.offset);
		}
	}
}

BCS_RESULT c_field_types_chunk::set_data(const void* data, unsigned long data_size)
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

void c_field_types_chunk::read_entries()
{
	if (entries)
	{
		delete[] entries;
	}

	entry_count = chunk_size / sizeof(*entries);
	if (entry_count > 0)
	{
		const s_tag_persist_field_type* src_entries = reinterpret_cast<const s_tag_persist_field_type*>(get_chunk_data_start());
		entries = new() s_tag_persist_field_type[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_field_type& entry = entries[entry_index];
			entry = src_entries[entry_index];
			chunk_byteswap_inplace(entry);
		}
	}
}
