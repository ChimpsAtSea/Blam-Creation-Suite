#pragma once

struct s_struct_definition_entry
{
	blofeld::s_tag_persistent_identifier persistent_identifier;
	unsigned long name_string_offset;
	unsigned long fields_start_index;
};

class c_structure_definitions_chunk : public c_typed_chunk<'stv2'>
{
public:
	s_struct_definition_entry* const entries;
	unsigned long const entry_count;

	c_structure_definitions_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;

};

