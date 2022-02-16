#pragma once

struct s_tag_persist_field
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long field_type_index;
	unsigned long metadata;
};

class c_fields_chunk : public c_typed_chunk<'gras'>
{
public:
	s_tag_persist_field* const entries;
	unsigned long const entry_count;

	c_fields_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;

};
