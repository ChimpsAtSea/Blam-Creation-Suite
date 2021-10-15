#pragma once

class c_tag_header_chunk : public c_typed_chunk<'tag!'>
{
public:
	c_tag_header_chunk(void* chunk_data);
};

