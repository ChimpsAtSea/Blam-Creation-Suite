#pragma once

class c_blamtoozle_tag_struct_definition;
class c_blamtoozle_tag_group_definition;

class c_blamtoozle_tag_block_definition
{
public:
	BCS_SHARED c_blamtoozle_tag_block_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_block_definition(const c_blamtoozle_tag_block_definition&) = delete;
	c_blamtoozle_tag_block_definition(c_blamtoozle_tag_block_definition&&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_block_definition();

	virtual const char* get_pretty_name() = 0;
	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;
	virtual uint32_t get_max_count() = 0;
	virtual const char* get_max_count_string() = 0;
	virtual c_blamtoozle_tag_struct_definition& get_struct_definition() = 0;

	BCS_SHARED virtual void associate_tag_group_definition(c_blamtoozle_tag_group_definition* tag_group_definition);
	BCS_SHARED virtual c_blamtoozle_tag_group_definition* get_tag_group_definition();

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
	c_blamtoozle_tag_group_definition* tag_group_definition;
};
