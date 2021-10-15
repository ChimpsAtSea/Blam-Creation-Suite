#pragma once

struct s_string_list_entry
{
	unsigned long name_string_offset;
	unsigned long string_offset_count;
	unsigned long string_offset_start_index;
};

class c_string_lists_chunk : public c_typed_chunk<'sz[]'>
{
public:
	s_string_list_entry* const entries;
	unsigned long const entry_count;

	c_string_lists_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;
};
