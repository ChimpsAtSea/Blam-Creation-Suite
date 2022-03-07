#pragma once

class c_partitioned_persistent_heap_backend_chunk : public c_typed_chunk<'disk', true>
{
public:
	c_partitioned_persistent_heap_backend_chunk(c_chunk& parent);
};
