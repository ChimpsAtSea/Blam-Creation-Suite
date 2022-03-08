#pragma once

struct s_tag_persist_field_type
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long size;
	bool metadata;
};

class c_field_types_chunk : public c_typed_chunk<'tgft', false>
{
public:
	s_tag_persist_field_type* entries;
	unsigned long entry_count;

	c_field_types_chunk(c_chunk& parent);
	~c_field_types_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, unsigned long data_size) override;
	void read_entries();

};
