#pragma once

class c_tag_source_generator
{
public:
	e_engine_type engine_type;
	
	c_tag_source_generator(e_engine_type engine_type);

	static const char* field_type_to_source_type(blofeld::e_field field_type);
	void generate_source();
};

