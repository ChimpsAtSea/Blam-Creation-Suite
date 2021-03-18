#pragma once

class c_low_level_tag_source_generator
{
public:
	s_engine_platform_build engine_platform_build;
	mutable bool has_error;

	c_low_level_tag_source_generator(s_engine_platform_build engine_platform_build);
	void generate_header() const;
	void generate_source() const;
	void generate_enum_header() const;

	static const char* field_type_to_low_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
};

