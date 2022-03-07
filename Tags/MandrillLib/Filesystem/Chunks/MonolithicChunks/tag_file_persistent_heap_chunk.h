#pragma once

class c_tag_file_persistent_heap_chunk : public c_typed_chunk<'heap', true>
{
public:
	c_tag_file_persistent_heap_chunk(c_chunk& parent);
};
