#pragma once

class c_low_level_tag_source_generator :
	public c_source_generator_base
{
public:
	c_low_level_tag_source_generator(s_engine_platform_build engine_platform_build);
	virtual ~c_low_level_tag_source_generator();

	void generate_header();
	void generate_ida_header();
	void generate_source();
	void generate_enum_header();

	std::string output_directory;
	std::string output_header_file_path;
	std::string output_ida_header_file_path;
	std::string output_enum_header_file_path;
	std::string output_source_file_path;

	static const char* field_type_to_low_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
};

