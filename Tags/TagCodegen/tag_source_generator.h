#pragma once

class c_tag_source_generator
{
public:
	e_engine_type engine_type;
	e_platform_type platform_type;
	e_build build;
	bool has_error;

	c_tag_source_generator(e_engine_type engine_type, e_platform_type platform_type, e_build build);

	static const char* field_type_to_low_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
	static const char* field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
	void generate_source();

};

