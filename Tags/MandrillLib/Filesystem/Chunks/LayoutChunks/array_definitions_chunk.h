#pragma once

struct s_tag_persist_array_definition
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long count;
	unsigned long structure_entry_index;
};

class c_array_definitions_chunk : public c_typed_chunk<'arr!'>
{
public:
	s_tag_persist_array_definition* entries;
	unsigned long const entry_count;

	c_array_definitions_chunk(const void* chunk_data, c_chunk& parent);
	~c_array_definitions_chunk();

	void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;

};
