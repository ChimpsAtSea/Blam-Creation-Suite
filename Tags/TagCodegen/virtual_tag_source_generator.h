#pragma once
class c_virtual_tag_source_generator
{
public:

	e_engine_type engine_type;

	c_virtual_tag_source_generator(e_engine_type engine_type);
	void generate_header();
	void generate_source();
};

