#include "mandrilllib-private-pch.h"

template<> void byteswap_inplace(s_tag_persist_aggregate_prechunk& value)
{
	byteswap_inplace(value.persistent_identifier);
	byteswap_inplace(value.string_character_index);
	byteswap_inplace(value.count);
	byteswap_inplace(value.fields_start_index);
}

c_tag_layout_prechunk_chunk::c_tag_layout_prechunk_chunk(c_chunk& parent) :
	c_typed_chunk(&parent),
	layout_header_prechunk(),
	string_data(),
	string_offsets(),
	string_list(),
	custom_block_index_search_names(),
	data_definition_names(),
	array_definitions(),
	field_types(),
	fields(),
	aggregate_definitions()
{
}

c_tag_layout_prechunk_chunk::~c_tag_layout_prechunk_chunk()
{
	delete[] string_offsets;
	delete[] string_list;
	delete[] custom_block_index_search_names;
	delete[] data_definition_names;
	delete[] array_definitions;
	delete[] field_types;
	delete[] fields;
	delete[] aggregate_definitions;
}

BCS_RESULT c_tag_layout_prechunk_chunk::read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = c_typed_chunk::read_chunk(userdata, data, use_read_only, parse_children)))
	{
		return rs;
	}

	const s_tag_group_layout_header* src_tag_group_layout_header = reinterpret_cast<const s_tag_group_layout_header*>(get_chunk_data_start());
	s_tag_group_layout_header tag_group_layout_header = chunk_byteswap(*src_tag_group_layout_header);
	ASSERT(tag_group_layout_header.layout_version == _tag_persist_layout_version_prechunk);

	const s_tag_persist_layout_header_prechunk* src_tag_persist_layout_header_prechunk = next_contiguous_pointer(s_tag_persist_layout_header_prechunk, src_tag_group_layout_header);
	layout_header_prechunk = chunk_byteswap(*src_tag_persist_layout_header_prechunk);

	const char* src_string_data = next_contiguous_pointer(char, src_tag_persist_layout_header_prechunk);
	if (layout_header_prechunk.string_data_size > 0)
	{
		string_data = src_string_data;
	}

	const s_tag_persist_string_character_index* src_string_offsets = reinterpret_cast<const s_tag_persist_string_character_index*>(src_string_data + layout_header_prechunk.string_data_size);
	if (layout_header_prechunk.string_offset_count > 0)
	{
		string_offsets = new() s_tag_persist_string_character_index[layout_header_prechunk.string_offset_count];
		for (uint32_t string_offset_index = 0; string_offset_index < layout_header_prechunk.string_offset_count; string_offset_index++)
		{
			string_offsets[string_offset_index] = chunk_byteswap(src_string_offsets[string_offset_index]);
		}
	}

	const s_tag_persist_string_list* src_string_list = reinterpret_cast<const s_tag_persist_string_list*>(src_string_offsets + layout_header_prechunk.string_offset_count);
	if (layout_header_prechunk.string_list_count > 0)
	{
		string_list = new() s_tag_persist_string_list[layout_header_prechunk.string_list_count];
		for (uint32_t string_list_index = 0; string_list_index < layout_header_prechunk.string_list_count; string_list_index++)
		{
			string_list[string_list_index] = chunk_byteswap(src_string_list[string_list_index]);
		}
	}

	const s_tag_persist_string_character_index* src_custom_block_index_search_names = reinterpret_cast<const s_tag_persist_string_character_index*>(src_string_list + layout_header_prechunk.string_list_count);
	if (layout_header_prechunk.custom_block_index_search_names_count > 0)
	{
		custom_block_index_search_names = new() s_tag_persist_string_character_index[layout_header_prechunk.custom_block_index_search_names_count];
		for (uint32_t custom_block_index_search_name_index = 0; custom_block_index_search_name_index < layout_header_prechunk.custom_block_index_search_names_count; custom_block_index_search_name_index++)
		{
			custom_block_index_search_names[custom_block_index_search_name_index] = chunk_byteswap(src_custom_block_index_search_names[custom_block_index_search_name_index]);
		}
	}

	const s_tag_persist_string_character_index* src_data_definition_names = reinterpret_cast<const s_tag_persist_string_character_index*>(src_custom_block_index_search_names + layout_header_prechunk.custom_block_index_search_names_count);
	if (layout_header_prechunk.data_definition_name_count > 0)
	{
		data_definition_names = new() s_tag_persist_string_character_index[layout_header_prechunk.data_definition_name_count];
		for (uint32_t data_definition_name_index = 0; data_definition_name_index < layout_header_prechunk.data_definition_name_count; data_definition_name_index++)
		{
			data_definition_names[data_definition_name_index] = chunk_byteswap(src_data_definition_names[data_definition_name_index]);
		}
	}

	const s_tag_persist_array_definition* src_array_definitions = reinterpret_cast<const s_tag_persist_array_definition*>(src_data_definition_names + layout_header_prechunk.data_definition_name_count);
	if (layout_header_prechunk.array_definition_count > 0)
	{
		array_definitions = new() s_tag_persist_array_definition[layout_header_prechunk.array_definition_count];
		for (uint32_t array_definition_index = 0; array_definition_index < layout_header_prechunk.array_definition_count; array_definition_index++)
		{
			array_definitions[array_definition_index] = chunk_byteswap(src_array_definitions[array_definition_index]);
		}
	}

	const s_tag_persist_field_type* src_field_types = reinterpret_cast<const s_tag_persist_field_type*>(src_array_definitions + layout_header_prechunk.array_definition_count);
	if (layout_header_prechunk.field_type_count > 0)
	{
		field_types = new() s_tag_persist_field_type[layout_header_prechunk.field_type_count];
		for (uint32_t field_type_index = 0; field_type_index < layout_header_prechunk.field_type_count; field_type_index++)
		{
			field_types[field_type_index] = chunk_byteswap(src_field_types[field_type_index]);
		}
	}

	const s_tag_persist_field* src_fields = reinterpret_cast<const s_tag_persist_field*>(src_field_types + layout_header_prechunk.field_type_count);
	if (layout_header_prechunk.field_count > 0)
	{
		fields = new() s_tag_persist_field[layout_header_prechunk.field_count];
		for (uint32_t field_type_index = 0; field_type_index < layout_header_prechunk.field_count; field_type_index++)
		{
			fields[field_type_index] = chunk_byteswap(src_fields[field_type_index]);
		}
	}

	const s_tag_persist_aggregate_prechunk* src_aggregate_definitions = reinterpret_cast<const s_tag_persist_aggregate_prechunk*>(src_fields + layout_header_prechunk.field_count);
	if (layout_header_prechunk.aggregate_definition_count > 0)
	{
		aggregate_definitions = new() s_tag_persist_aggregate_prechunk[layout_header_prechunk.aggregate_definition_count];
		for (uint32_t field_type_index = 0; field_type_index < layout_header_prechunk.aggregate_definition_count; field_type_index++)
		{
			aggregate_definitions[field_type_index] = chunk_byteswap(src_aggregate_definitions[field_type_index]);
		}
	}

	//char* expected_data_end = reinterpret_cast<char*>(aggregate_definitions + layout_header_prechunk.aggregate_definition_count);
	//const char* chunk_data_end = get_chunk_data_end();
	//intptr_t a = chunk_data_end - expected_data_end;
	//intptr_t b = expected_data_end - chunk_data_end;
	//ASSERT(expected_data_end == chunk_data_end);

	

	return rs;
}
