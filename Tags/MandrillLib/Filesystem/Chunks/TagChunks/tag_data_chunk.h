#pragma once

class c_tag_data_chunk : public c_typed_chunk<'tgda', false>
{
public:
	uint32_t data_length;
	char* data;

	c_tag_data_chunk(c_chunk& parent);
	~c_tag_data_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, uint32_t data_size) override;
	void read_data();
};
