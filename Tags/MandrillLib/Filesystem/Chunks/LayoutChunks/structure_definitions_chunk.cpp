#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_persist_struct_definition& value)
{
	byteswap_inplace(value.persistent_identifier);
	byteswap_inplace(value.string_character_index);
	byteswap_inplace(value.fields_start_index);
}

c_structure_definitions_chunk::c_structure_definitions_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	entries(),
	entry_count()
{
	
}

c_structure_definitions_chunk::~c_structure_definitions_chunk()
{
	delete[] entries;
}

BCS_RESULT c_structure_definitions_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	read_entries();

	return rs;
}

void c_structure_definitions_chunk::log_impl(c_tag_file_string_debugger* string_debugger) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_struct_definition& entry = entries[index];
		if (string_debugger)
		{
			const char* string = string_debugger->get_string_by_string_character_index(entry.string_character_index);
			log_pad(); console_write_line_verbose(
				"\t0x%08X\t[0x%08X, 0x%08X, 0x%08X, 0x%08X]\tfields_start_index:0x%08X %s",
				index,
				entry.persistent_identifier.identifier_part_0,
				entry.persistent_identifier.identifier_part_1,
				entry.persistent_identifier.identifier_part_2,
				entry.persistent_identifier.identifier_part_3,
				entry.fields_start_index,
				string);
		}
		else
		{
			log_pad(); console_write_line_verbose(
				"\t0x%08X\t[0x%08X, 0x%08X, 0x%08X, 0x%08X]\tfields_start_index:0x%08X\tstring_character_index:0x%08X",
				index,
				entry.persistent_identifier.identifier_part_0,
				entry.persistent_identifier.identifier_part_1,
				entry.persistent_identifier.identifier_part_2,
				entry.persistent_identifier.identifier_part_3,
				entry.fields_start_index,
				entry.string_character_index.offset);
		}
		
	}
}

BCS_RESULT c_structure_definitions_chunk::set_data(const void* data, unsigned long data_size)
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

void c_structure_definitions_chunk::read_entries()
{
	if (entries)
	{
		delete[] entries;
	}

	entry_count = chunk_size / sizeof(*entries);
	if (entry_count > 0)
	{
		const s_tag_persist_struct_definition* src_entries = reinterpret_cast<const s_tag_persist_struct_definition*>(get_chunk_data_start());
		entries = new() s_tag_persist_struct_definition[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_struct_definition& entry = entries[entry_index];
			entry = src_entries[entry_index];
			chunk_byteswap_inplace(entry);
		}
	}
}
