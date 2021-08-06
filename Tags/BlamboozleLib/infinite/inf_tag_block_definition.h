#pragma once

class c_inf_tag_struct_definition;
class c_inf_tag_group_definition;

struct s_inf_tag_block_definition
{
	ptr64 pretty_name_address;
	ptr64 name_address;
	unsigned long flags;
	unsigned long max_count;
	ptr64 structure_definition_address;
	ptr64 byteswap_definition_address;
};
constexpr size_t k_inf_tag_block_definition_size = sizeof(s_inf_tag_block_definition);
static_assert(k_inf_tag_block_definition_size == 40);

class c_inf_tag_block_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string code_name;
	unsigned long flags;
	unsigned long max_count;
	c_inf_tag_struct_definition& struct_definition;
	const s_inf_tag_block_definition& block_definition;
	c_inf_tag_group_definition* tag_group_definition;

	c_inf_tag_block_definition(const char* guerilla_data, const s_inf_tag_block_definition& definition_header, c_inf_tag_group_definition* tag_group_definition = nullptr);

	static std::map<ptr64, c_inf_tag_block_definition*> tag_block_definitions;
	static c_inf_tag_block_definition* inf_get_tag_block_definition(const char* guerilla_data, ptr64 virtual_address, c_inf_tag_group_definition* tag_group_definition = nullptr);
};

