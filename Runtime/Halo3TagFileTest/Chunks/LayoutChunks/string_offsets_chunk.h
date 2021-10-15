#pragma once

class c_string_offsets_chunk : public c_typed_chunk<'sz+x'>
{
public:
	unsigned long* const offsets;
	unsigned long const entry_count;

	c_string_offsets_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;

};
