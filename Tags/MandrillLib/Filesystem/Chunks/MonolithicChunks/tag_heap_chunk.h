#pragma once

class c_tag_heap_chunk : public c_typed_chunk<'tags'>
{
public:
	c_tag_heap_chunk(void* chunk_data, c_chunk& parent);
};
