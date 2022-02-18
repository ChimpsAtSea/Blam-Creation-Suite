#pragma once

class c_tag_resource_null_chunk : public c_typed_single_tag_file_reader_chunk<'tg\0c'>
{
public:
	c_tag_resource_null_chunk(const void* chunk_data, c_chunk& parent, c_single_tag_file_reader& reader);
	~c_tag_resource_null_chunk();
};
