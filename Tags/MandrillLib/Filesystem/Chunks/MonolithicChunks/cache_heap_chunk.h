#pragma once

class c_cache_heap_chunk : public c_typed_chunk<'cash'>
{
public:
	c_cache_heap_chunk(const void* chunk_data, c_chunk& parent);
};
