#pragma once

class c_tag_dependency_index_loader_chunk : public c_typed_chunk<'mtdp'>
{
public:
	c_tag_dependency_index_loader_chunk(const void* chunk_data, c_chunk& parent);
};
