#pragma once

class c_binary_data_chunk : public c_typed_chunk<'bdat'>
{
public:
	c_binary_data_chunk(void* chunk_data, c_chunk& parent);
};
