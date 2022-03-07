#pragma once

class c_tag_string_id_chunk : public c_typed_single_tag_file_reader_chunk<'tgsi', false>
{
public:
	const char* string;

	c_tag_string_id_chunk(c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_string_id_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
