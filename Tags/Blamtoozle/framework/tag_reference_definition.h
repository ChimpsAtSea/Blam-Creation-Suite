#pragma once

class c_blamtoozle_tag_group_definition;

class c_blamtoozle_tag_reference_definition
{
public:
	BCS_SHARED c_blamtoozle_tag_reference_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_reference_definition(const c_blamtoozle_tag_reference_definition&) = delete;
	c_blamtoozle_tag_reference_definition(c_blamtoozle_tag_reference_definition&&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_reference_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual c_flags<blofeld::e_tag_reference_flags> get_tag_reference_flags() = 0;

	std::unordered_set<tag> group_tags;
	std::unordered_set<c_blamtoozle_tag_group_definition*> tag_group_definitions;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};
