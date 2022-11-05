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
	uint32_t structure_entry_index;
};

class c_resource_definitions_chunk : public c_typed_chunk<'rcv2', false>
{
public:
	s_tag_persist_resource_definition* entries;
	uint32_t entry_count;

	BCS_SHARED c_resource_definitions_chunk(c_chunk& parent);
	BCS_SHARED ~c_resource_definitions_chunk();

	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	BCS_SHARED virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	BCS_SHARED virtual BCS_RESULT set_data(const void* data, uint32_t data_size) override;
	BCS_SHARED void read_entries();
};
