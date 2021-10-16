#include "halo3tagfiletest-private-pch.h"

c_array_definitions_chunk::c_array_definitions_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_array_entry*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_array_definitions_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);

	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_array_entry entry = entries[index];
		char* string = string_data_chunk->chunk_data_begin + entry.name_string_offset;
		log_pad(); console_write_line_verbose("\t0x%08X\tcount:0x%08X structure_index:0x%08X %s", index, entry.count, entry.structure_index, string);
	}
}
