#pragma once

class c_tag_reference_chunk : public c_typed_chunk<'tgrf', false>
{
public:
	tag group_tag;
	char* tag_filepath_without_extension;

	c_tag_reference_chunk(c_chunk& parent);
	~c_tag_reference_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_reference(tag group_tag, const char* tag_filepath_without_extension);
	void read_data();

protected:
	virtual BCS_RESULT set_data(const void* data, unsigned long data_size) override;
};
