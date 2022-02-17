#pragma once

class c_tag_header_chunk : public c_typed_chunk<'tag!'>
{
public:
	c_tag_header_chunk(const void* chunk_data);
};

