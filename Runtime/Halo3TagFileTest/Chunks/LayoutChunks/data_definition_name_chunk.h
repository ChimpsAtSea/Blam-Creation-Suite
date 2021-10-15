#pragma once

class c_data_definition_name_chunk : public c_typed_chunk<'dtnm'>
{
public:
	unsigned long* const offsets;
	unsigned long const entry_count;

	c_data_definition_name_chunk(void* chunk_data, c_chunk& parent);
	void log_impl(c_string_data_chunk* string_data_chunk) const override;

};
