#pragma once

typedef struct _iobuf FILE;

class c_chunk;
class c_tag_header_chunk;
class c_tag_group_layout_chunk;
class c_tag_layout_v3_chunk;
class c_string_data_chunk;
class c_string_offsets_chunk;
class c_string_lists_chunk;
class c_custom_block_index_search_names_chunk;
class c_data_definition_name_chunk;
class c_array_definitions_chunk;
class c_field_types_chunk;
class c_fields_chunk;
class c_block_definitions_chunk;
class c_resource_definitions_chunk;
class c_interop_definitions_chunk;
class c_structure_definitions_chunk;
class c_binary_data_chunk;

struct s_tag_persist_string_list;

namespace blofeld
{
	struct s_tag_block_definition;
}

class c_high_level_tag_file_writer :
	public c_tag_file_string_debugger
{
public:
	BCS_DEBUG_API c_high_level_tag_file_writer(s_engine_platform_build engine_platform_build, const char* filepath, h_tag& tag);
	BCS_DEBUG_API ~c_high_level_tag_file_writer();

	void init_chunks();
	void write_file();
	void write_chunk(c_chunk& chunk);


	virtual const char* get_string_by_string_character_index(const s_tag_persist_string_character_index& string_character_index) const override;

	h_tag& tag;
	const char* filepath;
	s_engine_platform_build engine_platform_build;

	FILE* file_handle;

	s_single_tag_file_header tag_file_header;
	c_tag_header_chunk* header_chunk;
	c_tag_group_layout_chunk* tag_group_layout_chunk;
	c_tag_layout_v3_chunk* tag_layout_chunk;
	c_string_data_chunk* string_data_chunk;
	c_string_offsets_chunk* string_offsets_chunk;
	c_string_lists_chunk* string_lists_chunk;
	c_custom_block_index_search_names_chunk* custom_block_index_search_names_chunk;
	c_data_definition_name_chunk* data_definition_name_chunk;
	c_array_definitions_chunk* array_definitions_chunk;
	c_field_types_chunk* field_types_chunk;
	c_fields_chunk* fields_chunk;
	c_block_definitions_chunk* block_definitions_chunk;
	c_resource_definitions_chunk* resource_definitions_chunk;
	c_interop_definitions_chunk* interop_definitions_chunk;
	c_structure_definitions_chunk* structure_definitions_chunk;
	c_binary_data_chunk* binary_data_chunk;

	uint32_t enqueue_block_definition(const blofeld::s_tag_block_definition& tag_block_definition);
	uint32_t enqueue_struct_definition(const blofeld::s_tag_struct_definition& tag_struct_definition);
	void enqueue_field(const blofeld::s_tag_field& field, s_tag_persist_field& tag_persist_field);
	uint32_t enqueue_field_type(blofeld::e_field field_type);
	uint32_t enqueue_array_definition(const blofeld::s_tag_array_definition& tag_array_definition);
	uint32_t enqueue_string_list_definition(const blofeld::s_string_list_definition& string_list_definition);
	uint32_t enqueue_data_definition(const blofeld::s_tag_data_definition& tag_data_definition);
	uint32_t enqueue_resource_definition(const blofeld::s_tag_resource_definition& tag_resource_definition);
	uint32_t enqueue_interop_definition(const blofeld::s_tag_interop_definition& tag_interop_definition);
	uint32_t enqueue_block_index_custom_search_definition(const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition);

	uint32_t enqueue_string(const char* string);
	uint32_t enqueue_string_list(s_tag_persist_string_list& string_list);

	void serialize_tag_group(const h_tag& tag, c_binary_data_chunk& parent_chunk);
	void serialize_tag_block(const h_block& block, c_tag_struct_chunk& parent_chunk);
	void serialize_tag_struct(const h_prototype& object, char* const structure_data, c_tag_struct_chunk* tag_struct_chunk);
	void serialize_tag_data(const h_data& data, c_tag_struct_chunk& parent_chunk);
	void serialize_tag_resource(const h_resource* data, const blofeld::s_tag_resource_definition& tag_resource_definition, c_tag_struct_chunk& parent_chunk);
	void serialize_string_id(const h_string_id& string_id, c_tag_struct_chunk& parent_chunk);
	void serialize_tag_reference(const h_tag_reference& reference, const blofeld::s_tag_reference_definition& tag_reference_definition, c_tag_struct_chunk& parent_chunk);

	uint32_t calculate_structure_size(const h_prototype& object);
	uint32_t calculate_structure_size(const blofeld::s_tag_struct_definition& tag_struct_definition);
};
