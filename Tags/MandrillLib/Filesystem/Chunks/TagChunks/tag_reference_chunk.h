#pragma once

class c_tag_reference_chunk : public c_typed_single_tag_file_reader_chunk<'tgrf'>
{
public:
	tag group_tag;
	char* tag_filepath_without_extension;

	c_tag_reference_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_reference_chunk();
	virtual void log_impl(c_single_tag_file_layout_reader& layout_reader) const override;
};
