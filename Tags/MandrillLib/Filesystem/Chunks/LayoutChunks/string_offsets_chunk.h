#pragma once

struct s_tag_persist_string_character_index
{
	unsigned long offset;
};

class c_string_offsets_chunk : public c_typed_chunk<'sz+x'>
{
public:
	s_tag_persist_string_character_index* const offsets;
	unsigned long const entry_count;

	c_string_offsets_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_single_tag_file_layout_reader& layout_reader) const override;

};
