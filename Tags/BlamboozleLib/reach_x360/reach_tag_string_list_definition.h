#pragma once

struct s_reach_x360_string_list_definition
{
	bptr32 name_address;
	bulong option_count;
	bptr32 options_address;
	bulong unknown0;
	bulong unknown1;
	bptr32 filepath;
	bulong line_number;
};

class c_reach_x360_string_list_definition
{
public:
	std::vector<const char*> options;

	const s_reach_x360_string_list_definition& string_list_definition;

	c_fixed_string_1024 name;
	c_fixed_string_1024 code_name;

	c_reach_x360_string_list_definition(const char* guerilla_data, const s_reach_x360_string_list_definition& string_list_definition);
};

c_reach_x360_string_list_definition* reach_x360_get_string_list_definition(const char* guerilla_data, ptr32 virtual_address);
