#include "mandrilllib-private-pch.h"

c_data_definition_name_chunk::c_data_definition_name_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	offsets(),
	entry_count()
{


	debug_point;
}

c_data_definition_name_chunk::~c_data_definition_name_chunk()
{
	delete[] offsets;
}

BCS_RESULT c_data_definition_name_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	entry_count = chunk_size / sizeof(*offsets);
	if (entry_count > 0)
	{
		const s_tag_persist_string_character_index* src_offsets = reinterpret_cast<const s_tag_persist_string_character_index*>(get_chunk_data_start());
		offsets = new() s_tag_persist_string_character_index[entry_count];
		for (unsigned long entry_index = 0; entry_index < entry_count; entry_index++)
		{
			s_tag_persist_string_character_index& offset = offsets[entry_index];
			offset = src_offsets[entry_index];
			byteswap_inplace(offset);
		}
	}

	return rs;
}

void c_data_definition_name_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);

	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_string_character_index string_character_index = offsets[index];
		if (layout_reader)
		{
			const char* string = layout_reader->get_string_by_string_character_index(string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X\t%s", index, string_character_index.offset, string);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X", index, string_character_index.offset);
		}
	}
}
