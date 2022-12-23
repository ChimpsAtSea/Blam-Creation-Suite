#pragma once

class c_cache_heap_chunk : public c_typed_chunk<'cash', true>
{
public:
	BCS_SHARED c_cache_heap_chunk(c_chunk& parent);
};
