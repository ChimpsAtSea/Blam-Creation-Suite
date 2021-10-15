#pragma once

class c_custom_block_index_search_names_chunk : public c_typed_chunk<'csbn'>
{
public:
	unsigned long* const offsets;
	unsigned long const entry_count;

	c_custom_block_index_search_names_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;

};
