#pragma once

class c_binary_data_chunk : public c_typed_single_tag_file_reader_chunk<'bdat'>
{
public:
	c_binary_data_chunk(void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader);
};
