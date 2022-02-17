#pragma once

struct s_tag_persist_field_type
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long size;
	unsigned long metadata;
};

class c_field_types_chunk : public c_typed_chunk<'tgft'>
{
public:
	s_tag_persist_field_type* entries;
	unsigned long const entry_count;

	c_field_types_chunk(const void* chunk_data, c_chunk& parent);
	~c_field_types_chunk();

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;

};
