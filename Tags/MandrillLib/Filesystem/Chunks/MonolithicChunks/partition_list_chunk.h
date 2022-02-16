#pragma once

class c_partition_list_chunk : public c_typed_chunk<'ptls'>
{
public:
	c_partition_list_chunk(void* chunk_data, c_chunk& parent);
};
