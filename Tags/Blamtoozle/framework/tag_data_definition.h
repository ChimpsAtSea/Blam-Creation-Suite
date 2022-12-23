#pragma once

class c_blamtoozle_tag_data_definition
{
public:
	BCS_SHARED c_blamtoozle_tag_data_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_data_definition(const c_blamtoozle_tag_data_definition&) = delete;
	c_blamtoozle_tag_data_definition(c_blamtoozle_tag_data_definition&&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_data_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual uint32_t get_flags() = 0;
	virtual uint32_t get_alignment_bits() = 0;
	virtual uint32_t get_maximum_element_count() = 0;
	virtual const char* get_maximum_element_count_string() = 0;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};
