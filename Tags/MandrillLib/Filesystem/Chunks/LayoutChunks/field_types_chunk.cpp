#include "mandrilllib-private-pch.h"

c_field_types_chunk::c_field_types_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_tag_persist_field_type*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_field_types_chunk::log_impl(c_single_tag_file_layout_reader& layout_reader) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_field_type entry = entries[index];
		char* _typename = layout_reader.get_string_by_string_character_index(entry.string_character_index);
		log_pad(); console_write_line_verbose("\t0x%08X\tsize:0x%08X metadata:0x%08X %s", index, entry.size, entry.metadata, _typename);
	}
}