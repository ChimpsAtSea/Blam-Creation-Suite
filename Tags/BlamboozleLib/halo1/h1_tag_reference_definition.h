#pragma once

struct s_h1_tag_reference_definition
{
	c_flags<e_h4_tag_reference_definition_flags, unsigned long> flags;
	tag group_tag;
	ptr32 group_tags_address;
};

class c_h1_tag_reference_definition
{
public:
	std::vector<tag> group_tags;
	std::vector<c_h1_tag_group_definition*> group_tags2;

	const s_h1_tag_reference_definition& tag_reference_definition;

	c_fixed_string_1024 name;
	c_fixed_string_1024 code_name;

	c_h1_tag_reference_definition(const char* guerilla_data, const s_h1_tag_reference_definition& tag_reference_definition);
};

c_h1_tag_reference_definition* h1_get_tag_reference_definition(const char* guerilla_data, ptr32 virtual_address);
