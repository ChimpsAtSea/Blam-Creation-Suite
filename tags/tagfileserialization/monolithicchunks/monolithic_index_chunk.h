#pragma once

class c_monolithic_index_chunk : public c_typed_chunk<'mtag', true>
{
public:
	BCS_SHARED c_monolithic_index_chunk(c_chunk& parent);
};
