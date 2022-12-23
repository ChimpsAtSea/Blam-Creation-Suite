#pragma once

class c_blamtoozle_tag_struct_definition;

class c_blamtoozle_tag_block_index_custom_search_definition
{
public:
	BCS_SHARED c_blamtoozle_tag_block_index_custom_search_definition(c_blamtoozle_tag_definition_manager& tag_definition_manager);
	c_blamtoozle_tag_block_index_custom_search_definition(const c_blamtoozle_tag_block_index_custom_search_definition&) = delete;
	c_blamtoozle_tag_block_index_custom_search_definition(c_blamtoozle_tag_block_index_custom_search_definition&&) = delete;
	BCS_SHARED virtual ~c_blamtoozle_tag_block_index_custom_search_definition();

	virtual const char* get_name() = 0;
	virtual const char* get_code_symbol_name() = 0;

	c_blamtoozle_tag_definition_manager& tag_definition_manager;
};

