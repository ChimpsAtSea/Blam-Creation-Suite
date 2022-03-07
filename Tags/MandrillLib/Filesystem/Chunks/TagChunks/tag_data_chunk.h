#pragma once

class c_tag_data_chunk : public c_typed_single_tag_file_reader_chunk<'tgda', false>
{
public:
	unsigned long data_length;
	char* data;

	c_tag_data_chunk(c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_data_chunk();
	BCS_RESULT read_chunk(void* userdata, const void* _data, bool use_read_only, bool parse_children);
	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
