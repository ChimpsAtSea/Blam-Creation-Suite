#pragma once

class c_tag_struct_chunk : public c_typed_single_tag_file_reader_chunk<'tgst', true>
{
public:
	c_tag_struct_chunk(c_chunk& parent, c_single_tag_file_reader& reader);
	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
