#pragma once

class c_h1_pseudo_struct_definition;
class c_h1_tag_group_definition;

struct s_h1_tag_block_definition
{
	ptr32 name_address;
	unsigned long flags;
	unsigned long maximum_element_count;
	unsigned long size;
	unsigned long _unknown1;
	ptr32 fields_address;
	unsigned long _unknown2;
	ptr32 postprocess_procedure;
	ptr32 format_procedure;
	ptr32 generate_default_procedure;
	ptr32 dispose_element_procedure;
};

class c_h1_tag_block_definition
{
public:
	std::string name;
	std::string code_name;
	c_h1_pseudo_struct_definition* pseudo_struct_definition;
	const s_h1_tag_block_definition* block_definition;
	c_h1_tag_group_definition* tag_group_definition;

	c_h1_tag_block_definition(const char* guerilla_data, const s_h1_tag_block_definition* definition_header, c_h1_tag_group_definition* tag_group_definition = nullptr);
};

c_h1_tag_block_definition* h1_get_tag_block_definition(const char* guerilla_data, ptr32 virtual_address, c_h1_tag_group_definition* tag_group_definition = nullptr);
void h1_fixup_tag_inheritance_structures();

