#pragma once

struct s_reach_x360_tag_group_definition
{
	bptr32 name_address;
	unsigned long flags;
	bulong group_tag;
	bulong parent_group_tag;
	unsigned short version;
	bptr32 vtable_shim;
	bptr32 block_definition_address;
};
constexpr size_t k_reach_x360_tag_group_size = sizeof(s_reach_x360_tag_group_definition);
static_assert(k_reach_x360_tag_group_size >= 28);

class c_reach_x360_tag_block_definition;

class c_reach_x360_tag_group_definition
{
public:
	const s_reach_x360_tag_group_definition* tag_group_definition;
	const char* name;
	tag group_tag;
	tag parent_group_tag;
	c_fixed_string_512 code_name;
	c_fixed_string_512 tag_symbol_name;
	c_reach_x360_tag_block_definition* tag_block_definition;
	c_reach_x360_tag_group_definition(const char* guerilla_data, const char* tag_layout_data);

	void traverse(const char* guerilla_data);

	static std::map<ptr32, c_reach_x360_tag_group_definition*> tag_group_definitions;
	static c_reach_x360_tag_group_definition* reach_x360_get_tag_group_definition(const char* guerilla_data, ptr32 virtual_address);
	static c_reach_x360_tag_group_definition* reach_x360_get_tag_group_definition_by_group_tag(tag group_tag);
};

