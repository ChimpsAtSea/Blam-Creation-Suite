#pragma once

class c_tag_file_persistent_heap_chunk : public c_typed_chunk<'heap'>
{
public:
	c_tag_file_persistent_heap_chunk(const void* chunk_data, c_chunk& parent);
};
