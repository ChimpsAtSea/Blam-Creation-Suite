#pragma once

#include <stack>
#include <map>

class c_single_tag_file_layout_reader;
class c_binary_data_chunk;
class c_tag_block_chunk;
class c_tag_struct_chunk;
class c_monolithic_partition_view;

struct s_blofeld_field_transpose_entry
{
	bool can_transpose;

	unsigned long dest_blofeld_field_index;
	const blofeld::s_tag_field* dest_blofeld_field;

	unsigned long src_file_field_index;
	const s_tag_persist_field* src_file_field;
	const s_tag_persist_field_type* src_file_field_type;
	const char* src_file_field_name;
	const char* src_file_field_type_name;
	blofeld::e_field src_file_blofeld_field_type;
};

struct s_single_tag_file_reader_structure_entry
{
	const blofeld::s_tag_struct_definition* tag_struct_definition;
	const s_tag_persist_struct_definition* struct_definition_entry;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	std::vector<s_blofeld_field_transpose_entry> transpose_entries;
};

enum e_tag_file_reader_metadata_entry_type
{
	_tag_file_reader_metadata_entry_type_block,
	_tag_file_reader_metadata_entry_type_resource,
};

struct t_tag_file_reader_metadata_entry
{
	e_tag_file_reader_metadata_entry_type entry_type;
	unsigned long id;
};

#include "tag_file_reader_stack.h"

class c_single_tag_file_reader
{
public:
	s_single_tag_file_header& header;
	c_single_tag_file_layout_reader& layout_reader;
	c_binary_data_chunk& binary_data_chunk;

	bool is_big_endian;

	t_tag_file_reader_metadata_stack metadata_stack;

	const blofeld::s_tag_struct_definition** tag_struct_definitions;
	s_single_tag_file_reader_structure_entry* struct_entries_data;
	unsigned long structure_entries_data_count;
	c_fast_byte_lookup<const blofeld::s_tag_struct_definition*, 4096, 1024> tag_struct_definitions_lookup_table;

	//using t_tag_struct_definition_table = std::unordered_map<XXH64_hash_t, const blofeld::s_tag_struct_definition*>;
	//s_single_tag_file_reader_structure_entry* struct_entries_data;
	//std::vector<s_single_tag_file_reader_structure_entry> struct_entries_data;
	//t_tag_struct_definition_table tag_struct_definitions_lookup_table;

	s_engine_platform_build engine_platform_build;

	c_tag_struct_definition_view& tag_structs_view;
	t_inplace_wrapper<c_tag_struct_definition_view> tag_structs_view_wrapper;

	const blofeld::s_tag_group* blofeld_tag_group;
	const blofeld::s_tag_block_definition* blofeld_tag_block_definition;
	const blofeld::s_tag_struct_definition* blofeld_tag_group_struct_definition;
	c_monolithic_partition_view* tag_partition_view;
	c_monolithic_partition_view* resource_partition_view;

	c_single_tag_file_reader(
		s_single_tag_file_header& header,
		s_engine_platform_build engine_platform_build,
		bool is_big_endian,
		c_single_tag_file_layout_reader& layout_reader,
		c_binary_data_chunk& binary_data_chunk,
		c_monolithic_partition_view* tag_partition_view,
		c_monolithic_partition_view* resource_partition_view);
	~c_single_tag_file_reader();

	BCS_RESULT parse_high_level_object(h_tag*& high_level_tag);

	BCS_RESULT read_tag_block_structure_to_high_level_object(
		c_tag_block_chunk& tag_group_block,
		unsigned long tag_block_index,
		h_object& high_level_object);

	BCS_RESULT read_tag_struct_to_high_level_object_ref(
		h_object& high_level_object,
		unsigned long structure_entry_index,
		s_tag_persist_struct_definition& structure_entry,
		const char* const structure_data_begin,
		c_tag_struct_chunk* structure_chunk);

	BCS_RESULT get_tag_struct_definition_by_persistent_identifier(
		const blofeld::s_tag_persistent_identifier& persistent_identifier,
		const blofeld::s_tag_struct_definition*& tag_struct_definition) const;

	const blofeld::s_tag_struct_definition& get_tag_struct_definition_by_index(unsigned long index) const;
	
};
