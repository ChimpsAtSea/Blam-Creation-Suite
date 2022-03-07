#pragma once

class c_data_definition_name_chunk : public c_typed_chunk<'dtnm', false>
{
public:
	s_tag_persist_string_character_index* offsets;
	unsigned long entry_count;

	c_data_definition_name_chunk(c_chunk& parent);
	~c_data_definition_name_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;

};
