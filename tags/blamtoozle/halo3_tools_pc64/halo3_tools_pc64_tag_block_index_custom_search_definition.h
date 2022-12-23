#pragma once

struct s_halo3_tools_pc64_block_index_custom_search_definition
{
	ptr64 name_address;
	ptr64 unknown_func0;
	ptr64 unknown_func1;
};
constexpr size_t k_halo3_tools_pc64_block_index_custom_search_definition_size = sizeof(s_halo3_tools_pc64_block_index_custom_search_definition);
static_assert(k_halo3_tools_pc64_block_index_custom_search_definition_size == 24);

class c_halo3_tools_pc64_tag_block_index_custom_search_definition :
	public c_blamtoozle_tag_block_index_custom_search_definition
{
protected:
	c_halo3_tools_pc64_tag_block_index_custom_search_definition(c_halo3_tools_pc64_tag_definition_manager& tag_definition_manager, ptr64 definition_address);
	c_halo3_tools_pc64_tag_block_index_custom_search_definition(const c_halo3_tools_pc64_tag_block_index_custom_search_definition&) = delete;
	c_halo3_tools_pc64_tag_block_index_custom_search_definition(c_halo3_tools_pc64_tag_block_index_custom_search_definition&&) = delete;
	~c_halo3_tools_pc64_tag_block_index_custom_search_definition();

public:
	friend c_blamtoozle_tag_definition_manager;
	friend c_halo3_tools_pc64_tag_definition_manager;

	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;

protected:
	ptr64 definition_address;
	s_halo3_tools_pc64_block_index_custom_search_definition block_index_custom_search_definition;
	const char* name;
	std::string code_symbol_name;
};
