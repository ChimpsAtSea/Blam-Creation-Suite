#pragma once

class c_string_data_chunk : public c_typed_chunk<'str*'>
{
public:

	c_string_data_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_single_tag_file_layout_reader& layout_reader) const override;

};
