#pragma once

class c_partition_list_chunk : public c_typed_chunk<'ptls', true>
{
public:
	BCS_SHARED c_partition_list_chunk(c_chunk& parent);
};
