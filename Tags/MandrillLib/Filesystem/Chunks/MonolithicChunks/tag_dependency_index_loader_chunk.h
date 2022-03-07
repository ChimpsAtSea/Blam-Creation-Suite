#pragma once

class c_tag_dependency_index_loader_chunk : public c_typed_chunk<'mtdp', true>
{
public:
	c_tag_dependency_index_loader_chunk(c_chunk& parent);
};
