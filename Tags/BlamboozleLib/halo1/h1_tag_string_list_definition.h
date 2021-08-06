#pragma once

struct s_h1_string_list_definition
{
	unsigned long option_count;
	ptr32 options_address;
	unsigned long flags; //?
};

class c_h1_string_list_definition
{
public:
	std::vector<const char*> options;

	const s_h1_string_list_definition& string_list_definition;

	c_fixed_string_1024 name;
	c_fixed_string_1024 code_name;

	c_h1_string_list_definition(const char* guerilla_data, const s_h1_string_list_definition& string_list_definition);
};

c_h1_string_list_definition* h1_get_string_list_definition(const char* guerilla_data, ptr32 virtual_address);
