#pragma once

enum s_tag_group_layout_header_version
{
	_tag_persist_layout_version_prechunk = 1,
	_tag_persist_layout_version_preinterop,
	_tag_persist_layout_version_v3,
};

struct s_tag_group_layout_header
{
	uint32_t unknown;
	char guid[16];
	s_tag_group_layout_header_version layout_version;
};
static_assert(sizeof(s_tag_group_layout_header) == 0x18);

struct s_tag_persist_layout_header_prechunk
{
	uint32_t string_data_size;
	uint32_t string_offset_count;
	uint32_t string_list_count;
	uint32_t custom_block_index_search_names_count;
	uint32_t data_definition_name_count;
	uint32_t array_definition_count;
	uint32_t field_type_count;
	uint32_t field_count;
	uint32_t aggregate_definition_count;
};
static_assert(sizeof(s_tag_persist_layout_header_prechunk) == 0x24);

struct s_tag_persist_layout_header_preinterop
{
	uint32_t tag_group_block_index;
	uint32_t string_data_size;
	uint32_t string_offset_count;
	uint32_t string_list_count;
	uint32_t custom_block_index_search_names_count;
	uint32_t data_definition_name_count;
	uint32_t array_definition_count;
	uint32_t field_type_count;
	uint32_t field_count;
	uint32_t struct_definition_count;
	uint32_t block_definition_count;
	uint32_t resource_definition_count;
};
static_assert(sizeof(s_tag_persist_layout_header_preinterop) == 0x30);

struct s_tag_persist_layout_header_v3 :
	public s_tag_persist_layout_header_preinterop
{
	uint32_t interop_definition_count;
};
static_assert(sizeof(s_tag_persist_layout_header_v3) == 0x34);

class c_tag_group_layout_chunk : public c_typed_chunk<'blay', true>
{
public:
	s_tag_group_layout_header tag_group_layout_header;

	s_tag_persist_layout_header_prechunk* layout_header_prechunk;
	s_tag_persist_layout_header_preinterop* layout_header_preinterop;
	s_tag_persist_layout_header_v3* layout_header_v3;

	BCS_SHARED uint32_t get_tag_group_block_index() const;
	BCS_SHARED uint32_t get_string_data_size() const;
	BCS_SHARED uint32_t get_string_offset_count() const;
	BCS_SHARED uint32_t get_string_list_count() const;
	BCS_SHARED uint32_t get_custom_block_index_search_names_count() const;
	BCS_SHARED uint32_t get_data_definition_name_count() const;
	BCS_SHARED uint32_t get_array_definition_count() const;
	BCS_SHARED uint32_t get_field_type_count() const;
	BCS_SHARED uint32_t get_field_count() const;
	BCS_SHARED uint32_t get_block_definition_count() const;
	BCS_SHARED uint32_t get_struct_definition_count() const;
	BCS_SHARED uint32_t get_resource_definition_count() const;
	BCS_SHARED uint32_t get_interop_definition_count() const;
	BCS_SHARED uint32_t get_aggregate_definition_count() const;

	BCS_SHARED c_tag_group_layout_chunk(c_chunk& parent);
	BCS_SHARED ~c_tag_group_layout_chunk();

	BCS_SHARED BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

protected:
	union
	{
		s_tag_persist_layout_header_prechunk layout_header_prechunk_data;
		s_tag_persist_layout_header_preinterop layout_header_preinterop_data;
		s_tag_persist_layout_header_v3 layout_header_v3_data;
	};
};
