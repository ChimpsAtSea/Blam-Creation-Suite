#pragma once

enum e_tag_persist_resource_flags
{
	_tag_persist_resource_flag_unknown0,
	_tag_persist_resource_flag_streaming,
};

struct s_tag_persist_resource_definition
{
	s_tag_persist_string_character_index string_character_index;
	c_flags<e_tag_persist_resource_flags, long> flags;
	unsigned long structure_entry_index;
};

class c_resource_definitions_chunk : public c_typed_chunk<'rcv2', false>
{
public:
	s_tag_persist_resource_definition* entries;
	unsigned long entry_count;

	c_resource_definitions_chunk(c_chunk& parent);
	~c_resource_definitions_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children);

	virtual void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;
};
