#pragma once

struct s_h3_tag_group_definition
{
	ptr64 name_address;
	unsigned long flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	unsigned long version;
	ptr64 postprocess_procedure; // engine pointer
	ptr64 block_definition_address; // dynamic pointer
};
constexpr size_t k_h3_tag_group_size = sizeof(s_h3_tag_group_definition);
static_assert(k_h3_tag_group_size == 40);

class c_h3_tag_block_definition;

class c_h3_tag_group_definition
{
public:
	const s_h3_tag_group_definition* tag_group_definition;
	const char* name;
	c_fixed_string_512 code_name;
	c_fixed_string_512 tag_symbol_name;
	c_h3_tag_block_definition* tag_block_definition;
	c_h3_tag_group_definition(const char* guerilla_data, const char* tag_layout_data);

	void traverse(const char* guerilla_data);

	static std::map<ptr64, c_h3_tag_group_definition*> tag_group_definitions;
	static c_h3_tag_group_definition* h3_get_tag_group_definition(const char* guerilla_data, ptr64 virtual_address);
	static c_h3_tag_group_definition* h3_get_tag_group_definition_by_group_tag(tag group_tag);
};

