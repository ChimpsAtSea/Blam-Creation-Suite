#pragma once

class c_tag_layout_v3_chunk : public c_typed_chunk<'tgly'>
{
public:
	c_tag_layout_v3_chunk(void* chunk_data, c_chunk& parent);
};
