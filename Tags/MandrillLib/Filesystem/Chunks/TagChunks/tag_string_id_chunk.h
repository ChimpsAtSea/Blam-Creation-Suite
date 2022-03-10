#pragma once

class c_tag_string_id_chunk : public c_typed_chunk<'tgsi', false>
{
public:
	const char* string;

	c_tag_string_id_chunk(c_chunk& parent);
	~c_tag_string_id_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_string(const char* string);
	void read_data();

protected:
	virtual BCS_RESULT set_data(const void* data, unsigned long data_size) override;
};
