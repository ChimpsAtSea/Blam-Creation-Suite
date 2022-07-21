#pragma once

struct s_tag_persist_string_character_index
{
	uint32_t offset;
};

class c_string_offsets_chunk : public c_typed_chunk<'sz+x', false>
{
public:
	s_tag_persist_string_character_index* offsets;
	uint32_t entry_count;

	c_string_offsets_chunk(c_chunk& parent);
	~c_string_offsets_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, uint32_t data_size) override;
	void read_entries();

};
