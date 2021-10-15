#include "halo3tagfiletest-private-pch.h"

c_tag_field_types_chunk::c_tag_field_types_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_tag_field_type_entry*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_tag_field_types_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_field_type_entry entry = entries[index];
		char* _typename = string_data_chunk->chunk_data_begin + entry.name_string_offset;
		log_pad(); console_write_line("\t0x%08X\tsize:0x%08X metadata:0x%08X %s", index, entry.size, entry.metadata, _typename);
	}
}