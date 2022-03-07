#pragma once

class c_monolithic_index_chunk : public c_typed_chunk<'mtag', true>
{
public:
	c_monolithic_index_chunk(c_chunk& parent);
};
