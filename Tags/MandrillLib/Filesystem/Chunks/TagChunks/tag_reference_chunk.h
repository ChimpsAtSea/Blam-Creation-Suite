#pragma once

class c_tag_reference_chunk : public c_typed_single_tag_file_reader_chunk<'tgrf', false>
{
public:
	tag group_tag;
	char* tag_filepath_without_extension;

	c_tag_reference_chunk(c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_reference_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);
	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
};
