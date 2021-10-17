#pragma once

struct s_block_definition_entry
{
	uint32_t name_string_offset;
	uint32_t max_count;
	uint32_t structure_entry_index;
};

class c_block_definitions_chunk : public c_typed_chunk<'blv2'>
{
public:
	s_block_definition_entry* const entries;
	unsigned long const entry_count;

	c_block_definitions_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;
};
