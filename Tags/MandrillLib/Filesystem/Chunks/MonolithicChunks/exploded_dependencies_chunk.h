#pragma once

class c_exploded_dependencies_chunk : public c_typed_chunk<'expl'>
{
public:
	c_exploded_dependencies_chunk(void* chunk_data, c_chunk& parent);
};
