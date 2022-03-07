#pragma once

class c_binary_data_chunk : public c_typed_chunk<'bdat', false>
{
public:
	c_binary_data_chunk(c_chunk& parent);
};
