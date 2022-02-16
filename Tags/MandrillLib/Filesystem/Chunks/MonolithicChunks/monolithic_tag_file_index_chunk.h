#pragma once

class c_monolithic_tag_file_index_chunk : public c_typed_chunk<'mtfi'>
{
public:
	c_monolithic_tag_file_index_chunk(void* chunk_data, c_chunk& parent);
};
