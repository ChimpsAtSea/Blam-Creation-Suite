#include "mandrilllib-private-pch.h"

c_structure_definitions_chunk::c_structure_definitions_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_struct_definition_entry*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_structure_definitions_chunk::log_impl(c_string_data_chunk* string_data_chunk) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_struct_definition_entry& entry = entries[index];
		char* string = string_data_chunk->chunk_data_begin + entry.name_string_offset;
		log_pad(); console_write_line_verbose(
			"\t0x%08X\t[0x%08X, 0x%08X, 0x%08X, 0x%08X]\tfields_start_index:0x%08X %s",
			index,
			entry.persistent_identifier.identifier_part_0,
			entry.persistent_identifier.identifier_part_1,
			entry.persistent_identifier.identifier_part_2,
			entry.persistent_identifier.identifier_part_3,
			entry.fields_start_index,
			string);
		debug_point;
	}
}
