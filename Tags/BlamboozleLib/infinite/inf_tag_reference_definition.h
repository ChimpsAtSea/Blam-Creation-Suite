#pragma once

struct s_inf_tag_reference_definition
{
	c_flags< e_h4_tag_reference_definition_flags, unsigned long> flags;
	tag group_tag;
	ptr64 group_tags_address;
};

class c_inf_tag_group_definition;

class c_inf_tag_reference_definition
{
public:
	std::vector<tag> group_tags;
	std::vector<c_inf_tag_group_definition*> group_tags2;

	const s_inf_tag_reference_definition& tag_reference_definition;

	c_fixed_string_1024 name;
	c_fixed_string_1024 code_name;

	c_inf_tag_reference_definition(const char* guerilla_data, const s_inf_tag_reference_definition& tag_reference_definition);
};

c_inf_tag_reference_definition* inf_get_tag_reference_definition(const char* guerilla_data, ptr64 virtual_address);
