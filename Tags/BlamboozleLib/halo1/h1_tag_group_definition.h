#pragma once

struct s_h1_tag_group_definition
{
	ptr32 name_address;
	unsigned long flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	unsigned short version : 16;
	bool initialized;
	ptr32 postprocess_procedure;
	ptr32 definition_address;
	tag_group child_group_tags[16];
	unsigned long num_child_group_tags;
};

class c_h1_tag_block_definition;

class c_h1_tag_group_definition
{
public:
	const s_h1_tag_group_definition* tag_group_definition;
	const char* name;
	c_fixed_string_512 code_name;
	c_fixed_string_512 tag_symbol_name;
	c_h1_tag_block_definition* tag_block_definition;
	c_h1_tag_group_definition(const char* guerilla_data, const char* tag_layout_data);

	void traverse(const char* guerilla_data);
};

c_h1_tag_group_definition* get_tag_group_definition(const char* guerilla_data, ptr32 virtual_address);
c_h1_tag_group_definition* get_tag_group_definition_by_group_tag(tag group_tag);
