#pragma once
class h_tag_source_generator
{
public:

	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;

	h_tag_source_generator(e_engine_type engine_type, e_platform_type platform_type, e_build build);
	const blofeld::s_tag_group* get_tag_struct_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition);
	void generate_header();
	void generate_tag_constructor_params(std::stringstream& stream, const blofeld::s_tag_struct_definition& tag_struct_definition);
	void generate_source();

	static const char* field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
};

