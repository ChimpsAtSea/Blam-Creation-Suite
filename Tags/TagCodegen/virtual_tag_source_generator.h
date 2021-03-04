#pragma once
class c_virtual_tag_source_generator
{
public:

	s_engine_platform_build engine_platform_build;

	c_virtual_tag_source_generator(s_engine_platform_build engine_platform_build);
	void generate_header() const;
	void generate_source() const;
};

