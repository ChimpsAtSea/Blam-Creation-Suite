#pragma once

class c_custom_block_index_search_names_chunk : public c_typed_chunk<'csbn'>
{
public:
	s_tag_persist_string_character_index* offsets;
	unsigned long const entry_count;

	c_custom_block_index_search_names_chunk(const void* chunk_data, c_chunk& parent);
	~c_custom_block_index_search_names_chunk();

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;

};
