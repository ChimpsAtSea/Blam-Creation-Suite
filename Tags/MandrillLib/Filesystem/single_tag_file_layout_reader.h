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

class c_single_tag_file_reader;
class c_single_tag_file_layout_reader :
	public c_tag_file_string_debugger
{
public:
	friend c_single_tag_file_reader;
	c_chunk* root_chunk;
	c_tag_group_layout_chunk* tag_group_layout_chunk;
	c_binary_data_chunk* binary_data_chunk;

	BCS_DEBUG_API c_single_tag_file_layout_reader(s_single_tag_file_header& header, const void* tag_file_data);
	BCS_DEBUG_API ~c_single_tag_file_layout_reader();

	uint32_t get_structure_size_by_index(uint32_t structure_index);
	uint32_t get_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry);
	uint32_t get_structure_expected_children_by_index(uint32_t structure_index);
	uint32_t get_structure_expected_children_by_entry(const s_tag_persist_struct_definition& structure_entry);



	blofeld::e_field get_blofeld_type_by_field_type_index(uint32_t field_type_index) const;

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

	using t_persistent_id_to_ulong_map = std::unordered_map<XXH64_hash_t, unsigned long>;
	struct s_structure_precomputed_info
	{
		DEBUG_ONLY(const char* name);
		uint32_t structure_size;
		uint32_t expected_children;
	};
	s_structure_precomputed_info* structure_precomputed_info_by_index;
	c_fast_byte_lookup<s_structure_precomputed_info, 4096, 1024> structure_precomputed_info_by_persistent_identifier;
	uint32_t field_type_to_blofeld_field_type_count;
	blofeld::e_field* field_type_to_blofeld_field_type;

	void calculate_structure_size_and_children();
	uint32_t _calculate_structure_size_by_index(uint32_t structure_index) const;
	uint32_t _calculate_structure_size_by_entry(const s_tag_persist_struct_definition& structure_entry)const;
	uint32_t _calculate_structure_expected_children_by_index(uint32_t structure_index)const;
	uint32_t _calculate_structure_expected_children_by_entry(const s_tag_persist_struct_definition& structure_entry)const;
	void init_structure_type_to_blofeld_type_lookup();

public:
	virtual const char* get_string_by_string_character_index(const s_tag_persist_string_character_index& offset) const override;
	const char* get_custom_block_index_search_name_by_index(uint32_t custom_block_index_search_name_index) const;
	const char* get_data_definition_name_by_index(uint32_t data_definition_index) const;
	s_tag_persist_block_definition& get_block_definition_by_index(uint32_t index) const;
	uint32_t get_struct_definition_count() const;
	s_tag_persist_struct_definition& get_struct_definition_by_index(uint32_t index) const;
	s_tag_persist_array_definition& get_array_definition_by_index(uint32_t index) const;
	s_tag_persist_resource_definition& get_resource_definition_by_index(uint32_t index) const;
	s_tag_persist_interop_definition& get_interop_definition_by_index(uint32_t index) const;
	s_tag_persist_aggregate_prechunk& get_aggregate_by_index(uint32_t index) const;
	s_tag_persist_field& get_field_by_index(uint32_t index) const;
	s_tag_persist_field_type& get_field_type_by_index(uint32_t index) const;

protected:
	void init_string_by_string_character_index();
	void init_custom_block_index_search_name_by_index();
	void init_data_definition_name_by_index();
	void init_block_definition_by_index();
	void init_struct_definition_count();
	void init_struct_definition_by_index();
	void init_array_definition_by_index();
	void init_resource_definition_by_index();
	void init_interop_definition_by_index();
	void init_field_by_index();
	void init_field_type_by_index();

	const char* string_by_string_character_index;
	uint32_t string_by_string_character_index_size;

	s_tag_persist_string_character_index* custom_block_index_search_name_by_index;
	uint32_t custom_block_index_search_name_by_index_count;

	s_tag_persist_string_character_index* data_definition_name_by_index;
	uint32_t data_definition_name_by_index_count;

	s_tag_persist_block_definition* block_definition_by_index; // make sure to free if tag_layout_prechunk is not null
	uint32_t block_definition_by_index_count;

	uint32_t struct_definition_count;

	s_tag_persist_struct_definition* struct_definition_by_index; // make sure to free if tag_layout_prechunk is not null
	uint32_t struct_definition_by_index_count;

	s_tag_persist_array_definition* array_definition_by_index;
	uint32_t array_definition_by_index_count;

	s_tag_persist_resource_definition* resource_definition_by_index;
	uint32_t resource_definition_by_index_count;

	s_tag_persist_interop_definition* interop_definition_by_index;
	uint32_t interop_definition_by_index_count;

	s_tag_persist_field* field_by_index;
	uint32_t field_by_index_count;

	s_tag_persist_field_type* field_type_by_index;
	uint32_t field_type_by_index_count;
};
