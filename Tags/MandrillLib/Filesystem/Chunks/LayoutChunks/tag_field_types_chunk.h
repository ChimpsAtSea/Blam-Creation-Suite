#pragma once

struct s_tag_field_type_entry
{
	uint32_t name_string_offset;
	uint32_t size;
	uint32_t metadata;
};

class c_tag_field_types_chunk : public c_typed_chunk<'tgft'>
{
public:
	s_tag_field_type_entry* const entries;
	unsigned long const entry_count;

	c_tag_field_types_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;

};
