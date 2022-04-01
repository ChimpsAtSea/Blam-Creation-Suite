#pragma once

class c_data_definition_name_chunk : public c_typed_chunk<'dtnm', false>
{
public:
	s_tag_persist_string_character_index* offsets;
	unsigned long entry_count;

	c_data_definition_name_chunk(c_chunk& parent);
	~c_data_definition_name_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, unsigned long data_size) override;
	void read_entries();

};
