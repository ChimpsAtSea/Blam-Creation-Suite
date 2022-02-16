#pragma once

class c_monolithic_tag_backend_chunk : public c_typed_chunk<'tgin'>
{
public:
	c_monolithic_tag_backend_chunk(void* chunk_data);
	~c_monolithic_tag_backend_chunk();
};
