#pragma once

struct s_tag_persist_string_list
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long string_offset_count;
	unsigned long string_offset_start_index;
};

class c_string_lists_chunk : public c_typed_chunk<'sz[]'>
{
public:
	s_tag_persist_string_list* const entries;
	unsigned long const entry_count;

	c_string_lists_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
