#pragma once

struct s_tag_persist_field
{
	s_tag_persist_string_character_index string_character_index;
	uint32_t field_type_index;
	uint32_t metadata;
};

class c_fields_chunk : public c_typed_chunk<'gras', false>
{
public:
	s_tag_persist_field* entries;
	uint32_t entry_count;

	c_fields_chunk(c_chunk& parent);
	~c_fields_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, uint32_t data_size) override;
	void read_entries();

};
