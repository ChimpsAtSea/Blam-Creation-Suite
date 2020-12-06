#pragma once
class c_high_level_tag_source_generator
{
public:

	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;

	c_high_level_tag_source_generator(e_engine_type engine_type, e_platform_type platform_type, e_build build);
	const blofeld::s_tag_group* get_tag_struct_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition) const;
	void generate_header() const;
	void generate_tag_constructor_params(std::stringstream& stream, const blofeld::s_tag_struct_definition& tag_struct_definition) const;
	void generate_ctor_source(uint32_t source_index, uint32_t source_count) const;
	void generate_source_virtual() const;
	void generate_source_misc() const;

	static const char* field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
};

