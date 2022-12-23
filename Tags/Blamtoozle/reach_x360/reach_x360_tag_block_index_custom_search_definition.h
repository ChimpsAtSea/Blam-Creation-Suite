#pragma once

struct s_reach_x360_block_index_custom_search_definition
{
	ptr32 name_address;
	ptr32 unknown_func0;
	ptr32 unknown_func1;
};
constexpr size_t k_reach_x360_block_index_custom_search_definition_size = sizeof(s_reach_x360_block_index_custom_search_definition);
static_assert(k_reach_x360_block_index_custom_search_definition_size == 12);

class c_reach_x360_tag_block_index_custom_search_definition :
	public c_blamtoozle_tag_block_index_custom_search_definition
{
protected:
	c_reach_x360_tag_block_index_custom_search_definition(c_reach_x360_tag_definition_manager& tag_definition_manager, ptr32 definition_address);
	c_reach_x360_tag_block_index_custom_search_definition(const c_reach_x360_tag_block_index_custom_search_definition&) = delete;
	c_reach_x360_tag_block_index_custom_search_definition(c_reach_x360_tag_block_index_custom_search_definition&&) = delete;
	~c_reach_x360_tag_block_index_custom_search_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_reach_x360_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;

protected:
	ptr32 definition_address;
	s_reach_x360_block_index_custom_search_definition block_index_custom_search_definition;
	const char* name;
	std::string code_symbol_name;
};
