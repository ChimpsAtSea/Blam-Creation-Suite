#include "mandrilllib-private-pch.h"

c_tag_layout_prechunk_chunk::c_tag_layout_prechunk_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	layout_header_prechunk(reinterpret_cast<s_tag_persist_layout_header_prechunk*>(chunk_data_begin + sizeof(s_tag_group_layout_header))),
	string_data(),
	string_offsets(),
	custom_block_index_search_names(),
	data_definition_names(),
	array_definitions(),
	field_types(),
	fields(),
	aggregate_definitions()
{
	// #FIXUP
	c_chunk::signature = c_tag_layout_prechunk_chunk::signature;

	s_tag_group_layout_header* tag_group_layout_header = reinterpret_cast<s_tag_group_layout_header*>(chunk_data_begin);
	ASSERT(tag_group_layout_header->layout_version == _tag_persist_layout_version_prechunk);

	chunk_data_begin = reinterpret_cast<char*>(layout_header_prechunk + 1);

	string_data = chunk_data_begin;
	string_offsets = reinterpret_cast<s_tag_persist_string_character_index*>(string_data + layout_header_prechunk->string_data_size);
	string_list = reinterpret_cast<s_tag_persist_string_list*>(string_offsets + layout_header_prechunk->string_offset_count);
	custom_block_index_search_names = reinterpret_cast<s_tag_persist_string_character_index*>(string_list + layout_header_prechunk->string_list_count);
	data_definition_names = custom_block_index_search_names + layout_header_prechunk->custom_block_index_search_names_count;
	array_definitions = reinterpret_cast<s_tag_persist_array_definition*>(data_definition_names + layout_header_prechunk->data_definition_name_count);
	field_types = reinterpret_cast<s_tag_persist_field_type*>(array_definitions + layout_header_prechunk->array_definition_count);
	fields = reinterpret_cast<s_tag_persist_field*>(field_types + layout_header_prechunk->field_type_count);
	aggregate_definitions = reinterpret_cast<s_tag_persist_aggregate_prechunk*>(fields + layout_header_prechunk->field_count);
	char* expected_data_end = reinterpret_cast<char*>(aggregate_definitions + layout_header_prechunk->aggregate_definition_count);

	if (layout_header_prechunk->string_data_size == 0) string_data = nullptr;
	if (layout_header_prechunk->string_offset_count == 0) string_offsets = nullptr;
	if (layout_header_prechunk->string_list_count == 0) string_list = nullptr;
	if (layout_header_prechunk->custom_block_index_search_names_count == 0) custom_block_index_search_names = nullptr;
	if (layout_header_prechunk->data_definition_name_count == 0) data_definition_names = nullptr;
	if (layout_header_prechunk->array_definition_count == 0) array_definitions = nullptr;
	if (layout_header_prechunk->field_type_count == 0) field_types = nullptr;
	if (layout_header_prechunk->field_count == 0) fields = nullptr;
	if (layout_header_prechunk->aggregate_definition_count == 0) aggregate_definitions = nullptr;

	ASSERT(expected_data_end == chunk_data_end);

	debug_point;

}
