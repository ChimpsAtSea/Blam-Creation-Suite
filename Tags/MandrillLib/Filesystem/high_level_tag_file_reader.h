#pragma once

struct s_tag_persist_struct_definition;

struct s_blofeld_field_transpose_entry
{
	uint64_t field_size : 20;
	uint64_t blofeld_field_index : 20;
	uint64_t field_index : 20;
	uint64_t can_transpose : 1;
	uint64_t has_child_chunk : 1;

	uint32_t field_metadata;
	blofeld::e_field field_type;

	blofeld::s_tag_field const* blofeld_tag_field;
	//const s_tag_persist_field* tag_persist_field;
	//const s_tag_persist_field_type* tag_persist_field_type;

	//const char* tag_persist_field_name;
	//const char* tag_persist_field_type_name;

	h_serialization_info const* serialization_info;
};

struct s_single_tag_file_reader_structure_entry
{
	const blofeld::s_tag_struct_definition* tag_struct_definition;
	const s_tag_persist_struct_definition* struct_definition_entry;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	std::vector<s_blofeld_field_transpose_entry> transpose_entries;
};

class c_high_level_tag_file_reader :
	public c_tag_file_reader
{
public:
	blofeld::s_tag_group const* blofeld_tag_group;
	blofeld::s_tag_block_definition const* blofeld_tag_block_definition;
	const blofeld::s_tag_struct_definition* blofeld_tag_group_struct_definition;

	s_engine_platform_build engine_platform_build;
	const blofeld::s_tag_struct_definition** tag_struct_definitions;
	s_single_tag_file_reader_structure_entry* struct_entries_data;
	uint32_t structure_entries_data_count;

	blofeld::c_tag_struct_definition_view& tag_structs_view;
	t_inplace_wrapper<blofeld::c_tag_struct_definition_view> tag_structs_view_wrapper;

	c_high_level_tag_file_reader(c_high_level_tag_file_reader const&) = delete;
	BCS_SHARED c_high_level_tag_file_reader(
		s_engine_platform_build engine_platform_build,
		const void* tag_file_data,
		c_monolithic_partition_view* tag_partition_view = nullptr,
		c_monolithic_partition_view* resource_partition_view = nullptr);
	BCS_SHARED ~c_high_level_tag_file_reader();

	BCS_SHARED BCS_RESULT parse_high_level_object(h_prototype*& prototype);

	BCS_RESULT read_tag_block_structure_to_high_level_object(
		c_tag_block_chunk& tag_group_block,
		uint32_t tag_block_index,
		h_prototype& high_level_object);

	BCS_RESULT read_tag_struct_to_high_level_object_ref(
		h_prototype& high_level_object,
		uint32_t structure_entry_index,
		s_tag_persist_struct_definition& structure_entry,
		const char* const structure_data_begin,
		c_tag_struct_chunk* structure_chunk);

	BCS_RESULT get_tag_struct_definition_by_persistent_identifier(
		const blofeld::s_tag_persistent_identifier& persistent_identifier,
		const blofeld::s_tag_struct_definition*& tag_struct_definition) const;

	blofeld::s_tag_struct_definition const& get_tag_struct_definition_by_index(uint32_t index) const;
};
