#pragma once

struct s_field_entry
{
	unsigned long name_string_offset;
	unsigned long tag_field_type_index;
	unsigned long metadata;
};

class s_fields_chunk : public c_typed_chunk<'gras'>
{
public:
	s_field_entry* const entries;
	unsigned long const entry_count;

	s_fields_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;

};
