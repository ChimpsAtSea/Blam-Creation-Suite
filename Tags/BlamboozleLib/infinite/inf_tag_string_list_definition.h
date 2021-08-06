#pragma once

struct s_inf_string_list_definition
{
	ptr64 name_address;
	unsigned long option_count;
	unsigned long padding;
	ptr64 options_address;
};

class c_inf_string_list_definition
{
public:
	std::vector<const char*> options;

	const s_inf_string_list_definition& string_list_definition;

	c_fixed_string_1024 name;
	c_fixed_string_1024 code_name;

	c_inf_string_list_definition(const char* guerilla_data, const s_inf_string_list_definition& string_list_definition);
};

c_inf_string_list_definition* inf_get_string_list_definition(const char* guerilla_data, ptr64 virtual_address);
