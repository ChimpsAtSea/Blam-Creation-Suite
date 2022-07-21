#pragma once

struct s_tag_persist_string_list
{
	s_tag_persist_string_character_index string_character_index;
	uint32_t string_offset_count;
	uint32_t string_offset_start_index;
};

class c_string_lists_chunk : public c_typed_chunk<'sz[]', false>
{
public:
	s_tag_persist_string_list* entries;
	uint32_t entry_count;

	c_string_lists_chunk(c_chunk& parent);
	~c_string_lists_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, uint32_t data_size) override;
	void read_entries();
};
