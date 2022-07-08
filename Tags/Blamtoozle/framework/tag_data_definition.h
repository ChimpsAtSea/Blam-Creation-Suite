#pragma once

class c_blamtoozle_tag_data_definition
{
public:
	c_blamtoozle_tag_data_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_data_definition(const c_blamtoozle_tag_data_definition&) = delete;
	c_blamtoozle_tag_data_definition(c_blamtoozle_tag_data_definition&&) = delete;
	virtual ~c_blamtoozle_tag_data_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual unsigned long get_flags() = 0;
	virtual unsigned long get_alignment_bits() = 0;
	virtual unsigned long get_maximum_element_count() = 0;
	virtual const char* get_maximum_element_count_string() = 0;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};
