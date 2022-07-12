#pragma once

class c_high_level_tag_source_generator :
	public c_source_generator_base
{
public:
	c_high_level_tag_source_generator(s_engine_platform_build engine_platform_build);
	virtual ~c_high_level_tag_source_generator();

	void generate_header();
	void generate_forward_declare();
	void generate_tag_constructor_params(std::stringstream& stream, const blofeld::s_tag_struct_definition& tag_struct_definition);
	void generate_ctor_source(unsigned long source_index, unsigned long source_count);
	void generate_source_virtual();
	void generate_source_misc();

	std::string output_directory;
	std::string output_header_file_path;
	std::string output_source_file_path;
	std::string output_forward_declare_file_path;
	std::string output_virtual_file_path;
	std::string output_misc_file_path;

	const blofeld::s_tag_group* get_tag_struct_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition);
	std::string format_structure_symbol(const blofeld::s_tag_struct_definition& struct_definition);
	static const char* field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
};
