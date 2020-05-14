#pragma once

class c_h4_blamboozle;
class c_h4_tag_group_container;

class c_h4_source_file
{
public:
	c_h4_source_file(const char* filepath);

	std::string filepath;
	std::string source_output_filepath;
	std::string header_output_filepath;
	std::string full_source_output_filepath;
	std::string full_header_output_filepath;
	std::vector<c_h4_tag_group_container*> tag_groups;
	std::stringstream source_stream;
	std::stringstream header_stream;
};

class c_h4_tag_group_container
{
public:
	c_h4_tag_group_container(c_h4_tag_group& tag_group, c_h4_source_file& source_file);
	bool operator ==(const c_h4_tag_group_container& container) const;

	c_h4_tag_group& tag_group;
	c_h4_source_file& source_file;	
	std::string name_uppercase;
};

class c_h4_generator_preprocessor
{
public:
	c_h4_generator_preprocessor(c_h4_blamboozle& blamboozle);
	~c_h4_generator_preprocessor();
	c_h4_source_file& get_source_file(const char* filepath);

	c_h4_tag_group_container* get_container_by_group_tag(uint32_t group_tag);

	c_h4_blamboozle& blamboozle;
	std::vector<c_h4_source_file*> source_files;
	std::vector<c_h4_tag_group_container*> tag_group_containers;
};

