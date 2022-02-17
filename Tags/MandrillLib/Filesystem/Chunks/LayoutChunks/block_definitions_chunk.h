#pragma once

struct s_tag_persist_block_definition
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long max_count;
	unsigned long structure_entry_index;
};

class c_block_definitions_chunk : public c_typed_chunk<'blv2'>
{
public:
	s_tag_persist_block_definition* entries;
	unsigned long const entry_count;

	c_block_definitions_chunk(const void* chunk_data, c_chunk& parent);
	~c_block_definitions_chunk();

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
