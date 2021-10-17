#pragma once

struct s_interop_definition_entry
{
	uint32_t name_string_offset;
	uint32_t structure_entry_index;
	blofeld::s_tag_persistent_identifier persistent_identifier;
};

class c_interop_definitions_chunk : public c_typed_chunk<']==['>
{
public:
	s_interop_definition_entry* const entries;
	unsigned long const entry_count;

	c_interop_definitions_chunk(void* chunk_data, c_chunk& parent);
	virtual void log_impl(c_string_data_chunk* string_data_chunk) const override;
};
