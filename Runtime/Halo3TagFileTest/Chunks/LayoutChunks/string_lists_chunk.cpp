#include "halo3tagfiletest-private-pch.h"

c_string_lists_chunk::c_string_lists_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_string_list_entry*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_string_lists_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line("count:0x % 08X", entry_count);

	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_string_list_entry& entry = entries[index];
		char* name = string_data_chunk->chunk_data_begin + entry.name_string_offset;
		log_pad(); console_write_line(
			"\t0x%08X\tstring_offset_start_index:0x%08X\tstring_offset_start_index:0x%08X\t'%s'",
			index,
			entry.string_offset_count,
			entry.string_offset_start_index,
			name);
		debug_point;
	}
}
