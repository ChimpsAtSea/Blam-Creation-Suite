#pragma once

struct s_tag_persist_aggregate_prechunk
{
	blofeld::s_tag_persistent_identifier persistent_identifier;
	s_tag_persist_string_character_index string_character_index;
	unsigned long fields_start_index;
	unsigned long unknown18;
};

class s_tag_persist_string_character_index;
class s_tag_persist_string_list;
class s_tag_persist_array_definition;
class s_tag_persist_field_type;
class s_tag_persist_field;
class s_tag_persist_aggregate_prechunk;

class c_tag_layout_prechunk_chunk : public c_typed_chunk<'tgly'>
{
public:
	s_tag_persist_layout_header_prechunk* layout_header_prechunk;

	char* string_data;
	s_tag_persist_string_character_index* string_offsets;
	s_tag_persist_string_list* string_list;
	s_tag_persist_string_character_index* custom_block_index_search_names;
	s_tag_persist_string_character_index* data_definition_names;
	s_tag_persist_array_definition* array_definitions;
	s_tag_persist_field_type* field_types;
	s_tag_persist_field* fields;
	s_tag_persist_aggregate_prechunk* aggregate_definitions;

	c_tag_layout_prechunk_chunk(void* chunk_data, c_chunk& parent);
};
