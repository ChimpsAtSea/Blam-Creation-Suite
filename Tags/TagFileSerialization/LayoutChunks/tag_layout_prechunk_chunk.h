#pragma once

struct s_tag_persist_aggregate_prechunk
{
	s_system_global_unique_identifier unique_identifier;
	s_tag_persist_string_character_index string_character_index;
	uint32_t count;
	uint32_t fields_start_index;
};

struct s_tag_persist_aggregate_fixup
{
	s_tag_persist_struct_definition struct_definition;
	s_tag_persist_block_definition block_definition;
};

struct s_tag_persist_string_character_index;
struct s_tag_persist_string_list;
struct s_tag_persist_array_definition;
struct s_tag_persist_field_type;
struct s_tag_persist_field;
struct s_tag_persist_aggregate_prechunk;

class c_tag_layout_prechunk_chunk : public c_typed_chunk<'tgly', false>
{
public:
	s_tag_persist_layout_header_prechunk layout_header_prechunk;

	const char* string_data;
	s_tag_persist_string_character_index* string_offsets;
	s_tag_persist_string_list* string_lists;
	s_tag_persist_string_character_index* custom_block_index_search_names;
	s_tag_persist_string_character_index* data_definition_names;
	s_tag_persist_array_definition* array_definitions;
	s_tag_persist_field_type* field_types;
	s_tag_persist_field* fields;
	s_tag_persist_aggregate_prechunk* aggregate_definitions;

	BCS_SHARED c_tag_layout_prechunk_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_layout_prechunk_chunk();
	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;
};
