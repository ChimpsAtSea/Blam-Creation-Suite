#pragma once

struct s_tag_persist_interop_definition
{
	s_tag_persist_string_character_index string_character_index;
	unsigned long structure_entry_index;
	blofeld::s_tag_persistent_identifier persistent_identifier;
};

class c_interop_definitions_chunk : public c_typed_chunk<']==[', false>
{
public:
	s_tag_persist_interop_definition* entries;
	unsigned long entry_count;

	c_interop_definitions_chunk(c_chunk& parent);
	~c_interop_definitions_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
