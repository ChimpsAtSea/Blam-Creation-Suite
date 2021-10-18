#include "mandrilllib-private-pch.h"

c_interop_definitions_chunk::c_interop_definitions_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_tag_persist_interop_definition*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_interop_definitions_chunk::log_impl(c_single_tag_file_layout_reader& layout_reader) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_interop_definition& entry = entries[index];
		const char* string = layout_reader.get_string_by_string_character_index(entry.string_character_index);
		log_pad(); console_write_line_verbose(
			"\t0x%08X\t[0x%08X, 0x%08X, 0x%08X, 0x%08X]\tstructure_entry_index:0x%08X %s",
			index,
			entry.persistent_identifier.identifier_part_0,
			entry.persistent_identifier.identifier_part_1,
			entry.persistent_identifier.identifier_part_2,
			entry.persistent_identifier.identifier_part_3,
			entry.structure_entry_index,
			string);
		debug_point;
	}
}
