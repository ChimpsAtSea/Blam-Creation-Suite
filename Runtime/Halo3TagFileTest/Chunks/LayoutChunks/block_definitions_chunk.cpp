#include "halo3tagfiletest-private-pch.h"

c_block_definitions_chunk::c_block_definitions_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_block_definition_entry*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_block_definitions_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_block_definition_entry entry = entries[index];
		char* name = string_data_chunk->chunk_data_begin + entry.name_string_offset;
		log_pad(); console_write_line_verbose("\t0x%08X\tmax_count:0x%08X\tstructure_entry_index:0x%08X\t%s", index, entry.max_count, entry.structure_entry_index, name);
	}
}