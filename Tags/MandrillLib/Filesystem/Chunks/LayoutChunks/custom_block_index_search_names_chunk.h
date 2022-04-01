#pragma once

class c_custom_block_index_search_names_chunk : public c_typed_chunk<'csbn', false>
{
public:
	s_tag_persist_string_character_index* offsets;
	unsigned long entry_count;

	c_custom_block_index_search_names_chunk(c_chunk& parent);
	~c_custom_block_index_search_names_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, unsigned long data_size) override;
	void read_data();
};
