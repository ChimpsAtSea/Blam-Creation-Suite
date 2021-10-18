#pragma once

struct s_tag_persist_struct_definition
{
	blofeld::s_tag_persistent_identifier persistent_identifier;
	s_tag_persist_string_character_index string_character_index;
	unsigned long fields_start_index;
};

class c_structure_definitions_chunk : public c_typed_chunk<'stv2'>
{
public:
	s_tag_persist_struct_definition* const entries;
	unsigned long const entry_count;

	c_structure_definitions_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_single_tag_file_layout_reader& layout_reader) const override;

};

