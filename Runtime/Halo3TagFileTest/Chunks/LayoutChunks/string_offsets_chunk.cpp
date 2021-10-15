#include "halo3tagfiletest-private-pch.h"

c_string_offsets_chunk::c_string_offsets_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	offsets(reinterpret_cast<unsigned long*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*offsets))
{
	debug_point;
}

void c_string_offsets_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		unsigned long offset = offsets[index];
		char* string = string_data_chunk->chunk_data_begin + offset;
		log_pad(); console_write_line("\t0x%08X\t0x%08X\t%s", index, offset, string);
	}
}
