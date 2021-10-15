#include "halo3tagfiletest-private-pch.h"

s_fields_chunk::s_fields_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_field_entry*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void s_fields_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_field_entry entry = entries[index];
		char* name = string_data_chunk->chunk_data_begin + entry.name_string_offset;
		log_pad(); console_write_line("\t0x%08X\ttag_field_type_index:0x%08X\tmetadata:0x%08X\t'%s'", index, entry.tag_field_type_index, entry.metadata, name);
	}
}