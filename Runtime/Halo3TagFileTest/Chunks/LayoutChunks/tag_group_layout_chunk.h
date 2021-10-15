#pragma once

struct s_tag_group_layout_header
{
	unsigned long unknown;
	char guid[16];
	unsigned long unknown14;
	unsigned long tag_group_block_index;
	unsigned long string_data_size;
	unsigned long string_offset_count;
	unsigned long string_list_count;
	unsigned long custom_block_index_search_names_count;
	unsigned long data_definition_name_count;
	unsigned long array_definition_count;
	unsigned long tag_field_type_count;
	unsigned long field_count;
	unsigned long block_definition_count;
	unsigned long struct_definition_count;
	unsigned long resource_definition_count;
	unsigned long interop_definition_count;
};

static_assert(sizeof(s_tag_group_layout_header) == 0x4C);
class c_tag_group_layout_chunk : public c_typed_chunk<'blay'>
{
public:
	s_tag_group_layout_header* tag_group_layout_header;

	c_tag_group_layout_chunk(void* chunk_data, c_chunk& parent);
};
