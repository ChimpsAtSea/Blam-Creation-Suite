#pragma once

class c_h3_tag_struct_definition;
class c_h3_tag_group_definition;

struct s_h3_tag_block_definition
{
	ptr64 pretty_name_address;
	ptr64 name_address;
	unsigned long max_count;
	unsigned long flags;
	ptr64 max_count_string_address;
	ptr64 structure_definition_address;
};
constexpr size_t k_h3_tag_block_definition_size = sizeof(s_h3_tag_block_definition);
static_assert(k_h3_tag_block_definition_size == 40);

class c_h3_tag_block_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string code_name;
	unsigned long flags;
	unsigned long max_count;
	std::string max_count_string;
	c_h3_tag_struct_definition& struct_definition;
	const s_h3_tag_block_definition& block_definition;
	c_h3_tag_group_definition* tag_group_definition;

	c_h3_tag_block_definition(const char* guerilla_data, const s_h3_tag_block_definition& definition_header, c_h3_tag_group_definition* tag_group_definition = nullptr);

	static std::map<ptr64, c_h3_tag_block_definition*> tag_block_definitions;
	static c_h3_tag_block_definition* h3_get_tag_block_definition(const char* guerilla_data, ptr64 virtual_address, c_h3_tag_group_definition* tag_group_definition = nullptr);
};

