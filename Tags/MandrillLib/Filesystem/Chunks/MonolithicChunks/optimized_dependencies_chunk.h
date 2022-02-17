#pragma once

class c_optimized_dependencies_chunk : public c_typed_chunk<'opti'>
{
public:
	c_optimized_dependencies_chunk(const void* chunk_data, c_chunk& parent);
};
