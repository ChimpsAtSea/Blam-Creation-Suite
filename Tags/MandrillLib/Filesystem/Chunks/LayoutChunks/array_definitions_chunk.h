#pragma once

struct s_array_entry
{
	uint32_t name_string_offset;
	uint32_t count;
	uint32_t structure_index;
};

class c_array_definitions_chunk : public c_typed_chunk<'arr!'>
{
public:
	s_array_entry* const entries;
	unsigned long const entry_count;

	c_array_definitions_chunk(void* chunk_data, c_chunk& parent);
	void log_impl(c_string_data_chunk* string_data_chunk) const override;

};
