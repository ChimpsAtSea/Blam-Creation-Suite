#pragma once

class c_tag_heap_chunk : public c_typed_chunk<'tags', true>
{
public:
	c_tag_heap_chunk(c_chunk& parent);
};
