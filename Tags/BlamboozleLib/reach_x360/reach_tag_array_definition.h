#pragma once

class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_group_definition;

struct s_reach_x360_tag_array_definition
{
	bptr32 name_address;
	bulong element_count;
	bptr32 element_count_string;
	bptr32 structure_definition_address;
};
constexpr size_t k_reach_x360_tag_array_definition_size = sizeof(s_reach_x360_tag_array_definition);
//static_assert(k_reach_x360_tag_array_definition_size == 32);

class c_reach_x360_tag_array_definition
{
public:
	std::string name;
	std::string code_name;
	unsigned long count;
	const s_reach_x360_tag_array_definition& array_definition;
	c_reach_x360_tag_struct_definition& struct_definition;

	c_reach_x360_tag_array_definition(const char* guerilla_data, const s_reach_x360_tag_array_definition& definition_header);

	static std::map<ptr32, c_reach_x360_tag_array_definition*> tag_array_definitions;
	static c_reach_x360_tag_array_definition* reach_x360_get_tag_array_definition(const char* guerilla_data, ptr32 virtual_address);
};

