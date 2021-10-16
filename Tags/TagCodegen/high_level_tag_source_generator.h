#pragma once
class c_high_level_tag_source_generator
{
public:

	s_engine_platform_build engine_platform_build;

	c_high_level_tag_source_generator(s_engine_platform_build engine_platform_build);
	const blofeld::s_tag_group* get_tag_struct_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition) const;
	void generate_header() const;
	void generate_tag_constructor_params(std::stringstream& stream, const blofeld::s_tag_struct_definition& tag_struct_definition) const;
	void generate_ctor_source(unsigned long source_index, unsigned long source_count) const;
	void generate_source_virtual() const;
	void generate_source_misc() const;

	std::string format_structure_symbol(const blofeld::s_tag_struct_definition& struct_definition) const;

	static const char* field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
};

