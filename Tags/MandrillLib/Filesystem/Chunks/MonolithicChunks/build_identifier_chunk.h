#pragma once

class c_build_identifier_chunk : public c_typed_chunk<'id#6'>
{
public:
	unsigned long long id;

	c_build_identifier_chunk(void* chunk_data, c_chunk& parent);
};
