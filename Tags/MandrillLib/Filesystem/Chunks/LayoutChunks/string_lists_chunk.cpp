#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_persist_string_list& value)
{
	byteswap_inplace(value.string_character_index);
	byteswap_inplace(value.string_offset_count);
	byteswap_inplace(value.string_offset_start_index);
}

c_string_lists_chunk::c_string_lists_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	entries(),
	entry_count()
{
	
}

c_string_lists_chunk::~c_string_lists_chunk()
{
	delete[] entries;
}

BCS_RESULT c_string_lists_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	read_entries();

	return rs;
}

void c_string_lists_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);

	for (uint32_t index = 0; index < entry_count; index++)
	{
		s_tag_persist_string_list& entry = entries[index];
		if (string_debugger)
		{
			const char* name = string_debugger->get_string_by_string_character_index(entry.string_character_index);
			log_pad(); console_write_line_verbose(
				"\t0x%08X\tstring_offset_start_index:0x%08X\tstring_offset_count:0x%08X\t'%s'",
				index,
				entry.string_offset_start_index,
				entry.string_offset_count,
				name);
		}
		else
		{
			log_pad(); console_write_line_verbose(
				"\t0x%08X\tstring_offset_start_index:0x%08X\tstring_offset_count:0x%08X\tstring_character_index:0x%08X",
				index,
				entry.string_offset_start_index,
				entry.string_offset_count,
				entry.string_character_index.offset);
		}
		
	}
}

BCS_RESULT c_string_lists_chunk::set_data(const void* data, uint32_t data_size)
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

void c_string_lists_chunk::read_entries()
{
	if (entries)
	{
		delete[] entries;
	}

	entry_count = chunk_size / sizeof(*entries);
	if (entry_count > 0)
	{
		const s_tag_persist_string_list* src_entries = reinterpret_cast<const s_tag_persist_string_list*>(get_chunk_data_start());
		entries = new() s_tag_persist_string_list[entry_count];
		for (uint32_t entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_string_list& entry = entries[entry_index];
			entry = src_entries[entry_index];
			chunk_byteswap_inplace(entry);
		}
	}
}
