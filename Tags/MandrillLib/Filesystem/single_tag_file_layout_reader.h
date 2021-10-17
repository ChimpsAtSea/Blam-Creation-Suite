#pragma once

struct s_struct_definition_entry;

class c_tag_group_layout_chunk;
class c_string_data_chunk;
class c_array_definitions_chunk;
class c_data_definition_name_chunk;
class c_block_definitions_chunk;
class c_tag_field_types_chunk;
class c_fields_chunk;
class c_structure_definitions_chunk;

class c_single_tag_file_layout_reader
{
public:
	c_tag_group_layout_chunk& tag_group_layout_chunk;
	c_string_data_chunk* string_data_chunk;
	c_array_definitions_chunk* array_definitions_chunk;
	c_data_definition_name_chunk* data_definition_name_chunk;
	c_block_definitions_chunk* block_definitions_chunk;
	c_tag_field_types_chunk* tag_field_types_chunk;
	c_fields_chunk* fields_chunk;
	c_structure_definitions_chunk* structure_definitions_chunk;

	c_single_tag_file_layout_reader(c_tag_group_layout_chunk& tag_group_layout_chunk);

	unsigned long calculate_structure_size_by_index(unsigned long structure_index);
	unsigned long calculate_structure_size_by_entry(const s_struct_definition_entry& structure_entry);
};
