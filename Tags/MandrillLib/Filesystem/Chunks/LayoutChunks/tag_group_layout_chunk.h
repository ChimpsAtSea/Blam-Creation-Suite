#pragma once

enum s_tag_group_layout_header_version
{
	_tag_persist_layout_version_prechunk = 1,
	_tag_persist_layout_version_preinterop,
	_tag_persist_layout_version_v3,
};

struct s_tag_group_layout_header
{
	unsigned long unknown;
	char guid[16];
	s_tag_group_layout_header_version layout_version;
};
static_assert(sizeof(s_tag_group_layout_header) == 0x18);

struct s_tag_persist_layout_header_prechunk
{
	unsigned long string_data_size;
	unsigned long string_offset_count;
	unsigned long string_list_count;
	unsigned long custom_block_index_search_names_count;
	unsigned long data_definition_name_count;
	unsigned long array_definition_count;
	unsigned long field_type_count;
	unsigned long field_count;
	unsigned long aggregate_definition_count;
};
static_assert(sizeof(s_tag_persist_layout_header_prechunk) == 0x24);

struct s_tag_persist_layout_header_preinterop
{
	unsigned long tag_group_block_index;
	unsigned long string_data_size;
	unsigned long string_offset_count;
	unsigned long string_list_count;
	unsigned long custom_block_index_search_names_count;
	unsigned long data_definition_name_count;
	unsigned long array_definition_count;
	unsigned long field_type_count;
	unsigned long field_count;
	unsigned long block_definition_count;
	unsigned long struct_definition_count;
	unsigned long resource_definition_count;
};
static_assert(sizeof(s_tag_persist_layout_header_preinterop) == 0x30);

struct s_tag_persist_layout_header_v3 :
	public s_tag_persist_layout_header_preinterop
{
	unsigned long interop_definition_count;
};
static_assert(sizeof(s_tag_persist_layout_header_v3) == 0x34);

class c_tag_group_layout_chunk : public c_typed_chunk<'blay'>
{
public:
	s_tag_group_layout_header* tag_group_layout_header;

	s_tag_persist_layout_header_prechunk* layout_header_prechunk;
	s_tag_persist_layout_header_preinterop* layout_header_preinterop;
	s_tag_persist_layout_header_v3* layout_header_v3;

	unsigned long get_tag_group_block_index() const;
	unsigned long get_string_data_size() const;
	unsigned long get_string_offset_count() const;
	unsigned long get_string_list_count() const;
	unsigned long get_custom_block_index_search_names_count() const;
	unsigned long get_data_definition_name_count() const;
	unsigned long get_array_definition_count() const;
	unsigned long get_field_type_count() const;
	unsigned long get_field_count() const;
	unsigned long get_block_definition_count() const;
	unsigned long get_struct_definition_count() const;
	unsigned long get_resource_definition_count() const;
	unsigned long get_interop_definition_count() const;
	unsigned long get_aggregate_definition_count() const;

	c_tag_group_layout_chunk(void* chunk_data, c_chunk& parent);
};
