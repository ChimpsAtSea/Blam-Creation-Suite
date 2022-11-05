#pragma once

class c_binary_data_chunk : public c_typed_chunk<'bdat', false>
{
public:
	BCS_SHARED c_binary_data_chunk(c_chunk& parent);
};
