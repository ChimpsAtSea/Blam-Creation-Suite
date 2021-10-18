#pragma once

class c_tag_string_id_chunk : public c_typed_single_tag_file_reader_chunk<'tgsi'>
{
public:
	char* string;

	c_tag_string_id_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_string_id_chunk();
	virtual void log_impl(c_single_tag_file_layout_reader& layout_reader) const override;
};
