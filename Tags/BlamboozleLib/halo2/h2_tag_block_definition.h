#pragma once

class c_h2_pseudo_struct_definition;
class c_h2_tag_group_definition;

struct s_h2_tag_block_definition
{
	ptr32 display_name_address;
	ptr32 name_address;
	unsigned long flags;
	unsigned long maximum_element_count;
	ptr32 maximum_element_count_string_address;
	ptr32 struct_definitions;
	unsigned long struct_definition_count;
	ptr32 latest_struct_definition;
	unsigned long _unknown;
	ptr32 postprocess_procedure;
	ptr32 format_procedure;
	ptr32 generate_default_procedure;
	ptr32 dispose_element_procedure;
};

class c_h2_tag_block_definition
{
public:
	std::string display_name;
	std::string name;
	std::string code_name;
	unsigned long maximum_element_count;
	std::string maximum_element_count_string;
	std::vector<c_h2_pseudo_struct_definition*> pseudo_struct_definitions;
	c_h2_pseudo_struct_definition* latest_pseudo_struct_definition;
	const s_h2_tag_block_definition* block_definition;
	c_h2_tag_group_definition* tag_group_definition;

	c_h2_tag_block_definition(const char* guerilla_data, const s_h2_tag_block_definition* definition_header, c_h2_tag_group_definition* tag_group_definition = nullptr);

	static std::map<ptr32, c_h2_tag_block_definition*> tag_block_definitions;
	static c_h2_tag_block_definition* h2_get_tag_block_definition(const char* guerilla_data, ptr32 virtual_address, c_h2_tag_group_definition* tag_group_definition = nullptr);
	static void h2_fixup_tag_inheritance_structures();
};


