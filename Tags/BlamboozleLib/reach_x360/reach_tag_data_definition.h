#pragma once

struct s_reach_x360_tag_data_definition
{
	bptr32 name_address;
	bulong flags;
	bulong alignment_bit;
	bulong maximum_size;
	bptr32 maximum_size_string_address;
	bptr32 unknown_procedure0;
	bptr32 unknown_procedure1;
	bptr32 unknown_procedure2;
	bptr32 unknown_procedure3;
	bptr32 unknown_procedure4;
	bptr32 unknown_procedure5;
};
constexpr size_t k_reach_x360_tag_data_definition_size = sizeof(s_reach_x360_tag_data_definition);
////static_assert(k_reach_x360_tag_data_definition_size == 80);

class c_reach_x360_tag_data_definition
{
public:
	std::string name;
	std::string code_name;
	unsigned long flags;
	unsigned long alignment_bit;
	unsigned long maximum_size;
	std::string maximum_size_string;
	const s_reach_x360_tag_data_definition& data_definition;

	c_reach_x360_tag_data_definition(const char* guerilla_data, const s_reach_x360_tag_data_definition& definition_header);

	static std::map<ptr32, c_reach_x360_tag_data_definition*> tag_data_definitions;
	static c_reach_x360_tag_data_definition* reach_x360_get_tag_data_definition(const char* guerilla_data, ptr32 virtual_address);
};
