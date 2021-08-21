#pragma once

struct s_h2_tag_group_definition
{
	ptr32 name_address;
	unsigned long flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	unsigned short version : 16;
	bool initialized;
	ptr32 save_postprocess_procedure;
	ptr32 postprocess_for_sync_procedure;
	ptr32 postprocess_procedure;
	unsigned long inheritance_flags;
	ptr32 definition_address;
	tag_group child_group_tags[16];
	unsigned long num_child_group_tags;
	ptr32 default_tag_path_address;
};

class c_h2_tag_block_definition;

class c_h2_tag_group_definition
{
public:
	const s_h2_tag_group_definition* tag_group_definition;
	const char* name;
	c_fixed_string_512 code_name;
	c_fixed_string_512 tag_symbol_name;
	c_h2_tag_block_definition* tag_block_definition;
	c_h2_tag_group_definition(const char* guerilla_data, const char* tag_layout_data);

	void traverse(const char* guerilla_data);

	static std::map<ptr32, c_h2_tag_group_definition*> tag_group_definitions;
	static c_h2_tag_group_definition* h2_get_tag_group_definition(const char* guerilla_data, ptr32 virtual_address);
	static c_h2_tag_group_definition* h2_get_tag_group_definition_by_group_tag(tag group_tag);
};


