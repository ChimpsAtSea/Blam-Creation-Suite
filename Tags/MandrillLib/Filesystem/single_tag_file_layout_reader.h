#pragma once

struct s_tag_persist_struct_definition;

class c_tag_group_layout_chunk;
class c_string_data_chunk;
class c_array_definitions_chunk;
class c_data_definition_name_chunk;
class c_block_definitions_chunk;
class c_field_types_chunk;
class c_tag_layout_prechunk_chunk;
class c_fields_chunk;
class c_structure_definitions_chunk;
class c_custom_block_index_search_names_chunk;
class c_resource_definitions_chunk;
class c_interop_definitions_chunk;

struct s_tag_persist_string_character_index;
struct s_tag_persist_block_definition;
struct s_tag_persist_struct_definition;
struct s_tag_persist_array_definition;
struct s_tag_persist_resource_definition;
struct s_tag_persist_interop_definition;
struct s_tag_persist_field;
struct s_tag_persist_field_type;
struct s_tag_persist_aggregate_prechunk;
struct s_tag_persist_aggregate_fixup;

class c_single_tag_file_layout_reader
{
public:
	c_chunk* root_chunk;
	c_tag_group_layout_chunk* tag_group_layout_chunk;
	c_binary_data_chunk* binary_data_chunk;

	c_single_tag_file_layout_reader(s_single_tag_file_header& header, const void* tag_file_data);
	~c_single_tag_file_layout_reader();

	unsigned long calculate_structure_size_by_index(unsigned long structure_index);
	unsigned long calculate_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry);
	unsigned long calculate_structure_expected_children(unsigned long structure_index);
	unsigned long calculate_structure_expected_children_by_entry(const s_tag_persist_struct_definition& structure_entry);

	const char* get_string_by_string_character_index(const s_tag_persist_string_character_index& string_character_index) const;
	const char* get_custom_block_index_search_name_by_index(unsigned long custom_block_index_search_name_index) const;
	const char* get_data_definition_name_by_index(unsigned long data_definition_index) const;
	s_tag_persist_block_definition& get_block_definition_by_index(unsigned long index) const;
	s_tag_persist_struct_definition& get_struct_definition_by_index(unsigned long index) const;
	s_tag_persist_array_definition& get_array_definition_by_index(unsigned long index) const;
	s_tag_persist_resource_definition& get_resource_definition_by_index(unsigned long index) const;
	s_tag_persist_interop_definition& get_interop_definition_by_index(unsigned long index) const;
	s_tag_persist_aggregate_prechunk& get_aggregate_by_index(unsigned long index) const;
	s_tag_persist_field& get_field_by_index(unsigned long index) const;
	s_tag_persist_field_type& get_field_type_by_index(unsigned long index) const;

	c_tag_layout_prechunk_chunk* tag_layout_prechunk_chunk;
protected:
	s_tag_persist_aggregate_fixup* aggregate_entries;
	c_string_data_chunk* string_data_chunk;
	c_custom_block_index_search_names_chunk* custom_block_index_search_names_chunk;
	c_array_definitions_chunk* array_definitions_chunk;
	c_data_definition_name_chunk* data_definition_name_chunk;
	c_block_definitions_chunk* block_definitions_chunk;
	c_field_types_chunk* field_types_chunk;
	c_fields_chunk* fields_chunk;
	c_structure_definitions_chunk* structure_definitions_chunk;
	c_resource_definitions_chunk* resource_definitions_chunk;
	c_interop_definitions_chunk* interop_definitions_chunk;
};
