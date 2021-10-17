#pragma once

#include <stack>
#include <map>

class c_single_tag_file_layout_reader;
class c_binary_data_chunk;
class c_tag_block_chunk;
class c_tag_struct_chunk;

struct s_single_tag_file_reader_structure_entry
{
	const blofeld::s_tag_struct_definition* tag_struct_definition;
	const s_struct_definition_entry* struct_definition_entry;
	blofeld::s_tag_persistent_identifier persistent_identifier;
};

class c_single_tag_file_reader
{
public:
	s_single_tag_file_header& header;
	c_single_tag_file_layout_reader& layout_reader;
	c_binary_data_chunk& binary_data_chunk;

	std::stack<unsigned long> metadata_stack;

	const blofeld::s_tag_struct_definition** tag_struct_definitions;
	using t_tag_struct_definition_table = std::map<XXH64_hash_t, const blofeld::s_tag_struct_definition*>;
	s_single_tag_file_reader_structure_entry* struct_entries_data;
	t_tag_struct_definition_table tag_struct_definitions_lookup_table;

	s_engine_platform_build engine_platform_build;

	const blofeld::s_tag_group* blofeld_tag_group;
	const blofeld::s_tag_block_definition* blofeld_tag_block_definition;
	const blofeld::s_tag_struct_definition* blofeld_tag_group_struct_definition;

	c_single_tag_file_reader(
		s_single_tag_file_header& header,
		s_engine_platform_build engine_platform_build,
		c_single_tag_file_layout_reader& layout_reader,
		c_binary_data_chunk& binary_data_chunk);
	~c_single_tag_file_reader();

	BCS_RESULT parse_high_level_object(h_tag*& high_level_tag);

	BCS_RESULT read_tag_block_structure_to_high_level_object(
		c_tag_block_chunk& tag_group_block,
		unsigned long tag_block_index,
		h_object*& high_level_object);

	BCS_RESULT read_tag_struct_to_high_level_object_ref(
		h_object& high_level_object,
		s_struct_definition_entry& structure_entry,
		char* const structure_data_begin,
		c_tag_struct_chunk* structure_chunk);

	BCS_RESULT get_tag_struct_definition_by_persistent_identifier(
		const blofeld::s_tag_persistent_identifier& persistent_identifier,
		const blofeld::s_tag_struct_definition*& tag_struct_definition) const;

	BCS_RESULT get_tag_struct_definition_by_index(
		unsigned long index,
		const blofeld::s_tag_struct_definition*& tag_struct_definition) const;
	
};
