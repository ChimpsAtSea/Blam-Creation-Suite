#pragma once

class c_blamtoozle_string_list_definition
{
public:
	c_blamtoozle_string_list_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_string_list_definition(const c_blamtoozle_string_list_definition&) = delete;
	c_blamtoozle_string_list_definition(c_blamtoozle_string_list_definition&&) = delete;
	virtual ~c_blamtoozle_string_list_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual const char* get_file_path();
	virtual int32_t get_line_number();

	using t_options = std::vector<const char*>;
	t_options options;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};
