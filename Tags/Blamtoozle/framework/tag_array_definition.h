#pragma once

class c_blamtoozle_tag_array_definition
{
public:
	c_blamtoozle_tag_array_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_array_definition(const c_blamtoozle_tag_array_definition&) = delete;
	c_blamtoozle_tag_array_definition(c_blamtoozle_tag_array_definition&&) = delete;
	virtual ~c_blamtoozle_tag_array_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual unsigned long get_element_count() = 0;
	virtual const char* get_element_count_string() = 0;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() = 0;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};

