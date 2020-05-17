#pragma once

class c_h4_blamboozle;
class c_h4_generator_preprocessor;

class c_h4_source_generator
{
public:
	c_h4_source_generator(c_h4_blamboozle& blamboozle, c_h4_generator_preprocessor& preprocessor);
	~c_h4_source_generator();
	void create_blofeld_header(std::stringstream& hs);
	void create_blofeld_source(std::stringstream& ss);
	void create_validation_header(std::stringstream& hs);
	void create_validation_source(std::stringstream& ss);
	void create_tag_group_header(std::stringstream& hs, c_h4_tag_group_container& tag_group_container);
	void create_tag_block_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container);
	void create_tag_block_source(std::stringstream& ss, c_h4_tag_block_container& tag_block_container);
	void create_tag_array_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container);
	void create_tag_array_source(std::stringstream& ss, c_h4_tag_block_container& tag_block_container);
	void create_tag_struct_header(std::stringstream& hs, c_h4_tag_struct_container& tag_struct_container);
	void create_tag_struct_source(std::stringstream& ss, c_h4_tag_struct_container& tag_struct_container);
	void create_tag_group_source(std::stringstream& ss, c_h4_tag_group_container& tag_group_container);
	void create_tag_enum_header(std::stringstream& hs, c_h4_tag_enum_container& tag_enum_container);
	void create_tag_enum_source(std::stringstream& ss, c_h4_tag_enum_container& tag_enum_container, bool is_header);
	void generate_tag_fields_source(std::stringstream& ss, std::vector<c_h4_tag_field*>& tag_fields);

	c_h4_blamboozle& blamboozle;
	c_h4_generator_preprocessor& preprocessor;
};