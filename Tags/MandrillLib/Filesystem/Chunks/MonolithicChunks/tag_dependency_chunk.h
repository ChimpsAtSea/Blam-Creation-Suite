#pragma once

class c_tag_dependency_chunk : public c_typed_chunk<'tree'>
{
public:
	c_tag_dependency_chunk(void* chunk_data, c_chunk& parent);
};
