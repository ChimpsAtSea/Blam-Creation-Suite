#pragma once

struct s_h3_string_list_definition
{
	ptr64 name_address;
	unsigned long option_count;
	unsigned long padding;
	ptr64 options_address;
};

class c_h3_string_list_definition
{
public:
	std::vector<const char*> options;

	const s_h3_string_list_definition& string_list_definition;

	c_fixed_string_1024 name;
	c_fixed_string_1024 code_name;

	c_h3_string_list_definition(const char* guerilla_data, const s_h3_string_list_definition& string_list_definition);
};

c_h3_string_list_definition* h3_get_string_list_definition(const char* guerilla_data, ptr64 virtual_address);
