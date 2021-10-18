#include "mandrilllib-private-pch.h"

c_string_lists_chunk::c_string_lists_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	entries(reinterpret_cast<s_tag_persist_string_list*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*entries))
{
	debug_point;
}

void c_string_lists_chunk::log_impl(c_single_tag_file_layout_reader& layout_reader) const
{
	log_signature();
	console_write_line_verbose("count:0x % 08X", entry_count);

	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_string_list& entry = entries[index];
		char* name = layout_reader.get_string_by_string_character_index(entry.string_character_index);
		log_pad(); console_write_line_verbose(
			"\t0x%08X\tstring_offset_start_index:0x%08X\tstring_offset_start_index:0x%08X\t'%s'",
			index,
			entry.string_offset_count,
			entry.string_offset_start_index,
			name);
		debug_point;
	}
}
