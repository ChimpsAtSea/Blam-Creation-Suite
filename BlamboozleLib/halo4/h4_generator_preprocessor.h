#pragma once

class c_h4_blamboozle;
class c_h4_generator_preprocessor;
class c_h4_tag_group_container;
class c_h4_tag_block_container;
class c_h4_tag_struct_container;

class c_h4_source_file
{
public:
	c_h4_source_file(const char* filepath, c_h4_generator_preprocessor& preprocessor);

	std::string filepath;
	c_h4_generator_preprocessor& preprocessor;
	std::string source_output_filepath;
	std::string header_output_filepath;
	std::string full_source_output_filepath;
	std::string full_header_output_filepath;
	std::vector<c_h4_tag_group_container*> tag_groups;
	std::vector<c_h4_tag_block_container*> tag_blocks;
	std::vector<c_h4_tag_struct_container*> tag_structs;
	std::stringstream source_stream;
	std::stringstream header_stream;
};

class c_h4_tag_group_container
{
public:
	c_h4_tag_group_container(c_h4_tag_group& tag_group, c_h4_generator_preprocessor& preprocessor, c_h4_source_file& source_file);
	bool operator ==(const c_h4_tag_group_container& container) const;

	c_h4_tag_group& tag_group;
	c_h4_source_file& source_file;
	c_h4_tag_block_container* tag_block_container;
	c_h4_tag_struct_container* tag_struct_container;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	bool define_tag_group_block_and_fields;
};

class c_h4_tag_block_container
{
public:
	c_h4_tag_block_container(c_h4_tag_block& tag_block, c_h4_generator_preprocessor& preprocessor, bool is_tag);
	bool operator ==(const c_h4_tag_block_container& container) const;

	c_h4_tag_block& tag_block;
	c_h4_tag_struct_container* tag_struct_container;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	bool use_tag_block_definition;
	bool defined_by_tag_group;
	bool has_traversed;
};

class c_h4_tag_struct_container
{
public:
	c_h4_tag_struct_container(c_h4_tag_struct& tag_struct, c_h4_generator_preprocessor& preprocessor, bool is_tag);
	bool operator ==(const c_h4_tag_struct_container& container) const;

	c_h4_tag_struct& tag_struct;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	bool is_block;
	bool is_tag_group;
	bool has_traversed;
};

class c_h4_tag_enum_container
{
public:
	c_h4_tag_enum_container(c_h4_tag_enum& tag_enum, c_h4_generator_preprocessor& preprocessor, bool is_tag);
	bool operator ==(const c_h4_tag_enum_container& container) const;

	c_h4_tag_enum& tag_enum;
	std::string name;
	std::string symbol_name;
	std::string name_uppercase;
	bool is_block;
	bool is_tag_group;
	bool has_traversed;
};

class c_h4_generator_preprocessor
{
public:
	c_h4_generator_preprocessor(c_h4_blamboozle& blamboozle);
	~c_h4_generator_preprocessor();
	c_h4_tag_block_container* find_existing_tag_block_container(c_h4_tag_block& tag_block);
	c_h4_tag_struct_container* find_existing_tag_struct_container(c_h4_tag_struct& tag_struct);
	c_h4_source_file& get_source_file(const char* filepath, c_h4_generator_preprocessor& preprocessor);
	c_h4_tag_block_container& traverse_tag_blocks(c_h4_tag_block& tag_block, bool is_tag = false, bool traverse = true);
	c_h4_tag_struct_container& traverse_tag_structs(c_h4_tag_struct& tag_struct, bool is_block = false, bool traverse = true);
	void cleanup_tag_blocks();
	void cleanup_tag_structs();

	c_h4_tag_group_container* get_container_by_group_tag(uint32_t group_tag);
	void create_tag_block_source_count_constants(c_h4_tag_block& tag_block);

	c_h4_blamboozle& blamboozle;
	std::vector<c_h4_source_file*> source_files;
	std::vector<c_h4_tag_group_container*> tag_group_containers;
	std::vector<c_h4_tag_block_container*> tag_block_containers;
	std::vector<c_h4_tag_struct_container*> tag_struct_containers;
	std::vector<c_h4_tag_enum_container*> tag_enum_containers;
	std::vector<std::string> maximum_count_constants_source_lines_define;
	std::vector<std::string> maximum_count_constants_source_lines_constant;
	std::vector<std::string> maximum_count_constants_source_lines_struct;
	std::map<std::string, uint32_t> tag_type_name_unique_counter;
};

