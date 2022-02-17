#pragma once

class c_monolithic_index_chunk : public c_typed_chunk<'mtag'>
{
public:
	c_monolithic_index_chunk(const void* chunk_data, c_chunk& parent);
};
