#pragma once

class c_blamtoozle_tag_block_definition;

class c_blamtoozle_tag_group_definition
{
public:
	BCS_SHARED c_blamtoozle_tag_group_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_group_definition(const c_blamtoozle_tag_group_definition&) = delete;
	c_blamtoozle_tag_group_definition(c_blamtoozle_tag_group_definition&&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_group_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual const char* get_group_tag_macro_name() = 0;
	virtual uint32_t get_version() = 0;
	virtual tag get_group_tag() = 0;
	virtual tag get_parent_group_tag() = 0;
	virtual c_blamtoozle_tag_block_definition& get_block_definition() = 0;
	virtual void traverse() = 0;
	virtual blofeld::f_tag_group_flags get_tag_group_flags() = 0;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};

