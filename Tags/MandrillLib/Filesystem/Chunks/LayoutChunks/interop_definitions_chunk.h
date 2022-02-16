#pragma once

struct s_tag_persist_interop_definition
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long structure_entry_index;
	blofeld::s_tag_persistent_identifier persistent_identifier;
};

class c_interop_definitions_chunk : public c_typed_chunk<']==['>
{
public:
	s_tag_persist_interop_definition* const entries;
	unsigned long const entry_count;

	c_interop_definitions_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
