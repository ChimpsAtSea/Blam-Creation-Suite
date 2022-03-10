#pragma once

struct s_h3_block_index_custom_search_definition
{
	ptr64 name_address;
	ptr64 unknown_func0;
	ptr64 unknown_func1;
};
constexpr size_t k_h3_block_index_custom_search_definition_size = sizeof(s_h3_block_index_custom_search_definition);
static_assert(k_h3_block_index_custom_search_definition_size == 24);

class c_h3_block_index_custom_search_definition
{
public:
	std::string name;
	std::string code_name;
	const s_h3_block_index_custom_search_definition& block_index_custom_search_definition;

	c_h3_block_index_custom_search_definition(const char* guerilla_data, const s_h3_block_index_custom_search_definition& definition_header);

	static std::map<ptr64, c_h3_block_index_custom_search_definition*> block_index_custom_search_definitions;
	static c_h3_block_index_custom_search_definition* h3_get_block_index_custom_search_definition(const char* guerilla_data, ptr64 virtual_address);
};
