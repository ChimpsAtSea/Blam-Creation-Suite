#pragma once

class c_partitioned_persistent_heap_backend_chunk : public c_typed_chunk<'disk'>
{
public:
	c_partitioned_persistent_heap_backend_chunk(void* chunk_data, c_chunk& parent);
};
