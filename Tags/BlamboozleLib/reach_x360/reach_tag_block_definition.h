#pragma once

class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_group_definition;

struct s_reach_x360_tag_block_definition
{
	bptr32 pretty_name_address;
	bptr32 name_address;
	unsigned long max_count;
	bptr32 max_count_string_address;
	bptr32 structure_definition_address;
};
constexpr size_t k_reach_x360_tag_block_definition_size = sizeof(s_reach_x360_tag_block_definition);
//static_assert(k_reach_x360_tag_block_definition_size == 40);

class c_reach_x360_tag_block_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string code_name;
	unsigned long max_count;
	std::string max_count_string;
	c_reach_x360_tag_struct_definition& struct_definition;
	const s_reach_x360_tag_block_definition& block_definition;
	c_reach_x360_tag_group_definition* tag_group_definition;

	c_reach_x360_tag_block_definition(const char* guerilla_data, const s_reach_x360_tag_block_definition& definition_header, c_reach_x360_tag_group_definition* tag_group_definition = nullptr);

	static std::map<ptr32, c_reach_x360_tag_block_definition*> tag_block_definitions;
	static c_reach_x360_tag_block_definition* reach_x360_get_tag_block_definition(const char* guerilla_data, ptr32 virtual_address, c_reach_x360_tag_group_definition* tag_group_definition = nullptr);
};

